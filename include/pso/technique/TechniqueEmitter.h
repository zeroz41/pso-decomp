#ifndef PSO_TECHNIQUE_TECHNIQUEEMITTER_H
#define PSO_TECHNIQUE_TECHNIQUEEMITTER_H

#include "types.h"

// One particle emitter an area technique places for a band (TObjPlayer::get_level_tier): the
// particle entry, flags (0x40 scales the emitter by scale, 0x20 attaches the technique model
// numbered by the high half) and the scale.
struct TechniqueEmitter {
    u32 entry;
    u32 flags;
    f32 scale;
};

// A band's emitters.
struct TechniqueEmitterSet {
    const TechniqueEmitter *emitters;
    u32 count;
};

#endif
