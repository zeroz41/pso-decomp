#include "pso/object/city/CityTraffic.h"
#include "types.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/BmlResource.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"


extern "C" {
extern s32 local_client_id;
s32 is_local_client_floor_leader(s32);
s32 city_main_warp_destination_id;

void TObjCityMainWarp::update_state() {
    s32 temp_r0_2;
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
                this->dest_floor = (s32) city_main_warp_destination_id;
                this->confirm_area_transfer(player);
                *(s16 *)((s8 *)this + 0xE0) = 2;
            }
        }
        temp_r0_2 = *(s32 *)((s8 *)this + 0x17C) - 1;
        *(s32 *)((s8 *)this + 0x17C) = temp_r0_2;
        if (temp_r0_2 <= 0) {
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
    TObjCityMainWarpChallenge *arg0 = this;
    s32 r;
    switch (arg0->state_step) {
    case 0:
        arg0->warp_countdown = 0x12C;
        play_sound_effect(0x40003205, reinterpret_cast<const Vec *>((u8 *)&arg0->position), 0, 0);
        arg0->state_step = 1;
        arg0->model = (saddr)city_common_model_archive->models[0].model;
        arg0->motion = city_common_model_archive->motions[5].motion;
        break;
    case 1:
        if (find_local_city_warp_player(arg0, arg0->warp_range) != 0) {
            ((TObjCityMainWarpChallenge *)arg0)->sub_801875F8();
            if (arg0->warp_triggered == 0) {
                arg0->trigger_warp_effect(local_client_id);
                arg0->warp_triggered = 1;
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0) {
            if (is_local_client_floor_leader(arg0->warp_countdown--) != 0) {
                if (arg0->warp_countdown <= 0) {
                    r = 1;
                } else {
                    r = arg0->are_all_players_in_range();
                }
                if (r != 0) {
                    arg0->send_6x6A_set_boss_warp_flags(2);
                    arg0->state_step = 2;
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
