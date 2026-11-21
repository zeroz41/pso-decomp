#ifndef PSO_UI_WINDOW_SCROLL_8026D790_H
#define PSO_UI_WINDOW_SCROLL_8026D790_H

#include "types.h"
#include <stddef.h>

// The position input carries two floats.
struct Scroll_8026D790 {
    f32 m_0;
    f32 height;
    s32 frame;

    Scroll_8026D790(void *pair);
    void copy_position(void *pair);
};

LAYOUT_ASSERT(Scroll_8026D790_size, sizeof(Scroll_8026D790) == 0xC);
LAYOUT_ASSERT(Scroll_8026D790_height, offsetof(Scroll_8026D790, height) == 4);
LAYOUT_ASSERT(Scroll_8026D790_frame, offsetof(Scroll_8026D790, frame) == 8);

#endif
