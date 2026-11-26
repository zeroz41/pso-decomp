#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowShortCut.h"
#include "pso/ui/window/TWindowSubShortCut.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
class TChCrTagPlBack;
struct TWindowShortCut;
#include "pso/ui/chat/TWindowChat.h"

#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/WindowLayout.h"

#pragma readonly_strings on



const char *TWindowSubShortCut::class_name = "TWindowSubShortCut";

void TWindowChat::set_flag1e_bit80() { flags |= 0x80; }

TWindowSubShortCut::TWindowSubShortCut(TObject *parent, s32 client) : TObject(parent) {
    this->m_name = TWindowSubShortCut::class_name;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    client_id = client;
    this->com_card_list = 0;
    this->menu = 0;
    this->confirm_window = 0;
    this->chat_window = 0;
    this->shortcut_window = 0;
    this->shortcut_slot = 0;
    this->state = 0;
}

TWindowSubShortCut::~TWindowSubShortCut() {
    if (chat_window != NULL) { chat_window->queue_destruction(); this->chat_window = 0; }
    if (confirm_window != NULL) { confirm_window->close(); this->confirm_window = 0; }
    if (shortcut_window != NULL) { shortcut_window->close(); this->shortcut_window = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close(); this->menu = 0; }
    if (com_card_list != NULL) { com_card_list->close(); com_card_list = NULL; }
}

void TWindowSubShortCut::run_task() {
    u32 var_r0;
    switch (this->state) {
    case 0:
    case 1:
        if (this->chat_window != NULL) {
            this->chat_window->queue_destruction();
            this->chat_window = 0U;
        }
        if (this->confirm_window != NULL) {
            this->confirm_window->close();
            this->confirm_window = 0U;
        }
        if (this->shortcut_window != NULL) {
            this->shortcut_window->close();
            this->shortcut_window = 0U;
        }
        if (this->menu != NULL) {
            this->menu->close();
            this->menu = 0U;
        }
        if (com_card_list == NULL) {
            com_card_list = open_com_card_list();
        }
        com_card_list->refresh_entries();
        com_card_list->clear_decided();
        this->state = 2U;
    case 2:
        if (com_card_list->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->state = 0xBU;
            return;
        }
        if (com_card_list->is_decided() != 0) {
            this->state = 3U;
        }
        break;
    case 3:
        if (this->confirm_window != NULL) {
            this->confirm_window->close();
            this->confirm_window = 0U;
        }
        if (this->menu == NULL) {
            this->menu = open_menu();
        }
        this->menu->clear_flag_and_release();
        this->menu->clear_transition_flag();
        this->state = 4U;
    case 4:
        if (this->menu->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->menu->is_decided() != 0) {
            this->state = this->menu->get_selected_value();
            return;
        }
        break;
    case 5:
        if (this->menu != NULL) {
            this->menu->close();
            this->menu = 0U;
        }
        if (com_card_list != NULL) {
            this->shortcut_slot = com_card_list->get_cursor_value();
            com_card_list->close();
            this->com_card_list = NULL;
        }
        if (this->chat_window == NULL) {
            this->chat_window = new TWindowChat(this, &this->chat_submission);
            this->chat_window->set_keyboard_flag62_bit4();
            this->chat_window->close_and_clear_flag();
            this->chat_window->set_flag1e_bit80();
        }
        this->state = 6U;
    case 6:
        if (this->chat_window->is_visible() != 0) {
            this->state = 1U;
            return;
        }
        if (this->chat_window->is_mode_bit4() != 0) {
            this->state = 7U;
            return;
        }
        break;
    case 7:
        if (this->chat_window != NULL) {
            this->chat_window->queue_destruction();
            this->chat_window = 0U;
        }
        if (this->shortcut_window == NULL) {
            this->shortcut_window = new TWindowShortCut((s32)((saddr)get_window_layout_position(0x73)), this->shortcut_slot, (s32 *)&this->chat_submission);
        }
        if (this->confirm_window == NULL) {
            this->confirm_window = open_confirm_prompt();
        }
        this->state = 8U;
    case 8:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                store_chat_shortcut(this->shortcut_slot, &this->chat_submission);
                this->state = 1U;
                return;
            }
            this->state = 1U;
            return;
        }
        break;
    case 9:
        this->menu->open();
        if (this->confirm_window == NULL) {
            this->confirm_window = open_confirm_message();
        }
        this->state = 0xAU;
    case 10:
        if (this->confirm_window->is_cancelled() != 0) {
            this->state = 3U;
            return;
        }
        if (this->confirm_window->is_child_visible() != 0) {
            if (this->confirm_window->get_selected_value() == 0) {
                clear_chat_shortcut(com_card_list->get_cursor_value());
                this->state = 1U;
                return;
            }
            this->state = 3U;
        }
        break;
    case 11:
        break;
    }
}

void TWindowSubShortCut::render() {  }

TWindowSubShortCutList *TWindowSubShortCut::open_com_card_list() {
    return TWindowSubShortCutList::create(get_window_layout_position(0x72), static_cast<s32>(shortcut_slot));
}

TWindowMenu *TWindowSubShortCut::open_menu() {
    TWindowMenu *list;
    ChatShortcut *chat_shortcut;

    chat_shortcut = get_chat_shortcut(com_card_list->get_cursor_value());
    list = create_titled_window_menu_default(get_window_layout_position(0x74), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x2C));
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x7E)), 6, 5);
    if (chat_shortcut->kind.value != 0) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 9);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 9);
    }
    list->set_flag70_bit10();
    list->update_layout_height(205.0f);
    align_menu_entry_positions(list);
    return list;
}

TWindowMessageYesNo *TWindowSubShortCut::open_confirm_prompt() {
    TWindowMessageYesNo *dialog = TWindowMessageYesNo::create(this, this->client_id, 0, 0);
    open_yes_no_prompt(dialog, (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x3D)), get_window_layout_position(0x75), 205.0f);
    dialog->set_choice_menu_flag70_bit10();
    return dialog;
}

TWindowMessageYesNo *TWindowSubShortCut::open_confirm_message() {
    TWindowMessageYesNo *dialog;

    dialog = TWindowMessageYesNo::create(this, this->client_id, 0, 0);
    open_yes_no_prompt(dialog, (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x3e)), get_window_layout_position(0x76), 205.0f);
    dialog->set_menu_selected_index(1);
    dialog->set_choice_menu_flag70_bit10();
    return dialog;
}

int TWindowSubQuestBoardSelect::is_shortcut_active() { return this->state_flags & 0x4; }
