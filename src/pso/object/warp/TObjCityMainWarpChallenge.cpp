#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/task/TObject.h"
const char *lbl_805D32B8 = "TObjCityMainWarpChallenge";
static const char lbl_80444A44[] = "<- NEXT STAGE No.%d";
static const char lbl_80444A58[] = "<- KEY ID : %d";

void initialize_option_dialog(void *dialog, s32 message, s32 position, f32 width);

extern "C" {
f32 xz_distance_squared(void *, void *);
char *strcpy(char *, const char *);
extern s32 local_client_id;
s32 is_local_client_floor_leader(s32);
s32 find_local_player_in_range__16TObjCityMainWarpFf(void *, f32);
s32 close_windows__25TObjCityMainWarpChallengeFv();
void sub_801875F8__25TObjCityMainWarpChallengeFv(TObjCityMainWarpChallenge *self);
s32 fn_80248994(void *, u32, int);
void request_active_window_close(void);
void begin_player_keyboard_hold(s32 arg0);
s32 get_window_layout_position(s32);
s32 free_member__17TWindowSubComCardFv(void *, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(void *, s32, s32, f32);
s32 get_main_phase();
extern s32 city_main_warp_destination_id;
extern BmlResource *city_common_model_archive;
s32 post_translate_matrix(void *);
s32 update_floor_switch_state__16TObjCityMainWarpFv();
s32 update_warp_sequence__16TObjCityMainWarpFv();
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 update_challenge_warp_window();
s32 update_state__16TObjCityMainWarpFv();
extern s32 camera_ctrl_instance;
extern s32 city_common_texture_list;

TObjCityMainWarpChallenge::TObjCityMainWarpChallenge(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = lbl_805D32B8;
    frame = 0.0f;
    warp_range = 19.0f;
    dest_floor = set_params[0];
    city_main_warp_destination_id = dest_floor;
    bodies = NULL;
    register_entity_by_id(this);
    player_list_window = NULL;
    yes_no_window = NULL;
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        key_id = -1;
    } else if (set_params[1] < 0 || set_params[1] > 0xFF) {
        key_id = -1;
    } else {
        key_id = set_params[1];
    }
    if (key_id >= 0) {
        next_state = 4;
        state = 4;
    } else {
        next_state = 0;
        state = 0;
    }
    state_step = 0;
    state_flags = 0;
    model = city_common_model_archive->models[0].model;
    motion = city_common_model_archive->motions[5].motion;
    if (field_collider != NULL) {
        ((TObject *)field_collider)->queue_destruction();
        field_collider = NULL;
    }
    for (int i = 0; i < 4; i++) {
        player_in_range[i] = 0;
    }
}

TObjCityMainWarpChallenge::~TObjCityMainWarpChallenge() {
    unregister_object_by_id();
    close_windows();
}

void TObjCityMainWarpChallenge::run_task() {
    if (TObjPlayer::check_demo_mode() != 1) {
        if (!(state_flags & 1) && state != next_state) {
            if (state_step != -1) {
                state_step = -1;
                update_state();
            }
            state = next_state;
            state_step = 0;
        }
        count_players_in_warp_radius();
        update_state();
        if (motion != NULL) {
            frame += 4.0f;
            if ((1.0f + frame) >= (f32)motion->frameCount) {
                frame = 0.0f;
            }
        }
    }
}

void TObjCityMainWarpChallenge::render() {
    if (dest_floor == 0xE) {
        if (xz_distance_squared((void *)(camera_ctrl_instance + 0x178), (u8 *)&this->position) > 160000.0f) {
            return;
        }
        goto block_4;
    }
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
block_4:
        TObjFish::set_global_param(city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((void *)city_common_model_archive->models[12].model);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(city_common_model_archive->models[0].model, (s32)city_common_model_archive->motions[5].motion, frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjCityMainWarpChallenge::debug_print_area_num() {
    s32 v = set_params[1];
    if (v < 0 || v > 0xFF) {
        key_id = -1;
    } else {
        key_id = v;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        debug_printf_at(0x130020, lbl_80444A44, set_params[0]);
    }
    debug_printf_at(0x130021, lbl_80444A58, key_id);
}

void TObjCityMainWarpChallenge::update_state() {

    switch (state) {
    case 0:
        update_challenge_state();
        return;
    case 1:
        update_warp_sequence__16TObjCityMainWarpFv();
        return;
    case 2:
        update_state__16TObjCityMainWarpFv();
        return;
    case 3:
        update_challenge_warp_window();
        return;
    case 4:
        update_floor_switch_state__16TObjCityMainWarpFv();
        return;
    }
}

void TObjCityMainWarpChallenge::sub_801875F8() {
    s32 i;
    s32 j;
    u32 color;
    TLobby *player;
    f32 pos[2];

    switch (this->state) {
    case 0:
        if (this->yes_no_window == 0) {
            this->yes_no_window = TWindowMessageYesNo::create(this, (void *)local_client_id, (void *)0, (void *)0);
            if (this->yes_no_window != 0) {
                forward_slot_selection__16TAdChrSelASlotGCFPvPv(this->yes_no_window, (s32)TWindowSubStatusDisp::get_message_10(0x41), get_window_layout_position(0x36), 368.0f);
                free_member__17TWindowSubComCardFv(this->yes_no_window, 1);
                ((TWindowSubShortMail *)this->yes_no_window)->notify_warp_flag70();
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                ((TWindowCtrl *)local_client_id)->suppress_slot();
            }
        }
        break;
    case 1:
        if (this->yes_no_window == 0) {
            this->yes_no_window = TWindowMessageYesNo::create(this, (void *)local_client_id, (void *)0, (void *)0);
            if (this->yes_no_window != 0) {
                initialize_option_dialog(this->yes_no_window, (s32)TWindowSubStatusDisp::get_message_10(0x42), get_window_layout_position(0x36), 368.0f);
            }
        }
        break;
    }
    if (this->player_list_window == 0) {
        pos[0] = 229.0f;
        pos[1] = 104.0f;
        this->player_list_window = TWindowSubStatusDisp::refresh_with_default_list(get_window_layout_position(0x34), (s32)pos);
        if (this->player_list_window != 0) {
            ((TWindowSubTradeMain *)this->player_list_window)->set_visible();
            ((TWindowSubTradeMain *)this->player_list_window)->set_close_flag();
            for (i = 0; i < this->player_count; i++) {
                TWindowSubStatusDisp::dispatch_without_flags((s32)this->player_list_window, (s32)this->player_names[i], i);
            }
        }
        request_active_window_close();
    }
    if (this->player_list_window != 0) {
        for (j = 0; j < this->player_count; j++) {
            ((THunterGuildSeqOffline *)this->player_list_window)->advance_matching_entries(this->player_in_range[j] != 0, j);
            color = 0xF0F0F0FF;
            if (this->state == 1 && (player = (TLobby *)get_player_by_client_id(j)) != NULL &&
                player->check_player_flag1() != 0) {
                color = 0xFFFF00FF;
            }
            fn_80248994(this->player_list_window, color, j);
        }
    }
}

void TObjCityMainWarpChallenge::count_players_in_warp_radius() {
    s32 i;
    s32 inside;
    TObjPlayer *pl;
    s32 room;
    s32 old;
    TObjPlayer *pl2;
    old = player_count;
    player_count = 0;
    players_in_range = 0;
    player_on_dest_floor = 0;
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(i);
        if (pl != NULL) {
            room = pl->get_floor();
            if (room == dest_floor) {
                player_on_dest_floor = 1;
            }
            inside = 0;
            if (room == get_current_floor()) {
                if (xz_distance_squared(&pl->position, &position) <= warp_range * warp_range) {
                    inside = 1;
                    players_in_range++;
                }
            }
            player_in_range[player_count] = inside;
            strcpy(player_names[player_count], pl->name);
            player_count++;
        }
    }
    for (i = player_count; i < 4; i++) {
        player_names[i][0] = 0;
    }
    if (old != player_count && player_list_window != 0) {
        ((TWindowBase *)player_list_window)->close();
        player_list_window = 0;
    }
    pl2 = get_player_by_client_id(local_client_id);
    if (pl2 != NULL && pl2->get_floor() == get_current_floor()) {
        if (xz_distance_squared(&pl2->position, &position) <= (25.0f + warp_range) * (25.0f + warp_range)) {
            if (TObjWarpBossMulti::is_flag_clear(pl2) != 0) {
                pl2->check_technique_flag();
            }
        } else if (TObjWarpBossMulti::is_flag_clear(pl2) == 0) {
            pl2->has_item_flag_4096();
        }
    }
}

void TObjCityMainWarpChallenge::update_challenge_state() {
    s32 r;
    if (player_on_dest_floor == 1) {
        next_state = 3;
        return;
    }
    switch (state_step) {
    case 0:
        warp_triggered = 0;
        warp_effect_timer = 0;
        state_step = 1;
        model = city_common_model_archive->models[0].model;
        motion = city_common_model_archive->motions[5].motion;
        break;
    case 1:
        if (((u32 (*)(f32))find_local_player_in_range__16TObjCityMainWarpFf)(warp_range) != 0) {
            sub_801875F8__25TObjCityMainWarpChallengeFv(this);
            trigger_warp_effect(local_client_id);
            state_step = 2;
            break;
        }
        if (menu_window != 0) {
            ((TWindowBase *)menu_window)->close();
            menu_window = 0;
        }
        if (player_list_window != 0) {
            ((TWindowBase *)player_list_window)->close();
            player_list_window = 0;
        }
        break;
    case 2:
        sub_801875F8__25TObjCityMainWarpChallengeFv(this);
        if (yes_no_window != 0) {
            if (((TWindowSubComCard *)yes_no_window)->get_card_data() != 0) {
                state_step = 3;
            } else if (((TWindowMessageYesNo *)yes_no_window)->is_child_visible() != 0) {
                r = ((TWindowSubComCard *)yes_no_window)->get_slot_or_neg1();
                if (r == 0) {
                    trigger_warp_effect(local_client_id);
                    warp_triggered = 1;
                    send_6x6A_set_boss_warp_flags(1);
                    state_step = 5;
                } else if (r == 1) {
                    state_step = 3;
                }
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF &&
            ((s32 (*)())is_local_client_floor_leader)() != 0 && are_all_players_in_range() != 0) {
            send_6x6A_set_boss_warp_flags(2);
            state_step = 5;
        }
        if (state_step != 2) {
            close_windows();
        }
        break;
    case 3:
        TObjCityMainWarp::notify_player_warp(this, local_client_id);
        state_step = 4;
        break;
    case 4:
        if (((u32 (*)(f32))find_local_player_in_range__16TObjCityMainWarpFf)(warp_range) == 0) {
            state_step = 1;
            break;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF &&
            ((s32 (*)())is_local_client_floor_leader)() != 0 && are_all_players_in_range() != 0) {
            send_6x6A_set_boss_warp_flags(2);
            state_step = 5;
        }
        break;
    case 5:
        break;
    case -1:
        close_windows__25TObjCityMainWarpChallengeFv();
        break;
    }
}

}
