#ifndef PSO_MISC_TWINDOWDEPOSIT_H
#define PSO_MISC_TWINDOWDEPOSIT_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowDeposit : public TWindowBase {
    virtual ~TWindowDeposit();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 unk_28[0x10];
    f32 m_38;
    u8 unk_3C[0x24];
    f32 m_60;
    void* m_64;
    void render_status(s32 arg1);
    virtual void run_task();
    u8 unk_68[0x4];
};

typedef char TWindowDeposit_size[sizeof(TWindowDeposit) == 0x6C ? 1 : -1];

extern "C" {
u8 *TWindowDeposit__ct(u8 *arg0, s32 arg1);
void *__dt__14TWindowDepositFv(void *arg0, s16 arg1);
void render__14TWindowDepositFv(s32 arg0);
}

// --- C functions defined in TWindowDeposit.cpp ---
extern "C" {
u8 *TWindowDeposit__ct(u8 *arg0, s32 arg1);
void *__dt__14TWindowDepositFv(void *arg0, s16 arg1);
void render__14TWindowDepositFv(s32 arg0);
}
// --- end of C functions

#endif
