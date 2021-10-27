#include "game_object.h"

void GameObject::WrapBound(std::size_t width, std::size_t height) {
  // X
  if (X < 0.0) {
    X = width;
  } else if (X > width) {
    X = 0.0;
  }

  // Y
  if (Y < 0.0) {
    Y = height;
  } else if (Y > height) {
    Y = 0.0;
  }
}

bool GameObject::Overlaps(GameObject& gObj) {
  for (int i = 0; i < gObj.PXs.size(); i++) {
    if (ContainsPoint(gObj.PXs[i], gObj.PYs[i])) {
      return true;
    }
  }
  return false;
}

// Reference : https://wrf.ecse.rpi.edu/Research/Short_Notes/pnpoly.html
bool GameObject::ContainsPoint(double x, double y) {
  int i, j = 0;
  bool c = false;
  for (i = 0, j = PXs.size() - 1; i < PXs.size(); j = i++) {
    if (((PYs[i] > y) != (PYs[j] > y)) &&
        (x < (PXs[j] - PXs[i]) * (y - PYs[i]) / (PYs[j] - PYs[i]) + PXs[i]))
      c = !c;
  }
  return c;
}