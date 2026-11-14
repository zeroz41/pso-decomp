#include "types.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowHelpItem_8025A12C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/system/memory.h"
#include "pso/unk/TUnk_804CF930.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#pragma readonly_strings on

struct RecoveredGlobal_8025A594_lbl_804CF9F8 {
    s32 value;
    u8 remaining[0x14];
};

typedef struct Item_8025A354 {
    u16 flags;
    u8 pad2[6];
    f32 x;
    f32 y;
    s32 value10;
    u8 pad14[4];
    char *label;
    s32 cur;
    s32 next;
} Item_8025A354;

typedef struct Win_8025A354 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0x18];
    s32 f30;
    u8 pad34[4];
    f32 f38;
} Win_8025A354;

typedef struct Vec2_8025A354 { f32 x, y; } Vec2_8025A354;

extern "C" {
s32 sub_80256BDC__13TUnk_804CF930Fl(void *, void *);
void mem_free(void *p);
void *mem_alloc(u32 size);
s32 strncpy(s32, u32, s32);
void render_summary_row__15TWindowHelpItemFv(Item_8025A354 *self, Win_8025A354 *w);
s32 measure_string_len__20TWindowSubStatusDispFv(u32);

void *lbl_804CF9F8[6] = {
    0, 0,
    (void *)destroy__15TWindowHelpItemFPvs,
    (void *)tick_display_timer__15TWindowHelpItemFPv,
    (void *)render_summary_row__15TWindowHelpItemFv,
    0,
};

void TWindowHelpItem::update_visible_flags() {
    u16 *arg0 = (u16 *)this;
    s32 temp_r3;
    u16 temp_r0;

    temp_r0 = *arg0;
    temp_r3 = temp_r0 & 4;
    if ((temp_r3 != 0) || (temp_r0 & 8)) {
        if (temp_r3 == 0) {
            set_flag4_and_field1c(0);
        }
        if (!(*arg0 & 8)) {
            set_flag8_and_field20(0);
        }
    }
}

void TWindowHelpItem::draw_number_value(void *entry, f32 *pos, s32 value, s32 color, s32 percent) {
    f32 xy[2];
    text_builder_reset();
    TWindowSubStatusDisp__sub_80228F5C(value);
    if (percent) {
        text_builder_append((u8 *)((void *)"%"));
    }
    xy[0] = pos[0] - (f32)calc_text_width((char *)((void *)get_shared_text_buffer()));
    xy[1] = pos[1];
    draw_window_text((f32 *)xy, (const char *)((void *)get_shared_text_buffer()), color, 0, 1000000.0f);
}

void TWindowHelpItem::set_flag_0x10(u16 *arg0, s32 arg1) {
    if (arg1 != 0) {
        *arg0 |= 0x10;
        return;
    }
    *arg0 &= 0xFFFFFFEF;
}

void TWindowHelpItem::set_flag8_and_field20(s32 arg1) {
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 8);
    *(s32 *)&this->m_20 = arg1;
}

void TWindowHelpItem::set_compare_color(s32 arg1) {
    s32 temp_r0;

    temp_r0 = *(s32 *)&this->_pad1C;
    if (temp_r0 == arg1) {
        this->m_10 = -1;
        return;
    }
    if (temp_r0 > arg1) {
        this->m_10 = 0xFF77E8FF;
    } else {
        this->m_10 = 0xFFDD8C41;
    }
    *(s32 *)&this->unk_14 = 0x1E;
    set_flag4_and_field1c(arg1);
}

void TWindowHelpItem::set_flag4_and_field1c(s32 arg1) {
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 4);
    *(s32 *)&this->_pad1C = arg1;
}

void TWindowHelpItem::set_help_text(u32 arg1) {
    s32 temp_r3;

    mem_free(this->m_vtable18);
    this->m_vtable18 = 0;
    if (arg1 != 0U) {
        temp_r3 = measure_string_len__20TWindowSubStatusDispFv(arg1);
        *(s32 *)&this->m_vtable18 = (s32)mem_alloc(temp_r3 + 1);
        strncpy(*(s32 *)&this->m_vtable18, arg1, temp_r3 + 1);
    }
}

void render_summary_row__15TWindowHelpItemFv(Item_8025A354 *self, Win_8025A354 *w) {
    Vec2_8025A354 pos;
    s32 color;
    if (w->f30 < 0) {
        return;
    }
    if (!(self->flags & 4) && !(self->flags & 8)) {
        return;
    }
    pos.x = w->x + self->x;
    pos.y = w->y + self->y;
    set_text_draw_params((s32)w, 1, 0, (f32)(-1.0f / (0.0897f + w->f38)), 100000.0f);
    draw_window_text((f32 *)&pos, self->label, -1, 1, 100000.0f);
    pos.x += 86.0f;
    draw_window_text((f32 *)&pos, (const char *)((void *)":"), -1, 0, 100000.0f);
    pos.x += 64.0f;
    if (self->flags & 4) {
        TWindowHelpItem::draw_number_value(self, (f32 *)&pos, self->cur, self->value10, (s32)(TWindowHelpItem__sub_8025A600(self)));
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

void tick_display_timer__15TWindowHelpItemFPv(void *arg0) {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x14);
    if (temp_r4 > 0) {
        *(s32 *)((s8 *)arg0 + 0x14) = (temp_r4 - 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x14) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x10) = -1;
        }
    }
}

void *destroy__15TWindowHelpItemFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 4) = lbl_804CF9F8;
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 0x18)));
        ((TUnk_804CF930 *)arg0)->destroy((s16)(0));
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8025A594_lbl_804CF9F8_size[sizeof(RecoveredGlobal_8025A594_lbl_804CF9F8) == 0x18 ? 1 : -1];
u8 *TWindowHelpItem__sub_8025A594(u8 *arg0, s32 arg1, s32 arg2) {
    sub_80256BDC__13TUnk_804CF930Fl((void *)arg0, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_8025A594_lbl_804CF9F8 *)&lbl_804CF9F8).value;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 8))->copy_vec2((void *)(arg1 + 4));
    *(s32 *)((s8 *)arg0 + 0x10) = -1;
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    return arg0;
}

int TWindowHelpItem__sub_8025A600(void* p) { return *(u16*)((char*)p + 0x0) & 0x20; }

}
