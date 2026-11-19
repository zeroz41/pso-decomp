#ifndef PSO_EFFECT_PARTICLE_TPARTICLECTRL_80085EE4_H
#define PSO_EFFECT_PARTICLE_TPARTICLECTRL_80085EE4_H

#include "types.h"

// Child generators of an emitter: TParticleCtrl::run_task calls
// particle_ctrl_generator_table[kind].create(param, &pos, parent).
struct ParticleGenerator {
    const char *name;
    void *(*create)(void *param, void *pos, void *parent);
};

extern ParticleGenerator particle_ctrl_generator_table[];

#endif
