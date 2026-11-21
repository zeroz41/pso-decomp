#ifndef PSO_SYSTEM_AREASOUND_H
#define PSO_SYSTEM_AREASOUND_H

#include "types.h"
#include <dolphin/mtx.h>

// Play the current area's variant of a sound effect at a world position.
void play_area_variant_sound(Vec *position);
void play_area_se_with_particle(Vec *position);
void play_area_sound_effect(Vec *position);

#endif
