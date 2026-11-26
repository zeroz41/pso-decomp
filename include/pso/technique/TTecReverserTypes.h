#ifndef PSO_TECHNIQUE_TTECREVERSERTYPES_H
#define PSO_TECHNIQUE_TTECREVERSERTYPES_H

#include "types.h"

// A particle emitter of the revival effect: it starts after `delay` frames, `count` times.
struct RevivalEmitter { s32 delay; s32 count; s32 id; s32 pad; };

#endif
