#include "spaceship.h"

#include "renderer.h"

Spaceship::Spaceship(std::size_t screenWidth, std::size_t screenHeight,
                     double x, double y)
    : screenWidth_(screenWidth), screenHeight_(screenHeight), X(x), Y(y) {}

void Spaceship::Accelerate() {
  Y = Y + 1;  // TODO
}

void Spaceship::Rotate(RotateDirection direction) {
  if (direction == RotateDirection::Clockwise) {
    directionX_ = 10;  // TODO
  } else {
    directionX_ = -10;  // TODO
  }
}

void Spaceship::Update(double dt) { X += directionX_ * dt; }

void Spaceship::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_Rect box;
  box.w = 20;
  box.h = 20;
  box.x = X;
  box.y = Y;

  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xCC, 0x00, 0xFF);
  SDL_RenderFillRect(sdlRenderer, &box);
}
