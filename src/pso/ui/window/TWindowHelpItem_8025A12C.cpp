#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowHelpItem_8025A12C.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/system/memory.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/vector.h"
#include <string.h>
#pragma readonly_strings on

typedef struct Item_8025A354 {
    u16 flags;
    u8 pad2[6];
    f32 x;
    f32 y;
    s32 color;
    s32 highlight_timer;
    char *label;
    s32 cur;
    s32 next;
} Item_8025A354;

extern "C" {
void render_summary_row__15TWindowHelpItemFv(Item_8025A354 *self, WindowDrawContext *w);

void *lbl_804CF9F8[6] = {
    0, 0,
    (void *)TWindowHelpItem::destroy,
    (void *)TWindowHelpItem::tick_display_timer,
    (void *)render_summary_row__15TWindowHelpItemFv,
    0,
};

void TWindowHelpItem::update_visible_flags() {
    Item_8025A354 *row = (Item_8025A354 *)this;
    s32 shows_cur;
    u16 flags;

    flags = row->flags;
    shows_cur = flags & 4;
    if ((shows_cur != 0) || (flags & 8)) {
        if (shows_cur == 0) {
            set_flag4_and_field1c(0);
        }
        if (!(row->flags & 8)) {
            set_flag8_and_field20(0);
        }
    }
}

void TWindowHelpItem::draw_number_value(void *entry, f32 *pos, s32 value, s32 color, s32 percent) {
    f32 xy[2];
    text_builder_reset();
    text_builder_append_int(value);
    if (percent) {
        text_builder_append((u8 *)((void *)"%"));
    }
    xy[0] = pos[0] - (f32)calc_text_width((char *)((void *)get_shared_text_buffer()));
    xy[1] = pos[1];
    draw_window_text((f32 *)xy, (const char *)((void *)get_shared_text_buffer()), color, 0, 1000000.0f);
}

void TWindowHelpItem::set_flag_0x10(u16 *flags, s32 on) {
    if (on != 0) {
        *flags |= 0x10;
        return;
    }
    *flags &= 0xFFFFFFEF;
}

void TWindowHelpItem::set_flag8_and_field20(s32 next_value) {
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 8);
    reinterpret_cast<Item_8025A354 *>(this)->next = next_value;
}

void TWindowHelpItem::set_compare_color(s32 count) {
    s32 cur;

    cur = reinterpret_cast<Item_8025A354 *>(this)->cur;
    if (cur == count) {
        reinterpret_cast<Item_8025A354 *>(this)->color = -1;
        return;
    }
    if (cur > count) {
        reinterpret_cast<Item_8025A354 *>(this)->color = 0xFF77E8FF;
    } else {
        reinterpret_cast<Item_8025A354 *>(this)->color = 0xFFDD8C41;
    }
    reinterpret_cast<Item_8025A354 *>(this)->highlight_timer = 0x1E;
    set_flag4_and_field1c(count);
}

void TWindowHelpItem::set_flag4_and_field1c(s32 count) {
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 4);
    reinterpret_cast<Item_8025A354 *>(this)->cur = count;
}

void TWindowHelpItem::set_help_text(uaddr str) {
    s32 len;

    mem_free(reinterpret_cast<Item_8025A354 *>(this)->label);
    reinterpret_cast<Item_8025A354 *>(this)->label = NULL;
    if (str != 0U) {
        len = (s32)measure_string_len((const char *)(str));
        reinterpret_cast<Item_8025A354 *>(this)->label = static_cast<char *>(mem_alloc(len + 1));
        strncpy(reinterpret_cast<Item_8025A354 *>(this)->label, reinterpret_cast<const char *>(str), (u32)len + 1);
    }
}

void render_summary_row__15TWindowHelpItemFv(Item_8025A354 *self, WindowDrawContext *w) {
    NJS_POINT2 pos;
    s32 color;
    if (w->open_tick < 0) {
        return;
    }
    if (!(self->flags & 4) && !(self->flags & 8)) {
        return;
    }
    pos.x = w->inner_x + self->x;
    pos.y = w->inner_y + self->y;
    set_text_draw_params(w, 1, 0, (f32)(-1.0f / (0.0897f + w->depth)), 100000.0f);
    draw_window_text((f32 *)&pos, self->label, -1, 1, 100000.0f);
    pos.x += 86.0f;
    draw_window_text((f32 *)&pos, (const char *)((void *)":"), -1, 0, 100000.0f);
    pos.x += 64.0f;
    if (self->flags & 4) {
        TWindowHelpItem::draw_number_value(self, (f32 *)&pos, self->cur, self->color, (s32)(TWindowHelpItem__sub_8025A600(self)));
    }
    if (self->flags & 8) {
        draw_window_text((f32 *)&pos, (const char *)((void *)"\tJ\x81\xA8"), -1, 0, 100000.0f);
        pos.x += 70.0f;
        if (!(self->flags & 0x10)) {
            color = 0xFF909090;
        } else if (self->cur == self->next) {
            color = -1;
        } else if (self->cur > self->next) {
            color = 0xFF77E8FF;
        } else {
            color = 0xFFDD8C41;
        }
        TWindowHelpItem::draw_number_value(self, (f32 *)&pos, self->next, color, (s32)(TWindowHelpItem__sub_8025A600(self)));
    }
}

void TWindowHelpItem::tick_display_timer(void *row_arg) {
    Item_8025A354 *row = (Item_8025A354 *)row_arg;
    s32 timer;

    timer = row->highlight_timer;
    if (timer > 0) {
        row->highlight_timer = (timer - 1);
        if ((s32) row->highlight_timer <= 0) {
            row->color = -1;
        }
    }
}

void *TWindowHelpItem::destroy(void *row, s16 flags) {
    if (row != NULL) {
        *(void ***)((s8 *)row + 4) = lbl_804CF9F8;
        mem_free(((Item_8025A354 *)row)->label);
        __dt__18TWindowLayoutEntryFv(row, 0);
        if (flags > 0) {
            ::operator delete(row);
        }
    }
    return row;
}

u8 *TWindowHelpItem__sub_8025A594(u8 *row_arg, saddr rec, s32 client) {
    Item_8025A354 *row = (Item_8025A354 *)row_arg;
    __ct__18TWindowLayoutEntryFl(row_arg, client);
    *(s32 **)((s8 *)row_arg + 4) = ((s32 *)&lbl_804CF9F8);
    copy_vec2((row_arg + 8), (void *)(rec + 4));
    row->color = -1;
    row->highlight_timer = 0;
    row->label = 0;
    row->cur = 0;
    row->next = 0;
    return row_arg;
}

int TWindowHelpItem__sub_8025A600(void* p) { return *(u16*)((char*)p + 0x0) & 0x20; }

}
