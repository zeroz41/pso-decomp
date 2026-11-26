#ifndef PSO_UI_WINDOW_LISTPAGEINDICATOR_H
#define PSO_UI_WINDOW_LISTPAGEINDICATOR_H

#include "types.h"

struct PageIndicator;
struct WindowDrawContext;

void draw_page_arrow_left(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);
void draw_page_arrow_right(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);

// Restarts the indicator at page 0 of `count` pages.
s32 reset_list_page_indicator(PageIndicator *indicator, s8 count);
// Turns to `page`, starting the arrow slide toward it; 0 when already there.
s32 set_list_page(PageIndicator *indicator, s8 page);

#endif
