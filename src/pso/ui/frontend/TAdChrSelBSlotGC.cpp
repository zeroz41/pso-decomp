#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/vector.h"

static const ChrSelPlateLayout chr_sel_b_slot_plate_layout = { 180.0f, 38.0f, { 0xBC, 0x98, 0x36, 0x00 }, 0 };
// Plate positions of the four entries
static const CharacterSlotPosition lbl_804758E8[4] = {
    { 434.0f, 182.0f }, { 434.0f, 225.0f }, { 434.0f, 268.0f }, { 434.0f, 311.0f },
};
static const CharacterSlotPosition lbl_80475908 = { 429.0f, 156.0f };
static const CharacterSlotPosition lbl_80475910 = { 441.0f, 117.0f };
const char *TAdChrSelBSlotGC__name = "TAdChrSelBSlotGC";

struct G_8030E3BC { s32 a; s32 b; s32 c; f32 v[2]; };

struct S_8030E3BC { s32 x; s32 y; s32 state; };

G_8030E3BC chr_select_b_slot_entry;

extern "C" {
void set_entry_text__15TAdSubPlyItemGCFPvPv(void *item, G_8030E3BC *entry);
s32 poll_memcard_result(saddr);
s32 start_memcard_format(s32, s32, s32, s32, s32);
s32 are_split_screen_battle_players_tied(void *);
extern s32 TLobby__battle_ctrl_default_value;
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

G_8030E3BC *TAdChrSelBSlotGC::build_slot_entry(s32 index, s32 slot, void *pos) {
    S_8030E3BC *e = (S_8030E3BC *)TAdSinglePlyChrSelectGC__sub_801FE3E4(slot);
    chr_select_b_slot_entry.a = index;
    chr_select_b_slot_entry.b = e != NULL ? e->x : get_localized_text_entry(0x16, 0x1C);
    chr_select_b_slot_entry.c = e != NULL ? e->y + 1 : 0;
    copy_vec2((chr_select_b_slot_entry.v), pos);
    return &chr_select_b_slot_entry;
}

void TAdChrSelBSlotGC::sub_8030E458() {  }
void TAdChrSelBSlotGC::set_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        state = 0x1D;
    }
}
void TAdChrSelBSlotGC::init() {
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
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
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
    state = 0x1A;
}
void TAdChrSelBSlotGC::enter_state17() {
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
    state = 0x17;
}
void TAdChrSelBSlotGC::sub_8030E620() {  }

void TAdChrSelBSlotGC::populate_slot_entries() {
    u32 i;

    if (m_2c->is_slot_value_ready(2)) {
        slot_gc->init_slot_entry(2, (void *)&lbl_80475908);
        for (i = 0; i < 4; i++) {
            set_entry_text__15TAdSubPlyItemGCFPvPv(player_items, build_slot_entry(i, i, (void *)&lbl_804758E8[i]));
            if (is_character_transferred(i)) {
                m_34->add_plate_rect(const_cast<CharacterSlotPosition *>(&lbl_804758E8[i]));
            }
        }
        state = 0x14;
    }
}

void TAdChrSelBSlotGC::reset_plate_positions() {
    if (get_global_state() == 0x19) {
        m_2c->push_plate_position(&lbl_804758E8[0]);
        m_2c->push_plate_position(&lbl_804758E8[1]);
        m_2c->push_plate_position(&lbl_804758E8[2]);
        m_2c->push_plate_position(&lbl_804758E8[3]);
        state = 0x13;
    }
}

void TAdChrSelBSlotGC::show_pso12_character_message() {
    if (get_global_state() > 0x18) {
        if (m_64 != 0) {
            m_64->close();
            m_64 = 0;
        }
        state = 0x12;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_64 == 0)) {
        get_global_slot_data();
        m_64 = get_global_slot_data()->create_slot_message_window(1, 0x13);
    }
}
void TAdChrSelBSlotGC::show_character_data_corrupt_message() {
    if (get_global_state() > 0x17) {
        if (m_68 != 0) {
            m_68->close();
            m_68 = 0;
        }
        state = 0x11;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_68 == 0)) {
        get_global_slot_data();
        m_68 = get_global_slot_data()->create_slot_message_window(1, 0x15);
    }
}
void TAdChrSelBSlotGC::show_no_system_file_message() {
    if (get_global_state() > 0x15) {
        if (m_60 != 0) {
            m_60->close();
            m_60 = 0;
        }
        state = 0x10;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_60 == 0)) {
        get_global_slot_data();
        m_60 = get_global_slot_data()->create_slot_message_window(1, 0x11);
    }
}
void TAdChrSelBSlotGC::show_system_file_corrupt_message() {
    if (get_global_state() > 0x14) {
        if (m_5c != 0) {
            m_5c->close();
            m_5c = 0;
        }
        state = 0xF;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (m_5c == 0)) {
        get_global_slot_data();
        m_5c = get_global_slot_data()->create_slot_message_window(1, 0xF);
    }
}
void TAdChrSelBSlotGC::show_no_character_data_message() {
    if (get_global_state() > 0x13) {
        if (m_58 != 0) {
            m_58->close();
            m_58 = 0;
        }
        state = 0xE;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (m_58 == 0)) {
        get_global_slot_data();
        m_58 = get_global_slot_data()->create_slot_message_window(1, 0xD);
    }
}
void TAdChrSelBSlotGC::show_character_file_corrupt_message() {
    if (get_global_state() > 0x12) {
        if (m_54 != 0) {
            m_54->close();
            m_54 = 0;
        }
        state = 0xD;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 0xF;
        return;
    }
    if ((state_frames > 0xA) && (m_54 == 0)) {
        get_global_slot_data();
        m_54 = get_global_slot_data()->create_slot_message_window(1, 0xB);
    }
}
void TAdChrSelBSlotGC::wait_format_failed_dismiss() {
    TWindowMessageYesNo *confirm;
    TWindowBase *window;
    ControllerInputContext *context;
    confirm = m_70;
    if (confirm != 0) {
        ((TWindowSubComCard *)confirm)->close();
        m_70 = 0;
    }
    context = &controller_physical_port_bank.controllers[TAdMultiPlyChrSelectGC::get_state()->get_state_result()];
    if (TWindowShortListCtrl__check_controller_button(context, 4) != 0 || TWindowShortListCtrl__check_controller_button(context, 2) != 0 ||
        TWindowShortListCtrl__check_controller_button(context, 0x400) != 0 || TWindowShortListCtrl__check_controller_button(context, 0x200) != 0) {
        state = 1;
        return;
    }
    if (get_global_state() < 0xC) {
        window = m_40;
        if (window != 0) {
            window->close();
            m_40 = 0;
        }
        state = 1;
    }
}
void TAdChrSelBSlotGC::check_cancel_and_close() {
    TWindowBase *window;
    s32 port;
    port = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[port], 4) != 0 ||
        TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[port], 2) != 0 ||
        TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[port], 0x400) != 0 ||
        TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[port], 0x200) != 0) {
        state = 1;
        return;
    }
    if (get_global_state() < 0xC) {
        window = m_40;
        if (window != 0) {
            window->close();
            m_40 = 0;
        }
        state = 1;
    }
}

void TAdChrSelBSlotGC::update_slot_state() {
    if (m_70 != 0) {
        ((TWindowSubComCard *)m_70)->close();
        m_70 = 0;
    }
    if ((u32) (poll_memcard_result(1) + 0x10000) != 0xFFFFU) {
        if ((TAdPlayerLoadGC::check_card_result_code(1) != 0) && (poll_memcard_result(1) == 0)) {
            m_74 = get_global_slot_data()->create_formatted_window(1);
            state = 0xA;
            return;
        }
        m_7c = get_global_slot_data()->create_format_failed_window(1);
        state = 0xB;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
    }
}

void TAdChrSelBSlotGC::update_card_select() {

    if (m_6c != 0) {
        ((TWindowSubComCard *)m_6c)->close();
        m_6c = 0;
    }
    if (m_70->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)m_70)->get_slot_or_neg1()) {
        case 1:
            state = 7;
            return;
        case 0:
            if (start_memcard_format(1, 0, 0, 0, 0) == 0) {
                state = 9;
                return;
            }
            m_7c = get_global_slot_data()->create_format_failed_window(1);
            state = 0xB;
            return;
        }
    } else {
        if (((TWindowSubComCard *)m_70)->get_card_data() != 0) {
            state = 7;
            return;
        }
        if (get_global_state() < 0xC) {
            if (m_40 != 0) {
                m_40->close();
                m_40 = 0;
            }
            state = 1;
        }
    }
}

void TAdChrSelBSlotGC::show_not_formatted_message() {
    if (m_6c != 0) {
        ((TWindowSubComCard *)m_6c)->close();
        m_6c = 0;
    }
    if (m_70 != 0) {
        ((TWindowSubComCard *)m_70)->close();
        m_70 = 0;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_78 == 0) && (get_global_slot_data() != 0)) {
        m_78 = get_global_slot_data()->create_not_formatted_window(1);
    }
}

void TAdChrSelBSlotGC::update_card_confirm() {
    s32 var_r31;

    if (m_6c->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)m_6c)->get_slot_or_neg1()) {
        case 1:
            state = 7;
            return;
        case 0:
            if ((m_70 == 0) && (get_global_slot_data() != 0)) {
                if (TAdMultiPlyChrSelectGC::get_state() != NULL) {
                    var_r31 = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
                } else {
                    var_r31 = 0;
                }
                m_70 = get_global_slot_data()->open_confirm_message(1, var_r31);
                state = 8;
                return;
            }
            break;
        }
    } else {
        if (((TWindowSubComCard *)m_6c)->get_card_data() != 0) {
            state = 7;
            return;
        }
        if (get_global_state() < 0xC) {
            if (m_40 != 0) {
                m_40->close();
                m_40 = 0;
            }
            state = 1;
        }
    }
}

void TAdChrSelBSlotGC::show_format_prompt() {
    s32 var_r31;
    if (get_global_state() > 0x11) {
        if (m_50 != 0) {
            m_50->close();
            m_50 = 0;
        }
        state = 0xC;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_6c == 0) && (get_global_slot_data() != 0)) {
        if (TAdMultiPlyChrSelectGC::get_state() != NULL) {
            var_r31 = TAdMultiPlyChrSelectGC::get_state()->get_state_result();
        } else {
            var_r31 = 0;
        }
        m_6c = get_global_slot_data()->create_message_window(1, var_r31);
        state = 6;
    }
}

void TAdChrSelBSlotGC::show_card_damaged_message() {
    if (get_global_state() > 0x10) {
        if (m_4c != 0) {
            m_4c->close();
            m_4c = 0;
        }
        state = 5;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_4c == 0)) {
        get_global_slot_data();
        m_4c = get_global_slot_data()->create_slot_message_window(1, 7);
    }
}

void TAdChrSelBSlotGC::show_card_incompatible_message() {
    if (get_global_state() > 0xF) {
        if (m_48 != 0) {
            m_48->close();
            m_48 = 0;
        }
        state = 4;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_48 == 0)) {
        get_global_slot_data();
        m_48 = get_global_slot_data()->create_slot_message_window(1, 5);
    }
}

void TAdChrSelBSlotGC::show_unsupported_device_message() {
    if (get_global_state() > 0xE) {
        if (m_44 != 0) {
            m_44->close();
            m_44 = 0;
        }
        state = 3;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_44 == 0)) {
        get_global_slot_data();
        m_44 = get_global_slot_data()->create_slot_message_window(1, 3);
    }
}

void TAdChrSelBSlotGC::close_windows() {
    if (m_44 != 0) {
        m_44->close();
        m_44 = 0;
    }
    if (m_48 != 0) {
        m_48->close();
        m_48 = 0;
    }
    if (m_4c != 0) {
        m_4c->close();
        m_4c = 0;
    }
    if (m_6c != 0) {
        ((TWindowSubComCard *)m_6c)->close();
        m_6c = 0;
    }
    if (m_70 != 0) {
        ((TWindowSubComCard *)m_70)->close();
        m_70 = 0;
    }
    if (m_74 != 0) {
        m_74->close();
        m_74 = 0;
    }
    if (m_78 != 0) {
        m_78->close();
        m_78 = 0;
    }
    if (m_7c != 0) {
        m_7c->close();
        m_7c = 0;
    }
    if (m_50 != 0) {
        m_50->close();
        m_50 = 0;
    }
    if (m_54 != 0) {
        m_54->close();
        m_54 = 0;
    }
    if (m_58 != 0) {
        m_58->close();
        m_58 = 0;
    }
    if (m_5c != 0) {
        m_5c->close();
        m_5c = 0;
    }
    if (m_60 != 0) {
        m_60->close();
        m_60 = 0;
    }
    if (m_64 != 0) {
        m_64->close();
        m_64 = 0;
    }
    if (m_68 != 0) {
        m_68->close();
        m_68 = 0;
    }
    m_2c->reset_selection_slots();
    player_items->sub_802D6D88();
    m_34->clear_entries();
    slot_gc->sub_802C7498(2);
    if (get_global_state() > 0xD) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state = 2;
        return;
    }
    if (get_global_state() < 0xC) {
        if (m_40 != 0) {
            m_40->close();
            m_40 = 0;
        }
        state_frames = 0;
        state = 1;
        return;
    }
    if ((state_frames > 0xA) && (m_40 == 0)) {
        get_global_slot_data();
        m_40 = get_global_slot_data()->create_slot_message_window(1, 1);
    }
}


void TAdChrSelBSlotGC::reset_windows() {
    slot_gc->reset_all_slots();
    if (m_38 != 0) {
        m_38->queue_destruction();
        m_38 = 0;
    }
    if (m_3c != 0) {
        m_3c->queue_destruction();
        m_3c = 0;
    }
    if (m_40 != 0) {
        m_40->close();
        m_40 = 0;
    }
    if (m_44 != 0) {
        m_44->close();
        m_44 = 0;
    }
    if (m_48 != 0) {
        m_48->close();
        m_48 = 0;
    }
    if (m_4c != 0) {
        m_4c->close();
        m_4c = 0;
    }
    if (m_50 != 0) {
        m_50->close();
        m_50 = 0;
    }
    if (m_54 != 0) {
        m_54->close();
        m_54 = 0;
    }
    if (m_58 != 0) {
        m_58->close();
        m_58 = 0;
    }
    if (m_5c != 0) {
        m_5c->close();
        m_5c = 0;
    }
    if (m_60 != 0) {
        m_60->close();
        m_60 = 0;
    }
    if (m_64 != 0) {
        m_64->close();
        m_64 = 0;
    }
    if (m_68 != 0) {
        m_68->close();
        m_68 = 0;
    }
    m_2c->reset_selection_slots();
    player_items->sub_802D6D88();
    slot_gc->init_slot(1, (void *)&lbl_80475910);
    m_38 = create_draw_line_ctrl(this, 0xE, 0.0f);
    m_3c = create_draw_line_ctrl(this, 0x15, 0.0f);
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
    m_2c = new TAdPlyChrSelPlateGC(this, &chr_sel_b_slot_plate_layout);
    player_items = new TAdSubPlyItemGC(this);
    m_34 = new TAdChrSelMovePlateGC(this);
}

void TAdChrSelBSlotGC::clear_all_fields() {
    state = 0;
    prev_state = 0;
    state_frames = -1;
    slot_gc = 0;
    m_2c = NULL;
    player_items = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
}

TAdChrSelBSlotGC::~TAdChrSelBSlotGC() {
    if (m_40 != 0) {
        m_40->queue_destruction();
        m_40 = 0;
    }
    if (m_44 != 0) {
        m_44->queue_destruction();
        m_44 = 0;
    }
    if (m_48 != 0) {
        m_48->queue_destruction();
        m_48 = 0;
    }
    if (m_4c != 0) {
        m_4c->queue_destruction();
        m_4c = 0;
    }
    if (m_50 != 0) {
        m_50->queue_destruction();
        m_50 = 0;
    }
    if (m_54 != 0) {
        m_54->queue_destruction();
        m_54 = 0;
    }
    if (m_58 != 0) {
        m_58->queue_destruction();
        m_58 = 0;
    }
    if (m_5c != 0) {
        m_5c->queue_destruction();
        m_5c = 0;
    }
    if (m_60 != 0) {
        m_60->queue_destruction();
        m_60 = 0;
    }
    if (m_64 != 0) {
        m_64->queue_destruction();
        m_64 = 0;
    }
    if (m_68 != 0) {
        m_68->queue_destruction();
        m_68 = 0;
    }
    if (m_6c != 0) {
        m_6c->queue_destruction();
        m_6c = 0;
    }
    if (m_70 != 0) {
        m_70->queue_destruction();
        m_70 = 0;
    }
    if (m_74 != 0) {
        m_74->queue_destruction();
        m_74 = 0;
    }
    if (m_78 != 0) {
        m_78->queue_destruction();
        m_78 = 0;
    }
    if (m_7c != 0) {
        m_7c->queue_destruction();
        m_7c = 0;
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
    return are_split_screen_battle_players_tied(this) != 0 ? 0 : TLobby__battle_ctrl_default_value;
}
