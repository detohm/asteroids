#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "spaceship.h"
class Controller {
 public:
  void HandleInput(bool& running, Spaceship& ship) const;
};
#endif