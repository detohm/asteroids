#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <vector>

#include "SDL.h"
#include "bullet.h"
#include "game_object.h"
#include "renderer.h"
class Spaceship : public GameObject {
 public:
  Spaceship(std::size_t screenWidth, std::size_t screenHeight, double posX,
            double posY);
  enum class RotateDirection { Clockwise, AntiClockwise };
  void Accelerate();
  void Rotate(RotateDirection direction);
  void Shoot();

  void Update(double dt);
  void Render(Renderer& renderer);

 private:
  int screenWidth_;
  int screenHeight_;
  void setPoints();

  bool isAccelarating_;
  double acceleration_;
  double maxSpeed_;
  double deceleration_;

  std::vector<Bullet> bullets_;
};
#endif