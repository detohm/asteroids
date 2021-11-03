#include "scene_manager.h"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "renderer.h"
#include "scene.h"

SceneManager::SceneManager(std::size_t width, std::size_t height,
                           Renderer& renderer, std::size_t msPerFrame)
    : screenWidth_(width),
      screenHeight_(height),
      renderer_(renderer),
      isRunning_(true),
      msPerFrame_(msPerFrame) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }

  if (TTF_Init() < 0) {
    std::cerr << "SDL TTF could not initialize.\n";
    std::cerr << "SDL_TTF_Error: " << TTF_GetError() << "\n";
  }
}

void SceneManager::Change(Scene* scene) {
  if (!scenes_.empty()) {
    scenes_.top()->CleanUp();
    // delete scenes_.top();
    scenes_.pop();
  }

  scenes_.push(scene);
  scene->Init();
}
void SceneManager::Push(Scene* scene) {
  scenes_.push(scene);
  scene->Init();
}
void SceneManager::Pop() {
  if (!scenes_.empty()) {
    scenes_.top()->CleanUp();
    delete scenes_.top();
    scenes_.pop();
  }
}

bool SceneManager::IsRunning() { return isRunning_; }
void SceneManager::SceneQuit() { isRunning_ = false; }
void SceneManager::Terminate() {
  while (!scenes_.empty()) {
    scenes_.top()->CleanUp();
    delete scenes_.top();
    scenes_.pop();
  }
  renderer_.Terminate();
  SDL_Quit();
}

// run main game loop
void SceneManager::Run() {
  Uint32 currentTime = SDL_GetTicks();
  Uint32 accumulator = 0;

  const double dt = msPerFrame_ / 1000.0;

  Uint32 frameRateTimestamp = SDL_GetTicks();
  unsigned int frameCount = 0;

  while (isRunning_) {
    Uint32 newTime = SDL_GetTicks();
    Uint32 frameTime = newTime - currentTime;
    currentTime = newTime;
    accumulator += frameTime;

    // scene phase
    Scene* currentScene = scenes_.top();

    currentScene->HandleInputs();
    while (accumulator >= msPerFrame_) {
      currentScene->Update(dt);
      accumulator -= msPerFrame_;
    }

    currentScene->Render();

    // monitor fps
    frameCount++;
    if (newTime - frameRateTimestamp >= 1000) {
      renderer_.UpdateWindowTitle("Asteroids - FPS: " +
                                  std::to_string(frameCount));
      frameCount = 0;
      frameRateTimestamp = newTime;
    }
  }

  Terminate();
}