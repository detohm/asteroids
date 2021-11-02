#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H

#include "SDL_ttf.h"
#include "scene.h"
class GameOverScene : public Scene {
 public:
  GameOverScene(SceneManager& manager);
  void Init();
  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();

 private:
  TTF_Font* font_;
};

#endif