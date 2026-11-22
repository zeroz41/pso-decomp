#ifndef PSO_EFFECT_PARTICLE_PARTICLEORBIT_H
#define PSO_EFFECT_PARTICLE_PARTICLEORBIT_H

#include "types.h"

extern "C" {
u8 *create_orbit_particle(u8 *arg0, u8 *pos, u8 *dir, s32 parent, u16 flags, s16 target_id);
}

#endif
