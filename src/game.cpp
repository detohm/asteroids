#include "game.h"

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "spaceship.h"

Game::Game(std::size_t width, std::size_t height) {}

void Game::Run(const Controller& controller, Renderer& renderer,
               const std::size_t msPerFrame) {
  Uint32 titleTimestamp = SDL_GetTicks();
  Uint32 frameStart = 0;
  Uint32 frameEnd = 0;
  Uint32 frameDuration = 0;
  int frameCount = 0;
  bool running = true;

  while (running) {
    frameStart = SDL_GetTicks();

    controller.HandleInput(running, ship_);
    Update();
    ship_.Render(renderer);
    renderer.Render();

    frameEnd = SDL_GetTicks();
    frameCount++;
    frameDuration = frameEnd - frameStart;

    // Show frame rate in title every second.
    if (frameEnd - titleTimestamp >= 1000) {
      renderer.UpdateWindowTitle("FPS: " + std::to_string(frameCount));
      frameCount = 0;
      titleTimestamp = frameEnd;
    }

    if (frameDuration < msPerFrame) {
      SDL_Delay(msPerFrame - frameDuration);
    }
  }
}

void Game::Update() {}
