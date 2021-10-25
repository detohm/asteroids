#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "SDL.h"
#include "renderer.h"
class Spaceship {
 public:
  Spaceship(std::size_t screenWidth, std::size_t screenHeight, double x,
            double y);
  enum class RotateDirection { Clockwise, AntiClockwise };
  void Accelerate();
  void Rotate(RotateDirection direction);
  void Update(double dt);
  void Render(Renderer& renderer);
  double X;
  double Y;

 private:
  int screenWidth_;
  int screenHeight_;
  double directionX_;
};
#endif