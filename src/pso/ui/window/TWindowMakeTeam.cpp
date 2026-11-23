#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/WindowLayout.h"

const char *TWindowMakeTeam__name = "TWindowMakeTeam";
const char *lbl_805D395C = "";
// Menu position pairs {389, 251} of the entry and status menus.
extern const f32 lbl_8044F300[2] = {389.0f, 251.0f};
extern const f32 lbl_8044F308[2] = {389.0f, 251.0f};
extern "C" {
const char *TWindowMakeTeam__sub_80264B38(TWindowMakeTeam *o);
const char *TWindowMakeTeam__sub_80264B24(TWindowMakeTeam *o);
extern s32 local_client_id;
char *get_shared_text_buffer(void);
}

extern "C" {
TWindowMakeTeam::TWindowMakeTeam(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TWindowMakeTeam__name;
    m_1c = 0;
    m_1d = 0;
    m_20 = mode;
    m_menu = create_menu();
    m_30 = 0;
    keyboard = 0;
    name = 0;
    comment = 0;
    m_1e = 0;
    selected_value = 0;
    if (m_20 == 1 || m_20 == 2) {
        m_menu->set_entry_string_by_id((void *)draw_entry_0x110(m_1e), 2);
    }
    m_menu->set_entry_string_by_id(TWindowMakeTeam::init_status_disp(selected_value), 3);
}

TWindowMakeTeam::~TWindowMakeTeam() {
    mem_free(comment);
    mem_free(name);
    if (this->keyboard != 0) {
        keyboard->queue_destruction();
        this->keyboard = 0;
    }
    if (this->m_30 != 0) {
        m_30->close();
        this->m_30 = 0;
    }
    if (this->m_menu != 0) {
        m_menu->close();
        this->m_menu = 0;
    }
}

void TWindowMakeTeam::run_task() {
    switch (this->m_1c) {
    case 0:
    case 1:
        if (keyboard != NULL) {
            keyboard->queue_destruction();
            keyboard = NULL;
        }
        if (m_30 != NULL) {
            m_30->close();
            m_30 = NULL;
        }
        m_menu->clear_flag_and_release2();
        update_ok_button();
        this->m_1c = 2;
    case 2:
        if (m_menu->get_flag() != 0) {
            this->m_1d |= 2;
            this->m_1c = 11;
        } else if (m_menu->is_open() != 0) {
            set_state(m_menu->update_selected_entry());
        }
        break;
    case 3: {
        TKeyBoardControl *kb = new TKeyBoardControl(this, 0xE, 0, 4, local_client_id);
        keyboard = kb;
        keyboard->set_sub_position((u8 *)(get_window_layout_position(0xCB)));
        keyboard->set_depth(38500.0f);
        keyboard->set_composer_flag62_bit4();
        keyboard->set_text(name);
        m_menu->set_entry_string_by_id(NULL, 0);
        this->m_1c = 4;
    }
    case 4:
        if (keyboard->is_cancelled() != 0) {
            m_menu->set_entry_string_by_id(name, 0);
            this->m_1c = 1;
        }
        if (keyboard->is_confirmed() != 0) {
            s32 n;
            mem_free(name);
            name = keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(name, get_shared_text_buffer());
            n = (s32)measure_string_len(name);
            strncpy(name, get_shared_text_buffer(), n);
            m_menu->set_entry_string_by_id(name, 0);
            this->m_1c = 1;
        }
        break;
    case 5: {
        TKeyBoardControl *kb = new TKeyBoardControl(this, 0x10, 0, 0, local_client_id);
        keyboard = kb;
        keyboard->set_sub_position((u8 *)(get_window_layout_position(0xCC)));
        keyboard->set_depth(38500.0f);
        keyboard->set_text(comment);
        m_menu->set_entry_string_by_id(NULL, 1);
        this->m_1c = 6;
    }
    case 6:
        if (keyboard->is_cancelled() != 0) {
            m_menu->set_entry_string_by_id(comment, 1);
            this->m_1c = 1;
        }
        if (keyboard->is_confirmed() != 0) {
            s32 n;
            mem_free(comment);
            comment = keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(comment, get_shared_text_buffer());
            n = (s32)measure_string_len(comment);
            strncpy(comment, get_shared_text_buffer(), n);
            m_menu->set_entry_string_by_id(comment, 1);
            this->m_1c = 1;
        }
        break;
    case 7:
        m_30 = create_entry_menu_window();
        this->m_1c = 8;
    case 8:
        if (m_30->is_cancelled() != 0) {
            this->m_1c = 1;
        } else if (m_30->is_decided() != 0) {
            this->m_1e = m_30->get_selected_value();
            m_menu->set_entry_string_by_id((void *)TWindowMakeTeam::draw_entry_0x110(this->m_1e), 2);
            send_state();
            this->m_1c = 1;
        }
        break;
    case 9:
        m_30 = create_status_menu_window();
        this->m_1c = 10;
    case 10:
        if (m_30->is_cancelled() != 0) {
            this->m_1c = 1;
        } else if (m_30->is_decided() != 0) {
            this->selected_value = m_30->get_selected_value();
            m_menu->set_entry_string_by_id(TWindowMakeTeam::init_status_disp(this->selected_value), 3);
            this->m_1c = 1;
        }
        break;
    case 11:
        break;
    }
}

void TWindowMakeTeam::render() {  }
TWindowMenuInfomation *TWindowMakeTeam::create_menu() {
    TWindowMenuInfomation *information_counter_window;

    information_counter_window = create_information_counter_window(5);
    information_counter_window->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4D), 0, 0);
    information_counter_window->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4E), 0, 1);
    information_counter_window->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4F), 0, 2);
    information_counter_window->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x50), 0, 3);
    ((TWindowSubStatusDisp *)information_counter_window)->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x51), 4);
    return information_counter_window;
}

TWindowMenu *TWindowMakeTeam::create_entry_menu_window() {
    u8 *arg0 = (u8 *)this;
    saddr r;
    r = (s32)create_window_menu_default((saddr)lbl_8044F300, 3);
    ((TWindowMenu *)r)->add_text_entry(TWindowMakeTeam::draw_entry_0x110(0), 6, 0);
    ((TWindowMenu *)r)->add_text_entry(TWindowMakeTeam::draw_entry_0x110(1), 6, 1);
    ((TWindowMenu *)r)->add_text_entry(TWindowMakeTeam::draw_entry_0x110(2), 6, 2);
    ((TWindowMenu *)r)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(r));
    ((TWindowSubComCardList *)r)->set_selected_index(*(s8 *)(arg0 + 0x1E));
    return (TWindowMenu *)r;
}

TWindowMenu *TWindowMakeTeam::create_status_menu_window() {
    u8 *arg0 = (u8 *)this;
    saddr r;
    s32 m;
    r = (s32)create_window_menu_default((saddr)lbl_8044F308, 4);
    ((TWindowMenu *)r)->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(0)), 6, 0);
    ((TWindowMenu *)r)->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(1)), 6, 1);
    ((TWindowMenu *)r)->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(2)), 6, 2);
    m = *(s32 *)(arg0 + 0x20);
    if (m == 1 || m == 2) {
        ((TWindowMenu *)r)->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(3)), 6, 3);
    }
    ((TWindowMenu *)r)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(r));
    ((TWindowSubComCardList *)r)->set_selected_index(this->selected_value);
    return (TWindowMenu *)r;
}

void TWindowMakeTeam::update_ok_button() {
    const char *team_name = name;
    if (team_name != NULL && *team_name != 0) {
        m_menu->mark_entry_by_id(4);
        return;
    }
    m_menu->disable_entry_by_id(4);
}

void TWindowMakeTeam::send_state() {
    if ((s32) this->m_1e != 1) {
        m_menu->mark_entry_by_id(3);
        return;
    }
    m_menu->disable_entry_by_id(3);
}

void TWindowMakeTeam::set_state(s32 state) {
    switch (state) {
    case 0:
        this->m_1c = 3;
        return;
    case 1:
        this->m_1c = 5;
        return;
    case 2:
        this->m_1c = 7;
        return;
    case 3:
        this->m_1c = 9;
        return;
    case 4:
        this->m_1d = (u8) (this->m_1d | 1);
        this->m_1c = 0xB;
        return;
    }
}

const char *TWindowMakeTeam__sub_80264B38(TWindowMakeTeam *o) {
    if (o->name) return o->name;
    return lbl_805D395C;
}

const char *TWindowMakeTeam__sub_80264B24(TWindowMakeTeam *o) {
    if (o->comment) return o->comment;
    return lbl_805D395C;
}

s32 TWindowMakeTeam::is_enabled() {
    if ((s8)get_mode() == 1) {
        return (u8)(0U);
    }
    return (u8)(this->selected_value);
}

saddr TWindowMakeTeam::draw_entry_0x110(s8 arg0) {
    return (saddr)TWindowSubStatusDisp::get_message_10(arg0 + 0x110);
}

void *TWindowMakeTeam::init_status_disp(s8 arg0) {
    return TWindowSubStatusDisp::get_message_10(arg0 + 0x113);
}

}
