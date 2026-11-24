#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TSnapshotFileSetup.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/TLanguage.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8023F160.h"
#include "pso/unk/text_8036A3CC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/text_8013ADE4.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/ui/window/TWindowSoundBalance.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C5D8.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/math/TMath.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/WindowLayout.h"

// The class name opens .rodata (0x8044F478), then the menu window positions
// (0x8044F48C..0x8044F4A4) in this order, ahead of the strings of the functions.
const char *TWindowOptionCtrl::class_name = "TWindowOptionCtrl";
const vec2f lbl_8044F48C = {470.0f, 124.0f};
const vec2f lbl_8044F494 = {470.0f, 80.0f};
const vec2f lbl_8044F49C = {470.0f, 80.0f};
const vec2f lbl_8044F4A4 = {470.0f, 80.0f};

extern "C" {
s32 create_window_menu_default(s32, s32);
}

extern "C" {
void play_sound_effect(int, int, int, int);
void set_field_value__17TWindowOptionCtrlFls(s32 arg0, s16 arg1);
}

int TWindowOptionCtrl__sub_8026C658(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }

s16 TWindowOptionCtrl::get_field_62() { return *(s16*)((char*)this + 0x62); }

s32 TWindowOptionCtrl::get_field_64() { return (s16)(*(s16*)((char*)this + 0x64)); }

int TWindowSoundBalance::is_active() { return this->m_60 & 0x1; }

int TWindowOptionCtrl__sub_8026C630(void* p) { return *(u8*)((char*)p + 0x60) & 0x1; }

void TWindowOptionCtrl::clear_flag70_bit4() { *(u16*)((char*)this + 0x70) &= 0xfffffffb; }

void TWindowSubComCardList::set_flag70_bit100() { this->m_70 |= 0x100; }

void TWindowOptionCtrl::set_flag70_bit400() { *(u16*)((char*)this + 0x70) |= 0x400; }

saddr TWindowOptionCtrl::get_chr_select_base_plus_1154c() {
    return TAdSinglePlyChrSelectGC::get_instance() + 0x1154C;
}

TWindowOptionCtrl::TWindowOptionCtrl(TObject *parent) : TObject(parent) {
    m_name = class_name;
    main_menu = NULL;
    sub_menu = NULL;
    m_30 = NULL;
    option_menu = NULL;
    sound_balance_window = NULL;
    snap_shot_window = NULL;
    yes_no_window = NULL;
    serial_info_window = NULL;
    card_format_dialog = NULL;
    player_load = new TAdPlayerLoadGC(this, 2);
    init_selection_indices();
    m_24 = 4;
    flags = 0;
    state = 0;
}

extern "C" {
TWindowOptionCtrl::~TWindowOptionCtrl() {
    apply_selection_change();
    if (serial_info_window != NULL) {
        ((TWindowBase *)serial_info_window)->close();
        serial_info_window = NULL;
    }
    if (yes_no_window != NULL) {
        ((TWindowMessageYesNo *)yes_no_window)->close();
        yes_no_window = NULL;
    }
    if (snap_shot_window != NULL) {
        ((TWindowBase *)snap_shot_window)->close();
        snap_shot_window = NULL;
    }
    if (sound_balance_window != NULL) {
        ((TWindowBase *)sound_balance_window)->close();
        sound_balance_window = NULL;
    }
    if (option_menu != NULL) {
        ((TWindowBase *)option_menu)->close();
        option_menu = NULL;
    }
    if (m_30 != NULL) {
        ((TWindowBase *)m_30)->close();
        m_30 = NULL;
    }
    if (sub_menu != NULL) {
        ((TWindowBase *)sub_menu)->close();
        sub_menu = NULL;
    }
    if (main_menu != NULL) {
        ((TWindowBase *)main_menu)->close();
        main_menu = NULL;
    }
}

void TWindowOptionCtrl::run_task() {
    switch (state) {
    case 0:
    case 1:
        if (serial_info_window != NULL) {
            ((TWindowBase *)serial_info_window)->close();
            serial_info_window = NULL;
        }
        if (yes_no_window != NULL) {
            ((TWindowMessageYesNo *)(yes_no_window))->close();
            yes_no_window = NULL;
        }
        if (snap_shot_window != NULL) {
            ((TWindowBase *)snap_shot_window)->close();
            snap_shot_window = NULL;
        }
        if (sound_balance_window != NULL) {
            ((TWindowBase *)sound_balance_window)->close();
            sound_balance_window = NULL;
        }
        if (option_menu != NULL) {
            ((TWindowBase *)option_menu)->close();
            option_menu = NULL;
        }
        if (sub_menu != NULL) {
            ((TWindowBase *)sub_menu)->close();
            sub_menu = NULL;
        }
        if (main_menu == NULL) {
            main_menu = (void *)create_menu();
        }
        ((TWindowMenu *)(main_menu))->clear_transition_flag();
        ((TWindowMenu *)(main_menu))->clear_flag_and_release();
        state = 2;
    case 2:
        if (((TWindowMenu *)(main_menu))->is_cancelled() != 0) {
            state = 0x1B;
        } else if (((TWindowMenu *)(main_menu))->is_decided() != 0) {
            state = ((TWindowMenu *)main_menu)->get_selected_value();
        }
        break;
    case 3:
        ((TWindowMenu *)(main_menu))->open();
        if (option_menu == NULL) {
            option_menu = (void *)create_select_menu_window();
        }
        state = 4;
    case 4:
        if (((TWindowMenuIconLine *)(option_menu))->is_cancelled() != 0) {
            state = 1;
        }
        if (handle_input(((TWindowOptionCtrl *)option_menu)->update_selected_item()) != 0) {
            state = 1;
        }
        break;
    case 5:
        TWindowOptionCtrl__sub_802273B4(0x1E);
        ((TWindowMenu *)(main_menu))->open();
        if (sub_menu == NULL) {
            sub_menu = (void *)create_list_window();
        }
        state = 6;
    case 6:
        if (((TWindowMenu *)(sub_menu))->is_cancelled() != 0) {
            if (flags & 2) {
                TWindowOptionCtrl__sub_802273B4(0x1E);
                flags &= ~2;
                ((TWindowOptionCtrl *)(sub_menu))->clear_flag70_bit4();
            } else {
                TLobby::stop_audio_streams();
                TLobby::close_option_window();
                play_area_music("advr.adx");
                state = 1;
                break;
            }
        }
        if (((TWindowMenu *)(sub_menu))->is_decided() != 0) {
            apply_and_close(((TWindowMenu *)sub_menu)->get_selected_value());
            ((TWindowMenu *)(sub_menu))->clear_flag_and_release();
        }
        break;
    case 7:
        ((TWindowMenu *)(main_menu))->open();
        if (option_menu == NULL) {
            option_menu = (void *)create_sound_mode_menu();
        }
        state = 8;
    case 8:
        sound_mode = ((TWindowOptionCtrl *)option_menu)->update_selected_item();
        if (((TWindowMenuIconLine *)(option_menu))->is_cancelled() != 0) {
            state = 1;
        }
        break;
    case 9:
        ((TWindowMenu *)(main_menu))->open();
        if (sound_balance_window == NULL) {
            sound_balance_window = (void *)create_sound_balance_window();
        }
        state = 0xA;
    case 10:
        if (TWindowOptionCtrl__sub_8026C658(sound_balance_window) != 0) {
            s16 b = ((TWindowOptionCtrl *)sound_balance_window)->get_field_64();
            TWindowOptionCtrl::set_params(this, (s16)((TWindowOptionCtrl *)(sound_balance_window))->get_field_62(), b);
            state = 1;
        } else if (((TWindowSoundBalance *)(sound_balance_window))->is_active() != 0) {
            s16 b = ((TWindowOptionCtrl *)sound_balance_window)->get_field_64();
            TWindowOptionCtrl::set_params(this, (s16)((TWindowOptionCtrl *)(sound_balance_window))->get_field_62(), b);
            state = 1;
        }
        break;
    case 11:
        if (TObjBoss2Tunnel::save_snapshot() != 1) {
            state = 0xE;
        } else {
            save_screen_snapshot();
            state = 0xC;
        }
        break;
    case 12:
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            ((TWindowMenu *)(main_menu))->open();
            if (snap_shot_window == NULL) {
                snap_shot_window = (void *)create_snap_shot_window();
            }
            state = 0xD;
        }
        break;
    case 13:
        if (TWindowOptionCtrl__sub_8026C630(snap_shot_window) != 0) {
            state = 1;
        }
        break;
    case 14:
        if (card_format_dialog == NULL) {
            card_format_dialog = new TSnapshotFileSetup(this);
        }
        ((TWindowMenu *)(main_menu))->open();
        state = 0xF;
    case 15: {
        s32 r = card_format_dialog->get_result();
        if (r == 1 || r == 2) {
            card_format_dialog->queue_destruction();
            card_format_dialog = NULL;
            if (r == 1) {
                state = 0xB;
            } else {
                state = 1;
            }
        } else if (r == 3) {
            request_main_phase(0);
        }
        break;
    }
    case 16:
        if (yes_no_window != NULL) {
            ((TWindowMessageYesNo *)(yes_no_window))->close();
            yes_no_window = NULL;
        }
        if (option_menu != NULL) {
            ((TWindowBase *)option_menu)->close();
            option_menu = NULL;
        }
        if (m_30 != NULL) {
            ((TWindowBase *)m_30)->close();
            m_30 = NULL;
        }
        if (sub_menu == NULL) {
            sub_menu = (void *)create_sub_menu_window();
        }
        ((TWindowMenu *)(main_menu))->open();
        ((TWindowMenu *)(sub_menu))->clear_transition_flag();
        ((TWindowMenu *)(sub_menu))->clear_flag_and_release();
        state = 0x11;
    case 17:
        if (((TWindowMenu *)(sub_menu))->is_cancelled() != 0) {
            state = 1;
        } else if (((TWindowMenu *)(sub_menu))->is_decided() != 0) {
            state = ((TWindowMenu *)sub_menu)->get_selected_value();
        }
        break;
    case 18:
        ((TWindowMenu *)(sub_menu))->open();
        if (option_menu == NULL) {
            option_menu = (void *)create_option_menu();
        }
        state = 0x13;
    case 19:
        ((void (*)(void *, s32)) set_field_value__17TWindowOptionCtrlFls)(this, ((TWindowOptionCtrl *)option_menu)->update_selected_item());
        if (((TWindowMenuIconLine *)(option_menu))->is_cancelled() != 0) {
            state = 0x10;
        }
        break;
    case 20:
    case 21:
        state = 0x17;
        break;
    case 22:
        if (((TWindowMenu *)(m_30))->is_cancelled() != 0) {
            state = 0x10;
        }
        if (((TWindowMenu *)(m_30))->is_decided() != 0) {
            state = 0x17;
        }
        break;
    case 23:
        if (yes_no_window == NULL) {
            switch (((TWindowMenu *)sub_menu)->get_selected_value()) {
            case 0x14:
                yes_no_window = (void *)TWindowOptionCtrl::open_yes_no_window((saddr)this, 0x22, 0xD0);
                break;
            case 0x15:
                yes_no_window = (void *)TWindowOptionCtrl::open_yes_no_window((saddr)this, 0x24, 0xD0);
                break;
            }
        }
        ((TWindowMenu *)(sub_menu))->open();
        state = 0x18;
    case 24:
        if (((TWindowMessageYesNo *)(yes_no_window))->is_cancelled() != 0) {
            state = 0x10;
        } else if (((TWindowMessageYesNo *)(yes_no_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(yes_no_window))->get_selected_value() == 0) {
                if (((TWindowMenu *)sub_menu)->get_selected_value() == 0x14) {
                    m_24 = 1;
                } else {
                    m_24 = 3;
                }
                state = 0x1B;
            } else {
                state = 0x10;
            }
        }
        break;
    case 25:
        if (serial_info_window == NULL) {
            serial_info_window = (void *)TWindowOptionCtrl::create_serial_info_window(TWindowOptionCtrl::get_option_entry(0xCF), 1);
        }
        ((TWindowMenu *)(main_menu))->open();
        state = 0x1A;
    case 26:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            state = 1;
        }
        break;
    case 27:
        flags |= 1;
        break;
    }
}
}

void TWindowOptionCtrl::render() {  }

extern "C" {
saddr TWindowOptionCtrl::create_menu() {
    saddr menu;

    menu = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCE), 9);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 0), 6, 3);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 1), 6, 7);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 2), 6, 5);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 3), 6, 9);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 4), 6, 0xB);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 5), 6, 0x10);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 6), 6, 0x19);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 7), 6, 0x1B);
    ((TWindowMenu *)menu)->update_layout_height(470.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}

saddr TWindowOptionCtrl::create_select_menu_window() {
    saddr check_box_window;
    check_box_window = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xCF), &lbl_8044F48C);
    TWindowOptionCtrl::add_menu_item(check_box_window, (get_localized_text_entry(0xF, 8)), 0);
    TWindowOptionCtrl::add_menu_item(check_box_window, (get_localized_text_entry(0xF, 9)), 1);
    TWindowOptionCtrl::add_menu_item(check_box_window, (get_localized_text_entry(0xF, 0xA)), 2);
    TWindowOptionCtrl::add_menu_item(check_box_window, (get_localized_text_entry(0xF, 0xB)), 3);
    TWindowOptionCtrl::add_menu_item(check_box_window, (get_localized_text_entry(0xF, 0xC)), 4);
    ((TWindowSubStatusDisp *)check_box_window)->set_selected_index((s16)((s16) current_language));
    return check_box_window;
}

saddr TWindowOptionCtrl::create_list_window() {
    s32 idx;
    saddr list;

    unlock_music_flag(2);
    list = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCF), 0x31);
    ((TWindowSubComCardList *)list)->set_flag70_bit100();
    idx = 0;
    do {
        if (is_music_flag_unlocked_stub(idx) != 0) {
            if (check_flag_index_set(idx) == 0) {
                add_gray_text_entry((TWindowMenu *)list, (const char *)("?????"), 0x26, idx);
            } else {
                ((TWindowMenu *)list)->add_text_entry(get_option_table_entry(idx), 0x26, idx);
            }
        }
        idx += 1;
    } while (idx < 0x31);
    ((TWindowOptionCtrl *)list)->set_flag70_bit400();
    ((TWindowSubComCardList *)list)->set_scroll_target(470.0f, 124.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

saddr TWindowOptionCtrl::create_sound_mode_menu() {
    saddr check_box_window;

    saddr temp_r3_after_cba4 = (saddr)TWindowOptionCtrl::get_option_entry(0xCF);
    check_box_window = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)temp_r3_after_cba4, &lbl_8044F494);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0xE), 0);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0xD), 1);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0xF), 2);
    switch (sound_mode) {
    case 0:
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(0);
        break;
    case 1:
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(1);
        break;
    case 2:
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(2);
        break;
    }
    return check_box_window;
}

saddr TWindowOptionCtrl::create_sound_balance_window() {
    s32 sound_balance_window;

    sound_balance_window = (saddr)new TWindowSoundBalance(reinterpret_cast<const NJS_POINT2 *>(get_option_entry(0xCF)));
    return sound_balance_window;
}

saddr TWindowOptionCtrl::create_snap_shot_window() {
    s32 window_snap_shot;

    window_snap_shot = (saddr)new TWindowSnapShot((saddr)TWindowOptionCtrl::get_option_entry(0xCF));
    return window_snap_shot;
}

saddr TWindowOptionCtrl::create_sub_menu_window() {
    saddr menu;
    menu = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCF), 3);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 0x1A), 6, 0x12);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 0x1B), 6, 0x14);
    ((TWindowMenu *)menu)->add_text_entry(get_localized_text_entry(0xF, 0x1C), 6, 0x15);
    ((TWindowMenu *)menu)->update_layout_height(470.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}

saddr TWindowOptionCtrl::create_option_menu() {
    saddr check_box_window;

    check_box_window = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xD0), &lbl_8044F49C);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0x10), 0);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0x11), 1);
    TWindowOptionCtrl::add_menu_item(check_box_window, get_localized_text_entry(0xF, 0x12), 2);
    ((TWindowSubStatusDisp *)check_box_window)->set_selected_index((s16) TWindowOptionCtrl::get_option_field_C());
    return check_box_window;
}

saddr TWindowOptionCtrl::open_yes_no_window(saddr arg0, s32 arg1, s32 index) {
  saddr window;
  window = (saddr)TWindowMessageYesNo::create((void *)(arg0), 6, (void *)(arg0 * 0), 0);
  ((TWindowMessageYesNo *)window)->open_yes_no_prompt_with_text((s32)(get_localized_text_entry(0xF, arg1)), (saddr)(get_window_layout_position(index)), 470.0f);
  ((TWindowMessageYesNo *)window)->set_menu_selected_index(1);
  return window;
}

saddr TWindowOptionCtrl::create_serial_info_window(const NJS_POINT2 *pos, s32 kind) {
    saddr w;
    w = (saddr)TWindowMessage::create(pos, (const f32 *)(&lbl_8044F4A4), 3);
    switch (kind) {
    case 0:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_80321874()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_803217B8()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterPasswordGC__sub_8013ADE4()))), (u32)0);
        break;
    case 1:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_80321738()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC::get_formatted_serial()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)((void *)TWindowOptionCtrl::get_chr_select_base_plus_1154c()))), (u32)0);
        break;
    }
    ((TWindowMessage *)w)->complete_reveal();
    return w;
}
}

const char *TWindowOptionCtrl::text_or_default(const char *text) {
    if ((text == NULL) || ((s8) *text == 0)) {
        return (const char *)get_localized_text_entry(0xF, 0x19);
    }
    return text;
}

extern "C" {
s32 TWindowOptionCtrl::handle_input(s32 language) {
    if (TLanguage::set_language((s8) language) != 0) {
        unload_lobby_scene_resources();
        load_lobby_scene_resources();
        if (option_menu != NULL) {
            ((TObject *)option_menu)->queue_destruction();
            option_menu = NULL;
        }
        if (main_menu != NULL) {
            ((TObject *)main_menu)->queue_destruction();
            main_menu = NULL;
        }
        main_menu = (void *)create_menu();
        window_request_refresh((u8 *)main_menu);
        return 1;
    }
    return 0;
}

void TWindowOptionCtrl::apply_and_close(s32 arg1) {
    TLobby::stop_audio_streams();
    TLobby::stop_audio_streams();
    TLobby::close_option_window();
    play_area_music(get_bgm_filename(arg1));
    this->flags = (u8) (this->flags | 2);
}

void TWindowOptionCtrl::init_selection_indices() {
    s16 temp_r3;

    temp_r3 = TLobby::init_sound_mode();
    saved_sound_mode = temp_r3;
    sound_mode = temp_r3;
}

void TWindowOptionCtrl::apply_selection_change() {
    if (saved_sound_mode != sound_mode) {
        TLobby::stop_audio_streams();
        TLobby::set_sound_output_mode(sound_mode);
        TLobby::init_layout_positions();
    }
}

void TWindowOptionCtrl::set_params(void *arg0, s16 arg1, s16 arg2) {
    void *global_state;

    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state != NULL) {
        *(s16 *)((s8 *)global_state + 4) = arg1;
        *(s8 *)((s8 *)global_state + 6) = arg2;
    }
}
}

s32 TWindowOptionCtrl::get_option_field_C() {
    return (s16)(*(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC));
}

void TWindowOptionCtrl::set_field_value(s32 arg0, s16 arg1) {
    *(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC) = arg1;
}
