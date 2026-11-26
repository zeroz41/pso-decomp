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
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/window/TWindowComCardFollower.h"

void TObjCityMainWarpChallenge::close_windows() {
    if (yes_no_window != NULL) {
        yes_no_window->close();
        yes_no_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    if (player_list_window != NULL) {
        ((TWindowBase *)player_list_window)->close();
        player_list_window = NULL;
    }
    TWindowCtrl::end_client_keyboard_hold(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::unsuppress_slot(local_client_id);
}

void TObjCityMainWarpChallenge::send_6x6A_set_boss_warp_flags(u16 value) {
    G_SetBossWarpFlags_6x6A pkt;
    ((TWindowSubTradeMain *)&pkt)->init_pkt_cmd_6A();
    pkt.header.entity_id = entity_id;
    pkt.flags = value;
    ((TWindowSubTradeMain *)&pkt)->send_60_update();
}

void TObjCityMainWarpChallenge::release_warp_effect(s32 client) {
    TObjPlayer *player;

    player = get_player_by_client_id(client);
    if (player != NULL) {
        send_release_hold(player);
        obj_clear_flag30_20000(player);
    }
}

void TObjCityMainWarpChallenge::trigger_warp_effect(s32 client) {
    TObjPlayer *player;

    player = get_player_by_client_id(client);
    if (player != NULL) {
        send_impose_hold(player, -1);
        obj_set_flag_20000(player);
        this->warp_effect_timer = 0x12C;
    }
}

void TObjCityMainWarpChallenge::update_floor_switch_state() {
    switch (state_step) {
    case 0:
        model = 0;
        state_step = 1;
        break;
    case 1:
        if (key_id >= 0 && is_current_floor_switch_set((u16)key_id) == 1) {
            next_state = 0;
        }
        break;
    case -1:
        break;
    }
}

void TObjCityMainWarpChallenge::update_warp_window() {

    switch (state_step) {
    case 0:
        state_step = 1;
        model = 0;
        return;
    case 1:
        if (find_local_city_warp_player(this, warp_range) != NULL) {
            if (menu_window == NULL) {
                menu_window = create_window_menu_default(get_window_layout_position(0x35), 7);
                if (menu_window != NULL) {
                    menu_window->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x40), 0, 0, -1);
                    menu_window->set_flag_40();
                    menu_window->calc_window_size();
                    align_menu_entry_positions(menu_window);
                }
                TWindowCtrl::begin_client_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        } else {
            if (menu_window != NULL) {
                menu_window->close();
                menu_window = NULL;
            }
            TWindowCtrl::end_client_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
        if (player_on_dest_floor == 0) {
            next_state = 0;
        }
        return;
    case -1:
        if (menu_window != NULL) {
            menu_window->close();
            menu_window = NULL;
        }
        TWindowCtrl::end_client_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
        break;
    }
}

s32 city_main_warp_destination_id;

extern "C" s32 is_local_client_floor_leader();

void TObjCityMainWarpChallenge::update_area_transfer() {
    TObjPlayer *player;

    switch (state_step) {
    case 0:
        state_timer = 0x96;
        state_step = 1;
        state_flags |= 1;
        model = (saddr)city_common_model_archive->models[0].model;
        motion = city_common_model_archive->motions[5].motion;
        return;
    case 1:
        if (TObjCityMainWarp::get_phase_flag() == 0) {
            player = find_local_city_warp_player(this, warp_range);
            if (player != NULL) {
                release_warp_effect(local_client_id);
                dest_floor = city_main_warp_destination_id;
                confirm_area_transfer(player);
                state_step = 2;
            }
        }
        if (--state_timer <= 0) {
            state_step = 2;
        }
        break;
    case -1:
        break;
    case 2:
        state_flags &= ~1;
        next_state = 3;
        break;
    }
}

void TObjCityMainWarpChallenge::update_warp_sequence() {
    s32 r;
    switch (this->state_step) {
    case 0:
        this->warp_countdown = 0x12C;
        play_sound_effect(0x40003205, &this->position, 0, 0);
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
            warp_countdown--;
            if (is_local_client_floor_leader() != 0) {
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
        close_windows();
        break;
    }
}
