#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H

#include "types.h"

extern "C" {
u32 TWindowSubStatusDisp__sub_80144E9C(char *s);
}
s32 calc_ci4_tile_offset(u32 arg0, u32 arg1);
extern "C" {
u8 calc_gauge_scale__20TWindowSubStatusDispFPvPvi(void *arg0, void *arg1, s32 arg2);
u32 calc_text_width(char *s);
void draw_menu_font_string(const char *s, s32 arg1, u32 flags, f32 x, f32 y, f32 scale);
int end_render_forward__20TWindowSubStatusDispFPv(void *p);
void *find_cached_glyph__20TWindowSubStatusDispFUs(u16 code);
u32 get_font_char_advance(u16 arg0);
u16 map_char_to_font_code(u16 c);
char *parse_text_control_codes(char *p, s32 *a, s32 *b);
void set_glyph_quad_extents(u8 arg0, u8 *arg1);
}
void upload_font_glyph(u16 c, void *arg1);

#endif
