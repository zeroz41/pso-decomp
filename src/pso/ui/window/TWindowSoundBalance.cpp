#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "types.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSoundBalance.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"

#pragma readonly_strings on

// inferred: GaugeLayoutRecord, the type 1 record (0x24 bytes) behind entries 2 and 3, which
// set_music_gain (entry 2) and set_sound_effect_gain (entry 3) drive as gauges (TWindowStatusGauge::target).
struct GaugeLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    f32 pad_18;
    f32 pad_1C;
    f32 pad_20;
};

// inferred: window_sound_balance_layout_entries, the layout table window_sound_balance_settings
// points at (the "BGM" and "SE" labels and their two gauges).
struct SoundBalanceWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    GaugeLayoutRecord rec_2;
    GaugeLayoutRecord rec_3;
};
SoundBalanceWindowLayout window_sound_balance_layout_entries = {
    4, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, "BGM"},
    {3, {0.0f, 18.0f}, 0.5f, 0xFFFFFFFF, 0, "SE"},
    {1, {288.0f, 4.0f}, 0.5f, 0xFFFF0000, 8, 100.0f, 250.0f, 250.0f},
    {1, {288.0f, 22.0f}, 0.5f, 0xFF0000FF, 8, 100.0f, 100.0f, 100.0f},
};
WindowDescriptor window_sound_balance_settings = {
    {470.0f, 60.0f}, 50100.0f, &window_sound_balance_layout_entries, 3,
};

extern "C" {
const char *TWindowSoundBalance__name = "TWindowSoundBalance";

void TWindowSoundBalance::set_sound_effect_gain(s16 gain) {
    if (sound_effect_gain != gain) {
        sound_effect_gain = gain;
        TLobby__sub_8022614C(gain);
        TWindowStatusGauge *gauge = (TWindowStatusGauge *)get_array_entry(3);
        gauge->target = gain + 100;
        gauge->calc_bar_width();
    }
}

void TWindowSoundBalance::set_music_gain(s16 gain) {
    if (music_gain != gain) {
        music_gain = gain;
        update_music_stream_gain(gain);
        TWindowStatusGauge *gauge = (TWindowStatusGauge *)get_array_entry(2);
        gauge->target = gain + 250;
        gauge->calc_bar_width();
    }
}

void TWindowSoundBalance::apply_balance(WindowDrawContext *context) {
    u8 *entry = static_cast<u8 *>(get_array_entry(selection));
    draw_selection_bar(context, entry, is_active());
}

void TWindowSoundBalance::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}


void TWindowSoundBalance::play_open_sound() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
}


void TWindowSoundBalance::sub_8027095C() {
    ControllerInputContext *input = &controller_input_state.controllers[0];
    s16 gain;
    s16 range;
    s16 step;
    if (test_previous_buttons_color(input, 0xC0) != 0 ||
        test_previous_buttons_color(&controller_input_state.keyboard, 0xC0) != 0) {
        if (selection != 0) {
            gain = sound_effect_gain;
            range = 100;
        } else {
            gain = music_gain;
            range = 250;
        }
        step = 0.025f * range;
        if (test_previous_buttons_color(input, 0x80) != 0 ||
            test_previous_buttons_color(&controller_input_state.keyboard, 0x80) != 0) {
            gain += step;
        }
        if (test_previous_buttons_color(input, 0x40) != 0 ||
            test_previous_buttons_color(&controller_input_state.keyboard, 0x40) != 0) {
            gain -= step;
        }
        if (gain > 0) gain = 0;
        if (gain < -range) gain = -range;
        if (selection != 0) {
            set_sound_effect_gain(gain);
        } else {
            set_music_gain(gain);
        }
    }
}


void TWindowSoundBalance::handle_lr_input() {
    ControllerInputContext *input;
    input = &controller_input_state.controllers[0];
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x30, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x30, 6, 1) != 0)) {
        play_sound_effect(0x54100, NULL, 0, 0);
        if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->selection = (this->selection - 1);
        }
        if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->selection = (this->selection + 1);
        }
        if ((s8) this->selection < 0) {
            this->selection = 0U;
        }
        if ((s8) this->selection > 1) {
            this->selection = 1U;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowSoundBalance::render() {
    TWindowSoundBalance *self = this;
    WindowDrawContext *entry = self->draw_default_entry();
    self->draw_window_frame(entry);
    draw_visible_window_entries(
        self,
        &self->entry_list,
        entry);
    entry->inner_x += 174.0f;
    entry->inner_w -= 348.0f;
    self->apply_balance(entry);
}
#pragma pop

void TWindowSoundBalance::run_task() {
    ControllerInputContext *input;
    if (is_active() == 0) {
        handle_lr_input();
        sub_8027095C();
        input = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(input, 4) != 0) || ((s32)test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            play_open_sound();
        }
        if ((test_pressed_buttons_packed(input, 2) != 0) || ((s32)test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(&entry_list));
}

TWindowSoundBalance::~TWindowSoundBalance() {}
#pragma push
#pragma fp_contract on
TWindowSoundBalance::TWindowSoundBalance(const NJS_POINT2 *position)
    : TWindowBase((u8 *)&window_sound_balance_settings, 4, (u8 *)position) {
    u8 *e;
    SoundBalanceSettings *st;

    ((TWindowSoundBalance *)this)->m_name = TWindowSoundBalance__name;
    this->m_60 = 0;
    this->selection = 0;
    this->music_gain = 1;
    this->sound_effect_gain = 1;
    e = (u8 *)get_array_entry(0);
    char *label = reinterpret_cast<char *>(reinterpret_cast<TWindowSubComCard *>(e)->get_field_20());
    *(f32 *)((s8 *)e + 8) = 231.0f - 0.5f * calc_text_width(label);
    measure_message_text_width_default(e);
    e = (u8 *)get_array_entry(1);
    label = reinterpret_cast<char *>(reinterpret_cast<TWindowSubComCard *>(e)->get_field_20());
    *(f32 *)((s8 *)e + 8) = 231.0f - 0.5f * calc_text_width(label);
    measure_message_text_width_default(e);
    st = (SoundBalanceSettings *)TAdSinglePlyChrSelectGC::get_global_state();
    if (st == 0) {
        this->set_music_gain(0);
        this->set_sound_effect_gain(0);
    } else {
        this->set_music_gain(st->music_gain);
        this->set_sound_effect_gain(st->sound_effect_gain);
    }
}

#pragma pop

}
