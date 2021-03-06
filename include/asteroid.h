#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include "game_object.h"
class Asteroid : public GameObject {
 public:
  enum class AsteroidSize { Small, Medium, Large };
  Asteroid(std::size_t screenWidth, std::size_t screenHeight, double x,
           double y, AsteroidSize size);
  void Update(double dt);
  void Render(Renderer& renderer);
  bool WillBeRemoved = false;
  AsteroidSize Size() { return size_; }

 private:
  void setPoints();
  void setOriginPoints();
  std::vector<double> oPxs_;
  std::vector<double> oPys_;
  AsteroidSize size_;
  std::size_t screenWidth_;
  std::size_t screenHeight_;
};

#endif