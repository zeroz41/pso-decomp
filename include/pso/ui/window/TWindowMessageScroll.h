#ifndef PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H
#define PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowMessageQuest.h"

struct TWindowMessageScroll : public TWindowMessageQuest {
    TWindowMessageScroll(s32 parent, s32 *done);
    virtual ~TWindowMessageScroll();
    void run_task();
    void set_scroll_speed(f32 speed);
    f32 scroll_speed;
    s32 * completion_register;
};

LAYOUT_ASSERT(TWindowMessageScroll_scroll_speed_offset, offsetof(TWindowMessageScroll, scroll_speed) == 0x94);
LAYOUT_ASSERT(TWindowMessageScroll_size, sizeof(TWindowMessageScroll) == 0x9C);

extern "C" {
void *__dt__20TWindowMessageScrollFv(void *arg0, s16 arg1);
}

#endif
