#ifndef PSO_SYSTEM_SOUNDEFFECT_H
#define PSO_SYSTEM_SOUNDEFFECT_H

#include "types.h"

extern "C" {
// Plays a one-shot sound effect at a world position.
void play_sound_effect(s32 id, void *pos, s32 a2, s32 a3);
}

#endif
