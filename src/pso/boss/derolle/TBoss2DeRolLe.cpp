#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/animation/MotionContext.h"

struct NJS_OBJECT;

#include "pso/math/FloatRounding.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"

#include "pso/network/protocol/protocol_types.h"

#include "pso/unk/TLobby_801E43E4.h"
#include "pso/network/protocol/protocol.h"
#include "pso/object/TObjControl.h"

#include "pso/system/NinjaTypes.h"

#include "types.h"

#include "pso/camera/CameraPlayback.h"

#include "pso/render/NinjaUtil.h"

#include "pso/system/PadRumble.h"

#include "pso/boss/DragonAttackParams.h"
#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjChara.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/derolle/TBoss2DeRolLe.h"

#include "pso/boss/derolle/TUnk_80036250.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/math/AngleLookup.h"


#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include "pso/effect/TBreakUpMdl.h"

#include "pso/unk/TUnk_80482090.h"

#include "pso/boss/derolle/TBoss2Tentacle.h"

#include "pso/object/TObjEZRopeBase.h"

#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TBoss2PhotonPad.h"
#include "pso/boss/derolle/TBoss2LaserLight.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/TUnk_80482C58.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/model_render_state.h"

#include "pso/boss/derolle/TBoss2Fin.h"

#include "pso/boss/derolle/TBoss2Joint.h"

#include "pso/boss/derolle/TBoss2Mine.h"
#include "pso/system/ControllerInput.h"

#include "pso/boss/derolle/TUnk_80482D04.h"

#include "pso/boss/derolle/TUnk_80482EC0.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2CeilJunk.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/ui/window/TWindowCtrl.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/math/AngleUnits.h"

#include "pso/system/BmlResourceDescriptor.h"

#include <stddef.h>

// The model nodes whose positions derolle_capture_node_points records into node_positions, -1 ended.
const s32 derolle_position_node_ids[21] = {
    0x18, 0x1A, 0x1C, 0x1D, 0x1E, 0x1F, 0x22, 0x45, 0x4A, 0x5F, 0x60,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, -1,
};

const Vec TBoss2DeRolLe__position_point_table[4] = {
    {-175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, 500.0f},
    {175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, -250.0f},
};

const DragonAttackParams derolle_effect_params = {0, 0.0f, 8.0f, {5.0f, 1}};

// inferred: the five mine positions load_resources grounds into TBoss2DeRolLe__mine_ground_targets
const Vec derolle_mine_offsets[5] = {
    {0.0f, 0.0f, 0.0f},
    {45.0f, 0.0f, 30.0f},
    {45.0f, 0.0f, -30.0f},
    {-45.0f, 0.0f, 30.0f},
    {-45.0f, 0.0f, -30.0f},
};

// inferred: the effect handle_laser_attack_state spawns where the laser hits
const DragonAttackParams derolle_laser_hit_effect_params = {0, 120.0f, 16.0f, {20.0f, 1}};

s32 de_rol_le_base_param_ids[1] = {0xF};

s32 de_rol_le_resistance_param_ids[1] = {0xF};

// inferred: the ids load_resources passes to TLobby::dispatch_shared_handler_a, the
// counterpart of TBoss2DeRolLe__shared_handler_id_table (dispatch_shared_handler_b)
s32 de_rol_le_shared_handler_a_ids[1] = {0xF};

// What TObjEnemy::movementParameters points at.
struct TBoss2DeRolLeMovement {
    EnemyMoveParams move;
    s32 pad_0C[4];
};

// The four points matrix_mult_vec_array places along a breakup piece (derolle_capture_node_points).
Vec derolle_part_transform_template[4] = {
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 4.0f},
    {0.0f, 0.0f, 13.0f},
};

s32 derolle_action_mode_sequence_table[44] = {
    0x1, 0x3, 0x18, 0x6, 0x11, 0x9, 0xC, 0x12, 0x14, 0x16, 0x3,
    0x6, 0x11, 0x9, 0xD, 0x19, 0x8, 0x10, 0x4, 0x13, 0x15, 0x17,
    0x9, 0xF, 0x21, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1C, 0x23,
    0x24, 0x25, 0x21, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1D, 0x2C,
};

s32 derolle_action_sequence_table[50] = {
    0x1, 0x28, 0x29, 0x2A, 0x2B, 0x22, 0xD, 0x25, 0x21, 0x28,
    0x27, 0x29, 0x2A, 0x2B, 0x27, 0x22, 0xF, 0x21, 0x28, 0x27,
    0x28, 0x27, 0x28, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
    0x1C, 0xD, 0x25, 0x21, 0x28, 0x29, 0x2A, 0x2B, 0x28, 0x22,
    0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1D, 0x2C,
};

s32 TBoss2DeRolLe__shared_handler_id_table[3] = {0xF, 0x10, 0x11};

TBoss2DeRolLeMovement boss2_derolle_movement = {{225.0f, 0.0f, 0x600}, {0, 0, 0, 0}};

CollisionBody boss2_derolle_collision_bodies[3] = {
    {{0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *bm_boss2_de_rol_le_model_names[8] = {
    "boss2_b_derorure_fin_b.nj",
    "boss2_b_derorure_fin_a.nj",
    "boss2_b_derorure_body.nj",
    "boss2_b_derorure_sting.nj",
    "boss2_b_derorure_tentacle.nj",
    "boss2_b_helm_break.nj",
    "boss2_b_shell_break.nj",
    NULL,
};

const char *bm_boss2_de_rol_le_motion_names[19] = {
    "beam02_boss2_b_body.njm",
    "beamwait_boss2_b_body.njm",
    "beam_a_boss2_b_body.njm",
    "beam_b_boss2_b_body.njm",
    "beam_c_boss2_b_body.njm",
    "bite_lloop_boss2_b_body.njm",
    "bite_rloop_boss2_b_body.njm",
    "die_boss2_b_body.njm",
    "enter_boss2_b_body.njm",
    "fd02_boss2_b_body.njm",
    "fjump_boss2_b_body.njm",
    "forward_boss2_b_body.njm",
    "lrjump_boss2_b_body.njm",
    "l_bite_boss2_b_body.njm",
    "rljump_boss2_b_body.njm",
    "r_bite_boss2_b_body.njm",
    "scatter_boss2_b_body.njm",
    "tloop_boss2_b_tentacle.njm",
    NULL,
};

BmlResourceDescriptor boss2_derolle_bml_descriptor = {
    "bm_boss2_de_rol_le.bml", bm_boss2_de_rol_le_model_names, bm_boss2_de_rol_le_motion_names, 7, 18,
};

TObjMotionAction boss2_derolle_action_table[17] = {
    {3, 0, 8, 0.8f, ACTION_NO_BLEND_IN | ACTION_NO_BLEND_OUT},
    {1, 0, 11, 0.6f, 0x0},
    {1, 0, 9, 1.0f, 0x0},
    {3, 0, 0, 0.4f, 0x0},
    {2, 1, 10, 0.3f, 0x0},
    {2, 1, 14, 0.5f, 0x0},
    {2, 1, 12, 0.5f, 0x0},
    {2, 9, 15, 0.28f, 0x0},
    {2, 10, 13, 0.28f, 0x0},
    {1, 0, 6, 2.0f, 0x0},
    {1, 0, 5, 2.0f, 0x0},
    {3, 0, 16, 0.6f, 0x0},
    {2, 15, 2, 0.4f, 0x0},
    {3, 0, 3, 0.3f, 0x0},
    {2, 1, 4, 0.4f, 0x0},
    {1, 0, 1, 0.5f, 0x0},
    {3, 0, 7, 0.7f, 0x0},
};

s32 boss2_derolle_particle_node_indices[3] = {0, 5, 9};

f32 boss2_derolle_particle_limits[3] = {32.0f, 30.0f, 30.0f};

const char *boss2_de_rol_le_class_name = "TBoss2DeRolLe";

#include <stddef.h>
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/TUnk_804A6F78.h"

player_stats *TBoss2DeRolLe__base_params[1];
ActorParamBlock *TBoss2DeRolLe__resistance_params[1];
TBoss2DeRolLeParams *derolle_params[1];
BmlResource *boss2_derolle_resource;
// derolle_capture_node_points's state while the body draws (derolle_begin_node_capture sets it up).
s32 derolle_capture_node_index;
s32 derolle_capture_position_index;
s32 derolle_capture_flags;
Vec *derolle_capture_positions;
Vec *derolle_capture_part_points;
GC_Mtx *derolle_capture_tentacle_matrices;
GC_Mtx *derolle_capture_node_matrices;
TBoss2DeRolLe *TBoss2DeRolLe__instance;
NJS_OBJECT *derolle_breakup_node;        // body node 0x4D; its children are swapped while broken up
NJS_OBJECT *derolle_breakup_node_child;  // the node's own first child



Vec TBoss2DeRolLe__mine_ground_targets[5];

u32 *boss2_derolle_primary_color_targets[3];

uaddr derolle_segment_joint_node_offsets[10];

u32 *boss2_derolle_segment_color_targets[10];

AttackParams *TBoss2DeRolLe__attack_params_table[3];
NJS_ARGB derolle_capture_color;  // the body colour while it draws (derolle_begin_node_capture)
Vec derolle_capture_origin;      // the node-local point derolle_capture_node_points places

// The hidden nodes that stand in for derolle_breakup_node's children while the body is broken up.
NJS_OBJECT derolle_breakup_stub_nodes[11];

void TBoss2DeRolLe::init_6x14(DeRolLeActionTargetPacket *packet) {
    packet->header.subcommand = 0x14;
    packet->header.size = 3;
}

void TBoss2DeRolLe::update_and_send(DeRolLeActionTargetPacket *packet) {
    swap_endian(packet);
    send_subcommand(packet);
}

void TBoss2DeRolLe::init_6x13(DeRolLeActionPacket *packet) {
    packet->header.subcommand = 0x13;
    packet->header.size = 2;
}

void TBoss2DeRolLe::send_6x13(DeRolLeActionPacket *packet) {
    swap_6x13_fields(packet);
    send_subcommand(packet);
}

void TBoss2DeRolLe::swap_6x13_fields(DeRolLeActionPacket *packet) {
    packet->header.bswap();
    bswap_16((u16 *)&packet->state);
    bswap_16((u16 *)&packet->sequence_index);
}

void TBoss2DeRolLe::swap_endian(DeRolLeActionTargetPacket *packet) {
    packet->header.bswap();
    bswap_16((u16 *)&packet->state);
    bswap_16((u16 *)&packet->sequence_index);
    bswap_32((u32 *)&packet->target_id);
}

void TBoss2DeRolLe::clear_harmful_statuses() {  }

void TBoss2DeRolLe::apply_shock_status() {  }

void TBoss2DeRolLe::apply_movement_ailment(s32) {  }

void TBoss2DeRolLe::apply_confusion_status() {  }

void TBoss2DeRolLe::apply_slow_status() {  }

void TBoss2DeRolLe::apply_paralysis() {  }

void TBoss2DeRolLe::apply_poison_status() {  }

TBoss2DeRolLe *TBoss2DeRolLe::get_instance() {
    return (TBoss2DeRolLe *)TBoss2DeRolLe__instance;
}

TUnk_80036250::TUnk_80036250() {
    init_float_block();
}

TUnk_80036250::~TUnk_80036250() {}

void TUnk_80036250::init_float_block() {
    state = 0;
    accel = 0.0f;
    decel = 0.0f;
    max_speed = 0.0f;
    speed = 0.0f;
    distance = 0.0f;
    travelled = 0.0f;
    brake_point = 0.0f;
}

void TUnk_80036250::init_params(f32 max_speed, f32 distance, f32 accel) {
    state = 0;
    this->accel = accel;
    decel = accel;
    this->max_speed = max_speed;
    speed = 0.0f;
    this->distance = distance;
    travelled = 0.0f;
    plan_profile();
}

void TUnk_80036250::set_move_params(f32 max_speed, f32 distance, f32 accel, f32 decel) {
    state = 0;
    this->accel = accel;
    this->decel = decel;
    this->max_speed = max_speed;
    speed = 0.0f;
    this->distance = distance;
    travelled = 0.0f;
    plan_profile();
}

extern "C" {

void TUnk_80036250::plan_profile() {
    f32 cur_speed = speed;
    f32 neg_decel = -decel;
    f32 speed_sq = cur_speed * cur_speed;
    f32 ramp = 1.0f / accel - 1.0f / neg_decel;
    f32 reach = distance + speed_sq / (-2.0f * neg_decel);
    f32 top;
    if ((1.0f / accel - 1.0f / neg_decel) * (0.5f * speed_sq) > reach) {
        max_speed = newton_sqrtf((2.0f * reach) / ramp);
    }
    top = max_speed;
    brake_point = distance + (0.5f * (top * top)) / neg_decel;
}

s32 TUnk_80036250::advance() {
    switch (state) {
    case 0:
        speed = speed + accel;
        if (speed > max_speed) {
            speed = max_speed;
            state = 1;
        }
        break;
    case 1:
        if (travelled > brake_point) {
            speed = speed - decel;
            state = 2;
        }
        break;
    case 2:
        speed = speed - decel;
        if (speed < 0.0f) {
            speed = 0.0f;
            state = 3;
        }
        break;
    }
    travelled = travelled + speed;
    if (travelled > distance) {
        travelled = distance;
    }
    return state;
}

void TBoss2DeRolLe::load_resources() {
    s32 k;
    s32 m2;
    s32 m3;
    BmlResource *res;
    s32 i;
    NJS_OBJECT *n;
    NJS_OBJECT *m;
    NJS_OBJECT *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        res = (BmlResource *)load_enemy_bml_resource_named(&boss2_derolle_bml_descriptor, "bm_boss2_de_rol_le_a.bml");
    } else {
        res = (BmlResource *)load_enemy_bml_resource(&boss2_derolle_bml_descriptor);
    }
    boss2_derolle_resource = res;
    derolle_capture_node_index = 0;
    derolle_capture_position_index = 0;
    derolle_capture_flags = 0;
    derolle_capture_color.a = 0.0f;
    derolle_capture_color.r = 0.0f;
    derolle_capture_color.g = 0.0f;
    derolle_capture_color.b = 0.0f;
    derolle_capture_origin.x = 0.0f;
    derolle_capture_origin.y = 0.0f;
    derolle_capture_origin.z = 0.0f;
    derolle_capture_positions = NULL;
    derolle_capture_part_points = NULL;
    derolle_capture_tentacle_matrices = NULL;
    derolle_capture_node_matrices = NULL;
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__base_params[i] = TLobby::register_boss(de_rol_le_base_param_ids[i]);
    }
    for (i = 0; i < 3; i++) {
        TBoss2DeRolLe__attack_params_table[i] = TLobby::dispatch_shared_handler_b(TBoss2DeRolLe__shared_handler_id_table[i]);
    }
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__resistance_params[i] = TLobby::register_object(de_rol_le_resistance_param_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        derolle_params[i] = (TBoss2DeRolLeParams *)TLobby::dispatch_shared_handler_a(de_rol_le_shared_handler_a_ids[i]);
    }
    TBoss2DeRolLe__instance = 0;
    TBoss2Tentacle::load_shared_model();
    TBoss2Mine::load_resources();
    for (k = 0; k < 5; k++) {
        TObjBoss2Tunnel::adjust_to_ground(&derolle_mine_offsets[k], &TBoss2DeRolLe__mine_ground_targets[k]);
    }
    TBoss2Fin::init_effect_table();
    res = boss2_derolle_resource;
    // The shell segments' material colour words (just past each chunk list's first 8 bytes).
    n = res->models[2].model->child;
    for (i = 0; i < 10; i++) {
        derolle_segment_joint_node_offsets[i] = (uaddr)(((NJS_CNK_MODEL *)n->model)->polygon_list + 4);
        boss2_derolle_segment_color_targets[i] = (u32 *)(((NJS_CNK_MODEL *)n->child->model)->polygon_list + 4);
        n = n->sibling;
    }
    boss2_derolle_primary_color_targets[0] = (u32 *)(((NJS_CNK_MODEL *)n->model)->polygon_list + 4);
    m = n->sibling;
    boss2_derolle_primary_color_targets[1] = (u32 *)(((NJS_CNK_MODEL *)m->model)->polygon_list + 4);
    boss2_derolle_primary_color_targets[2] = (u32 *)(((NJS_CNK_MODEL *)m->sibling->model)->polygon_list + 4);
    derolle_breakup_node = find_model_node(res->models[2].model, 0x4D);
    derolle_breakup_node_child = derolle_breakup_node->child;
    for (m2 = 0; m2 < 11; m2++) {
        p = &derolle_breakup_stub_nodes[m2];
        p->evalflags = NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_HIDE;
        p->model = 0;
        p->pos[0] = 0.0f;
        p->pos[1] = 0.0f;
        p->pos[2] = 0.0f;
        p->ang[0] = 0;
        p->ang[1] = 0;
        p->ang[2] = 0;
        p->scl[0] = 0.0f;
        p->scl[1] = 0.0f;
        p->scl[2] = 0.0f;
        p->child = 0;
        p->sibling = 0;
    }
    for (m3 = 0; m3 < 10; m3++) {
        derolle_breakup_stub_nodes[m3].child = &derolle_breakup_stub_nodes[m3 + 1];
    }
    p = &derolle_breakup_stub_nodes[10];
    p->evalflags = NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_HIDE | NJD_EVAL_BREAK;
    p->child = 0;
    TObjPlayer::create_breakup_model();
    TObjPlayer::create_derolle_breakup_model();
    TWindowCtrl::init_all_slots();
}

void *TBoss2DeRolLe::create(void *set_data) {
    return new TBoss2DeRolLe(tl_04, set_data);
}

void TBoss2DeRolLe::reset_parts() {
    TObjPlayer::clear_target_ref();
    TObjPlayer::free_breakup_model();
    TBoss2Fin::release_effect_table();
    TBoss2Mine::free_resources();
    TBoss2Tentacle::release_shared_model();
    if (boss2_derolle_resource != NULL) {
        delete boss2_derolle_resource;
        boss2_derolle_resource = NULL;
    }
}

}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

TBoss2DeRolLe::TBoss2DeRolLe(TObject *parent, void *set_data) : TObjEneDD_ST(parent), part_group(NULL) {
    u16 id;
    s32 set;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    m_name = boss2_de_rol_le_class_name;
    if (TBoss2DeRolLe__instance == NULL) {
        TBoss2DeRolLe__instance = this;
    }
    invoke_initialization_hook(set_data);
    state_flags = 0;
    {
        // exchange_object_state copies the object's whole 12-byte lobby record
        u32 flags[3];
        if (exchange_object_state(flags, 1) != 0 && (flags[0] & 0x12008) == 0x12008) {
            state_flags |= 0x8000;
        }
    }
    init_position_vectors();
    model = boss2_derolle_resource->models[2].model;
    texlist = boss2_derolle_resource->models[2].texlist;
    init_model(boss2_derolle_collision_bodies, 3);
    motion_flags = 0;
    set_action_table(boss2_derolle_action_table);
    set_motion_list(boss2_derolle_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(TBoss2DeRolLe__base_params[0], TBoss2DeRolLe__attack_params_table[0], TBoss2DeRolLe__resistance_params[0]);
    set_state_flag_2();
    movementParameters = &boss2_derolle_movement;
    initialize_enemy_state(0x2D);
    wall_reach = 20.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    stat_phase = 0;
    pad_3D0 = 0;
    action_index = 0;
    for (i = 0; i < 20; i++) {
        node_positions[i].x = 0.0f;
        node_positions[i].y = 0.0f;
        node_positions[i].z = 0.0f;
    }
    for (i = 0; i < 4; i++) {
        part_points[i].x = 0.0f;
        part_points[i].y = 0.0f;
        part_points[i].z = 0.0f;
    }
    tentacle_matrices = (GC_Mtx *)mem_alloc(4 * sizeof(GC_Mtx));
    for (i = 0; i < 4; i++) {
        set_matrix_identity((u8 *)tentacle_matrices[i]);
        tentacles[i] = new TBoss2Tentacle(&part_group, tentacle_matrices[i], i);
    }
    Vec v = {10000.0f, 10000.0f, 10000.0f};
    id = entity_id + 1;
    set = set_index + 1;
    for (j = 0; j < 10; j++) {
        VecCopy(&joint_positions[j], &v);
        pad_5B8[j] = -1;
        joints[j] = new TBoss2Joint(this, id++, set++, &joint_positions[j], derolle_segment_joint_node_offsets[j], (saddr)boss2_derolle_segment_color_targets[j]);
    }
    for (i = 0; i < 5; i++) {
        mines[i] = new TUnk_80482EC0(&part_group, id++, set++);
    }
    for (i = 0; i < 3; i++) {
        target_mines[i] = new TUnk_80482D04(&part_group, id++, set++);
    }
    fin = new TBoss2Fin(&part_group, &node_positions[1], &node_positions[10]);
    position_index = 0;
    next_position_index = 0;
    travel_step_zx = 0;
    travel_step_xz = 0;
    motion_x.init_float_block();
    motion_z.init_float_block();
    height_offset = 0.0f;
    body_max_hp = body_hp = derolle_params[0]->body_hp;
    shell_hp = derolle_params[0]->shell_hp;
    hpmax = hp = 20000;
    photon_pad_level = 0;
    laser_light = new TBoss2LaserLight(&part_group, &laser_light_pos);
    laser_light_pos.x = 0.0f;
    laser_light_pos.y = 0.0f;
    laser_light_pos.z = 0.0f;
    attack_history = new AreaAttackHistory(4);
    fill_value_array(attack_history);
    hit_trail = NULL;
    hit_trail_long = NULL;
    pulse_phase = 1.0f;
    pulse_speed = 0.1f;
    for (k = 0; k < 3; k++) {
        VecCopy(&sound_origins[k], &position);
    }
    loop_sound_frames = 0;
    body_color.a = 1.0f;
    body_color.r = 1.0f;
    body_color.g = 1.0f;
    body_color.b = 1.0f;
    node_matrices = (GC_Mtx *)mem_alloc(12 * sizeof(GC_Mtx));
    for (i = 0; i < 12; i++) {
        set_matrix_identity((u8 *)node_matrices[i]);
    }
    for (m = 0; m < 6; m++) {
        splash_ctrls[m] = NULL;
    }
    splash_joint = 0;
    laser_shot_count = 0;
    state_step = 0;
    state_ints[0] = 0;
    state_ints[1] = 0;
    state_ints[2] = 0;
    state_ints[3] = 0;
    state_ints[4] = 0;
    state_ints[5] = 0;
    state_floats[0] = 0.0f;
    state_floats[1] = 0.0f;
    state_floats[2] = 0.0f;
    state_floats[3] = 0.0f;
    state_floats[4] = 0.0f;
    state_floats[5] = 0.0f;
    state_floats[6] = 0.0f;
    state_floats[7] = 0.0f;
    state_floats[8] = 0.0f;
    state_floats[9] = 0.0f;
    state_vectors[0].x = 0.0f;
    state_vectors[0].y = 0.0f;
    state_vectors[0].z = 0.0f;
    state_vectors[1].x = 0.0f;
    state_vectors[1].y = 0.0f;
    state_vectors[1].z = 0.0f;
    state_emitter = NULL;
    debug_pad_active = 0;
    debug_pad = &controller_input_state.controllers[1];
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (update_lobby_state() != 0) {
            run_mode = 0;
        } else {
            run_mode = 1;
        }
    } else {
        run_mode = 0;
    }
    reset_action_sequence();
    if (!(state_flags & 0x8000)) {
        mode = 1;
        dispatch_action(mode, 4);
    }
}

#pragma pop

TBoss2DeRolLe::~TBoss2DeRolLe() {
    s32 i;
    if (state_emitter != NULL) {
        state_emitter->queue_destruction();
        state_emitter = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (splash_ctrls[i] != NULL) {
            splash_ctrls[i]->queue_destruction();
            splash_ctrls[i] = NULL;
        }
    }
    mem_free(node_matrices);
    node_matrices = NULL;
    if (hit_trail != NULL) {
        hit_trail->queue_destruction();
        hit_trail = NULL;
    }
    if (hit_trail_long != NULL) {
        hit_trail_long->queue_destruction();
        hit_trail_long = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (laser_light != NULL) {
        laser_light->queue_destruction();
        laser_light = NULL;
    }
    if (fin != NULL) {
        fin->queue_destruction();
        fin = NULL;
    }
    for (i = 2; i >= 0; i--) {
        target_mines[i]->queue_destruction();
        target_mines[i] = NULL;
    }
    for (i = 4; i >= 0; i--) {
        mines[i]->queue_destruction();
        mines[i] = NULL;
    }
    for (i = 9; i >= 0; i--) {
        joints[i]->queue_destruction();
        joints[i] = NULL;
    }
    for (i = 3; i >= 0; i--) {
        tentacles[i]->queue_destruction();
        tentacles[i] = NULL;
    }
    mem_free(tentacle_matrices);
    free_collision_body_parts(this);
    if (TBoss2DeRolLe__instance == this) {
        TBoss2DeRolLe__instance = NULL;
    }
}

extern "C" {

void TBoss2DeRolLe::run_task() {
  s32 teammate_state;
  s32 flags;
  if (get_target_info() != 0)
  {
    vfunc_105();
    return;
  }
  flags = state_flags;
  if (flags & 0x8000)
  {
    send_entity_set_flags();
    queue_destruction();
    return;
  }
  if (flags & 0x80)
  {
    state_flags = flags & ~0x80;
    state_flags |= 0x40;
    new TUnk_80482090(this, node_matrices[0]);
  }
  if ((TObjEneDD::is_main_phase_15() != 0) && (debug_pad_active == 0))
  {
    if (update_lobby_state() != 0)
    {
      run_mode = 0;
    }
    else
    {
      run_mode = 1;
    }
  }
  if ((debug_pad_active != 0) && (debug_pad->pressed_buttons & 0x10000))
  {
    switch (run_mode)
    {
      case 1:
        run_mode = 0;
        advance_action_sequence();
        break;
      case 0:
        run_mode = 2;
        break;
      case 2:
        run_mode = 1;
        break;
    }
  }
  teammate_state = TObjEneDD::query_teammate_state();
  update_attack_stat_status();
  update_defense_stat_status();
  if (teammate_state == 0)
  {
    if (mode == 0x1F || mode == 0x20 || mode == 0x1E)
    {
      actorFlags |= 0x800;
    }
    else
    {
      actorFlags &= ~0x800;
    }
    if (run_mode != 1)
    {
      if (run_mode == 2)
      {
        if (is_ready() != 0)
        {
          start_death_sequence();
        }
        else
        {
          dispatch_action(mode, 2);
        }
      }
      else
      {
        update_or_dispatch();
      }
      if (test_flag30_512() != 0)
      {
        run_hit_reaction();
      }
      dispatch_action(mode, 8);
      dispatch_action(mode, 0);
    }
    else
    {
      if (test_flag30_512() != 0)
      {
        run_hit_reaction();
      }
      dispatch_action(mode, 0);
    }
    advance_phase_wrap();
    update_projectile_spawns();
  }
  sub_800BBA0C();
  update_body_colliders();
  backup_pos();
  submit_default_cursor_candidate();
  add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 2.0f);
  update_particle_ctrls();
  if (teammate_state == 0)
  {
    part_group.run_tasks();
  }
}

}

void TBoss2DeRolLe::update_or_dispatch() {
    if (is_ready() != 0) {
        start_death_sequence();
        return;
    }
    dispatch_action(mode, 9);
}

extern "C" {

void TBoss2DeRolLe::refresh_target() {  }

void TBoss2DeRolLe::run_death_reaction() {  }

}

extern "C" {

void TBoss2DeRolLe::run_hit_reaction() {
    s32 damage;
    damage = hpmax - hp;
    if (state_flags & 8) {
        body_hp = body_hp - damage;
        spawn_offset_particle(&bodies->center, 2.0f, 8.0f);
        play_sound(0x4003A80F, &sound_origins[0]);
    } else {
        shell_hp = shell_hp - damage;
        if (shell_hp < 0) {
            shell_hp = 0;
            set_flags_play_sound();
        }
    }
    hp = hpmax;
    clear_attack_receipts();
}

void TBoss2DeRolLe::run_miss_reaction() {  }

void TBoss2DeRolLe::backup_pos() {
    VecCopy(&body_center, &position);
    VecCopy(&center, &body_center);
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::update_body_colliders() {
    Vec offsets[3];
    VecCopy(&offsets[0], &node_positions[6]);
    VecCopy(&offsets[1], &part_points[2]);
    VecCopy(&offsets[2], &part_points[3]);
    update_local_colliders_from_world(this, offsets);
}

#pragma pop

}

void TBoss2DeRolLe::set_state_and_send(s32 state) {
    DeRolLeActionTargetPacket target_packet;
    DeRolLeActionPacket packet;
    dispatch_action(state, 6);
    if (state == 0x19 || (state - 0x14) <= 1U || state == 0x1B) {
        init_6x14(&target_packet);
        target_packet.header.client_id = entity_id;
        target_packet.state = state;
        target_packet.sequence_index = action_index;
        target_packet.target_id = target_id;
        update_and_send(&target_packet);
        return;
    }
    init_6x13(&packet);
    packet.header.client_id = entity_id;
    packet.state = state;
    packet.sequence_index = action_index;
    send_6x13(&packet);
}

void TBoss2DeRolLe::reload_stats_for_phase(s32 kind) {
    s32 a;
    s32 i;
    s32 b;
    switch (kind) {
    case 0:
    default:
        a = 0;
        i = 0;
        b = 0;
        break;
    case 1:
        a = 0;
        i = 1;
        b = 0;
        break;
    case 2:
        a = 0;
        i = 2;
        b = 0;
        break;
    }
    reload_stats_keep_hp_tp(TBoss2DeRolLe__base_params[a], TBoss2DeRolLe__attack_params_table[i], TBoss2DeRolLe__resistance_params[b]);
}

extern "C" {

// A ceiling junk piece that lands on a player (TObjBoss2CeilJunk) hits it through the boss.
void TBoss2DeRolLe::forward_switch_phase_stats(TObjChara *victim) {
    if (TBoss2DeRolLe__instance != NULL) {
        TBoss2DeRolLe__instance->switch_phase_stats(victim);
    }
}

// Hits victim with the phase-1 attack stats, then restores the running phase's stats.
void TBoss2DeRolLe::switch_phase_stats(TObjChara *victim) {
    if (victim->bodies != NULL) {
        victim->bodies->flags |= 0x04000000;
        reload_stats_for_phase(1);
        victim->receive_physical_attack(this, 1.0f);
        reload_stats_for_phase(stat_phase);
    }
}

// A tentacle's strike (TBoss2Tentacle) emits its effect at pos with the phase-2 stats.
void TBoss2DeRolLe::emit_effect_and_step(Vec *pos) {
    reload_stats_for_phase(2);
    TObjEneDD::emit_effect(this, pos, &derolle_effect_params);
    reload_stats_for_phase(stat_phase);
}

f32 TBoss2DeRolLe::get_bullet_power() {
    return derolle_params[0]->bullet_power;
}

f32 TBoss2DeRolLe::get_mine_power() {
    return derolle_params[0]->mine_power;
}

s32 TBoss2DeRolLe::get_shell_max_hp() {
    return derolle_params[0]->shell_max_hp;
}

}

void TBoss2DeRolLe::set_position_index(s32 index) {
    VecCopy(&position, &TBoss2DeRolLe__position_point_table[index]);
    height_offset = 0.0f;
    rotation_z = 0;
}

#pragma push
#pragma opt_common_subs off

void TBoss2DeRolLe::set_move_target_point(s32 index) {
    VecCopy(&destination, &TBoss2DeRolLe__position_point_table[index]);
    VecCopy(&destination_direction, &destination);
    subtract_vector(&destination_direction, &position);
    destination_distance = normalize_vector_xz(&destination_direction);
}

#pragma pop

// Puts the body at the side of position_index it swims out from (the TBoss7DeRolLeC twin is
// set_swim_direction); the callers pass position_index, which it reads itself.
void TBoss2DeRolLe::set_move_direction(s32) {
    if (position_index == 0) {
        position.x = -100.0f;
        rotation_z = 0x500;
    } else {
        position.x = 100.0f;
        rotation_z = -0x500;
    }
    position.z = 10.0f;
    height_offset = 4.0f;
}

// The height of the model's root node in the current motion frame (body scale 2).
f32 TBoss2DeRolLe::calc_node_height() {
    Vec v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    bind_motion_context(current_motion, frame);
    compose_motion_node_matrix(model);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

// Where the model's root node sits in the current motion frame (body scale 2).
void TBoss2DeRolLe::get_node_world_pos(Vec *out) {
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    push_matrix();
    set_matrix_identity(0);
    Vec scale = {2.0f, 2.0f, 2.0f};
    scale_current_matrix(&scale.x);
    bind_motion_context(current_motion, frame);
    compose_motion_node_matrix(model);
    matrix_mult_vec(0, out, out);
    pop_matrix();
}

void TBoss2DeRolLe::update_angle() {
    if (height_offset > 0.4f) {
        height_offset -= 0.4f;
        return;
    }
    if (height_offset < -0.4f) {
        height_offset += 0.4f;
        return;
    }
    height_offset = 0.0f;
}

void TBoss2DeRolLe::init_head_params() {
    travel_step_zx = 0;
    motion_x.init_params(3.0f, fabs_float(-position.x), 0.08f);
    motion_z.init_params(5.0f, fabs_float(500.0f - position.z), 0.08f);
}

#pragma push
#pragma opt_common_subs off

s32 TBoss2DeRolLe::update_phase_is_done() {
    motion_z.advance();
    switch (travel_step_zx) {
    case 0:
        if (motion_z.travelled > 380.0f) {
            travel_step_zx = 1;
        }
        break;
    case 1:
        if (motion_x.advance() == 3) {
            travel_step_zx = 2;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    return travel_step_zx == 2;
}

#pragma pop

void TBoss2DeRolLe::init_movement() {
    travel_step_xz = 0;
    motion_x.init_params(3.0f, fabs_float(-175.0f - position.x), 0.08f);
    motion_z.set_move_params(7.0f, fabs_float(25.0f - position.z), 0.2f, 0.05f);
}

s32 TBoss2DeRolLe::update_phase_settling() {
    motion_x.advance();
    switch (travel_step_xz) {
    case 0:
        if (motion_x.travelled > 160.0f) {
            travel_step_xz = 2;
        }
        break;
    case 2:
        play_speed = 0.3f;
        travel_step_xz = 3;
        break;
    case 3:
        if (motion_z.advance() == 3) {
            travel_step_xz = 4;
        }
        if (motion_z.travelled > 200.0f) {
            play_speed += 0.1f;
            if (play_speed > 0.9f) {
                play_speed = 0.9f;
            }
        }
        break;
    }
    return travel_step_xz == 4;
}

void TBoss2DeRolLe::init_move_params() {
    travel_step_zx = 0;
    motion_x.init_params(3.0f, fabs_float(-position.x), 0.08f);
    motion_z.set_move_params(7.0f, fabs_float(-250.0f - position.z), 0.2f, 0.05f);
}

s32 TBoss2DeRolLe::update_state() {

    motion_z.advance();
    switch (travel_step_zx) {
    case 0:
        play_speed = 0.3f;
        if (motion_z.travelled > 100.0f) {
            travel_step_zx = 1;
        }
        break;
    case 1:
        if (motion_x.advance() == 3) {
            travel_step_zx = 2;
        }
        break;
    }
    if (motion_z.travelled > 100.0f) {
        play_speed = 0.9f;
    }
    return travel_step_zx == 2;
}

void TBoss2DeRolLe::init_wave_params() {
    travel_step_xz = 1;
    motion_x.init_params(3.0f, fabs_float(-175.0f - position.x), 0.08f);
    motion_z.init_params(5.0f, fabs_float(25.0f - position.z), 0.08f);
}

s32 TBoss2DeRolLe::update_phase_rising() {
    f32 speed;
    motion_x.advance();
    switch (travel_step_xz) {
    case 2:
        break;
    case 1:
        speed = motion_z.speed - 0.1f;
        if (speed < -4.0f) {
            speed = -4.0f;
        }
        motion_z.speed = speed;
        motion_z.travelled = motion_z.travelled + speed;
        if (motion_x.travelled > 30.0f) {
            travel_step_xz = 3;
        }
        break;
    case 3:
        if (motion_z.advance() == 3) {
            travel_step_xz = 4;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    return travel_step_xz == 4;
}

void TBoss2DeRolLe::spawn_photon_pad(s32 joint, s32 level) {
    Vec dir;
    s32 ang;
    ang = 0x3800 - joint * 0x33;
    dir.x = sin_table_lookup(ang);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(ang);
    if (position_index == 2) {
        dir.x *= -1.0f;
    }
    new TBoss2PhotonPad(&part_group, &joint_positions[joint], &dir, level);
    play_sound_effect(0x4003B708, &joint_positions[joint], 0, 1);
    joints[joint]->start_pad_flash();
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::calc_offset_position() {
    VecCopy(&laser_light_pos, &part_points[0]);
    laser_light_pos.x = 30.0f * part_points[1].x + laser_light_pos.x;
    laser_light_pos.y = 30.0f * part_points[1].y + laser_light_pos.y;
    laser_light_pos.z = 30.0f * part_points[1].z + laser_light_pos.z;
}

#pragma pop

void TBoss2DeRolLe::activate_laser_light() {
    if (laser_light != NULL) {
        laser_light->turn_on();
    }
    state_flags |= 0x10;
}

void TBoss2DeRolLe::free_laser() {
    if (laser_light != NULL) {
        laser_light->turn_off();
    }
    state_flags &= ~0x10;
}

void TBoss2DeRolLe::pick_random_target() {
    s32 n;
    TObjPlayer *player;
    s32 j;
    s32 i;

    n = TLobby::get_game_mode();
    if (n == 0) {
        enemy_clear_target();
        return;
    }
    if (n == 1) {
        player = TObjPlayer::get_player_data(0);
        set_target_player(player);
        return;
    }
    j = (s32)floor_to_float((f32)n * random_ratio());
    enemy_clear_target();
    for (i = 0; i < n; i++) {
        player = TObjPlayer::get_player_data(j);
        if (player->is_alive() != 0) {
            set_target_player(player);
            return;
        }
        if (++j >= n) {
            j = 0;
        }
    }
}

void TBoss2DeRolLe::set_all_intangible() {
    s32 i;
    set_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->set_intangible();
    }
}

void TBoss2DeRolLe::clear_all_intangible() {
    s32 i;
    clear_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->clear_intangible();
    }
}

extern "C" {

void TBoss2DeRolLe::enable_body_collision() {
    TObjEneDD::enable_body_collision();
    if ((state_flags & 8) || TObjEneDD::check_v2_mode() != 0) {
        clear_play_flags();
    }
}

}

void TBoss2DeRolLe::apply_hp_damage_with_sound(s32 damage, u16) {
    body_hp = body_hp - (s32)(0.5f * damage);
    play_sound(0x4003A80F, &position);
}

void TBoss2DeRolLe::set_flags_play_sound() {
    state_flags |= 0x88;
    clear_play_flags();
    play_sound(0x4003AA06, &position);
}

void TBoss2DeRolLe::clear_play_flags() {
    bodies[1].flags &= ~1;
    bodies[2].flags &= ~1;
}

s32 TBoss2DeRolLe::is_ready() {
    int ready;

    ready = 0;
    if (body_hp <= 0 && !(state_flags & 4)) {
        ready = 1;
    }
    return (u8)ready;
}

void TBoss2DeRolLe::start_death_sequence() {
    s16 st = mode;
    if (st != 0x1f && st != 0x20) {
        if (st == 0x14 || st == 0x15) {
            advance_action_sequence();
        } else if (st == 0x16 || st == 0x17) {
            set_state_and_send(0x1f);
        } else {
            set_state_and_send(0x1e);
        }
    }
}

extern "C" {

void handle_6x13_de_rol_le_boss_actions(void *data) {
    DeRolLeActionPacket *packet = (DeRolLeActionPacket *)data;
    TBoss2DeRolLe *boss;
    TBoss2DeRolLe::swap_6x13_fields(packet);
    boss = (TBoss2DeRolLe *)get_enemy_entity(packet->header.client_id);
    if (boss != NULL) {
        boss->init_from_param(packet);
    }
}

void handle_6x14_de_rol_le_boss_actions_with_target(void *data) {
    DeRolLeActionTargetPacket *packet = (DeRolLeActionTargetPacket *)data;
    TBoss2DeRolLe *boss;
    TBoss2DeRolLe::swap_endian(packet);
    boss = (TBoss2DeRolLe *)get_enemy_entity(packet->header.client_id);
    if (boss != NULL) {
        boss->set_params(packet);
    }
}

void TBoss2DeRolLe::init_from_param(DeRolLeActionPacket *packet) {
    action_index = packet->sequence_index;
    transition_enemy_state(packet->state);
}

void TBoss2DeRolLe::set_params(DeRolLeActionTargetPacket *packet) {
    enemy_set_target_id(this, packet->target_id);
    action_index = packet->sequence_index;
    transition_enemy_state(packet->state);
}

void TBoss2DeRolLe::reset_action_sequence() {
    pad_3D0 = 0;
    action_index = 0;
}

}



void TBoss2DeRolLe::advance_action_sequence() {
    s32 retry;
    s32 mode;
    do {
        retry = 0;
        action_index++;
        if (TObjEneDD::check_v2_mode() != 0) {
            mode = derolle_action_sequence_table[action_index];
        } else {
            mode = derolle_action_mode_sequence_table[action_index];
        }
        switch (mode) {
        case 33:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 8;
            } else {
                mode = 6;
            }
            break;
        case 34:
            if (next_position_index == 0) {
                mode = 5;
            } else {
                mode = 9;
            }
            break;
        case 35:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 0xC;
            } else {
                mode = 0xE;
            }
            break;
        case 36:
            if (next_position_index == 0) {
                mode = 3;
            } else {
                mode = 0xB;
            }
            break;
        case 37:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 0x18;
            } else {
                mode = 0x19;
            }
            break;
        case 39:
            if (next_position_index == 0) {
                mode = 4;
            } else {
                mode = 0xA;
            }
            break;
        case 40:
            if (next_position_index == 0) {
                mode = 0x10;
            } else {
                mode = 0x11;
            }
            break;
        case 41:
            if (next_position_index == 0) {
                mode = 0x12;
            } else {
                mode = 0x13;
            }
            break;
        case 42:
            if (next_position_index == 0) {
                mode = 0x14;
            } else {
                mode = 0x15;
            }
            break;
        case 43:
            if (next_position_index == 0) {
                mode = 0x16;
            } else {
                mode = 0x17;
            }
            break;
        case 44:
            retry = 1;
            action_index = 5;
            break;
        }
    } while (retry != 0);
    set_state_and_send(mode);
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::update_particle_ctrls() {
    Vec t;
    s32 ang[3];
    s32 ok;
    s32 j;
    s32 i;
    s32 k;
    void *p;
    s32 m;
    s32 n;
    ok = 1;
    for (i = 0; i < 6; i++) {
        if (splash_ctrls[i] == NULL) {
            ang[2] = 0;
            ang[1] = 0;
            ang[0] = 0;
            p = create_particle_controller_with_angles(joint_positions, ang, 0x120, 1, 0x40);
            if (p != NULL) {
                splash_ctrls[i] = (TParticleCtrl *)p;
                splash_ctrls[i]->set_flags(2);
                splash_ctrls[i]->enable();
            } else {
                for (j = 0; j < i; j++) {
                    splash_ctrls[j]->enable();
                }
                ok = 0;
                break;
            }
        }
    }
    if (ok != 0) {
        if (splash_joint == 0) {
            for (k = 0; k < 3; k++) {
                Vec *v = &joint_positions[boss2_derolle_particle_node_indices[k]];
                f32 r = fabs_float(v->y - -10.0f);
                f32 lim = boss2_derolle_particle_limits[k];
                if (r < 0.9f * lim) {
                    VecCopy(&t, v);
                    lim -= r;
                    t.y = -5.0f;
                    t.x += lim;
                    splash_ctrls[k * 2]->set_position(&t);
                    t.x -= 2.0f * lim;
                    splash_ctrls[k * 2 + 1]->set_position(&t);
                } else {
                    splash_ctrls[k * 2]->enable();
                    splash_ctrls[k * 2 + 1]->enable();
                }
            }
        } else {
            VecCopy(&t, &joint_positions[splash_joint]);
            t.y = -5.0f;
            t.x += 20.0f;
            splash_ctrls[0]->set_position(&t);
            t.x -= 40.0f;
            splash_ctrls[1]->set_position(&t);
            for (m = 2; m < 6; m++) {
                splash_ctrls[m]->enable();
            }
            splash_joint = 0;
        }
        for (n = 0; n < 6; n++) {
            release_splash_particles(splash_ctrls[n]);
        }
    }
}

#pragma pop

void TBoss2DeRolLe::release_splash_particles(TParticleCtrl *ctrl) {
    TObjBoss2Tunnel::release_splash_children(ctrl);
}

void TBoss2DeRolLe::spawn_ceil_junk(Vec *pos) {
    TObjBoss2CeilJunk::create_particle(pos, 0x121);
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::spawn_offset_particle(Vec *position, f32 height, f32 distance) {
    Vec pos;
    VecCopy(&pos, position);
    pos.x = -((ninja_camera.vx * distance) - pos.x);
    pos.y -= (ninja_camera.vy * distance) - height;
    pos.z = -((ninja_camera.vz * distance) - pos.z);
    spawn_particle_effect_with_flags(&pos, 0x127, 0x40);
}

#pragma pop

void TBoss2DeRolLe::update_projectile_spawns() {
    Vec *mid;

    project_sound_origin_from_camera(&position, &sound_origins[0], 0.3f);
    project_sound_origin_from_camera(&node_positions[18], &sound_origins[1], 0.3f);
    mid = &sound_origins[2];
    VecCopy(mid, &sound_origins[1]);
    vec3_add_to(mid, &sound_origins[1]);
    mid->x *= 0.5f;
    mid->y *= 0.5f;
    mid->z *= 0.5f;
    if ((state_flags & 0x100) && ((is_passing_frame(3.0f) != 0) || (is_passing_frame(20.0f) != 0))) {
        loop_sound_frames = 0;
    }
    if (loop_sound_frames <= 0x10) {
        play_persistent_sound(0x4003AD00, this, &sound_origins[2], 0, 0);
        loop_sound_frames = loop_sound_frames + 1;
    }
}

void TBoss2DeRolLe::sub_800338BC() {  }

extern "C" s32 play_sound(s32 id, Vec *position) {
    return play_sound_effect(id, position, 0, 0);
}

s32 TBoss2DeRolLe::spawn_trap(s32 id, void *owner, Vec *pos) {
    return play_persistent_sound(id, owner, pos, 0, 0);
}

#pragma push
#pragma opt_common_subs off

void TBoss2DeRolLe::advance_phase_wrap() {
    f32 phase;
    pulse_phase = pulse_phase + pulse_speed;
    phase = pulse_phase;
    if (phase >= 2.0f) {
        pulse_phase = phase - 2.0f;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on

#define SWAP_COLOR_HALVES(x) ((((x) & 0xFF00) << 16) | ((x) >> 16) | (((x) & 0xFF) << 16))

// SWAP_COLOR_HALVES swaps the two halfwords of a packed colour (0xAARRGGBB -> 0xGGBBAARR)
// The runtime's float to unsigned conversion, called directly here.
extern "C" u32 __cvt_fp2unsigned(f32);

void TBoss2DeRolLe::update_pulsing_colors() {
    s32 i;
    f32 t;
    u8 v;
    u32 c;
    f32 ph;
    t = pulse_phase;
    if (t > 1.0f) {
        t = 2.0f - t;
    }
    v = __cvt_fp2unsigned(255.0f * (0.9f * t + 0.1f));
    c = 0xFF000000;
    c |= v << 16;
    c |= v >> 2;
    *boss2_derolle_primary_color_targets[2] = *boss2_derolle_primary_color_targets[0] = SWAP_COLOR_HALVES(c);
    c = 0xFF000000;
    c |= v << 16;
    c |= v << 8;
    *boss2_derolle_primary_color_targets[1] = SWAP_COLOR_HALVES(c);
    ph = pulse_phase;
    for (i = 0; i < 10; i++) {
        ph += 0.2f;
        if (ph > 2.0f) {
            ph -= 2.0f;
        }
        t = ph;
        if (ph > 1.0f) {
            t = 2.0f - ph;
        }
        v = __cvt_fp2unsigned(255.0f * (0.9f * t + 0.1f));
        c = 0xFF000000;
        c |= v << 16;
        c |= v << 8;
        *boss2_derolle_segment_color_targets[i] = SWAP_COLOR_HALVES(c);
    }
}

#pragma pop

#undef SWAP_COLOR_HALVES

extern "C" {

void TBoss2DeRolLe::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_opening_state(reason);
        return;
    case 1:
        handle_intro_camera_state(reason);
        return;
    case 2:
        handle_debug_pad_input(reason);
        return;
    case 3:
        handle_position_travel_state(reason, 0, 1);
        return;
    case 4:
        handle_side_jump_state(reason, 0, 2);
        return;
    case 5:
        handle_position_travel_state(reason, 0, 3);
        return;
    case 6:
        handle_position_travel_state(reason, 1, 2);
        return;
    case 8:
        handle_position_travel_state(reason, 1, 0);
        return;
    case 9:
        handle_position_travel_state(reason, 2, 3);
        return;
    case 10:
        handle_side_jump_state(reason, 2, 0);
        return;
    case 11:
        handle_position_travel_state(reason, 2, 1);
        return;
    case 12:
        handle_position_travel_state(reason, 3, 0);
        return;
    case 13:
        handle_forward_jump_state(reason);
        return;
    case 14:
        handle_position_travel_state(reason, 3, 2);
        return;
    case 18:
        handle_bite_state(reason, 0);
        return;
    case 19:
        handle_bite_state(reason, 2);
        return;
    case 20:
        handle_tentacle_volley_state(reason, 0);
        return;
    case 21:
        handle_tentacle_volley_state(reason, 2);
        return;
    case 22:
        handle_roll_dive_state(reason, 0);
        return;
    case 23:
        handle_roll_dive_state(reason, 2);
        return;
    case 16:
        state_photon_pads(reason, 0);
        return;
    case 17:
        state_photon_pads(reason, 2);
        return;
    case 15:
        handle_ceiling_pass_state(reason);
        return;
    case 24:
        state_launch_mines(reason, 0x18);
        return;
    case 25:
        state_launch_mines(reason, 0x19);
        return;
    case 26:
        state_ceiling_attack(reason);
        return;
    case 27:
        handle_laser_attack_state(reason);
        return;
    case 28:
        handle_surface_state(reason, 0);
        return;
    case 29:
        handle_surface_state(reason, 1);
        return;
    case 30:
        handle_deep_sink_state(reason);
        return;
    case 31:
        handle_death_state(reason);
        return;
    case 32:
        handle_despawn_state(reason);
    default:
        return;
    }
}

}

void TBoss2DeRolLe::handle_opening_state(u32 reason) {
    switch (reason) {
    case 4: requested_action = 1; return;
    case 2: set_state_and_send(1); return;
    case 0: advance_animation(); return;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::handle_intro_camera_state(u32 reason) {
    Vec *p = &state_vectors[0];
    CameraPlayback cam;
    CameraPlayback cam2;
    Vec v1;
    Vec v2;
    Vec v3;
    f32 t;
    switch (reason) {
    case 4:
        requested_action = 0;
        set_all_intangible();
        state_flags &= ~4;
        state_flags &= ~0x100;
        position.x = 70.0f;
        height_offset = 0.0f;
        rotation_z = 0;
        state_step = 1;
        state_ints[0] = 0;
        state_ints[1] = 0;
        state_floats[0] = 0.0f;
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
        if (TObjEneDD::check_v2_mode() != 0) {
            cam.index = 1;
            cam.bank = 1;
            cam.flags = 0;
            cam.frame = 0.0f;
            cam.frame_step = 0.8f;
            activate_camera_mode(5);
            cam.play(0x1C71);
        } else {
            cam2.index = 0;
            cam2.bank = 1;
            cam2.flags = 0;
            cam2.frame = 0.0f;
            cam2.frame_step = 0.8f;
            activate_camera_mode(5);
            cam2.play(0x1C71);
        }
        TWindowCtrl::init_all_slots();
        get_target_state_b();
        break;
    case 2:
        if (state_step == 5) {
            position_index = 0;
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 5) {
            position_index = 0;
            advance_action_sequence();
        }
        break;
    case 0:
        if (state_step == 2) {
            requested_action = 1;
            vec3_add_to(&position, p);
            set_move_target_point(0);
            state_step = 3;
        }
        advance_animation();
        switch (state_step) {
        case 0:
            state_ints[1]++;
            if (state_ints[1] >= 0x37) {
                state_ints[1] = 0;
                state_step = 1;
                position.x = 0.0f;
                position.y = 7.0f;
                position.z = -190.0f;
                height_offset = 0.0f;
                rotation_z = 0;
            }
            break;
        case 1:
            get_node_world_pos(p);
            state_ints[0]++;
            t = frame;
            if (t >= 34.0f && t <= 42.0f) {
                if ((f32)state_ints[0] >= 3.0f) {
                    state_ints[0] = 0;
                    VecCopy(&v1, &position);
                    vec3_add_to(&v1, p);
                    v1.x += 30.0f * calc_elapsed_scaled();
                    v1.y = -5.0f;
                    v1.z += 70.0f;
                    spawn_ceil_junk(&v1);
                }
            } else if (t >= 64.0f && t <= 72.0f) {
                if ((f32)state_ints[0] >= 2.0f) {
                    state_ints[0] = 0;
                    VecCopy(&v2, &position);
                    vec3_add_to(&v2, p);
                    v2.x += 40.0f * calc_elapsed_scaled();
                    v2.y = -5.0f;
                    v2.z += 40.0f;
                    spawn_ceil_junk(&v2);
                }
            } else if (t >= 110.0f && t <= 120.0f && (f32)state_ints[0] >= 2.0f) {
                state_ints[0] = 0;
                VecCopy(&v3, &position);
                vec3_add_to(&v3, p);
                v3.x += 30.0f * calc_elapsed_scaled();
                v3.y = -5.0f;
                v3.z += 70.0f;
                spawn_ceil_junk(&v3);
            }
            if (is_passing_frame(35.0f) != 0 || is_passing_frame(112.0f) != 0) {
                play_sound_effect(0x4003AD11, 0, 0, 0);
            } else if (is_passing_frame(65.0f) != 0) {
                play_sound_effect(0x4003AD12, 0, 0, 0);
            }
            if (frame >= 34.0f) {
                position.x -= 1.0f;
            } else if (frame >= 18.0f) {
                position.x -= 5.0f;
            }
            if (get_flag_b4() != 0) {
                state_step = 2;
                state_flags |= 0x100;
            }
            break;
        case 2:
            break;
        case 3:
            position.x = 3.0f * destination_direction.x + position.x;
            position.z = 3.0f * destination_direction.z + position.z;
            state_floats[0] += 3.0f;
            if (state_floats[0] >= destination_distance) {
                state_step = 4;
            }
            break;
        case 4:
            if (get_scripted_camera_playback()->flags & CameraPlayback::FLAG_DONE) {
                restore_player_cameras();
                state_step = 5;
            }
            break;
        }
        break;
    case 5:
        restore_player_cameras();
        TWindowCtrl::init_all_slots2();
        get_target_state_a();
        break;
    }
}

#pragma pop

#undef arg0

void TBoss2DeRolLe::handle_debug_pad_input(u32 reason) {
    u32 b;

    switch (reason) {
    case 4:
        requested_action = 1;
        clear_all_intangible();
        state_flags &= ~4;
        state_flags |= 0x100;
        height_offset = 0.0f;
        rotation_z = 0;
        state_ints[0] = 1;
        state_ints[1] = 0;
        state_step = 0;
        break;
    case 2:
        switch (position_index) {
        case 0:
            b = debug_pad->pressed_buttons;
            if (b & 0x10) {
                set_state_and_send(3);
            } else if (b & 0x40) {
                set_state_and_send(4);
            } else if (b & 0x20) {
                set_state_and_send(5);
            } else if (b & 0x400) {
                set_state_and_send(0x12);
            } else if (b & 4) {
                set_state_and_send(0x10);
            } else if (b & 2) {
                position.z = -210.0f;
                set_state_and_send(1);
            }
            break;
        case 1:
            b = debug_pad->pressed_buttons;
            if (b & 0x40) {
                set_state_and_send(6);
            } else if (b & 0x20) {
            } else if (b & 0x80) {
                set_state_and_send(8);
            } else if (b & 0x400) {
                set_state_and_send(0x18);
            } else if (b & 4) {
                set_state_and_send(0x19);
            } else if (b & 2) {
                set_state_and_send(0x1E);
            }
            break;
        case 2:
            b = debug_pad->pressed_buttons;
            if (b & 0x20) {
                set_state_and_send(9);
            } else if (b & 0x80) {
                set_state_and_send(0xA);
            } else if (b & 0x10) {
                set_state_and_send(0xB);
            } else if (b & 0x400) {
                set_state_and_send(0x13);
            } else if (b & 4) {
                set_state_and_send(0x11);
            } else if (b & 2) {
                set_state_and_send(0x1E);
            }
            break;
        case 3:
            b = debug_pad->pressed_buttons;
            if (b & 0x80) {
                set_state_and_send(0xC);
            } else if (b & 0x10) {
                set_state_and_send(0xD);
            } else if (b & 0x40) {
                set_state_and_send(0xE);
            } else if (b & 0x400) {
                set_state_and_send(0xF);
            } else if (b & 4) {
                set_state_and_send(0x1A);
            } else if (b & 0x200) {
                if (TObjBoss2Tunnel::is_active() != 0) {
                    TObjBoss2Tunnel::set_global_flag_800();
                } else {
                    TObjBoss2Tunnel::set_global_flag_400();
                }
            } else if (b & 2) {
                set_state_and_send(0x1F);
            }
            break;
        }
        break;
    case 0:
        advance_animation();
        if (!(motion_flags & 4)) {
            play_speed -= 0.03f;
            if (play_speed < 0.6f) {
                play_speed = 0.6f;
            }
        }
        break;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

extern "C" {

#pragma push
#pragma fp_contract on

#undef arg0

}

void TBoss2DeRolLe::handle_position_travel_state(u32 reason, s32 from, s32 to) {
    s32 r;
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_all_intangible();
        state_flags &= ~4;
        state_flags |= 0x100;
        position_index = from;
        next_position_index = to;
        set_position_index(position_index);
        state_step = 0;
        state_floats[0] = position.x;
        state_floats[1] = position.z;
        switch (position_index) {
        case 0:
            state_floats[2] = 1.0f;
            switch (next_position_index) {
            case 2:
                break;
            case 1:
                state_ints[0] = 1;
                break;
            case 3:
                state_ints[0] = 3;
                break;
            }
            break;
        case 1:
            state_ints[0] = 2;
            switch (next_position_index) {
            case 1:
                break;
            case 2:
                state_floats[2] = 1.0f;
                break;
            case 0:
                state_floats[2] = -1.0f;
                break;
            }
            break;
        case 2:
            state_floats[2] = -1.0f;
            switch (next_position_index) {
            case 2:
                break;
            case 1:
                state_ints[0] = 1;
                break;
            case 3:
                state_ints[0] = 3;
                break;
            }
            break;
        case 3:
            state_ints[0] = 0;
            switch (next_position_index) {
            case 1:
                break;
            case 2:
                state_floats[2] = 1.0f;
                break;
            case 0:
                state_floats[2] = -1.0f;
                break;
            }
            break;
        }
        switch (state_ints[0]) {
        case 0:
            init_wave_params();
            state_floats[3] = 1.0f;
            break;
        case 1:
            init_head_params();
            state_floats[3] = 1.0f;
            break;
        case 2:
            init_movement();
            state_floats[3] = -1.0f;
            break;
        case 3:
            init_move_params();
            state_floats[3] = -1.0f;
            break;
        }
        break;
    case 2:
        if (state_step == 1) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 1) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        sub_800338BC();
        r = 0;
        switch (state_ints[0]) {
        case 0:
            r = update_phase_rising();
            break;
        case 1:
            r = update_phase_is_done();
            position.z = state_floats[1] + motion_z.travelled;
            break;
        case 2:
            r = update_phase_settling();
            position.z = state_floats[1] - motion_z.travelled;
            break;
        case 3:
            r = update_state();
            position.z = state_floats[1] - motion_z.travelled;
            break;
        }
        if (r != 0) {
            state_step = 1;
        }
        position.x = motion_x.travelled * state_floats[2] + state_floats[0];
        position.z = motion_z.travelled * state_floats[3] + state_floats[1];
        break;
    case 5:
        position_index = next_position_index;
        break;
    }
}

void TBoss2DeRolLe::handle_side_jump_state(u32 reason, s32 from, s32 to) {
    switch (reason) {
    case 4:
        clear_all_intangible();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_index = from;
        next_position_index = to;
        set_position_index(position_index);
        if (position_index == 0) {
            requested_action = 5;
            state_floats[0] = -1.0f;
        } else {
            requested_action = 6;
            state_floats[0] = 1.0f;
        }
        state_step = 0;
        state_ints[0] = 0;
        state_ints[1] = 0;
        state_floats[1] = 0.0f;
        state_floats[2] = 0.0f;
        state_floats[4] = 0.0f;
        state_floats[5] = 0.0f;
        state_floats[3] = 0.0f;
        state_ints[2] = 0;
        break;
    case 2:
        if (state_step == 2) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 2) {
            advance_action_sequence();
        }
        break;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (!(motion_flags & 4)) {
                state_step = 1;
            }
            break;
        case 1:
            advance_animation();
            switch (state_ints[1]) {
            case 0:
                if (frame >= 10.0f) {
                    state_ints[1] = 1;
                    state_floats[4] = 3.25f * state_floats[0];
                }
                break;
            case 1:
                if (frame >= 20.0f) {
                    state_ints[1] = 2;
                    state_floats[4] = -5.625f * state_floats[0];
                    state_floats[5] = (270.0f - position.z + 72.666664f * -state_floats[3]) / 1034.6666f;
                }
                break;
            case 2:
                if (frame >= 28.0f) {
                    state_ints[1] = 3;
                    state_floats[1] = (calc_node_height() - state_floats[1]) / 2.5f;
                    state_floats[2] = (2.0f * state_floats[1]) / 56.666664f;
                    state_floats[4] = -6.5294123f * state_floats[0];
                    state_ints[2] = 0;
                }
                break;
            case 3:
                if (frame >= 45.0f) {
                    state_ints[1] = 4;
                    state_floats[4] = -15.0f * state_floats[0];
                    motion_z.set_move_params(7.0f, fabs_float(25.0f - position.z), 0.2f, 0.05f);
                    motion_z.speed = -(0.5f * state_floats[3]);
                    state_floats[3] = position.z;
                }
                break;
            case 4:
                if (frame >= 46.0f) {
                    state_ints[1] = 5;
                    state_floats[4] = state_floats[0] * ((-175.0f - position.x * state_floats[0]) / 36.0f);
                }
                break;
            case 5:
                if (frame >= 64.0f) {
                    state_ints[1] = 6;
                }
                break;
            }
            if (requested_action != 1) {
                if (is_passing_frame(10.0f) != 0 || is_passing_frame(41.0f) != 0) {
                    play_sound(0x4003AD11, &sound_origins[0]);
                } else if (is_passing_frame(25.0f) != 0) {
                    play_sound(0x4003AD12, &sound_origins[0]);
                }
            }
            state_ints[2]++;
            if (state_ints[1] != 6) {
                f32 f = frame;
                if (f >= 24.0f && f <= 32.0f) {
                    if (state_ints[2] >= 3) {
                        Vec v;
                        s32 i;
                        state_ints[2] = 0;
                        VecCopy(&v, &position);
                        for (i = 0; i < 10; i++) {
                            if (v.y * joint_positions[i].y < 0.0f) {
                                break;
                            }
                            VecCopy(&v, &joint_positions[i]);
                        }
                        v.x = v.x - state_floats[0] * (20.0f * random_ratio() + 40.0f);
                        v.y = -5.0f;
                        v.z = v.z + (20.0f * calc_elapsed_scaled() + 70.0f);
                        spawn_ceil_junk(&v);
                    }
                } else if (f >= 41.0f && f <= 46.0f && state_ints[2] >= 3) {
                    Vec v;
                    state_ints[2] = 0;
                    VecCopy(&v, &position);
                    v.x = v.x + state_floats[0] * (20.0f * random_ratio() + 20.0f);
                    v.y = -5.0f;
                    v.z = v.z + (60.0f * calc_elapsed_scaled() + 10.0f);
                    spawn_ceil_junk(&v);
                }
            }
            switch (state_ints[1]) {
            case 0:
                state_floats[3] = state_floats[3] - 0.2f;
                position.z = position.z + state_floats[3];
                break;
            case 1:
                position.x = position.x + state_floats[4];
                position.z = position.z + state_floats[3];
                break;
            case 2:
                position.x = position.x + state_floats[4];
                state_floats[3] = state_floats[3] + state_floats[5];
                position.z = position.z + state_floats[3];
                state_floats[1] = calc_node_height();
                break;
            case 3:
                position.x = position.x + state_floats[4];
                frame = frame - 0.19999999f;
                height_offset = height_offset + state_floats[1];
                state_floats[1] = state_floats[1] - state_floats[2];
                position.z = position.z + state_floats[3];
                break;
            case 4:
                position.x = position.x + state_floats[4];
                update_angle();
                motion_z.advance();
                position.z = state_floats[3] - motion_z.travelled;
                break;
            case 5:
                position.x = position.x + state_floats[4];
                update_angle();
                motion_z.advance();
                position.z = state_floats[3] - motion_z.travelled;
                break;
            case 6:
                update_angle();
                if (motion_z.advance() == 3) {
                    state_step = 2;
                }
                position.z = state_floats[3] - motion_z.travelled;
                if (requested_action == 1) {
                    state_flags |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        position_index = next_position_index;
        state_flags &= ~4;
        break;
    }
}

#undef o
#undef self

void TBoss2DeRolLe::handle_forward_jump_state(u32 reason) {
    Vec va;
    Vec vb;

    switch (reason) {
    case 4:
        requested_action = 1;
        clear_all_intangible();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_index = 3;
        set_position_index(position_index);
        state_step = 0;
        state_ints[1] = 0;
        state_ints[0] = 0;
        state_floats[0] = 0.0f;
        state_floats[1] = 0.0f;
        state_floats[2] = 0.0f;
        state_floats[3] = 0.0f;
        state_ints[2] = 0;
        break;
    case 2:
        if (state_step == 3) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 3) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_ints[1]++;
            if (state_ints[1] > 0x14) {
                requested_action = 4;
                state_step = 1;
            }
            state_floats[2] -= 0.2f;
            if (state_floats[2] < -7.0f) {
                state_floats[2] = -7.0f;
            }
            position.z += state_floats[2];
            break;
        case 1:
            if (!(motion_flags & 4)) {
                state_step = 2;
            }
            break;
        case 2:
            switch (state_ints[0]) {
            case 0:
                if (frame >= 10.5f) {
                    state_ints[0] = 1;
                    state_floats[3] = (300.0f - position.z + 49.102562f * -state_floats[2]) / 732.1581f;
                    state_ints[2] = 0;
                }
                break;
            case 1:
                if (frame >= 16.0f) {
                    state_ints[0] = 2;
                    state_floats[0] = 4.0f * (40.0f - position.y) / 30.76923f;
                    state_floats[1] = 2.0f * state_floats[0] / 30.76923f;
                    state_ints[2] = 0;
                }
                break;
            case 2:
                if (frame >= 22.0f) {
                    state_ints[0] = 3;
                    state_floats[2] *= 0.5f;
                    state_floats[3] = 0.0f;
                }
                break;
            case 3:
                if (frame >= 29.0f) {
                    state_ints[0] = 4;
                }
                break;
            }
            if (requested_action != 1) {
                if (is_passing_frame(4.0f) != 0 || is_passing_frame(22.0f) != 0) {
                    play_sound(0x4003AD11, &sound_origins[0]);
                } else if (is_passing_frame(14.0f) != 0) {
                    play_sound(0x4003AD12, &sound_origins[0]);
                }
            }
            switch (state_ints[0]) {
            case 1:
                state_ints[2]++;
                if (frame >= 13.5f && state_ints[2] >= 2) {
                    state_ints[2] = 0;
                    VecCopy(&va, &position);
                    va.x += 50.0f * calc_elapsed_scaled();
                    va.y = -5.0f;
                    va.z += 180.0f;
                    spawn_ceil_junk(&va);
                }
                break;
            case 2:
            case 3:
                state_ints[2]++;
                if (state_ints[2] >= 2 && frame >= 21.0f && frame <= 26.0f) {
                    state_ints[2] = 0;
                    VecCopy(&vb, &position);
                    vb.x += 50.0f * calc_elapsed_scaled();
                    vb.y = -5.0f;
                    vb.z += -20.0f;
                    spawn_ceil_junk(&vb);
                }
                break;
            }
            switch (state_ints[0]) {
            case 0:
                state_floats[2] -= 0.2f;
                if (state_floats[2] < -7.0f) {
                    state_floats[2] = -7.0f;
                }
                position.z += state_floats[2];
                break;
            case 1:
                state_floats[2] += state_floats[3];
                position.z += state_floats[2];
                state_floats[0] = calc_node_height();
                break;
            case 2:
                position.z += state_floats[2];
                height_offset += state_floats[0];
                state_floats[0] -= state_floats[1];
                frame -= 0.105000004f;
                break;
            case 3:
            case 4:
                if (state_floats[3] <= 0.0f) {
                    state_floats[2] -= 0.2f;
                    if (state_floats[2] <= 0.0f) {
                        state_floats[3] = 1.0f;
                        motion_z.set_move_params(7.0f, fabs_float(500.0f - position.z), 0.2f, 0.05f);
                        state_floats[2] = position.z;
                    } else {
                        position.z += state_floats[2];
                    }
                } else if (motion_z.advance() == 3) {
                    state_step = 3;
                } else {
                    position.z = state_floats[2] - motion_z.travelled;
                }
                update_angle();
                break;
            }
            break;
        }
        break;
    case 5:
        position_index = 1;
        state_flags &= ~4;
        break;
    }
}

#undef o

void TBoss2DeRolLe::handle_bite_state(u32 reason, s32 side) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_all_intangible();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_index = side;
        set_position_index(position_index);
        state_floats[0] = 0.0f;
        state_floats[3] = 0.0f;
        state_floats[2] = 0.0f;
        state_floats[1] = 0.0f;
        state_floats[4] = -0.2f;
        state_floats[5] = 0.0f;
        state_floats[6] = position.z;
        state_floats[7] = 0.0f;
        state_ints[0] = 0;
        state_step = 0;
        state_ints[1] = 0;
        state_emitter = 0;
        state_ints[2] = 0;
        break;
    case 2: {
        u32 buttons = debug_pad->pressed_buttons;
        if (buttons & 0x400) {
            if (position_index == 0) {
                set_state_and_send(0x14);
            } else {
                set_state_and_send(0x15);
            }
        } else if (buttons & 4) {
            if (position_index == 0) {
                set_state_and_send(0x16);
            } else {
                set_state_and_send(0x17);
            }
        }
        break;
    }
    case 9:
        if (requested_action == 0xA || requested_action == 9) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_ints[0]++;
            if (state_ints[0] > 0xA) {
                state_ints[0] = 0;
                state_step = 1;
                if (position_index == 0) {
                    requested_action = 7;
                    state_floats[0] = -1.0f;
                } else {
                    requested_action = 8;
                    state_floats[0] = 1.0f;
                }
            }
            break;
        case 1:
            if (!(motion_flags & 4)) {
                state_step = 2;
            }
            break;
        case 2:
            if (frame >= 6.0f) {
                state_step = 3;
                state_floats[3] = 0.0f;
                state_floats[1] = position.x;
                state_floats[2] = (100.0f * state_floats[0] - state_floats[1]) / 7.0f;
                state_floats[4] = -(state_floats[5] / 7.0f);
                state_floats[6] = position.z;
                state_floats[5] = 0.0f;
            }
            break;
        case 3:
            if (frame >= 13.0f) {
                state_step = 4;
                state_floats[3] = 0.0f;
                state_floats[1] = 100.0f * state_floats[0];
                state_floats[2] = (135.0f * state_floats[0] - state_floats[1]) / 7.0f;
                state_floats[6] = position.z;
                state_floats[4] = (2.0f * (10.0f - position.z)) / 144.0f;
                state_floats[5] = 0.0f;
            }
            break;
        case 4:
            if (frame >= 20.0f) {
                state_step = 5;
                state_floats[3] = 0.0f;
                state_floats[1] = 135.0f * state_floats[0];
                state_floats[2] = (100.0f * state_floats[0] - state_floats[1]) / 5.0f;
                state_floats[7] = (1280.0f * -state_floats[0]) / 5.0f;
            }
            break;
        case 5:
            if (frame >= 25.0f) {
                s32 i;
                state_step = 6;
                TCameraCtrl::set_shake_preset(1);
                if (position_index == 0) {
                    TObjBoss2Tunnel::start_sway_negative_x();
                } else {
                    TObjBoss2Tunnel::start_sway_positive_x();
                }
                play_sound(0x4003A507, &sound_origins[0]);
                for (i = 0; i < 4; i++) {
                    tentacles[i]->raise();
                }
            }
            break;
        case 6:
            break;
        }
        state_ints[1]++;
        if (state_step != 0 && state_step != 1) {
            if (frame >= 15.0f && frame <= 17.0f && state_ints[1] >= 2) {
                Vec v;
                f32 s;
                state_ints[1] = 0;
                VecCopy(&v, &part_points[0]);
                s = 50.0f * random_ratio();
                v.x = v.x - state_floats[0] * s;
                v.y = -5.0f;
                v.z += 40.0f;
                spawn_ceil_junk(&v);
            }
            if (is_passing_frame(15.0f) != 0) {
                play_sound(0x4003AD11, &sound_origins[0]);
            }
            if (state_emitter == 0) {
                state_emitter = create_particle_emitter(&position, 0x161);
                if (state_emitter != 0) {
                    state_emitter->enable();
                }
            } else if (frame >= 24.0f && frame <= 30.0f) {
                state_ints[2]++;
                if (state_ints[2] % 4 == 0) {
                    state_emitter->set_position(&node_positions[7]);
                } else if (state_ints[2] % 4 == 2) {
                    state_emitter->set_position(&node_positions[8]);
                } else {
                    state_emitter->enable();
                }
            } else {
                state_emitter->enable();
            }
        }
        switch (state_step) {
        case 0:
        case 1:
        case 2:
            state_floats[5] += state_floats[4];
            if (state_floats[5] < -7.0f) {
                state_floats[5] = -7.0f;
            }
            position.z += state_floats[5];
            break;
        case 3: {
            f32 t = frame - 6.0f;
            position.x = state_floats[2] * t + state_floats[1];
            f32 h = 0.5f * state_floats[4];
            position.z = t * (h * t + -7.0f) + state_floats[6];
            if (is_passing_frame(8.5f) != 0) {
                play_sound(0x4003AD12, &sound_origins[0]);
            }
            break;
        }
        case 4: {
            f32 t = frame - 13.0f;
            position.x = state_floats[2] * t + state_floats[1];
            f32 h = 0.5f * state_floats[4];
            position.z = t * (h * t) + state_floats[6];
            height_offset = 28.0f * t;
            if (height_offset > 4.0f) {
                height_offset = 4.0f;
            }
            break;
        }
        case 5: {
            f32 t = frame - 20.0f;
            f32 u;
            position.x = state_floats[2] * t + state_floats[1];
            u = frame - 13.0f;
            {
                f32 h = 0.5f * state_floats[4];
                f32 w = u * (h * u);
                position.z = state_floats[6] + w;
            }
            rotation_z = state_floats[7] * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        state_flags &= ~4;
        if (state_emitter != 0) {
            state_emitter->queue_destruction();
            state_emitter = 0;
        }
        break;
    }
}

#pragma pop


void TBoss2DeRolLe::handle_tentacle_volley_state(u32 reason, s32 side) {
    Vec v;
    s32 a;
    s32 ok;
    s32 i;
    switch (reason) {
    case 4:
        clear_all_intangible();
        state_flags &= ~4;
        state_flags &= ~0x100;
        position_index = side;
        set_move_direction(position_index);
        if (position_index == 0) {
            requested_action = 9;
        } else {
            requested_action = 10;
        }
        state_step = 0;
        state_ints[0] = 0;
        state_ints[1] = 0;
        if (TObjEneDD::check_v2_mode() != 0) {
            state_ints[2] = derolle_params[0]->volley_interval;
            state_ints[3] = derolle_params[0]->volley_hold_time;
        } else {
            state_ints[2] = 0xB4;
            state_ints[3] = 0x78;
        }
        break;
    case 2:
        if (state_step == 3) {
            if (position_index == 0) {
                set_state_and_send(0x16);
            } else {
                set_state_and_send(0x17);
            }
        }
        break;
    case 9:
        if (state_step == 3) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_ints[0]++;
            if (state_ints[0] > 0x28) {
                state_step = 1;
                state_ints[0] = 0;
                state_ints[1] = 0;
            }
            break;
        case 1:
            state_ints[0]++;
            if (state_ints[0] >= state_ints[2]) {
                state_ints[0] = 0;
                if (enemy_has_live_target() != 0) {
                    VecCopy(&v, &current_target->position);
                } else {
                    f32 r = 120.0f * random_ratio();
                    a = get_random_scaled();
                    v.x = r * sin_table_lookup(a);
                    v.y = -1.85f;
                    v.z = r * cos_table_lookup(a);
                    TObjBoss2Tunnel::adjust_to_ground(&v, &v);
                }
                tentacles[state_ints[1]]->start_attack_at_target(&v, state_ints[3]);
                state_ints[1]++;
                if (state_ints[1] >= 4) {
                    state_ints[0] = 0;
                    state_step = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            state_ints[0]++;
            for (i = 0; i < 4; i++) {
                if (tentacles[i]->is_turning_to_rest() == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || state_ints[0] > 0x258) {
                state_step = 3;
            }
            break;
        }
        break;
    case 6:
        pick_random_target();
        break;
    case 5:
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                tentacles[j]->drop_back();
            }
        }
        break;
    }
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::handle_roll_dive_state(u32 reason, s32 side) {
    switch (reason) {
    case 4:
        clear_all_intangible();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_index = side;
        set_move_direction(position_index);
        if (position_index == 0) {
            state_floats[1] = -1.0f;
            requested_action = 9;
        } else {
            state_floats[1] = 1.0f;
            requested_action = 10;
        }
        state_step = 0;
        state_ints[0] = 0;
        state_floats[0] = 0.0f;
        state_floats[3] = -1.0f;
        state_floats[2] = 0.0f;
        state_ints[4] = 0x500;
        TObjBoss2Tunnel::clear_global_flag_3000();
        break;
    case 2:
        if (state_step == 2) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 2) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_floats[2] += 0.2f;
            position.z -= state_floats[2];
            state_floats[0] += 0.08f;
            position.x += state_floats[0] * state_floats[1];
            state_floats[3] += 0.1f;
            height_offset -= state_floats[3];
            state_ints[4] += 256.0f;
            if ((f32)state_ints[4] >= 16384.0f) {
                state_ints[4] = 0x4000;
            }
            rotation_z = (s32)((f32)state_ints[4] * -state_floats[1]);
            if (state_ints[0] == 0 && state_ints[4] >= 0x2200) {
                state_ints[0] = 1;
                play_sound(0x4003AD12, &sound_origins[0]);
            }
            if (height_offset < -137.0f) {
                state_step = 1;
                set_position_index(position_index);
                height_offset = -137.0f;
                requested_action = 1;
                state_floats[3] = 0.0f;
                state_flags &= ~4;
                state_flags |= 0x100;
            }
            break;
        case 1:
            height_offset += 2.0f;
            if (height_offset >= 0.0f) {
                height_offset = 0.0f;
                state_step = 2;
            }
            break;
        }
        break;
    case 5:
        state_flags &= ~4;
        break;
    case 1:
    case 3:
    case 6:
    case 7:
    case 8:
        break;
    }
}

void TBoss2DeRolLe::handle_ceiling_pass_state(u32 reason) {
    Vec v;

    switch (reason) {
    case 4:
        requested_action = 1;
        clear_all_intangible();
        state_flags = state_flags | 4;
        state_flags = state_flags & ~0x100;
        set_position_index(3);
        state_step = 0;
        state_ints[0] = 0;
        state_ints[1] = 0x1E;
        state_floats[0] = 0.0f;
        state_floats[1] = 3.0f;
        return;
    case 2:
        if (state_step == 6) {
            set_state_and_send(2);
        }
        return;
    case 9:
        if (state_step == 6) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            state_floats[0] += 0.2f;
            position.z -= state_floats[0];
            state_floats[1] += -0.2f;
            height_offset += state_floats[1];
            if (height_offset < -137.0f) {
                state_step = 1;
                state_ints[0] = 0;
            }
            break;
        case 1:
            state_ints[0] += 1;
            if (state_ints[0] >= 0x2D) {
                state_step = 2;
                requested_action = 2;
                position.z = -1200.0f;
                rotation_z = 0x8000;
                height_offset = 93.0f;
            }
            break;
        case 2:
            state_ints[1] += 1;
            if (state_ints[1] >= 0x1E) {
                state_ints[1] = 0;
            }
            spawn_trap(0x40039E02, this, &sound_origins[0]);
            position.z += 6.0f;
            if (position.z >= 360.0f) {
                state_step = 3;
                state_floats[1] = 0.0f;
            }
            if (random_ratio() <= derolle_params[0]->ceil_junk_chance) {
                VecCopy(&v, &position);
                v.x = derolle_params[0]->ceil_junk_drift * calc_elapsed_scaled() + v.x;
                v.z -= 100.0f * random_ratio();
                v.y += 10.0f + height_offset;
                TObjBoss2CeilJunk::create(&v);
            }
            break;
        case 3:
            play_speed -= 0.02f;
            if (play_speed < 0.0f) {
                play_speed = 0.0f;
            }
            if (height_offset > 0.0f) {
                state_floats[1] += -0.1f;
                position.z += 4.8f;
            } else {
                position.z += 1.2f;
            }
            height_offset += state_floats[1];
            if (height_offset < -137.0f) {
                state_step = 4;
                state_ints[0] = 0;
                play_sound(0x4003AD12, &sound_origins[0]);
            }
            break;
        case 4:
            state_ints[0] += 1;
            if (state_ints[0] >= 0x2D) {
                state_step = 5;
                requested_action = 1;
                position_index = 1;
                set_position_index(position_index);
                rotation_z = 0;
                height_offset = -137.0f;
                TObjBoss2Tunnel::set_global_flag_400();
            }
            break;
        case 5:
            height_offset += 0.9f;
            if (height_offset >= 0.0f) {
                height_offset = 0.0f;
                state_step = 6;
            }
            break;
        }
        break;
    default:
        break;
    }
}

#pragma pop

void TBoss2DeRolLe::state_photon_pads(u32 reason, s32 position) {
    s32 i;

    switch (reason) {
    case 4:
        requested_action = 3;
        clear_all_intangible();
        state_flags = state_flags & ~4;
        state_flags = state_flags & ~0x100;
        position_index = position;
        set_position_index(position_index);
        state_step = 0;
        state_ints[0] = 0;
        state_floats[0] = -1000.0f;
        photon_pad_level = photon_pad_level + 1;
        if (photon_pad_level >= 3) {
            photon_pad_level = 0;
        }
        return;
    case 2:
        if (get_flag_b4() != 0) {
            set_state_and_send(2);
            return;
        }
        break;
    case 9:
        if (get_flag_b4() != 0) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        switch (state_ints[0]) {
        case 0:
            if (!(motion_flags & 4)) {
                spawn_photon_pad(state_step, photon_pad_level);
                state_ints[0] = 1;
                return;
            }
            break;
        case 1:
            i = state_step;
            if (joint_positions[i].y < joint_positions[i + 1].y) {
                state_step = i + 1;
                if ((f32)state_step >= 4.0f) {
                    state_ints[0] = 2;
                }
                spawn_photon_pad(state_step, photon_pad_level);
            }
            break;
        }
        break;
    default:
        break;
    }
}

void TBoss2DeRolLe::state_launch_mines(u32 reason, s32 state) {
    Vec *pos;
    s32 i;
    s32 j;
    switch (reason) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        requested_action = 0xB;
        position_index = 1;
        set_position_index(position_index);
        break;
    case 2:
        if (get_flag_b4() != 0) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (get_flag_b4() != 0) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(18.0f) != 0) {
            pos = &node_positions[18];
            if (state == 0x18) {
                for (i = 0; i < 5; i++) {
                    mines[i]->set_launch_position_velocity(pos, &TBoss2DeRolLe__mine_ground_targets[i]);
                }
            } else if (enemy_has_live_target() != 0) {
                for (j = 0; j < 3; j++) {
                    target_mines[j]->init_launch(pos, current_target, j);
                }
            }
            play_sound(0x4003A303, &sound_origins[1]);
        }
        break;
    case 6:
        if (state == 0x19) {
            pick_random_target();
        }
        break;
    }
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::state_ceiling_attack(u32 reason) {
    Vec v;
    f32 frame_now;

    switch (reason) {
    case 4:
        state_flags = state_flags & ~4;
        state_flags = state_flags | 0x100;
        clear_all_intangible();
        requested_action = 0xC;
        position_index = 3;
        set_position_index(position_index);
        state_step = 0;
        laser_shot_count = 0;
        return;
    case 2:
        if (requested_action == 0xF) {
            set_state_and_send(0x1B);
        }
        return;
    case 9:
        if (requested_action == 0xF) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        state_step = state_step + 1;
        frame_now = frame;
        if (frame_now >= 10.0f && frame_now <= 14.0f && (f32)state_step >= 3.0f) {
            state_step = 0;
            VecCopy(&v, &position);
            v.x = 30.0f * calc_elapsed_scaled() + v.x;
            v.y = -5.0f;
            v.z += 80.0f;
            spawn_ceil_junk(&v);
        }
        if (is_passing_frame(10.0f) != 0) {
            play_sound(0x4003AD12, &sound_origins[0]);
        }
        break;
    default:
        break;
    }
}

void TBoss2DeRolLe::handle_laser_attack_state(u32 reason) {
    Vec *vel;
    Vec *hit;
    vel = &state_vectors[0];
    switch (reason) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        clear_all_intangible();
        requested_action = 0xF;
        position_index = 3;
        set_position_index(position_index);
        fill_value_array(attack_history);
        state_step = 0;
        state_ints[0] = 0;
        state_ints[1] = 0;
        state_ints[4] = 0;
        state_floats[0] = 0.0f;
        state_floats[1] = 0.0f;
        vel->x = 0.0f;
        vel->y = 0.0f;
        vel->z = 0.0f;
        state_emitter = NULL;
        break;
    case 2:
        if (state_step == 4) {
            if (laser_shot_count >= 4) {
                set_state_and_send(0x1C);
            } else {
                set_state_and_send(0x1B);
            }
        }
        break;
    case 9:
        if (state_step == 4) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        splash_joint = 6;
        switch (state_step) {
        case 0:
            state_ints[0]++;
            if (state_ints[0] >= 0x14) {
                state_ints[0] = 0;
                state_step = 1;
                fill_value_array(attack_history);
                requested_action = 0xD;
                if (enemy_check_target_valid() != 0) {
                    VecCopy(vel, &current_target->position);
                } else {
                    vel->x = 0.0f;
                    vel->y = 0.0f;
                    vel->z = 0.0f;
                }
                calc_offset_position();
                activate_laser_light();
                play_sound(0x4003A809, &sound_origins[0]);
            }
            break;
        case 1:
            if (laser_shot_count != 0 && TObjEneDD::check_v2_mode() != 0) {
                frame = 13.0f;
            }
            if (frame <= 12.0f) {
                if (state_emitter == NULL) {
                    state_emitter = spawn_continuous_particle_effect_with_flags(&part_points[0], 0x122, 0x40);
                    if (state_emitter != NULL) {
                        state_emitter->enable();
                    }
                } else {
                    Vec a;
                    VecCopy(&a, &part_points[0]);
                    a.x += 2.0f * (5.0f * part_points[1].x);
                    a.y += 5.0f * part_points[1].y;
                    a.z += 5.0f * part_points[1].z;
                    state_emitter->set_position(&a);
                }
            } else if (state_emitter != NULL) {
                state_emitter->queue_destruction();
                state_emitter = NULL;
            }
            calc_offset_position();
            if (frame >= 13.0f) {
                frame = 13.0f;
                state_step = 2;
                subtract_vector(vel, &part_points[0]);
                normalize_vector_xz(vel);
                vel->y = 0.0f;
                state_ints[4] = RADIANS_TO_ANGLE * atan2_float(vel->x, vel->z);
                state_floats[0] = 80.0f;
                spawn_particle_effect_with_flags(&part_points[0], 0x126, 0x40);
            }
            break;
        case 2: {
            f32 k;
            f32 dist;
            f32 s;
            CsnHit *col;
            frame = 13.0f;
            state_floats[0] += 30.0f;
            if (state_emitter == NULL) {
                state_emitter = spawn_continuous_particle_effect_with_flags(&part_points[0], 0x177, 0x40);
                if (state_emitter != NULL) {
                    state_emitter->enable();
                }
            } else {
                Vec b;
                VecCopy(&b, &part_points[0]);
                b.x += 2.0f * (5.0f * part_points[1].x);
                b.y += 5.0f * part_points[1].y;
                b.z += 5.0f * part_points[1].z;
                state_emitter->set_position(&b);
            }
            {
                Vec e;
                Vec c;
                Vec p;
                Vec d;
                f32 h;
                f32 dy;
                f32 t;
                hit = &state_vectors[1];
                h = part_points[0].y;
                dy = -10.0f - h;
                e.x = vel->x * state_floats[0];
                e.y = dy;
                e.z = vel->z * state_floats[0];
                t = (10.0f - h) / dy;
                c.x = e.x * t;
                c.y = dy * t;
                c.z = e.z * t;
                vec3_add_to(&c, &part_points[0]);
                VecCopy(hit, &e);
                vec3_add_to(hit, &part_points[0]);
                state_floats[1] += 5.0f;
                if (state_floats[1] >= 20.0f) {
                    state_floats[1] -= 20.0f;
                }
                s = state_floats[1];
                VecCopy(&p, &part_points[0]);
                VecCopy(&d, hit);
                subtract_vector(&d, &p);
                dist = normalize_vector_safe(&d);
                p.x += d.x * s;
                p.y += d.y * s;
                p.z += d.z * s;
                k = 20.0f;
                d.x *= k;
                d.y *= k;
                d.z *= k;
                for (; dist > s; s += k) {
                    spawn_particle_effect_with_flags(&p, 0x176, 0x40);
                    vec3_add_to(&p, &d);
                }
                col = csnVector(&c, hit, 0x16EF);
                if (col != NULL) {
                    VecCopy(hit, &col->contact->point);
                    if (hit_trail == NULL) {
                        hit_trail = new TUnk_80482C58(this, 6, 0x124);
                    } else {
                        hit_trail->push_ring_point(hit);
                    }
                    if (hit_trail_long == NULL) {
                        hit_trail_long = new TUnk_80482C58(this, 0xF, 0x125);
                    } else {
                        hit_trail_long->push_ring_point(hit);
                    }
                }
                {
                    DragonAttackParams r = derolle_laser_hit_effect_params;
                    r.power = derolle_params[0]->laser_power;
                    TObjEneDD::setup_instance(this, hit, &r, attack_history);
                }
            }
            spawn_trap(0x4003B00A, this, hit);
            if (state_floats[0] >= 500.0f) {
                state_floats[0] = 500.0f;
                state_step = 3;
                if (state_emitter != NULL) {
                    state_emitter->queue_destruction();
                    state_emitter = NULL;
                }
            }
            break;
        }
        case 3:
            if (TObjEneDD::check_v2_mode() != 0) {
                state_step = 4;
            }
            if (get_flag_b4() != 0) {
                state_step = 4;
            }
            break;
        }
        break;
    case 6:
        pick_random_target();
        break;
    case 5:
        laser_shot_count++;
        free_laser();
        if (state_emitter != NULL) {
            state_emitter->queue_destruction();
            state_emitter = NULL;
        }
        if (hit_trail != NULL) {
            hit_trail->queue_destruction();
            hit_trail = NULL;
        }
        if (hit_trail_long != NULL) {
            hit_trail_long->queue_destruction();
            hit_trail_long = NULL;
        }
        break;
    }
}

#pragma pop

void TBoss2DeRolLe::handle_surface_state(u32 reason, s32 arg2) {
    switch (reason) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        requested_action = 0xE;
        clear_all_intangible();
        position_index = 3;
        set_position_index(position_index);
        if (arg2 != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 2:
        if (requested_action == 1) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        break;
    }
}

void TBoss2DeRolLe::handle_deep_sink_state(u32 reason) {
    switch (reason) {
    case 4:
        state_flags = state_flags | 4;
        state_flags = state_flags & 0xFFFFFEFF;
        set_all_intangible();
        rotation_x = 0;
        height_offset = 0.0f;
        return;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
        }
        break;
    case 8:
        if (height_offset < -200.0f) {
            set_state_and_send(0x1F);
            return;
        }
        break;
    case 0:
        height_offset = height_offset - 2.0f;
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    }
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::handle_death_state(u32 reason) {
    CameraPlayback cam;
    Vec v;
    Vec w;
    Vec save;
    s32 i;
    f32 t;
    switch (reason) {
    case 4:
        state_flags &= ~0x100;
        state_flags |= 4;
        set_all_intangible();
        requested_action = 0x10;
        position_index = 3;
        set_position_index(position_index);
        rotation_x = 0;
        height_offset = 0.0f;
        state_step = 0;
        state_ints[0] = 0;
        state_ints[4] = 0;
        body_hp = 0;
        for (i = 0; i < 4; i++) {
            tentacles[i]->speed_up_sway();
        }
        TWindowCtrl::init_all_slots();
        cam.index = 0;
        cam.bank = 2;
        cam.flags = 0;
        cam.frame = 0.0f;
        cam.frame_step = 0.7f;
        activate_camera_mode(5);
        cam.play(0x2AAA);
        set_scripted_camera_origin(&position, &position, (CameraAngles *)&rotation_x);
        break;
    case 2:
        if (debug_pad->pressed_buttons & 0x400) {
            actorFlags &= ~0x800;
            clear_all_intangible();
            set_state_and_send(2);
        }
        break;
    case 9:
        if (state_step == 3) {
            set_state_and_send(0x20);
        }
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            if (is_passing_frame(27.0f) != 0) {
                play_cue_stream_file("deldeath.adx");
            } else if (is_passing_frame(20.0f) != 0) {
                play_sound_effect(0x4003AD11, 0, 0, 0);
            } else if (is_passing_frame(99.0f) != 0) {
                play_sound_effect(0x4003AD12, 0, 0, 0);
                start_pad_rumble_all(0xC0, 0xF);
            }
            state_ints[0]++;
            t = frame;
            if (t >= 20.0f && t <= 28.0f) {
                if ((f32)state_ints[0] >= 2.0f) {
                    state_ints[0] = 0;
                    VecCopy(&v, &position);
                    for (i = 0; i < 10; i++) {
                        if (v.y * joint_positions[i].y < 0.0f) {
                            break;
                        }
                        VecCopy(&v, &joint_positions[i]);
                    }
                    v.x += 40.0f * calc_elapsed_scaled();
                    v.y = -5.0f;
                    v.z += 80.0f * random_ratio();
                    spawn_ceil_junk(&v);
                }
            } else if (t >= 99.0f && t <= 140.0f && (f32)state_ints[0] >= 2.0f) {
                state_ints[0] = 0;
                VecCopy(&w, &position);
                w.x += 40.0f * calc_elapsed_scaled() + 20.0f;
                w.y = -5.0f;
                w.z += 40.0f * calc_elapsed_scaled() + 20.0f;
                spawn_ceil_junk(&w);
            }
            if (frame >= 20.0f) {
                splash_joint = 5;
            }
            if (frame > 100.0f) {
                state_step = 2;
            }
            break;
        case 1:
            state_ints[4] += 0x400;
            height_offset = 0.5f * (6.0f * (cos_table_lookup(state_ints[4]) - 1.0f));
            break;
        case 2:
            height_offset -= 1.0f;
            if (height_offset < -100.0f) {
                state_step = 3;
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 1:
        break;
    case 3:
        break;
    case 5:
        VecCopy(&save, &position);
        position.x = -55.8f;
        position.y = 2.0f;
        position.z = 60.29f;
        update_prev_position();
        for (i = 0; i != 10; i++) {
            assign_slots_from_list(this, (saddr)joints[i]);
        }
        refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x20);
        VecCopy(&position, &save);
        update_prev_position();
        actorFlags = 0x12008;
        sync_enemy_state(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    }
}

#pragma pop

void TBoss2DeRolLe::handle_despawn_state(u32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0x10;
        set_all_intangible();
        state_flags = state_flags | 4;
        state_flags = state_flags & 0xFFFFFEFF;
        TObjBoss2Tunnel::set_global_flag_200();
        if (TObjBoss2Tunnel::is_active() != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 0:
        queue_destruction();
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    }
}

extern "C" {

// The model-node callback the body draws with: records the listed nodes' positions, the breakup
// piece points and the matrices the tentacles and joints follow.
void derolle_capture_node_points(NJS_OBJECT *) {
    if (derolle_capture_node_index == derolle_position_node_ids[derolle_capture_position_index]) {
        forward_transform_to_view(&derolle_capture_origin, derolle_capture_positions);
        derolle_capture_position_index += 1;
        derolle_capture_positions++;
    }
    if (derolle_capture_node_index == 0x33) {
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(0, derolle_part_transform_template, derolle_capture_part_points, 4);
        pop_matrix();
        subtract_vector(&derolle_capture_part_points[1], &derolle_capture_part_points[0]);
    }
    if ((derolle_capture_flags & 0x80) && derolle_capture_node_index >= 0x4D && derolle_capture_node_index <= 0x58) {
        push_matrix();
        forward_split_screen_view_matrix();
        get_current_matrix(derolle_capture_node_matrices);
        pop_matrix();
        derolle_capture_node_matrices++;
    }
    if (derolle_capture_node_index >= 0x1D && derolle_capture_node_index <= 0x20) {
        push_matrix();
        forward_split_screen_view_matrix();
        get_current_matrix(derolle_capture_tentacle_matrices);
        pop_matrix();
        derolle_capture_tentacle_matrices++;
    }
    derolle_capture_node_index += 1;
}

}

void derolle_begin_node_capture(TBoss2DeRolLe *boss) {
    derolle_capture_node_index = 0;
    copy_argb(&derolle_capture_color, &boss->body_color);
    derolle_capture_flags = boss->state_flags;
    derolle_capture_position_index = 0;
    derolle_capture_positions = boss->node_positions;
    derolle_capture_tentacle_matrices = boss->tentacle_matrices;
    derolle_capture_node_matrices = boss->node_matrices;
    derolle_capture_part_points = boss->part_points;
}

void copy_argb(NJS_ARGB *dst, NJS_ARGB *src) {
    dst->a = src->a;
    dst->r = src->r;
    dst->g = src->g;
    dst->b = src->b;
}

void TBoss2DeRolLe::render() {
    NJS_ARGB *col;
    s32 i;
    Vec *out;

    if (this->get_target_info() != 0) {
        render_body();
        return;
    }
    update_object_view_visibility(1000.0f, 1000.0f);
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    TObjEneDD::clear_global_flag_400();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&position.x);
    translate_matrix(0, 0.0f, height_offset, 0.0f);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, rotation_x);
    rotate_matrix_z(0, rotation_z);
    {
        Vec sc = {2.0f, 2.0f, 2.0f};
        scale_current_matrix(&sc.x);
    }
    update_pulsing_colors();
    for (i = 0; i < 10; i++) {
        joints[i]->apply_flash_color();
    }
    if (state_flags & 0x40) {
        derolle_breakup_node->child = derolle_breakup_stub_nodes;
    } else {
        derolle_breakup_node->child = derolle_breakup_node_child;
    }
    derolle_begin_node_capture(this);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    set_chunk_model_node_callback(derolle_capture_node_points);
    {
    NJS_ARGB saved;
    col = &scene_light_state.color;
    copy_argb(&saved, col);
    if (TObjBoss2Tunnel::is_active() != 0) {
        scene_light_state.color.r = 0.3f;
        scene_light_state.color.g = 0.4f;
        scene_light_state.color.b = 0.5f;
        current_scene_light->sub_8013379C(&scene_light_state);
        lbl_805D5564->sub_801336DC();
    }
    this->draw();
    copy_argb(col, &saved);
    }
    set_chunk_model_node_callback(NULL);
    current_scene_light->sub_801337F8();
    pop_matrix();
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    {
    Vec v;
    out = joint_positions;
    VecCopy(&v, &node_positions[0]);
    vec3_add_to(&v, &node_positions[9]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy(out, &v);
    VecCopy(&v, &node_positions[9]);
    vec3_add_to(&v, &node_positions[11]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy(out + 1, &v);
    out += 2;
    for (i = 0; i < 8; i++) {
        VecCopy(&v, &node_positions[i + 11]);
        vec3_add_to(&v, &node_positions[i + 12]);
        v.x *= 0.5f;
        v.y *= 0.5f;
        v.z *= 0.5f;
        VecCopy(out, &v);
        out++;
    }
    }
    part_group.render_nodes();
}

int TBoss2DeRolLe::vfunc_105() { return this->get_target_info(); }

#pragma push
#pragma opt_common_subs off

void TBoss2DeRolLe::render_body() {
    s32 i;
    AnimationMotion *motion;
    s32 idx;
    f32 frame;
    f32 max;
    this->update_object_view_visibility(1000.0f, 1000.0f);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    Vec scale = {2.0f, 2.0f, 2.0f};
    TObjEneDD::check_v2_mode();
    scale_current_matrix(&scale.x);
    for (i = 0; i < 10; i++) {
        joints[i]->apply_flash_color();
    }
    idx = parameters[0];
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 0x11) {
        idx = 0x10;
    }
    motion = motion_list[action_table[idx].motion].motion;
    if (test_previous_buttons_packed(&controller_input_state.controllers[2], 4) != 0) {
        max = motion->frameCount - 1;
        this->frame = this->frame + parameters[2];
        while (this->frame < 0.0f) {
            this->frame = this->frame + max;
        }
        while (this->frame > max) {
            this->frame = this->frame - max;
        }
        frame = this->frame;
    } else {
        frame = parameters[1];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (motion->frameCount - 1)) {
            frame = motion->frameCount;
        }
    }
    derolle_begin_node_capture(this);
    set_chunk_model_node_callback(derolle_capture_node_points);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    draw_model_motion(model, motion, frame);
    set_chunk_model_node_callback(NULL);
    current_scene_light->sub_801337F8();
    pop_matrix();
}


#pragma pop
