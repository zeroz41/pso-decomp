#ifndef PSO_EFFECT_PARTICLE_PARTICLESTRIP_H
#define PSO_EFFECT_PARTICLE_PARTICLESTRIP_H

#include "types.h"

// One vertex of a particle strip as emit_particle_strip_vertices sends it (colour is ARGB).
struct ParticleStripVertex {
    f32 x, y, z;
    f32 u, v;
    u32 color;
};

// Loads the camera view matrix, the textured vertex state (alpha blended when blended is set) and the
// render context's texture for a particle strip.
void setup_particle_draw(s32 blended);
// Ends a particle strip draw.
void end_particle_draw();
// Sends count vertices as one triangle strip in the particle vertex format.
void emit_particle_strip_vertices(ParticleStripVertex *vertices, s32 count);
// Draws count vertices as one textured triangle strip, alpha blended when blended is set.
void draw_particle_strip(ParticleStripVertex *vertices, s32 count, s32 blended);

#endif
