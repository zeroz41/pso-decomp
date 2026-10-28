#ifndef PSO_OBJECT_TOBJPARTICLE_H
#define PSO_OBJECT_TOBJPARTICLE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjParticle : public TObjBase {
    virtual ~TObjParticle();
    u32 m_90;
    u32 m_94;
    virtual void render();
    virtual void run_task();
};

typedef char TObjParticle_size[sizeof(TObjParticle) == 0x98 ? 1 : -1];

extern "C" {
u8 *TObjParticle__create(u8 *arg0);
void *__dt__12TObjParticleFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjParticle.cpp ---
extern "C" {
u8 *TObjParticle__create(u8 *arg0);
void *__dt__12TObjParticleFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
