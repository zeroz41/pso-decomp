#ifndef PSO_MISC_TPHOTONRAINBOW_H
#define PSO_MISC_TPHOTONRAINBOW_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TPhotonRainbow : public TObjBase {
    virtual ~TPhotonRainbow();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    u8 _padA0[0x8];
    u32 m_a8;
    virtual void render();
    virtual void run_task();
};

typedef char TPhotonRainbow_size[sizeof(TPhotonRainbow) == 0xAC ? 1 : -1];

extern "C" {
void *__dt__14TPhotonRainbowFv(void *arg0, s16 arg1);
}

#endif
