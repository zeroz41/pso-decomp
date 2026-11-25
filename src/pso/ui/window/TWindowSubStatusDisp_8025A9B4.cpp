#include "pso/ui/font/TNECFontEORFunction.h"
#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/Language.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#pragma readonly_strings on

extern "C" {
u8 get_small_font_glyph_width(u8);
s32 TWindowSubStatusDisp__sub_800FC248(u8);
u8 get_font_char_advance(u16);
u16 map_char_to_font_code(u16);
void render_text_entry(WindowTextEntry *entry, WindowDrawContext *context);

void *lbl_804CFA28[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp__sub_8025AF0C,
    (void *)advance_text_entry_reveal,
    (void *)render_text_entry,
    0,
};

void TWindowHelpItem::reset_float_field() {
    *(f32 *)&this->sort_depth = (f32) (9e+05f);
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
void measure_message_text_width(WindowTextEntry *msg, f32 maxw) {
    s32 sjis;
    f32 adv;
    f32 lineh;
    f32 maxx;
    f32 y;
    f32 x;
    f32 limit;
    char *p;
    s32 small;
    s32 c;
    char ch;
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
        p = const_cast<char *>(parse_text_control_codes(p, &sjis, NULL));
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
void set_text_entry_string(WindowTextEntry *entry, uaddr str, s32 flags) {
    saddr num;
    u16 old_flags;
    if (entry->text != NULL) {
        old_flags = entry->flags;
        if (old_flags & 0x20) {
            entry->flags = old_flags & 0xFFFFFFDF;
            mem_free(entry->text);
        }
    }
    if ((str != 0U) && (flags & 0x20)) {
        num = TWindowKeyBoardSoft::strnlen((s8 *)str, 0x400);
        entry->text = (char *)mem_alloc(num + 1);
        strncpy(entry->text, (const char *)str, num);
        *(char *)(num + (uaddr)entry->text) = 0;
        entry->flags = entry->flags | 0x20;
    } else {
        entry->text = (char *)str;
    }
    if (entry->reveal_speed > K_CFAC) {
        entry->reveal_width = K_CFAC;
    }
    entry->flags = entry->flags & ~0x2D1;
    entry->flags = entry->flags | (flags & 0x2C1);
}
#pragma pop

int TWindowDuelResult::set_default_status(void* p, int a1) { return ((int (*)(void *, int, int))set_text_entry_string)(p, a1, 0); }

#pragma push
#pragma fp_contract on
void render_text_entry(WindowTextEntry *entry, WindowDrawContext *context) {
    f32 t;
    f32 a;
    f32 len;
    NJS_POINT2 pt;
    f32 scale;
    f32 clip;
    s32 clipped;
    if (entry->text != NULL && *entry->text != 0) {
    pt.x = context->inner_x + entry->x;
    pt.y = context->inner_y + entry->y;
    scale = (-1.0f) / ((0.299f) * entry->depth + context->depth);
    if (entry->flags & 0x40) {
        clip = K_CFB0;
    } else {
        clip = context->clip_x1;
    }
    a = entry->y / (21.0f);
    t = a + entry->x / context->inner_w;
    t *= (7.5f);
    len = (17.0f) * ((f32)context->open_tick - t);
    if (len > entry->reveal_width) {
        len = entry->reveal_width;
    }
    set_text_draw_params(context, (!(entry->flags & 0x100)), (entry->flags & 0x80), scale, clip);
    if (entry->flags & 4) {
        clipped = draw_small_font_string_clipped((f32 *)&pt, entry->text, entry->color, len);
    } else {
        clipped = draw_window_text((f32 *)&pt, entry->text, entry->color, ((entry->flags >> 9) & 1), len);
    }
    if (clipped != 0) {
        entry->flags |= 0x10;
    } else {
        entry->flags &= ~0x10;
    }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void advance_text_entry_reveal(WindowTextEntry *entry) {
    if (!(entry->flags & 8)) {
        entry->reveal_width = entry->reveal_width + entry->reveal_speed;
        if (entry->reveal_width > (9e+05f)) {
            entry->reveal_width = (9e+05f);
        }
    }
}
#pragma pop

void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 arg1) {
    u16 flags;

    if (window_sub_status_disp != NULL) {
        *(void ***)((s8 *)window_sub_status_disp + 4) = lbl_804CFA28;
        if ((u32) *(u32 *)((s8 *)window_sub_status_disp + 0x20) != 0U) {
            flags = ((WindowTextEntry *)window_sub_status_disp)->flags;
            if (flags & 0x20) {
                ((WindowTextEntry *)window_sub_status_disp)->flags = (u16) (flags & 0xFFFFFFDF);
                mem_free((void *)(*(uaddr *)((s8 *)window_sub_status_disp + 0x20)));
            }
        }
        __dt__17TWindowLayoutRectFv(window_sub_status_disp, 0);
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

WindowTextEntry *construct_text_entry(WindowTextEntry *entry, TextLayoutRecord *rec, s32 client) {
    __ct__17TWindowLayoutRectFl(entry, client);
    *(s32 **)((s8 *)entry + 4) = ((s32 *)&lbl_804CFA28);
    entry->x = rec->pos[0];
    entry->y = rec->pos[1];
    entry->depth = rec->depth;
    entry->flags = rec->flags;
    entry->reveal_width = K_CFAC;
    entry->color = rec->color;
    entry->reveal_speed = TWindowSubStatusDisp::get_card_window_scale(entry->client);
    if (entry->flags & 4) {
        entry->reveal_speed = entry->reveal_speed * K_CFC4;
    }
    if (entry->reveal_speed <= K_CFAC) {
        entry->reveal_width = (9e+05f);
    }
    entry->text = (char *)rec->text;
    return entry;
}
