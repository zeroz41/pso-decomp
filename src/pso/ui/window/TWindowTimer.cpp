#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/object/lobby/LobbyGoGoBall.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowTimer.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/vector.h"

#pragma readonly_strings on

// inferred: window_timer_layout_entries, the layout table window_timer_layout points at.
struct TimerWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

TimerWindowLayout window_timer_layout_entries = {
    1, 1,
    {3, {0.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
};

WindowDescriptor window_timer_layout = {
    {104.0f, 27.0f}, 50100.0f, &window_timer_layout_entries, 0x828,
};

const char *TWindowTimer__name = "TWindowTimer";

/* Window entry view: the text entry the timer centres (x at +8). */
struct TimerEntry {
    u8 pad_0[8];
    f32 x;
};

extern "C" {
saddr get_window_layout_position(s32);
void init_timer_window_layout(TWindowTimer *self);
void init_timer_window_layout_alt(TWindowTimer *self);

#pragma push
#pragma fp_contract on
void init_timer_window_layout(TWindowTimer *self) {
    f32 width;
    TimerEntry *entry;
    self->flags |= 1;
    width = (f32)calc_text_width("000:000");
    entry = (TimerEntry *)self->get_array_entry(0);
    entry->x = 48.0f - 0.5f * width;
}
#pragma pop

#pragma push
#pragma fp_contract on
void init_timer_window_layout_alt(TWindowTimer *self) {
    f32 width;
    TimerEntry *entry;
    self->flags &= ~1;
    width = (f32)calc_text_width("0'00\"00");
    entry = (TimerEntry *)self->get_array_entry(0);
    entry->x = 48.0f - 0.5f * width;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowTimer::ease_window_timer_position() {
    frame_position[0] += 0.21f * (target_position[0] - frame_position[0]);
    frame_position[1] += 0.21f * (target_position[1] - frame_position[1]);
}
#pragma pop

void TWindowTimer::update_chat_parts() {
    saddr window_layout_position;

    if (this->flags & 1) {
        window_layout_position = get_window_layout_position(0xA9);
    } else if ((TWindowSubShortMail::is_active() != 0) || (is_com_card_active() != 0) || (is_guild_card_receive_active() != 0)) {
        window_layout_position = get_window_layout_position(0xA8);
    } else {
        window_layout_position = get_window_layout_position(0x22);
    }
    copy_vec2(target_position, (void*)window_layout_position);
}

void TWindowTimer::draw(s32 arg1, s32 arg2) {
    saddr array_entry;

    array_entry = reinterpret_cast<saddr>(get_array_entry(0));
    text_builder_reset();
    text_builder_append((u8 *)"\tC8");
    append_padded_number(arg1, 3);
    text_builder_append((u8 *)"\tC7:\tC3");
    append_padded_number(arg2, 3);
    set_text_entry_string((u8 *)array_entry, (uaddr)(get_shared_text_buffer()), 0x20);
    ((TWindowHelpItem *)array_entry)->reset_float_field();
}

void TWindowTimer::set_time(u32 secs) {
    saddr entry;
    u32 hours;
    u32 mins;
    entry = reinterpret_cast<saddr>(get_array_entry(0));
    text_builder_reset();
    hours = secs / 3600;
    secs %= 3600;
    if (hours > 9) {
        text_builder_append((u8 *)"9'59\"59");
    } else {
        append_padded_number((hours), 1);
        text_builder_append((u8 *)"'");
        mins = secs / 60;
        secs %= 60;
        append_padded_number((mins), 2);
        text_builder_append((u8 *)"\"");
        append_padded_number((secs), 2);
    }
    set_text_entry_string((u8 *)entry, (uaddr)(get_shared_text_buffer()), 0x20);
    ((TWindowHelpItem *)entry)->reset_float_field();
}

void TWindowTimer::draw_tab(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, 3, -64.0f);
}

TWindowTimer *TWindowTimer::create() {
    TWindowTimer *window_timer = new TWindowTimer();
    init_timer_window_layout(window_timer);
    return window_timer;
}

TWindowTimer *TWindowTimer::create_alt() {
    TWindowTimer *window_timer = new TWindowTimer();
    init_timer_window_layout_alt(window_timer);
    return window_timer;
}

void TWindowTimer::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_tab(context);
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowTimer::run_task() {
    if (flags & 1) {
        draw(get_gogo_ball_score(0), get_gogo_ball_score(1));
    }
    ((TWindowDD *)this)->initialize_subwindow();
    update_chat_parts();
    ease_window_timer_position();
    update_window_entry_list(&entry_list);
}

TWindowTimer::~TWindowTimer() {}
TWindowTimer::TWindowTimer() : TWindowBase((u8 *)&window_timer_layout, 4, (u8 *)(get_zero_vec2())) {
    m_name = TWindowTimer__name;
    flags = 0;
    update_chat_parts();
    save_position();
}

}
