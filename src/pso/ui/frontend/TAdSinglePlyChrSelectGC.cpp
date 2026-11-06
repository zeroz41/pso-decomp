#include "types.h"
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

struct RecoveredGlobal_802D4730_lbl_804C89BC { s32 value; u8 remaining[0x74]; };
typedef char RecoveredGlobal_802D4730_lbl_804C89BC_size[sizeof(RecoveredGlobal_802D4730_lbl_804C89BC) == 0x78 ? 1 : -1];

extern "C" {
extern const f32 lbl_805DE780;
void *__nw__7TObjectFUl(u32);
extern u8 single_chr_select_item_rect_table[];
s32 play_sound_effect(s32, s32, s32, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
extern char controller_input_state[];
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 load_player__23TAdSinglePlyChrSelectGCFv();
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
extern RecoveredGlobal_802D4730_lbl_804C89BC lbl_804C89BC;
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 TAdChrSelASlotGC__sub_8030C978(void *arg0, s32 arg1, s32 arg2);
extern s32 lbl_80472538[];
s32 TAdSinglePlyChrSelectGC__sub_801334DC(s32);
s32 load_tables();
u32 TAdSinglePlyChrSelectGC__sub_801FE4BC();
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi();
u32 check_flag__23TAdSinglePlyChrSelectGCFl(s32);
s32 TAdChrSelASlotGC__sub_8030C3C0(s32, s32);
u32 TAdChrSelASlotGC__sub_8030CA84(s32, s32 *);
extern s32 lbl_80472540[];
extern s32 lbl_80472548[];
extern s32 lbl_80472550[];
extern s32 controller_physical_port_bank[];
extern s32 lbl_805DE784;
s32 clear_entry__23TAdSinglePlyChrSelectGCFi();
s32 TAdSinglePlyChrSelectGC__sub_802D4D9C();
s32 align_menu_entry_positions(s32);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);

void TAdSinglePlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

s32 TAdSinglePlyChrSelectGC::create_chr_warp(s32 arg0, s32 arg1) {
    s32 var_r31 = arg1;

    if (TAdSinglePlyChrSelectGC__sub_802D4D9C() != 0) {
        var_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(arg1, 4);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 1)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 2)), 6, 1);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 3)), 6, 2);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 4)), 6, 3);
    } else {
        var_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(arg1, 3);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 1)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 3)), 6, 2);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)var_r31, (int)(get_localized_text_entry(0x1E, 4)), 6, 3);
    }
    ((TWindowSubComCard *)var_r31)->calc_window_size();
    align_menu_entry_positions(var_r31);
    return var_r31;
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
    if ((f32) temp_r4 > lbl_805DE780) {
        switch (*(s32 *)((s8 *)arg0 + 0x5C)) {
        case 0:
            if (((s32)TAdSinglePlyChrSelectGC::get_data()) == 0) {
                TAdMultiChgGameModeGC::request_transition();
                return;
            }
            TKeyBoardControl__sub_8000F91C(0xE);
            TAdMultiChgGameModeGC::set_game_mode_changed();
            return;
        case 1:
            TKeyBoardControl__sub_8000F9CC(5);
            return;
        case 2: break;
        case 3:
            set_opening_movie_purpose(1);
            TKeyBoardControl__sub_8000F9CC(3);
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::close_and_change_scene() {
    s32 temp_r4;
    u8 *temp_r3;
    u8 *window_sub_com_card;
    temp_r3 = (u8 *)(*(u8 * *)&this->unk_38);
    if (temp_r3 != NULL) {
        ((TWindowBase *)temp_r3)->close();
        *(u8 * *)&this->unk_38 = NULL;
    }
    window_sub_com_card = (u8 *)(*(u8 * *)&this->m_44);
    if (window_sub_com_card != NULL) {
        ((TWindowSubComCard *)window_sub_com_card)->close();
        *(u8 * *)&this->m_44 = NULL;
    }
    temp_r4 = *(s32 *)&this->m_1c + 1;
    *(s32 *)&this->m_1c = temp_r4;
    if ((f32) temp_r4 > lbl_805DE780) {
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

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)&this->unk_50))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)&this->unk_50))->get_slot_or_neg1()) {
        case 0:
            this->m_5c = 3;
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 1:
            ((TWindowSubComCard *)(*(s32 *)&this->unk_38))->clear_transition_flag();
            ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(*(s32 *)&this->unk_50))->get_card_data() != 0) {
        ((TWindowSubComCard *)(*(s32 *)&this->unk_38))->clear_transition_flag();
        ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}

void TAdSinglePlyChrSelectGC::handle_card_select2() {

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index() == 1) {
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
            ((TWindowSubComCard *)(*(s32 *)&this->unk_38))->clear_transition_flag();
            ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(this->m_4c))->get_card_data() != 0) {
        ((TWindowSubComCard *)(*(s32 *)&this->unk_38))->clear_transition_flag();
        ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
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
            ((TAdMultiSelGameModeGC *)(this->m_2c))->set_selection_state(1);
            this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(this->m_44))->get_card_data() != 0) {
        ((TAdMultiSelGameModeGC *)(this->m_2c))->set_selection_state(1);
        this->m_20 = 5;
    }
}

void TAdSinglePlyChrSelectGC::update() {

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)&this->unk_48))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)&this->unk_48))->get_slot_or_neg1()) {
        case 0:
            TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
            clear_entry__23TAdSinglePlyChrSelectGCFi();
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index();
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->set_cursor_index(0xF);
            ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 0;
            return;
        case 1:
            ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        }
    } else if (((TWindowSubComCard *)(*(s32 *)&this->unk_48))->get_card_data() != 0) {
        ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}


void TAdSinglePlyChrSelectGC::handle_menu_selection() {
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    if (((TWindowMenu *)(*(s32 *)&this->unk_38))->is_decided() != 0) {
        this->m_5c = ((TWindowMenu *)(*(s32 *)&this->unk_38))->get_selected_value();
        switch (this->m_5c) {
        case 0:
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 1:
            ((TWindowOptionCtrl *)(*(s32 *)&this->unk_38))->open();
            this->m_4c = TAdChrSelASlotGC::create_format_message_window((s32)((int) (*(s32 *)&this->m_28)), (s32)lbl_80472538, 0);
            *(s32 *)&this->m_20 = 9;
            return;
        case 2:
            ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
            *(s32 *)&this->m_20 = 5;
            return;
        case 3:
            ((TWindowOptionCtrl *)(*(s32 *)&this->unk_38))->open();
            *(s32 *)&this->unk_50 = TAdChrSelASlotGC__sub_8030C978((void *)(*(s32 *)&this->m_28), (s32)lbl_80472538, 0);
            *(s32 *)&this->m_20 = 0xA;
            return;
        }
    } else if (((TWindowMenu *)(*(s32 *)&this->unk_38))->is_cancelled() != 0) {
        ((TAdMultiSelGameModeGC *)(*(s32 *)&this->m_2c))->set_selection_state(1);
        *(s32 *)&this->m_20 = 5;
    }
}

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
        queue_destruction__7TObjectFv((void *)this->m_54);
        this->m_54 = 0U;
    }
    if ((TWindowShortListCtrl__check_controller_button((void *)((u8 *)controller_physical_port_bank + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_28))->get_player_index() == 1) {
        *(s32 *)&this->m_20 = 0;
        return;
    }
    var_r30 = 0;
    if (*(s32 *)&this->unk_58 != TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c)) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_30))->set_field_100(1);
        TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
        if (TAdSinglePlyChrSelectGC__sub_801FE4BC() != 0U) {
            TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
            load_tables();
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_30))->set_field_100(2);
            if (check_flag__23TAdSinglePlyChrSelectGCFl(1) != 0U) {
                var_r30 = 1;
                ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_34))->set_entry_value(0, get_localized_text_entry(0x1E, 5));
                ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_34))->set_entry_value(1, get_localized_text_entry(0x1E, 6));
            }
        }
        if (var_r30 == 0) {
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_34))->set_entry_value(0, get_localized_text_entry(0x1E, 0));
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->m_34))->set_entry_value(1, (s32)&lbl_805DE784);
        }
        *(s32 *)&this->unk_58 = TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
    }
    if (((TAdSinglePlyChrSelectGC *)(*(s32 *)&this->m_2c))->get_selected_slot() == 1) {
        TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
        load_tables();
        TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c);
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi() != 0) {
            if (TAdChrSelASlotGC__sub_8030C3C0(*(s32 *)&this->m_28, TAdSinglePlyChrSelectGC__sub_801334DC(*(s32 *)&this->m_2c)) != 0) {
                this->m_54 = (u32)new TAdFadeGC(tl_fade, NULL);
                *(u32 *)&this->unk_48 = TAdChrSelASlotGC::open_yes_no_window((s32)(*(s32 *)&this->m_28), (s32)lbl_80472540, 0);
                *(s32 *)&this->m_20 = 7;
                return;
            }
            *(u32 *)&this->unk_38 = TAdSinglePlyChrSelectGC::create_chr_warp((s32)this, (s32)lbl_80472548);
            *(s32 *)&this->m_20 = 6;
            return;
        }
        *(u32 *)&this->m_44 = TAdChrSelASlotGC__sub_8030CA84(*(s32 *)&this->m_28, lbl_80472550);
        *(s32 *)&this->m_20 = 8;
    }
}

void TAdSinglePlyChrSelectGC::sub_802D4570() {
    u8 *arg0 = (u8 *)this;
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    ((TLevelSelect *)(*(s32 *)((s8 *)arg0 + 0x2C)))->add_item_rect(single_chr_select_item_rect_table);
    ((TLevelSelect *)(*(s32 *)((s8 *)arg0 + 0x2C)))->add_item_rect(single_chr_select_item_rect_table + 8);
    ((TLevelSelect *)(*(s32 *)((s8 *)arg0 + 0x2C)))->add_item_rect(single_chr_select_item_rect_table + 0x10);
    ((TLevelSelect *)(*(s32 *)((s8 *)arg0 + 0x2C)))->add_item_rect(single_chr_select_item_rect_table + 0x18);
    *(s32 *)((s8 *)arg0 + 0x20) = 5;
}

void TAdSinglePlyChrSelectGC::sub_802D4664() {
    u8 *arg0 = (u8 *)this;
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
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
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            *(u32 *)((s8 *)arg0 + 0x40) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) == 0) {
        if (TAdPlayerLoadGC::find_card_file(0, (const char *)(&lbl_804C89BC.value)) == 0) {
            if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
                *(u32 *)((s8 *)arg0 + 0x40) = 0U;
            }
            load_player__23TAdSinglePlyChrSelectGCFv();
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
            return;
        }
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
        *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
        if ((temp_r0 > 0xA) && ((u32) *(u32 *)((s8 *)arg0 + 0x40) == 0U)) {
            *(u32 *)((s8 *)arg0 + 0x40) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(*(s32 *)((s8 *)arg0 + 0x28)), 0, 0x18);
        }
    }
}
void TAdSinglePlyChrSelectGC::sub_802D486C() {
    void *arg0 = this;
    s32 temp_r0;
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x28)))->get_player_index() == 1) {
        if (*(u32 *)((s8 *)arg0 + 0x3C) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) == 0) {
        if ((u32)TAdPlayerLoadGC::find_card_file(0, (const char *)&lbl_804C89BC.value) != 0xFFFFFF41U) {
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
            *(u32 *)((s8 *)arg0 + 0x3C) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(*(s32 *)((s8 *)arg0 + 0x28)), 0, 0x16);
        }
    }
}

struct P_802D4F2C { f32 x, y; };

struct T_802D4F2C { P_802D4F2C p[3]; };

struct Self_802D4B6C {
    s32 pad[7];
    s32 flag1c;
    s32 state;
    s32 prev;
};
typedef void (TAdSinglePlyChrSelectGC::*Act_802D4B6C)();

extern "C" {
s32 set_default_camera__21TAdMultiChgGameModeGCFv(void *);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 __ct__9TAdBackGCFv(void *, void *);
s32 __ct__12TAdBackTxtGCFv(void *, void *);
s32 __ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void *__ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
extern u8 lbl_80472530[];
extern T_802D4F2C single_chr_select_position_table;
extern s32 __vt__23TAdSinglePlyChrSelectGC[];
extern s32 lbl_805D3F40;
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent);
void *__dt__23TAdSinglePlyChrSelectGCFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s32, s32, s32 *);
TPlyCharData *get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);

extern s32 lbl_805DE784;

void TAdSinglePlyChrSelectGC::cleanup() {
    ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)this + 0x2C)))->reset_input_state();
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x30)))->set_field_100(1);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 0, &lbl_805DE784);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 1, &lbl_805DE784);
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
        queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x54)));
        *(u32 *)((s8 *)this + 0x54) = 0U;
    }
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)this + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x28)))->get_player_index() == 0xE) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x34)))->set_entry_value(0, get_localized_text_entry(0x1E, 0));
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 1, &lbl_805DE784);
        *(s32 *)((s8 *)this + 0x20) = 1;
    }
}

void TAdSinglePlyChrSelectGC::run_task() {
    Self_802D4B6C *self = (Self_802D4B6C *)this;
    set_default_camera__21TAdMultiChgGameModeGCFv(self);
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
    (this->*tbl[self->state])();
    if (self->state != self->prev) {
        self->flag1c = 0;
    }
    self->prev = self->state;
}

s32 TAdSinglePlyChrSelectGC__sub_802D4D9C() {
    player_stats stats = get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_stats;
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
    if (*(void **)((s8 *)this + 0x38) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x38))); *(s32 *)((s8 *)this + 0x38) = 0; }
    if (*(void **)((s8 *)this + 0x3C) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x3C))); *(s32 *)((s8 *)this + 0x3C) = 0; }
    if (*(void **)((s8 *)this + 0x40) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x40))); *(s32 *)((s8 *)this + 0x40) = 0; }
    if (*(void **)((s8 *)this + 0x44) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x44))); *(s32 *)((s8 *)this + 0x44) = 0; }
    if (*(void **)((s8 *)this + 0x48) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x48))); *(s32 *)((s8 *)this + 0x48) = 0; }
}
extern "C" {
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent) {
    void *p;
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TAdSinglePlyChrSelectGC;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3F40;
    ((TAdSinglePlyChrSelectGC *)arg0)->sub_802D4E08();
    p = __nw__7TObjectFUl(0x24);
    if (p != NULL) {
        __ct__9TAdBackGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != NULL) {
        __ct__12TAdBackTxtGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x138);
    if (p != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, arg0, 0);
    }
    *(s32 *)((s8 *)arg0 + 0x28) = (s32)get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii((s32)arg0, 0);
    *(s32 *)((s8 *)arg0 + 0x30) = get_or_create_player__22TAdMultiPlyChrSelectGCFiiii((s32)arg0, 0, -1, 0);
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, arg0);
    }
    *(void **)((s8 *)arg0 + 0x34) = p;
    p = __nw__7TObjectFUl(0x708);
    if (p != NULL) {
        p = __ct__14TAdSelectCurGCFv(p, arg0, single_chr_select_item_rect_table, lbl_80472530);
    }
    *(void **)((s8 *)arg0 + 0x2C) = p;
    p = __nw__7TObjectFUl(0x9C);
    if (p != NULL) {
        p = __ct__13TAdTitleTexGCFv(p, arg0);
    }
    T_802D4F2C t = single_chr_select_position_table;
    fn_802D50B8(p, &t.p[0], &t.p[1], &t.p[2]);
    return arg0;
}

}
