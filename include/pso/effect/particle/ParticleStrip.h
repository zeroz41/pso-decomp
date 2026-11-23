#ifndef PSO_EFFECT_PARTICLE_PARTICLESTRIP_H
#define PSO_EFFECT_PARTICLE_PARTICLESTRIP_H

#include "types.h"

// One vertex of a particle strip as emit_particle_strip_vertices sends it (colour is ARGB).
struct ParticleStripVertex {
    f32 x, y, z;
    f32 u, v;
    u32 color;
};

extern "C" {
// Sends count vertices as one triangle strip in the particle vertex format.
void emit_particle_strip_vertices(ParticleStripVertex *vertices, s32 count);
}

#endif
