#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/Language.h"
#pragma readonly_strings on

struct Msg_8025A9C0 {
    u16 flags;
    u8 pad2[0x10 - 2];
    f32 width;
    f32 height;
    u8 pad18[0x20 - 0x18];
    s8 *text;
};

struct RecoveredGlobal_8025AF90_lbl_804CFA28 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8025AF90_lbl_804CFA28_size[sizeof(RecoveredGlobal_8025AF90_lbl_804CFA28) == 0x18 ? 1 : -1];

struct Win_8025AD5C { u16 flags; u8 pad2[6]; f32 f8; f32 fC; u8 pad10[8]; f32 f18; f32 f1C; s8 *text; s32 i24; };

struct Ref_8025AD5C { u8 pad0[0x10]; f32 f10; f32 f14; f32 f18; u8 pad1c[0x30 - 0x1C]; s32 i30; u8 pad34[4]; f32 f38; u8 pad3c[8]; f32 f44; };

struct Pt_8025AD5C { f32 x; f32 y; };

extern "C" {
void mem_free(void *p);
void *mem_alloc(u32 size);
s32 strncpy(s32, u32, s32);
u8 get_small_font_glyph_width(u8);
s32 TWindowSubStatusDisp__sub_800FC248(u8);
s8 *parse_text_control_codes(s8 *, s32 *, s32);
u8 get_font_char_advance(u16);
u16 map_char_to_font_code(u16);
void measure_message_text_width(Msg_8025A9C0 *msg, f32 maxw);
s32 reset_entry__20TWindowSubStatusDispFPv(void *, void *);
void render_text_entry(Win_8025AD5C *arg0, Ref_8025AD5C *arg1);
s32 deleting_destructor__20TWindowSubStatusDispFs(void *, s32);

void *lbl_804CFA28[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp__sub_8025AF0C,
    (void *)advance_text_entry_reveal,
    (void *)render_text_entry,
    0,
};

void TWindowHelpItem::reset_float_field() {
    *(f32 *)&this->_pad1C = (f32) (9e+05f);
}

extern const u32 lbl_805DCFAC = 0x00000000;
extern const u32 lbl_805DCFB0 = 0x4B189680;
extern const u32 lbl_805DCFB4 = 0x41200000;
extern const u32 lbl_805DCFB8 = 0x41500000;
extern const u32 lbl_805DCFBC = 0x41900000;
extern const u32 lbl_805DCFC0 = 0x41A00000;
extern const u32 lbl_805DCFC4 = 0x3F000000;
#define K_CFAC (*(const f32 *)&lbl_805DCFAC)
#define K_CFB0 (*(const f32 *)&lbl_805DCFB0)
#define K_CFB4 (*(const f32 *)&lbl_805DCFB4)
#define K_CFB8 (*(const f32 *)&lbl_805DCFB8)
#define K_CFBC (*(const f32 *)&lbl_805DCFBC)
#define K_CFC0 (*(const f32 *)&lbl_805DCFC0)
#define K_CFC4 (*(const f32 *)&lbl_805DCFC4)

#pragma push
#pragma fp_contract on
void measure_message_text_width(Msg_8025A9C0 *msg, f32 maxw) {
    s32 sjis;
    f32 adv;
    f32 lineh;
    f32 maxx;
    f32 y;
    f32 x;
    f32 limit;
    s8 *p;
    s32 small;
    s32 c;
    s8 ch;
    u8 w;
    if (msg->text == NULL || *msg->text == 0) {
        msg->width = K_CFAC;
        msg->height = K_CFAC;
        return;
    }
    if (msg->flags & 0x40) {
        limit = K_CFB0;
    } else {
        limit = maxw;
    }
    sjis = (u32)__cntlzw(current_language) >> 5;
    small = (msg->flags >> 2) & 1;
    if (small) {
        lineh = K_CFB8;
        adv = K_CFB4;
        y = lineh;
    } else {
        adv = K_CFBC;
        lineh = K_CFC0;
        y = adv;
    }
    maxx = K_CFAC;
    p = msg->text;
    x = maxx;
    while (*p != 0) {
        p = parse_text_control_codes(p, &sjis, 0);
        ch = *p;
        if (ch == 0) {
            continue;
        }
        c = ch & 0xFF;
        p++;
        if (c == 0xA) {
            if (msg->flags & 0x80) {
                x += adv * K_CFC4;
            } else {
                if (x > maxx) {
                    maxx = x;
                }
                y += lineh;
                x = K_CFAC;
            }
        } else if (c == 0x20) {
            x += adv * K_CFC4;
        } else {
            if (sjis != 0 && ((c & 0xE0) == 0x80 || (c & 0xE0) == 0xE0)) {
                c = ((c << 8) & 0xFF00) | *(u8 *)p;
                p++;
            }
            if (small) {
                w = get_small_font_glyph_width(TWindowSubStatusDisp__sub_800FC248(c));
            } else {
                w = get_font_char_advance(((u16 (*)(s32))map_char_to_font_code)(c));
            }
            if (x + (f32)w > limit) {
                if (x > maxx) {
                    maxx = x;
                }
                x = K_CFAC;
                y += lineh;
            }
            x += (f32)w;
        }
    }
    if (x <= K_CFAC) {
        y -= lineh;
    }
    if (x > maxx) {
        maxx = x;
    }
    if (maxx > maxw) {
        maxx = maxw;
    }
    msg->width = maxx;
    msg->height = y;
}
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2) {
    s32 temp_r3_2;
    u16 temp_r3;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) {
        temp_r3 = *(u16 *)((s8 *)arg0 + 0);
        if (temp_r3 & 0x20) {
            *(u16 *)((s8 *)arg0 + 0) = (u16) (temp_r3 & 0xFFFFFFDF);
            mem_free((void *)((int) (*(u32 *)((s8 *)arg0 + 0x20))));
        }
    }
    if ((str != 0U) && (arg2 & 0x20)) {
        temp_r3_2 = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)(0x400));
        *(u32 *)((s8 *)arg0 + 0x20) = ((u32)mem_alloc(temp_r3_2 + 1));
        strncpy((s32)((int) (*(u32 *)((s8 *)arg0 + 0x20))), str, temp_r3_2);
        *(s8 *)((s8 *)(temp_r3_2 + *(u32 *)((s8 *)arg0 + 0x20)) + 0) = 0;
        *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) | 0x20);
    } else {
        *(u32 *)((s8 *)arg0 + 0x20) = str;
    }
    if (*(f32 *)((s8 *)arg0 + 0x28) > K_CFAC) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) K_CFAC;
    }
    *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) & ~0x2D1);
    *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) | (arg2 & 0x2C1));
}
#pragma pop

int TWindowDuelResult::set_default_status(void* p, int a1) { return ((int (*)(void *, int, int))set_text_entry_string)(p, a1, 0); }

#pragma push
#pragma fp_contract on
void render_text_entry(Win_8025AD5C *arg0, Ref_8025AD5C *arg1) {
    f32 t;
    f32 a;
    f32 len;
    Pt_8025AD5C pt;
    f32 scale;
    f32 alpha;
    s32 r;
    if (arg0->text != NULL && *arg0->text != 0) {
    pt.x = arg1->f10 + arg0->f8;
    pt.y = arg1->f14 + arg0->fC;
    scale = (-1.0f) / ((0.299f) * arg0->f18 + arg1->f38);
    if (arg0->flags & 0x40) {
        alpha = K_CFB0;
    } else {
        alpha = arg1->f44;
    }
    a = arg0->fC / (21.0f);
    t = a + arg0->f8 / arg1->f18;
    t *= (7.5f);
    len = (17.0f) * ((f32)arg1->i30 - t);
    if (len > arg0->f1C) {
        len = arg0->f1C;
    }
    set_text_draw_params((s32)arg1, (s32)(!(arg0->flags & 0x100)), (s32)(arg0->flags & 0x80), (f32)scale, (f32)alpha);
    if (arg0->flags & 4) {
        r = draw_small_font_string_clipped((f32 *)&pt, (const char *)arg0->text, arg0->i24, (f32)len);
    } else {
        r = draw_window_text((f32 *)&pt, (const char *)arg0->text, arg0->i24, ((arg0->flags >> 9) & 1), (f32)len);
    }
    if (r != 0) {
        arg0->flags |= 0x10;
    } else {
        arg0->flags &= ~0x10;
    }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void advance_text_entry_reveal(u8 *arg0) {
    if (!(*(u16 *)((s8 *)arg0 + 0) & 8)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + *(f32 *)((s8 *)arg0 + 0x28));
        if (*(f32 *)((s8 *)arg0 + 0x1C) > (9e+05f)) {
            *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (9e+05f);
        }
    }
}
#pragma pop

void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 arg1) {
    u16 temp_r3;

    if (window_sub_status_disp != NULL) {
        *(void ***)((s8 *)window_sub_status_disp + 4) = lbl_804CFA28;
        if ((u32) *(u32 *)((s8 *)window_sub_status_disp + 0x20) != 0U) {
            temp_r3 = *(u16 *)((s8 *)window_sub_status_disp + 0);
            if (temp_r3 & 0x20) {
                *(u16 *)((s8 *)window_sub_status_disp + 0) = (u16) (temp_r3 & 0xFFFFFFDF);
                mem_free((void *)(*(u32 *)((s8 *)window_sub_status_disp + 0x20)));
            }
        }
        deleting_destructor__20TWindowSubStatusDispFs(window_sub_status_disp, 0);
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

u8 *construct_text_entry(u8 *arg0, u8 *arg1, s32 arg2) {
    reset_entry__20TWindowSubStatusDispFPv((void *)arg0, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_8025AF90_lbl_804CFA28 *)&lbl_804CFA28).value;
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(s32 *)((s8 *)arg1 + 0x14);
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) K_CFAC;
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(f32 *)((s8 *)arg0 + 0x28) = TWindowSubStatusDisp::get_card_window_scale((int) ((s32) *(s16 *)((s8 *)arg0 + 2)));
    if (*(u16 *)((s8 *)arg0 + 0) & 4) {
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) (*(f32 *)((s8 *)arg0 + 0x28) * K_CFC4);
    }
    if (*(f32 *)((s8 *)arg0 + 0x28) <= K_CFAC) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (9e+05f);
    }
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    return arg0;
}
