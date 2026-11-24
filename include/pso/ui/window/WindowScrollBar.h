#ifndef PSO_UI_WINDOW_WINDOWSCROLLBAR_H
#define PSO_UI_WINDOW_WINDOWSCROLLBAR_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include <stddef.h>

// A window list scroll bar. The extent gives the width and height of the
// list contents. The scroll offset is bounded by the visible height.
struct WindowDrawContext;

struct WindowScrollBar {
    NJS_POINT2 extent;
    s32 frame;

    WindowScrollBar(const NJS_POINT2 *extent);
    void set_extent(const NJS_POINT2 *size);
    s32 clamp_offset(f32 *offset, const NJS_POINT2 *visible) const;
    void increment_counter();
};

extern "C" void draw_window_scrollbar(const WindowScrollBar *scroll, WindowDrawContext *context, const f32 *offset);

LAYOUT_ASSERT(WindowScrollBar_size, sizeof(WindowScrollBar) == 0xC);
LAYOUT_ASSERT(WindowScrollBar_extent, offsetof(WindowScrollBar, extent) == 0);
LAYOUT_ASSERT(WindowScrollBar_frame, offsetof(WindowScrollBar, frame) == 8);

#endif
