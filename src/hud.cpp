#include "hud.h"

#include <iostream>
#include <string>

#include "SDL_ttf.h"
#include "game.h"

HUD::HUD() : lifePoint_(6), score_(0) {
  if (TTF_Init() < 0) {
    std::cerr << TTF_GetError() << "\n";
  }
  font_ = TTF_OpenFont("./assets/space-marine.ttf", 16);
  if (!font_) {
    std::cerr << TTF_GetError() << "\n";
  }
}

HUD::~HUD() { TTF_CloseFont(font_); }

void HUD::Update(double dt, int lifePoint, int score) {
  lifePoint_ = lifePoint;
  score_ = score;
}

void HUD::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();

  std::string text = "H: ";
  for (int i = 0; i < lifePoint_; i++) {
    text += "|";
  }

  SDL_Color white = {255, 255, 255};
  SDL_Surface* surface = TTF_RenderText_Solid(font_, text.c_str(), white);
  SDL_Texture* msg = SDL_CreateTextureFromSurface(sdlRenderer, surface);
  SDL_Rect msgRect;
  msgRect.x = 10;
  msgRect.y = 10;

  TTF_SizeText(font_, text.c_str(), &msgRect.w, &msgRect.h);
  SDL_RenderCopy(sdlRenderer, msg, NULL, &msgRect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(msg);

  text = "SCORE: ";
  text += std::to_string(score_);
  surface = TTF_RenderText_Solid(font_, text.c_str(), white);
  msg = SDL_CreateTextureFromSurface(sdlRenderer, surface);
  msgRect.x = 400;
  msgRect.y = 10;
  TTF_SizeText(font_, text.c_str(), &msgRect.w, &msgRect.h);
  SDL_RenderCopy(sdlRenderer, msg, NULL, &msgRect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(msg);
}