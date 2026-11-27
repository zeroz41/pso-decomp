#ifndef PSO_UI_WINDOW_PAGEINDICATOR_H
#define PSO_UI_WINDOW_PAGEINDICATOR_H

#include "types.h"
#include <stddef.h>

struct WindowDrawContext;

// Allocated by the status, shortcut and card-list windows. handle_list_page_flip_input
// and draw share this layout.
struct PageIndicator {
    s8 page;
    s8 count;
    u8 pad_02[2];
    s32 input_port;
    f32 arrow_offset;

    // Observed dynamic callers already sign-extend the two byte values.
    PageIndicator(s8 page, s8 count, s32 client);
    s8 get_type();
    // Restarts the indicator at page 0 of new_count pages.
    s32 reset(s8 new_count);
    // Turns to new_page, starting the arrow slide toward it; 0 when already there.
    s32 turn_to(s8 new_page);
    void draw(WindowDrawContext *r);
    void decay_arrow_offset();
    s32 handle_flip_input();
};

LAYOUT_ASSERT(PageIndicator_size, sizeof(PageIndicator) == 0xC);
LAYOUT_ASSERT(PageIndicator_input_port, offsetof(PageIndicator, input_port) == 4);
LAYOUT_ASSERT(PageIndicator_arrow_offset, offsetof(PageIndicator, arrow_offset) == 8);


// Ordinary global-storage release; this known page object has trivial cleanup.
void *delete_if_allocated(void *storage, s16 release);

#endif
