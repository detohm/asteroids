#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "SDL.h"
#include "game_object.h"
#include "renderer.h"
class Spaceship : public GameObject {
 public:
  Spaceship(std::size_t screenWidth, std::size_t screenHeight, double posX,
            double posY);
  enum class RotateDirection { Clockwise, AntiClockwise };
  void Accelerate();
  void Rotate(RotateDirection direction);
  void Update(double dt);
  void Render(Renderer& renderer);

 private:
  int screenWidth_;
  int screenHeight_;
  double directionX_;
  void setPoints();
  double maneuverability_;
  bool isAccelarate_;
};
#endif