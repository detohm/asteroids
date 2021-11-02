#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H

#include "SDL_ttf.h"
#include "scene.h"
class GameOverScene : public Scene {
 public:
  static GameOverScene* Instance(SceneManager& manager);
  void Init();
  void CleanUp();

  void HandleInputs();
  void Update(double dt);
  void Render();

 protected:
  GameOverScene(SceneManager& manager);

 private:
  static GameOverScene* gameOverScene_;

  TTF_Font* font_;
  TTF_Font* fontHeader_;
  void renderTextbox(std::string text, int x, int y, SDL_Color color,
                     TTF_Font* font);
};

#endif