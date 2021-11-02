#include "renderer.h"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"

Renderer::Renderer(const std::size_t screenWidth,
                   const std::size_t screenHeight)
    : screenWidth_(screenWidth), screenHeight_(screenHeight) {}

void Renderer::Init() {
  sdlWindow_ = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screenWidth_,
                                screenHeight_, SDL_WINDOW_SHOWN);
  if (nullptr == sdlWindow_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  sdlRenderer_ = SDL_CreateRenderer(
      sdlWindow_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (nullptr == sdlRenderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {}

void Renderer::RenderFrameStart() {
  SDL_SetRenderDrawColor(sdlRenderer_, 0x0, 0x0, 0x0, 0xFF);
  if (SDL_RenderClear(sdlRenderer_) < 0) {
    std::cerr << "RenderClear error: " << SDL_GetError() << "\n";
  }
}
void Renderer::RenderFrameEnd() { SDL_RenderPresent(sdlRenderer_); }

void Renderer::UpdateWindowTitle(std::string title) {
  SDL_SetWindowTitle(sdlWindow_, title.c_str());
}

SDL_Renderer* Renderer::getSDLRenderer() { return sdlRenderer_; }

void Renderer::Terminate() { SDL_DestroyWindow(sdlWindow_); }