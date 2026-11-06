#ifndef PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H
#define PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H

#include "types.h"
#include "pso/ui/window/TWindowMessageQuest.h"

struct TWindowMessageScroll : public TWindowMessageQuest {
    virtual ~TWindowMessageScroll();
    void run_task();
    u8 unk_94[0x4];
    s32 * m_98;
};

typedef char TWindowMessageScroll_size[sizeof(TWindowMessageScroll) == 0x9C ? 1 : -1];

extern "C" {
u8 *TWindowMessageScroll__ct(u8 *window_message_scroll, s32 arg1, s32 *arg2);
void *__dt__20TWindowMessageScrollFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowMessageScroll.cpp ---
extern "C" {
u8 *TWindowMessageScroll__ct(u8 *window_message_scroll, s32 arg1, s32 *arg2);
}
// --- end of C functions

#endif
