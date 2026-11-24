#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H

#include "types.h"

extern "C" {
u32 calc_fullwidth_text_width(char *s);
}
s32 calc_ci4_tile_offset(u32 arg0, u32 arg1);
extern "C" {
u8 calc_gauge_scale__20TWindowSubStatusDispFUsPvl(u16 glyph, void *quad, s32 color);
u32 calc_text_width(char *s);
void draw_menu_font_string(const char *s, s32 color, u32 flags, f32 x, f32 y, f32 scale);
void draw_menu_font_string_white(const char *text, f32 x, f32 y);
u32 get_font_char_advance(u16 arg0);
u16 map_char_to_font_code(u16 c);
}
void upload_font_glyph(u16 c, void *free_slot);

#endif
