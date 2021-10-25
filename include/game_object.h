#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <vector>

class GameObject {
 public:
  double X;                 // origin x
  double Y;                 // origin y
  std::vector<double> PXs;  // x position of points in shape
  std::vector<double> PYs;  // y position of points in shape

  double DX;      // direction x
  double DY;      // direction y
  double Radian;  // rotation angle
};
#endif