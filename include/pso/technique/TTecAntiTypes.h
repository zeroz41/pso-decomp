#ifndef PSO_TECHNIQUE_TTECANTITYPES_H
#define PSO_TECHNIQUE_TTECANTITYPES_H

#include "types.h"

// A particle emitter of the Anti effect: it starts after `delay` frames, `count` times; bit 0 of flags puts it at the
// ground position instead of the body position.
struct AntiEmitterRow { s32 delay; s32 count; s32 id; s32 flags; };

#endif
