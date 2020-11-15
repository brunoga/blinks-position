#ifndef POSITION_H_
#define POSITION_H_

#include <blinklib.h>

namespace position {

struct Coordinates {
  int8_t x;
  int8_t y;
  int8_t z;
};

// Set x and y coordinates for the Blink. The z coordinate is computed based on
// the other 2.
void Set(int8_t x, int8_t y);

// Returns the coordinates for the Blink.
Coordinates Get();

// Returns the coordinate for a Blink connected to the given global relative
// face.
Coordinates AtFace(byte global_relative_face);

}  // namespace position

#endif