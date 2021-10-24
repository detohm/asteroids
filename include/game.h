#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"
class Game {
 public:
  Game(std::size_t width, std::size_t height);
  void Run(const Controller& controller, Renderer& renderer,
           const std::size_t msPerFrame);
  void Update();
};
#endif