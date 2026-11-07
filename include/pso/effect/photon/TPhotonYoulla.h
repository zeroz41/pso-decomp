#ifndef PSO_EFFECT_PHOTON_TPHOTONYOULLA_H
#define PSO_EFFECT_PHOTON_TPHOTONYOULLA_H

#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

struct TPhotonYoulla : public TUnk_804C3248 {
    virtual ~TPhotonYoulla();
    // The ctor passes byte +0x1C of its spawn record; the body ignores it.
    void sub_801AE72C(u8);
    u8 unk_158[0x24];
    u16 m_17c;
    u8 _pad17E[0x2];
    u32 m_180;
    void* m_184;
    u8 unk_188[0x4];
    float m_18c;
    u8 unk_190[0x4];
    u16 m_194;
    u8 _pad196[0x2];
    u32 m_198;
    u32 m_19c;
    u32 m_1a0;
    u32 m_1a4;
    virtual void render();
    virtual void run_task();
};

typedef char TPhotonYoulla_size[sizeof(TPhotonYoulla) == 0x1A8 ? 1 : -1];

extern "C" {
void TObjPlayer__sub_801AEB74(void);
void TObjPlayer__sub_801AEB80(void);
u8 *TPhotonYoulla__ct(TPhotonYoulla *arg0, u8 *arg1);
void *__dt__13TPhotonYoullaFv(void *arg0, s16 arg1);
}

#endif
