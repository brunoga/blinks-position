#include "coordinates.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

namespace position {

namespace coordinates {

// Lookup array for map traversal. Even coordinates are X, odd are Y. Each pair
// is the offset to be applied when moving through a specific local relative
// face. This assumes the X axis crosses faces 1/2 (increasing) and 4/5
// (decreasing), the Y axis crosses faces 5/0 (increasing) and 2/3 (decreasing)
// and the Z axis crosses faces 3/4 (increasing) and 0/1 (decreasing).
static const int8_t traversal_[] = {0, 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1};

int8_t Z(Coordinates coordinates) { return -(coordinates.x + coordinates.y); }

Coordinates SourceToDestination(byte source_relative_face, Coordinates source) {
  byte x_index = source_relative_face * 2;

  return Coordinates{(int8_t)(source.x + traversal_[x_index]),
                     (int8_t)(source.y + traversal_[x_index + 1])};
}

byte Distance(Coordinates coordinates1, Coordinates coordinates2) {
  byte delta_x = ABS(coordinates1.x - coordinates2.x);
  byte delta_y = ABS(coordinates1.y - coordinates2.y);
  byte delta_z = ABS(Z(coordinates1) - Z(coordinates2));

  if (delta_x >= delta_y && delta_x >= delta_z) {
    return delta_x;
  } else if (delta_y >= delta_z) {
    return delta_y;
  } else {
    return delta_z;
  }
}

}  // namespace coordinates

}  // namespace position