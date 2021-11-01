#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "scene_intro.h"
#include "scene_manager.h"
const std::size_t kFramePerSecond = 60;
const std::size_t kMsPerFrame = 1000 / kFramePerSecond;
const std::size_t kScreenWidth = 640;
const std::size_t kScreenHeight = 480;

int main() {
  Renderer renderer(kScreenWidth, kScreenHeight);
  SceneManager sceneManager(kScreenWidth, kScreenHeight, renderer, kMsPerFrame);
  IntroScene* intro = new IntroScene(sceneManager);
  sceneManager.Push(intro);
  sceneManager.Run();
}