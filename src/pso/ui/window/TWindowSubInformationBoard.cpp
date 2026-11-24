#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowSubComCard.h"

struct I_8034CDE0 { u8 pad[0x10]; s8 f10; u8 pad11[0xBC - 0x11]; };

struct L_8034CDE0 { u8 f0; u8 n; u8 pad2[2]; I_8034CDE0 items[1]; };

extern "C" {
s32 set_info_board_text__6TLobbyFv();
saddr get_window_layout_position(s32);
void *create_titled_window_menu_default(s32, s32, void *);

extern s32 local_client_id;

const char *lbl_805D4348 = "TWindowSubInformationBoard";

}

TWindowSubInformationBoard::TWindowSubInformationBoard(TObject *object, void *arg2) : TObject(object) {
    this->m_name = lbl_805D4348;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->shown_index = -1;
    parent_menu = static_cast<TWindowMainMenu *>(object);
    this->menu_window = 0;
    this->page_menu = 0;
    this->message_window = 0;
    this->m_38 = 0;
    this->keyboard = 0;
    this->m_1c = 0;
}

TWindowSubInformationBoard::~TWindowSubInformationBoard() {
    if (this->keyboard != NULL) {
        this->keyboard->queue_destruction();
        this->keyboard = 0;
    }
    if (this->m_38 != 0U) {
        ((TWindowMessageYesNo *)this->m_38)->close();
        this->m_38 = 0;
    }
    if (this->message_window != 0U) {
        ((TWindowBase *)this->message_window)->close();
        this->message_window = 0;
    }
    if (this->page_menu != 0U) {
        ((TWindowBase *)this->page_menu)->close();
        this->page_menu = 0;
    }
    if (this->menu_window != 0U) {
        ((TWindowBase *)this->menu_window)->close();
        this->menu_window = 0;
    }
    TWindowSubInformationBoard::clear_if_current((uaddr)&this->m_40);
}

extern "C" {

void TWindowSubInformationBoard::run_task() {
    u8 *arg0 = (u8 *)this;
    saddr temp_r30;
    u8 temp_r0;
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->menu_window == 0U) {
            this->menu_window = create_info_board_menu();
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = open_card_info_window();
        }
        ((TWindowMenu *)(this->menu_window))->clear_flag_and_release();
        this->m_1c = 2U;
    case 2:
        set_message_index(((TWindowShortListCtrl *)this->menu_window)->get_cursor_pos());
        if (((TWindowMenu *)(this->menu_window))->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->m_1c = 0xCU;
        } else if (((TWindowMenu *)(this->menu_window))->is_decided() != 0) {
            if ((u32) this->message_window != 0U) {
                ((TWindowBase *)this->message_window)->close();
                this->message_window = 0U;
            }
            this->m_1c = ((TWindowMenu *)this->menu_window)->get_selected_value();
        }
        break;
    case 3:
        TLobby::init_once_data((uaddr)((void *) ((u8 *)arg0 + 0x40)));
        this->m_1c = 4U;
    case 4:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 5U;
        }
        if (TLobby::get_info_board_ptr() != 0U) {
            this->m_1c = 6U;
            break;
        }
        break;
    case 5:
        TWindowSubInformationBoard::clear_if_current((uaddr)((void *) ((u8 *)arg0 + 0x40)));
        this->m_1c = 1U;
        break;
    case 6:
        if ((u32) this->page_menu == 0U) {
            this->page_menu = sub_8034CDE0();
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = show_card_a7();
        }
        this->m_1c = 7U;
    case 7:
        ((TWindowSubInformationBoard *)arg0)->set_page((int) (((TWindowMenu *)this->page_menu)->get_selected_value()));
        if (((TWindowMenu *)(this->page_menu))->is_cancelled() != 0) {
            this->m_1c = 8U;
            break;
        }
        break;
    case 8:
        if ((u32) this->page_menu != 0U) {
            ((TWindowBase *)this->page_menu)->close();
            this->page_menu = 0U;
        }
        this->m_1c = 5U;
        break;
    case 9:
        if ((u32) this->menu_window != 0U) {
            ((TWindowBase *)this->menu_window)->close();
            this->menu_window = 0U;
        }
        if (this->keyboard == NULL) {
            this->keyboard = TWindowSubInformationBoard::open_keyboard((saddr)((void *)arg0));
        }
        this->m_1c = 0xAU;
    case 10:
        if (this->keyboard->is_cancelled() != 0) {
            this->m_1c = 0xBU;
            break;
        }
        if (this->keyboard->is_confirmed() != 0) {
            temp_r30 = (saddr)this->keyboard->realloc_buffer();
            set_info_board_text__6TLobbyFv();
            TLobby::flush_pending_send();
            mem_free((void *)temp_r30);
            this->m_1c = 0xBU;
            break;
        }
        break;
    case 11:
        if (this->keyboard != NULL) {
            this->keyboard->queue_destruction();
            this->keyboard = NULL;
        }
        this->m_1c = 1U;
        break;
    case 12:
        break;
    }
}

void TWindowSubInformationBoard::render() {  }

u32 TWindowSubInformationBoard::create_info_board_menu() {
  void *list;
  list = create_titled_window_menu_default(get_window_layout_position(0xA4), 2, TWindowSubStatusDisp::get_message_10(0x1D));
  if (get_main_phase() == 0xF)
  {
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x117)), 6, 3);
  }
  else
  {
    add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x117)), 6, 3);
  }
  ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x118)), 6, 9);
  ((TWindowMenu *)list)->set_flag70_bit10();
  ((TWindowMenu *)list)->update_layout_height(179.0f);
  align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
  return (uaddr)list;
}

u32 TWindowSubInformationBoard::sub_8034CDE0() {
    I_8034CDE0 *it;
    void *w;
    s32 i;
    s32 n;
    it = (I_8034CDE0 *)TLobby::get_info_board_ptr();
    if (it == NULL) {
        return 0;
    }
    w = create_titled_window_menu_default(get_window_layout_position(0xA6), 0xC, TWindowSubStatusDisp::get_message_10(0x1D));
    n = ((L_8034CDE0 *)it)->n;
    it = ((L_8034CDE0 *)it)->items;
    for (i = 0; i < n; i++, it++) {
        if (it->f10 != 0) {
            ((TWindowMenu *)w)->add_text_entry((saddr)it, 0x16, i);
        } else {
            add_gray_text_entry((TWindowMenu *)w, (const char *)it, 0x16, i);
        }
    }
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 6, -1);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 184.0f);
    return (uaddr)w;
}

u32 TWindowSubInformationBoard::open_card_info_window() {
    static const f32 size[2] = {188.0f, 160.0f};
    u8 *window;
    window = TWindowMessage::create((const NJS_POINT2 *)get_window_layout_position(0xA5), (const f32 *)size, 1);
    this->shown_index = -1;
    return (uaddr)window;
}

u32 TWindowSubInformationBoard::show_card_a7() {
    static const f32 size[2] = {206.0f, 180.0f};
    u8 *window;
    window = TWindowMessage::create((const NJS_POINT2 *)get_window_layout_position(0xA7), (const f32 *)size, 1);
    this->shown_index = -1;
    return (uaddr)window;
}

TKeyBoardControl *TWindowSubInformationBoard::open_keyboard(saddr parent) {
    TKeyBoardControl *keyboard = new TKeyBoardControl((TObject *)parent, 0xC6, 5, 4, local_client_id);
    keyboard->set_text((char *)TLobby::get_card_window_field());
    keyboard->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    keyboard->set_flag62_bit2();
    keyboard->set_soft_flag60_bit1();
    return keyboard;
}

void TWindowSubInformationBoard::set_message_index(s32 index) {
    static const s32 message_ids[3] = {0x119, 0x11A, 0};
    if ((s32) this->shown_index != index) {
        this->shown_index = index;
        ((TWindowMessage *)(this->message_window))->append_line((saddr)TWindowSubStatusDisp::get_message_10(message_ids[index]), 0x80);
    }
}

void TWindowSubInformationBoard::set_page(s32 arg1) {
    s32 info_board;

    if (((s32) this->shown_index != arg1) && (arg1 != -1)) {
        info_board = (saddr)TLobby::get_info_board_ptr();
        if (info_board != 0) {
            this->shown_index = arg1;
            ((TWindowMessage *)(this->message_window))->append_line(info_board + (arg1 * 0xBC) + 0x14, 0x80);
        }
    }
}

}
