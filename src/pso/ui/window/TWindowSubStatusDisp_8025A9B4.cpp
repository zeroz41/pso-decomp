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
s32 get_small_font_glyph_id(u8);
u8 get_font_char_advance(u16);
u16 map_char_to_font_code(u16);

void WindowTextEntry::reveal_all() {
    reveal_pos = 9e+05f;
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
                w = get_small_font_glyph_width(get_small_font_glyph_id(c));
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
        num = TWindowKeyBoardSoft::strnlen((const char *)str, 0x400);
        entry->text = (char *)mem_alloc(num + 1);
        strncpy(entry->text, (const char *)str, num);
        *(char *)(num + (uaddr)entry->text) = 0;
        entry->flags = entry->flags | 0x20;
    } else {
        entry->text = (char *)str;
    }
    if (entry->reveal_step > K_CFAC) {
        entry->reveal_pos = K_CFAC;
    }
    entry->flags = entry->flags & ~0x2D1;
    entry->flags = entry->flags | (flags & 0x2C1);
}
#pragma pop

int TWindowDuelResult::set_default_status(void* p, int a1) { return ((int (*)(void *, int, int))set_text_entry_string)(p, a1, 0); }

#pragma push
#pragma fp_contract on
void WindowTextEntry::render(WindowDrawContext *context) {
    f32 t;
    f32 a;
    f32 len;
    NJS_POINT2 pt;
    f32 scale;
    f32 clip;
    s32 fully_shown;
    if (text != NULL && *text != 0) {
    pt.x = context->inner_x + x;
    pt.y = context->inner_y + y;
    scale = (-1.0f) / ((0.299f) * depth + context->depth);
    if (flags & 0x40) {
        clip = K_CFB0;
    } else {
        clip = context->clip_x1;
    }
    a = y / (21.0f);
    t = a + x / context->inner_w;
    t *= (7.5f);
    len = (17.0f) * ((f32)context->open_tick - t);
    if (len > reveal_pos) {
        len = reveal_pos;
    }
    set_text_draw_params(context, (!(flags & 0x100)), (flags & 0x80), scale, clip);
    if (flags & 4) {
        fully_shown = draw_small_font_string_clipped((f32 *)&pt, text, color, len);
    } else {
        fully_shown = draw_window_text((f32 *)&pt, text, color, ((flags >> 9) & 1), len);
    }
    if (fully_shown != 0) {
        flags |= 0x10;
    } else {
        flags &= ~0x10;
    }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void WindowTextEntry::update() {
    if (!(flags & 8)) {
        reveal_pos = reveal_pos + reveal_step;
        if (reveal_pos > (9e+05f)) {
            reveal_pos = (9e+05f);
        }
    }
}
#pragma pop

WindowTextEntry::~WindowTextEntry() {
    u16 old_flags;
    if (text != NULL) {
        old_flags = flags;
        if (old_flags & 0x20) {
            flags = old_flags & 0xFFFFFFDF;
            mem_free(text);
        }
    }
}

WindowTextEntry::WindowTextEntry(TextLayoutRecord *rec, s32 client) : TWindowLayoutRect(client) {
    x = rec->pos[0];
    y = rec->pos[1];
    depth = rec->depth;
    flags = rec->flags;
    reveal_pos = K_CFAC;
    color = rec->color;
    reveal_step = TWindowSubStatusDisp::get_card_window_scale(this->client);
    if (flags & 4) {
        reveal_step = reveal_step * K_CFC4;
    }
    if (reveal_step <= K_CFAC) {
        reveal_pos = (9e+05f);
    }
    text = (char *)rec->text;
}
