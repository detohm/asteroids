#include "renderer.h"

#include <iostream>

#include "SDL.h"
Renderer::Renderer(const std::size_t screenWidth,
                   const std::size_t screenHeight)
    : screenWidth_(screenWidth), screenHeight_(screenHeight) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }

  sdlWindow_ = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screenWidth_,
                                screenHeight_, SDL_WINDOW_SHOWN);
  if (nullptr == sdlWindow_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  sdlRenderer_ = SDL_CreateRenderer(sdlWindow_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdlRenderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdlWindow_);
  SDL_Quit();
}
void Renderer::Render() {
  SDL_Rect box;
  box.w = 20;
  box.h = 20;
  box.x = 50;
  box.y = 50;
  SDL_SetRenderDrawColor(sdlRenderer_, 0xFF, 0xCC, 0x00, 0xFF);
  SDL_RenderFillRect(sdlRenderer_, &box);
  SDL_RenderPresent(sdlRenderer_);
}

void Renderer::UpdateWindowTitle(std::string title) {
  SDL_SetWindowTitle(sdlWindow_, title.c_str());
}