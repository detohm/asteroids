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
          ship.Accelerate();
          break;
        case SDLK_LEFT:
          ship.Rotate(Spaceship::RotateDirection::AntiClockwise);
          break;
        case SDLK_RIGHT:
          ship.Rotate(Spaceship::RotateDirection::Clockwise);
          break;
      }
    }
  }
}