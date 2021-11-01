#ifndef SCENE_H
#define SCENE_H
#include "renderer.h"
#include "scene_manager.h"
class SceneManager;
class Scene {
 public:
  Scene(SceneManager& manager);
  virtual ~Scene();
  virtual void CleanUp() = 0;

  virtual void HandleInputs() = 0;
  virtual void Update(double dt) = 0;
  virtual void Render() = 0;

 protected:
  SceneManager& manager_;
};
#endif