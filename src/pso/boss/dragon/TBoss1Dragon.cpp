#include "pso/enemy/EnemyStateRecord.h"
#include "pso/system/SubtractiveRng.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/animation/MotionContext.h"
#include "pso/ui/hud/TRaderMapCore.h"
struct NJS_OBJECT;
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/AccelerationCurve.h"
#include "pso/boss/TUnk_80481B34.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/enemy/EnemyStateEvent.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/system/ControllerInputState.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/system/NinjaTypes.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/dragon/TObjBoss1Rock.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/dragon/TObjBoss1Crater.h"
#include "pso/boss/dragon/TBoss1DragonDemo.h"
#include "pso/boss/dragon/TBoss1DragonEffBreath.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/dragon/TBoss1DragonEffTail.h"
#include "pso/boss/dragon/TBoss1DragonEffBullet.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_SoloM.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/model_render_state.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/player/PlayerSlots.h"
#include "types.h"

struct ByteBlock_C { u8 bytes[0xC]; };
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/object/base/TObjBase.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/network/client_id.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/object/TObjControl.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
struct DragonCaptureVectors { Vec vectors[3]; };
// The Dragon's block from TLobby::dispatch_shared_handler_a (boss1_dragon_behavior_param_ids): the powers and the
// landing radius its attacks put in their DragonAttackParams copies, the V2 speeds, and the body parts' defenses.
struct Boss1DragonParams {
    f32 breath_attack_power;   // deliver_breath_attack
    f32 fireball_impact_power; // apply_fireball_impact_damage; 0.666 of it for the craters
    f32 trail_attack_power;    // the burrow trail hit while the mound trail is damaging (apply_trail_attack)
    f32 landing_attack_radius; // apply_landing_attack: the hit body radius
    f32 walk_speed_scale;      // V2 walking speed scale (V1 uses 0.8)
    f32 flight_speed;          // V2 flight speed (V1 2.0); 256 times it is the turn speed
    s32 defense[3];            // update_body_colliders: [0] body 5, [1] bodies 1 and 2, [2] bodies 0, 3, 4, 6
};
struct DragonModelState { s32 state[2]; f32 params[4]; };
struct DragonEffectRotation { s32 x, y, z; };
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t);
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed);
extern "C" {
s32 get_current_floor();
f32 newton_sqrtf(f32);
s32 is_split_screen();
}
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
void dragon_capture_node_points(NJS_OBJECT *);
extern "C" {
extern const Vec boss1_dragon_arena_center = {0.0f, 0.0f, 0.0f};
extern const DragonAttackParams boss1_dragon_attack_sphere_params = {0, 0.0f, 30.0f, {7.0f, 1}};
extern const DragonAttackParams boss1_dragon_head_fall_attack_params = {0, 0.0f, 35.0f, {50.0f, 1}};
extern const DragonAttackParams boss1_dragon_ground_impact_params = {0, 10.0f, 25.0f, {7.5f, 1}};
extern const Vec boss1_dragon_death_impact_point_a = {-35.0f, 0.0f, 10.0f};
extern const Vec boss1_dragon_death_impact_point_b = {-60.0f, 0.0f, -20.0f};
extern const s32 boss1_dragon_normal_action_table[8] = {0x41, 0x4c, 0x223, 0xf0, 0x220, 0x221, 0x222, 0x225};
extern const s32 boss1_dragon_normal_particle_table[8] = {0x200, 0x201, 0x202, 0x94, 0x20d, 0x20c, 0x20b, 0x209};
extern const s32 boss1_dragon_capture_node_table[35] = {0, 8, 0xa, 0x28, 0x29, 0x32, 0x33, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x46, 0x47, 0x48, 0x4a, 0x4c, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x64, 0x66, 0x3e7};
s32 boss1_dragon_primary_sequence_table[8] = {2, 3, 4, 5, 6, 7, 8, 32};
s32 boss1_dragon_sequence_remap_table[8] = {0, 0, 2, 3, 3, 3, 0, 0};
s32 boss1_dragon_primary_sequence_table_b[10] = {2, 3, 2, 3, 4, 5, 6, 34, 8, 32};
s32 boss1_dragon_sequence_remap_table_b[10] = {0, 0, 2, 0, 2, 3, 3, 3, 0, 0};
s32 boss1_dragon_action_sequence_table[14] = {5, 6, 15, 16, 18, 17, 18, 17, 18, 19, 8, 2, 3, 33};
s32 boss1_dragon_action_sequence_table_b[13] = {5, 6, 15, 16, 18, 17, 18, 35, 19, 8, 2, 3, 33};
s32 boss1_dragon_attack_param_ids[5] = {0x12,0x14,0x15,0x16,0x17};
s32 boss1_dragon_behavior_param_ids[3] = {0x11,0x12,0x13};
s32 boss1_dragon_base_stat_indices[5] = { 0, 0, 0, 0, 0 };
s32 boss1_dragon_attack_stat_indices[5] = { 0, 1, 2, 3, 4 };
s32 boss1_dragon_resistance_stat_indices[5] = { 0, 0, 0, 0, 0 };
void *boss1_dragon_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
struct DragonCollisionBodyPartInit {
    f32 local_center[3];
    f32 radius;
    f32 field_10;
    s32 field_14;
    u32 flags;
    f32 world_center[3];
    f32 field_28;
};
DragonCollisionBodyPartInit boss1_dragon_collision_body_parts[7] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *boss1_dragon_model_names[3] = {
    "boss1_s_nb_dragon.nj",
    "boss1_s_sd_dragon.nj",
    NULL,
};
const char *boss1_dragon_motion_names[27] = {
    "bossop_boss1_s_nb_dragon.njm",
    "daml_boss1_s_nb_dragon.njm",
    "dams_boss1_s_nb_dragon.njm",
    "dead_boss1_s_nb_dragon.njm",
    "down_boss1_s_nb_dragon.njm",
    "fire_boss1_s_nb_dragon.njm",
    "flyshot_boss1_s_nb_dragon.njm",
    "fly_boss1_s_nb_dragon.njm",
    "frin_boss1_s_nb_dragon.njm",
    "frloop_boss1_s_nb_dragon.njm",
    "frout_boss1_s_nb_dragon.njm",
    "kiri_boss1_s_nb_dragon.njm",
    "land_boss1_s_nb_dragon.njm",
    "lift_boss1_s_nb_dragon.njm",
    "nkdown_boss1_s_nb_dragon.njm",
    "nkup_boss1_s_nb_dragon.njm",
    "nobi_boss1_s_nb_dragon.njm",
    "stand_boss1_s_nb_dragon.njm",
    "tatk_boss1_s_nb_dragon.njm",
    "tobidasi_boss1_s_nb_dragon.njm",
    "tukomi_boss1_s_nb_dragon.njm",
    "walk_boss1_s_nb_dragon.njm",
    "wgwalk_boss1_s_nb_dragon.njm",
    "wing_boss1_s_nb_dragon.njm",
    "wngclose_boss1_s_nb_dragon.njm",
    "wngopn_boss1_s_nb_dragon.njm",
    NULL,
};
BmlResourceDescriptor boss1_dragon_bml_descriptor = {"bm_boss1_dragon.bml", boss1_dragon_model_names, boss1_dragon_motion_names, 2, 26};
// inferred: the ids load_resources passes to TLobby::register_boss and TLobby::register_object
// (de_rol_le_base_param_ids / boss5_gryphon_base_param_ids twins)
s32 boss1_dragon_base_param_ids[1] = {0x12};
s32 boss1_dragon_register_object_ids[1] = {0x12};
const char *TBoss1Dragon__name = "TBoss1Dragon";
extern const DragonAttackParams TBoss1Dragon__foot_step_attack_params = {0, 10.0f, 15.0f, {8.0f, 1}};
extern const DragonAttackParams dragon_breath_attack_params = {0, 500.0f, 45.0f, {100.0f, 1}};
extern const DragonAttackParams dragon_fireball_attack_params = {1, 2.0f, 10.0f, {10.0f, 1}};
extern const DragonAttackParams dragon_fireball_impact_damage_params = {1, 10.0f, 30.0f, {10.0f, 1}};
extern const NJS_ARGB dragon_boss1_render_color = {0.2f, 0.0f, 0.0f, 0.0f};
TObjMotionAction boss1_dragon_motion_actions[27] = {
    {1, 0, 17, 0.5f, 0},
    {1, 0, 21, 0.5f, 0},
    {3, 0, 16, 0.7f, 0},
    {3, 0, 5, 0.9f, 0},
    {3, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.4f, 0},
    {3, 0, 10, 0.5f, 0},
    {3, 0, 18, 0.5f, 0},
    {2, 9, 14, 0.5f, 0},
    {1, 0, 4, 0.3f, 0},
    {3, 0, 15, 0.3f, 0},
    {3, 0, 2, 0.6f, 0},
    {3, 0, 1, 0.5f, 0},
    {3, 0, 25, 0.5f, 0},
    {3, 0, 24, 0.5f, 0},
    {3, 0, 13, 1.0f, 0},
    {1, 0, 7, 1.0f, 0},
    {2, 14, 12, 1.0f, 0},
    {2, 16, 6, 1.1f, 0},
    {3, 0, 3, 0.5f, 0},
    {1, 0, 23, 1.0f, 0},
    {1, 0, 22, 0.5f, 0},
    {3, 0, 20, 1.0f, 0},
    {1, 0, 11, 1.0f, 0},
    {2, 16, 19, 0.5f, 0x80000000},
    {3, 0, 0, 0.5f, 0x80000000},
    {2, 8, 2, 0.6f, 0},
};
static Vec boss1_dragon_follow_camera_target_offset[1] = {
    {0.0f, 19.8f, -5.0f},
};
static Vec boss1_dragon_follow_camera_eye_offset[1] = {
    {0.0f, 25.43f, 45.42f},
};
static Vec boss1_dragon_follow_camera_phase_target_offsets[3] = {
    {0.0f, 23.0f, -3.0f},
    {0.0f, 32.0f, 0.0f},
    {0.0f, 25.0f, -5.0f},
};
static Vec boss1_dragon_follow_camera_phase_eye_offsets[3] = {
    {0.0f, 11.0f, 40.0f},
    {0.0f, 5.0f, 35.0f},
    {0.0f, 50.0f, 60.0f},
};
static Vec boss1_dragon_held_camera_target_offsets[4] = {
    {0.0f, 20.0f, -120.0f},
    {0.0f, 120.0f, -120.0f},
    {0.0f, 25.0f, -30.0f},
    {0.0f, 50.0f, -80.0f},
};
static Vec boss1_dragon_held_camera_eye_offsets[4] = {
    {0.0f, 120.0f, 50.0f},
    {0.0f, 300.0f, -30.0f},
    {0.0f, 40.0f, 0.0f},
    {300.0f, 120.0f, 50.0f},
};
f32 atan2_float(f32 y, f32 x);
}
void handle_6x12_dragon_boss_actions(TObjPlayer *packet);
void handle_6x11_dragon_boss_actions(void *packet);
void handle_6x10_dragon_boss_actions(void *packet);
extern s32 enable_v2_features;
static const f64 boss1_dragon_angle_units_per_radian = 10430.38043493439;
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/player/TPlyDispData.h"
extern "C" {
AttackParams *boss1_dragon_part_hp_stats[5];
Boss1DragonParams *boss1_dragon_behavior_params[3];
Vec boss1_dragon_node_origin;
DragonCaptureVectors boss1_dragon_breath_local_points;
DragonModelState boss1_dragon_capture_chunk_model;
}
// The camera's xz position and its normalized xz direction to the camera target, set by render before it
// tests the model's points with is_sphere_visible (twins of boss8_dragon_reference_pos_vec and
// dragon_forward_reference_vec).
Vec boss1_dragon_reference_pos_vec;
Vec boss1_dragon_forward_reference_vec;
extern s32 registered_player_count;
extern "C" {
f64 floor(f64);
}
extern f32 lbl_805D9E80;
extern const f32 boss1_dragon_lift_accel = 3.0f * lbl_805D9E80;
extern const f32 TBoss1Dragon__gravity_accel = 2.0f * lbl_805D9E80;
f32 boss1_dragon_dive_accel = 5.0f * lbl_805D9E80;
f32 boss1_dragon_gravity = 7.0f * lbl_805D9E80;
player_stats *boss1_dragon_base_params[1];
ActorParamBlock *boss1_dragon_resistance_params[1];
BmlResource *boss1_dragon_resource;
s32 boss1_dragon_capture_node;
s32 boss1_dragon_breath_node;
Vec *boss1_dragon_breath_points_out;
s32 boss1_dragon_capture_cursor;
Vec *boss1_dragon_capture_points_out;
s32 boss1_dragon_capture_flags;
s32 boss1_dragon_model_node_count;
NJS_OBJECT *boss1_dragon_capture_model;
saddr boss1_dragon_main_instance;
f32 boss1_dragon_visibility_distance;
s32 boss1_dragon_hold_mode;
s32 boss1_dragon_player_control;
u16 boss1_dragon_control_client_id;
extern const f32 boss1_dragon_fall_accel = 5.0f * lbl_805D9E80;

void fill_value_array(PointerBuffer *buffer) {
    s32 i;
    for (i = 0; i < buffer->capacity; i++) {
        buffer->entries[i] = buffer->empty;
    }
    buffer->count = 0;
}

// Keep the individual field accesses used for the retail state-table copy.
void EnemyStateRecord::copy_header(const EnemyStateRecord *source) {
    volatile EnemyStateRecord *target = this;
    const volatile EnemyStateRecord *input = source;
    target->flags = input->flags;
    target->drop_id = input->drop_id;
    target->damage = input->damage;
    target->attack_status = input->attack_status;
    target->attack_status_level = input->attack_status_level;
    target->defense_status = input->defense_status;
    target->defense_status_level = input->defense_status_level;
}

s32 TObjEnemy::exchange_object_state(void *record, s16 mode) {
    s16 index;
    index = this->set_index;
    if ((index < 0) || (index > 0xB4F)) {
        return 0;
    }
    if (mode == 0) {
        TLobby__data_805D6144[index].copy_header(static_cast<const EnemyStateRecord *>(record));
    }
    if (mode == 1) {
        static_cast<EnemyStateRecord *>(record)->copy_header(&TLobby__data_805D6144[index]);
    }
    return 1;
}

void TObjPlayer::bswap_stats() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

void TObjPlayer::bswap_dragon_boss_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

void TObjPlayer::set_type_dragon() { *(u8*)((char*)this + 0x0) = 18; *(u8*)((char*)this + 0x1) = 5; }

void TObjPlayer::bswap_6x12_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

void TObjPlayer::send_6x12_packet() { bswap_6x12_packet(); send_subcommand((u8 *)this); }

void ProtectionTimer::set_frames(s32 v) { frames = v; }

void ProtectionTimer::reset_type() { frames = 0; }

void ProtectionTimer::reset_lobby_model() { reset_type(); }

void TObjMotion::set_action_table(TObjMotionAction *actions) { action_table = actions; }

void TObjMotion::set_motion_list(BmlMotionEntry *motions) { motion_list = motions; }

void TObjMotion::set_requested_action(s16 v) { this->requested_action = v; }

void TObjMotion::enable_motion_blend() {
    this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFFE);
}

void MaterialColorFade::set_speed(f32 v) { rate = v; }

s32 TWindowKeyBoardHard::test_card_flag_2(s32 client_id) { return TWindowKeyBoardHard::test_card_flag(client_id, 2); }

extern "C" {
s32 fn_8002AE08(s32 client_id) {
    return TWindowKeyBoardHard::test_card_flag_2(client_id) ? 0x20000 : 0x10000;
}

f32 floor_to_float(f32 value) {
    return (f32) floor((f64)value);
}

}
int TObjEneDD::get_flag_b4() { return (this->motion_flags >> 4) & 0x1; }

s32 TCameraCtrl::get_camera_mode() {
    return TCameraCtrl::camera_mode;
}

s32 TLobby::get_game_mode() {
    return registered_player_count;
}

void TBoss1Dragon::clear_harmful_statuses() {  }

void TBoss1Dragon::apply_shock_status() {  }

void TBoss1Dragon::apply_movement_ailment(s32) {  }

void TBoss1Dragon::apply_confusion_status() {  }

void TBoss1Dragon::apply_slow_status() {  }

void TBoss1Dragon::apply_paralysis() {  }

void TBoss1Dragon::apply_poison_status() {  }

s32 TBoss1Dragon::countModelNodes(NJS_OBJECT* source) {
    s32 count=1;
    NJS_OBJECT* child=source->child;
    if(child!=0)count=countModelNodes(child)+1;
    NJS_OBJECT* sibling=source->sibling;
    if(sibling!=0)count+=countModelNodes(sibling);
    return count;
}

#pragma push
#pragma scheduling off
void copy_model_node(NJS_OBJECT *dst, const NJS_OBJECT *src) {
    dst->evalflags = src->evalflags;
    dst->model = src->model;
    *reinterpret_cast<ByteBlock_C *>(dst->pos) = *reinterpret_cast<const ByteBlock_C *>(src->pos);
    *reinterpret_cast<ByteBlock_C *>(dst->ang) = *reinterpret_cast<const ByteBlock_C *>(src->ang);
    *reinterpret_cast<ByteBlock_C *>(dst->scl) = *reinterpret_cast<const ByteBlock_C *>(src->scl);
    dst->child = src->child;
    dst->sibling = src->sibling;
    dst->quat_w = src->quat_w;
}
#pragma pop

NJS_OBJECT* TBoss1Dragon::cloneModelHierarchy(NJS_OBJECT* source, NJS_OBJECT* output, void* model) {
    NJS_OBJECT* current = output;
    ++output;
    copy_model_node(current, source);
    current->model = model;
    if (source->child != 0) {
        current->child = output;
        output = cloneModelHierarchy(source->child, output, model);
    }
    if (source->sibling != 0) {
        current->sibling = output;
        output = cloneModelHierarchy(source->sibling, output, model);
    }
    return output;
}

TUnk_80481B34::TUnk_80481B34(TObject *parent, TObjBase *owner) : TUnk_804928CC(parent, owner) {
}

TUnk_80481B34::~TUnk_80481B34() {

}

void apply_dragon_hit_ailment(TObjChara *target) {
    if (target->obj_isState2_324() == 0) {
        target->apply_movement_ailment(0);
    }
}

void TUnk_80481B34::area_attack_receive_direct(void *target, f32 *, void *payload) {
    TObjChara *chara = (TObjChara *)target;
    s32 i;
    CollisionBody *e;

    for (i = 0; i < chara->body_count; i++) {
        e = &chara->bodies[i];
        if (e->flags & 0x04000000) {
            DirectAttackPayload attack = *(DirectAttackPayload *)payload;
            chara->receive_direct_attack((void *)this->owner, attack, e, -1, -1);
            apply_dragon_hit_ailment(chara);
            return;
        }
    }
}

void TUnk_80481B34::apply_hit_if_active(void *target, f32 *) {
    ((TObjChara *)target)->receive_physical_attack((void *)this->owner, 1.0f);
    apply_dragon_hit_ailment((TObjChara *)target);
}

saddr TBoss1Dragon::get_instance() {
    return boss1_dragon_main_instance;
}

void get_dragon_follow_camera_offsets(Vec *target_offset, Vec *eye_offset) {
    if ((void *) (*(u8 * *)&boss1_dragon_main_instance) == NULL) {
        VecCopy(target_offset, boss1_dragon_follow_camera_target_offset);
        VecCopy(eye_offset, boss1_dragon_follow_camera_eye_offset);
        return;
    }
    ((TBoss1Dragon *)boss1_dragon_main_instance)->calc_follow_camera_offsets(target_offset, eye_offset);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::calc_follow_camera_offsets(Vec *target_offset, Vec *eye_offset) {
    s32 phase;
    Vec *limit;

    if (((TBoss1Dragon *)boss1_dragon_main_instance)->mode == 0x16) {
        VecCopy(target_offset, boss1_dragon_follow_camera_target_offset);
        VecCopy(eye_offset, boss1_dragon_follow_camera_eye_offset);
        return;
    }
    switch (this->phase) {
    case 0:
    default:
        phase = 0;
        break;
    case 1:
        phase = 1;
        break;
    case 2:
        phase = 2;
        break;
    }
    VecCopy(target_offset, boss1_dragon_follow_camera_phase_target_offsets + phase);
    VecCopy(eye_offset, boss1_dragon_follow_camera_phase_eye_offsets + phase);
    if (this->camera_eye_raised == 1) {
        eye_offset->y += 10.0f;
        eye_offset->z += 10.0f;
    }
    if (this->player_controlled != 0 && this->target_client_id == local_client_id) {
        if (this->mode == 0xF) {
            VecCopy(target_offset, boss1_dragon_held_camera_target_offsets + 3);
            limit = boss1_dragon_held_camera_eye_offsets + 3;
            target_offset->y += (0.5f) * this->height;
            VecCopy(eye_offset, limit);
            eye_offset->x = (0.0f);
            eye_offset->y += this->height;
            if (eye_offset->y > limit->x) {
                eye_offset->y = limit->x;
            } else if (eye_offset->y < 10.0f) {
                eye_offset->y = (1.0f);
            }
        } else {
            VecCopy(target_offset, boss1_dragon_held_camera_target_offsets + phase);
            VecCopy(eye_offset, boss1_dragon_held_camera_eye_offsets + phase);
        }
        target_offset->y += 200.0f;
        eye_offset->y += 200.0f;
    }
}

#pragma pop
#pragma push
#pragma opt_propagation off
void TBoss1Dragon::load_resources() {
    NJS_OBJECT *source;
    NJS_MKEY_F *nodes;
    s32 *table;
    void *out;
    Vec *capture;
    Vec *delta;
    s32 i;

    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        boss1_dragon_resource = load_enemy_bml_resource(&boss1_dragon_bml_descriptor);
        break;
    case 1:
        boss1_dragon_resource = load_enemy_bml_resource_named(&boss1_dragon_bml_descriptor, "bm_boss1_dragon_a.bml");
        break;
    }
    source = boss1_dragon_resource->models[0].model;
    boss1_dragon_model_node_count = TBoss1Dragon::countModelNodes(source);
    boss1_dragon_capture_model = static_cast<NJS_OBJECT *>(TQuestVmDownLoadServer::alloc(boss1_dragon_model_node_count * 0x50));
    boss1_dragon_capture_chunk_model.state[0] = 0;
    boss1_dragon_capture_chunk_model.state[1] = 0;
    boss1_dragon_capture_chunk_model.params[0] = (0.0f);
    boss1_dragon_capture_chunk_model.params[1] = (0.0f);
    boss1_dragon_capture_chunk_model.params[2] = (0.0f);
    boss1_dragon_capture_chunk_model.params[3] = (0.0f);
    source = boss1_dragon_resource->models[0].model;
    TBoss1Dragon::cloneModelHierarchy(source, boss1_dragon_capture_model, boss1_dragon_capture_chunk_model.state);

    boss1_dragon_capture_node = 0;
    boss1_dragon_breath_node = 0x3C;
    boss1_dragon_node_origin.x = (0.0f);
    boss1_dragon_node_origin.y = (0.0f);
    boss1_dragon_node_origin.z = (0.0f);
    boss1_dragon_breath_local_points.vectors[0].x = (0.0f);
    boss1_dragon_breath_local_points.vectors[0].y = (0.0f);
    boss1_dragon_breath_local_points.vectors[0].z = (5.0f);
    capture = &boss1_dragon_breath_local_points.vectors[0];
    delta = capture + 1;
    delta->x = (0.0f);
    boss1_dragon_breath_local_points.vectors[1].y = sin_table_lookup(-0x1555);
    boss1_dragon_breath_local_points.vectors[1].z = cos_table_lookup(-0x1555);
    vec3_add_to(delta, &boss1_dragon_breath_local_points.vectors[0]);
    boss1_dragon_breath_local_points.vectors[2].x = (0.0f);
    boss1_dragon_breath_local_points.vectors[2].y = (-1.0f);
    boss1_dragon_breath_local_points.vectors[2].z = (1.0f);
    boss1_dragon_breath_points_out = NULL;
    boss1_dragon_capture_cursor = 0;
    boss1_dragon_capture_points_out = NULL;
    boss1_dragon_capture_flags = 0;
    boss1_dragon_main_instance = 0;

    NJS_MOTION *landing_motion = reinterpret_cast<NJS_MOTION *>(boss1_dragon_resource->motions[13].motion);
    NJS_MDATA2 *data = static_cast<NJS_MDATA2 *>(landing_motion->mdata);
    for (i = 0; i < 1; i++) {
        nodes = static_cast<NJS_MKEY_F *>(data[i].p[0]);
        nodes[25].key[1] -= 0.2f;
        nodes[26].key[1] -= 0.3f;
        nodes[27].key[1] -= 0.6f;
        nodes[28].key[1] -= (0.8f);
        nodes[29].key[1] -= (1.0f);
        nodes[30].key[1] -= 1.25f;
        nodes[31].key[1] -= 1.25f;
        nodes[32].key[1] -= 1.25f;
        nodes[33].key[1] -= 1.25f;
        nodes[34].key[1] -= 0.85f;
        nodes[35].key[1] -= 0.35f;
        nodes[36].key[1] += 0.4f;
        nodes[37].key[1] += 2.3f;
    }
    nodes[38].key[1] += 7.9f;
    nodes[39].key[1] += 18.5f;
    nodes[40].key[1] += (30.0f);

    NJS_MOTION *falling_motion = reinterpret_cast<NJS_MOTION *>(boss1_dragon_resource->motions[12].motion);
    data = static_cast<NJS_MDATA2 *>(falling_motion->mdata);
    nodes = static_cast<NJS_MKEY_F *>(data->p[0]);
    nodes[41].key[1] += 21.0f;
    nodes[42].key[1] += 20.5f;
    nodes[43].key[1] += (20.0f);
    nodes[44].key[1] += 19.0f;
    nodes[45].key[1] += 16.5f;
    nodes[46].key[1] += 12.25f;
    nodes[47].key[1] += 8.6f;
    nodes[48].key[1] += 4.1f;
    nodes[50].key[1] -= (2.5f);
    nodes[51].key[1] -= (4.0f);
    nodes[52].key[1] -= 4.1f;
    nodes[53].key[1] -= 2.75f;
    nodes[54].key[1] -= 1.65f;
    nodes[55].key[1] -= (0.5f);

    out = boss1_dragon_base_params;
    for (s32 i = 0; i < 1; i++) { static_cast<player_stats **>(out)[i] = TLobby::register_boss(boss1_dragon_base_param_ids[i]); }
    table = boss1_dragon_attack_param_ids;
    out = boss1_dragon_part_hp_stats;
    for (s32 i = 0; i < 5; i++) {
        static_cast<AttackParams **>(out)[i] = TLobby::dispatch_shared_handler_b(table[i]);
    }
    for (s32 i = 0; i < 1; i++) { boss1_dragon_resistance_params[i] = TLobby::register_object(boss1_dragon_register_object_ids[i]); }
    for (s32 i = 0; i < 3; i++) {
        boss1_dragon_behavior_params[i] = (Boss1DragonParams *)TLobby::dispatch_shared_handler_a(boss1_dragon_behavior_param_ids[i]);
    }
    boss1_dragon_hold_mode = 0;
    boss1_dragon_player_control = 0;
    boss1_dragon_control_client_id = 0xFFFF;
    TWindowCtrl::init_all_slots();
    TBoss1Dragon::select_fireball_particle_table();
}

#pragma pop
void *TBoss1Dragon::create(void *set_data) {
    set_story_flag_or_send_quest_flag(0x16);
    return new TBoss1Dragon(tl_04, set_data);
}

void TBoss1Dragon::free_resources() {
    if ((u32) boss1_dragon_capture_model != 0U) {
        safe_free(boss1_dragon_capture_model);
        boss1_dragon_capture_model = 0U;
    }
    if (boss1_dragon_resource != NULL) {
        delete boss1_dragon_resource;
        boss1_dragon_resource = NULL;
    }
}

void TBoss1Dragon::requestActionRefresh() {
    boss1_dragon_hold_mode = 1;
}

void TBoss1Dragon::setControlOverride(s16 controlId) {
    if (enable_v2_features != 0) {
        boss1_dragon_control_client_id = controlId;
        boss1_dragon_player_control = 1;
    }
}

void TBoss1Dragon::clearControlOverride() {
    boss1_dragon_player_control = 0;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
TBoss1Dragon::TBoss1Dragon(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    u32 state[3];
    s32 i;
    s32 j;

    __ct__14SubtractiveRngFv(this->randomState);
    this->m_name = TBoss1Dragon__name;
    if ((u32)boss1_dragon_main_instance == 0U) {
        boss1_dragon_main_instance = (saddr)this;
    }
    this->invoke_initialization_hook(set_data);
    this->flags = 0;
    if (this->exchange_object_state(state, 1) != 0 && (state[0] & 0x12008) == 0x12008) {
        this->flags |= 0x40;
    }
    this->init_position_vectors();
    this->model = boss1_dragon_resource->models[0].model;
    this->texlist = boss1_dragon_resource->models[0].texlist;
    this->init_model((CollisionBody *)boss1_dragon_collision_body_parts, (s32)7);
    this->motion_flags = 0;
    this->set_action_table(boss1_dragon_motion_actions);
    this->set_motion_list(boss1_dragon_resource->motions);
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    this->reset_hp(boss1_dragon_base_params[boss1_dragon_base_stat_indices[0]], boss1_dragon_part_hp_stats[boss1_dragon_attack_stat_indices[0]], boss1_dragon_resistance_params[boss1_dragon_resistance_stat_indices[0]]);
    this->set_state_flag_1();
    this->movementParameters = boss1_dragon_init_params;
    this->initialize_enemy_state(0x2C);
    this->wall_reach = (20.0f);
    this->enemy_init_acquire_period(10);
    this->enemy_init_validate_period(10);
    this->phase = 0;
    this->flags |= 0x100;
    for (i = 0; i < 3; i++) {
        VecCopy(&this->breath_node_points[i], &this->position);
    }
    VecCopy(&this->breath_origin, &this->position);
    VecCopy(&this->breath_direction, &this->position);
    VecCopy(&this->breath_effect_position, &this->position);
    for (i = 0; i < 0x22; i++) {
        VecCopy(&this->node_positions[i], &this->position);
    }
    this->target_vector.x = (0.0f);
    this->target_vector.y = (0.0f);
    this->target_vector.z = (0.0f);
    this->target_distance = (0.0f);
    this->height = (0.0f);
    this->defaultHeightOffset = (0.0f);
    this->heightOffset = this->defaultHeightOffset;
    this->pad_5e4 = (0.0f);
    this->last_flight_direction.x = (0.0f);
    this->last_flight_direction.y = (0.0f);
    this->last_flight_direction.z = (0.0f);
    this->curve0.reset_coords();
    this->curve1.reset_coords();
    VecCopy(&this->sound_origin, &this->position);
    VecCopy(&this->last_body_center, &this->position);
    this->camera_eye_raised = 0;
    this->airTurnVelocity = 0;
    this->airTurnDirection = 1;
    this->airTurnAcceleration = (0.0f);
    this->airTurnFinalAcceleration = (0.0f);
    this->airTurnTime = (0.0f);
    this->sequenceCursor = 0;
    this->hpThreshold = 0;
    this->finalHpThreshold = this->hpmax * 3 / 10;
    this->stat_block->proportions = 10.0f;
    this->update_damage_threshold();
    this->tail = new TBoss1DragonEffTail(this, &this->node_positions[15]);
    this->attack_history = new AreaAttackHistory(4);
    this->collider = new TBoss1DragonColli(&this->sub_tasks);
    this->destinationX = (0.0f);
    this->destinationZ = (0.0f);
    this->savedX = (0.0f);
    this->savedZ = (0.0f);
    this->sector_count = 0;
    this->crater_count = 0;
    for (i = 0; i < 12; i++) {
        this->sector_radii[i] = (0.0f);
    }
    this->moko_hill = new TObjBoss1MokoHill_SoloM(tl_05, &this->position, &this->rotation_y);
    this->burrow_run_count = 0;
    for (j = 0; j < 4; j++) {
        this->viewFade[j].activate_and_dispatch();
    }
    this->pad_758 = 0;
    this->pad_75c = 0xA8C;
    this->player_controlled = 0;
    this->target_client_id = 0xFFFF;
    this->controlTimer = 0;
    this->facingAngle = 0;
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        this->attack_kind = 1;
        this->effectResource = (DragonEffectResource *)boss1_dragon_normal_action_table;
        break;
    case 1:
        this->attack_kind = 0x13;
        this->effectResource = (DragonEffectResource *)boss1_dragon_normal_particle_table;
        break;
    }
    this->attack_collider = new TUnk_80481B34(NULL, this);
    this->stateStep = 0;
    this->impactAge = 0;
    this->action_frames = 0;
    this->demo_flag = 0;
    this->action_angle = 0;
    this->action_spin = 0;
    this->fallVelocity = (0.0f);
    this->rootHeight = (0.0f);
    this->action_speed = (0.0f);
    this->vertical_speed = (0.0f);
    this->root_height_speed = (0.0f);
    this->action_point.x = (0.0f);
    this->action_point.y = (0.0f);
    this->action_point.z = (0.0f);
    this->pad_89c = (0.0f);
    this->pad_8a0 = (0.0f);
    this->pad_8a4 = (0.0f);
    this->ground_impact_done = 0;
    this->breath_particles[0] = 0;
    this->breath_particles[1] = 0;
    this->breath_particles[2] = 0;
    this->controller_input = &controller_input_state.controllers[2];
    this->lobby_state_locked = 0;
    this->mode = 0;
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (this->update_lobby_state() != 0) {
            this->lobby_state = 0;
        } else {
            this->lobby_state = 1;
        }
    } else {
        this->lobby_state = 0;
    }
    this->restart_primary_sequence();
    this->mode = 0x1D;
    if (!(this->flags & 0x40)) {
        this->dispatch_action(this->mode, 4);
    }
    this->lobby_state_changed = 0;
}

#pragma pop
TBoss1Dragon::~TBoss1Dragon() {
    if (this->attack_collider != 0) {
        delete this->attack_collider;
        this->attack_collider = 0;
    }
    if (this->moko_hill != 0) {
        this->moko_hill->queue_destruction();
        this->moko_hill = 0;
    }
    if (this->collider != 0) {
        delete this->collider;
        this->collider = 0;
    }
    if (this->attack_history != 0) {
        delete this->attack_history;
        this->attack_history = 0;
    }
    if (this->tail != 0) {
        delete this->tail;
        this->tail = 0;
    }
    free_collision_body_parts(this);
    if ((TBoss1Dragon *)boss1_dragon_main_instance == this) {
        boss1_dragon_main_instance = 0;
    }
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::run_task() {
    s16 mode;
    s32 state;
    s32 old_state;
    s32 teammate_state;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->flags & 0x40) {
        this->send_entity_set_flags();
        this->queue_destruction();
        return;
    }
    if ((s32) this->player_controlled != 0) {
        this->hold_captured_player();
        this->controlTimer = (s32) (this->controlTimer + 1);
    } else if ((TObjEneDD::is_main_phase_15() != 0) && ((s32) this->lobby_state_locked == 0)) {
        old_state = this->lobby_state;
        if (this->update_lobby_state() != 0) {
            this->lobby_state = 0;
            if ((s32) this->lobby_state != old_state) {
                this->lobby_state_changed = 1;
            }
        } else {
            this->lobby_state = 1;
        }
    }
    teammate_state = TObjEneDD::query_teammate_state();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (teammate_state == 0) {
        mode = this->mode;
        if ((mode == 0x15) || (mode == 0x16)) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        if ((s32) this->player_controlled != 0) {
            if ((s32) this->target_client_id == (s32) local_client_id) {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    ;
                    if ((s16) this->hp < (s16) this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if ((s32) boss1_dragon_player_control == 0) {
                    this->release_held_player();
                } else {
                    this->check_death();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    ;
                    if ((s16) this->hp < (s16) this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if ((s32) boss1_dragon_player_control == 0) {
                    this->release_held_player();
                }
                this->dispatch_action(this->mode, 0);
            }
        } else {
            state = this->lobby_state;
            if (state != 1) {
                if (state == 2) {
                    this->dispatch_action(this->mode, 2);
                } else {
                    if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                        ;
                        if ((s16) this->hp < (s16) this->finalHpThreshold) {
                            this->hp = this->finalHpThreshold;
                        }
                        this->clear_attack_receipts();
                    }
                    this->choose_next_action();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    ;
                    if ((s16) this->hp < (s16) this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                this->dispatch_action(this->mode, 0);
            }
        }
    }
    this->sub_800BBA0C();
    this->update_body_colliders();
    this->update_position_history();
    this->submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, (f32) (((2.0f))));
    VecCopy(&this->last_body_center, &this->body_center);
    if (teammate_state == 0) {
        this->sub_tasks.run_tasks();
    }
    project_sound_origin_from_camera(&this->position, &this->sound_origin, 0.4f);
}

#pragma pop
void TBoss1Dragon::choose_next_action() {
    if (this->is_primary_sequence() != 0) {
        if (!(this->flags & 0x400)) {
            if (update_max_hp_phase() == 0) {
                if (check_phase_advance() != 0) {
                    return;
                }
                goto block_12;
            }
        } else {
            goto block_12;
        }
    } else {
        if (!(this->flags & 0x800) && (this->hp <= 0)) {
            if ((s32) this->phase == 1) {
                if ((s32) enable_v2_features != 0) {
                    this->request_state_change(0xC);
                    return;
                }
                transition_enemy_state(0xC);
                return;
            }
            this->request_state_change(0x15);
            return;
        }
block_12:
        if ((s32) boss1_dragon_hold_mode != 0) {
            this->dispatch_action(this->mode, 2);
            return;
        }
        if ((s32) this->player_controlled != 0) {
            this->dispatch_action(this->mode, 0xB);
            return;
        }
        this->dispatch_action(this->mode, 9);
    }
}

void TBoss1Dragon::check_death() {
    if (this->is_primary_sequence() != 0) {
        if (update_max_hp_phase() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->flags & 0x800) && ((s32) this->hp <= 0)) {
        if ((s32) this->phase == 1) {
            this->request_state_change(0xC);
            return;
        }
        this->request_state_change(0x15);
        return;
    }
block_8:
    this->dispatch_action(this->mode, 0xB);
}

void TBoss1Dragon::refresh_target() {  }

void TBoss1Dragon::run_death_reaction() {  }

void TBoss1Dragon::run_hit_reaction() {  }

void TBoss1Dragon::run_miss_reaction() {  }

void TBoss1Dragon::update_position_history() {
    VecCopy(&this->body_center, &this->node_positions[0]);
    VecCopy(&this->center, &this->body_center);
}

void TBoss1Dragon::update_body_colliders() {
    Vec pts[7];
    Vec *p;
    f32 lim;
    s32 off;
    s32 i;
    CollisionBody *c;
    p = pts;
    VecCopy(p++, this->node_positions);
    VecCopy(p++, &this->node_positions[5]);
    VecCopy(p++, &this->node_positions[3]);
    VecCopy(p++, &this->node_positions[1]);
    VecCopy(p++, &this->node_positions[32]);
    VecCopy(p++, &this->node_positions[12]);
    VecCopy(p, &this->node_positions[17]);
    update_local_colliders_from_world(this, pts);
    lim = (30.0f);
    i = 0;
    off = 0;
    do {
        c = &this->bodies[i];
        if (c->offset.y >= lim) {
            set_collider_contact_high(c);
        } else {
            set_collider_contact_low(c);
        }
        i++;
        off += 0x2C;
    } while (i < 7);
    if (this->mode != 9) {
        set_collider_contact_high(&this->bodies[3]);
        set_collider_contact_high(&this->bodies[4]);
    }
    this->bodies[0].unk_28 = boss1_dragon_behavior_params[0]->defense[2];
    this->bodies[1].unk_28 = boss1_dragon_behavior_params[0]->defense[1];
    this->bodies[2].unk_28 = boss1_dragon_behavior_params[0]->defense[1];
    this->bodies[3].unk_28 = boss1_dragon_behavior_params[0]->defense[2];
    this->bodies[4].unk_28 = boss1_dragon_behavior_params[0]->defense[2];
    this->bodies[5].unk_28 = boss1_dragon_behavior_params[0]->defense[0];
    this->bodies[6].unk_28 = boss1_dragon_behavior_params[0]->defense[2];
}

s32 TBoss1Dragon::update_linked_epsilon_position() {
    return this->update_linked_position(1000.0f);
}

void TBoss1Dragon::calc_target_vector() {
    this->target_vector.x = this->destination.x - this->breath_origin.x;
    this->target_vector.y = 0.0f;
    this->target_vector.z = this->destination.z - this->breath_origin.z;
    this->target_distance = normalize_vector_xz(&this->target_vector);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::calc_forward_point(f32 *x, f32 *z) {
    *x = (185.0f * sin_table_lookup(this->rotation_y)) + this->position.x;
    *z = (185.0f * cos_table_lookup(this->rotation_y)) + this->position.z;
}

#pragma pop
s32 TBoss1Dragon::is_destination_ahead() {
    Vec pt;
    Vec diff;
    Vec unused;

    this->calc_forward_point(&pt.x, &pt.z);
    VecCopy(&diff, &this->destination);
    subtract_vector(&diff, &pt);
    return normalize_vector_xz((Vec *)&diff) <= (35.0f);
}

f32 TBoss1Dragon::sample_root_height() {
    struct Vec v;
    v.x = (0.0f);
    v.y = (0.0f);
    v.z = (0.0f);
    push_matrix_from(identity_matrix);
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    bind_motion_context((NJS_MOTION *)this->current_motion, this->frame);
    compose_motion_node_matrix(this->model);
    matrix_mult_vec(NULL, &v, &v);
    pop_matrix();
    return v.y;
}

void TBoss1Dragon::restart_primary_sequence() {
    select_sequence(0);
}

void TBoss1Dragon::select_sequence(int secondary) {
    if (secondary == 0) {
        sequenceCursor = 0;
        return;
    }
    sequenceCursor = 50;
}

s32 TBoss1Dragon::is_primary_sequence() {
    return sequenceCursor < 50;
}

s32 TBoss1Dragon::is_secondary_sequence() {
    return (u8)(sequenceCursor >= 50);
}

void TBoss1Dragon::update_damage_threshold() {
    s16 current = this->hp;
    s32 hp = this->hpmax;
    s16 step = hp / 10;
    s16 threshold = hp - step;
    step += step;
    while (current <= threshold) {
        threshold -= step;
    }
    hpThreshold = threshold;
}

s32 TBoss1Dragon::select_air_fire_target(Vec *out) {
    TObjChara *p;
    TObjChara *list[12];
    s32 top;
    s32 count;
    s32 i;
    s32 best;
    Vec *apos;
    TObjChara *a;
    TObjChara *b;
    s32 found;
    s32 i2;
    s32 j;
    f32 range;
    s32 sum;
    range = 6400.0f;
    count = 0;
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (((TObjEneDD *)p)->is_valid_target() != 0 && horizontal_distance_squared(&p->position, &this->position) >= range) {
            list[count++] = p;
        }
    }
    if (count <= 0) {
        return 0;
    }
    if (count == 1) {
        VecCopy(out, &list[0]->position);
    } else {
        range = (100.0f);
        best = 0;
        found = 0;
        for (i2 = 0; i2 < count; i2++) {
            a = list[i2];
            apos = &a->position;
            for (j = i2 + 1; j < count; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(&b->position, apos)) < range) {
                    found = 1;
                    sum = a->hp + b->hp;
                    if (sum > best) {
                        best = sum;
                        out->x = (0.5f) * (apos->x + b->position.x);
                        out->y = (0.5f) * (apos->y + b->position.y);
                        out->z = (0.5f) * (apos->z + b->position.z);
                    }
                }
            }
        }
        if (found == 0) {
            s32 k;
            top = 0;
            for (k = 0; k < count; k++) {
                if (top < list[k]->hp) {
                    top = list[k]->hp;
                    VecCopy(out, &list[k]->position);
                }
            }
        }
    }
    return 1;
}

s32 TBoss1Dragon::choose_burrow_ring_destination(Vec *out) {
    s32 idx;
    f32 r;
    idx = (s32)floor_to_float((12.0f) * this->random_ratio());
    if (this->sector_count < 12) {
        this->sector_count++;
        while ((0.0f) != this->sector_radii[idx]) {
            idx++;
            if (idx >= 12) {
                idx = 0;
            }
        }
        r = this->rand_range((100.0f), (220.0f));
        this->sector_radii[idx] = r;
    } else {
        r = this->sector_radii[idx];
    }
    out->x = r * sin_table_lookup(idx * 0x1555);
    out->y = (0.0f);
    out->z = r * cos_table_lookup(idx * 0x1555);
    return 1;
}

void TBoss1Dragon::prepare_flight_destination(Vec *dest) {
    if (this->is_primary_sequence() != 0) {
        VecCopy(&this->destination, &this->position);
        this->destination.y = 0.0f;
        normalize_vector_xz(&this->destination);
        this->destination.x *= -100.0f;
        this->destination.z *= -100.0f;
        return;
    }
    VecCopy(&this->destination, &boss1_dragon_arena_center);
}

s32 TBoss1Dragon::select_forward_target() {
    u16 selected[4];
    Vec delta;
    Vec fwd;
    f32 cutoff;
    s32 n;
    s32 count;
    TObjPlayer *p;
    s32 i;
    n = 0;
    count = TLobby::get_game_mode();
    if (count > 4) {
        count = 4;
    }
    cutoff = cos_table_lookup(0x3000);
    fwd.x = sin_table_lookup(this->rotation_y);
    fwd.y = (0.0f);
    fwd.z = cos_table_lookup(this->rotation_y);
    for (i = 0; i < count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p->is_alive() != 0) {
            VecCopy(&delta, &p->position);
            subtract_vector(&delta, &this->position);
            normalize_vector_xz((Vec *)&delta);
            if (vec3_dot(&delta, &fwd) > cutoff) {
                selected[n++] = p->get_entity_id();
            }
        }
    }
    if (n <= 0) {
        this->enemy_clear_target();
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(this, selected[0]);
        return 1;
    }
    enemy_set_target_id(this, selected[(s32)floor_to_float((f32)n * this->random_ratio())]);
    return 1;
}

void TBoss1Dragon::play_se_at_pos(s32 id) {
    play_sound_effect(id, &this->sound_origin, 0, 0);
}

void TBoss1Dragon::spawn_trap(s32 id) {
    play_persistent_sound(id, this, &this->sound_origin, 0, 0);
}

void TBoss1Dragon::play_sound_if_in_band() {
    if ((this->is_passing_frame(4.0f) != 0) || (this->is_passing_frame(24.5f) != 0)) {
        this->play_se_at_pos(0x4003A801);
    }
}

void TBoss1Dragon::play_nearby_se() {
    if (this->is_passing_frame((5.0f)) != 0) {
        this->play_se_at_pos(0x4003A804);
    }
}

void TBoss1Dragon::clearState() {
    phase = 0;
}

void TBoss1Dragon::setActive() {
    phase = 1;
}

void TBoss1Dragon::setPhase2() {
    phase = 2;
}

void TBoss1Dragon::beginHeightTransition() {
    flags |= 0x100;
    height = position.y;
    heightOffset = defaultHeightOffset;
}

void TBoss1Dragon::set_flight_height() {
    this->flags = (s32) (this->flags | 0x100);
    this->height = (f32) (180.0f + this->position.y);
    this->heightOffset = (f32) (180.0f + this->defaultHeightOffset);
}

void TBoss1Dragon::set_burrow_height() {
    this->flags = (s32) (this->flags & 0xFFFFFEFF);
    this->height = (f32) ((-400.0f) + this->position.y);
    this->heightOffset = (f32) ((-400.0f) + this->defaultHeightOffset);
}

void TBoss1Dragon::set_air_turn_direction(s32 angle, s32 target_angle) {
    if (angle_diff_s16(angle, target_angle) >= 0) {
        this->airTurnDirection = 1;
        return;
    }
    this->airTurnDirection = -1;
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::init_air_turn(s32 targetAngle) {
    f32 target;
    f32 difference;
    f32 work;
    f32 half;
    airTurnVelocity = (s16)airTurnVelocity;
    target = (f32)airTurnVelocity;
    difference = (f32)angle_diff_s16(rotation_y, targetAngle);
    f32 duration = (35.0f);
    f32 endTime = (25.0f);
    half = 0.5f;
    airTurnFinalAcceleration = -((difference - (target * 0.5f) * duration) *
        (2.0f)) / 1500.0f;
    airTurnAcceleration = -(airTurnFinalAcceleration * endTime + target) / duration;
    airTurnTime = (0.0f);
    airTurnInitialVelocity = target;
    airTurnFinalVelocity = -(airTurnFinalAcceleration * endTime);
    work = half * airTurnAcceleration;
    work = work * duration + target;
    airTurnMidpointAngle = duration * work;
    airTurnStartAngle = rotation_y;
}

s32 TBoss1Dragon::advance_air_turn() {
    f32 t;
    airTurnTime += 1.0f;
    t = airTurnTime;
    if (t <= 35.0f) {
        rotation_y = airTurnStartAngle + (s32)(t * ((0.5f * airTurnAcceleration) * t + airTurnInitialVelocity));
        return 0;
    }
    if (t <= 60.0f) {
        t -= 35.0f;
        rotation_y = airTurnStartAngle + (s32)(t * ((0.5f * airTurnFinalAcceleration) * t + airTurnFinalVelocity) + airTurnMidpointAngle);
        return 0;
    }
    return 1;
}

#pragma pop
void TBoss1Dragon::reload_difficulty_stats() {
    this->reload_stats_keep_hp_tp(boss1_dragon_base_params[boss1_dragon_base_stat_indices[0]], boss1_dragon_part_hp_stats[boss1_dragon_attack_stat_indices[0]], boss1_dragon_resistance_params[boss1_dragon_resistance_stat_indices[0]]);
}

void TBoss1Dragon::reset_tail_hp() {
    this->reset_hp(NULL, boss1_dragon_part_hp_stats[1], NULL);
}

void TBoss1Dragon::reload_stats_for_phase(int) {
    this->reload_stats_keep_hp_tp(boss1_dragon_base_params[boss1_dragon_base_stat_indices[2]], boss1_dragon_part_hp_stats[boss1_dragon_attack_stat_indices[2]], boss1_dragon_resistance_params[boss1_dragon_resistance_stat_indices[2]]);
}

void TBoss1Dragon::reload_impact_stats() {
    this->reload_stats_keep_hp_tp(boss1_dragon_base_params[boss1_dragon_base_stat_indices[3]], boss1_dragon_part_hp_stats[boss1_dragon_attack_stat_indices[3]], boss1_dragon_resistance_params[boss1_dragon_resistance_stat_indices[3]]);
}

void handle_6x10_dragon_boss_actions(void *packet) {
    void *x;
    ((TObjPlayer *)packet)->bswap_stats();
    x = get_enemy_entity(static_cast<const G_DragonBossActions_6x10_6x11 *>(packet)->header.entity_id);
    if (x != NULL) {
        ((TBoss1Dragon *)x)->copy_params(packet);
    }
}

void TBoss1Dragon::copy_params(void *packet) {
    const G_DragonBossActions_6x10_6x11 *action = static_cast<const G_DragonBossActions_6x10_6x11 *>(packet);
    enemy_set_target_id(this, (u16)action->target_id);
    this->sequenceCursor = action->action_index;
    transition_enemy_state(action->state);
}

void handle_6x11_dragon_boss_actions(void *packet) {
    void *x;
    ((TObjPlayer *)packet)->bswap_dragon_boss_fields();
    x = get_enemy_entity(static_cast<const G_DragonBossActions_6x10_6x11 *>(packet)->header.entity_id);
    if (x != NULL) {
        ((TBoss1Dragon *)x)->set_params(packet);
    }
}

void TBoss1Dragon::set_params(void *packet) {
    const G_DragonBossActions_6x10_6x11 *action = static_cast<const G_DragonBossActions_6x10_6x11 *>(packet);
    enemy_set_target_id(this, (u16)action->target_id);
    this->sequenceCursor = action->action_index;
    if ((s16) this->mode != (s16) action->state) {
        transition_enemy_state(action->state);
    }
}

void handle_6x12_dragon_boss_actions(TObjPlayer *packet) {
    void *x;
    packet->bswap_6x12_packet();
    x = get_enemy_entity(reinterpret_cast<const G_DragonBossActions_6x12 *>(packet)->action.header.entity_id);
    if (x != NULL) {
        ((TBoss1Dragon *)x)->receive_state_request((u8 *)packet);
    }
}

void TBoss1Dragon::receive_state_request(u8 *packet) {
    const G_DragonBossActions_6x12 *sync = reinterpret_cast<const G_DragonBossActions_6x12 *>(packet);
    const G_DragonBossActions_6x10_6x11 *action = &sync->action;
    s32 state;
    enemy_set_target_id(this, (u16)action->target_id);
    this->sequenceCursor = action->action_index;
    this->savedX = sync->x;
    this->savedZ = sync->z;
    this->dispatch_action(action->state, 7);
    state = action->state;
    if ((s16) this->mode != state) {
        transition_enemy_state(state);
    }
}

void TBoss1Dragon::send_state_sync() {
    G_DragonBossActions_6x12 pkt;
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.action.header.entity_id = this->entity_id;
    pkt.action.state = this->mode;
    pkt.action.action_index = (s16) this->sequenceCursor;
    pkt.action.target_id = this->target_id;
    pkt.x = this->destinationX;
    pkt.z = this->destinationZ;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void TBoss1Dragon::request_state_change(u32 state32) {
    G_DragonBossActions_6x12 pkt;

    dispatch_action(state32, 6);
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.action.header.entity_id = entity_id;
    pkt.action.state = state32;
    pkt.action.action_index = sequenceCursor;
    pkt.action.target_id = target_id;
    pkt.x = destinationX;
    pkt.z = destinationZ;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void TBoss1Dragon::restoreTargetPosition() {
    destination.x = savedX;
    destination.z = savedZ;
}

void TBoss1Dragon::copySavedX(int* x) {
    *x = (int)savedX;
}

void TBoss1Dragon::restorePosition() {
    position.x = savedX;
    position.z = savedZ;
}

void TBoss1Dragon::saveTargetDestination() {
    destinationX = destination.x;
    destinationZ = destination.z;
}

void TBoss1Dragon::setDestinationX(int x) {
    destinationX = (f32)x;
    destinationZ = (0.0f);
}

void TBoss1Dragon::saveCurrentDestination() {
    destinationX = position.x;
    destinationZ = position.z;
}

void TBoss1Dragon::next_sequence_action() {
    s32 idx;
    s32 *seq;
    s32 code;
    s32 again;

    s32 pos = this->sequenceCursor;
    if (pos < 50) {
        idx = pos;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            seq = boss1_dragon_primary_sequence_table;
            break;
        case 1:
            seq = boss1_dragon_primary_sequence_table_b;
            break;
        }
    } else {
        idx = pos - 50;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            seq = boss1_dragon_action_sequence_table;
            break;
        case 1:
            seq = boss1_dragon_action_sequence_table_b;
            break;
        }
    }
    do {
        code = seq[idx];
        again = 0;
        idx++;
        this->sequenceCursor++;
        switch (code) {
        case 32:
            this->sequenceCursor = 0;
            again = 1;
            idx = 0;
            break;
        case 33:
            this->sequenceCursor = 50;
            again = 1;
            idx = 0;
            break;
        }
    } while (again != 0);
    this->request_state_change(code);
}

void TBoss1Dragon::remap_sequence_after_recovery() {
    if ((s32) this->player_controlled != 0) {
        next_sequence_action();
        return;
    }
    if (this->update_max_hp_phase() == 0) {
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            this->sequenceCursor = boss1_dragon_sequence_remap_table[this->sequenceCursor];
            break;
        case 1:
            this->sequenceCursor = boss1_dragon_sequence_remap_table_b[this->sequenceCursor];
            break;
        }
        next_sequence_action();
    }
}

s32 TBoss1Dragon::update_max_hp_phase() {
    s16 threshold;

    if ((s16) this->hp <= (threshold = this->finalHpThreshold)) {
        this->hp = threshold;
        this->select_sequence(1);
        if ((s32) this->phase == 0) {
            this->request_state_change(0xD);
            return 1;
        }
        this->request_state_change(0xB);
        return 1;
    }
    return 0;
}

s32 TBoss1Dragon::check_phase_advance() {
    if ((s16) this->hp <= (s16) this->hpThreshold) {
        if ((s32) this->phase == 1) {
            this->request_state_change(0xA);
            return 1;
        }
        this->request_state_change(9);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
f32 TBoss1Dragon::calc_burrow_speed() {
    return ((4.0f) * (f32) this->burrow_run_count) + (4.0f);
}

void TBoss1Dragon::spawn_impact_crater(Vec *pos) {
    Vec position;
    s32 count;
    VecCopy(&position, pos);
    count = this->crater_count;
    if (count < 0xC) {
        position.y += 0.05f * (f32) count;
        this->crater_count = (count + 1);
        TObjBoss1Crater::create(tl_02, &position);
    }
    spawn_particle_effect_with_flags(&position, this->effectResource->particle_ids[0], 0x840);
    TCameraCtrl::set_shake_preset(1);
}

#pragma pop
void TBoss1Dragon::start_rumble() {
    saddr self = (saddr)this;
    start_pad_rumble_at(&this->position, 0xE0, self);
}

void TBoss1Dragon::apply_foot_step_attack(int side) {
    DragonAttackParams params = TBoss1Dragon__foot_step_attack_params;
    Vec *a;
    Vec *b;

    fill_value_array(this->attack_history);
    if (side == 0) {
        a = &this->node_positions[5];
        b = &this->node_positions[6];
    } else {
        a = &this->node_positions[3];
        b = &this->node_positions[4];
    }
    reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        TObjEneDD::emit_enemy_effect(this, a, &params, this->attack_history);
        TObjEneDD::emit_enemy_effect(this, b, &params, this->attack_history);
        break;
    case 1:
        this->emit_v2_enemy_effect(a, &params, this->attack_history);
        this->emit_v2_enemy_effect(b, &params, this->attack_history);
        break;
    }
    reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
    spawn_particle_effect_with_flags(b, this->effectResource->particle_ids[3], 0x40);
}

void TBoss1Dragon::apply_foot_attack_pair_0() {
    apply_foot_step_attack(0);
}

void TBoss1Dragon::apply_foot_attack_pair_1() {
    apply_foot_step_attack(1);
}

void TBoss1Dragon::apply_landing_attack() {
    DragonAttackParams stack;
    TBoss1Dragon__sub_80027A80(&stack, &boss1_dragon_attack_sphere_params);
    stack.radius = boss1_dragon_behavior_params[0]->landing_attack_radius;
    this->reload_stats_for_phase((saddr)boss1_dragon_behavior_params[0]);
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        this->emit_effect_at_position(&stack);
        break;
    case 1:
        this->emit_v2_effect_at_position(&stack);
        break;
    }
    this->reload_difficulty_stats();
}

void TBoss1Dragon::apply_head_fall_attack() {
    reset_hp(NULL, boss1_dragon_part_hp_stats[4], NULL);
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        emit_effect_at_position(&boss1_dragon_head_fall_attack_params);
        break;
    case 1:
        this->emit_v2_effect_at_position(&boss1_dragon_head_fall_attack_params);
        break;
    }
    reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::sweep_body_attack_spheres(f32 a, f32 b, f32 c) {
    f32 factor;
    Vec pos;
    Vec base;
    DragonAttackParams fx = boss1_dragon_head_fall_attack_params;
    f32 s0;
    f32 s1;
    f32 d;

    fx.radius = a - (2.0f);
    fill_value_array(this->attack_history);
    s0 = sin_table_lookup(this->rotation_y);
    s1 = cos_table_lookup(this->rotation_y);
    VecCopy(&base, &this->position);
    base.x = (-4.0f) * s1 + base.x;
    base.y = (0.0f);
    base.z = base.z - (-4.0f) * s0;
    d = (0.5f) * (b + c);
    VecCopy(&pos, &base);
    pos.x += s0 * d;
    pos.z += s1 * d;
    spawn_particle_effect_with_flags(&pos, this->effectResource->particle_ids[3], 0x40);
    this->reset_hp(NULL, boss1_dragon_part_hp_stats[4], NULL);
    c = c - a;
    d = b - a;
    factor = 2.0f;
    a = a * factor;
    b = (0.5f) * ((0.5f) * a);
    while (d > c) {
        VecCopy(&pos, &base);
        pos.x += s0 * d;
        pos.z += s1 * d;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            TObjEneDD::emit_enemy_effect(this, &pos, &fx, this->attack_history);
            break;
        case 1:
            this->emit_v2_enemy_effect(&pos, &fx, this->attack_history);
            break;
        }
        d -= a;
        push_matrix();
        post_translate_matrix(&pos.x);
        scale_matrix(0, b, (2.0f), b);
        draw_chunk_object(debug_cylinder_object);
        pop_matrix();
    }
    this->reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
}

#pragma pop
void TBoss1Dragon::sweep_head_fall_spheres_early() {
    sweep_body_attack_spheres(10.0f, -60.0f, -140.0f);
}

void TBoss1Dragon::sweep_head_fall_spheres_late() {
    sweep_body_attack_spheres(10.0f, 90.0f, 60.0f);
}

void TBoss1Dragon::apply_ground_impact_attack() {
    reload_impact_stats();
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        this->emit_effect_at_position(&boss1_dragon_ground_impact_params);
        break;
    case 1:
        this->emit_v2_effect_at_position(&boss1_dragon_ground_impact_params);
        break;
    }
    reload_difficulty_stats();
}

#pragma push
#pragma scheduling off
void TBoss1Dragon__sub_80027A80(DragonAttackParams *destination, const DragonAttackParams *source) {
    __memcpy(destination, source, 8);
    destination->radius = source->radius;
    // Character views start at the complete objects, not a smaller member.
    __memcpy(reinterpret_cast<u8 *>(destination) + 12,
        reinterpret_cast<const u8 *>(source) + 12, 8);
}

#pragma pop
#pragma push
#pragma opt_common_subs off
void TBoss1Dragon::sweep_death_body_attack() {
    Vec *pts[8];
    Vec pos;
    DragonAttackParams params;
    s32 i;
    s32 off;
    reset_hp(NULL, boss1_dragon_part_hp_stats[4], NULL);
    fill_value_array(this->attack_history);
    TBoss1Dragon__sub_80027A80(&params, &boss1_dragon_head_fall_attack_params);
    VecCopy(&pos, &this->node_positions[12]);
    params.radius = (15.0f);
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        TObjEneDD::emit_enemy_effect(this, &pos, &params, this->attack_history);
        break;
    case 1:
        this->emit_v2_enemy_effect(&pos, &params, this->attack_history);
        break;
    }
    params.radius = (12.0f);
    pts[0] = &this->node_positions[7];
    pts[1] = &this->node_positions[9];
    for (i = 0; i < 2; i++) {
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            TObjEneDD::emit_enemy_effect(this, pts[i], &params, this->attack_history);
            break;
        case 1:
            this->emit_v2_enemy_effect(pts[i], &params, this->attack_history);
            break;
        }
    }
    params.radius = 11.0f;
    pts[0] = &this->node_positions[14];
    pts[1] = &this->node_positions[15];
    pts[2] = &this->node_positions[16];
    pts[3] = &this->node_positions[17];
    for (i = 0; i < 4; i++) {
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            TObjEneDD::emit_enemy_effect(this, pts[i], &params, this->attack_history);
            break;
        case 1:
            this->emit_v2_enemy_effect(pts[i], &params, this->attack_history);
            break;
        }
    }
    reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
}

#pragma pop
void TBoss1Dragon::apply_trail_attack() {
    TObjBoss1MokoHill_SoloM *moko_hill = this->moko_hill;
    if ((moko_hill != NULL) && (moko_hill->is_dragon_trail_damaging() != 0)) {
        DragonAttackParams params = dragon_breath_attack_params;
        params.power = boss1_dragon_behavior_params[0]->trail_attack_power;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            TObjEneDD::setup_instance(this, &this->position, &params, this->attack_history);
            return;
        case 1:
            this->setup_v2_instance(&this->position, &params, this->attack_history);
            break;
        }
    }
}

void TBoss1Dragon::deliver_breath_attack(Vec *position, AreaAttackHistory *attack_history) {
    DragonAttackParams params = dragon_fireball_attack_params;
    params.power = boss1_dragon_behavior_params[0]->breath_attack_power;
    params.kind = this->attack_kind;
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        TObjEneDD::setup_instance(this, position, &params, attack_history);
        return;
    case 1:
        this->setup_v2_instance(position, &params, attack_history);
        return;
    }
}

void TBoss1Dragon::apply_fireball_impact_damage(Vec *position) {
    DragonAttackParams params = dragon_fireball_impact_damage_params;
    params.power = boss1_dragon_behavior_params[0]->fireball_impact_power;
    params.kind = this->attack_kind;
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        TObjEneDD::setup(this, position, &params);
        return;
    case 1:
        this->setup_v2_instance(position, &params, 0);
        return;
    }
}

f32 TBoss1Dragon::get_crater_attack_power() {
    return 0.666f * boss1_dragon_behavior_params[0]->fireball_impact_power;
}

void TBoss1Dragon::emit_v2_enemy_effect(const Vec *position, const DragonAttackParams *params, AreaAttackHistory *history) {
    ((TUnk_804928CC *)this->attack_collider)->set_position_from(position);
    this->attack_collider->bodies->radius = params->radius;
    this->attack_collider->bodies->flags = 0x9D03;
    this->attack_collider->call_vt16_with_default(const_cast<AreaAttackContact *>(&params->contact), history);
}

void TBoss1Dragon::emit_v2_effect_at_position(const DragonAttackParams *params) {
    this->emit_v2_enemy_effect(&this->position, params, NULL);
}

void TBoss1Dragon::setup_v2_instance(const Vec *position, DragonAttackParams *params, AreaAttackHistory *history) {
    ((TUnk_804928CC *)this->attack_collider)->set_position_from(position);
    this->attack_collider->bodies->radius = params->radius;
    this->attack_collider->bodies->flags = 0x9D03;
    this->attack_collider->call_vt13_with_default(&params->contact, params, reinterpret_cast<saddr>(history));
}

void TBoss1Dragon::update_switch_attack() {
    spawn_particle_effect_with_flags(&this->position, this->effectResource->particle_ids[1], 0x40);
}

void TBoss1Dragon::update_flap_effect() {
    if (this->is_passing_frame(14.0f) != 0) {
        this->update_switch_attack();
    }
}

#pragma push
#pragma fp_contract on
u16 TBoss1Dragon::find_player_on_floor() {
    TObjPlayer *p;
    u16 idx;
    u16 i;
    p = get_player_by_client_id(designated_client_id);
    if (p != NULL) {
        if (p->get_floor() == get_current_floor()) {
            return designated_client_id;
        }
    }
    for (i = 0; i < 4; i++) {
        idx = (designated_client_id + i + 1) % 4;
        p = get_player_by_client_id(idx);
        if (p != NULL) {
            if (p->get_floor() == get_current_floor()) {
                break;
            }
        }
    }
    return idx;
}

#pragma pop
void TBoss1Dragon::init_control_mode() {
    u16 id;

    if (boss1_dragon_player_control != 0) {
        this->player_controlled = 1;
    } else {
        this->player_controlled = 0;
        this->target_client_id = 0xFFFF;
        return;
    }
    this->controlTimer = 0x96;
    this->controller_input = &controller_input_state.controllers[0];
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (boss1_dragon_control_client_id == 0xFFFF) {
            id = this->find_player_on_floor();
        } else {
            id = boss1_dragon_control_client_id;
        }
    } else {
        id = local_client_id;
    }
    {
        TObjPlayer *player = get_player_by_client_id(id);
        if (player != NULL) {
            player->start_freeze();
        }
    }
    this->target_client_id = id;
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::hold_captured_player() {
    s32 current_floor;
    s32 player_floor;
    TObjPlayer *player;
    player = get_player_by_client_id(this->target_client_id);
    if (player != NULL) {
        current_floor = get_current_floor();
        player_floor = player->get_floor();
        if (player_floor == current_floor) {
            player->start_freeze();
            player->protection.set_frames(0x14);
            player->actorFlags = player->actorFlags & 0xFFEFFFDF;
            VecCopy(&player->position, &this->position);
            player->position.y = player->position.y - 200.0f;
            player->rotation_y = this->rotation_y;
            return;
        }
    }
    TBoss1Dragon::clearControlOverride();
}

#pragma pop
void TBoss1Dragon::release_held_player() {
    s32 pick_next_action;
    u16 client_id;
    TObjPlayer *player;
    player = get_player_by_client_id((s32) this->target_client_id);
    if (player != NULL) {
        player->end_camera_pan();
        player->actorFlags = player->actorFlags & 0xFDFFFFFF;
        player->protection.reset_lobby_model();
        player->position.y = 0.0f;
        client_id = this->target_client_id;
        if (((s32) client_id == (s32) local_client_id) && ((s16) this->mode == 0x15)) {
            send_6x2F_change_player_hp((0xFFFFU), (client_id), 0);
        }
    }
    this->player_controlled = 0;
    if ((s16) this->mode != 0x15) {
        pick_next_action = 0;
        if (this->is_primary_sequence() != 0) {
            this->sequenceCursor = 0;
            switch (this->mode) {
            case 23:
            case 24:
                pick_next_action = 1;
                this->sequenceCursor = 0;
                break;
            case 3:
                this->sequenceCursor = 2;
                break;
            case 4:
                this->sequenceCursor = 3;
                break;
            case 5:
                this->sequenceCursor = 4;
                break;
            case 25:
            case 26:
                pick_next_action = 1;
                this->sequenceCursor = 6;
                break;
            case 7:
                this->sequenceCursor = 6;
                break;
            case 8:
                this->sequenceCursor = 7;
                break;
            case 9:
                this->sequenceCursor = 0;
                break;
            }
        } else {
            this->sequenceCursor = 0;
            switch (this->mode) {
            case 23:
            case 24:
                pick_next_action = 1;
                this->sequenceCursor = 0;
                break;
            case 3:
            case 4:
                this->sequenceCursor = 0;
                break;
            case 5:
                this->sequenceCursor = 1;
                break;
            case 25:
            case 26:
                pick_next_action = 1;
                this->sequenceCursor = 0xA;
                break;
            case 7:
                this->sequenceCursor = 0xA;
                break;
            case 8:
            case 19:
                this->sequenceCursor = 0xB;
                break;
            case 15:
                this->sequenceCursor = 2;
                break;
            case 36:
            case 37:
                pick_next_action = 1;
                this->sequenceCursor = 9;
                break;
            case 9:
                this->sequenceCursor = 0;
                break;
            }
            this->sequenceCursor = (this->sequenceCursor + 0x32);
        }
        if (pick_next_action != 0) {
            next_sequence_action();
        }
    }
}

#pragma push
#pragma fp_contract on
f32 TBoss1Dragon::clamp_step_in_radius(f32 dir_x, f32 dir_z, f32 step) {
    Vec v;
    v.x = dir_x * step + this->position.x;
    v.y = (0.0f);
    v.z = dir_z * step + this->position.z;
    if (vec3_dot(&v, &v) > 28900.0f) {
        step = (0.0f);
    }
    return step;
}

#pragma pop
s32 TBoss1Dragon::check_attack_ready() {
    u8 ready;

    ready = 0;
    if (((s32) this->controlTimer >= 0x96) && (this->filter_input_flags(this->controller_input->pressed_buttons, 0x400) != 0)) {
        ready = 1;
    }
    return ready;
}

s32 TBoss1Dragon::check_can_attack() {
    u8 can_attack;

    can_attack = 0;
    if ((this->filter_input_flags(this->controller_input->pressed_buttons, 0x400) != 0) && (this->is_secondary_sequence() != 0)) {
        can_attack = 1;
    }
    return can_attack;
}

void TBoss1Dragon::updateFacingPosition() {
    position.x = 330.0f * sin_table_lookup(facingAngle);
    position.z = 330.0f * cos_table_lookup(facingAngle);
}

s32 TBoss1Dragon::filter_input_flags(s32 input_flags, s32 mask) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if ((player == NULL) || (player->is_controls_locked() != 0)) {
        input_flags &= 0xFFFCF9F9;
    }
    return input_flags & mask;
}

void TBoss1Dragon::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        this->update_idle_state((u32)reason);
        return;
    case 1:
        this->update_stand_state((u32)reason);
        return;
    case 2:
        this->update_walking_state(reason);
        return;
    case 3:
        this->update_breath_attack_state(reason);
        return;
    case 4:
        this->update_tail_attack_state(reason);
        return;
    case 5:
        this->update_lift_state(reason);
        return;
    case 6:
        this->update_flight_state(reason);
        return;
    case 7:
        this->update_air_fire_state((u32)reason);
        return;
    case 8:
    case 10:
    case 11:
    case 12:
        this->handleFallState(reason);
        return;
    case 9:
        this->update_head_down_attack_state(reason);
        return;
    case 13:
        this->update_stretch_state(reason);
        return;
    case 14:
        this->update_roar_state(reason);
        return;
    case 15:
        update_dive_state((u32)reason);
        return;
    case 16:
    case 17:
        this->update_burrow_inward_run(reason, state);
        return;
    case 18:
        this->update_burrow_outward_run(reason);
        return;
    case 19:
        this->update_emergence_state((u32)reason);
        return;
    case 21:
        update_death_state((u32)reason);
        return;
    case 22:
        this->update_fade_state(reason);
        return;
    case 23:
        this->update_controlled_stand_state((u32)reason);
        return;
    case 24:
        this->update_controlled_walk_state((u32)reason);
        return;
    case 25:
        this->update_controlled_hover_state((u32)reason);
        return;
    case 26:
        this->update_controlled_flight_state((u32)reason);
        return;
    case 27:
        this->handle_state(reason);
        return;
    case 28:
        this->handle_walk_state((u32)reason);
        return;
    case 29:
        this->update_appearance_state(reason);
        return;
    case 30:
        this->wait_for_players(reason);
        return;
    case 31:
        this->update_wander_state(reason);
        return;
    case 34:
        this->update_spinning_projectile_attack((u32)reason);
        return;
    case 35:
        this->handle_spiral_state((u32)reason);
        return;
    case 36:
        this->state_circle_flight(reason);
        return;
    case 37:
        this->handle_fall_state(reason);
    default:
        return;
    }
}

void TBoss1Dragon::update_idle_state(u32 reason) {
    switch (reason) {
    case 4:
        this->init_control_mode();
        return;
    case 2:
    case 11:
        this->request_state_change(0x17);
        return;
    case 9:
        if ((s32) this->player_controlled != 0) {
            this->request_state_change(0x17);
            return;
        }
        this->next_sequence_action();
    default:
        return;
    }
}

void TBoss1Dragon::update_stand_state(u32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->stateStep = 0;
        this->height = (f32) this->position.y;
        this->heightOffset = (f32) this->defaultHeightOffset;
        this->play_se_at_pos(0x4003AD00);
        return;
    case 2:
    case 11:
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 4) != 0) {
            this->request_state_change(3);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 0x400) != 0) {
            this->request_state_change(5);
            return;
        }
        if (this->controller_input->stick_magnitude > (0.1f)) {
            this->request_state_change(0x18);
            return;
        }
        break;
    case 0:
        this->stateStep = this->stateStep + 1;
        this->advance_animation();
        break;
    }
}

void TBoss1Dragon::update_walking_state(u32 reason) {
    s32 ticks;
    f32 scale;
    s32 iscale;
    s32 next;
    f32 v;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags &= ~0xE80;
        this->stateStep = 0;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            this->fallVelocity = (5.0f) + TObjBoss2Tunnel::calc_scaled_value(0x100, (0.8f));
            break;
        case 1:
            {
                f32 s1 = boss1_dragon_behavior_params[0]->walk_speed_scale;
                this->fallVelocity = (5.0f) + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * s1), s1);
            }
            break;
        }
        break;
    case 2:
    case 11:
        this->request_state_change(0x17);
        break;
    case 9:
        ticks = this->stateStep;
        next = 0;
        if (ticks >= 150 && this->current_target != 0) {
            if (this->destination_distance < this->fallVelocity) {
                next = 1;
            } else if (this->is_destination_ahead() != 0) {
                next = 1;
            } else if (TBoss1Dragon::isV2Mode() >= 1 && this->stateStep >= 600) {
                next = 1;
            }
        } else if (ticks >= 300) {
            next = 1;
        }
        if (next != 0) {
            next_sequence_action();
        }
        break;
    case 8:
        this->update_linked_epsilon_position();
        (this->stateStep)++;
        if (this->stateStep % 20 == 19) {
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
            } else {
                this->set_target_destination(&boss1_dragon_arena_center);
            }
            this->saveTargetDestination();
            this->send_state_sync();
        }
        break;
    case 7:
        this->restoreTargetPosition();
        break;
    case 6:
        this->acquire_counter = this->acquire_period;
        if (this->update_linked_epsilon_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss1_dragon_arena_center);
        }
        this->saveTargetDestination();
        break;
    case 0:
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            scale = (0.8f);
            break;
        case 1:
            scale = boss1_dragon_behavior_params[0]->walk_speed_scale;
            break;
        }
        iscale = (s32) (320.0f * scale);
        if (this->motion_flags & 4) {
            this->play_speed = 0.125f * scale;
        } else {
            this->play_speed = 0.6f * scale;
        }
        this->advance_animation();
        this->play_sound_if_in_band();
        this->update_velocity();
        this->calc_target_vector();
        if (this->is_passing_frame((f32)(3.0f)) != 0) {
            this->apply_foot_attack_pair_0();
        } else if (this->is_passing_frame((f32)(24.0f)) != 0) {
            this->apply_foot_attack_pair_1();
        }
        v = this->frame;
        if (v < (4.0f)) {
            this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
        } else if (!(v < (9.0f))) {
            if (v < 19.0f) {
                TObjEneEpsilon__sub_800B9384(this, iscale, scale);
            } else if (v < (24.0f)) {
                this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
            } else if (!(v < (30.0f))) {
                TObjEneEpsilon__sub_800B9384(this, iscale, scale);
            }
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::update_breath_attack_state(u32 reason) {
    DragonEffectRotation rotation;

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 4;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = (s32) (this->flags & ~0xE80);
        this->stateStep = 0;
        this->impactAge = 2;
        this->action_frames = 0;
        this->breath_particles[0] = 0;
        this->breath_particles[1] = 0;
        this->breath_particles[2] = 0;
        return;
    case 2:
    case 11:
        if ((s32) this->stateStep == 3) {
            this->request_state_change(0x17);
        }
        return;
    case 9:
        if ((s32) this->stateStep == 3) {
            next_sequence_action();
            return;
        }
        break;
    case 7:
        this->restoreTargetPosition();
        return;
    case 6:
        if (enemy_validate_retained_target(this) != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->destination.x = (f32) ((115.0f * sin_table_lookup(this->rotation_y)) + this->breath_origin.x);
            this->destination.y = (f32) this->position.y;
            this->destination.z = (f32) ((115.0f * cos_table_lookup(this->rotation_y)) + this->breath_origin.z);
        }
        this->saveTargetDestination();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        switch (this->stateStep) {
        case 0:
            this->update_velocity();
            this->calc_target_vector();
            this->rotation_y = approach_angle_limited(this->rotation_y, ((s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->destination_direction.x, this->destination_direction.z))), 0xA0);
            this->rotation_y = (s32) (s16) this->rotation_y;
            if (this->get_flag_b4() != 0) {
                this->requested_action = 5;
                this->stateStep = 1;
                return;
            }
            break;
        case 1:
            this->action_frames = (this->action_frames + 1);
            if (this->action_frames >= 0x78) {
                this->requested_action = 6;
                if (this->breath_particles[0] != 0) {
                    this->breath_particles[0]->queue_destruction();
                    this->breath_particles[0] = 0;
                }
                if (this->breath_particles[1] != 0) {
                    this->breath_particles[1]->queue_destruction();
                    this->breath_particles[1] = 0;
                }
                if (this->breath_particles[2] != 0) {
                    this->breath_particles[2]->queue_destruction();
                    this->breath_particles[2] = 0;
                }
                this->stateStep = 2;
                this->impactAge = 0;
                return;
            }
            if (!(this->motion_flags & 4)) {
                this->spawn_trap(0x4003AD0D);
                direction_to_rotation_xz((u8 *)&this->breath_direction, &rotation.x, &rotation.z);
                this->impactAge = (this->impactAge + 1);
                if ((s32) this->impactAge >= 2) {
                    new TBoss1DragonEffBreath(&this->sub_tasks, &this->breath_origin, &this->breath_direction);
                    this->impactAge = 0;
                }
                if (this->breath_particles[0] == 0) {
                    this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->breath_origin, &rotation, this->effectResource->particle_ids[4], 0x40);
                    if (this->breath_particles[0] != 0) {
                        this->breath_particles[0]->enable();
                    }
                } else {
                    this->breath_particles[0]->set_position(&this->breath_effect_position);
                    this->breath_particles[0]->set_direction(&rotation);
                }
                if (this->breath_particles[2] == 0) {
                    this->breath_particles[2] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->breath_origin, &rotation, this->effectResource->particle_ids[5], 0x40);
                    if (this->breath_particles[2] != 0) {
                        this->breath_particles[2]->enable();
                        return;
                    }
                } else {
                    this->breath_particles[2]->set_position(&this->breath_effect_position);
                    this->breath_particles[2]->set_direction(&rotation);
                    return;
                }
            }
            break;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge < 0x1E) {
                this->spawn_trap(0x4003AD0D);
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 3;
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (this->breath_particles[0] != 0) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        if (this->breath_particles[1] != 0) {
            this->breath_particles[1]->queue_destruction();
            this->breath_particles[1] = 0;
        }
        if (this->breath_particles[2] != 0) {
            this->breath_particles[2]->queue_destruction();
            this->breath_particles[2] = 0;
        }
        break;
    default:
        return;
    }
}

#pragma pop
void TBoss1Dragon::update_tail_attack_state(u32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags &= ~0xC80;
        this->flags |= 0x200;
        this->stateStep = 0;
        this->tail->enable();
        break;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            this->request_state_change(0x17);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            next_sequence_action();
        }
        break;
    case 0:
        advance_animation();
        this->stateStep++;
        if (this->is_passing_frame((f32)(0.0f)) != 0 ||
            this->is_passing_frame((f32)(12.0f)) != 0) {
            this->play_se_at_pos(0x4003AD09);
        }
        if (this->stateStep > 1) {
            if (this->is_passing_frame(10.0f) != 0) {
                this->tail->disable();
            } else if (this->is_passing_frame(23.0f) != 0) {
                this->tail->enable();
            }
            this->tail->run_task();
        }
        break;
    }
}

void TBoss1Dragon::update_lift_state(u32 reason) {

    switch (reason) {
    case 4:
        this->requested_action = 0xF;
        advance_animation();
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = this->flags & ~0xE80;
        this->stateStep = 0;
        this->fallVelocity = (0.0f);
        this->impactAge = 0;
        this->height = this->position.y;
        return;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (this->fallVelocity < (0.0f)) {
            this->request_state_change(0x19);
        }
        return;
    case 9:
        if (this->fallVelocity < (0.0f)) {
            next_sequence_action();
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case 0:
        this->stateStep = this->stateStep + 1;
        switch (this->impactAge) {
        case 0:
            if ((this->frame + this->play_speed) >= (40.0f)) {
                f32 t;
                this->rootHeight = this->sample_root_height();
                t = (-2.0f) * boss1_dragon_lift_accel;
                this->fallVelocity = newton_sqrtf(t * (180.0f - this->rootHeight));
                this->impactAge = 1;
                this->flags = this->flags | 0xC00;
                this->setActive();
            }
            break;
        }
        this->advance_animation();
        if (this->is_passing_frame(14.0f) != 0) {
            this->play_se_at_pos(0x4003A804);
        }
        if (this->is_passing_frame(42.0f) != 0) {
            this->play_se_at_pos(0x4003A803);
        }
        if (this->is_passing_frame(46.0f) != 0) {
            spawn_particle_effect_with_flags((const Vec *)&this->position.x, this->effectResource->particle_ids[1], 0x40);
        }
        switch (this->impactAge) {
        case 1:
            this->heightOffset = this->defaultHeightOffset + (this->rootHeight - this->sample_root_height());
            this->height = this->position.y + this->rootHeight;
            this->rootHeight = this->rootHeight + this->fallVelocity;
            this->fallVelocity = this->fallVelocity + boss1_dragon_lift_accel;
            break;
        case 0:
            break;
        }
        break;
    default:
        return;
    }
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_flight_state(u32 reason) {
    Vec *base;
    s32 var;
    s32 old;
    f32 t;

    base = &this->action_point;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        old = this->flags;
        this->flags = old & ~0xE80;
        this->update_velocity();
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            init_acceleration_curve(&this->curve0, (0.1f), (-0.1f), this->destination_distance, (2.0f));
            break;
        case 1:
            init_acceleration_curve(&this->curve0, (0.1f), (-0.1f), this->destination_distance, boss1_dragon_behavior_params[0]->flight_speed);
            break;
        }
        VecCopy(base, &this->position);
        var = angle_diff_s16(this->rotation_y, (s32)(boss1_dragon_angle_units_per_radian * atan2_float(this->destination_direction.x, this->destination_direction.z)));
        if (var >= 0) {
            this->airTurnDirection = 1;
        } else {
            var = -var;
            this->airTurnDirection = -1;
        }
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            init_acceleration_curve(&this->curve1, 16.0f, (-16.0f), (f32)var, 512.0f);
            break;
        case 1:
            init_acceleration_curve(&this->curve1, 16.0f, (-16.0f), (f32)var, (f32)(s32)(256.0f * boss1_dragon_behavior_params[0]->flight_speed));
            break;
        }
        this->action_angle = this->rotation_y;
        this->stateStep = 0;
        this->fallVelocity = (0.0f);
        break;
    case 2:
        this->request_state_change(0x19);
        break;
    case 11:
        if (this->stateStep == 2) {
            this->request_state_change(0xF);
        }
        break;
    case 9:
        if (this->stateStep == 2) {
            next_sequence_action();
        }
        break;
    case 7:
        this->restoreTargetPosition();
        break;
    case 6:
        this->prepare_flight_destination(&this->destination);
        this->saveTargetDestination();
        break;
    case ENEMY_STATE_UPDATE:
        this->advance_animation();
        play_nearby_se();
        this->update_flap_effect();
        switch (this->stateStep) {
        case 0:
            this->fallVelocity += (1.0f);
            t = sample_acceleration_curve(&this->curve1, this->fallVelocity);
            this->rotation_y = (s32)((f32)this->airTurnDirection * t + (f32)this->action_angle);
            if (this->curve1.check_param_threshold(this->fallVelocity) != 0) {
                this->fallVelocity = (0.0f);
                this->stateStep = 1;
            }
            break;
        case 1:
            this->fallVelocity += (1.0f);
            t = sample_acceleration_curve(&this->curve0, this->fallVelocity);
            this->position.x = this->destination_direction.x * t + base->x;
            this->position.z = this->destination_direction.z * t + base->z;
            if (this->curve0.check_param_threshold(this->fallVelocity) != 0) {
                this->stateStep = 2;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        VecCopy(&this->last_flight_direction, &this->destination_direction);
        break;
    }
}

void TBoss1Dragon::update_air_fire_state(u32 reason) {
    Vec *tgt;
    f32 dist;
    Vec dest;
    Vec d;
    Vec out;

    tgt = (Vec *)&this->action_point;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags &= ~0xE80;
        this->stateStep = 0;
        this->impactAge = 0;
        this->action_frames = 0;
        this->breath_particles[0] = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            this->request_state_change(0x19);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            next_sequence_action();
        }
        break;
    case ENEMY_STATE_UPDATE:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->select_air_fire_target(tgt) != 0) {
                this->action_angle = (s32)(boss1_dragon_angle_units_per_radian * atan2_float(tgt->x - this->position.x, tgt->z - this->position.z));
            } else {
                this->action_angle = this->get_random_scaled();
                tgt->x = 125.0f * sin_table_lookup(this->action_angle);
                tgt->y = (0.0f);
                tgt->z = 125.0f * cos_table_lookup(this->action_angle);
            }
            this->action_angle = (s16)this->action_angle;
            this->stateStep = 1;
            if (this->player_controlled != 0) {
                this->action_angle = (s16)this->rotation_y;
                VecCopy(tgt, &this->position);
                tgt->x = 125.0f * sin_table_lookup(this->action_angle) + tgt->x;
                tgt->y = (0.0f);
                tgt->z = 125.0f * cos_table_lookup(this->action_angle) + tgt->z;
                this->stateStep = 2;
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->requested_action = 0x12;
                this->flags |= 0xC00;
            }
            this->set_air_turn_direction(this->rotation_y, this->action_angle);
            this->init_air_turn(this->action_angle);
        case 1:
            this->play_nearby_se();
            this->update_flap_effect();
            if (this->advance_air_turn() != 0) {
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->stateStep = 2;
                this->requested_action = 0x12;
                this->flags |= 0xC00;
            }
            break;
        case 2:
            if (this->is_passing_frame((f32)(2.0f)) != 0) {
                this->play_se_at_pos(0x4003A804);
            }
            if (this->is_passing_frame(45.0f) != 0) {
                this->play_se_at_pos(0x4003AD0A);
            }
            if (this->is_passing_frame(14.0f) != 0 || this->is_passing_frame(53.0f) != 0) {
                this->update_switch_attack();
            }
            if (this->breath_particles[0] == NULL) {
                if (this->frame >= (20.0f)) {
                    this->breath_particles[0] = spawn_continuous_particle_effect_with_flags(&this->breath_origin, this->effectResource->particle_ids[6], 0x40);
                }
            } else if (this->frame <= (40.0f)) {
                this->breath_particles[0]->set_position(&this->breath_origin);
            } else {
                this->breath_particles[0]->queue_destruction();
                this->breath_particles[0] = 0;
            }
            if (this->is_passing_frame(47.0f) != 0) {
                VecCopy(&d, tgt);
                subtract_vector(&d, &this->position);
                dist = normalize_vector_xz((Vec *)&d);
                d.y = (0.0f);
                VecCopy(&dest, tgt);
                dest.y = boss1_dragon_arena_center.y;
                new TBoss1DragonEffBullet(&this->sub_tasks, &this->breath_origin, &dest);
                rotate_vec_xz(&d, &out, 0x1000);
                VecCopy(&dest, &this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = boss1_dragon_arena_center.y;
                dest.z = out.z * dist + dest.z;
                new TBoss1DragonEffBullet(&this->sub_tasks, &this->breath_origin, &dest);
                rotate_vec_xz(&d, &out, -0x1000);
                VecCopy(&dest, &this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = boss1_dragon_arena_center.y;
                dest.z = out.z * dist + dest.z;
                new TBoss1DragonEffBullet(&this->sub_tasks, &this->breath_origin, &dest);
                spawn_particle_effect_with_flags(&this->breath_origin, this->effectResource->particle_ids[7], 0x40);
                this->stateStep = 3;
                this->action_frames = 0;
                this->flags &= ~0xC00;
            }
            break;
        case 3:
            (this->action_frames)++;
            if (this->action_frames > 0xA) {
                (this->impactAge)++;
                if (this->impactAge >= 2) {
                    this->stateStep = 4;
                } else {
                    this->stateStep = 0;
                }
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (this->breath_particles[0] != NULL) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        break;
    }
}

#pragma pop
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::update_spinning_projectile_attack(u32 reason) {

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x16;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags |= 0xC00;
        this->flags &= ~0x280;
        this->stateStep = 0;
        this->impactAge = 0;
        this->action_frames = 0;
        this->action_angle = 0;
        this->fallVelocity = (13.0f);
        break;
    case 2:
    case 11:
        this->request_state_change(0x19);
        break;
    case 9:
        if (this->stateStep == 6) {
            next_sequence_action();
        }
        break;
    case 7: {
        u32 seed = (u32)(s32)((100.0f) * this->savedX);
        s32 low = (s32)((100.0f) * this->savedZ);
        seed *= 0x10000UL;
        seed |= (u32)low & 0xFFFFUL;
        subtractive_rng_seed(this->randomState, seed);
        break;
    }
    case 6:
        this->saveCurrentDestination();
        break;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 0:
            this->advance_animation();
            if (this->frame >= 18.0f) {
                this->stateStep = 1;
                this->play_se_at_pos(0x4003B210);
            }
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 22.0f) {
                this->rotation_x = (s32)((-16384.0f) * ((this->frame - 22.0f) / (this->frame_count - 22.0f)));
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0x18;
                this->stateStep = 2;
            }
            break;
        case 2:
            this->advance_animation();
            this->rotation_x = 0;
            if (this->frame > 22.0f) {
                this->action_angle = 0x1000;
                this->stateStep = 3;
                this->camera_eye_raised = 1;
            }
            break;
        case 3: {
            Vec position;
            s32 found;
            this->action_angle += 0x40;
            if (this->action_angle > 0x2000) {
                this->action_angle = 0x2000;
            }
            this->impactAge++;
            if (this->impactAge >= 4) {
                this->impactAge = 0;
                this->action_frames += 1;
                if (this->action_frames >= 0x28) {
                    this->stateStep = 4;
                    this->camera_eye_raised = 0;
                }
                found = 0;
                if ((this->action_frames & 1) == 0) {
                    TObjPlayer *player = get_player_by_client_id((u16)((this->action_frames >> 1) % 4));
                    if (((TObjBase *)player)->is_alive() != 0) {
                        VecCopy(&position, &player->position);
                        position.x += (100.0f) *
                            (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - (0.5f));
                        position.z += (100.0f) *
                            (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - (0.5f));
                        found = 1;
                    }
                }
                if (found == 0) {
                    position.x = 700.0f *
                        (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - (0.5f));
                    position.y = (0.0f);
                    position.z = 700.0f *
                        (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - (0.5f));
                }
                new TBoss1DragonEffBullet(&this->sub_tasks, &this->breath_origin, &position);
            }
            this->rotation_x -= this->action_angle;
            break;
        }
        case 4: {
            s32 angle;
            this->action_angle -= 0x50;
            if (this->action_angle < 0x1300) {
                this->action_angle = 0x1300;
                this->rotation_x -= this->action_angle;
                angle = (u16)this->rotation_x;
                if (angle <= 0x1300 || angle >= 0x10000 - 0x1300) {
                    this->rotation_x = 0;
                    this->action_spin = (s32)(boss1_dragon_angle_units_per_radian *
                        atan2_float(-this->position.x, -this->position.z));
                    this->stateStep = 5;
                }
            } else {
                this->rotation_x -= this->action_angle;
            }
            break;
        }
        case 5: {
            f32 delta;
            this->advance_animation();
            delta = (f32)angle_diff_s16(this->rotation_y, this->action_spin);
            delta *= 0.3f;
            if ((delta < 512.0f && delta >= (-512.0f)) || this->get_flag_b4() != 0) {
                this->rotation_y = this->action_spin;
                this->stateStep = 6;
            } else {
                this->rotation_y += (s32)delta;
            }
            break;
        }
        case 6:
            this->advance_animation();
            break;
        }
        if (this->stateStep == 1 || this->stateStep == 2) {
            this->fallVelocity += boss1_dragon_fall_accel;
            if (this->fallVelocity < (0.0f)) {
                this->fallVelocity = (0.0f);
            }
            this->heightOffset += this->fallVelocity;
            if (this->heightOffset - this->defaultHeightOffset <= 180.0f) {
                this->heightOffset = 180.0f + this->defaultHeightOffset;
            }
        }
        if (this->stateStep == 3 || this->stateStep == 4 || this->stateStep == 5) {
            this->heightOffset -= (1.0f);
            if (this->heightOffset - this->defaultHeightOffset < 180.0f) {
                this->heightOffset = 180.0f + this->defaultHeightOffset;
            }
        }
        this->height = this->position.y + this->heightOffset;
        break;
    case ENEMY_STATE_LEAVE:
        this->rotation_x = 0;
        this->enable_motion_blend();
        this->camera_eye_raised = 0;
        break;
    }
}

#pragma pop
void TBoss1Dragon::handleFallState(u32 reason) {
    f32 root_height;
    f32 fall_height;
    f32 ground_y;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->clearState();
        this->set_flight_height();
        this->flags = (s32) (this->flags | 0xE80);
        this->stateStep = 0;
        this->fallVelocity = (f32) (0.0f);
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (get_flag_b4() != 0) {
            this->request_state_change(0x17);
        }
        return;
    case 9:
        if (get_flag_b4() != 0) {
            switch (this->mode) {
            default:
            case 8:
                next_sequence_action();
                return;
            case 10:
                this->request_state_change(9);
                return;
            case 11:
                this->request_state_change(0xD);
                return;
            case 12:
                this->request_state_change(0x15);
                return;
            }
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 1:
            break;
        case 0:
            advance_animation();
            this->rootHeight = sample_root_height();
            if (this->frame >= 44.0f) {
                this->stateStep = 1;
            }
            if (is_passing_frame((2.0f)) != 0) {
                this->play_se_at_pos(0x4003A804);
            }
            if (is_passing_frame(11.0f) != 0) {
                update_switch_attack();
            }
            break;
        case 2:
            advance_animation();
            break;
        }
        switch (this->stateStep) {
        case 0:
            if (this->frame > 18.0f) {
                this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
                this->height = (f32) (this->height + this->fallVelocity);
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((this->height - this->rootHeight) - this->position.y));
            return;
        case 1:
            this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
            this->height = (f32) (this->height + this->fallVelocity);
            ground_y = this->position.y;
            root_height = this->rootHeight;
            fall_height = this->height;
            if (fall_height < (ground_y + root_height)) {
                this->stateStep = 2;
                this->height = (f32) this->position.y;
                this->heightOffset = (f32) this->defaultHeightOffset;
                this->play_se_at_pos(0x4003AD0E);
                return;
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((fall_height - root_height) - ground_y));
            return;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge == 4) {
                spawn_particle_effect_with_flags(&this->position, this->effectResource->particle_ids[2], 0x40);
                TCameraCtrl::set_shake_preset(1);
                this->apply_landing_attack();
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->beginHeightTransition();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_head_down_attack_state(u32 reason) {
    u8 *self = (u8 *)this;
    f32 step;
    f32 dir_x;
    f32 dir_z;
    f32 frame;

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 8;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = (s32) (this->flags | 0x680);
        this->flags = (this->flags & 0xFFFFF7FF);
        this->stateStep = 0;
        this->impactAge = 0;
        this->play_se_at_pos(0x4003AD06);
        return;
    case 11:
        if (((s32) this->stateStep >= 0x96) && (this->filter_input_flags(this->controller_input->pressed_buttons, 2) != 0)) {
            this->stateStep = 0x1C2;
        }
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            this->request_state_change(0x17);
        }
        return;
    case 2:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            this->request_state_change(0x17);
            return;
        }
        break;
    case 9:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            this->remap_sequence_after_recovery();
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        switch (this->impactAge) {
        case 0:
            if (this->is_passing_frame(7.0f) != 0) {
                apply_head_fall_attack();
            } else if (this->is_passing_frame(14.0f) != 0) {
                this->sweep_head_fall_spheres_early();
            } else if (this->is_passing_frame(18.0f) != 0) {
                this->sweep_head_fall_spheres_late();
            }
            if ((s16) this->requested_action != 8) {
                this->collider->enable_blocking_bodies(&this->position, this->rotation_y);
                this->impactAge = 1;
                return;
            }
            break;
        case 1:
            this->spawn_trap(0x4003AD12);
            this->stateStep = (this->stateStep + 1);
            if ((s32) this->stateStep >= 0x1C2) {
                this->requested_action = 0xA;
                this->impactAge = 2;
                this->collider->disable_blocking_bodies();
                return;
            }
            break;
        case 2:
            step = 0.9f;
            dir_x = sin_table_lookup(this->rotation_y);
            dir_z = cos_table_lookup(this->rotation_y);
            if ((s32) this->player_controlled != 0) {
                step = this->clamp_step_in_radius(dir_x, dir_z, 0.9f);
            }
            frame = this->frame;
            if ((frame >= (13.0f)) && (frame <= (20.0f))) {
                this->move_to_shot_position(dir_x, dir_z, step);
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->update_damage_threshold();
        this->collider->disable_blocking_bodies();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_stretch_state(u32 reason) {

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 2;
        this->set_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & ~0x280);
        this->set_invulnerable();
        return;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            this->request_state_change(0x17);
            return;
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            next_sequence_action();
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        if (this->is_passing_frame((20.0f)) != 0) {
            play_cue_stream_file("draroar.adx");
            return;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->clear_invulnerable();
        break;
    }
}

void TBoss1Dragon::update_roar_state(u32 reason) {

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags |= 0xC00;
        this->flags &= ~0x280;
        play_cue_stream_file("draroar.adx");
        this->set_invulnerable();
        this->stateStep = 0;
        return;
    case 9:
        if ((s32) this->stateStep >= 0x3C) {
            next_sequence_action();
            return;
        }
        break;
    case 11:
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        this->stateStep = this->stateStep + 1;
        play_nearby_se();
        this->update_flap_effect();
        return;
    case ENEMY_STATE_LEAVE:
        this->clear_invulnerable();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_dive_state(u32 reason) {
    f32 factor;
    Vec pos;
    Vec vel;
    s32 r;
    s32 a;
    f32 k;
    f32 t;
    f32 q;
    f32 c;
    f32 sn;
    f32 cs;
    f32 s;
    u8 *mem;

    switch (reason) {
    case 4:
        this->requested_action = 0x10;
        ((TBoss1Dragon *)(((u8 *)this)))->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags &= ~0xE80;
        this->stateStep = 0;
        this->vertical_speed = (0.0f);
        this->ground_impact_done = 0;
        this->action_spin = 0;
        this->action_angle = boss1_dragon_angle_units_per_radian * atan2_float(this->destination_direction.x, this->destination_direction.z);
        factor = (5.0f);
        this->destination_distance = this->destination_distance + factor;
        this->init_air_turn(this->action_angle);
        k = -(13.0f / boss1_dragon_dive_accel);
        t = newton_sqrtf((2.0f + (this->heightOffset - 169.0f / (2.0f * boss1_dragon_dive_accel))) / -boss1_dragon_gravity);
        if (this->destination_distance < 50.0f) {
            t = this->destination_distance / (k + t);
            this->action_speed = t;
            this->rootHeight = t;
            this->root_height_speed = (0.0f);
        } else {
            q = 50.0f / t;
            this->action_speed = q;
            c = (2.0f * (q * k - (this->destination_distance - 50.0f))) / k;
            this->root_height_speed = c / k;
            this->rootHeight = q - c;
        }
        this->vertical_speed = (13.0f);
        break;
    case 2:
        if (this->stateStep == 4) {
            this->request_state_change(0x1B);
        }
        break;
    case 11:
        if (this->stateStep == 4) {
            this->request_state_change(0x24);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            next_sequence_action();
        }
        break;
    case 7:
        this->restoreTargetPosition();
        if (enable_v2_features != 0) {
            update_velocity();
        }
        break;
    case 6:
        if (this->choose_burrow_ring_destination(&this->destination) == 0) {
            this->destination.x = (0.0f);
            this->destination.y = (0.0f);
            this->destination.z = (0.0f);
        }
        update_velocity();
        this->saveTargetDestination();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            this->play_nearby_se();
            this->update_flap_effect();
            if (this->advance_air_turn() != 0) {
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->stateStep = 1;
                this->requested_action = 0x16;
            }
            break;
        case 1:
            if (this->frame >= 18.0f) {
                this->stateStep = 2;
                this->flags |= 0xC00;
                this->play_se_at_pos(0x4003B210);
            }
            break;
        case 2:
            if (this->vertical_speed > (0.0f)) {
                this->vertical_speed = this->vertical_speed + boss1_dragon_dive_accel;
                this->rootHeight = this->rootHeight + this->root_height_speed;
                this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->rootHeight);
            } else {
                this->vertical_speed = this->vertical_speed + boss1_dragon_gravity;
                this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->action_speed);
            }
            this->heightOffset = this->heightOffset + this->vertical_speed;
            this->height = this->position.y + this->heightOffset;
            if (this->vertical_speed < (0.0f)) {
                a = -(s32)(boss1_dragon_angle_units_per_radian * atan2_float(this->vertical_speed, this->rootHeight));
                if (a > this->rotation_x) {
                    this->rotation_x = a;
                }
                if (this->action_spin < 0x2800) {
                    this->action_spin += 0x120;
                }
                this->rotation_z += this->action_spin;
            } else {
                this->rotation_x = approach_angle_limited(this->rotation_x, 0x4000, 0x200);
            }
            if (this->breath_origin.y <= boss1_dragon_arena_center.y - (50.0f)) {
                this->stateStep = 3;
                this->play_se_at_pos(0x4003AD0F);
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0x17;
            }
            break;
        case 3:
            if (this->heightOffset - this->defaultHeightOffset <= (-400.0f)) {
                this->stateStep = 4;
                this->flags &= ~0x100;
            }
            if (this->heightOffset - this->defaultHeightOffset <= (0.0f) && this->ground_impact_done == 0) {
                this->spawn_impact_crater(&this->position);
                this->apply_ground_impact_attack();
                this->ground_impact_done = 1;
                ((TBoss1Dragon *)(((u8 *)this)))->set_invulnerable();
                ((TBoss1Dragon *)(((u8 *)this)))->disable_body_collision();
                this->setPhase2();
            }
            r = get_random_scaled();
            sn = sin_table_lookup(r);
            cs = cos_table_lookup(r);
            pos.x = (20.0f) * sn + this->destination.x;
            pos.y = this->destination.y;
            pos.z = (20.0f) * cs + this->destination.z;
            s = rand_range((2.0f), (0.5f));
            vel.x = sn * s;
            vel.y = rand_range(10.0f, (4.0f));
            vel.z = cs * s;
            mem = (u8 *)new TObjBoss1Rock(tl_05, &pos, &vel);
            this->heightOffset = this->heightOffset + this->vertical_speed;
            this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->action_speed);
            this->height = this->position.y + this->heightOffset;
            if (this->action_spin < 0x2800) {
                this->action_spin += 0x80;
            }
            this->rotation_z += this->action_spin;
            break;
        case 4:
            break;
        }
        break;
    case 5:
        this->rotation_x = 0;
        this->rotation_z = 0;
        break;
    }
}

void TBoss1Dragon::update_burrow_inward_run(u32 reason, s32 state) {
    f32 factor;
    s32 angle;
    Vec v;

    switch (reason) {
    case 4:
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->set_invulnerable();
        this->disable_body_collision();
        if (state == 0x10) {
            this->burrow_run_count = 0;
        } else {
            this->burrow_run_count = (this->burrow_run_count + 1);
        }
        fill_value_array(this->attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = (f32) (0.0f);
        this->rootHeight = calc_burrow_speed();
        return;
    case 2:
    case 11:
        this->request_state_change(0x1B);
        return;
    case 9:
        if ((s32) this->lobby_state_changed != 0) {
            next_sequence_action();
            this->lobby_state_changed = 0;
            return;
        }
        if ((s32) this->stateStep == 1) {
            VecCopy(&v, &this->position);
            v.y = (0.0f);
            if (normalize_vector_xz(&v) < (50.0f)) {
                next_sequence_action();
            }
        }
        return;
    case 6:
        this->position.x = (f32) ((350.0f) * sin_table_lookup(angle = (s32) ((65536.0f) * this->random_ratio())));
        this->position.z = (f32) ((350.0f) * cos_table_lookup(angle));
        this->saveCurrentDestination();
        return;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge = (this->impactAge + 1);
            if ((f32) this->impactAge >= (60.0f)) {
                this->impactAge = 0;
                this->stateStep = 1;
                this->moko_hill->start();
                this->restorePosition();
                this->rotation_y = (s32) ((s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->position.x, this->position.z)) + 0x8000);
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            break;
        case 1:
            factor = (0.1f);
            this->fallVelocity = (f32) (this->fallVelocity + factor);
            if (this->fallVelocity > this->rootHeight) {
                this->fallVelocity = this->rootHeight;
            }
            this->position.x = (f32) ((this->destination_direction.x * this->fallVelocity) + this->position.x);
            this->position.z = (f32) ((this->destination_direction.z * this->fallVelocity) + this->position.z);
            this->apply_trail_attack();
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge > 0xA) {
                start_rumble();
                this->impactAge = 0;
            }
            break;
        }
        this->spawn_trap(0x40038F11);
        return;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_burrow_outward_run(u32 reason) {
    u8 *self = (u8 *)this;
    Vec offset;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags |= 0xC00;
        this->flags &= ~0x380;
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = this->calc_burrow_speed();
        this->moko_hill->start();
        if (TBoss1Dragon::isV2Mode() == 1 && this->burrow_run_count == 2) {
            this->burrow_run_count += 1;
            this->rootHeight = this->calc_burrow_speed();
            this->burrow_run_count -= 1;
        }
        break;
    case 2:
    case 11:
        this->request_state_change(0x1B);
        break;
    case 9:
        VecCopy(&offset, &this->position);
        if (normalize_vector_xz(&offset) > (350.0f)) {
            next_sequence_action();
        }
        break;
    case 7:
        this->restoreTargetPosition();
        break;
    case 6:
        if (this->select_forward_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        } else {
            this->destination_direction.x = sin_table_lookup(this->rotation_y);
            this->destination_direction.z = cos_table_lookup(this->rotation_y);
        }
        this->destination.x = (350.0f) * this->destination_direction.x;
        this->destination.y = (0.0f);
        this->destination.z = (350.0f) * this->destination_direction.z;
        this->saveTargetDestination();
        break;
    case ENEMY_STATE_UPDATE:
        this->update_velocity();
        this->rotation_y = approach_angle_limited(this->rotation_y, (boss1_dragon_angle_units_per_radian * atan2_float(this->destination_direction.x, this->destination_direction.z)), 0x600);
        this->position.x += this->rootHeight * sin_table_lookup(this->rotation_y);
        this->position.z += this->rootHeight * cos_table_lookup(this->rotation_y);
        this->apply_trail_attack();
        this->impactAge += 1;
        if (this->impactAge > 10) {
            this->start_rumble();
            this->impactAge = 0;
        }
        this->spawn_trap(0x40038F11);
        break;
    case ENEMY_STATE_LEAVE:
        this->clear_invulnerable();
        this->enable_body_collision();
        this->moko_hill->stop();
        break;
    }
}

void TBoss1Dragon::handle_spiral_state(u32 reason) {
    s32 angle;
    s32 turn;

    switch (reason) {
    case 4:
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->set_invulnerable();
        this->disable_body_collision();
        fill_value_array(this->attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = this->calc_burrow_speed();
        this->fallVelocity = (f32) ((2.5f) * this->rootHeight);
        this->action_speed = (f32) (350.0f);
        this->action_angle = 0;
        return;
    case 2:
    case 11:
        this->request_state_change(0x1B);
        return;
    case 9:
        if ((s32) this->lobby_state_changed != 0) {
            this->next_sequence_action();
            this->lobby_state_changed = 0;
            return;
        }
        if ((s32) this->stateStep == 2) {
            this->next_sequence_action();
        }
        return;
    case 6:
        angle = (s32) ((65536.0f) * this->random_ratio());
        this->position.x = (f32) ((350.0f) * sin_table_lookup(angle));
        this->position.z = (f32) ((350.0f) * cos_table_lookup(angle));
        this->saveCurrentDestination();
        return;
    case 0:
        switch (this->stateStep) {
        case 2:
            break;
        case 0:
            this->impactAge = (this->impactAge + 1);
            if ((f32) this->impactAge >= (60.0f)) {
                this->impactAge = 0;
                this->stateStep = 1;
                this->moko_hill->start_without_hold();
                this->restorePosition();
                this->action_angle = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->position.x, this->position.z));
                return;
            }
            break;
        case 1:
            turn = (s32) (boss1_dragon_angle_units_per_radian * (this->fallVelocity / this->action_speed));
            this->action_angle += turn;
            this->position.x = this->action_speed * sin_table_lookup(this->action_angle);
            this->position.z = this->action_speed * cos_table_lookup(this->action_angle);
            this->action_speed -= (0.001068115234375f) * (f32) turn;
            if (this->action_speed < (5.0f)) {
                this->stateStep = 2;
            }
            this->apply_trail_attack();
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge > 0xA) {
                this->start_rumble();
                this->impactAge = 0;
            }
            this->spawn_trap(0x40038F11);
            return;
        }
        break;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        this->moko_hill->stop();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_emergence_state(u32 reason) {
    f32 factor;
    Vec *v = (Vec *)&this->action_point;
    f32 len;

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x18;
        advance_animation();
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        if (this->stateStep == 6) {
            this->request_state_change(0x19);
        }
        return;
    case 9:
        if (this->stateStep == 6) {
            this->request_state_change(8);
        }
        return;
    case 6:
        if (this->choose_burrow_ring_destination(&this->destination) == 0) {
            this->destination.x = (0.0f);
            this->destination.y = this->position.y;
            this->destination.z = (0.0f);
            this->update_velocity();
        }
        this->saveTargetDestination();
        return;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 0:
            (this->impactAge)++;
            if ((f32) this->impactAge >= (100.0f)) {
                this->stateStep = 1;
                this->restorePosition();
                this->flags |= 0x100;
                v->x = boss1_dragon_arena_center.x - this->position.x;
                v->y = (0.0f);
                v->z = boss1_dragon_arena_center.z - this->position.z;
                len = normalize_vector_xz((Vec *)v);
                if (len <= (100.0f)) {
                    this->fallVelocity = (0.0f);
                    this->rotation_x = 0;
                } else {
                    f32 k = (37.333335876464844f);
                    k += newton_sqrtf((298.66668701171875f));
                    this->fallVelocity = len / k;
                    this->rotation_x = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->fallVelocity, (15.0f)));
                }
                this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(v->x, v->z));
                this->rootHeight = (15.0f);
                v->x *= this->fallVelocity;
                v->z *= this->fallVelocity;
                factor = (-11.333333015441895f);
                this->position.x = v->x * factor + this->position.x;
                this->position.z = v->z * factor + this->position.z;
                this->height = (-170.0f);
                this->heightOffset = this->defaultHeightOffset + (this->height - this->position.y);
            }
            break;
        case 1:
            if (this->height > boss1_dragon_arena_center.y) {
                this->stateStep = 2;
                this->clear_invulnerable();
                this->enable_body_collision();
                this->setActive();
                this->spawn_impact_crater(&this->position);
                this->apply_ground_impact_attack();
                this->play_se_at_pos(0x4003AD0F);
            }
            break;
        case 2:
            if (this->height > (110.0f)) {
                this->stateStep = 3;
            }
            break;
        case 3:
            if (this->rootHeight < (0.0f) && this->height < (220.0f)) {
                this->stateStep = 4;
                this->action_speed = (this->rootHeight * this->rootHeight) / (80.0f);
            }
            break;
        case 4:
            if (this->rootHeight > (0.0f)) {
                this->stateStep = 5;
                this->rootHeight = (0.0f);
                this->impactAge = 0;
            }
            break;
        }
        switch (this->stateStep) {
        case 1:
            vec3_add_to(&this->position, v);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - this->position.y);
            break;
        case 2:
            vec3_add_to(&this->position, v);
            this->rootHeight += (-0.4017857015132904f);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - this->position.y);
            break;
        case 3:
            advance_animation();
            this->rootHeight += (-0.4017857015132904f);
            this->height += this->rootHeight;
            if (this->frame >= (15.0f)) {
                v->x *= (0.98f);
                v->z *= (0.98f);
            }
            vec3_add_to(&this->position, v);
            this->rotation_x = approach_angle_limited(this->rotation_x, 0, 0x80);
            this->heightOffset = this->height - this->position.y;
            break;
        case 4:
            advance_animation();
            if (this->requested_action == 0x10) {
                this->play_nearby_se();
            }
            this->rootHeight += this->action_speed;
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - this->position.y);
            v->x *= (0.98f);
            v->z *= (0.98f);
            vec3_add_to(&this->position, v);
            break;
        case 5:
            advance_animation();
            this->play_nearby_se();
            (this->impactAge)++;
            if (this->impactAge >= 50) {
                this->stateStep = 6;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->rotation_x = 0;
        break;
    }
}

#pragma pop
#pragma push
#pragma pool_data off
void TBoss1Dragon::update_death_state(u32 reason) {
    CameraPlayback cam;
    Vec rot;
    Vec v;
    switch (reason) {
    case 4:
        this->requested_action = 0x13;
        ((TBoss1Dragon *)(((u8 *)this)))->set_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags |= 0xE80;
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = (0.0f);
        this->breath_particles[0] = 0;
        play_cue_stream_file("dradeath.adx");
        TWindowCtrl::init_all_slots();
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            cam.index = 0;
            cam.bank = 2;
            cam.flags = 0;
            cam.frame = (0.0f);
            cam.frame_step = (0.5f);
            activate_camera_mode(5);
            cam.play(0x31C7);
            set_scripted_camera_origin(&this->position, &this->position, (CameraAngles *)&this->rotation_x);
            break;
        case 1:
            cam.index = 1;
            cam.bank = 2;
            cam.flags = 0;
            cam.frame = (0.0f);
            cam.frame_step = (0.5f);
            activate_camera_mode(5);
            cam.play(0x3333);
            set_scripted_camera_origin(&this->position, &this->position, (CameraAngles *)&this->rotation_x);
            break;
        }
        break;
    case 2:
    case 11:
        if (this->impactAge >= 0x32) {
            this->request_state_change(0x16);
        }
        break;
    case 9:
        if (this->impactAge >= 0x32) {
            this->request_state_change(0x16);
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->is_passing_frame((f32)(60.0f)) != 0 || this->is_passing_frame((f32)((f32)(98.0f))) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (this->frame >= (25.0f) && this->frame < (40.0f)) {
                direction_to_rotation_xz((u8 *)&this->breath_direction, (s32 *)&rot.x, (s32 *)&rot.z);
                if (this->breath_particles[0] == 0) {
                    this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation((void *)(&this->breath_origin), (void *)&rot, (saddr)((void *)((TBoss1Dragon *)((u8 *)this))->effectResource->particle_ids[5]), (int)(0x40));
                }
                if (this->breath_particles[0] != 0) {
                    this->breath_particles[0]->set_position(&this->breath_effect_position);
                    this->breath_particles[0]->set_direction(&rot);
                }
            } else if (this->breath_particles[0] != 0) {
                ((TObject *)(this->breath_particles[0]))->queue_destruction();
                this->breath_particles[0] = 0;
            }
            if (this->is_passing_frame((f32)(57.0f)) != 0) {
                DragonAttackParams eff1 = boss1_dragon_head_fall_attack_params;
                eff1.radius = 12.0f;
                VecCopy(&v, &boss1_dragon_death_impact_point_a);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, &this->position);
                reset_hp(NULL, boss1_dragon_part_hp_stats[4], NULL);
                switch (TBoss1Dragon::isV2Mode()) {
                case 0:
                    TObjEneDD::emit_effect(this, &v, &eff1);
                    break;
                case 1:
                    this->emit_v2_enemy_effect(&v, &eff1, NULL);
                    break;
                }
                reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
                spawn_particle_effect_with_flags(&v, this->effectResource->particle_ids[2], 0x40);
            }
            if (this->is_passing_frame((f32)(88.0f)) != 0) {
                DragonAttackParams eff2 = boss1_dragon_head_fall_attack_params;
                eff2.radius = 25.0f;
                VecCopy(&v, &boss1_dragon_death_impact_point_b);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, &this->position);
                reset_hp(NULL, boss1_dragon_part_hp_stats[4], NULL);
                switch (TBoss1Dragon::isV2Mode()) {
                case 0:
                    TObjEneDD::emit_effect(this, &v, &eff2);
                    break;
                case 1:
                    this->emit_v2_enemy_effect(&v, &eff2, NULL);
                    break;
                }
                reset_hp(NULL, boss1_dragon_part_hp_stats[0], NULL);
                spawn_particle_effect_with_flags(&v, this->effectResource->particle_ids[2], 0x40);
            }
            if (this->is_passing_frame((f32)(97.0f)) != 0) {
                this->sweep_death_body_attack();
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 1;
                this->impactAge = 0;
            }
            break;
        case 1:
            this->impactAge += 1;
            if (this->impactAge >= 0x32) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        this->refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x17);
        this->actorFlags = 0x12008;
        ((TBoss1Dragon *)(((u8 *)this)))->sync_enemy_state(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (this->breath_particles[0] != 0) {
            ((TObject *)(this->breath_particles[0]))->queue_destruction();
            this->breath_particles[0] = 0;
        }
        if (this->player_controlled != 0) {
            this->release_held_player();
        }
        break;
    }
}

#pragma pop
void TBoss1Dragon::update_fade_state(u32 reason) {
    s32 i;

    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x13;
        this->set_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags |= 0xE80;
        for (i = 0; i < 4; i++) {
            this->viewFade[i].set_speed(0.005f);
        }
        break;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        for (i = 0; i < 4; i++) {
            if (this->viewFade[i].decay_value_toward_floor() != 0) {
                queue_destruction();
            }
        }
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case ENEMY_STATE_LEAVE:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    case 10:
        return;
    case 11:
        return;
    }
}

void TBoss1Dragon::update_controlled_stand_state(u32 reason) {

    ControllerInputContext *in;
    s32 flags;

    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = this->flags & ~0xE80;
        return;
    case 11:
        in = this->controller_input;
        if (in->stick_magnitude > (0.1f)) {
            this->request_state_change(0x18);
            return;
        }
        if (this->filter_input_flags(in->pressed_buttons, 4) != 0) {
            this->request_state_change(3);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 2) != 0) {
            this->request_state_change(4);
            return;
        }
        if (this->check_attack_ready() != 0) {
            this->request_state_change(5);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, fn_8002AE08(boss1_dragon_control_client_id)) != 0) {
            this->request_state_change(9);
        }
        return;
    case 2:
        in = this->controller_input;
        if (in->stick_magnitude > (0.1f)) {
            this->request_state_change(0x18);
            return;
        }
        flags = in->pressed_buttons;
        if (flags & 4) {
            this->request_state_change(3);
            return;
        }
        if (flags & 2) {
            this->request_state_change(4);
            return;
        }
        if (flags & 0x400) {
            this->request_state_change(5);
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case 0:
        this->advance_animation();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_controlled_walk_state(u32 reason) {
    f32 dir_x;
    f32 dir_z;
    f32 step;
    f32 frame;
    s32 input_flags;
    ControllerInputContext *input;
    s32 *saved = &this->action_angle;

    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->clearState();
        this->beginHeightTransition();
        this->flags = (s32) (this->flags & ~0xE80);
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
        if ((s32) this->impactAge == 1) {
            this->request_state_change(0x17);
            return;
        }
        input_flags = this->controller_input->pressed_buttons;
        if (input_flags & 4) {
            this->request_state_change(3);
            return;
        }
        if (input_flags & 2) {
            this->request_state_change(4);
            return;
        }
        if (input_flags & 0x400) {
            this->request_state_change(5);
        }
        return;
    case 11:
        if ((s32) this->impactAge == 1) {
            this->request_state_change(0x17);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 4) != 0) {
            this->request_state_change(3);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 2) != 0) {
            this->request_state_change(4);
            return;
        }
        if (this->check_attack_ready() != 0) {
            this->request_state_change(5);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, fn_8002AE08(boss1_dragon_control_client_id)) != 0) {
            this->request_state_change(9);
            return;
        }
        break;
    case 8:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep >= 0x1E) {
            this->stateStep = 0;
            input = this->controller_input;
            if (input->stick_magnitude <= (0.1f)) {
                this->impactAge = 1;
                return;
            }
            *saved = input->stick_angle;
            this->setDestinationX(*saved);
            this->send_state_sync();
            return;
        }
        break;
    case 7:
        this->copySavedX((int*)saved);
        return;
    case 6:
        this->setDestinationX(this->rotation_y);
        return;
    case 0:
        this->advance_animation();
        if ((s16) this->requested_action == 1) {
            this->play_sound_if_in_band();
        }
        if (this->is_passing_frame((3.0f)) != 0) {
            this->apply_foot_attack_pair_0();
        } else if (this->is_passing_frame((24.0f)) != 0) {
            this->apply_foot_attack_pair_1();
        }
        step = (0.8f);
        this->play_speed = (f32) (0.48000001907348633f);
        frame = this->frame;
        if ((!(frame > (4.0f)) || !(frame < (9.0f))) && (!(frame > (24.0f)) || !(frame < (30.0f)))) {
            this->rotation_y = approach_angle_limited(this->rotation_y, *saved, 0x200);
            dir_x = sin_table_lookup(this->rotation_y);
            dir_z = cos_table_lookup(this->rotation_y);
            if ((s32) this->player_controlled != 0) {
                step = this->clamp_step_in_radius(dir_x, dir_z, (0.8f));
            }
            this->move_to_shot_position(dir_x, dir_z, step);
        }
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_controlled_hover_state(u32 reason) {

    ControllerInputContext *in;
    s32 flags;

    switch (reason) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags = this->flags & ~0xE80;
        return;
    case 11:
        if (this->controlTimer > 0x1C2 || this->filter_input_flags(this->controller_input->pressed_buttons, 2) != 0) {
            this->request_state_change(8);
            return;
        }
        in = this->controller_input;
        if (in->stick_magnitude > (0.1f)) {
            this->request_state_change(0x1A);
            return;
        }
        if (this->filter_input_flags(in->pressed_buttons, 4) != 0) {
            this->request_state_change(7);
            return;
        }
        if (this->check_can_attack() != 0) {
            this->request_state_change(0xF);
        }
        return;
    case 2:
        in = this->controller_input;
        if (in->stick_magnitude > (0.1f)) {
            this->request_state_change(0x1A);
            return;
        }
        flags = in->pressed_buttons;
        if (flags & 4) {
            this->request_state_change(7);
            return;
        }
        if (flags & 2) {
            this->request_state_change(0xF);
            return;
        }
        if (flags & 0x400) {
            this->request_state_change(8);
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case 0:
        this->advance_animation();
        this->play_nearby_se();
        this->update_flap_effect();
        break;
    default:
        return;
    }
}

void TBoss1Dragon::update_controlled_flight_state(u32 reason) {
    f32 dir_x;
    f32 dir_z;
    f32 step;
    s32 input_flags;
    ControllerInputContext *input;
    s32 *saved = &this->action_angle;

    switch (reason) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->setActive();
        this->set_flight_height();
        this->flags = (s32) (this->flags & ~0xE80);
        this->stateStep = 0x64;
        this->impactAge = 0;
        return;
    case 11:
        if (((s32) this->controlTimer > 0x1C2) || (this->filter_input_flags(this->controller_input->pressed_buttons, 2) != 0)) {
            this->request_state_change(8);
            return;
        }
        if ((s32) this->impactAge == 1) {
            this->request_state_change(0x19);
            return;
        }
        if (this->filter_input_flags(this->controller_input->pressed_buttons, 4) != 0) {
            this->request_state_change(7);
            return;
        }
        if (this->check_can_attack() != 0) {
            this->request_state_change(0xF);
        }
        return;
    case 2:
        if ((s32) this->impactAge == 1) {
            this->request_state_change(0x19);
            return;
        }
        input_flags = this->controller_input->pressed_buttons;
        if (input_flags & 4) {
            this->request_state_change(7);
            return;
        }
        if (input_flags & 2) {
            this->request_state_change(0xF);
            return;
        }
        if (input_flags & 0x400) {
            this->request_state_change(8);
            return;
        }
        break;
    case 8:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep >= 0x1E) {
            this->stateStep = 0;
            input = this->controller_input;
            if (input->stick_magnitude <= (0.1f)) {
                this->impactAge = 1;
                return;
            }
            *saved = input->stick_angle;
            this->setDestinationX(*saved);
            this->send_state_sync();
            return;
        }
        break;
    case 7:
        this->copySavedX((int*)saved);
        return;
    case 6:
        this->setDestinationX(*saved);
        return;
    case 0:
        this->advance_animation();
        this->play_nearby_se();
        this->update_flap_effect();
        this->rotation_y = approach_angle_limited(this->rotation_y, *saved, 0x200);
        dir_x = sin_table_lookup(this->rotation_y);
        dir_z = cos_table_lookup(this->rotation_y);
        step = (2.0f);
        if ((s32) this->player_controlled != 0) {
            step = this->clamp_step_in_radius(dir_x, dir_z, step);
        }
        this->move_with_wall_stop(dir_x, dir_z, step);
        break;
    default:
        return;
    }
}

void TBoss1Dragon::handle_state(u32 reason) {
    ControllerInputContext *input;

    switch (reason) {
    case 4:
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        return;
    case 2:
    case 11:
        input = this->controller_input;
        if (input->stick_magnitude > (0.1f)) {
            this->request_state_change(0x1C);
            return;
        }
        if (input->pressed_buttons & 2) {
            this->request_state_change(0x13);
            return;
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case 0:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0xA) {
            this->start_rumble();
            this->stateStep = 0;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::handle_walk_state(u32 reason) {
    f32 factor;
    f32 dx;
    f32 dz;
    Vec *home;
    ControllerInputContext *in;

    home = &this->action_point;
    switch (reason) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = this->flags | 0xC00;
        this->flags = this->flags & 0xFFFFFC7F;
        this->set_invulnerable();
        this->disable_body_collision();
        VecCopy(home, &this->position);
        this->stateStep = 0x64;
        this->impactAge = 0;
        home->y = boss1_dragon_arena_center.y;
        this->fallVelocity = (0.0f);
        this->rootHeight = (0.0f);
        this->moko_hill->start();
        return;
    case 2:
    case 11:
        if (this->impactAge == 1) {
            this->request_state_change(0x1B);
            return;
        }
        if (this->controller_input->pressed_buttons & 2) {
            this->request_state_change(0x13);
        }
        return;
    case 8:
        this->stateStep = this->stateStep + 1;
        if (this->stateStep >= 0x1E) {
            this->stateStep = 0;
            in = this->controller_input;
            if (in->stick_magnitude <= (0.1f)) {
                this->impactAge = 1;
                return;
            }
            this->rotation_y = in->stick_angle;
            this->setDestinationX(this->rotation_y);
            this->send_state_sync();
            return;
        }
        break;
    case 7:
        this->copySavedX((int *)&this->rotation_y);
        return;
    case 6:
        this->setDestinationX(this->rotation_y);
        return;
    case 0:
        dx = sin_table_lookup(this->rotation_y);
        dz = cos_table_lookup(this->rotation_y);
        factor = (4.0f);
        this->position.x = dx * factor + this->position.x;
        this->position.z = dz * factor + this->position.z;
        horizontal_distance_squared(&this->position, home);
        dx = ((f32 (*)(void))newton_sqrtf)();
        VecCopy(home, &this->position);
        this->fallVelocity = this->fallVelocity + dx;
        return;
    case 5:
        this->moko_hill->stop();
        break;
    default:
        return;
    }
}

#pragma pop
void TBoss1Dragon::state_circle_flight(u32 reason) {
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->set_invulnerable();
        this->disable_body_collision();
        this->updateFacingPosition();
        this->moko_hill->start_without_hold();
        return;
    case 2:
    case 11:
        if (((s32) this->stateStep >= 0x1C2) || (this->filter_input_flags(this->controller_input->pressed_buttons, 0x400) != 0)) {
            this->request_state_change(0x25);
        }
        return;
    case 7:
        this->facingAngle = (s32) this->savedX;
        if (this->savedZ > (0.0f)) {
            this->action_angle = 0x180;
            return;
        }
        this->action_angle = -0x180;
        return;
    case 6:
        this->destinationX = (f32) ((65536.0f) * this->random_ratio());
        this->destinationZ = this->calc_elapsed_scaled();
        return;
    case ENEMY_STATE_UPDATE:
        this->facingAngle = (s32) (this->facingAngle + this->action_angle);
        if ((s32) this->action_angle >= 0) {
            this->rotation_y = (this->facingAngle + 0x9800);
        } else {
            this->rotation_y = (this->facingAngle + 0xFFFF6800);
        }
        this->updateFacingPosition();
        this->stateStep++;
        this->apply_trail_attack();
        return;
    case ENEMY_STATE_LEAVE:
        this->moko_hill->stop();
        break;
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::handle_fall_state(u32 reason) {
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->setPhase2();
        this->set_burrow_height();
        this->flags = this->flags | 0xC00;
        this->flags = this->flags & 0xFFFFFC7F;
        this->set_invulnerable();
        this->disable_body_collision();
        this->fallVelocity = (0.0f);
        this->destination_direction.x = -this->position.x;
        this->destination_direction.y = (0.0f);
        this->destination_direction.z = -this->position.z;
        normalize_vector_xz((Vec *)&this->destination_direction);
        this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->destination_direction.x, this->destination_direction.z));
        this->moko_hill->start_without_hold();
        return;
    case 2:
    case 11:
        if (this->rootHeight >= (680.0f)) {
            this->request_state_change(0x13);
        }
        return;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        this->fallVelocity += (0.1f);
        if (this->fallVelocity > (12.0f)) {
            this->fallVelocity = (12.0f);
        }
        this->rootHeight = this->rootHeight + this->fallVelocity;
        this->position.x = this->destination_direction.x * this->fallVelocity + this->position.x;
        this->position.z = this->destination_direction.z * this->fallVelocity + this->position.z;
        this->apply_trail_attack();
        return;
    case ENEMY_STATE_LEAVE:
        this->moko_hill->stop();
        break;
    default:
        return;
    }
}

#pragma pop
void TBoss1Dragon::update_wander_state(s32 reason) {
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0xB;
        this->stateStep = 0;
        return;
    case ENEMY_STATE_UPDATE:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0x5A) {
            this->stateStep = 0;
            this->requested_action = (this->requested_action + 1);
            if ((s16) this->requested_action >= 0x1B) {
                this->requested_action = 0;
            }
        }
        advance_animation();
    case 3:
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    }
}

void TBoss1Dragon::update_appearance_state(u32 reason) {
    s32 *demo = &this->demo_flag;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0;
        this->clearState();
        advance_animation();
        this->position.x = (0.0f);
        this->position.y = (0.0f);
        this->position.z = (0.0f);
        this->rotation_x = 0;
        this->rotation_y = 0;
        this->rotation_z = 0;
        this->height = (0.0f);
        this->heightOffset = this->defaultHeightOffset;
        this->breath_particles[0] = 0;
        switch (TBoss1Dragon::isV2Mode()) {
        case 0:
            this->stateStep = 1;
            break;
        case 1:
            this->stateStep = 2;
            break;
        }
        this->action_frames = 0;
        this->impactAge = 0;
        *demo = 1;
        new TBoss1DragonDemo(tl_01, demo, 0.5f);
        this->requested_action = 25;
        TWindowCtrl::init_all_slots();
        this->get_target_state_b();
        ((TMainCursor *)this)->update_pair();
        break;
    case 2:
    case 9:
        if (this->stateStep == 4) {
            this->request_state_change(0);
        }
        break;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 0:
            break;
        case 1:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                this->stateStep = 4;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 0;
            }
            switch (this->action_frames) {
            case 0:
                if (this->is_passing_frame((f32)(2.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    this->action_frames++;
                }
                break;
            case 1:
                if (this->is_passing_frame((f32)(32.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (this->is_passing_frame((f32)(35.0f)) != 0) {
                    spawn_particle_effect_with_flags(&this->position, this->effectResource->particle_ids[2], 0x40);
                    this->action_frames++;
                }
                break;
            case 2:
                if (this->is_passing_frame((f32)(75.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 3:
                if (this->frame <= (80.0f)) {
                    this->impactAge++;
                    if (this->impactAge % 4 == 0) {
                        spawn_particle_effect_with_flags(&this->breath_origin, this->effectResource->particle_ids[7], 0x40);
                    }
                } else {
                    this->action_frames++;
                }
                break;
            case 4:
                if (this->is_passing_frame((f32)(105.0f)) != 0) {
                    play_cue_stream_file("dradeath.adx");
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 5:
                if (this->frame < (150.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&this->breath_direction, &rot.x, &rot.z);
                    if (this->breath_particles[0] == 0) {
                        this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->breath_origin, &rot, this->effectResource->particle_ids[5], 0x40);
                    } else {
                        this->breath_particles[0]->set_position(&this->breath_origin);
                        this->breath_particles[0]->set_direction(&rot);
                    }
                } else {
                    if (this->breath_particles[0] != 0) {
                        this->breath_particles[0]->queue_destruction();
                        this->breath_particles[0] = 0;
                    }
                    this->action_frames++;
                }
                break;
            }
            break;
        case 2:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                this->stateStep = 4;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 0;
            }
            switch (this->action_frames) {
            case 0:
                if (this->is_passing_frame((f32)(9.0f)) != 0 ||
                    this->is_passing_frame((f32)(40.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                }
                if (this->is_passing_frame((f32)(62.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (this->is_passing_frame((f32)(64.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    spawn_particle_effect_with_flags(&this->position, this->effectResource->particle_ids[2], 0x40);
                    this->action_frames++;
                }
                break;
            case 1:
                if (this->is_passing_frame((f32)(92.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 2:
                if (this->frame <= (99.0f)) {
                    this->impactAge++;
                    if (this->impactAge % 4 == 0) {
                        spawn_particle_effect_with_flags(&this->breath_origin, this->effectResource->particle_ids[7], 0x40);
                    }
                } else {
                    this->action_frames++;
                }
                break;
            case 3:
                if (this->is_passing_frame((f32)(120.0f)) != 0) {
                    play_cue_stream_file("dradeath.adx");
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 4:
                if (this->frame < (155.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&this->breath_direction, &rot.x, &rot.z);
                    if (this->breath_particles[0] == 0) {
                        this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->breath_origin, &rot, this->effectResource->particle_ids[5], 0x40);
                    } else {
                        this->breath_particles[0]->set_position(&this->breath_origin);
                        this->breath_particles[0]->set_direction(&rot);
                    }
                } else {
                    if (this->breath_particles[0] != 0) {
                        this->breath_particles[0]->queue_destruction();
                        this->breath_particles[0] = 0;
                    }
                    this->action_frames++;
                }
                break;
            }
            break;
        case 3:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                this->stateStep = 4;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 0;
            }
            switch (this->action_frames) {
            case 0:
                if (this->is_passing_frame((f32)(2.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    this->action_frames++;
                }
                break;
            case 1:
                if (this->is_passing_frame((f32)(60.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (this->is_passing_frame((f32)(63.0f)) != 0) {
                    spawn_particle_effect_with_flags(&this->position, this->effectResource->particle_ids[2], 0x40);
                    spawn_particle_effect_with_flags(&this->position, 0x203, 0x40);
                    this->action_frames++;
                }
                break;
            case 2:
                if (this->is_passing_frame((f32)(75.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 3:
                if (this->frame > (80.0f)) {
                    this->action_frames++;
                }
                break;
            case 4:
                if (this->is_passing_frame((f32)(105.0f)) != 0) {
                    play_cue_stream_file("dradeath.adx");
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 5:
                if (this->frame < (150.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&this->breath_direction, &rot.x, &rot.z);
                    if (this->breath_particles[0] == 0) {
                        this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->breath_origin, &rot, this->effectResource->particle_ids[5], 0x40);
                    } else {
                        this->breath_particles[0]->set_position(&this->breath_origin);
                        this->breath_particles[0]->set_direction(&rot);
                    }
                } else {
                    if (this->breath_particles[0] != 0) {
                        this->breath_particles[0]->queue_destruction();
                        this->breath_particles[0] = 0;
                    }
                    this->action_frames++;
                }
                break;
            }
            break;
        case 4:
            advance_animation();
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (this->breath_particles[0] != 0) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        ((TMainCursor *)this)->update_cursor_pair();
        *demo = 0;
        TWindowCtrl::init_all_slots2();
        this->get_target_state_a();
        break;
    }
}

void TBoss1Dragon::wait_for_players(s32 reason) {
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0;
        this->stateStep = 0;
        this->position.y = (f32) (0.0f);
        this->heightOffset = (f32) ((300.0f) + this->defaultHeightOffset);
        this->height = (f32) (this->defaultHeightOffset + (this->heightOffset + this->position.y));
        return;
    case 3:
        if ((s32) this->stateStep > 0x96) {
            transition_enemy_state((s16)(8));
        }
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    case ENEMY_STATE_UPDATE:
        if ((get_player_by_client_id(0) != NULL) || (get_player_by_client_id(1) != NULL) || (get_player_by_client_id(2) != NULL) || (get_player_by_client_id(3) != NULL)) {
            this->stateStep = (this->stateStep + 1);
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
s32 TBoss1Dragon::is_sphere_visible(Vec *center, f32 radius) {
    Vec delta;
    f32 distance;
    VecCopy(&delta, center);
    delta.y = 0.0f;
    subtract_vector(&delta, &boss1_dragon_reference_pos_vec);
    distance = normalize_vector_xz(&delta);
    if ((distance + radius) < boss1_dragon_visibility_distance) {
        if (vec3_dot(&delta, &boss1_dragon_forward_reference_vec) >= (distance * ((1.0f) / newton_sqrtf((f32) ((distance * distance) + (radius * radius)))))) {
            return 1;
        }
    }
    return 0;
}

#pragma pop
s32 TBoss1Dragon::check_parts_visible(TObjCollidable *parts) {
    s32 n;
    s32 i;
    n = parts->body_count;
    for (i = 0; i < n; i++) {
        if (this->is_sphere_visible(&parts->bodies[i].center, parts->bodies[i].radius) != 0) {
            return 1;
        }
    }
    return 0;
}

void dragon_capture_node_points(NJS_OBJECT *) {
    s32 cursor;
    Vec *point;
    if ((s32) boss1_dragon_capture_node == (s32) boss1_dragon_breath_node) {
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(NULL, boss1_dragon_breath_local_points.vectors, boss1_dragon_breath_points_out, 3);
        pop_matrix();
    }
    if ((s32) boss1_dragon_capture_node == (s32) boss1_dragon_capture_node_table[boss1_dragon_capture_cursor]) {
        point = boss1_dragon_capture_points_out;
        boss1_dragon_capture_points_out = point + 1;
        forward_transform_to_view(&boss1_dragon_node_origin, point);
        cursor = boss1_dragon_capture_cursor + 1;
        boss1_dragon_capture_cursor = cursor;
        if ((cursor == 7) && !(boss1_dragon_capture_flags & 0x80)) {
            boss1_dragon_capture_cursor = 0xC;
            boss1_dragon_capture_points_out += 5;
        }
        if (((s32) boss1_dragon_capture_cursor == 0x12) && !(boss1_dragon_capture_flags & 0x200)) {
            boss1_dragon_capture_cursor = 0x20;
            boss1_dragon_capture_points_out += 14;
        }
    }
    boss1_dragon_capture_node += 1;
}

void TBoss1Dragon::draw() {
    void *saved_model;

    saved_model = this->model;
    this->model = boss1_dragon_capture_model;
    set_chunk_model_node_callback(dragon_capture_node_points);
    push_matrix();
    post_translate_matrix(&this->position.x);
    translate_matrix(0, (0.0f), this->heightOffset, (0.0f));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    TObjMotion::draw();
    pop_matrix();
    set_chunk_model_node_callback(NULL);
    this->model = saved_model;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::render() {
    s32 view;
    s32 saved;
    s32 i;
    RenderFadeState *ch;
    s32 visible;
    s16 state;
    TObjCollidable *ent;
    s32 hit;
    f32 dist;
    view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_low_detail();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    boss1_dragon_capture_node = 0;
    boss1_dragon_breath_points_out = this->breath_node_points;
    boss1_dragon_capture_cursor = 0;
    boss1_dragon_capture_points_out = this->node_positions;
    boss1_dragon_capture_flags = *(s32 *)&this->flags;
    this->update_object_view_visibility((1000.0f), (1000.0f));
    ch = &this->viewFade[view];
    if (ch->has_visible_opacity() != 0) {
        if (is_split_screen() != 0 && this->heightOffset - this->defaultHeightOffset >= (-5.0f) &&
            this->mode != 0x16) {
            push_matrix();
            post_translate_matrix(&this->position.x);
            translate_matrix(0, (0.0f), (2.0f), (0.0f));
            rotate_matrix_y(0, this->rotation_y);
            scale_matrix(0, (2.0f), (0.001f), (2.0f));
            rotate_matrix_x(0, this->rotation_x);
            rotate_matrix_z(0, this->rotation_z);
            NJS_ARGB color = dragon_boss1_render_color;
            saved = *(s32 *)&this->model;
            this->model = boss1_dragon_resource->models[1].model;
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)((&color)));
            TObjMotion::draw();
            model_render_flags = saved_model_render_flags;
            *(s32 *)&this->model = saved;
            pop_matrix();
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        state = this->mode;
        visible = 1;
        if (state == 0x16) {
            ch->set_flags_and_apply_damage_color();
            visible = 0;
        } else {
            hit = 0;
            if (camera_ctrl_instance != NULL && state != 0x1D && state != 0x16 && state != 0x15 &&
                this->phase == 0) {
                ent = find_entity_by_id(TCameraCtrl::get_camera_target_id(-1));
                if (ent != NULL) {
                    Vec origin;
                    Vec delta;
                    Vec *points[4];
                    Vec probe;
                    VecCopy(&origin, &camera_ctrl_instance->pos);
                    origin.y = (0.0f);
                    VecCopy(&delta, &ent->position);
                    subtract_vector(&delta, &origin);
                    delta.y = (0.0f);
                    dist = normalize_vector_xz((Vec *)&delta);
                    VecCopy(&boss1_dragon_reference_pos_vec, &origin);
                    VecCopy(&boss1_dragon_forward_reference_vec, &delta);
                    *(f32 *) &boss1_dragon_visibility_distance = dist;
                    points[0] = &this->node_positions[3];
                    points[1] = &this->node_positions[4];
                    points[2] = &this->node_positions[5];
                    points[3] = &this->node_positions[6];
                    for (i = 0; i < 4; i++) {
                        if (this->is_sphere_visible(points[i], (12.0f)) != 0) {
                            hit = 1;
                            break;
                        }
                    }
                    if (this->mode == 9) {
                        if (hit == 0) {
                            probe.x = this->position.x - (25.0f) * sin_table_lookup(this->rotation_y);
                            probe.y = (0.0f);
                            probe.z = this->position.z - (25.0f) * cos_table_lookup(this->rotation_y);
                            hit = this->is_sphere_visible(&probe, (20.0f));
                        }
                        if (hit == 0) {
                            hit = this->check_parts_visible(this->collider->get_object(1));
                        }
                        if (hit == 0) {
                            hit = this->check_parts_visible(this->collider->get_object(2));
                        }
                    }
                }
            }
            if (hit != 0) {
                ch->fadeOut();
            } else {
                ch->restore();
            }
            ch->update();
            if (ch->isFading() != 0) {
                ch->set_flags_and_apply_damage_color();
                visible = 0;
            }
        }
        if (visible == 0) {
            if (defer_render() != 0) {
                visible = 0;
            } else {
                visible = 1;
            }
        }
        if (visible != 0) {
            push_matrix();
            post_translate_matrix(&this->position.x);
            translate_matrix(0, (0.0f), this->heightOffset, (0.0f));
            rotate_matrix_y(0, this->rotation_y);
            rotate_matrix_x(0, this->rotation_x);
            rotate_matrix_z(0, this->rotation_z);
            scale_matrix(0, (2.0f), (2.0f), (2.0f));
            set_chunk_model_node_callback(dragon_capture_node_points);
            TObjPlayer::toggle_particle_effect();
            TObjMotion::draw();
            TParticleCtrl::end_effect_render();
            set_chunk_model_node_callback(NULL);
            current_scene_light->sub_801337F8();
            pop_matrix();
        }
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    } else {
        this->draw();
        this->update_object_view_visibility((1000.0f), (1000.0f));
    }
    VecCopy(&this->breath_origin, &this->breath_node_points[0]);
    VecCopy(&this->breath_direction, &this->breath_node_points[1]);
    subtract_vector(&this->breath_direction, &this->breath_origin);
    VecCopy(&this->breath_effect_position, &this->breath_node_points[2]);
    saved_model_render_flags = model_render_flags;
    model_render_flags = saved_model_render_flags | 0x400;
    this->sub_tasks.render_nodes();
    model_render_flags = saved_model_render_flags;
}

#pragma pop
void TBoss1Dragon::render_shadows() {
    void *body_model;
    s32 view;

    view = 0;
    if (TObjPlayer::check_demo_mode() == 0) {
        if (is_split_screen() != 0) {
            view = TCameraCtrl::get_camera_mode();
        }
        if ((this->viewFade[view].has_visible_opacity() != 0) && ((this->heightOffset - this->defaultHeightOffset) >= (-5.0f)) && ((s16) this->mode != 0x16)) {
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, (int) (this->rotation_y));
            scale_matrix(0, (2.0f), (2.0f), (2.0f));
            rotate_matrix_x(0, this->rotation_x);
            rotate_matrix_z(0, (int) (this->rotation_z));
            body_model = this->model;
            this->model = boss1_dragon_resource->models[1].model;
            TObjMotion::draw();
            this->model = body_model;
            pop_matrix();
        }
    }
}

int TBoss1Dragon::run_demo_task() { return this->get_target_info(); }

void TBoss1Dragon::render_low_detail() {
    TBoss1Dragon *self = this;
    AnimationMotion *m;
    s32 i;
    f32 frame;

    if (((TBoss1Dragon*)self)->update_object_view_visibility((400.0f), (20.0f)) == 0) {
        return;
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    push_matrix();
    scale_matrix(0, (8.0f), (2.0f), (8.0f));
    pop_matrix();
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    model_render_flags &= ~0x400;
    i = (s32)this->parameters[0];
    if (i < 0) {
        i = 0;
    } else if (i >= 0x1B) {
        i = 0x1A;
    }
    m = motion_list[action_table[i].motion].motion;
    frame = this->parameters[1];
    if (frame < (0.0f)) {
        frame = (0.0f);
    } else {
        if (frame > (m->frameCount - 1)) {
            frame = (f32)m->frameCount;
        }
    }
    draw_model_motion(this->model, m, frame);
    current_scene_light->sub_801337F8();
    pop_matrix();
}

s32 TBoss1Dragon::isV2Mode() {
    return TObjEneDD::check_v2_mode() ? 1 : 0;
}
