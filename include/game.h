#ifndef GAME_H
#define GAME_H

#include <vector>

#include "asteroid.h"
#include "controller.h"
#include "renderer.h"
#include "spaceship.h"
class Game {
 public:
  Game(std::size_t width, std::size_t height);
  void Run(const Controller& controller, Renderer& renderer,
           const std::size_t msPerFrame);
  void Update(double dt);

 private:
  std::size_t width_;
  std::size_t height_;
  Spaceship ship_;
  std::vector<Asteroid> asteroid_;  // TODO - refactor to use pool
  void initAsteroids();
  void detectCollision();
  void splitAsteroids(Asteroid atr);
};
#endif