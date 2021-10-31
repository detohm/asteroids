#include "scene_manager.h"

#include "renderer.h"
#include "scene.h"
SceneManager::SceneManager(std::size_t width, std::size_t height,
                           Renderer& renderer)
    : screenWidth_(width), screenHeight_(height), renderer_(renderer) {}

void SceneManager::Set(Scene* scene) { currentScene_ = scene; }
void SceneManager::Run() { currentScene_->Run(renderer_); }

void SceneManager::Replace(Scene* scene) {
  // TODO - clean up call for previous scene
  currentScene_ = scene;
  currentScene_->Run(renderer_);
}

void SceneManager::Terminate() {}