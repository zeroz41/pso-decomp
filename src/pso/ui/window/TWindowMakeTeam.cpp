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
#include "pso/ui/window/TWindowMakeTeam_8026534C.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TUnk_804D0658.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/object/warp/TObjCityMainWarp.h"

const char *TWindowMakeTeam__name = "TWindowMakeTeam";
const char *lbl_805D395C = "";
// Menu position pairs {389, 251} of the entry and status menus.
extern const f32 lbl_8044F300[2] = {389.0f, 251.0f};
extern const f32 lbl_8044F308[2] = {389.0f, 251.0f};
struct Obj_80264B38 { u8 pad[0x24]; const char *f24; };
struct Obj_80264B24 { u8 pad[0x28]; const char *f28; };
typedef struct Self_80264EB8 {
    u8 pad0[0x1C];
    u8 state;
    u8 flags;
    u8 sel1E;
    u8 sel1F;
    u8 pad20[4];
    char *name;
    char *comment;
    void *menu;
    void *window;
    void *keyboard;
} Self_80264EB8;

struct TWMT;
extern "C" {
const char *TWindowMakeTeam__sub_80264B38(Obj_80264B38 *o);
const char *TWindowMakeTeam__sub_80264B24(Obj_80264B24 *o);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void *init_status_disp__15TWindowMakeTeamFc(s8 arg0);
s8 get_mode__6TLobbyFv();
extern s32 local_client_id;
void *get_window_layout_position(s32);
char *get_shared_text_buffer(void);
extern s32 __vt__15TWindowMakeTeam[];
s32 __ct__7TObjectFP7TObject();
}

extern "C" {
void *TWindowMakeTeam__ct(void *arg0, void *arg1, s32 arg2) {
    s32 temp_r0;
    s32 v;
    register struct TWMT *self;

    __ct__7TObjectFP7TObject();
    self = (struct TWMT *) arg0;
    *(void **)((s8 *)self + 0x18) = (void *) __vt__15TWindowMakeTeam;
    v = (saddr)TWindowMakeTeam__name;
    *(s32 *)((s8 *)self + 0) = v;
    ((TWindowMakeTeam *)self)->m_1c = 0;
    ((TWindowMakeTeam *)self)->m_1d = 0;
    ((TWindowMakeTeam *)self)->m_20 = arg2;
    ((TWindowMakeTeam *)self)->m_menu = ((TWindowMakeTeam *)self)->create_menu();
    ((TWindowMakeTeam *)self)->m_30 = 0;
    ((TWindowMakeTeam *)self)->m_34 = 0;
    ((TWindowMakeTeam *)self)->m_24 = 0;
    ((TWindowMakeTeam *)self)->m_28 = 0;
    ((TWindowMakeTeam *)self)->m_1e = 0U;
    ((TWindowMakeTeam *)self)->m_1f = 0U;
    temp_r0 = ((TWindowMakeTeam *)self)->m_20;
    if ((temp_r0 == 1) || (temp_r0 == 2)) {
        ((TWindowMakeTeam *)(((TWindowMakeTeam *)self)->m_menu))->set_entry_string_by_id((void *)TWindowMakeTeam::draw_entry_0x110(((TWindowMakeTeam *)self)->m_1e), 2);
    }
    ((TWindowMakeTeam *)(((TWindowMakeTeam *)self)->m_menu))->set_entry_string_by_id(init_status_disp__15TWindowMakeTeamFc(((TWindowMakeTeam *)self)->m_1f), 3);
    return arg0;
}

TWindowMakeTeam::~TWindowMakeTeam() {
    mem_free((void *)this->m_28);
    mem_free((void *)this->m_24);
    if (this->m_34 != 0) {
        ((TObject *)this->m_34)->queue_destruction();
        this->m_34 = 0;
    }
    if (this->m_30 != 0) {
        ((TWindowBase *)this->m_30)->close();
        this->m_30 = 0;
    }
    if (this->m_menu != 0) {
        ((TWindowBase *)this->m_menu)->close();
        this->m_menu = 0;
    }
}

void TWindowMakeTeam::run_task() {
    Self_80264EB8 *self = (Self_80264EB8 *)this;
    switch (this->m_1c) {
    case 0:
    case 1:
        if (self->keyboard != NULL) {
            ((TObject *)self->keyboard)->queue_destruction();
            self->keyboard = NULL;
        }
        if (self->window != NULL) {
            ((TWindowBase *)self->window)->close();
            self->window = NULL;
        }
        ((TWindowSubComCard *)(self->menu))->clear_flag_and_release2();
        ((TWindowMakeTeam *)self)->update_ok_button();
        this->m_1c = 2;
    case 2:
        if (((TWindowSubComCard *)(self->menu))->get_flag() != 0) {
            this->m_1d |= 2;
            this->m_1c = 11;
        } else if (((TUnk_804D0658 *)(self->menu))->is_open() != 0) {
            ((TWindowMakeTeam *)self)->set_state(((TWindowSubComCard *)(self->menu))->update_selected_entry());
        }
        break;
    case 3: {
        void *kb = new TKeyBoardControl((TObject *)self, 0xE, 0, 4, local_client_id);
        self->keyboard = kb;
        ((TKeyBoardControl *)(self->keyboard))->set_sub_position((u8 *)(get_window_layout_position(0xCB)));
        ((TKeyBoardControl *)self->keyboard)->set_depth(38500.0f);
        reinterpret_cast<TKeyBoardControl *>(self->keyboard)->set_composer_flag62_bit4();
        ((TKeyBoardControl *)self->keyboard)->set_text((char *)self->name);
        ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(NULL, 0);
        this->m_1c = 4;
    }
    case 4:
        if (((TKeyBoardControl *)(self->keyboard))->is_cancelled() != 0) {
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(self->name, 0);
            this->m_1c = 1;
        }
        if (((TKeyBoardControl *)(self->keyboard))->is_confirmed() != 0) {
            s32 n;
            mem_free(self->name);
            self->name = ((TKeyBoardControl *)self->keyboard)->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(self->name, get_shared_text_buffer());
            n = (s32)measure_string_len((const char *)(self->name));
            strncpy(self->name, get_shared_text_buffer(), n);
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(self->name, 0);
            this->m_1c = 1;
        }
        break;
    case 5: {
        void *kb = new TKeyBoardControl((TObject *)self, 0x10, 0, 0, local_client_id);
        self->keyboard = kb;
        ((TKeyBoardControl *)(self->keyboard))->set_sub_position((u8 *)(get_window_layout_position(0xCC)));
        ((TKeyBoardControl *)self->keyboard)->set_depth(38500.0f);
        ((TKeyBoardControl *)self->keyboard)->set_text((char *)self->comment);
        ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(NULL, 1);
        this->m_1c = 6;
    }
    case 6:
        if (((TKeyBoardControl *)(self->keyboard))->is_cancelled() != 0) {
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(self->comment, 1);
            this->m_1c = 1;
        }
        if (((TKeyBoardControl *)(self->keyboard))->is_confirmed() != 0) {
            s32 n;
            mem_free(self->comment);
            self->comment = ((TKeyBoardControl *)self->keyboard)->realloc_buffer();
            TWindowSubComCard::mask_profanity_words(self->comment, get_shared_text_buffer());
            n = (s32)measure_string_len((const char *)(self->comment));
            strncpy(self->comment, get_shared_text_buffer(), n);
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(self->comment, 1);
            this->m_1c = 1;
        }
        break;
    case 7:
        self->window = (void *)((TWindowMakeTeam *)self)->create_entry_menu_window();
        this->m_1c = 8;
    case 8:
        if (((TWindowMenu *)(self->window))->is_cancelled() != 0) {
            this->m_1c = 1;
        } else if (((TWindowMenu *)(self->window))->is_decided() != 0) {
            this->m_1e = ((TWindowMenu *)self->window)->get_selected_value();
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id((void *)TWindowMakeTeam::draw_entry_0x110(this->m_1e), 2);
            ((TWindowMakeTeam *)self)->send_state();
            this->m_1c = 1;
        }
        break;
    case 9:
        self->window = (void *)((TWindowMakeTeam *)self)->create_status_menu_window();
        this->m_1c = 10;
    case 10:
        if (((TWindowMenu *)(self->window))->is_cancelled() != 0) {
            this->m_1c = 1;
        } else if (((TWindowMenu *)(self->window))->is_decided() != 0) {
            this->m_1f = ((TWindowMenu *)self->window)->get_selected_value();
            ((TWindowMakeTeam *)(self->menu))->set_entry_string_by_id(init_status_disp__15TWindowMakeTeamFc(this->m_1f), 3);
            this->m_1c = 1;
        }
        break;
    case 11:
        break;
    }
}

void TWindowMakeTeam::render() {  }
saddr TWindowMakeTeam::create_menu() {
    saddr information_counter_window;

    information_counter_window = create_information_counter_window(5);
    ((TWindowSubComCard *)information_counter_window)->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4D), 0, 0);
    ((TWindowSubComCard *)information_counter_window)->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4E), 0, 1);
    ((TWindowSubComCard *)information_counter_window)->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x4F), 0, 2);
    ((TWindowSubComCard *)information_counter_window)->update_next_entry((saddr)TWindowSubStatusDisp::get_message_10(0x50), 0, 3);
    ((TWindowSubStatusDisp *)information_counter_window)->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x51), 4);
    return information_counter_window;
}

saddr TWindowMakeTeam::create_entry_menu_window() {
    u8 *arg0 = (u8 *)this;
    saddr r;
    r = (s32)create_window_menu_default((saddr)lbl_8044F300, 3);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(0)), 6, 0);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(1)), 6, 1);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(2)), 6, 2);
    ((TWindowMenu *)r)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(r));
    ((TWindowSubComCardList *)r)->set_selected_index(*(s8 *)(arg0 + 0x1E));
    return r;
}

saddr TWindowMakeTeam::create_status_menu_window() {
    u8 *arg0 = (u8 *)this;
    saddr r;
    s32 m;
    r = (s32)create_window_menu_default((saddr)lbl_8044F308, 4);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (saddr)init_status_disp__15TWindowMakeTeamFc(0), 6, 0);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (saddr)init_status_disp__15TWindowMakeTeamFc(1), 6, 1);
    TObjCityMainWarp::forward_trade_action_default((void *)r, (saddr)init_status_disp__15TWindowMakeTeamFc(2), 6, 2);
    m = *(s32 *)(arg0 + 0x20);
    if (m == 1 || m == 2) {
        TObjCityMainWarp::forward_trade_action_default((void *)r, (saddr)init_status_disp__15TWindowMakeTeamFc(3), 6, 3);
    }
    ((TWindowMenu *)r)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(r));
    ((TWindowSubComCardList *)r)->set_selected_index(*(s8 *)(arg0 + 0x1F));
    return r;
}

void TWindowMakeTeam::update_ok_button() {
    u8 *temp_r4;

    temp_r4 = *(u8 * *)&this->m_24;
    if ((temp_r4 != NULL) && ((s8) *temp_r4 != 0)) {
        ((TWindowSubComCard *)(this->m_menu))->mark_entry_by_id(4);
        return;
    }
    ((TWindowSubComCard *)(this->m_menu))->disable_entry_by_id(4);
}

void TWindowMakeTeam::send_state() {
    if ((s32) this->m_1e != 1) {
        ((TWindowSubComCard *)(this->m_menu))->mark_entry_by_id(3);
        return;
    }
    ((TWindowSubComCard *)(this->m_menu))->disable_entry_by_id(3);
}

void TWindowMakeTeam::set_state(s32 arg1) {
    switch (arg1) {
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

const char *TWindowMakeTeam__sub_80264B38(Obj_80264B38 *o) {
    if (o->f24) return o->f24;
    return lbl_805D395C;
}

const char *TWindowMakeTeam__sub_80264B24(Obj_80264B24 *o) {
    if (o->f28) return o->f28;
    return lbl_805D395C;
}

s32 TWindowMakeTeam::is_enabled() {
    if (get_mode__6TLobbyFv() == 1) {
        return (u8)(0U);
    }
    return (u8)(this->m_1f);
}

saddr TWindowMakeTeam::draw_entry_0x110(s8 arg0) {
    return (saddr)TWindowSubStatusDisp::get_message_10(arg0 + 0x110);
}

void *init_status_disp__15TWindowMakeTeamFc(s8 arg0) {
    return TWindowSubStatusDisp::get_message_10(arg0 + 0x113);
}

}
