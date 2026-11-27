#include "pso/system/memory.h"
#include "pso/math/FloatRound.h"
#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/BattleParamTables.h"
const char *TWindowMessage::class_name = "TWindowMessage";

extern "C" {


void TWindowMessage::scroll_up_line(WindowTextEntry *entry) {
    f32 d;
    s32 i;
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
    TWindowDuelResult::set_default_status(entry, 0);
}

void TWindowMessage::advance_reveal_cursor() {
    WindowTextEntry *e;
    s32 t;
    e = static_cast<WindowTextEntry *>(get_array_entry(reveal_line));
    while (e->get_text() != 0 && (e->flags & 0x10)) {
        t = reveal_line + 1;
        reveal_line = t;
        if (t >= line_count) {
            reveal_line = 0;
        }
        if (reveal_line == oldest_line) {
            break;
        }
        e = static_cast<WindowTextEntry *>(get_array_entry(reveal_line));
        if (lines[reveal_line].flags & 8) {
            lines[reveal_line].flags &= ~8;
            e->flags &= ~8;
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
        if (static_cast<WindowTextEntry *>(get_array_entry(i))->get_text() != 0) {
            if ((lines[i].flags & 4) && lines[i].timer > 0) {
                lines[i].timer--;
            }
        }
    }
    idx = oldest_line;
    e = static_cast<WindowTextEntry *>(get_array_entry(idx));
    m = &lines[idx];
    while (e->get_text() != 0 && m->timer <= 0 && (m->flags & 4)) {
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
    while (e->get_text() != 0 && e->y + e->height < scroll_offset[1]) {
        scroll_up_line(e);
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
    f32 distance;
    f32 target;
    f32 step;
    target = target_scroll_y;
    distance = target - scroll_offset[1];
    step = (0.15f) * distance;
    if (step < (15.0f)) {
        step = (15.0f);
    }
    if (distance < step) {
        scroll_offset[1] = target;
        return;
    }
    scroll_offset[1] += step;
}
#pragma pop

#pragma push
#pragma fp_contract on

#pragma readonly_strings on
s32 TWindowMessage::add_label_value_line(const char *label, const char *value, u32 flags) {
    const char *sep;
    f32 x;
    s32 r;
    WindowTextEntry *e;

    sep = " : ";
    text_builder_reset();
    text_builder_append(label);
    text_builder_append(sep);
    text_builder_append(value);
    e = (WindowTextEntry *)get_array_entry(next_line);
    r = append_line_colored(get_shared_text_buffer(), flags | 2, -1);
    if (r != 0) {
        x = (0.5f) * (target_size[0] - 8.0f);
        x -= (f32)calc_text_width((char *)label);
        x -= (0.5f) * (f32)calc_text_width((char *)sep);
        e->x = x;
    }
    return r;
}
#pragma readonly_strings reset
#pragma pop

}


s32 TWindowMessage::append_line_colored(const char *text, s32 flags, s32 color) {
    WindowTextEntry *e;
    TWindowMessageLine *rec;
    f32 y;
    f32 lim;
    if (text == 0) {
        return 0;
    }
    e = (WindowTextEntry *)get_array_entry(next_line);
    rec = &lines[next_line];
    if (e->get_text() != 0U) {
        scroll_up_line(e);
    }
    if (flags & 0x80) {
        next_line_y = scroll_offset[1];
    }
    if (flags & 0x10) {
        lim = (scroll_offset[1] + frame_size[1]) - 2e+01f;
        if (next_line_y < lim) {
            next_line_y = lim;
        }
    }
    if (flags & 8) {
        if (reveal_line == next_line) {
            flags &= ~8;
        } else {
            e->flags |= 8;
        }
    }
    e->y = next_line_y;
    e->color = color;
    if (flags & 2) {
        set_text_entry_string(e, text, 0x20);
    } else {
        set_text_entry_string(e, text, 0);
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
    y = frame_size[0] - 8.0f;
    if (window_flags & 0x80) {
        y -= 5.0f;
    }
    e->measure_text(y);
    if (flags & 0x200) {
        e->x = y - e->width;
    } else {
        e->x = 0.0f;
    }
    rec->flags = flags;
    rec->timer = line_display_ticks;
    if (++next_line >= line_count) {
        next_line = 0;
    }
    next_line_y += 2.0f + e->height;
    if (flags & 1) {
        target_scroll_y = (next_line_y - e->height) - 2.0f;
    } else if (next_line_y > (scroll_offset[1] + frame_size[1]) - 2e+01f) {
        lim = next_line_y - (frame_size[1] - 2e+01f);
        if (target_scroll_y < lim) {
            target_scroll_y = lim;
        }
    }
    return 1;
}


MessageWindowLayout message_window_layout_entries = {
    1, 0,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

WindowDescriptor message_window_settings = {
    {0.0f, 0.0f}, 50100.0f, &message_window_layout_entries, 3,
};


int TWindowMessage::append_line(const char *text, int flags) { return append_line_colored(text, flags, -1); }

void set_message_window_default_flags(void) {
    message_window_settings.flags = 3;
}

void set_message_window_flags(s32 flags) {
    message_window_settings.flags = flags;
}

WindowDescriptor *get_message_window_settings(void) {
    return &message_window_settings;
}

TWindowMessage *TWindowMessage::create(const NJS_POINT2 *position, const f32 *size, uaddr rows, s32 client) {
    set_message_window_size(size, rows);
    return new TWindowMessage(position, rows, client);
}

TWindowMessage *TWindowMessage::create(const NJS_POINT2 *pos, const f32 *size, saddr rows) {
    return TWindowMessage::create(pos, size, (u32)rows, 4);
}

TWindowMessage *create_message_window_for_size(NJS_POINT2 *pos, NJS_POINT2 *size) {
    return TWindowMessage::create(pos, (const f32 *)size, (s32)((s32)((s32) round_away_from_zero((size->y - 2e+01f) / 2e+01f) + 2)));
}

void set_message_window_size(const void *extent, u32 rows) {
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
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    this->update_scroll();
    this->retire_scrolled_lines();
    this->update_line_timers();
    this->advance_reveal_cursor();
    update_window();
    this->update_fade();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowMessage::~TWindowMessage() {
    if (this->lines != NULL) { delete[] this->lines; }
}
TWindowMessage::TWindowMessage(const NJS_POINT2 *position, u32 rows, s32 client) : TWindowAddition((u8 *)&message_window_settings, (s16)client, (u8 *)position) {
    u32 i;
    TWindowMessageLine *line;
    m_name = TWindowMessage::class_name;
    oldest_line = 0;
    reveal_line = 0;
    next_line = 0;
    line_count = rows;
    line_display_ticks = 0xB4;
    target_scroll_y = 0.0f;
    next_line_y = 0.0f;
    lines = new TWindowMessageLine[rows];
    line = lines;
    for (i = 0; i < rows; i++) {
        line->flags = 0;
        line->timer = 0;
        line++;
    }
}

