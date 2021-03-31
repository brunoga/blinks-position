#ifndef POSITION_H_
#define POSITION_H_

#include <blinklib.h>

namespace position {

struct Coordinates {
  int8_t x;
  int8_t y;
};

Coordinates Local(byte relative_remote_face, Coordinates remote);

Coordinates Remote(byte relative_local_face, Coordinates local);

int8_t Z(Coordinates coordinates);

byte Distance(Coordinates coordinates1, Coordinates coordinates2);

}  // namespace position

#endif
