#ifndef PSO_TECHNIQUE_TTECGRANTSTYPES_H
#define PSO_TECHNIQUE_TTECGRANTSTYPES_H

#include "types.h"

struct GrantsEmitterPart { s32 id; u32 flags; u8 pad_08[4]; };

struct GrantsEmitterSet { const GrantsEmitterPart *parts; u32 count; };

struct GrantsEffectEntry { s32 effect; u32 flags; s32 pad_08; };

struct GrantsEffectSet { const GrantsEffectEntry *ents; u32 count; };

#endif
