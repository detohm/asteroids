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
  static Game* Instance(SceneManager& manager);
  void Init();

  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();

  int LifePoint() { return lifePoint_; }

 protected:
  Game(SceneManager& manager);

 private:
  static Game* game_;

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