#include "controller.h"

#include "SDL.h"
#include "spaceship.h"

void Controller::HandleInput(bool& running, Spaceship& ship) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
        case SDLK_w:
          ship.Accelerate();
          break;
        case SDLK_LEFT:
        case SDLK_a:
          ship.Rotate(Spaceship::RotateDirection::AntiClockwise);
          break;
        case SDLK_RIGHT:
        case SDLK_d:
          ship.Rotate(Spaceship::RotateDirection::Clockwise);
          break;
        case SDLK_SPACE:
          ship.Shoot();
          break;
      }
    }
  }
}