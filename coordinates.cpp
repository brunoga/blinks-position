#include "coordinates.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

namespace position {

namespace coordinates {

int8_t Z(Coordinates coordinates) { return -(coordinates.x + coordinates.y); }

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