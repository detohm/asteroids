#include "spaceship.h"

#include <cmath>
#include <iostream>

#include "renderer.h"

Spaceship::Spaceship(std::size_t screenWidth, std::size_t screenHeight,
                     double posX, double posY)
    : screenWidth_(screenWidth), screenHeight_(screenHeight) {
  X = posX;
  Y = posY;
  maneuverability_ = 0;
  setPoints();
  Radian = -M_PI / 2.0;

  // velocity
  Acceleration = 180;
  VX = 0;
  VY = 0;
  isAccelarate_ = false;
}

void Spaceship::Accelerate() { isAccelarate_ = true; }

void Spaceship::Rotate(RotateDirection direction) {
  if (direction == RotateDirection::Clockwise) {
    maneuverability_ = 3;
  } else {
    maneuverability_ = -3;
  }
}

void Spaceship::Update(double dt) {
  Radian += maneuverability_ * dt;

  if (isAccelarate_) {
    VX += cos(Radian) * Acceleration * dt;
    VY += sin(Radian) * Acceleration * dt;
  }
  X += VX * dt;
  Y += VY * dt;

  // wrap
  WrapBound(screenWidth_, screenHeight_);

  setPoints();
}

void Spaceship::setPoints() {
  PXs.clear();
  PYs.clear();

  PXs.emplace_back(10);
  PYs.emplace_back(0);

  PXs.emplace_back(-5);
  PYs.emplace_back(5);

  PXs.emplace_back(-5);
  PYs.emplace_back(-5);

  for (int i = 0; i < PXs.size(); i++) {
    double px = cos(Radian) * (PXs[i]) - sin(Radian) * (PYs[i]);
    double py = sin(Radian) * (PXs[i]) + cos(Radian) * (PYs[i]);
    PXs[i] = X + px;
    PYs[i] = Y + py;
  }
}

void Spaceship::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xCC, 0x00, 0xFF);

  for (int i = 0; i < PXs.size(); i++) {
    if (SDL_RenderDrawLine(sdlRenderer, PXs[i], PYs[i],
                           PXs[(i + 1) % PXs.size()],
                           PYs[(i + 1) % PYs.size()]) < 0) {
      std::cerr << SDL_GetError() << "\n";
    }
  }
}
