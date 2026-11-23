#ifndef PSO_UI_FRONTEND_TADENDTEXT_H
#define PSO_UI_FRONTEND_TADENDTEXT_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"

// The ending credits: the lines of AdEnding.rel scrolled up the screen in the
// ending font, with the ADX and Sofdec logos.
class TAdEndText : public TObject {
public:
    TAdEndText(TObject *parent);
    virtual ~TAdEndText();
    virtual void render();
    virtual void run_task();
public:
    static void free_resources();
    static void load_ending_font();
    static void draw_end_font_text(s32 color, char *str, f32 x, f32 y, f32 depth);
public:
    static void cleanup();

    static const char *class_name;
    // Ending font height per size index.
    static const f32 font_heights[2];
    // Glyph advance widths: 36 glyphs per texture row.
    static const f32 glyph_widths[3][36];
    static NJS_TEXNAME ending_font_textures[5];
    static NJS_TEXLIST ending_font_texture_list;
    // Set once the last credit line has scrolled off the top.
    static s32 font_loaded_flag;
    static NJS_TEXLIST *loaded_font_texture_list;
    // The lines of AdEnding.rel; '#' lines use the ending font, '!' and '@'
    // place the ADX and Sofdec logos, '*' ends the list.
    static char **credit_script_lines;
    // Scroll speed at rate 1; lower-case glyphs also sit this far down.
    static const f32 scroll_step;
    // Advance of a space.
    static const f32 space_width;
    // Font cell size in pixels; also the height of a heading line.
    static const f32 glyph_size;
    static const f32 zero;
    // One texel of the 128-pixel font texture.
    static const f32 texel_scale;
    // Lines above this are hidden; also the fade-out length.
    static const f32 fade_top;
    // Lines below this are hidden.
    static const f32 fade_bottom;
    static const f32 fade_in_end;
    static const f32 alpha_max;
    static const f32 fade_out_start;
    static const f32 text_depth;
    static const f32 scroll_start_y;
    static const f32 one;
    static const f32 scroll_height_scale;
    static const f32 scroll_time_scale;
    static const f32 text_x;
    static const f32 logo_x;
    // ADX and Sofdec logo size; also their line height.
    static const f32 logo_size;
    static const f32 line_height;
    // The credits end once the last line scrolls above this.
    static const f32 end_y;
    // Scroll rate when TKeyBoardControl__sub_8000F828 is set.
    static const f32 fast_rate;

    s32 pad_1C;
    u32 pad_20;
    f32 m_scroll;
    NJS_POINT2 m_line_pos[800];
    u32 m_line_count;
    TexturedQuad m_adx_logo;
    TexturedQuad m_sofdec_logo;
    f32 m_speed;
    f32 m_height;
    s32 m_size_index;
    f32 m_rate;
};

LAYOUT_ASSERT(TAdEndText_size, sizeof(TAdEndText) == 0x197C);

// The C library's character class tests (the __ctype_map masks).
int is_digit(int c);
int is_upper(int c);
int is_alnum(int c);
int is_lower(int c);
s32 is_ending_sequence_active(void);

extern "C" {
s32 get_end_text_font_loaded_flag(void);
s32 get_ending_scene_active(void);
}

#endif
