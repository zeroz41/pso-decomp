#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct Obj_80264B38 { u8 pad[0x24]; void *f24; };

struct Obj_80264B24 { u8 pad[0x28]; void *f28; };

extern "C" {
extern void *lbl_805D395C;
void *TWindowMakeTeam__sub_80264B38(Obj_80264B38 *o);
void *TWindowMakeTeam__sub_80264B24(Obj_80264B24 *o);
void align_menu_entry_positions(s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, s32);
extern u8 lbl_8044F300[];
void init_status_disp__15TWindowMakeTeamFc(s8 arg0);
extern u8 lbl_8044F308[];
s8 get_mode__6TLobbyFv();

void init_status_disp__15TWindowMakeTeamFc(s8 arg0) {
    TWindowSubStatusDisp::get_message_10(arg0 + 0x113);
}
s32 TWindowMakeTeam::draw_entry_0x110(s8 arg0) {
    TWindowSubStatusDisp::get_message_10(arg0 + 0x110);
}
u8 TWindowMakeTeam::is_enabled() {
    if (get_mode__6TLobbyFv() == 1) {
        return 0U;
    }
    return this->m_1f;
}

void *TWindowMakeTeam__sub_80264B24(Obj_80264B24 *o) {
    if (o->f28) return o->f28;
    return lbl_805D395C;
}

void *TWindowMakeTeam__sub_80264B38(Obj_80264B38 *o) {
    if (o->f24) return o->f24;
    return lbl_805D395C;
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

void TWindowMakeTeam::send_state() {
    if ((s32) this->m_1e != 1) {
        ((TWindowSubComCard *)(this->m_2c))->mark_entry_by_id(3);
        return;
    }
    ((TWindowSubComCard *)(this->m_2c))->disable_entry_by_id(3);
}

void TWindowMakeTeam::update_ok_button() {
    u8 *temp_r4;

    temp_r4 = *(u8 * *)&this->m_24;
    if ((temp_r4 != NULL) && ((s8) *temp_r4 != 0)) {
        ((TWindowSubComCard *)(this->m_2c))->mark_entry_by_id(4);
        return;
    }
    ((TWindowSubComCard *)(this->m_2c))->disable_entry_by_id(4);
}

#define STATUS(n) ((s32 (*)(s8)) init_status_disp__15TWindowMakeTeamFc)(n)
s32 TWindowMakeTeam::create_status_menu_window() {
    u8 *arg0 = (u8 *)this;
    s32 r;
    s32 m;
    r = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_8044F308, 4);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(STATUS(0)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(STATUS(1)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(STATUS(2)), 6, 2);
    m = *(s32 *)(arg0 + 0x20);
    if (m == 1 || m == 2) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(STATUS(3)), 6, 3);
    }
    ((TWindowSubComCard *)r)->calc_window_size();
    align_menu_entry_positions(r);
    ((TWindowSubComCardList *)r)->set_selected_index(*(s8 *)(arg0 + 0x1F));
    return r;
}

s32 TWindowMakeTeam::create_entry_menu_window() {
    u8 *arg0 = (u8 *)this;
    s32 r;
    r = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_8044F300, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(0)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(1)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(TWindowMakeTeam::draw_entry_0x110(2)), 6, 2);
    ((TWindowSubComCard *)r)->calc_window_size();
    align_menu_entry_positions(r);
    ((TWindowSubComCardList *)r)->set_selected_index(*(s8 *)(arg0 + 0x1E));
    return r;
}

}
