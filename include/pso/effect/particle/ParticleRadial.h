#ifndef PSO_EFFECT_PARTICLE_PARTICLERADIAL_H
#define PSO_EFFECT_PARTICLE_PARTICLERADIAL_H

#include "types.h"

class TObject;
class TUnk_8048E728;
struct ParticleParam;
struct Vec;

// A child particle of an emitter that moves out from its spawn point.
TUnk_8048E728 *create_radial_particle(ParticleParam *entry, Vec *position, TObject *parent, u16 flags,
                                      u16 target_id);
TUnk_8048E728 *create_random_particle(void *param, void *pos, void *parent);
void destroy_keyboard_objects(void *object);

#endif
