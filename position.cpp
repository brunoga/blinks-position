#include "position.h"

namespace position {

// Lookup array for map traversal. Even coordinates are X, odd are Y. Each pair
// is the offset to be applied when moving through a specific local relative
// face. This assumes the X axis crosses faces 1/2 (increasing) and 4/5
// (decreasing), the Y axis crosses faces 5/0 (increasing) and 2/3 (decreasing)
// and the Z axis crosses faces 3/4 (increasing) and 0/1 (decreasing).
static const int8_t traversal_[] = {0, 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1};

static Coordinates coordinates_;

static Coordinates __attribute__((noinline))
from_face_and_coordinates(byte relative_exit_face, int8_t x, int8_t y) {
  byte x_index = relative_exit_face * 2;

  int8_t x1 = x + traversal_[x_index];
  int8_t y1 = y + traversal_[x_index + 1];

  return Coordinates{x1, y1};
}

void Setup(byte relative_remote_face, int8_t remote_x, int8_t remote_y) {
  coordinates_ =
      from_face_and_coordinates(relative_remote_face, remote_x, remote_y);
}

void Reset() { coordinates_ = Coordinates{0, 0}; }

Coordinates Local() { return coordinates_; }

Coordinates Remote(byte relative_local_face) {
  return from_face_and_coordinates(relative_local_face, coordinates_.x,
                                   coordinates_.y);
}

byte __attribute__((noinline)) Distance(const Coordinates& coordinates) {
  return coordinates::Distance(Local(), coordinates);
}

}  // namespace position
