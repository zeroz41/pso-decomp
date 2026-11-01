#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowDuelResult.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TLobby_80269C6C.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowDD.h"

struct RecoveredFields_802698C4_arg0 {
    u8 unknown_0[0x6C];
    f32 field_6C;
    u8 unknown_70[0x14];
    f32 field_84;
};

struct Ent_802695A8 { u32 flags; u32 x; };

struct Msg_802695A8 {
    u8 pad0[0x70];
    s32 sel;
    s32 cur;
    u8 pad2[4];
    Ent_802695A8 *ents;
    u8 pad3[0xC];
    s32 cnt;
};

struct Meta_802697B4 {
    u32 flags;
    s32 timer;
};

struct Q_802697B4 {
    u8 pad0[0x6C];
    f32 scroll;
    s32 oldest;
    s32 reveal;
    s32 duration;
    Meta_802697B4 *meta;
    u8 pad80[0xC];
    s32 capacity;
};

struct Meta_80269664 { u32 flags; s32 timer; };

struct Q_80269664 {
    u8 pad0[0x70];
    s32 oldest;
    u8 pad74[0x7C - 0x74];
    Meta_80269664 *meta;
    u8 pad80[4];
    f32 height;
    u8 pad88[4];
    s32 capacity;
};

struct Ent_80269664 { u8 pad0[0xC]; f32 y; u8 pad10[4]; f32 h; };

extern "C" {
u8 *get_array_entry__11TWindowBaseFi(void *, s32);

u32 get_field_20__17TWindowSubComCardFv(void *);

void TWindowMessage::scroll_up_line(u8 *arg1) {
    f32 d;
    s32 i;
    u8 *e;
    i = 0;
    d = 2.0f + *(f32 *)(arg1 + 0x14);
    this->m_84 -= d;
    this->m_6c -= d;
    *(f32 *)(((u8 *)this) + 0x80) -= d;
    for (; i < this->line_count; i++) {
        e = get_array_entry__11TWindowBaseFi(this, i);
        *(f32 *)(e + 0xC) -= d;
    }
    *(f32 *)(arg1 + 0xC) = 0.0f;
    *(f32 *)(arg1 + 0x14) = 0.0f;
    TWindowDuelResult::set_default_status(arg1, 0);
}

void TWindowMessage::advance_reveal_cursor() {
    u16 *e;
    s32 t;
    e = ((u16 *)get_array_entry__11TWindowBaseFi(((Msg_802695A8 *)this), ((Msg_802695A8 *)this)->cur));
    while (get_field_20__17TWindowSubComCardFv(e) != 0 && (*e & 0x10)) {
        t = ((Msg_802695A8 *)this)->cur + 1;
        ((Msg_802695A8 *)this)->cur = t;
        if (t >= ((Msg_802695A8 *)this)->cnt) {
            ((Msg_802695A8 *)this)->cur = 0;
        }
        if (((Msg_802695A8 *)this)->cur == ((Msg_802695A8 *)this)->sel) {
            break;
        }
        e = ((u16 *)get_array_entry__11TWindowBaseFi(((Msg_802695A8 *)this), ((Msg_802695A8 *)this)->cur));
        if (((Msg_802695A8 *)this)->ents[((Msg_802695A8 *)this)->cur].flags & 8) {
            ((Msg_802695A8 *)this)->ents[((Msg_802695A8 *)this)->cur].flags &= ~8;
            *e &= ~8;
        }
    }
}

void TWindowMessage::update_line_timers() {
    Ent_80269664 *e;
    u32 i;
    Meta_80269664 *m;
    s32 idx;
    f32 h;
    for (i = 0; i < (u32)((Q_80269664 *)this)->capacity; i++) {
        if (get_field_20__17TWindowSubComCardFv(get_array_entry__11TWindowBaseFi(this, i)) != 0) {
            if ((((Q_80269664 *)this)->meta[i].flags & 4) && ((Q_80269664 *)this)->meta[i].timer > 0) {
                ((Q_80269664 *)this)->meta[i].timer--;
            }
        }
    }
    idx = ((Q_80269664 *)this)->oldest;
    e = (Ent_80269664 *)get_array_entry__11TWindowBaseFi(((Q_80269664 *)this), idx);
    m = &((Q_80269664 *)this)->meta[idx];
    while (get_field_20__17TWindowSubComCardFv(e) != 0 && m->timer <= 0 && (m->flags & 4)) {
        m->flags &= ~4;
        h = (1.0f) + (e->y + e->h);
        if (((Q_80269664 *)this)->height < h) {
            ((Q_80269664 *)this)->height = h;
        }
        idx++;
        if (idx >= ((Q_80269664 *)this)->capacity) {
            idx = 0;
        }
        if (idx == ((Q_80269664 *)this)->oldest) {
            break;
        }
        e = (Ent_80269664 *)get_array_entry__11TWindowBaseFi(((Q_80269664 *)this), idx);
        m = &((Q_80269664 *)this)->meta[idx];
    }
}

void TWindowMessage::retire_scrolled_lines() {
    Q_802697B4 *w = (Q_802697B4 *)this;
    u8 *e;
    Meta_802697B4 *m;
    e = get_array_entry__11TWindowBaseFi(w, w->oldest);
    m = &w->meta[w->oldest];
    while (get_field_20__17TWindowSubComCardFv(e) != 0 && *(f32 *)(e + 0xC) + *(f32 *)(e + 0x14) < w->scroll) {
        ((TWindowMessage *)w)->scroll_up_line(e);
        m->flags = 0;
        m->timer = 0;
        if (w->reveal == w->oldest) {
            if (++w->reveal >= w->capacity) {
                w->reveal = 0;
            }
        }
        if (++w->oldest >= w->capacity) {
            w->oldest = 0;
        }
        e = get_array_entry__11TWindowBaseFi(w, w->oldest);
        m = &w->meta[w->oldest];
        if (m->flags & 8) {
            m->flags &= ~8;
            *(u16 *)e &= ~8;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowMessage::update_scroll() {
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f1;
    temp_f3 = ((struct RecoveredFields_802698C4_arg0 *)this)->field_84;
    temp_f2 = temp_f3 - ((struct RecoveredFields_802698C4_arg0 *)this)->field_6C;
    var_f1 = (0.15f) * temp_f2;
    if (var_f1 < (15.0f)) {
        var_f1 = (15.0f);
    }
    if (temp_f2 < var_f1) {
        ((struct RecoveredFields_802698C4_arg0 *)this)->field_6C = temp_f3;
        return;
    }
    ((struct RecoveredFields_802698C4_arg0 *)this)->field_6C += var_f1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 get_shared_text_buffer(void);
s32 append_message_window_line(TWindowMessage *self, s32 text, s32 flags, s32 arg3);

#pragma readonly_strings on
s32 TWindowOptionCtrl::add_label_value_line(const char *arg1, const char *arg2, u32 arg3) {
    const char *sep;
    f32 x;
    s32 r;
    u8 *e;

    sep = " : ";
    text_builder_reset();
    text_builder_append((u8 *)arg1);
    text_builder_append((u8 *)sep);
    text_builder_append((u8 *)arg2);
    e = get_array_entry__11TWindowBaseFi(this, *(s32 *)(((u8 *)this) + 0x88));
    r = append_message_window_line((TWindowMessage *)this, get_shared_text_buffer(), arg3 | 2, -1);
    if (r != 0) {
        x = (0.5f) * (*(f32 *)(((u8 *)this) + 0x38) - 8.0f);
        x -= (f32)calc_text_width((char *)arg1);
        x -= (0.5f) * (f32)calc_text_width((char *)sep);
        *(f32 *)(e + 8) = x;
    }
    return r;
}
#pragma readonly_strings reset
#pragma pop

}

struct Entry_80269A0C {
    u16 flags;
    u8 pad2[6];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 pad18[0x24 - 0x18];
    s32 f24;
};

extern "C" {
void measure_message_text_width(void *, f32);

s32 append_message_window_line(TWindowMessage *self, s32 text, s32 flags, s32 arg3);
s32 append_message_window_line(TWindowMessage *self, s32 text, s32 flags, s32 arg3) {
    Entry_80269A0C *e;
    TWindowMessageLine *rec;
    f32 y;
    f32 lim;
    if (text == 0) {
        return 0;
    }
    e = (Entry_80269A0C *)get_array_entry__11TWindowBaseFi(self, self->next_line);
    rec = &self->lines[self->next_line];
    if (((TWindowSubComCard *)e)->get_field_20() != 0U) {
        self->scroll_up_line((u8 *)e);
    }
    if (flags & 0x80) {
        self->unk_80 = self->m_6c;
    }
    if (flags & 0x10) {
        lim = (self->m_6c + self->m_4c) - 2e+01f;
        if (self->unk_80 < lim) {
            self->unk_80 = lim;
        }
    }
    if (flags & 8) {
        if (self->m_74 == self->next_line) {
            flags &= ~8;
        } else {
            e->flags |= 8;
        }
    }
    e->fC = self->unk_80;
    e->f24 = arg3;
    if (flags & 2) {
        set_text_entry_string((u8 *)e, text, 0x20);
    } else {
        set_text_entry_string((u8 *)e, text, 0);
    }
    if (flags & 0x20) {
        e->flags |= 1;
    }
    if (flags & 0x40) {
        e->flags |= 0x40;
    }
    if (flags & 0x100) {
        e->flags |= 0x80;
    }
    if (flags & 0x400) {
        e->flags |= 0x200;
    }
    y = self->m_48 - 8.0f;
    if (self->m_2c & 0x80) {
        y -= 5.0f;
    }
    measure_message_text_width(e, y);
    if (flags & 0x200) {
        e->f8 = y - e->f10;
    } else {
        e->f8 = 0.0f;
    }
    rec->flags = flags;
    rec->timer = self->m_78;
    if (++self->next_line >= self->line_count) {
        self->next_line = 0;
    }
    self->unk_80 += 2.0f + e->f14;
    if (flags & 1) {
        self->m_84 = (self->unk_80 - e->f14) - 2.0f;
    } else if (self->unk_80 > (self->m_6c + self->m_4c) - 2e+01f) {
        lim = self->unk_80 - (self->m_4c - 2e+01f);
        if (self->m_84 < lim) {
            self->m_84 = lim;
        }
    }
    return 1;
}

}

struct RecoveredGlobal_80269CA4_lbl_804D071C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80269CB4_lbl_804D071C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80269C90_lbl_804D071C {
    s32 value;
    u8 remaining[0x10];
};

struct V2_80269DA4 { f32 x; f32 y; };
struct G_80269DA4 { s32 a; s32 b; };

extern "C" {
s32 TLobby__sub_80269DA4(V2_80269DA4 size, void *arg1);
extern G_80269DA4 lbl_804D06F8[];
u8 *TWindowMessage__ct(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
u8 *__nw__7TObjectFUl(s32);
extern RecoveredGlobal_80269CA4_lbl_804D071C message_window_settings;

int TWindowMessage::append_line(int a1, int a2) { return append_message_window_line((TWindowMessage *)this, a1, a2, -1); }

typedef char RecoveredGlobal_80269CA4_lbl_804D071C_size[sizeof(RecoveredGlobal_80269CA4_lbl_804D071C) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_80269C90_lbl_804D071C_size[sizeof(RecoveredGlobal_80269C90_lbl_804D071C) == 0x14 ? 1 : -1];
void TLobby__sub_80269C90(void) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80269C90_lbl_804D071C *)&message_window_settings).value) + 0x10) = 3;
}

void TLobby__sub_80269CA4(s32 arg0) {
    *(s32 *)((s8 *)&message_window_settings.value + 0x10) = arg0;
}

typedef char RecoveredGlobal_80269CB4_lbl_804D071C_size[sizeof(RecoveredGlobal_80269CB4_lbl_804D071C) == 0x14 ? 1 : -1];
s32 *TLobby__sub_80269CB4(void) {
    return &(*(RecoveredGlobal_80269CB4_lbl_804D071C *)&message_window_settings).value;
}

u8 *TWindowMessage::create(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    u8 *temp_r3;
    u8 *var_r0;
    ((s32 (*)(void *, void *))TLobby__sub_80269DA4)((void *)arg1, (void *)arg2);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x90));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowMessage__ct(temp_r3, arg0, arg2, arg3));
    }
    return var_r0;
}

u8 *TWindowMessage::create(void *arg0, s32 arg1, s32 arg2) {
    return TWindowMessage::create((s32)arg0, (s32)arg1, (u32)arg2, 4);
}

void TLobby::update_window_mode_from_progress(void *arg1) {
    s32 arg0 = (s32)this;
    TWindowMessage::create((void *)arg0, (s32)arg1, (s32)((s32)((s32) TWindowSubStatusDisp::round_away_from_zero((*(f32 *)((s8 *)arg1 + 4) - 2e+01f) / 2e+01f) + 2)));
}

s32 TLobby__sub_80269DA4(V2_80269DA4 size, void *arg1) {
    V2_80269DA4 *dst = (V2_80269DA4 *)&message_window_settings;
    dst->x = size.x;
    dst->y = size.y;
    lbl_804D06F8[0].b = (s32)arg1;
}

}

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
void *mem_alloc(u32 size);
void *construct_with_parent__15TWindowAdditionFPv(void *, void *, s16, s32);
extern s32 __vt__14TWindowMessage[];
extern s32 lbl_805D3980;

u8 *TWindowMessage__ct(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
void *__dt__14TWindowMessageFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void mem_free(void *);

void TWindowMessage::render() {
    s32 temp_r3;
    s32 arg0 = (s32)this;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

void TWindowMessage::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->m_2c & 2)) {
        this->m_5c = 0x01000000;
    }
    ((TWindowMessage *)arg0)->update_scroll();
    ((TWindowMessage *)arg0)->retire_scrolled_lines();
    ((TWindowMessage *)arg0)->update_line_timers();
    ((TWindowMessage *)arg0)->advance_reveal_cursor();
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *__dt__14TWindowMessageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowMessage;
        if (*(void **)((s8 *)arg0 + 0x7C) != NULL) { mem_free(*(void **)((s8 *)arg0 + 0x7C)); }
        ((TWindowAddition *)arg0)->destroy_window(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowMessage__ct(u8 *arg0, s32 arg1, u32 arg2, s32 arg3) {
    u32 i;
    u8 *p;
    construct_with_parent__15TWindowAdditionFPv(arg0, (u8 *)&message_window_settings, arg3, arg1);
    *(void **)(arg0 + 0x18) = ((u8 *)&__vt__14TWindowMessage);
    *(s32 *)arg0 = lbl_805D3980;
    *(s32 *)(arg0 + 0x70) = 0;
    *(s32 *)(arg0 + 0x74) = 0;
    *(s32 *)(arg0 + 0x88) = 0;
    *(u32 *)(arg0 + 0x8C) = arg2;
    *(s32 *)(arg0 + 0x78) = 0xB4;
    *(f32 *)(arg0 + 0x84) = 0.0f;
    *(f32 *)(arg0 + 0x80) = 0.0f;
    *(u8 **)(arg0 + 0x7C) = (u8 *)mem_alloc(arg2 * 8);
    p = *(u8 **)(arg0 + 0x7C);
    for (i = 0; i < arg2; i++) {
        *(s32 *)p = 0;
        *(s32 *)(p + 4) = 0;
        p += 8;
    }
    return arg0;
}

}
