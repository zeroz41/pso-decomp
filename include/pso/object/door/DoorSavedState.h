#ifndef PSO_OBJECT_DOOR_DOORSAVEDSTATE_H
#define PSO_OBJECT_DOOR_DOORSAVEDSTATE_H

#include "types.h"

// The saved state record of a door (access_object_saved_state fills it) and the part of its set
// entry the 6x0B object state message needs.
struct DoorSavedState { s16 flags; s16 unused; };
struct DoorSetEntryView { u8 pad[4]; s16 object_index; };

#endif
