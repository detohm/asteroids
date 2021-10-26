#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <vector>

#include "renderer.h"
class GameObject {
 public:
  double X;                 // origin x
  double Y;                 // origin y
  std::vector<double> PXs;  // x position of points in shape
  std::vector<double> PYs;  // y position of points in shape

  double DX;      // diff x
  double DY;      // diff y
  double Radian;  // rotation angle

  double Speed;
  double RotationSpeed;

  // base behaviors
  void WrapBound(std::size_t width, std::size_t height);

  // virtual
  virtual void Update(double dt) = 0;
  virtual void Render(Renderer& renderer) = 0;
};
#endif