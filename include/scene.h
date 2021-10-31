#ifndef SCENE_H
#define SCENE_H
#include "renderer.h"
#include "scene_manager.h"
class SceneManager;
class Scene {
 public:
  Scene(SceneManager& manager);
  virtual void Run(Renderer& renderer) = 0;

 private:
  SceneManager& manager_;
};
#endif