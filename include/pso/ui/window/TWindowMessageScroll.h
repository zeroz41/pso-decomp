#ifndef PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H
#define PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H

#include "types.h"
#include "pso/ui/window/TWindowMessageQuest.h"

struct TWindowMessageScroll : public TWindowMessageQuest {
    TWindowMessageScroll(s32 parent, s32 *done);
    virtual ~TWindowMessageScroll();
    void run_task();
    u8 unk_94[0x4];
    s32 * m_98;
};

LAYOUT_ASSERT(TWindowMessageScroll_size, sizeof(TWindowMessageScroll) == 0x9C);

extern "C" {
void *__dt__20TWindowMessageScrollFv(void *arg0, s16 arg1);
}

#endif
