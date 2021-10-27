#include "spaceship.h"

#include <cmath>
#include <iostream>

#include "renderer.h"

Spaceship::Spaceship(std::size_t screenWidth, std::size_t screenHeight,
                     double posX, double posY)
    : screenWidth_(screenWidth), screenHeight_(screenHeight) {
  X = posX;
  Y = posY;
  Speed = 0;
  RotationSpeed = 0;
  Radian = -M_PI / 2.0;
  acceleration_ = 100;
  isAccelarating_ = false;
  deceleration_ = 100;
  maxSpeed_ = 500;
  setPoints();
}

void Spaceship::Accelerate() { isAccelarating_ = true; }

void Spaceship::Rotate(RotateDirection direction) {
  if (direction == RotateDirection::Clockwise) {
    RotationSpeed = 3;
  } else {
    RotationSpeed = -3;
  }
}

void Spaceship::Shoot() { bullets_.emplace_back(Bullet(X, Y, Radian)); }

void Spaceship::Update(double dt) {
  Radian += RotationSpeed * dt;

  if (isAccelarating_) {
    DX += cos(Radian) * acceleration_ * dt;
    DY += sin(Radian) * acceleration_ * dt;
  }

  Speed = sqrt(DX * DX + DY * DY);
  if (Speed > maxSpeed_) {
    DX -= (DX / Speed) * deceleration_ * dt;
    DY -= (DY / Speed) * deceleration_ * dt;
  }

  X += DX * dt;
  Y += DY * dt;

  // wrap
  WrapBound(screenWidth_, screenHeight_);

  setPoints();

  // update bullet
  for (int i = 0; i < bullets_.size(); i++) {
    bullets_[i].Update(dt);
  }

  // TODO - remove out of viewpoint bullet from the list
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

  for (int i = 0; i < bullets_.size(); i++) {
    bullets_[i].Render(renderer);
  }
}
