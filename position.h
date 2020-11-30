#ifndef POSITION_H_
#define POSITION_H_

#include <blinklib.h>

#include "coordinates.h"

namespace position {

// Set up the local Blink position based on the given parameters. The
// relative_local_face parameter is the relative face number of the face we got
// the given remote_x and remote_y coordinates from so it needs to be sent from
// one Blink to the other in some way (either using face values or datagrams).
void Setup(byte relative_local_face, int8_t remote_x, int8_t remote_y);

// Resets the local Blink position to 0, 0, 0.
void Reset();

// Returns the coordinates for the local Blink.
Coordinates Local();

// Returns the coordinates for the Blink connected to the given
// relative_local_face.
Coordinates Remote(byte relative_local_face);

byte Distance(Coordinates coordinates);

}  // namespace position

#endif