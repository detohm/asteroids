#include "scene_intro.h"

#include <iostream>
#include <random>

#include "SDL.h"
#include "SDL_ttf.h"
#include "asteroid.h"
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
  fontHeader_ = TTF_OpenFont("./assets/space-marine.ttf", 40);
  if (!fontHeader_) {
    std::cerr << TTF_GetError() << "\n";
  }
  font_ = TTF_OpenFont("./assets/audiowide.ttf", 18);
  if (!font_) {
    std::cerr << TTF_GetError() << "\n";
  }
  initAsteroids();
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
void IntroScene::Update(double dt) {
  for (int i = 0; i < asteroid_.size(); i++) {
    asteroid_[i].Update(dt);
  }
}

void IntroScene::Render() {
  Renderer& renderer = manager_.GetRenderer();
  renderer.RenderFrameStart();

  for (int i = 0; i < asteroid_.size(); i++) {
    asteroid_[i].Render(renderer);
  }

  SDL_Renderer* sdlRenderer = renderer.getSDLRenderer();
  std::string text = "Asteroids";
  SDL_Color yellow = {0xFF, 0xCC, 0x00};
  SDL_Color white = {255, 255, 255};

  int bX = 115;

  renderTextbox("Asteroids", bX, 120, yellow, fontHeader_);
  renderTextbox("Use arrow keys to navigate the ship", bX, 200, white, font_);
  renderTextbox("Use [space] to fire !!", bX, 220, white, font_);
  renderTextbox("Press [Space] to start !!!", bX, 260, white, font_);

  renderer.RenderFrameEnd();
}

void IntroScene::renderTextbox(std::string text, int x, int y, SDL_Color color,
                               TTF_Font* font) {
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

void IntroScene::initAsteroids() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<double> distW(0, manager_.Width());
  std::uniform_real_distribution<double> distH(0, manager_.Height());
  for (int i = 0; i < 19; i++) {
    double ax = 0;
    double ay = 0;

    ax = distW(generator);
    ay = distH(generator);
    if (i < 7) {
      asteroid_.emplace_back(Asteroid(manager_.Width(), manager_.Height(), ax,
                                      ay, Asteroid::AsteroidSize::Small));
    } else if (i < 15) {
      asteroid_.emplace_back(Asteroid(manager_.Width(), manager_.Height(), ax,
                                      ay, Asteroid::AsteroidSize::Medium));
    } else {
      asteroid_.emplace_back(Asteroid(manager_.Width(), manager_.Height(), ax,
                                      ay, Asteroid::AsteroidSize::Large));
    }
  }
}
