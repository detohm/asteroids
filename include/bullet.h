#ifndef BULLET_H
#define BULLET_H
#include "game_object.h"
#include "renderer.h"

class Bullet : public GameObject {
 public:
  Bullet(std::size_t screenWidth, std::size_t screenHeight, double posX,
         double posY, double radian);
  // ~Bullet();
  void Update(double dt);
  void Render(Renderer& renderer);

  bool WillBeRemoved = false;

 private:
  int screenWidth_;
  int screenHeight_;
};
#endif