#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "SDL.h"
#include "renderer.h"
class Spaceship {
 public:
  enum class RotateDirection { Clockwise, AntiClockwise };
  void Accelerate();
  void Rotate(RotateDirection direction);
  void Render(Renderer& renderer);

 private:
  double x_;
  double y_;
};
#endif