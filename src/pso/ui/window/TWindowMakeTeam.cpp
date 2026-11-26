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
#include "pso/network/client_id.h"

const char *TWindowMakeTeam::class_name = "TWindowMakeTeam";
const char *lbl_805D395C = "";
// Menu position pairs {389, 251} of the entry and status menus.
extern const NJS_POINT2 lbl_8044F300 = {389.0f, 251.0f};
extern const NJS_POINT2 lbl_8044F308 = {389.0f, 251.0f};
extern "C" {
char *get_shared_text_buffer(void);
}

TWindowMakeTeam::TWindowMakeTeam(TObject *parent, s32 kind) : TObject(parent) {
    m_name = TWindowMakeTeam::class_name;
    state = 0;
    flags = 0;
    m_20 = kind;
    m_menu = create_menu();
    sub_menu = 0;
    keyboard = 0;
    name = 0;
    comment = 0;
    mode = 0;
    selected_value = 0;
    if (m_20 == 1 || m_20 == 2) {
        m_menu->set_entry_string_by_id((void *)draw_entry_0x110(mode), 2);
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
    if (this->sub_menu != 0) {
        sub_menu->close();
        this->sub_menu = 0;
    }
    if (this->m_menu != 0) {
        m_menu->close();
        this->m_menu = 0;
    }
}

void TWindowMakeTeam::run_task() {
    switch (this->state) {
    case 0:
    case 1:
        if (keyboard != NULL) {
            keyboard->queue_destruction();
            keyboard = NULL;
        }
        if (sub_menu != NULL) {
            sub_menu->close();
            sub_menu = NULL;
        }
        m_menu->clear_flag_and_release2();
        update_ok_button();
        this->state = 2;
    case 2:
        if (m_menu->get_flag() != 0) {
            this->flags |= 2;
            this->state = 11;
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
        this->state = 4;
    }
    case 4:
        if (keyboard->is_cancelled() != 0) {
            m_menu->set_entry_string_by_id(name, 0);
            this->state = 1;
        }
        if (keyboard->is_confirmed() != 0) {
            s32 n;
            mem_free(name);
            name = keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(name, get_shared_text_buffer());
            n = (s32)measure_string_len(name);
            strncpy(name, get_shared_text_buffer(), n);
            m_menu->set_entry_string_by_id(name, 0);
            this->state = 1;
        }
        break;
    case 5: {
        TKeyBoardControl *kb = new TKeyBoardControl(this, 0x10, 0, 0, local_client_id);
        keyboard = kb;
        keyboard->set_sub_position((u8 *)(get_window_layout_position(0xCC)));
        keyboard->set_depth(38500.0f);
        keyboard->set_text(comment);
        m_menu->set_entry_string_by_id(NULL, 1);
        this->state = 6;
    }
    case 6:
        if (keyboard->is_cancelled() != 0) {
            m_menu->set_entry_string_by_id(comment, 1);
            this->state = 1;
        }
        if (keyboard->is_confirmed() != 0) {
            s32 n;
            mem_free(comment);
            comment = keyboard->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(comment, get_shared_text_buffer());
            n = (s32)measure_string_len(comment);
            strncpy(comment, get_shared_text_buffer(), n);
            m_menu->set_entry_string_by_id(comment, 1);
            this->state = 1;
        }
        break;
    case 7:
        sub_menu = create_entry_menu_window();
        this->state = 8;
    case 8:
        if (sub_menu->is_cancelled() != 0) {
            this->state = 1;
        } else if (sub_menu->is_decided() != 0) {
            this->mode = sub_menu->get_selected_value();
            m_menu->set_entry_string_by_id((void *)TWindowMakeTeam::draw_entry_0x110(this->mode), 2);
            send_state();
            this->state = 1;
        }
        break;
    case 9:
        sub_menu = create_status_menu_window();
        this->state = 10;
    case 10:
        if (sub_menu->is_cancelled() != 0) {
            this->state = 1;
        } else if (sub_menu->is_decided() != 0) {
            this->selected_value = sub_menu->get_selected_value();
            m_menu->set_entry_string_by_id(TWindowMakeTeam::init_status_disp(this->selected_value), 3);
            this->state = 1;
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
    information_counter_window->update_next_entry(TWindowSubStatusDisp::get_message_10(0x4D), 0, 0);
    information_counter_window->update_next_entry(TWindowSubStatusDisp::get_message_10(0x4E), 0, 1);
    information_counter_window->update_next_entry(TWindowSubStatusDisp::get_message_10(0x4F), 0, 2);
    information_counter_window->update_next_entry(TWindowSubStatusDisp::get_message_10(0x50), 0, 3);
    information_counter_window->add_text_entry((uaddr)TWindowSubStatusDisp::get_message_10(0x51), 4);
    return information_counter_window;
}

TWindowMenu *TWindowMakeTeam::create_entry_menu_window() {
    TWindowMenu *r;
    r = create_window_menu_default(&lbl_8044F300, 3);
    r->add_text_entry(TWindowMakeTeam::draw_entry_0x110(0), 6, 0);
    r->add_text_entry(TWindowMakeTeam::draw_entry_0x110(1), 6, 1);
    r->add_text_entry(TWindowMakeTeam::draw_entry_0x110(2), 6, 2);
    r->calc_window_size();
    align_menu_entry_positions(r);
    r->set_selected_index(this->mode);
    return r;
}

TWindowMenu *TWindowMakeTeam::create_status_menu_window() {
    TWindowMenu *r;
    s32 m;
    r = create_window_menu_default(&lbl_8044F308, 4);
    r->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(0)), 6, 0);
    r->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(1)), 6, 1);
    r->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(2)), 6, 2);
    m = this->m_20;
    if (m == 1 || m == 2) {
        r->add_text_entry((saddr)(TWindowMakeTeam::init_status_disp(3)), 6, 3);
    }
    r->calc_window_size();
    align_menu_entry_positions(r);
    r->set_selected_index(this->selected_value);
    return r;
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
    if ((s32) this->mode != 1) {
        m_menu->mark_entry_by_id(3);
        return;
    }
    m_menu->disable_entry_by_id(3);
}

void TWindowMakeTeam::set_state(s32 state) {
    switch (state) {
    case 0:
        this->state = 3;
        return;
    case 1:
        this->state = 5;
        return;
    case 2:
        this->state = 7;
        return;
    case 3:
        this->state = 9;
        return;
    case 4:
        this->flags = (u8) (this->flags | 1);
        this->state = 0xB;
        return;
    }
}

const char *TWindowMakeTeam::get_name() {
    if (name) return name;
    return lbl_805D395C;
}

const char *TWindowMakeTeam::get_comment() {
    if (comment) return comment;
    return lbl_805D395C;
}

s32 TWindowMakeTeam::is_enabled() {
    if ((s8)get_mode() == 1) {
        return (u8)(0U);
    }
    return (u8)this->selected_value;
}

saddr TWindowMakeTeam::draw_entry_0x110(s8 index) {
    return (saddr)TWindowSubStatusDisp::get_message_10(index + 0x110);
}

void *TWindowMakeTeam::init_status_disp(s8 index) {
    return TWindowSubStatusDisp::get_message_10(index + 0x113);
}

