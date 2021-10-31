#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "scene.h"
class Scene;
class SceneManager {
 public:
  SceneManager(std::size_t width, std::size_t height, Renderer& renderer);
  void Replace(Scene* scene);
  void Set(Scene* scene);
  void Run();
  void Terminate();

 private:
  std::size_t screenWidth_;
  std::size_t screenHeight_;
  Scene* currentScene_;
  Renderer& renderer_;
};
#endif