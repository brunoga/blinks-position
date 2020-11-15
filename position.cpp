#include "position.h"

namespace position {

// Lookup array for map traversal. Even coordinates are X, odd are Y. Each pair
// is the offset to be applied when moving through a specific global relative
// face.
static const int8_t traversal_[] = {0, -1, -1, 0, -1, 1, 0, 1, 1, 0, 1, -1};

static Coordinates coordinates_;

static int8_t compute_z_coordinate(int8_t x, int8_t y) { return -(x + y); }

void Set(int8_t x, int8_t y) {
  coordinates_.x = x;
  coordinates_.y = y;
  coordinates_.z = compute_z_coordinate(x, y);
}

Coordinates Get() { return coordinates_; }

Coordinates AtFace(byte global_relative_face) {
  byte x_index = global_relative_face * 2;

  int8_t x = coordinates_.x + traversal_[x_index];
  int8_t y = coordinates_.y + traversal_[x_index + 1];
  int8_t z = compute_z_coordinate(x, y);

  return Coordinates{x, y, z};
}

}  // namespace position
