#ifndef COORDINATES_H_
#define COORDINATES_H_

#include <stdint.h>

namespace position {

class Coordinates {
 public:
  Coordinates();
  Coordinates(int8_t x, int8_t y);

  int8_t X() const;
  int8_t Y() const;
  int8_t Z() const;

 private:
  int8_t x_;
  int8_t y_;
};

}  // namespace position

#endif