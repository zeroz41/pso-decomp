#ifndef PSO_EFFECT_PARTICLE_PARTICLERADIAL_H
#define PSO_EFFECT_PARTICLE_PARTICLERADIAL_H

#include "types.h"

extern "C" {
void *__dt__13TUnk_8048E7A8Fv(void *arg0, s16 arg1);
}
u8 *construct_radial_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5);
extern "C" {
u8 *create_radial_particle(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, s16 arg4);
}
void *create_random_particle(void *arg0, void *arg1, void *arg2);
extern "C" {
void destroy_keyboard_objects(void *_w0);
}

// --- C functions defined in ParticleRadial.cpp ---
extern "C" {
u8 *create_radial_particle(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, s16 arg4);
void destroy_keyboard_objects(void *_w0);
}
// --- end of C functions

#endif
