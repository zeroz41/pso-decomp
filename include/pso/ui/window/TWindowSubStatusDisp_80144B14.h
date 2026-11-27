#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80144B14_H

#include "types.h"

u32 calc_fullwidth_text_width(const char *s);
void pack_ci4_texels(u8 *dst, u32 pixel);
s32 calc_ci4_tile_offset(u32 x, u32 y);
struct TexturedQuad;

u32 calc_text_width(const char *s);
struct MenuGlyphEntry;
u8 get_font_char_advance(u16 c);
u16 map_char_to_font_code(u16 c);
u8 bind_menu_font_glyph(u16 glyph, TexturedQuad *quad, s32 color);
extern "C" {
void draw_menu_font_string(const char *s, s32 color, u32 flags, f32 x, f32 y, f32 scale);
void draw_menu_font_string_white(const char *text, f32 x, f32 y);
}
void upload_font_glyph(u16 c, MenuGlyphEntry *glyph);

#endif
