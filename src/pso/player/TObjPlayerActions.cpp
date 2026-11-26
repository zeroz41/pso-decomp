#include "pso/player/PhotonBlastRequests.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/object/TActorLight.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/vector.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/technique/TTecReverserEff.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/weapon/TItemWeaponDrillLauncher.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TDeathTintFade.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/network/protocol/subcommand_validation_photon_blast.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecReverser.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/enemy/TObjEneBeastBase.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/Palettex.h"
#include "pso/player/TForceOperate.h"
#include "pso/player/TObjPlayer_8022C6C4.h"
#include "pso/ui/charcreate/PaletteCursorAction.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/math/ScratchVectors.h"
#include "pso/system/byteswap.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerSubcommandHandlers.h"
#include "pso/item/item_pmt.h"
#include "pso/player/TObjPlayer_801AF2F0.h"


#pragma readonly_strings on




#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };
#pragma pop


#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };
#pragma pop














extern "C" {

s32 copy_attack_targets(void *dst, void *src);
s32 draw_player_status(void *, void *, const char *);
u16 get_action_palette_mode(void *, s32);
// start_action sees TObjPlayer::get_run_action as returning int (it narrows the result itself).
s32 get_run_action__10TObjPlayerFv(void *);
void update_player_action_palette(TObjPlayer *player, u8 slot);
u8 get_cast_technique_level(void *techs, s16 tech);
}
int is_android_player(void* p);
void remove_photon_blast_participant(s32 id);
void emit_heavy_attack_particles(saddr owner, u16 target_id);
extern "C" {
s32 dispatch_weapon_special_effect(void *, int, int, int);

const f64 freeze_escape_timer_scale = 0.1;
const f64 lbl_80447148 = 10430.38043493439;
extern const char *TWindowReturnCity__class_name;

}
void handle_6xB0_turn_or_move_lobby_chair(G_TurnOrMoveLobbyChair_6xAF_6xB0 *command) {
    G_MoveLobbyChair_6xB0 m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6xB0_move_lobby_chair(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if ((p != NULL) && (p->is_in_tl03_state() != 0)) {
            p->update_lobby_chair(m.angle);
            calc_direction_vector(p->rotation_y, &p->velocity, 1.0f);
        }
    }
}

void handle_6xAF_turn_or_move_lobby_chair(G_TurnOrMoveLobbyChair_6xAF_6xB0 *command) {
    G_TurnLobbyChair_6xAF m;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6xAF_turn_lobby_chair(&m.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            p->get_chair_state(m.angle);
        }
    }
}

void TObjPlayer::update_state_group() {

    clear_velocity();
    clear_state_flag();
    clear_anim_flag();
    clear_chair_seated();
    leave_chair_seat();
    set_motion_list(action_provider->get_current_motion_list());
}

void TObjPlayer::turn_toward_chair_seat() {
    s32 step;
    f32 length;
    this->rotation_y = this->interpolate_angle(this->rotation_y, this->get_chair_target_angle(), &step);
    length = normalize_vector_safe(&this->velocity) - 0.04f;
    if (length < 0.04f) {
        clear_velocity();
    } else {
        calc_direction_vector(this->rotation_y, &this->velocity, length);
    }
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::start_action_18() {
    s16 sit_action;

    this->action_state = 0x18;
    run_action_state_phase(this->mode, 6);
    if (is_action_flag_28() != 0) {
        sit_action = action_provider->get_alt_chair_sit_action();
    } else {
        sit_action = action_provider->get_chair_sit_action();
    }
    set_chair_seat_animation(sit_action);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    set_chair_seated();
    this->phase = 0;
    get_chair_state(this->rotation_y);
    create_photon_chair();
    this->set_action_state(0x18, start_action18_sub());
}


void handle_6xAB(G_CreateLobbyChair_6xAB *command) {
    G_CreateLobbyChair_6xAB m;
    TObjPlayer *p;

    m.init();
    m = *command;
    m.bswap();
    if (validate_6xAB(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            if (m.uses_alt_chair() == 0) {
                p->clear_state_flag();
            } else {
                p->set_action_flag_28();
            }
            if (m.has_keyboard() != 0) {
                p->set_anim_flag();
            }
            p->run_action_state_phase(0x18, 0);
        }
    }
}
void TObjPlayer::send_state_sync() {
    G_CreateLobbyChair_6xAB pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        if (lobby_animation == action_provider->get_alt_chair_sit_action()) {
            pkt.set_alt_chair();
        }
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            pkt.set_keyboard();
        }
        pkt.send();
    }
}

void TObjPlayer::lobby_chair_phase8_nop() {  }

void TObjPlayer::finish_chair_sit_down() {
    if (this->motion_flags & MOTION_CHAINED) {
        this->phase = 1;
    }
}

void TObjPlayer::update_lobby_chair_controls() {
    G_MoveLobbyChair_6xB0 a;
    G_TurnLobbyChair_6xAF b;
    s32 target;
    f32 amount;
    if (this->is_controls_locked() == 0 && this->phase != 0 &&
        (this->pad_binding.is_button_pressed(2) != 0 ||
         (this->is_action_flag_28() == 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x24) != 0) ||
         (this->is_action_flag_28() != 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x18) != 0))) {
        this->run_action_state_phase(1, 5);
        return;
    }
    target = this->pad_binding.get_stick_angle();
    amount = this->pad_binding.get_stick_magnitude();
    if (this->chair_seat.is_delay_6xB0_over() == 0) {
        this->chair_seat.tick_delay_6xB0();
        return;
    }
    if (this->is_controls_locked() == 0 && this->pad_binding.is_button_pressed(4) != 0) {
        if (this == NULL || this->obj_isState2_324() == 0) {
            this->chair_seat.start_delay_6xB0();
            a.init();
            a.header.client_id = this->get_entity_id();
            a.angle = target;
            a.send();
        }
    } else {
        if (this->chair_seat.is_delay_6xAF_over() == 0) {
            this->chair_seat.tick_delay_6xAF();
            return;
        }
        if (amount >= 0.1f && (this == NULL || this->obj_isState2_324() == 0)) {
            this->chair_seat.start_delay_6xAF();
            b.init();
            b.header.client_id = this->get_entity_id();
            b.angle = target;
            b.send();
        }
    }
}

int TObjPlayer::try_lobby_chair_change_action() { return try_change_action(); }

void TObjPlayer::run_lobby_chair_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_lobby_chair_change_action();
        return;
      case 2:
        update_lobby_chair_controls();
        return;
      case 3:
        finish_chair_sit_down();
        return;
      case 8:
        lobby_chair_phase8_nop();
        return;
      case 5:
        this->send_state_sync();
        return;
      case 0:
        this->start_action_18();
        return;
      case 1:
        this->turn_toward_chair_seat();
        return;
      case 6:
        this->update_state_group();
        break;
    }
  }
}

s16 TObjPlayer::select_idle_action() {
    if (this->action_provider == NULL) {
        return -1;
    }
    if ((get_player_action_provider_selector() == 0) && (TFontSmallLobby::is_lobby_floor_15() != 0)) {
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x24) != 0)) || ((is_controls_locked() == 0) && (pad_binding.is_button_held(0x400) != 0) && (pad_binding.is_button_pressed(4) != 0))) {
            return action_provider->get_chair_sit_action();
        }
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x18) != 0)) || ((is_controls_locked() == 0) && (pad_binding.is_button_held(0x400) != 0) && (pad_binding.is_button_pressed(2) != 0))) {
            return action_provider->get_alt_chair_sit_action();
        }
        if (TKeyBoardControl__sub_801A58B0() != 0) {
            if (TKeyBoardControl::is_key_down(0x40) != 0) {
                return action_provider->get_knockdown_action();
            }
            if (TKeyBoardControl::is_key_down(0x41) != 0) {
                return action_provider->get_hurt_action();
            }
            if (TKeyBoardControl::is_key_down(0x42) != 0) {
                return action_provider->get_interact_action();
            }
            if (TKeyBoardControl::is_key_down(0x43) != 0) {
                return action_provider->get_use_item_action();
            }
            if (TKeyBoardControl::is_key_down(0x44) != 0) {
                return action_provider->get_key_f5_action();
            }
            if (TKeyBoardControl::is_key_down(0x45) != 0) {
                return action_provider->get_key_f6_action();
            }
            if (TKeyBoardControl::is_key_down(0x46) != 0) {
                return action_provider->get_key_f7_action();
            }
            if (TKeyBoardControl::is_key_down(0x47) != 0) {
                return action_provider->get_key_f8_action();
            }
            if (TKeyBoardControl::is_key_down(0x48) != 0) {
                return action_provider->get_key_f9_action();
            }
            if (TKeyBoardControl::is_key_down(0x49) != 0) {
                return action_provider->get_key_f10_action();
            }
            if (TKeyBoardControl::is_key_down(0x4A) != 0) {
                return action_provider->get_key_f11_action();
            }
            if (TKeyBoardControl::is_key_down(0x4B) != 0) {
                return action_provider->get_key_f12_action();
            }
            if (TKeyBoardControl::is_key_down(0x1C) != 0) {
                return action_provider->get_death_action();
            }
            if (TKeyBoardControl::is_key_down(0x2E) != 0) {
                return action_provider->get_lock_on_idle_action();
            }
            if (TKeyBoardControl::is_key_down(0x2F) != 0) {
                return action_provider->get_key_6_action();
            }
            if (TKeyBoardControl::is_key_down(0x30) != 0) {
                return action_provider->get_key_7_action();
            }
            if (TKeyBoardControl::is_key_down(0x31) != 0) {
                return action_provider->get_key_8_action();
            }
            if (TKeyBoardControl::is_key_down(0x32) != 0) {
                return action_provider->get_key_9_action();
            }
            if (TKeyBoardControl::is_key_down(0x33) != 0) {
                return action_provider->get_key_0_action();
            }
            if (TKeyBoardControl::is_key_down(0x17) != 0) {
                return action_provider->get_key_h_action();
            }
            if (TKeyBoardControl::is_key_down(0x11) != 0) {
                return action_provider->get_key_b_action();
            }
            if (TKeyBoardControl::is_key_down(0x1E) != 0) {
                return action_provider->get_key_o_action();
            }
            if (TKeyBoardControl::is_key_down(0x1D) != 0) {
                return action_provider->get_key_n_action();
            }
            if (TKeyBoardControl::is_key_down(0x20) != 0) {
                return action_provider->get_key_q_action();
            }
            if (TKeyBoardControl::is_key_down(0x19) != 0) {
                return action_provider->get_key_j_action();
            }
            if (TKeyBoardControl::is_key_down(0x21) != 0) {
                return action_provider->get_key_r_action();
            }
            if (TKeyBoardControl::is_key_down(0x1A) != 0) {
                return action_provider->get_key_k_action();
            }
            if (TKeyBoardControl::is_key_down(0x26) != 0) {
                return action_provider->get_key_w_action();
            }
            if (TKeyBoardControl::is_key_down(0x22) != 0) {
                return action_provider->get_key_s_action();
            }
            if (TKeyBoardControl::is_key_down(0x23) != 0) {
                return action_provider->get_key_t_action();
            }
            if (TKeyBoardControl::is_key_down(0x12) != 0) {
                return action_provider->get_key_c_action();
            }
            if (TKeyBoardControl::is_key_down(0x13) != 0) {
                return action_provider->get_key_d_action();
            }
            if (TKeyBoardControl::is_key_down(0x15) != 0) {
                return action_provider->get_key_f_action();
            }
            if (TKeyBoardControl::is_key_down(0x16) != 0) {
                return action_provider->get_key_g_action();
            }
            if (TKeyBoardControl::is_key_down(0x28) != 0) {
                return action_provider->get_key_y_action();
            }
            if (TKeyBoardControl::is_key_down(0x1F) != 0) {
                return action_provider->get_key_p_action();
            }
            if (TKeyBoardControl::is_key_down(0x10) != 0) {
                return action_provider->get_key_a_action();
            }
            if (TKeyBoardControl::is_key_down(0x14) != 0) {
                return action_provider->get_key_e_action();
            }
            if (TKeyBoardControl::is_key_down(0x29) != 0) {
                return action_provider->get_key_z_action();
            }
            if (TKeyBoardControl::is_key_down(0x27) != 0) {
                return action_provider->get_key_x_action();
            }
            if (TKeyBoardControl::is_key_down(0x25) != 0) {
                return action_provider->get_key_v_action();
            }
            if (TKeyBoardControl::is_key_down(0x1B) != 0) {
                return action_provider->get_key_l_action();
            }
            if (TKeyBoardControl::is_key_down(0x2A) != 0) {
                return action_provider->get_key_1_action();
            }
            if (TKeyBoardControl::is_key_down(0x2B) != 0) {
                return action_provider->get_key_2_action();
            }
            if (TKeyBoardControl::is_key_down(0x2C) != 0) {
                return action_provider->get_key_3_action();
            }
            if (TKeyBoardControl::is_key_down(0x2D) != 0) {
                return action_provider->get_key_4_action();
            }
            goto block_109;
        }
        goto block_109;
    }
block_109:
    return get_no_action();
}

void handle_6xB1(void) {  }

void TObjPlayer::update_dispatch_v76() {

    clear_velocity();
    clear_anim_flag();
    clear_lobby_pose_hold();
    set_motion_list(action_provider->get_current_motion_list());
}

void TObjPlayer::lobby_animation_phase1_nop() {  }

void TObjPlayer::do_action() {
    this->action_state = 0x17;
    run_action_state_phase(this->mode, 6);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    if (obj_isState2_324() != 0) {
        this->current_action = (s16)get_no_action();
    }
    this->set_action_state(0x17, this->lobby_animation);
    if (get_flag() != 0) {
        pause_motion();
        set_frame(this->lobby_animation_frame);
    }
}
void handle_6x58_lobby_animation(G_LobbyAnimation_6x58 *command) {
    G_LobbyAnimation_6x58 m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x58_lobby_animation(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if ((p != NULL) && (p->is_in_tl03_state() != 0)) {
            p->lobby_animation = m.animation_number;
            if (m.has_keyboard() != 0) {
                p->set_anim_flag();
            }
            p->run_action_state_phase(0x17, 0);
        }
    }
}
void TObjPlayer::send_6x58_lobby_animation() {
    G_LobbyAnimation_6x58 pkt;
    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.animation_number = lobby_animation;
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            pkt.set_keyboard();
        }
        pkt.send();
    }
}

void TObjPlayer::lobby_animation_phase8_nop() {  }

void TObjPlayer::update_if_flagged() {
    if ((get_flag() == 0) && (this->motion_flags & 0x10)) {
        update_position_from_target();
    }
}

void TObjPlayer::lobby_animation_phase2_nop() {  }

int TObjPlayer::try_lobby_animation_change_action() { return try_change_action(); }

void TObjPlayer::run_lobby_animation_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_lobby_animation_change_action();
        return;
      case 2:
        lobby_animation_phase2_nop();
        return;
      case 3:
        update_if_flagged();
        return;
      case 8:
        lobby_animation_phase8_nop();
        return;
      case 5:
        send_6x58_lobby_animation();
        return;
      case 0:
        this->do_action();
        return;
      case 1:
        lobby_animation_phase1_nop();
        return;
      case 6:
        this->update_dispatch_v76();
        break;
    }
  }
}

void TObjPlayer::init_effects() {
    clear_flag_20000();
    clear_state_flags(5);
    activate_body_collision();
    set_indexed_flags(0, 1);
    render_material_state.reset_opacity();
}
void TObjPlayer::deactivate_off_floor_body() { this->deactivate_body_collision(); }

void TObjPlayer::enter_off_floor_state() {
    this->movement_hold.reset();
    death_sink.reset();
    this->protection.reset_lobby_model();
    this->set_state_flags(4);
    this->deactivate_body_collision();
    this->set_flag_20000();
    this->phase = 0;
    this->set_action_state(0x16, (s16)get_no_action());
}


void handle_6x57(G_Unknown_6x57 *command) {
    G_Unknown_6x57 m;
    TObjPlayer *p;

    m.init();
    m = *command;
    bswap_g_client_id_header(&m);
    if (validate_6x57(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->run_action_state_phase(0x16, 0);
        }
    }
}

void TObjPlayer::send_6x57() {
    G_Unknown_6x57 pkt;

    if ((this == NULL) || (obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjPlayer::update_off_floor_state() {
  f32 alpha;
  s16 *new_var;
  if (is_on_current_floor() != 0)
  {
    this->clear_state_flags(4);
    this->update_active_state();
    ::set_flag_400000((TObjPlayer *)this);
    appear_fade.begin();
    return;
  }
  switch (this->phase)
  {
    case 0:
      alpha = this->render_material_state.fade_color.a;
      alpha = alpha - 0.1f;
      if (alpha < 0.0f)
    {
      alpha = 0.0f;
      new_var = &this->phase;
      *new_var = 1;
      this->set_actor_flags(0x02000000);
      this->clear_player_status_flag(0, 1);
    }
      this->render_material_state.fade_color.a = alpha;
    case 1:
      return;
  }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjPlayer::fade_out_off_floor() {
  f32 alpha;
  if (is_on_current_floor() != 0)
  {
    clear_state_flags(4);
    return;
  }
  switch (phase)
  {
    case 0:
      alpha = render_material_state.fade_color.a;
      alpha -= 0.1f;
      if (alpha < 0.0f)
    {
      alpha = 0.0f;
      phase = 1;
    }
      render_material_state.fade_color.a = alpha;
    case 1:
      return;
  }
}
#pragma pop

void TObjPlayer::off_floor_phase2_nop() {  }

void TObjPlayer::off_floor_phase7_nop() {  }

void TObjPlayer::run_off_floor_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        off_floor_phase7_nop();
        return;
      case 2:
        off_floor_phase2_nop();
        return;
      case 3:
        fade_out_off_floor();
        return;
      case 8:
        update_off_floor_state();
        return;
      case 5:
        send_6x57();
        return;
      case 0:
        enter_off_floor_state();
        return;
      case 1:
        this->deactivate_off_floor_body();
        return;
      case 6:
        this->init_effects();
        break;
    }
  }
}

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
void TObjPlayer::start_action_21() {
    this->action_state = 0x15;
    run_action_state_phase(this->mode, 6);
    cleanup_idle_entry();
    clear_player_status_flag(0, 1);
    this->render_material_state.fade_color.a = 0.0f;
    refresh_equipment_slot();
    this->update_actor_ground_y();
    if (this->is_locally_controlled() != 0) {
        this->play_sound_if_on_floor(0x40003206);
    }
    this->phase = 1;
    this->set_action_state(0x15, this->get_idle_animation());
}

#undef CAT2
#undef CAT
void handle_6x56_set_player_position_and_angle(G_SetPlayerPositionAndAngle_6x56 *command) {
    G_SetPlayerPositionAndAngle_6x56 m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x56_set_player_position_and_angle(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->rotation_y = m.angle_y;
            p->set_position_from(&m.pos);
            p->calc_attach_pos();
            p->run_action_state_phase(0x15, 0);
        }
    }
}
extern "C" {

void TObjPlayer::send_position_update() {
    G_SetPlayerPositionAndAngle_6x56 pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.angle_y = rotation_y;
        VecCopy(&pkt.pos, &position);
        pkt.send();
    }
}

void TObjPlayer::sub_801C8C50(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        warp_phase7_nop();
        return;
      case 2:
        warp_phase2_nop();
        return;
      case 3:
        this->check_state_dead();
        return;
      case 8:
        warp_phase8_nop();
        return;
      case 5:
        this->send_position_update();
        return;
      case 0:
        this->start_action_21();
        return;
      case 1:
        this->update_warp_relocation();
        return;
      case 6:
        this->init_flags_vec4();
        break;
    }
  }
}

void send_6x55_intra_map_warp(u16 id, const Vec *destination, s32 yaw) {
    G_IntraMapWarp_6x55 packet;
    TObjPlayer *player = get_player_by_client_id(id);
    if (player != NULL && (player == NULL || player->obj_isState2_324() == 0)) {
        packet.init();
        packet.header.client_id = id;
        packet.angle_y = yaw;
        VecCopy(&packet.from_pos, &player->position);
        VecCopy(&packet.pos, destination);
        packet.send();
    }
}

void TObjPlayer::init_flags_vec4() { set_indexed_flags((saddr)((void*)0), (saddr)((void*)1)); render_material_state.reset_fade_color(); }

void TObjPlayer::update_warp_relocation() {
    Vec pos;
    f32 fade_in_alpha;
    f32 fade_out_alpha;
    s32 temp;

    switch (this->phase) {
    case 0:
        fade_out_alpha = this->render_material_state.fade_color.a;
        fade_out_alpha -= 0.1f;
        if (fade_out_alpha < 0.0f) {
            fade_out_alpha = 0.0f;
            this->phase = 3;
            this->rotation_y = intra_map_warp.yaw;
            this->set_position_from(&intra_map_warp.destination);
            refresh_equipment_slot();
            this->set_flag_4000();
            this->update_actor_ground_y();
            if (is_on_current_floor() != 0) {
                this->play_sound_if_on_floor(0x40003206);
            }
            if (this->is_locally_controlled() != 0) {
                calc_circle_offset_pos(this->rotation_y + 0x8000, this->get_position_ptr(), &pos, 10.0f);
                send_6x3e_to_all_players(&pos, this->rotation_y);
                reset_cameras_to_actor(this, 1);
            }
        }
        this->render_material_state.fade_color.a = fade_out_alpha;
        break;
    case 1:
        if (this->is_inactive() != 0) {
            this->phase = 2;
            intra_map_warp.timer = 4;
        }
        break;
    case 4:
        break;
    case 2:
        temp = intra_map_warp.timer - 1;
        intra_map_warp.timer = temp;
        if (temp <= 0) {
            this->phase = 3;
            activate_body_collision();
            if (is_on_current_floor() != 0) {
                spawn_appearance_effect(get_entity_id());
            }
        }
        break;
    case 3:
        this->clear_flag_4000();
        fade_in_alpha = this->render_material_state.fade_color.a;
        fade_in_alpha += 0.1f;
        if (fade_in_alpha >= 1.0f) {
            fade_in_alpha = 1.0f;
            this->phase = 4;
        }
        this->render_material_state.fade_color.a = fade_in_alpha;
        break;
    }
}

void TObjPlayer::set_dead_state() {
    this->action_state = 0x14;
    run_action_state_phase(this->mode, 6);
    clear_velocity();
    clear_player_status_flag(0, 1);
    this->phase = 0;
    this->play_sound_if_on_floor(0x40003205);
    this->set_action_state(0x14, this->get_idle_animation());
}

void handle_6x55_intra_map_warp(game_command_header *command) {
    G_IntraMapWarp_6x55 packet;
    packet.init();
    packet = *reinterpret_cast<G_IntraMapWarp_6x55 *>(command);
    packet.bswap();
    if (validate_6x55_intra_map_warp(&packet) != 0) {
        TObjPlayer *player = get_player_by_client_id(packet.header.client_id);
        if (player != NULL && player->is_in_tl03_state() != 0 && player->test_action_mask(0x8200) == 0) {
            player->intra_map_warp.yaw = packet.angle_y;
            player->set_position_from(&packet.from_pos);
            VecCopy(&player->intra_map_warp.destination, &packet.pos);
            player->run_action_state_phase(0x14, 0);
        }
    }
}

void TObjPlayer::send_warp_position() {
    G_IntraMapWarp_6x55 packet;
    if (this == NULL || obj_isState2_324() == 0) {
        packet.init();
        packet.header.client_id = this->get_entity_id();
        packet.angle_y = rotation_y;
        VecCopy(&packet.from_pos, &position);
        VecCopy(&packet.pos, &position);
        packet.send();
    }
}

void TObjPlayer::warp_phase8_nop() {  }

void TObjPlayer::check_state_dead() { if (this->phase == 4) { update_position_from_target(); } }

void TObjPlayer::warp_phase2_nop() {  }

void TObjPlayer::warp_phase7_nop() {  }

void TObjPlayer::run_warp_action_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        warp_phase7_nop();
        return;
      case 2:
        warp_phase2_nop();
        return;
      case 3:
        check_state_dead();
        return;
      case 8:
        warp_phase8_nop();
        return;
      case 5:
        send_warp_position();
        return;
      case 0:
        this->set_dead_state();
        return;
      case 1:
        update_warp_relocation();
        return;
      case 6:
        this->init_flags_vec4();
        break;
    }
  }
}

void TObjPlayer::reset_lobby_state() {
    this->resume_motion();
    clear_velocity();
    this->clear_actor_flags((u32)0x20);
    if (((s16) this->phase == 1) && (this->is_locally_controlled() != 0)) {
        this->protection.reset_lobby_model();
    }
}

void TObjPlayer::try_use_mag() {
    if ((this->is_frozen() == 0) && (this->is_locally_controlled() != 0) && (stick_escape_detector.check_input_angle() != 0)) {
        this->add_status_effect_timer(1, this->freeze_escape_step);
    }
}

void TObjPlayer::enter_freeze_action() {
    this->action_state = 0x13;
    run_action_state_phase(this->mode, 6);
    clear_velocity();
    clear_actor_flags((u32)0x200);
    pause_motion();
    if (this->is_frozen() != 0) {
        this->phase = 1;
    } else {
        this->phase = 0;
        this->freeze_escape_step = (s32) -(freeze_escape_timer_scale * (f64) this->get_status_effect_timer(1));
    }
    this->set_action_state(0x13, (s16)get_no_action());
}


}
void handle_6x53(G_Unknown_6x53 *command) {
    G_Unknown_6x53 m;
    TObjPlayer *p;

    m.init();
    m = *command;
    bswap_g_client_id_header(&m);
    if (validate_6x53(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            p->run_action_state_phase(0x13, 0);
        }
    }
}
extern "C" {

G_Unknown_6x53 &G_Unknown_6x53::operator=(const G_Unknown_6x53 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void TObjPlayer::send_name_and_state() {
    G_Unknown_6x53 a;
    G_ChangePlayerHP_6x2F b;
    if (this->is_frozen() == 0) {
        init_stick_escape_detector(&stick_escape_detector, pad_binding.get_controller());
    }
    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        a.init();
        a.header.client_id = this->get_entity_id();
        a.send();
        b.init();
        b.header.client_id = this->get_entity_id();
        b.type = 0;
        b.amount = this->get_actor_hp();
        b.client_id = this->get_entity_id();
        b.send();
    }
}

void TObjPlayer::return_to_idle_when_unfrozen() {
    switch (this->phase) {
    case 1:
        if (this->is_frozen() == 0) {
            this->run_action_state_phase(1, 0);
        }
        break;
    }
}

void TObjPlayer::update_gated_action() {
    u16 client_id;

    if (this->phase == 0) {
        if (this->is_status_flag_200() != 0) {
            client_id = this->get_entity_id();
            send_6x2F_change_player_hp(client_id, client_id, get_actor_hp());
            clear_actor_flags((u32)0x200);
            return;
        }
        if (can_guard() != 0) {
            use_current_item();
        }
    }
}

void TObjPlayer::freeze_phase2_nop() {  }

void TObjPlayer::update_frozen_release() {
  if (this->test_actor_flags(0x800) != 0)
  {
    death_flags.clear(1);
    run_action_state_phase(0xF, 5);
    return;
  }
  ;
  switch (this->phase)
  {
    return;
    case 0:
      if (check_flag30_bit20() == 0)
    {
      this->update_position_from_target();
    }
      return;
    case 1:
      if (this->is_frozen() == 0)
    {
      this->update_position_from_target();
    }
      break;
  }
}

void TObjPlayer::run_freeze_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->update_frozen_release();
        return;
      case 2:
        freeze_phase2_nop();
        return;
      case 3:
        this->update_gated_action();
        return;
      case 8:
        return_to_idle_when_unfrozen();
        return;
      case 5:
        this->send_name_and_state();
        return;
      case 0:
        this->enter_freeze_action();
        return;
      case 1:
        this->try_use_mag();
        return;
      case 6:
        this->reset_lobby_state();
        break;
    }
  }
}

s32 TObjPlayer::try_change_action() {
    if (this->is_status_locked() != 0) {
        if (anim_state.get_action_id() == 0x10) {
            run_action_state_phase(0x10, 5);
        } else {
            this->clear_actor_flags((uaddr)((void*)(0x10000)));
            run_action_state_phase(anim_state.get_action_id(), 5);
            anim_state.set_action_id(0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer::clear_flag() { clear_actor_flags((uaddr)((void*)((void*)65536))); clear_velocity(); }

void TObjPlayer::apply_velocity_if_free(void *player) {
    TObjPlayer *p = (TObjPlayer *)player;
    void *x = (void *)p->resolve_move_collision();
    if (x == NULL) {
        p->apply_velocity();
    }
}

void TObjPlayer::enter_service_hold_action() {
    this->action_state = 0x10;
    run_action_state_phase(this->mode, 6);
    this->requested_action = anim_state.get_animation();
    this->rotation_y = anim_state.get_angle();
    this->set_action_state(0x10, (s16)get_no_action());
}

}
void handle_6x52_set_animation_state(G_SetAnimationState_6x52 *command) {
    G_SetAnimationState_6x52 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x52_set_animation_state(&pkt) != 0) {
        player = get_player_by_client_id(pkt.header.client_id);
        if ((player != NULL) && (player->is_in_tl03_state() != 0) && (player->test_action_mask(0x8000) == 0) && ((TFontSmallLobby::is_lobby_floor_15() == 0) || (player->obj_isState2_324() == 0) || (player->check_flag(0x04000000) == 0))) {
            player->anim_state.set_animation(pkt.animation);
            player->anim_state.set_angle(pkt.angle);
            player->anim_state.set_state(pkt.state);
            player->run_action_state_phase(0x10, 0);
        }
    }
}
extern "C" {

void TObjPlayer::send_6x52_animation_state() {
    G_SetAnimationState_6x52 pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.animation = anim_state.get_animation();
        pkt.angle = anim_state.get_angle();
        pkt.state = anim_state.get_state();
        pkt.send();
    }
}

void TObjPlayer::service_hold_phase8_nop() {  }

void TObjPlayer::update_service_hold() {
    if (!(this->actorFlags & 0x10000)) {
        if (anim_state.get_action_id() == 0) {
            update_position_from_target();
            return;
        }
        run_action_state_phase(anim_state.get_action_id(), 5);
        anim_state.set_action_id(0);
    }
}

void TObjPlayer::service_hold_phase2_nop() {  }

void TObjPlayer::set_motion() {
    if (is_status_flag_200() != 0) {
        if (test_actor_flags(0x400) != 0) {
            run_action_state_phase(0xE, 5);
            return;
        }
        run_action_state_phase(0xD, 5);
        return;
    }
    if (can_guard() != 0) {
        run_action_state_phase(0xA, 5);
        return;
    }
    if (check_flag30_bit20() != 0) {
        run_action_state_phase(0x13, 5);
    }
}

void TObjPlayer::run_service_hold_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        set_motion();
        return;
      case 2:
        TObjPlayer::service_hold_phase2_nop();
        return;
      case 3:
        update_service_hold();
        return;
      case 8:
        TObjPlayer::service_hold_phase8_nop();
        return;
      case 5:
        this->send_6x52_animation_state();
        return;
      case 0:
        this->enter_service_hold_action();
        return;
      case 1:
        apply_velocity_if_free(this);
        return;
      case 6:
        this->clear_flag();
        break;
    }
  }
}

void TObjPlayer::notify_lobby() {
    this->resume_motion();
    TWindowCtrl::enable_client_main_menu(this->get_entity_id());
}

void TObjPlayer::ensure_default() {
    void *x;
    x = (void *)this->resolve_move_collision();
    if (x == NULL) {
        this->apply_velocity();
    }
}

void TObjPlayer::init_action() {
    this->action_state = 0x12;
    run_action_state_phase(this->mode, 6);
    clear_velocity();
    this->protection.set_frames(0x12C);
    this->phase = 0;
    this->frame_timer = 44.0f;
    this->set_attacker_id(0xFFFF);
    this->set_action_state(0x12, (s16)get_no_action());
    disable_motion_blend();
    if (is_current_area_item_enabled() != 0) {
        new TTecReverserEff(this, tl_07);
    }
    if (this->death_fade != NULL) {
        this->death_fade->queue_destruction();
        this->death_fade = NULL;
    }
}

}
void handle_6x4F_player_revived(G_PlayerRevived_6x4F *command) {
    G_PlayerRevived_6x4F m;
    TObjPlayer *p;

    m.init();
    m = *command;
    bswap_g_client_id_header(&m);
    if (validate_6x4F_player_revived(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            p->run_action_state_phase(0x12, 0);
        }
    }
}
extern "C" {

G_PlayerRevived_6x4F &G_PlayerRevived_6x4F::operator=(const G_PlayerRevived_6x4F &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void TObjPlayer::send_6x4F_revived() {
    G_PlayerRevived_6x4F msg;

    if (test_flags_any(&death_flags.bits, 4) != 0) {
        send_use_medical_center();
        if (this->is_alive_and_ready() != 0) {
            this->refill_traps();
        }
    } else {
        this->send_6xA1_player_id();
    }
    this->photon_blast_gauge.update_if_ready();
    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        msg.init();
        msg.header.client_id = this->get_entity_id();
        msg.send();
    }
}

void TObjPlayer::update_timer_state() {
    f32 timer;

    switch (this->phase) {
    case 0:
        timer = this->frame_timer - 1.0f;
        this->frame_timer = timer;
        if (timer < 0.0f) {
            this->phase = 1;
            this->TObjMotion::init(this->get_idle_animation());
            this->pause_motion();
            this->frame_timer = 24.0f;
        }
        break;
    case 1:
        timer = this->frame_timer - 1.0f;
        this->frame_timer = timer;
        if (timer < 0.0f) {
            this->resume_motion();
            this->run_action_state_phase(1, 0);
        }
        break;
    }
}

void TObjPlayer::update_timer_action() {
    f32 timer;

    switch (this->phase) {
    case 0:
        timer = this->frame_timer - 1.0f;
        this->frame_timer = timer;
        if (timer < 0.0f) {
            this->phase = 1;
            TObjMotion::init(this->get_idle_animation());
            pause_motion();
            this->frame_timer = 24.0f;
        }
        break;
    case 1:
        timer = this->frame_timer - 1.0f;
        this->frame_timer = timer;
        if (timer < 0.0f) {
            this->resume_motion();
            this->protection.set_frames((saddr)this->get_getup_protection_ticks());
            this->update_position_from_target();
        }
        break;
    }
}

void TObjPlayer::revival_phase2_nop() {  }

void TObjPlayer::revival_phase7_nop() {  }

void TObjPlayer::run_revival_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        revival_phase7_nop();
        return;
      case 2:
        revival_phase2_nop();
        return;
      case 3:
        update_timer_action();
        return;
      case 8:
        update_timer_state();
        return;
      case 5:
        this->send_6x4F_revived();
        return;
      case 0:
        this->init_action();
        return;
      case 1:
        ensure_default();
        return;
      case 6:
        notify_lobby();
        break;
    }
  }
}

}
void handle_6x89_set_killer_entity_id(G_SetKillerEntityID_6x89 *command) {
    G_SetKillerEntityID_6x89 pkt;
    TObjPlayer *p;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x89_set_killer_entity_id(&pkt.header) != 0) {
        p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            p->attacker_id = pkt.killer_entity_id;
        }
    }
}
void init_subobject(TObjPlayer *player) {
    if (player != NULL) {
        player->run_action_state_phase(0xF, 0);
        player->update_action_render();
        player->death_sink.reset();
        player->death_sink.calc_height(player);
        player->death_sink.set_progress(1.0f);
    }
}

void queue_player_injured_pose(TObjPlayer *player) {
    new TPlayerReadyCallback(player, player->get_entity_id(), init_subobject);
}

extern "C" {
void TObjPlayer::update_active_state() {
    if (is_on_current_floor() != 0) {
        this->clear_state_flags(4);
        if (this->test_actor_flags(0x800) == 0) {
            run_action_state_phase(1, 0);
            return;
        }
        run_action_state_phase(0xF, 0);
        if (test_flags_any(&death_flags.bits, 1) != 0) {
            this->requested_action = this->get_action_animation();
        } else {
            this->restart_death_pose();
        }
        death_sink.set_progress(1.0f);
        this->revive_or_spawn_marker();
    }
}


}
void handle_6x4E_player_revivable(G_PlayerRevivable_6x4E *command) {
    G_PlayerRevivable_6x4E m;
    TObjPlayer *p;

    m.init();
    m = *command;
    bswap_g_client_id_header(&m);
    if (validate_6x4E_player_revivable(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            p->update_action_render();
            p->revive_or_spawn_marker();
        }
    }
}
extern "C" {

G_PlayerRevivable_6x4E &G_PlayerRevivable_6x4E::operator=(const G_PlayerRevivable_6x4E &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void TObjPlayer::send_6x4E_player_revivable() {
    G_PlayerRevivable_6x4E msg;

    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        msg.init();
        msg.header.client_id = this->get_entity_id();
        msg.send();
    }
}

void TObjPlayer::update_action_render() {
    if (test_flags_any(&death_flags.bits, 1) != 0) {
        this->requested_action = this->get_action_animation();
    } else {
        this->requested_action = this->get_model_field_m25();
    }
    this->set_animation((int) (this->requested_action));
    this->frame = (f32) (this->frame_count - 1.0f);
    draw(this->frame);
    pause_motion();
    this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFDF);
}

void TObjPlayer::restart_death_pose() {
    this->update_action_render();
    death_sink.reset();
    death_sink.calc_height(this);
    if (this->is_locally_controlled() != 0) {
        this->death_fade = new TDeathTintFade(tl_particlemodel, complete_deferred_player_death, get_entity_id());
    }
}

void TObjPlayer::reset_on_death() {
    set_actor_flags(0x800U);
    this->hp = 0;
    this->clear_all_status_effects();
    protection.reset_lobby_model();
    death_sink.reset();
}

void TObjPlayer::exit_death_state() {
    s32 flags;

    flags = this->actorFlags & 0xFFFFFDFF;
    this->actorFlags = flags;
    this->return_city_window = 0;
    this->death_sink.reset();
    this->resume_motion();
}

void TObjPlayer::update_death_pose() {
    if ((test_motion_flags(0x20) != 0) && ((s16) this->requested_action == (s16) this->current_action)) {
        this->restart_death_pose();
    }
    death_sink.add_progress(0.002f);
    death_sink.update_offset();
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::enter_death_state() {
    TObjCollidable *entity;
    u32 entity_id;
    u32 other;
    u16 killer;
    TObjCollidable *culprit;
    CharacterSaveRecord *character_save_record;
    CharacterSaveRecord *save_record;
    this->action_state = 0xF;
    run_action_state_phase(this->mode, 6);
    reset_on_death();
    clear_velocity();
    this->phase = 0;
    if (test_flags_any(&death_flags.bits, 1) != 0) {
        this->set_action_state(0xF, (s16)get_no_action());
        this->restart_death_pose();
    } else {
        this->set_action_state(0xF, this->get_model_field_m25());
    }
    this->photon_blast_gauge.clear_photon_blast_state();
    if (TTecCtrl::is_technique_ready() != 0) {
        entity = reinterpret_cast<TObjCollidable *>(find_entity_by_id(this->get_attacker_id()));
        if (entity != NULL) {
            if (entity->check_value_equals(TObjPlayer_name) != 0) {
                entity_id = (u16)this->get_entity_id();
                other = (u16)((TObjBase *)entity)->get_entity_id();
                if (other != entity_id) {
                    ((TObjPlayer *)entity)->record_kill(this, 1);
                }
            }
            if (entity->check_value_equals(TOMineTrap::class_name) == 0) {
                record_death(entity, 1);
            } else if ((killer = ((TOMineTrap *)entity)->get_trap_type()) == 0xffffU) {
                record_death(entity, 1);
            } else {
                culprit = find_entity_by_id(killer);
                record_death(culprit, 1);
            }
            draw_player_status(this, (void *) (entity), "\tC9");
        }
        draw_player_status(this, this, "\tC8");
        if (this->is_locally_controlled() != 0) {
            play_duel_result_stream("death.adx", 0x96);
        }
    }
    if ((this->is_locally_controlled() != 0) && (TObjPlayer::is_camera_mode_active() == 0) && (TTecCtrl::is_technique_ready() == 0)) {
        if (TObjPlayer::is_single_screen() != 0) {
            character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)(this->get_entity_id()));
            character_save_record->death_count += 1;
            return;
        }
        save_record = (CharacterSaveRecord *)get_character_save_record((u16)(0xFFFFU));
        save_record->death_count += 1;
    }
}

}
void handle_6x4D_player_died(G_PlayerDied_6x4D *command) {
    G_PlayerDied_6x4D cmd;
    TObjPlayer *p;
    cmd = *command;
    cmd.bswap();
    if (validate_6x4D_player_died(&cmd.header) != 0) {
        p = get_player_by_client_id(cmd.header.client_id);
        if (p != NULL) {
            p->death_flags = cmd.death_flags;
            p->reset_on_death();
            if (p->is_in_tl03_state() != 0) {
                p->run_action_state_phase(0xF, 0);
            }
        }
    }
}
extern "C" {

void TObjPlayer::prepare_death() {
    G_SetKillerEntityID_6x89 c1;
    if (this->is_locally_controlled() != 0) {
        TWindowCtrl::disable_client_main_menu((u16)this->get_entity_id());
        this->return_city_window = 0;
        this->death_fade = NULL;
        death_flags.clear(4);
        if (this->find_revival_item() == 0) {
            death_flags.set(2);
        }
    }
    if (test_flags_any(&death_flags.bits, 1) == 0) {
        this->drop_items_on_death();
    }
    if (is_action_input_disabled() != 0) {
        enable_action_input();
    }
    if (this->lock_on_cursor != NULL && this->lock_on_cursor->is_cursor_clear() == 0) {
        ((TObjPlayer *)this->lock_on_cursor)->clear_flag_1_at_1c();
    }
    if (this == NULL || this->obj_isState2_324() == 0) {
        c1.init();
        c1.header.client_id = this->get_entity_id();
        c1.killer_entity_id = this->get_attacker_id();
        c1.send();
        G_PlayerDied_6x4D c2;
        c2.header.client_id = this->get_entity_id();
        c2.death_flags = this->death_flags;
        c2.send();
    }
}

void TObjPlayer::set_death_marker_pos() {
    bodies->center.x = position.x;
    bodies->center.y = 8.0f + position.y;
    bodies->center.z = position.z;
    this->set_actor_flags(0x800U);
}

void TObjPlayer::request_revival_if_not_dead() {
    if (this->test_actor_flags(0x800) == 0) {
        run_action_state_phase(0x12, 5);
    }
}

void TObjPlayer::check_reopen_return_city_window() {
  TWindowCtrl::disable_client_main_menu((u16)this->get_entity_id());
  uaddr window = this->return_city_window;
  if ((window != 0) && ((((TObject *)window)->all_parents_unqueued_for_destruction() == 0) || (reinterpret_cast<TObject *>(return_city_window)->check_value_equals(TWindowReturnCity::class_name) == 0)))
  {
    this->return_city_window = 0U;
  }
  if (((((pad_binding.is_button_pressed(4) != 0) && (TObjPlayer::is_camera_mode_active() == 0)) && (TTecCtrl::is_technique_ready() == 0)) && ((TObjPlayer::check_camera_mode() == 0) || ((TObjPlayer::check_camera_mode() != 0) && (get_main_phase() == 0xF)))) && (is_controls_locked() == 0))
  {
    this->create_return_city_window();
  }
}

void TObjPlayer::death_phase7_nop() {  }

void TObjPlayer::run_death_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        death_phase7_nop();
        return;
      case 2:
        this->check_reopen_return_city_window();
        return;
      case 3:
        this->request_revival_if_not_dead();
        return;
      case 8:
        this->set_death_marker_pos();
        return;
      case 5:
        this->prepare_death();
        return;
      case 0:
        this->enter_death_state();
        return;
      case 1:
        this->update_death_pose();
        return;
      case 6:
        this->exit_death_state();
        break;
    }
  }
}

void TObjPlayer::exit_fall_reaction() { clear_velocity(); }

void TObjPlayer::update_fall_reaction() {
    f32 frame_timer;
    switch (this->phase) {
    case 0:
        if (is_passing_frame(10.0f) != 0) {
            if (classify_action_state() == 2) {
                this->play_sound_if_on_floor(0x40002320);
            } else {
                this->play_sound_if_on_floor(0x40009E14);
            }
        }
        if (this->motion_flags & 0x10) {
            this->phase = 1;
            this->frame_timer = 30.0f;
        }
        break;
    case 1:
        frame_timer = this->frame_timer - 1.0f;
        this->frame_timer = frame_timer;
        if (frame_timer < 0.0f) {
            this->phase = 2;
            this->requested_action = query_child_state2();
        }
        break;
    case 2:
        break;
    }
    this->damp_planar_velocity();
    if (check_actor_blocking_move() != 0) {
        clear_velocity();
    }
    if (resolve_move_collision() == 0U) {
        apply_velocity();
    }
}

void TObjPlayer::start_action_0e() {
    Vec saved_velocity;

    VecCopy(&saved_velocity, &this->velocity);
    this->action_state = 0xE;
    this->run_action_state_phase(this->mode, 6);
    VecCopy(&this->velocity, &saved_velocity);
    this->protection.set_frames(0x12C);
    this->clear_actor_flags(0x10000);
    this->play_sound_if_on_floor(0x4000AD13);
    if (this->obj_isState2_324() != 0) {
        this->TObjChara::trigger_switch_attack((const Vec *)this->get_center());
    }
    this->phase = 0;
    this->set_action_state(0xE, this->get_action_animation());
}

}
void handle_6x4C_hit_by_enemy(G_HitByEnemy_6x4C *command) {
    G_HitByEnemy_6x4C m;
    TObjPlayer *p;

    m.init();
    m = *command;
    m.bswap();
    if (validate_6x4C_hit_by_enemy(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->test_action_mask(0x8000) == 0) {
            p->set_hp_clamped(m.current_hp);
            if (p->is_in_tl03_state() != 0 && p->reset_volopt_state() != 0) {
                p->rotation_y = m.angle;
                p->velocity.x = m.velocity.xz[0];
                p->velocity.z = m.velocity.xz[1];
                p->run_action_state_phase(0xE, 0);
            }
        }
    }
}
extern "C" {

#pragma push
#pragma fp_contract on
void TObjPlayer::begin_fall_reaction() {
    f32 x;
    f32 z;
    G_HitByEnemy_6x4C pkt;
    z = this->velocity.z;
    x = this->velocity.x;
    if (newton_sqrtf(x * x + z * z) > 1e-05f) {
        this->rotation_y = (s32) ((s32) (lbl_80447148 * atan2_float(x, z)) + 0x8000);
    }
    if (test_actor_flags(0x800) != 0) {
        drop_items_on_death();
    }
    TObjPlayer::spawn_effect((saddr)this);
    if ((this == NULL) || (obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = this->get_entity_id();
        pkt.angle = (s16) this->rotation_y;
        pkt.current_hp = this->hp;
        pkt.velocity.xz[0] = x;
        pkt.velocity.xz[1] = z;
        pkt.send();
    }
}
#pragma pop

void TObjPlayer::fall_reaction_phase8_nop() {  }

void TObjPlayer::complete_fall_reaction() {
    switch (this->phase) {
    case 1:
        if (((s16) this->requested_action == this->get_action_animation()) && (this->motion_flags & 0x10) && (this->test_actor_flags(0x800) != 0)) {
            death_flags.set(1);
            run_action_state_phase(0xF, 5);
        }
        break;
    case 2:
        if (this->motion_flags & 0x10) {
            this->protection.set_frames((saddr)get_getup_protection_ticks());
            update_position_from_target();
        }
        break;
    }
}

void TObjPlayer::fall_reaction_phase2_nop() {  }

void TObjPlayer::check_and_trigger_19_5() { if (check_flag30_bit20() != 0) { run_action_state_phase(19, 5); } }

void TObjPlayer::run_fall_reaction_phase(s16 phase) {
    switch (phase) {
    case 7:
        check_and_trigger_19_5();
        return;
    case 2:
        fall_reaction_phase2_nop();
        return;
    case 3:
        complete_fall_reaction();
        return;
    case 8:
        fall_reaction_phase8_nop();
        return;
    case 5:
        begin_fall_reaction();
        return;
    case 0:
        start_action_0e();
        return;
    case 1:
        update_fall_reaction();
        return;
    case 6:
        exit_fall_reaction();
        break;
    }
}

void TObjPlayer::set_flag_100000() { clear_velocity(); set_actor_flags(0x100000); }

void TObjPlayer::update_move_state() {
    damp_planar_velocity();
    if (this->check_actor_blocking_move() != 0) {
        clear_velocity();
    }
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::end_freeze_action() {
    Vec saved_velocity;

    VecCopy(&saved_velocity, &this->velocity);
    this->action_state = 0xD;
    this->run_action_state_phase(this->mode, 6);
    VecCopy(&this->velocity, &saved_velocity);
    if (TTecCtrl::is_technique_ready() != 0) {
        this->protection.set_frames(0x1E);
    } else {
        this->protection.set_frames(this->get_hurt_protection_ticks());
    }
    this->play_sound_if_on_floor(0x4000AD12);
    if (this->obj_isState2_324() != 0) {
        this->TObjChara::trigger_switch_attack((const Vec *)this->get_center());
    }
    this->clear_actor_flags(0x10000);
    this->set_action_state(0xD, this->call_model_m24());
}

}
void handle_6x4B_hit_by_enemy(G_HitByEnemy_6x4B *command) {
    G_HitByEnemy_6x4B m;
    TObjPlayer *p;

    m.init();
    m = *command;
    m.bswap();
    if (validate_6x4B_hit_by_enemy(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->test_action_mask(0x8000) == 0) {
            p->set_hp_clamped(m.current_hp);
            if (p->is_in_tl03_state() != 0 && p->reset_volopt_state() != 0) {
                p->rotation_y = m.angle;
                p->velocity.x = m.velocity.xz[0];
                p->velocity.z = m.velocity.xz[1];
                p->run_action_state_phase(0xD, 0);
            }
        }
    }
}
extern "C" {
void TObjPlayer::send_6x4B_hurt_reaction() {
    G_HitByEnemy_6x4B pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = this->get_entity_id();
        pkt.angle = this->rotation_y;
        pkt.current_hp = this->hp;
        pkt.velocity.xz[0] = this->velocity.x;
        pkt.velocity.xz[1] = this->velocity.z;
        pkt.send();
    }
}

void TObjPlayer::hurt_phase8_nop() {  }

void TObjPlayer::complete_hurt_reaction() {
    if (this->motion_flags & 0x10) {
        if (this->test_actor_flags(0x800) != 0) {
            death_flags.clear(1);
            run_action_state_phase(0xF, 5);
            return;
        }
        update_position_from_target();
    }
}

void TObjPlayer::hurt_phase2_nop() {  }

void TObjPlayer::do_action_19_5_if_flag30() { if (check_flag30_bit20() != 0) { run_action_state_phase(19, 5); } }

void TObjPlayer::run_hurt_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->do_action_19_5_if_flag30();
        return;
      case 2:
        hurt_phase2_nop();
        return;
      case 3:
        this->complete_hurt_reaction();
        return;
      case 8:
        hurt_phase8_nop();
        return;
      case 5:
        this->send_6x4B_hurt_reaction();
        return;
      case 0:
        this->end_freeze_action();
        return;
      case 1:
        this->update_move_state();
        return;
      case 6:
        this->set_flag_100000();
        break;
    }
  }
}

void TObjPlayer::action11_phase6_nop() {  }

void TObjPlayer::update_action11_movement() {
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::begin_action_0xB() {
    this->action_state = 0xB;
    run_action_state_phase(this->mode, 6);
    if (obj_isState2_324() != 0) {
        this->current_action = (s16)get_no_action();
    }
    this->set_action_state(0xB, this->call_obj_vt26());
}

void TObjPlayer::send_6x51_set_player_angle() {
    G_SetPlayerAngle_6x51 pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = this->get_entity_id();
        pkt.angle_y = this->rotation_y;
        pkt.send();
    }
}

void TObjPlayer::action11_phase8_nop() {  }

void TObjPlayer::run_if_flag_10() {
    if (this->motion_flags & 0x10) {
        update_position_from_target();
    }
}

void TObjPlayer::action11_phase2_nop() {  }

int TObjPlayer::try_apply_status_action() { return try_status_action(); }

void TObjPlayer::run_action11_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action();
        return;
      case 2:
        action11_phase2_nop();
        return;
      case 3:
        this->run_if_flag_10();
        return;
      case 8:
        action11_phase8_nop();
        return;
      case 5:
        this->send_6x51_set_player_angle();
        return;
      case 0:
        this->begin_action_0xB();
        return;
      case 1:
        update_action11_movement();
        return;
      case 6:
        action11_phase6_nop();
        break;
    }
  }
}

void TObjPlayer::switch_interaction_phase6_nop() {  }

void TObjPlayer::apply_velocity_if_ready(saddr player) {
    TObjPlayer *p = (TObjPlayer *)player;
    if (p->resolve_move_collision() == 0U) {
        p->apply_velocity();
    }
}

void TObjPlayer::start_action_c() {
    this->action_state = 0xC;
    run_action_state_phase(this->mode, 6);
    if (obj_isState2_324() != 0) {
        this->current_action = (s16)get_no_action();
    }
    this->set_action_state(0xC, this->get_weapon_stat_c());
}

}
void handle_6x50_switch_interaction(G_SwitchInteraction_6x50 *command) {
    G_SwitchInteraction_6x50 packet;
    packet.init();
    packet = *command;
    packet.bswap();
    if (validate_6x50_switch_interaction(&packet.header)) {
        TObjPlayer *player = get_player_by_client_id(packet.header.client_id);
        if (player && player->is_in_tl03_state() && !player->test_action_mask(0x8200)) {
            player->rotation_y = packet.angle_y;
            player->run_action_state_phase(12, 0);
        }
    }
}
extern "C" {

void TObjPlayer::send_6x50_switch_interaction() {
    G_SwitchInteraction_6x50 pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.angle_y = this->rotation_y;
        pkt.send();
    }
}

void TObjPlayer::switch_interaction_phase8_nop() {  }

void TObjPlayer::update_if_flag_set() {
    if (this->motion_flags & 0x10) {
        update_position_from_target();
    }
}

void TObjPlayer::switch_interaction_phase2_nop() {  }

int TObjPlayer::try_switch_interaction_status_action() { return try_status_action(); }

void TObjPlayer::run_switch_interaction_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_switch_interaction_status_action();
        return;
      case 2:
        switch_interaction_phase2_nop();
        return;
      case 3:
        this->update_if_flag_set();
        return;
      case 8:
        switch_interaction_phase8_nop();
        return;
      case 5:
        this->send_6x50_switch_interaction();
        return;
      case 0:
        this->start_action_c();
        return;
      case 1:
        TObjPlayer::apply_velocity_if_ready((saddr)this);
        return;
      case 6:
        switch_interaction_phase6_nop();
        break;
    }
  }
}

s32 TObjPlayer::can_guard() {
    if ((((TObjCollidable *)((u8 *)this))->test_actor_flags(0x100) != 0) && (((TObjCollidable *)((u8 *)this))->test_actor_flags(0x04000000) == 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::set_flag_0x100000() { clear_velocity(); set_actor_flags(0x100000); }

void TObjPlayer::apply_velocity_if_free(saddr owner) {
    TObjPlayer *p = (TObjPlayer *)owner;
    p->damp_planar_velocity();
    if (p->resolve_move_collision() == 0U) {
        p->apply_velocity();
    }
}

void TObjPlayer::start_use_item_action() {
    Vec saved_velocity;

    VecCopy(&saved_velocity, &this->velocity);
    this->action_state = 0xA;
    this->run_action_state_phase(this->mode, 6);
    VecCopy(&this->velocity, &saved_velocity);
    this->clear_actor_flags(0x10000);
    this->use_current_item();
    if (this->obj_isState2_324() != 0) {
        this->current_action = (s16)get_no_action();
    }
    this->set_action_state(0xA, this->query_child_state());
}

}
void handle_6x4A_shield_attack(G_ShieldAttack_6x4A *command) {
    G_ShieldAttack_6x4A m;
    TObjPlayer *p;

    m.init();
    m = *command;
    bswap_g_client_id_header(&m);
    if (validate_6x4A_shield_attack(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && p->is_in_tl03_state() != 0 && p->reset_volopt_state() != 0 &&
            p->test_action_mask(0x8000) == 0) {
            p->run_action_state_phase(0xA, 0);
        }
    }
}
extern "C" {

G_ShieldAttack_6x4A &G_ShieldAttack_6x4A::operator=(const G_ShieldAttack_6x4A &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void TObjPlayer::send_object_id_packet() {
    G_ShieldAttack_6x4A msg;

    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        msg.init();
        msg.header.client_id = this->get_entity_id();
        msg.send();
    }
}

void TObjPlayer::guard_reaction_phase8_nop() {  }

void TObjPlayer::complete_guard_reaction() {
    if (this->motion_flags & 0x10) {
        if (this->test_actor_flags(0x800) != 0) {
            death_flags.clear(1);
            run_action_state_phase(0xF, 5);
            return;
        }
        update_position_from_target();
    }
}

void TObjPlayer::guard_reaction_phase2_nop() {  }

void TObjPlayer::select_hit_action() {
    if (check_flag30_bit20() != 0) {
        run_action_state_phase(0x13, 5);
        return;
    }
    if (is_status_flag_200() != 0) {
        if (test_actor_flags(0x400) != 0) {
            run_action_state_phase(0xE, 5);
            return;
        }
        run_action_state_phase(0xD, 5);
    }
}

void TObjPlayer::run_guard_reaction_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        select_hit_action();
        return;
      case 2:
        guard_reaction_phase2_nop();
        return;
      case 3:
        this->complete_guard_reaction();
        return;
      case 8:
        guard_reaction_phase8_nop();
        return;
      case 5:
        this->send_object_id_packet();
        return;
      case 0:
        this->start_use_item_action();
        return;
      case 1:
        TObjPlayer::apply_velocity_if_free((saddr)this);
        return;
      case 6:
        set_flag_0x100000();
        break;
    }
  }
}
}

void TObjPlayer::create_photon_blast_party_effects(u16 id) {
    if (shared_photon_blast_state != NULL) {
        shared_photon_blast_state->create_party_effects(id);
    }
}

PhotonBlastRequestSlot *TObjPlayer::find_photon_blast_by_section_id(u16 section_id) {
    if (shared_photon_blast_state != NULL) {
        return shared_photon_blast_state->find_by_section_id(section_id);
    }
    return NULL;
}

u16 TObjPlayer::get_current_target_id() {
    if (shared_photon_blast_state != NULL) {
        return shared_photon_blast_state->find_first_valid_target_id();
    }
    return 0xFFFF;
}

void remove_photon_blast_participant(s32 id) {
    if (TObjPlayer::shared_photon_blast_state != NULL) {
        TObjPlayer::shared_photon_blast_state->sub_80312E98(id);
    }
}

void TObjPlayer::update_photon_blast_state() {
    if (shared_photon_blast_state != NULL) {
        shared_photon_blast_state->process_all_elements();
    }
}

PhotonBlastRequest *TObjPlayer::get_photon_blast_element(s32 index) {
    if (shared_photon_blast_state != NULL) {
        return shared_photon_blast_state->get_element(index);
    }
    return NULL;
}

void TObjPlayer::apply_photon_blast(u16 client_id, s16 kind) {
    if (shared_photon_blast_state != NULL) {
        append_photon_blast_request(shared_photon_blast_state, client_id, kind);
    }
}

// index (the 0x4AC slot's valid index the caller passes in r4) is not read.
void TObjPlayer::update_active_instance(int index) {
    if (shared_photon_blast_state != NULL) {
        if (this->reset_volopt_state() == 0) {
            shared_photon_blast_state->process_all_elements();
            return;
        }
        release_photon_blast_requests(shared_photon_blast_state);
        admit_photon_blast_sequence(TObjPlayer::get_photon_blast_element(0), this);
    }
}

void TObjPlayer::gain_photon_blast_charge(f32 amount) {
    if (this->is_locally_controlled() == 0 || this->test_actor_flags(0x800) != 0 ||
        this->get_equipped_mag() == NULL || this->action_palettes.is_secondary_bank_empty(1) != 0 ||
        is_current_area_item_enabled() == 0) {
        return;
    }
    this->photon_blast_gauge.add_photon_blast_charge(amount);
}

f32 TObjPlayer::calc_photon_blast_charge(void *player, s32 damage) {
    return (f32) damage / (15.0f * (1.0f + (f32) ((TObjPlayer *)player)->clamp_nested_index()));
}

void release_all_players_control_lock(void) {
    TObjPlayer::for_each_player_slot(release_control_lock);
}

void release_photon_blast_player_holds(u16 *p) {
    s32 i;
    uaddr obj;
    if (p != NULL) {
        i = 0;
        while (*p != 0xFFFF) {
            u32 id = *p++;
            if (id >= 12) {
                break;
            }
            obj = (uaddr)get_player_by_client_id(id);
            if (obj != 0) {
                ((TObjPlayer *)obj)->clear_flag_200();
            }
            i++;
            if (i >= 12) {
                break;
            }
        }
    }
}

void freeze_players_for_photon_blast(s16 room, u16 *frozen_ids) {
    s32 i;
    TObjPlayer *obj;
    TObjPlayer **tbl;
    tbl = player_slot_table;
    i = 0;
    do {
        obj = *tbl;
        if (obj != NULL && obj->is_on_current_floor() != 0 && obj->test_action_mask(0x8000) == 0 &&
            (TObjPlayer::is_single_screen() != 0 ||
             (TObjPlayer::is_single_screen() == 0 && room == obj->get_room()))) {
            obj->set_flag_200();
            if (frozen_ids != NULL) {
                *frozen_ids = obj->get_entity_id();
                frozen_ids++;
            }
            obj->run_action_state_phase(0x13, 0);
        }
        i++;
        tbl++;
    } while (i < 4);
}
void handle_6x36(void) {  }
void handle_6x37_photon_blast(G_PhotonBlast_6x37 *command) {
    G_PhotonBlast_6x37 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x37_photon_blast(&pkt) != 0) {
        player = get_player_by_client_id(pkt.header.client_id);
        if ((player != NULL) && (player->check_flag_4() == 0) && (player->m_up == tl_03) && (player->reset_volopt_state() != 0)) {
            player->photon_blast_gauge.check_photon_blast_flag();
            player->photon_blast_gauge.trigger_photon_blast();
        }
    }
}
extern "C" {

void TObjPlayer::send_6x37_photon_blast() {
    G_PhotonBlast_6x37 packet;
    if (this == NULL || obj_isState2_324() == 0) {
        packet.init();
        packet.header.client_id = this->get_entity_id();
        packet.amount = get_photon_blast_charge();
        packet.send();
    }
}

s32 TObjPlayer::check_conditions(s16 blast) {
    if ((this->test_actor_flags(0x20006) != 0) || (this->test_action_mask(0x11E) == 0) || (this->photon_blast_gauge.has_ready_flag() == 0) || (this->photon_blast_gauge.check_flag_clear() == 0) || ((this->is_locally_controlled() != 0) && ((is_controls_locked() != 0) || (this->get_camera_field() == 0))) || (this->reset_volopt_state() == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::exit_photon_blast_action() {
    TLockOnCursor *lock_on_cursor;
    this->motion_flags &= ~0x40;
    this->clear_state_flags(0x80);
    this->clear_actor_flags((u32)(0x400000));
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
    this->photon_blast_gauge.reset_photon_blast_gauge();
    if (TObjPlayer::is_final_phase() != 0) {
        this->get_entity_id();
        ((s32 (*)(void))remove_photon_blast_participant)();
    } else {
        TObjPlayer::update_photon_blast_state();
    }
    if ((s32) this->action_state != 0x13) {
        this->protection.reset_lobby_model();
    }
}

void TObjPlayer::update_photon_blast_action() {
  this->rotation_y = lerp_angle_half((int) (this->rotation_y), (int) (this->target_heading));
  switch (this->phase)
  {
    case 2:
    case 4:
      break;
    case 0:
      if (is_passing_frame(get_photon_blast_hold_frame()) != 0)
    {
      this->phase = 1;
      this->motion_flags = (s32) ((this->motion_flags) | 0x40);
      this->photon_blast_gauge.set_field8((int) (*((s16 *) (((s8 *) get_photon_blast_entry(this->photon_blast_gauge.get_valid_index())) + 0x12))));
      this->photon_blast_gauge.set_field_0c(-0.2f);
    }
      play_persistent_sound(0x4002A823,this, NULL, 0, 0);
      break;
    case 1:
      this->frame = (f32) ((this->frame) + this->photon_blast_gauge.get_frame_step());
      if (this->photon_blast_gauge.get_frame_step() > 0.0f)
    {
      if ((this->frame) >= this->get_photon_blast_upper_bound())
      {
        this->photon_blast_gauge.set_field_0c(-0.2f);
      }
    }
    else
      if ((this->frame) <= (this->get_photon_blast_hold_frame() - 1.0f))
    {
      if (1)
      {
        this->photon_blast_gauge.set_field_0c(0.2f);
      }
    }
      this->photon_blast_gauge.decrement_countdown();
      if (this->photon_blast_gauge.get_countdown() < 0)
    {
      this->phase = 2;
      this->motion_flags = (s32) ((this->motion_flags) & 0xFFFFFFBF);
      this->photon_blast_gauge.set_complete_threshold(this->get_photon_blast_complete_threshold());
    }
      play_persistent_sound(0x4002A823,this, NULL, 0, 0);
      break;
    case 3:
      if (this->photon_blast_gauge.is_blast_launched() != 0)
    {
      this->phase = 4;
      this->clear_state_flags(0x80);
      this->resume_motion();
      this->update_active_instance(this->photon_blast_gauge.get_valid_index());
    }
      break;
  }
  if (this->resolve_move_collision() == 0U)
  {
    this->apply_velocity();
  }
}

void TObjPlayer::enter_photon_blast_action() {
    PhotonBlastTarget *slot;
    u16 id;
    TObjCollidable *actor;
    this->action_state = 9;
    run_action_state_phase(this->mode, 6);
    slot = this->photon_blast_gauge.get_target(0);
    id = slot->entity_id;
    if (id != 0xFFFF) {
        actor = find_entity_by_id(id);
        if (actor == NULL) {
            slot->entity_id = id = 0xFFFF;
        } else {
            photon_blast_aim.set_position(&actor->bodies[slot->index].center);
        }
    }
    if (id == 0xFFFF) {
        this->target_heading = this->rotation_y;
    } else {
        this->target_heading = calc_angle_to(this->get_position_ptr(), photon_blast_aim.get_position());
    }
    this->set_actor_flags(0x400000);
    clear_velocity();
    if (this->obj_isState2_324() != 0) {
        this->play_sound_if_on_floor(0x22824);
    } else {
        this->play_sound_if_on_floor(0x22322);
    }
    this->phase = 0;
    this->set_action_state(9, this->query_equip());
    this->set_state_flags(0x80);
    TObjPlayer::start_photon_blast(this->photon_blast_gauge.get_valid_index(), (u16)this->get_entity_id());
}
}
void handle_6x49_execute_photon_blast(G_ExecutePhotonBlast_6x49 *command) {
    s32 i;
    TObjPlayer *p;
    G_ExecutePhotonBlast_6x49 cmd;
    cmd = *command;
    cmd.bswap_received();
    if (validate_6x49_execute_photon_blast(&cmd) != 0) {
        p = get_player_by_client_id(cmd.header.client_id);
        if (p != NULL && p->test_action_mask(0x8000) == 0 && is_current_area_item_enabled() != 0) {
            if (get_current_floor() == p->get_floor()) {
                s32 count;
                PhotonBlastTarget *dst;
                PhotonBlastTarget *src;
                p->photon_blast_gauge.start_photon_blast_action();
                TObjPlayer::apply_photon_blast(cmd.header.client_id, cmd.params.photon_blast);
                p->photon_blast_gauge.set_blast(cmd.params.photon_blast);
                count = cmd.params.target_count;
                p->photon_blast_gauge.set_section_index(count);
                p->set_float_param(cmd.params.pb_meter_value);
                dst = p->photon_blast_gauge.get_target(0);
                src = cmd.targets;
                for (i = 0; i < count; i++) {
                    copy_tech_params(dst++, src++);
                }
                p->run_action_state_phase(9, 0);
            }
        }
    }
}
extern "C" {

extern "C++" void copy_tech_params(PhotonBlastTarget *dst, PhotonBlastTarget *src) {
    dst->entity_id = src->entity_id;
    dst->index = src->index;
}

void TObjPlayer::prepare_photon_blast_action() {
    s32 i;
    s16 n;
    PhotonBlastTarget *src;
    PhotonBlastTarget *dst;
    if (this->reset_volopt_state() != 0) {
        this->protection.set_frames(0x708);
        capture_technique_targets(this->photon_blast_gauge.get_valid_index(), this);
        if (this->lock_on_cursor != NULL) {
            PhotonBlastTarget *e = this->photon_blast_gauge.get_target(0);
            this->lock_on_cursor->set_cursor_pos(e->entity_id, e->index);
        }
        if (this == NULL || this->obj_isState2_324() == 0) {
            G_ExecutePhotonBlast_6x49 cmd;
            cmd.header.client_id = this->get_entity_id();
            cmd.params.photon_blast = this->photon_blast_gauge.get_valid_index();
            cmd.params.target_count = n = this->photon_blast_gauge.get_target_count();
            cmd.params.pb_meter_value = this->get_photon_blast_charge();
            src = this->photon_blast_gauge.get_target(0);
            dst = cmd.targets;
            for (i = 0; i < n; i++) {
                copy_tech_params(dst++, src++);
            }
            cmd.send();
        }
    }
}

void TObjPlayer::update_band_state() {
    if ((s16) this->phase == 2) {
        if (is_passing_frame(this->photon_blast_gauge.get_dist()) != 0) {
            this->phase = 3;
            pause_motion();
        }
    }
}

void TObjPlayer::update_target_approach() {
    if (this->motion_flags & 0x10) {
        update_position_from_target();
        return;
    }
    if ((s16) this->phase == 2) {
        if (is_passing_frame(this->photon_blast_gauge.get_dist()) != 0) {
            this->phase = 3;
            pause_motion();
            send_6x37_photon_blast();
        }
    }
}

void TObjPlayer::photon_blast_phase2_nop() {  }

int TObjPlayer::try_apply_status_action_default() { return try_status_action(); }

void TObjPlayer::dispatch_photon_blast_action(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_default();
        return;
      case 2:
        photon_blast_phase2_nop();
        return;
      case 3:
        this->update_target_approach();
        return;
      case 8:
        this->update_band_state();
        return;
      case 5:
        this->prepare_photon_blast_action();
        return;
      case 0:
        this->enter_photon_blast_action();
        return;
      case 1:
        this->update_photon_blast_action();
        return;
      case 6:
        this->exit_photon_blast_action();
        break;
    }
  }
}

}
void handle_6x33_revive_player(G_RevivePlayer_6x33 *command) {
    G_RevivePlayer_6x33 m;
    TObjPlayer *p;
    TObjPlayer *q;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x33_revive_player(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            q = get_player_by_client_id(m.client_id2);
            if (q != NULL && q->check_flag_4() == 0 && q->m_up == tl_03) {
                TargetCursorList targets;
                targets.count = 1;
                targets.records[0].id = m.client_id2;
                targets.records[0].flag = 0;
                targets.records[0].value = 10.0f;
                TTecReverser::create(p, p->get_position_ptr(), &targets, 0x1D);
            }
        }
    }
}

void send_6x33_revive_player(u16 client_id, u16 target_id) {
    G_RevivePlayer_6x33 pkt;
    TObjChara *chara = (TObjChara *)get_player_by_client_id(static_cast<u16>(client_id));
    if (chara == NULL || chara->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = client_id;
        pkt.client_id2 = target_id;
        pkt.send();
    }
}

extern "C" {

void TObjPlayer::set_technique_level_clamped(TObjPlayer *player, u8 level, s16 tech) {
    if (player->obj_isState3_324() != 0 && TObjPlayer::is_invalid_slot(level) == 0 &&
        level > player->technique_state.get_technique_level(tech)) {
        level = player->technique_state.get_technique_level(tech);
    }
    player->technique_state.set_learned_level(tech, level);
}

void TObjPlayer::update_cursor(s32 parameter) {
    TLockOnCursor *cursor;

    cursor = this->lock_on_cursor;
    if ((cursor != NULL) && (canSetMenuCursorAction((PaletteCursorOverride *)&cursor->palette_override, this, 3, (u8) parameter) != 0)) {
        set_action_palette_tag_mode(&lock_on_cursor->palette_override, 3);
        set_action_palette_tag_slot(&lock_on_cursor->palette_override, static_cast<u8>(parameter));
        set_action_channel_active((u8 *)&this->lock_on_cursor->palette_override);
    }
}

s32 TObjPlayer::try_equip_item(s16 tech) {
    if (this->test_action_mask(0x100) == 0) {
        if (this->can_equip_item(tech) == 0) {
            return 0;
        }
        this->technique_state.set_technique_id(tech);
        this->request_technique_cast();
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void tail_801CCD38(TObjPlayer *p, s32 t, s8 lvl) {
    switch (t) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
    case 16:
        p->technique_state.set_technique_state(calc_technique_parameters(t, lvl, p->get_entity_id())->duration);
        p->phase = 4;
        launch_technique(t, lvl, p);
        return;
    }
    if (p->check_flag_4() == 0 && p->m_up == tl_03) {
        p->technique_state.set_technique_state(calc_technique_parameters(t, lvl, p->get_entity_id())->duration);
        p->phase = 4;
        launch_technique(t, lvl, p);
    }
}
#pragma pop

}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void handle_6x48_cast_technique_complete(G_CastTechniqueComplete_6x48 *command) {
    G_CastTechniqueComplete_6x48 pkt;
    s8 lvl;
    u8 ul;
    TObjPlayer *p;
    s16 tech;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x48_cast_technique_complete(&pkt) == 0) {
        return;
    }
    p = get_player_by_client_id(pkt.header.client_id);
    if (p == NULL) {
        return;
    }
    if (p->reset_volopt_state() == 0) {
        return;
    }
    tech = pkt.technique_number;
    p->technique_state.set_technique_id(tech);
    lvl = pkt.level;
    if (lvl == 0xE) {
        lvl += p->technique_state.get_valid_technique();
    }
    if (p->technique_state.check_technique_level((s16)tech, (u8)lvl) == 0) {
        lvl = 0;
    }
    ul = lvl;
    p->technique_state.set_level(ul);
    TObjPlayer::set_technique_level_clamped(p, ul, tech);
    tail_801CCD38(p, tech, lvl);
}
#pragma pop

extern "C" {

void TObjPlayer::pay_tp_and_send_6x48_cast() {
    s16 tech;
    u8 hi;
    u8 lo;
    if (this->reset_volopt_state() != 0) {
        if (this == 0 || this->obj_isState2_324() == 0) {
            G_CastTechniqueComplete_6x48 pkt;
            this->phase = 4;
            tech = this->technique_state.get_or_init_field_4();
            this->tp -= calc_technique_parameters(tech, this->technique_state.get_castable_technique_level(), get_entity_id())->tp_cost;
            if (this->tp < 0) {
                this->tp = 0;
            }
            TObjPlayer::split_capped_value(this->technique_state.get_castable_technique_level(), &hi, &lo);
            pkt.init();
            pkt.header.client_id = get_entity_id();
            pkt.technique_number = tech;
            pkt.level = hi;
            pkt.send();
        }
    }
}

s32 TObjPlayer::try_camera_action(s32 tech) {
    if ((this->is_locally_controlled() != 0) && ((this->is_controls_locked() != 0) || (this->get_camera_field() == 0))) {
        return 0;
    }
    return this->can_start_technique(tech);
}

s32 TObjPlayer::can_equip_item(s32 tech) {
    if (this->is_locally_controlled() != 0) {
        return this->can_start_technique(tech);
    }
    return 0;
}

s32 TObjPlayer::can_start_technique(s32 tech) {
    if (technique_state.test_flag_2() != 0 ||
        this->test_actor_flags(0x20006) != 0 ||
        this->test_actor_flags(0x2000000) != 0 ||
        this->test_action_mask(0x11E) == 0 ||
        (tech == 0xE && TObjWarpBossMulti::is_flag_clear(this) == 0) ||
        (tech == 0x11 && TObjPlayer::is_camera_mode_active() != 0) ||
        TObjPlayer::validate_and_clear_slot(&this->technique_state, tech) != 0 ||
        this->reset_volopt_state() == 0) {
        return 0;
    }
    return this->tp - calc_technique_parameters(tech, get_cast_technique_level(&this->technique_state, tech), this->get_entity_id())->tp_cost >= 0 ? 1 : 0;
}

void TObjPlayer::exit_technique_cast() {
    this->motion_flags &= ~0x40;
    clear_state_flags(0x80);
    clear_actor_flags(0x400000);
    resume_motion();
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

void TObjPlayer::update_technique_cast() {
    s16 phase;
    u8 *cast_record;
    this->rotation_y = lerp_angle_half((int) (this->rotation_y), (int) (this->target_heading));
    cast_record = get_cast_motion_record();
    phase = this->phase;
    switch (phase) {
    case 3:
    case 5:
        break;
    case 0:
        this->phase = 1;
        this->set_state_flags(0x80);
        create_technique_charge_light((s16) (technique_state.get_or_init_field_4()),this);
        technique_state.set_technique_state(calc_technique_parameters(technique_state.get_or_init_field_4(), technique_state.get_castable_technique_level(), this->get_entity_id())->charge_speed);
        technique_state.set_charge_step(0.05f);
        break;
    case 1:
        if (this->is_flag_b0_4() == 0) {
            this->motion_flags = (s32) (this->motion_flags | 0x40);
            this->frame = (f32) (this->frame + technique_state.get_charge_step());
            if (technique_state.get_charge_step() > 0.0f) {
                if (this->frame >= 0.2f) {
                    technique_state.set_charge_step(-0.05f);
                }
            } else if (this->frame < 0.0f) {
                technique_state.set_charge_step(0.05f);
            }
        }
        technique_state.decrement_state();
        if (technique_state.get_state() < 0) {
            this->phase = 2;
            this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFBF);
        }
        break;
    case 2:
        if (this->is_passing_frame((f32) (*(f32 *)((s8 *)cast_record + 0xC))) != 0) {
            this->phase = 3;
            this->clear_state_flags(0x80);
            pause_motion();
            if (this->obj_isState2_324() == 0) {
                pay_tp_and_send_6x48_cast();
            }
        }
        break;
    case 4:
        technique_state.decrement_state();
        if (technique_state.get_state() < 0) {
            this->phase = 5;
            this->requested_action = this->get_idle_animation();
            this->resume_motion();
        }
        break;
    }
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::enter_technique_cast() {
    PhotonBlastTarget *td;
    u16 target;
    TObjCollidable *actor;
    action_state = 8;
    run_action_state_phase(this->mode, 6);
    td = technique_state.get_technique_data();
    target = td->entity_id;
    if (target == 0xFFFF || target == (u16)get_entity_id() ||
        technique_state.get_section_clamped() == 0) {
        target_heading = rotation_y;
    } else {
        actor = find_entity_by_id(target);
        if (actor == 0) {
            td->entity_id = 0xFFFF;
        } else {
            photon_blast_aim.set_position(&actor->bodies[td->index].center);
            target_heading = calc_angle_to(get_position_ptr(), photon_blast_aim.get_position());
        }
    }
    set_actor_flags(0x400000);
    clear_velocity();
    phase = 0;
    if (obj_isState2_324() != 0) {
        current_action = (s16)get_no_action();
    }
    set_action_state(8, get_status());
}

}
void handle_6x47_cast_technique(G_CastTechnique_6x47 *command) {
    G_CastTechnique_6x47 cmd;
    TObjPlayer *p;
    s32 i;
    s32 lim;
    s8 n;
    PhotonBlastTarget *d;
    PhotonBlastTarget *s;
    s16 c;
    s8 e;

    cmd = *command;
    cmd.bswap();
    if (validate_6x47_cast_technique(&cmd) == 0) {
        return;
    }
    p = get_player_by_client_id(cmd.header.client_id);
    if (p == NULL) {
        return;
    }
    if (p->reset_volopt_state() == 0) {
        return;
    }
    if (p->test_action_mask(0x8200) != 0) {
        return;
    }
    s32 technique = cmd.params.technique_number;
    c = technique;
    p->technique_state.set_technique_id(technique);
    e = cmd.params.level;
    n = p->technique_state.get_valid_technique();
    if (TObjPlayer::is_valid_technique_slot((u8)n) == 0) {
        n = 0;
    }
    if (e == 14) {
        e += n;
    }
    if (p->technique_state.check_technique_level(c, e) == 0) {
        e = 0;
    }
    p->technique_state.set_level((u8)e);
    TObjPlayer::set_technique_level_clamped(p, (u8)e, c);
    lim = cmd.params.target_count;
    p->technique_state.set_tech_level(lim);
    d = p->technique_state.get_technique_data();
    s = cmd.targets;
    for (i = 0; i < lim; i++) {
        copy_tech_params(d++, s++);
    }
    p->run_action_state_phase(8, 0);
}
void handle_6x8D_set_technique_level_override(G_SetTechniqueLevelOverride_6x8D *command) {
    G_SetTechniqueLevelOverride_6x8D m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x8D_set_technique_level_override(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->technique_state.set_tech_override(m.level_upgrade);
        }
    }
}
extern "C" {
void TObjPlayer::request_technique_cast() {
    u8 hi;
    u8 lo;
    G_SetTechniqueLevelOverride_6x8D m1;
    PhotonBlastTarget *td;
    s16 tech;
    s32 i;
    s32 count;
    PhotonBlastTarget *src;
    PhotonBlastTarget *dst;
    capture_technique_targets(technique_state.get_or_init_field_4(), this);
    if (lock_on_cursor != NULL) {
        td = technique_state.get_technique_data();
        ((TLockOnCursor *)lock_on_cursor)->set_cursor_pos(td->entity_id, td->index);
    }
    tech = technique_state.get_or_init_field_4();
    TObjPlayer::split_capped_value(get_cast_technique_level(&technique_state, tech), &hi, &lo);
    if (this == NULL || obj_isState2_324() == 0) {
        m1.init();
        m1.header.client_id = get_entity_id();
        m1.level_upgrade = lo;
        m1.send();
        G_CastTechnique_6x47 cmd;
        cmd.header.client_id = get_entity_id();
        cmd.params.technique_number = tech;
        cmd.params.level = hi;
        count = technique_state.get_section_clamped();
        cmd.params.target_count = count;
        src = technique_state.get_technique_data();
        dst = cmd.targets;
        for (i = 0; i < count; i++) {
            copy_tech_params(dst++, src++);
        }
        cmd.send();
    }
}

void TObjPlayer::check_anim_done() {
    if (((s16) this->phase == 5) && (this->is_anim_finished() != 0)) {
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::update_state5_action() {
    if (((s16) this->phase == 5) && (this->is_anim_finished() != 0)) {
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::technique_cast_phase2_nop() {  }

int TObjPlayer::apply_status_action_a() { return try_status_action(); }

void TObjPlayer::dispatch_technique_cast_state(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->apply_status_action_a();
        return;
      case 2:
        technique_cast_phase2_nop();
        return;
      case 3:
        this->update_state5_action();
        return;
      case 8:
        this->check_anim_done();
        return;
      case 5:
        this->request_technique_cast();
        return;
      case 0:
        this->enter_technique_cast();
        return;
      case 1:
        this->update_technique_cast();
        return;
      case 6:
        this->exit_technique_cast();
        break;
    }
  }
}

void TObjPlayer::reset_linked_obj() {
    TLockOnCursor *lock_on_cursor;

    clear_velocity();
    this->resume_motion();
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

void TObjPlayer::update_attack_stage3() { this->update_attack_stage(); }

void TObjPlayer::enter_attack_stage3() {
    this->action_state = 7;
    this->run_action_state_phase(this->mode, 6);
    this->attack_state.set_attack_kind(this->attack_state.get_validated_queued_kind());
    update_player_action_palette(this, static_cast<u8>(this->attack_state.get_validated_attack_kind()));
    this->attack_state.begin(this, 2, 2);
    this->setup_attack_stage();
    this->set_action_state(7, this->get_model_state());
    apply_speed_scale(get_action_rate_entry() * this->attack_state.get_attack_speed());
}

}
void handle_6x45_attack(G_Attack_6x45 *command) {
    G_Attack_6x45 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x45_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == 0) return;
    if (player->is_in_tl03_state() == 0) return;
    if (player->reset_volopt_state() == 0) return;
    if (player->test_action_mask(0x8200) != 0) return;
    player->attack_state.set_attack_kind(pkt.action_type);
        player->attack_state.set_queued_kind(pkt.action_type);
    player->target_heading = pkt.angle_y;
    player->run_action_state_phase(7, 0);
}
extern "C" {

void TObjPlayer::send_attack_stage3_request() {
    G_Attack_6x45 cmd;
    s32 heading;
    Vec *position;
    s32 angle;
    TObjChara *target;
    TLockOnCursor *lock_on_cursor;
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        target = resolve_hittable_target(lock_on_cursor->target_part.actor_id, lock_on_cursor->target_part.collider);
        if (target != NULL) {
            position = this->get_position_ptr();
            angle = calc_angle_to(position, &target->bodies[this->lock_on_cursor->target_part.collider].center);
        } else {
            angle = this->rotation_y;
        }
        heading = calc_scaled_value(angle);
        if ((this == NULL) || (this->obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = this->get_entity_id();
            cmd.angle_y = heading;
            cmd.action_type = this->attack_state.get_validated_queued_kind();
            cmd.send();
        }
    }
}

void TObjPlayer::attack_stage3_phase8_nop() {  }

void TObjPlayer::finish_attack_stage3() {
    if ((s16) this->phase == 4) {
        if (this->is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if (this->motion_flags & 0x10) {
        if (test_flags_any(&this->attack_state.get_flags()->bits, 1) != 0) {
            this->phase = 4;
            this->requested_action = this->get_idle_animation();
            this->resume_motion();
        }
    }
}

void TObjPlayer::check_attack_stage3_input() {  }

int TObjPlayer::try_apply_status_action_1() { return try_status_action(); }

void TObjPlayer::run_attack_stage3_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_1();
        return;
      case 2:
        TObjPlayer::check_attack_stage3_input();
        return;
      case 3:
        this->finish_attack_stage3();
        return;
      case 8:
        attack_stage3_phase8_nop();
        return;
      case 5:
        this->send_attack_stage3_request();
        return;
      case 0:
        this->enter_attack_stage3();
        return;
      case 1:
        update_attack_stage3();
        return;
      case 6:
        this->reset_linked_obj();
        break;
    }
  }
}

void TObjPlayer::reset_target_link() {
    TLockOnCursor *lock_on_cursor;

    clear_velocity();
    this->resume_motion();
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

void TObjPlayer::update_attack_stage2() { this->update_attack_stage(); }

void TObjPlayer::enter_attack_stage2() {
    this->action_state = 6;
    this->run_action_state_phase(this->mode, 6);
    this->attack_state.set_attack_kind(this->attack_state.get_validated_queued_kind());
    update_player_action_palette(this, static_cast<u8>(this->attack_state.get_validated_attack_kind()));
    this->attack_state.begin(this, 1, 1);
    this->setup_attack_stage();
    this->set_action_state(6, this->get_state());
    apply_speed_scale(get_action_rate_entry() * this->attack_state.get_attack_speed());
}

}
void handle_6x44_attack(G_Attack_6x44 *command) {
    G_Attack_6x44 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x44_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == 0) return;
    if (player->is_in_tl03_state() == 0) return;
    if (player->reset_volopt_state() == 0) return;
    if (player->test_action_mask(0x8200) != 0) return;
    player->attack_state.set_attack_kind(pkt.action_type);
        player->attack_state.set_queued_kind(pkt.action_type);
    player->target_heading = pkt.angle_y;
    player->run_action_state_phase(6, 0);
}
extern "C" {

void TObjPlayer::send_attack_stage2_request() {
    G_Attack_6x44 cmd;
    s32 heading;
    Vec *position;
    s32 angle;
    TObjChara *target;
    TLockOnCursor *lock_on_cursor;
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        target = resolve_hittable_target(lock_on_cursor->target_part.actor_id, lock_on_cursor->target_part.collider);
        if (target != NULL) {
            position = this->get_position_ptr();
            angle = calc_angle_to(position, &target->bodies[this->lock_on_cursor->target_part.collider].center);
        } else {
            angle = this->rotation_y;
        }
        heading = calc_scaled_value(angle);
        if ((this == NULL) || (this->obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = this->get_entity_id();
            cmd.angle_y = heading;
            cmd.action_type = this->attack_state.get_validated_queued_kind();
            cmd.send();
        }
    }
}

void TObjPlayer::attack_stage2_phase8_nop() {  }

void TObjPlayer::finish_attack_stage2() {
    if (this->phase == 4) {
        if (is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if ((this->motion_flags & 0x10) &&
               test_flags_any(&this->attack_state.get_flags()->bits, 1) != 0) {
        switch (attack_state.get_validated_attack_stage()) {
        case 0:
        case 1:
            this->phase = 4;
            resume_motion();
            this->requested_action = get_idle_animation();
            break;
        case 2:
            run_action_state_phase(7, 5);
            break;
        }
    }
}

void TObjPlayer::check_attack_stage2_input() {
    s32 slot;

    slot = select_attack_palette_slot();
    if (slot != -1) {
        this->attack_state.queue_physical_attack_input(this, slot, 2);
    }
}

int TObjPlayer::apply_status_action() { return try_status_action(); }

void TObjPlayer::run_attack_stage2_phase(s16 phase) {
    switch (phase) {
    case 7:
        apply_status_action();
        return;
    case 2:
        check_attack_stage2_input();
        return;
    case 3:
        finish_attack_stage2();
        return;
    case 8:
        attack_stage2_phase8_nop();
        return;
    case 5:
        send_attack_stage2_request();
        return;
    case 0:
        enter_attack_stage2();
        return;
    case 1:
        update_attack_stage2();
        return;
    case 6:
        reset_target_link();
        break;
    }
}

void TObjPlayer::start_attack_preparation() {
    switch (this->attack_state.get_validated_attack_kind()) {
    case 0:
        this->phase = 3;
        break;
    case 1:
        this->phase = 1;
        this->set_state_flags(0x80);
        ((TObjPlayer *)&this->follow_particles)->request_heavy_attack_particles();
        scratch_vec.y = scratch_vec.x = 0.0f;
        player_feedback_light_color.a = scratch_vec.z = 1.0f;
        player_feedback_light_color.g = player_feedback_light_color.r = 0.8f;
        player_feedback_light_color.b = 1.0f;
        new TActorLight(0.2f, &player_feedback_light_color, &scratch_vec, 8, this, tl_07);
        publish_actor_light_scalars(this->get_entity_id(), 1.0f, 0.5f);
        this->play_sound_if_on_floor(0x1AD1C);
        break;
    case 2:
        this->phase = 1;
        this->set_state_flags(0x80);
        dispatch_weapon_special_effect(this, 0, 0, 0);
        scratch_vec.y = scratch_vec.x = 0.0f;
        player_feedback_light_color.a = scratch_vec.z = 1.0f;
        player_feedback_light_color.g = player_feedback_light_color.r = 0.8f;
        player_feedback_light_color.b = 1.0f;
        new TActorLight(0.2f, &player_feedback_light_color, &scratch_vec, 8, this, tl_07);
        publish_actor_light_scalars(this->get_entity_id(), 1.0f, 0.5f);
        this->play_sound_if_on_floor(0x1AD1D);
        break;
    }
}

void TObjPlayer::setup_attack_stage() {
    this->phase = 0;
    switch (this->attack_state.get_validated_attack_kind()) {
    case 0:
        if (attack_state.get_validated_attack_stage() == 0) {
            set_field_d4_and_flag_200(0.5f);
        }
        break;
    case 1:
    case 2:
        if (attack_state.get_validated_attack_stage() == 0) {
            set_field_d4_and_flag_200(0.2f);
        }
        break;
    }
}

struct TargetCollider {
    u8 pad0[0x18];
    u32 flags;
    u8 pad1C[0x10];
};



int TObjPlayer::deliver_attack_hits(f32 damage_scale) {
    s32 count;
    s32 i;
    int hit = 0;
    CapturedTarget *entry;
    count = attack_state.get_lockon_targets()->get_captured_target_count();
    entry = attack_state.get_lockon_targets()->get_captured_target_entry(0);
    for (i = 0; i < count; i++) {
        u16 uid = entry->get_uid();
        s16 collider = entry->get_captured_target_collider_index();
        TObjChara *target = (TObjChara *)resolve_hittable_target(uid, collider);
        if (target == NULL) {
            continue;
        }
        if (pk_state.is_enabled() != 0 && obj_isState2_324() != 0 &&
            ((TObjEneBeastBase *)target)->test_elt_flag(collider, 0x2000) == 0) {
            continue;
        }
        if ((((TargetCollider *)bodies)->flags ^ ((TargetCollider *)target->bodies)[collider].flags) & 6) {
            continue;
        }
        f32 accuracy;
        if (attack_state.get_validated_attack_kind() == 2 && get_equipped_weapon(this) != NULL &&
            get_equipped_weapon(this)->is_identified() == 0) {
            if ((f32)get_ata() < 0.0f) {
                accuracy = 0.0f;
            } else {
                accuracy = 0.1f;
            }
        } else {
            accuracy = attack_state.get_attack_accuracy_scale();
        }
        if (target->roll_physical_accuracy(this, collider, accuracy) != 0) {
            s32 damage;
            f32 dealt;
            switch (attack_state.get_validated_attack_kind()) {
            case 0:
                damage = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                apply_camera_shake(target, damage);
                break;
            case 1:
                dealt = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                damage = dealt;
                gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                apply_camera_shake(target, damage);
                target->apply_knockback_from_attacker((u8 *)this, 0.1f * dealt);
                break;
            case 2:
                target->receive_weapon_special_attack(this, &((TargetCollider *)target->bodies)[collider]);
                break;
            }
            hit = 1;
            ItemSoundRequest sound;
            sound.clear();
            TItem *item = get_equipped_weapon(this);
            if (item != NULL) {
                sound.group = item->get_item_group();
                sound.index = item->get_item_index();
            }
            sound.player = this;
            sound.target = target;
            sound.collider = collider;
            play_weapon_hit_sound(&sound);
        } else {
            switch (obj_getS16_116()) {
            case 4:
            case 5:
            case 6:
            case 9:
            case 10:
            case 13:
                ((TObjPlayer *)target)->show_miss_for_collider(collider);
                break;
            default:
                switch (attack_state.get_validated_attack_kind()) {
                case 2:
                    if (target->roll_physical_accuracy(this, collider,
                                                       attack_state.calc_attack_stage_multiplier(2)) != 0) {
                        s32 damage = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                        gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                        apply_camera_shake(target, damage);
                        hit = 1;
                        ItemSoundRequest sound;
                        sound.clear();
                        TItem *item = get_equipped_weapon(this);
                        if (item != NULL) {
                            sound.group = item->get_item_group();
                        }
                        sound.player = this;
                        sound.target = target;
                        sound.collider = collider;
                        play_weapon_hit_sound(&sound);
                    } else {
                        ((TObjPlayer *)target)->show_miss_for_collider(collider);
                    }
                    break;
                default:
                    ((TObjPlayer *)target)->show_miss_for_collider(collider);
                    break;
                }
                break;
            }
        }
        entry++;
    }
    return hit;
}

}
void handle_6x46_attack_finished(G_AttackFinished_6x46 *command) {
    G_AttackFinished_6x46 packet;
    TObjPlayer *pl;
    TItem *it;
    packet = *command;
    packet.bswap_received();
    if (validate_6x46_attack_finished(&packet.header) != 0 && (pl = get_player_by_client_id(packet.header.client_id)) != NULL) {
        if (pl->is_in_tl03_state() != 0 && pl->reset_volopt_state() != 0) {
            pl->attack_state.set_lockon_targets(&packet.targets);
            it = TObjPlayer::get_equipped_weapon(pl);
            if (it != NULL) {
                it->perform_action();
                return;
            }
            if (pl->deliver_attack_hits(1.0f) == 0) {
                pl->play_sound_if_on_floor(0x4001A80C);
            }
        }
    }
}
extern "C" {

void TObjPlayer::send_attack_target_packet() {
    if (((this->obj_isState2_324() == 0) || (this->reset_volopt_state() != 0)) && ((this->obj_isState3_324() != 0) || (this->attack_state.capture_lockon_targets(this) != 0)) && (this->is_body_collision_inactive() == 0) && ((this == NULL) || (this->obj_isState2_324() == 0))) {
        G_AttackFinished_6x46 packet;
        packet.header.client_id = this->get_entity_id();
        copy_attack_targets(&packet.targets, this->attack_state.get_lockon_targets());
        packet.send();
    }
}

s32 TObjPlayer::select_attack_palette_slot() {
    s32 r = -1;
    if (get_action_palette_mode(((u8 *)this), 1) == 2 && pad_binding.is_button_pressed(4) != 0) {
        r = 1;
    }
    if (get_action_palette_mode(((u8 *)this), 2) == 2 && pad_binding.is_button_pressed(0x400) != 0 &&
        is_palettex_activated(this->get_entity_id()) == 0) {
        r = 2;
    }
    if (get_action_palette_mode(((u8 *)this), 3) == 2 && pad_binding.is_button_pressed(2) != 0) {
        r = 3;
    }
    return this->check_mode_action((u16)this->get_action_palette_entry(r)) != 0 ? r : -1;
}

s32 TObjPlayer::check_mode_action(s32 action) {
    if (action == 2) {
        TItem *weapon = get_equipped_weapon(this);
        if (weapon != NULL) {
            if (weapon_has_extra_attack((TItemWeapon *)weapon) == 0) {
                return 0;
            }
            goto block_5;
        }
        return 0;
    }
block_5:
    return can_perform_physical_action();
}

s32 TObjPlayer::can_perform_physical_action() {
    if ((this->test_actor_flags(0x20006) != 0) || (this->test_actor_flags(0x02000000) != 0) || (this->check_flag(2) != 0) || (this->test_action_mask(0x548000) != 0) || ((this->is_locally_controlled() != 0) && ((is_controls_locked() != 0) || (this->get_camera_field() == 0))) || (this->reset_volopt_state() == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_by_state() {

    switch (this->get_handle_value()) {
    case 0:
        if (this->motion_flags & 0x10) {
            this->attack_state.end_swing();
        }
        return;
    case 8:
        this->attack_state.tick_burst_recovery();
        return;
    default:
        if (this->motion_flags & 0x10) {
            this->attack_state.tick_recovery_timer();
        }
        break;
    }
}

void TObjPlayer::apply_movement_if_ready() {
    s16 handle_value;

    handle_value = this->get_handle_value();
    if ((handle_value != 0x11) && ((handle_value >= 0x11) || (handle_value >= 0xA) || (handle_value < 6)) && (this->is_flag_b0_4() == 0) && ((s16) this->requested_action == (s16) this->current_action) && (this->action_flags & 0x20000000) && (this->is_motion_paused() == 0)) {
        if (0.0f > get_root_motion_step(&this->velocity.x, &this->velocity.z)) {
            clear_velocity();
        }
        if (this->check_actor_blocking_move() != 0) {
            clear_velocity();
        }
        if (this->resolve_move_collision() == 0U) {
            this->apply_velocity();
        }
    }
}

void TObjPlayer::update_anim_action() {
    get_equipped_weapon(this);
    if (this->get_handle_value() != 8) {
        if (is_passing_frame(select_normal_attack_marker()) != 0) {
            send_attack_target_packet();
            this->attack_state.increment_hit_count();
            this->attack_state.register_strike(this);
        }
    } else {
        if (test_flags_any(&this->attack_state.get_flags()->bits, 8) == 0) {
            if (is_passing_frame(select_normal_attack_marker()) != 0) {
                send_attack_target_packet();
                increment_burst_counter((u8 *)&this->attack_state);
                if (get_burst_counter(&this->attack_state) >= 3) {
                    this->attack_state.get_flags()->set(8);
                    this->attack_state.register_strike(this);
                    pause_motion();
                    this->motion_flags = (s32) (this->motion_flags | 0x10);
                }
            }
        }
    }
}

void TObjPlayer::update_attack_stage() {
    s32 timer;

    this->rotation_y = lerp_angle_half(this->rotation_y, this->target_heading);
    switch (this->phase) {
    case 0:
        this->start_attack_preparation();
    case 1:
        if (this->is_anim_finished() != 0) {
            this->phase = 2;
            this->pause_motion();
        }
    case 4:
        return;
    case 2:
        timer = this->attack_state.get_recovery_timer() - 1;
        if (timer < 0) {
            this->phase = 3;
            this->resume_motion();
        }
        this->attack_state.set_recovery_timer(timer);
        return;
    case 3:
        this->update_anim_action();
        this->apply_movement_if_ready();
        this->update_by_state();
        break;
    }
}

void TObjPlayer::reset_lockon() {
    TLockOnCursor *lock_on_cursor;

    clear_velocity();
    this->resume_motion();
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

void TObjPlayer::update_action_state() {
    this->update_attack_stage();
}

void TObjPlayer::enter_attack_stage1() {
    this->action_state = 5;
    this->run_action_state_phase(this->mode, 6);
    clear_velocity();
    this->attack_state.begin(this, 0, 0);
    this->setup_attack_stage();
    this->set_action_state(5, this->get_attack1_action());
    apply_speed_scale(get_action_rate_entry() * this->attack_state.get_attack_speed());
}

}
void handle_6x43_attack(G_Attack_6x43 *command) {
    G_Attack_6x43 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x43_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == 0) return;
    if (player->is_in_tl03_state() == 0) return;
    if (player->reset_volopt_state() == 0) return;
    if (player->test_action_mask(0x8200) != 0) return;
    player->attack_state.set_attack_kind(pkt.action_type);
    player->target_heading = pkt.angle_y;
    player->run_action_state_phase(5, 0);
}
void TObjPlayer::request_normal_attack_stage1() {
    Vec target_pos;
    G_Attack_6x43 cmd;
    s32 heading;
    s32 angle;
    if ((this->reset_volopt_state() != 0) && (this->attack_state.capture_lockon_targets(this) != 0)) {
        if (this->attack_state.get_first_target_position(&target_pos) != 0) {
            angle = calc_angle_to(get_position_ptr(), &target_pos);
        } else {
            angle = this->rotation_y;
        }
        heading = calc_scaled_value(angle);
        if ((this == NULL) || (obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = get_entity_id();
            cmd.angle_y = heading;
            cmd.action_type = this->attack_state.get_validated_attack_kind();
            cmd.send();
        }
    }
}

extern "C" {
void TObjPlayer::attack_stage1_phase8_nop() {  }

void TObjPlayer::finish_attack_stage1() {
    if (this->phase == 4) {
        if (is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if ((this->motion_flags & 0x10) &&
               test_flags_any(&this->attack_state.get_flags()->bits, 1) != 0) {
        switch (attack_state.get_validated_attack_stage()) {
        case 0:
            this->phase = 4;
            resume_motion();
            this->requested_action = get_idle_animation();
            break;
        case 1:
        case 2:
            run_action_state_phase(6, 5);
            break;
        }
    }
}

void TObjPlayer::update_active_item() {
    s32 slot;

    slot = select_attack_palette_slot();
    if (slot != -1) {
        this->attack_state.queue_physical_attack_input(this, slot, 1);
    }
}

int TObjPlayer::try_attack_stage1_status_action() { return try_status_action(); }

void TObjPlayer::run_attack_stage1_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_attack_stage1_status_action();
        return;
      case 2:
        this->update_active_item();
        return;
      case 3:
        this->finish_attack_stage1();
        return;
      case 8:
        attack_stage1_phase8_nop();
        return;
      case 5:
        this->request_normal_attack_stage1();
        return;
      case 0:
        this->enter_attack_stage1();
        return;
      case 1:
        this->update_action_state();
        return;
      case 6:
        this->reset_lockon();
        break;
    }
  }
}

s32 TObjPlayer::update_aim_target() {
    f32 x;
    s32 collision;

    if (this->is_inactive() == 0) {
        return 0;
    }
    x = 1.5f * sin_table_lookup(this->target_heading);
    this->velocity.x = x;
    this->velocity.y = 0.0f;
    this->velocity.z = 1.5f * cos_table_lookup(this->target_heading);
    if (this->check_actor_blocking_move() != 0) {
        clear_velocity();
        return 0;
    }
    collision = this->resolve_move_collision();
    if (collision == 0) {
        return 1;
    }
    if ((this->is_locally_controlled() != 0) && (this->check_player_flag1() == 0) && (collision == 4)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::apply_damage_and_reset() { clear_motion_flags((saddr)((void*)256)); clear_velocity(); }

void TObjPlayer::update_run_movement() {
    s32 ang;
    f32 dist;
    target_heading = calc_angle_to(get_position_ptr(), &move_target);
    rotation_y = approach_angle_adaptive(rotation_y, target_heading);
    ang = lerp_angle_half(rotation_y, target_heading);
    velocity.x = move_speed.get_speed() * sin_table_lookup(ang);
    velocity.y = 0.0f;
    velocity.z = move_speed.get_speed() * cos_table_lookup(ang);
    dist = (move_target.x - position.x) * (move_target.x - position.x) + (move_target.z - position.z) * (move_target.z - position.z);
    if ((2.0f * move_speed.get_speed()) * (2.0f * move_speed.get_speed()) > dist) {
        move_speed.flags.set(4);
    }
    if (this->resolve_move_collision() == 0U) {
        apply_velocity();
    } else {
        move_speed.flags.set(4);
    }
    play_footstep_sound(1.0f, 10.0f);
    emit_footstep_effect(1.0f, 10.0f);
}

void TObjPlayer::start_action() {
    f32 unscaled_speed;
    f32 rate;
    s16 action;

    this->action_state = 4;
    run_action_state_phase(this->mode, 6);
    move_speed.flags.reset();
    action = get_run_action__10TObjPlayerFv(this);
    if (is_matching_id(action) != 0) {
        set_action_flag();
    }
    move_speed.update(this, 1.5f);
    set_action_state(4, action);
    unscaled_speed = move_speed.get_unscaled_speed();
    rate = get_action_rate_entry();
    set_override_speed(rate * unscaled_speed);
}

}
void handle_6x42_move_to_position(G_MoveToPosition_6x41_6x42 *command) {
    G_MoveToPosition_6x41_6x42 cmd;
    TObjPlayer *p;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6x42_move_to_position(&cmd) != 0) {
        p = get_player_by_client_id(cmd.header.client_id);
        if (p != 0 && p->is_in_tl03_state() != 0 && p->test_action_mask(0x1E) != 0) {
            p->move_target.x = cmd.pos.x;
            p->move_target.z = cmd.pos.z;
            p->run_action_state_phase(4, 0);
        }
    }
}
void TObjPlayer::send_6x42_run_to_position() {
    G_MoveToPosition_6x41_6x42 m;
    if (update_aim_target() != 0) {
        calc_movement_target(target_heading, &move_target.x, &move_target.z);
        if ((this == NULL) || (obj_isState2_324() == 0)) {
            m.init();
            m.header.client_id = get_entity_id();
            m.pos.x = move_target.x;
            m.pos.z = move_target.z;
            m.send();
        }
    }
}

void TObjPlayer::handle_ring_release() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::try_trigger_effect() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        run_action_state_phase(1, 5);
    }
}

void TObjPlayer::select_run_request() {
    f32 magnitude;
    s32 stick_angle;
    s32 heading;
    stick_angle = pad_binding.get_stick_angle();
    magnitude = pad_binding.get_stick_magnitude();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        if (magnitude < 0.1f) {
            if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                run_action_state_phase(1, 5);
                return;
            }
            return;
        } else {
            heading = calc_scaled_value(stick_angle);
            if ((this->test_actor_flags(0x100000) != 0) || (magnitude < 0.5f)) {
                move_speed.set_run_counter(0);
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    this->target_heading = heading;
                    run_action_state_phase(2, 5);
                }
            } else {
                move_speed.increment_run_counter();
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    this->target_heading = heading;
                    run_action_state_phase(4, 5);
                }
            }
        }
    }
}

int TObjPlayer::try_run_status_action() { return try_status_action(); }

void TObjPlayer::dispatch_run_state(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_run_status_action();
        return;
      case 2:
        this->select_run_request();
        return;
      case 3:
        this->try_trigger_effect();
        return;
      case 8:
        this->handle_ring_release();
        return;
      case 5:
        this->send_6x42_run_to_position();
        return;
      case 0:
        start_action();
        return;
      case 1:
        this->update_run_movement();
        return;
      case 6:
        this->apply_damage_and_reset();
        break;
    }
  }
}

void TObjPlayer::action3_phase6_nop() {  }

void TObjPlayer::action3_phase1_nop() {  }

void TObjPlayer::action3_phase0_nop() {  }

void handle_6x41_move_to_position(void) {

}

void TObjPlayer::action3_phase5_nop() {  }

void TObjPlayer::action3_phase8_nop() {  }

void TObjPlayer::action3_phase3_nop() {  }

void TObjPlayer::action3_phase2_nop() {  }

int TObjPlayer::apply_status_action_b() { return try_status_action(); }

#pragma push
#pragma opt_lifetimes off
void TObjPlayer::run_action3_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->apply_status_action_b();
        return;
      case 2:
        action3_phase2_nop();
        return;
      case 3:
        action3_phase3_nop();
        return;
      case 8:
        action3_phase8_nop();
        return;
      case 5:
        action3_phase5_nop();
        return;
      case 0:
        action3_phase0_nop();
        return;
      case 1:
        action3_phase1_nop();
        return;
      case 6:
        action3_phase6_nop();
        break;
    }
  }
}
#pragma pop

#pragma push
#pragma opt_lifetimes off
// The slow walk while move_speed flag 8 is set.
s16 TObjPlayer::get_walk_action() {
    if (test_flags_any(&move_speed.flags.bits, 8) != 0) {
        return action_provider->get_slow_walk_action();
    }
    return action_provider->get_walk_action();
}
#pragma pop

s32 TObjPlayer::update_combat_stats() {
    f32 x;
    f32 speed;
    s32 collision;

    if (this->is_inactive() == 0) {
        return 0;
    }
    speed = move_speed.calc_speed(this);
    x = speed * sin_table_lookup(this->target_heading);
    this->velocity.x = x;
    this->velocity.y = 0.0f;
    this->velocity.z = speed * cos_table_lookup(this->target_heading);
    if (this->check_actor_blocking_move() != 0) {
        clear_velocity();
        return 0;
    }
    collision = this->resolve_move_collision();
    if (collision == 0) {
        return 1;
    }
    if ((((TObjChara *)((u8 *)this))->is_locally_controlled() != 0) && (this->check_player_flag1() == 0) && (collision == 4)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TObjPlayer::calc_movement_target(s32 angle, f32 *out_x, f32 *out_z) {
    *out_x = (8.0f * sin_table_lookup(angle)) + this->position.x;
    *out_z = (8.0f * cos_table_lookup(angle)) + this->position.z;
}
#pragma pop

void TObjPlayer::reset_and_flag() { clear_velocity(); clear_motion_flags((saddr)((void*)256)); }

void TObjPlayer::update_walk_movement() {
    s32 ang;
    f32 dist;
    target_heading = calc_angle_to(get_position_ptr(), &move_target);
    rotation_y = approach_angle_adaptive(rotation_y, target_heading);
    ang = lerp_angle_half(rotation_y, target_heading);
    velocity.x = move_speed.get_speed() * sin_table_lookup(ang);
    velocity.y = 0.0f;
    velocity.z = move_speed.get_speed() * cos_table_lookup(ang);
    dist = (move_target.x - position.x) * (move_target.x - position.x) + (move_target.z - position.z) * (move_target.z - position.z);
    if ((2.0f * move_speed.get_speed()) * (2.0f * move_speed.get_speed()) > dist) {
        move_speed.flags.set(4);
    }
    if (this->resolve_move_collision() == 0U) {
        apply_velocity();
    } else {
        move_speed.flags.set(4);
    }
    play_footstep_sound(1.0f, 15.0f);
    emit_footstep_effect(1.0f, 15.0f);
}

void TObjPlayer::set_attack_state() {
    f32 unscaled_speed;
    f32 rate;
    s32 action;

    this->action_state = 2;
    run_action_state_phase(this->mode, 6);
    action = get_walk_action();
    if (is_matching_id(action) != 0) {
        set_action_flag();
    }
    move_speed.update(this);
    set_action_state(2, action);
    unscaled_speed = move_speed.get_unscaled_speed();
    rate = get_action_rate_entry();
    set_override_speed(rate * unscaled_speed);
}
void handle_6x40_walk_to_position(G_WalkToPosition_6x40 *command) {
    G_WalkToPosition_6x40 cmd;
    TObjPlayer *p;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6x40_walk_to_position(&cmd) != 0) {
        p = get_player_by_client_id(cmd.header.client_id);
        if (p != 0 && p->is_in_tl03_state() != 0 && p->test_action_mask(0x1E) != 0) {
            p->move_target.x = cmd.pos.x;
            p->move_target.z = cmd.pos.z;
            p->move_speed.flags.set_bits(cmd.flags);
            p->run_action_state_phase(2, 0);
        }
    }
}
extern "C" {

void TObjPlayer::send_6x40_walk_to_position() {
    G_WalkToPosition_6x40 m;
    if (update_combat_stats() != 0) {
        calc_movement_target(target_heading, &move_target.x, &move_target.z);
        move_speed.flags.reset();
        if (test_actor_flags(0x100000) != 0) {
            move_speed.flags.set(8);
        }
        if ((this == NULL) || (obj_isState2_324() == 0)) {
            m.init();
            m.header.client_id = get_entity_id();
            m.pos.x = move_target.x;
            m.pos.z = move_target.z;
            m.flags = move_speed.flags.get_bits();
            m.send();
        }
    }
}

void TObjPlayer::handle_ring_hit() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        this->clear_player_status_flag(0, 0x01C00000);
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::check_ring_action() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        move_speed.set_run_counter(0);
        run_action_state_phase(1, 5);
    }
}

void TObjPlayer::select_walk_request() {
    f32 magnitude;
    s32 stick_angle;
    s32 heading;

    stick_angle = pad_binding.get_stick_angle();
    magnitude = pad_binding.get_stick_magnitude();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        if (magnitude < 0.1f) {
            if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                run_action_state_phase(1, 5);
                return;
            }
            return;
        } else {
            heading = calc_scaled_value(stick_angle);
            if (magnitude > 0.5f) {
                move_speed.increment_run_counter();
            }
            if (this->test_actor_flags(0x100000) != 0) {
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    this->target_heading = heading;
                    run_action_state_phase(2, 5);
                }
            } else if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                this->target_heading = heading;
                if ((f32) move_speed.get_run_counter() < 24.0f) {
                    run_action_state_phase(2, 5);
                    return;
                }
                run_action_state_phase(4, 5);
            }
        }
    }
}

int TObjPlayer::try_walk_status_action() { return try_status_action(); }

void TObjPlayer::run_walk_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_walk_status_action();
        return;
      case 2:
        this->select_walk_request();
        return;
      case 3:
        this->check_ring_action();
        return;
      case 8:
        this->handle_ring_hit();
        return;
      case 5:
        this->send_6x40_walk_to_position();
        return;
      case 0:
        set_attack_state();
        return;
      case 1:
        this->update_walk_movement();
        return;
      case 6:
        this->reset_and_flag();
        break;
    }
  }
}

s16 TObjPlayer::get_idle_animation() {
    if (this->actorFlags & 0x100000) {
        return action_provider->get_lock_on_idle_action();
    }
    return action_provider->get_idle_action();
}

void TObjPlayer::cleanup_idle_entry() { clear_actor_flags((uaddr)((void*)3840)); clear_state_flags((s32)(128)); move_speed.set_run_counter(0); this->resume_motion(); clear_velocity(); death_sink.reset(); }

void TObjPlayer::exit_idle_state() {  }

void TObjPlayer::update_action(saddr owner) {
    u32 collision;
    TObjPlayer *p = (TObjPlayer *)owner;

    collision = p->resolve_move_collision();
    if (collision == 0U) {
        p->apply_velocity();
    } else if (collision == 1U) {
        p->rewind_position_history();
    }
    if ((p->is_newman() != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (p->tick_regen_timer() != 0)) {
        add_actor_tp(p, 1);
    }
    if ((is_android_player(p) != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (p->tick_regen_timer() != 0)) {
        add_actor_hp(p, 1);
    }
}

void TObjPlayer::start_animation() {
    this->action_state = 1;
    run_action_state_phase(this->mode, 6);
    cleanup_idle_entry();
    this->set_action_state(1, this->get_idle_animation());
}
}
void handle_6x3F_set_position(G_SetPosition_6x3F *command) {
    G_SetPosition_6x3F m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x3F_set_position(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->set_position_from(&m.pos);
            ::set_flag_400000(p);
            if (m.floor >= 0) {
                p->set_floor(m.floor);
                p->set_floor_index(get_floor_area(m.floor));
            }
            if (m.room >= 0) {
                p->set_room(m.room);
            }
            p->rotation_y = m.angle;
            if (m.is_near_enemy != 1) {
                p->clear_actor_flags((u32)0x100000);
            } else {
                p->set_actor_flags(0x100000);
            }
            p->run_action_state_phase(1, 0);
        }
    }
}

void handle_6x3E_stop_at_position(G_StopAtPosition_6x3E *command) {
    G_StopAtPosition_6x3E m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x3E_stop_at_position(&m) == 0) {
        return;
    }
    p = get_player_by_client_id(m.header.client_id);
    if (p == NULL) {
        return;
    }
    p->set_position_from(&m.pos);
    if (m.floor >= 0) {
        p->set_floor(m.floor);
        p->set_floor_index(get_floor_area(m.floor));
    }
    p->rotation_y = m.angle;
    if (p->is_in_tl03_state() == 0 || p->test_action_mask(0x8100) != 0 ||
        (p->test_action_mask(0x200) != 0 && p->phase <= 2) ||
        (p->test_action_mask(0x4000) != 0 && p->phase == 0)) {
        return;
    }
    if (m.room >= 0) {
        p->set_room(m.room);
    }
    switch (m.is_near_enemy) {
    case 0:
        p->clear_actor_flags((u32)0x100000);
        break;
    case 1:
        p->set_actor_flags(0x100000);
        break;
    }
    p->run_action_state_phase(1, 0);
}
extern "C" {

void TObjPlayer::update_position_from_target() { send_6x3F_set_position(&position, rotation_y); }

void TObjPlayer::send_6x3F_set_position(const Vec *pos, s32 angle) {
    G_SetPosition_6x3F m;
    s32 near_enemy;
    if ((this == NULL) || (obj_isState2_324() == 0)) {
        near_enemy = test_actor_flags(0x100000) != 0 ? 1 : 0;
        m.init();
        m.header.client_id = get_entity_id();
        m.is_near_enemy = near_enemy;
        m.angle = angle;
        m.floor = get_floor();
        m.room = get_room();
        VecCopy((Vec *)&m.pos, pos);
        m.send();
    }
}

void TObjPlayer::send_6x3E_stop_at_position() {
    G_StopAtPosition_6x3E m;
    s32 near_enemy;
    if ((this == NULL) || (obj_isState2_324() == 0)) {
        near_enemy = test_actor_flags(0x100000) != 0 ? 1 : 0;
        m.init();
        m.header.client_id = get_entity_id();
        m.is_near_enemy = near_enemy;
        m.angle = rotation_y;
        sync_current_floor();
        sync_current_area();
        m.floor = get_floor();
        m.room = get_room();
        VecCopy((Vec *)&m.pos, &position);
        m.send();
    }
}

void TObjPlayer::idle_phase8_nop() {  }

void TObjPlayer::complete_idle_state() {  }

void TObjPlayer::check_idle_movement_request() {
    f32 magnitude;
    s32 stick_angle;
    magnitude = pad_binding.get_stick_magnitude();
    stick_angle = pad_binding.get_stick_angle();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        this->lobby_animation = this->select_idle_action();
        if (is_action_id_none(this->lobby_animation) == 0) {
            if (this->lobby_animation == action_provider->get_chair_sit_action() ||
                this->lobby_animation == action_provider->get_alt_chair_sit_action()) {
                run_action_state_phase(0x18, 5);
            } else {
                run_action_state_phase(0x17, 5);
            }
            return;
        }
        if (magnitude >= 0.1f) {
            this->target_heading = calc_scaled_value(stick_angle);
            run_action_state_phase(2, 5);
        }
    }
}

int TObjPlayer::try_apply_status_action_2() { return try_status_action(); }

void TObjPlayer::run_idle_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_2();
        return;
      case 2:
        check_idle_movement_request();
        return;
      case 3:
        TObjPlayer::complete_idle_state();
        return;
      case 8:
        idle_phase8_nop();
        return;
      case 5:
        send_6x3E_stop_at_position();
        return;
      case 0:
        start_animation();
        return;
      case 1:
        TObjPlayer::update_action((saddr)this);
        return;
      case 6:
        TObjPlayer::exit_idle_state();
        break;
    }
  }
}

void TObjPlayer::run_action_state_phase(s16 state, s16 phase) {
    switch (state) {
    case 1:
        run_idle_state_phase(phase);
        break;
    case 2:
        run_walk_state_phase(phase);
        break;
    case 3:
        run_action3_phase(phase);
        break;
    case 4:
        dispatch_run_state(phase);
        break;
    case 5:
        run_attack_stage1_phase(phase);
        break;
    case 6:
        run_attack_stage2_phase(phase);
        break;
    case 7:
        run_attack_stage3_phase(phase);
        break;
    case 8:
        dispatch_technique_cast_state(phase);
        break;
    case 9:
        dispatch_photon_blast_action(phase);
        break;
    case 10:
        run_guard_reaction_phase(phase);
        break;
    case 11:
        run_action11_phase(phase);
        break;
    case 12:
        run_switch_interaction_phase(phase);
        break;
    case 13:
        run_hurt_state_phase(phase);
        break;
    case 14:
        run_fall_reaction_phase(phase);
        break;
    case 15:
        run_death_state_phase(phase);
        break;
    case 18:
        run_revival_state_phase(phase);
        break;
    case 16:
        run_service_hold_state_phase(phase);
        break;
    case 19:
        run_freeze_state_phase(phase);
        break;
    case 20:
        run_warp_action_phase(phase);
        break;
    case 21:
        sub_801C8C50(phase);
        break;
    case 22:
        run_off_floor_state_phase(phase);
        break;
    case 23:
        run_lobby_animation_state_phase(phase);
        break;
    case 24:
        run_lobby_chair_state_phase(phase);
        break;
    }
}

void TObjPlayer::update_lobby_chair(s32 value) { chair_seat.set_move_angle(value); }

void TObjPlayer::get_chair_state(s32 value) { chair_seat.set_target_angle(value); }

void TObjPlayer::leave_chair_seat() { this->chair_seat.update(); }

void TObjPlayer::clear_chair_seated() { this->state_flags &= 0xfbffffff; }

void TObjPlayer::clear_anim_flag() { this->state_flags &= 0xf7ffffff; }

void TObjPlayer::clear_state_flag() { this->state_flags &= 0xefffffff; }

s32 TObjPlayer::get_chair_target_angle() { return chair_seat.get_target_angle(); }

short TObjPlayer::start_action18_sub() { return chair_seat.get_animation(); }

int TObjPlayer::create_photon_chair() { return this->chair_seat.create_chair(); }

void TObjPlayer::set_chair_seated() { this->state_flags |= 0x4000000; }

int TObjPlayer::get_action_flag() { return (this->state_flags >> 27) & 0x1; }

void TObjPlayer::set_chair_seat_animation(s16 value) { chair_seat.set_animation(value); }

int TObjPlayer::is_action_flag_28() { return (this->state_flags >> 28) & 0x1; }

void TObjPlayer::set_anim_flag() { this->state_flags |= 0x8000000; }

void TObjPlayer::set_action_flag_28() { this->state_flags |= 0x10000000; }

void TObjPlayer::clear_lobby_pose_hold() { this->state_flags &= 0xdfffffff; }

int TObjPlayer::get_flag() { return (this->state_flags >> 29) & 0x1; }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_IntraMapWarp_6x55 &G_IntraMapWarp_6x55::operator=(G_IntraMapWarp_6x55 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    __memcpy(&from_pos, &src.from_pos, sizeof(Vec));
    __memcpy(&pos, &src.pos, sizeof(Vec));
    return *this;
}
#pragma pop

short TObjPlayer::query_child_state2() {
    return action_provider->get_stand_up_action();
}

}

void release_control_lock(TObjPlayer *player) { player->clear_flag_200(); }

extern "C" {

void TObjPlayer::clear_flag_200() { this->state_flags &= 0xfffffdff; }

void TObjPlayer::set_flag_200() { this->state_flags |= 0x200; }

Vec *PhotonBlastAim::get_position() { return &position; }

Vec *PhotonBlastAim::set_position(const Vec *src) { return VecCopy(&position, src); }

void TObjPlayer::set_float_param(s16 value) {
    this->photon_blast_gauge.set_field_3c((f32) (s32) value);
}

void update_player_action_palette(TObjPlayer *player, u8 slot) {
    player->action_palette_state.set_slot(slot);
}
}

int is_android_player(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }


void PhotonChairSeat::set_move_angle(s32 v) { move_angle = v; }

void PhotonChairSeat::set_target_angle(s32 angle) { target_angle = angle; }

s32 PhotonChairSeat::get_target_angle() { return target_angle; }

s16 PhotonChairSeat::get_animation() { return animation; }

void PhotonChairSeat::set_animation(s16 v) { animation = v; }

void PhotonChairSeat::start_delay_6xAF() { delay_6xAF = 8; }

void PhotonChairSeat::tick_delay_6xAF() {
    if (--delay_6xAF < 0) {
        delay_6xAF = 0;
    }
}

s32 PhotonChairSeat::is_delay_6xAF_over() { return delay_6xAF <= 0; }

void PhotonChairSeat::start_delay_6xB0() { delay_6xB0 = 8; }

void PhotonChairSeat::tick_delay_6xB0() {
    if (--delay_6xB0 < 0) {
        delay_6xB0 = 0;
    }
}

s32 PhotonChairSeat::is_delay_6xB0_over() { return delay_6xB0 <= 0; }

void G_MoveLobbyChair_6xB0::bswap() {
    header.bswap();
    bswap_32(&angle);
}

G_MoveLobbyChair_6xB0 &G_MoveLobbyChair_6xB0::operator=(const G_TurnOrMoveLobbyChair_6xAF_6xB0 &src) {
    copy_subcommand_header(this, &src);
    angle = src.angle;
    return *this;
}

void G_MoveLobbyChair_6xB0::init() {
    angle = 0;
    header.subcommand = 0xB0;
    header.size = 2;
}

void G_TurnLobbyChair_6xAF::bswap() {
    header.bswap();
    bswap_32(&angle);
}

G_TurnLobbyChair_6xAF &G_TurnLobbyChair_6xAF::operator=(const G_TurnOrMoveLobbyChair_6xAF_6xB0 &src) {
    copy_subcommand_header(this, &src);
    angle = src.angle;
    return *this;
}

void G_TurnLobbyChair_6xAF::init() {
    angle = 0;
    header.subcommand = 0xAF;
    header.size = 2;
}

s32 G_CreateLobbyChair_6xAB::has_keyboard() { return flags & 1; }

s32 G_CreateLobbyChair_6xAB::uses_alt_chair() { return (flags >> 1) & 1; }

void G_CreateLobbyChair_6xAB::bswap() {
    header.bswap();
    bswap_16((u16 *)&animation_number);
    bswap_16(&flags);
}

G_CreateLobbyChair_6xAB &G_CreateLobbyChair_6xAB::operator=(G_CreateLobbyChair_6xAB &src) {
    copy_subcommand_header(this, &src);
    animation_number = src.animation_number;
    flags = src.flags;
    return *this;
}

void G_CreateLobbyChair_6xAB::init() {
    animation_number = 0;
    flags = 0;
    header.subcommand = 0xAB;
    header.size = 2;
}

void G_CreateLobbyChair_6xAB::send() {
    bswap();
    send_subcommand(this);
}

void G_CreateLobbyChair_6xAB::set_keyboard() { flags |= 1; }

void G_CreateLobbyChair_6xAB::set_alt_chair() { flags |= 2; }

void G_TurnLobbyChair_6xAF::send() {
    bswap();
    send_subcommand(this);
}

void G_MoveLobbyChair_6xB0::send() {
    bswap();
    send_subcommand(this);
}

s32 G_LobbyAnimation_6x58::has_keyboard() { return flags & 1; }

void G_LobbyAnimation_6x58::bswap() {
    header.bswap();
    bswap_16((u16 *)&animation_number);
    bswap_16(&flags);
}

G_LobbyAnimation_6x58 &G_LobbyAnimation_6x58::operator=(G_LobbyAnimation_6x58 &src) {
    copy_subcommand_header(this, &src);
    animation_number = src.animation_number;
    flags = src.flags;
    return *this;
}

void G_LobbyAnimation_6x58::init() {
    animation_number = 0;
    flags = 0;
    header.subcommand = 0x58;
    header.size = 2;
}

void G_LobbyAnimation_6x58::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_LobbyAnimation_6x58::set_keyboard() { flags |= 1; }

G_Unknown_6x57 &G_Unknown_6x57::operator=(const G_Unknown_6x57 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void G_Unknown_6x57::init() {
    header.subcommand = 0x57;
    header.size = 1;
}

void G_Unknown_6x57::send() {
    bswap_g_client_id_header(&header);
    send_subcommand(this);
}

void G_SetPlayerPositionAndAngle_6x56::bswap() {
    header.bswap();
    bswap_32(&angle_y);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_SetPlayerPositionAndAngle_6x56 &G_SetPlayerPositionAndAngle_6x56::operator=(G_SetPlayerPositionAndAngle_6x56 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    *(ByteBlock_C *)&pos = *(ByteBlock_C *)&src.pos;
    return *this;
}
extern int fold_flush_9;
#pragma pop

void G_SetPlayerPositionAndAngle_6x56::init() {
    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x56;
    header.size = 5;
}

void G_SetPlayerPositionAndAngle_6x56::send() {
    bswap();
    send_subcommand(this);
}

void G_IntraMapWarp_6x55::send() { bswap(); send_subcommand(this); }

void G_IntraMapWarp_6x55::bswap() {
    header.bswap();
    bswap_32((u32 *)&angle_y);
    bswap_32((u32 *)&from_pos.x);
    bswap_32((u32 *)&from_pos.y);
    bswap_32((u32 *)&from_pos.z);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}

void G_IntraMapWarp_6x55::init() {
    angle_y = 0;
    from_pos.z = 0.0f;
    from_pos.y = 0.0f;
    from_pos.x = 0.0f;
    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x55;
    header.size = 8;
}

void G_Unknown_6x53::init() {
    header.subcommand = 0x53;
    header.size = 1;
}

void G_Unknown_6x53::send() {
    bswap_g_client_id_header(&header);
    send_subcommand(this);
}

void G_SetAnimationState_6x52::bswap() {
    header.bswap();
    bswap_16((u16 *)&animation);
    bswap_16((u16 *)&state);
    bswap_32((u32 *)&angle);
}

G_SetAnimationState_6x52 &G_SetAnimationState_6x52::operator=(G_SetAnimationState_6x52 &src) {
    copy_subcommand_header(this, &src);
    animation = src.animation;
    state = src.state;
    angle = src.angle;
    return *this;
}

void G_SetAnimationState_6x52::init() {
    animation = 0;
    state = 0;
    angle = 0;
    header.subcommand = 0x52;
    header.size = 3;
}

void G_SetAnimationState_6x52::send() {
    bswap();
    send_subcommand(this);
}

void G_PlayerRevived_6x4F::init() {
    header.subcommand = 0x4F;
    header.size = 1;
}

void G_PlayerRevived_6x4F::send() {
    bswap_g_client_id_header(&header);
    send_subcommand(this);
}

void G_SetKillerEntityID_6x89::bswap() {
    header.bswap();
    bswap_16(&killer_entity_id);
    bswap_16((u16 *)&unused);
}

G_SetKillerEntityID_6x89 &G_SetKillerEntityID_6x89::operator=(G_SetKillerEntityID_6x89 &src) {
    copy_subcommand_header(this, &src);
    killer_entity_id = src.killer_entity_id;
    unused = src.unused;
    return *this;
}

void G_SetKillerEntityID_6x89::init() {
    killer_entity_id = 0xFFFF;
    unused = 0;
    header.subcommand = 0x89;
    header.size = 2;
}

void G_PlayerRevivable_6x4E::init() {
    header.subcommand = 0x4E;
    header.size = 1;
}

void G_PlayerRevivable_6x4E::send() {
    bswap_g_client_id_header(&header);
    send_subcommand(this);
}

void G_PlayerDied_6x4D::bswap() {
    header.bswap();
    death_flags.bswap();
}

G_PlayerDied_6x4D::G_PlayerDied_6x4D() {
    death_flags.reset();
    header.subcommand = 0x4D;
    header.size = 2;
}

void G_PlayerDied_6x4D::send() {
    bswap();
    send_subcommand(this);
}

void G_SetKillerEntityID_6x89::send() {
    bswap();
    send_subcommand(this);
}

void G_HitByEnemy_6x4C::bswap() {
    header.bswap();
    bswap_16((u16 *)&angle);
    bswap_16((u16 *)&current_hp);
    velocity.bswap();
}

void G_HitByEnemy_6x4C::init() {
    current_hp = 0;
    angle = 0;
    velocity.xz[1] = 0.0f;
    velocity.xz[0] = 0.0f;
    header.subcommand = 0x4C;
    header.size = 4;
}

void G_HitByEnemy_6x4C::send() {
    bswap();
    send_subcommand(this);
}

void G_HitByEnemy_6x4B::bswap() {
    header.bswap();
    bswap_16((u16 *)&angle);
    bswap_16((u16 *)&current_hp);
    velocity.bswap();
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_HitByEnemy_6x4B &G_HitByEnemy_6x4B::operator=(G_HitByEnemy_6x4B &src) {
    copy_subcommand_header(this, &src);
    angle = src.angle;
    current_hp = src.current_hp;
    velocity = src.velocity;
    return *this;
}
extern int fold_flush_10;
#pragma pop

void G_HitByEnemy_6x4B::init() {
    current_hp = 0;
    angle = 0;
    velocity.xz[1] = 0.0f;
    velocity.xz[0] = 0.0f;
    header.subcommand = 0x4B;
    header.size = 4;
}

void G_HitByEnemy_6x4B::send() {
    bswap();
    send_subcommand(this);
}

void G_SetPlayerAngle_6x51::bswap() {
    header.bswap();
    bswap_32(&angle_y);
}

void G_SetPlayerAngle_6x51::init() {
    angle_y = 0;
    header.subcommand = 0x51;
    header.size = 2;
}

void G_SetPlayerAngle_6x51::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_SwitchInteraction_6x50::bswap() {
    header.bswap();
    bswap_32(&angle_y);
}

G_SwitchInteraction_6x50 &G_SwitchInteraction_6x50::operator=(const G_SwitchInteraction_6x50 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    return *this;
}

void G_SwitchInteraction_6x50::init() {
    angle_y = 0;
    header.subcommand = 0x50;
    header.size = 2;
}

void G_SwitchInteraction_6x50::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_ShieldAttack_6x4A::init() {
    header.subcommand = 0x4A;
    header.size = 1;
}

void G_ShieldAttack_6x4A::send() {
    bswap_g_client_id_header(&header);
    send_subcommand(this);
}

void G_PhotonBlast_6x37::bswap() {
    header.bswap();
    bswap_16((u16 *)&amount);
    bswap_16((u16 *)&unused);
}

G_PhotonBlast_6x37 &G_PhotonBlast_6x37::operator=(G_PhotonBlast_6x37 &src) {
    copy_subcommand_header(this, &src);
    amount = src.amount;
    unused = src.unused;
    return *this;
}

void G_PhotonBlast_6x37::init() {
    amount = 0;
    unused = 0;
    header.subcommand = 0x37;
    header.size = 2;
}

void G_PhotonBlast_6x37::send() {
    bswap();
    send_subcommand(this);
}

void G_ExecutePhotonBlast_6x49::bswap_received() {
    s32 i;
    header.bswap();
    params.bswap();
    for (i = 0; i < params.target_count; i++) {
        targets[i].bswap();
    }
}

void G_ExecutePhotonBlastParams_6x49::bswap() {
    bswap_16((u16 *)&target_count);
    bswap_16((u16 *)&pb_meter_value);
    bswap_16((u16 *)&unused2);
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_ExecutePhotonBlast_6x49 &G_ExecutePhotonBlast_6x49::operator=(G_ExecutePhotonBlast_6x49 &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&params, &src.params, sizeof(params));
    __memcpy(targets, src.targets, sizeof(targets));
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_ExecutePhotonBlast_6x49::G_ExecutePhotonBlast_6x49() {
    header.subcommand = 0x49;
    header.size = sizeof(G_ExecutePhotonBlast_6x49) / 4;
}
#pragma pop

G_ExecutePhotonBlastParams_6x49::G_ExecutePhotonBlastParams_6x49() {
    unused2 = 0;
    pb_meter_value = 0;
    target_count = 0;
    unused1 = 0;
    photon_blast = 0;
}

void G_ExecutePhotonBlast_6x49::send() {
    header.size = (get_size() >> 2) & 0x3F;
    bswap_for_send();
    send_subcommand(this);
}

void G_ExecutePhotonBlast_6x49::bswap_for_send() {
    s32 i;
    header.bswap();
    for (i = 0; i < params.target_count; i++) {
        targets[i].bswap();
    }
    params.bswap();
}

u8 G_ExecutePhotonBlast_6x49::get_size() {
    return sizeof(G_ExecutePhotonBlast_6x49) - (10 - params.target_count) * sizeof(PhotonBlastTarget);
}

void G_RevivePlayer_6x33::bswap() {
    header.bswap();
    bswap_16(&client_id2);
    bswap_16((u16 *)&unused);
}

G_RevivePlayer_6x33 &G_RevivePlayer_6x33::operator=(G_RevivePlayer_6x33 &src) {
    copy_subcommand_header(this, &src);
    client_id2 = src.client_id2;
    unused = src.unused;
    return *this;
}

void G_RevivePlayer_6x33::init() {
    client_id2 = 0xFFFF;
    unused = 0;
    header.subcommand = 0x33;
    header.size = 2;
}

void G_RevivePlayer_6x33::send() {
    bswap();
    send_subcommand(this);
}

void G_CastTechniqueComplete_6x48::bswap() {
    header.bswap();
    bswap_16((u16 *)&technique_number);
    bswap_16((u16 *)&level);
}

G_CastTechniqueComplete_6x48 &G_CastTechniqueComplete_6x48::operator=(G_CastTechniqueComplete_6x48 &src) {
    copy_subcommand_header(this, &src);
    technique_number = src.technique_number;
    level = src.level;
    return *this;
}

void G_CastTechniqueComplete_6x48::init() {
    level = 0;
    technique_number = 0;
    header.subcommand = 0x48;
    header.size = 2;
}

void G_CastTechniqueComplete_6x48::send() {
    bswap();
    send_subcommand(this);
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_CastTechnique_6x47 &G_CastTechnique_6x47::operator=(const G_CastTechnique_6x47 &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&params, &src.params, sizeof(params));
    __memcpy(targets, src.targets, sizeof(targets));
    return *this;
}
#pragma pop

void G_SetTechniqueLevelOverride_6x8D::bswap() {
    header.bswap();
    bswap_16((u16 *)&unused2);
}

G_SetTechniqueLevelOverride_6x8D &G_SetTechniqueLevelOverride_6x8D::operator=(G_SetTechniqueLevelOverride_6x8D &src) {
    copy_subcommand_header(this, &src);
    level_upgrade = src.level_upgrade;
    unused1 = src.unused1;
    unused2 = src.unused2;
    return *this;
}

void G_SetTechniqueLevelOverride_6x8D::init() {
    unused2 = 0;
    unused1 = 0;
    level_upgrade = 0;
    header.subcommand = 0x8D;
    header.size = 2;
}

void G_SetTechniqueLevelOverride_6x8D::send() {
    bswap();
    send_subcommand(this);
}

G_Attack_6x45 &G_Attack_6x45::operator=(G_Attack_6x45 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    action_type = src.action_type;
    return *this;
}

G_Attack_6x44 &G_Attack_6x44::operator=(G_Attack_6x44 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    action_type = src.action_type;
    return *this;
}

void G_AttackFinished_6x46::bswap_received() {
    header.bswap();
    targets.bswap_received();
}

G_AttackFinished_6x46::G_AttackFinished_6x46() {
    TObjPlayer__sub_8012AF00(&targets);
    header.subcommand = 0x46;
    header.size = sizeof(G_AttackFinished_6x46) / 4;
}

void G_AttackFinished_6x46::send() {
    header.size = (get_size() >> 2) & 0x3F;
    bswap_for_send();
    send_subcommand(this);
}

void G_AttackFinished_6x46::bswap_for_send() {
    header.bswap();
    targets.bswap_for_send();
}

#pragma push
#pragma dont_inline off
u8 G_AttackFinished_6x46::get_size() {
    return sizeof(G_AttackFinished_6x46) - (10 - targets.get_captured_target_count()) * sizeof(CapturedTarget);
}
#pragma pop

#pragma push
#pragma dont_inline off

G_Attack_6x43 &G_Attack_6x43::operator=(G_Attack_6x43 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    action_type = src.action_type;
    return *this;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
G_WalkToPosition_6x40 &G_WalkToPosition_6x40::operator=(G_WalkToPosition_6x40 &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&pos, &src.pos, sizeof(pos));
    flags = src.flags;
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_SetPosition_6x3F &G_SetPosition_6x3F::operator=(G_SetPosition_6x3F &src) {
    copy_subcommand_header(this, &src);
    is_near_enemy = src.is_near_enemy;
    angle = src.angle;
    floor = src.floor;
    room = src.room;
    __memcpy(&pos, &src.pos, sizeof(Vec));
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_StopAtPosition_6x3E &G_StopAtPosition_6x3E::operator=(G_StopAtPosition_6x3E &src) {
    copy_subcommand_header(this, &src);
    is_near_enemy = src.is_near_enemy;
    angle = src.angle;
    floor = src.floor;
    room = src.room;
    __memcpy(&pos, &src.pos, sizeof(Vec));
    return *this;
}
#pragma pop

void TObjMotion::set_frame(f32 frame) { this->frame = frame; }

void TObjMotion::pause_motion() { this->motion_flags |= MOTION_PAUSED; }

void TObjMotion::resume_motion() { this->motion_flags &= ~MOTION_PAUSED; }

f32 TObjPlayer::get_action_rate_entry() {
    return action_table[requested_action].speed;
}

void TObjPlayer::set_field_d4_and_flag_200(f32 value) {
    this->override_blend_speed = value;
    set_motion_flags(MOTION_OVERRIDE_BLEND_SPEED);
}

int TObjPlayer::is_motion_paused() {
    return (this->motion_flags >> 6) & 1;
}

void TObjPlayer::set_action_flag() {
    this->motion_flags |= 0x80;
}

int PlayerActionProvider::get_alt_chair_sit_action() { return -1; }

int PlayerActionProvider::get_chair_sit_action() { return -1; }

int get_no_action() { return -1; }

int PlayerActionProvider::get_key_4_action() { return -1; }

int PlayerActionProvider::get_key_3_action() { return -1; }

int PlayerActionProvider::get_key_2_action() { return -1; }

int PlayerActionProvider::get_key_1_action() { return -1; }

int PlayerActionProvider::get_key_l_action() { return -1; }

int PlayerActionProvider::get_key_v_action() { return -1; }

int PlayerActionProvider::get_key_x_action() { return -1; }

int PlayerActionProvider::get_key_z_action() { return -1; }

int PlayerActionProvider::get_key_e_action() { return -1; }

int PlayerActionProvider::get_key_a_action() { return -1; }

int PlayerActionProvider::get_key_p_action() { return -1; }

int PlayerActionProvider::get_key_y_action() { return -1; }

int PlayerActionProvider::get_key_g_action() { return -1; }

int PlayerActionProvider::get_key_f_action() { return -1; }

int PlayerActionProvider::get_key_d_action() { return -1; }

int PlayerActionProvider::get_key_c_action() { return -1; }

int PlayerActionProvider::get_key_t_action() { return -1; }

int PlayerActionProvider::get_key_s_action() { return -1; }

int PlayerActionProvider::get_key_w_action() { return -1; }

int PlayerActionProvider::get_key_k_action() { return -1; }

int PlayerActionProvider::get_key_r_action() { return -1; }

int PlayerActionProvider::get_key_j_action() { return -1; }

int PlayerActionProvider::get_key_q_action() { return -1; }

int PlayerActionProvider::get_key_n_action() { return -1; }

int PlayerActionProvider::get_key_o_action() { return -1; }

int PlayerActionProvider::get_key_b_action() { return -1; }

int PlayerActionProvider::get_key_h_action() { return -1; }

int PlayerActionProvider::get_key_0_action() { return -1; }

int PlayerActionProvider::get_key_9_action() { return -1; }

int PlayerActionProvider::get_key_8_action() { return -1; }

int PlayerActionProvider::get_key_7_action() { return -1; }

int PlayerActionProvider::get_key_6_action() { return -1; }

int PlayerActionProvider::get_lock_on_idle_action() { return -1; }

int PlayerActionProvider::get_key_f12_action() { return -1; }

int PlayerActionProvider::get_key_f11_action() { return -1; }

int PlayerActionProvider::get_key_f10_action() { return -1; }

int PlayerActionProvider::get_key_f9_action() { return -1; }

int PlayerActionProvider::get_key_f8_action() { return -1; }

int PlayerActionProvider::get_key_f7_action() { return -1; }

int PlayerActionProvider::get_key_f6_action() { return -1; }

int PlayerActionProvider::get_key_f5_action() { return -1; }

int PlayerActionProvider::get_stand_up_action() { return -1; }

int PlayerActionProvider::get_walk_action() { return -1; }

int PlayerActionProvider::get_slow_walk_action() { return -1; }

int PlayerActionProvider::get_idle_action() { return -1; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PlayerAnimationState::get_angle() { return angle; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 PlayerAnimationState::get_animation() { return animation; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 PlayerAnimationState::get_state() { return state; }
#pragma pop

#pragma push
#pragma opt_common_subs off
void PlayerDeathSink::add_progress(f32 step) {
    progress += step;
    if (progress > 1.0f) {
        progress = 1.0f;
    }
}
#pragma pop


f32 PlayerMoveSpeed::get_unscaled_speed() { return unscaled_speed; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PlayerMoveSpeed::increment_run_counter() { run_counter++; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PlayerMoveSpeed::get_run_counter() { return run_counter; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
ControllerInputContext *PlayerPadBinding::get_controller() { return controller; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void FlagWord::bswap() { bswap_32((u32 *)&bits); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
G_PlayerDied_6x4D &G_PlayerDied_6x4D::operator=(G_PlayerDied_6x4D &src) {
    copy_subcommand_header(this, &src);
    death_flags.bits = src.death_flags.bits;
    return *this;
}
#pragma pop

#pragma push
#pragma dont_inline off
void PacketVelocityXZ::bswap() { bswap_32((u32 *)&xz[0]); bswap_32((u32 *)&xz[1]); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_HitByEnemy_6x4C &G_HitByEnemy_6x4C::operator=(G_HitByEnemy_6x4C &src) {
    copy_subcommand_header(this, &src);
    angle = src.angle;
    current_hp = src.current_hp;
    velocity = src.velocity;
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_MoveToPosition_6x41_6x42 &G_MoveToPosition_6x41_6x42::operator=(const G_MoveToPosition_6x41_6x42 &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&pos, &src.pos, sizeof(pos));
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma auto_inline off
void PhotonBlastGauge::clear_photon_blast_state() { ((FlagWord *)&flags)->clear(62); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::trigger_photon_blast() { ((FlagWord *)&flags)->clear(4); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::check_photon_blast_flag() { ((FlagWord *)&flags)->set(8); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int PhotonBlastGauge::check_flag_clear() { return test_flags_any(&flags.bits, 1) == 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int PhotonBlastGauge::is_blast_launched() { return test_flags_any(&flags.bits, 8); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_complete_threshold(f32 threshold) { complete_threshold = threshold; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PhotonBlastGauge::get_countdown() { return countdown; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::decrement_countdown() {
    countdown--;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PhotonBlastGauge::get_frame_step() { return frame_step; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field_0c(f32 v) { frame_step = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field8(s32 v) { countdown = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
PhotonBlastTarget *PhotonBlastGauge::get_target(s32 i) {
    return &targets[i];
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field_3c(f32 v) { charge = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::start_photon_blast_action() { ((FlagWord *)&flags)->set(4); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PhotonBlastGauge::get_dist() { return complete_threshold; }
#pragma pop

PhotonBlastRequest *PhotonBlastRegistry::get_element(s32 index) { return &slots[index]; }

int TPlyDispConfig::is_secondary_bank_empty(s32 bank) { return m_smth1.is_bank_empty(bank); }

void CapturedTargetList::bswap_received() {
    s32 i;
    bswap_32((u32 *)&count);
    for (i = 0; i < count; i++) {
        entries[i].bswap();
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void CapturedTarget::bswap() {
    bswap_16(&uid);
    bswap_16((u16 *)&collider_index);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma fp_contract on
G_AttackFinished_6x46 &G_AttackFinished_6x46::operator=(G_AttackFinished_6x46 &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&targets, &src.targets, sizeof(targets));
    return *this;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
void CapturedTargetList::bswap_for_send() {
    s32 i;
    for (i = 0; i < count; i++) {
        entries[i].bswap();
    }
    bswap_32((u32 *)&count);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
void PlayerTechniqueState::set_technique_state(s32 v) { state = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma auto_inline off
void PlayerTechniqueState::set_level(u8 v) { level = v; }
#pragma pop

s32 PlayerTechniqueState::test_flag_2() { return test_flags_any(&flags.bits, 2); }

void PlayerTechniqueState::decrement_state() { state--; }

f32 PlayerTechniqueState::get_charge_step() { return charge_step; }

void PlayerTechniqueState::set_charge_step(f32 step) { charge_step = step; }

PhotonBlastTarget *PlayerTechniqueState::get_technique_data() { return targets; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PlayerTechniqueState::set_tech_override(u8 v) { level_override = v; }
#pragma pop

f32 PlayerAttackController::get_attack_speed() { return attack_speed; }


void PlayerAttackController::set_queued_kind(s16 kind) { queued_kind = kind; }

FlagWord *PlayerAttackController::get_flags() { return (FlagWord *)&flags; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PlayerAttackController::calc_attack_stage_multiplier(s32 kind) {
    return attack_type_accuracy_scales[kind] * attack_combo_accuracy_multipliers[get_validated_attack_stage()];
}

void PlayerAttackController::set_lockon_targets(void *src) { copy_attack_targets(&lockon_targets, src); }

void PlayerAttackController::end_swing() { ((FlagWord *)&flags)->set(1); }

void PlayerAttackController::increment_hit_count() { hit_count++; }

void PlayerAttackController::set_recovery_timer(s32 frames) { recovery_timer = frames; }

s32 PlayerAttackController::get_recovery_timer() { return recovery_timer; }

void TObjPlayer::request_heavy_attack_particles() {
    u16 *arg0 = (u16 *)this;
    emit_heavy_attack_particles((saddr)((s8 *)arg0 + 4), *arg0);
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void emit_heavy_attack_particles(saddr owner, u16 target_id) {
    TObjPlayer::check_hit_by_id(owner, target_id, 0xBB);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x1B7);
}

f32 attack_damage_scale_table[3] = { 0.9f, 1.7f, 0.5f };
f32 attack_type_accuracy_scales[3] = { 1.0f, 0.7f, 0.5f };
f32 attack_combo_accuracy_multipliers[4] = { 1.0f, 1.3f, 1.69f, 0.0f };
