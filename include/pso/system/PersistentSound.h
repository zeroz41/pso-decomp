#ifndef PSO_SYSTEM_PERSISTENT_SOUND_H
#define PSO_SYSTEM_PERSISTENT_SOUND_H

#include "types.h"

struct Vec;

// A persistent request keeps its identity and position until the sound is
// refreshed or released. A null position selects the existing unpositioned path.
extern "C" s32 play_persistent_sound(s32 id, const void *identity, const Vec *position, s32 adjustment, s32 flags);

s32 normalize_sound_request(u32 id, const void *actor, const Vec *position, s32 arg3, s32 arg4);

#endif
