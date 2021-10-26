#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include "game_object.h"
class Asteroid : public GameObject {
 public:
  enum class Size { Small, Medium, Large };
  Asteroid(double x, double y, Size size);
  void Update(double dt);
  void Render(Renderer& renderer);

 private:
  void setPoints();
  void setOriginPoints();
  std::vector<double> oPxs_;
  std::vector<double> oPys_;
  Size size_;
};

#endif