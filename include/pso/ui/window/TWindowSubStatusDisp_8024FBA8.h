#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8024FBA8_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8024FBA8_H

#include "types.h"

struct WindowDrawContext;

s32 draw_small_font_string_clipped(f32 *pos, const char *s, u32 color, f32 width);
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern "C" {
void set_text_draw_params(WindowDrawContext *context, s32 clip, s32 mode, f32 depth, f32 right_limit);
}

#endif
