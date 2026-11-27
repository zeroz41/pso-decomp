#pragma defer_codegen on

#include "pso/system/SoundEffect.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/network/client_id.h"
#include "pso/ui/LoadingInfoIcon.h"
#include "pso/ui/window/TSnapshotFileSetup.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_MemCard.h"
#include "pso/network/InfoBoardRequests.h"

extern "C" {

TSnapshotFileSetup::TSnapshotFileSetup(TObject *parent) : TObject(parent) {
    this->state = 0;
    this->flags = 0;
    this->result = 0;
    this->shown_message = 14;
    this->message_window = NULL;
}

TSnapshotFileSetup::~TSnapshotFileSetup() {
    if (this->message_window != NULL) { this->message_window->close(); this->message_window = NULL; }
}

void TSnapshotFileSetup::run_task() {
    s32 state;
    s32 current_state;
    if (!(this->flags & 1)) {
        switch (TObjBoss2Tunnel::save_snapshot()) {
        case 1:
            this->flags = (s32) (this->flags | 2);
            this->result = 1;
            this->state = 0x10;
            break;
        case -4:
            if (this->flags & 2) {
                this->result = 0;
                this->state = 3;
            }
            if (this->state == 4) {
                set_option_and_confirm(1, 0);
            }
            break;
        case -3:
            if (this->state == 4) {
                set_option_and_confirm(2, 1);
                this->state = 0xB;
            }
            break;
        case -2:
            if (this->state == 4) {
                set_option_and_confirm(3, 0);
            }
            break;
        case -9:
            state = this->state;
            if ((state == 4) || (state == 0)) {
                set_option_and_confirm(7, 1);
                this->state = 9;
            }
            break;
        case -1:
            if (this->state == 4) {
                set_option_and_confirm(4, 1);
                this->state = 7;
            }
            break;
        case -7:
            if (this->state == 4) {
                set_option_and_confirm(5, 1);
                this->state = 7;
            }
            break;
        case 0:
            if (this->state == 4) {
                set_option_and_confirm(6, 0);
                this->state = 5;
            }
            break;
        case -6:
            if (this->state == 4) {
                set_option_and_confirm(0xA, 0);
            }
            break;
        case -8:
            if ((this->state == 4) && ((s32) this->shown_message != 0xF)) {
                this->shown_message = 0xF;
                open_confirm_dialog(get_localized_text_entry(0x16, 5), 0);
            }
            break;
        }
    }
    current_state = this->state;
    {
        switch (current_state) {
        case 0:
        case 1:
            set_option_and_confirm(0, 1);
            this->state = 2;
        case 2:
            if (this->message_window->is_cancelled() != 0) {
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (this->message_window->is_child_visible() != 0) {
                if (this->message_window->get_selected_value() == 0) {
                    this->state = 3;
                    return;
                }
                this->result = 2;
                this->state = 0x10;
                return;
            }
            break;
        case 3:
            this->flags = (s32) (this->flags & 0xFFFFFFFD);
            this->state = 4;
        case 4:
            if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            break;
        case 5:
            this->flags = (s32) (this->flags | 1);
            TObjBoss2Tunnel::save_snapshot_to_card();
            this->state = 6;
        case 6:
            if (TObjBoss2Tunnel::load_snapshot() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFE);
                this->state = 3;
                return;
            }
            break;
        case 7:
            this->flags = (s32) (this->flags | 2);
            this->state = 8;
        case 8:
            if (this->message_window->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (this->message_window->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (this->message_window->get_selected_value() == 0) {
                    this->result = 3;
                    this->state = 0x10;
                    return;
                }
                this->result = 2;
                this->state = 0x10;
                return;
            }
            break;
        case 9:
            this->flags = (s32) (this->flags | 2);
            this->state = 0xA;
        case 10:
            if (this->message_window->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (this->message_window->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (this->message_window->get_selected_value() == 0) {
                    TObjBoss2Tunnel::poll_pso_screen_load();
                    this->result = 2;
                    this->state = 0x10;
                    return;
                }
                this->result = 2;
                this->state = 0x10;
                return;
            }
            break;
        case 11:
            this->flags = (s32) (this->flags | 2);
            this->state = 0xC;
        case 12:
            if (this->message_window->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (this->message_window->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (this->message_window->get_selected_value() == 0) {
                    this->state = 0xD;
                    return;
                }
                this->result = 2;
                this->state = 0x10;
                return;
            }
            break;
        case 13:
            if (start_memcard_format(1, 0, 0, 0, 0) == 0) {
                set_option_and_confirm(8, 0);
                this->flags = (s32) (this->flags | 1);
                this->state = 0xE;
                return;
            }
            set_option_and_confirm(9, 0);
            this->state = 0xF;
            return;
        case 14:
            if (poll_memcard_result(1) == 0) {
                if ((u32) TAdPlayerLoadGC::get_load_result(1) == 0xFFFFFF81U) {
                    set_option_and_confirm(9, 0);
                    this->state = 0xF;
                    return;
                }
                this->flags = (s32) (this->flags & 0xFFFFFFFE);
                this->state = 0;
                return;
            }
            break;
        case 15:
            if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 3;
            }
            break;
        case 16:
            break;
        }
    }
}

void TSnapshotFileSetup::render() { if (this->state == 6) { update_pulse_colors((saddr)((void*)1)); draw_loading_overlay(); } }

void TSnapshotFileSetup::set_option_and_confirm(s32 option, s32 yes_no) {
    if (option != (s32) this->shown_message) {
        this->shown_message = option;
        open_confirm_dialog(get_localized_text_entry(0x24, option), yes_no);
    }
}

void TSnapshotFileSetup::open_confirm_dialog(const char *message, s32 yes_no) {
    if (this->message_window != NULL) {
        this->message_window->close();
        this->message_window = NULL;
    }
    this->message_window = TWindowMessageYesNo::create((TObject *)tl_01, local_client_id, 0, 0);
    if (yes_no != 0) {
        this->message_window->open_yes_no_prompt_with_text(message, TWindowOptionCtrl::get_option_entry(0xCF), 470.0f);
        return;
    }
    initialize_option_dialog(this->message_window, message, TWindowOptionCtrl::get_option_entry(0xCF), 470.0f);
}

s32 TSnapshotFileSetup::get_result() { return this->result; }
}

void reset_info_board_on_load() { reset_info_board(); }

void reset_info_board_on_unload() { reset_info_board(); }
