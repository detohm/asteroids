#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "scene.h"

class IntroScene : public Scene {
 public:
  IntroScene(SceneManager& manager);
  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();
};

#endif