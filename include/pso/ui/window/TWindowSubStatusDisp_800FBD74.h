#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_800FBD74_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_800FBD74_H

#include "types.h"

extern "C" {
void TWindowSubStatusDisp__sub_800FBD74(s32 text_color, f32 x, f32 y, f32 depth);
s32 get_small_font_glyph_id(s32 c);
}
u32 calc_small_font_text_width(const char *s);
void draw_small_font_text(u32 color, const char *s, f32 x, f32 y, f32 scale);
u32 get_name_text_width(void *p);
extern "C" {
s32 get_small_font_glyph_width(u8 c);
}

#endif
