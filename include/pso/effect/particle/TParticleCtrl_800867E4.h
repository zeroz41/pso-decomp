#ifndef PSO_EFFECT_PARTICLE_TPARTICLECTRL_800867E4_H
#define PSO_EFFECT_PARTICLE_TPARTICLECTRL_800867E4_H

#include "types.h"

extern "C" {
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
}
void *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 a, s32 b, s32 flags);
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c);

#endif
