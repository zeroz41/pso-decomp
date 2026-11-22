#ifndef PSO_EFFECT_PARTICLE_PARTICLERADIAL_H
#define PSO_EFFECT_PARTICLE_PARTICLERADIAL_H

#include "types.h"

extern "C" {
u8 *create_radial_particle(u8 *arg0, u8 *pos, s32 parent, u16 flags, s16 target_id);
}
void *create_random_particle(void *arg0, void *pos, void *parent);
void destroy_keyboard_objects(void *_w0);

// --- C functions defined in ParticleRadial.cpp ---
extern "C" {
u8 *create_radial_particle(u8 *arg0, u8 *pos, s32 parent, u16 flags, s16 target_id);
}
void destroy_keyboard_objects(void *_w0);
// --- end of C functions

#endif
