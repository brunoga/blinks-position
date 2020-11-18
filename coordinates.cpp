#include "coordinates.h"

namespace position {

Coordinates::Coordinates() : Coordinates(0, 0) {}

Coordinates::Coordinates(int8_t x, int8_t y) {
  x_ = x;
  y_ = y;
}

int8_t Coordinates::X() const { return x_; }
int8_t Coordinates::Y() const { return y_; }
int8_t Coordinates::Z() const { return -(x_ + y_); }

}  // namespace position
