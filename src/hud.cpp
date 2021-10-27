#include "hud.h"

#include <iostream>
#include <string>

#include "SDL_ttf.h"
HUD::HUD() {}

void HUD::Update(double dt) {}

void HUD::Render(Renderer& renderer) {
  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();

  if (TTF_Init() < 0) {
    std::cerr << TTF_GetError() << "\n";
  }

  TTF_Font* font = TTF_OpenFont("./assets/space-quest.ttf", 24);
  if (!font) {
    std::cerr << TTF_GetError() << "\n";
  }

  std::string text = "HUD DEMO !!!";

  SDL_Color white = {255, 255, 255};
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), white);
  SDL_Texture* msg = SDL_CreateTextureFromSurface(sdlRenderer, surface);
  SDL_Rect msgRect;
  msgRect.x = 30;
  msgRect.y = 30;

  TTF_SizeText(font, text.c_str(), &msgRect.w, &msgRect.h);
  SDL_RenderCopy(sdlRenderer, msg, NULL, &msgRect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(msg);
}