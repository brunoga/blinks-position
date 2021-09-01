#ifndef POSITION_H_
#define POSITION_H_

#include <blinklib.h>

#include "coordinates.h"

namespace position {

// Sets the local Blink position to the given coordinates.
void SetCoordinates(Coordinates coordinates);

// Returns the coordinates for the local Blink position.
Coordinates GetCoordinates();

// Computes the local Blink position coordinates based on the given parameters.
// The relative_local_face parameter is the relative face number of the face we
// got the given remote_coordinates from so it needs to be sent from one Blink
// to the other in some way (either using face values or datagrams). This does
// not change the current position.
Coordinates ComputeCoordinates(byte relative_local_face,
                               Coordinates remote_coordinates);

// Computes the axial distance between the local Blink coordinates and the given
// coordinates.
byte Distance(Coordinates coordinates);

}  // namespace position

#endif
