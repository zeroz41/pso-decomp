#include "pso/system/SubtractiveRng.h"
#include "pso/system/memory.h"
#include "pso/math/CurvePathPoint.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/system/memory.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/math/FloatRounding.h"
#include "pso/boss/goldragon/TBoss8DragonEffBullet.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/render/RenderFadeState.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/system/ControllerInputState.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/boss/goldragon/TBoss8DragonEffBreath.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/network/client_id.h"
#include "pso/math/AngleUnits.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/PlayerStats.h"
#include "pso/ui/hud/TMainCursor.h"

#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/vector.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8DragonDemo.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/SoundEffect.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
f32 atan2_float(f32 y, f32 x);
}
extern u16 boss8_dragon_control_client_id;
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t);
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed);
extern "C" {
f32 newton_sqrtf(f32);

}
AttackParams *boss8_dragon_part_hp_stats[5];
Boss8DragonParams *boss8_dragon_behavior_params[3];
Vec boss8_dragon_node_origin;
Vec boss8_dragon_breath_local_points[3];
// The empty chunk model every node of boss8_dragon_capture_model draws, so that rendering it only
// runs TBoss8Dragon::capture_node_points on each node.
NJS_CNK_MODEL boss8_dragon_capture_chunk_model;
Vec boss8_dragon_reference_pos_vec;
Vec dragon_forward_reference_vec;
extern "C" {



s32 get_current_floor();
void free_collision_body_parts(void *);
}

extern BmlResource *boss8_dragon_resource;
extern s32 boss8_dragon_model_node_count;
extern s32 boss8_dragon_capture_node;
extern Vec *boss8_dragon_breath_points_out;
extern s32 boss8_dragon_capture_cursor;
extern Vec *boss8_dragon_capture_points_out;
extern s32 boss8_dragon_capture_flags;
extern NJS_OBJECT *boss8_dragon_capture_model;
extern TBoss8Dragon *boss8_dragon_main_instance;
extern s32 boss8_dragon_breath_node;
extern f32 boss8_dragon_visibility_distance;


// The tables below mirror TBoss1Dragon's (same values where the Gol Dragon kept them).
extern const Vec boss8_dragon_arena_center = {0.0f, 0.0f, 0.0f};
extern const DragonAttackParams boss8_dragon_attack_sphere_params = {0, 0.0f, 30.0f, {7.0f, 1}};
extern const DragonAttackParams boss8_dragon_head_fall_attack_params = {0, 0.0f, 35.0f, {50.0f, 1}};
extern const DragonAttackParams boss8_dragon_ground_impact_params = {0, 10.0f, 25.0f, {7.5f, 1}};
extern const Vec boss8_dragon_death_impact_point_a = {-35.0f, 0.0f, 10.0f};
extern const Vec boss8_dragon_death_impact_point_b = {-60.0f, 0.0f, -20.0f};
extern const s32 boss8_dragon_mode_params[10] = {0x41, 0x4c, 0x223, -1, 0xf0, 0x220, -1, 0x221, 0x222, 0xc5};
extern const s32 dragon_mode_params_a[10] = {0x200, 0x211, 0x212, 0x212, 0x94, 0x21d, -1, 0x21c, 0x21b, 0x219};
extern const s32 dragon_mode_params_b[10] = {0x41, 0x4c, 0x208, 0x203, 0xf0, 0x207, 0x200, 0x201, 0x202, 0x205};
extern const s32 boss8_dragon_capture_node_table[35] = {0, 8, 0xa, 0x28, 0x29, 0x32, 0x33, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x46, 0x47, 0x48, 0x4a, 0x4c, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x64, 0x66, 0x3e7};
extern const s32 dragon_next_action_table[11] = {3, 0x27, 0x28, 0x29, 0x2a, 3, 5, 6, 0x23, 8, 0x21};
extern const s32 boss8_dragon_state_transition_table[8] = {0, 0, 2, 3, 3, 3, 0, 0};
extern const s32 boss8_dragon_action_pick_table[29] = {5, 6, 0xf, 0x2b, 0x13, 8, 0x27, 0x28, 3, 5, 6, 0x23, 8, 3, 2, 0x29, 0x2a, 0x27, 0x28, 3, 5, 6, 0x23, 8, 0x27, 0x28, 3, 2, 0x22};
extern const s32 boss8_dragon_action_pick_table_b[28] = {0x13, 8, 0x27, 0x28, 3, 0x27, 0x28, 3, 2, 3, 0x27, 0x28, 5, 6, 0x23, 8, 3, 5, 6, 0x23, 8, 2, 3, 5, 6, 0xf, 0x16, 0x21};
s32 TBoss8Dragon__camera_offset_index_table[5] = {
    0x12, 0x14, 0x15, 0x16, 0x17,
};
s32 boss8_dragon_behavior_param_ids[3] = {
    0x11, 0x12, 0x13,
};
s32 boss8_dragon_attack_stat_indices[5] = {0, 1, 2, 3, 4};
void *boss8_dragon_movement_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x500050,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody boss8_dragon_collision_bodies[7] = {
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *boss8_dragon_model_names[4] = {
    "boss1_s_nb_dragon.nj",
    "lo_boss1_s_nb_dragon.nj",
    "boss1_s_sd_dragon.nj",
    NULL,
};
const char *boss8_dragon_motion_names[27] = {
    "dead_boss1_s_nb_dragon.njm",
    "bossopgc_boss1_s_nb_dragon.njm",
    "down_boss1_s_nb_dragon.njm",
    "frin_boss1_s_nb_dragon.njm",
    "frloop_boss1_s_nb_dragon.njm",
    "frout_boss1_s_nb_dragon.njm",
    "land_boss1_s_nb_dragon.njm",
    "lift_boss1_s_nb_dragon.njm",
    "nkdown_boss1_s_nb_dragon.njm",
    "nkup_boss1_s_nb_dragon.njm",
    "nobi_boss1_s_nb_dragon.njm",
    "stand_boss1_s_nb_dragon.njm",
    "tatk_boss1_s_nb_dragon.njm",
    "walk_boss1_s_nb_dragon.njm",
    "wngclose_boss1_s_nb_dragon.njm",
    "wngopn_boss1_s_nb_dragon.njm",
    "daml_boss1_s_nb_dragon.njm",
    "dams_boss1_s_nb_dragon.njm",
    "fire_boss1_s_nb_dragon.njm",
    "fly_boss1_s_nb_dragon.njm",
    "flyshot_boss1_s_nb_dragon.njm",
    "kiri_boss1_s_nb_dragon.njm",
    "tobidasi_boss1_s_nb_dragon.njm",
    "tukomi_boss1_s_nb_dragon.njm",
    "wgwalk_boss1_s_nb_dragon.njm",
    "wing_boss1_s_nb_dragon.njm",
    NULL,
};
BmlResourceDescriptor boss8_dragon_bml_descriptor = {"bm_boss8_dragon.bml", boss8_dragon_model_names, boss8_dragon_motion_names, 3, 26};
const char *boss8_dragon_class_name = "TBoss8Dragon";
// Same records as TBoss1Dragon's foot-step / fireball attack parameters.
extern const DragonAttackParams boss8_dragon_foot_step_attack_params = {0, 10.0f, 15.0f, {8.0f, 1}};
extern const DragonAttackParams TBoss8Dragon__breath_params = {1, 2.0f, 10.0f, {10.0f, 1}};
extern const DragonAttackParams boss8_dragon_fireball_impact_params = {1, 10.0f, 30.0f, {10.0f, 1}};
extern const DragonAttackParams boss8_dragon_pillar_attack_params = {0, 10.0f, 0.0f, {10.0f, 1}};
extern const s32 boss8_dragon_point_index_table[4] = {3, 4, 5, 6};
TObjMotionAction boss8_dragon_motion_actions[28] = {
    {1, 0, 11, 0.5f, 0},
    {1, 0, 13, 0.5f, 0},
    {3, 0, 10, 0.7f, 0},
    {3, 0, 18, 0.9f, 0},
    {3, 0, 3, 0.5f, 0},
    {1, 0, 4, 0.4f, 0},
    {3, 0, 5, 0.5f, 0},
    {3, 0, 12, 0.5f, 0},
    {2, 9, 8, 0.5f, 0},
    {1, 0, 2, 0.3f, 0},
    {3, 0, 9, 0.3f, 0},
    {3, 0, 17, 0.6f, 0},
    {3, 0, 16, 0.5f, 0},
    {3, 0, 15, 0.5f, 0},
    {3, 0, 14, 0.5f, 0},
    {3, 0, 7, 1.0f, 0},
    {1, 0, 19, 1.0f, 0},
    {2, 14, 6, 1.0f, 0},
    {2, 16, 20, 1.1f, 0},
    {3, 0, 0, 0.5f, 0},
    {1, 0, 25, 1.0f, 0},
    {1, 0, 24, 0.5f, 0},
    {2, 23, 23, 1.0f, 0},
    {1, 0, 21, 1.0f, 0},
    {2, 16, 22, 0.5f, 0x80000000},
    {3, 0, 23, 1.0f, 0},
    {3, 0, 1, 0.5f, 0x80000000},
    {2, 8, 17, 0.6f, 0},
};
Vec boss8_dragon_follow_camera_target_offset = {0.0f, 19.8f, -5.0f};
Vec boss8_dragon_follow_camera_eye_offset = {0.0f, 25.43f, 45.42f};
Vec boss8_dragon_follow_camera_phase_target_offsets[3] = {
    {0.0f, 23.0f, -3.0f},
    {0.0f, 32.0f, 0.0f},
    {0.0f, 25.0f, -5.0f},
};
// Rows 3-10 are TBoss1Dragon's held-camera target and eye offsets, which no Gol Dragon code reads.
Vec boss8_dragon_follow_camera_phase_eye_offsets[11] = {
    {0.0f, 11.0f, 40.0f},
    {0.0f, 5.0f, 35.0f},
    {0.0f, 50.0f, 60.0f},
    {0.0f, 20.0f, -120.0f},
    {0.0f, 120.0f, -120.0f},
    {0.0f, 25.0f, -30.0f},
    {0.0f, 50.0f, -80.0f},
    {0.0f, 120.0f, 50.0f},
    {0.0f, 300.0f, -30.0f},
    {0.0f, 40.0f, 0.0f},
    {300.0f, 120.0f, 50.0f},
};
extern CurvePathPoint boss8_dragon_bezier_points[4];
extern CurvePathPoint boss8_dragon_bezier_points_3[3];
extern CurvePathPoint TBoss8Dragon__dive_height_curve[3];


extern "C" {
extern f32 boss8_dragon_fall_accel;
void subtractive_rng_seed(void *, s32);
// Slot 87: per-action event dispatch through a table of handler members.
}
extern "C" {
s32 __ct__14SubtractiveRngFv(void *rng);
}
void handle_6xA8_gol_dragon_boss_actions(void *data);

extern "C" {
extern const f32 lbl_805D9E80;
f32 lbl_805D6980 = 5.0f * lbl_805D9E80;
f32 lbl_805D6984 = 7.0f * lbl_805D9E80;
}
BmlResource *boss8_dragon_resource;
s32 boss8_dragon_capture_node;
s32 boss8_dragon_breath_node;
Vec *boss8_dragon_breath_points_out;
s32 boss8_dragon_capture_cursor;
Vec *boss8_dragon_capture_points_out;
s32 boss8_dragon_capture_flags;
s32 boss8_dragon_model_node_count;
NJS_OBJECT *boss8_dragon_capture_model;
TBoss8Dragon *boss8_dragon_main_instance;
f32 boss8_dragon_visibility_distance;
s32 boss8_dragon_hold_mode;
s32 boss8_dragon_player_control;
u16 boss8_dragon_control_client_id;
// (from _802FDDD4)
extern "C" {
extern s32 model_render_flags;
// (from _802F3CA0)
extern s32 saved_model_render_flags;
}
// (from _802F3EE4)
extern "C" {
u8 *find_entity_by_id(void);
// (from _802F3F20)
// (from _802F42A0)
}
// (from _802F4324)
extern "C" {
BOOL is_split_screen(void); // TObjPlayer_80011014.h, whose other prototypes clash here
}
void set_tev_swap_channels(u8 r, u8 g, u8 b, u8 a);
void init_tev_swap();
// (from _802F4380)
// (from _802F4480)
void G_GolDragonBossActions_6xA8::init() {
    header.subcommand = 0xA8;
    header.size = sizeof(*this) / 4;
}

void G_GolDragonBossActions_6xA8::bswap() {
    header.bswap();
    bswap_16((u16 *)&what);
    bswap_16((u16 *)&action_index);
    bswap_32(&target_id);
}

void G_GolDragonBossActions_6xA8::send() {
    bswap();
    send_subcommand(this);
}

void TBoss8Dragon::clear_harmful_statuses() {  }

void TBoss8Dragon::apply_shock_status() {  }

void TBoss8Dragon::apply_movement_ailment(s32) {  }

void TBoss8Dragon::apply_confusion_status() {  }

void TBoss8Dragon::apply_slow_status() {  }

void TBoss8Dragon::apply_paralysis() {  }

void TBoss8Dragon::apply_poison_status() {  }

extern "C" {
// Copies the node tree under src into the node array at dst, every copy drawing model; returns the
// next free node.
NJS_OBJECT *TBoss8Dragon::clone_node_tree(NJS_OBJECT *src, NJS_OBJECT *dst, NJS_CNK_MODEL *model) {
    NJS_OBJECT *cur = dst;
    dst = dst + 1;
    copy_model_node(cur, src);
    cur->model = model;
    if (src->child != NULL) {
        cur->child = dst;
        dst = clone_node_tree(src->child, dst, model);
    }
    if (src->sibling != NULL) {
        cur->sibling = dst;
        dst = clone_node_tree(src->sibling, dst, model);
    }
    return dst;
}
void TBoss8Dragon::get_camera_offsets(Vec *target_offset, Vec *eye_offset) {
    s32 mode;
    s32 idx;

    if (boss8_dragon_main_instance == NULL) {
        mode = 1;
    } else if (TBoss8Dragon::find_target_enemy() != 0) {
        mode = 0;
    } else if (boss8_dragon_main_instance->mode == 0x17) {
        mode = 1;
    } else {
        switch (boss8_dragon_main_instance->phase) {
        case 0:
        default:
            idx = 0;
            break;
        case 1:
            idx = 1;
            break;
        case 2:
            idx = 2;
            break;
        }
        VecCopy(target_offset, boss8_dragon_follow_camera_phase_target_offsets + idx);
        VecCopy(eye_offset, boss8_dragon_follow_camera_phase_eye_offsets + idx);
        if (boss8_dragon_main_instance->camera_eye_raised == 1) {
            eye_offset->y += 10.0f;
            eye_offset->z += 10.0f;
        }
        return;
    }
    target_offset->x = 0.0f;
    eye_offset->x = 0.0f;
    switch (mode) {
    case 1:
    default:
        if (TCameraCtrl::get_camera_id() == 2) {
            VecCopy(target_offset, &boss8_dragon_follow_camera_target_offset);
            VecCopy(eye_offset, &boss8_dragon_follow_camera_eye_offset);
            break;
        }
        target_offset->y = boss8_dragon_behavior_params[1]->values[0];
        target_offset->z = boss8_dragon_behavior_params[1]->values[1];
        eye_offset->y = boss8_dragon_behavior_params[1]->values[2];
        eye_offset->z = boss8_dragon_behavior_params[1]->values[3];
        break;
    case 0:
        target_offset->y = boss8_dragon_behavior_params[1]->values[4];
        target_offset->z = boss8_dragon_behavior_params[1]->values[5];
        eye_offset->y = boss8_dragon_behavior_params[2]->values[0];
        eye_offset->z = boss8_dragon_behavior_params[2]->values[1];
        break;
    }
}

void TBoss8Dragon::load_resources() {
    s32 i;
    s32 j;

    boss8_dragon_resource = load_enemy_bml_resource(&boss8_dragon_bml_descriptor);
    boss8_dragon_model_node_count = count_tree_nodes(boss8_dragon_resource->models->model);
    boss8_dragon_capture_model = (NJS_OBJECT *)TQuestVmDownLoadServer::alloc(boss8_dragon_model_node_count * 0x50);
    boss8_dragon_capture_chunk_model.vertex_list = NULL;
    boss8_dragon_capture_chunk_model.polygon_list = NULL;
    boss8_dragon_capture_chunk_model.center[0] = 0.0f;
    boss8_dragon_capture_chunk_model.center[1] = 0.0f;
    boss8_dragon_capture_chunk_model.center[2] = 0.0f;
    boss8_dragon_capture_chunk_model.r = 0.0f;
    TBoss8Dragon::clone_node_tree(boss8_dragon_resource->models->model, boss8_dragon_capture_model,
                                  &boss8_dragon_capture_chunk_model);
    boss8_dragon_capture_node = 0;
    boss8_dragon_breath_node = 60;
    boss8_dragon_node_origin.x = 0.0f;
    boss8_dragon_node_origin.y = 0.0f;
    boss8_dragon_node_origin.z = 0.0f;
    boss8_dragon_breath_local_points[0].x = 0.0f;
    boss8_dragon_breath_local_points[0].y = 0.0f;
    boss8_dragon_breath_local_points[0].z = 5.0f;
    boss8_dragon_breath_local_points[1].x = 0.0f;
    boss8_dragon_breath_local_points[1].y = sin_table_lookup(-0x1555);
    boss8_dragon_breath_local_points[1].z = cos_table_lookup(-0x1555);
    vec3_add_to(&boss8_dragon_breath_local_points[1], &boss8_dragon_breath_local_points[0]);
    boss8_dragon_breath_local_points[2].x = 0.0f;
    boss8_dragon_breath_local_points[2].y = -1.0f;
    boss8_dragon_breath_local_points[2].z = 1.0f;
    boss8_dragon_breath_points_out = 0;
    boss8_dragon_capture_cursor = 0;
    boss8_dragon_capture_points_out = 0;
    boss8_dragon_capture_flags = 0;
    boss8_dragon_main_instance = 0;
    for (i = 0; i < 5; i++) {
        boss8_dragon_part_hp_stats[i] = TLobby::dispatch_shared_handler_b(TBoss8Dragon__camera_offset_index_table[i]);
    }
    for (j = 0; j < 3; j++) {
        boss8_dragon_behavior_params[j] = (Boss8DragonParams *)TLobby::dispatch_shared_handler_a(boss8_dragon_behavior_param_ids[j]);
    }
    boss8_dragon_hold_mode = 0;
    boss8_dragon_player_control = 0;
    boss8_dragon_control_client_id = 0xFFFF;
    TWindowCtrl::init_all_slots();
    TBoss8DragonEffTail::load_resources();
}

void *TBoss8Dragon::create(void *set_data) {
    return new TBoss8Dragon(tl_04, set_data);
}

void TBoss8Dragon::free_static() {
    if (boss8_dragon_capture_model != NULL) {
        safe_free(boss8_dragon_capture_model);
        boss8_dragon_capture_model = NULL;
    }
    if (boss8_dragon_resource != NULL) {
        delete boss8_dragon_resource;
        boss8_dragon_resource = NULL;
    }
}

void TBoss8Dragon::clear_player_control() { boss8_dragon_player_control = 0; }

TBoss8Dragon::TBoss8Dragon(TObject *parent, void *set_data) : TObjEneDD_ST(parent), sub_tasks(NULL) {
    u32 record[4];
    s32 i;
    s32 j;
    Boss8DragonParams *cfg;

    __ct__14SubtractiveRngFv(this->randomState);
    this->m_name = boss8_dragon_class_name;
    if (boss8_dragon_main_instance == NULL) {
        boss8_dragon_main_instance = this;
    }
    invoke_initialization_hook(set_data);
    this->flags = 0;
    if (this->exchange_object_state(record, 1) != 0 && (record[0] & 0x12008) == 0x12008) {
        this->flags |= 8;
    }
    this->init_position_vectors();
    this->model = boss8_dragon_resource->models[0].model;
    this->texlist = boss8_dragon_resource->models[0].texlist;
    this->scale.x = 2.0f;
    this->scale.y = 2.0f;
    this->scale.z = 2.0f;
    init_model(boss8_dragon_collision_bodies, 7);
    this->motion_flags = 0;
    this->set_action_table(boss8_dragon_motion_actions);
    this->set_motion_list(boss8_dragon_resource->motions);
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    reset_hp(TLobby::register_boss(0x12), boss8_dragon_part_hp_stats[boss8_dragon_attack_stat_indices[0]], TLobby::register_object(0x12));
    this->set_state_flag_1();
    this->movementParameters = boss8_dragon_movement_params;
    initialize_enemy_state(0x4C);
    this->wall_reach = 20.0f;
    this->enemy_init_acquire_period(0xA);
    this->enemy_init_validate_period(0xA);
    this->phase = 0;
    this->flags |= 1;
    for (i = 0; i < 3; i++) {
        VecCopy(&this->breath_node_points[i], &this->position);
    }
    VecCopy(&this->breath_origin, &this->position);
    VecCopy(&this->breath_direction, &this->position);
    VecCopy(&this->breath_effect_position, &this->position);
    for (i = 0; i < 0x22; i++) {
        VecCopy(&this->node_positions[i], &this->position);
    }
    this->target_vector.x = 0.0f;
    this->target_vector.y = 0.0f;
    this->target_vector.z = 0.0f;
    this->target_distance = 0.0f;
    this->m_5dc = 0.0f;
    this->last_flight_direction.x = 0.0f;
    this->last_flight_direction.y = 0.0f;
    this->last_flight_direction.z = 0.0f;
    curve0.reset_coords();
    curve1.reset_coords();
    VecCopy(&this->sound_origin, &this->position);
    VecCopy(&this->last_body_center, &this->position);
    this->camera_eye_raised = 0;
    this->airTurnVelocity = 0;
    this->airTurnDirection = 1;
    this->airTurnAcceleration = 0.0f;
    this->airTurnFinalAcceleration = 0.0f;
    this->airTurnTime = 0.0f;
    this->sequenceCursor = 0;
    this->hpThreshold = 0;
    cfg = boss8_dragon_behavior_params[2];
    this->finalHpThreshold = cfg->values[2] * this->hpmax / 100.0f;
    stat_block->proportions = 10.0f;
    update_damage_threshold();
    this->tail = new TBoss8DragonEffTail(this, &this->node_positions[15]);
    this->attack_history = new AreaAttackHistory(4);
    this->collider = new TBoss8DragonColli(&this->sub_tasks);
    this->destinationX = 0.0f;
    this->destinationZ = 0.0f;
    this->savedX = 0.0f;
    this->savedZ = 0.0f;
    this->sector_count = 0;
    this->crater_count = 0;
    for (i = 0; i < 0xC; i++) {
        this->sector_radii[i] = 0.0f;
    }
    this->burrow_run_count = 0;
    for (j = 0; j < 4; j++) {
        this->renderFadeStates[j].activate_and_dispatch();
    }
    this->player_controlled = 0;
    this->target_client_id = 0xFFFF;
    this->controlTimer = 0;
    this->facingAngle = 0;
    this->set_mode_params(2);
    this->stateStep = 0;
    this->impactAge = 0;
    this->action_frames = 0;
    this->demo_flag = 0;
    this->action_angle = 0;
    this->action_spin = 0;
    this->fallVelocity = 0.0f;
    this->rootHeight = 0.0f;
    this->action_speed = 0.0f;
    this->vertical_speed = 0.0f;
    this->root_height_speed = 0.0f;
    this->action_point.x = 0.0f;
    this->action_point.y = 0.0f;
    this->action_point.z = 0.0f;
    this->m_884 = 0.0f;
    this->m_888 = 0.0f;
    this->m_88c = 0.0f;
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
    restart_primary_sequence();
    if (boss8_dragon_main_instance == this) {
        this->mode = 0x1E;
        create_boss8_dragon_leader_part(this, set_data);
    }
    if (!(this->flags & 8)) {
        this->dispatch_action(this->mode, 4);
    }
    this->lobby_state_changed = 0;
}

}
TBoss8Dragon::~TBoss8Dragon() {
    if (collider != NULL) {
        delete collider;
        collider = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (tail != NULL) {
        delete tail;
        tail = NULL;
    }
    free_collision_body_parts(this);
    if (boss8_dragon_main_instance == this) {
        boss8_dragon_main_instance = NULL;
    }
}

void TBoss8Dragon::run_task() {
    s32 state;
    s32 old_state;
    s32 teammate_state;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->flags & 8) {
        this->send_entity_set_flags();
        this->TObject::queue_destruction();
        return;
    }
    if (this->player_controlled != 0) {
        this->freeze_player_at_self();
        this->controlTimer = this->controlTimer + 1;
    } else if ((TObjEneDD::is_main_phase_15() != 0) && (this->lobby_state_locked == 0)) {
        old_state = this->lobby_state;
        if (this->update_lobby_state() != 0) {
            this->lobby_state = 0;
            if (this->lobby_state != old_state) {
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
        if (this->mode == 0x15 || this->mode == 0x16 || this->mode == 0x17) {
            this->actorFlags |= 0x800;
        } else {
            this->actorFlags &= ~0x800;
        }
        if (this->player_controlled != 0) {
            if (this->target_client_id == local_client_id) {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if (boss8_dragon_player_control == 0) {
                    this->release_grabbed_player();
                } else {
                    this->check_death();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if (boss8_dragon_player_control == 0) {
                    this->release_grabbed_player();
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
                        if ((s16) this->hp < this->finalHpThreshold) {
                            this->hp = this->finalHpThreshold;
                        }
                        this->clear_attack_receipts();
                    }
                    this->select_next_action();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_primary_sequence() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
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
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    VecCopy(&this->last_body_center, &this->body_center);
    if (teammate_state == 0) {
        this->sub_tasks.run_tasks();
    }
    project_sound_origin_from_camera(&this->position, &this->sound_origin, 0.4f);
    if (!(this->flags & 0x100)) {
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].update();
        }
    }
}

void TBoss8Dragon::select_next_action() {
    s32 state_flags;
    state_flags = this->flags;
    if (state_flags & 0x40) {
        if (!(state_flags & 0x20) && (this->hp <= 0)) {
            this->send_action_packet(0x16);
            return;
        }
        goto block_14;
    }
    if (is_primary_sequence() != 0) {
        if (!(this->flags & 0x10)) {
            if (check_damage_reaction() == 0) {
                if (this->check_phase_advance() != 0) {
                    return;
                }
                goto block_14;
            }
        } else {
            goto block_14;
        }
    } else {
        if (!(this->flags & 0x20) && (this->hp <= 0)) {
            if (this->phase == 1) {
                this->send_action_packet(0xC);
                return;
            }
            this->send_action_packet(0x15);
            return;
        }
block_14:
        if ((s32) boss8_dragon_hold_mode != 0) {
            this->dispatch_action(this->mode, 2);
            return;
        }
        if (this->player_controlled != 0) {
            this->dispatch_action(this->mode, 0xB);
            return;
        }
        this->dispatch_action(this->mode, 9);
    }
}

void TBoss8Dragon::check_death() {
    if (is_primary_sequence() != 0) {
        if (check_damage_reaction() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->flags & 0x20) && (this->hp <= 0)) {
        if (this->phase == 1) {
            send_action_packet(0xC);
            return;
        }
        send_action_packet(0x15);
        return;
    }
block_8:
    this->dispatch_action(this->mode, 0xB);
}

void TBoss8Dragon::refresh_target() {  }

void TBoss8Dragon::run_death_reaction() {  }

void TBoss8Dragon::run_hit_reaction() {  }

void TBoss8Dragon::run_miss_reaction() {  }

void TBoss8Dragon::set_state_22() { if (this->mode != 22) { send_action_packet(22); } }

s32 TBoss8Dragon::has_appeared() {
    if (this->mode != 0x1E) {
        return 1;
    }
    return 0;
}

void TBoss8Dragon::update_position_history() {
    VecCopy(&this->body_center, &this->node_positions[0]);
    VecCopy(&this->center, &this->body_center);
}

void TBoss8Dragon::update_body_colliders() {
    Vec pts[7];
    Vec *p;
    s32 i;

    p = pts;
    VecCopy(p++, &this->node_positions[0]);
    VecCopy(p++, &this->node_positions[5]);
    VecCopy(p++, &this->node_positions[3]);
    VecCopy(p++, &this->node_positions[1]);
    VecCopy(p++, &this->node_positions[32]);
    VecCopy(p++, &this->node_positions[12]);
    VecCopy(p, &this->node_positions[17]);
    update_local_colliders_from_world(this, pts);
    for (i = 0; i < 7; i++) {
        if (bodies[i].offset.y >= 30.0f) {
            set_collider_contact_high(&bodies[i]);
        } else {
            set_collider_contact_low(&bodies[i]);
        }
    }
    if (this->mode != 9) {
        set_collider_contact_high(&bodies[3]);
        set_collider_contact_high(&bodies[4]);
    }
    bodies[0].unk_28 = boss8_dragon_behavior_params[0]->ints[2];
    bodies[1].unk_28 = boss8_dragon_behavior_params[0]->ints[1];
    bodies[2].unk_28 = boss8_dragon_behavior_params[0]->ints[1];
    bodies[3].unk_28 = boss8_dragon_behavior_params[0]->ints[2];
    bodies[4].unk_28 = boss8_dragon_behavior_params[0]->ints[2];
    bodies[5].unk_28 = boss8_dragon_behavior_params[0]->ints[0];
    bodies[6].unk_28 = boss8_dragon_behavior_params[0]->ints[2];
}

s32 TBoss8Dragon::update_linked_position() {
    return TObjEneDD_ST::update_linked_position(1000.0f);
}

void TBoss8Dragon::calc_target_vector() {
    this->target_vector.x = this->destination.x - this->breath_origin.x;
    this->target_vector.y = 0.0f;
    this->target_vector.z = this->destination.z - this->breath_origin.z;
    this->target_distance = normalize_vector_xz(&this->target_vector);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::calc_forward_point(f32 *x, f32 *z) {
    *x = (185.0f * sin_table_lookup(this->rotation_y)) + this->position.x;
    *z = (185.0f * cos_table_lookup(this->rotation_y)) + this->position.z;
}

#pragma pop
s32 TBoss8Dragon::is_near_target() {
    Vec orbit;
    Vec d;
    calc_forward_point(&orbit.x, &orbit.z);
    VecCopy(&d, &this->destination);
    subtract_vector(&d, &orbit);
    return normalize_vector_xz(&d) <= 35.0f;
}

void TBoss8Dragon::restart_primary_sequence() {
    select_sequence(0);
}

void TBoss8Dragon::select_sequence(s32 secondary) {
    if (secondary == 0) {
        this->sequenceCursor = 0;
        return;
    }
    this->sequenceCursor = 0x32;
}

s32 TBoss8Dragon::is_primary_sequence() {
    TBoss8Dragon * boss8_dragon = this;
    return boss8_dragon->sequenceCursor < 0x32;
}

s32 TBoss8Dragon::is_secondary_sequence() {
    return (u8) (this->sequenceCursor >= 0x32);
}

void TBoss8Dragon::update_damage_threshold() {
    s16 step = this->hpmax / 10;
    s16 value = this->hpmax - step;
    step += step;
    while (this->hp <= value) {
        value -= step;
    }
    this->hpThreshold = value;
}

s32 TBoss8Dragon::select_air_fire_target(Vec *out) {
    TObjPlayer *list[12];
    TObjPlayer *p;
    s32 bestHp;
    s32 n;
    s32 i;
    s32 best;
    Vec *apos;
    TObjPlayer *a;
    TObjPlayer *b;
    s32 found;
    s32 i2;
    s32 j;
    s32 k;
    f32 lim;
    lim = 6400.0f;
    n = 0;
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (((TObjEneDD *)p)->is_valid_target() != 0 &&
            horizontal_distance_squared(&p->position, &this->position) >= lim) {
            list[n] = p;
            n++;
        }
    }
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        VecCopy(out, &list[0]->position);
    } else {
        lim = 100.0f;
        best = 0;
        found = 0;
        for (i2 = 0; i2 < n; i2++) {
            a = list[i2];
            apos = &a->position;
            for (j = i2 + 1; j < n; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(&b->position, apos)) < lim) {
                    s32 sum;
                    found = 1;
                    sum = a->hp + b->hp;
                    if (sum > best) {
                        best = sum;
                        out->x = 0.5f * (apos->x + b->position.x);
                        out->y = 0.5f * (apos->y + b->position.y);
                        out->z = 0.5f * (apos->z + b->position.z);
                    }
                }
            }
        }
        if (found == 0) {
            bestHp = 0;
            for (k = 0; k < n; k++) {
                p = list[k];
                if (bestHp < p->hp) {
                    bestHp = p->hp;
                    VecCopy(out, &p->position);
                }
            }
        }
    }
    return 1;
}

s32 TBoss8Dragon::choose_burrow_ring_destination(f32 *out) {
    s32 ang;
    s32 i;
    s32 n;
    f32 r;
    i = (s32)floor_to_float(12.0f * this->random_ratio());
    n = this->sector_count;
    if (n < 12) {
        this->sector_count = n + 1;
        while (0.0f != this->sector_radii[i]) {
            i++;
            if (i >= 12) {
                i = 0;
            }
        }
        r = this->rand_range(100.0f, 220.0f);
        this->sector_radii[i] = r;
    } else {
        r = this->sector_radii[i];
    }
    ang = i * 0x1555;
    out[0] = r * sin_table_lookup(ang);
    out[1] = 0.0f;
    out[2] = r * cos_table_lookup(ang);
    return 1;
}

void TBoss8Dragon::prepare_flight_destination(Vec *dest) {
    if (this->is_primary_sequence() != 0) {
        VecCopy(&this->destination, &this->position);
        this->destination.y = 0.0f;
        normalize_vector_xz(&this->destination);
        this->destination.x *= -100.0f;
        this->destination.z *= -100.0f;
        return;
    }
    VecCopy(&this->destination, &boss8_dragon_arena_center);
}

s32 TBoss8Dragon::select_target_in_front() {
    Vec d;
    Vec ref;
    u16 ids[4];
    f32 lim;
    s32 n;
    s32 count;
    u8 *player;
    s32 i;

    n = 0;
    count = TLobby::get_game_mode();
    if (count > 4) {
        count = 4;
    }
    lim = cos_table_lookup(0x3000);
    ref.x = sin_table_lookup(this->rotation_y);
    ref.y = 0.0f;
    ref.z = cos_table_lookup(this->rotation_y);
    for (i = 0; i < count; i++) {
        player = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjMotion *)player)->is_alive() != 0) {
            VecCopy(&d, (Vec *)(player + 0x38));
            subtract_vector(&d, &this->position);
            normalize_vector_xz((Vec *)&d);
            if (vec3_dot(&d, &ref) > lim) {
                ids[n++] = ((TObjBase *)(player))->get_entity_id();
            }
        }
    }
    if (n <= 0) {
        this->enemy_clear_target();
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(this, ids[0]);
        return 1;
    }
    enemy_set_target_id(this, ids[(s32)floor_to_float((f32)n * this->random_ratio())]);
    return 1;
}

void TBoss8Dragon::play_effect_sound(s32 sound_id) {
    play_sound_effect(sound_id, &this->sound_origin, 0, 0);
}

void TBoss8Dragon::spawn_trap(s32 id) {
    play_persistent_sound(id, this, &this->sound_origin, 0, 0);
}

void TBoss8Dragon::try_spawn_trap() {
    if ((this->flags & 0x40) && (is_closest_part() != 0)) {
        this->spawn_trap(0x4003D013);
    }
}

void TBoss8Dragon::play_sound_if_in_band() {
    u8 *self = (u8 *)this;
    if ((this->is_passing_frame(4.0f) != 0) || (this->is_passing_frame(24.5f) != 0)) {
        ((TBoss8Dragon *)((saddr) self))->play_effect_sound(0x4003A801);
    }
}

void TBoss8Dragon::spawn_effect_if_in_band() {
    if (this->is_passing_frame(5.0f) != 0) {
        this->play_effect_sound(0x4003A804);
    }
}

void TBoss8Dragon::reset_timer() { this->phase = 0; }

void TBoss8Dragon::set_state() { this->phase = 1; }

void TBoss8Dragon::set_action_state() { this->phase = 2; }

void TBoss8Dragon::set_active_flag() { this->flags = (this->flags | 0x1); this->position.y = 0.0f; }

void TBoss8Dragon::activate_attack() { this->flags = (this->flags | 0x1); this->position.y = 180.0f; }

void TBoss8Dragon::reset_action() { this->flags = (this->flags & 0xfffffffe); this->position.y = -400.0f; }

void TBoss8Dragon::set_air_turn_direction(s32 angle, s32 target_angle) {
    if (angle_diff_s16(angle, target_angle) >= 0) {
        this->airTurnDirection = 1;
        return;
    }
    this->airTurnDirection = -1;
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::init_air_turn(s32 targetAngle) {
    f32 height;
    f32 turn;
    f32 half;
    f32 frames = 35.0f;
    f32 k = 25.0f;

    this->airTurnVelocity = (s16) this->airTurnVelocity;
    height = (f32) this->airTurnVelocity;
    turn = (f32) angle_diff_s16(this->rotation_y, targetAngle);
    half = 0.5f * height;
    this->airTurnFinalAcceleration = -(2.0f * (turn - half * frames)) / 1500.0f;
    this->airTurnAcceleration = -(this->airTurnFinalAcceleration * k + height) / frames;
    this->airTurnTime = 0.0f;
    this->airTurnInitialVelocity = height;
    this->airTurnFinalVelocity = -(this->airTurnFinalAcceleration * k);
    half = 0.5f * this->airTurnAcceleration;
    this->airTurnMidpointAngle = frames * (half * frames + height);
    this->airTurnStartAngle = this->rotation_y;
}

s32 TBoss8Dragon::advance_air_turn() {
    f32 t;
    this->airTurnTime += 1.0f;
    t = this->airTurnTime;
    if (t <= 35.0f) {
        this->rotation_y = this->airTurnStartAngle + (s32) (t * ((0.5f * this->airTurnAcceleration * t) + this->airTurnInitialVelocity));
        return 0;
    }
    if (t <= 60.0f) {
        t = t - 35.0f;
        this->rotation_y = this->airTurnStartAngle + (s32) ((t * ((0.5f * this->airTurnFinalAcceleration * t) + this->airTurnFinalVelocity)) + this->airTurnMidpointAngle);
        return 0;
    }
    return 1;
}

#pragma pop
void TBoss8Dragon::reload_boss_stats() {
    this->reload_stats_keep_hp_tp(TLobby::register_boss(0x12), boss8_dragon_part_hp_stats[boss8_dragon_attack_stat_indices[0]], TLobby::register_object(0x12));
}

void TBoss8Dragon::reset_tail_hp() {
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[1], NULL);
}

void TBoss8Dragon::reload_stats_for_phase() {
    this->reload_stats_keep_hp_tp(TLobby::register_boss(0x12), boss8_dragon_part_hp_stats[boss8_dragon_attack_stat_indices[2]], TLobby::register_object(0x12));
}

void TBoss8Dragon::reload_impact_stats() {
    this->reload_stats_keep_hp_tp(TLobby::register_boss(0x12), boss8_dragon_part_hp_stats[boss8_dragon_attack_stat_indices[3]], TLobby::register_object(0x12));
}

void handle_6xA8_gol_dragon_boss_actions(void *data) {
    G_GolDragonBossActions_6xA8 *cmd = (G_GolDragonBossActions_6xA8 *)data;
    TBoss8Dragon *boss;
    cmd->bswap();
    boss = (TBoss8Dragon *)get_enemy_entity(cmd->header.client_id);
    if (boss != NULL) {
        boss->apply_6xA8_action(cmd);
    }
}

void TBoss8Dragon::apply_6xA8_action(G_GolDragonBossActions_6xA8 *cmd) {
    s16 action;
    enemy_set_target_id(this, (u16)cmd->target_id);
    this->sequenceCursor = cmd->action_index;
    this->savedX = cmd->x;
    this->savedZ = cmd->z;
    this->dispatch_action(cmd->what, 7);
    this->set_mode_params(cmd->effect_mode);
    action = cmd->what;
    if ((s16)this->mode != action) {
        this->transition_enemy_state(action);
    }
}

void TBoss8Dragon::send_6xA8_action() {
    G_GolDragonBossActions_6xA8 cmd;
    f32 t;
    cmd.init();
    cmd.header.client_id = this->entity_id;
    cmd.what = this->mode;
    cmd.action_index = this->sequenceCursor;
    cmd.target_id = this->target_id;
    cmd.x = this->destinationX;
    cmd.z = this->destinationZ;
    t = 0.000030517578f * (f32)rand();
    cmd.effect_mode = (s8)(3.0f * t);
    cmd.send();
}

void TBoss8Dragon::send_action_packet(int action) {
    G_GolDragonBossActions_6xA8 cmd;
    f32 t;
    this->dispatch_action(action, 6);
    cmd.init();
    cmd.header.client_id = this->entity_id;
    cmd.what = action;
    cmd.action_index = this->sequenceCursor;
    cmd.target_id = this->target_id;
    cmd.x = this->destinationX;
    cmd.z = this->destinationZ;
    t = 0.000030517578f * (f32)rand();
    cmd.effect_mode = (s8)(3.0f * t);
    cmd.send();
}

void TBoss8Dragon::sync_target_pos() {
    this->destination.x = this->savedX;
    this->destination.z = this->savedZ;
}

void TBoss8Dragon::copySavedX(s32 *x) {
    *x = (s32) this->savedX;
}

void TBoss8Dragon::restore_target_pos() {
    this->position.x = this->savedX;
    this->position.z = this->savedZ;
}

void TBoss8Dragon::save_position() { this->destinationX = this->destination.x; this->destinationZ = this->destination.z; }

void TBoss8Dragon::setDestinationX(s32 x) {
    this->destinationX = (f32) x;
    this->destinationZ = 0.0f;
}

void TBoss8Dragon::copy_pos_to_field688() {
    this->destinationX = this->position.x;
    this->destinationZ = this->position.z;
}

#pragma push
#pragma pool_data off
void TBoss8Dragon::pick_next_action() {
  s32 index;
  const s32 *table;
  s32 action;
  s32 cursor;
  s32 restart;
  if (this->flags & 0x40)
  {
    index = this->sequenceCursor;
    table = boss8_dragon_action_pick_table_b;
  }
  else
  {
    cursor = this->sequenceCursor;
    if (cursor < 0x32)
    {
      index = cursor;
      table = dragon_next_action_table;
    }
    else
    {
      index = cursor - 0x32;
      table = boss8_dragon_action_pick_table;
    }
  }
  do
  {
    action = table[index];
    restart = 0;
    index += 1;
    this->sequenceCursor = this->sequenceCursor + 1;
    switch (action)
    {
      case 33:
        this->sequenceCursor = 0;
        restart = 1;
        index = 0;
        break;
      case 34:
        this->sequenceCursor = 0x32;
        restart = 1;
        index = 0;
        break;
    }
  }
  while (restart != 0);
  this->send_action_packet(action);
}
#pragma pop

void TBoss8Dragon::remap_sequence_after_recovery() {
    if (this->player_controlled != 0) {
        this->pick_next_action();
        return;
    }
    if (this->check_damage_reaction() == 0) {
        this->sequenceCursor = boss8_dragon_state_transition_table[this->sequenceCursor];
        this->pick_next_action();
    }
}

s32 TBoss8Dragon::check_damage_reaction() {
    if (this->flags & 0x40) {
        return 0;
    }
    if ((s16) this->hp <= this->finalHpThreshold) {
        this->hp = this->finalHpThreshold;
        select_sequence(1);
        if (this->phase == 0) {
            send_action_packet(0xD);
            return 1;
        }
        send_action_packet(0xB);
        return 1;
    }
    return 0;
}

s32 TBoss8Dragon::check_phase_advance() { return 0; }

#pragma push
#pragma fp_contract on
f32 TBoss8Dragon::calc_step_value() {
    TBoss8Dragon *o = this;
    return 4.0f * (f32)o->burrow_run_count + 4.0f;
}

#pragma pop
void TBoss8Dragon::start_rumble() {
    saddr self = (saddr)this;
    start_pad_rumble_at(&this->position, 0xE0, self);
}

void TBoss8Dragon::apply_foot_step_attack(int side) {
    DragonAttackParams params = boss8_dragon_foot_step_attack_params;
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
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
    this->emit_effect(a, &params, this->attack_history);
    this->emit_effect(b, &params, this->attack_history);
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
    spawn_particle_effect_with_flags(b, this->particle_ids[4], 0x40);
}

void TBoss8Dragon::apply_foot_attack_pair_0() { apply_foot_step_attack(0); }

void TBoss8Dragon::apply_foot_attack_pair_1() { apply_foot_step_attack(1); }

void TBoss8Dragon::apply_landing_attack() {
    DragonAttackParams stack;
    TBoss1Dragon__sub_80027A80(&stack, &boss8_dragon_attack_sphere_params);
    stack.radius = boss8_dragon_behavior_params[0]->values[3];
    reload_stats_for_phase();
    this->get_state_flags(&stack);
    this->reload_boss_stats();
}

void TBoss8Dragon::apply_head_fall_attack() {
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[4], NULL);
    this->get_state_flags(&boss8_dragon_head_fall_attack_params);
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::sweep_body_attack_spheres(f32 a, f32 b, f32 c) {
    DragonAttackParams fx = boss8_dragon_head_fall_attack_params;
    Vec pos;
    Vec base;
    f32 sn;
    f32 cs;
    f32 d;

    fx.radius = a - 2.0f;
    fill_value_array(this->attack_history);
    sn = sin_table_lookup(this->rotation_y);
    cs = cos_table_lookup(this->rotation_y);
    VecCopy(&base, &this->position);
    base.x += -4.0f * cs;
    base.y = 0.0f;
    base.z -= -4.0f * sn;
    d = 0.5f * (b + c);
    VecCopy(&pos, &base);
    pos.x = sn * d + pos.x;
    pos.z = cs * d + pos.z;
    spawn_particle_effect_with_flags(&pos, this->particle_ids[4], 0x40);
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[4], NULL);
    c = c - a;
    d = b - a;
    a *= 2.0f;
    b = 0.5f * (0.5f * a);
    while (d > c) {
        VecCopy(&pos, &base);
        pos.x = sn * d + pos.x;
        pos.z = cs * d + pos.z;
        this->emit_effect(&pos, &fx, this->attack_history);
        d -= a;
        push_matrix();
        post_translate_matrix(&pos.x);
        scale_matrix(0, b, 2.0f, b);
        draw_chunk_object(debug_cylinder_object);
        pop_matrix();
    }
    this->reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
}

#pragma pop
void TBoss8Dragon::sweep_head_fall_spheres_early() {
    sweep_body_attack_spheres(10.0f, -60.0f, -140.0f);
}

void TBoss8Dragon::sweep_head_fall_spheres_late() {
    this->sweep_body_attack_spheres(10.0f, 90.0f, 60.0f);
}

void TBoss8Dragon::apply_ground_impact_attack() {
    this->reload_impact_stats();
    this->get_state_flags(&boss8_dragon_ground_impact_params);
    this->reload_boss_stats();
}

void TBoss8Dragon::sweep_death_body_attack() {
    Vec *pts[10];
    DragonAttackParams e;
    Vec v;
    s32 i;
    reset_hp(NULL, boss8_dragon_part_hp_stats[4], NULL);
    fill_value_array(this->attack_history);
    TBoss1Dragon__sub_80027A80(&e, &boss8_dragon_head_fall_attack_params);
    VecCopy(&v, &this->node_positions[12]);
    e.radius = 15.0f;
    emit_effect(&v, &e, this->attack_history);
    e.radius = 12.0f;
    pts[0] = &this->node_positions[7];
    pts[1] = &this->node_positions[9];
    for (i = 0; i < 2; i++) {
        emit_effect(pts[i], &e, this->attack_history);
    }
    e.radius = 11.0f;
    pts[0] = &this->node_positions[14];
    pts[1] = &this->node_positions[15];
    pts[2] = &this->node_positions[16];
    pts[3] = &this->node_positions[17];
    for (i = 0; i < 4; i++) {
        emit_effect(pts[i], &e, this->attack_history);
    }
    reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
}

void TBoss8Dragon::apply_trail_attack() {  }

void TBoss8Dragon::setup_breath_instance(Vec *pos, u32 kind, AreaAttackHistory *history) {
    DragonAttackParams s = TBoss8Dragon__breath_params;
    s.power = boss8_dragon_behavior_params[0]->values[0];
    s.kind = kind;
    setup_instance(pos, &s, history);
}

void TBoss8Dragon::apply_fireball_impact_damage(Vec *pos, u32 kind) {
    DragonAttackParams s = boss8_dragon_fireball_impact_params;
    s.power = boss8_dragon_behavior_params[0]->values[1];
    s.kind = kind;
    this->setup_instance(pos, &s, 0);
}

void TBoss8Dragon::apply_pillar_attack(Vec *pos, f32 radius) {
    DragonAttackParams s = boss8_dragon_pillar_attack_params;
    s.radius = radius;
    s.power = boss8_dragon_behavior_params[0]->values[2];
    this->setup_instance(pos, &s, this->attack_history);
}

void TBoss8Dragon::emit_effect(const Vec *pos, const DragonAttackParams *params, AreaAttackHistory *history) {
    TObjEneDD::emit_enemy_effect(this, pos, params, history);
}

void TBoss8Dragon::get_state_flags(const DragonAttackParams *params) { emit_effect_at_position(params); }

void TBoss8Dragon::setup_instance(Vec *pos, DragonAttackParams *params, AreaAttackHistory *history) { TObjEneDD::setup_instance(this, pos, params, history); }

void TBoss8Dragon::spawn_ground_effect() {
    Vec pos;
    f32 floor_y;
    CsnHit *hit;
    VecCopy(&pos, &this->position);
    hit = csnVecterUnder(&pos, 0x16EF);
    if (hit != NULL) {
        floor_y = hit->contact->point.y;
        if (!(floor_y > 30.0f)) {
            pos.y = floor_y;
            spawn_particle_effect_with_flags(&pos, this->particle_ids[1], 0x40);
        }
    }
}

void TBoss8Dragon::update_flap_effect() {
    if (this->is_passing_frame(14.0f) != 0) {
        this->spawn_ground_effect();
    }
}

u16 TBoss8Dragon::find_player_on_floor() {
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

void TBoss8Dragon::select_freeze_target() {
    u16 client_id;
    if (boss8_dragon_player_control != 0) {
        this->player_controlled = 1;
    } else {
        this->player_controlled = 0;
        this->target_client_id = 0xFFFFU;
        return;
    }
    this->controlTimer = 0x96;
    this->controller_input = &controller_input_state.controllers[0];
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (boss8_dragon_control_client_id == 0xFFFFU) {
            client_id = this->find_player_on_floor();
        } else {
            client_id = boss8_dragon_control_client_id;
        }
    } else {
        client_id = (u16)local_client_id;
    }
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        player->start_freeze();
    }
    this->target_client_id = client_id;
}

#pragma push
void TBoss8Dragon::freeze_player_at_self() {
    TObjPlayer *player = get_player_by_client_id(this->target_client_id);
    if (player != NULL) {
        if (player->get_floor() == get_current_floor()) {
            player->start_freeze();
            player->protection.set_frames(0x14);
            player->actorFlags = player->actorFlags & 0xFFEFFFDF;
            VecCopy(&player->position, &this->position);
            player->position.y = player->position.y - 200.0f;
            player->rotation_y = this->rotation_y;
            return;
        }
    }
    TBoss8Dragon::clear_player_control();
}

#pragma pop
void TBoss8Dragon::release_grabbed_player() {
    s32 pick_next;
    u16 client_id;
    TObjPlayer *player = get_player_by_client_id(this->target_client_id);
    if (player != NULL) {
        player->end_camera_pan();
        player->actorFlags = player->actorFlags & 0xFDFFFFFF;
        player->protection.reset_lobby_model();
        player->position.y = 0.0f;
        client_id = this->target_client_id;
        if ((client_id == local_client_id) && ((s16) this->mode == 0x15)) {
            send_6x2F_change_player_hp(0xFFFF, client_id, 0);
        }
    }
    this->player_controlled = 0;
    if ((s16) this->mode != 0x15) {
        pick_next = 0;
        if (this->is_primary_sequence() != 0) {
            this->sequenceCursor = 0;
            switch (this->mode) {
            case 24:
            case 25:
                pick_next = 1;
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
            case 26:
            case 27:
                pick_next = 1;
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
            case 24:
            case 25:
                pick_next = 1;
                this->sequenceCursor = 0;
                break;
            case 3:
            case 4:
                this->sequenceCursor = 0;
                break;
            case 5:
                this->sequenceCursor = 1;
                break;
            case 26:
            case 27:
                pick_next = 1;
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
            case 37:
            case 38:
                pick_next = 1;
                this->sequenceCursor = 9;
                break;
            case 9:
                this->sequenceCursor = 0;
                break;
            }
            this->sequenceCursor = (this->sequenceCursor + 0x32);
        }
        if (pick_next != 0) {
            this->pick_next_action();
        }
    }
}

#pragma push
#pragma fp_contract on
f32 TBoss8Dragon::clamp_step_in_radius(f32 a, f32 b, f32 s) {
    Vec v;
    v.x = a * s + this->position.x;
    v.y = 0.0f;
    v.z = b * s + this->position.z;
    if (vec3_dot(&v, &v) > 28900.0f) {
        s = 0.0f;
    }
    return s;
}

#pragma pop
s32 TBoss8Dragon::check_attack_ready() {
    u8 ready;

    ready = 0;
    if (((s32) this->controlTimer >= 0x96) && (this->mask_flags(this->controller_input->pressed_buttons, 0x400) != 0)) {
        ready = 1;
    }
    return (u8) ready;
}

s32 TBoss8Dragon::check_can_attack() {
    u8 ready;

    ready = 0;
    if ((this->mask_flags(this->controller_input->pressed_buttons, 0x400) != 0) && (is_secondary_sequence() != 0)) {
        ready = 1;
    }
    return ready;
}

void TBoss8Dragon::calc_velocity_from_angle() {
    this->position.x = (f32) (330.0f * sin_table_lookup(this->facingAngle));
    this->position.z = (f32) (330.0f * cos_table_lookup(this->facingAngle));
}

s32 TBoss8Dragon::mask_flags(s32 input_flags, s32 mask) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if ((player == NULL) || (player->is_controls_locked() != 0)) {
        input_flags &= 0xFFFCF9F9;
    }
    return input_flags & mask;
}

void TBoss8Dragon::dispatch_action(u32 action, s32 event) {
    static void (TBoss8Dragon::*handlers[44])(s32) = {
        &TBoss8Dragon::update_idle_state,
        &TBoss8Dragon::update_stand_state,
        &TBoss8Dragon::update_walking_state,
        &TBoss8Dragon::state_breath_attack,
        &TBoss8Dragon::handle_tail_attack_state,
        &TBoss8Dragon::update_lift_state,
        &TBoss8Dragon::state_turn_and_charge,
        &TBoss8Dragon::update_air_fire_state,
        &TBoss8Dragon::update_fall_state,
        &TBoss8Dragon::update_head_down_attack_state,
        &TBoss8Dragon::update_fall_state,
        &TBoss8Dragon::update_fall_state,
        &TBoss8Dragon::update_fall_state,
        &TBoss8Dragon::update_stretch_state,
        &TBoss8Dragon::state_roar,
        &TBoss8Dragon::update_dive_state,
        &TBoss8Dragon::update_burrow_first_run,
        &TBoss8Dragon::update_burrow_repeat_run,
        &TBoss8Dragon::update_burrow_outward_run,
        &TBoss8Dragon::handle_leap_state,
        0,
        &TBoss8Dragon::update_death_state,
        &TBoss8Dragon::update_fade_state,
        &TBoss8Dragon::update_fade_out_state,
        &TBoss8Dragon::update_controlled_stand_state,
        &TBoss8Dragon::update_controlled_walk_state,
        &TBoss8Dragon::update_controlled_hover_state,
        &TBoss8Dragon::update_controlled_flight_state,
        &TBoss8Dragon::update_controlled_burrow_state,
        &TBoss8Dragon::handle_walk_state,
        &TBoss8Dragon::update_appearance_state,
        &TBoss8Dragon::wait_for_players,
        &TBoss8Dragon::update_wander_state,
        0,
        0,
        &TBoss8Dragon::update_spinning_projectile_attack,
        &TBoss8Dragon::handle_spiral_state,
        &TBoss8Dragon::state_circle_flight,
        &TBoss8Dragon::handle_fall_state,
        &TBoss8Dragon::update_vanish_walk_state,
        &TBoss8Dragon::update_appear_walk_state,
        &TBoss8Dragon::update_vanish_lift_state,
        &TBoss8Dragon::update_appear_fall_state,
        &TBoss8Dragon::update_parts_burrow_state,
    };
    if (handlers[action]) {
        (this->*handlers[action])(event);
    }
}

f32 boss8_dragon_fall_accel = 5.0f * lbl_805D9E80;

CurvePathPoint boss8_dragon_bezier_points[4] = {
    {{0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 280.0f, 0.0f}, 0.0f},
    {{0.0f, 190.0f, 0.0f}, 0.0f},
    {{0.0f, 180.0f, 0.0f}, 0.0f},
};
CurvePathPoint boss8_dragon_bezier_points_3[3] = {
    {{0.0f, 180.0f, 0.0f}, 0.0f},
    {{0.0f, 500.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 0.0f},
};
CurvePathPoint TBoss8Dragon__dive_height_curve[3] = {
    {{0.0f, 180.0f, 0.0f}, 0.0f},
    {{0.0f, 900.0f, 0.0f}, 0.0f},
    {{0.0f, -400.0f, 0.0f}, 0.0f},
};
void TBoss8Dragon::update_idle_state(s32 event) {
    switch (event) {
    case 4:
        this->select_freeze_target();
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->player_controlled != 0) {
            send_action_packet(0x18);
            return;
        }
        this->pick_next_action();
    default:
        return;
    }
}

void TBoss8Dragon::update_stand_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->stateStep = 0;
        if (this->flags & 0x40) {
            this->try_spawn_trap();
        } else {
            this->play_effect_sound(0x4003AD00);
        }
        break;
    case 2:
    case 11:
        if (this->mask_flags(this->controller_input->pressed_buttons, 4) != 0) {
            send_action_packet(3);
        } else if (this->mask_flags(this->controller_input->pressed_buttons, 0x400) != 0) {
            send_action_packet(5);
        } else if (this->controller_input->stick_magnitude > 0.1f) {
            send_action_packet(0x19);
        }
        break;
    case 0:
        this->stateStep++;
        this->advance_animation();
        break;
    }
}

void TBoss8Dragon::update_walking_state(s32 event) {
    f32 speed_param;
    s32 step;
    s32 done;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        this->stateStep = 0;
        speed_param = boss8_dragon_behavior_params[0]->values[4];
        this->fallVelocity = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * speed_param), speed_param));
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        step = this->stateStep;
        done = 0;
        if ((step >= 0x96) && (this->current_target != NULL)) {
            if (this->destination_distance < this->fallVelocity) {
                done = 1;
            } else if (this->is_near_target() != 0) {
                done = 1;
            } else if ((s32) this->stateStep >= 0x258) {
                done = 1;
            }
        } else if (step >= 0x12C) {
            done = 1;
        }
        if (done != 0) {
            this->pick_next_action();
        }
        return;
    case 8:
        this->try_spawn_trap();
        this->update_linked_position();
        this->stateStep = (this->stateStep + 1);
        if ((s32) (this->stateStep % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
            } else {
                this->set_target_destination(&boss8_dragon_arena_center);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss8_dragon_arena_center);
        }
        this->save_position();
        return;
    case 0:
        this->update_movement();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::state_breath_attack(s32 event) {
    ParticleAngles rot;
    switch (event) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 2;
        this->action_frames = 0;
        this->breath_particles[0] = 0;
        this->breath_particles[1] = 0;
        this->breath_particles[2] = 0;
        return;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            send_action_packet(0x18);
        }
        return;
    case 9:
        if (this->stateStep == 3) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        if (enemy_validate_retained_target(this) != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->destination.x = 115.0f * sin_table_lookup(this->rotation_y) + this->breath_origin.x;
            this->destination.y = this->position.y;
            this->destination.z = 115.0f * cos_table_lookup(this->rotation_y) + this->breath_origin.z;
        }
        this->save_position();
        return;
    case 0:
        this->advance_animation();
        this->try_spawn_trap();
        switch (this->stateStep) {
        case 0:
            this->update_velocity();
            calc_target_vector();
            this->rotation_y = approach_angle_limited(this->rotation_y, (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)), 0xA0);
            this->rotation_y = (s16)this->rotation_y;
            if (this->get_flag_b4() != 0) {
                this->requested_action = 5;
                this->stateStep = 1;
            }
            break;
        case 1:
            this->action_frames++;
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
            } else if (!(this->motion_flags & 4)) {
                this->spawn_trap(0x4003AD0D);
                direction_to_rotation_xz((u8 *)&breath_direction, &rot.x, &rot.z);
                this->impactAge++;
                if (this->impactAge >= 2) {
                    new TBoss8DragonEffBreath(&sub_tasks, &breath_origin, &breath_direction, attack_kind, ((TObjBase *)this)->get_entity_id());
                    this->impactAge = 0;
                }
                if (this->breath_particles[0] == 0) {
                    this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&breath_origin, &rot, this->particle_ids[5], 0x40);
                    if (this->breath_particles[0] != 0) {
                        this->breath_particles[0]->enable();
                    }
                } else {
                    this->breath_particles[0]->set_position((u8 *)&breath_effect_position);
                    this->breath_particles[0]->set_direction(&rot);
                }
                if (this->breath_particles[1] == 0) {
                    if (this->particle_ids[6] != -1) {
                        this->breath_particles[1] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&breath_origin, &rot, this->particle_ids[6], 0x40);
                    }
                    if (this->breath_particles[1] != 0) {
                        this->breath_particles[1]->enable();
                    }
                } else {
                    this->breath_particles[1]->set_position((u8 *)&breath_effect_position);
                    this->breath_particles[1]->set_direction(&rot);
                }
                if (this->breath_particles[2] == 0) {
                    this->breath_particles[2] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&breath_origin, &rot, this->particle_ids[7], 0x40);
                    if (this->breath_particles[2] != 0) {
                        this->breath_particles[2]->enable();
                    }
                } else {
                    this->breath_particles[2]->set_position((u8 *)&breath_effect_position);
                    this->breath_particles[2]->set_direction(&rot);
                }
            }
            break;
        case 2:
            this->impactAge++;
            if (this->impactAge < 0x1E) {
                this->spawn_trap(0x4003AD0D);
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 3;
            }
            break;
        }
        break;
    case 5:
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
    }
}

#pragma pop
void TBoss8Dragon::handle_tail_attack_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 7;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x34;
        this->flags |= 2;
        this->stateStep = 0;
        this->tail->enable();
        break;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        this->advance_animation();
        (this->stateStep)++;
        if (this->is_passing_frame(0.0f) != 0 || this->is_passing_frame(12.0f) != 0) {
            this->play_effect_sound(0x4003AD09);
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

void TBoss8Dragon::update_vanish_lift_state(s32 event) {
    s32 i;
    switch (event) {
    case 4:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.08f);
        }
        this->flags |= 0x100;
        update_lift_state(event);
        break;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (this->is_any_fade_visible() == 0) {
            this->pick_next_action();
        }
        break;
    case 9:
        if (this->is_any_fade_visible() == 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 4; i++) {
                this->renderFadeStates[i].decay_value_toward_floor();
            }
            break;
        }
        update_lift_state(event);
        break;
    case 5:
        this->flags &= ~0x100;
        update_lift_state(event);
        break;
    default:
        update_lift_state(event);
        break;
    }
}

void TBoss8Dragon::update_lift_state(s32 event) {
    Vec point;

    switch (event) {
    case 4:
        this->requested_action = 0xF;
        this->advance_animation();
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (this->impactAge >= 0x28) {
            send_action_packet(0x1A);
        }
        return;
    case 9:
        if (this->impactAge >= 0x28) {
            this->pick_next_action();
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(14.0f) != 0) {
            this->play_effect_sound(0x4003A804);
        }
        if (this->is_passing_frame(42.0f) != 0) {
            this->play_effect_sound(0x4003A803);
        }
        if (this->is_passing_frame(46.0f) != 0) {
            this->spawn_ground_effect();
        }
        switch (this->stateStep) {
        case 0:
            if (this->is_passing_frame(35.0f) != 0) {
                this->flags |= 0x30;
                this->set_state();
                this->stateStep = 1;
                this->impactAge = 0;
                return;
            }
            break;
        case 1:
            this->impactAge++;
            eval_bezier_curve(boss8_dragon_bezier_points, 4, 0, &point, (f32)this->impactAge / 40.0f);
            this->position.y = point.y;
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::state_turn_and_charge(s32 event) {
    s32 diff;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->update_velocity();
        init_acceleration_curve(&this->curve0, (f32)(0.1f), (f32)(-0.1f), (f32)this->destination_distance, (f32)(2.0f + boss8_dragon_behavior_params[0]->values[5]));
        diff = angle_diff_s16(this->rotation_y, (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)));
        if (diff >= 0) {
            this->airTurnDirection = 1;
        } else {
            diff = -diff;
            this->airTurnDirection = -1;
        }
        init_acceleration_curve(&this->curve1, (f32)(16.0f), (f32)(-16.0f), (f32)((f32)diff), (f32)(s32)(256.0f * (2.0f + boss8_dragon_behavior_params[0]->values[5])));
        this->action_angle = this->rotation_y;
        this->stateStep = 0;
        this->fallVelocity = 0.0f;
        break;
    case 2:
        send_action_packet(26);
        break;
    case 11:
        if (this->stateStep == 2) {
            send_action_packet(15);
        }
        break;
    case 9:
        if (this->stateStep == 2) {
            this->pick_next_action();
        }
        break;
    case 7:
        this->sync_target_pos();
        break;
    case 6:
        this->prepare_flight_destination(&this->destination);
        this->save_position();
        break;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        update_flap_effect();
        switch (this->stateStep) {
        case 0:
            this->fallVelocity += 1.0f;
            this->rotation_y = (s32)((f32)this->airTurnDirection * sample_acceleration_curve(&this->curve1, this->fallVelocity) + (f32)this->action_angle);
            if (this->curve1.check_param_threshold(this->fallVelocity) != 0) {
                this->fallVelocity = 0.0f;
                this->stateStep = 1;
            }
            break;
        case 1: {
            f32 prev = sample_acceleration_curve(&this->curve0, this->fallVelocity);
            f32 dlt;
            Vec v;
            this->fallVelocity += 1.0f;
            dlt = sample_acceleration_curve(&this->curve0, this->fallVelocity) - prev;
            v.x = this->destination_direction.x * dlt;
            v.y = 0.0f;
            v.z = this->destination_direction.z * dlt;
            apply_ground_movement(&v);
            if (this->curve0.check_param_threshold(this->fallVelocity) != 0) {
                this->stateStep = 2;
            }
            break;
        }
        }
        break;
    case 5:
        VecCopy(&this->last_flight_direction, &this->destination_direction);
        break;
    }
}

void TBoss8Dragon::update_air_fire_state(s32 event) {
    Vec *d = &action_point;

    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->action_frames = 0;
        this->breath_particles[0] = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            send_action_packet(0x1A);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            this->pick_next_action();
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->select_air_fire_target(d) != 0) {
                this->action_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(d->x - this->position.x, d->z - this->position.z));
            } else {
                this->action_angle = get_random_scaled();
                d->x = 125.0f * sin_table_lookup(this->action_angle);
                d->y = 0.0f;
                d->z = 125.0f * cos_table_lookup(this->action_angle);
            }
            this->action_angle = (s16)this->action_angle;
            this->stateStep = 1;
            if (this->player_controlled != 0) {
                this->action_angle = (s16)this->rotation_y;
                VecCopy(d, &position);
                d->x += 125.0f * sin_table_lookup(this->action_angle);
                d->y = 0.0f;
                d->z += 125.0f * cos_table_lookup(this->action_angle);
                this->stateStep = 2;
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->requested_action = 0x12;
                this->flags |= 0x30;
            }
            this->set_air_turn_direction(this->rotation_y, this->action_angle);
            init_air_turn(this->action_angle);
        case 1:
            this->spawn_effect_if_in_band();
            update_flap_effect();
            if (advance_air_turn() != 0) {
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->stateStep = 2;
                this->requested_action = 0x12;
                this->flags |= 0x30;
            }
            break;
        case 2:
            if (this->is_passing_frame(2.0f) != 0) {
                this->play_effect_sound(0x4003A804);
            }
            if (this->is_passing_frame(45.0f) != 0) {
                this->play_effect_sound(0x4003AD0A);
            }
            if (this->is_passing_frame(14.0f) != 0 || this->is_passing_frame(53.0f) != 0) {
                this->spawn_ground_effect();
            }
            if (this->breath_particles[0] == 0) {
                if (this->frame >= 20.0f) {
                    this->breath_particles[0] = spawn_continuous_particle_effect_with_flags((void *)&breath_origin, this->particle_ids[8], (s32)(0x40));
                }
            } else if (this->frame <= 40.0f) {
                this->breath_particles[0]->set_position((u8 *)&breath_origin);
            } else {
                this->breath_particles[0]->queue_destruction();
                this->breath_particles[0] = 0;
            }
            if (this->is_passing_frame(47.0f) != 0) {
                Vec v;
                Vec dir;
                Vec rot;
                f32 len;
                VecCopy(&dir, (Vec *)d);
                subtract_vector(&dir, &position);
                len = normalize_vector_xz((Vec *)&dir);
                dir.y = 0.0f;
                VecCopy(&v, (Vec *)d);
                v.y = boss8_dragon_arena_center.y;
                new TBoss8DragonEffBullet(&sub_tasks, &breath_origin, &v, attack_kind, ((TObjBase *)this)->get_entity_id());
                rotate_vec_xz(&dir, &rot, 0x1000);
                VecCopy(&v, &position);
                v.x += rot.x * len;
                v.y = boss8_dragon_arena_center.y;
                v.z += rot.z * len;
                new TBoss8DragonEffBullet(&sub_tasks, &breath_origin, &v, attack_kind, ((TObjBase *)this)->get_entity_id());
                rotate_vec_xz(&dir, &rot, -0x1000);
                VecCopy(&v, &position);
                v.x += rot.x * len;
                v.y = boss8_dragon_arena_center.y;
                v.z += rot.z * len;
                new TBoss8DragonEffBullet(&sub_tasks, &breath_origin, &v, attack_kind, ((TObjBase *)this)->get_entity_id());
                spawn_particle_effect_with_flags((const Vec *)&breath_origin, this->particle_ids[9], 0x40);
                this->stateStep = 3;
                this->action_frames = 0;
                this->flags &= ~0x30;
            }
            break;
        case 3:
            this->action_frames++;
            if (this->action_frames > 10) {
                this->impactAge++;
                if (this->impactAge >= 2) {
                    this->stateStep = 4;
                } else {
                    this->stateStep = 0;
                }
            }
            break;
        }
        break;
    case 5:
        if (this->breath_particles[0] != 0) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        break;
    }
}

void TBoss8Dragon::update_spinning_projectile_attack(s32 event) {
    s32 found;
    Vec pos;
    TObjPlayer *player;
    f32 step;

    switch (event) {
    case 4:
        this->requested_action = 0x19;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags |= 0x30;
        this->flags &= ~0x6;
        this->stateStep = 0;
        this->impactAge = 0;
        this->action_frames = 0;
        this->action_angle = 0;
        this->fallVelocity = 13.0f;
        break;
    case 2:
    case 11:
        send_action_packet(0x1A);
        break;
    case 9:
        if (this->stateStep == 6) {
            this->pick_next_action();
        }
        break;
    case 7:
        {
            u32 seed = (u32)(s32)(100.0f * this->savedX);
            s32 low = (s32)(100.0f * this->savedZ);
            seed *= 0x10000UL;
            seed |= (u32)low & 0xFFFFUL;
            subtractive_rng_seed(this->randomState, seed);
        }
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->advance_animation();
            if (this->is_passing_frame(39.0f) != 0) {
                this->stateStep = 1;
                this->play_effect_sound(0x4003B210);
            }
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 22.0f) {
                this->rotation_x = (s32)(-16384.0f * ((this->frame - 22.0f) / (this->frame_count - 22.0f)));
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
        case 3:
            this->action_angle += 0x40;
            if (this->action_angle > 0x2000) {
                this->action_angle = 0x2000;
            }
            this->impactAge++;
            if (this->impactAge >= 4) {
                this->impactAge = 0;
                this->action_frames++;
                if (this->action_frames >= 40) {
                    this->stateStep = 4;
                    this->camera_eye_raised = 0;
                }
                found = 0;
                if ((this->action_frames & 1) == 0) {
                    player = get_player_by_client_id((u16)((this->action_frames >> 1) % 4));
                    if (player->is_alive() != 0) {
                        VecCopy(&pos, &player->position);
                        pos.x += 100.0f * (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - 0.5f);
                        pos.z += 100.0f * (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - 0.5f);
                        found = 1;
                    }
                }
                if (found == 0) {
                    pos.x = 700.0f * (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - 0.5f);
                    pos.y = 0.0f;
                    pos.z = 700.0f * (calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(this->randomState)) - 0.5f);
                }
                new TBoss8DragonEffBullet(&sub_tasks, &breath_origin, &pos, this->attack_kind, ((TObjBase *)this)->get_entity_id());
            }
            this->rotation_x -= this->action_angle;
            break;
        case 4:
            this->action_angle -= 0x50;
            if (this->action_angle < 0x1300) {
                this->action_angle = 0x1300;
                this->rotation_x -= this->action_angle;
                if ((this->rotation_x & 0xFFFF) <= 0x1300 || (this->rotation_x & 0xFFFF) >= 0xED00) {
                    this->rotation_x = 0;
                    this->action_spin = (s32)(RADIANS_TO_ANGLE * atan2_float(-this->position.x, -this->position.z));
                    this->stateStep = 5;
                }
            } else {
                this->rotation_x -= this->action_angle;
            }
            break;
        case 5:
            this->advance_animation();
            step = (f32)angle_diff_s16(this->rotation_y, this->action_spin);
            step *= 0.3f;
            if ((step < 512.0f && step >= -512.0f) || this->get_flag_b4() != 0) {
                this->rotation_y = this->action_spin;
                this->stateStep = 6;
            } else {
                this->rotation_y += (s32)step;
            }
            break;
        case 6:
            this->advance_animation();
            break;
        }
        if (this->stateStep == 1 || this->stateStep == 2) {
            this->fallVelocity += boss8_dragon_fall_accel;
            if (this->fallVelocity < 0.0f) {
                this->fallVelocity = 0.0f;
            }
            this->position.y += this->fallVelocity;
            if (this->position.y <= 180.0f) {
                this->position.y = 180.0f;
            }
        }
        if (this->stateStep == 3 || this->stateStep == 4 || this->stateStep == 5) {
            this->position.y -= 1.0f;
            if (this->position.y < 180.0f) {
                this->position.y = 180.0f;
            }
        }
        break;
    case 5:
        this->rotation_x = 0;
        this->enable_motion_blend();
        this->camera_eye_raised = 0;
        break;
    }
}

void TBoss8Dragon::update_appear_fall_state(s32 event) {
    Vec v;
    s32 ang;
    f32 c;
    s32 i;
    CsnHit *hit;
    switch (event) {
    case 4:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.008f);
        }
        this->flags = (s32) (this->flags | 0x100);
        update_fall_state(event);
        this->play_effect_sound(0x4003A814);
        return;
    case 7:
        move_to_on_ground(&this->position);
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss8_dragon_arena_center);
        }
        c = sin_table_lookup((s32)(ang = (s32) (65536.0f * (0.000030517578f * (f32) rand()))));
        v.x = boss8_dragon_behavior_params[2]->values[3] * c + this->destination.x;
        v.y = 30.0f;
        v.z = boss8_dragon_behavior_params[2]->values[3] * cos_table_lookup(ang) + this->destination.z;
        hit = csnVecterUnder(&v, 0x16EF);
        if ((hit != NULL) && (hit->contact->point.y <= 30.0f)) {
            this->destination.x = v.x;
            this->destination.z = v.z;
        }
        this->save_position();
        return;
    case 0:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].advance_toward_max();
        }
        update_fall_state(event);
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        update_fall_state(event);
        return;
    case 11:
    default:
        update_fall_state(event);
        return;
    }
}

#pragma pop
void TBoss8Dragon::update_fall_state(s32 event) {
    Vec out;

    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags |= 0x36;
        this->stateStep = 0;
        this->fallVelocity = 0.0f;
        this->impactAge = 0;
        break;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            switch (this->mode) {
            default:
            case 8:
                this->pick_next_action();
                break;
            case 10:
                send_action_packet(9);
                break;
            case 11:
                send_action_packet(0xD);
                break;
            case 12:
                send_action_packet(0x15);
                break;
            }
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            eval_bezier_curve(boss8_dragon_bezier_points_3, 3, 0, &out,
                this->get_motion_frame() / 50.0f);
            this->position.y = out.y;
            if (this->is_passing_frame(2.0f) != 0) {
                this->play_effect_sound(0x4003A804);
            }
            if (this->is_passing_frame(11.0f) != 0) {
                this->spawn_ground_effect();
            }
            if (this->is_passing_frame(50.0f) != 0) {
                fill_value_array(this->attack_history);
                create_boss8_piller_ctrl(&position, (((TObjBase *)this)->get_entity_id()), 100.0f);
                spawn_particle_effect_with_flags(&position, this->particle_ids[2], 0x40);
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
                this->play_effect_sound(0x4003AD0E);
                TCameraCtrl::set_shake_preset(1);
                apply_landing_attack();
                this->reset_timer();
                this->set_active_flag();
                this->stateStep = 1;
            }
            break;
        case 1:
            break;
        }
        break;
    case 5:
        this->set_active_flag();
        break;
    }
}

void TBoss8Dragon::update_head_down_attack_state(s32 event) {
    f32 step_scale;
    f32 dir_x;
    f32 dir_z;
    f32 anim_frame;
    switch (event) {
    case 4:
        this->requested_action = 8;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0x16);
        this->flags = this->flags & 0xFFFFFFDF;
        this->stateStep = 0;
        this->impactAge = 0;
        this->play_effect_sound(0x4003AD06);
        return;
    case 11:
        if (((s32) this->stateStep >= 0x96) && (this->mask_flags(this->controller_input->pressed_buttons, 2) != 0)) {
            this->stateStep = 0x1C2;
        }
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            send_action_packet(0x18);
        }
        return;
    case 2:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            send_action_packet(0x18);
            return;
        }
        break;
    case 9:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            remap_sequence_after_recovery();
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        switch (this->impactAge) {
        case 0:
            if (this->is_passing_frame(7.0f) != 0) {
                apply_head_fall_attack();
            } else if (this->is_passing_frame(14.0f) != 0) {
                sweep_head_fall_spheres_early();
            } else if (this->is_passing_frame(18.0f) != 0) {
                sweep_head_fall_spheres_late();
            }
            if ((s16) this->requested_action != 8) {
                this->collider->enable_blocking_bodies(&this->position, this->rotation_y);
                this->impactAge = 1;
                return;
            }
            break;
        case 1:
            this->spawn_trap(0x4003AD12);
            this->stateStep = (s32) (this->stateStep + 1);
            if ((s32) this->stateStep >= 0x1C2) {
                this->requested_action = 0xA;
                this->impactAge = 2;
                this->collider->disable_blocking_bodies();
                return;
            }
            break;
        case 2:
            step_scale = 0.9f;
            dir_x = sin_table_lookup((int) (this->rotation_y));
            dir_z = cos_table_lookup((int) (this->rotation_y));
            if ((s32) this->player_controlled != 0) {
                step_scale = this->clamp_step_in_radius(dir_x, dir_z, 0.9f);
            }
            anim_frame = this->frame;
            if ((anim_frame >= 13.0f) && (anim_frame <= 20.0f)) {
                this->move_to_shot_position(dir_x, dir_z, step_scale);
                return;
            }
            break;
        }
        break;
    case 5:
        update_damage_threshold();
        this->collider->disable_blocking_bodies();
        break;
    }
}

void TBoss8Dragon::update_stretch_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 2;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF9);
        this->set_invulnerable();
        break;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(20.0f) != 0) {
            play_cue_stream_file("draroar.adx");
        }
        break;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TBoss8Dragon::state_roar(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF9);
        play_cue_stream_file("draroar.adx");
        this->set_invulnerable();
        this->stateStep = 0;
        break;
    case 9:
        if ((s32) this->stateStep >= 0x3C) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        this->stateStep = this->stateStep + 1;
        this->spawn_effect_if_in_band();
        update_flap_effect();
        break;
    case 5:
        this->clear_invulnerable();
        break;
    case 11:
        break;
    }
}

void TBoss8Dragon::update_dive_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->ground_impact_done = 0;
        this->action_spin = 0;
        this->action_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
        this->destination_distance += 5.0f;
        init_air_turn(this->action_angle);
        if (this->destination_distance < 50.0f) {
            this->fallVelocity = this->rootHeight = this->destination_distance / 60.0f;
            this->action_speed = 0.0f;
        } else {
            f32 t;
            this->rootHeight = 1.6666666f;
            t = 2.0f * (50.0f - (this->destination_distance - 50.0f)) / 30.0f;
            this->action_speed = t / 30.0f;
            this->fallVelocity = 1.6666666f - t;
        }
        break;
    case 2:
        if (this->stateStep == 6) {
            send_action_packet(0x1C);
        }
        break;
    case 11:
        if (this->stateStep == 6) {
            send_action_packet(0x25);
        }
        break;
    case 9:
        if (this->stateStep == 6) {
            this->pick_next_action();
        }
        break;
    case 7:
        sync_target_pos();
        this->update_velocity();
        break;
    case 6:
        if (choose_burrow_ring_destination(&destination.x) == 0) {
            this->destination.x = 0.0f;
            this->destination.y = 0.0f;
            this->destination.z = 0.0f;
        }
        this->update_velocity();
        this->save_position();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            this->stateStep = 1;
        case 1:
            this->spawn_effect_if_in_band();
            update_flap_effect();
            if (advance_air_turn() != 0) {
                this->airTurnVelocity = 0;
                this->rotation_y = this->action_angle;
                this->stateStep = 2;
                this->requested_action = 0x16;
            }
            break;
        case 2:
            if (this->is_passing_frame(14.0f) != 0) {
                this->flags |= 0x30;
                this->impactAge = 0;
                this->stateStep = 3;
            }
            break;
        case 3: {
            Vec v;
            this->fallVelocity += this->action_speed;
            this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->fallVelocity);
            eval_bezier_curve(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)this->impactAge / 60.0f);
            this->position.y = v.y;
            this->impactAge++;
            if (this->is_passing_frame(39.0f) != 0) {
                this->stateStep = 4;
                this->play_effect_sound(0x4003B210);
            }
            break;
        }
        case 4:
        case 5: {
            Vec v;
            this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->rootHeight);
            this->rotation_x = approach_angle_limited(this->rotation_x, 0x4000, 0x400);
            if (this->action_spin < 0x2811) {
                this->action_spin += 0x117;
            }
            this->rotation_z += this->action_spin;
            eval_bezier_curve(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)this->impactAge / 60.0f);
            this->position.y = v.y;
            this->impactAge++;
            if (this->breath_origin.y <= boss8_dragon_arena_center.y - 50.0f && this->stateStep == 4) {
                this->stateStep = 5;
                this->play_effect_sound(0x4003AD0F);
            }
            if (this->position.y <= 0.0f && this->ground_impact_done == 0) {
                this->apply_ground_impact_attack();
                fill_value_array(this->attack_history);
                create_boss8_piller_ctrl(&position, (((TObjBase *)this)->get_entity_id()), 100.0f);
                this->ground_impact_done = 1;
                this->set_invulnerable();
                this->disable_body_collision();
                this->set_action_state();
            }
            if (this->impactAge >= 60) {
                this->stateStep = 6;
                this->flags &= ~1;
            }
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        this->rotation_x = 0;
        this->rotation_z = 0;
        break;
    case 1:
    case 3:
    case 8:
    case 10:
        break;
    }
}

void TBoss8Dragon::update_burrow_first_run(s32 event) { update_burrow_inward_run(event, 16); }

void TBoss8Dragon::update_burrow_repeat_run(s32 event) { update_burrow_inward_run(event, 17); }

#pragma push
#pragma fp_contract on
void TBoss8Dragon::update_burrow_inward_run(u32 event, s32 action) {
    s32 a;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        if (action == 0x10) {
            this->burrow_run_count = 0;
        } else {
            this->burrow_run_count++;
        }
        fill_value_array(this->attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = 0.0f;
        this->rootHeight = this->calc_step_value();
        break;
    case 2:
    case 11:
        this->send_action_packet(0x1C);
        break;
    case 9:
        if (this->lobby_state_changed != 0) {
            this->pick_next_action();
            this->lobby_state_changed = 0;
        } else if (this->stateStep == 1) {
            Vec v;
            VecCopy(&v, &this->position);
            v.y = 0.0f;
            if (normalize_vector_xz((Vec *)&v) < 50.0f) {
                this->pick_next_action();
            }
        }
        break;
    case 6:
        a = (s32)(65536.0f * this->random_ratio());
        this->position.x = 350.0f * sin_table_lookup(a);
        this->position.z = 350.0f * cos_table_lookup(a);
        this->copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 60.0f) {
                this->impactAge = 0;
                this->stateStep = 1;
                this->restore_target_pos();
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x, this->position.z)) + 0x8000;
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            break;
        case 1:
            this->fallVelocity += 0.1f;
            if (this->fallVelocity > this->rootHeight) {
                this->fallVelocity = this->rootHeight;
            }
            this->position.x = this->destination_direction.x * this->fallVelocity + this->position.x;
            this->position.z = this->destination_direction.z * this->fallVelocity + this->position.z;
            this->apply_trail_attack();
            this->impactAge++;
            if (this->impactAge > 10) {
                this->start_rumble();
                this->impactAge = 0;
            }
            break;
        }
        this->spawn_trap(0x4003AD11);
        break;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::update_burrow_outward_run(s32 event) {
    struct { f32 x, y, z; } sp8;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = this->calc_step_value();
        return;
    case 2:
    case 11:
        send_action_packet(0x1C);
        return;
    case 9:
        VecCopy((Vec *)(&sp8), &this->position);
        if (normalize_vector_xz((Vec *)&sp8) > 350.0f) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        if (this->select_target_in_front() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        } else {
            this->destination_direction.x = sin_table_lookup((int) (this->rotation_y));
            this->destination_direction.z = cos_table_lookup((int) (this->rotation_y));
        }
        this->destination.x = (350.0f * this->destination_direction.x);
        this->destination.y = 0.0f;
        this->destination.z = (f32) (350.0f * this->destination_direction.z);
        this->save_position();
        return;
    case 0:
        this->update_velocity();
        this->rotation_y = approach_angle_limited((this->rotation_y), ((s32) (RADIANS_TO_ANGLE * atan2_float((f32) (this->destination_direction.x), (f32) (this->destination_direction.z)))), 0x600);
        this->position.x = (f32) ((this->rootHeight * sin_table_lookup((int) (this->rotation_y))) + this->position.x);
        this->position.z = (f32) ((this->rootHeight * cos_table_lookup((int) (this->rotation_y))) + this->position.z);
        this->apply_trail_attack();
        this->impactAge = (s32) (this->impactAge + 1);
        if ((s32) this->impactAge > 0xA) {
            this->start_rumble();
            this->impactAge = 0;
        }
        this->spawn_trap(0x4003AD11);
        return;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::handle_spiral_state(s32 event) {
    s32 a;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        fill_value_array(attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = this->calc_step_value();
        this->fallVelocity = 2.5f * this->rootHeight;
        this->action_speed = 350.0f;
        this->action_angle = 0;
        break;
    case 2:
    case 11:
        send_action_packet(0x1C);
        break;
    case 9:
        if (this->lobby_state_changed != 0) {
            this->pick_next_action();
            this->lobby_state_changed = 0;
        } else if (this->stateStep == 2) {
            this->pick_next_action();
        }
        break;
    case 6:
        a = (s32)(65536.0f * random_ratio());
        this->position.x = 350.0f * sin_table_lookup(a);
        this->position.z = 350.0f * cos_table_lookup(a);
        copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 60.0f) {
                this->impactAge = 0;
                this->stateStep = 1;
                restore_target_pos();
                this->action_angle = (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x, this->position.z));
                return;
            }
            break;
        case 1:
            a = (s32)(RADIANS_TO_ANGLE * (this->fallVelocity / this->action_speed));
            this->action_angle += a;
            this->position.x = this->action_speed * sin_table_lookup(this->action_angle);
            this->position.z = this->action_speed * cos_table_lookup(this->action_angle);
            this->action_speed -= 0.0010681152f * (f32)a;
            if (this->action_speed < 5.0f) {
                this->stateStep = 2;
            }
            this->apply_trail_attack();
            this->impactAge++;
            if (this->impactAge > 10) {
                this->start_rumble();
                this->impactAge = 0;
            }
            this->spawn_trap(0x4003AD11);
            return;
        case 2:
            break;
        }
        break;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::handle_leap_state(s32 event) {
    Vec *d = &action_point;
    f32 v;

    switch (event) {
    case 4:
        this->requested_action = 0x18;
        this->advance_animation();
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->stateStep = 0;
        this->impactAge = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 6) {
            send_action_packet(0x1A);
        }
        break;
    case 9:
        if (this->stateStep == 6) {
            send_action_packet(8);
        }
        break;
    case 6:
        if (choose_burrow_ring_destination(&destination.x) == 0) {
            this->destination.x = 0.0f;
            this->destination.y = this->position.y;
            this->destination.z = 0.0f;
            this->update_velocity();
        }
        this->save_position();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 100.0f) {
                this->stateStep = 1;
                this->flags |= 1;
                d->x = boss8_dragon_arena_center.x - this->position.x;
                d->y = 0.0f;
                d->z = boss8_dragon_arena_center.z - this->position.z;
                v = normalize_vector_xz((Vec *)d);
                if (v > 110.0f) {
                    v = 110.0f;
                }
                if (v <= 100.0f) {
                    this->fallVelocity = 0.0f;
                    this->rotation_x = 0;
                } else {
                    f32 k = 37.333336f;
                    k += newton_sqrtf(298.6667f);
                    this->fallVelocity = v / k;
                    this->rotation_x = (s32)(RADIANS_TO_ANGLE * atan2_float(this->fallVelocity, 15.0f));
                }
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(d->x, d->z));
                this->rootHeight = 15.0f;
                d->x *= this->fallVelocity;
                d->z *= this->fallVelocity;
                f32 step = -11.333333f;
                this->position.x = d->x * step + this->position.x;
                this->position.z = d->z * step + this->position.z;
                this->position.y = -170.0f;
            }
            break;
        case 1:
            if (this->position.y > boss8_dragon_arena_center.y) {
                this->stateStep = 2;
                this->clear_invulnerable();
                this->enable_body_collision();
                this->set_state();
                this->apply_ground_impact_attack();
                fill_value_array(attack_history);
                create_boss8_piller_ctrl(&position, (this->get_entity_id()), 100.0f);
                this->play_effect_sound(0x4003AD0F);
            }
            break;
        case 2:
            if (this->position.y > 110.0f) {
                this->stateStep = 3;
            }
            break;
        case 3:
            if (this->rootHeight < 0.0f && this->position.y < 220.0f) {
                this->stateStep = 4;
                this->action_speed = this->rootHeight * this->rootHeight / 80.0f;
            }
            break;
        case 4:
            if (this->rootHeight > 0.0f) {
                this->stateStep = 5;
                this->rootHeight = 0.0f;
                this->impactAge = 0;
            }
            break;
        }
        switch (this->stateStep) {
        case 1:
            vec3_add_to(&position, d);
            this->position.y += this->rootHeight;
            break;
        case 2:
            vec3_add_to(&position, d);
            this->rootHeight += -0.4017857f;
            this->position.y += this->rootHeight;
            break;
        case 3:
            this->advance_animation();
            this->rootHeight += -0.4017857f;
            if (this->frame >= 15.0f) {
                d->x *= 0.98f;
                d->z *= 0.98f;
            }
            vec3_add_to(&position, d);
            this->position.y += this->rootHeight;
            this->rotation_x = approach_angle_limited(this->rotation_x, 0, 0x80);
            break;
        case 4:
            this->advance_animation();
            if (this->requested_action == 0x10) {
                this->spawn_effect_if_in_band();
            }
            this->rootHeight += this->action_speed;
            this->position.y += this->rootHeight;
            d->x *= 0.98f;
            d->z *= 0.98f;
            vec3_add_to(&position, d);
            break;
        case 5:
            this->advance_animation();
            this->spawn_effect_if_in_band();
            this->impactAge++;
            if (this->impactAge >= 50) {
                this->stateStep = 6;
            }
            break;
        }
        break;
    case 5:
        this->rotation_x = 0;
        break;
    }
}

#pragma pop
#pragma push
#pragma pool_data off
void TBoss8Dragon::update_death_state(s32 event) {
    CameraPlayback cam;
    ParticleAngles r;
    Vec v;

    switch (event) {
    case 4: {
        this->requested_action = 0x13;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags |= 0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = 0.0f;
        this->breath_particles[0] = 0;
        play_cue_stream_file("goldeath.adx");
        TWindowCtrl::init_all_slots();
        cam.bank = 2;
        cam.index = 0;
        cam.flags = 0;
        cam.frame = 0.0f;
        cam.frame_step = 0.5f;
        activate_camera_mode(5);
        cam.play(0x31C7);
        set_scripted_camera_origin(&position, &position, (CameraAngles *)&rotation_x);
        break;
    }
    case 2:
    case 11:
        if (this->impactAge >= 50) {
            send_action_packet(0x17);
        }
        break;
    case 9:
        if (this->impactAge >= 50) {
            send_action_packet(0x17);
        }
        break;
    case 8:
        TBoss8Dragon::update_all_parts();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->is_passing_frame(60.0f) != 0 || this->is_passing_frame(98.0f) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (this->frame >= 25.0f && this->frame < 40.0f) {
                direction_to_rotation_xz((u8 *)&breath_direction, &r.x, &r.z);
                if (this->breath_particles[0] == 0) {
                    this->breath_particles[0] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&breath_origin, &r, this->particle_ids[7], 0x40);
                }
                if (this->breath_particles[0] != 0) {
                    this->breath_particles[0]->set_position((u8 *)&breath_effect_position);
                    this->breath_particles[0]->set_direction(&r);
                }
            } else if (this->breath_particles[0] != 0) {
                this->breath_particles[0]->queue_destruction();
                this->breath_particles[0] = 0;
            }
            if (this->is_passing_frame(57.0f) != 0) {
                DragonAttackParams e = boss8_dragon_head_fall_attack_params;
                e.radius = 12.0f;
                VecCopy(&v, &boss8_dragon_death_impact_point_a);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, &position);
                reset_hp(NULL, boss8_dragon_part_hp_stats[4], NULL);
                emit_effect(&v, &e, 0);
                reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
                spawn_particle_effect_with_flags(&v, this->particle_ids[2], (s32)(0x40));
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
            }
            if (this->is_passing_frame(88.0f) != 0) {
                DragonAttackParams e = boss8_dragon_head_fall_attack_params;
                e.radius = 25.0f;
                VecCopy(&v, &boss8_dragon_death_impact_point_b);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, &position);
                reset_hp(NULL, boss8_dragon_part_hp_stats[4], NULL);
                emit_effect(&v, &e, 0);
                reset_hp(NULL, boss8_dragon_part_hp_stats[0], NULL);
                spawn_particle_effect_with_flags(&v, this->particle_ids[2], (s32)(0x40));
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
            }
            if (this->is_passing_frame(97.0f) != 0) {
                this->sweep_death_body_attack();
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 1;
                this->impactAge = 0;
            }
            break;
        case 1:
            (this->impactAge)++;
            if (this->impactAge >= 50) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x4F);
        this->actorFlags = 0x12008;
        this->sync_enemy_state(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (this->breath_particles[0] != 0) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        if (this->player_controlled != 0) {
            release_grabbed_player();
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss8Dragon::update_fade_state(s32 event) {
    f32 width;
    f32 t;

    switch (event) {
    case 4:
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0xB6);
        this->stateStep = 0;
        break;
    case 2:
    case 11:
        if ((s32) this->stateStep >= 6) {
            send_action_packet(0x17);
        }
        break;
    case 9:
        if ((s32) this->stateStep >= 6) {
            send_action_packet(0x17);
        }
        break;
    case 0:
        t = (f32) this->stateStep / 6.0f;
        width = 2.0f * (1.0f - t);
        this->scale.x = width;
        this->scale.y = (f32) (2.0f * ((3.0f * t) + 1.0f));
        this->scale.z = width;
        this->stateStep = (s32) (this->stateStep + 1);
        break;
    case 5:
        if ((s32) this->player_controlled != 0) {
            release_grabbed_player();
        }
        TObject::queue_destruction();
        break;
    }
}

#pragma pop
void TBoss8Dragon::update_fade_out_state(s32 event) {
    s32 i;
    switch (event) {
    case 4:
        this->requested_action = 0x13;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags |= 0x136;
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.005f);
        }
        break;
    case 0:
        this->advance_animation();
        for (i = 0; i < 4; i++) {
            if (this->renderFadeStates[i].decay_value_toward_floor() != 0) {
                TObject::queue_destruction();
                return;
            }
        }
        break;
    case 2:
    case 11:
        break;
    }
}

void TBoss8Dragon::update_controlled_stand_state(s32 event) {
    ControllerInputContext *input;
    u32 buttons;
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        return;
    case 11:
        input = this->controller_input;
        if (input->stick_magnitude > 0.1f) {
            send_action_packet(0x19);
            return;
        }
        if (this->mask_flags(input->pressed_buttons, 4) != 0) {
            send_action_packet(3);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, 2) != 0) {
            send_action_packet(4);
            return;
        }
        if (check_attack_ready() != 0) {
            send_action_packet(5);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, fn_8002AE08(boss8_dragon_control_client_id)) != 0) {
            send_action_packet(9);
        }
        return;
    case 2:
        input = this->controller_input;
        if (input->stick_magnitude > 0.1f) {
            send_action_packet(0x19);
            return;
        }
        buttons = input->pressed_buttons;
        if (buttons & 4) {
            send_action_packet(3);
            return;
        }
        if (buttons & 2) {
            send_action_packet(4);
            return;
        }
        if (buttons & 0x400) {
            send_action_packet(5);
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        break;
    }
}

void TBoss8Dragon::update_controlled_walk_state(s32 event) {
    s32 *p = &this->action_angle;
    ControllerInputContext *input;
    u32 buttons;
    f32 s;
    f32 c;
    f32 scale;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
        if (this->impactAge == 1) {
            send_action_packet(0x18);
            return;
        }
        buttons = this->controller_input->pressed_buttons;
        if (buttons & 4) {
            send_action_packet(3);
            return;
        }
        if (buttons & 2) {
            send_action_packet(4);
            return;
        }
        if (buttons & 0x400) {
            send_action_packet(5);
            return;
        }
        break;
    case 11:
        if (this->impactAge == 1) {
            send_action_packet(0x18);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, 4) != 0) {
            send_action_packet(3);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, 2) != 0) {
            send_action_packet(4);
            return;
        }
        if (check_attack_ready() != 0) {
            send_action_packet(5);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, fn_8002AE08(boss8_dragon_control_client_id)) != 0) {
            send_action_packet(9);
            return;
        }
        break;
    case 8:
        (this->stateStep)++;
        if (this->stateStep >= 0x1E) {
            this->stateStep = 0;
            input = this->controller_input;
            if (input->stick_magnitude <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            *p = input->stick_angle;
            this->setDestinationX(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        copySavedX(p);
        return;
    case 6:
        this->setDestinationX(this->rotation_y);
        return;
    case 0:
        this->advance_animation();
        if (this->requested_action == 1) {
            this->play_sound_if_in_band();
        }
        if (this->is_passing_frame(24.0f) != 0) {
            this->apply_foot_attack_pair_0();
        } else if (this->is_passing_frame(3.0f) != 0) {
            this->apply_foot_attack_pair_1();
        }
        this->play_speed = 0.48000002f;
        scale = 0.8f;
        if (this->frame > 4.0f && this->frame < 9.0f) {
            return;
        }
        if (this->frame > 24.0f && this->frame < 30.0f) {
            return;
        }
        this->rotation_y = approach_angle_limited(this->rotation_y, *p, 0x200);
        s = sin_table_lookup(this->rotation_y);
        c = cos_table_lookup(this->rotation_y);
        if (this->player_controlled != 0) {
            scale = this->clamp_step_in_radius(s, c, 0.8f);
        }
        this->move_to_shot_position(s, c, scale);
        break;
    }
}

void TBoss8Dragon::update_controlled_hover_state(s32 event) {
    ControllerInputContext *input;
    u32 buttons;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags = (s32) (this->flags & ~0x36);
        return;
    case 11:
        if ((this->controlTimer > 0x1C2) || (this->mask_flags(this->controller_input->pressed_buttons, 2) != 0)) {
            send_action_packet(8);
            return;
        }
        input = this->controller_input;
        if (input->stick_magnitude > 0.1f) {
            send_action_packet(0x1B);
            return;
        }
        if (this->mask_flags(input->pressed_buttons, 4) != 0) {
            send_action_packet(7);
            return;
        }
        if (this->check_can_attack() != 0) {
            send_action_packet(0xF);
        }
        return;
    case 2:
        input = this->controller_input;
        if (input->stick_magnitude > 0.1f) {
            send_action_packet(0x1B);
            return;
        }
        buttons = input->pressed_buttons;
        if (buttons & 4) {
            send_action_packet(7);
            return;
        }
        if (buttons & 2) {
            send_action_packet(0xF);
            return;
        }
        if (buttons & 0x400) {
            send_action_packet(8);
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        update_flap_effect();
        break;
    }
}

void TBoss8Dragon::update_controlled_flight_state(s32 event) {
    s32 *p = &this->action_angle;
    ControllerInputContext *input;
    u32 buttons;
    f32 s;
    f32 c;
    f32 scale;

    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0x64;
        this->impactAge = 0;
        return;
    case 11:
        if (this->controlTimer > 0x1C2 || this->mask_flags(this->controller_input->pressed_buttons, 2) != 0) {
            send_action_packet(8);
            return;
        }
        if (this->impactAge == 1) {
            send_action_packet(0x1A);
            return;
        }
        if (this->mask_flags(this->controller_input->pressed_buttons, 4) != 0) {
            send_action_packet(7);
            return;
        }
        if (this->check_can_attack() != 0) {
            send_action_packet(0xF);
        }
        return;
    case 2:
        if (this->impactAge == 1) {
            send_action_packet(0x1A);
            return;
        }
        buttons = this->controller_input->pressed_buttons;
        if (buttons & 4) {
            send_action_packet(7);
            return;
        }
        if (buttons & 2) {
            send_action_packet(0xF);
            return;
        }
        if (buttons & 0x400) {
            send_action_packet(8);
            return;
        }
        break;
    case 8:
        (this->stateStep)++;
        if (this->stateStep >= 0x1E) {
            this->stateStep = 0;
            input = this->controller_input;
            if (input->stick_magnitude <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            *p = input->stick_angle;
            this->setDestinationX(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        copySavedX(p);
        return;
    case 6:
        this->setDestinationX(*p);
        return;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        update_flap_effect();
        this->rotation_y = approach_angle_limited(this->rotation_y, *p, 0x200);
        s = sin_table_lookup(this->rotation_y);
        c = cos_table_lookup(this->rotation_y);
        scale = 2.0f;
        if (this->player_controlled != 0) {
            scale = this->clamp_step_in_radius(s, c, scale);
        }
        this->move_with_wall_stop(s, c, scale);
        break;
    }
}

void TBoss8Dragon::update_controlled_burrow_state(s32 event) {
    ControllerInputContext *input;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        break;
    case 2:
    case 11:
        input = this->controller_input;
        if (input->stick_magnitude > 0.1f) {
            send_action_packet(0x1D);
            break;
        }
        if (input->pressed_buttons & 2) {
            send_action_packet(0x13);
            break;
        }
    default:
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
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
void TBoss8Dragon::handle_walk_state(s32 event) {
    f32 dir_z;
    f32 dir_x;
    f32 moved;
    Vec *prev;
    ControllerInputContext *input;

    prev = &this->action_point;
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        VecCopy(prev, &this->position);
        this->stateStep = 0x64;
        this->impactAge = 0;
        prev->y = boss8_dragon_arena_center.y;
        this->fallVelocity = 0.0f;
        this->rootHeight = 0.0f;
        return;
    case 2:
    case 11:
        if ((s32) this->impactAge == 1) {
            send_action_packet(0x1C);
            return;
        }
        if (this->controller_input->pressed_buttons & 2) {
            send_action_packet(0x13);
        }
        return;
    case 8:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep >= 0x1E) {
            this->stateStep = 0;
            input = this->controller_input;
            if (input->stick_magnitude <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            this->rotation_y = (s32) input->stick_angle;
            this->setDestinationX(this->rotation_y);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        copySavedX(&this->rotation_y);
        return;
    case 6:
        this->setDestinationX(this->rotation_y);
        return;
    case 0:
        dir_x = sin_table_lookup(this->rotation_y);
        dir_z = cos_table_lookup(this->rotation_y);
        f32 speed = 4.0f;
        this->position.x = (f32) ((dir_x * speed) + this->position.x);
        this->position.z = (f32) ((dir_z * speed) + this->position.z);
        moved = newton_sqrtf(horizontal_distance_squared(&this->position, prev));
        VecCopy(prev, &this->position);
        this->fallVelocity = (f32) (this->fallVelocity + moved);
        break;
    }
}

#pragma pop
void TBoss8Dragon::state_circle_flight(s32 event) {
    s32 step;
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->calc_velocity_from_angle();
        return;
    case 2:
    case 11:
        if (((s32) this->stateStep >= 0x1C2) || (this->mask_flags(this->controller_input->pressed_buttons, 0x400) != 0)) {
            send_action_packet(0x26);
        }
        return;
    case 7:
        this->facingAngle = (s32) this->savedX;
        if (this->savedZ > 0.0f) {
            this->action_angle = 0x180;
            return;
        }
        this->action_angle = -0x180;
        return;
    case 6:
        this->destinationX = (f32) (65536.0f * random_ratio());
        this->destinationZ = calc_elapsed_scaled();
        return;
    case 0:
        this->facingAngle = (s32) (this->facingAngle + this->action_angle);
        if ((s32) this->action_angle >= 0) {
            this->rotation_y = (s32) (this->facingAngle + 0x9800);
        } else {
            this->rotation_y = (s32) (this->facingAngle + 0xFFFF6800);
        }
        this->calc_velocity_from_angle();
        step = this->stateStep;
        this->stateStep = (step + 1);
        this->apply_trail_attack();
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss8Dragon::handle_fall_state(s32 event) {
    f32 speed;
    f32 dir_z;
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->fallVelocity = 0.0f;
        this->destination_direction.x = (f32) -this->position.x;
        this->destination_direction.y = 0.0f;
        this->destination_direction.z = (f32) -this->position.z;
        normalize_vector_xz(&this->destination_direction);
        this->rotation_y = (s32) (RADIANS_TO_ANGLE * atan2_float((f32) (this->destination_direction.x), this->destination_direction.z));
        return;
    case 2:
    case 11:
        if (this->rootHeight >= 680.0f) {
            send_action_packet(0x13);
        }
        return;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->fallVelocity += 0.1f;
        if (this->fallVelocity > 12.0f) {
            this->fallVelocity = 12.0f;
        }
        this->rootHeight = (f32) (this->rootHeight + this->fallVelocity);
        this->position.x = (f32) ((this->destination_direction.x * this->fallVelocity) + this->position.x);
        dir_z = this->destination_direction.z;
        speed = this->fallVelocity;
        this->position.z = (f32) ((dir_z * speed) + this->position.z);
        this->apply_trail_attack();
        break;
    }
}

#pragma pop
void TBoss8Dragon::update_vanish_walk_state(s32 event) {
    f32 speed_param;
    s32 i;
    s32 j;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.02f);
        }
        this->flags = (this->flags | 0x100);
        this->stateStep = 0;
        speed_param = boss8_dragon_behavior_params[0]->values[4];
        this->fallVelocity = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * speed_param), speed_param));
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->is_any_fade_visible() == 0) {
            this->pick_next_action();
        }
        return;
    case 8:
        this->update_linked_position();
        this->stateStep = (this->stateStep + 1);
        if ((s32) (this->stateStep % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
            } else {
                this->set_target_destination(&boss8_dragon_arena_center);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss8_dragon_arena_center);
        }
        this->save_position();
        return;
    case 0:
        this->update_movement();
        for (j = 0; j < 4; j++) {
            this->renderFadeStates[j].decay_value_toward_floor();
        }
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::update_appear_walk_state(s32 event) {
    Vec v;
    f32 speed_param;
    f32 dist;
    s32 i;
    s32 j;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        move_to_on_ground(&this->destination);
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.02f);
        }
        this->flags = (s32) (this->flags | 0x100);
        speed_param = boss8_dragon_behavior_params[0]->values[4];
        this->fallVelocity = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * speed_param), speed_param));
        this->play_effect_sound(0x4003A315);
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->hasActiveRenderFade() == 0) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&boss8_dragon_arena_center);
        }
        v.x = this->destination.x - this->position.x;
        v.z = this->destination.z - this->position.z;
        if ((s32) ((u16) ((s32) (RADIANS_TO_ANGLE * atan2_float(v.x, v.z)) - this->rotation_y) + 0x2000) > 0x4000) {
            v.x = sin_table_lookup(this->rotation_y);
            v.z = cos_table_lookup(this->rotation_y);
            dist = 120.0f;
        } else {
            dist = normalize_vector_xz((Vec *)&v);
            dist *= 0.5f;
        }
        this->destination.x = (f32) ((v.x * dist) + this->position.x);
        this->destination.z = (f32) ((v.z * dist) + this->position.z);
        this->save_position();
        return;
    case 0:
        this->update_movement();
        for (j = 0; j < 4; j++) {
            this->renderFadeStates[j].advance_toward_max();
        }
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        break;
    }
}

#pragma pop
void TBoss8Dragon::update_wander_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0xB;
        this->stateStep = 0;
        return;
    case 0:
        this->stateStep = (s32) (this->stateStep + 1);
        if ((s32) this->stateStep > 0x5A) {
            this->stateStep = 0;
            this->requested_action = (s16) (this->requested_action + 1);
            if ((s16) this->requested_action >= 0x1C) {
                this->requested_action = 0;
            }
        }
        this->advance_animation();
    case 3:
    case 5:
    case 1:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss8Dragon::update_appearance_state(s32 event) {
    s32 *flag = &this->demo_flag;

    switch (event) {
    case 4: {
        this->requested_action = 0;
        this->reset_timer();
        this->advance_animation();
        this->breath_particles[0] = 0;
        this->stateStep = 0;
        this->action_frames = 0;
        this->impactAge = 0;
        *flag = 1;
        new TBoss8DragonDemo(tl_01, flag, 0.5f);
        this->requested_action = 0x1A;
        TWindowCtrl::init_all_slots();
        this->get_target_state_b();
        ((TMainCursor *)this)->update_pair();
        break;
    }
    case 2:
    case 9:
        if (this->stateStep == 1) {
            this->send_action_packet(0);
        }
        break;
    case 0:
        switch (this->stateStep) {
        case 0: {
            s32 step;
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->stateStep = 1;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 0;
            }
            switch (step = this->action_frames) {
            case 0:
                if (this->is_passing_frame(2.0f) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    this->action_frames++;
                }
                break;
            case 1:
                if (this->is_passing_frame(60.0f) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (this->is_passing_frame(63.0f) != 0) {
                    Vec v;
                    v.x = 0.5f * (this->node_positions[3].x + this->node_positions[5].x);
                    v.y = 0.0f;
                    v.z = 0.5f * (this->node_positions[3].z + this->node_positions[5].z);
                    fill_value_array(this->attack_history);
                    create_boss8_piller_ctrl(&v, (this->get_entity_id()), 100.0f);
                    spawn_particle_effect_with_flags(&this->position, this->particle_ids[2], 0x40);
                    if (this->particle_ids[3] != -1) {
                        spawn_particle_effect_with_flags(&this->position, this->particle_ids[3], 0x40);
                    }
                    this->action_frames++;
                }
                break;
            case 2:
                if (this->is_passing_frame(75.0f) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 3:
                if (this->frame > 80.0f) {
                    this->action_frames = step + 1;
                }
                break;
            case 4:
                if (this->is_passing_frame(105.0f) != 0) {
                    play_cue_stream_file("dradeath.adx");
                    this->action_frames++;
                    this->impactAge = 0;
                }
                break;
            case 5:
                if (this->frame < 150.0f) {
                    s32 rot[3];
                    direction_to_rotation_xz((u8 *)&this->breath_direction, &rot[0], &rot[2]);
                } else {
                    this->action_frames = step + 1;
                }
                break;
            }
            break;
        }
        case 1:
            this->advance_animation();
            break;
        }
        break;
    case 5:
        if (this->breath_particles[0] != 0) {
            this->breath_particles[0]->queue_destruction();
            this->breath_particles[0] = 0;
        }
        ((TMainCursor *)this)->update_cursor_pair();
        *flag = 0;
        TWindowCtrl::init_all_slots2();
        this->get_target_state_a();
        break;
    }
}

#pragma pop
void TBoss8Dragon::wait_for_players(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->stateStep = 0;
        this->position.y = 0.0f;
        return;
    case 3:
        if ((s32) this->stateStep > 0x96) {
            this->transition_enemy_state(8);
        }
        break;
    case 0:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            this->stateStep = (s32) (this->stateStep + 1);
        }
        break;
    case 5:
    case 1:
        break;
    }
}

void TBoss8Dragon::update_parts_burrow_state(s32 event) {
    s32 *p = &this->action_angle;

    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        break;
    case 2:
    case 11:
        send_action_packet(0x1C);
        break;
    case 9:
        if (TBoss8Dragon::is_any_part_alive() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        copySavedX(p);
        break;
    case 6: {
        u32 v = 4294967296.0f * (0.000030517578f * (f32)rand());
        this->setDestinationX((s32)v);
        break;
    }
    case 5:
        TBoss8Dragon::place_parts_in_ring(boss8_dragon_behavior_params[0]->ints[4], boss8_dragon_behavior_params[0]->ints[3], *p);
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::update_movement() {
    Vec old;
    Vec d;
    f32 scale;
    s32 iscale;
    f32 v;
    scale = 0.8f + boss8_dragon_behavior_params[0]->values[4];
    iscale = (s32) (320.0f * scale);
    if (this->motion_flags & 4) {
        this->play_speed = 0.125f * scale;
    } else {
        this->play_speed = 0.6f * scale;
    }
    this->advance_animation();
    this->play_sound_if_in_band();
    this->update_velocity();
    calc_target_vector();
    if (this->is_passing_frame(24.0f) != 0) {
        this->apply_foot_attack_pair_0();
    } else if (this->is_passing_frame(3.0f) != 0) {
        this->apply_foot_attack_pair_1();
    }
    VecCopy(&old, &this->position);
    v = this->frame;
    if (v < 4.0f) {
        this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
    } else if (!(v < 9.0f)) {
        if (v < 19.0f) {
            TObjEneEpsilon__sub_800B9384(this, iscale, scale);
        } else if (v < 24.0f) {
            this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
        } else if (!(v < 30.0f)) {
            TObjEneEpsilon__sub_800B9384(this, iscale, scale);
        }
    }
    d.x = this->position.x - old.x;
    d.y = this->position.y - old.y;
    d.z = this->position.z - old.z;
    VecCopy(&this->position, &old);
    this->apply_ground_movement(&d);
}

void TBoss8Dragon::move_to_on_ground(Vec *target) {
    Vec saved;
    Vec shot;
    Vec delta;
    f32 dist;
    VecCopy(&saved, &this->position);
    delta.x = target->x - (&this->position)->x;
    delta.y = 0.0f;
    delta.z = target->z - (&this->position)->z;
    dist = normalize_vector_xz((Vec *)&delta);
    this->calc_shot_position(&shot, delta.x, delta.z, dist);
    this->try_move_actor_xz_on_ground(&shot);
    (&this->position)->y = saved.y;
    if (this->is_near_other_part() != 0) {
        VecCopy(&this->position, &saved);
    }
}

void TBoss8Dragon::apply_ground_movement(Vec *step) {
    Vec c;
    Vec b;
    Vec a;
    f32 t;
    this->position.y = this->position.y + step->y;
    step->y = 0.0f;
    VecCopy(&a, &this->position);
    VecCopy(&c, step);
    t = normalize_vector_xz((Vec *)&c);
    this->calc_shot_position(&b, (f32)c.x, (f32)c.z, (f32)t);
    this->try_move_actor_xz_on_ground(&b);
    this->position.y = a.y;
    if ((this->push_apart_from_parts() != 0) && (this->is_near_other_part() != 0)) {
        VecCopy(&this->position, &a);
    }
}

#pragma push
#pragma fp_contract on
s32 TBoss8Dragon::is_sphere_visible(Vec *center, f32 radius) {
    Vec delta;
    f32 dist;
    VecCopy(&delta, center);
    delta.y = 0.0f;
    subtract_vector(&delta, &boss8_dragon_reference_pos_vec);
    dist = normalize_vector_xz(&delta);
    if ((dist + radius) < boss8_dragon_visibility_distance) {
        if (vec3_dot(&delta, &dragon_forward_reference_vec) >= (dist * (1.0f / newton_sqrtf((f32) ((dist * dist) + (radius * radius)))))) {
            return 1;
        }
    }
    return 0;
}

#pragma pop
s32 TBoss8Dragon::is_any_fade_visible() {
    for (s32 i = 0; i < 4; ++i) {
        if (renderFadeStates[i].has_visible_opacity() != 0) {
            return 1;
        }
    }
    return 0;
}

s32 TBoss8Dragon::hasActiveRenderFade() {
    for (s32 i = 0; i < 4; ++i) {
        if (renderFadeStates[i].isFading() != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss8Dragon::capture_node_points(NJS_OBJECT *) {
    s32 cursor;
    Vec *pos;
    if ((s32) boss8_dragon_capture_node == (s32) boss8_dragon_breath_node) {
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(NULL, boss8_dragon_breath_local_points, boss8_dragon_breath_points_out, 3);
        pop_matrix();
    }
    if ((s32) boss8_dragon_capture_node == boss8_dragon_capture_node_table[boss8_dragon_capture_cursor]) {
        pos = boss8_dragon_capture_points_out;
        boss8_dragon_capture_points_out = pos + 1;
        forward_transform_to_view(&boss8_dragon_node_origin, pos);
        cursor = boss8_dragon_capture_cursor + 1;
        boss8_dragon_capture_cursor = cursor;
        if ((cursor == 7) && !(boss8_dragon_capture_flags & 4)) {
            boss8_dragon_capture_cursor = 0xC;
            boss8_dragon_capture_points_out += 5;
        }
        if (((s32) boss8_dragon_capture_cursor == 0x12) && !(boss8_dragon_capture_flags & 2)) {
            boss8_dragon_capture_cursor = 0x20;
            boss8_dragon_capture_points_out += 14;
        }
    }
    boss8_dragon_capture_node += 1;
}

void TBoss8Dragon::render_body_model() {
    void *saved = this->model;
    this->model = boss8_dragon_capture_model;
    boss8_dragon_capture_node = 0;
    boss8_dragon_breath_points_out = this->breath_node_points;
    boss8_dragon_capture_cursor = 0;
    boss8_dragon_capture_points_out = this->node_positions;
    boss8_dragon_capture_flags = this->flags;
    set_chunk_model_node_callback(TBoss8Dragon::capture_node_points);
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_current_matrix(&this->scale.x);
    draw_motion((NJS_OBJECT *)this->model, this->current_motion, this->get_motion_frame());
    clear_motion_packed_rotation();
    pop_matrix();
    set_chunk_model_node_callback(NULL);
    this->model = saved;
}

void TBoss8Dragon::copy_vectors() {
    VecCopy(&this->breath_origin, &this->breath_node_points[0]);
    VecCopy(&this->breath_direction, &this->breath_node_points[1]);
    subtract_vector(&this->breath_direction, &this->breath_origin);
    VecCopy(&this->breath_effect_position, &this->breath_node_points[2]);
}

void TBoss8Dragon::render() {
    s32 view = 0;
    Vec pos;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_motion_model();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    this->get_render_position(&pos);
    if (defer_render() != 0) {
        if (!((s32)main_task.get_task_flags() & 0x10)) {
            this->render_body_model();
            this->copy_vectors();
        }
        if (this->renderFadeStates[view].isFading() == 0) {
            this->draw_with_fade(&pos, view);
        }
        this->render_nodes_flagged();
    } else if (this->renderFadeStates[view].isFading() != 0) {
        this->draw_with_fade(&pos, view);
    }
}

int TBoss8Dragon::run_demo_task() { return get_target_info(); }

void TBoss8Dragon::render_shadows() { if (TObjPlayer::check_demo_mode() == 0) { draw(); } }

void TBoss8Dragon::draw() {
    void *saved_model;

    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_current_matrix(&this->scale.x);
    saved_model = this->model;
    this->model = boss8_dragon_resource->models[2].model;
    this->TObjMotion::draw();
    this->model = saved_model;
    pop_matrix();
}

void TBoss8Dragon::draw_with_fade(Vec *pos, s32 view) {
    RenderFadeState *fade;
    if (!(this->position.y <= -400.0f)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        if (this->is_hiding_camera_target() != 0) {
            this->renderFadeStates[view].fadeOut();
        } else {
            this->renderFadeStates[view].restore();
        }
        fade = &this->renderFadeStates[view];
        if (fade->isFading() != 0) {
            fade->set_flags_and_apply_damage_color();
        }
        push_matrix();
        post_translate_matrix(&pos->x);
        rotate_matrix_y(0, this->rotation_y);
        rotate_matrix_x(0, this->rotation_x);
        rotate_matrix_z(0, this->rotation_z);
        scale_current_matrix(&this->scale.x);
        TObjPlayer::toggle_particle_effect();
        if (this->flags & 0x80) {
            set_tev_swap_channels(3, 3, 3, 3);
        }
        if (has_enough_enemies() != 0) {
            this->model = boss8_dragon_resource->models[1].model;
        } else {
            this->model = boss8_dragon_resource->models[0].model;
        }
        this->TObjMotion::draw();
        init_tev_swap();
        TParticleCtrl::end_effect_render();
        current_scene_light->sub_801337F8();
        pop_matrix();
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    }
}

void TBoss8Dragon::get_render_position(Vec *pos) {
    VecCopy(pos, &this->position);
    if (((s32)main_task.get_task_flags() & 0x10) && (this->has_appeared() == 0) && !(this->frame > 63.0f)) {
        pos->z += -460.0f;
    }
}

s32 TBoss8Dragon::is_hiding_camera_target() {
    Vec eye;
    Vec dir;
    f32 dist;
    u8 *entity;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (this->mode == 30) {
        return 0;
    }
    if (this->mode == 21) {
        return 0;
    }
    if (this->mode == 22) {
        return 0;
    }
    if (this->mode == 23) {
        return 1;
    }
    if (this->phase != 0) {
        return 0;
    }
    TCameraCtrl::get_camera_target_id(-1);
    entity = find_entity_by_id();
    if (entity == 0) {
        return 0;
    }
    VecCopy(&eye, &camera_ctrl_instance->pos);
    eye.y = 0.0f;
    VecCopy(&dir, (const Vec *)(entity + 0x38));
    subtract_vector(&dir, &eye);
    dir.y = 0.0f;
    dist = normalize_vector_xz(&dir);
    VecCopy(&boss8_dragon_reference_pos_vec, &eye);
    VecCopy(&dragon_forward_reference_vec, &dir);
    boss8_dragon_visibility_distance = dist;
    for (i = 0; i < 4; i++) {
        if (this->is_sphere_visible(&this->node_positions[boss8_dragon_point_index_table[i]], 12.0f) != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss8Dragon::render_nodes_flagged() {
    s32 render_flags;

    render_flags = model_render_flags;
    saved_model_render_flags = render_flags;
    model_render_flags = render_flags | 0x400;
    this->sub_tasks.render_nodes();
    model_render_flags = saved_model_render_flags;
}

void TBoss8Dragon::draw_motion_model() {
    f32 f;
    s32 idx;
    AnimationMotion *anim;
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
        idx = this->parameters[0];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1C) {
            idx = 0x1B;
        }
        anim = this->motion_list[this->action_table[idx].motion].motion;
        f = this->parameters[1];
        if (f < 0.0f) {
            f = 0.0f;
        } else if (f > (f32)(anim->frameCount - 1)) {
            f = anim->frameCount;
        }
        set_motion_packed_rotation();
        draw_model_motion(this->model, anim, f);
        clear_motion_packed_rotation();
        current_scene_light->sub_801337F8();
        pop_matrix();
    }
}

f32 TBoss8Dragon::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *collision, s32 tech, s32 flags) {
    switch (payload.kind) {
    case 0xB:
    case 0xC:
        return 0.0f;
    }
    return TObjChara::receive_direct_attack(attacker, payload, collision, tech, flags);
}

#pragma push
#pragma pool_data off
void TBoss8Dragon::set_mode_params(s8 mode) {
    this->effect_mode = mode;
    switch (this->effect_mode) {
    case 0:
        this->attack_kind = 1;
        this->particle_ids = boss8_dragon_mode_params;
        return;
    case 1:
        this->attack_kind = 2;
        this->particle_ids = dragon_mode_params_a;
        return;
    case 2:
        this->attack_kind = 3;
        this->particle_ids = dragon_mode_params_b;
        return;
    }
}
#pragma pop

