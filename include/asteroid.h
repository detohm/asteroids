#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include "game_object.h"
class Asteroid : public GameObject {
 public:
  Asteroid(double x, double y);
  void Update(double dt);
  void Render(Renderer& renderer);

 private:
  void setPoints();
  double maneuverability_;
};

#endif