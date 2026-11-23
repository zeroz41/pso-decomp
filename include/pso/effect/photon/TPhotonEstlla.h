#ifndef PSO_EFFECT_PHOTON_TPHOTONESTLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONESTLLA_H

#include "types.h"
#include "pso/effect/photon/PhotonBlastSummon.h"

struct TPhotonEstlla : public TPhotonBlastSummon {
    TPhotonEstlla(u8 *arg1);
    virtual ~TPhotonEstlla();
    void sub_801AA6F8();
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
    u32 m_1a0;
    void spawn_line();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TPhotonEstlla_size, sizeof(TPhotonEstlla) == 0x1A4);

#endif
