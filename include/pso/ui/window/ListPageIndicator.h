#ifndef PSO_UI_WINDOW_LISTPAGEINDICATOR_H
#define PSO_UI_WINDOW_LISTPAGEINDICATOR_H

#include "types.h"

struct PageIndicator;
struct WindowDrawContext;

void draw_page_arrow_left(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);
void draw_page_arrow_right(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);

#endif
