#include "position.h"

namespace position {

static Coordinates local_;

void Setup(byte source_relative_face, int8_t source_x, int8_t source_y) {
  local_ = coordinates::SourceToDestination(source_relative_face,
                                            {source_x, source_y});
}

void Reset() { local_ = Coordinates{0, 0}; }

void Update(int8_t x, int8_t y) {
  local_.x = x;
  local_.y = y;
}

const Coordinates& Local() { return local_; }

Coordinates Remote(byte local_relative_face) {
  return coordinates::SourceToDestination(local_relative_face, local_);
}

byte __attribute__((noinline)) Distance(Coordinates destination) {
  return coordinates::Distance(local_, destination);
}

}  // namespace position
