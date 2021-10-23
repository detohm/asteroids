#include <iostream>

#include "SDL.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

void initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << SDL_GetError() << std::endl;
  }
  SDL_Window* sdl_window =
      SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;
    }
  }
  SDL_Quit();
}

int main() { initSDL(); }