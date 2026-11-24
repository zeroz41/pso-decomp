#include "pso/system/memory.h"
#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
const char *TWindowMessage__name = "TWindowMessage";

extern "C" {


void TWindowMessage::scroll_up_line(u8 *arg1) {
    f32 d;
    s32 i;
    WindowTextEntry *entry = reinterpret_cast<WindowTextEntry *>(arg1);
    WindowTextEntry *line;
    i = 0;
    d = 2.0f + entry->height;
    this->target_scroll_y -= d;
    this->scroll_offset[1] -= d;
    next_line_y -= d;
    for (; i < this->line_count; i++) {
        line = static_cast<WindowTextEntry *>(get_array_entry(i));
        line->y -= d;
    }
    entry->y = 0.0f;
    entry->height = 0.0f;
    TWindowDuelResult::set_default_status(arg1, 0);
}

void TWindowMessage::advance_reveal_cursor() {
    u16 *e;
    s32 t;
    e = ((u16 *)get_array_entry(reveal_line));
    while (((TWindowSubComCard *)e)->get_field_20() != 0 && (*e & 0x10)) {
        t = reveal_line + 1;
        reveal_line = t;
        if (t >= line_count) {
            reveal_line = 0;
        }
        if (reveal_line == oldest_line) {
            break;
        }
        e = ((u16 *)get_array_entry(reveal_line));
        if (lines[reveal_line].flags & 8) {
            lines[reveal_line].flags &= ~8;
            *e &= ~8;
        }
    }
}

void TWindowMessage::update_line_timers() {
    WindowTextEntry *e;
    u32 i;
    TWindowMessageLine *m;
    s32 idx;
    f32 h;
    for (i = 0; i < (u32)line_count; i++) {
        if (((TWindowSubComCard *)((u8 *)((TWindowBase *)this)->get_array_entry(i)))->get_field_20() != 0) {
            if ((lines[i].flags & 4) && lines[i].timer > 0) {
                lines[i].timer--;
            }
        }
    }
    idx = oldest_line;
    e = static_cast<WindowTextEntry *>(get_array_entry(idx));
    m = &lines[idx];
    while (((TWindowSubComCard *)e)->get_field_20() != 0 && m->timer <= 0 && (m->flags & 4)) {
        m->flags &= ~4;
        h = (1.0f) + (e->y + e->height);
        if (target_scroll_y < h) {
            target_scroll_y = h;
        }
        idx++;
        if (idx >= line_count) {
            idx = 0;
        }
        if (idx == oldest_line) {
            break;
        }
        e = static_cast<WindowTextEntry *>(get_array_entry(idx));
        m = &lines[idx];
    }
}

void TWindowMessage::retire_scrolled_lines() {
    WindowTextEntry *e;
    TWindowMessageLine *m;
    e = static_cast<WindowTextEntry *>(get_array_entry(oldest_line));
    m = &lines[oldest_line];
    while (((TWindowSubComCard *)e)->get_field_20() != 0 && e->y + e->height < scroll_offset[1]) {
        scroll_up_line(reinterpret_cast<u8 *>(e));
        m->flags = 0;
        m->timer = 0;
        if (reveal_line == oldest_line) {
            if (++reveal_line >= line_count) {
                reveal_line = 0;
            }
        }
        if (++oldest_line >= line_count) {
            oldest_line = 0;
        }
        e = static_cast<WindowTextEntry *>(get_array_entry(oldest_line));
        m = &lines[oldest_line];
        if (m->flags & 8) {
            m->flags &= ~8;
            e->flags &= ~8;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowMessage::update_scroll() {
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f1;
    temp_f3 = target_scroll_y;
    temp_f2 = temp_f3 - scroll_offset[1];
    var_f1 = (0.15f) * temp_f2;
    if (var_f1 < (15.0f)) {
        var_f1 = (15.0f);
    }
    if (temp_f2 < var_f1) {
        scroll_offset[1] = temp_f3;
        return;
    }
    scroll_offset[1] += var_f1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 get_shared_text_buffer(void);
s32 append_message_window_line(TWindowMessage *self, s32 text, s32 flags, s32 color);

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
    e = (u8 *)((TWindowBase *)this)->get_array_entry(*(s32 *)(((u8 *)this) + 0x88));
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

s32 append_message_window_line(TWindowMessage *self, s32 text, s32 flags, s32 color) {
    Entry_80269A0C *e;
    TWindowMessageLine *rec;
    f32 y;
    f32 lim;
    if (text == 0) {
        return 0;
    }
    e = (Entry_80269A0C *)self->get_array_entry(self->next_line);
    rec = &self->lines[self->next_line];
    if (((TWindowSubComCard *)e)->get_field_20() != 0U) {
        self->scroll_up_line((u8 *)e);
    }
    if (flags & 0x80) {
        self->next_line_y = self->scroll_offset[1];
    }
    if (flags & 0x10) {
        lim = (self->scroll_offset[1] + self->frame_size[1]) - 2e+01f;
        if (self->next_line_y < lim) {
            self->next_line_y = lim;
        }
    }
    if (flags & 8) {
        if (self->reveal_line == self->next_line) {
            flags &= ~8;
        } else {
            e->flags |= 8;
        }
    }
    e->fC = self->next_line_y;
    e->f24 = color;
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
    y = self->frame_size[0] - 8.0f;
    if (self->window_flags & 0x80) {
        y -= 5.0f;
    }
    measure_message_text_width(e, y);
    if (flags & 0x200) {
        e->f8 = y - e->f10;
    } else {
        e->f8 = 0.0f;
    }
    rec->flags = flags;
    rec->timer = self->line_display_ticks;
    if (++self->next_line >= self->line_count) {
        self->next_line = 0;
    }
    self->next_line_y += 2.0f + e->f14;
    if (flags & 1) {
        self->target_scroll_y = (self->next_line_y - e->f14) - 2.0f;
    } else if (self->next_line_y > (self->scroll_offset[1] + self->frame_size[1]) - 2e+01f) {
        lim = self->next_line_y - (self->frame_size[1] - 2e+01f);
        if (self->target_scroll_y < lim) {
            self->target_scroll_y = lim;
        }
    }
    return 1;
}

}

// inferred: message_window_layout_entries, the layout table message_window_settings points at: one
// text record per row, rows set to the line count by TLobby__sub_80269DA4.
struct MessageWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

MessageWindowLayout message_window_layout_entries = {
    1, 0,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

WindowDescriptor message_window_settings = {
    {0.0f, 0.0f}, 50100.0f, &message_window_layout_entries, 3,
};

extern "C" {

int TWindowMessage::append_line(int text, int flags) { return append_message_window_line((TWindowMessage *)this, text, flags, -1); }

void TLobby__sub_80269C90(void) {
    message_window_settings.flags = 3;
}

void TLobby__sub_80269CA4(s32 arg0) {
    message_window_settings.flags = arg0;
}

WindowDescriptor *TLobby__sub_80269CB4(void) {
    return &message_window_settings;
}

u8 *TWindowMessage::create(saddr parent, const f32 *size, uaddr rows, s32 client) {
    TLobby__sub_80269DA4(size, rows);
    return (u8 *)new TWindowMessage(parent, rows, client);
}

u8 *TWindowMessage::create(const NJS_POINT2 *pos, const f32 *size, saddr rows) {
    return TWindowMessage::create((saddr)pos, size, (u32)rows, 4);
}

u8 *create_message_window_for_size(NJS_POINT2 *pos, NJS_POINT2 *size) {
    return TWindowMessage::create(pos, (const f32 *)size, (s32)((s32)((s32) TWindowSubStatusDisp::round_away_from_zero((size->y - 2e+01f) / 2e+01f) + 2)));
}

void TLobby__sub_80269DA4(const void *extent, u32 rows) {
    const f32 *size = static_cast<const f32 *>(extent);
    NJS_POINT2 *dst = (NJS_POINT2 *)&message_window_settings;
    dst->x = size[0];
    dst->y = size[1];
    message_window_layout_entries.rows = rows;
}



void TWindowMessage::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowMessage::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    ((TWindowMessage *)arg0)->update_scroll();
    ((TWindowMessage *)arg0)->retire_scrolled_lines();
    ((TWindowMessage *)arg0)->update_line_timers();
    ((TWindowMessage *)arg0)->advance_reveal_cursor();
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowMessage::~TWindowMessage() {
    if (this->lines != NULL) { mem_free(this->lines); }
}
TWindowMessage::TWindowMessage(saddr parent, u32 rows, s32 client) : TWindowAddition((u8 *)&message_window_settings, (s16)client, (u8 *)parent) {
    u32 i;
    TWindowMessageLine *line;
    m_name = TWindowMessage__name;
    oldest_line = 0;
    reveal_line = 0;
    next_line = 0;
    line_count = rows;
    line_display_ticks = 0xB4;
    target_scroll_y = 0.0f;
    next_line_y = 0.0f;
    lines = static_cast<TWindowMessageLine *>(mem_alloc(rows * sizeof(*lines)));
    line = lines;
    for (i = 0; i < rows; i++) {
        line->flags = 0;
        line->timer = 0;
        line++;
    }
}

}
