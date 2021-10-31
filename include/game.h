#ifndef GAME_H
#define GAME_H

#include <vector>

#include "asteroid.h"
#include "controller.h"
#include "hud.h"
#include "renderer.h"
#include "scene.h"
#include "scene_manager.h"
#include "spaceship.h"
class Game : public Scene {
 public:
  Game(std::size_t width, std::size_t height, std::size_t msPerFrame,
       SceneManager manager);

  void Run(Renderer& renderer);
  void Update(double dt);
  int LifePoint() { return lifePoint_; }

 private:
  std::size_t width_;
  std::size_t height_;

  Spaceship ship_;
  std::vector<Asteroid> asteroid_;  // TODO - refactor to use pool
  void handleInput(bool& running, Spaceship& ship);
  void initAsteroids();
  void detectCollision();
  void splitAsteroids(Asteroid atr);

  int lifePoint_;
  int score_;

  // UI
  HUD hud_;
};
#endif