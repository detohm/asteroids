#include "game.h"

#include "controller.h"
#include "renderer.h"
Game::Game(std::size_t width, std::size_t height) {}

void Game::Run(const Controller& controller, Renderer& renderer,
               const std::size_t msPerFrame) {
  bool running = true;
  while (running) {
    controller.HandleInput(running);
    Update();
    renderer.Render();
  }
}

void Game::Update() {}
