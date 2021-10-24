#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"

const std::size_t kFramePerSecond = 60;
const std::size_t kMsPerFrame = 1000 / kFramePerSecond;
const std::size_t kScreenWidth = 640;
const std::size_t kScreenHeight = 480;

int main() {
  Renderer renderer(kScreenWidth, kScreenHeight);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight);
  game.Run(controller, renderer, kMsPerFrame);
}