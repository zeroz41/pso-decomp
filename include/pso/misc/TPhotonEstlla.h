#ifndef PSO_MISC_TPHOTONESTLLA_H
#define PSO_MISC_TPHOTONESTLLA_H

#include "types.h"
#include "pso/misc/TUnk_804C3248.h"

struct TPhotonEstlla : public TUnk_804C3248 {
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

typedef char TPhotonEstlla_size[sizeof(TPhotonEstlla) == 0x1A4 ? 1 : -1];

extern "C" {
void *__dt__13TPhotonEstllaFv(void *arg0, s16 arg1);
}

#endif
