#include "coordinates.h"

#include <stdlib.h>

namespace position {

namespace coordinates {

int8_t Z(const Coordinates& coordinates) {
  return -(coordinates.x + coordinates.y);
}

byte Distance(const Coordinates& coordinates1,
              const Coordinates& coordinates2) {
  byte delta_x = abs(coordinates1.x - coordinates2.x);
  byte delta_y = abs(coordinates1.y - coordinates2.y);
  byte delta_z = abs(Z(coordinates1) - Z(coordinates2));

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