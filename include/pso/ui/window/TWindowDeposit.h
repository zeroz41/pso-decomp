#ifndef PSO_UI_WINDOW_TWINDOWDEPOSIT_H
#define PSO_UI_WINDOW_TWINDOWDEPOSIT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowDeposit : public TWindowBase {
    virtual ~TWindowDeposit();
    virtual void render();
    f32 m_60;
    f32 scale;
    void render_status(s32 ctx);
    virtual void run_task();
    u8 unk_68[0x4];
};

LAYOUT_ASSERT(TWindowDeposit_size, sizeof(TWindowDeposit) == 0x6C);

extern "C" {
u8 *TWindowDeposit__ct(u8 *arg0, s16 client);
}

// --- C functions defined in TWindowDeposit.cpp ---
extern "C" {
u8 *TWindowDeposit__ct(u8 *arg0, s16 client);
}
// --- end of C functions

#endif
