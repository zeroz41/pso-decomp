#include "pso/ui/font/TNECFontEORFunction.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"


WindowDrawContext *text_draw_clip_context;
f32 text_draw_depth;
f32 text_draw_right_limit_x;
s32 text_clip_enabled_flag;
s32 lbl_805D6440;


extern f32 text_draw_depth;
extern f32 text_draw_right_limit_x;
extern s32 text_clip_enabled_flag;
extern s32 lbl_805D6440;
extern "C" {
u8 get_small_font_glyph_width(s32);
s32 TWindowSubStatusDisp__sub_800FC248(s32);
void calc_plain_glyph_quad(s32, void *);
void build_small_font_glyph_quad(s32, void *);
void begin_screen_draw(s32);
void draw_textured_quad_at_depth(void *, f32);
void set_draw_texture_and_color(s32, u32);
s32 get_font_char_advance(s32);
s32 map_char_to_font_code(s32);
void calc_gauge_scale__20TWindowSubStatusDispFUsPvl(s32, void *, s32);
void TWindowKeyBoardBase::set_input_mode(s32 mode) { m_input_mode = mode; }
}
s32 draw_small_font_string_clipped(f32 *pos, const char *s, u32 color, f32 width) {
    s32 ok;
    f32 x;
    f32 y;
    s32 glyph;
    u8 adv;
    s32 c;
    TexturedQuad q;
    ok = 1;
    if (s == NULL) {
        return 1;
    }
    if (*s == 0) {
        return 1;
    }
    x = pos[0];
    y = pos[1];
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, color);
    while (*s != 0) {
        c = (u8)*s++;
        if (c == 0x20) {
            x += 5.0f;
            width -= 5.0f;
        } else if (width <= 0.0f) {
            ok = 0;
        } else {
            glyph = TWindowSubStatusDisp__sub_800FC248(c);
            adv = get_small_font_glyph_width(glyph);
            q.x0 = x;
            q.y0 = y;
            if (lbl_805D6440 != 0) {
                calc_plain_glyph_quad(glyph, &q);
            } else {
                build_small_font_glyph_quad(glyph, &q);
            }
            if ((f32)adv > width) {
                ok = 0;
                q.x1 = q.x0 + width;
            }
            x += (f32)adv;
            width -= (f32)adv;
            if (text_clip_enabled_flag == 0 || text_draw_clip_context->clip_textured_quad(&q) != 0) {
                text_draw_clip_context->transform_quad(&q);
                draw_textured_quad_at_depth(&q, text_draw_depth);
            }
        }
    }
    TWindowSubStatusDisp::get_player();
    return ok;
}

s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width) {
    s32 glyph;
    s32 adv;
    s32 ok;
    f32 x;
    f32 y;
    char ch;
    s32 code;
    s32 col;
    s32 flag;
    TexturedQuad q;
    // The original caller passes the advance in a full word.
    typedef void (*SetGlyphExtent)(s32, TexturedQuad *);
    col = color;
    ok = 1;
    flag = 0;
    if (s == NULL) {
        return 1;
    }
    if (*s == 0) {
        return 1;
    }
    if (current_language == LANGUAGE_JAPANESE) {
        flag = 1;
    }
    x = pos[0];
    y = pos[1];
    s = parse_text_control_codes(s, &flag, &col);
    if (mode == 1) {
        col = color;
    }
    TWindowSubStatusDisp::reset_gauge(0);
    while (*s != 0) {
        s = parse_text_control_codes(s, &flag, &col);
        if (mode == 1) {
            col = color;
        }
        if (*s == 0) {
            continue;
        }
        code = *s++ & 0xFF;
        if (code == '\n') {
            if (mode == 0) {
                if (lbl_805D6440 != 0) {
                    x += 9.0f;
                    width -= 9.0f;
                } else {
                    x = pos[0];
                    y += 20.0f;
                }
            }
            continue;
        }
        if (flag != 0 && ((code & 0xE0) == 0x80 || (code & 0xE0) == 0xE0)) {
            code = (u16)(code << 8);
            code |= (u8)*s++;
        }
        if (width <= 0.0f) {
            ok = 0;
            continue;
        }
        glyph = map_char_to_font_code(code);
        adv = get_font_char_advance(glyph);
        if (x + (f32)(u8)adv > text_draw_right_limit_x) {
            x = pos[0];
            y += 20.0f;
        }
        if ((glyph & 0xFFFF) == 0x20) {
            x += (f32)(s32)(u8)adv;
            width -= (f32)(s32)(u8)adv;
            continue;
        }
        q.x0 = x;
        q.y0 = y;
        reinterpret_cast<SetGlyphExtent>(set_glyph_quad_extents)(adv, &q);
        if ((f32)(u8)adv > width) {
            ok = 0;
            q.x1 = q.x0 + width;
        }
        if (text_clip_enabled_flag == 0 || text_draw_clip_context->is_point_in_bounds(&q) != 0) {
            calc_gauge_scale__20TWindowSubStatusDispFUsPvl(glyph, &q, col);
            reinterpret_cast<SetGlyphExtent>(set_glyph_quad_extents)(adv, &q);
            if ((f32)(u8)adv > width) {
                q.x1 = q.x0 + width;
            }
            if (text_clip_enabled_flag != 0) {
                text_draw_clip_context->clip_textured_quad(&q);
            }
            text_draw_clip_context->transform_quad(&q);
            draw_textured_quad_at_depth(&q, text_draw_depth);
        }
        x += (f32)(u8)adv;
        width -= (f32)(u8)adv;
    }
    TWindowSubStatusDisp::end_render_forward();
    return ok;
}

void set_text_draw_params(WindowDrawContext *context, s32 clip, s32 mode, f32 depth, f32 right_limit) {
    text_draw_clip_context = context;
    text_draw_depth = depth;
    text_draw_right_limit_x = right_limit;
    text_clip_enabled_flag = clip;
    lbl_805D6440 = mode;
}
