#include <blinklib.h>

#include "position.h"
#include "src/blinks-debug/debug.h"

void setup() {}

static position::Coordinates local_;  // Starts as the origin.

void loop() {
  FOREACH_FACE(face) {
    position::Coordinates remote_position = position::Remote(face, local_);
    LOGF("Remote position for face ");
    LOG(face);
    LOGF(" is ");
    LOG(remote_position.x);
    LOGF(",");
    LOGLN(remote_position.y);
  }
}
