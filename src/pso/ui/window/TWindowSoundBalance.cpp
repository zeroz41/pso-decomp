#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/audio/SoundRequests.h"
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
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowTextEntry.h"

#pragma readonly_strings on

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

const char *TWindowSoundBalance::class_name = "TWindowSoundBalance";

void TWindowSoundBalance::set_sound_effect_gain(s16 gain) {
    if (sound_effect_gain != gain) {
        sound_effect_gain = gain;
        set_cue_stream_user_gain(gain);
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
    TWindowLayoutRect *entry = static_cast<TWindowLayoutRect *>(get_array_entry(selection));
    draw_selection_bar(context, entry, is_active());
}

void TWindowSoundBalance::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->result_flags = (u8) (this->result_flags | 2);
    }
}


void TWindowSoundBalance::play_open_sound() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->result_flags = (u8) (this->result_flags | 1);
}


void TWindowSoundBalance::handle_gain_input() {
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
    if ((test_buttons_press_or_repeat_color(input, 0x30, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x30, 6, 1) != 0)) {
        play_sound_effect(0x54100, NULL, 0, 0);
        if ((test_buttons_press_or_repeat_color(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->selection = (this->selection - 1);
        }
        if ((test_buttons_press_or_repeat_color(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
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
    WindowDrawContext *entry = draw_default_entry();
    draw_window_frame(entry);
    draw_visible_window_entries(
        this,
        &entry_list,
        entry);
    entry->inner_x += 174.0f;
    entry->inner_w -= 348.0f;
    apply_balance(entry);
}
#pragma pop

void TWindowSoundBalance::run_task() {
    ControllerInputContext *input;
    if (is_active() == 0) {
        handle_lr_input();
        handle_gain_input();
        input = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(input, 4) != 0) || ((s32)test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            play_open_sound();
        }
        if ((test_pressed_buttons_packed(input, 2) != 0) || ((s32)test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    update_window();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(&entry_list));
}

TWindowSoundBalance::~TWindowSoundBalance() {}
#pragma push
#pragma fp_contract on
TWindowSoundBalance::TWindowSoundBalance(const NJS_POINT2 *position)
    : TWindowBase((u8 *)&window_sound_balance_settings, 4, (u8 *)position) {
    WindowTextEntry *e;
    SoundBalanceSettings *st;

    this->m_name = TWindowSoundBalance::class_name;
    this->result_flags = 0;
    this->selection = 0;
    this->music_gain = 1;
    this->sound_effect_gain = 1;
    e = (WindowTextEntry *)get_array_entry(0);
    char *label = e->get_text();
    e->x = 231.0f - 0.5f * calc_text_width(label);
    measure_message_text_width_default(e);
    e = (WindowTextEntry *)get_array_entry(1);
    label = e->get_text();
    e->x = 231.0f - 0.5f * calc_text_width(label);
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

