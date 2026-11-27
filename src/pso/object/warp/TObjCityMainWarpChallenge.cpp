#include "pso/object/city/CityTraffic.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <string.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/technique/TTelepipeSelectField.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/TextureState.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/DebugFont.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/math/MatrixReflect.h"
#include "pso/network/client_id.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/enemy/TObjEnemyCustom.h"
const char *TObjCityMainWarpChallenge::class_name = "TObjCityMainWarpChallenge";
static const char debug_next_stage_format[] = "<- NEXT STAGE No.%d";
static const char debug_key_id_format_challenge[] = "<- KEY ID : %d";



TObjCityMainWarpChallenge::TObjCityMainWarpChallenge(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = class_name;
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
    model = (saddr)city_common_model_archive->models[0].model;
    motion = city_common_model_archive->motions[5].motion;
    if (field_collider != NULL) {
        field_collider->queue_destruction();
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
            if ((1.0f + frame) >= (f32)motion->nbFrame) {
                frame = 0.0f;
            }
        }
    }
}

void TObjCityMainWarpChallenge::render() {
    if (dest_floor == 0xE) {
        if (xz_distance_squared(&camera_ctrl_instance->pos, &this->position) > 160000.0f) {
            return;
        }
        goto block_4;
    }
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
block_4:
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(city_common_model_archive->models[12].model);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(city_common_model_archive->models[0].model, city_common_model_archive->motions[5].motion, (f32)frame);
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
    set_debug_text_color(0xFF00FF);
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        debug_printf_at(0x130020, debug_next_stage_format, set_params[0]);
    }
    debug_printf_at(0x130021, debug_key_id_format_challenge, key_id);
}

void TObjCityMainWarpChallenge::update_state() {

    switch (state) {
    case 0:
        update_challenge_state();
        return;
    case 1:
        update_warp_sequence();
        return;
    case 2:
        update_area_transfer();
        return;
    case 3:
        update_warp_window();
        return;
    case 4:
        update_floor_switch_state();
        return;
    }
}

void TObjCityMainWarpChallenge::update_warp_dialogs() {
    s32 i;
    s32 j;
    u32 color;
    TObjPlayer *player;
    f32 pos[2];

    switch (this->state) {
    case 0:
        if (this->yes_no_window == 0) {
            this->yes_no_window = TWindowMessageYesNo::create(this, local_client_id, NULL, NULL);
            if (this->yes_no_window != 0) {
                this->yes_no_window->open_yes_no_prompt_with_text(TWindowSubStatusDisp::get_message_10(0x41), get_window_layout_position(0x36), 368.0f);
                this->yes_no_window->set_menu_selected_index(1);
                this->yes_no_window->set_choice_menu_flag70_bit10();
                TWindowCtrl::begin_client_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        }
        break;
    case 1:
        if (this->yes_no_window == 0) {
            this->yes_no_window = TWindowMessageYesNo::create(this, local_client_id, NULL, NULL);
            if (this->yes_no_window != 0) {
                initialize_option_dialog(this->yes_no_window, TWindowSubStatusDisp::get_message_10(0x42), get_window_layout_position(0x36), 368.0f);
            }
        }
        break;
    }
    if (this->player_list_window == 0) {
        pos[0] = 229.0f;
        pos[1] = 104.0f;
        this->player_list_window = create_check_box_window_for_local_client(get_window_layout_position(0x34), pos);
        if (this->player_list_window != 0) {
            this->player_list_window->disable_input();
            this->player_list_window->set_close_flag();
            for (i = 0; i < this->player_count; i++) {
                this->player_list_window->dispatch_without_flags(this->player_names[i], i);
            }
        }
        request_active_window_close();
    }
    if (this->player_list_window != 0) {
        for (j = 0; j < this->player_count; j++) {
            this->player_list_window->advance_matching_entries(this->player_in_range[j] != 0, j);
            color = 0xF0F0F0FF;
            if (this->state == 1 && (player = get_player_by_client_id(j)) != NULL &&
                (player)->check_player_flag1() != 0) {
                color = 0xFFFF00FF;
            }
            this->player_list_window->set_item_color(color, j);
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
            strcpy(player_names[player_count], pl->appearance.name);
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
                pl2->set_flag_4096();
            }
        } else if (TObjWarpBossMulti::is_flag_clear(pl2) == 0) {
            pl2->clear_flag_4096();
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
        model = (saddr)city_common_model_archive->models[0].model;
        motion = city_common_model_archive->motions[5].motion;
        break;
    case 1:
        if (find_local_city_warp_player(this, warp_range) != 0) {
            update_warp_dialogs();
            trigger_warp_effect(local_client_id);
            state_step = 2;
            break;
        }
        if (menu_window != NULL) {
            menu_window->close();
            menu_window = NULL;
        }
        if (player_list_window != 0) {
            ((TWindowBase *)player_list_window)->close();
            player_list_window = 0;
        }
        break;
    case 2:
        update_warp_dialogs();
        if (yes_no_window != 0) {
            if (yes_no_window->is_cancelled() != 0) {
                state_step = 3;
            } else if (yes_no_window->is_child_visible() != 0) {
                r = yes_no_window->get_selected_value();
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
            is_local_client_floor_leader() != 0 && are_all_players_in_range() != 0) {
            send_6x6A_set_boss_warp_flags(2);
            state_step = 5;
        }
        if (state_step != 2) {
            close_windows();
        }
        break;
    case 3:
        release_warp_effect(local_client_id);
        state_step = 4;
        break;
    case 4:
        if (find_local_city_warp_player(this, warp_range) == 0) {
            state_step = 1;
            break;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF &&
            is_local_client_floor_leader() != 0 && are_all_players_in_range() != 0) {
            send_6x6A_set_boss_warp_flags(2);
            state_step = 5;
        }
        break;
    case 5:
        break;
    case -1:
        close_windows();
        break;
    }
}
