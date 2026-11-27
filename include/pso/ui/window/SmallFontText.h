#ifndef PSO_UI_WINDOW_SMALLFONTTEXT_H
#define PSO_UI_WINDOW_SMALLFONTTEXT_H

#include "types.h"

void draw_beat_time_label(s32 text_color, f32 x, f32 y, f32 depth);
extern "C" {
s32 get_small_font_glyph_id(s32 c);
}
u32 calc_small_font_text_width(const char *s);
void draw_small_font_text(u32 color, const char *s, f32 x, f32 y, f32 scale);
u32 get_name_text_width(void *p);
extern "C" {
s32 get_small_font_glyph_width(u8 c);
}

void draw_number_digits(u32 color, s16 value, u16 digits, f32 x, f32 y, f32 scale);
void free_ending_callback();
void set_ending_callback();

struct GlyphMetrics {
    f32 width;
    f32 y_offset;
};
extern GlyphMetrics *small_font_metrics_table_ptr;

#endif
