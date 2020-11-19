#ifndef COORDINATES_H_
#define COORDINATES_H_

#include <blinklib.h>

#define POSITION_INVALID_COORDINATE -128

namespace position {

struct Coordinates {
  int8_t x = POSITION_INVALID_COORDINATE;
  int8_t y = POSITION_INVALID_COORDINATE;
};

namespace coordinates {

int8_t Z(const Coordinates& coordinates);

byte Distance(const Coordinates& coordinates1, const Coordinates& coordinates2);

}  // namespace coordinates

}  // namespace position

#endif