#ifndef PSO_OBJECT_TOBJPARTICLE_H
#define PSO_OBJECT_TOBJPARTICLE_H

#include "pso/object/base/TObjMotion.h"
#include <stddef.h>

class TParticleCtrl;

struct TObjParticle : public TObjBase {
    TObjParticle(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjParticle();
    static void *create(ObjectSetData *set_data);
    virtual void render();
    virtual void run_task();

    TParticleCtrl *emitter;
    s32 particle_id;
};

LAYOUT_ASSERT(TObjParticle_size, sizeof(TObjParticle) == 0x98);
LAYOUT_ASSERT(TObjParticle_emitter_offset, offsetof(TObjParticle, emitter) == 0x90);
LAYOUT_ASSERT(TObjParticle_id_offset, offsetof(TObjParticle, particle_id) == 0x94);

#endif
