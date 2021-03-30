#include <blinklib.h>

#include "position.h"
#include "src/blinks-debug/debug.h"

void setup() {
  // Set ourselves as the origin. Assume our relative local faces and absolute
  // local faces match.
  position::Setup(0, 0, 0);
}

void loop() {
  FOREACH_FACE(face) {
    position::Coordinates remote_position = position::Remote(face);
    LOGF("Remote position for face ");
    LOG(face);
    LOGF(" is ");
    LOG(remote_position.x);
    LOGF(",");
    LOGLN(remote_position.y);
  }
}
