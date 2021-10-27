#include "bullet.h"

#include "renderer.h"
Bullet::Bullet(double posX, double posY, double radian) {
  X = posX;
  Y = posY;
  Radian = radian;
  Speed = 500;
  DX = cos(Radian) * Speed;
  DY = sin(Radian) * Speed;
}

void Bullet::Update(double dt) {
  X += DX * dt;
  Y += DY * dt;
}

void Bullet::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawPoint(sdlRenderer, X, Y);
}