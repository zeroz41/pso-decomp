#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8024FBA8_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8024FBA8_H

#include "types.h"

s32 draw_small_font_string_clipped(f32 *pos, const char *s, u32 color, f32 width);
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern "C" {
void set_text_draw_params(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
}

#endif
