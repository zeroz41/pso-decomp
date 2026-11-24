#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/AngleUnits.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/math/FloatRounding.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/boss/DragonAttackParams.h"
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
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixOps.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


extern "C" {
// inferred: the BML resource load_resources reads through bm_ene_me1_mb_resource_descriptor
BmlResource *bm_ene_me1_mb_resource;
// inferred: node counter of the render callback (TObjEneDf2Bringer__render_node_index twin)
u32 TObjEneMe1Canadin__render_node_index;
Vec *TObjEneMe1Canadin__render_point_cursor;



TBreakUpMdlData *canadin_leader_breakup_model;
TBreakUpMdlData *canadin_breakup_model;
// Colour words of the first material chunk (polygon_list + 2) of nodes 3 and 2 of the leader and member models;
// apply_model_color writes core_color_packed into them.
s32 *canadin_leader_node3_diffuse;
s32 *canadin_leader_node2_diffuse;
s32 *canadin_node3_diffuse;
s32 *canadin_node2_diffuse;

TObjEneMe1CanadinMovement canadin_setup_param_block = { 225.0f, 0.0f, 0x600 };
CollisionBody canadin_collision_body = { { 0.0f, 0.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003 };
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
const Vec canadin_node3_axis = { 0.0f, 0.0f, 1.0f };
const Vec canadin_node2_axis = { 0.0f, -1.0f, 0.0f };
const NJS_ARGB canadin_formation_reset_vec4 = { 1.0f, 0.0f, 0.2f, 1.0f };
const NJS_ARGB TObjEneMe1Canadin__map_core_default_vec4 = { 1.0f, 1.0f, 0.0f, 0.2f };
const NJS_ARGB canadin_formation_fade_start_color = { 1.0f, 0.2f, 1.0f, 0.0f };
TObjMotionAction canadin_action_table[7] = {
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
const DragonAttackParams canadin_discharge_attack_params = { 3, 5.0f, 3.0f, {3.0f, 1} };
const DragonAttackParams canadin_self_destruct_attack_params = { 3, 10.0f, 20.0f, {3.0f, 1} };
const char *TObjEneMe1Canadin__class_name = "TObjEneMe1Canadin";
const char *TObjEneMe1CanadinLeader__class_name = "TObjEneMe1CanadinLeader";
player_stats *canadin_boss_stat_handle_table[3];
AttackParams *canadin_shared_handler_b_table[3];
ActorParamBlock *canadin_object_handle_table[3];
TObjEneMe1CanadinParams *canadin_shared_handler_a_table[3];
Vec canadin_node_origin;

}


// Motion setup passed to TLobby::spawn_npc_enemy: (motions, animation table, 0, 0x70000).

// Floor load: loads the Canadin archive, the per-difficulty stats and the breakup models, and spawns the
// two NPC copies.
void TObjEneMe1Canadin::load_resources() {
    s32 i;
    NJS_OBJECT *model;
    NJS_OBJECT *model2;
    void *p;

    canadin_node_origin.x = 0.0f;
    canadin_node_origin.y = 0.0f;
    canadin_node_origin.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        bm_ene_me1_mb_resource = load_enemy_bml_resource_named(&bm_ene_me1_mb_resource_descriptor, "bm_ene_me1_mb_a.bml");
    } else {
        bm_ene_me1_mb_resource = load_enemy_bml_resource(&bm_ene_me1_mb_resource_descriptor);
    }
    for (i = 0; i < 3; i++) {
        canadin_boss_stat_handle_table[i] = TLobby::register_boss(canadin_base_stat_ids[i]);
        canadin_shared_handler_b_table[i] = TLobby::dispatch_shared_handler_b(canadin_attack_stat_ids[i]);
        canadin_object_handle_table[i] = TLobby::register_object(canadin_resist_stat_ids[i]);
        canadin_shared_handler_a_table[i] = (TObjEneMe1CanadinParams *)TLobby::dispatch_shared_handler_a(canadin_param_ids[i]);
    }
    TObjEneMe1Canadin__render_node_index = 0;
    p = new TBreakUpMdlData(bm_ene_me1_mb_resource->models[1].model);
    canadin_leader_breakup_model = (TBreakUpMdlData *)p;
    p = new TBreakUpMdlData(bm_ene_me1_mb_resource->models[0].model);
    canadin_breakup_model = (TBreakUpMdlData *)p;
    model = bm_ene_me1_mb_resource->models[1].model;
    canadin_leader_node3_diffuse = (s32 *)(((NJS_CNK_MODEL *)find_model_node(model, 3)->model)->polygon_list + 2);
    canadin_leader_node2_diffuse = (s32 *)(((NJS_CNK_MODEL *)find_model_node(model, 2)->model)->polygon_list + 2);
    model2 = bm_ene_me1_mb_resource->models[0].model;
    canadin_node3_diffuse = (s32 *)(((NJS_CNK_MODEL *)find_model_node(model2, 3)->model)->polygon_list + 2);
    canadin_node2_diffuse = (s32 *)(((NJS_CNK_MODEL *)find_model_node(model2, 2)->model)->polygon_list + 2);
    TObjPlayer::init_alt_model();
    s16 ids[2] = { 0x17, 0x18 };
    NpcAnimationBinding params = { bm_ene_me1_mb_resource->motions, canadin_action_table, 0, 0, 7 };
    for (i = 0; i < 2; i++) {
        TObjNpcEnemy::register_animated_chunk(ids[i], bm_ene_me1_mb_resource->models[i].model, bm_ene_me1_mb_resource->models[1].texlist, &params, 8.0f, 15.0f);
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
    if (canadin_breakup_model != NULL) {
        delete canadin_breakup_model;
        canadin_breakup_model = NULL;
    }
    if (canadin_leader_breakup_model != NULL) {
        delete canadin_leader_breakup_model;
        canadin_leader_breakup_model = NULL;
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
    apply_parameters();
    this->leader = this;
    this->kind = kind;
    setup_enemy();
}

TObjEneMe1Canadin::TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Canadin__class_name;
    this->leader = leader;
    init_common_from(this->leader);
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
    init_model(&canadin_collision_body, 1);
    set_action_table(canadin_action_table);
    set_motion_list(bm_ene_me1_mb_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(canadin_boss_stat_handle_table[kind], canadin_shared_handler_b_table[kind], canadin_object_handle_table[kind]);
    set_state_flag_4();
    movementParameters = &canadin_setup_param_block;
    initialize_enemy_state(0x1C);
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x2D);
    enemy_init_validate_period(0x2D);
    set_active();
    actorFlags |= 0x01000000;
    kind_params = canadin_shared_handler_a_table[kind];
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
    pad_40c = 0;
    alt_model_color = 0;
    for (i = 0; i < 7; i++) {
        VecCopy(&node_points[i], &position);
    }
    attack_pattern = 0;
    stage = 0;
    stage_timer = 0;
    stage_counter = 0;
    pad_47c = 0;
    orbit_angle_step = 0;
    work_speed = 0.0f;
    orbit_radius = 0.0f;
    orbit_radius_step = 0.0f;
    work_point.x = 0.0f;
    work_point.y = 0.0f;
    work_point.z = 0.0f;
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
        leader_id = leader->get_entity_id();
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
        run_demo_task();
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
    if ((mode != 0xD) && (mode != 0xB)) {
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

void TObjEneMe1Canadin::apply_parameters() {
    if ((s32) floor_to_float(parameters[0]) == 0) {
        set_in_fighter();
        return;
    }
    set_out_fighter();
}

void TObjEneMe1Canadin::select_model() {
    model = (void *)bm_ene_me1_mb_resource->models[0].model;
    texlist = bm_ene_me1_mb_resource->models[1].texlist;
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

CsnHit *TObjEneMe1Canadin::move_xz_on_ground(const Vec *arg) {
    CsnHit *result = TObjEneDD::move_xz_on_ground(arg);
    if (result == NULL) {
        status_flags &= ~0x1000000;
    } else {
        status_flags |= 0x01000000;
    }
    return result;
}


void TObjEneMe1Canadin::approach_hover_y(f32 height) {
    f32 delta;
    delta = height - hover_y;
    status_flags &= ~0x80000;
    if (delta >= 0.5f) {
        hover_y += 0.5f;
    } else if (delta <= -0.5f) {
        hover_y -= 0.5f;
    } else {
        hover_y = height;
        status_flags |= 0x80000;
    }
}

void TObjEneMe1Canadin::approach_upper_hover_height() {
    approach_hover_y(position.y + upper_hover_height);
}


void TObjEneMe1Canadin::hover_toward(f32 height) {
    Vec pos;
    approach_hover_y(height);
    VecCopy(&pos, &position);
    pos.y = hover_y;
    move_xz_on_ground(&pos);
}

void TObjEneMe1Canadin::update_hover_height() {
    hover_toward(hover_height + position.y);
}

void TObjEneMe1Canadin::update_upper_hover_height() {
    hover_toward(upper_hover_height + position.y);
}

void TObjEneMe1Canadin::update_angle() {
    rotation_y = approach_angle_limited(rotation_y, (s32) (RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z)), 0x400);
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


void TObjEneMe1Canadin::set_melee_body_flags() {
    bodies->flags |= 0x28;
}
void TObjEneMe1Canadin::clear_melee_body_flags() {
    bodies->flags &= ~0x28;
}
s32 TObjEneMe1Canadin::find_attack_target(f32 *out, f32 squared_range) {
    TargetCandidate list[5];
    s32 found;
    s32 count;
    TObjChara *player;
    s32 i;
    found = 0;
    *out = -1.0f;
    count = collect_enemy_target_candidates(this, list, squared_range);
    for (i = 0; i < count; i++) {
        player = get_player_by_client_id(list[i].id);
        if (player != current_target) {
            leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
            if (leader->can_member_attack_target(player) != 0) {
                *out = newton_sqrtf(list[i].dist);
                found = 1;
                set_target_player(player);
                break;
            }
        }
    }
    return found;
}

s32 TObjEneMe1Canadin::check_target() {
    f32 dist;
    s32 in_range;

    in_range = 0;
    if (destination_distance < 70.0f) {
        in_range = 1;
        leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
        if ((leader->can_member_attack_target(current_target) == 0) && (find_attack_target(&dist, 22500.0f) != 0) && (dist > 70.0f)) {
            in_range = 0;
        }
    }
    return in_range;
}

void TObjEneMe1Canadin::advance_state_4_to_5() {
    if (move_action == 4) {
        requested_action = 2;
        move_action = 5;
    }
}

void TObjEneMe1Canadin::advance_state_5_to_4() {
    if (this->move_action == 5) {
        this->requested_action = 3;
        this->move_action = 4;
    }
}


s32 TObjEneMe1Canadin::is_hover_low() {
    return hover_offset < 20.0f;
}

void TObjEneMe1Canadin::spawn_members() {  }

s32 TObjEneMe1Canadin::check_retreat_trigger() {
    if (status_flags & 0x20) {
        status_flags &= 0xFFFFFFDF;
        transition_enemy_state(0xA);
        pad_40c = 0;
        return 1;
    }
    if (status_flags & 0x40) {
        status_flags &= 0xFFFFFFBF;
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


void TObjEneMe1Canadin::start_fade_sequence(s32 sequence) {
    set_core_color(&canadin_formation_fade_start_color);
    fade_mode = 3;
    fade_sequence = sequence;
    fade_step_timer = 2;
    fade_cursor = 0;
}

void TObjEneMe1Canadin::set_core_color(const NJS_ARGB *color) {
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
    *canadin_node3_diffuse = core_color_packed;
    *canadin_node2_diffuse = core_color_packed;
}

int TObjEneMe1Canadin::has_no_members() { return 1; }


void TObjEneMe1Canadin::wake_leader() {
    if (mode == 2) {
        leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
        leader->order_activation_now();
    }
}
int TObjEneMe1Canadin::is_activated() { return (status_flags >> 15) & 0x1; }
void TObjEneMe1Canadin::set_in_fighter() {
    status_flags |= 0x100;
    status_flags &= ~0x200;
}
void TObjEneMe1Canadin::set_out_fighter() {
    status_flags |= 0x200;
    status_flags &= ~0x100;
}
s32 TObjEneMe1Canadin::has_status_flag(s32 mask) {
    return (status_flags & mask) != 0;
}
TObjChara *TObjEneMe1Canadin::get_attacking_target() {
    if (status_flags & 0x40000) {
        return current_target;
    }
    return NULL;
}

void TObjEneMe1Canadin::remove_member(TObjEneMe1Canadin *) {  }

int TObjEneMe1Canadin::can_member_attack_target(TObjChara *) { return 1; }


void TObjEneMe1Canadin::order_activation_now() {
    attack_delay = 0;
    status_flags |= 1;
}

void TObjEneMe1Canadin::order_activation(TObjChara *target, s32 delay) {
    set_target_player(target);
    attack_delay = delay;
    status_flags |= 1;
}

void TObjEneMe1Canadin::start_formation() { status_flags |= 0x2; }


void TObjEneMe1Canadin::order_attack() { status_flags |= 0x4; }

void TObjEneMe1Canadin::set_flag3c8_bit8() { status_flags |= 0x8; }


void TObjEneMe1Canadin::release_from_formation() {
    status_flags |= 0x100000 | 4;
}

void TObjEneMe1Canadin::set_flag3c8_bit20() { status_flags |= 0x20; }

void TObjEneMe1Canadin::set_flag3c8_bit40() { status_flags |= 0x40; }


void TObjEneMe1Canadin::deliver_discharge_attack(Vec *pos) {
    DragonAttackParams params = canadin_discharge_attack_params;
    params.power = kind_params->ranged_power;
    TObjEneDD::setup(this, pos, &params);
}

// The state names are read from the bodies and shared with the Gee's twin states (Gee state n + 1
// from state 2 on; the Gee has a second appear state at 2, the Canadin a self-destruct at 10):
// spawn (spawns the members), appear (fade-in), hover (until the leader orders the activation, status 1),
// activate (after attack_delay the core lights up, status 0x8000), rise (to upper_hover_height),
// formation (waits for the leader's attack order, status 4), ranged/melee attack, orbit (circles the
// target, orbit_angle_step), regroup (back to home_position, tells the leader, status 8), self-destruct
// (spins 150 frames, hp = 0), vanish, return home, motion test (steps through every action), move forward.
void TObjEneMe1Canadin::dispatch_action(u32 which, s32 arg) {
    switch (which) {
    case 0:
        state_spawn(arg);
        break;
    case 1:
        state_appear(arg);
        break;
    case 2:
        state_hover(arg);
        break;
    case 3:
        state_activate(arg);
        break;
    case 4:
        state_rise(arg);
        break;
    case 5:
        state_formation(arg);
        break;
    case 6:
        state_ranged_attack(arg);
        break;
    case 7:
        state_melee_attack(arg);
        break;
    case 8:
        state_orbit(arg);
        break;
    case 9:
        state_regroup(arg);
        break;
    case 10:
        state_self_destruct(arg);
        break;
    case 11:
        state_vanish(arg);
        break;
    case 12:
        hurt_state(arg);
        break;
    case 13:
        state_dead(arg);
        break;
    case 14:
        state_return_home(arg);
        break;
    case 16:
        state_motion_test(arg);
        break;
    case 17:
        state_move_forward(arg);
        break;
    }
}

void TObjEneMe1Canadin::state_spawn(s32 msg) {
    switch (msg) {
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


void TObjEneMe1Canadin::state_appear(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(2);
        this->status_flags &= ~0x400000;
        this->set_intangible();
        this->actorFlags |= 0x01000000;
        this->move_action = 4;
        this->fade_mode = 1;
        this->fade.start_fade_in();
        TBoss3Volopt__sub_800D8D88((saddr)&this->position);
        return;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        if (this->kind == 2) {
            this->hover_toward(25.0f + this->position.y);
        } else {
            this->update_hover_height();
        }
        this->update_body_colliders();
        break;
    }
}

void TObjEneMe1Canadin::state_hover(s32 msg) {
    switch (msg) {
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
            if (status_flags & 1) {
                status_flags &= 0xFFFFFFFE;
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
            hover_toward(25.0f + position.y);
        } else {
            update_hover_height();
        }
        this->check_collisions();
        break;
    case 5:
    case 1:
        break;
    }
}

void TObjEneMe1Canadin::state_activate(s32 msg) {
    switch (msg) {
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
            if (status_flags & 2) {
                status_flags &= ~2;
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
                    this->start_formation();
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
        update_hover_height();
        this->check_collisions();
        return;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1Canadin::state_rise(s32 msg) {
    switch (msg) {
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
        this->update_upper_hover_height();
        this->check_collisions();
        noop();
        break;
    }
}

void TObjEneMe1Canadin::state_formation(s32 msg) {
    switch (msg) {
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
            if (status_flags & 4) {
                status_flags &= 0xFFFFFFFB;
                if (has_status_flag(0x200) != 0) {
                    stage = 1;
                    start_fade_sequence(1);
                } else {
                    stage = 2;
                    advance_state_4_to_5();
                    start_fade_sequence(3);
                }
            }
            update_move();
            update_upper_hover_height();
            break;
        case 1:
            if (fade_mode == 0) {
                stage = 3;
            }
            update_move();
            update_upper_hover_height();
            break;
        case 2:
            update_move();
            if (fade_mode != 0) {
                update_upper_hover_height();
            } else {
                hover_toward(position.y + random_hover_height);
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
void TObjEneMe1Canadin::state_ranged_attack(s32 msg) {
    Vec *pos;
    pos = &this->work_point;
    switch (msg) {
    case 4:
        this->set_field_378(6);
        this->status_flags |= 0x10000;
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags |= 0x01000000;
        this->set_core_color(&canadin_formation_reset_vec4);
        this->stage = 1;
        this->stage_timer = 0;
        this->eff_line = 0;
        this->particle_emitter = 0;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->try_trigger_action() == 0 && this->stage == 6) {
            if (this->status_flags & 0x100000) {
                this->transition_enemy_state(8);
            } else {
                this->transition_enemy_state(9);
            }
        }
        break;
    case 0:
        this->advance_animation();
        if (this->stage == 1) {
            if (this->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        this->enemy_copy_target_destination();
        switch (this->stage) {
        case 1:
            this->update_velocity();
            if (this->check_target() != 0) {
                this->stage = 2;
                this->status_flags |= 0x40000;
                this->advance_state_4_to_5();
            } else {
                this->advance_state_5_to_4();
            }
            TObjEneEpsilon__sub_800B92F8(this, 0x200, 0.5f);
            break;
        case 2:
            this->update_velocity();
            this->update_angle();
            if (this->requested_action == 1) {
                this->stage = 3;
                this->set_core_color(&TObjEneMe1Canadin__map_core_default_vec4);
                VecCopy(pos, &this->destination);
                this->eff_line = new TObjEneMe1Canadin_EffLine(this, this->node_points, pos);
                play_sound_effect(0x4002B71B, &this->body_center, 0, 0);
                play_sound_effect(0x4002B51E, &this->body_center, 0, 0);
            }
            break;
        case 3: {
            Vec v;
            this->update_velocity();
            this->update_angle();
            VecCopy(&v, &this->destination);
            subtract_vector(&v, pos);
            if (normalize_vector_xz(&v) < 0.6f) {
                VecCopy(pos, &this->destination);
            } else {
                pos->x = 0.6f * v.x + pos->x;
                pos->y = 0.6f * v.y + pos->y;
                pos->z = 0.6f * v.z + pos->z;
            }
            if (this->particle_emitter == 0) {
                this->particle_emitter = create_particle_emitter(this->node_points, 0xF7);
                if (this->particle_emitter != 0) {
                    this->particle_emitter->enable();
                }
            } else {
                this->particle_emitter->set_position(this->node_points);
            }
            this->stage_timer++;
            if (this->stage_timer > this->kind_params->aim_time) {
                this->stage = 4;
                this->stage_timer = 0;
                this->eff_line->queue_destruction();
                this->eff_line = 0;
                if (this->particle_emitter != 0) {
                    this->particle_emitter->queue_destruction();
                    this->particle_emitter = 0;
                }
            }
            break;
        }
        case 4:
            this->stage_timer++;
            if (this->stage_timer >= this->kind_params->fire_delay) {
                this->stage = 5;
                this->stage_timer = 0;
                this->status_flags &= ~0x40000;
                this->set_core_color(&canadin_formation_reset_vec4);
                this->attack_count++;
                new TObjEneMe1Canadin_EffDischarge(this, this->node_points, pos);
                play_sound_effect(0x4002A408, &this->body_center, 0, 0);
            }
            break;
        case 5:
            this->stage_timer++;
            if (this->stage_timer > this->kind_params->shot_interval) {
                this->stage_timer = 0;
                if (this->attack_count >= this->kind_params->shots_per_attack) {
                    this->stage = 6;
                } else {
                    this->stage = 1;
                }
            }
            break;
        }
        this->approach_upper_hover_height();
        this->check_collisions();
        this->noop();
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->set_core_color(&canadin_formation_reset_vec4);
        if (this->eff_line != 0) {
            this->eff_line->queue_destruction();
            this->eff_line = 0;
        }
        if (this->particle_emitter != 0) {
            this->particle_emitter->queue_destruction();
            this->particle_emitter = 0;
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma optimization_level 3
void TObjEneMe1Canadin::state_melee_attack(s32 msg) {
    switch (msg) {
    case 4:
        this->advance_state_4_to_5();
        this->set_field_378(7);
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags &= ~0x1000000;
        this->status_flags &= ~0x80000;
        this->stage = 0;
        this->stage_timer = 40;
        this->stage_counter = 0;
        this->work_speed = 0.0f;
        this->orbit_radius = 0.0f;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->try_trigger_action() == 0 && this->stage == 4) {
            this->transition_enemy_state(8);
        }
        break;
    case 0:
        this->advance_animation();
        if (this->stage == 0) {
            if (this->update_linked_position(200.0f) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        switch (this->stage) {
        case 4:
            break;
        case 0: {
            f32 d;
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->stage_timer > 40) {
                this->stage_timer = 0;
                this->stage = 1;
                if (this->status_flags & 0x40000) {
                    if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                        this->set_core_color(&TObjEneMe1Canadin__map_core_default_vec4);
                    }
                } else if (this->destination_distance < 100.0f) {
                    this->leader = (TObjEneMe1Canadin *)find_entity_by_id(this->leader_id);
                    if (this->leader->can_member_attack_target(this->current_target) != 0) {
                        this->status_flags |= 0x40000;
                    } else if (this->find_attack_target(&d, 10000.0f) != 0) {
                        if (d < 100.0f) {
                            this->status_flags |= 0x40000;
                        }
                    } else {
                        this->stage = 4;
                    }
                }
            }
            this->hover_toward(this->position.y + this->hover_offset);
            break;
        }
        case 1:
            if (this->stage_timer == 0) {
                f32 s, c, inv, len;
                this->enemy_copy_target_destination();
                this->update_velocity();
                len = 1800.0f;
                inv = 1.0f / newton_sqrtf(len);
                c = 30.0f * inv;
                s = 30.0f * inv;
                len *= inv;
                if (this->stage_counter == 1) {
                    this->stage_counter = 0;
                    s *= -1.0f;
                } else {
                    this->stage_counter = 1;
                }
                {
                    f32 nx, nz;
                    nx = this->destination_direction.x * c + this->destination_direction.z * s;
                    nz = this->destination_direction.z * c - this->destination_direction.x * s;
                    this->destination_direction.x = nx;
                    this->destination_direction.z = nz;
                }
                this->work_speed = 0.25f * len;
                this->orbit_radius = 0.25f * (this->hover_height - this->hover_offset);
                play_sound_effect(0x4003AD18, &this->body_center, 0, 0);
            }
            this->set_melee_body_flags();
            this->stage_timer++;
            if (this->stage_timer >= 4) {
                this->stage_timer = 0;
                this->stage = 0;
                this->clear_melee_body_flags();
            }
            this->hover_y += this->orbit_radius;
            this->move_to_wall_clamped_destination(this->destination_direction.x, this->destination_direction.z, this->work_speed);
            this->eff_light->push_history_entry(1.2f, this->node_points, this->core_color_packed);
            break;
        case 2:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->approach_hover_y(this->position.y + this->hover_height);
            if (this->destination_distance < 18.0f) {
                if (this->is_hover_low() != 0) {
                    this->stage_timer = 0;
                    this->stage = 3;
                }
            } else {
                if (this->destination_distance > 40.0f) {
                    this->stage = 1;
                }
                TObjEneEpsilon__sub_800B92AC(this, 0x200, this->kind_params->melee_speed);
            }
            this->noop();
            break;
        case 3:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->stage_timer == 20) {
                Vec v;
                VecCopy(&v, &this->node_points[5]);
                vec3_add_to(&v, &this->node_points[6]);
                v.x *= 0.5f;
                v.y *= 0.5f;
                v.z *= 0.5f;
                create_timed_particle_emitter(&v, 0x113, 0, 0x14);
            } else if (this->stage_timer == 25) {
                this->attack_count++;
                if (this->is_hover_low() != 0 && this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                    this->current_target->receive_physical_attack(this, 1.0f);
                    this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                    if ((s32)is_player_entity_id(this->current_target->get_entity_id()) != 0 && is_target_android(this->current_target) != 0 && this->random_ratio() < 0.05f) {
                        this->current_target->apply_shock_status();
                        this->current_target->sync_enemy_state(0);
                    }
                }
                play_sound_effect(0x4003B219, &this->body_center, 0, 0);
            } else if (this->stage_timer > 50) {
                if (this->attack_count >= 3) {
                    this->stage = 4;
                } else {
                    this->stage_timer = 0;
                    if (this->destination_distance < 13.0f) {
                        this->stage = 3;
                    } else if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                    } else {
                        this->stage = 1;
                        this->set_core_color(&canadin_formation_reset_vec4);
                        if (this->destination_distance > 100.0f) {
                            this->status_flags &= ~0x40000;
                        }
                    }
                }
            }
            this->update_hover_height();
            break;
        }
        this->check_collisions();
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->set_core_color(&canadin_formation_reset_vec4);
        this->clear_melee_body_flags();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::state_orbit(s32 msg) {
    Vec *dir = &this->work_point;
    switch (msg) {
    case 4:
        this->advance_state_4_to_5();
        this->set_field_378(8);
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->attack_count = 0;
        this->stage = 1;
        this->set_melee_body_flags();
        this->stage_timer = 0;
        this->stage_counter = 0;
        this->orbit_angle_step = 0;
        this->work_speed = 0.0f;
        this->orbit_radius = 0.0f;
        this->orbit_radius_step = 0.0f;
        dir->x = 0.0f;
        dir->y = 0.0f;
        dir->z = 0.0f;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->try_trigger_action() == 0 && this->stage_counter >= 4) {
            this->select_next_attack_state();
        }
        break;
    case 0:
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            switch (this->stage) {
            case 1: {
                if (this->stage_timer == 0) {
                    f32 t;
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    t = 8192.0f * ((TObjEneDD *)this)->calc_elapsed_scaled();
                    if (t >= 0.0f) {
                        t += 12288.0f;
                    } else {
                        t -= 12288.0f;
                    }
                    t *= 0.125f;
                    this->orbit_angle_step = t;
                    dir->x = -this->destination_direction.x;
                    dir->z = -this->destination_direction.z;
                    this->work_speed = 0.125f * (this->upper_hover_height - this->hover_offset);
                    this->orbit_radius_step = 0.125f * (70.0f - this->destination_distance);
                    this->orbit_radius = this->destination_distance;
                }
                this->stage_timer++;
                if (this->stage_timer >= 8) {
                    this->stage_counter++;
                    this->stage = 0;
                    this->clear_melee_body_flags();
                }
                this->hover_y += this->work_speed;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, this->orbit_angle_step);
                {
                    Vec v;
                    f32 c;
                    this->orbit_radius += this->orbit_radius_step;
                    v.x = dir->x * this->orbit_radius + this->destination.x;
                    v.z = dir->z * this->orbit_radius + this->destination.z;
                    subtract_vector(&v, &this->position);
                    c = normalize_vector_xz(&v);
                    this->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(dir->x, dir->z)) + 0x8000;
                this->eff_light->push_history_entry(0.8f, this->node_points, this->core_color_packed);
                break;
            }
            case 0:
                this->enemy_copy_target_destination();
                this->update_velocity();
                this->update_angle();
                this->update_upper_hover_height();
                this->stage_timer++;
                if (this->stage_timer > 30) {
                    this->stage_timer = 0;
                    this->stage = 1;
                }
                break;
            }
            this->check_collisions();
        }
        break;
    case 5:
        this->clear_melee_body_flags();
        break;
    }
}
#pragma pop

void TObjEneMe1Canadin::state_regroup(s32 msg) {
    switch (msg) {
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
        approach_upper_hover_height();
        move_with_wall_slide_commit(destination_direction.x, destination_direction.z, 0.8f);
        update_body_colliders();
        noop();
        break;
    }
}


void TObjEneMe1Canadin::hurt_state(s32 msg) {
    f32 t;
    Vec v;
    f32 f;
    switch (msg) {
    case 4:
        this->requested_action = this->move_action;
        this->advance_animation();
        this->wake_leader();
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags &= ~0x1000000;
        this->stage = 0;
        if (this->hover_y > 5.0f + (this->position.y + this->hover_height)) {
            this->stage_timer = 0;
        } else {
            this->stage_timer = 2;
        }
        this->orbit_radius = this->work_speed = 0.0f;
        break;
    case 3:
        if (this->stage_timer == 3) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, (const Vec *)&this->velocity.x);
        f = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, f);
        f *= 0.5f;
        this->velocity.x = v.x * f;
        this->velocity.z = v.z * f;
        switch (this->stage_timer) {
        case 0:
            this->work_speed -= 0.13f;
            if (this->work_speed < -4.0f) {
                this->work_speed = -4.0f;
            }
            this->hover_y += this->work_speed;
            if (this->hover_y < 12.0f + (this->position.y + this->hover_height)) {
                this->stage_timer = 1;
                if (this->work_speed > -2.0f) {
                    this->work_speed = -2.0f;
                }
                this->orbit_radius = this->work_speed * this->work_speed / 30.0f;
            }
            break;
        case 1:
            this->work_speed += this->orbit_radius;
            this->hover_y += this->work_speed;
            if (this->work_speed >= 0.0f) {
                if (this->hover_y > this->position.y + this->hover_height) {
                    this->hover_y = this->position.y + this->hover_height;
                    this->stage = 0;
                    this->stage_timer = 2;
                }
            }
            break;
        case 2:
            this->stage++;
            if (this->stage >= this->kind_params->hurt_wait_time) {
                this->stage_timer = 3;
            }
            break;
        }
        this->check_collisions();
        break;
    case 5:
        ((TObjEneDD *)this)->clear_attack_receipts();
        if (this->move_action == 5) {
            this->requested_action = 1;
        } else {
            this->requested_action = 0;
        }
        break;
    }
}
void TObjEneMe1Canadin::state_self_destruct(s32 msg) {
    switch (msg) {
    case 4:
        this->advance_state_4_to_5();
        this->set_field_378(0xA);
        this->clear_intangible();
        this->status_flags &= ~0x400000;
        this->status_flags |= 0x200000;
        this->actorFlags |= 0x01000000;
        this->alt_model_color = -0x7F80;
        break;
    case 3:
        if (this->stage >= 0x96) {
            this->transition_enemy_state(0xD);
            this->hp = 0;
            this->actorFlags |= 0x800;
            play_sound_effect(0x4003AD1F, &this->body_center, 0, 0);
        }
        break;
    case 1:
        break;
    case 0: {
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
        }
        this->update_velocity();
        this->approach_hover_y(this->position.y + this->hover_height);
        TObjEneEpsilon__sub_800B92AC(this, 0x200, 0.68f);
        this->rotation_z += 0x2000;
        this->stage++;
        if (this->stage >= 0x96) {
            DragonAttackParams c = canadin_self_destruct_attack_params;
            TObjEneMe1CanadinParams *t = this->kind_params;
            c.power = t->self_destruct_power;
            TObjEneDD__sub_800BA5A4(this, &c);
            this->status_flags |= 0x800000;
        }
        if (this->stage % 10 < 5) {
            this->alt_model_color = 0xFFFF0000;
        } else {
            this->alt_model_color = 0xFF000000;
        }
        play_persistent_sound(0x4003B71D, this, &this->body_center, 0, 0);
        this->check_collisions();
        break;
    }
    case 5:
        this->rotation_z = 0;
        break;
    }
}
void TObjEneMe1Canadin::state_vanish(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xB);
        this->set_intangible();
        this->status_flags &= ~0x400000;
        this->actorFlags |= 0x800;
        if (this->kind == 1) {
            this->leader = (TObjEneMe1Canadin *)find_entity_by_id(this->leader_id);
            this->leader->remove_member(this);
        } else {
            this->send_entity_set_flags();
        }
        create_timed_particle_emitter(&this->body_center, 0x117, 0, 0x19);
        create_timed_particle_emitter(&this->body_center, 0x118, 0x19, 0xF);
        this->fade.set_rate_from_divisor(0x19);
        this->fade.reset_color();
        play_sound_effect(0x4003AD18, &this->body_center, 0, 0);
        return;
    case 3:
        if ((this->fade.decay_value_toward_floor() != 0) && (this->has_no_members() != 0)) {
            this->queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}
void TObjEneMe1Canadin::state_return_home(s32 msg) {

    switch (msg) {
    case 4:
        this->set_field_378(0xE);
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->stage = 0;
        return;
    case 3:
        if (this->stage == 2) {
            this->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->stage = 2;
        }
        switch (this->stage) {
        case 0:
            this->stage_timer += 1;
            if (this->stage_timer >= 0x3C) {
                this->stage = 1;
                this->advance_state_5_to_4();
            }
            this->hover_toward(this->position.y + this->hover_offset);
            break;
        case 1:
            this->set_target_destination(&this->home_position);
            this->update_velocity();
            this->update_angle();
            this->approach_upper_hover_height();
            if (this->destination_distance > 2.0f) {
                this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, 0.8f);
            }
            break;
        }
        this->check_collisions();
        this->noop();
        break;
    }
}

void TObjEneMe1Canadin::state_dead(s32 msg) {
    Vec pos;
    switch (msg) {
    case 4:
        if (kind == 1) {
            leader = (TObjEneMe1Canadin *)find_entity_by_id(leader_id);
            leader->remove_member(this);
        }
        TBoss3Volopt::create_breakup_mdl(canadin_breakup_model, NULL,
                           texlist, &body_center, rotation_y);
        status_flags |= 0x400000;
        VecCopy(&pos, &body_center);
        pos.y -= 5.0f;
        trigger_dell_biter_events(&pos);
        refresh_and_send_entity_flags();
        play_sound_effect(0x4003AA1E, &body_center, 0, 0);
        return;
    case 0:
        queue_destruction();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Canadin::state_motion_test(s32 msg) {
    switch (msg) {
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

void TObjEneMe1Canadin::state_move_forward(s32 msg) {

    switch (msg) {
    case 4:
        requested_action = 0;
        hover_y = (f32) (position.y + hover_height);
        work_speed = sin_table_lookup(rotation_y);
        orbit_radius = cos_table_lookup(rotation_y);
        return;
    case 0:
        advance_animation();
        hover_y = (f32) (position.y + hover_height);
        body_center.y = (f32) hover_y;
        move_with_wall_slide_commit(work_speed, orbit_radius, 0.2f);
    case 3:
    case 5:
    case 1:
        return;
    }
}


void canadin_capture_node_points(NJS_OBJECT *) {
    Vec *pos;
    switch (TObjEneMe1Canadin__render_node_index) {
    case 2:
    case 3:
        push_matrix();
        forward_split_screen_view_matrix();
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 1;
        matrix_mult_vec(0, &canadin_node_origin, pos);
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 1;
        rotate_vector_by_matrix(0, pos, pos);
        pop_matrix();
        break;
    case 6:
    case 11:
    case 14:
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 1;
        forward_transform_to_view(&canadin_node_origin, pos);
        break;
    }
    TObjEneMe1Canadin__render_node_index += 1;
}

void TObjEneMe1Canadin::render() {
    s32 detail;
    s32 draw_now;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    if (status_flags & 0x400000) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        if (status_flags & 0x01000000) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        apply_model_color();
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, hover_offset, 0.0f);
        rotate_matrix_y(0, rotation_y);
        draw_now = 1;
        if ((mode == 1) || (mode == 0xB)) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw_now = 0;
            }
        }
        if (draw_now != 0) {
            if ((s16) mode != 0xA) {
                TObjEneMe1Canadin__render_node_index = 0;
                TObjEneMe1Canadin__render_point_cursor = node_points;
                VecCopy(&node_points[3], &canadin_node3_axis);
                VecCopy(&node_points[1], &canadin_node2_axis);
                set_chunk_model_node_callback(canadin_capture_node_points);
                if (detail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                set_chunk_model_node_callback(NULL);
            } else {
                rotate_matrix_z(NULL, rotation_z);
                TObjEneMe1Canadin__render_node_index = -1;
                TObjEneMe1Canadin__render_point_cursor = node_points;
                VecCopy(&node_points[3], &canadin_node3_axis);
                VecCopy(&node_points[1], &canadin_node2_axis);
                set_chunk_model_node_callback(canadin_capture_node_points);
                this->draw_with_alt_model(alt_model_color);
                set_chunk_model_node_callback(NULL);
            }
        }
        if ((mode == 1) || (mode == 0xB)) {
            fade.clear_flag_and_notify();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        return;
    }
    VecCopy(&node_points[3], &canadin_node3_axis);
    VecCopy(&node_points[1], &canadin_node2_axis);
    VecCopy(&node_points[2], &body_center);
    VecCopy(&node_points[0], &body_center);
    VecCopy(&node_points[4], &body_center);
    VecCopy(&node_points[5], &body_center);
    VecCopy(&node_points[6], &body_center);
}

void TObjEneMe1Canadin::run_demo_task() { if (get_target_info() != 0) { this->apply_parameters(); } }

#pragma pool_data off
void TObjEneMe1Canadin::render_demo() {
    if (((s32)get_target_info() != 0) && (kind == 0)) {
        if (status_flags & 0x100) {
            queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:IN FIGHTER");
        } else if (status_flags & 0x200) {
            queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:OUT FIGHTER");
        } else {
            queue_debug_text((s32)(pack_debug_text_position(0, 0)), "TYPE:UNKOWN");
        }
    }
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
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
        run_demo_task();
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
    texlist = bm_ene_me1_mb_resource->models[1].texlist;
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
    n = (s32)ceil_to_float((f32)member_total / (f32)kind_params->group_size);
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
        members[i]->set_out_fighter();
        member_count++;
    }
    for (j = n; j < member_total; j++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &position);
        angle += 0x10000 / member_total;
        members[j] = create_canadin(this, &v, id++, sub++);
        members[j]->set_in_fighter();
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

void TObjEneMe1CanadinLeader::remove_member(TObjEneMe1Canadin *member) {
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
        s32 k = ceil_to_float((f32)member_total / (f32)kind_params->group_size);
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
        if (members[i]->get_attacking_target() == current_target) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneMe1CanadinLeader::apply_model_color() {
    *canadin_leader_node3_diffuse = core_color_packed;
    *canadin_leader_node2_diffuse = core_color_packed;
}

int TObjEneMe1CanadinLeader::has_no_members() {
    return (u8) (member_count <= 0);
}

void TObjEneMe1CanadinLeader::update_formation_state() {
    s32 i;
    s32 j;
    if (this->status_flags & 0x10) {
        this->status_flags &= ~0x10;
        this->formation_state = 7;
    }
    switch (this->formation_state) {
    case 1:
        this->start_fade_sequence(0);
        this->formation_state = 2;
        play_sound_effect(0x4003AD1B, &this->body_center, 0, 0);
        break;
    case 2:
        if (this->fade_mode == 0) {
            this->formation_state = 3;
            this->status_flags &= ~8;
            copy_argb(&this->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (i = 0; i < this->member_count; i++) {
                if (this->members[i]->has_status_flag(0x200) != 0) {
                    this->members[i]->order_attack();
                }
            }
        }
        break;
    case 3:
        if (this->status_flags & 8) {
            this->formation_state = 4;
        }
        break;
    case 4:
        this->start_fade_sequence(2);
        this->formation_state = 5;
        play_sound_effect(0x4003AD1C, &this->body_center, 0, 0);
        break;
    case 5:
        if (this->fade_mode == 0) {
            copy_argb(&this->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            this->formation_state = 6;
            for (i = 0; i < this->member_count; i++) {
                if (this->members[i]->has_status_flag(0x100) != 0) {
                    this->members[i]->order_attack();
                }
            }
        }
        break;
    case 6:
        break;
    case 7:
        this->start_fade_sequence(4);
        this->formation_state = 8;
        play_sound_effect(0x4003AD1B, &this->body_center, 0, 0);
        break;
    case 8:
        if (this->fade_mode == 0) {
            this->formation_state = 9;
            copy_argb(&this->core_color, (NJS_ARGB *)&canadin_formation_reset_vec4);
            for (j = 0; j < this->member_count; j++) {
                this->members[j]->release_from_formation();
            }
            this->release_from_formation();
        }
        break;
    case 0:
    case 9:
        break;
    }
}

void TObjEneMe1CanadinLeader::state_activate(s32 msg) {
    s32 k;
    s32 i;
    s32 j;

    switch (msg) {
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
            members[i]->order_activation(current_target, k);
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
                    if (members[j]->is_activated() == 0) {
                        break;
                    }
                }
                if (j == member_count) {
                    start_formation();
                    s32 m;
                    for (m = 0; m < member_count; m++) {
                        members[m]->start_formation();
                    }
                }
            }
            update_move();
            break;
        }
        hover_toward(25.0f + position.y);
        check_collisions();
        break;
    case 5:
        clear_invulnerable();
        break;
    }
}

void TObjEneMe1CanadinLeader::state_rise(s32 mode) {
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
        update_upper_hover_height();
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
        TBoss3Volopt::create_breakup_mdl(canadin_leader_breakup_model, NULL,
                           texlist, &body_center, rotation_y);
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
