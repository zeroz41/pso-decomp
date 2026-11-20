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
    virtual void render();
    virtual void run_task();

    TParticleCtrl *emitter;
    s32 particle_id;
};

typedef char TObjParticle_size[sizeof(TObjParticle) == 0x98 ? 1 : -1];
typedef char TObjParticle_emitter_offset[offsetof(TObjParticle, emitter) == 0x90 ? 1 : -1];
typedef char TObjParticle_id_offset[offsetof(TObjParticle, particle_id) == 0x94 ? 1 : -1];
typedef char ParticleSetData_params_offset[offsetof(ParticleSetData, params) == 0x24 ? 1 : -1];
typedef char ParticleSetData_ints_offset[offsetof(ParticleSetData, set_params) == 0x30 ? 1 : -1];

extern "C" u8 *TObjParticle__create(u8 *set_data);

#endif
