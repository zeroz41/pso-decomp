#ifndef PSO_EFFECT_PARTICLE_PARTICLEFACTORY_H
#define PSO_EFFECT_PARTICLE_PARTICLEFACTORY_H

#include "types.h"

struct Vec;
class TParticleCtrl;

TParticleCtrl *spawn_particle_effect_with_flags(const Vec *position, s32 id, u16 flags);
TParticleCtrl *spawn_particle_effect(const Vec *position, s32 id);

#endif
