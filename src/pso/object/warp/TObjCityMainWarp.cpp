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
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/system/BmlResource.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/network/TLobby.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"

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
        this->yes_no_window->close();
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
    TWindowCtrl::end_client_keyboard_hold(local_client_id);
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

void TObjCityMainWarp::notify_player_warp(void *warp, s32 local_client_id) {
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

extern "C" {

void request_active_window_close(void);
}

void update_challenge_warp_window(TObjCityMainWarpChallenge *warp) {

    switch (warp->state_step) {
    case 0:
        warp->state_step = 1;
        *(s32 *)((s8 *)warp + 0xD0) = 0;
        return;
    case 1:
        if (find_local_city_warp_player(warp, warp->warp_range) != NULL) {
            if ((u32) warp->menu_window == 0U) {
                warp->menu_window = (uaddr)create_window_menu_default(get_window_layout_position(0x35), 7);
                if ((u32) warp->menu_window != 0U) {
                    ((TWindowMenu *)(warp->menu_window))->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x40), 0, 0, -1);
                    ((TWindowMenu *)(warp->menu_window))->set_flag_40();
                    ((TWindowMenu *)(warp->menu_window))->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(warp->menu_window));
                }
                TWindowCtrl::begin_client_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        } else {
            if ((u32) warp->menu_window != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
                warp->menu_window = 0U;
            }
            TWindowCtrl::end_client_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
        if ((s32) warp->player_on_dest_floor == 0) {
            warp->next_state = 0;
        }
        return;
    case -1:
        if ((u32) warp->menu_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
            warp->menu_window = 0U;
        }
        TWindowCtrl::end_client_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
        break;
    }
}

s32 city_main_warp_destination_id;

extern "C" {
s32 is_local_client_floor_leader(s32);

void TObjCityMainWarp::update_state() {
    s32 frames_left;
    TObjPlayer *player;

    switch (*(s16 *)((s8 *)this + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)this + 0x17C) = 0x96;
        *(s16 *)((s8 *)this + 0xE0) = 1;
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) | 1);
        *(NJS_OBJECT **)((s8 *)this + 0xD0) = city_common_model_archive->models[0].model;
        this->menu_destinations[3] = (saddr) city_common_model_archive->motions[5].motion;
        return;
    case 1:
        if (TObjCityMainWarp::get_phase_flag() == 0) {
            player = find_local_city_warp_player(this, warp_range);
            if (player != NULL) {
                TObjCityMainWarp::notify_player_warp(this, local_client_id);
                this->dest_floor = city_main_warp_destination_id;
                this->confirm_area_transfer(player);
                *(s16 *)((s8 *)this + 0xE0) = 2;
            }
        }
        frames_left = *(s32 *)((s8 *)this + 0x17C) - 1;
        *(s32 *)((s8 *)this + 0x17C) = frames_left;
        if (frames_left <= 0) {
            *(s16 *)((s8 *)this + 0xE0) = 2;
        }
    case -1:
        break;
    case 2:
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) & 0xFFFFFFFE);
        *(s16 *)((s8 *)this + 0xDC) = 3;
        break;
    }
}

void TObjCityMainWarpChallenge::update_warp_sequence() {
    s32 r;
    switch (this->state_step) {
    case 0:
        this->warp_countdown = 0x12C;
        play_sound_effect(0x40003205, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        this->state_step = 1;
        this->model = (saddr)city_common_model_archive->models[0].model;
        this->motion = city_common_model_archive->motions[5].motion;
        break;
    case 1:
        if (find_local_city_warp_player(this, this->warp_range) != 0) {
            this->sub_801875F8();
            if (this->warp_triggered == 0) {
                this->trigger_warp_effect(local_client_id);
                this->warp_triggered = 1;
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0) {
            if (is_local_client_floor_leader(this->warp_countdown--) != 0) {
                if (this->warp_countdown <= 0) {
                    r = 1;
                } else {
                    r = this->are_all_players_in_range();
                }
                if (r != 0) {
                    this->send_6x6A_set_boss_warp_flags(2);
                    this->state_step = 2;
                }
            }
        }
        break;
    case 2:
        break;
    case -1:
        ((TObjCityMainWarpChallenge *) this)->close_windows();
        break;
    }
}

}
