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