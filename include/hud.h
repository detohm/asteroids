#ifndef HUD_H
#define HUD_H
#include "SDL_ttf.h"
#include "renderer.h"

class HUD {
 public:
  HUD();
  void Update(double dt);
  void Render(Renderer& renderer);

 private:
  TTF_Font* font_;
};
#endif
