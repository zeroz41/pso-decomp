#ifndef PSO_EFFECT_PARTICLE_PARTICLEBALLISTIC_H
#define PSO_EFFECT_PARTICLE_PARTICLEBALLISTIC_H

#include "types.h"

class TObject;
class TParticle;
struct ParticleAngles;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that flies off along its direction.
TParticle *create_ballistic_particle(ParticleParam *entry, Vec *position, ParticleAngles *direction,
                                         TObject *parent, u16 flags, u16 target_id);

#endif
