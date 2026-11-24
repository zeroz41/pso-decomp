#ifndef PSO_SYSTEM_SOUNDEFFECT_H
#define PSO_SYSTEM_SOUNDEFFECT_H

#include "types.h"

struct Vec;

extern "C" {
// Plays a one-shot sound effect at a world position; returns the request
// handle stop_sound_request takes.
s32 play_sound_effect(s32 id, const Vec *position, s32 adjustment, s32 flags);
}

#endif
