#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/collision/TObjFogCollisionPoison.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/effect/sprite/TQuadSprite.h"

extern "C" {

void build_small_font_glyph_quad(u8 c, TexturedQuad *q);
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void draw_beat_time_label(s32 text_color, f32 x, f32 y, f32 depth) {
    QuadSpriteRect quad;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, text_color);
    quad.x0 = x;
    quad.y0 = y;
    quad.x1 = 109.0f + x;
    quad.y1 = 12.0f + y;
    quad.u0 = 0.00390625f;
    quad.v0 = 0.921875f;
    quad.u1 = 0.4296875f;
    quad.v1 = 0.96875f;
    draw_textured_quad_at_depth(&quad.x0, depth);
    quad.x0 += 114.0f;
    quad.y0 += -3.0f;
    quad.x1 = 15.0f + quad.x0;
    quad.y1 = 14.0f + quad.y0;
    quad.u0 = 0.4453125f;
    quad.v0 = 0.92578125f;
    quad.u1 = 0.50390625f;
    quad.v1 = 0.98046875f;
    draw_textured_quad_at_depth(&quad.x0, depth);
    end_screen_draw();
}

void draw_number_digits(u32 color, s16 value, u16 digits, f32 x, f32 y, f32 scale) {
    TexturedQuad pos;
    s32 id;
    s32 i;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, color);
    for (i = 0; i < digits; i++) {
        id = get_small_font_glyph_id((u8)(value % 10) + '0');
        x -= ((u8 (*)(s32))get_small_font_glyph_width)(id);
        pos.x0 = x;
        pos.y0 = y;
        ((void (*)(s32, TexturedQuad *))build_small_font_glyph_quad)(id, &pos);
        draw_textured_quad_at_depth(&pos.x0, scale);
        value /= 10;
    }
    end_screen_draw();
}

void draw_small_font_text(u32 color, const char *s, f32 x, f32 y, f32 scale) {
    TexturedQuad pos;
    s32 id;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, color);
    while (*s != 0) {
        u8 c = *s++;
        pos.x0 = x;
        pos.y0 = y;
        id = get_small_font_glyph_id(c);
        ((void (*)(s32, TexturedQuad *))build_small_font_glyph_quad)(id, &pos);
        draw_textured_quad_at_depth(&pos.x0, scale);
        x += ((u8 (*)(s32))get_small_font_glyph_width)(id);
    }
    end_screen_draw();
}

u32 get_name_text_width(void* p) { return ((u32 (*)(void*))calc_small_font_text_width)(p); }

u32 calc_small_font_text_width(const char *s) {
    f32 max = (0.0f);
    u32 w = 0;
    u8 c;

    if (s == NULL) {
        return 0;
    }
    while (*s != 0) {
        c = *s++;
        if (c == '\n') {
            if (max < (f32)w) {
                max = (f32)w;
            }
            w = 0;
        } else if (c == ' ') {
            { f32 t = (f32)w; t += (5.0f); w = t; }
        } else {
            w += ((u8 (*)(u8))get_small_font_glyph_width)(c);
        }
    }
    if (max < (f32)w) {
        max = (f32)w;
    }
    return max;
}
extern "C" {

s32 get_small_font_glyph_width(u8 c) {
    return (s32)small_font_metrics_table_ptr[c - 0x20].width;
}

// The small font indexes its glyphs by character code.
s32 get_small_font_glyph_id(s32 c) { return c; }

void calc_plain_glyph_quad(u8 c, TexturedQuad *q) {
    f32 a = (f32)((c & 0xF) << 4);
    f32 b = 109.0f + (f32)(c & 0xF0);
    GlyphMetrics *g = &small_font_metrics_table_ptr[c - 0x20];
    q->y0 = q->y0 + g->y_offset;
    q->x1 = q->x0 + g->width;
    q->y1 = 13.0f + q->y0;
    q->u0 = a / 256.0f;
    q->v0 = b / 256.0f;
    q->u1 = (a + g->width) / 256.0f;
    q->v1 = (13.0f + b) / 256.0f;
}

void build_small_font_glyph_quad(u8 c, TexturedQuad *q) {
    f32 a = (f32)((c << 4) & 0xF0);
    f32 b = (f32)(c & 0xF0);
    GlyphMetrics *g = &small_font_metrics_table_ptr[c - 0x20];
    q->y0 = q->y0 + g->y_offset;
    q->x1 = q->x0 + g->width;
    q->y1 = 13.0f + q->y0;
    q->u0 = a / 256.0f;
    q->v0 = b / 256.0f;
    q->u1 = (a + g->width) / 256.0f;
    q->v1 = (13.0f + b) / 256.0f;
}
}

GlyphMetrics status_alphabet_metrics_table[95] = {
    {6.0f, 0.0f},   // ' '
    {6.0f, 0.0f},   // '!'
    {10.0f, 0.0f},  // '"'
    {11.0f, 0.0f},  // '#'
    {11.0f, 0.0f},  // '$'
    {15.0f, 0.0f},  // '%'
    {13.0f, 0.0f},  // '&'
    {6.0f, 0.0f},   // '''
    {7.0f, 0.0f},   // '('
    {7.0f, 0.0f},   // ')'
    {11.0f, 0.0f},  // '*'
    {11.0f, 0.0f},  // '+'
    {6.0f, 0.0f},   // ','
    {11.0f, 0.0f},  // '-'
    {6.0f, 0.0f},   // '.'
    {12.0f, 0.0f},  // '/'
    {10.0f, 0.0f},  // '0'
    {10.0f, 0.0f},  // '1'
    {10.0f, 0.0f},  // '2'
    {10.0f, 0.0f},  // '3'
    {10.0f, 0.0f},  // '4'
    {10.0f, 0.0f},  // '5'
    {10.0f, 0.0f},  // '6'
    {10.0f, 0.0f},  // '7'
    {10.0f, 0.0f},  // '8'
    {10.0f, 0.0f},  // '9'
    {5.0f, 0.0f},   // ':'
    {5.0f, 0.0f},   // ';'
    {11.0f, 0.0f},  // '<'
    {11.0f, 0.0f},  // '='
    {12.0f, 0.0f},  // '>'
    {11.0f, 0.0f},  // '?'
    {14.0f, 0.0f},  // '@'
    {13.0f, 0.0f},  // 'A'
    {12.0f, 0.0f},  // 'B'
    {13.0f, 0.0f},  // 'C'
    {12.0f, 0.0f},  // 'D'
    {11.0f, 0.0f},  // 'E'
    {11.0f, 0.0f},  // 'F'
    {13.0f, 0.0f},  // 'G'
    {12.0f, 0.0f},  // 'H'
    {9.0f, 0.0f},   // 'I'
    {10.0f, 0.0f},  // 'J'
    {11.0f, 0.0f},  // 'K'
    {11.0f, 0.0f},  // 'L'
    {13.0f, 0.0f},  // 'M'
    {12.0f, 0.0f},  // 'N'
    {12.0f, 0.0f},  // 'O'
    {11.0f, 0.0f},  // 'P'
    {13.0f, 0.0f},  // 'Q'
    {12.0f, 0.0f},  // 'R'
    {11.0f, 0.0f},  // 'S'
    {12.0f, 0.0f},  // 'T'
    {12.0f, 0.0f},  // 'U'
    {13.0f, 0.0f},  // 'V'
    {15.0f, 0.0f},  // 'W'
    {13.0f, 0.0f},  // 'X'
    {14.0f, 0.0f},  // 'Y'
    {11.0f, 0.0f},  // 'Z'
    {8.0f, 0.0f},   // '['
    {11.0f, 0.0f},  // '\'
    {8.0f, 0.0f},   // ']'
    {10.0f, 0.0f},  // '^'
    {9.0f, 0.0f},   // '_'
    {5.0f, 0.0f},   // '`'
    {11.0f, 0.0f},  // 'a'
    {11.0f, 0.0f},  // 'b'
    {10.0f, 0.0f},  // 'c'
    {11.0f, 0.0f},  // 'd'
    {10.0f, 0.0f},  // 'e'
    {9.0f, 0.0f},   // 'f'
    {10.0f, 3.0f},  // 'g'
    {10.0f, 0.0f},  // 'h'
    {5.0f, 0.0f},   // 'i'
    {9.0f, 1.0f},   // 'j'
    {11.0f, 0.0f},  // 'k'
    {5.0f, 0.0f},   // 'l'
    {13.0f, 0.0f},  // 'm'
    {10.0f, 0.0f},  // 'n'
    {11.0f, 0.0f},  // 'o'
    {10.0f, 3.0f},  // 'p'
    {10.0f, 3.0f},  // 'q'
    {9.0f, 0.0f},   // 'r'
    {10.0f, 0.0f},  // 's'
    {9.0f, 0.0f},   // 't'
    {10.0f, 0.0f},  // 'u'
    {12.0f, 0.0f},  // 'v'
    {14.0f, 0.0f},  // 'w'
    {12.0f, 0.0f},  // 'x'
    {12.0f, 3.0f},  // 'y'
    {10.0f, 0.0f},  // 'z'
    {7.0f, 0.0f},   // '{'
    {5.0f, 0.0f},   // '|'
    {7.0f, 0.0f},   // '}'
    {12.0f, 0.0f},  // '~'
};

GlyphMetrics *small_font_metrics_table_ptr;

void free_ending_callback() {  }

void set_ending_callback() {
    small_font_metrics_table_ptr = status_alphabet_metrics_table;
}
