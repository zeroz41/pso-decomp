#ifndef PSO_EFFECT_PARTICLE_PARTICLEORBIT_H
#define PSO_EFFECT_PARTICLE_PARTICLEORBIT_H

#include "types.h"

class TObject;
class TParticle;
struct ParticleAngles;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that circles its spawn point.
TParticle *create_orbit_particle(ParticleParam *entry, Vec *position, ParticleAngles *direction,
                                     TObject *parent, u16 flags, u16 target_id);

#endif
