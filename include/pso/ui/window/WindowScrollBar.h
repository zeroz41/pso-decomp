#ifndef PSO_UI_WINDOW_WINDOWSCROLLBAR_H
#define PSO_UI_WINDOW_WINDOWSCROLLBAR_H

#include "types.h"
#include <stddef.h>

// A window list scroll bar (0xC bytes): created with the list extent, positioned by
// copy_position, clamped by clamp_list_scroll_offset and drawn by draw_window_scrollbar.
// The position input carries two floats.
struct WindowScrollBar {
    f32 m_0;
    f32 height;
    s32 frame;

    WindowScrollBar(void *pair);
    void copy_position(void *pair);
};

LAYOUT_ASSERT(WindowScrollBar_size, sizeof(WindowScrollBar) == 0xC);
LAYOUT_ASSERT(WindowScrollBar_height, offsetof(WindowScrollBar, height) == 4);
LAYOUT_ASSERT(WindowScrollBar_frame, offsetof(WindowScrollBar, frame) == 8);

#endif
