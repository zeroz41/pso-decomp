#include "pso/system/SubtractiveRng.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#pragma defer_codegen on
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/DragonAttackParams.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/system/vector.h"
#include "pso/enemy/EnemyStateEvent.h"
#include "pso/render/MaterialColorFade.h"
#include "types.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/PadRumble.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include <stddef.h>
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/PlayerStats.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/galgryphon/Boss5GryphonActionScripts.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/boss/galgryphon/TBoss5GryphonShockWave.h"
#include "pso/boss/galgryphon/TBoss5GryphonTornado.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningHorn.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "pso/unk/TLobby_802268F4.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
// TObjPlayer_80011014.h declares these too, but its calc_random_ratio prototype takes no rng.
extern "C" {
f64 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
s32 is_split_screen();
f32 fabs_float(f32);
}
const char *bm_modelparticle_gryphon_model_names[4] = {
    "boss_rock.gj", "fe_obj001_iwaware_01.gj", "fe_obj001_iwaware_02.gj", NULL,
};
const char *bm_modelparticle_gryphon_motion_names[2] = {
    "boss_rock.njm", NULL,
};
// Resource descriptor passed to load_enemy_bml_resource for boss5_gryphon_bml_resource.
BmlResourceDescriptor boss5_gryphon_bml_desc = {
    "bm_modelparticle_gryphon.bml", bm_modelparticle_gryphon_model_names, bm_modelparticle_gryphon_motion_names, 3, 1,
};
// Ids resolved into boss5_gryphon_attack_params / boss5_gryphon_behavior_params by the resource loader.
s32 boss5_gryphon_attack_param_ids[5] = { 0x1E, 0x1F, 0x20, 0x21, 0x22 };
s32 boss5_gryphon_behavior_param_ids[3] = { 0x1E, 0x1F, 0x20 };
s32 boss5_gryphon_base_stat_indices[3] = { 0, 0, 0 };
s32 boss5_gryphon_attack_stat_indices[3] = { 0, 1, 2 };
s32 boss5_gryphon_resistance_stat_indices[3] = { 0, 0, 0 };
// What the constructor points TObjEnemy::movementParameters at.
struct Boss5GryphonMovementParameters {
    EnemyMoveParams move;
    s32 pad_0C[4];
};
Boss5GryphonMovementParameters boss5_gryphon_movement_params = { { 225.0f, 0.0f, 0x600 } };
void *boss5_gryphon_collision_body_parts[110] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
extern const Vec boss5_gryphon_arena_center = { 0.0f, 0.0f, 0.0f };
extern const DragonAttackParams boss5_gryphon_params_b = { 0, 0.0f, 30.0f, {7.0f, 1} };
extern const s32 boss5_gryphon_effect_ids[9] = { 0x220, 0x221, 0x222, 0x202, 0x200, 0x207, 0x223, 0x224, 0x225 };
extern const s32 boss5_gryphon_bone_capture_node_indices[16] = {
    4, 11, 27, 43, 46, 47, 48, 66, 69, 70, 71, 95, 128, 144, 159, 999,
};
const char *bm_boss5_gryphon_model_names[5] = {
    "boss5_s_body.nj", "boss5_ss_body.nj", "lo_boss5_s_body.nj", "lo_boss5_ss_body.nj",
    NULL,
};
const char *bm_boss5_gryphon_motion_names[28] = {
    "fly_boss5_s_body.njm", "hoe_boss5_s_body.njm", "kakuin_boss5_s_body.njm", "kakuland_boss5_s_body.njm",
    "kakuout_boss5_s_body.njm", "kaku_boss5_s_body.njm", "land_boss5_s_body.njm", "op_boss5_s_body.njm",
    "shot_boss5_s_body.njm", "stand_boss5_s_body.njm", "takeoff_boss5_s_body.njm", "walk_boss5_s_body.njm",
    "huseout_boss5_s_body.njm", "houko_boss5_s_body.njm", "huse_boss5_s_body.njm", "husein_boss5_s_body.njm",
    "dead_boss5_s_body.njm", "kiri_boss5_s_body.njm", "kiriland_boss5_s_body.njm", "kirin_boss5_s_body.njm",
    "kiriout_boss5_s_body.njm", "run_boss5_s_body.njm", "runin_boss5_s_body.njm", "runout_boss5_s_body.njm",
    "tuno_boss5_s_body.njm", "tunoin_boss5_s_body.njm", "tunout_boss5_s_body.njm", NULL,
};
// Resource descriptor passed to load_enemy_bml_resource for boss5_gryphon_body_bml_resource.
BmlResourceDescriptor boss5_gryphon_body_bml_desc = {
    "bm_boss5_gryphon.bml", bm_boss5_gryphon_model_names, bm_boss5_gryphon_motion_names, 4, 27,
};
extern const char boss5_gryphon_type_name[] = "TBoss5Gryphon";
extern const s32 gryphon_part_attack_index_table[4] = { 1, 2, 12, 13 };
extern const DragonAttackParams gryphon_part_attack_params = { 0, 10.0f, 15.0f, {8.0f, 1} };
extern const DragonAttackParams gryphon_collider_desc = { 0, 0.0f, 80.0f, {0.0f, 1} };
extern const f32 gryphon_effect_scale_table[5] = { 20.0f, 30.0f, 50.0f, 30.0f, 20.0f };
extern const DragonAttackParams gryphon_effect_param_block = { 0, 0.0f, 0.0f, {7.0f, 1} };
extern const DragonAttackParams boss8_dragon_attack_params = { 0, 0.0f, 0.0f, {7.0f, 1} };
extern const DragonAttackParams gryphon_run_body_attack_params = { 0, 10.0f, 35.0f, {10.0f, 1} };
extern const DragonAttackParams gryphon_ground_contact_attack_params = { 0, 10.0f, 5.0f, {10.0f, 1} };
extern const DragonAttackParams gryphon_shockwave_hit_params = { 0, 10.0f, 15.0f, {10.0f, 1} };
extern const DragonAttackParams gryphon_tornado_hit_params = { 0, 10.0f, 15.0f, {10.0f, 1} };
extern const DragonAttackParams gryphon_snarl_hit_params = { 0, 10.0f, 10.0f, {10.0f, 1} };
extern const DragonAttackParams gryphon_lightning_hit_params = { 3, 10.0f, 10.0f, {20.0f, 1} };
// update_death_state's leave position and update_demo_state's start pose.
extern const Vec boss5_gryphon_death_position = { 0.0f, 2.0f, 0.0f };
extern const Vec boss5_gryphon_demo_position = { 23.0f, 180.0f, 991.0f };
extern const s32 boss5_gryphon_demo_rotation[3] = { -2928, 36734, 0 };
extern const Vec boss5_gryphon_waypoint_vecs[2] = { { 27.0f, 0.0f, 175.0f }, { 153.0f, 437.0f, 1347.0f } };
extern const f32 boss5_gryphon_scale_x_table[4] = { 0.3f, 0.75f, 0.75f, 0.0f };
extern const f32 boss5_gryphon_scale_y_table[4] = { 0.0f, 0.75f, 0.75f, 0.0f };
extern const f32 gryphon_velocity_scale_z_table[4] = { 0.0f, 0.75f, 0.75f, 0.0f };
extern const f32 gryphon_action_probability_table_a[9] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f };
const f32 gryphon_action_probability_table_b[9] = { 0.0f, 0.0f, 0.1f, 0.2f, 0.2f, 0.3f, 0.4f, 0.4f, 0.5f };
const s32 gryphon_bone_copy_index_table[10] = { 0, 1, 2, 12, 13, 11, 3, 5, 7, 9 };
const s32 boss5_gryphon_point_index_table[5] = { 1, 2, 12, 13, 0 };
AttackParams *boss5_gryphon_attack_params[5];
Boss5GryphonParams *boss5_gryphon_behavior_params[3];
Vec boss5_gryphon_bone_capture_origin;
Vec boss5_gryphon_camera_pos_vec;
u8 boss5_gryphon_direction_vec[0x10];  // a Vec; the split end counts the 4 bytes of .bss alignment after it
extern const f32 lbl_805D9E80;
// Set up by this file's static initializer (the last function in the object): 3x and 2x the enemies'
// per-frame gravity (TObjEneDD's -0.1f), the pair TBoss1Dragon names lift and gravity accel.
f32 boss5_gryphon_lift_accel = gryphon_three * lbl_805D9E80;
f32 boss5_gryphon_gravity_accel = 2.0f * lbl_805D9E80;
player_stats *boss5_gryphon_base_params[1];
ActorParamBlock *boss5_gryphon_resistance_params[1];
BmlResource *boss5_gryphon_body_bml_resource;
BmlResource *boss5_gryphon_bml_resource;
NJS_TEXLIST *boss5_gryphon_texture_list;
s32 boss5_gryphon_render_node_index;
s32 boss5_gryphon_bone_capture_index;
Vec *boss5_gryphon_bone_capture_output;  // draw_body points it at bone_positions
s32 boss5_gryphon_render_flags;
TBoss5Gryphon *boss5_gryphon_instance;
f32 boss5_gryphon_camera_player_distance;  // blocks_camera_view: camera to player, xz
extern "C" {
TObjMotionAction boss5_gryphon_action_table[27] = {
    { MOTION_MODE_LOOP, 0, 9, 0.8f, 0 },
    { MOTION_MODE_LOOP, 0, 11, 0.5f, 0 },
    { MOTION_MODE_ONCE, 0, 1, 0.43f, 0 },
    { MOTION_MODE_ONCE, 0, 10, 0.5f, 0 },
    { MOTION_MODE_LOOP, 0, 0, 0.77f, 0 },
    { MOTION_MODE_ONCE, 0, 6, 0.48f, 0 },
    { MOTION_MODE_CHAIN, 7, 2, 0.7f, 0x6 },
    { MOTION_MODE_LOOP, 0, 5, 0.9f, 0x7 },
    { MOTION_MODE_ONCE, 0, 4, 0.57f, 0 },
    { MOTION_MODE_ONCE, 0, 3, 0.7f, 0 },
    { MOTION_MODE_CHAIN, 11, 22, 1.0f, 0xa },
    { MOTION_MODE_LOOP, 0, 21, 1.0f, 0xb },
    { MOTION_MODE_ONCE, 0, 23, 1.0f, 0 },
    { MOTION_MODE_CHAIN, 14, 15, 0.4f, 0xd },
    { MOTION_MODE_LOOP, 0, 14, 0.35f, 0xe },
    { MOTION_MODE_ONCE, 0, 12, 0.4f, 0 },
    { MOTION_MODE_CHAIN, 17, 25, 0.75f, 0x10 },
    { MOTION_MODE_LOOP, 0, 24, 0.35f, 0x11 },
    { MOTION_MODE_ONCE, 0, 26, 0.6f, 0 },
    { MOTION_MODE_CHAIN, 20, 19, 0.5f, 0x13 },
    { MOTION_MODE_LOOP, 0, 17, 1.0f, 0x14 },
    { MOTION_MODE_ONCE, 0, 20, 0.5f, 0x15 },
    { MOTION_MODE_ONCE, 0, 18, 0.4f, 0x16 },
    { MOTION_MODE_ONCE, 0, 13, 0.35f, 0 },
    { MOTION_MODE_ONCE, 0, 8, 0.65f, 0 },
    { MOTION_MODE_ONCE, 0, 7, 1.0f, 0x80000000 },
    { MOTION_MODE_ONCE, 0, 16, 0.5f, 0 },
};
Vec boss5_gryphon_follow_camera_target_offset = {0.0f, 19.8f, -5.0f};
Vec boss5_gryphon_follow_camera_eye_offset = {0.0f, 25.43f, 45.42f};
extern CurvePathPoint boss5_gryphon_landing_bezier_points[4];
extern CurvePathPoint boss5_gryphon_descend_bezier_points[4];
extern Vec gryphon_left_horn_lightning_offset;
extern Vec gryphon_right_horn_lightning_offset;
extern void *gryphon_particle_enable_pos[3];
extern void *gryphon_particle_position_vec[3];
#define gryphon_particle_enable_pos ((u8 *)gryphon_particle_enable_pos)
#define gryphon_particle_position_vec ((s32 *)gryphon_particle_position_vec)
typedef void (TBoss5Gryphon::*StateAction)(int);
}
const f32 gryphon_max_floor_height = 6.0f;
#pragma push
#pragma inline on
extern "C" {
static inline StateAction *dispatch_state_actions() {
static StateAction actions[35] = {
    (StateAction)&TBoss5Gryphon::state_action_noop,
    (StateAction)&TBoss5Gryphon::update_idle_state,
    (StateAction)&TBoss5Gryphon::update_ground_pursuit,
    (StateAction)&TBoss5Gryphon::wait_for_players,
    (StateAction)&TBoss5Gryphon::update_demo_state,
    (StateAction)&TBoss5Gryphon::update_death_state,
    (StateAction)&TBoss5Gryphon::update_ground_takeoff,
    (StateAction)&TBoss5Gryphon::update_shockwave_attack,
    (StateAction)&TBoss5Gryphon::update_turning_flight,
    (StateAction)&TBoss5Gryphon::circle_arena,
    (StateAction)&TBoss5Gryphon::move_to_motion_destination,
    (StateAction)&TBoss5Gryphon::update_landing_attack,
    (StateAction)&TBoss5Gryphon::update_glide_in,
    (StateAction)&TBoss5Gryphon::update_low_flight_straight,
    (StateAction)&TBoss5Gryphon::update_low_flight_circle,
    (StateAction)&TBoss5Gryphon::update_bezier_descent,
    (StateAction)&TBoss5Gryphon::update_dive_motion,
    (StateAction)&TBoss5Gryphon::update_spiral_in,
    (StateAction)&TBoss5Gryphon::handle_descend_state,
    (StateAction)&TBoss5Gryphon::handle_takeoff_state,
    (StateAction)&TBoss5Gryphon::update_run_in,
    (StateAction)&TBoss5Gryphon::state_move,
    (StateAction)&TBoss5Gryphon::update_run_out,
    (StateAction)&TBoss5Gryphon::update_crouch_in,
    (StateAction)&TBoss5Gryphon::update_crouch,
    (StateAction)&TBoss5Gryphon::update_crouch_out,
    (StateAction)&TBoss5Gryphon::update_horn_in,
    (StateAction)&TBoss5Gryphon::update_ground_lightning_attack,
    (StateAction)&TBoss5Gryphon::update_horn_out,
    (StateAction)&TBoss5Gryphon::update_offscreen_climb,
    (StateAction)&TBoss5Gryphon::update_offscreen_dive,
    (StateAction)&TBoss5Gryphon::update_roar_state,
    (StateAction)&TBoss5Gryphon::update_howl_state,
    (StateAction)&TBoss5Gryphon::update_mode_idle,
    (StateAction)&TBoss5Gryphon::handle_message,
};
    return actions;
}

}
#pragma pop
extern "C" {
CurvePathPoint boss5_gryphon_landing_bezier_points[4] = {
    {{0.0f, 67.0f, 0.0f}, 0.0f},
    {{0.0f, 107.0f, 0.0f}, 0.0f},
    {{0.0f, 147.0f, 0.0f}, 0.0f},
    {{0.0f, 65.0f, 0.0f}, 0.0f},
};
#undef gryphon_particle_enable_pos
#undef gryphon_particle_position_vec
CurvePathPoint boss5_gryphon_descend_bezier_points[4] = {
    {{0.0f, 67.0f, 0.0f}, 0.0f},
    {{0.0f, 157.0f, 0.0f}, 0.0f},
    {{0.0f, 307.0f, 0.0f}, 0.0f},
    {{0.0f, 65.0f, 0.0f}, 0.0f},
};
Vec gryphon_left_horn_lightning_offset = { -25.0f, 0.0f, 69.0f };
Vec gryphon_right_horn_lightning_offset = { 19.0f, 0.0f, 69.0f };
typedef void (TBoss5Gryphon::*ScriptAction)(Boss5GryphonMotionEntry *, Boss5GryphonActionStep *);
}
#pragma push
#pragma inline on
extern "C" {
static inline ScriptAction *script_step_actions() {
    static ScriptAction actions[35] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        (ScriptAction)&TBoss5Gryphon::calc_product_and_ratio,
        (ScriptAction)&TBoss5Gryphon::calc_params,
        (ScriptAction)&TBoss5Gryphon::calc_move_params,
        0, 0, 0,
        (ScriptAction)&TBoss5Gryphon::calc_attack_params,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        (ScriptAction)&TBoss5Gryphon::set_random_param,
        0, 0,
        (ScriptAction)&TBoss5Gryphon::set_random_param,
        0, 0, 0, 0,
    };
    return actions;
}

}
#pragma pop
extern "C" {
void *gryphon_particle_enable_pos[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
void *gryphon_particle_position_vec[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
#define gryphon_particle_enable_pos ((u8 *)gryphon_particle_enable_pos)
#define gryphon_particle_position_vec ((s32 *)gryphon_particle_position_vec)
#define F(t, o) (*(t *)(arg0 + (o)))
#define TBL(o) (*(s32 *)((s8 *)(F(u8 *, 0x778)) + (o)))
#define PLAY_SE(o, id) ((TBoss5Gryphon *)o)->play_se((id))
inline s32 initial_angle_800623E4(TBoss5Gryphon *self) {
    Boss5GryphonMoveArgs *move = &self->motion->args.move;
    f32 initial_dx = move->x;
    f32 initial_dz = move->z - self->position.z;
    initial_dx -= self->position.x;
    return (s32)(10430.38043493439 * atan2_float(initial_dx, initial_dz));
}

#define F(t, o) (*(t *)(arg0 + (o)))
}
extern "C" {
// Ids resolved into boss5_gryphon_base_params / boss5_gryphon_resistance_params by the resource loader.
s32 boss5_gryphon_base_param_ids[1] = { 0x1E };
s32 boss5_gryphon_resistance_param_ids[1] = { 0x1E };
const char *boss5_gryphon_type_name_pointer = boss5_gryphon_type_name;
}

extern "C" {
void attach_particle_model(TParticleCtrl *particle, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                           AnimationMotion *motion, s32 loop, f32 frame) {
    particle->model = model;
    particle->texlist = texlist;
    particle->motion = reinterpret_cast<NJS_MOTION *>(motion);
    particle->emit_flags |= 0x200;
    particle->motion_frame = frame;
    if (loop != 0) {
        particle->emit_flags |= 0x400;
    }
}

extern "C" void load_boss5_gryphon_resources(void);
void TObjMotion::disable_motion_blend() {
    motion_flags &= ~MOTION_BLENDING;
    motion_flags |= MOTION_NO_BLEND;
}

void G_GalGryphonBossActions_6x9F::init() {
    header.subcommand = 0x9F;
    header.size = 4;
}

}
void G_GalGryphonBossActions_6x9F::bswap() {
    header.bswap();
    bswap_32(&target_id);
    bswap_32((u32 *)&x);
    bswap_32((u32 *)&z);
}

void G_GalGryphonBossActions_6x9F::send() { bswap(); send_subcommand(this); }

void Boss5GryphonMotionEntry::bswap() {
    s32 i;
    bswap_16((u16 *)&state);
    bswap_16((u16 *)&timer);
    for (i = 0; i < 4; i++) {
        bswap_32(&args.words[i]);
    }
}

void G_GalGryphonBossActions_6xA0::bswap() {
    header.bswap();
    motion.bswap();
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
    bswap_32((u32 *)&angle_y);
}

void G_GalGryphonBossActions_6xA0::send() { bswap(); send_subcommand(this); }

void G_GalGryphonBossActions_6xA0::init() { header.subcommand = 0xA0; header.size = 10; }

void TBoss5Gryphon::clear_harmful_statuses() {  }

void TBoss5Gryphon::apply_shock_status() {  }

void TBoss5Gryphon::apply_movement_ailment(s32) {  }

void TBoss5Gryphon::apply_confusion_status() {  }

void TBoss5Gryphon::apply_slow_status() {  }

void TBoss5Gryphon::apply_paralysis() {  }

void TBoss5Gryphon::apply_poison_status() {  }

TBoss5Gryphon *TBoss5Gryphon::get_instance() { return boss5_gryphon_instance; }

extern "C" {
const Vec *get_arena_center(void) {
    return &boss5_gryphon_arena_center;
}

}
void get_gryphon_follow_camera_offsets(Vec *target_offset, Vec *eye_offset) {
    if (boss5_gryphon_instance == NULL) {
        VecCopy(target_offset, &boss5_gryphon_follow_camera_target_offset);
        VecCopy(eye_offset, &boss5_gryphon_follow_camera_eye_offset);
        return;
    }
    boss5_gryphon_instance->fill_follow_camera_params(target_offset, eye_offset);
}

void TBoss5Gryphon::fill_follow_camera_params(Vec *target_offset, Vec *eye_offset) {
    target_offset->x = 0.0f;
    eye_offset->x = 0.0f;
    switch (this->flight_mode) {
    default:
    case 2:
    case 0:
        target_offset->y = boss5_gryphon_behavior_params[0]->camera[0];
        target_offset->z = boss5_gryphon_behavior_params[0]->camera[1];
        eye_offset->y = boss5_gryphon_behavior_params[0]->camera[2];
        eye_offset->z = boss5_gryphon_behavior_params[0]->camera[3];
        return;
    case 1:
        target_offset->y = boss5_gryphon_behavior_params[0]->camera[4];
        target_offset->z = boss5_gryphon_behavior_params[0]->camera[5];
        eye_offset->y = boss5_gryphon_behavior_params[1]->camera[0];
        eye_offset->z = boss5_gryphon_behavior_params[1]->camera[1];
        return;
    case 3:
        target_offset->y = boss5_gryphon_behavior_params[1]->camera[2];
        target_offset->z = boss5_gryphon_behavior_params[1]->camera[3];
        eye_offset->y = boss5_gryphon_behavior_params[1]->camera[4];
        eye_offset->z = boss5_gryphon_behavior_params[1]->camera[5];
        return;
    }
}

extern "C" {
// Inferred: TBoss5Gryphon's resource loader (paired with TBoss5Gryphon::cleanup in the boss resource table).
void load_boss5_gryphon_resources(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        boss5_gryphon_body_bml_resource = load_enemy_bml_resource(&boss5_gryphon_body_bml_desc);
        boss5_gryphon_bml_resource = load_enemy_bml_resource(&boss5_gryphon_bml_desc);
        boss5_gryphon_texture_list = load_gvm_texture_file("modelparticle_gryphon.gvm");
        break;
    }
    boss5_gryphon_render_node_index = 0;
    boss5_gryphon_bone_capture_origin.x = 0.0f;
    boss5_gryphon_bone_capture_origin.y = 0.0f;
    boss5_gryphon_bone_capture_origin.z = 0.0f;
    boss5_gryphon_bone_capture_index = 0;
    boss5_gryphon_bone_capture_output = 0;
    boss5_gryphon_render_flags = 0;
    boss5_gryphon_instance = NULL;
    for (s32 i = 0; i < 1; i++) {
        boss5_gryphon_base_params[i] = TLobby::register_boss(boss5_gryphon_base_param_ids[i]);
    }
    for (s32 i = 0; i < 5; i++) {
        boss5_gryphon_attack_params[i] = TLobby::dispatch_shared_handler_b(boss5_gryphon_attack_param_ids[i]);
    }
    for (s32 i = 0; i < 1; i++) {
        boss5_gryphon_resistance_params[i] = TLobby::register_object(boss5_gryphon_resistance_param_ids[i]);
    }
    for (s32 i = 0; i < 3; i++) {
        boss5_gryphon_behavior_params[i] = (Boss5GryphonParams *)TLobby::dispatch_shared_handler_a(boss5_gryphon_behavior_param_ids[i]);
    }
    TWindowCtrl::init_all_slots();
    TBoss5GryphonShockWave::select_particle_table();
    TBoss5GryphonTornado::select_particle_table();
    TBoss5GryphonSnarl::select_effect_table();
    TBoss5GryphonLightningEff::load_texture();
}

}
void *TBoss5Gryphon::create(void *data) {
    return new TBoss5Gryphon(tl_04, data);
}

void TBoss5Gryphon::cleanup() {
    TBoss5GryphonLightningEff::release_texture();
    TBoss5GryphonSnarl::release_effect_table();
    TBoss5GryphonTornado::release_particle_table();
    TBoss5GryphonShockWave::release_particle_table();
    if (boss5_gryphon_texture_list != NULL) {
        release_texture_list(boss5_gryphon_texture_list);
        safe_free(boss5_gryphon_texture_list);
        boss5_gryphon_texture_list = NULL;
    }
    if (boss5_gryphon_bml_resource != NULL) {
        delete boss5_gryphon_bml_resource;
        boss5_gryphon_bml_resource = NULL;
    }
    if (boss5_gryphon_body_bml_resource != NULL) {
        delete boss5_gryphon_body_bml_resource;
        boss5_gryphon_body_bml_resource = NULL;
    }
}

TBoss5Gryphon::TBoss5Gryphon(TObject *parent, void *data) : TObjEneDD_ST(parent), sub_tasks(NULL) {
    u32 flags[4];
    s32 i;

    __ct__14SubtractiveRngFv(this->rng);
    this->m_name = boss5_gryphon_type_name_pointer;
    if (boss5_gryphon_instance == NULL) {
        boss5_gryphon_instance = this;
    }
    ((TObjEneDD *)this)->invoke_initialization_hook(data);
    this->flags = 0;
    if (this->exchange_object_state(flags, 1) != 0 && (flags[0] & 0x12008) == 0x12008) {
        this->flags |= 1;
    }
    this->init_position_vectors();
    if (is_split_screen() != 0) {
        this->model = boss5_gryphon_body_bml_resource->models[2].model;
    } else {
        this->model = boss5_gryphon_body_bml_resource->models[0].model;
    }
    this->texlist = boss5_gryphon_body_bml_resource->models[0].texlist;
    ((TObjEneDD *)this)->init_model((CollisionBody *)boss5_gryphon_collision_body_parts, (s32)10);
    this->motion_flags = 0;
    this->set_action_table(boss5_gryphon_action_table);
    this->set_motion_list(boss5_gryphon_body_bml_resource->motions);
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    ((TObjEneDD *)this)->reset_hp(boss5_gryphon_base_params[boss5_gryphon_base_stat_indices[0]], boss5_gryphon_attack_params[boss5_gryphon_attack_stat_indices[0]], boss5_gryphon_resistance_params[boss5_gryphon_resistance_stat_indices[0]]);
    this->set_state_flag_2();
    this->movementParameters = &boss5_gryphon_movement_params;
    ((TObjEneDD *)this)->initialize_enemy_state(77);
    this->wall_reach = 20.0f;
    ((TObjEneDD_ST *)this)->set_target_destination(&boss5_gryphon_arena_center);
    this->enemy_init_acquire_period(10);
    this->enemy_init_validate_period(10);
    this->move_velocity.x = 0.0f;
    this->move_velocity.y = 0.0f;
    this->move_velocity.z = 0.0f;
    this->turn_velocity = 0;
    this->position_correction.x = 0.0f;
    this->position_correction.y = 0.0f;
    this->position_correction.z = 0.0f;
    for (i = 0; i < 2; i++) {
        this->motions[i].init();
    }
    this->motion = this->motions;
    this->flight_mode = 0;
    for (i = 0; i < 15; i++) {
        VecCopy(&this->bone_positions[i], &this->position);
    }
    for (i = 0; i < 10; i++) {
        VecCopy(&this->body_points[i], &this->position);
    }
    for (i = 0; i < 16; i++) {
        this->parts[i] = 0;
    }
    this->script_entry = 0;
    this->action_scripts = boss5_gryphon_action_scripts;
    VecCopy(&this->sound_origin, &this->position);
    VecCopy(&this->pad_56C, &this->position);
    stat_block->proportions = gryphon_ten;
    this->attack_history = new AreaAttackHistory(4);
    this->collider = new TBoss5GryphonColli(&this->sub_tasks);
    for (i = 0; i < 4; i++) {
        this->renderFadeStates[i].activate_and_dispatch();
    }
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        this->effect_ids = boss5_gryphon_effect_ids;
        break;
    }
    this->work.step = 0;
    this->work.timer = 0;
    this->work.substep = 0;
    this->work.demo_flag = 0;
    this->work.target_angle = 0;
    this->work.pad_14 = 0;
    this->work.fall_speed = 0.0f;
    this->work.pad_1C[0] = 0.0f;
    this->work.pad_1C[1] = 0.0f;
    this->work.pad_1C[2] = 0.0f;
    this->work.pad_1C[3] = 0.0f;
    this->work.pad_1C[4] = 0.0f;
    this->work.pad_1C[5] = 0.0f;
    this->work.pad_1C[6] = 0.0f;
    this->work.pad_1C[7] = 0.0f;
    this->work.pad_1C[8] = 0.0f;
    this->work.pad_1C[9] = 0.0f;
    this->pad_720 = 0;
    this->particles[0] = NULL;
    this->particles[1] = NULL;
    this->particles[2] = NULL;
    this->mode = 0;
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (this->update_lobby_state() != 0) {
            this->run_mode = 0;
        } else {
            this->run_mode = 1;
        }
    } else {
        this->run_mode = 0;
    }
    this->mode = 4;
    if (!(this->flags & 1)) {
        this->dispatch_action(this->mode, 4);
    }
    this->run_mode_changed = 0;
}

TBoss5Gryphon::~TBoss5Gryphon() {
    s32 i;
    for (i = 15; i >= 0; i--) {
        if (this->parts[i] != 0) {
            this->parts[i]->queue_destruction();
            this->parts[i] = 0;
        }
    }
    if (this->collider != 0) {
        delete this->collider;
        this->collider = 0;
    }
    if (this->attack_history != 0) {
        delete this->attack_history;
        this->attack_history = 0;
    }
    free_collision_body_parts(this);
    if (boss5_gryphon_instance == this) {
        boss5_gryphon_instance = 0;
    }
}

void TBoss5Gryphon::run_task() {
    s32 run_mode;
    s32 temp_r31_2;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (this->flags & 1) {
        send_entity_set_flags();
        queue_destruction();
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        run_mode = this->run_mode;
        if (update_lobby_state() != 0) {
            this->run_mode = 0;
            if (this->run_mode != run_mode) {
                this->run_mode_changed = 1;
            }
        } else {
            this->run_mode = 1;
        }
    }
    temp_r31_2 = TObjEneDD::query_teammate_state();
    update_attack_stat_status();
    update_defense_stat_status();
    if (temp_r31_2 == 0) {
        if (get_flag_bit6() != 0) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        if (this->run_mode != 1) {
            if (test_flag30_512() != 0) {
                clear_attack_receipts();
            }
            update_state_or_dispatch_tick();
            flush_pending_effect();
            dispatch_action(this->mode, 8);
            dispatch_action(this->mode, 0);
        } else {
            if (test_flag30_512() != 0) {
                clear_attack_receipts();
            }
            dispatch_action(this->mode, 0);
        }
    }
    sub_800BBA0C();
    apply_velocity();
    apply_position_correction();
    advance_motion_timer();
    update_body_colliders();
    shift_position_history();
    submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    VecCopy(&this->pad_56C, &this->body_center);
    if (temp_r31_2 == 0) {
        this->sub_tasks.run_tasks();
    }
    project_sound_origin_from_camera(&this->position, &this->sound_origin, gryphon_point_four);
    for (i = 0; i < 4; i++) {
        renderFadeStates[i].update();
    }
    if (this->flight_mode != 0) {
        update_collider_from_table();
    }
}

void TBoss5Gryphon::update_state_or_dispatch_tick() {
    if (!(flags & 0xC) && hp <= 0) {
        set_animation_by_state();
    } else {
        dispatch_action(mode, 9);
    }
}

void TBoss5Gryphon::refresh_target() {  }

void TBoss5Gryphon::run_death_reaction() {  }

void TBoss5Gryphon::run_hit_reaction() {  }

void TBoss5Gryphon::run_miss_reaction() {  }

void TBoss5Gryphon::shift_position_history() {
    VecCopy(&body_center, &bone_positions[0]);
    VecCopy(&center, &body_center);
}

void TBoss5Gryphon::update_body_colliders() {
    if (flags & 0x80) {
        for (s32 i = 0; i < 10; i++) {
            bodies[i].flags &= ~1;
        }
        return;
    }
    update_local_colliders_from_world(this, body_points);
    {
        f32 lim = gryphon_thirty;
        s32 i;
        for (i = 0; i < 10; i++) {
            CollisionBody *p;
            bodies[i].flags |= 1;
            p = &bodies[i];
            if (p->offset.y + p->center.y >= lim) {
                set_collider_contact_high(p);
            } else {
                set_collider_contact_low(p);
            }
        }
    }
    if (flight_mode == 2) {
        bodies[0].flags |= 0x300;
        bodies[1].flags |= 0x300;
        bodies[2].flags |= 0x300;
        bodies[3].flags |= 0x300;
        bodies[2].flags |= 0x300;
        bodies[6].flags &= ~1;
        bodies[7].flags &= ~1;
        bodies[8].flags &= ~1;
        bodies[9].flags &= ~1;
        bodies[0].radius = gryphon_one_hundred_ten;
        set_collider_contact_low(&bodies[0]);
        set_collider_contact_low(&bodies[1]);
        set_collider_contact_low(&bodies[2]);
        set_collider_contact_low(&bodies[3]);
        set_collider_contact_low(&bodies[2]);
    } else {
        bodies[0].flags &= ~0x300;
        bodies[1].flags &= ~0x300;
        bodies[2].flags &= ~0x300;
        bodies[3].flags &= ~0x300;
        bodies[2].flags &= ~0x300;
        bodies[6].flags |= 1;
        bodies[7].flags |= 1;
        bodies[8].flags |= 1;
        bodies[9].flags |= 1;
        bodies[0].radius = gryphon_ten;
    }
    bodies[0].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_0_value;
    bodies[1].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_1_4_value;
    bodies[2].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_1_4_value;
    bodies[3].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_1_4_value;
    bodies[4].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_1_4_value;
    bodies[5].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_5_value;
    bodies[6].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_6_9_value;
    bodies[7].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_6_9_value;
    bodies[8].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_6_9_value;
    bodies[9].unk_28 = boss5_gryphon_behavior_params[2]->attack.collider_6_9_value;
}

void TBoss5Gryphon::update_linked_ground_position() {
    this->update_linked_position(gryphon_thousand);
}

void TBoss5Gryphon::play_se(s32 se_id) {
    s32 self = (saddr)this;
    ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(se_id, self + 0x560, 0, 0);
}

void TBoss5Gryphon::spawn_ancient_trap(s32 id) {
    play_persistent_sound(id, this, &sound_origin, 0, 0);
}

void TBoss5Gryphon::play_walk_footsteps() {
    if (is_passing_frame(gryphon_twenty_one) != 0 || is_passing_frame(gryphon_five) != 0 || is_passing_frame(20.0f) != 0 || is_passing_frame(8.0f) != 0) {
        play_se(0x40032D08);
    }
}

void TBoss5Gryphon::play_run_footsteps() {
    if (is_passing_frame(gryphon_twelve) != 0 || is_passing_frame(8.0f) != 0 || is_passing_frame(gryphon_fifteen) != 0 || is_passing_frame(gryphon_eleven) != 0) {
        play_se(0x40032D08);
    }
}

void TBoss5Gryphon::enter_ground_mode() { this->flight_mode = 0; }

void TBoss5Gryphon::enter_flight_mode() { flight_mode = 1; }

void TBoss5Gryphon::enter_low_flight_mode() { this->flight_mode = 2; }

void TBoss5Gryphon::enter_offscreen_mode() { this->flight_mode = 3; }

void TBoss5Gryphon::set_ground_height() { this->position.y = gryphon_ground_height; }

void TBoss5Gryphon::set_flight_height() { this->position.y = gryphon_flight_height; }

void TBoss5Gryphon::set_low_flight_height() { this->position.y = gryphon_sixty_seven; }

void TBoss5Gryphon::set_offscreen_height() { this->position.y = gryphon_offscreen_height; }

void TBoss5Gryphon::reload_stats_for_type() {
    saddr self = (saddr)this;
    ((TObjEneDD *)self)->reload_stats_keep_hp_tp(boss5_gryphon_base_params[boss5_gryphon_base_stat_indices[0]], boss5_gryphon_attack_params[boss5_gryphon_attack_stat_indices[0]], boss5_gryphon_resistance_params[boss5_gryphon_resistance_stat_indices[0]]);
}

void TBoss5Gryphon::reload_stats_for_phase(void *) {
    this->reload_stats_keep_hp_tp(boss5_gryphon_base_params[boss5_gryphon_base_stat_indices[2]], boss5_gryphon_attack_params[boss5_gryphon_attack_stat_indices[2]], boss5_gryphon_resistance_params[boss5_gryphon_resistance_stat_indices[2]]);
}

void handle_6x9F_gal_gryphon_boss_actions(void *data) {
    G_GalGryphonBossActions_6x9F *cmd = (G_GalGryphonBossActions_6x9F *)data;
    TBoss5Gryphon *boss;
    cmd->bswap();
    boss = (TBoss5Gryphon *)get_enemy_entity(cmd->header.client_id);
    if (boss != NULL) {
        boss->set_target_from_action(cmd);
    }
}

void TBoss5Gryphon::set_target_from_action(G_GalGryphonBossActions_6x9F *packet) {
    enemy_set_target_id(this, (u16)packet->target_id);
    this->destination.x = packet->x;
    this->destination.z = packet->z;
}

void handle_6xA0_gal_gryphon_boss_actions(void *data) {
    G_GalGryphonBossActions_6xA0 *cmd = (G_GalGryphonBossActions_6xA0 *)data;
    TBoss5Gryphon *boss;
    cmd->bswap();
    boss = (TBoss5Gryphon *)get_enemy_entity(cmd->header.client_id);
    if (boss != NULL) {
        boss->apply_remote_action(cmd);
    }
}

void Boss5GryphonMotionEntry::copy(Boss5GryphonMotionEntry *src) {
    state = src->state;
    timer = src->timer;
    args = src->args;
}

void TBoss5Gryphon::apply_remote_action(G_GalGryphonBossActions_6xA0 *packet) {
    VecCopy(&position_correction, &packet->pos);
    subtract_vector(&position_correction, &position);
    rotation_y = packet->angle_y;
    motions[0].copy(&packet->motion);
    motion = &motions[0];
    if ((s16)mode != motion->state) {
        transition_enemy_state(motion->state);
    }
    flags |= 2;
}

void TBoss5Gryphon::send_target_update() {
    G_GalGryphonBossActions_6x9F p;
    p.init();
    p.header.client_id = entity_id;
    p.target_id = target_id;
    p.x = destination.x;
    p.z = destination.z;
    p.send();
}

void TBoss5Gryphon::copy_spawn_params(G_GalGryphonBossActions_6xA0 *packet) {
    packet->header.client_id = entity_id;
    VecCopy(&packet->pos, &position);
    packet->angle_y = rotation_y;
    packet->send();
}

void TBoss5Gryphon::emit_part_attack_effect(int part) {
    DragonAttackParams prm = gryphon_part_attack_params;
    Vec *p;
    fill_value_array(attack_history);
    p = &bone_positions[gryphon_part_attack_index_table[part]];
    reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
    TBoss8Dragon__sub_80067074(p, &prm);
    TObjEneDD::emit_enemy_effect(this, p, &prm, attack_history);
    reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
    spawn_particle_effect_with_flags(p, effect_ids[2], 0x40);
    spawn_attack_effect(p);
}

void TBoss5Gryphon::emit_walk_foot_attacks() {
    if (is_passing_frame((f32)gryphon_twenty_one) != 0) {
        query_default();
        return;
    }
    if (is_passing_frame((f32)gryphon_five) != 0) {
        attack_default();
        return;
    }
    if (is_passing_frame(20.0f) != 0) {
        set_state_2();
        return;
    }
    if (is_passing_frame(8.0f) != 0) {
        update_state_3();
    }
}

void TBoss5Gryphon::emit_run_foot_attacks() {
    if (is_passing_frame((f32)gryphon_twelve) != 0) {
        query_default();
        return;
    }
    if (is_passing_frame(8.0f) != 0) {
        attack_default();
        return;
    }
    if (is_passing_frame((f32)gryphon_fifteen) != 0) {
        set_state_2();
        return;
    }
    if (is_passing_frame((f32)gryphon_eleven) != 0) {
        update_state_3();
    }
}

void TBoss5Gryphon::query_default() { emit_part_attack_effect(0); }

void TBoss5Gryphon::attack_default() { emit_part_attack_effect(1); }

void TBoss5Gryphon::set_state_2() { emit_part_attack_effect(2); }

void TBoss5Gryphon::update_state_3() { emit_part_attack_effect(3); }

void TBoss5Gryphon::run_default_state() { query_default(); attack_default(); }

void TBoss5Gryphon::emit_landing_impact() {
    DragonAttackParams stack;
    TBoss1Dragon__sub_80027A80(&stack, &boss5_gryphon_params_b);
    stack.radius = boss5_gryphon_behavior_params[2]->attack.landing_radius;
    reload_stats_for_phase(boss5_gryphon_behavior_params[2]);
    TBoss8Dragon__sub_80067074(&position, &stack);
    emit_effect_at_position(&stack);
    reload_stats_for_type();
}

void TBoss5Gryphon::update_collider_from_table() {
    DragonAttackParams desc = gryphon_collider_desc;
    TBoss8Dragon__sub_800670E0(&bone_positions[0], &desc);
}

void TBoss5Gryphon::emit_wing_attacks() {
    DragonAttackParams fx;
    Vec pts[10];
    Vec *p;
    s32 i;
    TBoss1Dragon__sub_80027A80(&fx, &gryphon_effect_param_block);
    fill_value_array(attack_history);
    p = pts;
    VecCopy(p++, &bone_positions[3]);
    VecCopy(p, &bone_positions[7]);
    p[1].x = 0.5f * (bone_positions[3].x + bone_positions[4].x);
    p[1].y = 0.5f * (bone_positions[3].y + bone_positions[4].y);
    p[1].z = 0.5f * (bone_positions[3].z + bone_positions[4].z);
    p[2].x = 0.5f * (bone_positions[7].x + bone_positions[8].x);
    p[2].y = 0.5f * (bone_positions[7].y + bone_positions[8].y);
    p[2].z = 0.5f * (bone_positions[7].z + bone_positions[8].z);
    p[3].x = 0.5f * (bone_positions[4].x + bone_positions[5].x);
    p[3].y = 0.5f * (bone_positions[4].y + bone_positions[5].y);
    p[3].z = 0.5f * (bone_positions[4].z + bone_positions[5].z);
    p[4].x = 0.5f * (bone_positions[8].x + bone_positions[9].x);
    p[4].y = 0.5f * (bone_positions[8].y + bone_positions[9].y);
    p[4].z = 0.5f * (bone_positions[8].z + bone_positions[9].z);
    p[5].x = 0.5f * (bone_positions[5].x + bone_positions[6].x);
    p[5].y = 0.5f * (bone_positions[5].y + bone_positions[6].y);
    p[5].z = 0.5f * (bone_positions[5].z + bone_positions[6].z);
    p[6].x = 0.5f * (bone_positions[9].x + bone_positions[10].x);
    p[6].y = 0.5f * (bone_positions[9].y + bone_positions[10].y);
    p[6].z = 0.5f * (bone_positions[9].z + bone_positions[10].z);
    p += 7;
    VecCopy(p++, &bone_positions[6]);
    VecCopy(p, &bone_positions[10]);
    reset_hp(NULL, boss5_gryphon_attack_params[3], NULL);
    p = pts;
    for (i = 0; i < 5; i++) {
        fx.radius = gryphon_effect_scale_table[i];
        TBoss8Dragon__sub_800670E0(p, &fx);
        TObjEneDD::emit_enemy_effect(this, p++, &fx, attack_history);
        TBoss8Dragon__sub_800670E0(p, &fx);
        TObjEneDD::emit_enemy_effect(this, p++, &fx, attack_history);
    }
    reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
}

void TBoss5Gryphon::emit_flight_body_attacks() {
    DragonAttackParams prm;
    Vec *point;
    TBoss1Dragon__sub_80027A80(&prm, &boss8_dragon_attack_params);
    fill_value_array(attack_history);
    reset_hp(NULL, boss5_gryphon_attack_params[3], NULL);
    point = &bone_positions[11];
    prm.radius = gryphon_thirty;
    TBoss8Dragon__sub_800670E0(point, &prm);
    TObjEneDD::emit_enemy_effect(this, point, &prm, attack_history);
    point = &bone_positions[0];
    prm.radius = gryphon_fifty;
    TBoss8Dragon__sub_800670E0(point, &prm);
    TObjEneDD::emit_enemy_effect(this, point, &prm, attack_history);
    reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::emit_run_body_attack() {
    Vec mid;
    DragonAttackParams prm = gryphon_run_body_attack_params;
    f32 bx = bone_positions[11].x;
    mid.x = 0.5f * (bone_positions[0].x - bx) + bx;
    f32 by = bone_positions[11].y;
    mid.y = 0.5f * (bone_positions[0].y - by) + by;
    f32 bz = bone_positions[11].z;
    mid.z = 0.5f * (bone_positions[0].z - bz) + bz;
    fill_value_array(attack_history);
    reset_hp(NULL, boss5_gryphon_attack_params[4], NULL);
    TObjEneDD::emit_enemy_effect(this, &mid, &prm, attack_history);
    reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
}

#pragma pop
void TBoss5Gryphon::emit_ground_contact_attack() {
    DragonAttackParams desc = gryphon_ground_contact_attack_params;
    Vec *pos;
    pos = &bone_positions[14];
    if (!(bone_positions[14].y > gryphon_fifteen)) {
        fill_value_array(attack_history);
        reset_hp(NULL, boss5_gryphon_attack_params[1], NULL);
        TObjEneDD::emit_enemy_effect(this, pos, &desc, attack_history);
        reset_hp(NULL, boss5_gryphon_attack_params[0], NULL);
    }
}

void TBoss5Gryphon::apply_shockwave_hit(TBoss5Gryphon *owner, Vec *pos) {
    DragonAttackParams desc = gryphon_shockwave_hit_params;
    desc.power = boss5_gryphon_behavior_params[2]->attack.shockwave_power;
    TBoss8Dragon__sub_80067074(pos, &desc);
    TObjEneDD::setup_instance(owner, pos, &desc, NULL);
}

void TBoss5Gryphon::apply_tornado_hit(TBoss5Gryphon *owner, Vec *pos) {
    DragonAttackParams desc = gryphon_tornado_hit_params;
    desc.power = boss5_gryphon_behavior_params[2]->attack.tornado_power;
    TObjEneDD::setup_instance(owner, pos, &desc, NULL);
}

void TBoss5Gryphon::apply_snarl_hit(TBoss5Gryphon *owner, Vec *pos, f32 inner, f32 scale) {
    DragonAttackParams desc = gryphon_snarl_hit_params;
    desc.power = boss5_gryphon_behavior_params[2]->attack.snarl_power * scale;
    desc.radius = inner;
    TObjEneDD::setup_instance(owner, pos, &desc, NULL);
}

void TBoss5Gryphon::apply_lightning_hit(TBoss5Gryphon *owner, Vec *pos, f32 inner) {
    DragonAttackParams desc = gryphon_lightning_hit_params;
    desc.power = boss5_gryphon_behavior_params[2]->attack.lightning_power;
    desc.radius = inner;
    TObjEneDD::setup_instance(owner, pos, &desc, NULL);
}
void TBoss5Gryphon::spawn_ground_splash() {
    Vec pos;
    f32 y;
    CsnHit *hit;
    VecCopy(&pos, (Vec *)((void *) (&this->position)));
    hit = csnVecterUnder(&pos, 0x16EF);
    if (hit != NULL) {
        y = hit->contact->point.y;
        if (!(y > 6.0f)) {
            pos.y = y;
            spawn_particle_effect_with_flags(&pos, effect_ids[0], 0x40);
            play_se(0x40032D01);
        }
    }
}

void TBoss5Gryphon::spawn_flight_splash() {
    if (is_passing_frame(gryphon_fourteen) != 0) {
        spawn_ground_splash();
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::spawn_lightning_effect() {
    CurvePathPoint segs[3];
    s32 a;
    s32 b;
    TBoss5GryphonLightningEff *eff;

    a = (s32)(65536.0f * (gryphon_random_unit_scale * (f32)rand()));
    b = (s32)(65536.0f * (gryphon_random_unit_scale * (f32)rand()));
    segs[0].pos.x = gryphon_seventy * sin_table_lookup(a) + this->position.x;
    segs[0].pos.y = 0.0f;
    segs[0].pos.z = gryphon_seventy * cos_table_lookup(a) + this->position.z;
    segs[0].length = 0.0f;
    segs[2].pos.x = gryphon_seventy * sin_table_lookup(b) + this->position.x;
    segs[2].pos.y = 0.0f;
    segs[2].pos.z = gryphon_seventy * cos_table_lookup(b) + this->position.z;
    segs[2].length = 0.0f;
    a = (s32)(0.5f * (f32)(a + b));
    if (gryphon_random_unit_scale * (f32)rand() > 0.5f) {
        a += 0x8000;
    }
    segs[1].pos.x = gryphon_seventy * sin_table_lookup(a) + this->position.x;
    segs[1].pos.y = gryphon_ten;
    segs[1].pos.z = gryphon_seventy * cos_table_lookup(a) + this->position.z;
    segs[1].length = 0.0f;
    eff = new TBoss5GryphonLightningEff(this, segs, 3, 0.0f, gryphon_one, 8.0f);
    eff->set_two_sided();
}

#pragma pop
void TBoss5Gryphon::spawn_attack_effect(const Vec *pos) {
    TParticleCtrl *particle;

    particle = spawn_particle_effect_with_flags(pos, 0x210, 0x40);
    if (particle != 0) {
        attach_particle_model(particle, get_bml_model(boss5_gryphon_bml_resource, 1), boss5_gryphon_texture_list, 0, 0, (f32)gryphon_one);
    }
}

void TBoss5Gryphon::spawn_switch_attack(const Vec *pos) {
    TParticleCtrl *particle;

    particle = spawn_particle_effect_with_flags(pos, 0x211, 0x40);
    if (particle != 0) {
        attach_particle_model(particle, get_bml_model(boss5_gryphon_bml_resource, 2), boss5_gryphon_texture_list, 0, 0, (f32)gryphon_one);
    }
}

void TBoss5Gryphon::dispatch_action(u32 state, s32 event) {
    TBoss5Gryphon *self = this;
    StateAction *actions = dispatch_state_actions();
    StateAction *action = actions + state;

    if (*action != NULL) {
        (self->**action)(event);
    }
}

void TBoss5Gryphon::state_action_noop() {  }

void TBoss5Gryphon::update_idle_state(u32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0;
        self->clear_intangible();
        self->enter_ground_mode();
        self->set_ground_height();
        return;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case ENEMY_STATE_LEAVE: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::update_ground_pursuit(s32 event) {
    TBoss5Gryphon *self = this;
    f32 spd;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 1;
        self->clear_intangible();
        self->enter_ground_mode();
        self->set_ground_height();
        self->flags |= 0x10;
        this->targetRefreshCounter = 0;
        return;
    case 8:
        self->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->play_walk_footsteps();
        self->update_velocity();
        self->emit_walk_foot_attacks();
        spd = self->get_motion_frame();
        if (spd < gryphon_four) {
            TObjEneEpsilon__sub_800B9384(this, 0x100, gryphon_one_point_eight);
        } else if (!(spd < gryphon_ten)) {
            if (spd < gryphon_eighteen) {
                TObjEneEpsilon__sub_800B9384(this, 0x100, gryphon_one_point_eight);
            } else if (!(spd < gryphon_twenty_five)) {
                TObjEneEpsilon__sub_800B9384(this, 0x100, gryphon_one_point_eight);
            }
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x10;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_ground_takeoff(u32 event) {
    TBoss5Gryphon *self = this;
    f32 d;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 3;
        self->clear_intangible();
        self->enter_ground_mode();
        self->set_ground_height();
        self->takeoff.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->takeoff.step) {
        case 0:
            if (self->is_passing_frame((f32)gryphon_twenty_five) != 0) {
                move_along_angle(gryphon_five, this->rotation_y);
                self->flags |= 4;
                self->run_default_state();
                enter_flight_mode();
                start_camera_shake(0x14, gryphon_point_one_five);
                self->play_se(0x40033409);
                self->takeoff.step = 1;
            }
            break;
        case 1:
            d = self->get_motion_frame() - gryphon_twenty_five;
            d = gryphon_fifty * (d * d);
            self->position.y = d * gryphon_quarter + gryphon_ground_height;
            move_along_angle(gryphon_one, this->rotation_y);
            if (self->is_passing_frame((f32)gryphon_twenty_seven) != 0) {
                self->takeoff.step = 2;
            }
            break;
        case 2:
            d = gryphon_thirty - self->get_motion_frame();
            self->position.y = gryphon_flight_height + gryphon_ground_height * -(d * d) / gryphon_nine;
            move_along_angle(gryphon_one, this->rotation_y);
            if (self->is_passing_frame((f32)gryphon_thirty) != 0) {
                self->position.y = gryphon_flight_height;
                self->takeoff.step = 3;
            }
            break;
        case 3:
            move_along_angle(gryphon_one, this->rotation_y);
            if (is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        if (self->is_passing_frame(20.0f) != 0 || self->is_passing_frame((f32)((f32)gryphon_twenty_eight)) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        enter_flight_mode();
        self->set_flight_height();
        self->flags &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

#pragma pop
void TBoss5Gryphon::update_shockwave_attack(u32 event) {
    TBoss5Gryphon *self = this;
    Vec pos;
    Vec vel;
    f32 speed;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x18;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->work.step = 0;
        self->work.timer = 0;
        self->particles[0] = NULL;
        this->targetRefreshCounter = 0;
        break;
    case 8:
        self->refresh_target_periodically();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            self->work.step = 1;
        case 1:
            if (self->is_passing_frame(8.0f) != 0) {
                self->play_se(0x40033203);
            }
            if (self->is_passing_frame(20.0f) != 0) {
                self->play_se(0x40033204);
            }
            if (self->is_passing_frame((f32)gryphon_twelve) != 0) {
                self->spawn_ground_splash();
            }
            speed = self->get_motion_frame();
            if (self->particles[0] == NULL) {
                if (speed >= 8.0f && speed <= gryphon_eighteen) {
                    self->particles[0] = spawn_continuous_particle_effect_with_flags(&self->bone_positions[11], self->effect_ids[3], 0x40);
                }
            } else if (speed <= gryphon_eighteen) {
                self->particles[0]->set_position(&self->bone_positions[11]);
            } else {
                self->particles[0]->queue_destruction();
                self->particles[0] = NULL;
            }
            if (self->is_passing_frame((f32)gryphon_twenty_and_half) != 0) {
                pos.x = self->destination.x;
                pos.y = boss5_gryphon_arena_center.y;
                pos.z = self->destination.z;
                vel.x = gryphon_one_hundred_fifty * sin_table_lookup(this->rotation_y);
                vel.y = 0.5f * -(self->bone_positions[11].y - boss5_gryphon_arena_center.y);
                vel.z = gryphon_one_hundred_fifty * cos_table_lookup(this->rotation_y);
                new TBoss5GryphonShockWave(&self->sub_tasks, self, &self->bone_positions[11], &pos, &vel,
                                           self->target_id);
                spawn_particle_effect_with_flags(&self->bone_positions[11], self->effect_ids[4], 0x40);
                self->work.step = 2;
            }
            break;
        case 2:
            if (is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (self->particles[0] != NULL) {
            self->particles[0]->queue_destruction();
            self->particles[0] = NULL;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        break;
    }
}

void TBoss5Gryphon::update_landing_attack(u32 event) {
    TBoss5Gryphon *self = this;
    Vec at;
    f32 d;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 5;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            move_along_angle(gryphon_three_quarters, this->rotation_y);
            if (self->is_passing_frame((f32)gryphon_one) != 0) {
                self->work.step = 1;
            }
            break;
        case 1:
            d = self->get_motion_frame() - gryphon_one;
            self->position.y = gryphon_flight_height + gryphon_one_hundred_fifteen * -(d * d) / gryphon_four_hundred_eighty_four;
            move_along_angle(gryphon_three_quarters, this->rotation_y);
            if (self->is_passing_frame((f32)gryphon_twenty_three) != 0) {
                self->enter_ground_mode();
                self->set_ground_height();
                self->play_se(0x40032D0D);
                at.x = self->position.x;
                at.y = 0.0f;
                at.z = self->position.z;
                spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->emit_landing_impact();
                self->work.step = 2;
            }
            break;
        case 2:
            if (is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        if (self->is_passing_frame((f32)gryphon_twenty_four) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->enter_ground_mode();
        self->set_ground_height();
        self->flags &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

#pragma push
#pragma fp_contract on
#pragma pool_data off
void TBoss5Gryphon::update_death_state(u32 event) {
    TBoss5Gryphon *self = this;
    CameraPlayback cam;
    Vec v;
    Vec tmp;
    const Vec *p;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x1A;
        self->set_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 0xC4;
        self->work.step = 0;
        self->work.timer = 0;
        self->work.fall_speed = 0.0f;
        p = get_arena_center();
        self->rotation_y = (s32)(10430.38043493439 * atan2_float(p->x - self->position.x, p->z - self->position.z));
        self->position.x = p->x - gryphon_six_hundred * sin_table_lookup(self->rotation_y);
        self->position.y = gryphon_three_hundred_sixty;
        self->position.z = p->z - gryphon_six_hundred * cos_table_lookup(self->rotation_y);
        play_cue_stream_file("dradeath.adx");
        TWindowCtrl::init_all_slots();
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            cam.index = 0;
            cam.bank = 2;
            cam.flags = 0;
            cam.frame = 0.0f;
            cam.frame_step = 0.5f;
            activate_camera_mode(5);
            cam.play(0x31C7);
            set_scripted_camera_origin(&self->position, &self->position, (CameraAngles *)&this->rotation_x);
            break;
        }
        return;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
        if (self->is_passing_frame((f32)gryphon_one_hundred_ten) != 0) {
            v.x = self->position.x;
            v.y = gryphon_negative_thirty;
            v.z = self->position.z;
            spawn_particle_effect_with_flags(&v, 0x201, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            play_sound_effect(0x4003230C, 0, 0, 0);
        }
        }
        switch (self->work.step) {
        case 0:
            if (self->get_flag_b4() != 0) {
                self->work.step = 1;
                self->work.timer = 0;
            }
            break;
        case 1:
            self->work.timer++;
            if (self->work.timer >= 50) {
                self->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x84;
        VecCopy(&tmp, &self->position);
        VecCopy(&self->position, &boss5_gryphon_death_position);
        self->update_prev_position();
        self->refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x52);
        VecCopy(&self->position, &tmp);
        self->update_prev_position();
        self->actorFlags = 0x12008;
        self->sync_enemy_state(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

#pragma pop
#pragma push
#pragma pool_data off
void TBoss5Gryphon::update_demo_state(u32 event) {
    s32 *demo_flag = &this->work.demo_flag;
    Vec pos;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0;
        enter_flight_mode();
        this->set_flight_height();
        advance_animation();
        this->position.x = 0.0f;
        this->position.y = 0.0f;
        this->position.z = 0.0f;
        this->rotation_x = 0;
        this->rotation_y = 0;
        this->rotation_z = 0;
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            this->work.step = 0;
            break;
        }
        this->flags |= 0x80;
        this->work.substep = 0;
        this->work.timer = 0;
        *demo_flag = 1;
        new TBoss5GryphonDemo(tl_01, demo_flag, gryphon_one);
        this->requested_action = 0x19;
        TWindowCtrl::init_all_slots();
        this->get_target_state_b();
        return;
    case 2:
    case 9:
        if (this->work.step == 1) {
            init_state_zero();
        }
        break;
    case ENEMY_STATE_UPDATE:
        switch (this->work.step) {
        case 0:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                this->work.step = 1;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 4;
            }
            switch (this->work.substep) {
            case 0:
                if (is_passing_frame((f32)gryphon_sixty_eight) != 0) {
                    VecCopy(&pos, boss5_gryphon_waypoint_vecs);
                    spawn_particle_effect_with_flags(&pos, this->effect_ids[1], 0x40);
                    start_pad_rumble_all(0x1C, 0x3C);
                } else if (is_passing_frame((f32)gryphon_two_hundred_ten) != 0) {
                    VecCopy(&pos, &boss5_gryphon_waypoint_vecs[1]);
                    spawn_particle_effect_with_flags(&pos, this->effect_ids[1], 0x40);
                    start_pad_rumble_all(0xC0, 0xF);
                } else if ((is_passing_frame((f32)gryphon_four_hundred_twenty) != 0) || (is_passing_frame((f32)gryphon_four_hundred_sixty_three) != 0)) {
                    VecCopy(&pos, &boss5_gryphon_waypoint_vecs[1]);
                    spawn_particle_effect_with_flags(&pos, this->effect_ids[0], 0x40);
                }
                if (is_passing_frame((f32)gryphon_two_hundred_ninety) != 0) {
                    play_sound_effect(0x40032A00, NULL, 0, 0);
                    start_pad_rumble_all(0xA0, 0x3C);
                }
                if ((is_passing_frame(100.0f) != 0) || (is_passing_frame((f32)gryphon_four_hundred_five) != 0)) {
                    play_sound_effect(0x40033409, NULL, 0, 0);
                }
                if (is_passing_frame((f32)gryphon_two_hundred_ten) != 0) {
                    play_sound_effect(0x40032D0D, NULL, 0, 0);
                }
                if (is_passing_frame((f32)gryphon_four_hundred_fifty_five) != 0) {
                    play_sound_effect(0x40033409, NULL, 0, 0);
                    start_pad_rumble_all(0x80, 7);
                }
                if (is_passing_frame((f32)gryphon_two_hundred_sixty_five) != 0) {
                    TObjBoss5Ctrl::play_pillar_sound();
                }
                break;
            }
            break;
        case 1:
            VecCopy(&this->position, &boss5_gryphon_demo_position);
            copy_xyz((u8 *)this + 0x5C, (void *)boss5_gryphon_demo_rotation);
            advance_animation();
            return;
        }
        break;
    case ENEMY_STATE_LEAVE:
        VecCopy(&this->position, &boss5_gryphon_demo_position);
        copy_xyz((u8 *)this + 0x5C, (void *)boss5_gryphon_demo_rotation);
        this->position_correction.x = 0.0f;
        this->position_correction.y = 0.0f;
        this->position_correction.z = 0.0f;
        *demo_flag = 0;
        this->flags = (s32) (this->flags & 0xFFFFFF7F);
        TWindowCtrl::init_all_slots2();
        this->get_target_state_a();
        break;
    }
}

#pragma pop
void TBoss5Gryphon::wait_for_players(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0;
        self->work.step = 0;
        return;
    case 3:
        if (self->work.step > 0x96) {
            self->transition_enemy_state(0xB);
        }
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    case ENEMY_STATE_UPDATE:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            self->work.step = (s32) (self->work.step + 1);
        }
        break;
    }
}

void TBoss5Gryphon::update_turning_flight(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 4;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->spawn_flight_splash();
        move_along_angle(self->motion->args.flight.speed, self->rotation_y);
        self->turn_velocity += self->motion->args.flight.turn;
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::circle_arena(s32 event) {
    s32 ofs;
    s32 ang;
    s32 a;
    Boss5GryphonMotionEntry *t;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 4;
        this->clear_intangible();
        enter_flight_mode();
        this->set_flight_height();
        this->targetRefreshCounter = 0;
        return;
    case 8:
        this->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        spawn_flight_splash();
        ofs = 0x4000;
        if (this->position.x * this->position.x + this->position.z * this->position.z > this->motion->args.circle.radius * this->motion->args.circle.radius) {
            ofs = 0x5000;
        }
        a = (s32)(10430.38043493439 * atan2_float(this->position.x, this->position.z));
        t = this->motion;
        ang = a - ofs;
        if (t->args.circle.direction > 0) {
            ang = a + ofs;
        }
        move_along_angle(t->args.circle.speed, ang);
        this->update_heading(this->motion->args.circle.turn_rate);
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case ENEMY_STATE_LEAVE: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::move_to_motion_destination(s32 event) {
    TBoss5Gryphon *self = this;
    f32 dx;
    f32 dz;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 4;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->work.target_angle = initial_angle_800623E4(self);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->spawn_flight_splash();
        dx = self->motion->args.move.x - self->position.x;
        dz = self->motion->args.move.z - self->position.z;
        turn_toward_angle_limited(self->motion->args.move.turn_rate, self->work.target_angle);
        move_along_angle(self->motion->args.move.speed, (s32)(10430.38043493439 * atan2_float(dx, dz)));
        if (dx * dx + dz * dz < gryphon_ten) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_glide_in(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 6;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            speed = gryphon_quarter;
            self->position.y = gryphon_one_hundred_twenty * sin_table_lookup((s32)(gryphon_quarter_turn * self->get_motion_frame() / gryphon_eighteen)) + gryphon_flight_height;
            if (((TObjMotion *)self)->is_passing_frame(gryphon_eighteen) != 0) {
                self->work.step = 1;
                self->work.timer = 0;
            }
            break;
        case 1:
            t = self->work.timer;
            speed = gryphon_two_point_one;
            if ((f32)t < *(const f32 *)&gryphon_fifteen) {
                f = (f32)t;
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_fifteen));
                d = gryphon_one_hundred_sixteen_and_half * d + gryphon_one_hundred_sixteen_and_half;
                self->position.y = gryphon_sixty_seven + d;
            } else {
                f = (f32)(0x1E - t);
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_fifteen));
                d = -gryphon_one_hundred_sixteen_and_half * d + gryphon_one_hundred_sixteen_and_half;
                self->position.y = gryphon_sixty_seven + d;
            }
            self->rotation_x = (s32)(gryphon_three_32nds_turn * f / gryphon_fifteen);
            self->work.timer++;
            if (self->work.timer > 0x1E) {
                ((TBoss5Gryphon *)self)->enter_low_flight_mode();
                ((TBoss5Gryphon *)self)->set_low_flight_height();
                self->rotation_x = 0;
                self->work.step = 2;
            }
            break;
        case 2:
            speed = gryphon_two_point_one;
            if (self->action_flags == 7) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(gryphon_ten) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~4;
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop
void TBoss5Gryphon::update_low_flight_straight(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        if (self->flags & 0x100) {
            self->requested_action = 0x14;
        } else {
            self->requested_action = 7;
        }
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->work.timer = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        move_along_angle(gryphon_three_and_half, self->rotation_y);
        if (self->flags & 0x100) {
            self->emit_flight_body_attacks();
            self->update_low_flight_particles();
        } else {
            self->emit_wing_attacks();
            self->update_ground_effects();
            self->spawn_ancient_trap(0x40032802);
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_low_flight_circle(s32 event) {
    s32 ofs;
    s32 a;
    s32 d;
    s32 v;
    f32 speed;

    switch (event) {
    case ENEMY_STATE_ENTER:
        if (this->flags & 0x100) {
            this->requested_action = 0x14;
        } else {
            this->requested_action = 7;
        }
        this->clear_intangible();
        this->enter_low_flight_mode();
        this->set_low_flight_height();
        break;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        ofs = 0x4000;
        if (this->position.x * this->position.x + this->position.z * this->position.z > this->motion->args.flight.radius_sq) {
            ofs = 0x5000;
        }
        speed = this->motion->args.flight.speed;
        a = (s32)(10430.38043493439 * atan2_float(this->position.x, this->position.z));
        if (this->motion->args.flight.turn > 0) {
            a += ofs;
            d = angle_diff_s16(this->rotation_y, a);
            if (d > 0) {
                this->turn_velocity += this->motion->args.flight.turn;
            }
        } else {
            a -= ofs;
            d = angle_diff_s16(this->rotation_y, a);
            if (d < 0) {
                this->turn_velocity += this->motion->args.flight.turn;
            }
        }
        if (fabs_float((f32)d) > gryphon_three_32nds_turn) {
            speed *= gryphon_point_eight;
        }
        move_along_angle(speed, this->rotation_y);
        if ((f32)this->motion->timer > 6.0f) {
            v = (s32)(gryphon_negative_four * (f32)this->turn_velocity);
            v = (v < -0x600) ? -0x600 : ((v < 0x600) ? v : 0x600);
            d = angle_diff_s16(this->rotation_z, v);
            this->rotation_z = (s32)(gryphon_point_two * (f32)d + (f32)this->rotation_z);
        } else {
            this->rotation_z -= this->rotation_z / this->motion->timer;
        }
        if (this->flags & 0x100) {
            emit_flight_body_attacks();
            update_low_flight_particles();
        } else {
            emit_wing_attacks();
            this->update_ground_effects();
            spawn_ancient_trap(0x40032802);
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->rotation_z = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop
void TBoss5Gryphon::update_bezier_descent(s32 event) {
    TBoss5Gryphon *self = this;
    Vec out;
    Vec at;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 9;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->enable_particles();
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            move_along_angle(gryphon_one_and_half, self->rotation_y);
            TBoss8Dragon::eval_bezier_curve(boss5_gryphon_landing_bezier_points, 4, 0, &out, self->get_motion_frame() / 20.0f);
            self->position.y = out.y;
            if (((TObjMotion *)self)->is_passing_frame(20.0f) != 0) {
                ((TBoss5Gryphon *)self)->enter_ground_mode();
                ((TBoss5Gryphon *)self)->set_ground_height();
                self->play_se(0x40032D0D);
                at.x = self->position.x;
                at.y = 0.0f;
                at.z = self->position.z;
                spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->emit_landing_impact();
                self->work.step = 1;
            }
            break;
        case 1:
            if (self->is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~4;
        self->destroy_parts();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_dive_motion(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case 10:
    case 11:
        break;
    case ENEMY_STATE_ENTER:
        this->requested_action = 7;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->enable_particles();
        self->work.step = 0;
        self->work.timer = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            t = self->work.timer;
            speed = gryphon_two_point_three;
            if ((f32)t < *(const f32 *)&gryphon_nineteen_and_half) {
                f = (f32)t;
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_nineteen_and_half));
                d = -gryphon_one_hundred_sixteen_and_half * d + gryphon_one_hundred_sixteen_and_half;
                self->position.y = gryphon_sixty_seven + d;
            } else {
                f = (f32)(0x27 - t);
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_nineteen_and_half));
                d = gryphon_one_hundred_sixteen_and_half * d + gryphon_one_hundred_sixteen_and_half;
                self->position.y = gryphon_sixty_seven + d;
            }
            this->rotation_x = (s32)(-(gryphon_five_64ths_turn * f) / gryphon_nineteen_and_half);
            self->work.timer++;
            if (self->work.timer == 0x11) {
                this->requested_action = 8;
            } else if (self->work.timer > 0x27) {
                self->position.y = gryphon_three_hundred;
                this->rotation_x = 0;
                self->work.step = 1;
            }
            break;
        case 1:
            speed = gryphon_quarter;
            f = this->frame_count - gryphon_ten;
            d = self->get_motion_frame() - gryphon_ten;
            self->position.y = gryphon_three_hundred - gryphon_one_hundred_twenty * sin_table_lookup((s32)(gryphon_quarter_turn * d / f));
            if (self->is_passing_frame((f32)gryphon_seventeen) != 0) {
                self->spawn_ground_splash();
            }
            if (is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, this->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~4;
        self->destroy_parts();
        this->rotation_x = 0;
        break;
    }
}

void TBoss5Gryphon::update_spiral_in(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x13;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 0x104;
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            speed = gryphon_quarter;
            self->position.y = 20.0f * sin_table_lookup((s32)(gryphon_quarter_turn * self->get_motion_frame() / gryphon_nine)) + gryphon_flight_height;
            if (((TObjMotion *)self)->is_passing_frame(gryphon_nine) != 0) {
                self->work.step = 1;
                self->work.timer = 0;
            }
            break;
        case 1:
            t = self->work.timer;
            speed = gryphon_two_point_one;
            if ((f32)t < *(const f32 *)&gryphon_ten) {
                f = (f32)t;
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_ten));
                d = gryphon_sixty_six_and_half * d + gryphon_sixty_six_and_half;
                self->position.y = gryphon_sixty_seven + d;
            } else {
                f = (f32)(0x14 - t);
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_ten));
                d = -gryphon_sixty_six_and_half * d + gryphon_sixty_six_and_half;
                self->position.y = gryphon_sixty_seven + d;
            }
            self->rotation_x = (s32)(gryphon_three_32nds_turn * f / gryphon_ten);
            self->work.timer++;
            if (self->work.timer > 0x14) {
                ((TBoss5Gryphon *)self)->enter_low_flight_mode();
                ((TBoss5Gryphon *)self)->set_low_flight_height();
                self->rotation_x = 0;
                self->work.step = 2;
            }
            break;
        case 2:
            speed = gryphon_two_point_one;
            if (self->action_flags == 0x14) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(gryphon_five) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~4;
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop
void TBoss5Gryphon::handle_descend_state(s32 event) {
    TBoss5Gryphon *self = this;
    Vec out;
    Vec at;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x16;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->update_particle_positions();
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            move_along_angle(gryphon_one_and_half, self->rotation_y);
            TBoss8Dragon::eval_bezier_curve(boss5_gryphon_descend_bezier_points, 4, 0, &out, self->get_motion_frame() / gryphon_seventeen);
            self->position.y = out.y;
            if (self->is_passing_frame((f32)gryphon_seventeen) != 0) {
                self->enter_ground_mode();
                self->set_ground_height();
                self->play_se(0x40032D0D);
                at.x = self->position.x;
                at.y = 0.0f;
                at.z = self->position.z;
                spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->emit_landing_impact();
                self->work.step = 1;
            }
            break;
        case 1:
            if (self->is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        if (self->is_passing_frame((f32)gryphon_four) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x104;
        self->free_parts();
        break;
    case 10: case 11:
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::handle_takeoff_state(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x14;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->update_particle_positions();
        self->work.step = 0;
        self->work.timer = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0:
            t = self->work.timer;
            speed = gryphon_two_point_three;
            if ((f32)t < *(const f32 *)&gryphon_nineteen_and_half) {
                f = (f32)t;
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_nineteen_and_half));
                d = -gryphon_eighty_one_and_half * d + gryphon_eighty_one_and_half;
                self->position.y = gryphon_sixty_seven + d;
            } else {
                f = (f32)(0x27 - t);
                d = cos_table_lookup((s32)(gryphon_quarter_turn * f / gryphon_nineteen_and_half));
                d = gryphon_eighty_one_and_half * d + gryphon_eighty_one_and_half;
                self->position.y = gryphon_sixty_seven + d;
            }
            self->rotation_x = (s32)(-(gryphon_five_64ths_turn * f) / gryphon_nineteen_and_half);
            self->work.timer++;
            if (self->work.timer == 0xB) {
                self->requested_action = 0x15;
            } else if (self->work.timer > 0x27) {
                self->position.y = gryphon_two_hundred_thirty;
                self->rotation_x = 0;
                self->work.step = 1;
            }
            if (((TObjMotion *)self)->is_passing_frame(gryphon_seven) != 0) {
                self->spawn_ground_splash();
            }
            break;
        case 1: {
            f32 phase_speed;
            f32 base;
            speed = gryphon_quarter;
            phase_speed = self->get_motion_frame();
            base = gryphon_eleven;
            phase_speed -= base;
            d = self->frame_count - base;
            self->position.y = gryphon_two_hundred_thirty - gryphon_fifty *
                sin_table_lookup((s32)(gryphon_quarter_turn * phase_speed / d));
            if (self->is_motion_finished() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        }
        move_along_angle(speed, self->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x104;
        self->free_parts();
        self->position.y = gryphon_flight_height;
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop
void TBoss5Gryphon::update_run_in(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xA;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (self->action_flags == 0xB) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::state_move(s32 event) {
    f32 speed;
    f32 scale;
    f32 depth;
    f32 v;
    s32 ang;
    switch (event) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0xB;
        this->clear_intangible();
        this->enter_ground_mode();
        this->set_ground_height();
        this->flags |= 0x30;
        return;
    case 8:
        this->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        play_run_footsteps();
        this->update_velocity();
        emit_run_body_attack();
        emit_run_foot_attacks();
        v = this->get_motion_frame();
        if (v < gryphon_ten || v >= gryphon_seventeen) {
            depth = gryphon_three_quarters;
            ang = 0;
            speed = 0.0f;
            scale = gryphon_point_nine;
        } else {
            depth = gryphon_three_quarters;
            ang = 0xD0;
            speed = gryphon_one;
            scale = gryphon_point_eight_six;
        }
        if (is_passing_frame(0.5f) != 0) {
            ang += 0x500;
            speed += gryphon_nine;
        }
        this->scale_size(scale, depth, depth);
        move_along_angle(speed, this->rotation_y);
        this->update_heading(ang);
        return;
    case ENEMY_STATE_LEAVE:
        this->flags &= ~0x30;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::update_run_out(s32 event) {
    TBoss5Gryphon *self = this;
    Vec at;
    f32 v;
    f32 speed;
    f32 scale;
    f32 depth;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xC;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->flags |= 0x30;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        v = self->get_motion_frame();
        speed = 0.0f;
        if (v < gryphon_fifteen) {
            depth = gryphon_three_quarters;
            scale = gryphon_point_nine;
        } else {
            depth = gryphon_three_quarters;
            scale = gryphon_point_eight_six;
        }
        if (((TObjMotion *)self)->is_passing_frame(gryphon_three) != 0) {
            speed += gryphon_eleven;
        }
        self->scale_size(scale, depth, depth);
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(gryphon_fifteen) != 0) {
            at.x = self->position.x;
            at.y = 0.0f;
            at.z = self->position.z;
            spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
            self->emit_landing_impact();
            self->play_se(0x40032D0D);
        }
        if (self->is_motion_finished() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x30;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_crouch_in(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xD;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->emit_ground_contact_attack();
        if (((TObjMotion *)self)->is_passing_frame(gryphon_seven) != 0) {
            self->collider->enable_blocking_bodies(&self->position, self->rotation_y);
        }
        if (((TObjMotion *)self)->is_passing_frame(gryphon_one) != 0) {
            self->play_se(0x40032D0E);
        }
        if (self->action_flags == 0xE) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->collider->disable_blocking_bodies();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_crouch(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xE;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->collider->enable_blocking_bodies(&self->position, self->rotation_y);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->emit_ground_contact_attack();
        break;
    case ENEMY_STATE_LEAVE:
        self->collider->disable_blocking_bodies();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_crouch_out(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xF;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->collider->enable_blocking_bodies(&self->position, self->rotation_y);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->emit_ground_contact_attack();
        if (((TObjMotion *)self)->is_passing_frame(gryphon_five) != 0) {
            self->collider->disable_blocking_bodies();
        }
        if (self->is_motion_finished() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->collider->disable_blocking_bodies();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_horn_in(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x10;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(gryphon_nineteen) != 0) {
            self->play_se(0x4003320F);
        }
        if (self->action_flags == 0x11) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_ground_lightning_attack(s32 event) {
    TBoss5Gryphon *self = this;
    Vec left;
    Vec right;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x11;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->collider->enable_blocking_bodies(&self->position, self->rotation_y);
        self->lightning.frame = 0;
        push_matrix();
        set_matrix_identity(NULL);
        post_translate_matrix(&self->position.x);
        rotate_matrix_y(0, self->rotation_y);
        matrix_mult_vec(NULL, &gryphon_left_horn_lightning_offset, &left);
        matrix_mult_vec(NULL, &gryphon_right_horn_lightning_offset, &right);
        pop_matrix();
        self->lightning.horns[0] = TBoss5GryphonLightningHorn::spawn_ground_lightning(self, &left, self->rotation_y);
        self->lightning.horns[1] = TBoss5GryphonLightningHorn::spawn_ground_lightning(self, &right, self->rotation_y);
        subtractive_rng_seed(self->rng, self->motion->args.seed);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->emit_ground_contact_attack();
        if (boss5_gryphon_behavior_params[2]->attack.action_level >= 2) {
            self->spawn_lightning_effect();
            apply_lightning_hit(self, &self->position, gryphon_sixty);
        }
        if (boss5_gryphon_behavior_params[2]->attack.action_level >= 4 && self->lightning.frame % 20 == 0) {
            self->fire_horn_lightning((self->lightning.frame / 20) & 1 ? 0 : 1, gryphon_four * calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(self->rng)));
        }
        self->spawn_ancient_trap(0x40032D11);
        self->lightning.frame++;
        break;
    case ENEMY_STATE_LEAVE:
        if (self->lightning.horns[1] != NULL) {
            self->lightning.horns[1]->queue_destruction();
            self->lightning.horns[1] = NULL;
        }
        if (self->lightning.horns[0] != NULL) {
            self->lightning.horns[0]->queue_destruction();
            self->lightning.horns[0] = NULL;
        }
        self->collider->disable_blocking_bodies();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_horn_out(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x12;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(6.0f) != 0) {
            self->play_se(0x40032D10);
        }
        if (self->is_motion_finished() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_offscreen_climb(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x13;
        self->clear_intangible();
        enter_flight_mode();
        self->set_flight_height();
        self->flags |= 4;
        self->work.timer = 0;
        self->work.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->work.step) {
        case 0: {
            f32 t;
            speed = gryphon_point_two_eight;
            t = self->get_motion_frame();
            self->position.y = gryphon_flight_height + gryphon_sixty * (t * t) / gryphon_twenty_five;
            if (((TObjMotion *)self)->is_passing_frame(gryphon_five) != 0) {
                self->work.timer = 0;
                self->work.step = 1;
            }
            break;
        }
        case 1:
            self->position.y += gryphon_forty;
            speed = gryphon_point_two_eight;
            self->work.timer++;
            if (self->work.timer >= 0x28) {
                ((TBoss5Gryphon *)self)->enter_offscreen_mode();
                ((TBoss5Gryphon *)self)->set_offscreen_height();
                self->rotation_x = 0x4000;
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~4;
        ((TBoss5Gryphon *)self)->enter_offscreen_mode();
        ((TBoss5Gryphon *)self)->set_offscreen_height();
        self->rotation_x = 0x4000;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_offscreen_dive(u32 event) {
    TBoss5Gryphon *self = this;
    Vec w;
    Vec v;
    Vec p;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x14;
        self->clear_intangible();
        self->enter_offscreen_mode();
        self->set_offscreen_height();
        self->flags |= 4;
        self->play_se(0x4003A818);
        subtractive_rng_seed(self->rng, self->motion->args.seed);
        self->rotation_x = 0x4000;
        self->dive.frame = 0;
        self->dive.frame_limit = (f32)self->motion->timer - TWindowSubStatusDisp::round_away_from_zero(gryphon_seventy_five);
        self->dive.fall_speed = gryphon_offscreen_drop / ((f32)self->motion->timer - TWindowSubStatusDisp::round_away_from_zero(gryphon_thirty_two_and_half));
        self->dive.step = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->dive.step) {
        case 0: {
            TObjPlayer *pl;
            s32 a2;
            s32 ang;
            s32 found;
            f32 r;
            f32 xx = self->position.x * self->position.x;
            f32 zz = self->position.z * self->position.z;
            if (xx + zz > gryphon_arena_radius_sq) {
                self->fire_at_angle(0x100);
            } else {
                self->update_heading(0x100);
            }
            self->update_facing(gryphon_three);
            self->position.y -= self->dive.fall_speed;
            self->rotation_z += 0x3311;
            if (self->dive.frame >= self->dive.frame_limit) {
                self->requested_action = 0x16;
                self->disable_motion_blend();
                self->dive.step = 1;
            }
            found = 0;
            ang = 65536.0f * calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(self->rng));
            r = calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(self->rng));
            if (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(self->rng)) > 0.5f) {
                pl = get_player_by_client_id((u16)((s32)(gryphon_four * calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(self->rng)))));
                if (pl->is_alive() != 0) {
                    CsnHit *hit;
                    r *= gryphon_fifty;
                    do {
                        v.x = r * sin_table_lookup(ang) + pl->position.x;
                        v.y = gryphon_fifty + pl->position.y;
                        v.z = r * cos_table_lookup(ang) + pl->position.z;
                        hit = csnVecterUnder(&v, 0x16EF);
                        ang += 0x2000;
                    } while (hit == NULL || hit->contact->point.y > 6.0f);
                    found = 1;
                }
            }
            if (found == 0) {
                CsnHit *hit;
                r *= gryphon_three_hundred_sixty;
                do {
                    v.x = r * sin_table_lookup(ang);
                    v.y = 0.0f;
                    v.z = r * cos_table_lookup(ang);
                    hit = csnVecterUnder(&v, 0x16EF);
                    r -= gryphon_four;
                } while (hit == NULL || hit->contact->point.y > 6.0f);
            }
            {
                a2 = 10430.38043493439 * atan2_float(v.x - self->position.x, v.z - self->position.z);
                w.x = gryphon_fifty * sin_table_lookup(a2) + self->position.x;
                w.y = gryphon_fifty + self->position.y;
                w.z = gryphon_fifty * cos_table_lookup(a2) + self->position.z;
            }
            if (self->dive.frame % 5 == 0) {
                TBoss5GryphonLightningWing::spawn_corner(self, &w, &v, 0x28, 0x11);
            }
            if (self->dive.frame == 0x14) {
                self->play_se(0x40033C12);
            }
            self->dive.frame++;
            break;
        }
        case 1: {
            f32 s;
            self->move_along_angle(gryphon_one, self->rotation_y);
            self->position.y -= self->dive.fall_speed;
            s = self->get_motion_frame();
            self->rotation_x = 65536.0f - gryphon_three_quarter_turn * (gryphon_one - s / gryphon_seven);
            self->rotation_z = gryphon_dive_roll_scale * (gryphon_seven - s) * (gryphon_seven - s);
            if (self->is_passing_frame((f32)gryphon_seven) != 0) {
                self->rotation_x = 0;
                self->rotation_z = 0;
                self->dive.step = 2;
            }
            break;
        }
        case 2:
            self->move_along_angle(gryphon_one, self->rotation_y);
            self->position.y -= self->dive.fall_speed;
            if (self->is_passing_frame((f32)gryphon_seventeen) != 0) {
                self->enter_ground_mode();
                self->set_ground_height();
                self->play_se(0x40032D0D);
                p.x = self->position.x;
                p.y = 0.0f;
                p.z = self->position.z;
                spawn_particle_effect_with_flags(&p, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->emit_landing_impact();
                self->dive.step = 3;
            }
            break;
        case 3:
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->enter_ground_mode();
        self->set_ground_height();
        self->rotation_x = 0;
        self->rotation_z = 0;
        self->flags &= ~4;
        break;
    case 8:
        switch (self->dive.step) {
        case 0:
        case 1:
            self->refresh_target_periodically();
            break;
        case 2:
        case 3:
            break;
        }
        break;
    case 11:
        break;
    }
}

void TBoss5Gryphon::update_roar_state(s32 event) {
    TBoss5Gryphon *self = this;
    Vec pos;
    Vec *bones;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 2;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(gryphon_roar_frame) != 0) {
            bones = self->bone_positions;
            pos.x = 0.5f * (bones[1].x + bones[2].x);
            pos.y = 0.5f * (bones[1].y + bones[2].y);
            pos.z = 0.5f * (bones[1].z + bones[2].z);
            new TBoss5GryphonSnarl(&self->sub_tasks, &pos);
            TCameraCtrl::set_shake_preset(1);
            self->play_se(0x40032306);
        }
        if (self->is_motion_finished() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop
void TBoss5Gryphon::update_howl_state(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x17;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->flags &= ~4;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(gryphon_twelve) != 0) {
            self->play_se(0x4003A817);
        }
        if (self->is_motion_finished() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_mode_idle(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        switch (self->flight_mode) {
        case 0:
            self->requested_action = 0;
            break;
        case 1:
            self->requested_action = 4;
            break;
        case 2:
            self->requested_action = 7;
            break;
        }
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->flight_mode) {
        case 0:
            break;
        case 1:
            self->spawn_flight_splash();
            break;
        case 2:
            move_along_angle(gryphon_three, self->rotation_y);
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::handle_message(s32 msg) {
    TBoss5Gryphon *self = this;
    switch (msg) {
    case 4:
        self->flags |= 0x80;
        self->queue_destruction();
        break;
    case 5:
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        return;
    }
}

#pragma push
#pragma pool_data off
void TBoss5Gryphon::apply_velocity() {
    Vec shot;
    Vec v;
    f32 len;
    if (this->flags & 0x10) {
        this->position.y += this->move_velocity.y;
        this->rotation_y += this->turn_velocity;
        v.x = this->move_velocity.x;
        v.y = 0.0f;
        v.z = this->move_velocity.z;
        len = normalize_vector_xz(&v);
        this->calc_shot_position(&shot, v.x, v.z, len);
        this->try_move_actor_xz_on_ground(&shot);
    } else {
        this->position.x += this->move_velocity.x;
        this->position.y += this->move_velocity.y;
        this->position.z += this->move_velocity.z;
        this->rotation_y += this->turn_velocity;
    }
    if (!(this->flags & 0x20)) {
        this->scale_size(boss5_gryphon_scale_x_table[this->flight_mode], boss5_gryphon_scale_y_table[this->flight_mode], gryphon_velocity_scale_z_table[this->flight_mode]);
    }
}

#pragma pop
void TBoss5Gryphon::apply_position_correction() {
    position.x = position.x + position_correction.x;
    position.z = position.z + position_correction.z;
    position_correction.x = 0.0f;
    position_correction.y = 0.0f;
    position_correction.z = 0.0f;
}

void TBoss5Gryphon::advance_motion_timer() {
    int timer;
    Boss5GryphonMotionEntry *entry;

    if ((s16) this->mode != 4) {
        entry = this->motion;
        timer = entry->timer;
        if (timer > 0) {
            entry->timer = timer - 1;
            if (this->motion->timer == 0) {
                advance_motion_entry();
            }
        }
    }
}

void TBoss5Gryphon::advance_motion_entry() {
    this->motion++;
    if ((s16) this->mode != this->motion->state) {
        transition_enemy_state(this->motion->state);
    }
}

s32 TBoss5Gryphon::is_motion_finished() {
    return play_speed <= 0.0f;
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::move_along_angle(f32 speed, s32 ang) {
    move_velocity.x = (speed * sin_table_lookup(ang)) + move_velocity.x;
    move_velocity.z = (speed * cos_table_lookup(ang)) + move_velocity.z;
}

#pragma pop
void TBoss5Gryphon::update_facing(f32 speed) {
    update_velocity();
    move_along_angle(speed, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)));
}

void TBoss5Gryphon::turn_toward_angle_limited(s32 ang, s32 target) {
    s32 t;
    s32 v;

    t = angle_diff_s16(rotation_y, target);
    t = angle_diff_s16((s32)((f32)t * gryphon_point_six), turn_velocity);
    v = (t < -ang) ? -ang : ((t < ang) ? t : ang);
    turn_velocity = turn_velocity - v;
}

void TBoss5Gryphon::update_heading(s32 ang) {
    this->update_velocity();
    turn_toward_angle_limited(ang, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)));
}

void TBoss5Gryphon::fire_at_angle(s32 ang) {
    turn_toward_angle_limited(ang, (s32)(10430.38043493439 * atan2_float(-position.x, -position.z)));
}

void TBoss5Gryphon::scale_size(f32 scale, f32 scale_y, f32 turn_scale) {
    this->move_velocity.x = this->move_velocity.x * scale;
    this->move_velocity.y = this->move_velocity.y * scale_y;
    this->move_velocity.z = this->move_velocity.z * scale;
    this->turn_velocity = (s32)((f32)this->turn_velocity * turn_scale);
}

void TBoss5Gryphon::refresh_target_periodically() {
    TBoss5Gryphon::update_linked_ground_position();
    if (!(this->targetRefreshCounter & 0x1F)) {
        if (enemy_validate_retained_target(this) != 0) {
            enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss5_gryphon_arena_center);
        }
        send_target_update();
    }
    this->targetRefreshCounter = (this->targetRefreshCounter + 1);
}

void TBoss5Gryphon::flush_pending_effect() {
    G_GalGryphonBossActions_6xA0 p;
    if ((this->flags & 2) && this->motion >= &this->motions[1]) {
        p.init();
        init_packet_motion(&p);
        fill_action_steps(&p);
        this->flags &= ~2;
        copy_spawn_params(&p);
    }
}

void TBoss5Gryphon::init_packet_motion(G_GalGryphonBossActions_6xA0 *packet) {
    packet->motion.init();
}

void TBoss5Gryphon::fill_action_steps(G_GalGryphonBossActions_6xA0 *packet) {
    s32 i;
    Boss5GryphonMotionEntry *out;

    if (script_entry == NULL) {
        update_target_from_state();
    }
    out = &packet->motion;
    for (i = 0; i < 1;) {
        Boss5GryphonActionStep *step = script_entry;
        if (step->command == 0x21) {
            choose_next_action(step);
            continue;
        }
        if (run_action_script_step(out, step) != 0) {
            break;
        }
        i++;
        out++;
        script_entry++;
    }
}

void TBoss5Gryphon::init_state_zero() {
    play_animation_index(0);
}

void TBoss5Gryphon::set_animation_by_state() {
    flags |= 8;
    switch (flight_mode) {
    default:
    case 0:
        play_animation_index(0x19);
        return;
    case 1:
        play_animation_index(0x1A);
        return;
    case 3:
        play_animation_index(0x1B);
        return;
    case 2:
        play_animation_index(0x1C);
        return;
    }
}

void TBoss5Gryphon::play_animation_index(s32 index) {
    G_GalGryphonBossActions_6xA0 packet;
    packet.init();
    script_entry = action_scripts[index];
    init_packet_motion(&packet);
    fill_action_steps(&packet);
    copy_spawn_params(&packet);
}

void TBoss5Gryphon::update_target_from_state() {
    s32 flight_mode;

    flight_mode = this->flight_mode;
    switch (flight_mode) {
    default:
    case 0:
        this->script_entry = this->action_scripts[16];
        return;
    case 1:
        this->script_entry = this->action_scripts[2];
        return;
    case 3:
        this->script_entry = this->action_scripts[24];
        return;
    case 2:
        this->script_entry = this->action_scripts[23];
        return;
    }
}

void TBoss5Gryphon::choose_next_action(Boss5GryphonActionStep *step) {
    f32 r;
    if (step->command != 0x21) {
        update_target_from_state();
        return;
    }
    r = gryphon_random_unit_scale * (f32)rand();
    switch (get_table_min(step, 0)) {
    case 0:
        if (r < gryphon_point_six) {
            script_entry = action_scripts[2];
        } else if (r < gryphon_point_nine) {
            script_entry = action_scripts[3];
        } else {
            script_entry = action_scripts[4];
        }
        break;
    case 1:
        if ((flags & 0x200) && boss5_gryphon_behavior_params[2]->attack.action_level >= 5) {
            script_entry = action_scripts[9];
            flags &= ~0x200;
            break;
        }
        flags |= 0x200;
        if (r < gryphon_action_probability_table_a[boss5_gryphon_behavior_params[2]->attack.action_level]) {
            script_entry = action_scripts[9];
            break;
        }
        r = (f32)hp / (f32)hpmax;
        if (gryphon_random_unit_scale * (f32)rand() < gryphon_action_probability_table_b[boss5_gryphon_behavior_params[2]->attack.action_level]) {
            if (gryphon_random_unit_scale * (f32)rand() < r) {
                script_entry = action_scripts[7];
            } else {
                script_entry = action_scripts[8];
            }
        } else {
            if (gryphon_random_unit_scale * (f32)rand() < r) {
                script_entry = action_scripts[5];
            } else {
                script_entry = action_scripts[6];
            }
        }
        break;
    case 2:
        if (r < gryphon_action_probability_table_a[boss5_gryphon_behavior_params[2]->attack.action_level]) {
            script_entry = action_scripts[9];
        } else {
            script_entry = action_scripts[10];
        }
        break;
    case 3:
        if (r < gryphon_point_three) {
            script_entry = action_scripts[11];
        } else if (r < gryphon_point_four) {
            script_entry = action_scripts[12];
        } else if (r < gryphon_point_six) {
            script_entry = action_scripts[13];
        } else if (r < gryphon_point_eight) {
            script_entry = action_scripts[14];
        } else {
            script_entry = action_scripts[15];
        }
        break;
    case 4:
        if (r < gryphon_point_two) {
            if (boss5_gryphon_behavior_params[2]->attack.action_level >= 2) {
                script_entry = action_scripts[19];
            } else {
                script_entry = action_scripts[16];
            }
        } else if (r < gryphon_point_six) {
            if (boss5_gryphon_behavior_params[2]->attack.action_level >= 4) {
                script_entry = action_scripts[20];
            } else {
                script_entry = action_scripts[17];
            }
        } else {
            if (boss5_gryphon_behavior_params[2]->attack.action_level >= 6) {
                script_entry = action_scripts[21];
            } else {
                script_entry = action_scripts[18];
            }
        }
        break;
    case 5:
        script_entry = action_scripts[22];
        break;
    case 6:
        script_entry = action_scripts[4];
        break;
    }
}

s32 TBoss5Gryphon::run_action_script_step(Boss5GryphonMotionEntry *out, Boss5GryphonActionStep *step) {
    TBoss5Gryphon *self = this;
    ScriptAction *actions = script_step_actions();
    ScriptAction *action;
    u32 index = step->command;

    self->copy_angle_state(out, step);
    action = actions + index;
    if (*action != NULL) {
        (self->**action)(out, step);
    }
    if (index == 0x22) {
        return 1;
    }
    return 0;
}

void TBoss5Gryphon::copy_angle_state(Boss5GryphonMotionEntry *dst, Boss5GryphonActionStep *src) {
    dst->state = src->command;
    dst->timer = rand_scaled_offset(src->base, src->spread);
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::calc_product_and_ratio(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step) {
    motion->args.flight.turn = calc_product(step, 0, 1);
    motion->args.flight.speed = random_float_in_table_range(step, 0);
}

#pragma pop
void TBoss5Gryphon::calc_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step) {
    motion->args.circle.turn_rate = random_in_table_range(step, 1);
    motion->args.circle.speed = random_float_in_table_range(step, 0);
    motion->args.circle.radius = random_float_in_table_range(step, 1);
    motion->args.circle.direction = get_random_sign(step, 0);
}

void TBoss5Gryphon::calc_move_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step) {
    f32 distance;
    s32 angle;
    switch (random_in_table_range(step, 0)) {
    case 0:
        angle = (s32)(10430.38043493439 * atan2_float(position.x, position.z));
        distance = random_float_in_table_range(step, 1);
        motion->args.move.x = distance * sin_table_lookup(angle);
        motion->args.move.z = distance * cos_table_lookup(angle);
        break;
    case 1:
        motion->args.move.x = random_float_in_table_range(step, 1);
        motion->args.move.z = random_float_in_table_range(step, 2);
        break;
    }
    motion->args.move.speed = random_float_in_table_range(step, 0);
    motion->args.move.turn_rate = random_in_table_range(step, 1);
}

void TBoss5Gryphon::calc_attack_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step) {
    f32 radius = random_float_in_table_range(step, 1);
    motion->args.flight.radius_sq = radius * radius;
    motion->args.flight.speed = random_float_in_table_range(step, 0);
    motion->args.flight.turn = calc_product(step, 0, 1);
}

void TBoss5Gryphon::set_random_param(Boss5GryphonMotionEntry *motion) {
    motion->args.seed = (s32)(gryphon_u32_range * (gryphon_random_unit_scale * (f32)rand()));
}

#pragma push
#pragma scheduling off
f32 TBoss5Gryphon::random_float_in_table_range(Boss5GryphonActionStep *step, s32 i) {
    return random_in_range(step->floats[i].min, step->floats[i].range);
}

#pragma pop
#pragma push
#pragma fp_contract on
f32 TBoss5Gryphon::random_in_range(f32 min, f32 range) {
    return (range * (gryphon_random_unit_scale * (f32) rand())) + min;
}

#pragma pop
s32 TBoss5Gryphon::random_in_table_range(Boss5GryphonActionStep *step, s32 i) {
    return (s32) random_in_range((f32) step->ints[i].min, (f32) step->ints[i].range);
}

s32 TBoss5Gryphon::get_table_min(Boss5GryphonActionStep *step, s32 i) {
    return step->ints[i].min;
}

#pragma push
#pragma fp_contract on
s32 TBoss5Gryphon::rand_scaled_offset(s32 base, s32 spread) {
    return (s32) (((f32) spread * (gryphon_random_unit_scale * (f32) rand())) + (f32) base);
}

#pragma pop
s32 TBoss5Gryphon::calc_product(Boss5GryphonActionStep *step, s32 sign_index, s32 range_index) {
    s32 value;

    value = random_in_table_range(step, range_index);
    return value * get_random_sign(step, sign_index);
}

s32 TBoss5Gryphon::get_random_sign(Boss5GryphonActionStep *step, s32 i) {
    s32 v;

    v = step->ints[i].min;
    if (v > 0) {
        return 1;
    }
    if (v < 0) {
        return -1;
    }
    if ((gryphon_random_unit_scale * (f32) rand()) >= 0.5f) {
        return 1;
    }
    return -1;
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_ground_effects() {
    TBoss5Gryphon *self = this;
    Vec pts[16];
    Vec *p;
    Vec *q;
    s32 i;
    p = pts;
    VecCopy(p++, &self->bone_positions[3]);
    VecCopy(p++, &self->bone_positions[4]);
    VecCopy(p++, &self->bone_positions[5]);
    VecCopy(p, &self->bone_positions[6]);
    p[1].x = (2.0f * self->bone_positions[3].x + self->bone_positions[4].x) / gryphon_three;
    p[1].y = (2.0f * self->bone_positions[3].y + self->bone_positions[4].y) / gryphon_three;
    p[1].z = (2.0f * self->bone_positions[3].z + self->bone_positions[4].z) / gryphon_three;
    p[2].x = (2.0f * self->bone_positions[4].x + self->bone_positions[3].x) / gryphon_three;
    p[2].y = (2.0f * self->bone_positions[4].y + self->bone_positions[3].y) / gryphon_three;
    p[2].z = (2.0f * self->bone_positions[4].z + self->bone_positions[3].z) / gryphon_three;
    p[3].x = 0.5f * (self->bone_positions[4].x + self->bone_positions[5].x);
    p[3].y = 0.5f * (self->bone_positions[4].y + self->bone_positions[5].y);
    p[3].z = 0.5f * (self->bone_positions[4].z + self->bone_positions[5].z);
    p[4].x = 0.5f * (self->bone_positions[5].x + self->bone_positions[6].x);
    p[4].y = 0.5f * (self->bone_positions[5].y + self->bone_positions[6].y);
    p[4].z = 0.5f * (self->bone_positions[5].z + self->bone_positions[6].z);
    p += 5;
    VecCopy(p++, &self->bone_positions[7]);
    VecCopy(p++, &self->bone_positions[8]);
    VecCopy(p++, &self->bone_positions[9]);
    VecCopy(p, &self->bone_positions[10]);
    p[1].x = (2.0f * self->bone_positions[7].x + self->bone_positions[8].x) / gryphon_three;
    p[1].y = (2.0f * self->bone_positions[7].y + self->bone_positions[8].y) / gryphon_three;
    p[1].z = (2.0f * self->bone_positions[7].z + self->bone_positions[8].z) / gryphon_three;
    p[2].x = (2.0f * self->bone_positions[8].x + self->bone_positions[7].x) / gryphon_three;
    p[2].y = (2.0f * self->bone_positions[8].y + self->bone_positions[7].y) / gryphon_three;
    p[2].z = (2.0f * self->bone_positions[8].z + self->bone_positions[7].z) / gryphon_three;
    p[3].x = 0.5f * (self->bone_positions[8].x + self->bone_positions[9].x);
    p[3].y = 0.5f * (self->bone_positions[8].y + self->bone_positions[9].y);
    p[3].z = 0.5f * (self->bone_positions[8].z + self->bone_positions[9].z);
    p[4].x = 0.5f * (self->bone_positions[9].x + self->bone_positions[10].x);
    p[4].y = 0.5f * (self->bone_positions[9].y + self->bone_positions[10].y);
    p[4].z = 0.5f * (self->bone_positions[9].z + self->bone_positions[10].z);
    q = pts;
    for (i = 0; i < 16; i++, q++) {
        CsnHit *hit = csnVecterUnder(q, 0x16EF);
        if (hit == NULL) {
            q->y = gryphon_negative_thousand;
        } else {
            f32 y = hit->contact->point.y;
            if (y > 6.0f) {
                q->y = 6.0f;
            } else {
                q->y = y;
            }
        }
        if (self->parts[i] == NULL) {
            self->parts[i] = spawn_continuous_particle_effect_with_flags(q, self->effect_ids[5], 0x40);
        } else {
            self->parts[i]->set_position(q);
        }
    }
}

#pragma pop
void TBoss5Gryphon::enable_particles() {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (this->parts[i] != 0) {
            this->parts[i]->set_position(gryphon_particle_enable_pos);
            this->parts[i]->enable();
        }
    }
}

void TBoss5Gryphon::destroy_parts() {
    s32 i;
    for (i = 15; i >= 0; i--) {
        if (this->parts[i] != 0) {
            this->parts[i]->queue_destruction();
            this->parts[i] = 0;
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_low_flight_particles() {
    Vec pos;
    ParticleAngles rot;
    pos.x = gryphon_forty * sin_table_lookup(rotation_y) + bone_positions[11].x;
    pos.y = bone_positions[11].y;
    pos.z = gryphon_forty * cos_table_lookup(rotation_y) + bone_positions[11].z;
    rot.x = 0;
    rot.y = rotation_y;
    rot.x = 0x4000;
    if (particles[0] == NULL) {
        particles[0] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[6], 0x2040);
        particles[0]->set_direction(&rot);
    } else {
        particles[0]->set_position(&pos);
        particles[0]->set_direction(&rot);
    }
    if (particles[1] == NULL) {
        particles[1] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[7], 0x40);
    } else {
        particles[1]->set_position(&pos);
    }
    if (particles[2] == NULL) {
        particles[2] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[8], 0x40);
        particles[2]->set_direction(&rot);
    } else {
        particles[2]->set_position(&pos);
        particles[2]->set_direction(&rot);
    }
}

#pragma pop
void TBoss5Gryphon::update_particle_positions() {
    if (particles[0] != NULL) {
        particles[0]->set_position(gryphon_particle_position_vec);
        particles[0]->enable();
    }
    if (particles[1] != NULL) {
        particles[1]->set_position(gryphon_particle_position_vec);
        particles[1]->enable();
    }
    if (particles[2] != NULL) {
        particles[2]->set_position(gryphon_particle_position_vec);
        particles[2]->enable();
    }
}

void TBoss5Gryphon::free_parts() {
    if (particles[2] != NULL) {
        particles[2]->queue_destruction();
        particles[2] = NULL;
    }
    if (particles[1] != NULL) {
        particles[1]->queue_destruction();
        particles[1] = NULL;
    }
    if (particles[0] != NULL) {
        particles[0]->queue_destruction();
        particles[0] = NULL;
    }
}

#pragma push
#pragma fp_contract on
s32 TBoss5Gryphon::is_sphere_in_camera_cone(Vec *point, f32 radius) {
    Vec dir;
    f32 dist;
    f32 cos_limit;
    VecCopy(&dir, point);
    dir.y = 0.0f;
    subtract_vector(&dir, &boss5_gryphon_camera_pos_vec);
    dist = normalize_vector_xz(&dir);
    if (dist + radius < boss5_gryphon_camera_player_distance) {
        cos_limit = dist * (gryphon_one / newton_sqrtf(dist * dist + radius * radius));
        if (vec3_dot(&dir, (Vec *)boss5_gryphon_direction_vec) >= cos_limit) {
            return 1;
        }
    }
    return 0;
}

#pragma pop
extern "C" {
void TBoss5Gryphon::capture_bone_node(NJS_OBJECT *) {
    Vec *pos;
    if ((s32) boss5_gryphon_render_node_index == boss5_gryphon_bone_capture_node_indices[boss5_gryphon_bone_capture_index]) {
        pos = boss5_gryphon_bone_capture_output;
        boss5_gryphon_bone_capture_output = pos + 1;
        forward_transform_to_view(&boss5_gryphon_bone_capture_origin, pos);
        boss5_gryphon_bone_capture_index += 1;
    }
    boss5_gryphon_render_node_index += 1;
}

}
void TBoss5Gryphon::draw_body() {
    boss5_gryphon_render_node_index = 0;
    boss5_gryphon_bone_capture_index = 0;
    boss5_gryphon_bone_capture_output = this->bone_positions;
    boss5_gryphon_render_flags = this->flags;
    set_chunk_model_node_callback(capture_bone_node);
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    draw_motion((NJS_OBJECT *)this->model, this->current_motion, this->get_motion_frame());
    clear_motion_packed_rotation();
    pop_matrix();
    set_chunk_model_node_callback(0);
}

void TBoss5Gryphon::copy_bone_positions() {
    s32 i;
    Vec *d = this->body_points;
    for (i = 0; i < 10; i++) {
        VecCopy(d, &this->bone_positions[gryphon_bone_copy_index_table[i]]);
        d++;
    }
}

void TBoss5Gryphon::snap_to_ground_height() {
    if (flight_mode == 0) {
        position.y = gryphon_ground_height;
    }
}

void TBoss5Gryphon::render() {
    s32 view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    if (this->defer_render() != 0) {
        snap_to_ground_height();
        this->draw_body();
        this->copy_bone_positions();
        if (this->renderFadeStates[view].isFading() == 0) {
            this->render_with_fade(view);
        }
        this->render_nodes_with_flag();
    } else if (this->renderFadeStates[view].isFading() != 0) {
        this->render_with_fade(view);
    }
}

void TBoss5Gryphon::render_shadows() { if (TObjPlayer::check_demo_mode() == 0) { render_model(); } }

void TBoss5Gryphon::render_model() {
    void *body_model;

    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    body_model = this->model;
    this->model = boss5_gryphon_body_bml_resource->models[1].model;
    TObjMotion::draw();
    this->model = body_model;
    pop_matrix();
}

void TBoss5Gryphon::render_with_fade(s32 fade_index) {
    RenderFadeState *fade;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    TObjEneDD::clear_global_flag_400();
    saved_model_render_flags = model_render_flags;
    set_material_alpha_compare_reference(0);
    if (blocks_camera_view() != 0) {
        this->renderFadeStates[fade_index].fadeOut();
    } else {
        this->renderFadeStates[fade_index].restore();
    }
    fade = &this->renderFadeStates[fade_index];
    if (fade->isFading() != 0) {
        fade->set_flags_and_apply_damage_color();
    }
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    TObjPlayer::toggle_particle_effect();
    draw();
    TParticleCtrl::end_effect_render();
    current_scene_light->sub_801337F8();
    pop_matrix();
    set_chunk_material_override_pair(0xFF00, 0);
    set_material_alpha_compare_reference(0xBF);
    model_render_flags = saved_model_render_flags;
}

s32 TBoss5Gryphon::blocks_camera_view() {
    Vec cam;
    Vec dir;
    f32 len;
    TObjCollidable *pl;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (mode == 4) {
        return 0;
    }
    if (get_flag_bit6() != 0) {
        return 0;
    }
    if (flight_mode != 0) {
        return 0;
    }
    pl = find_entity_by_id(TCameraCtrl::get_camera_target_id(-1));
    if (pl == 0) {
        return 0;
    }
    VecCopy(&cam, &camera_ctrl_instance->pos);
    cam.y = 0.0f;
    VecCopy(&dir, &pl->position);
    subtract_vector(&dir, &cam);
    dir.y = 0.0f;
    len = normalize_vector_xz(&dir);
    VecCopy(&boss5_gryphon_camera_pos_vec, &cam);
    VecCopy((Vec *)boss5_gryphon_direction_vec, &dir);
    boss5_gryphon_camera_player_distance = len;
    for (i = 0; i < 4; i++) {
        if (is_sphere_in_camera_cone(&bone_positions[boss5_gryphon_point_index_table[i]], gryphon_twelve) != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss5Gryphon::render_nodes_with_flag() {
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    this->sub_tasks.render_nodes();
    model_render_flags = saved_model_render_flags;
}

#pragma push
#pragma fp_contract on
extern "C" {
// Strikes a lightning wing from the left or right horn at a player in its arc, else at the ground beside the boss.
void TBoss5Gryphon::fire_horn_lightning(s32 left, s32 client_id) {
    Vec pos;
    Vec mid;
    Vec out;
    Vec tmp;
    f32 r;
    s32 ang;
    CsnHit *hit;

    r = calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->rng));
    r = 100.0f * r + 100.0f;
    ang = (s32)(45056.0f * calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->rng)) + (f32)this->rotation_y);
    if (left != 0) {
        if (this->lightning.horns[0] == NULL) return;
        this->lightning.horns[0]->get_start_position(&pos);
    } else {
        if (this->lightning.horns[1] == NULL) return;
        this->lightning.horns[1]->get_start_position(&pos);
    }
    if (this->get_player_pos_in_arc(left, client_id, &pos, &out) == 0) {
        if (left != 0) {
            ang += 20480.0f;
        }
        out.x = r * sin_table_lookup(ang) + this->position.x;
        out.y = this->position.y;
        out.z = r * cos_table_lookup(ang) + this->position.z;
        VecCopy(&tmp, &out);
        hit = csnVecterUnder(&tmp, 0x16EF);
        if (hit == NULL || hit->contact->point.y > 6.0f) {
            out.x = 100.0f * sin_table_lookup(ang) + this->position.x;
            out.y = this->position.y;
            out.z = 100.0f * cos_table_lookup(ang) + this->position.z;
        }
    }
    mid.x = 0.5f * (pos.x + out.x);
    mid.y = 250.0f + pos.y;
    mid.z = 0.5f * (pos.z + out.z);
    TBoss5GryphonLightningWing::spawn(this, &pos, &mid, &out, 0x14, 0x11);
}
}
s32 TBoss5Gryphon::get_player_pos_in_arc(s32 left, s32 client_id, Vec *org, Vec *out) {
    TObjPlayer *p;
    f32 dx;
    f32 dz;
    f32 px;
    f32 pz;
    s32 ang;

    p = get_player_by_client_id(client_id);
    if (p == 0) {
        return 0;
    }
    pz = p->position.z;
    px = p->position.x;
    dz = pz - this->position.z;
    dx = px - this->position.x;
    if (dx * dx + dz * dz < 10000.0f) {
        return 0;
    }
    ang = angle_diff_s16((s32)(10430.38043493439 * atan2_float(px - org->x, pz - org->z)), this->rotation_y);
    if (left != 0) {
        if ((f32)(s32)(u16)ang > 45056.0f) {
            return 0;
        }
    } else {
        if ((f32)(s32)(u16)ang < 20480.0f) {
            return 0;
        }
    }
    VecCopy(out, &p->position);
    return 1;
}

void TBoss5Gryphon::run_demo_task() { get_target_info(); }

// parameters[0] holds the demo's action and parameters[1] its frame.
void TBoss5Gryphon::render_demo() {
    AnimationMotion *anim;
    f32 frame;
    s32 action;
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        push_matrix();
        scale_matrix(0, 8.0f, 2.0f, 8.0f);
        pop_matrix();
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        model_render_flags &= ~0x400;
        action = (s32)this->parameters[0];
        if (action < 0) {
            action = 0;
        } else if (action >= 0x1B) {
            action = 0x1A;
        }
        anim = this->motion_list[this->action_table[action].motion].motion;
        frame = this->parameters[1];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else {
            u32 n = anim->frameCount;
            if (frame > (n - 1)) {
                frame = (f32)n;
            }
        }
        draw_model_motion(this->model, anim, frame);
        current_scene_light->sub_801337F8();
        pop_matrix();
    }
}

#pragma pop
