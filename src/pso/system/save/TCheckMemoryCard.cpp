#include "types.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8033A8EC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby_80132ED0.h"

extern "C" {
s32 TAdPlayerLoadGC__sub_801E1B50(s32 chan);
TWindowMessage *update_window_mode_from_progress__6TLobbyFPv(const f32 *pos, const f32 *size);
TWindowMenu *check_room_seq_4__16TAdChrSelASlotGCFl(const f32 *pos, s32 arg1);
s32 align_menu_entry_positions(TWindowMenu *menu);
}

// Text of one card message: the entry is replaced by keyboard_entry while the keyboard controller is in use.
struct CheckMemoryCardText {
    s32 group;
    s32 entry;
    s32 keyboard_entry;
};

// One entry per state: enter is called by set_state, run by run_task every frame.
struct CheckMemoryCardState {
    void (TCheckMemoryCard::*enter)();
    void (TCheckMemoryCard::*run)();
};

const char *TCheckMemoryCard__name = "TCheckMemoryCard";

static const f32 check_memory_card_message_pos[2] = {46.0f, 131.0f};
static const f32 check_memory_card_message_size[2] = {548.0f, 220.0f};
static const CheckMemoryCardText check_memory_card_text[1] = {
    {0xB, 0x62, 0xA},
};
static const f32 check_memory_card_menu_pos[2] = {
    20.0f + check_memory_card_message_pos[0],
    10.0f + (check_memory_card_message_pos[1] + check_memory_card_message_size[1]),
};
static const f32 check_memory_card_menu_width = check_memory_card_message_size[0] - 40.0f;
static CheckMemoryCardState check_memory_card_state_table[4] = {
    {&TCheckMemoryCard::close_and_update_display, &TCheckMemoryCard::update_display_state},
    {&TCheckMemoryCard::enter_message_state, &TCheckMemoryCard::run_message_state},
    {&TCheckMemoryCard::enter_poll_state, &TCheckMemoryCard::poll_card_status},
    {&TCheckMemoryCard::enter_prompt_state, &TCheckMemoryCard::handle_menu_selection},
};

s32 TCheckMemoryCard::check_player_data() {
    s32 flags = 0;
    switch (TAdSinglePlyChrSelectGC::verify_card_player_data()) {
    case -2:
        flags |= 0x30;
        break;
    case -3:
    case -1:
        flags |= 0x10;
        break;
    }
    return flags;
}

s32 TCheckMemoryCard::check_card() {
    s32 flags;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        status_checked = 0;
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        status_checked = 0;
        return 4;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        busy_count++;
        status_checked = 0;
        return 2;
    }
    busy_count = 0;
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        status_checked = 0;
        return 8;
    }
    if (status_checked != 0) {
        return status;
    }
    status_checked = 1;
    flags = check_player_data();
    if (system_file_only != 0) {
        if (TAdSinglePlyChrSelectGC__sub_8033BA84(0) == 0) {
            flags |= 0x10;
        }
    } else if (TAdSinglePlyChrSelectGC::has_no_save_files(0) == 0) {
        flags |= 0x10;
    }
    return flags;
}

void TCheckMemoryCard::update_card_display(s32 kind, s32 sel, s32 sub_entry, s32 alt_sub_entry) {
    close_windows();
    create_card_message(kind, sel, sub_entry, alt_sub_entry);
}

void TCheckMemoryCard::recreate_message_and_menu(u32 text, s32 sel, u32 first_entry, u32 second_entry) {
    close_windows();
    create_message_and_menu(text, sel, first_entry, second_entry);
}

void TCheckMemoryCard::create_card_message(s32 kind, s32 sel, s32 sub_entry, s32 alt_sub_entry) {
    s32 text;
    s32 sub_text;
    s32 group;
    s32 entry;

    group = check_memory_card_text[kind].group;
    entry = check_memory_card_text[kind].entry;
    sub_text = 0;

    if (use_main_ctrl != 0) {
        entry = 0x6E;
    }
    if (TKeyBoardControl__sub_8000F8EC() == 0xF) {
        entry = check_memory_card_text[kind].keyboard_entry;
    }
    text = get_localized_text_entry(group, entry);
    if (sub_entry >= 0) {
        sub_text = get_localized_text_entry(0x1C, sub_entry);
    }
    if (alt_sub_entry >= 0) {
        sub_text = get_localized_text_entry(0x1C, alt_sub_entry);
    }
    create_message_and_menu(text, sel, sub_text, 0);
}

// sel -1: message only; -2: one menu entry; otherwise two entries with entry sel selected.
void TCheckMemoryCard::create_message_and_menu(u32 text, s32 sel, u32 first_entry, u32 second_entry) {
    u32 entry_text;

    if (message_window != NULL || menu_window != NULL) {
        return;
    }
    if (use_main_ctrl != 0) {
        message_window = (TWindowMessage *)TWindowMessage::create((s32)check_memory_card_message_pos, check_memory_card_message_size, 1, 4);
    } else {
        message_window = update_window_mode_from_progress__6TLobbyFPv(check_memory_card_message_pos, check_memory_card_message_size);
    }
    if (message_window == NULL) {
        return;
    }
    if (message_window != NULL && use_main_ctrl != 0) {
        ((TWindowSubComCard *)message_window)->reparent_to_main_ctrl();
    }
    if (text != 0) {
        message_window->append_line(text, 3);
    }
    message_window->complete_reveal();
    if (sel == -1) {
        return;
    }
    if (use_main_ctrl != 0) {
        menu_window = (TWindowMenu *)create_window_menu((s32)check_memory_card_menu_pos, 2, 4);
    } else {
        menu_window = check_room_seq_4__16TAdChrSelASlotGCFl(check_memory_card_menu_pos, 2);
    }
    if (message_window == NULL) {
        return;
    }
    if (menu_window != NULL && use_main_ctrl != 0) {
        ((TWindowSubComCard *)menu_window)->reparent_to_main_ctrl();
    }
    entry_text = first_entry;
    if (first_entry == 0) {
        entry_text = (u32)TWindowSubStatusDisp::get_message_10(0x5B);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(menu_window, entry_text, 5, 0);
    if (sel != -2) {
        entry_text = second_entry;
        if (second_entry == 0) {
            entry_text = (u32)TWindowSubStatusDisp::get_message_10(0x5C);
        }
        forward_trade_action_default__16TObjCityMainWarpFPviii(menu_window, entry_text, 5, 1);
    }
    ((TWindowSubComCardList *)menu_window)->update_layout_height(check_memory_card_menu_width);
    align_menu_entry_positions(menu_window);
    if (sel != -2) {
        ((TWindowSubComCardList *)menu_window)->set_selected_index(sel);
    } else {
        ((TWindowSubComCardList *)menu_window)->set_selected_index(0);
    }
    ((TWindowOptionCtrl *)menu_window)->clear_flag70_bit4();
}

void TCheckMemoryCard::close_windows() {
    if (message_window != NULL) {
        if (use_main_ctrl != 0) {
            delete message_window;
        } else {
            message_window->close();
        }
        message_window = NULL;
        close_wait = 7;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
        close_wait = 7;
    }
}

void TCheckMemoryCard::set_state(s32 new_state) {
    if (state != new_state) {
        state = new_state;
        CheckMemoryCardState *entry = &check_memory_card_state_table[state];
        void (TCheckMemoryCard::*enter)() = entry->enter;
        if (enter != NULL) {
            (this->*enter)();
        }
    }
}

void TCheckMemoryCard::reset() {
    message_window = NULL;
    menu_window = NULL;
    close_wait = 0;
    status_checked = 0;
    busy_count = 0;
    status = check_card();
    card_ready = 0;
    prompt = 0;
    prompt_accepted = 0;
    set_state(0);
}

void TCheckMemoryCard::poll_card_status() {
    card_ready = 0;
    if (close_wait <= 0) {
        status_checked = 0;
        status = check_card();
        if (status != 0) {
            set_state(1);
            return;
        }
        card_ready = 1;
    }
}

void TCheckMemoryCard::enter_poll_state() {
    close_windows();
}

void TCheckMemoryCard::run_message_state() {
}

void TCheckMemoryCard::enter_message_state() {
    update_card_display(0, -1, -1, -1);
}

void TCheckMemoryCard::handle_menu_selection() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    switch (menu_window->get_selected_value()) {
    case 0:
        prompt_accepted = 1;
        break;
    }
}

void TCheckMemoryCard::enter_prompt_state() {
    s32 text;
    s32 first_entry;

    if (TKeyBoardControl__sub_8000F8EC() == 0xF) {
        text = TQuestVmDownLoadServer__sub_8006EF6C(0xA);
        first_entry = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
        recreate_message_and_menu(text, -2, first_entry, 0);
        return;
    }
    text = TQuestVmDownLoadServer__sub_8006EF6C(0x62);
    first_entry = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
    if (status & 0x20) {
        text = TQuestVmDownLoadServer__sub_8006EF6C(0x6D);
        first_entry = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
    }
    recreate_message_and_menu(text, -2, first_entry, 0);
}

void TCheckMemoryCard::update_display_state() {
    s32 flags = status;

    if (!(flags & 2)) {
        if (flags & 1) {
            if (message_window == NULL) {
                update_card_display(0, -1, -1, -1);
            }
        } else {
            if (flags & 4) {
                if (prompt != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (flags & 8) {
                if (prompt != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (flags & 0x10) {
                if (prompt != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (flags == 0) {
                set_state(2);
            }
        }
    }
}

void TCheckMemoryCard::close_and_update_display() {
    close_windows();
    if (status & 1) {
        update_card_display(0, -1, -1, -1);
    }
}

void TCheckMemoryCard::render() {
}

void TCheckMemoryCard::run_task() {
    card_ready = 0;
    status = check_card();
    if (status & 1) {
        set_state(0);
    }
    CheckMemoryCardState *entry = &check_memory_card_state_table[state];
    void (TCheckMemoryCard::*run)() = entry->run;
    if (run != NULL) {
        (this->*run)();
    }
    close_wait--;
    if (close_wait < 0) {
        close_wait = 0;
    }
}

TCheckMemoryCard::~TCheckMemoryCard() {
    if (message_window != NULL) {
        delete message_window;
        message_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
}

TCheckMemoryCard::TCheckMemoryCard(TObject *parent, void *arg2, s32 main_ctrl, s32 system_only) : TObject(parent) {
    m_name = TCheckMemoryCard__name;
    unk_48 = arg2;
    system_file_only = system_only;
    use_main_ctrl = main_ctrl;
    reset();
}

TCheckMemoryCard *TCheckMemoryCard::create_system_file_check(TObject *parent, void *arg2, s32 main_ctrl) {
    return new TCheckMemoryCard(parent, arg2, main_ctrl, 1);
}

TCheckMemoryCard *TCheckMemoryCard::create(TObject *parent, void *arg2, s32 main_ctrl) {
    return new TCheckMemoryCard(parent, arg2, main_ctrl, 0);
}
