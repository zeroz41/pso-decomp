#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/save/CardFileInfo.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdChrSelMovePlateGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_801C25B4.h"

static const ChrSelPlateLayout chr_sel_b_slot_plate_layout = { 180.0f, 38.0f, { 0xBC, 0x98, 0x36, 0x00 }, 0 };
// Plate positions of the four entries
static const CharacterSlotPosition lbl_804758E8[4] = {
    { 434.0f, 182.0f }, { 434.0f, 225.0f }, { 434.0f, 268.0f }, { 434.0f, 311.0f },
};
static const CharacterSlotPosition lbl_80475908 = { 429.0f, 156.0f };
static const CharacterSlotPosition lbl_80475910 = { 441.0f, 117.0f };
const char *TAdChrSelBSlotGC__name = "TAdChrSelBSlotGC";

struct S_8030E3BC { s32 x; s32 y; s32 state; };

PlayerSlotLabel chr_select_b_slot_entry;

extern "C" {
s32 start_memcard_format(s32, s32, s32, s32, s32);
s32 are_split_screen_battle_players_tied(void *);
extern TAdChrSelASlotGC *TAdChrSel__global_slot_data;
}

void TAdChrSelBSlotGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

s32 TAdChrSelBSlotGC::is_character_transferred(u32 i) {
    S_8030E3BC *e = (S_8030E3BC *)TAdSinglePlyChrSelectGC__sub_801FE3E4(i);
    if (e == 0) {
        return 0;
    }
    return e->state == 1 ? 1 : 0;
}

PlayerSlotLabel *TAdChrSelBSlotGC::build_slot_entry(s32 index, s32 slot, void *pos) {
    S_8030E3BC *e = (S_8030E3BC *)TAdSinglePlyChrSelectGC__sub_801FE3E4(slot);
    chr_select_b_slot_entry.slot = index;
    chr_select_b_slot_entry.name = reinterpret_cast<const char *>(
        e != NULL ? e->x : get_localized_text_entry(0x16, 0x1C));
    chr_select_b_slot_entry.level = e != NULL ? e->y + 1 : 0;
    copy_vec2(&chr_select_b_slot_entry.position, pos);
    return &chr_select_b_slot_entry;
}

void TAdChrSelBSlotGC::sub_8030E458() {  }
void TAdChrSelBSlotGC::set_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        state = 0x1D;
    }
}
void TAdChrSelBSlotGC::init() {
    TAdSinglePlyChrSelectGC::encrypt_and_save();
    TAdSinglePlyChrSelectGC::open_confirm_window();
    state = 0x1C;
}
void TAdChrSelBSlotGC::reset_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        state = 0;
    }
}
void TAdChrSelBSlotGC::reset_slot_state() {
    if (get_global_state() <= 0xD) {
        state_frames = 0;
        state = 1;
    }
}
void TAdChrSelBSlotGC::sub_8030E550() {  }
void TAdChrSelBSlotGC::update_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if ((u32) (TAdPlayerLoadGC::get_load_result(1) + 0x10000) == 0xFF83U) {
            state = 0x18;
            return;
        }
        state = 0x19;
    }
}
void TAdChrSelBSlotGC::set_state_confirm() {
    TAdSinglePlyChrSelectGC::encrypt_and_save();
    TAdSinglePlyChrSelectGC::open_confirm_window();
    state = 0x1A;
}
void TAdChrSelBSlotGC::enter_state17() {
    TAdSinglePlyChrSelectGC::encrypt_and_save();
    TAdSinglePlyChrSelectGC::open_confirm_window();
    state = 0x17;
}
void TAdChrSelBSlotGC::sub_8030E620() {  }

void TAdChrSelBSlotGC::populate_slot_entries() {
    u32 i;

    if (plate->is_slot_value_ready(2)) {
        slot_gc->init_slot_entry(2, (void *)&lbl_80475908);
        for (i = 0; i < 4; i++) {
            set_entry_text__15TAdSubPlyItemGCFPvPv(player_items, build_slot_entry(i, i, (void *)&lbl_804758E8[i]));
            if (is_character_transferred(i)) {
                move_plate->add_plate_rect(const_cast<CharacterSlotPosition *>(&lbl_804758E8[i]));
            }
        }
        state = 0x14;
    }
}

void TAdChrSelBSlotGC::reset_plate_positions() {
    if (get_global_state() == 0x19) {
        plate->push_plate_position(&lbl_804758E8[0]);
        plate->push_plate_position(&lbl_804758E8[1]);
        plate->push_plate_position(&lbl_804758E8[2]);
        plate->push_plate_position(&lbl_804758E8[3]);
        state = 0x13;
    }
}

void TAdChrSelBSlotGC::show_pso12_character_message() {
    if (get_global_state() > 0x18) {
        if (wait_message[9] != NULL) {
            wait_message[9]->close();
            wait_message[9] = NULL;
        }
        state = 0x12;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[9] == NULL)) {
        get_global_slot_data();
        wait_message[9] = get_global_slot_data()->create_slot_message_window(1, 0x13);
    }
}
void TAdChrSelBSlotGC::show_character_data_corrupt_message() {
    if (get_global_state() > 0x17) {
        if (wait_message[10] != NULL) {
            wait_message[10]->close();
            wait_message[10] = NULL;
        }
        state = 0x11;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[10] == NULL)) {
        get_global_slot_data();
        wait_message[10] = get_global_slot_data()->create_slot_message_window(1, 0x15);
    }
}
void TAdChrSelBSlotGC::show_no_system_file_message() {
    if (get_global_state() > 0x15) {
        if (wait_message[8] != NULL) {
            wait_message[8]->close();
            wait_message[8] = NULL;
        }
        state = 0x10;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[8] == NULL)) {
        get_global_slot_data();
        wait_message[8] = get_global_slot_data()->create_slot_message_window(1, 0x11);
    }
}
void TAdChrSelBSlotGC::show_system_file_corrupt_message() {
    if (get_global_state() > 0x14) {
        if (wait_message[7] != NULL) {
            wait_message[7]->close();
            wait_message[7] = NULL;
        }
        state = 0xF;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[7] == NULL)) {
        get_global_slot_data();
        wait_message[7] = get_global_slot_data()->create_slot_message_window(1, 0xF);
    }
}
void TAdChrSelBSlotGC::show_no_character_data_message() {
    if (get_global_state() > 0x13) {
        if (wait_message[6] != NULL) {
            wait_message[6]->close();
            wait_message[6] = NULL;
        }
        state = 0xE;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[6] == NULL)) {
        get_global_slot_data();
        wait_message[6] = get_global_slot_data()->create_slot_message_window(1, 0xD);
    }
}
void TAdChrSelBSlotGC::show_character_file_corrupt_message() {
    if (get_global_state() > 0x12) {
        if (wait_message[5] != NULL) {
            wait_message[5]->close();
            wait_message[5] = NULL;
        }
        state = 0xD;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[5] == NULL)) {
        get_global_slot_data();
        wait_message[5] = get_global_slot_data()->create_slot_message_window(1, 0xB);
    }
}
void TAdChrSelBSlotGC::wait_format_failed_dismiss() {
    TWindowMessageYesNo *confirm;
    TWindowBase *window;
    ControllerInputContext *context;
    confirm = format_confirm;
    if (confirm != NULL) {
        confirm->close();
        format_confirm = NULL;
    }
    context = &controller_physical_port_bank.controllers[TAdMultiPlyChrSelectGC::get_state()->get_state_result()];
    if (test_pressed_buttons_packed(context, 4) != 0 || test_pressed_buttons_packed(context, 2) != 0 ||
        test_pressed_buttons_packed(context, 0x400) != 0 || test_pressed_buttons_packed(context, 0x200) != 0) {
        state = 1;
        return;
    }
    if (get_global_state() < 0xC) {
        window = wait_message[0];
        if (window != NULL) {
            window->close();
            wait_message[0] = NULL;
        }
        state = 1;
    }
}
void TAdChrSelBSlotGC::check_cancel_and_close() {
    TWindowBase *window;
    s32 port;
    port = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 4) != 0 ||
        test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 2) != 0 ||
        test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 0x400) != 0 ||
        test_pressed_buttons_packed(&controller_physical_port_bank.controllers[port], 0x200) != 0) {
        state = 1;
        return;
    }
    if (get_global_state() < 0xC) {
        window = wait_message[0];
        if (window != NULL) {
            window->close();
            wait_message[0] = NULL;
        }
        state = 1;
    }
}

void TAdChrSelBSlotGC::update_slot_state() {
    if (format_confirm != NULL) {
        format_confirm->close();
        format_confirm = NULL;
    }
    if ((u32) (poll_memcard_result(1) + 0x10000) != 0xFFFFU) {
        if ((TAdPlayerLoadGC::check_card_result_code(1) != 0) && (poll_memcard_result(1) == 0)) {
            formatted_message = get_global_slot_data()->create_formatted_window(1);
            state = 0xA;
            return;
        }
        format_failed_message = get_global_slot_data()->create_format_failed_window(1);
        state = 0xB;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
    }
}

void TAdChrSelBSlotGC::update_card_select() {

    if (format_prompt != NULL) {
        format_prompt->close();
        format_prompt = NULL;
    }
    if (format_confirm->is_child_visible() != 0) {
        switch (format_confirm->get_selected_value()) {
        case 1:
            state = 7;
            return;
        case 0:
            if (start_memcard_format(1, 0, 0, 0, 0) == 0) {
                state = 9;
                return;
            }
            format_failed_message = get_global_slot_data()->create_format_failed_window(1);
            state = 0xB;
            return;
        }
    } else {
        if (format_confirm->is_cancelled() != 0) {
            state = 7;
            return;
        }
        if (get_global_state() < 0xC) {
            if (wait_message[0] != NULL) {
                wait_message[0]->close();
                wait_message[0] = NULL;
            }
            state = 1;
        }
    }
}

void TAdChrSelBSlotGC::show_not_formatted_message() {
    if (format_prompt != NULL) {
        format_prompt->close();
        format_prompt = NULL;
    }
    if (format_confirm != NULL) {
        format_confirm->close();
        format_confirm = NULL;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (not_formatted_message == NULL) && (get_global_slot_data() != 0)) {
        not_formatted_message = get_global_slot_data()->create_not_formatted_window(1);
    }
}

void TAdChrSelBSlotGC::update_card_confirm() {
    s32 var_r31;

    if (format_prompt->is_child_visible() != 0) {
        switch (format_prompt->get_selected_value()) {
        case 1:
            state = 7;
            return;
        case 0:
            if ((format_confirm == NULL) && (get_global_slot_data() != 0)) {
                if (TAdMultiPlyChrSelectGC::get_state() != NULL) {
                    var_r31 = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
                } else {
                    var_r31 = 0;
                }
                format_confirm = get_global_slot_data()->open_confirm_message(1, var_r31);
                state = 8;
                return;
            }
            break;
        }
    } else {
        if (format_prompt->is_cancelled() != 0) {
            state = 7;
            return;
        }
        if (get_global_state() < 0xC) {
            if (wait_message[0] != NULL) {
                wait_message[0]->close();
                wait_message[0] = NULL;
            }
            state = 1;
        }
    }
}

void TAdChrSelBSlotGC::show_format_prompt() {
    s32 var_r31;
    if (get_global_state() > 0x11) {
        if (wait_message[4] != NULL) {
            wait_message[4]->close();
            wait_message[4] = NULL;
        }
        state = 0xC;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (format_prompt == NULL) && (get_global_slot_data() != 0)) {
        if (TAdMultiPlyChrSelectGC::get_state() != NULL) {
            var_r31 = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
        } else {
            var_r31 = 0;
        }
        format_prompt = get_global_slot_data()->create_message_window(1, var_r31);
        state = 6;
    }
}

void TAdChrSelBSlotGC::show_card_damaged_message() {
    if (get_global_state() > 0x10) {
        if (wait_message[3] != NULL) {
            wait_message[3]->close();
            wait_message[3] = NULL;
        }
        state = 5;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[3] == NULL)) {
        get_global_slot_data();
        wait_message[3] = get_global_slot_data()->create_slot_message_window(1, 7);
    }
}

void TAdChrSelBSlotGC::show_card_incompatible_message() {
    if (get_global_state() > 0xF) {
        if (wait_message[2] != NULL) {
            wait_message[2]->close();
            wait_message[2] = NULL;
        }
        state = 4;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[2] == NULL)) {
        get_global_slot_data();
        wait_message[2] = get_global_slot_data()->create_slot_message_window(1, 5);
    }
}

void TAdChrSelBSlotGC::show_unsupported_device_message() {
    if (get_global_state() > 0xE) {
        if (wait_message[1] != NULL) {
            wait_message[1]->close();
            wait_message[1] = NULL;
        }
        state = 3;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[1] == NULL)) {
        get_global_slot_data();
        wait_message[1] = get_global_slot_data()->create_slot_message_window(1, 3);
    }
}

void TAdChrSelBSlotGC::close_windows() {
    if (wait_message[1] != NULL) {
        wait_message[1]->close();
        wait_message[1] = NULL;
    }
    if (wait_message[2] != NULL) {
        wait_message[2]->close();
        wait_message[2] = NULL;
    }
    if (wait_message[3] != NULL) {
        wait_message[3]->close();
        wait_message[3] = NULL;
    }
    if (format_prompt != NULL) {
        format_prompt->close();
        format_prompt = NULL;
    }
    if (format_confirm != NULL) {
        format_confirm->close();
        format_confirm = NULL;
    }
    if (formatted_message != NULL) {
        formatted_message->close();
        formatted_message = NULL;
    }
    if (not_formatted_message != NULL) {
        not_formatted_message->close();
        not_formatted_message = NULL;
    }
    if (format_failed_message != NULL) {
        format_failed_message->close();
        format_failed_message = NULL;
    }
    if (wait_message[4] != NULL) {
        wait_message[4]->close();
        wait_message[4] = NULL;
    }
    if (wait_message[5] != NULL) {
        wait_message[5]->close();
        wait_message[5] = NULL;
    }
    if (wait_message[6] != NULL) {
        wait_message[6]->close();
        wait_message[6] = NULL;
    }
    if (wait_message[7] != NULL) {
        wait_message[7]->close();
        wait_message[7] = NULL;
    }
    if (wait_message[8] != NULL) {
        wait_message[8]->close();
        wait_message[8] = NULL;
    }
    if (wait_message[9] != NULL) {
        wait_message[9]->close();
        wait_message[9] = NULL;
    }
    if (wait_message[10] != NULL) {
        wait_message[10]->close();
        wait_message[10] = NULL;
    }
    plate->reset_selection_slots();
    player_items->sub_802D6D88();
    move_plate->clear_entries();
    slot_gc->sub_802C7498(2);
    if (get_global_state() > 0xD) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state = 2;
        return;
    }
    if (get_global_state() < 0xC) {
        if (wait_message[0] != NULL) {
            wait_message[0]->close();
            wait_message[0] = NULL;
        }
        state_frames = 0;
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (wait_message[0] == NULL)) {
        get_global_slot_data();
        wait_message[0] = get_global_slot_data()->create_slot_message_window(1, 1);
    }
}


void TAdChrSelBSlotGC::reset_windows() {
    slot_gc->reset_all_slots();
    if (draw_line[0] != NULL) {
        draw_line[0]->queue_destruction();
        draw_line[0] = NULL;
    }
    if (draw_line[1] != NULL) {
        draw_line[1]->queue_destruction();
        draw_line[1] = NULL;
    }
    if (wait_message[0] != NULL) {
        wait_message[0]->close();
        wait_message[0] = NULL;
    }
    if (wait_message[1] != NULL) {
        wait_message[1]->close();
        wait_message[1] = NULL;
    }
    if (wait_message[2] != NULL) {
        wait_message[2]->close();
        wait_message[2] = NULL;
    }
    if (wait_message[3] != NULL) {
        wait_message[3]->close();
        wait_message[3] = NULL;
    }
    if (wait_message[4] != NULL) {
        wait_message[4]->close();
        wait_message[4] = NULL;
    }
    if (wait_message[5] != NULL) {
        wait_message[5]->close();
        wait_message[5] = NULL;
    }
    if (wait_message[6] != NULL) {
        wait_message[6]->close();
        wait_message[6] = NULL;
    }
    if (wait_message[7] != NULL) {
        wait_message[7]->close();
        wait_message[7] = NULL;
    }
    if (wait_message[8] != NULL) {
        wait_message[8]->close();
        wait_message[8] = NULL;
    }
    if (wait_message[9] != NULL) {
        wait_message[9]->close();
        wait_message[9] = NULL;
    }
    if (wait_message[10] != NULL) {
        wait_message[10]->close();
        wait_message[10] = NULL;
    }
    plate->reset_selection_slots();
    player_items->sub_802D6D88();
    slot_gc->init_slot(1, (void *)&lbl_80475910);
    draw_line[0] = create_draw_line_ctrl(this, 0xE, 0.0f);
    draw_line[1] = create_draw_line_ctrl(this, 0x15, 0.0f);
    state_frames = -1;
    state = 1;
}

int TAdChrSelBSlotGC__global_state;

void TAdChrSelBSlotGC::run_task() {
    if (state < 0 || state >= 30) {
        state = 1;
    }
    prev_state = state;
    if (get_global_state() <= 0xD && state > 1) {
        state = 1;
    }
    static void (TAdChrSelBSlotGC::*handlers[30])() = {
        &TAdChrSelBSlotGC::reset_windows,
        &TAdChrSelBSlotGC::close_windows,
        &TAdChrSelBSlotGC::show_unsupported_device_message,
        &TAdChrSelBSlotGC::show_card_incompatible_message,
        &TAdChrSelBSlotGC::show_card_damaged_message,
        &TAdChrSelBSlotGC::show_format_prompt,
        &TAdChrSelBSlotGC::update_card_confirm,
        &TAdChrSelBSlotGC::show_not_formatted_message,
        &TAdChrSelBSlotGC::update_card_select,
        &TAdChrSelBSlotGC::update_slot_state,
        &TAdChrSelBSlotGC::check_cancel_and_close,
        &TAdChrSelBSlotGC::wait_format_failed_dismiss,
        &TAdChrSelBSlotGC::show_character_file_corrupt_message,
        &TAdChrSelBSlotGC::show_no_character_data_message,
        &TAdChrSelBSlotGC::show_system_file_corrupt_message,
        &TAdChrSelBSlotGC::show_no_system_file_message,
        &TAdChrSelBSlotGC::show_character_data_corrupt_message,
        &TAdChrSelBSlotGC::show_pso12_character_message,
        &TAdChrSelBSlotGC::reset_plate_positions,
        &TAdChrSelBSlotGC::populate_slot_entries,
        &TAdChrSelBSlotGC::sub_8030E620,
        &TAdChrSelBSlotGC::enter_state17,
        &TAdChrSelBSlotGC::set_state_confirm,
        &TAdChrSelBSlotGC::update_load_state,
        &TAdChrSelBSlotGC::sub_8030E550,
        &TAdChrSelBSlotGC::reset_slot_state,
        &TAdChrSelBSlotGC::reset_load_state,
        &TAdChrSelBSlotGC::init,
        &TAdChrSelBSlotGC::set_load_state,
        &TAdChrSelBSlotGC::sub_8030E458,
    };
    (this->*handlers[state])();
    if (state != prev_state) {
        state_frames = 0;
    }
    state_frames++;
}

void TAdChrSelBSlotGC::create_children() {
    slot_gc = new TAdChrSelSlotGC(this);
    plate = new TAdPlyChrSelPlateGC(this, &chr_sel_b_slot_plate_layout);
    player_items = new TAdSubPlyItemGC(this);
    move_plate = new TAdChrSelMovePlateGC(this);
}

void TAdChrSelBSlotGC::clear_all_fields() {
    state = 0;
    prev_state = 0;
    state_frames = -1;
    slot_gc = NULL;
    plate = NULL;
    player_items = NULL;
    move_plate = NULL;
    draw_line[0] = NULL;
    draw_line[1] = NULL;
    wait_message[0] = NULL;
    wait_message[1] = NULL;
    wait_message[2] = NULL;
    wait_message[3] = NULL;
    wait_message[4] = NULL;
    wait_message[5] = NULL;
    wait_message[6] = NULL;
    wait_message[7] = NULL;
    wait_message[8] = NULL;
    wait_message[9] = NULL;
    wait_message[10] = NULL;
    format_prompt = NULL;
    format_confirm = NULL;
    formatted_message = NULL;
    not_formatted_message = NULL;
    format_failed_message = NULL;
}

TAdChrSelBSlotGC::~TAdChrSelBSlotGC() {
    if (wait_message[0] != NULL) {
        wait_message[0]->queue_destruction();
        wait_message[0] = NULL;
    }
    if (wait_message[1] != NULL) {
        wait_message[1]->queue_destruction();
        wait_message[1] = NULL;
    }
    if (wait_message[2] != NULL) {
        wait_message[2]->queue_destruction();
        wait_message[2] = NULL;
    }
    if (wait_message[3] != NULL) {
        wait_message[3]->queue_destruction();
        wait_message[3] = NULL;
    }
    if (wait_message[4] != NULL) {
        wait_message[4]->queue_destruction();
        wait_message[4] = NULL;
    }
    if (wait_message[5] != NULL) {
        wait_message[5]->queue_destruction();
        wait_message[5] = NULL;
    }
    if (wait_message[6] != NULL) {
        wait_message[6]->queue_destruction();
        wait_message[6] = NULL;
    }
    if (wait_message[7] != NULL) {
        wait_message[7]->queue_destruction();
        wait_message[7] = NULL;
    }
    if (wait_message[8] != NULL) {
        wait_message[8]->queue_destruction();
        wait_message[8] = NULL;
    }
    if (wait_message[9] != NULL) {
        wait_message[9]->queue_destruction();
        wait_message[9] = NULL;
    }
    if (wait_message[10] != NULL) {
        wait_message[10]->queue_destruction();
        wait_message[10] = NULL;
    }
    if (format_prompt != NULL) {
        format_prompt->queue_destruction();
        format_prompt = NULL;
    }
    if (format_confirm != NULL) {
        format_confirm->queue_destruction();
        format_confirm = NULL;
    }
    if (formatted_message != NULL) {
        formatted_message->queue_destruction();
        formatted_message = NULL;
    }
    if (not_formatted_message != NULL) {
        not_formatted_message->queue_destruction();
        not_formatted_message = NULL;
    }
    if (format_failed_message != NULL) {
        format_failed_message->queue_destruction();
        format_failed_message = NULL;
    }
}

TAdChrSelBSlotGC::TAdChrSelBSlotGC(TObject *parent) : TObject(parent) {
    m_name = TAdChrSelBSlotGC__name;
    clear_all_fields();
    create_children();
}

TAdChrSelBSlotGC *TAdChrSelBSlotGC::create(void *parent) {
    return new TAdChrSelBSlotGC((TObject *)parent);
}

int TAdChrSelBSlotGC::get_global_state() {  return TAdChrSelBSlotGC__global_state; }

TAdChrSelASlotGC *TAdChrSelBSlotGC::get_global_slot_data() { return TAdChrSel__global_slot_data; }
s32 TLobby::get_battle_ctrl_default() {
    return are_split_screen_battle_players_tied(this) != 0 ? 0 : battle_ctrl_default_value;
}
