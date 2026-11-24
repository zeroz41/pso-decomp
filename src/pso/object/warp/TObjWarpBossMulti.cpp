#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/warp/TObjWarpBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/warp/TObjWarpBoss.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/ControllerInputState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/network/client_id.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include <string.h>
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/unk/text_803D853C.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"


#pragma defer_codegen on
const char *boss_warp_model_names[4] = {
    "fs_obj_warp_dai.gj", "fs_obj_warp_dai_beam.gj", "fs_obj_warp_dai_beam02.gj", NULL,
};
const char *boss_warp_motion_names[3] = { "fs_obj_warp_dai_beam.njm", "fs_obj_warp_dai_beam02.njm", NULL };
BmlResourceDescriptor lbl_804B94AC = { "bm_obj_warpboss.bml", boss_warp_model_names, boss_warp_motion_names, 3, 2 };

const char *ancient_boss_warp_model_names[4] = {
    "fe_obj_df_warp_gawa.gj", "de_obj_df_warp_beam.gj", "de_obj_df_warp_sbeam.gj", NULL,
};
const char *ancient_boss_warp_motion_names[3] = { "de_obj_df_warp_beam.njm", "de_obj_df_warp_sbeam.njm", NULL };
BmlResourceDescriptor lbl_804B94D8 = {
    "bm_obj_warpboss_ancient.bml", ancient_boss_warp_model_names, ancient_boss_warp_motion_names, 3, 2,
};

const char *jungle_boss_warp_model_names[3] = { "fe_obj_warp4_dodai.gj", "fe_obj_warp4_jogo_light.gj", NULL };
__declspec(section ".data") const char *jungle_boss_warp_motion_names[2] = { "fe_obj_warp4_jogo_light.njm", NULL };
BmlResourceDescriptor lbl_804B94FC = {
    "bm_obj_warpboss_jungle.bml", jungle_boss_warp_model_names, jungle_boss_warp_motion_names, 2, 1,
};

const char *TObjWarpBoss__name = "TObjWarpBoss";
const char *TObjWarpBossMulti__name = "TObjWarpBossMulti";


extern "C" {
s32 fn_80248994(void *, u32, int);
void request_active_window_close(void);
s32 is_local_client_floor_leader();
TObjPlayer *find_local_boss_warp_player(TObjAreaWarp *warp, f32 range);
BmlResource *boss_warp_resource_bundle;
NJS_OBJECT *boss_warp_base_model;
NJS_OBJECT *boss_warp_confirmation_model;
NJS_OBJECT *warp_boss_model;
AnimationMotion *warp_boss_motion;
AnimationMotion *warp_boss_bml_motion;
NJS_TEXLIST *boss_warp_base_textures;
NJS_TEXLIST *boss_warp_effect_textures;
extern "C" {
void release_boss_warp_resources(void);
}

const char lbl_8044663C[] = "<- NEXT STAGE No.";
const char lbl_80446650[] = "<- KEY ID : %d";
extern u32 player_slot_table[];
extern s32 lbl_805D55C0;




}
void handle_6x6A_set_boss_warp_flags(void *packet);
// Function definitions in reverse address order (defer_codegen emits them reversed).

NJS_OBJECT *get_boss_warp_base_model(void) { return boss_warp_base_model; }

NJS_OBJECT *get_boss_warp_confirmation_model(void) { return boss_warp_confirmation_model; }

NJS_OBJECT *get_boss_warp_model(void) { return warp_boss_model; }

AnimationMotion *get_boss_warp_motion(void) { return warp_boss_motion; }

AnimationMotion *get_boss_warp_bml_motion(void) { return warp_boss_bml_motion; }

NJS_TEXLIST *get_boss_warp_base_textures(void) { return boss_warp_base_textures; }

NJS_TEXLIST *get_boss_warp_effect_textures(void) { return boss_warp_effect_textures; }

void load_boss_warp_resources() {
    s32 area;
    BmlResource *resource;
    area = get_current_floor_area();
    if (area >= 8 && area <= 0xA) {
        resource = new BmlResource(5, &lbl_804B94D8, 0, 0, NULL);
        boss_warp_resource_bundle = resource;
        boss_warp_base_model = (NJS_OBJECT *)get_bml_model((BmlResource *)resource, 0);
        boss_warp_confirmation_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 2);
        warp_boss_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 1);
        warp_boss_motion = get_bml_motion(boss_warp_resource_bundle, 1);
        warp_boss_bml_motion = get_bml_motion(boss_warp_resource_bundle, 0);
        boss_warp_base_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 2);
        boss_warp_effect_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 2);
        return;
    }
    if (TContainerAncient01::is_global_state_in_table() != 0 || area == AREA_SEABED_UPPER || area == AREA_SEABED_LOWER) {
        resource = new BmlResource(5, &lbl_804B94FC, 0, 0, NULL);
        boss_warp_resource_bundle = resource;
        boss_warp_base_model = (NJS_OBJECT *)get_bml_model((BmlResource *)resource, 0);
        boss_warp_confirmation_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 1);
        warp_boss_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 1);
        warp_boss_motion = get_bml_motion(boss_warp_resource_bundle, 0);
        warp_boss_bml_motion = get_bml_motion(boss_warp_resource_bundle, 0);
        boss_warp_base_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 0);
        boss_warp_effect_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 0);
        return;
    }
    resource = new BmlResource(5, &lbl_804B94AC, 0, 0, NULL);
    boss_warp_resource_bundle = resource;
    boss_warp_base_model = (NJS_OBJECT *)get_bml_model((BmlResource *)resource, 0);
    boss_warp_confirmation_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 2);
    warp_boss_model = (NJS_OBJECT *)get_bml_model((BmlResource *)boss_warp_resource_bundle, 1);
    warp_boss_motion = get_bml_motion(boss_warp_resource_bundle, 1);
    warp_boss_bml_motion = get_bml_motion(boss_warp_resource_bundle, 0);
    boss_warp_base_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 2);
    boss_warp_effect_textures = get_bml_texlist((BmlResource *)boss_warp_resource_bundle, 2);
}

void release_boss_warp_resources(void) {
    if (boss_warp_resource_bundle != 0) {
        delete boss_warp_resource_bundle;
        boss_warp_resource_bundle = 0;
    }
}

void *TObjWarpBoss::create(void *set_data) {
    if ((TRaderMapCore::is_not_split_screen() == 0) && (get_main_phase() == 0xE)) {
        return TObjWarpBossMulti::create(set_data);
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return TObjWarpBossMulti::create(set_data);
    }
    return new TObjWarpBoss(tl_05, set_data);
}

TObjWarpBoss::TObjWarpBoss(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    int i;
    m_name = TObjWarpBoss__name;
    frame = 0.0f;
    warp_range = 19.0f;
    dest_floor = get_boss_warp_destination();
    bodies = NULL;
    register_entity_by_id(this);
    player_list_window = NULL;
    yes_no_window = NULL;
    local_player_in_range = 0;
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
    model = NULL;
    motion = NULL;
    if (field_collider != NULL) {
        ((TObject *)field_collider)->queue_destruction();
        field_collider = NULL;
    }
    for (i = 0; i < 4; i++) {
        player_in_range[i] = 0;
    }
}

TObjWarpBoss::~TObjWarpBoss() {
    unregister_object_by_id();
    close_windows();
}

void TObjWarpBoss::run_task() {
    if (TObjPlayer::check_demo_mode() != 1) {
        if (!(state_flags & 1) && (state != next_state)) {
            if (state_step != -1) {
                state_step = -1;
                update();
            }
            state = next_state;
            state_step = 0;
        }
        update_warp_occupants();
        update();
        if (motion != NULL) {
            frame += 4.0f;
            if ((1.0f + frame) >= (f32)motion->frameCount) {
                frame = 0.0f;
            }
        }
    }
}

void TObjWarpBoss::render() {
    if (dest_floor == 0xE) {
        if (xz_distance_squared(&camera_ctrl_instance->pos, &position) > 160000.0f) {
            return;
        }
        goto block_4;
    }
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
block_4:
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(boss_warp_base_textures);
        draw_ginja_object(boss_warp_base_model);
        if (model != NULL) {
            TParticleCtrl::begin_effect_render();
            TObjFish::set_global_param(boss_warp_effect_textures);
            draw_ginja_model_with_motion(model, motion, frame);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TObjWarpBoss::debug_print_area_num() {
    s32 id = set_params[1];
    if (id < 0 || id > 0xFF) {
        key_id = -1;
    } else {
        key_id = id;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        debug_printf_at(0x130020, lbl_8044663C);
    }
    debug_printf_at(0x130021, lbl_80446650, key_id);
}

void TObjWarpBoss::update() {

    update_warp_boss_visibility();
    switch (state) {
    case 0:
        this->update_warp_confirmation();
        return;
    case 1:
        this->update_warp_state();
        return;
    case 2:
        this->update_state();
        return;
    case 3:
        warp_boss_handle_window();
        return;
    case 4:
        this->update_floor_switch_state();
        return;
    }
}

void TObjWarpBoss::update_warp_dialogs() {
    void *player;
  s32 i;
  int j;
  u32 color;
  f32 pos[2];
  void *p;
  switch (state)
  {
    case 0:
      if ((TObjWarpBossMulti::is_lobby_active() == 0) && (yes_no_window == 0))
    {
      yes_no_window = TWindowMessageYesNo::create(this, local_client_id, (void *)0, (void *)0);
      if (yes_no_window != 0)
      {
        ((TWindowMessageYesNo *)yes_no_window)->open_yes_no_prompt_with_text((saddr)(TWindowSubStatusDisp::get_message_10(0x41)), (saddr)get_window_layout_position(0x36), 368.0f);
        ((TWindowMessageYesNo *)yes_no_window)->set_menu_selected_index(1);
        ((TWindowMessageYesNo *)yes_no_window)->set_choice_menu_flag70_bit10();
        begin_player_keyboard_hold(local_client_id);
        request_active_window_close();
        TWindowCtrl::suppress_slot(local_client_id);
      }
    }
      break;
    case 1:
      if (yes_no_window == 0)
    {
      i = 0x36;
      yes_no_window = TWindowMessageYesNo::create(this, local_client_id, (void *)0, (void *)0);
      if (yes_no_window != 0)
      {
        initialize_option_dialog(yes_no_window, (saddr)TWindowSubStatusDisp::get_message_10(0x42), (saddr)get_window_layout_position(i), 368.0f);
      }
    }
      break;
  }
  if (player_list_window == 0)
  {
    pos[0] = 229.0f;
    pos[1] = 104.0f;
    player_list_window = create_check_box_window_for_local_client(get_window_layout_position(0x34), (const void *)pos);
    if (player_list_window != 0)
    {
      ((TWindowSubTradeMain *)player_list_window)->set_visible();
      ((TWindowSubTradeMain *)player_list_window)->set_close_flag();
      for (i = 0; i < player_count; i++)
      {
        TWindowSubStatusDisp::dispatch_without_flags((saddr)player_list_window, (saddr)player_names[i], (s32)i);
      }
    }
    request_active_window_close();
  }
  if (player_list_window != 0)
  {
    for (j = 0; j < player_count; j++)
    {
            ((THunterGuildSeqOffline *)player_list_window)->advance_matching_entries(player_in_range[j] != 0, j);
      color = 0xF0F0F0FF;
      TObjPlayer *player;
      if (state == 1 && (player = get_player_by_client_id(j)) != NULL && player->check_player_flag1() != 0)
      {
        color = 0xFFFF00FF;
      }
      fn_80248994(player_list_window, color, j);
    }
  }
}

void TObjWarpBoss::update_warp_occupants() {
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
    if (old != player_count && player_list_window != NULL) {
        ((TWindowBase *)player_list_window)->close();
        player_list_window = NULL;
    }
    pl2 = get_player_by_client_id(local_client_id);
    if (pl2 != NULL && pl2->get_floor() == get_current_floor()) {
        if (xz_distance_squared(&pl2->position, &position) <= (25.0f + warp_range) * (25.0f + warp_range)) {
            if (TObjWarpBossMulti::is_flag_clear(pl2) != 0) {
                local_player_in_range = 1;
                pl2->set_flag_4096();
            }
        } else if (TObjWarpBossMulti::is_flag_clear(pl2) == 0 && local_player_in_range != 0) {
            local_player_in_range = 0;
            pl2->clear_flag_4096();
        }
    }
}

void TObjWarpBoss::update_warp_confirmation() {
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
        model = boss_warp_confirmation_model;
        motion = warp_boss_motion;
        break;
    case 1:
        if (sub_8019E418() == 0 && find_local_boss_warp_player(this, warp_range) != NULL) {
            update_warp_dialogs();
            warp_player(local_client_id);
            state_step = 2;
            break;
        }
        if (menu_window != 0) {
            ((TWindowBase *)menu_window)->close();
            menu_window = 0;
        }
        if (player_list_window != NULL) {
            ((TWindowBase *)player_list_window)->close();
            player_list_window = NULL;
        }
        break;
    case 2:
        update_warp_dialogs();
        if (yes_no_window != NULL) {
            if (((TWindowMessageYesNo *)yes_no_window)->is_cancelled() != 0) {
                state_step = 3;
            } else if (((TWindowMessageYesNo *)yes_no_window)->is_child_visible() != 0) {
                r = ((TWindowMessageYesNo *)yes_no_window)->get_selected_value();
                if (r == 0) {
                    warp_player(local_client_id);
                    warp_triggered = 1;
                    send_cmd_6A(1);
                    state_step = 5;
                } else if (r == 1) {
                    state_step = 3;
                }
            }
        }
        if (sub_8019E418() != 0) {
            state_step = 3;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF && is_local_client_floor_leader() != 0 && are_all_players_in_range() != 0) {
            send_cmd_6A(2);
            state_step = 5;
        }
        if (state_step != 2) {
            close_windows();
        }
        break;
    case 3:
        TObjWarpBossMulti::notify_player(this, local_client_id);
        state_step = 4;
        break;
    case 4:
        if (find_local_boss_warp_player(this, warp_range) == NULL) {
            state_step = 1;
            break;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF && is_local_client_floor_leader() != 0 && are_all_players_in_range() != 0) {
            send_cmd_6A(2);
            state_step = 5;
        }
        break;
    case -1:
        close_windows();
        break;
    case 5:
        break;
    }
}

void TObjWarpBoss::update_warp_state() {
    s32 var_r3;

    switch (state_step) {
    case 2:
        break;
    case 0:
        warp_countdown = 0x12C;
        play_sound_effect(0x40003205, &position, 0, 0);
        state_step = 1;
        model = warp_boss_model;
        motion = warp_boss_bml_motion;
        return;
    case 1:
        if (find_local_boss_warp_player(this, warp_range) != NULL) {
            update_warp_dialogs();
            if (warp_triggered == 0) {
                warp_player(local_client_id);
                warp_triggered = 1;
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0) {
            warp_countdown--;
            if (warp_countdown <= 0) {
                var_r3 = 1;
            } else {
                var_r3 = are_all_players_in_range();
            }
            if (var_r3 != 0) {
                send_cmd_6A(2);
                state_step = 2;
            }
        }
        break;
    case -1:
        close_windows();
        break;
    }
}

void TObjWarpBoss::update_state() {
    TObjPlayer *player;

    switch (state_step) {
    case 0:
        state_timer = 0x96;
        state_step = 1;
        state_flags |= 1;
        model = warp_boss_model;
        motion = warp_boss_bml_motion;
        return;
    case 1:
        if (TObjWarpBossMulti::get_boss_warp_flag() == 0) {
            player = find_local_boss_warp_player(this, warp_range);
            if (player != 0) {
                TObjWarpBossMulti::notify_player(this, local_client_id);
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

void TObjWarpBoss::warp_boss_handle_window() {

    switch (state_step) {
    case 0:
        state_step = 1;
        model = NULL;
        return;
    case 1:
        if (find_local_boss_warp_player(this, warp_range) != NULL) {
            if (menu_window == 0) {
                menu_window = create_window_menu_default((saddr)get_window_layout_position(0x35), 7);
                if (menu_window != 0) {
                    ((TWindowMenu *)menu_window)->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x40), 0, 0, -1);
                    ((TWindowMenu *)menu_window)->set_flag_40();
                    ((TWindowMenu *)menu_window)->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu_window));
                }
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        } else {
            if (menu_window != 0) {
                ((TWindowBase *)menu_window)->close();
                menu_window = 0;
            }
            end_player_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
        if (player_on_dest_floor == 0) {
            next_state = 0;
        }
        return;
    case -1:
        if (menu_window != 0) {
            ((TWindowBase *)menu_window)->close();
            menu_window = 0;
        }
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
        break;
    }
}

void TObjWarpBoss::update_floor_switch_state() {
    switch (state_step) {
    case 0:
        model = NULL;
        state_step = 1;
        return;
    case 1:
        if (key_id >= 0 && is_current_floor_switch_set((u16)key_id) == 1) {
            next_state = 0;
        }
        return;
    case -1:
        break;
    }
}

void TObjWarpBoss::warp_player(s32 local_client_id) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_impose_hold(player, -1);
        obj_set_flag_20000(player);
        warp_effect_timer = 0x12C;
    }
}

void TObjWarpBossMulti::notify_player(void *arg0, s32 local_client_id) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_release_hold(player);
        obj_clear_flag30_20000(player);
    }
}

void TObjWarpBoss::send_cmd_6A(u16 value) {
    G_SetBossWarpFlags_6x6A pkt;
    ((TWindowSubTradeMain *)&pkt)->init_pkt_cmd_6A();
    pkt.header.entity_id = entity_id;
    pkt.flags = value;
    ((TWindowSubTradeMain *)&pkt)->send_60_update();
}

void handle_6x6A_set_boss_warp_flags(void *packet) {
    TObjCollidable *entity;

    ((TWindowSubTradeMain *)packet)->bswap_6x6A_packet();
    entity = find_entity_by_id(((G_SetBossWarpFlags_6x6A *)packet)->header.entity_id);
    if (entity != NULL) {
        ((TObjWarpBoss *)entity)->next_state = ((G_SetBossWarpFlags_6x6A *)packet)->flags;
    }
}

void TObjWarpBoss::close_windows() {
    if (yes_no_window != NULL) {
        ((TWindowMessageYesNo *)yes_no_window)->close();
        yes_no_window = NULL;
    }
    if (menu_window != 0) {
        ((TWindowBase *)menu_window)->close();
        menu_window = 0;
    }
    if (player_list_window != NULL) {
        ((TWindowBase *)player_list_window)->close();
        player_list_window = NULL;
    }
    end_player_keyboard_hold(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::unsuppress_slot(local_client_id);
}

#pragma push
#pragma fp_contract on
TObjPlayer *find_local_boss_warp_player(TObjAreaWarp *warp, f32 range) {
    s32 current_floor;
    s32 temp_r3b;
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        current_floor = get_current_floor();
        temp_r3b = player->get_floor();
        if ((temp_r3b == current_floor) && (xz_distance_squared(&warp->position, &player->position) < (range * range))) {
            return player;
        }
    }
    return 0;
}
#pragma pop

s32 TObjWarpBoss::are_all_players_in_range() {
    s32 ok = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        TObjPlayer *p = get_player_by_client_id(i);
        if (p != 0) {
            if (p->get_floor() != get_current_floor() || xz_distance_squared(&p->position, &position) > warp_range * warp_range) {
                ok = 0;
            }
        }
    }
    return ok;
}

s32 TObjWarpBossMulti::get_boss_warp_flag() {
    return ((get_main_phase() - 0xF) == 0) ? lbl_805D55C0 : 0;
}

s32 TObjWarpBossMulti::is_lobby_active() {
    return TLobby::get_state() ? 1 : 0;
}

s32 TObjWarpBoss::sub_8019E418() {
    if (TObjWarpBossMulti::is_lobby_active() == 0) {
        return 0;
    }
    if ((controller_input_state.controllers[0].stick_magnitude > 0.25f) || (find_local_boss_warp_player(this, warp_range) == NULL)) {
        return 1;
    }
    return 0;
}

void TObjWarpBoss::update_warp_boss_visibility() {
    TObjPlayer *player;
    s32 var_r30;

    player = get_player_by_client_id(local_client_id);
    var_r30 = 1;
    if ((player != NULL) && (player->has_flag_0x800() != 0)) {
        var_r30 = 0;
    }
    if ((player != NULL) && (player->is_controls_locked() != 0)) {
        var_r30 = 0;
    }
    if (var_r30 == 0) {
        if (yes_no_window != NULL) {
            ((TObject *)yes_no_window)->suspend_update();
            ((TObject *)yes_no_window)->disallow_rendering();
        }
        if (menu_window != 0) {
            ((TObject *)menu_window)->suspend_update();
            ((TObject *)menu_window)->disallow_rendering();
        }
        if (player_list_window != NULL) {
            ((TObject *)player_list_window)->suspend_update();
            ((TObject *)player_list_window)->disallow_rendering();
        }
    } else {
        if (yes_no_window != NULL) {
            ((TObject *)yes_no_window)->clear_update_suspension();
            ((TObject *)yes_no_window)->allow_rendering();
        }
        if (menu_window != 0) {
            ((TObject *)menu_window)->clear_update_suspension();
            ((TObject *)menu_window)->allow_rendering();
        }
        if (player_list_window != NULL) {
            ((TObject *)player_list_window)->clear_update_suspension();
            ((TObject *)player_list_window)->allow_rendering();
        }
    }
}

TObjWarpBossMulti::TObjWarpBossMulti(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    int i;
    m_name = TObjWarpBossMulti__name;
    dest_floor = get_boss_warp_destination();
    bodies = NULL;
    register_entity_by_id(this);
    update();
    init_warp_params();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 19.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
    warp_range = 19.0f;
    for (i = 0; i < 4; i++) {
        player_in_range[i] = 0;
    }
}

TObjWarpBossMulti::~TObjWarpBossMulti() {
    unregister_object_by_id();
}

void TObjWarpBossMulti::run_task() {
    s32 i;
    uaddr pl;
    f32 r;

    for (i = 0; i < 4; i++) {
        pl = player_slot_table[i];
        if (pl != 0U && TObjPlayer::is_locally_controlled((void *)pl) != 0) {
            if (((TObjPlayer *)pl)->get_floor() == get_current_floor()) {
                if (xz_distance_squared(&((TObjPlayer *)pl)->position, &position) <= (r = 25.0f + warp_range) * r) {
                    if (TObjWarpBossMulti::is_flag_clear((void*)pl) != 0) {
                        player_in_range[i] = 1;
                        ((TObjPlayer *)pl)->set_flag_4096();
                    }
                } else if (TObjWarpBossMulti::is_flag_clear((void*)pl) == 0) {
                    if (player_in_range[i] != 0) {
                        player_in_range[i] = 0;
                        ((TObjPlayer *)pl)->clear_flag_4096();
                    }
                }
            }
        }
    }
    if (key_id >= 0) {
        if (is_current_floor_switch_set((u16)key_id) == 1) {
            state = 1;
        } else {
            state = 0;
        }
    }
    switch (state) {
    case 0:
        frame += frame_step;
        if (frame > (motion->frameCount - 1)) {
            frame = 0.0f;
        }
        break;
    case 1:
        frame += frame_step;
        if (frame > (bml_motion->frameCount - 1)) {
            frame = 0.0f;
        }
        handle_area_selection();
        break;
    }
}

void TObjWarpBossMulti::render() {
    if ((s32) dest_floor == 0xE) {
        if (xz_distance_squared(&camera_ctrl_instance->pos, &position) > 160000.0f) {
            return;
        }
        goto block_4;
    }
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
block_4:
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(model_handle));
        draw_ginja_object(base_model);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(effect_textures));
        switch (state) {
        case 0:
            draw_ginja_model_with_motion(confirmation_model, motion, frame);
            break;
        case 1:
            draw_ginja_model_with_motion(warp_model, bml_motion, frame);
            break;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjWarpBossMulti::debug_print_area_num() {
    update();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        debug_printf_at(0x130020, lbl_8044663C);
    }
    debug_printf_at(0x130021, lbl_80446650, key_id);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjWarpBossMulti::update() {
    s32 temp_r0;

    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        key_id = -1;
    } else {
        temp_r0 = set_params[1];
        if ((temp_r0 < 0) || (temp_r0 > 0xFF)) {
            key_id = -1;
        } else {
            key_id = temp_r0;
        }
    }
    if (key_id >= 0) {
        state = 0;
        return;
    }
    state = 1;
}

void TObjWarpBossMulti::init_warp_params() {
    base_model = get_boss_warp_base_model();
    confirmation_model = get_boss_warp_confirmation_model();
    warp_model = get_boss_warp_model();
    motion = get_boss_warp_motion();
    bml_motion = get_boss_warp_bml_motion();
    model_handle = get_boss_warp_base_textures();
    effect_textures = get_boss_warp_effect_textures();
    frame = 0.0f;
    frame_step = 4.0f;
}

void *TObjWarpBossMulti::create(void *set_data) {
    return new TObjWarpBossMulti(tl_05, set_data);
}
