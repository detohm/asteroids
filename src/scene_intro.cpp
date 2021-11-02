#include "scene_intro.h"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "game.h"

IntroScene* IntroScene::introScene_ = nullptr;

IntroScene::IntroScene(SceneManager& manager) : Scene(manager) {}

IntroScene* IntroScene::Instance(SceneManager& manager) {
  // lazy initialisation
  if (introScene_ == nullptr) {
    introScene_ = new IntroScene(manager);
  }
  return introScene_;
}

void IntroScene::Init() {
  font_ = TTF_OpenFont("./assets/space-marine.ttf", 16);
  if (!font_) {
    std::cerr << TTF_GetError() << "\n";
  }
}

void IntroScene::CleanUp() { /*TTF_CloseFont(font_);*/
}

void IntroScene::HandleInputs() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      manager_.SceneQuit();
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_SPACE:
          Game* game = Game::Instance(manager_);
          manager_.Change(game);
          break;
      }
    }
  }
}
void IntroScene::Update(double dt) {}

void IntroScene::Render() {
  Renderer& renderer = manager_.GetRenderer();
  renderer.RenderFrameStart();

  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  std::string text = "intro";

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

  renderer.RenderFrameEnd();
}
