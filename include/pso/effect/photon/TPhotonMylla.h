#ifndef PSO_EFFECT_PHOTON_TPHOTONMYLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONMYLLA_H

#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

struct TPhotonMylla : public TUnk_804C3248 {
    virtual ~TPhotonMylla();
    void sub_801AD4A8();
    u8 _pad158[0x24];
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

typedef char TPhotonMylla_size[sizeof(TPhotonMylla) == 0x1A8 ? 1 : -1];
#endif
