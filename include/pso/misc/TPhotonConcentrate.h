#ifndef PSO_MISC_TPHOTONCONCENTRATE_H
#define PSO_MISC_TPHOTONCONCENTRATE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TPhotonConcentrate : public TObjCollidable {
    TPhotonConcentrate(u8 *arg1, s32 arg2, s32 arg3);
    virtual ~TPhotonConcentrate();
    virtual void render();
    virtual void run_task();
    void* m_ac;
    u8 _padB0[0x8];
    u32 m_b8;
    u32 m_bc;
    u32 m_c0;
    void* m_c4;
    u8 unk_C8[0x4];
    f32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u32 m_d8;
    u8 unk_DC[0x8];
    f32 m_e4;
    u8 unk_E8[0x4];
    u32 m_ec;
    u32 m_f0;
    u8 _padF4[0x4];
    u32 m_f8;
    u32 m_fc;
    u8 unk_100[0xC];
};

typedef char TPhotonConcentrate_size[sizeof(TPhotonConcentrate) == 0x10C ? 1 : -1];

extern "C" {
u8 *__ct__18TPhotonConcentrateFPUcll(u8 *photon_concentrate, u8 *arg1, s32 arg2, s32 arg3);
void *__dt__18TPhotonConcentrateFv(void *arg0, s16 arg1);
void render__18TPhotonConcentrateFv(void);
}

// --- C functions defined in TPhotonConcentrate.cpp ---
extern "C" {
void *__dt__18TPhotonConcentrateFv(void *arg0, s16 arg1);
void render__18TPhotonConcentrateFv(void);
}
// --- end of C functions

#endif
