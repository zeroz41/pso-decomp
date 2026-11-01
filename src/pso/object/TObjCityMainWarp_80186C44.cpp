#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/object/TObjCityMainWarpChallenge.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"

struct Pkt_80186CC8 { u8 cmd; u8 size; u16 id; u16 value; u16 pad; };

struct Obj_80186CC8 { u8 pad[0x1c]; u16 id; };

struct Obj_80186DA0 {
    u8 pad0[0xD0];
    s32 fD0;
    u8 padD4[0xDC - 0xD4];
    s16 fDC;
    u8 padDE[2];
    s16 fE0;
    u8 padE2[0x16C - 0xE2];
    s32 f16C;
};

extern "C" {
u8 is_current_floor_switch_set(int);
void *get_player_by_client_id(s32 i);
void end_player_keyboard_hold(s32 arg0);
void obj_clear_flag30_20000(void *arg0);
void obj_set_flag_20000(void *arg0);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 send_code_45_1__10TObjPlayerFl();

extern s32 local_client_id;

void TObjCityMainWarpChallenge::close_windows() {
    if ((u32) *(u32 *)((s8 *)this + 0x168) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x168)))->close();
        *(u32 *)((s8 *)this + 0x168) = 0U;
    }
    if (this->m_b0 != 0U) {
        ((TWindowBase *)this->m_b0)->close();
        (this->m_b0) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x164) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x164)))->close();
        *(u32 *)((s8 *)this + 0x164) = 0U;
    }
    end_player_keyboard_hold(local_client_id);
    TWindowCtrl::clear_flag();
    ((TWindowCtrl *)local_client_id)->unsuppress_slot();
}

void TObjCityMainWarpChallenge::send_6x6A_set_boss_warp_flags(u16 value) {
    Obj_80186CC8 *self = (Obj_80186CC8 *)this;
    Pkt_80186CC8 pkt;
    ((TWindowSubTradeMain *)(&pkt))->init_pkt_cmd_6A();
    pkt.id = self->id;
    pkt.value = value;
    ((TWindowSubTradeMain *)(&pkt))->send_60_update();
}

void TObjCityMainWarp::notify_player_warp(void *arg0, s32 arg1) {
    s32 player;

    player = (s32)get_player_by_client_id(arg1);
    if (player != 0) {
        send_code_45_1__10TObjPlayerFl();
        obj_clear_flag30_20000((void *)player);
    }
}

void TObjCityMainWarpChallenge::trigger_warp_effect(s32 arg1) {
    s32 player;

    player = (s32)get_player_by_client_id(arg1);
    if (player != 0) {
        play_effect_default__10TObjPlayerFii(player, -1);
        obj_set_flag_20000((void *)player);
        this->m_174 = 0x12C;
    }
}
void TObjCityMainWarp::update_floor_switch_state() {
    Obj_80186DA0 *arg0 = (Obj_80186DA0 *)this;
    switch (arg0->fE0) {
    case 0:
        arg0->fD0 = 0;
        arg0->fE0 = 1;
        break;
    case 1:
        if (arg0->f16C >= 0 && is_current_floor_switch_set((u16)arg0->f16C) == 1) {
            arg0->fDC = 0;
        }
        break;
    case -1:
        break;
    }
}

}
