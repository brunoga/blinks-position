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
from_face_and_coordinates(byte relative_exit_face,
                          Coordinates remote_coordinates) {
  byte x_index = relative_exit_face * 2;

  return Coordinates{remote_coordinates.x + traversal_[x_index],
                     remote_coordinates.y + traversal_[x_index + 1]};
}

void SetCoordinates(Coordinates coordinates) { coordinates_ = coordinates; }

Coordinates GetCoordinates() { return coordinates_; }

Coordinates ComputeCoordinates(byte relative_remote_face,
                               Coordinates remote_coordinates) {
  return from_face_and_coordinates(relative_remote_face, remote_coordinates);
}

byte Distance(Coordinates coordinates) {
  return coordinates::Distance(coordinates_, coordinates);
}

}  // namespace position
