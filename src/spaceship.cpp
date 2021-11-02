#include "spaceship.h"

#include <cmath>
#include <iostream>

#include "renderer.h"

Spaceship::Spaceship() {}

void Spaceship::Init(std::size_t screenWidth, std::size_t screenHeight,
                     double posX, double posY) {
  screenWidth_ = screenWidth;
  screenHeight_ = screenHeight;
  X = posX;
  Y = posY;
  Speed = 0;
  RotationSpeed = 0;
  Radian = -M_PI / 2.0;
  acceleration_ = 300;
  isAccelarating_ = false;
  deceleration_ = 100;
  maxSpeed_ = 600;
  setPoints();
}

void Spaceship::Accelerate() { isAccelarating_ = true; }

void Spaceship::Rotate(RotateDirection direction) {
  if (direction == RotateDirection::Clockwise) {
    RotationSpeed = 5;
  } else {
    RotationSpeed = -5;
  }
}

void Spaceship::Shoot() {
  Bullets.emplace_back(Bullet(screenWidth_, screenHeight_, X, Y, Radian));
}

void Spaceship::Hit() { isHit_ = true; }

void Spaceship::Update(double dt) {
  if (isHit_) {
    DX = 0;
    DY = 0;
    isAccelarating_ = false;
    isHit_ = false;
  }

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
  for (auto it = Bullets.begin(); it != Bullets.end();) {
    if (it->WillBeRemoved) {
      Bullets.erase(it);
    } else {
      it->Update(dt);
      it++;
    }
  }
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

  for (int i = 0; i < Bullets.size(); i++) {
    Bullets[i].Render(renderer);
  }
}
