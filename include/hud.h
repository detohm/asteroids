#ifndef HUD_H
#define HUD_H
#include "renderer.h"

class HUD {
 public:
  HUD();
  void Update(double dt);
  void Render(Renderer& renderer);
};
#endif
