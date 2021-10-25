#include "game.h"

#include <iostream>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "spaceship.h"
Game::Game(std::size_t width, std::size_t height)
    : ship_(width, height, width / 2, height / 2){};

void Game::Run(const Controller& controller, Renderer& renderer,
               const std::size_t msPerFrame) {
  bool running = true;

  const Uint32 dt = 16.0;
  const double dtSecond = 0.016;
  Uint32 currentTime = SDL_GetTicks();
  Uint32 accumulator = 0;

  Uint32 frameRateTimestamp = SDL_GetTicks();
  int frameCount = 0;

  while (running) {
    // frameStart = SDL_GetTicks();
    Uint32 newTime = SDL_GetTicks();
    Uint32 frameTime = newTime - currentTime;
    currentTime = newTime;
    accumulator += frameTime;

    // io handler & user update
    controller.HandleInput(running, ship_);

    while (accumulator >= dt) {
      Update(dtSecond);
      accumulator -= dt;
    }

    // render
    renderer.RenderFrameStart();
    ship_.Render(renderer);
    renderer.RenderFrameEnd();
    frameCount++;

    // frame rate calculation
    if (newTime - frameRateTimestamp >= 1000) {
      renderer.UpdateWindowTitle("FPS: " + std::to_string(frameCount));
      frameCount = 0;
      frameRateTimestamp = newTime;
    }
  }
}

void Game::Update(double dt) { ship_.Update(dt); }
