#include "types.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubStatusDisp_80248BE8.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TUnk_804D1818.h"
#include "pso/misc/TWindowSubMagPhoton.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubQuestBoard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8027C56C_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8027C6B4_lbl_804D17E8 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8027C6B4___vt__19TWindowSubMagPhoton {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_8027C2D0_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Win_8027C4C8 { u8 pad[0x62]; s16 f62; };

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
void render__19TWindowSubMagPhotonFv(s32 arg0);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_8027C56C_lbl_8050E208 controller_input_state;
s32 init_photon_blast_entries__19TWindowSubMagPhotonFv(void *, int);
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, void *);
extern RecoveredGlobal_8027C6B4_lbl_804D17E8 TWindowSubMagPhoton__layout_descriptor;
extern s32 __vt__19TWindowSubMagPhoton[];
extern s32 TWindowSubMagPhoton__class_name;
u8 *TWindowSubMagPhoton__ct(TWindowSubMagPhoton *arg0, s32 arg1, s32 arg2, s16 arg3);
s32 play_sound_effect(s32, s32, s32, s32);
s32 apply_choice__20TWindowChoiceSettingFllll(void *, int, int, int);
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(void *, void *, int, f32);
extern const f32 lbl_805DD680;
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 fn_801A51F0(int);
s32 set_depth__11TWindowBaseFf(s32);
s32 TWindowSubEquip__sub_80263AF8(s32, s32);
s32 get_window_layout_position(s32);
extern u8 lbl_8044FA28[];
void *__dt__19TWindowSubMagPhotonFv(void *arg0, s16 arg1);
s32 align_menu_entry_positions(s32);
void __dl__7TObjectFPv(void *);
}
s32 create_titled_window_menu(s32, s32, s32, s32);
extern "C" {
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 is_split_screen();
s32 update_selected_item__17TWindowOptionCtrlFv(s32);

void TWindowSubMagPhoton::handle_cancel() {
    if (get_active_flag() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubMagPhoton::play_open_sound() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
}

typedef char RecoveredGlobal_8027C2D0_lbl_8050E208_size[sizeof(RecoveredGlobal_8027C2D0_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubMagPhoton::update_selection_input() {
    u8 temp_r3;
    u8 temp_r3_2;
    u8 *window_choice_setting;
    window_choice_setting = (u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + (is_player_input_active(((s32) this->m_20)) * 0x50) + 0x20;
    if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0xF0, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, (s32)(0U), 0, 0);
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x10, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x10, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x20, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x20, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x80, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x40, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_8027C2D0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x40, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        temp_r3 = this->m_61;
        if ((s8) temp_r3 < 0) {
            this->m_61 = (temp_r3 + 3);
        }
        temp_r3_2 = this->m_61;
        if ((s8) temp_r3_2 >= 3) {
            this->m_61 = (temp_r3_2 - 3);
        }
    }
}

s32 TWindowSubMagPhoton::draw_cursor(int arg1) {
    u8 sp8[16];
    get_cursor_origin(sp8);
    ((void (*)(f32, void *, void *, int))draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif)(lbl_805DD680, (void *)arg1, sp8, ((Win_8027C4C8 *)this)->f62);
}

void render__19TWindowSubMagPhotonFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
    ((TWindowSubMagPhoton *)arg0)->draw_cursor(temp_r3);
}

typedef char RecoveredGlobal_8027C56C_lbl_8050E208_size[sizeof(RecoveredGlobal_8027C56C_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubMagPhoton::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    u8 *temp_r31_2;
    temp_r31 = is_player_input_active(((s32) this->m_20));
    if (((TWindowSubMagPhoton *)arg0)->get_active_flag() == 0) {
        update_selection_input();
        temp_r31_2 = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r31_2, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            play_open_sound();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r31_2, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            handle_cancel();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
    this->m_62 = (this->m_62 + 1);
}

void *__dt__19TWindowSubMagPhotonFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSubMagPhoton;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8027C6B4_lbl_804D17E8_size[sizeof(RecoveredGlobal_8027C6B4_lbl_804D17E8) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8027C6B4___vt__19TWindowSubMagPhoton_size[sizeof(RecoveredGlobal_8027C6B4___vt__19TWindowSubMagPhoton) == 0x1C ? 1 : -1];
u8 *TWindowSubMagPhoton__ct(TWindowSubMagPhoton *window_sub_mag_photon, s32 arg1, s32 arg2, s16 arg3) {
    s16 temp_r4;
    construct_base__9TWindowDDFPUcsPUc((void *)window_sub_mag_photon, &TWindowSubMagPhoton__layout_descriptor.value, (void *)arg3, (void *)arg1);
    *(s32 **)((s8 *)window_sub_mag_photon + 0x18) = &(*(RecoveredGlobal_8027C6B4___vt__19TWindowSubMagPhoton *)&__vt__19TWindowSubMagPhoton).value;
    *(s32 *)((s8 *)window_sub_mag_photon + 0) = (s32) TWindowSubMagPhoton__class_name;
    ((TWindowSubSymbolChatPartsSet *)((u8 *)window_sub_mag_photon + 0x30))->copy_vec2((void *)arg1);
    ((TWindowBase *)window_sub_mag_photon)->save_position();
    window_sub_mag_photon->m_20 = arg3;
    window_sub_mag_photon->m_70 = arg2;
    window_sub_mag_photon->m_60 = 0;
    window_sub_mag_photon->m_61 = 1;
    temp_r4 = window_sub_mag_photon->m_62;
    window_sub_mag_photon->m_62 = (temp_r4 + 1);
    init_photon_blast_entries__19TWindowSubMagPhotonFv(window_sub_mag_photon, temp_r4);
    return (u8 *)window_sub_mag_photon;
}

void TUnk_804D1818::update_photon_selection() {
    s32 selected_menu_value;
    s32 temp_r3;

    selected_menu_value = ((TWindowMenu *)(*(s32 *)&this->unk_28))->get_selected_value();
    temp_r3 = update_selected_item__17TWindowOptionCtrlFv(this->m_2c);
    if ((selected_menu_value == 4) && ((s8)this->m_1d != temp_r3)) {
        (this->m_1d) = (u8) temp_r3;
        if ((s8)this->m_1d == 0) {
            start_pad_rumble_client(0xC0, 0xF, (s16) *(s32 *)&(this->m_20));
        }
    }
}

void TUnk_804D1818::update_quest_board_card_flags() {
    s32 selected_menu_value;
    s32 temp_r4;

    selected_menu_value = ((TWindowMenu *)(*(s32 *)&this->unk_28))->get_selected_value();
    temp_r4 = update_selected_item__17TWindowOptionCtrlFv(this->m_2c);
    switch (selected_menu_value) {
    case 0:
        ((TWindowSubQuestBoard *)(this->m_20))->set_card_flags_direct(temp_r4);
        return;
    case 1:
        ((TWindowSubQuestBoard *)(this->m_20))->set_card_flags_scaled(temp_r4);
        return;
    case 2:
        TWindowSubQuestBoard__sub_8027CF50(this->m_20, temp_r4);
        return;
    case 4:
        ((TWindowSubQuestBoard *)(this->m_20))->clear_card_window_flags(temp_r4);
        return;
    case 3:
        ((TWindowSubQuestBoard *)(this->m_20))->set_card_window_flags(temp_r4);
        return;
    case 5:
        ((TWindowSubQuestBoard *)(this->m_20))->set_board_flags(temp_r4);
        return;
    }
}

extern const f32 lbl_805DD688;

s32 TUnk_804D1818::sub_8027C884(s32 arg1) {
    s16 var_r29;
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = (s32)TWindowSubStatusDisp__sub_80248BE8((s32)(get_window_layout_position(0x16)), (s32)lbl_8044FA28, (s32)this->m_20);
    switch (arg1) {
    case 0:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x66)));
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x6F)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x70)), 1);
        var_r29 = ((TWindowKeyBoardHard *)(this->m_20))->is_card_flag_set();
        break;
    case 1:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x67)));
        TWindowSubStatusDisp::draw_status(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x71)), 0);
        TWindowSubStatusDisp::draw_status(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x72)), 1);
        var_r29 = ((TBoss8Dragon *)(this->m_20))->test_card_flag_2();
        break;
    case 2:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x68)));
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x73)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x74)), 1);
        var_r29 = test_keyboard_card_flag4((void *)this->m_20);
        break;
    case 4:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x6A)));
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0xA6)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0xA7)), 1);
        temp_r3 = TWindowKeyBoardHard::test_card_flag_8(this->m_20);
        this->m_1d = temp_r3;
        var_r29 = (s16) temp_r3;
        break;
    case 3:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x69)));
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x75)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x76)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x77)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x78)), 3);
        var_r29 = TWindowSubStatusDisp::get_card_window_flags(this->m_20);
        break;
    case 5:
        ((TWindowMenuIconLine *)temp_r31)->ensure_status_display((int) (get_message_10__20TWindowSubStatusDispFl(0x6E)));
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x79)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x7A)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x7B)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x7C)), 3);
        var_r29 = fn_801A51F0(this->m_20);
        break;
    }
    ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(var_r29);
    ((TWindowSubShortCutList *)temp_r31)->set_flag70_bit10();
    TWindowSubEquip__sub_80263AF8((int)this->m_24, 1);
    set_depth__11TWindowBaseFf(temp_r31);
    return temp_r31;
}

s32 TUnk_804D1818::create_option_menu_window() {
    s32 titled_window_menu;

    titled_window_menu = create_titled_window_menu(get_window_layout_position(0x15), 6, get_message_10__20TWindowSubStatusDispFl(0x2A), this->m_20);
    if (is_split_screen() == 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x66), 6, 0);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x67), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x68), 6, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x69), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x6A), 6, 4);
    if (is_split_screen() == 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, get_message_10__20TWindowSubStatusDispFl(0x6E), 6, 5);
    }
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)titled_window_menu)->update_layout_height(lbl_805DD688);
    align_menu_entry_positions(titled_window_menu);
    TWindowSubEquip__sub_80263AF8(*(s32 *)&this->m_24, 0);
    set_depth__11TWindowBaseFf(titled_window_menu);
    return titled_window_menu;
}
}
