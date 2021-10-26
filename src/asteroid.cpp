#include "asteroid.h"

#include <cmath>
#include <iostream>
#include <random>
Asteroid::Asteroid(double x, double y, Size size) : size_(size) {
  X = x;
  Y = y;
  RotationSpeed = 3;
  setPoints();
  std::random_device device;
  std::mt19937 generator(device());

  std::uniform_real_distribution<double> distRadian(0, 2.0 * M_PI);
  std::uniform_real_distribution<double> distSpeed(20, 40);
  Radian = distRadian(generator);
  double initSpeed = distSpeed(generator);
  DX = cos(Radian) * initSpeed;
  DY = sin(Radian) * initSpeed;
  setOriginPoints();
  setPoints();
}

void Asteroid::setOriginPoints() {
  double minSize = 0.0;
  double maxSize = 0.0;
  int points = 0;
  std::random_device device;
  std::mt19937 generator(device());

  switch (size_) {
    case Asteroid::Size::Large:
      minSize = 60;
      maxSize = 80;
      points = 24;
      break;
    case Asteroid::Size::Medium:
      minSize = 35;
      maxSize = 50;
      points = 16;
      break;
    case Asteroid::Size::Small:
      minSize = 20;
      maxSize = 25;
      points = 8;
      break;
  }
  std::uniform_real_distribution<double> distR(minSize, maxSize);

  oPxs_.clear();
  oPys_.clear();
  double angle = 0;
  double r = 0;

  for (int i = 0; i < points; i++) {
    r = distR(generator);
    oPxs_.emplace_back(cos(angle) * r);
    oPys_.emplace_back(sin(angle) * r);
    angle += 2.0 * M_PI / points;
  }
}

void Asteroid::Update(double dt) {
  Radian += RotationSpeed * dt;
  X += DX * dt;
  Y += DY * dt;

  setPoints();
}

void Asteroid::setPoints() {
  PXs.clear();
  PYs.clear();

  for (int i = 0; i < oPxs_.size(); i++) {
    double px = cos(Radian) * (oPxs_[i]) - sin(Radian) * (oPys_[i]);
    double py = sin(Radian) * (oPxs_[i]) + cos(Radian) * (oPys_[i]);
    PXs.emplace_back(X + px);
    PYs.emplace_back(Y + py);
  }
}

void Asteroid::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  for (int i = 0; i < oPxs_.size(); i++) {
    if (SDL_RenderDrawLine(sdlRenderer, PXs[i], PYs[i],
                           PXs[(i + 1) % oPxs_.size()],
                           PYs[(i + 1) % oPxs_.size()]) < 0) {
      std::cerr << SDL_GetError() << "\n";
    }
  }
}