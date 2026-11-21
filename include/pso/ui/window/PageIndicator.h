#ifndef PSO_UI_WINDOW_PAGEINDICATOR_H
#define PSO_UI_WINDOW_PAGEINDICATOR_H

#include "types.h"
#include <stddef.h>

struct WindowDrawContext;

// Allocated by the status, shortcut and card-list windows. The page-flip
// controller at 0x8026C9DC and renderer at 0x8026C800 share this layout.
struct PageIndicator {
    s8 page;
    s8 count;
    u8 pad_02[2];
    s32 input_port;
    f32 arrow_offset;

    // Observed dynamic callers already sign-extend the two byte values.
    PageIndicator(s8 page, s8 count, s32 client);
    s8 get_type();
};

LAYOUT_ASSERT(PageIndicator_size, sizeof(PageIndicator) == 0xC);
LAYOUT_ASSERT(PageIndicator_input_port, offsetof(PageIndicator, input_port) == 4);
LAYOUT_ASSERT(PageIndicator_arrow_offset, offsetof(PageIndicator, arrow_offset) == 8);

extern "C" {
void draw_list_page_indicator(PageIndicator *, WindowDrawContext *);
s32 handle_list_page_flip_input(PageIndicator *);
void decay_page_arrow_offset(PageIndicator *);
}

// Ordinary global-storage release; this known page object has trivial cleanup.
void *delete_if_allocated(void *storage, s16 release);

#endif
