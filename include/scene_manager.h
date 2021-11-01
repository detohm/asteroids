#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include <stack>

#include "renderer.h"
#include "scene.h"
class Scene;
class SceneManager {
 public:
  SceneManager(std::size_t width, std::size_t height, Renderer& renderer,
               std::size_t msPerFrame);

  void Change(Scene* scene);
  void Push(Scene* scene);
  void Pop();

  void Run();
  bool IsRunning();
  void SceneQuit();
  void Terminate();

  // getter
  std::size_t Width() { return screenWidth_; }
  std::size_t Height() { return screenHeight_; }
  Renderer& GetRenderer() { return renderer_; }

 private:
  std::stack<Scene*> scenes_;
  bool isRunning_;

  std::size_t screenWidth_;
  std::size_t screenHeight_;
  Renderer& renderer_;
  std::size_t msPerFrame_;
};
#endif