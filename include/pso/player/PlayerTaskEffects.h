#ifndef PSO_PLAYER_PLAYERTASKEFFECTS_H
#define PSO_PLAYER_PLAYERTASKEFFECTS_H

#include "types.h"

// Overrides where player `slot` appears on the next floor: at (x, y, z),
// facing `heading`.
void set_arrival_override_coords(u16 slot, s32 heading, f32 x, f32 y, f32 z);

#endif
