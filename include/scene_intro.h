#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "SDL_ttf.h"
#include "scene.h"
class IntroScene : public Scene {
 public:
  static IntroScene* Instance(SceneManager& manager);
  void Init();
  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();

 protected:
  IntroScene(SceneManager& manager);

 private:
  static IntroScene* introScene_;
  TTF_Font* font_;
};

#endif