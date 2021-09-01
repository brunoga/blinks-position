#ifndef COORDINATES_H_
#define COORDINATES_H_

#include <blinklib.h>

namespace position {

struct Coordinates {
  int8_t x;
  int8_t y;
};

namespace coordinates {

// Returns the axial Z coordinate of the given coordinates.
int8_t Z(Coordinates coordinates);

// Computes the axial distance between the 2 given coordinates.
byte Distance(Coordinates coordinates1, Coordinates coordinates2);

}  // namespace coordinates

}  // namespace position

#endif