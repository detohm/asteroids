#include "scene_gameover.h"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "game.h"
#include "scene_manager.h"

GameOverScene* GameOverScene::gameOverScene_ = nullptr;
GameOverScene::GameOverScene(SceneManager& manager) : Scene(manager) {}

GameOverScene* GameOverScene::Instance(SceneManager& manager, int score) {
  // lazy initialisation
  if (gameOverScene_ == nullptr) {
    gameOverScene_ = new GameOverScene(manager);
  }
  gameOverScene_->score_ = score;
  return gameOverScene_;
}
void GameOverScene::Init() {
  fontHeader_ = TTF_OpenFont("./assets/space-marine.ttf", 40);
  if (!fontHeader_) {
    std::cerr << TTF_GetError() << "\n";
  }
  font_ = TTF_OpenFont("./assets/audiowide.ttf", 18);
  if (!font_) {
    std::cerr << TTF_GetError() << "\n";
  }
}
void GameOverScene::CleanUp() {}

void GameOverScene::HandleInputs() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      manager_.SceneQuit();
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_p:
          Game* game = Game::Instance(manager_);
          manager_.Change(game);
          break;
      }
    }
  }
}
void GameOverScene::Update(double dt) {}

void GameOverScene::Render() {
  Renderer& renderer = manager_.GetRenderer();
  renderer.RenderFrameStart();

  int bX = 70;
  SDL_Color yellow = {0xFF, 0xCC, 0x00};
  SDL_Color white = {0xFF, 0xFF, 0xFF};
  renderTextbox("GAME OVER !!!", bX, 120, yellow, fontHeader_);
  renderTextbox("Your score is: ", bX + 160, 200, white, font_);
  renderTextbox(std::to_string(score_), bX + 160, 250, white, fontHeader_);
  renderTextbox("Press [p] to play again.", bX, 380, white, font_);
  renderer.RenderFrameEnd();
}

void GameOverScene::renderTextbox(std::string text, int x, int y,
                                  SDL_Color color, TTF_Font* font) {
  SDL_Renderer* sdlRenderer = manager_.GetRenderer().getSDLRenderer();
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
  SDL_Texture* msg = SDL_CreateTextureFromSurface(sdlRenderer, surface);
  SDL_Rect msgRect;
  msgRect.x = x;
  msgRect.y = y;
  TTF_SizeText(font, text.c_str(), &msgRect.w, &msgRect.h);
  SDL_RenderCopy(sdlRenderer, msg, NULL, &msgRect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(msg);
}