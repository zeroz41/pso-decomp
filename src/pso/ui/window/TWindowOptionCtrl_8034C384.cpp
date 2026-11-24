#pragma defer_codegen on

#include "pso/system/SoundEffect.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/ui/window/TWindowOptionCtrl_8034C384.h"
#include "pso/ui/window/TSnapshotFileSetup.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"

extern "C" {
saddr get_localized_text_entry(s32);
s32 start_memcard_format(int, int, int, int, int);
extern s32 local_client_id;
extern saddr tl_01;

TSnapshotFileSetup::TSnapshotFileSetup(TObject *parent) : TObject(parent) {
    this->state = 0;
    this->flags = 0;
    this->result = 0;
    this->shown_message = 14;
    this->message_window = 0;
}

TSnapshotFileSetup::~TSnapshotFileSetup() {
    if ((void *)this->message_window != NULL) { ((TWindowMessageYesNo *)this->message_window)->close(); this->message_window = 0; }
}

void TSnapshotFileSetup::run_task() {
    s32 state;
    s32 temp_r0_2;
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
                open_confirm_dialog((int) (((s32 (*)(int, int)) get_localized_text_entry)(0x16, 5)), 0);
            }
            break;
        }
    }
    temp_r0_2 = this->state;
    {
        switch (temp_r0_2) {
        case 0:
        case 1:
            set_option_and_confirm(0, 1);
            this->state = 2;
        case 2:
            if (((TWindowMessageYesNo *)(this->message_window))->is_cancelled() != 0) {
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->message_window))->is_child_visible() != 0) {
                if (((TWindowMessageYesNo *)(this->message_window))->get_selected_value() == 0) {
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
            if (((TWindowMessageYesNo *)(this->message_window))->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->message_window))->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (((TWindowMessageYesNo *)(this->message_window))->get_selected_value() == 0) {
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
            if (((TWindowMessageYesNo *)(this->message_window))->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->message_window))->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (((TWindowMessageYesNo *)(this->message_window))->get_selected_value() == 0) {
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
            if (((TWindowMessageYesNo *)(this->message_window))->is_cancelled() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                this->result = 2;
                this->state = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->message_window))->is_child_visible() != 0) {
                this->flags = (s32) (this->flags & 0xFFFFFFFD);
                if (((TWindowMessageYesNo *)(this->message_window))->get_selected_value() == 0) {
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

void TSnapshotFileSetup::render() { if (this->state == 6) { TLobby::update_pulse_colors((saddr)((void*)1)); TLobby__sub_80338534(); } }

void TSnapshotFileSetup::set_option_and_confirm(s32 arg1, s32 arg2) {
    if (arg1 != (s32) this->shown_message) {
        this->shown_message = arg1;
        open_confirm_dialog((s32)(get_localized_text_entry(0x24)), arg2);
    }
}

void TSnapshotFileSetup::open_confirm_dialog(s32 message, s32 arg2) {
    if ((uaddr) this->message_window != 0U) {
        ((TWindowMessageYesNo *)(this->message_window))->close();
        this->message_window = 0U;
    }
    this->message_window = (uaddr)TWindowMessageYesNo::create((void *)(tl_01), local_client_id, 0, 0);
    if (arg2 != 0) {
        ((TWindowMessageYesNo *)this->message_window)->open_yes_no_prompt_with_text((s32)message, (saddr)TWindowOptionCtrl::get_option_entry(0xCF), 470.0f);
        return;
    }
    initialize_option_dialog((void *)this->message_window, message, ((saddr)TWindowOptionCtrl::get_option_entry(0xCF)), 470.0f);
}

s32 TSnapshotFileSetup::get_result() { return this->result; }

void TLobby__sub_8034C3A4(void* p) { ((TLobby *)p)->reset_info_board(); }

void TLobby__sub_8034C384(void* p) { ((TLobby *)p)->reset_info_board(); }
}
