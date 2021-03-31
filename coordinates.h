#ifndef COORDINATES_H_
#define COORDINATES_H_

#include <blinklib.h>

namespace position {

struct Coordinates {
  int8_t x;
  int8_t y;
};

namespace coordinates {

Coordinates SourceToDestination(byte source_relative_face, Coordinates source);

int8_t Z(Coordinates coordinates);

byte Distance(Coordinates coordinates1, Coordinates coordinates2);

}  // namespace coordinates

}  // namespace position

#endif