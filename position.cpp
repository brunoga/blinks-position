#include "position.h"

namespace position {

// Lookup array for map traversal. Even coordinates are X, odd are Y. Each pair
// is the offset to be applied when moving through a specific local relative
// face.
static const int8_t traversal_[] = {0, -1, -1, 0, -1, 1, 0, 1, 1, 0, 1, -1};

static Coordinates coordinates_;

static Coordinates from_face_and_coordinates(byte relative_local_face, int8_t x,
                                             int8_t y) {
  byte x_index = relative_local_face * 2;

  int8_t x1 = x + traversal_[x_index];
  int8_t y1 = y + traversal_[x_index + 1];

  return Coordinates(x1, y1);
}

void Setup(byte relative_local_face, int8_t remote_x, int8_t remote_y) {
  coordinates_ =
      from_face_and_coordinates(relative_local_face, remote_x, remote_y);
}

void Reset() { coordinates_ = Coordinates(0, 0); }

Coordinates Local() { return coordinates_; }

Coordinates Remote(byte relative_local_face) {
  return from_face_and_coordinates(relative_local_face, coordinates_.X(),
                                   coordinates_.Y());
}

}  // namespace position
