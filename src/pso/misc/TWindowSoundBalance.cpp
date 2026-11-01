#include "pso/system/ControllerInputState.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TLobby_80226070.h"
#include "pso/misc/TUnk_804CF930.h"
#include "types.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSoundBalance.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 play_sound_effect(s32, s32, s32, s32);
SoundBalanceSettings *get_global_state__23TAdSinglePlyChrSelectGCFv();
u32 calc_text_width();
u8 *get_array_entry__11TWindowBaseFi(void *, s32);
s32 get_field_20__17TWindowSubComCardFv();
s32 refresh_status_display__9TWindowDDFv(u8 *);
extern s32 window_sound_balance_settings[];
extern s32 __vt__19TWindowSoundBalance[];
extern s32 TWindowSoundBalance__name;
extern const f32 lbl_805DD414;
extern const f32 lbl_805DD418;
s32 draw_visible_window_entries(s32, s32, void *);
void __dl__7TObjectFPv(void *);

void TWindowSoundBalance::set_sound_effect_gain(s16 gain) {
    if (sound_effect_gain != gain) {
        sound_effect_gain = gain;
        TLobby__sub_8022614C(gain);
        TUnk_804CF930 *gauge = (TUnk_804CF930 *)get_array_entry(3);
        gauge->target = gain + 100;
        gauge->calc_bar_width();
    }
}

void TWindowSoundBalance::set_music_gain(s16 gain) {
    if (music_gain != gain) {
        music_gain = gain;
        update_music_stream_gain(gain);
        TUnk_804CF930 *gauge = (TUnk_804CF930 *)get_array_entry(2);
        gauge->target = gain + 250;
        gauge->calc_bar_width();
    }
}

void TWindowSoundBalance::apply_balance(void *window_key_board_soft) {
    s32 temp;

    temp = get_array_entry((s32)selection);
    draw_selection_bar((u8 *)window_key_board_soft, (u8 *)temp, is_active());
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

extern const f32 lbl_805DD408;

void TWindowSoundBalance::sub_8027095C() {
    ControllerInputContext *input = &controller_input_state.controllers[0];
    s16 gain;
    s16 range;
    s16 step;
    if (is_flag_set__11TLoadingCurFv(input, 0xC0) != 0 ||
        is_flag_set__11TLoadingCurFv(&controller_input_state.keyboard, 0xC0) != 0) {
        if (selection != 0) {
            gain = sound_effect_gain;
            range = 100;
        } else {
            gain = music_gain;
            range = 250;
        }
        step = lbl_805DD408 * range;
        if (is_flag_set__11TLoadingCurFv(input, 0x80) != 0 ||
            is_flag_set__11TLoadingCurFv(&controller_input_state.keyboard, 0x80) != 0) {
            gain += step;
        }
        if (is_flag_set__11TLoadingCurFv(input, 0x40) != 0 ||
            is_flag_set__11TLoadingCurFv(&controller_input_state.keyboard, 0x40) != 0) {
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

extern const f32 lbl_805DD40C;
extern const f32 lbl_805DD410;

void TWindowSoundBalance::handle_lr_input() {
    u8 *input;
    input = (u8 *)&controller_input_state.controllers[0];
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)input, 0x30, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.keyboard)), 0x30, 6, 1) != 0)) {
        play_sound_effect(0x54100, (s32)(0U), 0, 0);
        if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.keyboard)), 0x10, 6, 1) != 0)) {
            this->selection = (this->selection - 1);
        }
        if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.keyboard)), 0x20, 6, 1) != 0)) {
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
    TWindowKeyBoardSoft *entry = (TWindowKeyBoardSoft *)TWindowDD::draw_default_entry((s32)self);
    self->draw_window_frame(entry);
    draw_visible_window_entries((s32)self, (s32)&self->m_24, entry);
    entry->inner_x += lbl_805DD40C;
    entry->inner_w -= lbl_805DD410;
    self->apply_balance(entry);
}
#pragma pop

void TWindowSoundBalance::run_task() {
    u8 *input;
    if (is_active() == 0) {
        handle_lr_input();
        sub_8027095C();
        input = (u8 *)&controller_input_state.controllers[0];
        if ((TWindowShortListCtrl__check_controller_button((int)input, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.keyboard), 4) != 0)) {
            play_open_sound();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)input, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.keyboard), 2) != 0)) {
            handle_cancel();
        }
    }
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&m_24);
}

void *__dt__19TWindowSoundBalanceFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSoundBalance;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
u8 *TWindowSoundBalance__ct(u8 *arg0, s32 arg1) {
    u8 *e;
    SoundBalanceSettings *st;
    ((TWindowDD *)arg0)->construct_base((u8 *)window_sound_balance_settings, (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSoundBalance;
    *(s32 *)((s8 *)arg0 + 0) = TWindowSoundBalance__name;
    ((TWindowSoundBalance *)arg0)->m_60 = 0;
    ((TWindowSoundBalance *)arg0)->selection = 0;
    ((TWindowSoundBalance *)arg0)->music_gain = 1;
    ((TWindowSoundBalance *)arg0)->sound_effect_gain = 1;
    e = get_array_entry__11TWindowBaseFi(arg0, 0);
    get_field_20__17TWindowSubComCardFv();
    *(f32 *)((s8 *)e + 8) = lbl_805DD414 - lbl_805DD418 * calc_text_width();
    refresh_status_display__9TWindowDDFv(e);
    e = get_array_entry__11TWindowBaseFi(arg0, 1);
    get_field_20__17TWindowSubComCardFv();
    *(f32 *)((s8 *)e + 8) = lbl_805DD414 - lbl_805DD418 * calc_text_width();
    refresh_status_display__9TWindowDDFv(e);
    st = get_global_state__23TAdSinglePlyChrSelectGCFv();
    if (st == 0) {
        ((TWindowSoundBalance *)arg0)->set_music_gain(0);
        ((TWindowSoundBalance *)arg0)->set_sound_effect_gain(0);
    } else {
        ((TWindowSoundBalance *)arg0)->set_music_gain(st->music_gain);
        ((TWindowSoundBalance *)arg0)->set_sound_effect_gain(st->sound_effect_gain);
    }
    return arg0;
}
#pragma pop

}
