#include "types.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

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
    s32 id;
};

extern "C" {

void TObjCityMainWarpChallenge::close_windows() {
    if ((u32) *(u32 *)((s8 *)this + 0x168) != 0U) {
        ((TWindowMessageYesNo *)(this->yes_no_window))->close();
        *(u32 *)((s8 *)this + 0x168) = 0U;
    }
    if (this->menu_window != 0U) {
        ((TWindowBase *)this->menu_window)->close();
        (this->menu_window) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x164) != 0U) {
        ((TWindowBase *)(this->player_list_window))->close();
        *(u32 *)((s8 *)this + 0x164) = 0U;
    }
    end_player_keyboard_hold(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::unsuppress_slot(local_client_id);
}

void TObjCityMainWarpChallenge::send_6x6A_set_boss_warp_flags(u16 value) {
    Obj_80186CC8 *self = (Obj_80186CC8 *)this;
    Pkt_80186CC8 pkt;
    ((TWindowSubTradeMain *)(&pkt))->init_pkt_cmd_6A();
    pkt.id = self->id;
    pkt.value = value;
    ((TWindowSubTradeMain *)(&pkt))->send_60_update();
}

void TObjCityMainWarp::notify_player_warp(void *arg0, s32 local_client_id) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_release_hold(player);
        obj_clear_flag30_20000(player);
    }
}

void TObjCityMainWarpChallenge::trigger_warp_effect(s32 local_client_id) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_impose_hold(player, -1);
        obj_set_flag_20000(player);
        this->warp_effect_timer = 0x12C;
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
        if (arg0->id >= 0 && is_current_floor_switch_set((u16)arg0->id) == 1) {
            arg0->fDC = 0;
        }
        break;
    case -1:
        break;
    }
}

}
