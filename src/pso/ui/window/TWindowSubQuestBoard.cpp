#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowSubQuestBoard_8027D1E8.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/ui/window/TWindowSubOption.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMagPhoton.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/window/TWindowShortListCtrl_801A4FC0.h"
#include "pso/object/warp/TObjCityMainWarp.h"

#pragma readonly_strings on

struct Ent_8027CFC8 { u8 pad[0x20]; s32 label; };

// The {width, height} of the option value window create_option_value_window opens.
__declspec(section ".rodata") static const f32 option_value_window_size[2] ATTRIBUTE_ALIGN(8) = { 302.0f, 148.0f };

extern "C" {
s32 fn_8027D1E8(s32);
extern Ent_8027CFC8 quest_board_handlers[];
int set_card_window_flags__19TWindowKeyBoardHardFPvll(void*, int, int);
}

const char *TWindowSubQuestBoard::class_name = "TWindowSubQuestBoard";

int TWindowSubQuestBoardSelect::is_cancelled() { return this->m_60 & 0x2; }

int TWindowSubQuestBoardSelect::is_open() { return this->m_60 & 0x1; }

u8 TWindowSubQuestBoardSelect::get_page_index() { return this->slot; }

TWindowSubQuestBoard::TWindowSubQuestBoard(TObject *object, void *client) : TObject(object) {
    this->m_name = class_name;
    parent_menu = static_cast<TWindowMainMenu *>(object);
    this->client = client;
    select_window = new TWindowSubQuestBoardSelect();
    this->quest_thread_board = NULL;
    this->state = 0;
    TWindowCtrl__sub_8027D214();
}

TWindowSubQuestBoard::~TWindowSubQuestBoard() {
    TWindowCtrl__sub_8027D1F8();
    if (select_window != NULL) { select_window->close(); select_window = NULL; }
}

extern "C" {
void TWindowSubQuestBoard::run_task() {
    switch (this->state) {
    case 0:
    case 1:
        fn_8027D1E8((saddr)select_window);
        this->state = 2;
    case 2:
        if (select_window->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->state = 5;
            break;
        }
        if (select_window->is_open() != 0) {
            this->state = 3;
        }
        break;
    case 3:
        this->quest_thread_board = TQuestThreadBoard::create_instance(
            quest_board_handlers[(s8)select_window->get_page_index()].label);
        this->state = 4;
    case 4:
        if (this->quest_thread_board->all_parents_unqueued_for_destruction() == 0) {
            this->quest_thread_board = NULL;
            this->state = 1;
        }
        break;
    case 5:
        break;
    }
}

void TWindowSubQuestBoard::render() {  }

int TWindowSubQuestBoard::set_card_flags_direct(int card_flags_direct) { return set_card_window_flags__19TWindowKeyBoardHardFPvll(this, card_flags_direct, -2); }

void TWindowSubQuestBoard::set_card_flags_scaled(s32 value) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, value * 2, -3);
}

void TWindowSubQuestBoard__sub_8027CF50(saddr client_id, s32 value) {
    TWindowKeyBoardHard::set_card_window_flags((void*)client_id, value * 4, -5);
}

void TWindowSubQuestBoard::clear_card_window_flags(s32 value) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, value * 8, -9);
}

void TWindowSubQuestBoard::set_card_window_flags(s32 value) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, value << 8, -0x301);
}

void TWindowSubQuestBoard::set_board_flags(s32 value) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, value << 0xA, -0x1C01);
}

TWindowSubOption::TWindowSubOption(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    this->parent = parent;
    client_id = client;
    menu = (TWindowMenu *)create_option_menu_window();
    value_window = 0;
    state = 0;
}

TWindowSubOption::~TWindowSubOption() {
    if (value_window != 0) { ((TWindowBase *)value_window)->close(); value_window = 0; }
    if (menu != NULL) { ((TWindowBase *)menu)->close(); menu = NULL; }
}

void TWindowSubOption::run_task() {
    s32 t;
    switch (state) {
    case 0:
    case 1:
        if (value_window != 0U) {
            ((TWindowBase *)value_window)->close();
            value_window = 0U;
        }
        ((TWindowMenu *)menu)->clear_flag_and_release();
        state = 2;
    case 2:
        if (menu->is_cancelled() != 0) {
            parent->on_submenu_closed();
            state = 5;
            break;
        }
        if (menu->is_decided() != 0) {
            state = 3;
        }
        break;
    case 3:
        t = menu->get_selected_value();
        value_window = create_option_value_window(t);
        state = 4;
    case 4:
        this->update_photon_selection();
        update_quest_board_card_flags();
        if (((TWindowMenuIconLine *)(value_window))->is_cancelled() != 0) {
            state = 1;
        }
        break;
    }
}

void TWindowSubOption::render() {  }

saddr TWindowSubOption::create_option_menu_window() {
    saddr titled_window_menu;

    titled_window_menu = create_titled_window_menu((saddr)get_window_layout_position(0x15), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x2A), client_id);
    if (is_split_screen() == 0) {
        ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x66)), 6, 0);
    }
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x67)), 6, 1);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x68)), 6, 2);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x69)), 6, 3);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x6A)), 6, 4);
    if (is_split_screen() == 0) {
        ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x6E)), 6, 5);
    }
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(195.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 0));
    return titled_window_menu;
}

saddr TWindowSubOption::create_option_value_window(s32 option) {
    s16 value;
    saddr window;
    s32 flag;
    window = (saddr)TWindowSubStatusDisp__sub_80248BE8((saddr)(get_window_layout_position(0x16)), (saddr)option_value_window_size, (s32)client_id);
    switch (option) {
    case 0:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x66)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x6F)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x70)), 1);
        value = ((TWindowKeyBoardHard *)(client_id))->is_card_flag_set();
        break;
    case 1:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x67)));
        TWindowSubStatusDisp::draw_status(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x71)), 0);
        TWindowSubStatusDisp::draw_status(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x72)), 1);
        value = TWindowKeyBoardHard::test_card_flag_2(client_id);
        break;
    case 2:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x68)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x73)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x74)), 1);
        value = test_keyboard_card_flag4((void *)client_id);
        break;
    case 4:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x6A)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0xA6)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0xA7)), 1);
        flag = TWindowKeyBoardHard::test_card_flag_8(client_id);
        vibration = flag;
        value = (s16) flag;
        break;
    case 3:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x69)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x75)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x76)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x77)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x78)), 3);
        value = TWindowSubStatusDisp::get_card_window_flags(client_id);
        break;
    case 5:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x6E)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x79)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7A)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7B)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7C)), 3);
        value = fn_801A51F0(client_id);
        break;
    }
    ((TWindowSubStatusDisp *)window)->set_selected_index(value);
    ((TWindowSubShortCutList *)window)->set_flag70_bit10();
    ((TWindowBase *)window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 1));
    return window;
}

void TWindowSubOption::update_quest_board_card_flags() {
    s32 selected_menu_value;
    s32 value;

    selected_menu_value = menu->get_selected_value();
    value = ((TWindowOptionCtrl *)value_window)->update_selected_item();
    switch (selected_menu_value) {
    case 0:
        ((TWindowSubQuestBoard *)(client_id))->set_card_flags_direct(value);
        return;
    case 1:
        ((TWindowSubQuestBoard *)(client_id))->set_card_flags_scaled(value);
        return;
    case 2:
        TWindowSubQuestBoard__sub_8027CF50(client_id, value);
        return;
    case 4:
        ((TWindowSubQuestBoard *)(client_id))->clear_card_window_flags(value);
        return;
    case 3:
        ((TWindowSubQuestBoard *)(client_id))->set_card_window_flags(value);
        return;
    case 5:
        ((TWindowSubQuestBoard *)(client_id))->set_board_flags(value);
        return;
    }
}

void TWindowSubOption::update_photon_selection() {
    s32 selected_menu_value;
    s32 value;

    selected_menu_value = menu->get_selected_value();
    value = ((TWindowOptionCtrl *)value_window)->update_selected_item();
    if ((selected_menu_value == 4) && ((s8)vibration != value)) {
        (vibration) = (u8) value;
        if ((s8)vibration == 0) {
            start_pad_rumble_client(0xC0, 0xF, (s16)client_id);
        }
    }
}
}
