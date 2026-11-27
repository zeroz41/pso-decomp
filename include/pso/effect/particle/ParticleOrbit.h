#ifndef PSO_EFFECT_PARTICLE_PARTICLEORBIT_H
#define PSO_EFFECT_PARTICLE_PARTICLEORBIT_H

#include "types.h"

class TObject;
class TParticle;
struct Angle3;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that circles its spawn point.
TParticle *create_orbit_particle(ParticleParam *entry, Vec *position, Angle3 *direction,
                                     TObject *parent, u16 flags, u16 target_id);

#endif
