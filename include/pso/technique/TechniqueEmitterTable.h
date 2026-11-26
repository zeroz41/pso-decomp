#ifndef PSO_TECHNIQUE_TECHNIQUEEMITTERTABLE_H
#define PSO_TECHNIQUE_TECHNIQUEEMITTERTABLE_H

#include "types.h"

// One particle a technique spawns: its particle entry, spawn flags and scale.
struct TechniqueEmitterSourceRow { u32 entry; u32 flags; f32 scale; };
// The particles a technique spawns at one level band.
struct TechniqueEmitterSourceTable { const TechniqueEmitterSourceRow *rows; u32 count; };

#endif
