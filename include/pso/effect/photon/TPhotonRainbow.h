#ifndef PSO_EFFECT_PHOTON_TPHOTONRAINBOW_H
#define PSO_EFFECT_PHOTON_TPHOTONRAINBOW_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TPhotonRainbow : public TObjBase {
    virtual ~TPhotonRainbow();
    u32 m_90;
    u32 m_94;
    uaddr m_98;
    uaddr m_9c;
    u8 _padA0[0x8];
    u32 m_a8;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TPhotonRainbow_size, sizeof(TPhotonRainbow) == 0xAC);

extern "C" {
void *__dt__14TPhotonRainbowFv(void *arg0, s16 arg1);
}

#endif
