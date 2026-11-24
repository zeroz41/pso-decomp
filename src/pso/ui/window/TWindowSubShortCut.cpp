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
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
class TChCrTagPlBack;
struct TWindowShortCut;
#include "pso/ui/chat/TWindowChat.h"

#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/object/warp/TObjCityMainWarp.h"

#pragma readonly_strings on

struct Win_8027DBB8 { u8 pad[0x20]; saddr client_id; };

extern "C" {
s32 clear_chat_shortcut();
}
s32 store_chat_shortcut(s32 arg0, s32 arg1);
extern "C" {
u32 *get_chat_shortcut();

}

const char *TWindowSubShortCut__class_name = "TWindowSubShortCut";

void TWindowChat::set_flag1e_bit80() { flags |= 0x80; }

TWindowSubShortCut::TWindowSubShortCut(TObject *object, void *arg2) : TObject(object) {
    this->m_name = TWindowSubShortCut__class_name;
    parent_menu = static_cast<TWindowMainMenu *>(object);
    *(void **)((s8 *)this + 0x20) = arg2;
    this->com_card_list = 0;
    this->menu = 0;
    this->confirm_window = 0;
    this->chat_window = 0;
    this->m_3c = 0;
    this->m_24 = 0;
    this->state = 0;
}

TWindowSubShortCut::~TWindowSubShortCut() {
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x38)))->queue_destruction(); this->chat_window = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x34)))->close(); this->confirm_window = 0; }
    if (*(void **)((s8 *)this + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close(); this->m_3c = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close(); this->menu = 0; }
    if (com_card_list != NULL) { com_card_list->close(); com_card_list = NULL; }
}

void TWindowSubShortCut::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 var_r0;
    switch (this->state) {
    case 0:
    case 1:
        if ((u32) this->chat_window != 0U) {
            ((TObject *)(this->chat_window))->queue_destruction();
            this->chat_window = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_3c != 0U) {
            ((TWindowBase *)this->m_3c)->close();
            this->m_3c = 0U;
        }
        if ((u32) this->menu != 0U) {
            ((TWindowBase *)this->menu)->close();
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
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->menu == 0U) {
            this->menu = open_menu();
        }
        ((TWindowMenu *)(this->menu))->clear_flag_and_release();
        ((TWindowMenu *)(this->menu))->clear_transition_flag();
        this->state = 4U;
    case 4:
        if (((TWindowMenu *)(this->menu))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->menu))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->menu)->get_selected_value();
            return;
        }
        break;
    case 5:
        if ((u32) this->menu != 0U) {
            ((TWindowBase *)this->menu)->close();
            this->menu = 0U;
        }
        if (com_card_list != NULL) {
            this->m_24 = com_card_list->get_cursor_value();
            com_card_list->close();
            this->com_card_list = NULL;
        }
        if ((u32) this->chat_window == 0U) {
            void *chat = new TWindowChat((TObject *)arg0, (u8 *)&this->m_40);
            *(void * *)&this->chat_window = chat;
            reinterpret_cast<TWindowChat *>(this->chat_window)->set_keyboard_flag62_bit4();
            reinterpret_cast<TWindowChat *>(this->chat_window)->close_and_clear_flag();
            reinterpret_cast<TWindowChat *>(chat_window)->set_flag1e_bit80();
        }
        this->state = 6U;
    case 6:
        if (((TWindowChat *)(this->chat_window))->is_visible() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowChat *)(this->chat_window))->is_mode_bit4() != 0) {
            this->state = 7U;
            return;
        }
        break;
    case 7:
        if ((u32) this->chat_window != 0U) {
            ((TObject *)(this->chat_window))->queue_destruction();
            this->chat_window = 0U;
        }
        if ((u32) this->m_3c == 0U) {
            *(void * *)&this->m_3c = (void *)new TWindowShortCut((s32)(get_window_layout_position(0x73)), this->m_24, (s32 *)((u8 *)arg0 + 0x40));
        }
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = open_confirm_prompt();
        }
        this->state = 8U;
    case 8:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                store_chat_shortcut((this->m_24), (saddr)(arg0 + 0x40));
                this->state = 1U;
                return;
            }
            this->state = 1U;
            return;
        }
        break;
    case 9:
        ((TWindowMenu *)(this->menu))->open();
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = open_confirm_message();
        }
        this->state = 0xAU;
    case 10:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 3U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                com_card_list->get_cursor_value();
                clear_chat_shortcut();
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
    return TWindowSubShortCutList::create(get_window_layout_position(0x72), static_cast<s32>(m_24));
}

s32 TWindowSubShortCut::open_menu() {
    saddr list;
    u32 *chat_shortcut;

    com_card_list->get_cursor_value();
    chat_shortcut = get_chat_shortcut();
    list = create_titled_window_menu_default(reinterpret_cast<saddr>(get_window_layout_position(0x74)), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x2C));
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x7E)), 6, 5);
    if ((u32) *chat_shortcut != 0U) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 9);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 9);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(205.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

s32 TWindowSubShortCut::open_confirm_prompt() {
    Win_8027DBB8 *arg0 = (Win_8027DBB8 *)this;
    saddr r = (saddr)TWindowMessageYesNo::create((void *)(arg0), arg0->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(r), (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x3D)), (s32)(get_window_layout_position(0x75)), 205.0f);
    ((TWindowMessageYesNo *)r)->set_choice_menu_flag70_bit10();
    return r;
}

s32 TWindowSubShortCut::open_confirm_message() {
    saddr dialog;

    dialog = (saddr)TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x3e)), (s32)(get_window_layout_position(0x76)), 205.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(1);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

int TWindowSubQuestBoardSelect::is_shortcut_active() { return this->m_60 & 0x4; }
