#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/TAdSystemFileCheckGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_MemCard.h"
#include "pso/ui/window/TObjBagWarnWin.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/SystemBootInit.h"

#include <stddef.h>
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/audio/MusicControl.h"

// Message text by id: table_a holds the English text, table_b the Japanese.
const char *multi_chg_game_mode_text_table_a[11] = {
    "\"PSO 1&2 Plus\" save files will overwrite\n"
    "\"PSO 1&2\" save files. When save files\n"
    "are overwritten the following will occur:\n"
    "\n"
    "- Characters created on PSO 1&2 will no longer be\n"
    "  compatible with older PSO 1&2 game.\n"
    "- All Item data for all characters (including all\n"
    "  items in Check Room, and Meseta) will be deleted.\n"
    "- Character level, game progress, and Guild Card\n"
    "  will be retained.",
    "- The Ship (server) for PSO 1&2 and PSO 1&2 Plus\n"
    "  are separate. Search or exchange of simple mail\n"
    "  between the PSO 1&2 Ship and the PSO 1&2 Plus\n"
    "  Ship will not be possible. \n"
    "- Please use the same Serial Number and\n"
    "  Access Key from PSO 1&2.\n"
    "- In order to avoid file corruption, do not turn off\n"
    "  the power, remove the Memory Card, or open the\n"
    "  Disc Cover while game data is being  overwritten.\n"
    "\n"
    "Select \"Yes\" if you agree with the stated\n"
    "conditions to have your files overwritten. ",
    "Next Page",
    "Are you sure?",
    "A Memory Card is required to play \n"
    "Phantasy Star Online. \n"
    "\n"
    "Please insert a Memory Card into Slot A.",
    "\tJ\x93\xFA\x96{\x8C\xEA",
    "YES",
    "NO",
    "Saving.\n"
    "Do not remove the Memory Card or\n"
    "turn the power off.",
    "You can play PSO 1&2,\n"
    "PSO 1&2 [Upgrade for Online play],\n"
    "PSO 1&2 Plus and PSO Episode 3\n"
    "using the same Serial Number/Access Key.\n"
    "\n"
    "The Serial Number/Access Key from PSO Episode 3\n"
    "in the Memory Card in Slot A will be recognized.",
    "Next",
};
const char *multi_chg_game_mode_text_table_b[11] = {
    "\tJ\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x81i\x88\xC8\x8D~\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x8C\xC4\x8F\xCC\x81j\x81v\x82\xCC\x83Z\x81[\x83u\n"
    "\x83t\x83@\x83" "C\x83\x8B\x82\xF0\x81" "A\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x81@\x82o\x82\x8C\x82\x95\x82\x93\x81i\x88\xC8\x8D~\x82" "d\x82o\x82P\x81\x95\x82Q\n"
    "\x82o\x82\x8C\x82\x95\x82\x93\x82\xC6\x8C\xC4\x8F\xCC\x81j\x81v\x82\xC5\x81" "A\x83v\x83\x8C\x83" "C\x82\xC5\x82\xAB\x82\xE9\x82\xE6\x82\xA4\x83Z\x81[\x83u\x83t\x83@\x83" "C\x83\x8B\x82\xCC\x8F\x91\x82\xAB\n"
    "\x82\xA9\x82\xA6\x82\xF0\x8Ds\x82\xA2\x82\xDC\x82\xB7\x81" "B\x83Z\x81[\x83u\x83t\x83@\x83" "C\x83\x8B\x82\xCC\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x91\x80\x8D\xEC\x82\xF0\x8Ds\x82\xA4\x82\xC6\x81" "A\n"
    "\n"
    "\x81" "E\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xCC\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x82\xCD\x97V\x82\xD7\x82\xC8\x82\xAD\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"
    "\x81" "E\x83\x81\x83" "C\x83\x93\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x81" "A\x83I\x83t\x83\x89\x83" "C\x83\x93\x83}\x83\x8B\x83`\x83\x82\x81[\x83h\x97p\x82\xCC\x88\xEA\x8E\x9E\x83L\x83\x83\x83\x89\n"
    "\x81@\x83N\x83^\x81[\x93\x99\x82\xCC\x91S\x83" "A\x83" "C\x83" "e\x83\x80\x83" "f\x81[\x83^\x81i\x83`\x83" "F\x83" "b\x83N\x83\x8B\x81[\x83\x80\x82\xF0\x8A\xDC\x82\xDE\x91S\x83" "A\x83" "C\x83" "e\n"
    "\x81@\x83\x80\x82\xA8\x82\xE6\x82\xD1\x83\x81\x83Z\x83^\x81j\x82\xAA\x8D\xED\x8F\x9C\x82\xB3\x82\xEA\x81" "A\x8F\x89\x8A\xFA\x91\x95\x94\xF5\x82\xC6\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"
    "\x81" "E\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x82\xCC\x83\x8C\x83x\x83\x8B\x82\xE2\x83Q\x81[\x83\x80\x90i\x8Ds\x93x\x81" "A\x83M\x83\x8B\x83h\x83J\x81[\x83h\x93\x99\x82\xCD\n"
    "\x81@\x82\xBB\x82\xCC\x82\xDC\x82\xDC\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B",
    "\tJ\x81" "E\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x82\xCC\x83V\x83" "b\x83v\x81i\x83T\x81[\x83o\x81j\x82\xCD\x95\xCA\x82\xC9\x82\xC8\n"
    "\x81@\x82\xE8\x82\xDC\x82\xB7\x81" "B\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x82\xCC\x83V\x83" "b\x83v\x81i\x83T\x81[\x83o\x81j\n"
    "\x81@\x8A\xD4\x82\xC5\x82\xCC\x8C\x9F\x8D\xF5\x82\xE2\x83V\x83\x93\x83v\x83\x8B\x83\x81\x81[\x83\x8B\x91\x97\x8E\xF3\x90M\x93\x99\x82\xCD\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"
    "\x81" "E\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "A\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xCD\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC5\x83n\x83\x93\x83^\x81[\x83Y\x83\x89\n"
    "\x81@\x83" "C\x83Z\x83\x93\x83X\x82\xF0\x82\xA8\x94\x83\x82\xA2\x8B\x81\x82\xDF\x82\xCC\x8F\xEA\x8D\x87\x82\xCD\x81" "A\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xCC\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\n"
    "\x81@\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xF0\x82\xBB\x82\xCC\x82\xDC\x82\xDC\x82\xA8\x8Eg\x82\xA2\x89\xBA\x82\xB3\x82\xA2\x81" "B\n"
    "\x81" "E\x83t\x83@\x83" "C\x83\x8B\x82\xAA\x89\xF3\x82\xEA\x82\xE9\x8C\xB4\x88\xF6\x82\xC6\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x82\xCC\x82\xC5\x81" "A\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x92\x86\x82\xCC\x96{\x91\xCC\x93" "d\x8C\xB9\n"
    "\x81@\x82n\x82" "e\x82" "e\x81" "A\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x81" "A\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x83I\x81[\x83v\x83\x93\x82\xCD\n"
    "\x81@\x90\xE2\x91\xCE\x82\xC9\x8Ds\x82\xED\x82\xC8\x82\xA2\x82\xC5\x89\xBA\x82\xB3\x82\xA2\x81" "B\n"
    "\n"
    "\x88\xC8\x8F\xE3\x82\xCC\x93_\x82\xC9\x93\xAF\x88\xD3\x82\xCC\x8F\xE3\x81" "A\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x82\xF0\x82\xA8\x82\xB1\x82\xC8\x82\xA2\x82\xDC\x82\xB7\x81" "B\n"
    "\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x81H",
    "\tJ\x8E\x9F\x82\xCC\x83y\x81[\x83W\x82\xD6",
    "\tJ\x96{\x93\x96\x82\xC9\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x81H",
    "\tJPSO\x82\xF0\x97V\x82\xD4\x82\xC9\x82\xCD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x95K\x97v\x82\xC5\x82\xB7\x81" "B\n"
    "\x83X\x83\x8D\x83" "b\x83g\x82`\x82\xC9\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B",
    "English",
    "\tJ\x82\xCD\x82\xA2",
    "\tJ\x82\xA2\x82\xA2\x82\xA6",
    "\tJ\x83Z\x81[\x83u\x92\x86\x82\xC5\x82\xB7\x81" "B\n"
    "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x82\xB5\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"
    "\x93" "d\x8C\xB9\x82\xF0\x90\xD8\x82\xE7\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B",
    "\tJ\x81u\x82o\x82r\x82n \x82" "d\x82o\x82P\x81\x95\x82Q\x81v\x81u\x82o\x82r\x82n \x82" "d\x82o\x82P\x81\x95\x82Q\x83I\x83\x93\x83\x89\x83" "C\x83\x93\x92\xB2\x90\xAE\x94\xC5\x81v\n"
    "\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x81v\x82\xC6\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82R\x81v\x82\xCD\n"
    "\x93\xAF\x88\xEA\x82\xCC\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xC5\x97V\x82\xD4\x82\xB1\x82\xC6\x82\xAA\x89\xC2\x94\\\x82\xC5\x82\xB7\x81" "B\n"
    "\n"
    "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x93\xE0\x82\xC9\x82\xA0\x82\xE9\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82R\x81v\x82\xCC\n"
    "\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xCC\x8F\xEE\x95\xF1\x82\xF0\x93\xC7\x82\xDD\x8D\x9E\x82\xDD\x82\xDC\x82\xB7\x81" "B",
    "\tJ\x8E\x9F\x82\xC9\x90i\x82\xDE",
};

// Size of the confirm window; the window is centred on the 640-wide screen in __sinit below.
const f32 multi_chg_game_mode_window_size[2] = {540.0f, 280.0f};


TAdSystemFileCheckGCState multi_chg_game_mode_entry_table[11] = {
    {&TAdSystemFileCheckGC::enter_state_0, &TAdSystemFileCheckGC::confirm_mode_selection},
    {&TAdSystemFileCheckGC::load_system_on_mode_default, &TAdSystemFileCheckGC::update_mode_selection},
    {&TAdSystemFileCheckGC::enter_state_2, &TAdSystemFileCheckGC::check_player_load_result},
    {&TAdSystemFileCheckGC::enter_state_3, &TAdSystemFileCheckGC::handle_menu_input},
    {&TAdSystemFileCheckGC::close_windows_and_reopen, &TAdSystemFileCheckGC::update_card_confirm_selection},
    {&TAdSystemFileCheckGC::close_windows_and_cleanup, &TAdSystemFileCheckGC::update_confirm_selection},
    {&TAdSystemFileCheckGC::enter_state_6, &TAdSystemFileCheckGC::update_mode_selection_and_save},
    {&TAdSystemFileCheckGC::enter_state_7, &TAdSystemFileCheckGC::run_state_7},
    {&TAdSystemFileCheckGC::enter_state_8, &TAdSystemFileCheckGC::run_state_8},
    {&TAdSystemFileCheckGC::enter_state_9, &TAdSystemFileCheckGC::request_scene_change_vt},
    {&TAdSystemFileCheckGC::enter_state_10, &TAdSystemFileCheckGC::close_windows_on_selection},
};
__declspec(section ".data") f32 multi_chg_game_mode_window_extent[2] = {0.5f * (640.0f - multi_chg_game_mode_window_size[0]), 70.0f};
__declspec(section ".data") NJS_POINT2 system_file_check_menu_pos = {
    20.0f + multi_chg_game_mode_window_extent[0],
    10.0f + (multi_chg_game_mode_window_extent[1] + multi_chg_game_mode_window_size[1]),
};
f32 system_file_check_menu_height = multi_chg_game_mode_window_size[0] - 40.0f;

// Message text by id: text_set -1 takes the shared message table, 0 the Japanese table, else English.
const char *TAdSystemFileCheckGC::get_system_file_check_text(s32 index, s32 text_set) {
    if (text_set == -1) {
        return get_message_text((index));
    }
    if (text_set == 0) {
        return multi_chg_game_mode_text_table_b[index];
    }
    return multi_chg_game_mode_text_table_a[index];
}

void TAdSystemFileCheckGC::close_windows_on_selection() {
    TObject *window;
    if (handle_mode_selection() == 0) {
        window = message_window;
        if (window != 0U) {
            window->queue_destruction();
            message_window = NULL;
        }
        window = menu_window;
        if (window != 0U) {
            window->queue_destruction();
            menu_window = NULL;
        }
        set_state(3);
    }
}

void TAdSystemFileCheckGC::enter_state_10() {
    if (handle_mode_selection() != 0) {
        return;
    }
}

void TAdSystemFileCheckGC::update_confirm_selection() {
    s32 selected_menu_value;
    TWindowMenu *menu;

    if (handle_mode_selection() == 0) {
        menu = menu_window;
        if (menu != NULL) {
            if (menu->is_decided() != 0) {
                selected_menu_value = menu_window->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    set_state(6);
                    close_window_30();
                    open_message_window(8);
                    return;
                case 1:
                    close_menu_window();
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}

void TAdSystemFileCheckGC::close_windows_and_cleanup() {
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    if (message_window != NULL) {
        message_window->close();
        message_window = NULL;
    }
    setup_mode_menu(0);
    open_message_window(4);
    if (message_window != NULL) {
        message_window->append_line(get_system_file_check_text(3, this->language), 3);
    }
}

void TAdSystemFileCheckGC::update_card_confirm_selection() {
    s32 selected_menu_value;

    if (handle_mode_selection() == 0) {
        if (menu_window != 0) {
            if (menu_window->is_decided() != 0) {
                selected_menu_value = menu_window->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_menu_window();
                    set_state(5);
                    return;
                case 1:
                    close_menu_window();
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}

void TAdSystemFileCheckGC::close_windows_and_reopen() {
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    if (message_window != NULL) {
        message_window->close();
        message_window = NULL;
    }
    setup_mode_menu(0);
    open_message_window(4);
    if (message_window != NULL) {
        message_window->append_line(get_system_file_check_text(1, this->language), 3);
    }
}

void TAdSystemFileCheckGC::open_message_window(s32 index) {
    if (this->message_window != NULL) {
        this->message_window->close();
        this->message_window = NULL;
    }
    this->message_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)multi_chg_game_mode_window_extent, (NJS_POINT2 *)multi_chg_game_mode_window_size);
    if (this->message_window != NULL) {
        this->message_window->append_line(get_system_file_check_text(index, this->language), 3);
    }
}

void TAdSystemFileCheckGC::close_window_30() {
    TWindowBase *window_base = (TWindowBase *)message_window;
    if (window_base != 0U) {
        window_base->close();
        message_window = NULL;
    }
    close_menu_window();
}
void TAdSystemFileCheckGC::close_menu_window() { if (menu_window != 0) { ((TWindowBase *)((void*)(menu_window)))->close(); menu_window = 0; } }

void TAdSystemFileCheckGC::setup_mode_menu(s32 mode) {
    const char *a;
    const char *b;
    const char *c;
    const char *d;
    this->menu_window = create_window_menu_default(&system_file_check_menu_pos, 2);
    a = get_system_file_check_text(6, this->language);
    b = get_system_file_check_text(7, this->language);
    c = get_system_file_check_text(2, this->language);
    d = get_system_file_check_text(5, this->language);
    if (this->menu_window != 0) {
        if (mode == 0) {
            this->menu_window->add_text_entry(a, 5, 0);
            this->menu_window->add_text_entry(b, 5, 1);
            this->menu_window->set_selected_index(1);
        } else {
            this->menu_window->add_text_entry(c, 5, 0);
            this->menu_window->add_text_entry(d, 5, 1);
            this->menu_window->set_selected_index(0);
        }
        this->menu_window->update_layout_height(system_file_check_menu_height);
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(this->menu_window));
    }
}

void TAdSystemFileCheckGC::handle_menu_input() {
    s32 selected_menu_value;
    u8 *window_menu;
    if (handle_mode_selection() == 0) {
        window_menu = (u8 *)(menu_window);
        if (window_menu != NULL) {
            if (((int)((TWindowMenu *)window_menu)->is_decided()) != 0) {
                selected_menu_value = menu_window->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_menu_window();
                    set_state(4);
                    return;
                case 1:
                    if ((s32) this->language == 0) {
                        this->language = 1;
                    } else {
                        this->language = 0;
                    }
                    set_state(0xA);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}
void TAdSystemFileCheckGC::create_back_objects() {
    void *o;
    void *o2;
    if (back == NULL) {
        o = new TAdBackGC(this);
        back = o;
    }
    if (back_text == NULL) {
        o2 = new TAdBackTxtGC(this);
        back_text = o2;
    }
}
void TAdSystemFileCheckGC::enter_state_3() {
    if (menu_window != NULL) {
        ((TWindowBase *)((void*)(menu_window)))->close();
        menu_window = NULL;
    }
    setup_mode_menu(1);
    open_message_window(4);
    if (message_window != NULL) {
        message_window->append_line(get_system_file_check_text(0, this->language), 3);
    }
    create_back_objects();
}
void TAdSystemFileCheckGC::update_mode_selection() {
    if ((handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        set_state(2);
    }
}
void TAdSystemFileCheckGC::load_system_on_mode_default() { if (handle_mode_selection() == 0) { load_system_file(0); } }
s32 TAdSystemFileCheckGC::handle_mode_selection() {
    s32 selection;
    selection = this->status;
    if (selection & 1) {
        set_state(9);
        return 1;
    }
    if (selection & 2) {
        return 0;
    }
    if (selection & 4) {
        set_state(9);
        return 1;
    }
    if (selection & 8) {
        set_state(9);
        return 1;
    }
    return 0;
}
void TAdSystemFileCheckGC::run_state_7() {
    if ((handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        set_state(8);
    }
}
void TAdSystemFileCheckGC::enter_state_7() {  }
void TAdSystemFileCheckGC::update_mode_selection_and_save() {
    if (((int)handle_mode_selection()) == 0) {
        TAdSinglePlyChrSelectGC::refresh_char_slots();
        if (TAdSinglePlyChrSelectGC::encrypt_save_and_write() != 0) {
            set_state(7);
            return;
        }
        set_state(8);
    }
}
void TAdSystemFileCheckGC::enter_state_6() {  }

void TAdSystemFileCheckGC::check_player_load_result() {
    if (handle_mode_selection() != 0) {
        return;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return;
    }
    switch (check_slot_a_card_save()) {
    case 5:
        if (TAdSinglePlyChrSelectGC::all_players_loaded() != 0) {
            set_state(3);
        } else {
            set_state(8);
        }
        break;
    default:
        set_state(8);
        break;
    }
}

void TAdSystemFileCheckGC::enter_state_2() {
    if (handle_mode_selection() != 0) {
        return;
    }
    if (TAdSinglePlyChrSelectGC::load_system_file_flag() == 0xFFFFFF05) {
        return;
    }
}

void TAdSystemFileCheckGC::request_scene_change_vt() { TAdMultiChgGameModeGC::open_time_set_scene(); }
void TAdSystemFileCheckGC::enter_state_9() {  }
void TAdSystemFileCheckGC::run_state_8() { TAdMultiChgGameModeGC::open_title_scene(); }
void TAdSystemFileCheckGC::enter_state_8() {  }

void TAdSystemFileCheckGC::set_state(s32 new_state) {
    if (state != new_state) {
        state = new_state;
        TAdSystemFileCheckGCAction enter = multi_chg_game_mode_entry_table[state].enter;
        if (enter != 0) {
            (this->*enter)();
        }
    }
}

s32 TAdSystemFileCheckGC::check_system_file_status() {
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        return 1;
    }
    if (poll_memcard_result(0) != 0) {
        return 2;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        return 4;
    }
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 4;
    }
    if ((TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename) != 0) || (TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) != 0) || (TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename) != 0)) {
        return 8;
    }
    return 0;
}

void TAdSystemFileCheckGC::confirm_mode_selection() { if (((int)handle_mode_selection()) == 0) { set_state(1); } }
void TAdSystemFileCheckGC::enter_state_0() { close_window_30(); open_message_window(4); }

void TAdSystemFileCheckGC::run_task() {
    this->status = check_system_file_status();
    if (this->status & 1) {
        set_state(9);
    }
    TAdSystemFileCheckGCState *entry = &multi_chg_game_mode_entry_table[this->state];
    TAdSystemFileCheckGCAction task = entry->task;
    if (task != 0) {
        (this->*task)();
    }
}

TAdSystemFileCheckGC::~TAdSystemFileCheckGC() {
    if (message_window != NULL) { message_window->queue_destruction(); message_window = 0; }
    if (menu_window != NULL) { menu_window->queue_destruction(); menu_window = 0; }
}

TAdSystemFileCheckGC::TAdSystemFileCheckGC(TObject *object) : TObject(object) {
    state = -1;
    this->status = 1;
    language = current_language;
    message_window = 0;
    menu_window = 0;
    back = 0;
    back_text = 0;
    this->status = check_system_file_status();
    if (this->status & 1) {
        set_state(0);
    } else {
        set_state(1);
    }
    stop_audio_streams();
    set_fallback_main_phase(9);
}
