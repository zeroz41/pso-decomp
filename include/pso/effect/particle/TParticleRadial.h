#ifndef PSO_EFFECT_PARTICLE_TPARTICLERADIAL_H
#define PSO_EFFECT_PARTICLE_TPARTICLERADIAL_H
#include "types.h"
#include "pso/effect/particle/TParticle.h"

class TParticleRadial : public TParticle {
public:
    TParticleRadial(ParticleParam *entry, Vec *position, TObject *parent, u16 particle_flags, u16 target);
    TParticleRadial(void *param, void *pos, void *parent);
    virtual ~TParticleRadial();
    virtual void run_task();
    void check_radial_particle_retire();
    virtual void render();
};

#endif
