#include "pso/system/save/CardFileInfo.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/ui/city/TMedicalCenterMes.h"
#include "pso/object/TObjRoomId.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/PlayerCharDataEntry.h"
#include "pso/player/InventoryItemList.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/player/PlayerHoldPacket.h"
#include "pso/system/SoundEffect.h"
// Built with -inline off,deferred (configure.py): CodeWarrior emits deferred functions
// last to first, so they are defined here from the highest address down.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/object/TActorLight.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/TPlyOnCountOver.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/ChunkMaterialState.h"

#include "pso/render/ChunkModelDraw.h"
#include "pso/player/PlayerTaskEffects.h"
#include "types.h"
#include <stdlib.h>
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/render/reflection.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffGuard.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/system/scene/TScene.h"
#include "pso/player/TObjContainerCommon.h"
#include "pso/object/base/TObjChara.h"

#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TMainTask.h"
#include <stddef.h>
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/TPlyDispData.h"
#include "pso/item/TItemData.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/item/TItem.h"
#include "pso/system/TDeathTintFade.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/network/TLobby.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/item/TItemList.h"
#include "pso/player/TPlyItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TForceOperate.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerClassTechniques.h"
#include "pso/network/client_id.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/render/BlobShadow.h"
#include "pso/object/base/CollisionActorLookup.h"

#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/model_render_state.h"
#include "pso/map/area/AreaScene.h"
#include "pso/math/ScratchVectors.h"
#include "pso/system/MainPhaseState.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/player/TPlyCharData.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/CameraCapture.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/render/DebugFont.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/ui/window/TWindowDuelResult_801C2528.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/player/PlayerSubcommandHandlers.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/player/Palettex.h"
#include "pso/player/TPlayerLobbyMarker.h"

#pragma readonly_strings on











extern "C" {
void copy_player_visual_record(void *, void *);
s32 TMainCursor__sub_80154098(int, int, int);
s32 TMainCursor__sub_801540B8(int, int, int);
saddr TObjPlayer__sub_80116620(void *, int);
bool is_trap_stock_empty(TObjPlayer *player, s32 kind);
s32 get_class_index__10TObjPlayerFv(TObjPlayer *player);
void emit_idle_water_effect(PlayerFollowParticles *particles);
s8 clamp_class_index(s8 cls);
}
extern "C" {
void record_damage_stats(uaddr mine_trap, u32 att, s16 damage);
void draw_player_status(saddr window, void *player, saddr str);
void show_sub_status_window(void *window, s32 *str, s32 *name);
void draw_status_line(void *window, s32 *str, s32 *name, s32 value);

}
extern "C" {
void set_selected_palette_tag_slot(TObjPlayer *player, s32 secondary, s32 i, s32 action, s32 param);
void get_action_palette_mode(TObjPlayer *player, s32 index);
void calc_move_velocity(const Vec *direction, Vec *out, f32 speed);
}
extern "C" {
s32 fn_801B7CEC(TObjPlayer *player, s8 kind, s8 group, s8 index);
void send_6x28_feed_mag(TObjChara *chara, s32 mag_id, s32 fed_item_id);
s32 try_send_6x27_use_item(TObjPlayer *player, s32 key);
void release_players_from_cutscene(void);
void TObjPlayer__sub_801BBB70(TObjPlayer *player, PlayerSyncRecord *record);
InventoryItemList *__ct__17InventoryItemListFv(void *list);
void *__ct__12StatusEffectFv(void *);


s32 accumulate_damage_stats(DamageStatSlot *slot, TObject *attacker, s32 amount);
s32 get_class_max_exp(void *, void *);
s32 validate_6xAE_set_animation_state(void *);
s32 fn_8000F740(void *);
void *__construct_array(void *, void *, void *, u32, u32);
}

extern const f32 player_front_distance;
extern Vec scratch_vec5;
extern s32 lbl_805D55C0;
extern PlayerCharDataEntry *lobby_char_slot_array;
extern const char status_line_break[];
extern f32 player_angle_per_degree;
extern f32 player_degrees_per_turn;
extern f32 player_rand_unit;
extern const f32 player_stick_deadzone;
extern const f32 player_velocity_epsilon;
extern const f32 player_velocity_neg_epsilon;
extern const f32 player_body_radius;
extern const f32 player_wall_probe_margin;
extern const f32 player_wall_facing_limit;
extern const f32 player_lock_range_sq;
extern const f32 player_lock_release_range_sq;
extern const f32 player_shadow_lift;
extern const f32 player_view_detail_near;
extern const f32 player_view_detail_far;
extern const f32 player_shadow_range;
const char *TObjPlayer_name = "TObjPlayer";


s16 item_equip_attach_equip_flag_table[10] = {0x3E, 0x3F, 0x18, 0x24, 0x32, 0x23, 0x30, 0x0A, 0x13, 0x00};


// The level-up light colour and direction (spawn_level_change_feedback).
extern const f32 player_feedback_light_dir_y;
extern const f32 player_feedback_light_green;
extern const f32 player_feedback_light_blue;
extern const f32 player_feedback_light_step;

// An equipped item and the slot it sits in, kept while apply_battle_level_reset rebuilds the stats.
struct EquippedItemSlot {
    EquippedItemSlot() {
        slot = 0;
        item = NULL;
    }

    s16 slot;
    TItem *item;
};

extern "C" {

extern const f32 player_rand_pick_limit;

// Called ahead of its definition: the functions run from the highest address down.

void TObjPlayer::update_position(PlayerSyncRecord *record) {
    set_position_from(&record->position);
    save_previous_position();
    calc_attach_pos();
    set_position_history_entry(0, position.x, position.z);
}

void TObjPlayer::send_selected_spawn_position(u16 id) {
    G_SetPosition_6x3F m;
    saddr found;
    TObjPlayerSet *o;
    found = 0;
    for (o = (TObjPlayerSet *)tl_06->m_down; o != NULL; o = (TObjPlayerSet *)o->m_next) {
        if (o->check_value_equals(TObjPlayerSet::class_name) != 0 && o->set_params[0] == 0 &&
            (s32)o->scale.x == id) {
            found = 1;
            break;
        }
    }
    if (found != 0 && (this == NULL || this->obj_isState2_324() == 0)) {
        m.init();
        m.header.client_id = get_entity_id();
        m.angle = o->rotation_y;
        VecCopy((Vec *)&m.pos, &o->position);
        m.send();
    }
}

RespawnCandidate::RespawnCandidate() {
    slot = 0xFFFF;
    set = NULL;
}

void TObjPlayer::send_respawn_position() {
    RespawnCandidate list[13];
    G_TeleportPlayer_6x24 cmd;
    Vec pos;
    s32 count;
    s32 i;
    s32 ok;
    TObjPlayerSet *obj;
    RespawnCandidate *c;
    s32 area;
    TObjPlayerSet *pick;

    c = list;
    count = 0;
    for (obj = (TObjPlayerSet *)tl_06->m_down; obj != NULL; obj = (TObjPlayerSet *)obj->m_next) {
        if (obj->check_value_equals(TObjPlayerSet::class_name) != 0 && obj->set_params[0] == 0) {
            f32 range = player_lock_range_sq;
            ok = 1;
            for (i = 0; i < 12; i++) {
                if (i != (u16)this->get_entity_id()) {
                    TObjPlayer *p = get_player_by_client_id(i);
                    if (p != NULL && horizontal_distance_squared(&obj->position, &p->position) < range) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0) {
                count++;
                c->slot = obj->scale.x;
                c->set = obj;
                c++;
            }
        }
        if (count > 4) {
            break;
        }
    }
    cmd.init();
    pick = list[(s32)((f32)count * (player_rand_pick_limit * (player_rand_unit * (f32)rand())))].set;
    if (pick == NULL || count == 0) {
        area = this->rotation_y;
        VecCopy(&pos, &this->position);
    } else {
        area = pick->rotation_y;
        VecCopy(&pos, &pick->position);
    }
    if (this == NULL || ((TObjChara *)this)->obj_isState2_324() == 0) {
        cmd.header.client_id = this->get_entity_id();
        cmd.angle_y = area;
        VecCopy((Vec *)&cmd.pos, &pos);
        cmd.send();
    }
}

void TObjPlayer::init_collision_body() {
    this->collision_body.offset.x = player_zero;
    this->collision_body.offset.y = player_zero;
    this->collision_body.offset.z = player_zero;
    this->collision_body.radius = player_body_radius;
    this->collision_body.half_width = player_body_radius;
    this->collision_body.shape = 0;
    switch (this->control_state) {
    case 1:
    case 2:
        if (this->pk_state.is_enabled() == 0) {
            this->collision_body.flags = 0x200B;
        } else {
            this->collision_body.flags = 0x2003;
        }
        break;
    case 3:
        if (this->pk_state.is_enabled() == 0) {
            this->collision_body.flags = 0x604B;
        } else {
            this->collision_body.flags = 0x6043;
        }
        break;
    case 6:
        this->collision_body.flags = 0x16043;
        break;
    }
    this->collision_body.center.x = this->position.x;
    this->collision_body.center.y = this->position.y;
    this->collision_body.center.z = this->position.z;
    this->collision_body.defense = player_zero;
    this->set_collision_body(&this->collision_body);
}

void TObjPlayer::clear_links() { this->clear_collision_bodies(); }

void TObjPlayer::create_lockon_cursor() {
    if (is_single_screen() != 0) {
        if (this->lock_on_cursor == NULL) {
            this->lock_on_cursor = new TLockOnCursor(this, this->get_entity_id());
        }
    } else if (((this->is_locally_controlled() != 0) || (obj_isState3_324() != 0)) && (this->lock_on_cursor == NULL)) {
        this->lock_on_cursor = new TLockOnCursor(this, this->get_entity_id());
    }
}

void TObjPlayer::release_lock_on_cursor() {  }

void TObjPlayer::update_lock_on_cursor() { TLockOnCursor *m = this->lock_on_cursor; if (m) m->reset_and_spawn_cursors(); }

void TObjPlayer::clear_lock_on_cursor(void *data) { this->lock_on_cursor = NULL; }

void TObjPlayer::init_action_palette_defaults() {
    set_action_palette_entry(0, 0, 0, 1, 0);
    set_action_palette_entry(0, 1, 0, 1, 0);
}

void TObjPlayer::init_player_substructs(u8 *data) {
    copy_disp_config(&action_palettes, (TPlyDispConfig *)data);
    init_action_palette_defaults();
}

void TObjPlayer::release_action_palettes() {  }

void TObjPlayer::reset_action_input() { enable_action_input(); }

void TObjPlayer__sub_801BBB70(TObjPlayer *player, PlayerSyncRecord *record) {}

void TObjPlayer::setup_fresh_player_state(u8 *char_data) {
    this->hp = (s16) this->hpmax;
    this->tp = (s16) this->tpmax;
    if ((this->obj_isState2_324() != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (TObjPlayer::check_camera_mode() == 0)) {
        deactivate_body_collision();
    }
    if (this->is_android() != 0) {
        this->set_flag_10000();
    }
    if (is_alive_and_ready() != 0) {
        refill_traps();
    }
    this->set_language((int) (*(u8 *)((s8 *)char_data + 3)));
    scale_state.set_actor_id(this->get_entity_id());
    this->disable_drop_weapon_on_death();
    TPlyCharData *record = reinterpret_cast<TPlyCharData *>(char_data);
    this->mag_level = record->get_class_flag_0();
    this->class_flag_1 = record->get_class_flag_1();
    this->battle_mode = record->get_class_flag_2();
}

void TObjPlayer::sub_801BB950() {
  u32 lobby_font;
  TItem *equipped_weapon;
  if (is_current_area_item_enabled() != 0)
  {
    equipped_weapon = get_equipped_weapon(this);
    if (equipped_weapon != 0)
    {
      this->set_action_provider_variant(equipped_weapon->get_motion_type());
    }
  }
  if ((this->is_locally_controlled() != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0))
  {
    if (is_current_area_item_enabled() == 0)
    {
      this->photon_blast_gauge.clear_charge();
    }
    this->photon_blast_gauge.reinit_photon_blast_gauge();
    this->photon_blast_gauge.update_if_ready();
    TObjPlayer::update_photon_blast_state();
  }
  if (TFontSmallLobby::is_lobby_floor_15() != 0)
  {
    lobby_font = this->lobby_label;
    if ((lobby_font != 0U) && (reinterpret_cast<TObject *>(lobby_font)->check_value_equals(TFontSmallLobby_class_name) != 0))
    {
      ((TObject *)(this->lobby_label))->queue_destruction();
    }
    this->lobby_label = (uaddr)TFontSmallLobby::create(this->get_entity_id() & 0xFFFFu);
  }
  obj_clear_flag30_20000(this);
  if (this->is_locally_controlled() != 0)
  {
    if (check_flag_800000() != 0)
    {
      send_disable_stealth_suit_effect();
    }
    if (scale_state.is_scaled() != 0)
    {
      scale_state.request_size_restore();
    }
  }
  technique_state.enable_techniques();
  reset_client_quest_slot_table();
}

void TObjPlayer::init_class_flags(PlayerSyncRecord *record) {
    this->mag_level = record->get_class_flag_0();
    this->class_flag_1 = record->get_class_flag_1();
    this->battle_mode = record->get_class_flag_2();
}

void TObjPlayer::load_pending_actions(TPlyCharData *record) {
    s32 bits = record->unpack_u32_lo();
    pending_actions.set_bits(bits);
    record_flags_hi = record->unpack_u32_hi();
}

void TObjPlayer::release_pending_action() {  }

void TObjPlayer::reset_pending_action() {  }

void load_pending_actions_from_sync_record(TObjPlayer *player, u8 *record) {
    u32 state = record[0x143] | (record[0x15F] << 8);
    state |= (record[0x17B] << 16) & 0xFF0000;
    state |= record[0x197] << 24;
    player->pending_actions.set_bits(state);
}

void TObjPlayer::reset_motion_fields() {
    s32 anim_id;
    TObjBase::reset_motion_fields();
    this->TObjCollidable::reset_motion_fields();
    this->TObjMotion::reset_motion_fields();
    this->TObjChara::reset_motion_fields();
    this->reset_state();
    reset_body_parts();
    this->place_on_area_entry();
    this->update_input_and_draw();
    reset_pad_binding();
    this->can_cast_technique();
    TObjPlayer::update_recobox((saddr)this);
    this->update_state();
    reset_technique_caps();
    this->reset_area_entry_state();
    this->update_lock_on_cursor();
    reset_action_input();
    this->sub_801BB950();
    reset_pending_action();
    if ((this->is_locally_controlled() != 0) && (TObjPlayer::is_key_machine_ready() != 0) && (this->check_flag(0x800) == 0) && ((this->test_actor_flags(0x800) != 0) || (this->get_actor_hp() <= 0))) {
        this->clear_actor_flags((u32)(0x800));
        if (TObjPlayer::check_camera_mode() != 0) {
            send_use_medical_center();
        } else {
            if (is_single_screen() == 0) {
                this->set_meseta(0);
            }
            send_6x24_teleport_player(this->get_entity_id(), (const Vec *)this->get_hospital_position(), this->get_hospital_yaw());
            this->set_state_flags(0x800);
            this->set_battle_flag(0);
        }
    }
    if ((this->is_locally_controlled() != 0) && (this->check_flag(0x800) != 0)) {
        this->clear_state_flags(0x800);
        TWindowCtrl::enable_client_main_menu(this->get_entity_id());
        send_impose_hold(this, 0xF);
        this->update_position_from_target();
        send_use_medical_center();
        send_medical_center_revive_all_players();
        if (this->is_alive_and_ready() != 0) {
            this->refill_traps();
        }
        anim_id = this->get_anim_id();
        switch (anim_id) {
        case 2:
            break;
        case 0:
            TObjPlayer::set_camera_mode(2);
            this->send_field_state();
            this->set_meseta(0);
            new TMedicalCenterMes(tl_05, this);
            break;
        case 1:
            TObjPlayer::set_camera_mode(1);
            break;
        }
        this->set_battle_flag(0);
    }
}

s32 TObjPlayer::setup_control_role(s32 role) {
    this->set_control_role(role);
    if (role < 4) {
        this->control_state = 1;
    } else if (role == 4) {
        this->control_state = 2;
    } else if (role == 5) {
        this->control_state = 3;
    } else if (role == 6) {
        this->control_state = 6;
    } else if (role == 7) {
        this->control_state = 7;
    } else {
        return 0;
    }
    this->actorFlags |= 0x10000000;
    init_collision_body();
    return register_player_slot() != 1 ? 1 : 0;
}

void TObjPlayer::unregister() {
    clear_links();
    this->unregister_sub();
    player_slot_table[(u16)this->get_entity_id()] = NULL;
}

void TObjPlayer::run_task() {
    handle_state2_transitions();
    update_subsystems();
    update_position_history();
    update_status_effects();
    run_action_state_phase(mode, 1);
    advance_animation();
    calc_attach_pos();
    copy_position();
    calc_marker_position(&marker_position, this);
    if (test_actor_flags(0x800) != 0) {
        refresh_collision_body_centers();
    } else if (pk_state.is_enabled() == 0) {
        switch (control_state) {
        case 1:
            refresh_collision_body_centers();
            check_enemy_body_collisions(this);
            update_enemy_collision_flags();
            break;
        case 6:
        case 2:
            refresh_collision_body_centers();
            break;
        case 3:
            refresh_collision_body_centers();
            check_enemy_body_collisions(this);
            update_enemy_collision_flags();
            break;
        }
    } else {
        switch (control_state) {
        case 3:
        case 1:
            check_object_collisions();
            check_enemy_body_collisions(this);
            update_enemy_collision_flags();
            break;
        case 2:
            if (check_flag(4) != 0) {
                refresh_collision_body_centers();
            } else {
                check_object_collisions();
            }
            break;
        case 6:
            refresh_collision_body_centers();
            break;
        }
    }
    update_movement_effects();
    update_facing_vector();
}

void TObjPlayer::render_shadows() {
    f32 f;

    if (is_in_shadow_range(&position, player_shadow_range) != 0) {
        set_shadow_flag();
        TParticleCtrl::begin_effect_render();
        if (test_actor_flags(0x02000000) == 0 && is_inactive() != 0 &&
            (check_flag_4() == 0 || (check_flag_4() != 0 && phase == 0))) {
            f = classify_actor_view_detail(player_view_detail_near, player_view_detail_far, player_front_distance);
            clear_actor_flags((u32)0x08000000);
            draw_body((s32)f);
            render_material_state.save();
            apply_material_color_override();
            draw_body_overlay();
            render_material_state.restore();
        }
        TParticleCtrl::end_effect_render();
        clear_shadow_flag();
    }
}

void TObjPlayer::render_body_pass(f32 f) {
    clear_actor_flags((u32)0x08000000);
    TParticleCtrl::end_effect_render();
    select_actor_lighting(this);
    if (check_flag_800000() != 0 && obj_isState2_324() != 0) {
        draw(get_frame());
    } else if (!(m_flags & 0x400)) {
        model_render_flags |= 1;
        draw_body((s32)f);
        model_render_flags &= ~1;
    }
    render_material_state.save();
    apply_material_color_override();
    set_draw_list_mask(1);
    draw_body_overlay();
    render_material_state.restore();
    restore_scene_lighting();
}

void TObjPlayer::render() {
    f32 detail;

    if (test_actor_flags(0x02000000) == 0 && is_inactive() != 0 &&
        (check_flag_4() == 0 || (check_flag_4() != 0 && phase == 0))) {
        detail = classify_actor_view_detail(player_view_detail_near, player_view_detail_far, player_front_distance);
        if (player_zero != detail) {
            if (((s32)main_task.get_task_flags() & 0x20) && is_central_control_area() != 0) {
                if (push_player_reflection_matrix(entity_id, 1) != 0) {
                    render_body_pass(detail);
                    restore_render_scissor(1);
                }
            } else {
                clear_actor_flags((u32)0x08000000);
                TParticleCtrl::end_effect_render();
                select_actor_lighting(this);
                if (check_flag_800000() != 0 && obj_isState2_324() != 0) {
                    draw(get_frame());
                } else if (!(m_flags & 0x400)) {
                    model_render_flags |= 1;
                    draw_body((s32)detail);
                    model_render_flags &= ~1;
                }
                render_material_state.save();
                apply_material_color_override();
                set_draw_list_mask(1);
                draw_body_overlay();
                render_material_state.restore();
                restore_scene_lighting();
            }
        } else {
            set_actor_flags(0x08000000);
            set_motion_packed_rotation();
            draw(get_frame());
            clear_motion_packed_rotation();
            render_material_state.save();
            apply_material_color_override();
            draw_body_overlay();
            render_material_state.restore();
        }
    } else {
        set_motion_packed_rotation();
        draw(get_frame());
        clear_motion_packed_rotation();
        render_material_state.save();
        apply_material_color_override();
        draw_body_overlay();
        render_material_state.restore();
    }
}

void TObjPlayer::draw_body(s32 detail) {
    Vec pos;
    Vec *scale;
    push_matrix();
    VecCopy(&pos, &position);
    pos.y += death_sink.offset;
    translate_matrix_vec3((u8 *)(0), (u8 *)&pos);
    rotate_matrix_y(0, rotation_y);
    if (scale_state.is_scaled() != 0) {
        scale = scale_state.get_scale();
        scale_matrix(0, scale->x, scale->y, scale->z);
    }
    render_material_state.save();
    set_model_render_flags(8);
    apply_material_color_override();
    if (m_flags & 0x400) {
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
    }
    set_texture_list(&body_textures);
    set_motion_packed_rotation();
    if (detail == 2) {
        motion_flags |= 0x400;
        draw_saving_joints();
    } else {
        motion_flags &= ~0x400;
        draw_saving_joints_checked();
    }
    clear_motion_packed_rotation();
    draw_head_attachments();
    render_material_state.restore();
    pop_matrix();
    if (scale_state.is_scaled() != 0) {
        draw_projected_shadow(scale_state.get_scale(), 0);
        return;
    }
    draw_projected_shadow(NULL, 0);
}

void TObjPlayer::draw_head_attachments() {
    s32 special_color;
    if ((u32) this->attachment_model != 0U) {
        this->get_joint_matrix(0x3A);
        ((s32 (*)(void))push_matrix_from)();
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(this->attachment_textures));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TObjPlayer::play_phase_transition_sound(this->attachment_model);
        set_default_alpha_blend();
        pop_matrix();
    }
    if (this->head_model != NULL) {
        this->get_joint_matrix(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(this->head_textures));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TCharaMaking::enable_making();
        draw_chunk_object(this->head_model);
        TCharaMaking::clear_flag_bit0();
        set_default_alpha_blend();
        pop_matrix();
    }
    if (this->hair_model != NULL) {
        this->get_joint_matrix(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(this->head_textures));
        special_color = 0;
        if (this->m_flags & 0x400) {
            special_color = 1;
        }
        TCharaMaking::enable_making();
        f32 alpha = this->render_material_state.get_alpha();
        draw_colored_hair(alpha, (saddr)this->hair_model,
            (CharacterAppearanceFields *)this->name, special_color);
        TCharaMaking::clear_flag_bit0();
        set_default_alpha_blend();
        pop_matrix();
    }
}

void TObjPlayer::draw_body_overlay() {}

void TObjPlayer::draw_projected_shadow(Vec *scale, s32 force_draw) {
    Vec v;
    s32 a;
    s32 b;
    get_anim_node_position(1, &v);
    push_matrix();
    direction_to_rotation_xz((u8 *)&this->TObjChara::ground_normal, &a, &b);
    translate_matrix(0, v.x, player_shadow_lift + position.y, v.z);
    rotate_matrix_z(0, b);
    rotate_matrix_x(0, a);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, -0x4000);
    if (scale != NULL) {
        scale_matrix(0, scale->x, scale->z, player_one);
    }
    draw_blob_shadow(force_draw);
    pop_matrix();
}

}

void send_6x21_inter_level_warp(TObjPlayer *player, s32 floor) {
    if (player == 0 || player->obj_isState2_324() == 0) {
        G_InterLevelWarp_6x21 m;
        m.init();
        m.header.client_id = player->get_entity_id();
        m.floor = floor;
        m.send();
    }
}

void handle_6x21_inter_level_warp(G_InterLevelWarp_6x21 *command) {
    G_InterLevelWarp_6x21 m;
    TObjPlayer *p;

    m.init();
    m = *command;
    m.bswap();
    if (validate_6x21_inter_level_warp(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            if ((p->obj_isState2_324() != 0) && (m.floor != p->get_floor())) {
                p->set_state_flags(0x40000);
            }
            p->set_floor_index(get_floor_area(m.floor));
            p->set_floor(m.floor);
        }
    }
}


void TObjPlayer::apply_state_transform() {
    G_SetPlayerFloor_6x1F pkt;

    ::set_flag_400000(this);
    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.floor = this->get_floor();
        pkt.send();
    }
}

void handle_6x1F_set_player_floor(G_SetPlayerFloor_6x1F *command) {
    G_SetPlayerFloor_6x1F m;
    G_SetAnimationState_6xAE anim;
    G_SetPosition_6x20 position;
    TObjPlayer *p;
    TObjPlayer *local;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x1F_set_player_floor(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->set_floor_index(get_floor_area(m.floor));
            p->set_floor(m.floor);
        }
        local = get_local_player();
        if (local != NULL && (local == NULL || local->obj_isState2_324() == 0)) {
            position.init();
            position.header.client_id = local->get_entity_id();
            position.floor = local->get_floor();
            VecCopy(&position.pos, &local->position);
            position.angle_y = local->rotation_y;
            position.send();
            if (TFontSmallLobby::is_lobby_floor_15() != 0) {
                anim.init();
                anim.header.client_id = local->get_entity_id();
                anim.player_flags = local->get_state_flags();
                anim.animation_number = local->get_requested_action();
                anim.animation_timer = local->get_frame();
                anim.send_to(m.header.client_id);
            }
        }
    }
}

void handle_6x20_set_position(G_SetPosition_6x20 *command) {
    G_SetPosition_6x20 m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x20_set_position(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->set_position_from(&m.pos);
            p->set_floor_index(get_floor_area(m.floor));
            p->set_floor(m.floor);
            p->rotation_y = m.angle_y;
            ::set_flag_400000(p);
        }
    }
}

void handle_6xAE_set_animation_state(G_SetAnimationState_6xAE *command) {
    G_SetAnimationState_6xAE m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6xAE_set_animation_state(&m) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL && TFontSmallLobby::is_lobby_floor_15() != 0 && p->test_action_mask(0x01000000) == 0 && (m.player_flags & 0x04000000)) {
            p->set_state_flags(m.player_flags & 0x1C000000);
            p->run_action_state_phase(0x18, 0);
        }
    }
}

TObjPlayer *get_player_by_client_id(s32 i) {
    if (i == 0xFFFF) {
        return 0;
    }
    if (i < 0 || i >= 12) {
        return 0;
    }
    return player_slot_table[i];
}

s32 TObjPlayer::register_player_slot() {
    TObjPlayer *previous = get_player_by_client_id((u16)this->get_entity_id());
    if (previous != 0) {
        delete previous;
    }
    player_slot_table[(u16)this->get_entity_id()] = this;
    return register_entity_by_id(this) == (u16)0xFFFF ? 1 : 0;
}

void TObjPlayer::set_action_state(s16 state, s16 animation_number) {
    prev_mode = this->mode;
    this->mode = state;
    if (is_action_id_none(animation_number) == 0) {
        this->requested_action = animation_number;
    }
    mode_mask = 1 << state;
    this->set_state_flags(0x10);
}

s32 TObjPlayer::start_freeze() {
    if (mode_mask & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(this->get_idle_animation());
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

s32 TObjPlayer::init_photon_blast(s16 anim) {
    if (mode_mask & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(anim);
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

s32 TObjPlayer::start_camera_pan(s16 action, s32 angle) {
    if (mode_mask & 0x1E000) {
        return 0;
    }
    if ((s16) this->mode == action) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(action);
    anim_state.set_animation(this->requested_action);
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

void TObjPlayer::freeze_all_players() {
    foreach_player(TObjPlayer::start_freeze_self);
}

s32 TObjPlayer::end_camera_pan() {
    if ((s32) lbl_805D55C0 != 0) {
        return 0;
    }
    if (!(mode_mask & 0x10000)) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFEFFFF);
    return 1;
}

void release_players_from_cutscene(void) {
    TObjPlayer::foreach_player(end_player_camera_pan);
    release_all_players_control_lock();
}

s32 TObjPlayer::try_status_action() {
    if (check_flag30_bit20() != 0) {
        run_action_state_phase(0x13, 5);
        return 1;
    }
    if (is_status_flag_200() != 0) {
        if (test_actor_flags(0x400) != 0) {
            run_action_state_phase(0xE, 5);
        } else {
            run_action_state_phase(0xD, 5);
        }
        return 1;
    }
    if (can_guard() != 0) {
        run_action_state_phase(0xA, 5);
        return 1;
    }
    if (is_status_locked() != 0) {
        if (anim_state.get_action_id() == 0x10) {
            run_action_state_phase(0x10, 5);
        } else {
            clear_actor_flags((u32)0x10000);
            run_action_state_phase(anim_state.get_action_id(), 5);
            anim_state.set_action_id(0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer::handle_state2_transitions() {
    s16 control_state;

    this->clear_state_flags(0x10);
    control_state = this->control_state;
    switch (control_state) {
    case 1:
        if ((get_main_phase() != 0xE) && ((s32) lbl_805D55C0 != 0)) {
            goto call3;
        }
        this->select_contextual_pickup_action();
        run_action_state_phase(this->mode, 7);
        if (this->check_flag_48() != 0) {
            break;
        }
        run_action_state_phase(this->mode, 2);
        if (this->check_flag_48() != 0) {
            break;
        }
call3:
        run_action_state_phase(this->mode, 3);
        break;
    case 2:
        if ((is_on_current_floor() == 0) && (this->check_flag_4() == 0)) {
            run_action_state_phase(0x16, 0);
            return;
        }
        if ((this->appear_fade.is_shown() != 0) && (this->is_body_collision_inactive() != 0) && (this->test_action_mask(4) != 0)) {
            ::set_flag_400000(this);
            appear_fade.begin();
        }
        run_action_state_phase(this->mode, 8);
        return;
    case 3:
    case 6:
        run_action_state_phase(this->mode, 7);
        if (this->check_flag_48() == 0) {
            run_action_state_phase(this->mode, 3);
        }
        break;
    }
}

void send_6x25_equip_item(TObjPlayer *player, s32 item_id, s32 slot) {
    G_EquipItem_6x25 packet;
    if (player->check_switch_available(item_id) != 0 && (player == NULL || player->obj_isState2_324() == 0)) {
        packet.init();
        packet.header.client_id = player->get_entity_id();
        packet.item_id = item_id;
        packet.equip_slot = slot;
        packet.send();
    }
}

void handle_6x25_equip_item(G_EquipItem_6x25 *command) {
    G_EquipItem_6x25 m;
    TObjPlayer *player;
    TItem *item;
    TItemList *slot;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x25_equip_item(&m) != 0) {
        player = get_player_by_client_id(m.header.client_id);
        if (player != NULL && (slot = static_cast<TItemList *>(player->inventory_objects->start_inventory_update(m.item_id))) != NULL &&
            (item = slot->get_owner_if_alive()) != NULL) {
            player->equip_item_to_slot(item, m.equip_slot);
        }
    }
}


void TObjPlayer::equip_item_to_slot(TItem *item, s32 slot) {
    if (item->is_unit() != 0) {
        if (slot < 9 || slot > 12) {
            slot = 9;
        }
        s32 attach_slot = (s8)slot;
        item->set_attach_slot(attach_slot);
    } else {
        slot = item->get_attach_slot();
    }
    TItem *current = (TItem *)get_slot_value(equipped_items.items, slot);
    if (current == NULL) {
        set_equip_slot_entry((saddr)equipped_items.items, slot, (saddr)item);
        item->equip();
    } else if (current != item) {
        unequip_item(current);
        set_equip_slot_entry((saddr)equipped_items.items, slot, (saddr)item);
        item->equip();
    }
    if (test_action_mask(2) != 0) {
        set_animation(this->get_current_mode_animation());
    }
}

void TObjPlayer::send_6x26_unequip_item(TObjPlayer *target, u32 item_id) {
    if (target == NULL || static_cast<TObjChara *>(target)->obj_isState2_324() == 0) {
        G_UnequipItem_6x26 packet;
        packet.init();
        packet.header.client_id = target->get_entity_id();
        packet.item_id = item_id;
        packet.send();
        target->send_unequip_held_item();
    }
}

G_UnequipItem_6x26 &G_UnequipItem_6x26::operator=(G_UnequipItem_6x26 &src) {
    copy_subcommand_header(this, &src);
    item_id = src.item_id;
    equip_slot = src.equip_slot;
    return *this;
}

void handle_6x26_unequip_item(G_UnequipItem_6x26 *command) {
    G_UnequipItem_6x26 m;
    TObjPlayer *player;
    TItem *item;
    TItemList *slot;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x26_unequip_item(&m) != 0) {
        player = get_player_by_client_id(m.header.client_id);
        if (player != NULL && (slot = static_cast<TItemList *>(player->inventory_objects->start_inventory_update(m.item_id))) != NULL &&
            (item = slot->get_owner_if_alive()) != NULL) {
            player->unequip_item(item);
        }
    }
}


void TObjPlayer::unequip_item(TItem *item) {
    set_equip_slot_entry((saddr)equipped_items.items, item->get_attach_slot(), 0);
    item->unequip();
    if (item->get_item_type() == 1 && item->get_item_group() == 1) {
        unequip_all_units();
    }
    if (test_action_mask(2) != 0) {
        set_animation(this->get_current_mode_animation());
    }
}

void TObjPlayer::unequip_all_units() {
    saddr player = (saddr)this;
    s32 i;
    TItem *slot_value;

    i = 9;
    do {
        slot_value = (TItem *)TObjPlayer::get_slot_value((s32 *)(player + 0xD04), i);
        if (slot_value != NULL) {
            set_equip_slot_entry(player + 0xD04, i, 0);
            slot_value->unequip();
        }
        i += 1;
    } while (i <= 0xC);
}

#pragma push
#pragma fp_contract on
s32 TObjPlayer::preview_equip_stats(PlayerRequirementStats *out, u8 *incoming) {
    player_stats b;
    AttackParams a;
    ActorParamBlock d;
    TItem *prev;
    saddr slot;
    s32 atp;
    f32 rate;
    if (incoming != NULL && out != NULL) {
    prev = NULL;
    b = *this->stat_block;
    a = *this->attack_params;
    d = *this->param_block;
    switch (incoming[0]) {
    case 0:
        prev = TObjPlayer::get_equipped_weapon(this);
        break;
    case 1:
        if (incoming[1] == 1) {
            prev = this->get_equipped_armor();
        } else if (incoming[1] == 2) {
            prev = this->get_equipped_shield();
        }
        break;
    case 2:
        prev = this->get_equipped_mag();
        break;
    }
    if (prev != NULL) {
        prev->subtract_equip_stats(&a, (s16 *)&d, (s16 *)&b);
        if (prev->get_item_type() == 1 && prev->get_item_group() == 1) {
            for (slot = 9; slot <= 12; slot++) {
                TItem *unit = (TItem *)TObjPlayer::get_slot_value(this->equipped_items.items, slot);
                if (unit != NULL) {
                    unit->subtract_equip_stats(&a, (s16 *)&d, (s16 *)&b);
                }
            }
        }
    }
    ((TItemData *)incoming)->apply_equip_effects(this, &a, &d, (EquipStatBonus *)&b, NULL);
    b.stats.atp = clamp_s32(b.stats.atp, 0, ((s16 *)get_class_stat_entry())[0]);
    b.stats.mst = clamp_s32(b.stats.mst, 0, ((s16 *)get_class_stat_entry())[1]);
    b.stats.evp = clamp_s32(b.stats.evp, 0, ((s16 *)get_class_stat_entry())[2]);
    b.stats.dfp = clamp_s32(b.stats.dfp, 0, ((s16 *)get_class_stat_entry())[4]);
    b.stats.ata = clamp_s32(b.stats.ata, 0, ((s16 *)get_class_stat_entry())[5]);
    b.stats.lck = clamp_s32(b.stats.lck, 0, ((s16 *)get_class_stat_entry())[6]);
    out->set(this, &b, &a, &d);
    rate = this->get_status_effect_amount(2);
    {
        s16 range;
        slot = b.stats.atp;
        {
        s16 sl = slot;
        atp = (s32)((f32)sl * rate + (f32)(sl + a.get_atp_min()));
        }
        range = a.get_atp_max() - a.get_atp_min();
        out->atp = atp + (s32)((f32)range * rate + (f32)range);
    }
    rate = this->get_status_effect_amount(3);
    out->dfp = (s32)((f32)out->dfp * rate + (f32)out->dfp);
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::preview_unequip_stats(PlayerRequirementStats *out, s32 key) {
    AttackParams a;
    player_stats c;
    ActorParamBlock b;
    TItem *owner;
    s32 i;
    s32 base;
    f32 k;
    s16 d;
    TItemList *list = this->inventory_objects->start_inventory_update(key);
    if (list == NULL) {
        return 0;
    }
    owner = list->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (owner->is_equipped() == 0 && this->get_equipped_item(owner->get_attach_slot()) == NULL) {
        return 1;
    }
    a = *this->attack_params;
    b = *this->param_block;
    c = *this->stat_block;
    owner->subtract_equip_stats(&a, (s16 *)&b, (s16 *)&c);
    if (owner->get_item_type() == 1 && owner->get_item_group() == 1) {
        for (i = 9; i <= 12; i++) {
            TItem *s = (TItem *)TObjPlayer::get_slot_value(this->equipped_items.items, i);
            if (s != NULL) {
                s->subtract_equip_stats(&a, (s16 *)&b, (s16 *)&c);
            }
        }
    }
    out->set(this, &c, &a, &b);
    k = this->get_status_effect_amount(2);
    i = c.stats.atp;
    {
        s16 sl = i;
        base = (s32)((f32)sl * k + (f32)(sl + a.get_atp_min()));
    }
    d = a.get_atp_max() - a.get_atp_min();
    out->atp = base + (s32)((f32)d * k + (f32)d);
    {
        f32 k2 = this->get_status_effect_amount(3);
        out->dfp = (f32)out->dfp * k2 + (f32)out->dfp;
    }
    return 2;
}
#pragma pop

void TObjPlayer::send_unequip_held_item() {
    G_UnequipItem_6x26 cmd;
    TItem *item;
    item = get_equipped_weapon(this);
    if ((item != NULL) && (item->check_equip_requirements(this, (s16 *)0) == 0) && ((this == NULL) || (this->obj_isState2_324() == 0))) {
        cmd.init();
        cmd.header.client_id = get_entity_id();
        cmd.item_id = item->get_item_id();
        cmd.send();
    }
}

void TObjPlayer::use_current_item() {
    s32 position;
    TItem *item;

    item = this->get_equipped_shield();
    if (item != NULL) {
        item->perform_action();
        return;
    }
    this->get_anim_node_position(0x24, (Vec *)&position);
    TEffGuard::create((Vec *)&position);
}

void TObjPlayer::get_anim_node_position(s32 joint, Vec *out_pos) {
    Vec stack;
    stack.z = player_zero;
    stack.y = player_zero;
    stack.x = player_zero;
    push_matrix_from(0);
    copy_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(get_joint_matrix(joint)));
    premultiply_matrix(NULL, TCameraCtrl::get_view_matrix());
    matrix_mult_vec(NULL, &stack, out_pos);
    pop_matrix();
}

s32 TObjPlayer::update_target_lock() {
    f32 lock_target_distance_sq;
    TLockOnCursor *cursor;
    u16 lock_target_id;
    TObjPlayer *target;

    cursor = this->lock_on_cursor;
    if (cursor == NULL) {
        return 0;
    }
    lock_target_id = cursor->nearest_target.get_published_target_id();
    lock_target_distance_sq = this->lock_on_cursor->nearest_target.get_published_target_dist();
    this->lock_on_cursor->nearest_target.get_candidate_part_index();
    if (!(this->actorFlags & 0x100000)) {
        if (lock_target_id == 0xFFFF) {
            return 0;
        }
        if ((target = (TObjPlayer *)find_entity_by_id(lock_target_id)) == NULL) {
            return 0;
        }
        if (!(lock_target_distance_sq < player_lock_range_sq)) {
            goto block_17;
        }
        if (is_target_in_facing_cone(target->get_position_ptr()) == 0) {
            goto block_17;
        }
        this->actorFlags = (s32) (this->actorFlags | 0x100000);
        return 1;
    }
    if (lock_target_id == 0xFFFF) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
        return 0;
    }
    if ((target = (TObjPlayer *)find_entity_by_id(lock_target_id)) == NULL) {
        return 0;
    }
    if (lock_target_distance_sq > player_lock_release_range_sq) {
        goto clear_and_return;
    }
    if (is_target_in_facing_cone(target->get_position_ptr()) != 0) {
        goto block_17;
    }
clear_and_return:
    this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
    return 0;
block_17:
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_target_in_facing_cone(Vec *target) {
    Vec to;
    Vec fwd = {0.0f, 0.0f, 1.0f};
    f32 x;
    f32 z;
    f32 dot;
    fwd.x = sin_table_lookup(rotation_y);
    fwd.y = player_zero;
    fwd.z = cos_table_lookup(rotation_y);
    x = player_front_distance * sin_table_lookup(rotation_y + 0x8000) + position.x;
    z = player_front_distance * cos_table_lookup(rotation_y + 0x8000) + position.z;
    to.x = target->x - x;
    to.y = player_zero;
    to.z = target->z - z;
    normalize_vector_safe(&to);
    dot = ((f32 (*)(Vec *, Vec *))vec3_dot)(&fwd, &to);
    if (dot < cos_table_lookup(0x1555)) {
        return 0;
    }
    return 1;
}
#pragma pop

s32 TObjPlayer::can_inventory_accept_item(u8 *item) {
    s32 max;
    s32 n;
    TItem *owner;
    if (TItemData::lookup_item_def(item) != 0) {
        if (item[0] == 4) {
            return 1;
        }
        TItemList *list = this->inventory_objects->set_mode_and_refresh_object(item);
        if (list == NULL) {
            if (this->inventory_objects->item_count >= 30) {
                return 0;
            }
            return ((TItemData *)item)->get_max_stack_size();
        }
        owner = list->get_owner_if_alive();
        if (owner == NULL) {
            return 0;
        }
        n = owner->get_max_stack_size();
        n -= owner->get_amount();
        max = ((TItemData *)item)->get_stack_count();
        return (n < max) ? 0 : n;
    }
    return this->inventory_objects->item_count < 30;
}

s32 TObjPlayer::can_pickup_item_by_id(TItem *item) {
    TItemData item_data;

    item->copy_to_item_data(&item_data);
    return this->can_pickup_item(&item_data);
}

s32 TObjPlayer::can_pickup_item(TItemData *item_data) {
    s32 room;
    s32 max_stack_size;
    TItem *held;

    if (TItemData::lookup_item_def((u8 *)item_data) != 0) {
        if ((u8) *(u8 *)item_data == 4) {
            return get_actor_meseta() < 0xF423F;
        }
        TItemList *list = this->inventory_objects->set_mode_and_refresh_object(item_data);
        if (list != NULL) {
            held = list->get_owner_if_alive();
            if (held == NULL) {
                return 0;
            }
            max_stack_size = held->get_max_stack_size();
            room = max_stack_size - held->get_amount();
            return (item_data->get_stack_count() <= room) ? 1 : 0;
        }
    }
    if (this->inventory_objects->item_count >= 0x1E) {
        return 0;
    }
    return 1;
}

u32 TObjPlayer::pickup_item(TItem *item) {
    u32 item_data[5];
    TItemList *id;
    TItemList *list;
    s32 n;
    TItem *owner;
    s16 idx;
    if (item == NULL) {
        return 0;
    }
    if (item->get_item_type() == 4) {
        this->add_meseta(item->calc_price());
        record_meseta_pickup(item->calc_price());
        item->destroy();
        this->play_sound_if_on_floor(0x52802);
        return 0;
    }
    if (this->can_pickup_item_by_id(item) == 0) {
        return 0;
    }
    ((void (*)(void *))on_inventory_item_added)(item);
    list = 0;
    switch (item->get_item_type()) {
    case 0:
    case 1:
    case 2:
        list = new TItemList(this->inventory_objects->item_list);
        break;
    case 3:
        if (item->is_stackable() != 0) {
            item->copy_to_item_data((TItemData *)&item_data);
            id = this->inventory_objects->set_mode_and_refresh_object(&item_data);
            if (id == 0) {
                list = new TItemList(this->inventory_objects->item_list);
                break;
            }
            n = item->get_amount();
            if (n == 0) {
                n = 1;
            }
            owner = (TItem *)id->get_owner_if_alive();
            if (owner != NULL) {
                owner->add_amount(n);
            }
            item->destroy();
            return 0;
        }
        list = new TItemList(this->inventory_objects->item_list);
        break;
    }
    if (list != NULL) {
        list->set_owner(item);
        on_inventory_item_added(item, this->inventory_objects->item_count++);
        item->set_mode(1);
        ((TObject *)item)->set_parent(this->inventory_objects->item_root);
        item->set_owner_client(this->get_entity_id());
        return (uaddr)list;
    }
    return 0;
}

void TObjPlayer::send_6x29_delete_item(TObjPlayer *player, s32 item_id, s32 count) {
    G_DeleteInventoryItem_6x29 cmd;
    if (player->is_in_lobby() != 0) {
        return;
    }
    if (player != NULL && player->obj_isState2_324() != 0) {
        return;
    }
    cmd.init();
    cmd.header.client_id = player->get_entity_id();
    cmd.item_id = item_id;
    cmd.amount = count;
    cmd.send();
    player->send_unequip_held_item();
}
void handle_6x29_delete_inventory_item(G_DeleteInventoryItem_6x29 *command) {
    G_DeleteInventoryItem_6x29 cmd;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6x29_delete_inventory_item(&cmd.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(cmd.header.client_id);
        if (p != NULL && p->is_in_lobby() == 0) {
            p->dispatch_action(cmd.item_id, cmd.amount);
        }
    }
}


void TObjPlayer::dispatch_action(s32 key, s32 amount) {
    inventory_objects->use_item(this, key, amount);
}

void handle_6xAC(G_DeleteMultipleInventoryItems_6xAC *command) {
    G_DeleteMultipleInventoryItems_6xAC cmd;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6xAC(&cmd) != 0) {
        TObjPlayer *p = get_player_by_client_id(cmd.header.client_id);
        if (p != NULL && TFontSmallLobby::is_lobby_floor_15() == 0) {
            p->delete_multiple_inventory_items(reinterpret_cast<s32 *>(cmd.item_ids.id), cmd.num_items);
        }
    }
}


void TObjPlayer::delete_multiple_inventory_items(s32 *item_ids, s32 count) {
    this->inventory_objects->remove_items(this, item_ids, count);
}

s32 TObjPlayer::count_items_of_type(u8 kind, u8 group, u8 subgroup) {
    TItemData item_data;
    if (this->inventory_objects == NULL) {
        return 0;
    }
    item_data.init();
    item_data.data1.data_u8[0] = kind;
    item_data.data1.data_u8[1] = group;
    item_data.data1.data_u8[2] = subgroup;
    return this->inventory_objects->count_items_by_id(&item_data);
}

void TObjPlayer::request_item_drop(s32 key, s32 count) {
    TItemData item;
    TItem *owner;
    s32 id;
    if (check_player_action_allowed() != 0 &&
        (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0 ||
         TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 1)) {
        ((void (*)(s32, s32, s32, s32))play_sound_effect)(0x53F06, 0, 0, 0);
        return;
    }
    TItemList *list = this->inventory_objects->start_inventory_update(key);
    if (list == NULL) {
        return;
    }
    owner = list->get_owner_if_alive();
    if (owner == NULL) {
        return;
    }
    send_impose_hold(this, 0x384);
    set_action_flag_2();
    owner->copy_to_item_data(&item);
    item.set_stack_count(count);
    id = item.id;
    if (owner->get_amount() - count > 0) {
        item.id = -1;
    }
    inventory_objects->list.add_drop(get_marker_position(&marker_position), this, &item, id);
}

void TObjPlayer::request_meseta_drop(s32 amount) {
    TItemData meseta;
    if (amount > 0) {
        send_impose_hold(this, 0x384);
        set_action_flag_2();
        meseta.init_meseta(amount);
        meseta.id = -1;
        inventory_objects->list.add_drop(get_marker_position(&marker_position), this, &meseta, -1);
    }
}

s32 TObjPlayer::send_trap_packet(int kind) {
    s32 trap = kind;
    G_PlaceTrap_6x83 pkt;

    if ((u8 *)this != NULL && this->obj_isState2_324() != 0) {
        return 0;
    }
    if (TWindowCtrl::is_client_countdown_done((u16)((TObjBase *)this)->get_entity_id()) == 0) {
        return 0;
    }
    if (is_action_available() == 0) {
        return 0;
    }
    if (trap_counts.get_count(trap) <= 0) {
        return 0;
    }
    pkt.init();
    pkt.header.client_id = get_entity_id();
    pkt.trap_type = trap;
    pkt.trap_index = trap_counts.get_count(trap);
    pkt.send();
    return 1;
}

void handle_6x83_place_trap(G_PlaceTrap_6x83 *command) {
    G_PlaceTrap_6x83 pkt;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x83_place_trap(&pkt) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL && TOMineTrap::create_placed_trap(p, pkt.trap_type, pkt.trap_index) != NULL) {
            p->trap_counts.consume(1, pkt.trap_type);
            if (p->is_locally_controlled() != 0) {
                TWindowCtrl::start_client_countdown((u16)p->get_entity_id());
            }
        }
    }
}


void TObjPlayer::send_6x2A_drop_item(TObjPlayer *player, s32 item_id, Vec *pos, s32 amount) {
    G_DropItem_6x2A cmd;
    if (player->is_in_lobby() == 0 && (player == NULL || player->obj_isState2_324() == 0)) {
        cmd.init();
        cmd.header.client_id = player->get_entity_id();
        cmd.item_id = item_id;
        cmd.amount = amount;
        cmd.floor = get_current_floor();
        VecCopy(&cmd.pos, pos);
        cmd.send();
        player->send_unequip_held_item();
    }
}

void handle_6x2A_drop_item(G_DropItem_6x2A *command) {
    G_DropItem_6x2A m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x2A_drop_item(&m) != 0) {
        p = (TObjPlayer *)get_player_by_client_id((u16)m.header.client_id);
        if ((p != NULL) && (p->is_in_lobby() == 0)) {
            p->inventory_objects->update_inventory_item(p, m.item_id, &m.pos.x, m.amount, m.floor);
        }
    }
}
void TObjPlayer::drop_items_on_death() {
    PendingItemDrop *record;
    s32 count;
    TItemData* item;
    TItem *equipped;
    if (this->inventory_objects==NULL || this->obj_isState3_324()!=0 || is_script_controlled()!=0) {
        return;
    }
    PendingItemDrop records[9];
    count=0;
    if (TTecCtrl::is_technique_ready()!=0) {
        if (this->is_drop_weapon_on_death_disabled() == 0) {
            count=this->inventory_objects->set_globals_and_notify(this, records);
        }
        if (get_actor_meseta()!=0) {
            record=&records[count];
            record->set_source_id(-1);
            item=reinterpret_cast<TPlyInventoryItem *>(record)->get_data();
            item->init_meseta(get_actor_meseta());
            count+=1;
            item->id=-1;
        }
    } else if (this->is_drop_weapon_on_death_disabled() == 0) {
        count=this->inventory_objects->set_globals_and_notify(this, records);
    } else {
        equipped = get_equipped_weapon(this);
        if (equipped!=NULL) {
            TObjPlayer::send_6x26_unequip_item(this, equipped->get_item_id());
        }
    }
    if (count>0) {
        scratch_vec5.x=this->position.x;
        scratch_vec5.y=player_front_distance+this->position.y;
        scratch_vec5.z=this->position.z;
        this->inventory_objects->list.add_drops(&scratch_vec5, this, records, count);
        set_action_flag_2();
    }
}
extern "C" {

s32 try_buy_item(TObjPlayer *player, TItemData *item) {
    if (player->can_pickup_item(item) == 0) {
        return 1;
    }
    if (player->try_spend_actor_meseta(item->data2.price * item->get_stack_count()) != 0) {
        buy_item_for_client(item, player->get_entity_id());
        return 0;
    }
    return 2;
}
}

#pragma push
#pragma opt_propagation off
s32 TObjPlayer::try_add_sale_meseta(s32 item_id, s32 amount, s32 count) {
    s32 max = 999999;
    if (max < this->stat_block->meseta + amount) {
        return 0;
    }
    this->add_meseta(amount);
    send_6x29_delete_item(this, item_id, count);
    return 1;
}
#pragma pop

void delete_item(TObjPlayer *player, s32 id, s32 count) { TObjPlayer::send_6x29_delete_item(player, id, count); }

void TObjPlayer::request_inventory_item(TItemData* item) {
    TObjPlayer* player = this;
    G_CreateInventoryItem_PC_V3_BB_6x2B packet;
    if (is_in_lobby() == 0) {
        if ((s32)item->id == -1) {
            item->id = advance_item_id_counter((u16)local_client_id);
        }
        if (player == 0 || ((TObjChara *)player)->obj_isState2_324() == 0) {
            packet.init();
            packet.header.client_id = player->get_entity_id();
            packet.item_data.copy_from(item);
            packet.item_data.encode_for_network();
            packet.send();
        }
    }
}

void handle_6x2B_create_inventory_item(G_CreateInventoryItem_PC_V3_BB_6x2B *command) {
    G_CreateInventoryItem_PC_V3_BB_6x2B pkt;
    TObjPlayer *player;
    s32 kind;
    TItem *item;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x2B_create_inventory_item(&pkt.header) != 0) {
        player = get_player_by_client_id(pkt.header.client_id);
        if ((player != NULL) && (player->is_in_lobby() == 0)) {
            if ((u32)(pkt.header.size * 4) == 0x18) {
                kind = 0;
                pkt.item_data.convert_from_version(0);
            } else {
                kind = 2;
                pkt.item_data.convert_from_version(2);
            }
            pkt.item_data.decode_from_network();
            item = create_item(&pkt.item_data);
            if ((item != NULL) && (player->pickup_item(item) != 0U) && (kind == 2) && (pkt.equip_item != 0) && (TObjPlayer::get_slot_value(player->equipped_items.items, item->get_attach_slot()) == 0U)) {
                set_equip_slot_entry((saddr)player->equipped_items.items, item->get_attach_slot(), (saddr)item);
                player->set_flag_20000();
                item->equip();
                player->clear_flag_20000();
            }
        }
    }
}

s32 TObjPlayer::query_state_if_present(void *out) {
    TPlyItem *inventory = this->inventory_objects;
    u8 *raw = (u8 *)out;
    if (inventory == NULL) {
        return 0;
    }
    return inventory->run_state_query((TPlyInventoryItem *)raw);
}

void TObjPlayer::create_inventory() {
    if ((void *) this->inventory_objects == NULL) {
        this->inventory_objects = new TPlyItem(this);
    }
    this->inventory_objects->item_list = new TItemList((TObject *)this->inventory_objects);
    this->inventory_objects->item_root = new TObject(this);
    equipped_items.clear();
}

void TObjPlayer::bind_saved_inventory_equipment(TObjPlayer *player, TPlyInventoryItem *records, int count) {
    if (records != NULL) {
        player->set_action_provider_variant((s16)TObjPlayer::default_action_provider_variant());
        for (s32 i = 0; i < count; i++) {
            equip_saved_item_if_slot_empty(player, records);
            ++records;
        }
        if (is_current_area_item_enabled() == 0) {
            player->set_action_provider_variant((s16)TObjPlayer::default_action_provider_variant());
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TObjPlayer::equip_saved_item_if_slot_empty(TObjPlayer *player, TPlyInventoryItem *record) {
    TItem *item = create_item(&record->m_data);
    if (item != NULL && player->pickup_item(item) != 0 && (record->m_flags & 8) &&
        TObjPlayer::get_slot_value(player->equipped_items.items, item->get_attach_slot()) == 0U) {
        set_equip_slot_entry((saddr)player->equipped_items.items, item->get_attach_slot(), (saddr)item);
        player->set_flag_20000();
        item->equip();
        player->clear_flag_20000();
    }
}
#pragma pop

void assign_inventory_item_ids(TObjPlayer *player, TPlyInventoryItem *records, s32 count) {
    s32 i;
    u16 client;
    if (records != NULL) {
        client = ((TObjBase *)(player))->get_entity_id();
        for (i = 0; i < count; i++) {
            records->m_data.id = advance_item_id_counter(client);
            ++records;
        }
    }
}

void rebuild_player_inventory(TObjPlayer *player) {
    if (player->inventory_objects != NULL) {
        InventoryItemList buffer;
        buffer.count = player->query_state_if_present(buffer.items);
        player->inventory_objects->destroy_subobjects(player);
        player->inventory_objects->queue_destruction();
        player->inventory_objects = NULL;
        player->create_inventory();
        assign_inventory_item_ids(player, buffer.items, buffer.count);
        TObjPlayer::bind_saved_inventory_equipment(player, buffer.items, buffer.count);
    }
}

s32 try_send_6x27_use_item(TObjPlayer *player, s32 key) {
    G_UseItem_6x27 cmd;
    TItem *temp;
    if (TFontSmallLobby::is_lobby_floor_15() != 0) {
        return 0;
    }
    TItemList *list = player->inventory_objects->start_inventory_update(key);
    if (list == NULL) {
        return 0;
    }
    temp = list->get_owner_if_alive();
    if (temp == NULL) {
        return 0;
    }
    if (player->can_use_item(temp) == 0) {
        play_sound_effect(0x3816, 0, 0, 0);
        return 0;
    }
    if ((player != NULL) && (player->obj_isState2_324() != 0)) {
        return 0;
    }
    cmd.init();
    cmd.header.client_id = player->get_entity_id();
    cmd.item_id = key;
    cmd.send();
    return 1;
}

void handle_6x27_use_item(G_UseItem_6x27 *command) {
    G_UseItem_6x27 pkt;
    TObjPlayer *player;
    TItem *owner_if_alive;
    TItemList *node;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x27_use_item(&pkt.header) != 0) {
        player = get_player_by_client_id((u16)pkt.header.client_id);
        if ((player != NULL) && ((node = player->inventory_objects->start_inventory_update(pkt.item_id)) != 0U)) {
            owner_if_alive = node->get_owner_if_alive();
            if (owner_if_alive != NULL) {
                owner_if_alive->use();
            }
        }
    }
}

void TWindowSubMag::feed_mag(void* p, void* a1, void* a2) { ((int (*)(void*))send_6x28_feed_mag)(p); ((int (*)(void*, void*, int))TObjPlayer::send_6x29_delete_item)(p, a2, 1); }

void send_6x28_feed_mag(TObjChara *chara, s32 mag_id, s32 fed_item_id) {
    G_FeedMag_6x28 cmd;
    if (chara == 0 || chara->obj_isState2_324() == 0) {
        cmd.init();
        cmd.header.client_id = chara->get_entity_id();
        cmd.mag_item_id = mag_id;
        cmd.fed_item_id = fed_item_id;
        cmd.send();
    }
}

void handle_6x28_feed_mag(G_FeedMag_6x28 *command) {
    G_FeedMag_6x28 cmd;
    TObjPlayer *p;
    TItem *a;
    TItem *b;
    TItemList *node;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6x28_feed_mag(&cmd.header) != 0) {
        p = get_player_by_client_id(cmd.header.client_id);
        if (p != NULL && (node = p->inventory_objects->start_inventory_update(cmd.mag_item_id)) != 0U) {
            a = node->get_owner_if_alive();
            if (a != 0 && (node = p->inventory_objects->start_inventory_update(cmd.fed_item_id)) != 0U) {
                b = node->get_owner_if_alive();
                if (b != 0) {
                    feed_item_to_mag(a, b);
                }
            }
        }
    }
}

s32 fn_801B7CEC(TObjPlayer *player, s8 kind, s8 group, s8 index) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = kind;
    item.data1.data_u8[1] = group;
    item.data1.data_u8[2] = index;
    TItemList *node_4144 = player->inventory_objects->set_mode_and_refresh_object(&item);
    if (node_4144 == 0U) {
        return -1;
    }
    TItem *owner = (TItem *)node_4144->get_owner_if_alive();
    if (owner == NULL) {
        return -1;
    }
    return owner->get_item_id();
}

s32 TObjPlayer::find_inventory_item_id(s8 kind, s8 group) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = kind;
    item.data1.data_u8[1] = group;
    TItemList *node = inventory_objects->find_first_inventory_entry(&item);
    if (node == 0U) {
        return -1;
    }
    TItem *owner = (TItem *)(node)->get_owner_if_alive();
    if (owner == NULL) {
        return -1;
    }
    return owner->get_item_id();
}

s32 TWindowSubItem::is_usable(TObjPlayer *player) {
    if ((player->is_action_active() != 0U) || (player->test_action_mask(0x43001E) == 0) || (player->test_actor_flags(0x20) != 0) || (player->check_player_flag1() != 0)) {
        return 0;
    }
    return 1;
}

s32 can_destroy_with_parents(TObject *obj) {
    if ((obj != NULL) && (obj->all_parents_unqueued_for_destruction() != 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::swap_inventory_items(s32 first_id, s32 second_id) {
    if (this->is_locally_controlled() == 0) {
        return;
    }
    if (first_id == -1 || second_id == -1) {
        return;
    }
    if (this->inventory_objects != NULL) {
        this->inventory_objects->swap_items(first_id, second_id);
    }
}

void handle_6x98(void) {  }

void TObjPlayer::close_sub_window() {
    TPlyItem *p;
    if (this->is_locally_controlled() != 0) {
        p = this->inventory_objects;
        if (p != 0) {
            p->sort_items();
        }
    }
}

void handle_6x99(void) {  }

CsnHit *TObjPlayer::update_actor_ground_y() {
    return update_actor_ground_y_at(get_position_ptr());
}

CsnHit *TObjPlayer::update_actor_ground_y_at(Vec *pos) {
    Vec stack;
    f32 y;
    s32 mask;
    CsnHit *hit;
    stack.x = pos->x;
    y = pos->y;
    stack.y = y + stat_block->proportions;
    stack.z = pos->z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x5F);
    if (hit == NULL) {
        return NULL;
    }
    contact_surface.clear_surface();
    mask = hit->hit_mask;
    if (mask & 0x10) {
        contact_surface.check_flag_2();
        follow_particles.set_grass_contact_point(&hit->contact[1].point);
    }
    if ((mask & 4) && (player_auxiliary_surfaces_enabled() != 0)) {
        contact_surface.set_flag_4();
        follow_particles.set_surface_contact_point(&hit->contact[2].point);
    }
    if ((mask & 2) && (player_auxiliary_surfaces_enabled() != 0)) {
        contact_surface.set_sand();
        follow_particles.set_surface_contact_point(&hit->contact[3].point);
    }
    if (mask & 8) {
        this->contact_surface.test_flag_16();
    }
    if (!(mask & 1)) {
        return NULL;
    }
    position.y = hit->contact[0].point.y;
    VecCopy(&ground_normal, &hit->contact[0].normal);
    return hit;
}

#pragma push
#pragma fp_contract on
#pragma scheduling off
void calc_wall_slide_point(const Vec *movement, const Vec *normal, Vec *out) {
    f32 component = -vec3_dot(movement, normal);
    out->x = component * normal->x + movement->x;
    out->y = component * normal->y + movement->y;
    out->z = component * normal->z + movement->z;
}
#pragma pop

void calc_move_velocity(const Vec *direction, Vec *out, f32 speed) {
    s32 angle = (s32)(10430.38043493439 * atan2_float(direction->x, direction->z));
    out->x = speed * sin_table_lookup(angle);
    out->y = player_zero;
    out->z = speed * cos_table_lookup(angle);
}

void calc_move(const Vec *movement, const Vec *direction, Vec *out) {
    calc_move_velocity(direction, out, vector_length(movement));
}

// Pushes the move in velocity off the walls it runs into: slides it along a
// wall it meets at a shallow angle, steps around a corner. Returns the wall
// contact that stops it, NULL when the move may go on.
CsnHit *TObjPlayer::apply_wall_response() {
    if (is_single_screen()) {
        s32 angle;
        f32 dx;
        f32 dz;
        f32 reach;
        f32 speed;
        Vec from;
        Vec to;
        angle = (s32)(10430.38043493439 * atan2_float(velocity.x, velocity.z));
        speed = vector_length(&velocity);
        reach = speed + get_body_radius(0);
        dx = reach * sin_table_lookup(angle);
        dz = reach * cos_table_lookup(angle);
        from.x = position.x;
        from.y = player_body_radius + position.y;
        from.z = position.z;
        to.x = from.x + dx;
        to.y = from.y;
        to.z = from.z + dz;
        return csnVector(&from, &to, 0x28A0);
    }

    s32 ray;
    s32 angle;
    Vec *normal;
    WallRayResult *blocked;
    Vec *offset;
    s32 i;
    f32 radius = get_body_radius(0);
    Vec move;
    WallRayQuery query;
    Vec rays[8];
    VecCopy(&move, &velocity);
    move.y = player_zero;
    Vec *origin = &query.origin;
    f32 reach = radius + vector_length(&move);
    query.count = 1;
    query.mask = 0x28A0;
    origin->x = position.x;
    origin->y = player_body_radius + position.y;
    origin->z = position.z;
    query.rays = rays;
    angle = (s32)(10430.38043493439 * atan2_float(move.x, move.z));
    rays[0].x = reach * sin_table_lookup(angle);
    rays[0].y = player_zero;
    rays[0].z = reach * cos_table_lookup(angle);
    query.radius = player_wall_probe_margin + reach;
    blocked = query_wall_radial(&query);
    Vec dir;
    if (blocked != NULL) {
        ray = blocked->index;
        normal = &blocked->header.contact[ray].normal;
        VecCopy(&dir, &move);
        normalize_vector_safe(&dir);
        if (vec3_dot(&dir, normal) > player_wall_facing_limit) {
            Vec end;
            Vec slide;
            Vec step;
            Vec *hit_ray = &query.rays[ray];
            end.x = origin->x + hit_ray->x;
            end.y = origin->y + hit_ray->y;
            end.z = origin->z + hit_ray->z;
            vsub(&blocked->header.contact->point, &end, &dir);
            calc_wall_slide_point(&dir, normal, &slide);
            vsub(origin, &move_target, &dir);
            dir.y = player_zero;
            calc_move(&dir, &slide, &step);
            move_target.x = position.x + step.x;
            move_target.z = position.z + step.z;
            calc_move(&velocity, &slide, &step);
            VecCopy(&velocity, &step);
            blocked = NULL;
        }
    }

    VecCopy(&move, &velocity);
    query.radius = radius;
    query.count = 8;
    origin->x = position.x + move.x;
    origin->z = position.z + move.z;
    offset = rays;
    for (i = 0; i < 8; i++) {
        offset->x = radius * sin_table_lookup(angle);
        offset->y = player_zero;
        offset->z = radius * cos_table_lookup(angle);
        angle += 0x2000;
        offset++;
    }
    WallRayResult *wall = query_prepared_wall_polygons(&query);
    if (wall != NULL) {
        ray = wall->index;
        normal = &wall->header.contact[ray].normal;
        VecCopy(&dir, &move);
        normalize_vector_safe(&dir);
        f32 facing = vec3_dot(&dir, normal);
        if (facing <= player_wall_facing_limit) {
            blocked = wall;
        } else if (facing > player_zero) {
            blocked = NULL;
        } else {
            f32 push = player_velocity_epsilon + wall->depth;
            Vec *wall_normal = &wall->header.contact[ray].normal;
            f32 px = wall_normal->x * push;
            f32 pz = wall_normal->z * push;
            Vec corner;
            corner.x = origin->x + px;
            corner.y = origin->y;
            corner.z = origin->z + pz;
            s32 target = calc_angle_to(&corner, &move_target);
            angle = lerp_angle_half(approach_angle_adaptive(rotation_y, target), target);
            move.x = move_speed.get_speed() * sin_table_lookup(angle);
            move.y = player_zero;
            move.z = move_speed.get_speed() * cos_table_lookup(angle);
            origin->x = corner.x + move.x;
            origin->z = corner.z + move.z;
            Vec first_ray;
            VecCopy(&first_ray, &query.rays[ray]);
            angle = (s32)(10430.38043493439 * atan2_float(move.x, move.z));
            offset = rays;
            for (i = 0; i < 8; i++) {
                offset->x = radius * sin_table_lookup(angle);
                offset->y = player_zero;
                offset->z = radius * cos_table_lookup(angle);
                angle += 0x2000;
                offset++;
            }
            WallRayResult *next = query_prepared_wall_polygons(&query);
            if (next == NULL) {
                blocked = NULL;
                position.x += px;
                position.z += pz;
            } else {
                Vec next_ray;
                VecCopy(&next_ray, &query.rays[next->index]);
                move.x = -velocity.z;
                move.z = velocity.x;
                f32 side = vec3_dot(&move, &first_ray);
                if (side * vec3_dot(&move, &next_ray) >= player_zero) {
                    blocked = NULL;
                    position.x += px;
                    position.z += pz;
                } else {
                    blocked = wall;
                }
            }
        }
    }
    return reinterpret_cast<CsnHit *>(blocked);
}

void TObjPlayer::get_hand_joint_position(Vec *out_pos) {
    this->get_anim_node_position(*(s32 *)(get_cast_motion_record() + 0x10), out_pos);
}

void TObjPlayer::init_effect_5f0() {
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(this->get_idle_animation());
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
}

void TObjPlayer::clear_lobby_flag(void *base) {
    if ((s32) lbl_805D55C0 == 0) {
        ((TObjBase *)base)->clear_actor_flags((u32)0x10000);
    }
}

void TObjPlayer::update_position_history() {
    s32 index;

    if ((this->prev_position.x != this->position.x) || (this->prev_position.z != this->position.z)) {
        index = this->movement_history.index + 1;
        this->movement_history.index = index;
        if (index >= 0x10) {
            this->movement_history.index = 0;
        }
        this->set_position_history_entry(this->movement_history.index, this->position.x, this->position.z);
    }
    VecCopy(&this->prev_position, &this->position);
    this->contact_surface.save_prev_flags();
}

void TObjPlayer::update_status_effects() {
  appear_fade.update();
  update_target_lock();
  if ((this->is_actor_cadence_frame(3)) != 0)
  {
    if (this->check_flag_02000000() == 0)
    {
      get_current_floor_area();
      this->room = TScene::find_player_section(this->get_entity_id());
    }
  }
  this->clear_flag_2000000();
  (this->vfunc_43());
  (this->update_poison_status());
  (this->update_action_hold_status());
  (this->update_slow_status());
  (this->update_flag30_timer());
  (this->update_movement_status());
  (this->update_shock_clock());
  (this->update_attack_stat_status());
  (this->update_defense_stat_status());
  if (this->protection.get_frames() <= 0)
  {
    this->clear_actor_flags((u32)(0x04000100));
  }
  else
  {
    TObjPlayer::decrement_clamp(&this->protection.frames, 1);
    set_actor_flags(0x04000000);
  }
  if ((this->hp) <= 0)
  {
    set_actor_flags(0xA00);
  }
  this->contact_surface.update_timer();
}

void TObjPlayer::check_level_up() {
    s32 i;
    TItem *removed_item;
    s32 j;
    s32 lvl;
    TItem *added_item;
    if ((this->is_locally_controlled() != 0) && (is_current_area_item_enabled() != 0)) {
        lvl = this->clamp_nested_index() + 1;
        if (lvl <= TObjPlayer::get_max_level()) {
            if (TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(this), lvl) <= (s32) this->stat_block->exp) {
                PlayerLevelStats before;
                PlayerLevelStats after;
                PlayerLevelStats gain;
                j = 0;
                do {
                    removed_item = (TItem *)TObjPlayer::get_slot_value(this->equipped_items.items, j);
                    if ((can_destroy_with_parents((TObject *)removed_item) != 0) && (removed_item->is_equipped() != 0)) {
                        removed_item->remove_equip_stats(1);
                    }
                    j += 1;
                } while (j < 0xD);
                before.set(this, this->stat_block, this->attack_params, param_block);
                this->apply_exp_level_growth();
                after.set(this, this->stat_block, this->attack_params, param_block);
                i = 0;
                do {
                    added_item = (TItem *)TObjPlayer::get_slot_value(this->equipped_items.items, i);
                    if ((can_destroy_with_parents((TObject *)added_item) != 0) && (added_item->is_equipped() != 0)) {
                        added_item->add_equip_stats(1);
                    }
                    i += 1;
                } while (i < 0xD);
                before.calc_delta(&after, &gain);
                TWindowCtrl::create_level_up_window((saddr)&gain, ((TObjBase *)this)->get_entity_id());
                this->send_6x30_change_player_level();
            }
        }
    }
}

s32 TObjPlayer::apply_exp_level_growth() {
    s32 i;
    s32 lvl;
    s32 cls;
    PlayerLevelTableRow *e;
    cls = this->get_class_index();
    lvl = clamp_nested_index() + 1;
    for (i = 0; i < TObjPlayer::get_max_level(); i++) {
        if (lvl > TObjPlayer::get_max_level()) {
            break;
        }
        e = get_ply_level_table_row(cls, lvl);
        if (e == NULL) {
            break;
        }
        if (e->get_exp_threshold() > stat_block->exp) {
            break;
        }
        add_stat(e->get_atp_growth());
        add_mst(e->get_mst_growth());
        add_evp(e->get_evp_growth());
        add_hp(e->get_hp_growth());
        add_dfp(e->get_dfp_growth());
        add_ata(e->get_ata_growth());
        stat_block->level = lvl;
        lvl++;
    }
    return 1;
}

void TObjPlayer::send_6x30_change_player_level() {
    G_ChangePlayerLevel_6x30 m;
    player_stats *stats;
    if ((this->reset_volopt_state() != 0) && ((this == NULL) || (this->obj_isState2_324() == 0))) {
        m.init();
        m.header.client_id = this->get_entity_id();
        stats = this->stat_block;
        m.atp = stats->stats.atp;
        m.mst = stats->stats.mst;
        m.evp = stats->stats.evp;
        m.hp = stats->stats.hp;
        m.dfp = stats->stats.dfp;
        m.ata = stats->stats.ata;
        m.level = this->clamp_nested_index();
        m.is_level_down = 0;
        m.send();
    }
}

void *TObjPlayer::copy_fields(void *command) {
    copy_subcommand_header(this, command);
    this->m_flags = (s16) *(s16 *)((s8 *)command + 4);
    this->m_id = (s16) *(s16 *)((s8 *)command + 6);
    *(s16 *)((s8 *)this + 8) = (s16) *(s16 *)((s8 *)command + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)command + 0xA);
    *(s16 *)((s8 *)this + 0xC) = (s16) *(s16 *)((s8 *)command + 0xC);
    *(s16 *)((s8 *)this + 0xE) = (s16) *(s16 *)((s8 *)command + 0xE);
    *(s16 *)((s8 *)this + 0x10) = (s16) *(s16 *)((s8 *)command + 0x10);
    *(s16 *)((s8 *)this + 0x12) = (s16) *(s16 *)((s8 *)command + 0x12);
    return this;
}

void handle_6x30_change_player_level(G_ChangePlayerLevel_6x30 *command) {
    G_ChangePlayerLevel_6x30 pkt;
    TObjPlayer *pl;
    f32 f;
    pkt.init();
    ((TObjPlayer *)(&pkt))->copy_fields(command);
    pkt.bswap();
    if (validate_6x30_change_player_level(&pkt) == 0) {
        return;
    }
    pl = (TObjPlayer *)get_player_by_client_id((u16)pkt.header.client_id);
    if (pl == NULL) {
        return;
    }
    if (pl->reset_volopt_state() == 0) {
        return;
    }
    pl->stat_block->stats.atp = pkt.atp;
    pl->stat_block->stats.mst = pkt.mst;
    pl->stat_block->stats.evp = pkt.evp;
    pl->stat_block->stats.hp = pkt.hp;
    pl->stat_block->stats.dfp = pkt.dfp;
    pl->stat_block->stats.ata = pkt.ata;
    pl->stat_block->level = pkt.level;
    f = pl->get_tp_class_factor();
    pl->recalc_combat_stats(pl->stat_block, NULL, NULL, (f32)(pl->get_class_hp_factor()), f);
    pl->hp = pl->hpmax;
    pl->tp = pl->tpmax;
    if (pl->is_alive_and_ready() != 0) {
        pl->refill_traps();
    }
    if (pl->check_flag_4() == 0) {
        if (pkt.is_level_down == 1) {
            pl->spawn_level_change_feedback("Level Down");
        } else {
            pl->spawn_level_change_feedback("Level Up");
        }
    }
}

void TObjPlayer::spawn_level_change_feedback(const char *message) {
    notify_volopt_if_ready();
    new TFontSmallHelp(get_entity_id(), -1, 0x3C, (uaddr)message);
    new_child_object(get_entity_id());
    scratch_vec.x = player_zero;
    scratch_vec.y = player_feedback_light_dir_y;
    scratch_vec.z = player_zero;
    player_feedback_light_color.r = player_feedback_light_color.a = player_one;
    player_feedback_light_color.g = player_feedback_light_green;
    player_feedback_light_color.b = player_feedback_light_blue;
    new TActorLight(player_feedback_light_step, &player_feedback_light_color, &scratch_vec, 10, this, tl_07);
    publish_actor_light_scalars(get_entity_id(), player_one, player_half);
}

void TObjPlayer::notify_volopt_if_ready() {
    if (is_locally_controlled() != 0) {
        play_sound_effect(0x51F1E, 0, 0, 0);
    }
}

#pragma push
#pragma scheduling off
void copy_stats(stats *out, const stats *source) {
    out->atp = source->atp;
    out->mst = source->mst;
    out->evp = source->evp;
    out->hp = source->hp;
    out->dfp = source->dfp;
    out->ata = source->ata;
    out->lck = source->lck;
}
#pragma pop

// Base stats of the class plus the growth of every level row up to `level`, each clamped to the class caps.
void apply_class_level_growth(s32 cls, s32 level, stats *st) {
    s32 n;
    s32 i;
    PlayerLevelTableRow *row;
    const player_stats *caps;

    n = TObjPlayer::clamp_index_to_max(level);
    copy_stats(st, get_class_base_stats(cls));
    row = get_ply_level_table_row(cls, 0);
    if (row != NULL) {
        caps = get_class_stat_caps(cls);
        for (i = 0; i < n; i++) {
            ++row;
            TObjPlayer::add_stat_clamped(row->get_atp_growth(), &st->atp, caps->stats.atp);
            TObjPlayer::add_stat_clamped(row->get_mst_growth(), &st->mst, caps->stats.mst);
            TObjPlayer::add_stat_clamped(row->get_evp_growth(), &st->evp, caps->stats.evp);
            TObjPlayer::add_stat_clamped(row->get_hp_growth(), &st->hp, caps->stats.hp);
            TObjPlayer::add_stat_clamped(row->get_dfp_growth(), &st->dfp, caps->stats.dfp);
            TObjPlayer::add_stat_clamped(row->get_ata_growth(), &st->ata, caps->stats.ata);
        }
    }
}

// Battle rule "level": rebuilds the stats as the class base plus the growth of every level row up to
// `level`, then puts back the equipment the new stats still allow (units last, and only over an armor).
void TObjPlayer::apply_battle_level_reset(s32 level) {
    level = clamp_index_to_max(level);

    EquippedItemSlot saved[9];
    s16 result;
    s32 i;

    EquippedItemSlot *e = saved;
    for (i = 0; i < 13; i++) {
        TItem *item = get_equipped_item(i);
        if (item != NULL) {
            e->slot = item->get_attach_slot();
            e->item = item;
            e++;
        }
    }
    inventory_objects->set_flag_and_update(this);
    s32 cls = get_class_index__10TObjPlayerFv(this);
    stats *base = get_class_base_stats(cls);
    stat_block->stats.atp = base->atp;
    stat_block->stats.mst = base->mst;
    stat_block->stats.evp = base->evp;
    stat_block->stats.hp = base->hp;
    stat_block->stats.dfp = base->dfp;
    stat_block->stats.ata = base->ata;
    stat_block->stats.lck = base->lck;
    PlayerLevelTableRow *row = get_ply_level_table_row(cls, 0);
    if (row != 0) {
        const player_stats *caps = get_class_stat_caps(cls);
        for (i = 0; i < level; i++) {
            ++row;
            add_stat_clamped(row->get_atp_growth(), &stat_block->stats.atp, caps->stats.atp);
            add_stat_clamped(row->get_mst_growth(), &stat_block->stats.mst, caps->stats.mst);
            add_stat_clamped(row->get_evp_growth(), &stat_block->stats.evp, caps->stats.evp);
            add_stat_clamped(row->get_hp_growth(), &stat_block->stats.hp, caps->stats.hp);
            add_stat_clamped(row->get_dfp_growth(), &stat_block->stats.dfp, caps->stats.dfp);
            add_stat_clamped(row->get_ata_growth(), &stat_block->stats.ata, caps->stats.ata);
        }
    }
    stat_block->level = level;
    stat_block->esp = 40;
    stat_block->exp = get_current_state_field(cls, level);
    stat_block->meseta = 300;
    f32 tp_factor = get_tp_class_factor();
    recalc_combat_stats(NULL, NULL, NULL, get_class_hp_factor(), tp_factor);
    hp = hpmax;
    tp = tpmax;
    set_flag_20000();
    EquippedItemSlot *p = saved;
    for (s32 i = 0; i < 9; i++, p++) {
        TItem *item = p->item;
        if (item == NULL) {
            break;
        }
        if (!item->is_unit() && item->check_equip_requirements(this, &result)) {
            equip_item_to_slot(item, p->slot);
        }
    }
    EquippedItemSlot *q = saved;
    for (s32 i = 0; i < 9; i++, q++) {
        TItem *item = q->item;
        if (item == NULL) {
            break;
        }
        if (item->is_unit() && item->check_equip_requirements(this, &result) && this->get_equipped_armor() != NULL) {
            equip_item_to_slot(item, q->slot);
        }
    }
    clear_flag_20000();
}

void TObjPlayer::update_aim_angle(s32 aim) {
    s32 class_state_field;

    class_state_field = this->get_class_state_field(TObjPlayer::clamp_index_to_max(aim + get_actor_level_index()));
    add_actor_exp(class_state_field - this->obj_getPtr2B0_1C());
}

void TObjPlayer::recalc_stats() {
    f32 tp_class_factor;
    f32 xscale;

    tp_class_factor = this->get_tp_class_factor();
    xscale = this->get_class_hp_factor();
    this->recalc_combat_stats(NULL, NULL, NULL, xscale, tp_class_factor);
    this->clamp_hp();
    this->clamp_tp();
}

s16 TObjPlayer::add_stat(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.atp, get_class_stat_entry()->stats.atp);
}

s16 TObjPlayer::add_dfp(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.dfp, get_class_stat_entry()->stats.dfp);
}

s16 TObjPlayer::add_hp(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.hp, get_class_stat_entry()->stats.hp);
}

s16 TObjPlayer::add_mst(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.mst, get_class_stat_entry()->stats.mst);
}

s16 TObjPlayer::add_ata(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.ata, get_class_stat_entry()->stats.ata);
}

s16 TObjPlayer::add_evp(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.evp, get_class_stat_entry()->stats.evp);
}

s16 TObjPlayer::add_lck(s32 amount) {
    return add_stat_clamped(amount, &this->stat_block->stats.lck, get_class_stat_entry()->stats.lck);
}

s16 TObjPlayer::add_stat_clamped(s32 amount, s16 *stat, s16 max) {
    s16 value;
    s16 excess;

    excess = 0;
    *stat += amount;
    value = *stat;
    if (value < 0) {
        *stat = 0;
    } else {
        excess = value - max;
        if (excess > 0) {
            *stat = max;
        }
    }
    return excess;
}

void handle_6x2E_set_or_clear_player_flags(G_SetOrClearPlayerFlags_6x2E *command) {
    G_SetOrClearPlayerFlags_6x2E m;
    TObjPlayer *p;
    m.init();
    m = *command;
    m.bswap();
    if (validate_6x2E_set_or_clear_player_flags(&m.header) != 0) {
        p = (TObjPlayer *)get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            p->actorFlags = p->actorFlags & m.and_mask;
            p->actorFlags = p->actorFlags | m.or_mask;
        }
    }
}

s32 TObjPlayer::is_matching_id(s16 action) {
    if ((this->is_flag_b0_4() != 0) && (action == (s16) this->previous_action)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::rewind_position_history() {
    Vec pos;
    s32 index;
    CsnHit *hit;
    index = this->movement_history.index - 1;
    this->movement_history.index = index;
    if (index < 0) {
        this->movement_history.index = 0xF;
    }
    get_position_history_entry(this->movement_history.index, &pos.x, &pos.z);
    pos.y = this->position.y;
    hit = csnVectorUnder(&pos, this->ground_candidates.groups, 0x41);
    if (hit != NULL) {
        this->position.x = hit->contact->point.x;
        this->position.y = hit->contact->point.y;
        this->position.z = hit->contact->point.z;
    }
}

void TObjPlayer::damp_planar_velocity() {
    if (this->velocity.x < player_velocity_epsilon && this->velocity.x > player_velocity_neg_epsilon) {
        this->velocity.x = player_zero;
    } else {
        this->velocity.x *= player_half;
    }
    if (this->velocity.z < player_velocity_epsilon && this->velocity.z > player_velocity_neg_epsilon) {
        this->velocity.z = player_zero;
    } else {
        this->velocity.z *= player_half;
    }
}

saddr TObjPlayer::resolve_move_collision() {
    Vec p;
    p.x = position.x + velocity.x;
    p.y = position.y + velocity.y;
    p.z = position.z + velocity.z;
    if (this->update_actor_ground_y_at(&p) == 0U) {
        clear_velocity();
        return 1;
    }
    if (apply_wall_response() != 0U) {
        clear_velocity();
        return 2;
    }
    if ((has_body_flags(this, 0, 0x380000) != 0) && (has_body_flags(this, 0, 0x01C00000) != 0)) {
        clear_velocity();
        return 4;
    }
    if (is_outside_movement_hold(&p.x) != 0) {
        clear_velocity();
        return 3;
    }
    return 0;
}

s32 TObjPlayer::check_actor_blocking_move() {
    Vec pos;
    Vec diff;
    CollisionBody hit;
    pos.x = position.x + velocity.x;
    pos.y = player_zero;
    pos.z = position.z + velocity.z;
    if (test_player_overlap_with_players(this, this, &pos, &hit) != 0) {
        if (hit.flags & 0x100) {
            return 0;
        }
        diff.x = pos.x - hit.center.x;
        diff.y = player_zero;
        diff.z = pos.z - hit.center.z;
        if (vec3_dot(&diff, &velocity) < player_zero) {
            return 1;
        }
    }
    return 0;
}

void TObjPlayer::update_ground_contact() {
    if (this->is_locally_controlled() != 0) {
        if (pad_binding.is_button_held(get_control_button_mask(this->get_entity_id())) != 0) {
            action_palettes.set_primary_bank();
            if (this->photon_blast_gauge.has_ready_flag() != 0) {
                action_palettes.set_secondary_bank();
            }
        } else {
            action_palettes.clear_primary_bank();
            if (this->photon_blast_gauge.has_ready_flag() != 0) {
                action_palettes.clear_secondary_bank();
            }
        }
        refresh_party_cursors();
    }
}

void TObjPlayer::select_contextual_pickup_action() {
    s32 type;
    CursorTarget *cursor;
    saddr ent;
    TLockOnCursor *obj;
    obj = this->lock_on_cursor;
    if (obj != NULL) {
        cursor = &obj->selection.target;
        type = 0;
        if (cursor->get_entity_id() != 0xFFFF) {
            ent = ((s32 (*)(u16))find_entity_by_id)(cursor->get_entity_id());
            if (ent != 0) {
                type = ((TObjCollidable *)ent)->get_cursor_action();
                if (type != 0) {
                    switch (type) {
                    case 4:
                        if (test_action_mask(0xE0) != 0) {
                            type = 0;
                        } else {
                            TItem *item = (TItem *)find_entity_by_id(cursor->get_entity_id());
                            if (this->can_pickup_item_by_id(item) != 0) {
                                if ((is_action_input_disabled()) != 0) {
                                    enable_palette_slot(1);
                                }
                            } else {
                                type = 0;
                                if (is_controls_locked() == 0 && pad_binding.is_button_pressed(4) != 0) {
                                    play_sound_effect(0x3816, ((TObjPlayer *)ent)->get_position_ptr(), 0, 1);
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (type == 0 && (is_action_input_disabled()) != 0) {
            type = 2;
        }
        ((void (*)(void *, s32, s32, s32, u16))set_selected_palette_tag_slot)(this, 0, 0, 0, type);
        ((void (*)(void *, s32, s32, s32, u16))set_selected_palette_tag_slot)(this, 0, 1, 0, type);
    }
}

TPlyDispConfigSmth *TObjPlayer::refresh_effect() {
    if (this->photon_blast_gauge.has_ready_flag() != 0) {
        if (action_palettes.test_photon_blast_modifier() != 0) {
            return action_palettes.ref_primary_palette();
        }
        return action_palettes.ref_secondary_palette();
    }
    return action_palettes.ref_primary_palette();
}

TPlyDispConfigSmth *TObjPlayer::select_action_palette(int secondary) {
    if (secondary == 1) {
        return action_palettes.ref_secondary_palette();
    }
    return action_palettes.ref_primary_palette();
}

#pragma push
#pragma fp_contract on
void get_action_palette_mode(TObjPlayer *player, s32 index) {
    player->refresh_effect()->get_current_tag_mode(index);
}
#pragma pop
#pragma push
#pragma fp_contract on
u16 TObjPlayer::get_action_palette_entry(s32 index) {
    return this->refresh_effect()->get_current_tag_slot(index);
}
#pragma pop

#pragma push
#pragma scheduling off
u16 TObjPlayer::select_action_palette_and_apply(s32 secondary, s32 row, s32 index) {
    return this->select_action_palette(secondary)->get_tag_slot(row, index);
}
#pragma pop

#pragma push
#pragma scheduling off
void set_selected_palette_tag_slot(TObjPlayer *player, s32 secondary, s32 i, s32 action, s32 param) {
    player->select_action_palette(secondary)->set_tag_slot(i, action, param);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::set_action_palette_entry(s32 secondary, s32 valid, s32 idx, s32 mode, u16 slot) {
    this->select_action_palette(secondary)->set_tag(valid, idx, mode, slot);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::refresh_party_cursors() {
    TObjPlayer::update_party_cursors(refresh_effect(), this);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_effect_channel_active(TObjPlayer *player, s32 index) {
    return player->refresh_effect()->is_channel_active(index);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_action_channel_available(s32 channel) {
    if (channel == 1) {
        if (is_action_input_disabled() != 0) {
            return 1;
        }
        if (this->has_action_palette_entry() != 0) {
            return 1;
        }
    }
    return this->refresh_effect()->is_channel_active(channel);
}
#pragma pop

s32 TObjPlayer::has_action_palette_entry() {
    if ((this->lock_on_cursor != NULL) && (((u16)get_action_palette_entry(0)) != 0)) {
        return 1;
    }
    return 0;
}

s32 TObjPlayer::is_quest_interaction_blocked() {
    if (this->lock_on_cursor == NULL) {
        return 0;
    }
    switch ((u16) get_action_palette_entry(0)) {
    case 0:
    case 2:
        return 0;
    case 1:
    default:
        return 0;
    }
}

LockOnActionSlot *TObjPlayer::find_palette_lockon_slot() {
    s32 i;
    saddr cursor;
    if (lock_on_cursor == NULL) {
        return NULL;
    }
    cursor = (saddr)lock_on_cursor->action_slots;
    for (i = 0; i < 4; i++) {
        if (is_active_channel_matching(cursor, action_palette_state.get_mode(),
                action_palette_state.get_slot()) != 0) {
            return (LockOnActionSlot *)cursor;
        }
        cursor += 0x124;
    }
    return NULL;
}

void TObjPlayer::action_enable_if_present() { void* m = this->lock_on_cursor; if (m) ((TObjPlayer *)m)->clear_flag_1_at_1c(); }

void TObjPlayer::release_attached_resource() { void* m = this->lock_on_cursor; if (m) ((TObjPlayer *)m)->set_flags_bit1(); }

s32 TObjPlayer::get_camera_field() {
    TLockOnCursor *p = this->lock_on_cursor;
    if (p != 0) {
        return p->is_cursor_clear();
    }
    return 0;
}

void TObjPlayer::reset_equip_slots() { pad_binding.disable_buttons(0x406); disable_palette_slot(0); disable_palette_slot(1); disable_palette_slot(2); disable_palette_slot(3); this->set_state_flags(256); }

void TObjPlayer::init_parts() { pad_binding.enable_buttons(0x406); enable_all_palette_slots(); this->clear_state_flags(256); }

s32 TObjPlayer::is_controls_locked() { return check_flag(256); }

int TObjPlayer::has_valid_handle() { return ((TObjPlayer *)this->action_provider)->is_handle_valid(); }

void TObjPlayer::select_class_action_provider() {
  s8 class_index;
  class_index = this->get_class_index();
  {
    switch (class_index)
    {
      case 0:
      case 2:
      case 3:
      case 4:
      case 7:
        action_provider->set_body_type(0);
        return;
      case 1:
      case 5:
      case 8:
        action_provider->set_body_type(1);
        return;
      case 6:
        action_provider->set_body_type(2);
        return;
      case 9:
        action_provider->set_body_type(4);
        return;
      case 10:
        action_provider->set_body_type(3);
        return;
      case 11:
        action_provider->set_body_type(5);
        break;
    }
  }
}

void TObjPlayer::apply_input_mode() {
    s32 class_flags;

    class_flags = get_class_flags();
    if (class_flags & CLASS_FLAG_HUNTER) {
        this->set_input_mode(0);
        return;
    }
    if (class_flags & CLASS_FLAG_RANGER) {
        this->set_input_mode(1);
        return;
    }
    this->set_input_mode(2);
}

void TObjPlayer::set_move_mode_from_class_flags() {
    s32 class_flags;

    class_flags = this->get_class_flags();
    if (class_flags & CLASS_FLAG_ANDROID) {
        this->set_move_mode(2);
        return;
    }
    if (class_flags & CLASS_FLAG_NEWMAN) {
        this->set_move_mode(1);
        return;
    }
    this->set_move_mode(0);
}

s32 TObjPlayer::get_clamped_index() {
    s32 index;

    index = this->input_mode;
    if ((index < 0) || (index >= 3)) {
        return 0;
    }
    return index;
}


void TObjPlayer::init_trait_flags() {
    this->target_attribute_mask = 0;
    if (get_class_flags() & CLASS_FLAG_ANDROID) {
        this->add_flags_2e4(4);
    } else {
        this->add_flags_2e4(1);
    }
    if (get_class_flags() & CLASS_FLAG_RANGER) {
        this->add_flags_2e4(0x20);
    }
}

void send_impose_hold(TObjPlayer *player, int frames) {
    ((s32 (*)(TObjPlayer *, Vec *, s32, s32, f32))send_6x2C_impose_hold)(player, player->get_position_ptr(), frames, 0, player_zero);
}


void TObjPlayer::play_effect(TObjPlayer *player, s32 effect_id, s32 mode) {
    send_6x2C_impose_hold(player, player->get_position_ptr(), effect_id, mode, player_zero);
}

void send_6x2C_impose_hold(TObjPlayer *player, Vec *pos, s32 frames, s32 mode, f32 radius) {
    G_ImposeHold_6x2C pkt;
    if (player == NULL || player->obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = player->get_entity_id();
        pkt.effect_type = mode;
        pkt.frames = frames;
        pkt.pos.x = pos->x;
        pkt.pos.z = pos->z;
        pkt.trigger_radius2 = radius * radius;
        pkt.send();
    }
}

void handle_6x2C_impose_hold(G_ImposeHold_6x2C *command) {
    G_ImposeHold_6x2C pkt;
    TObjPlayer * player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x2C_impose_hold(&pkt) == 0) {
        return;
    }
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == 0) {
        return;
    }
    player->movement_hold.set_effect_type(pkt.effect_type);
    player->movement_hold.set_frames(pkt.frames);
    player->movement_hold.set_center(pkt.pos.x, pkt.pos.z);
    player->movement_hold.set_radius_sq(pkt.trigger_radius2);
    player->set_state_flags(1);
    if (player->check_flag_4() == 0 && player->is_on_current_floor() != 0) {
        TObjEneHoldEffect::create(player, pkt.effect_type, pkt.frames);
    }
}

void send_release_hold(TObjPlayer *player) {
    G_ReleaseHold_6x2D pkt;

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = player->get_entity_id();
        pkt.send();
    }
}


G_ReleaseHold_6x2D &G_ReleaseHold_6x2D::operator=(G_ReleaseHold_6x2D &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x2D_release_hold(G_ReleaseHold_6x2D *command) {
    G_ReleaseHold_6x2D pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x2D_release_hold(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_state_flags(1);
        }
    }
}


#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_outside_movement_hold(f32 *pos) {
    f32 *center;
    f32 x, y, z;
    f32 dx, dz;
    if (check_player_flag1() == 0) {
        return 0;
    }
    center = movement_hold.get_center();
    x = center[0];
    y = pos[0];
    z = center[1];
    dx = x - y;
    dz = z - pos[2];
    return (u32)__cntlzw(movement_hold.get_radius_sq() > (dx * dx + dz * dz)) >> 5;
}
#pragma pop

PlayerSyncRecord::PlayerSyncRecord() {
    s32 i;
    client_id = 0xFFFF;
    room_id = 0;
    game_flags = 0;
    position.x = position.y = position.z = player_zero;
    angle[0] = angle[1] = angle[2] = 0;
    phase = 0;
    current_hp = 0;
    hp_material_bonus = 0;
    tp_material_bonus = 0;
    language = 0;
    area = 0;
    floor = 0;
    player_flags = 0;
    for (i = 0; i < 0x13; i++) {
        technique_levels[i] = TObjPlayer::get_item_count_max();
    }
}

void TObjPlayer::fill_player_record(PlayerSyncRecord *record) {
    s32 j;
    s32 i;
    s16 saved_hp;
    s16 saved_tp;
    u32 flags;
    record->client_id = get_entity_id();
    record->room_id = alt_room;
    record->game_flags = actorFlags & ~0x02000000;
    VecCopy(&record->position, &position);
    copy_xyz(record->angle, &rotation_x);
    record->phase = mode;
    record->current_hp = hp;
    for (i = 0; i < 5; i++) {
        record->status_effects[i] = status_effects[i];
    }
    ((TLobby *)&record->guild_card_tag)->copy_header_struct(&guild_card_tag);
    record->pk_state = pk_state;
    record->telepipe = telepipe;
    record->death_flags = death_flags;
    record->hold_state = movement_hold;
    record->area = get_area();
    record->floor = get_floor();
    record->player_flags = state_flags;
    record->language = get_language();
    copy_player_visual_record(&record->visual, name);
    record->inventory.count = inventory_objects->run_state_query(record->inventory.items);
    saved_hp = get_actor_hp();
    saved_tp = get_actor_tp();
    for (i = 0; i != 0xD; i++) {
        TItem *item = get_equipped_item(i);
        if (item != NULL) {
            item->remove_equip_stats(1);
        }
    }
    record->stats = *stat_block;
    record->hp_material_bonus = get_hp_bonus();
    record->tp_material_bonus = get_tp_bonus();
    record->set_power_materials_used(get_power_materials_used());
    record->set_mind_materials_used(get_mind_materials_used());
    record->set_evade_materials_used(get_evade_materials_used());
    record->set_def_materials_used(get_def_materials_used());
    record->set_luck_materials_used(get_luck_materials_used());
    for (i = 0; i < 0x13; i++) {
        TObjPlayer::split_capped_value(technique_state.get_learned_level(i), &record->technique_levels[i],
                                       (u8 *)&record->inventory.items[i].m_present[2]);
    }
    for (j = 0; j != 0xD; j++) {
        TItem *item = get_equipped_item(j);
        if (item != NULL) {
            item->add_equip_stats(1);
        }
    }
    set_hp_clamped(saved_hp);
    set_tp(saved_tp);
    encode_player_record_inventory(record);
    flags = pending_actions.get_bits();
    record->inventory.items[0].m_present[3] = flags;
    record->inventory.items[1].m_present[3] = (u8)(flags >> 8);
    record->inventory.items[2].m_present[3] = (u8)(flags >> 16);
    record->inventory.items[3].m_present[3] = (u8)(flags >> 24);
    record->set_class_flag_0(get_mag_level());
    record->set_class_flag_1(get_byte_339());
    record->set_class_flag_2(get_battle_mode());
    TLobby::bswap_player_data(record);
}

s32 TObjPlayer::get_battle_ctrl_flag(u16 id) {
    TObjPlayer *player;

    player = get_player_by_client_id(id);
    if ((player != NULL) && (player->is_on_current_floor() != 0)) {
        return (saddr)player;
    }
    return 0;
}

void TObjPlayer::apply_material_color_override() {
    if (!(this->render_material_state.get_alpha() >= player_one)) {
        set_default_alpha_blend();
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material(&this->render_material_state.fade_color);
    }
}

void TObjPlayer::clear_action_flag() {
    if ((is_count_positive(&this->inventory_objects->list.count) == 0) && (this->is_action_active() != 0U)) {
        this->clear_flag_0x2();
        send_release_hold(this);
    }
}

void TObjPlayer::update_facing_vector() {
    facing.x = sin_table_lookup(rotation_y);
    facing.y = player_zero;
    facing.z = cos_table_lookup(rotation_y);
    update_ground_contact();
    if (this->lock_on_cursor != NULL) {
        this->lock_on_cursor->reset_slots();
    }
    this->contact_surface.check_surface_exit();
}

void submit_target_to_player_cursor(void *target, s32 id) {
    s32 i;
    TObjPlayer *player;
    LockOnActionSlot *entry;
    if (target == NULL || (u16)id == 0xFFFF || (u16)id >= 0x1000) {
        return;
    }
    player = (TObjPlayer *)get_player_by_client_id((u16)id);
    if (player != NULL && player->lock_on_cursor != NULL) {
        for (i = 0; i < 4; i++) {
            entry = &player->lock_on_cursor->action_slots[i];
            if (((TMainCursor *)entry)->get_selected_entry() != 0) {
                TMainCursor::try_add_target_candidate(entry, target, player, &player->lock_on_cursor->nearest_target);
            }
        }
    }
}

void submit_cursor_candidate(void *self, s32) {
    s32 j;
    s32 i;
    TObjPlayer *o;
    TObjPlayer **pp;
    if (self != 0) {
        pp = player_slot_table;
        for (i = 0; i < 4; i++) {
            o = *pp++;
            if (o != 0 && o->lock_on_cursor != 0) {
                for (j = 0; j < 4; j++) {
                    LockOnActionSlot *c = &o->lock_on_cursor->action_slots[j];
                    if (((TMainCursor *)c)->get_selected_entry() != 0) {
                        TMainCursor::try_add_target_candidate(c, self, o, &o->lock_on_cursor->nearest_target);
                    }
                }
            }
        }
    }
}

u16 TObjPlayer::get_battle_ctrl_id(u16 client) {
    TLockOnCursor *cursor;
    TObjPlayer *player;

    player = (TObjPlayer *)get_player_by_client_id(client);
    if (player == NULL) {
        return 0xFFFF;
    }
    cursor = player->lock_on_cursor;
    if (cursor == NULL) {
        return 0xFFFF;
    }
    return cursor->selection.target.get_entity_id();
}

void TObjPlayer::update_subsystems() {
    if (this->is_locally_controlled() != 0) {
        this->check_level_up();
        sync_status_effect_flags();
        clear_action_flag();
        this->update_target();
        if ((this->check_player_flag1() != 0) && (this->movement_hold.get_frames() >= 0) && (this->movement_hold.count_down() == 0)) {
            send_release_hold(this);
        }
        this->battle_music.update_target_lock(this);
        if (scale_state.is_scaled() != 0) {
            scale_state.update_camera();
        }
    }
}

s32 TObjPlayer::is_target_valid() {
    if (this->lock_on_cursor == NULL) {
        return 0;
    }
    if (((u16) this->interactor != 0xFFFF) || (is_controls_locked() != 0) || (this->lock_on_cursor->is_cursor_clear() == 0) || (this->check_flag_0x40000000() != 0) || (test_action_mask(0x1E) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_target() {
    u16 current_target_id;

    current_target_id = TObjPlayer::get_current_target_id();
    if ((current_target_id == 0xFFFF) || (current_target_id == this->get_entity_id())) {
        this->photon_blast_gauge.reset_targets();
        return;
    }
    this->photon_blast_gauge.decrement_donation_state();
    if (this->can_use_action() != 0) {
        this->photon_blast_gauge.draw_party_label(this, current_target_id);
    }
}

void TObjPlayer::play_photon_blast_feedback() { ((TObjPlayer *)&this->follow_particles)->emit_photon_blast_feedback_from_packet(); this->play_sound_if_on_floor(142625); }

s32 TObjPlayer::can_use_action() {
    if (pad_binding.is_button_pressed(0x200) == 0) {
        return 0;
    }
    if (is_controls_locked() != 0) {
        return 0;
    }
    if (this->test_action_mask(0x200) != 0) {
        return 0;
    }
    return this->photon_blast_gauge.is_ready() != 0 ? 1 : 0;
}

s32 TObjPlayer::get_recovery_need_flags() {
    s32 flags;
    flags = 0;
    if ((s16) this->hp < (s16) this->hpmax) {
        flags |= 1;
    }
    if (this->tp < this->tpmax) {
        flags |= 2;
    }
    if (test_actor_flags(0x3F) != 0) {
        flags |= 4;
    }
    switch (this->get_status_effect_type(2)) {
    case 0xB:
        flags |= 4;
        break;
    }
    switch (this->get_status_effect_type(3)) {
    case 0xC:
        flags |= 4;
        break;
    }
    return flags;
}

void TObjPlayer::send_use_medical_center() {
    G_UseMedicalCenter_6x31 pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_UseMedicalCenter_6x31 &G_UseMedicalCenter_6x31::operator=(G_UseMedicalCenter_6x31 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x31_use_medical_center(G_UseMedicalCenter_6x31 *command) {
    G_UseMedicalCenter_6x31 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x31_use_medical_center(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            p->recover_full();
        }
    }
}


void TObjPlayer::recover_full() {
    this->restore_hp_and_tp();
    this->clear_all_status_effects();
    this->clear_actor_flags(0xE00);
    this->clear_state_flags(1);
}

void TObjPlayer::send_medical_center_revive_all_players() {
    G_MedicalCenterReviveAllPlayers_6x32 pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.unused = get_entity_id();
        pkt.send();
    }
}

void handle_6x32_medical_center_revive_all_players(void) {
    s32 i;
    TObjPlayer *p;
    TObjPlayer **pp = player_slot_table;
    for (i = 0; i < 4; i++, pp++) {
        p = *pp;
        if (p != NULL && p->obj_isState3_324() != 0) {
            p->recover_full();
        }
    }
}

void TObjPlayer::send_6xA1_player_id() {
    G_RevivePlayer_V3_BB_6xA1 pkt;

    if ((this == NULL) || (this->obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_RevivePlayer_V3_BB_6xA1 &G_RevivePlayer_V3_BB_6xA1::operator=(G_RevivePlayer_V3_BB_6xA1 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6xA1_revive_player_v3(G_RevivePlayer_V3_BB_6xA1 *command) {
    G_RevivePlayer_V3_BB_6xA1 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6xA1_revive_player_v3(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->revive();
        }
    }
}


void TObjPlayer::revive() {
    update_rotation();
    clear_all_status_effects();
    clear_actor_flags((u32)0xE00);
    clear_state_flags(1);
}

void TObjPlayer::update_rotation() {
    if ((TObjPlayer::check_camera_mode() == 0) && (this->reset_volopt_state() != 0) && (TTecCtrl::is_technique_ready() == 0) && (obj_isState3_324() == 0)) {
        set_hp_clamped((s16) ((s16) this->hpmax / 2));
        return;
    }
    set_hp_clamped(this->hpmax);
    set_tp(this->tpmax);
}

void TObjPlayer::play_footstep_sound(f32 first_frame, f32 second_frame) {
    if (test_ordered_anim_markers(first_frame, second_frame) != 0) {
        this->play_sound_if_on_floor(this->get_footstep_floor_index());
    }
}

void TObjPlayer::emit_footstep_effect(f32 first_frame, f32 second_frame) {
    s32 marker;
    s32 contact_surface_type;
    if ((this->is_body_collision_inactive() == 0) && (marker = ((s32)test_ordered_anim_markers(first_frame, second_frame)), ((marker == 0) == 0))) {
        contact_surface_type = this->contact_surface.get_contact_surface_type();
        switch (contact_surface_type) {
        case 1:
            emit_grass_footstep_effect(&this->follow_particles);
            return;
        case 2:
            emit_water_footstep_effect(&this->follow_particles);
            return;
        case 3:
            emit_sand_footstep_effect(&this->follow_particles);
            return;
        case 4:
            this->update_foot_stamp(marker);
            return;
        case 0:
            if (this->contact_surface.is_timer_running() != 0) {
                this->update_foot_stamp(marker);
            }
            break;
        }
    }
}

// 1 when the motion passes first_frame, 2 when it passes second_frame.
s32 TObjPlayer::test_ordered_anim_markers(f32 first_frame, f32 second_frame) {
    if (is_passing_frame(first_frame) != 0) {
        return 1;
    }
    return (is_passing_frame(second_frame) != 0) ? 2 : 0;
}

void TObjPlayer::update_foot_stamp(int marker) {
    if (marker == 1) {
        TObjPlayer::clear_foot_stamp((saddr)&this->follow_particles, (saddr)this);
    } else if (marker == 2) {
        TObjPlayer::enable_foot_stamp((saddr)&this->follow_particles, (saddr)this);
    }
}

s32 TObjPlayer::classify_action_state() {
    s8 class_index;

    class_index = this->get_class_index();
    switch (class_index) {
    case 5:
    case 9:
    case 2:
        return 1;
    case 4:
        return 2;
    default:
        return 0;
    }
}

void TObjPlayer::hold_battle_music() { battle_music.set_flag_2(); }

void TObjPlayer::release_battle_music() { battle_music.clear_flag0_bit1(); }

void TObjPlayer::start_battle_music() { battle_music.clear_target_lock(); }

void TObjPlayer::stop_battle_music() { battle_music.reset_ring(); }

s32 TObjPlayer::execute_palette_action(s32 mode, void *target) {
    s16 kind;
    s16 act;
    kind = ((s32 (*)(void *, s32))get_action_palette_mode)(this, mode);
    act = get_action_palette_entry(mode);
    action_palette_state.set_mode(kind);
    action_palette_state.set_slot(act);
    switch (kind) {
    case 0:
        return 0;
    case 1:
        if (target == NULL) {
            return 0;
        }
        if (is_target_valid() != 0) {
            ((TObjCollidable *)target)->interact(this->get_entity_id());
            return 1;
        }
        break;
    case 2:
        this->attack_state.set_attack_kind(act);
        if (this->check_mode_action(act) != 0) {
            if (pad_binding.get_stick_magnitude() >= player_stick_deadzone) {
                this->rotation_y = calc_scaled_value(pad_binding.get_stick_angle());
            }
            run_action_state_phase(5, 5);
            return 1;
        }
        break;
    case 3:
        if (this->try_camera_action((s32)act) != 0) {
            technique_state.set_technique_id(act);
            run_action_state_phase(8, 5);
            return 1;
        }
        break;
    case 4:
        if (can_use_camera_field() != 0 && dispatch_palette_action(act) != 0) {
            return 1;
        }
        break;
    case 5:
        if (check_conditions(act) != 0) {
            this->photon_blast_gauge.set_blast(act);
            run_action_state_phase(9, 5);
            return 1;
        }
        break;
    case 6:
        if (TObjPlayer::is_player_valid_target(this->get_entity_id()) != 0) {
            run_palettex_callback(this->get_entity_id());
        }
        break;
    default:
        return 0;
    }
    return 0;
}

s32 TObjPlayer::handle_palette_button_input() {
    if (pad_binding.is_button_pressed(4) != 0 && is_palette_slot_enabled(1) != 0) {
        s32 mode;
        void *target;
        if (has_action_palette_entry() != 0) {
            target = find_entity_by_id(this->lock_on_cursor->selection.target.get_entity_id());
            mode = 0;
        } else {
            target = 0;
            mode = 1;
        }
        if (execute_palette_action(mode, target) != 0) {
            TWindowCtrl::dispatch_to_child(this->get_entity_id(), 1);
            return 1;
        }
    } else if (pad_binding.is_button_pressed(0x400) != 0 && is_palette_slot_enabled(2) != 0) {
        if (is_palettex_activated(this->get_entity_id()) != 0 && this->action_palettes.is_primary_first_bank() != 0) {
            if (TObjPlayer::is_player_valid_target(this->get_entity_id()) != 0) {
                run_palettex_callback(this->get_entity_id());
            }
        } else if (this->execute_palette_action(2, 0) != 0) {
            TWindowCtrl::dispatch_to_child(this->get_entity_id(), 2);
            return 1;
        }
    } else if (pad_binding.is_button_pressed(2) != 0 && is_palette_slot_enabled(3) != 0 &&
               this->execute_palette_action(3, 0) != 0) {
        TWindowCtrl::dispatch_to_child(this->get_entity_id(), 3);
        return 1;
    }
    return 0;
}

void TObjPlayer::disable_palette_slot(s32 slot) { action_palette_state.disable_slot(slot); }

void TObjPlayer::enable_palette_slot(s32 slot) { action_palette_state.enable_slot(slot); }

void TObjPlayer::enable_all_palette_slots() { action_palette_state.enable_all_slots(); }

s32 TObjPlayer::is_palette_slot_enabled(s32 slot) { return action_palette_state.is_slot_enabled(slot); }

s32 TObjPlayer::dispatch_palette_action(u32 act) {
    switch (act) {
    case 0:
        return ((s32)try_use_item_by_type(3, 0, 0));
    case 1:
        return ((s32)try_use_item_by_type(3, 0, 1));
    case 2:
        return ((s32)try_use_item_by_type(3, 0, 2));
    case 3:
        return ((s32)try_use_item_by_type(3, 1, 0));
    case 4:
        return ((s32)try_use_item_by_type(3, 1, 1));
    case 5:
        return ((s32)try_use_item_by_type(3, 1, 2));
    case 6:
        return ((s32)try_use_item_by_type(3, 6, 0));
    case 7:
        return ((s32)try_use_item_by_type(3, 6, 1));
    case 8:
        return check_can_add_item((s8)(3), (s8)(3));
    case 9:
        return check_can_add_item((s8)(3), (s8)(4));
    case 10:
        technique_state.reset_slots();
        return check_can_add_item((s8)(3), (s8)(5));
    case 11:
        return check_can_add_item((s8)(3), (s8)(7));
    case 12:
        return check_can_add_item((s8)(3), (s8)(8));
    case 13:
        return send_trap_packet(0);
    case 14:
        return send_trap_packet(1);
    case 15:
        return send_trap_packet(2);
    case 16:
        return send_trap_packet(3);
    default:
        return 0;
    }
}

s32 TObjPlayer::can_use_camera_field() {
    if ((is_controls_locked() != 0) || (this->get_camera_field() == 0) || (is_current_area_item_enabled() == 0)) {
        return 0;
    }
    return 1;
}

s32 TObjPlayer::can_use_item(TItem *item) {
    LockOnActionSlot *slot;
    if (TTecCtrl::is_technique_ready() != 0 && lobby_rule_settings.get_tool_mode() == 2) {
        return 0;
    }
    switch (item->get_item_type()) {
    case 3:
        switch (item->get_item_group()) {
        case 0:
            if (this->hp >= this->hpmax) {
                return 0;
            }
            break;
        case 1:
            if (this->tp >= this->tpmax) {
                return 0;
            }
            break;
        case 6:
            switch (item->get_item_index()) {
            case 0:
                if (test_actor_flags(1) == 0) {
                    return 0;
                }
                break;
            case 1:
                if (test_actor_flags(2) == 0) {
                    return 0;
                }
                break;
            }
            break;
        case 3:
            if (!(get_recovery_need_flags() & 4)) {
                return 0;
            }
            break;
        case 4:
            if (this->lock_on_cursor != NULL) {
                slot = this->lock_on_cursor->find_by_pos(4, 9);
                if (slot == NULL) {
                    return 0;
                }
                if (slot->target_records.get_record(0)->get_entity_id() == 0xFFFF) {
                    return 0;
                }
            }
            break;
        case 7:
            if (TObjWarpBossMulti::is_flag_clear(this) == 0) {
                return 0;
            }
            break;
        }
        break;
    }
    return 1;
}

s32 TObjPlayer::check_can_add_item(s8 kind, s8 group) {
    TItemData item_data;

    item_data.init();
    item_data.data1.data_u8[0] = kind;
    item_data.data1.data_u8[1] = group;
    TItemList *node_5996 = this->inventory_objects->set_mode_and_refresh_object(&item_data);
    if (node_5996 == 0U) {
        return 0;
    }
    TItem *owner = (TItem *)node_5996->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (try_send_6x27_use_item(this, owner->get_item_id()) == 0) {
        return 0;
    }
    TItemList *node_6006 = this->inventory_objects->set_mode_and_refresh_object(&item_data);
    if (node_6006 == 0U) {
        return 0;
    }
    TObject *obj = (TObject *)node_6006->get_owner_if_alive();
    if (obj == NULL) {
        return 0;
    }
    return obj->all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

int TObjPlayer::try_use_item_by_type(int kind, int group, int subgroup) {
    TItemData item_data;
    item_data.init();
    item_data.data1.data_u8[0] = kind;
    item_data.data1.data_u8[1] = group;
    item_data.data1.data_u8[2] = subgroup;
    TItemList *node_6022 = this->inventory_objects->set_mode_and_refresh_object(&item_data);
    if (node_6022 == 0U) {
        return 0;
    }
    TItem *owner = (TItem *)node_6022->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (try_send_6x27_use_item(this, owner->get_item_id()) == 0) {
        return 0;
    }
    TItemList *node_6032 = this->inventory_objects->set_mode_and_refresh_object(&item_data);
    if (node_6032 == 0U) {
        return 0;
    }
    TObject *obj = (TObject *)node_6032->get_owner_if_alive();
    if (obj == NULL) {
        return 0;
    }
    return obj->all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

void TObjPlayer::disable_action_input() { this->set_state_flags(1024); disable_palette_slot(1); disable_palette_slot(2); disable_palette_slot(3); }

void TObjPlayer::disable_primary_action_input() { this->set_state_flags(1024); disable_palette_slot(1); }

void TObjPlayer::enable_action_input() { clear_state_flags(1024); enable_all_palette_slots(); }

s32 TObjPlayer::is_action_input_disabled() { return check_flag(1024); }

void TObjPlayer::set_flag_4096() { this->set_state_flags(4096); }

void TObjPlayer::clear_flag_4096() { this->clear_state_flags(4096); }

int TObjWarpBossMulti::is_flag_clear(void* p) { return (((TObjPlayer *)p)->check_flag(4096)) == 0; }

s32 TObjPlayer::create_return_city_window() {
    if ((this->is_locally_controlled() != 0) && ((u32) this->return_city_window == 0U) && (this->death_fade != NULL)) {
        this->return_city_window = (saddr)new TWindowReturnCity(tl_07, (u16)this->get_entity_id());
        return 1;
    }
    return 0;
}

void TObjPlayer::stop_battle() { this->set_battle_flag(0); }

void complete_deferred_player_death(TDeathTintFade *fade) {
    u8 lvl;
    s16 aim;
    u16 room;
    TObjPlayer *p;
    p = get_player_by_client_id(fade->get_viewport_index());
    if (p == NULL) {
        return;
    }
    p->death_flags.clear(2);
    if (p->try_pickup_item() != 0) {
        return;
    }
    if (TTecCtrl::is_technique_ready() != 0) {
        if (lobby_rule_settings.get_respawn_mode() == 1) {
            p->send_6x4E_player_revivable();
            return;
        }
        if (lobby_rule_settings.get_respawn_mode() == 2 && TObjPlayer::decrement_timer(&p->battle_score.timer) == 0) {
            p->send_6x4E_player_revivable();
            return;
        }
        p->send_respawn_position();
        aim = lobby_rule_settings.get_death_level_up();
        room = get_entity_id_kind(p->get_attacker_id());
        if (aim != 0 && (room == 0 || room == 0x1000)) {
            p->update_aim_angle(aim);
        }
        if ((lvl = (u8)lobby_rule_settings.get_death_tech_level_up()) != 0 && (room == 0 || room == 0x1000)) {
            p->send_level_up_all_techniques(lvl);
        }
        p->reset_pose();
        return;
    }
    if (TObjPlayer::is_camera_mode_active() != 0) {
        p->send_6x4E_player_revivable();
        return;
    }
    if (get_main_phase() == 0xE) {
        if (TObjPlayer::check_camera_mode() != 0) {
            if (p->get_anim_id() == 1) {
                p->prepare_guild_return(0);
                return;
            }
            p->prepare_hospital_return();
            floor_transition_state.set_next_floor(0, get_floor_map_terrain(0));
            mark_area_change_pending();
            send_inter_level_warp_all(floor_transition_state.get_next_floor());
            return;
        }
        p->create_return_city_window();
        p->send_6x4E_player_revivable();
        return;
    }
    p->create_return_city_window();
    p->send_6x4E_player_revivable();
}

void TObjPlayer::prepare_hospital_return() {
    send_6x21_inter_level_warp(this, 0);
    set_arrival_override_pos(this->get_entity_id(), get_hospital_yaw(), (const Vec *)this->get_hospital_position());
    this->set_state_flags(0x800);
    this->set_battle_flag(0);
    apply_to_players((s32)(floor_transition_state.get_next_floor()), get_npc_lobby_entry_position(), get_npc_lobby_entry_yaw());
}

void handle_6x34(void) {  }

int TObjPlayer::check_player_state_flag_2() { return death_flags.test_flags_any(2); }

void TObjPlayer::set_return_hunter() { set_battle_flag(1); }

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
#pragma scheduling on
void TObjPlayer::prepare_guild_return(s32) {
    floor_transition_state.set_next_floor(0, get_floor_map_terrain(0));
    mark_area_change_pending();
    set_arrival_override_pos(get_entity_id(), get_guild_return_yaw(), get_guild_return_position());
    set_state_flags(0x800);
    set_battle_flag(1);
    send_6x21_inter_level_warp(this, floor_transition_state.get_next_floor());
    apply_to_players((s32)(floor_transition_state.get_next_floor()), get_party_position(), get_party_yaw());
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
void TObjPlayer::recover_player_full(TObjPlayer *player) { player->recover_full(); }
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
s32 build_player_equipment_requirement_stats(TObjPlayer *self, PlayerRequirementStats *player_requirement_stats) {
    player_requirement_stats->set(self, self->get_stats(), get_class_attack_template(self),
                                  get_class_defense_template(self));
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
s32 build_player_class_stat_template(TObjPlayer *player, PlayerRequirementStats *out) {
    ActorParamBlock *defense;

    if (player == 0) {
        return 0;
    }
    defense = get_class_defense_template(player);
    out->set(player, player->get_class_stat_entry(), get_class_attack_template(player), defense);
    return 1;
}
#pragma pop

void TObjPlayer::apply_speed_scale(f32 speed) {
    f32 scale;

    if (is_flag30_8_set() != 0) {
        scale = player_half * speed;
    } else {
        scale = speed;
    }
    set_override_speed(scale);
}

s32 TObjPlayer::calc_scaled_value(s32 value) {
    if (is_flag30_10_set() != 0) {
        return (s32) (player_angle_per_degree * (player_degrees_per_turn * (player_rand_unit * (f32) rand())));
    }
    return value;
}

s32 TObjPlayer::get_next_level_exp() {
    s32 actor_level_index;
    s32 max_level;
    max_level = TObjPlayer::get_max_level();
    if (this->get_actor_level_index() >= max_level) {
        return 0;
    }
    actor_level_index = this->get_actor_level_index();
    return TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(this), actor_level_index + 1);
}

void TObjPlayer::send_status_effect_add(StatStatusReceipt effect) {
    G_AddStatusEffect_6x0C pkt;

    if ((this == 0) || (obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = this->get_entity_id();
        obj_copyVec2_0((u8 *)&pkt.effect, (u8 *)&effect);
        pkt.send();
    }
}

void handle_6x0C_add_or_remove_status_effect(G_AddOrRemoveStatusEffect_6x0C_6x0D *command) {
    G_AddStatusEffect_6x0C pkt;
    pkt.init();
    pkt = *(G_AddStatusEffect_6x0C *)command;
    pkt.bswap();
    if (validate_6x0C_add_status_effect(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != 0) {
            p->dispatch_status_effect_msg(pkt.effect);
        }
    }
}


G_ClearNegativeStatusEffects_6x0E &G_ClearNegativeStatusEffects_6x0E::operator=(G_ClearNegativeStatusEffects_6x0E &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x0E_clear_negative_status_effects(G_ClearNegativeStatusEffects_6x0E *command) {
    G_ClearNegativeStatusEffects_6x0E pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x0E_clear_negative_status_effects(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != 0) {
            p->clear_harmful_statuses();
        }
    }
}


void TObjPlayer::send_status_effect_remove(StatStatusReceipt effect) {
    G_RemoveStatusEffect_6x0D pkt;

    if ((this == 0) || (obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = this->get_entity_id();
        obj_copyVec2_0((u8 *)&pkt.effect, (u8 *)&effect);
        pkt.send();
    }
}
void handle_6x0D_add_or_remove_status_effect(G_AddOrRemoveStatusEffect_6x0C_6x0D *command) {
    G_RemoveStatusEffect_6x0D pkt;
    pkt.init();
    pkt = *(G_RemoveStatusEffect_6x0D *)command;
    pkt.bswap();
    if (validate_6x0D_remove_status_effect(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != 0) {
            p->remove_status_effect(pkt.effect);
        }
    }
}


void TObjPlayer::dispatch_status_effect_msg(StatStatusReceipt effect) {
    switch (effect.kind) {
    case 15:
        this->apply_poison_status();
        break;
    case 16:
        this->apply_paralysis();
        break;
    case 17:
        this->apply_slow_status();
        break;
    case 18:
        this->apply_confusion_status();
        break;
    case 3:
        this->apply_shock_status();
        break;
    case 2:
        this->apply_movement_ailment(0);
        break;
    case 7:
        this->clear_harmful_statuses();
        break;
    case 9:
    case 11:
        {
            StatStatusReceipt tmp = effect;
            this->apply_attack_stat_status(&tmp);
        }
        break;
    case 10:
    case 12:
        {
            StatStatusReceipt tmp2 = effect;
            this->apply_defense_stat_status(&tmp2);
        }
        break;
    }
}

void TObjPlayer::remove_status_effect(StatStatusReceipt effect) {
    TObjChara *chara = this;
    f32 amount;
    f32 base;

    switch (effect.kind) {
    case 0:
        chara->actorFlags = (s32) (chara->actorFlags & 0xFFFFFFFC);
        amount = -chara->get_status_effect_amount(0);
        base = chara->get_base_evp();
        base *= amount;
        chara->adjust_evp((s32) base);
        chara->status_effects[0].clear();
        return;
    case 1:
        chara->actorFlags = (s32) (chara->actorFlags & 0xFFFFFFC3);
        amount = -chara->get_status_effect_amount(1);
        base = chara->get_base_evp();
        base *= amount;
        chara->adjust_evp((s32) base);
        chara->status_effects[1].clear();
        return;
    case 2:
        amount = -chara->get_status_effect_amount(2);
        base = chara->get_base_atp();
        base *= amount;
        chara->adjust_atp((s32) base);
        amount = -chara->get_status_effect_amount(2);
        base = chara->get_base_atp_range();
        base *= amount;
        chara->adjust_atp_range((s32) base);
        chara->status_effects[2].clear();
        return;
    case 3:
        amount = -chara->get_status_effect_amount(3);
        base = chara->get_base_dfp();
        base *= amount;
        chara->adjust_dfp((s32) base);
        chara->status_effects[3].clear();
        return;
    }
}

void TObjPlayer::cancel_status_effects() {
    f32 amount;
    f32 base;
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFFC);
    amount = -this->get_status_effect_amount(0);
    base = this->get_base_evp();
    this->adjust_evp((s32) (base * amount));
    this->status_effects[0].clear();
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
    amount = -this->get_status_effect_amount(1);
    base = this->get_base_evp();
    this->adjust_evp((s32) (base * amount));
    this->status_effects[1].clear();
    amount = -this->get_status_effect_amount(2);
    base = this->get_base_atp();
    this->adjust_atp((s32) (base * amount));
    amount = -this->get_status_effect_amount(2);
    base = this->get_base_atp_range();
    this->adjust_atp_range((s32) (base * amount));
    this->status_effects[2].clear();
    amount = -this->get_status_effect_amount(3);
    base = this->get_base_dfp();
    this->adjust_dfp((s32) (base * amount));
    this->status_effects[3].clear();
}

s32 TObjPlayer::is_flag30_8_set() {
    if (this->reset_volopt_state() != 0) {
        return this->test_actor_flags(8);
    }
    return 0;
}

s32 TObjPlayer::is_flag30_10_set() {
    if (this->reset_volopt_state() != 0) {
        return this->test_actor_flags(0x10);
    }
    return 0;
}

s32 TObjPlayer::check_flag30_bit20() {
    if (this->reset_volopt_state() != 0) {
        return test_actor_flags(0x20);
    }
    return 0;
}

s32 TObjPlayer::update_poison_status() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_poison_status();
}

s32 TObjPlayer::update_action_hold_status() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_action_hold_status();
}

s32 TObjPlayer::update_slow_status() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_slow_status();
}

s32 TObjPlayer::update_flag30_timer() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_flag30_timer();
}

s32 TObjPlayer::update_movement_status() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_movement_status();
}

s32 TObjPlayer::update_shock_clock() {
    if ((this->reset_volopt_state() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_shock_clock();
}

s32 TObjPlayer::update_attack_stat_status() {
    if (this->reset_volopt_state() != 0) {
        return TObjChara::update_attack_stat_status();
    }
    return 0;
}

s32 TObjPlayer::update_defense_stat_status() {
    if (this->reset_volopt_state() != 0) {
        return TObjChara::update_defense_stat_status();
    }
    return 0;
}

void TObjPlayer::sync_status_effect_flags() {
    StatStatusReceipt item;
    u32 diff;
    item.power = player_zero;
    diff = (this->sent_status_flags ^ this->actorFlags) & 0x3F;
    if (diff != 0) {
        if (diff & 3) {
            if (this->actorFlags & 3) {
                if (this->actorFlags & 1) {
                    item.kind = 0xF;
                }
                if (this->actorFlags & 2) {
                    item.kind = 0x10;
                }
                this->send_status_effect_add(item);
            } else {
                item.kind = 0;
                this->send_status_effect_remove(item);
            }
        }
        if (diff & 0x3C) {
            if (this->actorFlags & 0x3C) {
                if (this->actorFlags & 8) {
                    item.kind = 0x11;
                }
                if (this->actorFlags & 0x10) {
                    item.kind = 0x12;
                }
                if (this->actorFlags & 0x20) {
                    item.kind = 2;
                }
                if (this->actorFlags & 4) {
                    item.kind = 3;
                }
                this->send_status_effect_add(item);
            } else {
                item.kind = 1;
                this->send_status_effect_remove(item);
            }
        }
        if (diff & 0x40) {
            item.kind = 7;
            this->send_status_effect_add(item);
        }
        this->sent_status_flags = this->actorFlags;
    }
}

void TObjPlayer::resend_status_effects() {
    StatStatusReceipt item;
    item.power = player_zero;
    if (this->test_actor_flags(1) != 0) {
        item.kind = 0xF;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(2) != 0) {
        item.kind = 0x10;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(0x40) != 0) {
        item.kind = 7;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(8) != 0) {
        item.kind = 0x11;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(0x10) != 0) {
        item.kind = 0x12;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(0x20) != 0) {
        item.kind = 2;
        this->dispatch_status_effect_msg(item);
    }
    if (this->test_actor_flags(4) != 0) {
        item.kind = 3;
        this->dispatch_status_effect_msg(item);
    }
}

void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading) {
    G_TeleportPlayer_6x24 pkt;
    pkt.init();
    TObjChara *chara = (TObjChara *)get_player_by_client_id(slot);
    if (chara != NULL && chara->obj_isState2_324() == 0) {
        pkt.header.client_id = slot;
        pkt.angle_y = heading;
        VecCopy(&pkt.pos, pos);
        pkt.send();
    }
}

void handle_6x24_teleport_player(G_TeleportPlayer_6x24 *command) {
    G_TeleportPlayer_6x24 pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x24_teleport_player(&pkt) == 0) {
        return;
    }
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == NULL) {
        return;
    }
    player->set_position_from(&pkt.pos);
    player->rotation_y = player->target_heading = pkt.angle_y;
    player->calc_attach_pos();
    player->set_flag_4000();
    player->refresh_equipment_slot();
    TPlyOnCountOver::create(player->get_entity_id(), 2, TObjPlayer::clear_flag_4000_callback);
    if (player->is_locally_controlled() != 0) {
        reset_cameras_to_actor(player, 0);
    }
}


void send_6x2F_change_player_hp(u16 sender, u16 client, s16 hp) {
    G_ChangePlayerHP_6x2F m;

    TObjChara *chara = (TObjChara *)get_player_by_client_id(sender);
    TObjPlayer *target;
    if (((chara == NULL) || (chara->obj_isState2_324() == 0)) && (((target = get_player_by_client_id(client)) == NULL) || (target->is_locally_controlled() != 0))) {
        m.init();
        m.header.client_id = sender;
        m.type = 0;
        m.amount = hp;
        m.client_id = client;
        m.send();
    }
}

void handle_6x2F_change_player_hp(G_ChangePlayerHP_6x2F *command) {
    G_ChangePlayerHP_6x2F pkt;
    TObjPlayer *player;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x2F_change_player_hp(&pkt) == 0) {
        return;
    }
    player = get_player_by_client_id(pkt.client_id);
    if (player == 0) {
        return;
    }
    if (player->test_actor_flags(0x800) != 0) {
        return;
    }
    switch (pkt.type) {
    case 0:
        player->set_hp_clamped(pkt.amount);
        break;
    case 1:
        add_actor_hp(player, pkt.amount);
        break;
    case 2:
        add_actor_hp(player, player->hpmax);
        break;
    }
}


s32 TObjPlayer::is_in_tl03_state() {
    int result;

    result = 0;
    if ((check_flag_4() == 0) && (m_up == tl_03)) {
        result = 1;
    }
    return (u8)((u8)result);
}

void TObjPlayer::play_sound_if_on_floor(s32 sound_id) {
    if (is_on_current_floor() != 0) {
        play_sound_effect(sound_id, get_position_ptr(), 0, 0);
    }
}

void TObjPlayer::send_local_player_invisible() {
    G_SetPlayerInvisible_6x22 cmd;
    TObjPlayer *p;
    cmd.init();
    p = get_local_player();
    if (p != NULL && (p == NULL || p->obj_isState2_324() == 0)) {
        cmd.header.client_id = p->get_entity_id();
        cmd.send();
    }
}
void handle_6x22_set_player_invisible(G_SetPlayerInvisible_6x22 *command) {
    G_SetPlayerInvisible_6x22 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt.header);
    if (validate_6x22_set_player_invisible(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL && p->check_flag_4() == 0) {
            p->set_state_flags(0x40000);
            p->deactivate_body_collision();
            p->clear_flag_200000();
        }
    }
}


void TObjPlayer::send_local_player_visible() {
    G_SetPlayerVisible_6x23 cmd;
    TObjPlayer *p;
    cmd.init();
    p = get_local_player();
    if (p != NULL && (p == NULL || p->obj_isState2_324() == 0)) {
        cmd.header.client_id = p->get_entity_id();
        cmd.send();
    }
}

void handle_6x23_set_player_visible(G_SetPlayerVisible_6x23 *command) {
    G_SetPlayerVisible_6x23 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt.header);
    if (validate_6x23_set_player_visible(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_state_flags(0x40000);
        }
    }
}

int TObjPlayer::check_flag_40000() {
    return check_flag(0x40000);
}

void TObjPlayer::for_each_player_slot(void (*callback)(TObjPlayer *)) {
    s32 i;
    TObjPlayer **p;
    p = player_slot_table;
    for (i = 0; i < 12; i++, p++) {
        if (*p != NULL) {
            callback(*p);
        }
    }
}

void TObjPlayer::foreach_player(void (*callback)(TObjPlayer *)) {
    void (*fn)(TObjPlayer *);
    s32 i;
    TObjPlayer **slots;
    s32 slot;
    TObjPlayer *player;

    fn = callback;
    i = 0;
    slots = player_slot_table;
    slot = 0;
    do {
        player = slots[slot];
        if ((player != NULL) && (player->is_locally_controlled() != 0)) {
            fn(player);
        }
        i += 1;
        slot += 1;
    } while (i < 0xC);
}

s32 TObjPlayer::reset_volopt_state() { return is_item_area_enabled(this->get_area()); }

void TObjPlayer::play_phase_transition_sound(saddr child) {
    if (((get_main_phase() == 0xE) || (get_main_phase() == 0xF)) && (TFontSmallLobby::is_lobby_floor_15() != 0)) {
        draw_chunk_object((void *)child);
        return;
    }
    draw_chunk_object((void *)child);
}

s16 TObjPlayer::get_current_mode_animation() {
    return this->get_mode_animation(this->mode);
}

s16 TObjPlayer::get_mode_animation(u32 mode) {
    switch (mode) {
    default:
        return this->get_idle_animation();
    case 2:
    case 3:
        return get_walk_action();
    case 4:
        return this->get_run_action();
    case 5:
        return this->get_attack1_action();
    case 6:
        return this->get_state();
    case 7:
        return this->get_model_state();
    case 8:
        return this->get_status();
    case 9:
        return this->query_equip();
    case 10:
        return this->query_child_state();
    case 11:
        return this->call_obj_vt26();
    case 12:
        return this->get_weapon_stat_c();
    case 13:
        return this->call_model_m24();
    case 14:
        return this->get_action_animation();
    case 15:
        return this->get_model_field_m25();
    }
}

int TObjPlayer::is_pk_enabled() { return this->pk_state.is_enabled(); }

void TObjPlayer::send_enable_pk_mode(TObjPlayer *player) {
    G_EnablePKModeForPlayer_6x1B pkt;

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = player->get_entity_id();
        pkt.send();
    }
}

G_EnablePKModeForPlayer_6x1B &G_EnablePKModeForPlayer_6x1B::operator=(G_EnablePKModeForPlayer_6x1B &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x1B_enable_pk_mode_for_player(G_EnablePKModeForPlayer_6x1B *command) {
    G_EnablePKModeForPlayer_6x1B pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x1B_enable_pk_mode_for_player(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_6043();
        }
    }
}

void TObjPlayer::set_state_flag_6043() {
    if (this->obj_isState3_324() != 0) {
        this->collision_body.flags = 0x6043;
    } else {
        this->collision_body.flags = 0x2003;
    }
    this->pk_state.enable();
}

void TObjPlayer::send_disable_pk_mode(TObjPlayer *player) {
    G_DisablePKModeForPlayer_6x1C pkt;

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        pkt.init();
        pkt.header.client_id = player->get_entity_id();
        pkt.send();
    }
}

G_DisablePKModeForPlayer_6x1C &G_DisablePKModeForPlayer_6x1C::operator=(G_DisablePKModeForPlayer_6x1C &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x1C_disable_pk_mode_for_player(G_DisablePKModeForPlayer_6x1C *command) {
    G_DisablePKModeForPlayer_6x1C pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x1C_disable_pk_mode_for_player(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_604B();
        }
    }
}

void TObjPlayer::set_state_flag_604B() {
    if (this->obj_isState3_324() != 0) {
        this->collision_body.flags = 0x604B;
    } else {
        this->collision_body.flags = 0x200B;
    }
    this->pk_state.disable();
}

TItemList *TObjPlayer::find_revival_item() {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = 1;
    item.data1.data_u8[1] = 2;
    item.data1.data_u8[2] = 0x52;
    TItemList *found = inventory_objects->set_mode_and_refresh_object(&item);
    if (found == NULL) {
        item.init();
        item.data1.data_u8[0] = 3;
        item.data1.data_u8[1] = 9;
        found = inventory_objects->set_mode_and_refresh_object(&item);
    }
    return found;
}

s32 TObjPlayer::try_pickup_item() {
    TItem *owner_if_alive;

    if (this->obj_isState2_324() != 0) {
        return 0;
    }
    TItemList *node;
    if ((node = this->find_revival_item()) != NULL) {
        owner_if_alive = node->get_owner_if_alive();
        if (owner_if_alive == 0) {
            return 0;
        }
        recover_full();
        ((FlagWord *)((saddr)this + 0x858))->set(4);
        send_6x29_delete_item(this, owner_if_alive->get_item_id(), 1);
        return 1;
    }
    return 0;
}

void TObjPlayer::draw() {
    push_matrix();
    translate_matrix_vec3((u8 *)(0), (u8 *)(this->get_position_ptr()));
    rotate_matrix_y(0, this->rotation_y);
    calc_joint_matrices(current_motion, player_zero, (saddr)joint_matrices);
    pop_matrix();
}

void TObjPlayer::draw(f32 at_frame) {
    push_matrix();
    translate_matrix_vec3(NULL, (u8 *)get_position_ptr());
    rotate_matrix_y(NULL, rotation_y);
    calc_joint_matrices(current_motion, at_frame, (saddr)joint_matrices);
    pop_matrix();
}

void TObjPlayer::spawn_effect(saddr player) {
    if (((TObjChara *)player)->is_locally_controlled() != 0) {
        start_pad_rumble_client(0xC0, 0xF, ((TObjBase *)(player))->get_entity_id());
    }
}

void TObjPlayer::send_field_state() {
    if ((this->is_body_collision_inactive() == 0) && (check_flag_800000() == 0)) {
        ((TObjPlayer *)((saddr)this + 0x384))->check_hit_by_id_431_from_packet();
    }
    this->play_sound_if_on_floor(0x42D08);
}

s32 TObjPlayer::is_actor_cadence_frame(s32 mask) {
    return (u8) ((actor_frame_tick & mask) == get_entity_id());
}

void TObjPlayer::deactivate_body_collision() {
    set_actor_flags(0x02000000U);
    this->clear_player_status_flag(0, 1U);
}

void TObjPlayer::activate_body_collision() {
    clear_actor_flags((u32)0x02000000U);
    set_indexed_flags(0, 1);
}

s32 TObjPlayer::is_body_collision_inactive() {
    return test_actor_flags(0x02000000);
}

void TObjPlayer::send_enable_stealth_suit_effect() {
    G_EnableStealthSuitEffect_6x7A pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_EnableStealthSuitEffect_6x7A &G_EnableStealthSuitEffect_6x7A::operator=(G_EnableStealthSuitEffect_6x7A &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x7A_enable_stealth_suit_effect(G_EnableStealthSuitEffect_6x7A *command) {
    G_EnableStealthSuitEffect_6x7A pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x7A_enable_stealth_suit_effect(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_stealth_suit_flags();
        }
    }
}


void TObjPlayer::set_stealth_suit_flags() {
    set_state_flags(0x800000U);
    set_indexed_flags(0, 0x08000000);
}

void TObjPlayer::send_disable_stealth_suit_effect() {
    G_DisableStealthSuitEffect_6x7B pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_DisableStealthSuitEffect_6x7B &G_DisableStealthSuitEffect_6x7B::operator=(G_DisableStealthSuitEffect_6x7B &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x7B_disable_stealth_suit_effect(G_DisableStealthSuitEffect_6x7B *command) {
    G_DisableStealthSuitEffect_6x7B pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x7B_disable_stealth_suit_effect(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_stealth_suit_flags();
        }
    }
}


void TObjPlayer::clear_stealth_suit_flags() {
    this->clear_state_flags(0x800000U);
    this->clear_player_status_flag(0, 0x08000000);
}

s32 TObjPlayer::check_flag_800000() {
    return check_flag(0x800000);
}

void TObjPlayer::refresh_equipment_slot() {
    TItem *item;
    item = this->get_equipped_mag();
    if (item != NULL) {
        item->snap_to_owner();
    }
}

void TObjPlayer::update_photon_chair(TObjPlayer *player) {
    player->appear_fade.begin();
    if (player->obj_isState2_324() != 0) {
        player->clear_flag_400000();
    }
}

s32 TObjPlayer::add_actor_exp(s32 amount) {
    s32 exp;
    s32 max_exp;
    player_stats *stat_block;

    if (is_current_area_item_enabled() == 0) {
        return 0;
    }
    stat_block = this->stat_block;
    exp = stat_block->exp;
    max_exp = get_class_max_exp(this, stat_block);
    exp = exp + amount;
    if (exp > max_exp) {
        exp = max_exp;
    }
    if (exp < 0) {
        exp = 0;
    }
    this->stat_block->exp = exp;
    return 1;
}

s32 TTecCtrl::is_technique_ready() {
    int result;

    result = 0;
    if ((TObjPlayer::get_player_count() == 1) && (TObjPlayer::get_rules_active() == 1)) {
        result = 1;
    }
    return (u8)result;
}

void apply_battle_rules_to_players() {
    s32 i;
    LobbyRuleSettings *q;
    TObjPlayer *p;
    saddr j;
    TItem *weapon;
    s8 lv;
    q = &lobby_rule_settings;
    for (i = 0; i < 0xC; i++) {
        p = (TObjPlayer *)get_player_by_client_id(i);
        if (p == NULL) {
            continue;
        }
        p->battle_score.reset();
        if (q->get_rules_active() == 1) {
            p->set_state_flag_6043();
            if (p->is_locally_controlled() != 0) {
                lobby_player_count = 1;
            }
        } else {
            return;
        }
        switch (q->get_weapon_and_armor_mode()) {
        case 1:
        case 2:
        case 3:
            p->inventory_objects->set_globals_and_update(p, 0);
            p->inventory_objects->set_globals_and_update(p, 1);
            break;
        }
        switch (q->get_mag_mode()) {
        case 1:
            p->inventory_objects->set_globals_and_update(p, 2);
            break;
        }
        if ((weapon = TObjPlayer::get_equipped_weapon(p)) != NULL && weapon->check_equip_requirements(p, (s16 *)0) == 0) {
            p->unequip_item(weapon);
        }
        switch (q->get_tool_mode()) {
        case 1:
        case 2:
            p->inventory_objects->set_globals_and_update(p, 3);
            break;
        }
        if (q->get_trap_mode() == 1) {
            for (j = 0; j < 4; j++) {
                p->trap_counts.set_count(q->get_trap_count(j), j);
            }
        }
        switch (q->get_respawn_mode()) {
        case 2:
            p->battle_score.set_timer(q->get_lives());
            break;
        }
        switch (q->get_replace_char()) {
        case 1:
            p->set_hp_bonus(0);
            p->set_tp_bonus(0);
            p->apply_battle_level_reset(q->get_char_level());
            break;
        }
        lv = q->get_max_tech_level();
        switch (q->get_tech_disk_mode()) {
        case 1:
            p->technique_state.copy_all_technique_entries(0xFF);
            p->technique_state.set_all_technique_levels(0xFF);
            break;
        case 2:
            p->technique_state.copy_all_technique_entries(0x1D);
            p->technique_state.set_learned_technique_levels(lv);
            break;
        }
        p->set_flag_drop_weapon_on_death();
        switch (q->get_drop_weapon()) {
        case 1:
            p->disable_drop_weapon_on_death();
            break;
        }
        if (q->get_hide_target_reticle() == 1 && p->is_locally_controlled() != 0) {
            ((TObjPlayer *)p->lock_on_cursor)->set_flags_bit2();
        }
        if (q->get_meseta_mode() != 0) {
            p->set_meseta(0);
        }
        if (q->get_enable_sonar() == 1) {
            p->sonar_stock.set_count(q->get_sonar_count());
        }
        if (q->get_forbid_scape_dolls() == 1) {
            p->inventory_objects->reduce_items_of_kind(p, 3, 9);
        }
        p->set_flag_4096();
        p->recover_full();
        p->cancel_status_effects();
        lobby_char_slot_array[i].copy_from_player(p);
    }
}

s32 TObjPlayer::check_switch_available(s32 item_id) {
    if (TTecCtrl::is_technique_ready() != 0) {
        if (lobby_rule_settings.get_weapon_and_armor_mode() == 2) {
            TItemList *slot = static_cast<TItemList *>(inventory_objects->start_inventory_update(item_id));
            if (slot == NULL) {
                return 0;
            }
            TItem *item_owner = slot->get_owner_if_alive();
            if (item_owner == NULL) {
                return 0;
            }
            if (item_owner->get_item_type() == 0) {
                return 0;
            }
        }
        if (lobby_rule_settings.get_mag_mode() == 1) {
            TItemList *slot = static_cast<TItemList *>(inventory_objects->start_inventory_update(item_id));
            if (slot == NULL) {
                return 0;
            }
            TItem *item_owner = slot->get_owner_if_alive();
            if (item_owner == NULL) {
                return 0;
            }
            if (item_owner->get_item_type() == 2) {
                return 0;
            }
        }
    }
    return 1;
}

void recreate_all_players(void) {
    TObjPlayer *players[12];
    s32 i;
    TObjPlayer *p;
    shared_state_flags[0] |= 1;
    for (i = 0; i < 12; i++) {
        players[i] = NULL;
    }
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            players[i] = p;
            delete p;
        }
    }
    for (i = 0; i < 12; i++) {
        if (players[i] != NULL) {
            TObjPlayer::create_player_instance((u16)i, &lobby_char_slot_array[i]);
            TWindowCtrl::enable_client_main_menu(i);
        }
    }
    shared_state_flags[0] &= ~1;
}

s32 TLobby::count_members() {
    TObjPlayer **p = player_slot_table;
    s32 n = 0;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (*p) {
            n++;
        }
        p++;
    }
    return n;
}

void TObjPlayer::send_disable_drop_weapon_on_death() {
    G_DisableDropWeaponOnDeath_6x81 pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_DisableDropWeaponOnDeath_6x81 &G_DisableDropWeaponOnDeath_6x81::operator=(G_DisableDropWeaponOnDeath_6x81 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x81_disable_drop_weapon_on_death(G_DisableDropWeaponOnDeath_6x81 *command) {
    G_DisableDropWeaponOnDeath_6x81 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x81_disable_drop_weapon_on_death(&pkt.header) != 0) {
        TObjPlayer *p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            p->disable_drop_weapon_on_death();
        }
    }
}


void TObjPlayer::disable_drop_weapon_on_death() {
    set_state_flags(0x01000000);
}

void TObjPlayer::send_enable_drop_weapon_on_death() {
    G_EnableDropWeaponOnDeath_6x82 pkt;

    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.send();
    }
}

G_EnableDropWeaponOnDeath_6x82 &G_EnableDropWeaponOnDeath_6x82::operator=(G_EnableDropWeaponOnDeath_6x82 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}

void handle_6x82_enable_drop_weapon_on_death(G_EnableDropWeaponOnDeath_6x82 *command) {
    G_EnableDropWeaponOnDeath_6x82 pkt;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x82_enable_drop_weapon_on_death(&pkt.header) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_flag_drop_weapon_on_death();
        }
    }
}

void TObjPlayer::set_flag_drop_weapon_on_death() {
    clear_state_flags(0x01000000);
}

s32 TObjPlayer::is_drop_weapon_on_death_disabled() {
    return check_flag(0x01000000);
}

void handle_6x90_set_player_battle_team(G_SetPlayerBattleTeam_6x90 *command) {
    G_SetPlayerBattleTeam_6x90 cmd;
    TObjPlayer *p;
    s32 team;
    cmd.init();
    cmd = *command;
    cmd.bswap();
    if (validate_6x90_set_player_battle_team(&cmd) == 0) {
        return;
    }
    p = get_player_by_client_id((u16)cmd.header.client_id);
    if (p == NULL) {
        return;
    }
    team = cmd.team_number;
    p->pk_state.set_team(team);
    if (team == 1) {
        TMainCursor__sub_801540B8((saddr) p, *(s32 *)((s8 *)p + 0xA4), 0);
    } else {
        TMainCursor__sub_80154098((saddr) p, *(s32 *)((s8 *)p + 0xA4), 0);
    }
}
int TObjPlayer::get_pk_team() { return pk_state.get_team(); }
extern "C" {

void draw_status_line(void *window, s32 *str, s32 *name, s32 value) {
    text_builder_reset();
    text_builder_append((const char *)str);
    text_builder_append((const char *)name);
    text_builder_append(status_line_break);
    text_builder_append_int(value);
    text_builder_append(status_line_break);
    TWindowCtrl::append_message_all(get_shared_text_buffer(), 0x200);
}

void show_sub_status_window(void *window, s32 *str, s32 *name) {
    text_builder_reset();
    text_builder_append((const char *)str);
    text_builder_append((const char *)name);
    text_builder_append(status_line_break);
    TWindowCtrl::append_message_all(get_shared_text_buffer(), 0x200);
}

void draw_player_status(saddr window, void *player, saddr str) {
    saddr name;

    name = (saddr)((TObjContainerCommon *)player)->get_name();
    if (name != 0) {
        if (static_cast<TObject *>(player)->check_value_equals(TObjPlayer_name) != 0) {
            ((s32 (*)(s32, s32, s32, s32))draw_status_line)(window, str, name, ((TObjPlayer *)player)->calc_battle_score());
            return;
        }
        show_sub_status_window((void *)window, (s32 *)str, (s32 *)name);
    }
}

// Counts a kill unless the victim is a player on this player's own PK team.
void TObjPlayer::record_kill(TObject *victim, s32 count) {
    if (victim->check_value_equals(TObjPlayer_name) == 0
        || lobby_rule_settings.get_is_teams() != 1
        || pk_state.get_team() != ((TObjPlayer *)victim)->pk_state.get_team()) {
        accumulate_damage_stats(&battle_score.kills, victim, count);
        play_sound_effect(0x4004B20A, 0, 0, 0);
    }
}

s32 TObjPlayer::record_death(TObject *killer, s32 count) {
    return accumulate_damage_stats(&battle_score.deaths, killer, count);
}

void record_damage_stats(uaddr mine_trap, u32 att, s16 damage) {
  G_AddBattleDamageScores_6x8F pkt;
  u32 player;
  uaddr obj;
  if (TTecCtrl::is_technique_ready() != 0)
  {
    obj = att;
    if ((reinterpret_cast<TObject *>(obj)->check_value_equals(TOMineTrap::class_name) != 0) && (((TOMineTrap *)obj)->get_trap_type() != 0xFFFF))
    {
      obj = ((u32 (*)(void))find_entity_by_id)();
    }
    if (((TObjCollidable *)obj)->test_actor_flags(0x10000000) == 0)
    {
      if (((TObjChara *)mine_trap)->is_locally_controlled() != 0)
      {
        ((int (*)(u32, u32, s16)) accumulate_damage_stats)(mine_trap + 0x77C, obj, damage);
      }
    }
    else
      if ((((TObjChara *)mine_trap)->is_locally_controlled() != 0) && ((mine_trap == 0U) || (((TObjChara *)mine_trap)->obj_isState2_324() == 0)))
    {
      ((int (*)(u32, u32, s16)) accumulate_damage_stats)(mine_trap + 0x77C, obj, damage);
      if (((TObjBase *)(obj))->get_entity_id() != ((TObjBase *)(mine_trap))->get_entity_id())
      {
        player = (uaddr)get_player_by_client_id(((TObjBase *)(obj))->get_entity_id());
        if (player != 0U)
        {
          ((int (*)(u32, u32, s16)) accumulate_damage_stats)(player + 0x78C, mine_trap, damage);
        }
      }
      if (TObjPlayer::is_final_phase() != 0)
      {
        pkt.init();
        pkt.header.client_id = ((TObjBase *)(obj))->get_entity_id();
        pkt.target_entity_id = ((TObjBase *)(mine_trap))->get_entity_id();
        pkt.amount = damage;
        pkt.send();
      }
    }
  }
}
}

void handle_6x8E(void) {  }

void TObjPlayer::apply_camera_shake(TObjCollidable *target, s32 damage) {
    if ((TTecCtrl::is_technique_ready() != 0) && (target->test_actor_flags(0x10000000) == 0) && (is_locally_controlled() != 0)) {
        accumulate_damage_stats(&battle_score.damage_given, target, damage);
    }
}
void handle_6x8F_add_battle_damage_scores(G_AddBattleDamageScores_6x8F *command) {
    G_AddBattleDamageScores_6x8F pkt;
    TObjPlayer *player;
    TObjCollidable *target;
    TObjPlayer *other;
    pkt.init();
    pkt = *command;
    pkt.bswap();
    if (validate_6x8F_add_battle_damage_scores(&pkt) == 0) {
        return;
    }
    player = get_player_by_client_id(pkt.header.client_id);
    if (player == NULL) {
        return;
    }
    target = find_entity_by_id(pkt.target_entity_id);
    if (target == NULL) {
        return;
    }
    if ((u16)target->get_entity_id() != (u16)player->get_entity_id()) {
        accumulate_damage_stats(&player->battle_score.damage_given, target, pkt.amount);
    }
    if (target->test_actor_flags(0x10000000) == 0) {
        return;
    }
    other = get_player_by_client_id((u16)target->get_entity_id());
    if (other != NULL) {
        accumulate_damage_stats(&other->battle_score.damage_taken, player, pkt.amount);
    }
}
extern "C" {

void TObjPlayer::record_meseta_pickup(s32 amount) {
    if (this->is_locally_controlled() == 0 || lobby_rule_settings.get_meseta_mode() != 2 || TTecCtrl::is_technique_ready() == 0) {
        return;
    }
    battle_score.meseta.set_total((f32) amount);
}

s32 TObjPlayer::calc_battle_score() {
    f32 v;

    v = (f32)battle_score.damage_given.get_total();
    v -= (f32)battle_score.damage_taken.get_total();
    v += (f32)battle_score.kills.get_total();
    v -= (f32)battle_score.deaths.get_total();
    if (test_actor_flags(0x800) == 0) {
        v += (f32)get_actor_meseta() * battle_score.meseta.get_bonus_weight();
    }
    return (s32)v;
}

int TObjPlayer::get_key_machine_global_state(void* p) { return ((int)get_current_floor_area()); }

void TObjPlayer::sync_current_area() {
    current_area = get_key_machine_global_state(this);
}

void TObjPlayer::sync_current_floor() {
    this->current_floor = get_current_floor();
}

s32 TObjPlayer::is_on_current_floor() {
    s32 current_floor;
    s32 player_floor;
    current_floor = get_current_floor();
    player_floor = get_floor();
    return (u8) (player_floor == current_floor);
}

s32 TFontSmallLobby::is_lobby_floor_15(void) {
    return (u8) (get_current_floor_area() == AREA_LOBBY);
}

s32 TObjPlayer::is_in_lobby() {
    return (u8)(get_area() == AREA_LOBBY);
}

s32 TObjPlayer::is_key_machine_ready(void) {
    s32 area;
    s32 result;

    area = get_current_floor_area();
    result = 0;
    if ((area == AREA_PIONEER2_EP1) || (area == AREA_PIONEER2_EP2)) {
        result = 1;
    }
    return (u8) result;
}

s32 TObjPlayer::check_technique_castable(TObjPlayer *player) {
    s32 area;

    if ((TTecCtrl::is_technique_ready() != 0) || (TObjPlayer::is_camera_mode_active() != 0) || (is_boss_area() != 0)) {
        player->set_flag_4096();
        return 0;
    }
    area = get_current_floor_area();
    switch (area) {
    case AREA_PIONEER2_EP1:
    case AREA_LOBBY:
    case AREA_PIONEER2_EP2:
        player->set_flag_4096();
        return 0;
    default:
        player->clear_flag_4096();
        return 1;
    }
}

s8 clamp_class_index(s8 cls) {
    if ((cls < 0) || (cls >= 0xC)) {
        return 0;
    }
    return cls;
}

s8 TObjPlayer::get_class_index() {
    return (s8) this->class_index;
}

s32 TObjPlayer::get_class_flags() { return this->class_flags; }

s32 TObjPlayer::get_language() {
    s32 lang;
    lang = this->language;
    if ((lang < 0) || (lang >= 5)) {
        return 1;
    }
    return lang;
}

s32 TObjPlayer::get_controller_port() { return this->controller_port; }

void TObjPlayer::set_action_provider_variant(s16 variant) {
    if (variant != ((TObjPlayer *)action_provider)->sub_802a7290_fwd() && fn_8000F740(&main_phase_state) != 0) {
        action_provider->load_motion_set(get_entity_id(), has_valid_handle(), variant);
        this->apply_motion_entry();
    }
}

s16 TObjPlayer::get_handle_value() { return (s16)(((TObjPlayer *)this->action_provider)->sub_802a7290_fwd()); }

f32 TObjPlayer::receive_physical_attack(TObjChara *attacker, f32 scale) {
    if (obj_isState2_324() != 0) {
        return player_zero;
    }
    return TObjChara::receive_physical_attack(attacker, scale);
}

void TObjPlayer::clamp_stats(player_stats *out, player_stats *class_stats) {
    s16 extra;
    s32 max_level;
    s32 value;
    s32 max_exp;
    s32 meseta;
    const player_stats *caps;
    player_stats *stats;

    stats = get_stats();
    caps = get_class_stat_caps(get_class_index__10TObjPlayerFv(this));
    if (stats->stats.atp < 0) {
        out->stats.atp = 1;
        clamp_stat_41c();
    } else if (stats->stats.atp > caps->stats.atp) {
        out->stats.atp = caps->stats.atp;
        clamp_stat_41c();
    } else {
        out->stats.atp = stats->stats.atp;
    }
    if (stats->stats.mst < 0) {
        out->stats.mst = 1;
        clamp_stat_41c();
    } else if (stats->stats.mst > caps->stats.mst) {
        out->stats.mst = caps->stats.mst;
        clamp_stat_41c();
    } else {
        out->stats.mst = stats->stats.mst;
    }
    if (stats->stats.evp < 0) {
        out->stats.evp = 1;
        clamp_stat_41c();
    } else if (stats->stats.evp > caps->stats.evp) {
        out->stats.evp = caps->stats.evp;
        clamp_stat_41c();
    } else {
        out->stats.evp = stats->stats.evp;
    }
    if (stats->stats.hp < 0) {
        out->stats.hp = 1;
        clamp_stat_41c();
    }
    if (stats->stats.hp > caps->stats.hp) {
        out->stats.hp = caps->stats.hp;
        clamp_stat_41c();
    } else {
        out->stats.hp = stats->stats.hp;
    }
    if (stats->stats.dfp < 0) {
        out->stats.dfp = 1;
        clamp_stat_41c();
    } else if (stats->stats.dfp > caps->stats.dfp) {
        out->stats.dfp = caps->stats.dfp;
        clamp_stat_41c();
    } else {
        out->stats.dfp = stats->stats.dfp;
    }
    if (stats->stats.ata < 0) {
        out->stats.ata = 1;
        clamp_stat_41c();
    } else if (stats->stats.ata > caps->stats.ata) {
        out->stats.ata = caps->stats.ata;
        clamp_stat_41c();
    } else {
        out->stats.ata = stats->stats.ata;
    }
    if (stats->stats.lck < 0) {
        out->stats.lck = 1;
        clamp_stat_41c();
    } else if (stats->stats.lck > caps->stats.lck) {
        out->stats.lck = caps->stats.lck;
        clamp_stat_41c();
    } else {
        out->stats.lck = stats->stats.lck;
    }
    extra = stats->esp;
    if (extra < 0) {
        out->esp = 1;
        clamp_stat_41c();
    } else {
        out->esp = extra;
    }
    out->proportions = stats->proportions;
    out->knockback_resist = stats->knockback_resist;
    value = stats->level;
    max_level = TObjPlayer::get_max_level();
    if (value < 0) {
        out->level = 0;
        set_flag_41c_bit1();
    } else if (value > max_level) {
        out->level = max_level;
        set_flag_41c_bit1();
    } else {
        out->level = value;
    }
    value = stats->exp;
    max_exp = TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(this), max_level);
    if (value < 0) {
        out->exp = 0;
        check_flag_at_41c();
    } else if (value > max_exp) {
        out->exp = max_exp;
        check_flag_at_41c();
    } else {
        out->exp = value;
    }
    meseta = stats->meseta;
    if (meseta < 0) {
        out->meseta = 0;
        check_stat_flag_41c();
        return;
    }
    if (meseta > 999999) {
        out->meseta = 999999;
        check_stat_flag_41c();
        return;
    }
    out->meseta = meseta;
}

}

void queue_player_kill(TObjPlayer *player) {
    new TPlayerReadyCallback(player, player->get_entity_id(), mark_player_killed);
}

void mark_player_killed(TObjPlayer *player) {
    if (player != NULL) {
        player->set_actor_flags(0xA00);
    }
}

extern "C" {

s32 TObjPlayer::get_battle_place() {
    u16 id;
    BattleRanking *e;
    int i;

    id = get_entity_id();
    if (is_single_screen() != 0) {
        e = get_split_screen_battle_rankings();
    } else {
        e = get_battle_rankings();
    }
    for (i = 0; i < 4; i++, e++) {
        if (id == e->client_id) {
            return e->place;
        }
    }
    return -1;
}

s32 TObjPlayer::update_movement_by_screen() {
    if (is_single_screen() != 0) {
        return get_battle_ctrl_default();
    }
    return get_ranked_battle_ctrl_value();
}

void TObjPlayer::refill_traps() {
    trap_counts.refill(get_actor_level_index(), get_class_index());
}

s32 TObjPlayer::is_alive_and_ready() {
    if ((TTecCtrl::is_technique_ready() == 0) && (this->is_android() != 0)) {
        return 1;
    }
    return 0;
}

s32 TObjPlayer::are_traps_full() {
    return trap_counts.is_full(get_actor_level_index(), get_class_index()) != 0 ? 1 : 0;
}

s32 TObjPlayer::is_action_available() {
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        return 0;
    }
    if (is_camera_ready() != 0) {
        return (u32)__cntlzw(test_actor_flags(0x20000)) >> 5;
    }
    return is_android() != 0 ? 1 : 0;
}

bool is_trap_stock_empty(TObjPlayer *player, s32 kind) { return player->trap_counts.is_empty(kind); }

TPlayerLobbyMarker *TObjPlayer::set_lobby_marker(u8 material) {
    if (TFontSmallLobby::is_lobby_floor_15() == 0) {
        return NULL;
    }
    if (lobby_marker == NULL) {
        lobby_marker = TPlayerLobbyMarker::create(get_entity_id(), material);
    } else {
        lobby_marker->set_material_index(material);
    }
    return lobby_marker;
}

void TObjPlayer::reset_pose() { this->clear_actor_flags((uaddr)((void*)2048)); update_rotation(); }

void TObjPlayer::restore_hp_and_tp() {
    set_hp_clamped(hpmax);
    set_tp(tpmax);
}

void TObjPlayer::send_level_up_all_techniques(u8 num_levels) {
    G_LevelUpAllTechniques_6x9B pkt;
    if (this == NULL || obj_isState2_324() == 0) {
        pkt.init();
        pkt.header.client_id = get_entity_id();
        pkt.num_levels = num_levels;
        pkt.send();
    }
}
}
void handle_6x9B_level_up_all_techniques(G_LevelUpAllTechniques_6x9B *command) {
    G_LevelUpAllTechniques_6x9B pkt;
    TObjPlayer *p;
    pkt.init();
    pkt = *command;
    bswap_g_client_id_header(&pkt);
    if (validate_6x9B_level_up_all_techniques(&pkt) != 0) {
        p = get_player_by_client_id(pkt.header.client_id);
        if (p != NULL) {
            p->technique_state.level_up_all_techniques(pkt.num_levels);
        }
    }
}


f32 TObjPlayer::get_battle_value(u16 client, s16 technique) {
    if (get_player_by_client_id(client) == NULL) {
        return player_zero;
    }
    return get_class_technique_boost(get_class_index(), technique);
}

void TObjPlayer::load_action_motions(u16 entity_id) {
    if (action_provider) {
        action_provider->load_motions(entity_id);
    }
}

void TObjPlayer::update_facing_from_lock() {
    if (action_provider->is_male() != 0) {
        set_motion_list(action_provider->get_motion_list(1));
        return;
    }
    set_motion_list(action_provider->get_motion_list(0));
}

s32 TObjPlayer::get_regen_interval(s32 timer) {
    s32 level;
    level = get_actor_level_index();
    if (level > 99) {
        level = 99;
    }
    if (is_newman() != 0) {
        level *= 0.8;
        return 90 - level;
    }
    level *= 0.55;
    return 60 - level;
}

s32 TObjPlayer::tick_regen_timer() {
    s32 next;
    TObjPlayer *target;
    s32 ticked = 0;
    TObjPlayer *player;
    s32 timer = get_regen_timer();
    target = player = this;
    next = timer + 1;
    if (next >= target->get_regen_interval(timer)) {
        next = 0;
        ticked = 1;
    }
    player->set_regen_timer(next);
    return ticked;
}

int TObjPlayer::get_max_level() { return 199; }

void TObjPlayer::update_movement_effects() {
    if (TTecCtrl::is_technique_ready() != 0 && get_battle_place() == 0 && update_movement_by_screen() != 0 &&
        test_action_mask(0x408000) == 0 && is_body_collision_inactive() == 0 &&
        check_flag_800000() == 0) {
        follow_particles.emit_movement_effect();
    }
    if (is_body_collision_inactive() == 0 && test_action_mask(2) != 0 && contact_surface.has_water_ground_flag() != 0) {
        emit_idle_water_effect(&follow_particles);
    }
}

void TObjPlayer::apply_switch_attack() {
    if (is_body_collision_inactive() != 0 || check_flag_800000() != 0) {
        return;
    }
    follow_particles.emit_shifta_support();
}

void TObjPlayer::enemy_spawn_jellen_effect() {
    if (is_body_collision_inactive() != 0 || check_flag_800000() != 0) {
        return;
    }
    follow_particles.emit_jellen_support_effect_default();
}

void TObjPlayer::trigger_switch_attack() {
    if (is_body_collision_inactive() != 0 || check_flag_800000() != 0) {
        return;
    }
    follow_particles.emit_deband_support();
}

// The support-technique effects: none while the body is inactive or flag 0x800000 is set.
void TObjPlayer::enemy_spawn_zalure_effect() {
    if (is_body_collision_inactive() != 0 || check_flag_800000() != 0) {
        return;
    }
    follow_particles.emit_zalure_support();
}

void TObjPlayer::update_battle_control_if_unlocked() {
    if (is_body_collision_inactive() == 0) {
        follow_particles.prepare_heavy_attack_particles_default();
    }
}

void TObjPlayer::stop_force_if_alive() {
    if (this->is_locally_controlled() != 0) {
        pad_binding.set_controller(NULL);
    }
}

void TObjPlayer::init_local_pad_binding() {
    if (this->is_locally_controlled() != 0) {
        pad_binding.init(get_entity_id(), controller_port);
    }
}

s32 TObjPlayer::get_total_deaths() {
    return ((CharacterSaveRecord *)get_character_save_record(this->get_entity_id()))->death_count;
}

s32 TObjPlayer::is_player_valid_target(u16 client_index) {
    TObjPlayer *player;

    if (is_local_client(client_index) == 0) {
        return 0;
    }
    player = get_player_by_client_id(client_index);
    if ((is_palettex_enabled(client_index) == 0) || (player->is_controls_locked() != 0) || (player->reset_volopt_state() == 0)) {
        return 0;
    }
    return 1;
}

s32 TObjPlayer::is_single_screen() {
    return (u8) (TRaderMapCore::is_not_split_screen() == 1);
}

s32 TObjPlayer::is_camera_mode_active() {
    int result;

    result = 0;
    if ((TObjPlayer::check_camera_mode() != 0) && (get_game_play_mode() == 1)) {
        result = 1;
    }
    return (u8)((u8)result);
}

s32 TObjPlayer::is_camera_ready() {
    int result;

    result = 0;
    if ((TObjPlayer::check_camera_mode() != 0) && (get_game_play_mode() == 2)) {
        result = 1;
    }
    return (u8)((u8)result);
}

s32 TObjPlayer::is_final_phase() {
    return (u8)((u8) (get_main_phase() == 0xF));
}

void TObjPlayer::add_hp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_actor_hp_bonus(this, amount);
}

void TObjPlayer::add_tp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_actor_tp_bonus(this, amount);
}

void TObjPlayer::add_power_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_stat(amount);
    materials.try_add_item(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_mind_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_mst(amount);
    materials.add_item_count(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_evp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_evp(amount);
    materials.try_add_item_count_type2(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_dfp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_dfp(amount);
    materials.try_add_item_count_kind3(get_class_index__10TObjPlayerFv(this), 1);
}

// TObjPlayer::get_class_index as its callers see it: the whole return register.
// The material handlers an item use calls; the gain is five times larger
// while is_camera_mode_active() holds.
void TObjPlayer::add_luck_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_lck(amount);
    materials.add_item_count_kind4(get_class_index__10TObjPlayerFv(this), 1);
}

__declspec(section ".sdata2") extern const f32 player_zero = 0.0f;
__declspec(section ".sdata2") extern const char status_line_break[4] = "\n";
__declspec(section ".sdata2") extern f32 player_angle_per_degree = 182.04445f;
__declspec(section ".sdata2") extern f32 player_degrees_per_turn = 360.0f;
__declspec(section ".sdata2") extern f32 player_rand_unit = 3.0517578e-05f;
__declspec(section ".sdata2") extern f32 player_half = 0.5f;
__declspec(section ".sdata2") extern const f32 player_stick_deadzone = 0.1f;
__declspec(section ".sdata2") extern f32 player_one = 1.0f;
__declspec(section ".sdata2") extern const f32 player_velocity_epsilon = 1e-05f;
__declspec(section ".sdata2") extern const f32 player_velocity_neg_epsilon = -1e-05f;
__declspec(section ".sdata2") extern const f32 player_feedback_light_dir_y = -1.0f;
__declspec(section ".sdata2") extern const f32 player_feedback_light_green = 0.8f;
__declspec(section ".sdata2") extern const f32 player_feedback_light_blue = 0.63f;
__declspec(section ".sdata2") extern const f32 player_feedback_light_step = 0.2f;
__declspec(section ".sdata2") extern const f32 player_body_radius = 5.0f;
__declspec(section ".sdata2") extern const f32 player_wall_probe_margin = 4.0f;
__declspec(section ".sdata2") extern const f32 player_wall_facing_limit = -0.87f;
__declspec(section ".sdata2") extern const f32 player_front_distance = 20.0f;
__declspec(section ".sdata2") extern const f32 player_lock_range_sq = 2500.0f;
__declspec(section ".sdata2") extern const f32 player_lock_release_range_sq = 3600.0f;
__declspec(section ".sdata2") extern const f32 player_shadow_lift = 0.3f;
__declspec(section ".sdata2") extern const f32 player_view_detail_near = 150.0f;
__declspec(section ".sdata2") extern const f32 player_view_detail_far = 400.0f;
__declspec(section ".sdata2") extern const f32 player_shadow_range = 10.0f;
__declspec(section ".sdata2") extern const f32 player_rand_pick_limit = 0.99f;
__declspec(section ".sdata2") extern const f32 player_scale_initial = 0.4f;
