#include "bullet.h"

#include "renderer.h"
Bullet::Bullet(std::size_t screenWidth, std::size_t screenHeight, double posX,
               double posY, double radian)
    : screenWidth_(screenWidth), screenHeight_(screenHeight) {
  X = posX;
  Y = posY;
  Radian = radian;
  Speed = 500;
  DX = cos(Radian) * Speed;
  DY = sin(Radian) * Speed;
  PXs.emplace_back(X);
  PYs.emplace_back(Y);
}

void Bullet::Update(double dt) {
  PXs.clear();
  PYs.clear();

  X += DX * dt;
  Y += DY * dt;

  PXs.emplace_back(X);
  PYs.emplace_back(Y);

  // X
  if (X < 0.0 || X > screenWidth_) {
    WillBeRemoved = true;
  }

  // Y
  if (Y < 0.0 || Y > screenHeight_) {
    WillBeRemoved = true;
  }
}

void Bullet::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawPoint(sdlRenderer, X, Y);
}