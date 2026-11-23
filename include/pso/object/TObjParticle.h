#ifndef PSO_OBJECT_TOBJPARTICLE_H
#define PSO_OBJECT_TOBJPARTICLE_H

#include "pso/object/base/TObjMotion.h"
#include <stddef.h>

class TParticleCtrl;

// Only the portion read by the particle constructor is known here.
struct ParticleSetData {
    u8 unknown[0xC];
    Vec position;
    s32 rotation[3];
    Vec params;
    s32 set_params[3];
};

struct TObjParticle : public TObjBase {
    TObjParticle(TObject *parent, ParticleSetData *set_data);
    virtual ~TObjParticle();
    static void *create(void *set_data);
    virtual void render();
    virtual void run_task();

    TParticleCtrl *emitter;
    s32 particle_id;
};

LAYOUT_ASSERT(TObjParticle_size, sizeof(TObjParticle) == 0x98);
LAYOUT_ASSERT(TObjParticle_emitter_offset, offsetof(TObjParticle, emitter) == 0x90);
LAYOUT_ASSERT(TObjParticle_id_offset, offsetof(TObjParticle, particle_id) == 0x94);
LAYOUT_ASSERT(ParticleSetData_params_offset, offsetof(ParticleSetData, params) == 0x24);
LAYOUT_ASSERT(ParticleSetData_ints_offset, offsetof(ParticleSetData, set_params) == 0x30);

#endif
