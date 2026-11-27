#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/network/TProtocol.h"
#include "pso/network/InfoBoardState.h"
#include "pso/network/InfoBoardRequests.h"

const char *TWindowSubInformationBoard::class_name = "TWindowSubInformationBoard";

TWindowSubInformationBoard::TWindowSubInformationBoard(TObject *parent, s32 client) : TObject(parent) {
    this->m_name = class_name;
    this->client = client;
    this->shown_index = -1;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    this->menu_window = 0;
    this->page_menu = 0;
    this->message_window = 0;
    this->dialog_window = 0;
    this->keyboard = 0;
    this->state = 0;
}

TWindowSubInformationBoard::~TWindowSubInformationBoard() {
    if (this->keyboard != NULL) {
        this->keyboard->queue_destruction();
        this->keyboard = 0;
    }
    if (this->dialog_window != 0U) {
        this->dialog_window->close();
        this->dialog_window = 0;
    }
    if (this->message_window != 0U) {
        this->message_window->close();
        this->message_window = 0;
    }
    if (this->page_menu != NULL) {
        this->page_menu->close();
        this->page_menu = 0;
    }
    if (this->menu_window != 0U) {
        this->menu_window->close();
        this->menu_window = 0;
    }
    TWindowSubInformationBoard::clear_if_current(&this->board);
}


void TWindowSubInformationBoard::run_task() {
    char *info_text;
    switch (this->state) {
    case 0:
    case 1:
        if (this->menu_window == NULL) {
            this->menu_window = create_info_board_menu();
        }
        if (this->message_window == NULL) {
            this->message_window = open_card_info_window();
        }
        this->menu_window->clear_flag_and_release();
        this->state = 2U;
    case 2:
        set_message_index(this->menu_window->get_cursor_pos());
        if (this->menu_window->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->state = 0xCU;
        } else if (this->menu_window->is_decided() != 0) {
            if (this->message_window != NULL) {
                this->message_window->close();
                this->message_window = 0U;
            }
            this->state = this->menu_window->get_selected_value();
        }
        break;
    case 3:
        request_info_board(&this->board);
        this->state = 4U;
    case 4:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 5U;
        }
        if (get_info_board_ptr() != NULL) {
            this->state = 6U;
            break;
        }
        break;
    case 5:
        TWindowSubInformationBoard::clear_if_current(&this->board);
        this->state = 1U;
        break;
    case 6:
        if (this->page_menu == NULL) {
            this->page_menu = create_board_menu();
        }
        if (this->message_window == NULL) {
            this->message_window = show_card_a7();
        }
        this->state = 7U;
    case 7:
        this->set_page(this->page_menu->get_selected_value());
        if (this->page_menu->is_cancelled() != 0) {
            this->state = 8U;
            break;
        }
        break;
    case 8:
        if (this->page_menu != NULL) {
            this->page_menu->close();
            this->page_menu = NULL;
        }
        this->state = 5U;
        break;
    case 9:
        if (this->menu_window != NULL) {
            this->menu_window->close();
            this->menu_window = 0U;
        }
        if (this->keyboard == NULL) {
            this->keyboard = open_keyboard();
        }
        this->state = 0xAU;
    case 10:
        if (this->keyboard->is_cancelled() != 0) {
            this->state = 0xBU;
            break;
        }
        if (this->keyboard->is_confirmed() != 0) {
            info_text = this->keyboard->realloc_buffer();
            set_info_board_text(info_text);
            flush_pending_send();
            mem_free(info_text);
            this->state = 0xBU;
            break;
        }
        break;
    case 11:
        if (this->keyboard != NULL) {
            this->keyboard->queue_destruction();
            this->keyboard = NULL;
        }
        this->state = 1U;
        break;
    case 12:
        break;
    }
}

void TWindowSubInformationBoard::render() {  }

TWindowMenu *TWindowSubInformationBoard::create_info_board_menu() {
  TWindowMenu *list;
  list = create_titled_window_menu_default(get_window_layout_position(0xA4), 2, TWindowSubStatusDisp::get_message_10(0x1D));
  if (get_main_phase() == 0xF)
  {
    list->add_text_entry((TWindowSubStatusDisp::get_message_10(0x117)), 6, 3);
  }
  else
  {
    add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x117)), 6, 3);
  }
  list->add_text_entry((TWindowSubStatusDisp::get_message_10(0x118)), 6, 9);
  list->set_flag70_bit10();
  list->update_layout_height(179.0f);
  align_menu_entry_positions(list);
  return list;
}

TWindowMenu *TWindowSubInformationBoard::create_board_menu() {
    TRecvInfoBoard *board;
    TInfoBoardEntry *it;
    TWindowMenu *w;
    s32 i;
    s32 n;
    board = get_info_board_ptr();
    if (board == NULL) {
        return NULL;
    }
    w = create_titled_window_menu_default(get_window_layout_position(0xA6), 0xC, TWindowSubStatusDisp::get_message_10(0x1D));
    // The packet's header flags carry the entry count; an entry with no text is listed grayed out.
    n = board->header.flags;
    it = board->entries;
    for (i = 0; i < n; i++, it++) {
        if (it->text[0] != 0) {
            w->add_text_entry(it->name, 0x16, i);
        } else {
            add_gray_text_entry(w, it->name, 0x16, i);
        }
    }
    if (w->get_entry_count() <= 0) {
        add_gray_text_entry(w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 6, -1);
    }
    w->set_flag70_bit10();
    w->set_scroll_target(223.0f, 184.0f);
    return w;
}

TWindowMessage *TWindowSubInformationBoard::open_card_info_window() {
    static const f32 size[2] = {188.0f, 160.0f};
    TWindowMessage *window;
    window = TWindowMessage::create((const NJS_POINT2 *)get_window_layout_position(0xA5), size, 1);
    this->shown_index = -1;
    return window;
}

TWindowMessage *TWindowSubInformationBoard::show_card_a7() {
    static const f32 size[2] = {206.0f, 180.0f};
    TWindowMessage *window;
    window = TWindowMessage::create((const NJS_POINT2 *)get_window_layout_position(0xA7), size, 1);
    this->shown_index = -1;
    return window;
}

TKeyBoardControl *TWindowSubInformationBoard::open_keyboard() {
    TKeyBoardControl *keyboard = new TKeyBoardControl(this, 0xC6, 5, 4, local_client_id);
    keyboard->set_text(TLobby::get_info_board_text());
    keyboard->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    keyboard->set_flag62_bit2();
    keyboard->set_soft_flag60_bit1();
    return keyboard;
}

void TWindowSubInformationBoard::set_message_index(s32 index) {
    static const s32 message_ids[3] = {0x119, 0x11A, 0};
    if ((s32) this->shown_index != index) {
        this->shown_index = index;
        this->message_window->append_line(TWindowSubStatusDisp::get_message_10(message_ids[index]), 0x80);
    }
}

void TWindowSubInformationBoard::set_page(s32 page) {
    TRecvInfoBoard *board;

    if (((s32) this->shown_index != page) && (page != -1)) {
        board = get_info_board_ptr();
        if (board != NULL) {
            this->shown_index = page;
            this->message_window->append_line(board->entries[page].text, 0x80);
        }
    }
}

