#ifndef PSO_SYSTEM_SOUNDEFFECT_H
#define PSO_SYSTEM_SOUNDEFFECT_H

#include "types.h"

struct Vec;

extern "C" {
// Plays a one-shot sound effect at a world position (NULL: not positional); returns the request
// handle stop_sound_request takes.
s32 play_sound_effect(s32 id, const Vec *position, s32 volume, s32 flags);
}

// Starts the looping sound id for actor (compared by address only) at position (NULL: not positional), or
// keeps it alive when it is already playing; called every frame the sound should continue. Flag 1 skips
// the range check, flag 2 adds volume (clamped to 0 or below) to the id's base volume. Returns the sound
// slot, or a negative value.
s32 play_persistent_sound(s32 id, const void *actor, const Vec *position, s32 volume, s32 flags);

#endif
