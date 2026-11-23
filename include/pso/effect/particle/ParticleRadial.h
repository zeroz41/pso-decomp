#ifndef PSO_EFFECT_PARTICLE_PARTICLERADIAL_H
#define PSO_EFFECT_PARTICLE_PARTICLERADIAL_H

#include "types.h"

extern "C" {
u8 *create_radial_particle(u8 *param, u8 *pos, s32 parent, u16 flags, s16 target_id);
}
void *create_random_particle(void *param, void *pos, void *parent);
void destroy_keyboard_objects(void *object);

#endif
