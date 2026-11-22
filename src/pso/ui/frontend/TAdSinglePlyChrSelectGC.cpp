#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdFadeGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_802D3AB8.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

struct RecoveredGlobal_802D4730_lbl_804C89BC { s32 value; u8 remaining[0x74]; };
LAYOUT_ASSERT(RecoveredGlobal_802D4730_lbl_804C89BC_size, sizeof(RecoveredGlobal_802D4730_lbl_804C89BC) == 0x78);

const vec2f single_chr_select_item_rect_table[4] = {
    { 131.0f, 182.0f }, { 131.0f, 225.0f }, { 131.0f, 268.0f }, { 131.0f, 311.0f },
};
const vec2f single_chr_select_cursor_size = { 180.0f, 38.0f };
const vec2f single_chr_select_message_pos = { 432.0f, 172.0f };
const vec2f single_chr_select_yes_no_pos = { 91.0f, 160.0f };
const vec2f single_chr_select_menu_pos = { 428.0f, 132.0f };
const vec2f single_chr_select_slot_message_pos = { 428.0f, 132.0f };

struct T_802D4F2C { NJS_POINT2 p[3]; };

const char *TAdSinglePlyChrSelectGC__class_name = "TAdSinglePlyChrSelectGC";
const T_802D4F2C single_chr_select_position_table = { { { 156.0f, 421.0f }, { 299.0f, 421.0f }, { 432.0f, 421.0f } } };

extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
s32 poll_memcard_result(saddr chan);
s32 load_guild_card_save();
extern RecoveredGlobal_802D4730_lbl_804C89BC pso_guildcard_card_filename;
void set_queued_main_phase(s32 arg0);
void request_main_phase(s32 arg0);
s32 load_tables();
u32 TAdSinglePlyChrSelectGC__sub_801FE4BC();
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi();
s32 clear_entry__23TAdSinglePlyChrSelectGCFi();
s32 TAdSinglePlyChrSelectGC__sub_802D4D9C();
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);

void TAdSinglePlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

s32 TAdSinglePlyChrSelectGC::create_chr_warp(s32 arg0, s32 arg1) {
    saddr window_menu_default = arg1;

    if (TAdSinglePlyChrSelectGC__sub_802D4D9C() != 0) {
        window_menu_default = create_window_menu_default(arg1, 4);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 1)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 2)), 6, 1);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 3)), 6, 2);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 4)), 6, 3);
    } else {
        window_menu_default = create_window_menu_default(arg1, 3);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 1)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 3)), 6, 2);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)(get_localized_text_entry(0x1E, 4)), 6, 3);
    }
    ((TWindowMenu *)window_menu_default)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(window_menu_default));
    return window_menu_default;
}
}

void TAdSinglePlyChrSelectGC::finish_character_selection_transition() {
    void *arg0 = this;
    s32 temp_r4;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
        *(u32 *)((s8 *)arg0 + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x44) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x44)))->close();
        *(u32 *)((s8 *)arg0 + 0x44) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x4C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
        *(u32 *)((s8 *)arg0 + 0x4C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x50) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x50)))->close();
        *(u32 *)((s8 *)arg0 + 0x50) = 0U;
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
    *(s32 *)((s8 *)arg0 + 0x1C) = temp_r4;
    if ((f32) temp_r4 > 4.5f) {
        switch (*(s32 *)((s8 *)arg0 + 0x5C)) {
        case 0:
            if (((s32)TAdSinglePlyChrSelectGC::get_data()) == 0) {
                TAdMultiChgGameModeGC::request_transition();
                return;
            }
            set_queued_main_phase(0xE);
            TAdMultiChgGameModeGC::set_game_mode_changed();
            return;
        case 1:
            request_main_phase(5);
            return;
        case 2: break;
        case 3:
            set_opening_movie_purpose(1);
            request_main_phase(3);
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::close_and_change_scene() {
    s32 temp_r4;
    u8 *window_base;
    u8 *window_sub_com_card;
    window_base = (u8 *)(*(u8 * *)&this->unk_38);
    if (window_base != NULL) {
        ((TWindowBase *)window_base)->close();
        *(u8 * *)&this->unk_38 = NULL;
    }
    window_sub_com_card = (u8 *)(*(u8 * *)&this->m_44);
    if (window_sub_com_card != NULL) {
        ((TWindowSubComCard *)window_sub_com_card)->close();
        *(u8 * *)&this->m_44 = NULL;
    }
    temp_r4 = *(s32 *)&this->m_1c + 1;
    *(s32 *)&this->m_1c = temp_r4;
    if ((f32) temp_r4 > 4.5f) {
        switch (TAdSinglePlyChrSelectGC::get_data()) {
        case 0:
            TAdMultiChgGameModeGC::request_scene_change();
            return;
        case 1:
            TAdMultiChgGameModeGC::set_game_mode_state();
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::handle_card_select() {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)&this->unk_50))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(saddr *)&this->unk_50))->get_slot_or_neg1()) {
        case 0:
            this->m_5c = 3;
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 1:
            ((TWindowMenu *)(*(saddr *)&this->unk_38))->clear_transition_flag();
            ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(*(saddr *)&this->unk_50))->get_card_data() != 0) {
        ((TWindowMenu *)(*(saddr *)&this->unk_38))->clear_transition_flag();
        ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}

void TAdSinglePlyChrSelectGC::handle_card_select2() {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_4c))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_4c))->get_slot_or_neg1()) {
        case 0:
            this->m_5c = 1;
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 1:
            ((TWindowMenu *)(*(saddr *)&this->unk_38))->clear_transition_flag();
            ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(this->m_4c))->get_card_data() != 0) {
        ((TWindowMenu *)(*(saddr *)&this->unk_38))->clear_transition_flag();
        ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}

void TAdSinglePlyChrSelectGC::update_card_input() {

    if (((TAdMultiPlyChrSelectGC *)(this->m_28))->get_player_index() == 1) {
        this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_44))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_44))->get_slot_or_neg1()) {
        case 0:
            this->m_5c = 3;
            this->m_20 = 0xC;
            return;
        case 1:
            ((TAdSelectCurGC *)(this->m_2c))->set_selection_state(1);
            this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(this->m_44))->get_card_data() != 0) {
        ((TAdSelectCurGC *)(this->m_2c))->set_selection_state(1);
        this->m_20 = 5;
    }
}

void TAdSinglePlyChrSelectGC::update() {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)&this->unk_48))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(saddr *)&this->unk_48))->get_slot_or_neg1()) {
        case 0:
            reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
            clear_entry__23TAdSinglePlyChrSelectGCFi();
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index();
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->set_cursor_index(0xF);
            ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 0;
            return;
        case 1:
            ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(*(saddr *)&this->unk_48))->get_card_data() != 0) {
        ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}


void TAdSinglePlyChrSelectGC::handle_menu_selection() {
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMenu *)(*(saddr *)&this->unk_38))->is_decided() != 0) {
        this->m_5c = ((TWindowMenu *)(*(saddr *)&this->unk_38))->get_selected_value();
        switch (this->m_5c) {
        case 0:
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 1:
            ((TWindowOptionCtrl *)(*(saddr *)&this->unk_38))->open();
            this->m_4c = TAdChrSelASlotGC::create_format_message_window((s32)((int) (*(s32 *)&this->m_28)), (saddr)&single_chr_select_message_pos, 0);
            *(s32 *)&this->m_20 = 9;
            return;
        case 2:
            ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        case 3:
            ((TWindowOptionCtrl *)(*(saddr *)&this->unk_38))->open();
            *(TWindowMessageYesNo **)&this->unk_50 = ((TAdChrSelASlotGC *)this->m_28)->sub_8030C978((saddr)&single_chr_select_message_pos, 0);
            *(s32 *)&this->m_20 = 0xA;
            return;
        }
    } else if (((TWindowMenu *)(*(saddr *)&this->unk_38))->is_cancelled() != 0) {
        ((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}

// pool_data off: each window position is reached with its own lis/addi.
#pragma pool_data off
void TAdSinglePlyChrSelectGC::handle_slot_selection() {
    s32 var_r30;
    if (*(u32 *)&this->unk_38 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_38))->close();
        *(u32 *)&this->unk_38 = 0U;
    }
    if (*(u32 *)&this->m_44 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_44))->close();
        *(u32 *)&this->m_44 = 0U;
    }
    if (*(u32 *)&this->unk_48 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_48))->close();
        *(u32 *)&this->unk_48 = 0U;
    }
    if (*(u32 *)&this->unk_50 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_50))->close();
        *(u32 *)&this->unk_50 = 0U;
    }
    if (*(u32 *)&this->m_4c != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_4c))->close();
        *(u32 *)&this->m_4c = 0U;
    }
    if (this->m_54 != 0U) {
        ((TObject *)this->m_54)->queue_destruction();
        this->m_54 = 0U;
    }
    if ((TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    var_r30 = 0;
    if (*(s32 *)&this->unk_58 != reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index()) {
        ((TAdMultiPlyChrSelectGC *)this->m_30)->set_field_100(1);
        reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
        if (TAdSinglePlyChrSelectGC__sub_801FE4BC() != 0U) {
            reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
            load_tables();
            ((TAdMultiPlyChrSelectGC *)this->m_30)->set_field_100(2);
            if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
                var_r30 = 1;
                this->m_34->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 5)));
                this->m_34->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 6)));
            }
        }
        if (var_r30 == 0) {
            this->m_34->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 0)));
            this->m_34->set_line(1, "");
        }
        *(s32 *)&this->unk_58 = reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
    }
    if (((TAdSelectCurGC *)(*(saddr *)&this->m_2c))->confirmation_result() == 1) {
        reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
        load_tables();
        reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index();
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi() != 0) {
            if (((TAdChrSelASlotGC *)this->m_28)->sub_8030C3C0((u32)(reinterpret_cast<TAdSelectCurGC *>((*(saddr *)&this->m_2c))->selection_index())) != 0) {
                this->m_54 = (uaddr)new TAdFadeGC(tl_fade, NULL);
                *(u32 *)&this->unk_48 = TAdChrSelASlotGC::open_yes_no_window((s32)(*(s32 *)&this->m_28), (saddr)&single_chr_select_yes_no_pos, 0);
                *(s32 *)&this->m_20 = 7;
                return;
            }
            *(u32 *)&this->unk_38 = TAdSinglePlyChrSelectGC::create_chr_warp((saddr)this, (saddr)&single_chr_select_menu_pos);
            *(s32 *)&this->m_20 = 6;
            return;
        }
        this->m_44 = (saddr)((TAdChrSelASlotGC *)this->m_28)->sub_8030CA84((saddr)&single_chr_select_slot_message_pos);
        *(s32 *)&this->m_20 = 8;
    }
}

#pragma pool_data reset

void TAdSinglePlyChrSelectGC::sub_802D4570() {
    u8 *arg0 = (u8 *)this;
    if ((TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    ((TAdSelectCurGC *)(*(saddr *)((s8 *)arg0 + 0x2C)))->append_entry((void *)&single_chr_select_item_rect_table[0]);
    ((TAdSelectCurGC *)(*(saddr *)((s8 *)arg0 + 0x2C)))->append_entry((void *)&single_chr_select_item_rect_table[1]);
    ((TAdSelectCurGC *)(*(saddr *)((s8 *)arg0 + 0x2C)))->append_entry((void *)&single_chr_select_item_rect_table[2]);
    ((TAdSelectCurGC *)(*(saddr *)((s8 *)arg0 + 0x2C)))->append_entry((void *)&single_chr_select_item_rect_table[3]);
    *(s32 *)((s8 *)arg0 + 0x20) = 5;
}

void TAdSinglePlyChrSelectGC::sub_802D4664() {
    u8 *arg0 = (u8 *)this;
    if ((TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            *(u32 *)((s8 *)arg0 + 0x40) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (TAdPlayerLoadGC::get_instance() == 0) {
        *(s32 *)((s8 *)arg0 + 0x20) = 4;
    }
}

void TAdSinglePlyChrSelectGC::sub_802D4730() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    if ((TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            *(u32 *)((s8 *)arg0 + 0x40) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (poll_memcard_result(0) == 0) {
        if (TAdPlayerLoadGC::find_card_file(0, (const char *)(&pso_guildcard_card_filename.value)) == 0) {
            if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
                *(u32 *)((s8 *)arg0 + 0x40) = 0U;
            }
            load_guild_card_save();
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
            return;
        }
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
        *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
        if ((temp_r0 > 0xA) && ((u32) *(u32 *)((s8 *)arg0 + 0x40) == 0U)) {
            *(TWindowBase **)((s8 *)arg0 + 0x40) = ((TAdChrSelASlotGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->sub_8030CB08(0, 0x18);
        }
    }
}
void TAdSinglePlyChrSelectGC::sub_802D486C() {
    void *arg0 = this;
    s32 temp_r0;
    if ((TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        if (*(u32 *)((s8 *)arg0 + 0x3C) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (poll_memcard_result(0) == 0) {
        if ((u32)TAdPlayerLoadGC::find_card_file(0, (const char *)&pso_guildcard_card_filename.value) != 0xFFFFFF41U) {
            if (*(u32 *)((s8 *)arg0 + 0x3C) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 2;
            return;
        }
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
        *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
        if ((temp_r0 > 0xA) && (*(u32 *)((s8 *)arg0 + 0x3C) == 0U)) {
            *(TWindowBase **)((s8 *)arg0 + 0x3C) = ((TAdChrSelASlotGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->sub_8030CB08(0, 0x16);
        }
    }
}


typedef void (TAdSinglePlyChrSelectGC::*Act_802D4B6C)();

extern "C" {
s32 set_default_camera__21TAdMultiChgGameModeGCFv(void *);

TPlyCharData *get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);


void TAdSinglePlyChrSelectGC::cleanup() {
    ((TAdSelectCurGC *)(*(saddr *)((s8 *)this + 0x2C)))->reset_entries();
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x30)))->set_field_100(1);
    ((TAdGuideTxtGC *)(*(saddr *)((s8 *)this + 0x34)))->set_line(0, "");
    ((TAdGuideTxtGC *)(*(saddr *)((s8 *)this + 0x34)))->set_line(1, "");
    *(s32 *)((s8 *)this + 0x58) = -1;
    if ((u32) *(u32 *)((s8 *)this + 0x38) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close();
        *(u32 *)((s8 *)this + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x44) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x44)))->close();
        *(u32 *)((s8 *)this + 0x44) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x48) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x48)))->close();
        *(u32 *)((s8 *)this + 0x48) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x4C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x4C)))->close();
        *(u32 *)((s8 *)this + 0x4C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x50) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x50)))->close();
        *(u32 *)((s8 *)this + 0x50) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x3C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close();
        *(u32 *)((s8 *)this + 0x3C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x40) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x40)))->close();
        *(u32 *)((s8 *)this + 0x40) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x54) != 0U) {
        ((TObject *)((void *)(*(void **)((s8 *)this + 0x54))))->queue_destruction();
        *(u32 *)((s8 *)this + 0x54) = 0U;
    }
    if ((TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)this + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x28)))->get_player_index() == 0xE) {
        ((TAdGuideTxtGC *)(*(saddr *)((s8 *)this + 0x34)))->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 0)));
        ((TAdGuideTxtGC *)(*(saddr *)((s8 *)this + 0x34)))->set_line(1, "");
        *(s32 *)((s8 *)this + 0x20) = 1;
    }
}

void TAdSinglePlyChrSelectGC::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    static Act_802D4B6C tbl[13] = {
        &TAdSinglePlyChrSelectGC::cleanup,
        &TAdSinglePlyChrSelectGC::sub_802D486C,
        &TAdSinglePlyChrSelectGC::sub_802D4730,
        &TAdSinglePlyChrSelectGC::sub_802D4664,
        &TAdSinglePlyChrSelectGC::sub_802D4570,
        &TAdSinglePlyChrSelectGC::handle_slot_selection,
        &TAdSinglePlyChrSelectGC::handle_menu_selection,
        &TAdSinglePlyChrSelectGC::update,
        &TAdSinglePlyChrSelectGC::update_card_input,
        &TAdSinglePlyChrSelectGC::handle_card_select2,
        &TAdSinglePlyChrSelectGC::handle_card_select,
        &TAdSinglePlyChrSelectGC::close_and_change_scene,
        &TAdSinglePlyChrSelectGC::finish_character_selection_transition,
    };
    (this->*tbl[m_20])();
    if (static_cast<s32>(m_20) != static_cast<s32>(m_24)) {
        m_1c = 0;
    }
    m_24 = m_20;
}

s32 TAdSinglePlyChrSelectGC__sub_802D4D9C() {
    player_stats stats = get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_stats;
    if (stats.meseta >= 10000) {
        return 1;
    }
    return 0;
}

void TAdSinglePlyChrSelectGC::sub_802D4E08() {
    *(s32 *)((s8 *)this + 0x20) = 0;
    *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)this + 0x20);
    *(s32 *)((s8 *)this + 0x2C) = 0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x54) = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x44) = 0;
    *(s32 *)((s8 *)this + 0x48) = 0;
    *(s32 *)((s8 *)this + 0x4C) = 0;
    *(s32 *)((s8 *)this + 0x50) = 0;
    *(s32 *)((s8 *)this + 0x3C) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0;
    *(s32 *)((s8 *)this + 0x1C) = -1;
    *(s32 *)((s8 *)this + 0x58) = -1;
    *(s32 *)((s8 *)this + 0x5C) = -1;
}

}
TAdSinglePlyChrSelectGC::~TAdSinglePlyChrSelectGC() {
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)this + 0x38))))->queue_destruction(); *(s32 *)((s8 *)this + 0x38) = 0; }
    if (*(void **)((s8 *)this + 0x3C) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)this + 0x3C))))->queue_destruction(); *(s32 *)((s8 *)this + 0x3C) = 0; }
    if (*(void **)((s8 *)this + 0x40) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)this + 0x40))))->queue_destruction(); *(s32 *)((s8 *)this + 0x40) = 0; }
    if (*(void **)((s8 *)this + 0x44) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)this + 0x44))))->queue_destruction(); *(s32 *)((s8 *)this + 0x44) = 0; }
    if (*(void **)((s8 *)this + 0x48) != NULL) { ((TObject *)((void *)(*(void **)((s8 *)this + 0x48))))->queue_destruction(); *(s32 *)((s8 *)this + 0x48) = 0; }
}

// pool_data off: the cursor rects and the title positions are each reached with their own lis/addi.
#pragma pool_data off
TAdSinglePlyChrSelectGC::TAdSinglePlyChrSelectGC(TObject *parent) : TObject(parent) {
    m_name = TAdSinglePlyChrSelectGC__class_name;
    sub_802D4E08();
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdTitleGC(this, 0);
    m_28 = reinterpret_cast<uaddr>(TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 0));
    m_30 = TAdMultiPlyChrSelectGC::get_or_create_player(this, 0, -1, 0);
    m_34 = new TAdGuideTxtGC(this);
    m_2c = reinterpret_cast<uaddr>(new TAdSelectCurGC(this,
        reinterpret_cast<const NJS_POINT2 *>(single_chr_select_item_rect_table),
        reinterpret_cast<const NJS_POINT2 *>(&single_chr_select_cursor_size)));
    TAdTitleTexGC *title_tex = new TAdTitleTexGC(this);
    T_802D4F2C t = single_chr_select_position_table;
    fn_802D50B8(title_tex, &t.p[0], &t.p[1], &t.p[2]);
}
#pragma pool_data reset
