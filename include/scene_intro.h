#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include <vector>

#include "SDL_ttf.h"
#include "asteroid.h"
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
  TTF_Font* fontHeader_;
  std::vector<Asteroid> asteroid_;
  void initAsteroids();

  void renderTextbox(std::string text, int x, int y, SDL_Color color,
                     TTF_Font* font);
};

#endif