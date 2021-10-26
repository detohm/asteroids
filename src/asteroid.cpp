#include "asteroid.h"

#include <cmath>
#include <iostream>
#include <random>
Asteroid::Asteroid(double x, double y) {
  X = x;
  Y = y;
  maneuverability_ = 3;
  setPoints();
  std::random_device device;
  std::mt19937 generator(device());

  std::uniform_real_distribution<double> distRadian(0, 2.0 * M_PI);
  std::uniform_real_distribution<double> distSpeed(20, 40);
  Radian = distRadian(generator);
  double initSpeed = distSpeed(generator);
  DX = cos(Radian) * initSpeed;
  DY = sin(Radian) * initSpeed;
}

void Asteroid::Update(double dt) {
  Radian += maneuverability_ * dt;
  X += DX * dt;
  Y += DY * dt;

  setPoints();
}

void Asteroid::setPoints() {
  PXs.clear();
  PYs.clear();
  PXs.emplace_back(20);
  PYs.emplace_back(20);

  PXs.emplace_back(20);
  PYs.emplace_back(-20);

  PXs.emplace_back(-20);
  PYs.emplace_back(-20);

  PXs.emplace_back(-20);
  PYs.emplace_back(20);

  for (int i = 0; i < PXs.size(); i++) {
    double px = cos(Radian) * (PXs[i]) - sin(Radian) * (PYs[i]);
    double py = sin(Radian) * (PXs[i]) + cos(Radian) * (PYs[i]);
    PXs[i] = X + px;
    PYs[i] = Y + py;
  }
}

void Asteroid::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  for (int i = 0; i < PXs.size(); i++) {
    if (SDL_RenderDrawLine(sdlRenderer, PXs[i], PYs[i],
                           PXs[(i + 1) % PXs.size()],
                           PYs[(i + 1) % PYs.size()]) < 0) {
      std::cerr << SDL_GetError() << "\n";
    }
  }
}