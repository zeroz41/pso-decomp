#ifndef PSO_EFFECT_PARTICLE_PARTICLEBALLISTIC_H
#define PSO_EFFECT_PARTICLE_PARTICLEBALLISTIC_H

#include "types.h"

class TObject;
class TUnk_8048E728;
struct ParticleAngles;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that flies off along its direction.
TUnk_8048E728 *create_ballistic_particle(ParticleParam *entry, Vec *position, ParticleAngles *direction,
                                         TObject *parent, u16 flags, u16 target_id);

#endif
