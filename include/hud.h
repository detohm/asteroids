#ifndef HUD_H
#define HUD_H
#include "SDL_ttf.h"
#include "renderer.h"
class HUD {
 public:
  HUD();
  ~HUD();
  void Update(double dt, int lifePoint, int score);
  void Render(Renderer& renderer);

 private:
  TTF_Font* font_;
  int lifePoint_;
  int score_;
};
#endif
