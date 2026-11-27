#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "types.h"
#include "pso/ui/window/TWindowLayoutRect.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/Language.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/ui/window/BoundedStrlen.h"
#pragma readonly_strings on

extern "C" {
u8 get_small_font_glyph_width(u8);
s32 get_small_font_glyph_id(u8);

void WindowTextEntry::reveal_all() {
    reveal_pos = 9e+05f;
}

extern const u32 text_entry_zero = 0x00000000;
extern const u32 text_entry_no_wrap_width = 0x4B189680;
extern const u32 text_entry_small_advance = 0x41200000;
extern const u32 text_entry_small_line_height = 0x41500000;
extern const u32 text_entry_advance = 0x41900000;
extern const u32 text_entry_line_height = 0x41A00000;
extern const u32 text_entry_half = 0x3F000000;
#define TEXT_ENTRY_ZERO (*(const f32 *)&text_entry_zero)
#define TEXT_ENTRY_NO_WRAP_WIDTH (*(const f32 *)&text_entry_no_wrap_width)
#define TEXT_ENTRY_SMALL_ADVANCE (*(const f32 *)&text_entry_small_advance)
#define TEXT_ENTRY_SMALL_LINE_HEIGHT (*(const f32 *)&text_entry_small_line_height)
#define TEXT_ENTRY_ADVANCE (*(const f32 *)&text_entry_advance)
#define TEXT_ENTRY_LINE_HEIGHT (*(const f32 *)&text_entry_line_height)
#define TEXT_ENTRY_HALF (*(const f32 *)&text_entry_half)

#pragma push
#pragma fp_contract on
void WindowTextEntry::measure_text(f32 max_width) {
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
    if (this->text == NULL || *this->text == 0) {
        this->width = TEXT_ENTRY_ZERO;
        this->height = TEXT_ENTRY_ZERO;
        return;
    }
    if (this->flags & 0x40) {
        limit = TEXT_ENTRY_NO_WRAP_WIDTH;
    } else {
        limit = max_width;
    }
    sjis = (u32)__cntlzw(current_language) >> 5;
    small = (this->flags >> 2) & 1;
    if (small) {
        lineh = TEXT_ENTRY_SMALL_LINE_HEIGHT;
        adv = TEXT_ENTRY_SMALL_ADVANCE;
        y = lineh;
    } else {
        adv = TEXT_ENTRY_ADVANCE;
        lineh = TEXT_ENTRY_LINE_HEIGHT;
        y = adv;
    }
    maxx = TEXT_ENTRY_ZERO;
    p = this->text;
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
            if (this->flags & 0x80) {
                x += adv * TEXT_ENTRY_HALF;
            } else {
                if (x > maxx) {
                    maxx = x;
                }
                y += lineh;
                x = TEXT_ENTRY_ZERO;
            }
        } else if (c == 0x20) {
            x += adv * TEXT_ENTRY_HALF;
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
                x = TEXT_ENTRY_ZERO;
                y += lineh;
            }
            x += (f32)w;
        }
    }
    if (x <= TEXT_ENTRY_ZERO) {
        y -= lineh;
    }
    if (x > maxx) {
        maxx = x;
    }
    if (maxx > max_width) {
        maxx = max_width;
    }
    this->width = maxx;
    this->height = y;
}
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void set_text_entry_string(WindowTextEntry *entry, const char *str, s32 flags) {
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
        num = bounded_strlen(str, 0x400);
        entry->text = (char *)mem_alloc(num + 1);
        strncpy(entry->text, str, num);
        *(char *)(num + (uaddr)entry->text) = 0;
        entry->flags = entry->flags | 0x20;
    } else {
        entry->text = (char *)str;
    }
    if (entry->reveal_step > TEXT_ENTRY_ZERO) {
        entry->reveal_pos = TEXT_ENTRY_ZERO;
    }
    entry->flags = entry->flags & ~0x2D1;
    entry->flags = entry->flags | (flags & 0x2C1);
}
#pragma pop

void TWindowDuelResult::set_default_status(WindowTextEntry *entry, const char *text) { set_text_entry_string(entry, text, 0); }

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
        clip = TEXT_ENTRY_NO_WRAP_WIDTH;
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
    reveal_pos = TEXT_ENTRY_ZERO;
    color = rec->color;
    reveal_step = TWindowSubStatusDisp::get_card_window_scale(this->client);
    if (flags & 4) {
        reveal_step = reveal_step * TEXT_ENTRY_HALF;
    }
    if (reveal_step <= TEXT_ENTRY_ZERO) {
        reveal_pos = (9e+05f);
    }
    text = (char *)rec->text;
}
