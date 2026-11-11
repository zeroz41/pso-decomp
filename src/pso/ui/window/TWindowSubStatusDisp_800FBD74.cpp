#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/collision/TObjFogCollisionPoison.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_800FAD08_TFogCtrl__data_80501188 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_800FAD08_TFogCtrl__data_80501188_size[sizeof(RecoveredGlobal_800FAD08_TFogCtrl__data_80501188) == 0x10 ? 1 : -1];

struct RecoveredGlobal_800FB8A0___vt__8TFogCtrl {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188 {
    s32 value;
    u8 remaining[0xC];
};

struct O_800FB400 { u8 pad[0x174]; s32 arr[1]; };

struct FogRow_800FB134 {
    u32 flags;
    u32 color;
    f32 end;
    f32 start;
    f32 rate;
    u32 reserved14;
    f32 speed;
    f32 reserved1c;
    f32 end_amplitude;
    f32 reserved24;
    f32 start_amplitude;
    f32 reserved2c;
    f32 width;
    f32 reserved34;
    u8 phases[8];
};

struct FogCtrl_800FB134 {
    u8 prefix[0x1C];
    u32 dirty;
    u8 pad20[0x174 - 0x20];
    FogRow_800FB134 *slots[4];
    s32 selected;
    u32 color;
    f32 end;
    f32 start;
    f32 width;
};

typedef char RecoveredGlobal_800FB8A0___vt__8TFogCtrl_size[sizeof(RecoveredGlobal_800FB8A0___vt__8TFogCtrl) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188_size[sizeof(RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188) == 0x10 ? 1 : -1];

struct Stack_800FBD74 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
};

struct RecoveredGlobal_800FBB68_lbl_8049C670 { s32 value; u8 remaining[0x8C]; };

typedef char RecoveredGlobal_800FBB68_lbl_8049C670_size[sizeof(RecoveredGlobal_800FBB68_lbl_8049C670) == 0x90 ? 1 : -1];

struct Pos_800FBEA8 {
    f32 x;
    f32 y;
    u8 pad[0x18];
};

struct Pos_800FBFD8 {
    f32 x;
    f32 y;
    u8 pad[0x18];
};

struct Quad_800FC310 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };

struct O_800FB400;

struct FogCtrl_800FB134;

struct Quad_800FC24C { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };
extern "C" {

void build_small_font_glyph_quad(u8 c, Quad_800FC310 *q);

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TWindowSubStatusDisp__sub_800FBD74(s32 arg0, f32 farg0, f32 farg1, f32 farg2) {
    typedef char sp8_offset[(offsetof(Stack_800FBD74, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800FBD74, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800FBD74, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800FBD74, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_800FBD74, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_800FBD74, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_800FBD74, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_800FBD74, sp24) == 0x1C) ? 1 : -1];
    Stack_800FBD74 stack;
    f32 temp_f7;
    f32 temp_f8;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, (arg0));
    stack.sp8 = farg0;
    stack.spC = farg1;
    stack.sp10 = (109.0f) + farg0;
    stack.sp14 = (12.0f) + farg1;
    stack.sp18 = (0.00390625f);
    stack.sp1C = (0.921875f);
    stack.sp20 = (0.4296875f);
    stack.sp24 = (0.96875f);
    draw_textured_quad_at_depth((&stack.sp8), farg2);
    stack.sp8 += (114.0f);
    stack.spC += (-3.0f);
    stack.sp10 = (15.0f) + stack.sp8;
    stack.sp14 = (14.0f) + stack.spC;
    stack.sp18 = (0.4453125f);
    stack.sp1C = (0.92578125f);
    stack.sp20 = (0.50390625f);
    stack.sp24 = (0.98046875f);
    draw_textured_quad_at_depth((&stack.sp8), farg2);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubStatusDisp::draw_number_digits(void *color, s16 value, u16 digits, f32 x, f32 y, f32 scale) {
    Pos_800FBEA8 pos;
    s32 id;
    s32 i;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, (s32)color);
    for (i = 0; i < digits; i++) {
        id = ((s32 (*)(s32))TWindowSubStatusDisp__sub_800FC248)((u8)(value % 10) + '0');
        x -= ((u8 (*)(s32))get_small_font_glyph_width)(id);
        pos.x = x;
        pos.y = y;
        ((void (*)(s32, Pos_800FBEA8 *))build_small_font_glyph_quad)(id, &pos);
        draw_textured_quad_at_depth((f32 *)&pos, scale);
        value /= 10;
    }
    TWindowSubStatusDisp::get_player();
}

void draw_small_font_text(void *color, const char *s, f32 x, f32 y, f32 scale) {
    Pos_800FBFD8 pos;
    s32 id;
    set_default_alpha_blend();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, (s32)color);
    while (*s != 0) {
        u8 c = *s++;
        pos.x = x;
        pos.y = y;
        id = ((s32 (*)(s32))TWindowSubStatusDisp__sub_800FC248)(c);
        ((void (*)(s32, Pos_800FBEA8 *))build_small_font_glyph_quad)(id, (Pos_800FBEA8 *)(&pos));
        draw_textured_quad_at_depth((f32 *)&pos, scale);
        x += ((u8 (*)(s32))get_small_font_glyph_width)(id);
    }
    TWindowSubStatusDisp::get_player();
}

u32 get_name_text_width(void* p) { return ((u32 (*)(void*))calc_small_font_text_width)(p); }
}

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

void TWindowSubStatusDisp__sub_800FC248(void) {  }

void calc_plain_glyph_quad(u8 c, Quad_800FC24C *q) {
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

void build_small_font_glyph_quad(u8 c, Quad_800FC310 *q) {
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

void TLobby__sub_800FC3CC(void) {  }

void TLobby::set_ending_callback() {
    small_font_metrics_table_ptr = status_alphabet_metrics_table;
}
