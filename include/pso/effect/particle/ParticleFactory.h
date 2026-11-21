#ifndef PSO_EFFECT_PARTICLE_PARTICLEFACTORY_H
#define PSO_EFFECT_PARTICLE_PARTICLEFACTORY_H

#include "types.h"

struct Vec;
class TParticleCtrl;

extern "C" {
TParticleCtrl *spawn_particle_effect(const Vec *position, s32 id);
TParticleCtrl *spawn_particle_effect_with_flags(const Vec *position, s32 id, s32 flags);
}

#endif
