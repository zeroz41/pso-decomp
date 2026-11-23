#ifndef PSO_EFFECT_PARTICLE_PARTICLEORBIT_H
#define PSO_EFFECT_PARTICLE_PARTICLEORBIT_H

#include "types.h"

class TObject;
class TUnk_8048E728;
struct ParticleAngles;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that circles its spawn point.
TUnk_8048E728 *create_orbit_particle(ParticleParam *entry, Vec *position, ParticleAngles *direction,
                                     TObject *parent, u16 flags, u16 target_id);

#endif
