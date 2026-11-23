#ifndef PSO_UNK_TEXT_80086B64_H
#define PSO_UNK_TEXT_80086B64_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/effect/particle/TParticleCtrl.h"

TParticleCtrl *create_particle_controller_with_rotation(Vec *position, ParticleAngles *rotation, s32 id, s32 a, s32 b);

#endif
