#ifndef RENDERER_H
#define RENDERER_H
#include "SDL.h"
class Renderer {
 public:
  Renderer(const std::size_t screenWidth, const std::size_t screenHeight);
  ~Renderer();
  void Render();

 private:
  SDL_Window* sdlWindow_;
  SDL_Renderer* sdlRenderer_;

  const std::size_t screenWidth_;
  const std::size_t screenHeight_;
};
#endif
