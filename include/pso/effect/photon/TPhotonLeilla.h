#ifndef PSO_EFFECT_PHOTON_TPHOTONLEILLA_H
#define PSO_EFFECT_PHOTON_TPHOTONLEILLA_H

#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

struct TPhotonLeilla : public TUnk_804C3248 {
    virtual ~TPhotonLeilla();
    void sub_801AC444();
    u8 _pad158[0x24];
    u16 m_17c;
    u8 _pad17E[0x2];
    void* m_180;
    u8 unk_184[0x4];
    float m_188;
    u8 unk_18C[0x4];
    u16 m_190;
    u8 _pad192[0x2];
    u32 m_194;
    u32 m_198;
    u32 m_19c;
    u8 _pad1A0[0xC];
    u32 m_1ac;
    virtual void render();
    virtual void run_task();
};

typedef char TPhotonLeilla_size[sizeof(TPhotonLeilla) == 0x1B0 ? 1 : -1];

extern "C" {
void TObjPlayer__sub_801AC43C(void);
void TObjPlayer__sub_801AC440(void);
}

#endif
