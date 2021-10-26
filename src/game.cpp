#include "game.h"

#include <iostream>
#include <random>
#include <vector>

#include "SDL.h"
#include "asteroid.h"
#include "controller.h"
#include "renderer.h"
#include "spaceship.h"
Game::Game(std::size_t width, std::size_t height)
    : ship_(width, height, width / 2, height / 2),
      width_(width),
      height_(height){};

void Game::initAsteroids() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<double> distW(0, width_);
  std::uniform_real_distribution<double> distH(0, height_);
  double minAsteroidDistance = 200.0;
  for (int i = 0; i < 5; i++) {
    double ax = 0;
    double ay = 0;
    while (true) {
      ax = distW(generator);
      ay = distH(generator);
      if (sqrt((ax - ship_.X) * (ax - ship_.X) +
               (ay - ship_.Y) * (ay - ship_.Y)) > minAsteroidDistance) {
        break;
      }
    }
    asteroid_.emplace_back(Asteroid{ax, ay, Asteroid::Size::Large});
  }
}

void Game::Run(const Controller& controller, Renderer& renderer,
               const std::size_t msPerFrame) {
  // init dynamic game objects
  initAsteroids();

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
    for (int i = 0; i < asteroid_.size(); i++) {
      asteroid_[i].Render(renderer);
    }
    renderer.RenderFrameEnd();
    frameCount++;

    // frame rate calculation
    if (newTime - frameRateTimestamp >= 1000) {
      renderer.UpdateWindowTitle("FPS: " + std::to_string(frameCount) +
                                 " Speed: " + std::to_string(ship_.Speed));
      frameCount = 0;
      frameRateTimestamp = newTime;
    }
  }
}

void Game::Update(double dt) {
  ship_.Update(dt);
  for (int i = 0; i < asteroid_.size(); i++) {
    asteroid_[i].Update(dt);
  }
}
