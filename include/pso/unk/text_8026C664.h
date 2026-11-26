#ifndef PSO_UNK_TEXT_8026C664_H
#define PSO_UNK_TEXT_8026C664_H

#include "types.h"

struct PageIndicator;
struct WindowDrawContext;

void draw_page_arrow_left(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);
void draw_page_arrow_right(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);

// Restarts the indicator at page 0 of `count` pages.
s32 reset_page_indicator(PageIndicator *indicator, s8 count);
// Turns to `page`, starting the arrow slide toward it; 0 when already there.
s32 turn_page_indicator(PageIndicator *indicator, s8 page);

#endif
