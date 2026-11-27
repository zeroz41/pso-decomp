#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TSnapshotFileSetup.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/audio/MusicUnlockFlags.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
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
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/audio/MusicControl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_Snapshot.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/math/TMath.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/audio/SoundRequests.h"

// The class name opens .rodata, then the menu window positions in this order, ahead of the
// strings of the functions.
const char *TWindowOptionCtrl::class_name = "TWindowOptionCtrl";
const vec2f select_menu_window_size = {470.0f, 124.0f};
const vec2f sound_mode_menu_window_size = {470.0f, 80.0f};
const vec2f option_menu_window_size = {470.0f, 80.0f};
const vec2f serial_info_window_size = {470.0f, 80.0f};

extern "C" {
void set_udp_option__17TWindowOptionCtrlFls(s32 unused, s16 option);
}

int TWindowSoundBalance::is_cancelled() { return result_flags & 0x2; }

s32 TWindowSoundBalance::get_music_gain() { return music_gain; }

s32 TWindowSoundBalance::get_sound_effect_gain() { return sound_effect_gain; }

int TWindowSoundBalance::is_active() { return this->result_flags & 0x1; }

int TWindowSnapShot::is_done() { return result_flags & 0x1; }

void TWindowMenu::clear_cancelled() { menu_flags &= ~4; }

void TWindowMenu::set_flag70_bit100() { this->menu_flags |= 0x100; }

void TWindowMenu::set_silent_cancel() { menu_flags |= 0x400; }

saddr TWindowOptionCtrl::get_chr_select_base_plus_1154c() {
    return (saddr)TAdSinglePlyChrSelectGC::get_instance()->password;
}

TWindowOptionCtrl::TWindowOptionCtrl(TObject *parent) : TObject(parent) {
    m_name = class_name;
    main_menu = NULL;
    sub_menu = NULL;
    confirm_menu = NULL;
    option_menu = NULL;
    sound_balance_window = NULL;
    snap_shot_window = NULL;
    yes_no_window = NULL;
    serial_info_window = NULL;
    card_format_dialog = NULL;
    player_load = new TAdPlayerLoadGC(this, 2);
    init_selection_indices();
    dial_selection = 4;
    flags = 0;
    state = 0;
}

TWindowOptionCtrl::~TWindowOptionCtrl() {
    apply_selection_change();
    if (serial_info_window != NULL) {
        serial_info_window->close();
        serial_info_window = NULL;
    }
    if (yes_no_window != NULL) {
        yes_no_window->close();
        yes_no_window = NULL;
    }
    if (snap_shot_window != NULL) {
        snap_shot_window->close();
        snap_shot_window = NULL;
    }
    if (sound_balance_window != NULL) {
        sound_balance_window->close();
        sound_balance_window = NULL;
    }
    if (option_menu != NULL) {
        option_menu->close();
        option_menu = NULL;
    }
    if (confirm_menu != NULL) {
        confirm_menu->close();
        confirm_menu = NULL;
    }
    if (sub_menu != NULL) {
        sub_menu->close();
        sub_menu = NULL;
    }
    if (main_menu != NULL) {
        main_menu->close();
        main_menu = NULL;
    }
}

void TWindowOptionCtrl::run_task() {
    switch (state) {
    case 0:
    case 1:
        if (serial_info_window != NULL) {
            serial_info_window->close();
            serial_info_window = NULL;
        }
        if (yes_no_window != NULL) {
            yes_no_window->close();
            yes_no_window = NULL;
        }
        if (snap_shot_window != NULL) {
            snap_shot_window->close();
            snap_shot_window = NULL;
        }
        if (sound_balance_window != NULL) {
            sound_balance_window->close();
            sound_balance_window = NULL;
        }
        if (option_menu != NULL) {
            option_menu->close();
            option_menu = NULL;
        }
        if (sub_menu != NULL) {
            sub_menu->close();
            sub_menu = NULL;
        }
        if (main_menu == NULL) {
            main_menu = (TWindowMenu *)create_menu();
        }
        main_menu->clear_transition_flag();
        main_menu->clear_flag_and_release();
        state = 2;
    case 2:
        if (main_menu->is_cancelled() != 0) {
            state = 0x1B;
        } else if (main_menu->is_decided() != 0) {
            state = main_menu->get_selected_value();
        }
        break;
    case 3:
        main_menu->open();
        if (option_menu == NULL) {
            option_menu = create_select_menu_window();
        }
        state = 4;
    case 4:
        if (option_menu->is_cancelled() != 0) {
            state = 1;
        }
        if (handle_input(option_menu->update_selected_item()) != 0) {
            state = 1;
        }
        break;
    case 5:
        start_music_crossfade(0x1E);
        main_menu->open();
        if (sub_menu == NULL) {
            sub_menu = (TWindowMenu *)create_list_window();
        }
        state = 6;
    case 6:
        if (sub_menu->is_cancelled() != 0) {
            if (flags & 2) {
                start_music_crossfade(0x1E);
                flags &= ~2;
                sub_menu->clear_cancelled();
            } else {
                stop_audio_streams();
                close_option_window();
                play_area_music("advr.adx");
                state = 1;
                break;
            }
        }
        if (sub_menu->is_decided() != 0) {
            apply_and_close(sub_menu->get_selected_value());
            sub_menu->clear_flag_and_release();
        }
        break;
    case 7:
        main_menu->open();
        if (option_menu == NULL) {
            option_menu = create_sound_mode_menu();
        }
        state = 8;
    case 8:
        sound_mode = option_menu->update_selected_item();
        if (option_menu->is_cancelled() != 0) {
            state = 1;
        }
        break;
    case 9:
        main_menu->open();
        if (sound_balance_window == NULL) {
            sound_balance_window = create_sound_balance_window();
        }
        state = 0xA;
    case 10:
        if (sound_balance_window->is_cancelled() != 0) {
            s16 b = sound_balance_window->get_sound_effect_gain();
            set_sound_balance(sound_balance_window->get_music_gain(), b);
            state = 1;
        } else if (sound_balance_window->is_active() != 0) {
            s16 b = sound_balance_window->get_sound_effect_gain();
            set_sound_balance(sound_balance_window->get_music_gain(), b);
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
            main_menu->open();
            if (snap_shot_window == NULL) {
                snap_shot_window = create_snap_shot_window();
            }
            state = 0xD;
        }
        break;
    case 13:
        if (snap_shot_window->is_done() != 0) {
            state = 1;
        }
        break;
    case 14:
        if (card_format_dialog == NULL) {
            card_format_dialog = new TSnapshotFileSetup(this);
        }
        main_menu->open();
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
            yes_no_window->close();
            yes_no_window = NULL;
        }
        if (option_menu != NULL) {
            option_menu->close();
            option_menu = NULL;
        }
        if (confirm_menu != NULL) {
            confirm_menu->close();
            confirm_menu = NULL;
        }
        if (sub_menu == NULL) {
            sub_menu = (TWindowMenu *)create_sub_menu_window();
        }
        main_menu->open();
        sub_menu->clear_transition_flag();
        sub_menu->clear_flag_and_release();
        state = 0x11;
    case 17:
        if (sub_menu->is_cancelled() != 0) {
            state = 1;
        } else if (sub_menu->is_decided() != 0) {
            state = sub_menu->get_selected_value();
        }
        break;
    case 18:
        sub_menu->open();
        if (option_menu == NULL) {
            option_menu = create_udp_option_menu();
        }
        state = 0x13;
    case 19:
        // Called with the selection as an int: the definition takes it as s16.
        ((void (*)(void *, s32)) set_udp_option__17TWindowOptionCtrlFls)(this, option_menu->update_selected_item());
        if (option_menu->is_cancelled() != 0) {
            state = 0x10;
        }
        break;
    case 20:
    case 21:
        state = 0x17;
        break;
    case 22:
        if (confirm_menu->is_cancelled() != 0) {
            state = 0x10;
        }
        if (confirm_menu->is_decided() != 0) {
            state = 0x17;
        }
        break;
    case 23:
        if (yes_no_window == NULL) {
            switch (sub_menu->get_selected_value()) {
            case 0x14:
                yes_no_window = open_yes_no_window(0x22, 0xD0);
                break;
            case 0x15:
                yes_no_window = open_yes_no_window(0x24, 0xD0);
                break;
            }
        }
        sub_menu->open();
        state = 0x18;
    case 24:
        if (yes_no_window->is_cancelled() != 0) {
            state = 0x10;
        } else if (yes_no_window->is_child_visible() != 0) {
            if (yes_no_window->get_selected_value() == 0) {
                if (sub_menu->get_selected_value() == 0x14) {
                    dial_selection = 1;
                } else {
                    dial_selection = 3;
                }
                state = 0x1B;
            } else {
                state = 0x10;
            }
        }
        break;
    case 25:
        if (serial_info_window == NULL) {
            serial_info_window = (TWindowBase *)TWindowOptionCtrl::create_serial_info_window(TWindowOptionCtrl::get_option_entry(0xCF), 1);
        }
        main_menu->open();
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

void TWindowOptionCtrl::render() {  }

saddr TWindowOptionCtrl::create_menu() {
    TWindowMenu *menu;

    menu = create_window_menu_default(TWindowOptionCtrl::get_option_entry(0xCE), 9);
    menu->add_text_entry(get_localized_text_entry(0xF, 0), 6, 3);
    menu->add_text_entry(get_localized_text_entry(0xF, 1), 6, 7);
    menu->add_text_entry(get_localized_text_entry(0xF, 2), 6, 5);
    menu->add_text_entry(get_localized_text_entry(0xF, 3), 6, 9);
    menu->add_text_entry(get_localized_text_entry(0xF, 4), 6, 0xB);
    menu->add_text_entry(get_localized_text_entry(0xF, 5), 6, 0x10);
    menu->add_text_entry(get_localized_text_entry(0xF, 6), 6, 0x19);
    menu->add_text_entry(get_localized_text_entry(0xF, 7), 6, 0x1B);
    menu->update_layout_height(470.0f);
    menu->align_menu_entry_positions();
    return (saddr)menu;
}

TWindowCheckBox *TWindowOptionCtrl::create_select_menu_window() {
    TWindowCheckBox *check_box_window;
    check_box_window = create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xCF), &select_menu_window_size);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 8), 0);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 9), 1);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xA), 2);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xB), 3);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xC), 4);
    check_box_window->set_selected_index((s16)((s16) current_language));
    return check_box_window;
}

saddr TWindowOptionCtrl::create_list_window() {
    s32 idx;
    TWindowMenu *list;

    unlock_music_flag(2);
    list = create_window_menu_default(TWindowOptionCtrl::get_option_entry(0xCF), 0x31);
    list->set_flag70_bit100();
    idx = 0;
    do {
        if (is_music_flag_unlocked_stub(idx) != 0) {
            if (check_flag_index_set(idx) == 0) {
                add_gray_text_entry(list, (const char *)("?????"), 0x26, idx);
            } else {
                list->add_text_entry(get_option_table_entry(idx), 0x26, idx);
            }
        }
        idx += 1;
    } while (idx < 0x31);
    list->set_silent_cancel();
    list->set_scroll_target(470.0f, 124.0f);
    list->align_menu_entry_positions();
    return (saddr)list;
}

TWindowCheckBox *TWindowOptionCtrl::create_sound_mode_menu() {
    TWindowCheckBox *check_box_window;

    const NJS_POINT2 *option_position = TWindowOptionCtrl::get_option_entry(0xCF);
    check_box_window = create_check_box_window_for_local_client(option_position, &sound_mode_menu_window_size);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xE), 0);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xD), 1);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0xF), 2);
    switch (sound_mode) {
    case 0:
        check_box_window->set_selected_index(0);
        break;
    case 1:
        check_box_window->set_selected_index(1);
        break;
    case 2:
        check_box_window->set_selected_index(2);
        break;
    }
    return check_box_window;
}

TWindowSoundBalance *TWindowOptionCtrl::create_sound_balance_window() {
    return new TWindowSoundBalance(get_option_entry(0xCF));
}

TWindowSnapShot *TWindowOptionCtrl::create_snap_shot_window() {
    return new TWindowSnapShot(TWindowOptionCtrl::get_option_entry(0xCF));
}

saddr TWindowOptionCtrl::create_sub_menu_window() {
    TWindowMenu *menu;
    menu = create_window_menu_default(TWindowOptionCtrl::get_option_entry(0xCF), 3);
    menu->add_text_entry(get_localized_text_entry(0xF, 0x1A), 6, 0x12);
    menu->add_text_entry(get_localized_text_entry(0xF, 0x1B), 6, 0x14);
    menu->add_text_entry(get_localized_text_entry(0xF, 0x1C), 6, 0x15);
    menu->update_layout_height(470.0f);
    menu->align_menu_entry_positions();
    return (saddr)menu;
}

TWindowCheckBox *TWindowOptionCtrl::create_udp_option_menu() {
    TWindowCheckBox *check_box_window;

    check_box_window = create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xD0), &option_menu_window_size);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0x10), 0);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0x11), 1);
    check_box_window->add_menu_item(get_localized_text_entry(0xF, 0x12), 2);
    check_box_window->set_selected_index((s16) TWindowOptionCtrl::get_udp_option());
    return check_box_window;
}

TWindowMessageYesNo *TWindowOptionCtrl::open_yes_no_window(s32 message_id, s32 index) {
  TWindowMessageYesNo *window;
  window = TWindowMessageYesNo::create(this, 6, NULL, NULL);
  window->open_yes_no_prompt_with_text(get_localized_text_entry(0xF, message_id), get_window_layout_position(index), 470.0f);
  window->set_menu_selected_index(1);
  return window;
}

saddr TWindowOptionCtrl::create_serial_info_window(const NJS_POINT2 *pos, s32 kind) {
    TWindowMessage *w;
    w = TWindowMessage::create(pos, (const f32 *)(&serial_info_window_size), 3);
    switch (kind) {
    case 0:
        w->add_label_value_line(get_localized_text_entry(0xF, 0x16), TWindowOptionCtrl::text_or_default(format_entered_serial()), 0);
        w->add_label_value_line(get_localized_text_entry(0xF, 0x17), TWindowOptionCtrl::text_or_default(format_entered_access_key()), 0);
        w->add_label_value_line(get_localized_text_entry(0xF, 0x18), TWindowOptionCtrl::text_or_default((const char *)get_password_input_buffer()), 0);
        break;
    case 1:
        w->add_label_value_line(get_localized_text_entry(0xF, 0x16), TWindowOptionCtrl::text_or_default(format_saved_serial()), 0);
        w->add_label_value_line(get_localized_text_entry(0xF, 0x17), TWindowOptionCtrl::text_or_default(TAdEnterSerialAccessGC::get_formatted_serial()), 0);
        w->add_label_value_line(get_localized_text_entry(0xF, 0x18), TWindowOptionCtrl::text_or_default((const char *)TWindowOptionCtrl::get_chr_select_base_plus_1154c()), 0);
        break;
    }
    w->complete_reveal();
    return (saddr)w;
}

const char *TWindowOptionCtrl::text_or_default(const char *text) {
    if ((text == NULL) || ((s8) *text == 0)) {
        return get_localized_text_entry(0xF, 0x19);
    }
    return text;
}

s32 TWindowOptionCtrl::handle_input(s32 language) {
    if (TLanguage::set_language((s8) language) != 0) {
        unload_lobby_scene_resources();
        load_lobby_scene_resources();
        if (option_menu != NULL) {
            option_menu->queue_destruction();
            option_menu = NULL;
        }
        if (main_menu != NULL) {
            main_menu->queue_destruction();
            main_menu = NULL;
        }
        main_menu = (TWindowMenu *)create_menu();
        main_menu->request_refresh();
        return 1;
    }
    return 0;
}

void TWindowOptionCtrl::apply_and_close(s32 bgm_index) {
    stop_audio_streams();
    stop_audio_streams();
    close_option_window();
    play_area_music(get_bgm_filename(bgm_index));
    this->flags = (u8) (this->flags | 2);
}

void TWindowOptionCtrl::init_selection_indices() {
    s16 current_sound_mode;

    current_sound_mode = init_sound_mode();
    saved_sound_mode = current_sound_mode;
    sound_mode = current_sound_mode;
}

void TWindowOptionCtrl::apply_selection_change() {
    if (saved_sound_mode != sound_mode) {
        stop_audio_streams();
        set_sound_output_mode(sound_mode);
        init_layout_positions();
    }
}

void TWindowOptionCtrl::set_sound_balance(s16 music_gain, s16 sound_effect_gain) {
    SystemSaveData *save;

    save = TAdSinglePlyChrSelectGC::get_global_state();
    if (save != NULL) {
        save->music_stream_gain = music_gain;
        save->cue_stream_gain = sound_effect_gain;
    }
}

s32 TWindowOptionCtrl::get_udp_option() {
    return TAdSinglePlyChrSelectGC::get_global_state()->udp_option;
}

void TWindowOptionCtrl::set_udp_option(s32 unused, s16 option) {
    TAdSinglePlyChrSelectGC::get_global_state()->udp_option = option;
}
