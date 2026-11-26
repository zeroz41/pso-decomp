#ifndef PSO_UNK_TEXT_8026C664_H
#define PSO_UNK_TEXT_8026C664_H

#include "types.h"

struct PageIndicator;
struct WindowDrawContext;

void fn_8026C664(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);
void fn_8026C708(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset);

// Restarts the indicator at page 0 of `count` pages.
s32 fn_8026C7AC(PageIndicator *indicator, s8 count);
// Turns to `page`, starting the arrow slide toward it; 0 when already there.
s32 fn_8026C7C0(PageIndicator *indicator, s8 page);

#endif
