#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H

#include "scene.h"
class GameOverScene : public Scene {
 public:
  GameOverScene(SceneManager& manager);
  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();
};

#endif