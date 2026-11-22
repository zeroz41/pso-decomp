#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/math/FloatRounding.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer_Eff_Rush.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/NinjaUtil.h"
#include "pso/player/TObjPlayer_800F0810.h"

#include "pso/render/TUnk_80494938.h"
#include <stddef.h>

#include "pso/enemy/canadin/TObjEneMe1CanadinLeader.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffDischarge.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLine.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"


extern "C" {
// inferred: the BML resource load_resources reads through bm_ene_me1_mb_resource_descriptor
BmlResource *bm_ene_me1_mb_resource;
// inferred: node counter of the render callback (TObjEneDf2Bringer__render_node_index twin)
u32 TObjEneMe1Canadin__render_node_index;
Vec *TObjEneMe1Canadin__render_point_cursor;


struct CanadinBehaviorParams {
    s32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_C;
    s32 m_10;
};


TUnk_8048FA00 *lbl_805D4FDC;
TUnk_8048FA00 *lbl_805D4FE0;
s32 *lbl_805D4FE4;
s32 *lbl_805D4FE8;
s32 *lbl_805D4FEC;
s32 *lbl_805D4FF0;

TObjEneMe1CanadinMovement canadin_setup_param_block = { 225.0f, 0.0f, 0x600, 0, 0, 0, 0 };
CollisionBody lbl_8048FECC = { { 0.0f, 0.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003 };
// The Canadin's two models and six motions, and the archive that holds them.
const char *bm_ene_me1_mb_model_names[3] = {
    "me1n_y_mb.nj",
    "me1_y_mb.nj",
    NULL
};
const char *bm_ene_me1_mb_motion_names[7] = {
    "change02_me1_y_mb.njm",
    "change01_me1_y_mb.njm",
    "damage01_me1_y_mb.njm",
    "damage02_me1_y_mb.njm",
    "wait01_me1_y_mb.njm",
    "wait02_me1_y_mb.njm",
    NULL
};
BmlResourceDescriptor bm_ene_me1_mb_resource_descriptor = {
    "bm_ene_me1_mb.bml", bm_ene_me1_mb_model_names, bm_ene_me1_mb_motion_names, 2, 6
};
const Vec lbl_8043A268 = { 0.0f, 0.0f, 1.0f };
const Vec lbl_8043A274 = { 0.0f, -1.0f, 0.0f };
const NJS_ARGB canadin_formation_reset_vec4 = { 1.0f, 0.0f, 0.2f, 1.0f };
const NJS_ARGB TObjEneMe1Canadin__map_core_default_vec4 = { 1.0f, 1.0f, 0.0f, 0.2f };
const NJS_ARGB canadin_formation_fade_start_color = { 1.0f, 0.2f, 1.0f, 0.0f };
TObjMotionAction lbl_8048FF30[7] = {
    { 1, 0, 4, 0.2f, 0 },
    { 1, 0, 5, 0.2f, 0 },
    { 2, 1, 1, 0.5f, 0 },
    { 2, 0, 0, 0.5f, 0 },
    { 2, 0, 2, 0.7f, 0 },
    { 2, 1, 3, 0.6f, 0 },
    { 3, 0, 1, 0.5f, 0 },
};
const char *canadin_leader_fade_sequence_table[5] = {
    "ababaababaabbababbabbbbc",
    "abbabbababc",
    "ababaaabbaaabbbabbabababbbbc",
    "abaaabababbac",
    "ababababaabbaabbababaabaabaaabbbbc",
};
const CanadinBehaviorParams canadin_behavior_params = { 3, 5.0f, 3.0f, 3.0f, 1 };
const CanadinBehaviorParams canadin_projectile_param_block = { 3, 10.0f, 20.0f, 3.0f, 1 };
const char *TObjEneMe1Canadin__class_name = "TObjEneMe1Canadin";
const char *TObjEneMe1CanadinLeader__class_name = "TObjEneMe1CanadinLeader";
saddr lbl_80500930[3];
saddr lbl_8050093C[3];
saddr lbl_80500948[3];
TObjEneMe1CanadinParams *lbl_80500954[3];
Vec lbl_80500960;

}

extern const s32 lbl_8043A180[3];
extern const s32 lbl_8043A18C[3];
extern const s32 lbl_8043A198[3];
extern const s32 lbl_8043A1A4[3];

// Motion setup passed to TLobby::spawn_npc_enemy: (motions, animation table, 0, 0x70000).

// Floor load: loads the Canadin archive, the per-difficulty stats and the breakup models, and spawns the
// two NPC copies.
void TObjEneMe1Canadin::load_resources() {
    s32 i;
    s32 model;
    s32 model2;
    void *p;

    lbl_80500960.x = 0.0f;
    lbl_80500960.y = 0.0f;
    lbl_80500960.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        bm_ene_me1_mb_resource = load_enemy_bml_resource_named(&bm_ene_me1_mb_resource_descriptor, "bm_ene_me1_mb_a.bml");
    } else {
        bm_ene_me1_mb_resource = load_enemy_bml_resource(&bm_ene_me1_mb_resource_descriptor);
    }
    for (i = 0; i < 3; i++) {
        lbl_80500930[i] = (saddr)TLobby::register_boss(lbl_8043A180[i]);
        lbl_8050093C[i] = (saddr)TLobby::dispatch_shared_handler_b(lbl_8043A18C[i]);
        lbl_80500948[i] = (saddr)TLobby::register_object(lbl_8043A198[i]);
        lbl_80500954[i] = (TObjEneMe1CanadinParams *)TLobby::dispatch_shared_handler_a(lbl_8043A1A4[i]);
    }
    TObjEneMe1Canadin__render_node_index = 0;
    p = new TUnk_8048FA00((saddr)bm_ene_me1_mb_resource->models[1].model);
    lbl_805D4FDC = (TUnk_8048FA00 *)p;
    p = new TUnk_8048FA00((saddr)bm_ene_me1_mb_resource->models[0].model);
    lbl_805D4FE0 = (TUnk_8048FA00 *)p;
    model = (saddr)bm_ene_me1_mb_resource->models[1].model;
    lbl_805D4FE4 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, 3))->model)->polygon_list + 2);
    lbl_805D4FE8 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, 2))->model)->polygon_list + 2);
    model2 = (saddr)bm_ene_me1_mb_resource->models[0].model;
    lbl_805D4FEC = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model2, 3))->model)->polygon_list + 2);
    lbl_805D4FF0 = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model2, 2))->model)->polygon_list + 2);
    TObjPlayer__sub_800F0928();
    s16 ids[2] = { 0x17, 0x18 };
    NpcAnimationBinding params = { reinterpret_cast<BmlMotionEntry *>(bm_ene_me1_mb_resource->motions), reinterpret_cast<TObjMotionAction *>(lbl_8048FF30), 0, 0, 7 };
    for (i = 0; i < 2; i++) {
        NpcModelRegistry::register_animated_chunk(ids[i], reinterpret_cast<void *>(bm_ene_me1_mb_resource->models[i].model), reinterpret_cast<void *>(bm_ene_me1_mb_resource->models[1].m_c), &params, 8.0f, 15.0f);
    }
}

void *TObjEneMe1Canadin::create(void *set_data) {
    return new TObjEneMe1Canadin(tl_04, set_data, 0);
}

TObjEneMe1Canadin *TObjEneMe1CanadinLeader::create_canadin(TObjEneMe1Canadin *leader, Vec *position, s32 id, s32 index) {
    return new TObjEneMe1Canadin(tl_04, leader, position, id, index);
}

// Floor teardown: frees the two breakup models and the Canadin archive.
void TObjEneMe1Canadin::free_resources() {
    if (lbl_805D4FE0 != NULL) {
        delete lbl_805D4FE0;
        lbl_805D4FE0 = NULL;
    }
    if (lbl_805D4FDC != NULL) {
        delete lbl_805D4FDC;
        lbl_805D4FDC = NULL;
    }
    if (bm_ene_me1_mb_resource != NULL) {
        delete bm_ene_me1_mb_resource;
        bm_ene_me1_mb_resource = NULL;
    }
}

TObjEneMe1Canadin::TObjEneMe1Canadin(TObject *parent, void *set_data, s32 kind) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Canadin__class_name;
    invoke_initialization_hook(set_data);
    status_flags = 0;
    update_by_field_0x354();
    this->leader = this;
    this->kind = kind;
    setup_enemy();
}

TObjEneMe1Canadin::TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Canadin__class_name;
    this->leader = leader;
    init_common_from((u8 *)this->leader);
    entity_id = id;
    set_index = sub_id;
    this->leader->calc_move_vector(&position);
    VecCopy(&position, pos);
    rotation_y = this->leader->rotation_y;
    status_flags = 0;
    this->kind = 1;
    setup_enemy();
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::setup_enemy() {
    s32 i;

    init_position_vectors();
    this->select_model();
    init_model(&lbl_8048FECC, 1);
    set_field_d8((saddr)lbl_8048FF30);
    set_field_dc((saddr)bm_ene_me1_mb_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp((u8 *)lbl_80500930[kind], (u8 *)lbl_8050093C[kind], (u8 *)lbl_80500948[kind]);
    set_state_flag_4();
    movementParameters = &canadin_setup_param_block;
    initialize_enemy_state(0x1C);
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x2D);
    enemy_init_validate_period(0x2D);
    set_active();
    actorFlags |= 0x01000000;
    kind_params = lbl_80500954[kind];
    fade.reset_color();
    upper_hover_height = 45.0f;
    hover_height = 15.0f;
    random_hover_height = 5.0f * (3.0517578e-05f * (f32)rand()) + 15.0f;
    hover_offset = hover_height;
    hover_y = position.y + hover_offset;
    move_action = 4;
    attack_delay = 0;
    attack_count = 0;
    eff_light = new TObjEneMe1Canadin_EffLight(this, 5);
    m_40C = 0;
    alt_model_color = 0;
    for (i = 0; i < 7; i++) {
        VecCopy(&node_points[i], &position);
    }
    attack_pattern = 0;
    stage = 0;
    stage_timer = 0;
    stage_counter = 0;
    m_47C = 0;
    orbit_angle_step = 0;
    m_484 = 0.0f;
    m_488 = 0.0f;
    m_48C = 0.0f;
    m_490.x = 0.0f;
    m_490.y = 0.0f;
    m_490.z = 0.0f;
    eff_line = 0;
    particle_emitter = 0;
    copy_argb(&core_color, (NJS_ARGB *)&TObjEneMe1Canadin__map_core_default_vec4);
    core_color.a = 0.0f;
    fade_mode = 0;
    core_color_packed = 0;
    fade_sequence = 0;
    fade_step_timer = 0;
    fade_cursor = 0;
    copy_pos();
    TObjEneDD::set_part_position(this, bodies, 0);
    mode = 0;
    dispatch_action(mode, 4);
    if (leader != NULL) {
        leader_id = get_entity_id(leader);
    } else {
        leader_id = 0xFFFF;
    }
}
#pragma pop

TObjEneMe1Canadin::~TObjEneMe1Canadin() {
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
    eff_light->queue_destruction();
    eff_light = NULL;
    free_collision_body_parts(this);
}

void TObjEneMe1Canadin::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_if_ready();
        return;
    }
    if (kind == 1) {
        leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
        if (leader == NULL || leader->all_parents_unqueued_for_destruction() == 0) {
            queue_destruction();
            return;
        }
    }
    if (update_status_effects() != 4) {
        update_action_state();
        update_fade_sequence();
    }
    copy_pos();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneMe1Canadin::refresh_target() {  }

void TObjEneMe1Canadin::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 != 0xD) && (temp_r0 != 0xB)) {
        transition_enemy_state(0xD);
    }
}

void TObjEneMe1Canadin::run_hit_reaction() { if (mode != 12) { transition_enemy_state(12); } }

void TObjEneMe1Canadin::run_miss_reaction() {  }

void TObjEneMe1Canadin::copy_pos() {
    body_center.x = (f32) position.x;
    body_center.y = (f32) hover_y;
    body_center.z = (f32) position.z;
    VecCopy(&center, &body_center);
}

void TObjEneMe1Canadin::update_body_colliders() {
    hover_offset = (f32) (hover_y - position.y);
    if (hover_offset < 30.0f) {
        set_colliders_contact_low();
    } else {
        set_colliders_contact_high();
    }
    bodies->offset.y = hover_offset;
}

void TObjEneMe1Canadin::update_by_field_0x354() {
    if ((s32) floor_to_float(parameters[0]) == 0) {
        fn_8009E350();
        return;
    }
    fn_8009E334();
}

void TObjEneMe1Canadin::select_model() {
    model = (void *)bm_ene_me1_mb_resource->models[0].model;
    texlist = (saddr)bm_ene_me1_mb_resource->models[1].m_c;
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::calc_move_vector(Vec *out) {
    s32 angle;
    f32 x;
    f32 dist;

    angle = TObjEneDD::get_random_scaled();
    f32 ratio = random_ratio();
    dist = (30.0f * ratio) + 10.0f;
    x = dist * sin_table_lookup(angle);
    out->x = x;
    out->y = 0.0f;
    out->z = (f32) (dist * cos_table_lookup(angle));
    vec3_add_to(out, &position);
}
#pragma pop

u8 *TObjEneMe1Canadin::move_xz_on_ground(u8 *arg) {
    u8 *result = TObjEneDD::move_xz_on_ground(arg);
    if (result == NULL) {
        status_flags &= ~0x1000000;
    } else {
        status_flags |= 0x01000000;
    }
    return result;
}


extern "C" void TObjEneMe1Canadin__sub_8009EB98(TObjEneMe1Canadin *self, f32 height) {
    f32 temp_f3;
    temp_f3 = height - self->hover_y;
    self->status_flags &= ~0x80000;
    if (temp_f3 >= 0.5f) {
        self->hover_y += 0.5f;
    } else if (temp_f3 <= -0.5f) {
        self->hover_y -= 0.5f;
    } else {
        self->hover_y = height;
        self->status_flags |= 0x80000;
    }
}

void TObjEneMe1Canadin::update_position_with_offset() {
    TObjEneMe1Canadin__sub_8009EB98(this, position.y + upper_hover_height);
}


extern "C" void TObjEneMe1Canadin__sub_8009EB14(TObjEneMe1Canadin *self, f32 height) {
    Vec pos;
    TObjEneMe1Canadin__sub_8009EB98(self, height);
    VecCopy(&pos, &self->position);
    pos.y = self->hover_y;
    self->move_xz_on_ground((u8 *)&pos);
}

void TObjEneMe1Canadin::set_target_speed_z() {
    TObjEneMe1Canadin__sub_8009EB14(this, hover_height + position.y);
}

void TObjEneMe1Canadin::update_hover_height() {
    TObjEneMe1Canadin__sub_8009EB14(this, upper_hover_height + position.y);
}

void TObjEneMe1Canadin::update_angle() {
    rotation_y = approach_angle_limited(rotation_y, (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x400);
    rotation_y = (s32) (s16) rotation_y;
}

void TObjEneMe1Canadin::update_move() {
    if (enemy_has_live_target() != 0) {
        enemy_copy_target_destination();
        update_velocity();
        update_angle();
    }
}

void TObjEneMe1Canadin::select_next_attack_state() {
    if (status_flags & 0x100) {
        transition_enemy_state(7);
        return;
    }
    if (kind == 0) {
        if (attack_pattern < 2) {
            transition_enemy_state(6);
            attack_pattern += 1;
            return;
        }
        transition_enemy_state(7);
        attack_pattern = 0;
        return;
    }
    transition_enemy_state(6);
}

void TObjEneMe1Canadin::check_collisions() { TObjEneDD::check_collisions(); }


void TObjEneMe1Canadin::fn_8009E948() {
    bodies->flags |= 0x28;
}
void TObjEneMe1Canadin::fn_8009E930() {
    bodies->flags &= ~0x28;
}
s32 TObjEneMe1Canadin::fn_8009E860(f32 *out, f32 squared_range) {
    TObjEneMe1Canadin *self = this;
    TargetCandidate list[5];
    s32 found;
    s32 count;
    TObjChara *player;
    s32 i;
    found = 0;
    *out = -1.0f;
    count = collect_enemy_target_candidates(self, list, squared_range);
    for (i = 0; i < count; i++) {
        player = get_player_by_client_id(list[i].id);
        if (player != self->current_target) {
            self->leader = (TObjEneMe1Canadin *)find_entity_by_id(self->leader_id);
            if (self->leader->can_member_attack_target(player) != 0) {
                *out = newton_sqrtf(list[i].dist);
                found = 1;
                self->set_target_player(player);
                break;
            }
        }
    }
    return found;
}

s32 TObjEneMe1Canadin::check_target() {
    f32 sp8;
    s32 var_r31;

    var_r31 = 0;
    if (destination_distance < 70.0f) {
        var_r31 = 1;
        leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
        if ((leader->can_member_attack_target(current_target) == 0) && (fn_8009E860(&sp8, 22500.0f) != 0) && (sp8 > 70.0f)) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

void TObjEneMe1Canadin::advance_state_4_to_5() {
    if (move_action == 4) {
        requested_action = 2;
        move_action = 5;
    }
}

void TObjEneMe1Canadin::advance_state_5_to_4() {
    TObjEneMe1Canadin *self = this;
    if (self->move_action == 5) {
        self->requested_action = 3;
        self->move_action = 4;
    }
}


s32 TObjEneMe1Canadin::fn_8009E76C() {
    return hover_offset < 20.0f;
}

void TObjEneMe1Canadin::spawn_members() {  }

s32 TObjEneMe1Canadin::check_retreat_trigger() {
    s32 temp_r4;
    temp_r4 = status_flags;
    if (temp_r4 & 0x20) {
        status_flags = (s32) (temp_r4 & 0xFFFFFFDF);
        transition_enemy_state(0xA);
        m_40C = 0;
        return 1;
    }
    if (temp_r4 & 0x40) {
        status_flags = (s32) (temp_r4 & 0xFFFFFFBF);
        transition_enemy_state(0xB);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Canadin::try_trigger_action() {
    if (current_target == NULL) {
        transition_enemy_state(0xE);
        return 1;
    }
    return 0;
}

void TObjEneMe1Canadin::noop() {}

s32 TObjEneMe1Canadin::acquire_target(f32 range) { return select_and_apply_target(range); }

void TObjEneMe1Canadin::update_fade_sequence() {
    TObjEneMe1Canadin *p = this;
    switch (p->fade_mode) {
    case 0:
        break;
    case 1:
        if (p->core_color.a > 0.0f) {
            p->core_color.a = p->core_color.a - 0.06f;
        } else {
            p->core_color.a = 0.0f;
            p->fade_mode = 0;
        }
        p->pack_color_rgba();
        break;
    case 2:
        if (p->core_color.a < 1.0f) {
            p->core_color.a += 0.06f;
        } else {
            p->core_color.a = 1.0f;
            p->fade_mode = 0;
        }
        p->pack_color_rgba();
        break;
    case 3:
        p->fade_step_timer++;
        if ((f32)p->fade_step_timer >= 2.0f) {
            p->fade_step_timer = 0;
            switch (((s8 **)canadin_leader_fade_sequence_table)[p->fade_sequence][p->fade_cursor++]) {
            case 0x62:
                p->core_color.a = 0.0f;
                break;
            case 0x63:
                p->fade_mode = 0;
                copy_argb(&p->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
                break;
            case 0x61:
                p->core_color.a = 1.0f;
                break;
            }
            p->pack_color_rgba();
        }
        break;
    }
}


void TObjEneMe1Canadin::fn_8009E4AC(s32 sequence) {
    reset_map_core((NJS_ARGB *)&canadin_formation_fade_start_color);
    fade_mode = 3;
    fade_sequence = sequence;
    fade_step_timer = 2;
    fade_cursor = 0;
}

void TObjEneMe1Canadin::reset_map_core(void *color) {
    copy_argb(&core_color, (NJS_ARGB *)color);
    pack_color_rgba();
}

void TObjEneMe1Canadin::pack_color_rgba() {
    core_color_packed = ((u8)(u32)(255.0f * core_color.g) << 24)
        | ((u8)(u32)(255.0f * core_color.b) << 16)
        | ((u8)(u32)(0.8f * (255.0f * core_color.a)) << 8)
        | (u8)(u32)(255.0f * core_color.r);
}

void TObjEneMe1Canadin::apply_model_color() {
    *lbl_805D4FEC = core_color_packed;
    *lbl_805D4FF0 = core_color_packed;
}

int TObjEneMe1Canadin::has_no_members() { return 1; }


void TObjEneMe1Canadin::fn_8009E378() {
    if (mode == 2) {
        leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
        leader->fn_8009E2DC();
    }
}
int TObjEneMe1Canadin::fn_8009E36C() { return (status_flags >> 15) & 0x1; }
void TObjEneMe1Canadin::fn_8009E350() {
    status_flags |= 0x100;
    status_flags &= ~0x200;
}
void TObjEneMe1Canadin::fn_8009E334() {
    status_flags |= 0x200;
    status_flags &= ~0x100;
}
s32 TObjEneMe1Canadin::fn_8009E31C(s32 mask) {
    return (status_flags & mask) != 0;
}
TObjChara *TObjEneMe1Canadin::fn_8009E300() {
    if (status_flags & 0x40000) {
        return current_target;
    }
    return NULL;
}

void TObjEneMe1Canadin::remove_member(uaddr) {  }

int TObjEneMe1Canadin::can_member_attack_target(TObjChara *) { return 1; }


void TObjEneMe1Canadin::fn_8009E2DC() {
    attack_delay = 0;
    status_flags |= 1;
}

void TObjEneMe1Canadin::set_leader_index(TObjChara *target, s32 index) {
    set_target_player(target);
    attack_delay = index;
    status_flags |= 1;
}

void TObjEneMe1Canadin::set_attack_flag() { status_flags |= 0x2; }


void TObjEneMe1Canadin::fn_8009E27C() { status_flags |= 0x4; }

void TObjEneMe1Canadin::set_flag3c8_bit8() { status_flags |= 0x8; }


void TObjEneMe1Canadin::fn_8009E258() {
    status_flags |= 0x100000 | 4;
}

void TObjEneMe1Canadin::set_flag3c8_bit20() { status_flags |= 0x20; }

void TObjEneMe1Canadin::set_flag3c8_bit40() { status_flags |= 0x40; }


void TObjEneMe1Canadin::fn_8009E1D4(Vec *pos) {
    CanadinBehaviorParams params = canadin_behavior_params;
    params.m_4 = kind_params->m_4;
    TObjEneDD::setup(this, (saddr)pos, (saddr)&params);
}

void TObjEneMe1Canadin::dispatch_action(u32 which, s32 arg) {
    switch (which) {
    case 0:
        handle_state(arg);
        break;
    case 1:
        fn_8009DE90(arg);
        break;
    case 2:
        action(arg);
        break;
    case 3:
        vfunc_110(arg);
        break;
    case 4:
        vfunc_111(arg);
        break;
    case 5:
        move(arg);
        break;
    case 6:
        fn_8009D320(arg);
        break;
    case 7:
        fn_8009CC74(arg);
        break;
    case 8:
        fn_8009C91C(arg);
        break;
    case 9:
        run_task(arg);
        break;
    case 10:
        fn_8009C2EC(arg);
        break;
    case 11:
        fn_8009C178(arg);
        break;
    case 12:
        fn_8009C510(arg);
        break;
    case 13:
        state_dead(arg);
        break;
    case 14:
        fn_8009BFF8(arg);
        break;
    case 16:
        update_walk_animation(arg);
        break;
    case 17:
        update_by_state(arg);
        break;
    }
}

void TObjEneMe1Canadin::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        this->set_intangible();
        status_flags |= 0x400000;
        move_action = 4;
        fade_mode = 1;
        stage = 0;
        return;
    case 3:
        if (stage >= 4) {
            if (kind == 0) {
                status_flags |= 0x100000;
            }
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        stage += 1;
        if (stage == 2) {
            this->spawn_members();
        }
        status_flags &= ~0x1000000;
        break;
    }
}


void TObjEneMe1Canadin::fn_8009DE90(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(2);
        self->status_flags &= ~0x400000;
        self->set_intangible();
        self->actorFlags |= 0x01000000;
        self->move_action = 4;
        self->fade_mode = 1;
        self->fade.start_fade_in();
        TBoss3Volopt__sub_800D8D88((saddr)&self->position);
        return;
    case 3:
        if (self->fade.advance_toward_max() != 0) {
            self->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        self->advance_animation();
        if (self->kind == 2) {
            TObjEneMe1Canadin__sub_8009EB14(self, 25.0f + self->position.y);
        } else {
            self->set_target_speed_z();
        }
        self->update_body_colliders();
        break;
    }
}

void TObjEneMe1Canadin::action(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(2);
        status_flags &= ~0x400000;
        this->set_intangible();
        actorFlags &= ~0x1000000;
        move_action = 4;
        fade_mode = 1;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = status_flags;
            if (temp_r3 & 1) {
                status_flags = (s32) (temp_r3 & 0xFFFFFFFE);
                transition_enemy_state(3);
            } else if (enemy_has_live_target() != 0) {
                transition_enemy_state(3);
            }
        }
        break;
    case 0:
        advance_animation();
        if (kind != 1) {
            update_linked_position(200.0f);
        }
        if (kind == 2) {
            TObjEneMe1Canadin__sub_8009EB14(this, 25.0f + position.y);
        } else {
            set_target_speed_z();
        }
        this->check_collisions();
        break;
    case 5:
    case 1:
        break;
    }
}

void TObjEneMe1Canadin::vfunc_110(s32 arg1) {
    s32 temp_r3;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(3);
        status_flags &= ~0x400000;
        this->clear_intangible();
        actorFlags &= ~0x1000000;
        {
            const f32 *p = (const f32 *)&canadin_formation_reset_vec4;
            core_color.r = p[1];
            core_color.g = p[2];
            core_color.b = p[3];
            pack_color_rgba();
        }
        stage = 0;
        return;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            temp_r3 = status_flags;
            if (temp_r3 & 2) {
                status_flags = temp_r3 & ~2;
                if (kind == 1) {
                    transition_enemy_state(5);
                } else {
                    transition_enemy_state(4);
                }
            }
        }
    case 1:
        return;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (stage) {
        case 2:
            break;
        case 0:
            attack_delay -= 1;
            if (attack_delay <= 0) {
                fade_mode = 2;
                stage = 1;
                play_sound_effect(0x4003B21A, &body_center, 0, 0);
            }
            break;
        case 1:
            if (fade_mode == 0) {
                status_flags |= 0x8000;
                switch (kind) {
                case 0:
                    this->set_attack_flag();
                case 1:
                    stage = 3;
                    break;
                }
            }
            update_move();
            break;
        case 3:
            update_move();
            break;
        }
        set_target_speed_z();
        this->check_collisions();
        return;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1Canadin::vfunc_111(s32 arg1) {
    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(4);
        status_flags &= ~0x400000;
        this->clear_intangible();
        actorFlags |= 0x01000000;
        return;
    case 3:
        if (status_flags & 0x80000) {
            attack_count = 0;
            this->select_next_attack_state();
        }
        return;
    case 5:
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update_move();
        this->update_hover_height();
        this->check_collisions();
        noop();
        break;
    }
}

void TObjEneMe1Canadin::move(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(5);
        status_flags &= ~0x400000;
        this->clear_intangible();
        actorFlags |= 0x01000000;
        stage = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && (stage == 3)) {
            attack_count = 0;
            this->select_next_attack_state();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (stage) {
        case 0:
            temp_r3 = status_flags;
            if (temp_r3 & 4) {
                status_flags = (s32) (temp_r3 & 0xFFFFFFFB);
                if (fn_8009E31C(0x200) != 0) {
                    stage = 1;
                    fn_8009E4AC(1);
                } else {
                    stage = 2;
                    advance_state_4_to_5();
                    fn_8009E4AC(3);
                }
            }
            update_move();
            update_hover_height();
            break;
        case 1:
            if (fade_mode == 0) {
                stage = 3;
            }
            update_move();
            update_hover_height();
            break;
        case 2:
            update_move();
            if (fade_mode != 0) {
                update_hover_height();
            } else {
                TObjEneMe1Canadin__sub_8009EB14(this, position.y + random_hover_height);
                if (status_flags & 0x80000) {
                    stage = 3;
                }
            }
            break;
        }
        this->check_collisions();
        noop();
        break;
    }
}


#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::fn_8009D320(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    Vec *pos;
    pos = &self->m_490;
    switch (arg1) {
    case 4:
        self->set_field_378(6);
        self->status_flags |= 0x10000;
        self->status_flags &= ~0x400000;
        self->clear_intangible();
        self->actorFlags |= 0x01000000;
        self->reset_map_core((void *)&canadin_formation_reset_vec4);
        self->stage = 1;
        self->stage_timer = 0;
        self->eff_line = 0;
        self->particle_emitter = 0;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->stage == 6) {
            if (self->status_flags & 0x100000) {
                self->transition_enemy_state(8);
            } else {
                self->transition_enemy_state(9);
            }
        }
        break;
    case 0:
        self->advance_animation();
        if (self->stage == 1) {
            if (self->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)self)->update_death_check() == 0) {
            break;
        }
        self->enemy_copy_target_destination();
        switch (self->stage) {
        case 1:
            self->update_velocity();
            if (self->check_target() != 0) {
                self->stage = 2;
                self->status_flags |= 0x40000;
                self->advance_state_4_to_5();
            } else {
                self->advance_state_5_to_4();
            }
            TObjEneEpsilon__sub_800B92F8(self, 0x200, 0.5f);
            break;
        case 2:
            self->update_velocity();
            self->update_angle();
            if (self->requested_action == 1) {
                self->stage = 3;
                self->reset_map_core((void *)&TObjEneMe1Canadin__map_core_default_vec4);
                VecCopy(pos, &self->destination);
                self->eff_line = new TObjEneMe1Canadin_EffLine(self, self->node_points, pos);
                play_sound_effect(0x4002B71B, &self->body_center, 0, 0);
                play_sound_effect(0x4002B51E, &self->body_center, 0, 0);
            }
            break;
        case 3: {
            Vec v;
            self->update_velocity();
            self->update_angle();
            VecCopy(&v, &self->destination);
            subtract_vector(&v, pos);
            if (normalize_vector_xz(&v) < 0.6f) {
                VecCopy(pos, &self->destination);
            } else {
                pos->x = 0.6f * v.x + pos->x;
                pos->y = 0.6f * v.y + pos->y;
                pos->z = 0.6f * v.z + pos->z;
            }
            if (self->particle_emitter == 0) {
                self->particle_emitter = create_particle_emitter(self->node_points, 0xF7);
                if (self->particle_emitter != 0) {
                    self->particle_emitter->enable();
                }
            } else {
                self->particle_emitter->set_position(self->node_points);
            }
            self->stage_timer++;
            if (self->stage_timer > self->kind_params->m_18) {
                self->stage = 4;
                self->stage_timer = 0;
                self->eff_line->queue_destruction();
                self->eff_line = 0;
                if (self->particle_emitter != 0) {
                    self->particle_emitter->queue_destruction();
                    self->particle_emitter = 0;
                }
            }
            break;
        }
        case 4:
            self->stage_timer++;
            if (self->stage_timer >= self->kind_params->m_1C) {
                self->stage = 5;
                self->stage_timer = 0;
                self->status_flags &= ~0x40000;
                self->reset_map_core((void *)&canadin_formation_reset_vec4);
                self->attack_count++;
                new TObjEneMe1Canadin_EffDischarge(self, self->node_points, pos);
                play_sound_effect(0x4002A408, &self->body_center, 0, 0);
            }
            break;
        case 5:
            self->stage_timer++;
            if (self->stage_timer > self->kind_params->m_20) {
                self->stage_timer = 0;
                if (self->attack_count >= self->kind_params->m_24) {
                    self->stage = 6;
                } else {
                    self->stage = 1;
                }
            }
            break;
        }
        self->update_position_with_offset();
        self->check_collisions();
        self->noop();
        break;
    case 5:
        self->status_flags &= ~0x40000;
        self->reset_map_core((void *)&canadin_formation_reset_vec4);
        if (self->eff_line != 0) {
            self->eff_line->queue_destruction();
            self->eff_line = 0;
        }
        if (self->particle_emitter != 0) {
            self->particle_emitter->queue_destruction();
            self->particle_emitter = 0;
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma optimization_level 3
void TObjEneMe1Canadin::fn_8009CC74(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(7);
        self->status_flags &= ~0x400000;
        self->clear_intangible();
        self->actorFlags &= ~0x1000000;
        self->status_flags &= ~0x80000;
        self->stage = 0;
        self->stage_timer = 40;
        self->stage_counter = 0;
        self->m_484 = 0.0f;
        self->m_488 = 0.0f;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->stage == 4) {
            self->transition_enemy_state(8);
        }
        break;
    case 0:
        self->advance_animation();
        if (self->stage == 0) {
            if (self->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)self)->update_death_check() == 0) {
            break;
        }
        switch (self->stage) {
        case 4:
            break;
        case 0: {
            f32 d;
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            self->stage_timer++;
            if (self->stage_timer > 40) {
                self->stage_timer = 0;
                self->stage = 1;
                if (self->status_flags & 0x40000) {
                    if (self->destination_distance < 40.0f) {
                        self->stage = 2;
                        self->reset_map_core((void *)&TObjEneMe1Canadin__map_core_default_vec4);
                    }
                } else if (self->destination_distance < 100.0f) {
                    self->leader = (TObjEneMe1Canadin *)find_entity_by_id(self->leader_id);
                    if (self->leader->can_member_attack_target(self->current_target) != 0) {
                        self->status_flags |= 0x40000;
                    } else if (self->fn_8009E860(&d, 10000.0f) != 0) {
                        if (d < 100.0f) {
                            self->status_flags |= 0x40000;
                        }
                    } else {
                        self->stage = 4;
                    }
                }
            }
            TObjEneMe1Canadin__sub_8009EB14(self, self->position.y + self->hover_offset);
            break;
        }
        case 1:
            if (self->stage_timer == 0) {
                f32 s, c, inv, len;
                self->enemy_copy_target_destination();
                self->update_velocity();
                len = 1800.0f;
                inv = 1.0f / newton_sqrtf(len);
                c = 30.0f * inv;
                s = 30.0f * inv;
                len *= inv;
                if (self->stage_counter == 1) {
                    self->stage_counter = 0;
                    s *= -1.0f;
                } else {
                    self->stage_counter = 1;
                }
                {
                    f32 nx, nz;
                    nx = self->destination_direction.x * c + self->destination_direction.z * s;
                    nz = self->destination_direction.z * c - self->destination_direction.x * s;
                    self->destination_direction.x = nx;
                    self->destination_direction.z = nz;
                }
                self->m_484 = 0.25f * len;
                self->m_488 = 0.25f * (self->hover_height - self->hover_offset);
                play_sound_effect(0x4003AD18, &self->body_center, 0, 0);
            }
            self->fn_8009E948();
            self->stage_timer++;
            if (self->stage_timer >= 4) {
                self->stage_timer = 0;
                self->stage = 0;
                self->fn_8009E930();
            }
            self->hover_y += self->m_488;
            self->move_to_wall_clamped_destination(self->destination_direction.x, self->destination_direction.z, self->m_484);
            self->eff_light->push_history_entry(1.2f, self->node_points, self->core_color_packed);
            break;
        case 2:
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            TObjEneMe1Canadin__sub_8009EB98(self, self->position.y + self->hover_height);
            if (self->destination_distance < 18.0f) {
                if (self->fn_8009E76C() != 0) {
                    self->stage_timer = 0;
                    self->stage = 3;
                }
            } else {
                if (self->destination_distance > 40.0f) {
                    self->stage = 1;
                }
                TObjEneEpsilon__sub_800B92AC(self, 0x200, self->kind_params->m_0);
            }
            self->noop();
            break;
        case 3:
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->update_angle();
            self->stage_timer++;
            if (self->stage_timer == 20) {
                Vec v;
                VecCopy(&v, &self->node_points[5]);
                vec3_add_to(&v, &self->node_points[6]);
                v.x *= 0.5f;
                v.y *= 0.5f;
                v.z *= 0.5f;
                create_timed_particle_emitter(&v, 0x113, 0, 0x14);
            } else if (self->stage_timer == 25) {
                self->attack_count++;
                if (self->fn_8009E76C() != 0 && self->current_target->select_melee_contact_body(self, 1.0f) != 0) {
                    self->current_target->receive_physical_attack(self, 1.0f);
                    self->current_target->apply_knockback_from_attacker((u8 *)self, 3.0f);
                    if ((s32)is_player_entity_id(get_entity_id(self->current_target)) != 0 && is_target_android(self->current_target) != 0 && self->random_ratio() < 0.05f) {
                        self->current_target->apply_shock_status();
                        self->current_target->vfunc_74(0);
                    }
                }
                play_sound_effect(0x4003B219, &self->body_center, 0, 0);
            } else if (self->stage_timer > 50) {
                if (self->attack_count >= 3) {
                    self->stage = 4;
                } else {
                    self->stage_timer = 0;
                    if (self->destination_distance < 13.0f) {
                        self->stage = 3;
                    } else if (self->destination_distance < 40.0f) {
                        self->stage = 2;
                    } else {
                        self->stage = 1;
                        self->reset_map_core((void *)&canadin_formation_reset_vec4);
                        if (self->destination_distance > 100.0f) {
                            self->status_flags &= ~0x40000;
                        }
                    }
                }
            }
            self->set_target_speed_z();
            break;
        }
        self->check_collisions();
        break;
    case 5:
        self->status_flags &= ~0x40000;
        self->reset_map_core((NJS_ARGB *)&canadin_formation_reset_vec4);
        self->fn_8009E930();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::fn_8009C91C(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    Vec *dir = &self->m_490;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(8);
        self->status_flags &= ~0x400000;
        self->clear_intangible();
        self->attack_count = 0;
        self->stage = 1;
        self->fn_8009E948();
        self->stage_timer = 0;
        self->stage_counter = 0;
        self->orbit_angle_step = 0;
        self->m_484 = 0.0f;
        self->m_488 = 0.0f;
        self->m_48C = 0.0f;
        dir->x = 0.0f;
        dir->y = 0.0f;
        dir->z = 0.0f;
        break;
    case 3:
        if (self->check_retreat_trigger() == 0 && self->try_trigger_action() == 0 && self->stage_counter >= 4) {
            self->select_next_attack_state();
        }
        break;
    case 0:
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            switch (self->stage) {
            case 1: {
                if (self->stage_timer == 0) {
                    f32 t;
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    t = 8192.0f * ((TObjEneDD *)self)->calc_elapsed_scaled();
                    if (t >= 0.0f) {
                        t += 12288.0f;
                    } else {
                        t -= 12288.0f;
                    }
                    t *= 0.125f;
                    self->orbit_angle_step = t;
                    dir->x = -self->destination_direction.x;
                    dir->z = -self->destination_direction.z;
                    self->m_484 = 0.125f * (self->upper_hover_height - self->hover_offset);
                    self->m_48C = 0.125f * (70.0f - self->destination_distance);
                    self->m_488 = self->destination_distance;
                }
                self->stage_timer++;
                if (self->stage_timer >= 8) {
                    self->stage_counter++;
                    self->stage = 0;
                    self->fn_8009E930();
                }
                self->hover_y += self->m_484;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, self->orbit_angle_step);
                {
                    Vec v;
                    f32 c;
                    self->m_488 += self->m_48C;
                    v.x = dir->x * self->m_488 + self->destination.x;
                    v.z = dir->z * self->m_488 + self->destination.z;
                    subtract_vector(&v, &self->position);
                    c = normalize_vector_xz(&v);
                    self->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                self->rotation_y = (s32)(10430.38043493439 * atan2_float(dir->x, dir->z)) + 0x8000;
                self->eff_light->push_history_entry(0.8f, self->node_points, self->core_color_packed);
                break;
            }
            case 0:
                self->enemy_copy_target_destination();
                self->update_velocity();
                self->update_angle();
                self->update_hover_height();
                self->stage_timer++;
                if (self->stage_timer > 30) {
                    self->stage_timer = 0;
                    self->stage = 1;
                }
                break;
            }
            self->check_collisions();
        }
        break;
    case 5:
        self->fn_8009E930();
        break;
    }
}
#pragma pop

void TObjEneMe1Canadin::run_task(s32 arg1) {
    switch (arg1) {
    case 4:
        advance_state_5_to_4();
        set_field_378(9);
        status_flags &= ~0x400000;
        set_intangible();
        actorFlags |= 0x01000000;
        if (kind == 1) {
            leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
            leader->set_flag3c8_bit8();
        }
        attack_count = 0;
        return;
    case 3:
        if ((check_retreat_trigger() == 0) && (destination_distance < 1.0f)) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        set_target_destination(&home_position);
        update_velocity();
        update_angle();
        update_position_with_offset();
        move_with_wall_slide_commit(destination_direction.x, destination_direction.z, 0.8f);
        update_body_colliders();
        noop();
        break;
    }
}


void TObjEneMe1Canadin::fn_8009C510(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    f32 t;
    Vec v;
    f32 f;
    switch (arg1) {
    case 4:
        self->requested_action = self->move_action;
        self->advance_animation();
        self->fn_8009E378();
        self->status_flags &= ~0x400000;
        self->clear_intangible();
        self->actorFlags &= ~0x1000000;
        self->stage = 0;
        if (self->hover_y > 5.0f + (self->position.y + self->hover_height)) {
            self->stage_timer = 0;
        } else {
            self->stage_timer = 2;
        }
        self->m_488 = self->m_484 = 0.0f;
        break;
    case 3:
        if (self->stage_timer == 3) {
            self->transition_enemy_state(self->next_mode);
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&v, (const Vec *)&self->velocity.x);
        f = normalize_vector_xz(&v);
        self->move_with_wall_slide_on_ground(v.x, v.z, f);
        f *= 0.5f;
        self->velocity.x = v.x * f;
        self->velocity.z = v.z * f;
        switch (self->stage_timer) {
        case 0:
            self->m_484 -= 0.13f;
            if (self->m_484 < -4.0f) {
                self->m_484 = -4.0f;
            }
            self->hover_y += self->m_484;
            if (self->hover_y < 12.0f + (self->position.y + self->hover_height)) {
                self->stage_timer = 1;
                if (self->m_484 > -2.0f) {
                    self->m_484 = -2.0f;
                }
                self->m_488 = self->m_484 * self->m_484 / 30.0f;
            }
            break;
        case 1:
            self->m_484 += self->m_488;
            self->hover_y += self->m_484;
            if (self->m_484 >= 0.0f) {
                if (self->hover_y > self->position.y + self->hover_height) {
                    self->hover_y = self->position.y + self->hover_height;
                    self->stage = 0;
                    self->stage_timer = 2;
                }
            }
            break;
        case 2:
            self->stage++;
            if (self->stage >= self->kind_params->m_28) {
                self->stage_timer = 3;
            }
            break;
        }
        self->check_collisions();
        break;
    case 5:
        ((TObjEneDD *)self)->clear_attack_receipts();
        if (self->move_action == 5) {
            self->requested_action = 1;
        } else {
            self->requested_action = 0;
        }
        break;
    }
}
void TObjEneMe1Canadin::fn_8009C2EC(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->advance_state_4_to_5();
        self->set_field_378(0xA);
        self->clear_intangible();
        self->status_flags &= ~0x400000;
        self->status_flags |= 0x200000;
        self->actorFlags |= 0x01000000;
        self->alt_model_color = -0x7F80;
        break;
    case 3:
        if (self->stage >= 0x96) {
            self->transition_enemy_state(0xD);
            self->hp = 0;
            self->actorFlags |= 0x800;
            play_sound_effect(0x4003AD1F, &self->body_center, 0, 0);
        }
        break;
    case 1:
        break;
    case 0: {
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            self->enemy_copy_target_destination();
        }
        self->update_velocity();
        TObjEneMe1Canadin__sub_8009EB98(self, self->position.y + self->hover_height);
        TObjEneEpsilon__sub_800B92AC(self, 0x200, 0.68f);
        self->rotation_z += 0x2000;
        self->stage++;
        if (self->stage >= 0x96) {
            CanadinBehaviorParams c = canadin_projectile_param_block;
            TObjEneMe1CanadinParams *t = self->kind_params;
            c.m_4 = t->m_8;
            TObjEneDD__sub_800BA5A4(self, &c);
            self->status_flags |= 0x800000;
        }
        if (self->stage % 10 < 5) {
            self->alt_model_color = 0xFFFF0000;
        } else {
            self->alt_model_color = 0xFF000000;
        }
        play_persistent_sound(0x4003B71D, (saddr)self, (uaddr)&self->body_center, 0, 0);
        self->check_collisions();
        break;
    }
    case 5:
        self->rotation_z = 0;
        break;
    }
}
void TObjEneMe1Canadin::fn_8009C178(s32 arg1) {
    TObjEneMe1Canadin *self = this;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(0xB);
        self->set_intangible();
        self->status_flags &= ~0x400000;
        self->actorFlags |= 0x800;
        if (self->kind == 1) {
            self->leader = (TObjEneMe1Canadin *)find_entity_by_id(self->leader_id);
            self->leader->remove_member((uaddr)self);
        } else {
            self->send_entity_set_flags();
        }
        create_timed_particle_emitter(&self->body_center, 0x117, 0, 0x19);
        create_timed_particle_emitter(&self->body_center, 0x118, 0x19, 0xF);
        self->fade.set_rate_from_divisor(0x19);
        self->fade.reset_color();
        play_sound_effect(0x4003AD18, &self->body_center, 0, 0);
        return;
    case 3:
        if ((self->fade.decay_value_toward_floor() != 0) && (self->has_no_members() != 0)) {
            self->queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}
void TObjEneMe1Canadin::fn_8009BFF8(s32 arg1) {
    TObjEneMe1Canadin *self = this;

    switch (arg1) {
    case 4:
        self->set_field_378(0xE);
        self->status_flags &= ~0x400000;
        self->clear_intangible();
        self->stage = 0;
        return;
    case 3:
        if (self->stage == 2) {
            self->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        self->advance_animation();
        if (self->update_linked_position(200.0f) != 0) {
            self->stage = 2;
        }
        switch (self->stage) {
        case 0:
            self->stage_timer += 1;
            if (self->stage_timer >= 0x3C) {
                self->stage = 1;
                self->advance_state_5_to_4();
            }
            TObjEneMe1Canadin__sub_8009EB14(self, self->position.y + self->hover_offset);
            break;
        case 1:
            self->set_target_destination(&self->home_position);
            self->update_velocity();
            self->update_angle();
            self->update_position_with_offset();
            if (self->destination_distance > 2.0f) {
                self->move_with_wall_slide_commit(self->destination_direction.x, self->destination_direction.z, 0.8f);
            }
            break;
        }
        self->check_collisions();
        self->noop();
        break;
    }
}

void TObjEneMe1Canadin::state_dead(s32 arg1) {
    Vec pos;
    switch (arg1) {
    case 4:
        if (kind == 1) {
            leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
            leader->remove_member((uaddr)this);
        }
        TBoss3Volopt::create_breakup_mdl((saddr)lbl_805D4FE0, 0, (s32)(texlist), (saddr)&body_center, (s32)(rotation_y));
        status_flags |= 0x400000;
        VecCopy(&pos, &body_center);
        pos.y -= 5.0f;
        trigger_dell_biter_events(&pos);
        refresh_and_send_entity_flags();
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AA1E, &body_center, 0, 0);
        return;
    case 0:
        queue_destruction();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Canadin::update_walk_animation(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        stage = 0;
        return;
    case 0:
        advance_animation();
        stage += 1;
        if (stage > 0x5A) {
            stage = 0;
            requested_action = (requested_action + 1);
            if ((s16) requested_action >= 7) {
                requested_action = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Canadin::update_by_state(s32 arg1) {

    switch (arg1) {
    case 4:
        requested_action = 0;
        hover_y = (f32) (position.y + hover_height);
        m_484 = sin_table_lookup(rotation_y);
        m_488 = cos_table_lookup(rotation_y);
        return;
    case 0:
        advance_animation();
        hover_y = (f32) (position.y + hover_height);
        body_center.y = (f32) hover_y;
        move_with_wall_slide_commit(m_484, m_488, 0.2f);
    case 3:
    case 5:
    case 1:
        return;
    }
}


void fn_8009BD00(NJS_OBJECT *) {
    Vec *temp_r4;
    Vec *pos;
    Vec *temp_r5;
    Vec *temp_r5_2;
    switch (TObjEneMe1Canadin__render_node_index) {
    case 2:
    case 3:
        push_matrix();
        forward_split_screen_view_matrix();
        temp_r5 = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = temp_r5 + 1;
        matrix_mult_vec(0, &lbl_80500960, temp_r5);
        temp_r4 = TObjEneMe1Canadin__render_point_cursor;
        temp_r5_2 = temp_r4;
        TObjEneMe1Canadin__render_point_cursor = temp_r4 + 1;
        rotate_vector_by_matrix(0, temp_r4, temp_r5_2);
        pop_matrix();
        break;
    case 6:
    case 11:
    case 14:
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 1;
        forward_transform_to_view(&lbl_80500960, pos);
        break;
    }
    TObjEneMe1Canadin__render_node_index += 1;
}

void TObjEneMe1Canadin::render() {
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r30;
    s32 var_r29;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_canadin_model_with_debug_type();
        return;
    }
    if (status_flags & 0x400000) {
        var_r30 = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        var_r30 = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (var_r30 != 0) {
        if (status_flags & 0x01000000) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(texlist);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        apply_model_color();
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, hover_offset, 0.0f);
        rotate_matrix_y(0, rotation_y);
        temp_r0 = mode;
        var_r29 = 1;
        if ((temp_r0 == 1) || (temp_r0 == 0xB)) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                var_r29 = 0;
            }
        }
        if (var_r29 != 0) {
            if ((s16) mode != 0xA) {
                TObjEneMe1Canadin__render_node_index = 0;
                TObjEneMe1Canadin__render_point_cursor = node_points;
                VecCopy(&node_points[3], &lbl_8043A268);
                VecCopy(&node_points[1], &lbl_8043A274);
                set_chunk_model_node_callback(fn_8009BD00);
                if (var_r30 == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                set_chunk_model_node_callback(NULL);
            } else {
                rotate_matrix_z(NULL, rotation_z);
                TObjEneMe1Canadin__render_node_index = -1;
                TObjEneMe1Canadin__render_point_cursor = node_points;
                VecCopy(&node_points[3], &lbl_8043A268);
                VecCopy(&node_points[1], &lbl_8043A274);
                set_chunk_model_node_callback(fn_8009BD00);
                this->draw_with_alt_model(alt_model_color);
                set_chunk_model_node_callback(NULL);
            }
        }
        temp_r0_2 = mode;
        if ((temp_r0_2 == 1) || (temp_r0_2 == 0xB)) {
            fade.clear_flag_and_notify();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        return;
    }
    VecCopy(&node_points[3], &lbl_8043A268);
    VecCopy(&node_points[1], &lbl_8043A274);
    VecCopy(&node_points[2], &body_center);
    VecCopy(&node_points[0], &body_center);
    VecCopy(&node_points[4], &body_center);
    VecCopy(&node_points[5], &body_center);
    VecCopy(&node_points[6], &body_center);
}

void TObjEneMe1Canadin::update_if_ready() { if (get_target_info() != 0) { this->update_by_field_0x354(); } }

#pragma pool_data off
void TObjEneMe1Canadin::render_canadin_model_with_debug_type() {
    s32 temp_r3;
    if (((s32)get_target_info() != 0) && (kind == 0)) {
        temp_r3 = status_flags;
        if (temp_r3 & 0x100) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:IN FIGHTER");
        } else if (temp_r3 & 0x200) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:OUT FIGHTER");
        } else {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:UNKOWN");
        }
    }
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object((void *)model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
#pragma pool_data reset

void *TObjEneMe1CanadinLeader::create(void *set_data) {
    return new TObjEneMe1CanadinLeader(tl_04, set_data);
}

TObjEneMe1CanadinLeader::TObjEneMe1CanadinLeader(TObject *parent, void *set_data) : TObjEneMe1Canadin(parent, set_data, 2) {
    s32 i;

    m_name = TObjEneMe1CanadinLeader__class_name;
    select_model();
    upper_hover_height += 10.0f;
    member_total = 8;
    member_count = 0;
    for (i = 0; i < 8; i++) {
        members[i] = 0;
    }
    formation_state = 0;
    initialize_enemy_state(0x1D);
}

TObjEneMe1CanadinLeader::~TObjEneMe1CanadinLeader() {
}

void TObjEneMe1CanadinLeader::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_if_ready();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
        update_fade_sequence();
        update_formation_state();
    }
    copy_pos();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneMe1CanadinLeader::select_model() {
    model = (void *)bm_ene_me1_mb_resource->models[1].model;
    texlist = (saddr)bm_ene_me1_mb_resource->models[1].m_c;
}

void TObjEneMe1CanadinLeader::select_next_attack_state() {
    switch (attack_pattern) {
    case 0:
    case 1:
        attack_pattern++;
        transition_enemy_state(6);
        break;
    case 2:
        attack_pattern = 0;
        transition_enemy_state(7);
        break;
    }
}

void TObjEneMe1CanadinLeader::spawn_members() {
    saddr id;
    saddr sub;
    s32 angle;
    s32 n;
    s32 i;
    s32 j;
    Vec v;
    n = (s32)ceil_to_float((f32)member_total / (f32)kind_params->m_2C);
    if (n < 1) {
        n = 1;
    }
    angle = rotation_y;
    id = (entity_id + 1) & 0xFFFF;
    sub = set_index + 1;
    for (i = 0; i < n; i++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &position);
        angle += 0x10000 / member_total;
        members[i] = create_canadin(this, &v, id++, sub++);
        members[i]->fn_8009E334();
        member_count++;
    }
    for (j = n; j < member_total; j++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &position);
        angle += 0x10000 / member_total;
        members[j] = create_canadin(this, &v, id++, sub++);
        members[j]->fn_8009E350();
        member_count++;
    }
}

s32 TObjEneMe1CanadinLeader::check_retreat_trigger() {
    s32 i;
    if (status_flags & 0x40) {
        status_flags &= ~0x40;
        transition_enemy_state(0xb);
        for (i = 0; i < member_count; i++) {
            members[i]->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TObjEneMe1CanadinLeader::remove_member(uaddr id) {
    TObjEneMe1Canadin *member = (TObjEneMe1Canadin *)id;
    s32 i;
    for (i = 0; i < member_count; i++) {
        if (members[i] == member) {
            member_count--;
            TObjEneMe1Canadin *t = members[member_count];
            members[member_count] = member;
            members[i] = t;
            break;
        }
    }
    if (formation_state == 3) {
        s32 k = ceil_to_float((f32)member_total / (f32)kind_params->m_2C);
        if (member_count <= member_total - k) {
            leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
            leader->set_flag3c8_bit8();
        }
    }
    if (!(status_flags & 0x100000) && member_count <= member_total / 2) {
        status_flags |= 0x10;
    }
    if (member_count <= 2) {
        status_flags |= 0x40;
    }
}

int TObjEneMe1CanadinLeader::can_member_attack_target(TObjChara *) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < member_count; i++) {
        if (members[i]->fn_8009E300() == current_target) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneMe1CanadinLeader::apply_model_color() {
    *lbl_805D4FE4 = core_color_packed;
    *lbl_805D4FE8 = core_color_packed;
}

int TObjEneMe1CanadinLeader::has_no_members() {
    return (u8) (member_count <= 0);
}

void TObjEneMe1CanadinLeader::update_formation_state() {
    TObjEneMe1CanadinLeader *self = this;
    s32 i;
    s32 j;
    if (self->status_flags & 0x10) {
        self->status_flags &= ~0x10;
        self->formation_state = 7;
    }
    switch (self->formation_state) {
    case 1:
        self->fn_8009E4AC(0);
        self->formation_state = 2;
        play_sound_effect(0x4003AD1B, &self->body_center, 0, 0);
        break;
    case 2:
        if (self->fade_mode == 0) {
            self->formation_state = 3;
            self->status_flags &= ~8;
            copy_argb(&self->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (i = 0; i < self->member_count; i++) {
                if (self->members[i]->fn_8009E31C(0x200) != 0) {
                    self->members[i]->fn_8009E27C();
                }
            }
        }
        break;
    case 3:
        if (self->status_flags & 8) {
            self->formation_state = 4;
        }
        break;
    case 4:
        self->fn_8009E4AC(2);
        self->formation_state = 5;
        play_sound_effect(0x4003AD1C, &self->body_center, 0, 0);
        break;
    case 5:
        if (self->fade_mode == 0) {
            copy_argb(&self->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            self->formation_state = 6;
            for (i = 0; i < self->member_count; i++) {
                if (self->members[i]->fn_8009E31C(0x100) != 0) {
                    self->members[i]->fn_8009E27C();
                }
            }
        }
        break;
    case 6:
        break;
    case 7:
        self->fn_8009E4AC(4);
        self->formation_state = 8;
        play_sound_effect(0x4003AD1B, &self->body_center, 0, 0);
        break;
    case 8:
        if (self->fade_mode == 0) {
            self->formation_state = 9;
            copy_argb(&self->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (j = 0; j < self->member_count; j++) {
                self->members[j]->fn_8009E258();
            }
            self->fn_8009E258();
        }
        break;
    case 0:
    case 9:
        break;
    }
}

void TObjEneMe1CanadinLeader::vfunc_110(s32 arg1) {
    s32 k;
    s32 i;
    s32 j;

    switch (arg1) {
    case 4: {
        advance_state_5_to_4();
        set_field_378(3);
        clear_intangible();
        const f32 *p = (const f32 *)&canadin_formation_reset_vec4;
        core_color.r = p[1];
        core_color.g = p[2];
        core_color.b = p[3];
        stage = 0;
        for (k = 2, i = 0; i < member_count; k += 2, i++) {
            members[i]->set_leader_index(current_target, k);
        }
        break;
    }
    case 3:
        if (status_flags & 2) {
            status_flags &= ~2;
            formation_state = 1;
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        switch (stage) {
        case 0:
            attack_delay--;
            if (attack_delay <= 0) {
                fade_mode = 2;
                stage = 1;
                play_sound_effect(0x4003B21A, &body_center, 0, 0);
            }
            break;
        case 1:
            if (fade_mode == 0) {
                status_flags |= 0x8000;
                for (j = 0; j < member_count; j++) {
                    if (members[j]->fn_8009E36C() == 0) {
                        break;
                    }
                }
                if (j == member_count) {
                    set_attack_flag();
                    s32 m;
                    for (m = 0; m < member_count; m++) {
                        members[m]->set_attack_flag();
                    }
                }
            }
            update_move();
            break;
        }
        TObjEneMe1Canadin__sub_8009EB14(this, 25.0f + position.y);
        check_collisions();
        break;
    case 5:
        clear_invulnerable();
        break;
    }
}

void TObjEneMe1CanadinLeader::vfunc_111(s32 mode) {
    switch (mode) {
    case 4:
        advance_state_5_to_4();
        set_field_378(4);
        clear_intangible();
        break;
    case 3:
        if (status_flags & 4) {
            select_next_attack_state();
        }
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update_move();
        update_hover_height();
        check_collisions();
        break;
    case 5:
        break;
    }
}

void TObjEneMe1CanadinLeader::state_dead(s32 mode) {
    s32 i;
    switch (mode) {
    case 4:
        TBoss3Volopt::create_breakup_mdl((saddr)lbl_805D4FDC, 0, (s32)texlist, (saddr)&body_center, (s32)rotation_y);
        for (i = 0; i < member_count; i++) {
            members[i]->set_flag3c8_bit20();
        }
        status_flags |= 0x400000;
        play_sound_effect(0x4003B71D, &body_center, 0, 0);
        refresh_lobby_state();
        break;
    case 0:
        if (has_no_members() != 0) {
            send_entity_set_flags();
            queue_destruction();
        }
        break;
    case 5:
        actorFlags &= ~0x200;
        break;
    case 1:
        return;
    case 3:
        return;
    }
}
