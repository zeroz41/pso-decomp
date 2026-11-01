#include "types.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TWindowSubShortMail_80246CB8.h"
#include "pso/misc/TWindowSubStatusDisp_80228CC0.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/unk/text_80198A2C.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowTimer.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct RecoveredGlobal_80287FBC_lbl_804D2E74 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80287FBC___vt__12TWindowTimer {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_window_tab(void *, void *, int, f32);
extern const f32 lbl_805DD890;
extern RecoveredGlobal_80287FBC_lbl_804D2E74 window_timer_layout;
extern s32 __vt__12TWindowTimer[];
extern s32 TWindowTimer__name;
extern s32 lbl_8044FCE8[];
extern s32 lbl_805DD888;
extern s32 lbl_805DD88C;
s32 get_window_layout_position(s32);
void __dl__7TObjectFPv(void *);
s32 __nw__7TObjectFUl(s32);
s32 init_timer_window_layout(s32);
s32 init_timer_window_layout_alt(s32);

void TWindowTimer::update_chat_parts() {
    u8 *arg0 = (u8 *)this;
    s32 window_layout_position;

    if (this->m_60 & 1) {
        window_layout_position = get_window_layout_position(0xA9);
    } else if ((TWindowSubShortMail::is_active() != 0) || (is_com_card_active() != 0) || (is_guild_card_receive_active() != 0)) {
        window_layout_position = get_window_layout_position(0xA8);
    } else {
        window_layout_position = get_window_layout_position(0x22);
    }
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x30))->copy_vec2((void*)window_layout_position);
}

extern s32 lbl_8044FCE0[];
extern s32 lbl_805DD884;

void TWindowTimer::draw(s32 arg1, s32 arg2) {
    s32 array_entry;

    array_entry = get_array_entry(0);
    text_builder_reset();
    text_builder_append((u8 *)&lbl_805DD884);
    append_padded_number(arg1, 3);
    text_builder_append((u8 *)lbl_8044FCE0);
    append_padded_number(arg2, 3);
    set_text_entry_string((u8 *)array_entry, (u32)(get_shared_text_buffer()), 0x20);
    ((TWindowHelpItem *)array_entry)->reset_float_field();
}

void TWindowTimer::set_time(u32 secs) {
    s32 entry;
    u32 hours;
    u32 mins;
    entry = get_array_entry(0);
    text_builder_reset();
    hours = secs / 3600;
    secs %= 3600;
    if (hours > 9) {
        text_builder_append((u8 *)lbl_8044FCE8);
    } else {
        append_padded_number((hours), 1);
        text_builder_append((u8 *)&lbl_805DD888);
        mins = secs / 60;
        secs %= 60;
        append_padded_number((mins), 2);
        text_builder_append((u8 *)&lbl_805DD88C);
        append_padded_number((secs), 2);
    }
    set_text_entry_string((u8 *)entry, (u32)(get_shared_text_buffer()), 0x20);
    ((TWindowHelpItem *)entry)->reset_float_field();
}

void TWindowTimer::draw_tab(s32 arg0, s32 arg1) {
    draw_window_tab((void *)arg1, (void *)(arg1 + 0x10), 3, (f32)lbl_805DD890);
}

s32 TWindowTimer::create() {
    s32 window_timer;

    window_timer = __nw__7TObjectFUl(0x64);
    if (window_timer != 0) {
        window_timer = ((s32)TWindowTimer__ct((TWindowTimer *)((u8 *)((void *)window_timer))));
    }
    init_timer_window_layout(window_timer);
    return window_timer;
}

s32 TWindowTimer::create_alt() {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0x64);
    if (var_r31 != 0) {
        var_r31 = ((s32)TWindowTimer__ct((TWindowTimer *)((u8 *)((void *)var_r31))));
    }
    init_timer_window_layout_alt(var_r31);
    return var_r31;
}

void render__12TWindowTimerFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    TWindowTimer::draw_tab(arg0, temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

void run_task__12TWindowTimerFv(TWindowTimer *window_timer) {
  if ((window_timer->m_60) & 1)
  {
    window_timer->draw((s32)((int) TWindowTimer::get_timer_value(0)), (s32)((int) TWindowTimer::get_timer_value(1)));
  }
 do { ((TWindowDD *)window_timer)->initialize_subwindow(); window_timer->update_chat_parts(); window_timer->ease_window_timer_position(); ((TWindowBase *)window_timer)->update_window_entry_list((u8 *)window_timer + 0x24); } while (0);
}

void *__dt__12TWindowTimerFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TWindowTimer;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80287FBC_lbl_804D2E74_size[sizeof(RecoveredGlobal_80287FBC_lbl_804D2E74) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80287FBC___vt__12TWindowTimer_size[sizeof(RecoveredGlobal_80287FBC___vt__12TWindowTimer) == 0x18 ? 1 : -1];
u8 *TWindowTimer__ct(TWindowTimer *window_timer) {
    ((TWindowDD *)window_timer)->construct_base((u8 *)&window_timer_layout.value, (s16)4, (u8 *)(get_zero_vec2()));
    *(s32 **)((s8 *)window_timer + 0x18) = &(*(RecoveredGlobal_80287FBC___vt__12TWindowTimer *)&__vt__12TWindowTimer).value;
    *(s32 *)((s8 *)window_timer + 0) = (s32) TWindowTimer__name;
    window_timer->m_60 = 0;
    window_timer->update_chat_parts();
    ((TWindowBase *)window_timer)->save_position();
    return (u8 *)window_timer;
}

}
