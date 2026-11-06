#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"

extern "C" {
s32 text_draw_clip_context;
f32 text_draw_depth;
f32 text_draw_right_limit_x;
s32 text_clip_enabled_flag;
s32 lbl_805D6440;
}


struct Quad_8024FBB0 {
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 u[4];
};

struct Quad_8024FD8C {
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 u[4];
};

extern s32 text_draw_clip_context;
extern f32 text_draw_depth;
extern f32 text_draw_right_limit_x;
extern s32 text_clip_enabled_flag;
extern s32 lbl_805D6440;
extern "C" {
void set_text_draw_params(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
u8 get_small_font_glyph_width(s32);
s32 TWindowSubStatusDisp__sub_800FC248(s32);
void calc_plain_glyph_quad(s32, void *);
void build_small_font_glyph_quad(s32, void *);
void render_forward__20TWindowSubStatusDispFPv();
void apply_context_transform_to_rect(s32, void *);
s32 clip_textured_quad__19TWindowKeyBoardSoftFPvPv(s32, void *);
void begin_screen_draw(s32);
void draw_textured_quad_at_depth(void *, f32);
void set_draw_texture_and_color(s32, u32);
const char *parse_text_control_codes(const char *, s32 *, s32 *);
void set_glyph_quad_extents(s32, void *);
s32 get_font_char_advance(s32);
s32 map_char_to_font_code(s32);
void calc_gauge_scale__20TWindowSubStatusDispFPvPvi(s32, void *, s32);
void end_render_forward__20TWindowSubStatusDispFPv();
void TWindowSubStatusDisp::set_input_mode(u8 v) { *(u8*)((char*)this + 0x64) = v; }
}
s32 draw_small_font_string_clipped(f32 *pos, const char *s, u32 color, f32 width);
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
s32 draw_small_font_string_clipped(f32 *pos, const char *s, u32 color, f32 width) {
    s32 ok;
    f32 x;
    f32 y;
    s32 glyph;
    u8 adv;
    s32 c;
    Quad_8024FBB0 q;
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
    render_forward__20TWindowSubStatusDispFPv();
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
            q.x = x;
            q.y = y;
            if (lbl_805D6440 != 0) {
                calc_plain_glyph_quad(glyph, &q);
            } else {
                build_small_font_glyph_quad(glyph, &q);
            }
            if ((f32)adv > width) {
                ok = 0;
                q.x2 = q.x + width;
            }
            x += (f32)adv;
            width -= (f32)adv;
            if (text_clip_enabled_flag == 0 || clip_textured_quad__19TWindowKeyBoardSoftFPvPv(text_draw_clip_context, &q) != 0) {
                apply_context_transform_to_rect(text_draw_clip_context, &q);
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
    Quad_8024FD8C q;
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
        q.x = x;
        q.y = y;
        set_glyph_quad_extents(adv, &q);
        if ((f32)(u8)adv > width) {
            ok = 0;
            q.x2 = q.x + width;
        }
        if (text_clip_enabled_flag == 0 || ((TWindowKeyBoardSoft *)text_draw_clip_context)->is_point_in_bounds(&q) != 0) {
            calc_gauge_scale__20TWindowSubStatusDispFPvPvi(glyph, &q, col);
            set_glyph_quad_extents(adv, &q);
            if ((f32)(u8)adv > width) {
                q.x2 = q.x + width;
            }
            if (text_clip_enabled_flag != 0) {
                clip_textured_quad__19TWindowKeyBoardSoftFPvPv(text_draw_clip_context, &q);
            }
            apply_context_transform_to_rect(text_draw_clip_context, &q);
            draw_textured_quad_at_depth(&q, text_draw_depth);
        }
        x += (f32)(u8)adv;
        width -= (f32)(u8)adv;
    }
    end_render_forward__20TWindowSubStatusDispFPv();
    return ok;
}

void set_text_draw_params(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1) {
    text_draw_clip_context = arg0;
    text_draw_depth = farg0;
    text_draw_right_limit_x = farg1;
    text_clip_enabled_flag = arg1;
    lbl_805D6440 = arg2;
}
