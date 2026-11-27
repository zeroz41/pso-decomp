#ifndef PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H
#define PSO_UI_WINDOW_TWINDOWMESSAGESCROLL_H

#include <stddef.h>
#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowMessageQuest.h"

struct TWindowMessageScroll : public TWindowMessageQuest {
    TWindowMessageScroll(const NJS_POINT2 *position, s32 *done);
    virtual ~TWindowMessageScroll();
    static const char *class_name;
    void run_task();
    void set_scroll_speed(f32 speed);
    f32 scroll_speed;
    s32 * completion_register;
};

LAYOUT_ASSERT(TWindowMessageScroll_scroll_speed_offset, offsetof(TWindowMessageScroll, scroll_speed) == 0x94);
LAYOUT_ASSERT(TWindowMessageScroll_size, sizeof(TWindowMessageScroll) == 0x9C);

TWindowMessageScroll *open_message_scroll_window(const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 *completion);

#endif
