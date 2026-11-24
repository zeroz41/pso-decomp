#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/system/task/TMainTask.h"
#include "pso/system/EnemyBmlResource.h"
#include <stddef.h>
#include <stdlib.h>
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/gee/TObjEneMe1GeeLeader.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/model_render_state.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma defer_codegen on
extern "C" {


BmlResource * TObjEneMe1Gee__resource_bundle;
NJS_OBJECT *gee_model_node7;
s32 TObjEneMe1Gee__render_node_index;
Vec *gee_camera_ctrl_step_ptr;
TBreakUpMdlData * gee_leader_breakup_model;
TBreakUpMdlData * gee_breakup_model;
// The colour word of model node 4's first material chunk (polygon_list + 2); apply_model_color writes core_color_packed.
s32 *gee_node4_diffuse;
GeeMovementParameters me1_gee_init_params = {225.0f, 0.0f, 0x600};

CollisionBody gee_collision_body = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};

const char *bm_ene_me1_gee_model_names[3] = {"me1_y_mb.nj", "needle_body.gj", NULL};

const char *bm_ene_me1_gee_motion_names[5] = {
    "attack_me1_y_mb.njm", "damage_me1_y_mb.njm", "tuki_me1_y_mb.njm", "wait_me1_y_mb.njm", NULL,
};

BmlResourceDescriptor bm_ene_me1_gee_resource_descriptor = {
    "bm_ene_me1_gee.bml", bm_ene_me1_gee_model_names, bm_ene_me1_gee_motion_names, 2, 4,
};

const char *bm_ene_me1_gee_low_model_names[3] = {"lo_me1_y_mb.nj", "needle_body.gj", NULL};

const char *bm_ene_me1_gee_low_motion_names[5] = {
    "attack_me1_y_mb.njm", "damage_me1_y_mb.njm", "tuki_me1_y_mb.njm", "wait_me1_y_mb.njm", NULL,
};

BmlResourceDescriptor bm_ene_me1_gee_low_resource_descriptor = {
    "bm_ene_me1_gee_low.bml", bm_ene_me1_gee_low_model_names, bm_ene_me1_gee_low_motion_names, 2, 4,
};

TObjMotionAction TObjEneMe1Gee__motion_parameters[4] = {
    {1, 0, 3, 0.9f, 0},
    {2, 0, 2, 1.0f, 0},
    {2, 0, 0, 1.0f, 0},
    {2, 0, 1, 0.8f, 0},
};

const NJS_ARGB gee_formation_reset_vec4 = {1.0f, 0.0f, 0.2f, 1.0f};

const NJS_ARGB TObjEneMe1Gee__map_core_default_vec4 = {1.0f, 1.0f, 0.0f, 0.2f};

const NJS_ARGB gee_formation_fade_start_color = {1.0f, 0.2f, 1.0f, 0.0f};

const char *TObjEneMe1Gee__fade_command_streams[5] = {
    "ababaababaabbababbabbbbc", "abbabbababc", "ababaaabbaaabbbabbabababbbbc", "abaaabababbac",
    "ababababaabbaabbababaabaabaaabbbbc",
};

const char *TObjEneMe1Gee__class_name = "TObjEneMe1Gee";

static player_stats *gee_boss_stat_handle_table[3];
static AttackParams *gee_shared_handler_b_table[3];
static ActorParamBlock *gee_object_handle_table[3];
static TObjEneMe1GeeParams *gee_shared_handler_a_table[3];
static f32 gee_camera_ctrl_vec[4];





void TObjEneMe1Gee::load_resources() {
    s32 i;
    TBreakUpMdlData *p;
    Vec *v;
    v = (Vec *)gee_camera_ctrl_vec;
    gee_camera_ctrl_vec[0] = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneMe1Gee__resource_bundle = load_enemy_bml_resource(&bm_ene_me1_gee_low_resource_descriptor);
    } else {
        TObjEneMe1Gee__resource_bundle = load_enemy_bml_resource(&bm_ene_me1_gee_resource_descriptor);
    }
    TObjEneMe1Gee_NEEDLE::init_global();
    gee_model_node7 = find_model_node(TObjEneMe1Gee__resource_bundle->models->model, 7);
    for (i = 0; i < 3; i++) {
        gee_boss_stat_handle_table[i] = TLobby::register_boss(gee_base_stat_ids[i]);
        gee_shared_handler_b_table[i] = TLobby::dispatch_shared_handler_b(gee_attack_stat_ids[i]);
        gee_object_handle_table[i] = TLobby::register_object(gee_resist_stat_ids[i]);
        gee_shared_handler_a_table[i] = (TObjEneMe1GeeParams *)TLobby::dispatch_shared_handler_a(gee_param_ids[i]);
    }
    TObjEneMe1Gee__render_node_index = 0;
    p = new TBreakUpMdlData(TObjEneMe1Gee__resource_bundle->models->model);
    gee_leader_breakup_model = p;
    p = new TBreakUpMdlData(TObjEneMe1Gee__resource_bundle->models->model);
    gee_breakup_model = p;
    gee_node4_diffuse = (s32 *)(((NJS_CNK_MODEL *)find_model_node(TObjEneMe1Gee__resource_bundle->models->model, 4)->model)->polygon_list + 2);
    TObjPlayer::init_alt_model();
    {
        NpcAnimationBinding params = { NULL, TObjEneMe1Gee__motion_parameters, 0, 0, 4 };
        params.motions = TObjEneMe1Gee__resource_bundle->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x10, TObjEneMe1Gee__resource_bundle->models->model, TObjEneMe1Gee__resource_bundle->models->texlist, &params, 8.0f, 15.0f);
    }
}

void *TObjEneMe1Gee::create(void *set_data) {
    return new TObjEneMe1Gee(tl_04, set_data, 0);
}

TObjEneMe1Gee *TObjEneMe1Gee::create(TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index) {
    return new TObjEneMe1Gee(tl_04, leader, pos, id, index);
}

void TObjEneMe1Gee::free_globals() {
    if (gee_breakup_model != NULL) {
        delete gee_breakup_model;
        gee_breakup_model = NULL;
    }
    if (gee_leader_breakup_model != NULL) {
        delete gee_leader_breakup_model;
        gee_leader_breakup_model = NULL;
    }
    if (TObjEneMe1Gee__resource_bundle != NULL) {
        delete TObjEneMe1Gee__resource_bundle;
        TObjEneMe1Gee__resource_bundle = NULL;
    }
    TObjEneMe1Gee_NEEDLE::free_global();
}

TObjEneMe1Gee::TObjEneMe1Gee(TObject *parent, void *set_data, s32 kind) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Gee__class_name;
    invoke_initialization_hook(set_data);
    status_flags = 0;
    apply_parameters();
    this->leader = this;
    this->kind = kind;
    init_state();
}

TObjEneMe1Gee::TObjEneMe1Gee(TObject *parent, TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index)
    : TObjEneDD_ST(parent) {
    m_name = TObjEneMe1Gee__class_name;
    this->leader = leader;
    init_common_from(this->leader);
    entity_id = id;
    set_index = index;
    this->leader->calc_position(&position);
    VecCopy(&position, pos);
    rotation_y = this->leader->rotation_y;
    status_flags = 0;
    this->kind = 1;
    init_state();
}
#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void TObjEneMe1Gee::init_state() {
    s32 i;
    this->init_position_vectors();
    this->select_model();
    this->init_model(&gee_collision_body, 1);
    this->set_action_table(TObjEneMe1Gee__motion_parameters);
    this->set_motion_list(TObjEneMe1Gee__resource_bundle->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    this->reset_hp(gee_boss_stat_handle_table[this->kind], gee_shared_handler_b_table[this->kind], gee_object_handle_table[this->kind]);
    this->set_state_flag_1();
    this->movementParameters = &me1_gee_init_params;
    this->initialize_enemy_state(0x36);
    this->wall_reach = 10.0f;
    this->enemy_init_acquire_period(0x2D);
    this->enemy_init_validate_period(0x2D);
    this->set_active();
    this->actorFlags |= 0x01000000;
    this->kind_params = gee_shared_handler_a_table[this->kind];
    this->fade.reset_color();
    this->upper_hover_height = 45.0f;
    this->hover_height = 15.0f;
    this->random_hover_height = ((5.0f * (3.0517578e-05f * (f32) rand())) + 15.0f);
    this->hover_offset = this->hover_height;
    this->hover_y = this->position.y + this->hover_offset;
    this->attack_delay = 0;
    this->attack_count = 0;
    this->pad_40c = 0;
    this->alt_model_color = 0;
    for (i = 0; i < 2; i++) {
        VecCopy(&this->node_points[i], &this->position);
    }
    this->attack_pattern = 0;
    this->stage = 0;
    this->stage_timer = 0;
    this->stage_counter = 0;
    this->pad_440 = 0;
    this->orbit_angle_step = 0;
    this->work_speed = 0.0f;
    this->orbit_radius = 0.0f;
    this->orbit_radius_step = 0.0f;
    this->work_point.x = 0.0f;
    this->work_point.y = 0.0f;
    this->work_point.z = 0.0f;
    this->eff_line = 0;
    this->particle_emitter = 0;
    copy_argb(&this->core_color, (NJS_ARGB *)&TObjEneMe1Gee__map_core_default_vec4);
    this->core_color.a = 0.0f;
    this->fade_mode = 0;
    this->core_color_packed = 0;
    this->fade_sequence = 0;
    this->fade_step_timer = 0;
    this->fade_cursor = 0;
    this->copy_pos();
    TObjEneDD::set_part_position(this, this->bodies, 0);
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
    if (this->leader != NULL) {
        this->leader_id = this->leader->get_entity_id();
        return;
    }
    this->leader_id = 0xFFFF;
}
#pragma pop
TObjEneMe1Gee::~TObjEneMe1Gee() {
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMe1Gee::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (kind == 1) {
        leader = (TObjEneMe1Gee *)find_entity_by_id(leader_id);
        if (leader == NULL || leader->all_parents_unqueued_for_destruction() == 0) {
            this->queue_destruction();
            return;
        }
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        this->update_fade_sequence();
    }
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

BmlResource *TObjEneMe1Gee::get_resource_bundle() { return TObjEneMe1Gee__resource_bundle; }

void TObjEneMe1Gee::refresh_target() {  }

void TObjEneMe1Gee::run_death_reaction() {
    if ((this->mode != 0xE) && (this->mode != 0xC)) {
        this->transition_enemy_state(0xE);
    }
}

void TObjEneMe1Gee::run_hit_reaction() { if (this->mode != 13) { this->transition_enemy_state(13); } }

void TObjEneMe1Gee::run_miss_reaction() {  }

void TObjEneMe1Gee::copy_pos() {
    this->body_center.x = this->position.x;
    this->body_center.y = this->hover_y;
    this->body_center.z = this->position.z;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneMe1Gee::update_body_colliders() {
    this->hover_offset = (this->hover_y - this->position.y);
    if (this->hover_offset < 30.0f) {
        this->set_colliders_contact_low();
    } else {
        this->set_colliders_contact_high();
    }
    this->bodies->offset.y = this->hover_offset;
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::apply_parameters() {
    if ((s32) floor_to_float(this->parameters[0]) == 0) {
        this->set_in_fighter();
    } else {
        this->set_out_fighter();
    }
    if ((s32) floor_to_float(this->parameters[1]) == 0) {
        this->set_low_appear();
    } else {
        this->set_high_appear();
    }
    this->needle_speed = (6.0f + this->parameters[3]);
    if (this->needle_speed < 0.01f) {
        this->needle_speed = 0.01f;
    }
    this->appear_speed = (1.0f + this->parameters[2]);
    if (this->appear_speed < 1.0f) {
        this->appear_speed = 1.0f;
    }
}
#pragma pop
void TObjEneMe1Gee::select_model() {
    this->model = (void *)TObjEneMe1Gee__resource_bundle->models->model;
    this->texlist = TObjEneMe1Gee__resource_bundle->models->texlist;
}
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::calc_position(Vec *out) {
    s32 angle = get_random_scaled();
    f32 radius = 30.0f * this->random_ratio() + 10.0f;
    out->x = radius * sin_table_lookup(angle);
    out->y = 0.0f;
    out->z = radius * cos_table_lookup(angle);
    vec3_add_to(out, &this->position);
}
#pragma pop
CsnHit *TObjEneMe1Gee::move_xz_on_ground(const Vec *dest) {
    CsnHit *ground = TObjEneDD::move_xz_on_ground(dest);
    if (ground == NULL) {
        this->status_flags &= 0xFEFFFFFF;
    } else {
        this->status_flags |= 0x01000000;
    }
    return ground;
}

void TObjEneMe1Gee::approach_hover_y(f32 height) {
    f32 delta;
    delta = height - this->hover_y;
    this->status_flags &= 0xFFF7FFFF;
    if (delta >= 0.5f) {
        this->hover_y += 0.5f;
        return;
    }
    if (delta <= (-0.5f)) {
        this->hover_y -= 0.5f;
        return;
    }
    this->hover_y = height;
    this->status_flags |= 0x80000;
}

void TObjEneMe1Gee::climb_hover_y(f32 height) {
    f32 delta = height - this->hover_y;
    this->status_flags &= ~0x80000;
    if (delta >= this->appear_speed) {
        this->hover_y += this->appear_speed;
    } else if (delta <= -this->appear_speed) {
        this->hover_y -= this->appear_speed;
    } else {
        this->hover_y = height;
        this->status_flags |= 0x80000;
    }
}

void TObjEneMe1Gee::approach_upper_hover_height() {
    this->approach_hover_y(this->position.y + this->upper_hover_height);
}

void TObjEneMe1Gee::hover_toward(f32 height) {
    Vec pos;
    this->approach_hover_y(height);
    VecCopy(&pos, &this->position);
    pos.y = this->hover_y;
    this->move_xz_on_ground(&pos);
}

void TObjEneMe1Gee::update_hover_height() {
    this->hover_toward(this->hover_height + this->position.y);
}

void TObjEneMe1Gee::update_upper_hover_height() {
    this->hover_toward(this->upper_hover_height + this->position.y);
}

void TObjEneMe1Gee::climb_toward(f32 height) {
    Vec pos;
    this->climb_hover_y(height);
    VecCopy(&pos, &this->position);
    pos.y = this->hover_y;
    this->move_xz_on_ground(&pos);
}

void TObjEneMe1Gee::climb_to_hover_height() {
    this->climb_toward(this->hover_height + this->position.y);
}

void TObjEneMe1Gee::update_angle() {
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)), 0x400);
    this->rotation_y = (s32) (s16) this->rotation_y;
}

void TObjEneMe1Gee::update() { if (this->enemy_has_live_target() != 0) { this->enemy_copy_target_destination(); this->update_velocity(); this->update_angle(); } }

void TObjEneMe1Gee::select_next_attack_state() {
    if (this->status_flags & 0x100) {
        this->transition_enemy_state(8);
        return;
    }
    if ((s32) this->kind == 0) {
        if ((s32) this->attack_pattern < 2) {
            this->transition_enemy_state(7);
            this->attack_pattern += 1;
            return;
        }
        this->transition_enemy_state(8);
        this->attack_pattern = 0;
        return;
    }
    this->transition_enemy_state(7);
}

void TObjEneMe1Gee::check_collisions() { TObjEneDD::check_collisions(); }

void TObjEneMe1Gee::set_melee_body_flags() {
    this->bodies->flags |= 0x28;
}

void TObjEneMe1Gee::clear_melee_body_flags() {
    this->bodies->flags &= ~0x28;
}

s32 TObjEneMe1Gee::find_attack_target(f32 *out, f32 range) {
    TargetCandidate recs[5];
    s32 found;
    s32 n;
    TObjPlayer *p;
    s32 i;
    found = 0;
    *out = (-1.0f);
    n = collect_enemy_target_candidates(this, recs, range);
    for (i = 0; i < n; i++) {
        p = get_player_by_client_id(recs[i].id);
        if (p != this->current_target) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            if (this->leader->can_member_attack_target(p) != 0) {
                *out = newton_sqrtf(recs[i].dist);
                found = 1;
                this->set_target_player(p);
                break;
            }
        }
    }
    return found;
}

s32 TObjEneMe1Gee::check_can_attack() {
    f32 dist;
    s32 in_range;

    in_range = 0;
    if (this->destination_distance < 70.0f) {
        in_range = 1;
        this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
        if ((this->leader->can_member_attack_target(this->current_target) == 0) && (this->find_attack_target(&dist, 22500.0f) != 0) && (dist > 70.0f)) {
            in_range = 0;
        }
    }
    return in_range;
}

s32 TObjEneMe1Gee::is_hover_low() {
    return this->hover_offset < 20.0f;
}

void TObjEneMe1Gee::spawn_members() {  }

s32 TObjEneMe1Gee::check_retreat_trigger() {
    if (this->status_flags & 0x40) {
        this->status_flags &= 0xFFFFFFBF;
        this->transition_enemy_state(0xC);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Gee::check_death_trigger() {
    if (this->current_target == NULL) {
        this->transition_enemy_state(0xF);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Gee::handle_message(s32 id) {
    s32 sound;

    if (id == 0x3A843) {
        sound = 0x3A843;
        if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
            return 0x4003B20D;
        }
        return sound;
    }
    sound = this->remap_sound_for_area(id);
    return sound;
}

void TObjEneMe1Gee::play_high_appear_sound() {
    play_persistent_sound(this->handle_message(0x3BC16), this, &this->body_center, 0, 0);
}

s32 TObjEneMe1Gee::acquire_target(f32 range) { return this->select_and_apply_target(range); }

void TObjEneMe1Gee::update_fade_sequence() {
    switch (this->fade_mode) {
    case 0:
        break;
    case 1:
        if (this->core_color.a > 0.0f) {
            this->core_color.a = this->core_color.a - 0.06f;
        } else {
            this->core_color.a = 0.0f;
            this->fade_mode = 0;
        }
        this->update_packed_color();
        break;
    case 2:
        if (this->core_color.a < 1.0f) {
            this->core_color.a += 0.06f;
        } else {
            this->core_color.a = 1.0f;
            this->fade_mode = 0;
        }
        this->update_packed_color();
        break;
    case 3:
        (this->fade_step_timer)++;
        if ((f32)this->fade_step_timer >= 2.0f) {
            this->fade_step_timer = 0;
            switch (TObjEneMe1Gee__fade_command_streams[this->fade_sequence][(this->fade_cursor)++]) {
            case 'b':
                this->core_color.a = 0.0f;
                break;
            case 'c':
                this->fade_mode = 0;
                copy_argb(&this->core_color, (NJS_ARGB *)&gee_formation_reset_vec4);
                break;
            case 'a':
                this->core_color.a = 1.0f;
                break;
            }
            this->update_packed_color();
        }
        break;
    }
}

void TObjEneMe1Gee::start_fade_sequence(s32 sequence) {
    this->set_core_color(&gee_formation_fade_start_color);
    this->fade_mode = 3;
    this->fade_sequence = sequence;
    this->fade_step_timer = 2;
    this->fade_cursor = 0;
}

void TObjEneMe1Gee::set_core_color(const NJS_ARGB *color) {
    copy_argb(&this->core_color, (NJS_ARGB *)color);
    this->update_packed_color();
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::update_packed_color() {
    u8 g = (u32)(255.0f * this->core_color.g);
    u8 b = (u32)(0.8f * (255.0f * this->core_color.b));
    u8 r = (u32)(255.0f * this->core_color.r);
    u8 a = (u32)(255.0f * this->core_color.a);
    this->core_color_packed = (b << 24) | (g << 16) | (r << 8) | a;
}
#pragma pop
void TObjEneMe1Gee::apply_model_color() {
    if (gee_node4_diffuse != NULL) {
        *gee_node4_diffuse = this->core_color_packed;
    }
}

int TObjEneMe1Gee::has_no_members() { return 1; }

void TObjEneMe1Gee::wake_leader() {
    if ((s16) this->mode == 3) {
        this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
        this->leader->order_activation_now();
    }
}

int TObjEneMe1Gee::is_activated() { return (this->status_flags >> 15) & 0x1; }

void TObjEneMe1Gee::set_low_appear() {
    this->status_flags |= 0x02000000;
    this->status_flags &= 0xFBFFFFFF;
}

void TObjEneMe1Gee::set_high_appear() {
    this->status_flags |= 0x04000000;
    this->status_flags &= 0xFDFFFFFF;
}

void TObjEneMe1Gee::set_in_fighter() {
    this->status_flags |= 0x100;
    this->status_flags &= 0xFFFFFDFF;
}

void TObjEneMe1Gee::set_out_fighter() {
    this->status_flags |= 0x200;
    this->status_flags &= 0xFFFFFEFF;
}

s32 TObjEneMe1Gee::has_status_flag(s32 mask) {
    return (u8) ((this->status_flags & mask) != 0);
}

TObjChara *TObjEneMe1Gee::get_attacking_target() {
    if (this->status_flags & 0x40000) {
        return this->current_target;
    }
    return NULL;
}

void TObjEneMe1Gee::remove_member(TObjEneMe1Gee *) {  }

int TObjEneMe1Gee::can_member_attack_target(TObjChara *) { return 1; }

void TObjEneMe1Gee::order_activation_now() {
    this->attack_delay = 0;
    this->status_flags |= 1;
}

void TObjEneMe1Gee::order_activation(TObjChara *target, s32 delay) {
    this->set_target_player(target);
    this->attack_delay = delay;
    this->status_flags |= 1;
}

void TObjEneMe1Gee::start_formation() { this->status_flags |= 0x2; }

void TObjEneMe1Gee::order_attack() { this->status_flags |= 0x4; }

void TObjEneMe1Gee::set_flag3c8_bit8() { this->status_flags |= 0x8; }

void TObjEneMe1Gee::release_from_formation() {
    this->status_flags |= 0x100000 | 4;
}

void TObjEneMe1Gee::set_flag3c8_bit40() { this->status_flags |= 0x40; }

// The state names are read from the bodies and shared with the Canadin's twin states (see
// TObjEneMe1Canadin::dispatch_action); spawn picks appear for "TYPE:LOW APPEAR" (0x02000000), else
// high_appear, which climbs at appear_speed.
void TObjEneMe1Gee::dispatch_action(u32 state, s32 mode) {
    switch (state) {
    case 0:
        state_spawn(mode);
        break;
    case 1:
        state_appear(mode);
        break;
    case 2:
        state_high_appear(mode);
        break;
    case 3:
        state_hover(mode);
        break;
    case 4:
        state_activate(mode);
        break;
    case 5:
        state_rise(mode);
        break;
    case 6:
        state_formation(mode);
        break;
    case 7:
        state_ranged_attack(mode);
        break;
    case 8:
        state_melee_attack(mode);
        break;
    case 9:
        state_orbit(mode);
        break;
    case 10:
        state_regroup(mode);
        break;
    case 12:
        state_vanish(mode);
        break;
    case 13:
        hurt_state(mode);
        break;
    case 14:
        state_dead(mode);
        break;
    case 15:
        state_return_home(mode);
        break;
    case 17:
        state_motion_test(mode);
        break;
    case 18:
        state_move_forward(mode);
        break;
    }
}

void TObjEneMe1Gee::state_spawn(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->set_intangible();
        this->status_flags |= 0x400000;
        this->fade_mode = 1;
        this->stage = 0;
        return;
    case 3:
        if ((s32) this->stage >= 4) {
            if ((s32) this->kind == 0) {
                this->status_flags |= 0x100000;
            }
            if (this->status_flags & 0x02000000) {
                this->transition_enemy_state(1);
            } else {
                this->transition_enemy_state(2);
            }
        }
    case 5:
        break;
    case 0:
        this->stage += 1;
        if ((s32) this->stage == 2) {
            this->spawn_members();
        }
        this->status_flags &= 0xFEFFFFFF;
        break;
    }
}

void TObjEneMe1Gee::state_appear(s32 msg) {

    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->set_intangible();
        this->actorFlags = (this->actorFlags & 0xFEFFFFFF);
        this->fade_mode = 1;
        fade.start_fade_in();
        play_area_sound_effect(&this->position);
        return;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(3);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if ((s32) this->kind == 2) {
            this->hover_toward(25.0f + this->position.y);
        } else {
            this->update_hover_height();
        }
        this->update_body_colliders();
        break;
    }
}

void TObjEneMe1Gee::state_high_appear(s32 mode) {
    Vec pos;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->status_flags &= 0xFFF7FFFF;
        this->actorFlags |= 0x01000000;
        this->set_intangible();
        this->fade_mode = 1;
        this->fade.start_fade_in();
        VecCopy(&pos, &this->position);
        pos.y += 150.0f;
        this->hover_y = pos.y;
        TBoss3Volopt__sub_800D8D88((saddr) &pos);
        this->set_invulnerable();
        this->stage = 0;
        return;
    case 3:
        if (this->status_flags & 0x80000) {
            this->transition_enemy_state(3);
            this->clear_invulnerable();
        }
        return;
    case 0:
        this->advance_animation();
        switch (this->stage) {
        case 0:
            if (this->fade.advance_toward_max() != 0) {
                this->stage = 1;
            }
            break;
        case 1:
            this->climb_to_hover_height();
            break;
        }
        this->update_body_colliders();
        this->play_high_appear_sound();
        return;
    case 5:
        this->clear_invulnerable();
        this->actorFlags &= 0xFEFFFFFF;
        break;
    }
}

void TObjEneMe1Gee::state_hover(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags &= 0xFEFFFFFF;
        this->fade_mode = 1;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            if (this->status_flags & 1) {
                this->status_flags &= 0xFFFFFFFE;
                this->transition_enemy_state(4);
            } else if (this->enemy_has_live_target() != 0) {
                this->transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        if ((s32) this->kind != 1) {
            this->update_linked_position(200.0f);
        }
        if ((s32) this->kind == 2) {
            this->hover_toward(25.0f + this->position.y);
        } else {
            this->update_hover_height();
        }
        this->check_collisions();
        break;
    case 5:
        this->actorFlags &= 0xFEFFFFFF;
        break;
    case 1:
        break;
    }
}

void TObjEneMe1Gee::state_activate(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags &= 0xFEFFFFFF;
        this->core_color.r = gee_formation_reset_vec4.r;
        this->core_color.g = gee_formation_reset_vec4.g;
        this->core_color.b = gee_formation_reset_vec4.b;
        this->update_packed_color();
        this->stage = 0;
        return;
    case 3:
        if (this->check_retreat_trigger() == 0) {
            if (this->status_flags & 2) {
                this->status_flags &= 0xFFFFFFFD;
                if ((s32) this->kind == 1) {
                    this->transition_enemy_state(6);
                } else {
                    this->transition_enemy_state(5);
                }
            }
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 2:
            break;
        case 0:
            this->attack_delay -= 1;
            if ((s32) this->attack_delay <= 0) {
                this->fade_mode = 2;
                this->stage = 1;
            }
            break;
        case 1:
            if ((s32) this->fade_mode == 0) {
                this->status_flags |= 0x8000;
                switch (this->kind) {
                case 0:
                    this->start_formation();
                case 1:
                    this->stage = 3;
                    break;
                }
            }
            this->update();
            break;
        case 3:
            this->update();
            break;
        }
        this->update_hover_height();
        this->check_collisions();
        return;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1Gee::state_rise(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags |= 0x01000000;
        return;
    case 3:
        if (this->status_flags & 0x80000) {
            this->attack_count = 0;
            this->select_next_attack_state();
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        update_linked_position(200.0f);
        update();
        update_upper_hover_height();
        this->check_collisions();
        break;
    }
}

void TObjEneMe1Gee::state_formation(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        set_field_378(6);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->actorFlags |= 0x01000000;
        this->stage = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && ((s32) this->stage == 3)) {
            this->attack_count = 0;
            this->select_next_attack_state();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 0:
            if (this->status_flags & 4) {
                this->status_flags &= 0xFFFFFFFB;
                if (this->has_status_flag(0x200) != 0) {
                    this->stage = 1;
                    start_fade_sequence(1);
                } else {
                    this->stage = 2;
                    start_fade_sequence(3);
                }
            }
            update();
            this->update_upper_hover_height();
            break;
        case 1:
            if ((s32) this->fade_mode == 0) {
                this->stage = 3;
            }
            update();
            this->update_upper_hover_height();
            break;
        case 2:
            update();
            if ((s32) this->fade_mode != 0) {
                this->update_upper_hover_height();
            } else {
                this->hover_toward(this->position.y + this->random_hover_height);
                if (this->status_flags & 0x80000) {
                    this->stage = 3;
                }
            }
            break;
        }
        this->check_collisions();
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#pragma pool_data off
void TObjEneMe1Gee::state_ranged_attack(s32 mode) {
    Vec *dir = &this->work_point;
    switch (mode) {
    case 4:
        this->set_field_378(7);
        this->status_flags |= 0x10000;
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags |= 0x1000000;
        this->set_core_color(&gee_formation_reset_vec4);
        this->stage = 1;
        this->stage_timer = 0;
        this->eff_line = NULL;
        this->particle_emitter = NULL;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage == 6) {
            if (this->status_flags & 0x100000) {
                this->transition_enemy_state(9);
            } else {
                this->transition_enemy_state(10);
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
            if (this->check_can_attack() != 0) {
                this->stage = 2;
                this->status_flags |= 0x40000;
            }
            TObjEneEpsilon__sub_800B92F8(this, 0x200, 0.5f);
            break;
        case 2:
            this->update_velocity();
            this->update_angle();
            this->stage = 3;
            this->set_core_color(&TObjEneMe1Gee__map_core_default_vec4);
            VecCopy(dir, &this->destination);
            break;
        case 3: {
            Vec d;
            this->update_velocity();
            this->update_angle();
            VecCopy(&d, &this->destination);
            subtract_vector(&d, dir);
            if (normalize_vector_xz(&d) < 0.6f) {
                VecCopy(dir, &this->destination);
            } else {
                dir->x = 0.6f * d.x + dir->x;
                dir->y = 0.6f * d.y + dir->y;
                dir->z = 0.6f * d.z + dir->z;
            }
            this->stage_timer++;
            if (this->stage_timer > this->kind_params->aim_time) {
                this->requested_action = 1;
                this->stage = 4;
                this->stage_timer = 0;
                if (this->eff_line != NULL) {
                    this->eff_line->queue_destruction();
                    this->eff_line = NULL;
                }
                if (this->particle_emitter != NULL) {
                    this->particle_emitter->queue_destruction();
                    this->particle_emitter = NULL;
                }
                play_sound_effect(this->handle_message(0x3AD17), &this->body_center, 0, 0);
            } else {
                play_persistent_sound((s32)(this->handle_message(0x3A914)), this, &this->body_center, 0, 0);
            }
            break;
        }
        case 4:
            this->stage_timer++;
            if (this->stage_timer >= 15) {
                this->stage = 5;
                this->status_flags &= ~0x40000;
                this->set_core_color(&gee_formation_reset_vec4);
                this->attack_count++;
                this->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&this->position.x);
                rotate_matrix_y(0, this->rotation_y);
                set_motion_packed_rotation();
                this->calc_joint_matrices(this->stage_timer);
                clear_motion_packed_rotation();
                pop_matrix();
                this->stage_timer = 0;
                push_matrix_from(anim_model_matrix_array[7]);
                {
                    Vec out;
                    Vec in = {0.0f, 0.0f, 0.0f};
                    matrix_mult_vec(0, &in, &out);
                    pop_matrix();
                    out.y += this->upper_hover_height;
                    new TObjEneMe1Gee_NEEDLE(this, &out, dir, this->needle_speed, this->kind_params->ranged_power);
                }
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
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->set_core_color(&gee_formation_reset_vec4);
        if (this->eff_line != NULL) {
            this->eff_line->queue_destruction();
            this->eff_line = NULL;
        }
        if (this->particle_emitter != NULL) {
            this->particle_emitter->queue_destruction();
            this->particle_emitter = NULL;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::state_melee_attack(s32 mode) {
    f32 dist;

    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(8);
        this->status_flags &= ~0x400000;
        this->clear_intangible();
        this->actorFlags &= ~0x1000000;
        this->status_flags &= ~0x80000;
        this->stage = 0;
        this->stage_timer = 0x28;
        this->stage_counter = 0;
        this->work_speed = 0.0f;
        this->orbit_radius = 0.0f;
        break;
    case 3:
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage == 5) {
            this->transition_enemy_state(9);
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
        case 0:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->stage_timer > 0x28) {
                this->stage_timer = 0;
                this->stage = 1;
                if (this->status_flags & 0x40000) {
                    if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                        this->set_core_color(&TObjEneMe1Gee__map_core_default_vec4);
                    }
                } else if (this->destination_distance < 100.0f) {
                    this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
                    if (this->leader->can_member_attack_target(this->current_target) != 0) {
                        this->status_flags |= 0x40000;
                    } else if (this->find_attack_target(&dist, 10000.0f) != 0) {
                        if (dist < 100.0f) {
                            this->status_flags |= 0x40000;
                        }
                    } else {
                        this->stage = 5;
                    }
                }
            }
            this->hover_toward(this->position.y + this->hover_offset);
            break;
        case 1:
            if (this->stage_timer == 0) {
                f32 z;
                f32 x;
                f32 c;
                f32 s;
                f32 inv;
                f32 k;
                this->enemy_copy_target_destination();
                this->update_velocity();
                play_sound_effect(this->handle_message(0x3AD13), &this->body_center, 0, 0);
                k = 956.25f;
                inv = 1.0f / newton_sqrtf(k);
                k *= inv;
                c = 30.0f * inv;
                s = 7.5f * inv;
                if (this->stage_counter == 1) {
                    this->stage_counter = 0;
                    s *= (-1.0f);
                } else {
                    this->stage_counter = 1;
                }
                x = this->destination_direction.x;
                z = this->destination_direction.z * c - x * s;
                this->destination_direction.x = x * c + this->destination_direction.z * s;
                this->destination_direction.z = z;
                this->work_speed = 0.25f * k;
                this->orbit_radius = 0.25f * (this->hover_height - this->hover_offset);
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
            break;
        case 3:
            this->requested_action = 1;
            this->stage = 4;
            play_sound_effect(this->handle_message(0x3AD15), &this->body_center, 0, 0);
        case 4:
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->update_angle();
            this->stage_timer++;
            if (this->requested_action == 0) {
                if (this->attack_count >= 3) {
                    this->stage = 5;
                } else {
                    this->stage_timer = 0;
                    if (this->destination_distance < 13.0f) {
                        this->stage = 3;
                    } else if (this->destination_distance < 40.0f) {
                        this->stage = 2;
                    } else {
                        this->stage = 1;
                        this->set_core_color(&gee_formation_reset_vec4);
                        if (this->destination_distance > 100.0f) {
                            this->status_flags &= ~0x40000;
                        }
                    }
                }
            } else if (this->is_passing_frame(10.0f) != 0) {
                this->attack_count++;
                if (this->is_hover_low() != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                        if (this->random_ratio() <= 0.25f) {
                            DirectAttackPayload p = {0x11, 0.0f};
                            this->current_target->receive_direct_attack(this, p, 0, -1, -1);
                        }
                    }
                }
            }
            this->update_hover_height();
            break;
        case 5:
            break;
        }
        this->check_collisions();
        break;
    case 5:
        this->status_flags &= ~0x40000;
        this->set_core_color(&gee_formation_reset_vec4);
        this->clear_melee_body_flags();
        break;
    }
}
#pragma pop
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe1Gee::state_orbit(s32 mode) {
    Vec *dir = &this->work_point;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(9);
        this->status_flags &= 0xFFBFFFFF;
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
        if (this->check_retreat_trigger() == 0 && this->check_death_trigger() == 0 && this->stage_counter >= 4) {
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
                    t = 8192.0f * calc_elapsed_scaled();
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
                    play_sound_effect(this->handle_message(0x3AD13), &this->body_center, 0, 0);
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
void TObjEneMe1Gee::state_regroup(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xA);
        this->status_flags &= 0xFFBFFFFF;
        this->set_intangible();
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id((this->leader_id));
            ((TObjEneMe1Gee *)(this->leader))->set_flag3c8_bit8();
        }
        this->attack_count = 0;
        return;
    case 3:
        if ((this->check_retreat_trigger() == 0) && (this->destination_distance < 1.0f)) {
            this->transition_enemy_state(6);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        this->set_target_destination(&this->home_position);
        this->update_velocity();
        this->update_angle();
        this->approach_upper_hover_height();
        this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, 0.8f);
        this->update_body_colliders();
        break;
    }
}

void TObjEneMe1Gee::hurt_state(s32 mode) {
    Vec v;
    f32 len;
    switch (mode) {
    case 4:
        this->requested_action = 3;
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
        this->work_speed = 0.0f;
        this->orbit_radius = 0.0f;
        break;
    case 3:
        if (this->stage_timer == 3) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, &this->velocity);
        len = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, len);
        len *= 0.5f;
        this->velocity.x = v.x * len;
        this->velocity.z = v.z * len;
        switch (this->stage_timer) {
        case 0:
            this->work_speed = this->work_speed - 0.13f;
            if (this->work_speed < -4.0f) {
                this->work_speed = -4.0f;
            }
            this->hover_y += this->work_speed;
            if (this->hover_y < 12.0f + (this->position.y + this->hover_height)) {
                this->stage_timer = 1;
                if (this->work_speed > -2.0f) {
                    this->work_speed = -2.0f;
                }
                this->orbit_radius = (this->work_speed * this->work_speed) / 30.0f;
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
        this->clear_attack_receipts();
        this->requested_action = 0;
        break;
    }
}
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::state_vanish(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xC);
        this->set_intangible();
        this->status_flags &= 0xFFBFFFFF;
        this->actorFlags |= 0x800;
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->remove_member(this);
        } else {
            this->send_entity_set_flags();
        }
        this->fade.set_rate_from_divisor(0x19);
        this->fade.reset_color();
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
#pragma pop
void TObjEneMe1Gee::state_return_home(s32 mode) {

    switch (mode) {
    case 4:
        set_field_378(0xF);
        this->status_flags &= 0xFFBFFFFF;
        this->clear_intangible();
        this->stage = 0;
        return;
    case 3:
        if ((s32) this->stage == 2) {
            this->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->stage = 2;
        }
        switch (this->stage) {
        case 0:
            this->stage_timer += 1;
            if ((s32) this->stage_timer >= 0x3C) {
                this->stage = 1;
            }
            this->hover_toward(this->position.y + this->hover_offset);
            break;
        case 1:
            set_target_destination(&this->home_position);
            this->update_velocity();
            update_angle();
            approach_upper_hover_height();
            if (this->destination_distance > 2.0f) {
                this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, 0.8f);
            }
            break;
        }
        this->check_collisions();
        break;
    }
}

void TObjEneMe1Gee::state_dead(s32 msg) {
    Vec pos;
    switch (msg) {
    case 4:
        if ((s32) this->kind == 1) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->remove_member(this);
        }
        TBoss3Volopt::create_breakup_mdl(gee_breakup_model, NULL,
                           this->texlist, &this->body_center, this->rotation_y);
        play_sound_effect(this->handle_message(0x3A843), &this->position, 0, 0);
        this->status_flags |= 0x400000;
        this->actorFlags |= 0x01000000;
        VecCopy(&pos, &this->body_center);
        pos.y -= 5.0f;
        this->refresh_and_send_entity_flags();
        return;
    case 0:
        this->queue_destruction();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Gee::state_motion_test(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->stage = 0;
        return;
    case 0:
        advance_animation();
        this->stage += 1;
        if ((s32) this->stage > 0x5A) {
            this->stage = 0;
            this->requested_action = (this->requested_action + 1);
            if ((s16) this->requested_action >= 4) {
                this->requested_action = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::state_move_forward(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->hover_y = this->position.y + this->hover_height;
        this->work_speed = sin_table_lookup(this->rotation_y);
        this->orbit_radius = cos_table_lookup(this->rotation_y);
        return;
    case 0:
        advance_animation();
        this->hover_y = this->position.y + this->hover_height;
        this->body_center.y = this->hover_y;
        this->move_with_wall_slide_commit(this->work_speed, this->orbit_radius, 0.2f);
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::advance_camera_ctrl_step(NJS_OBJECT *) {
    Vec *pos;
    switch ((s32) TObjEneMe1Gee__render_node_index) {
    case 4:
        pos = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = pos + 1;
        forward_transform_to_view((const Vec *)gee_camera_ctrl_vec, pos);
        break;
    case 7:
        pos = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = pos + 1;
        forward_transform_to_view((const Vec *)gee_camera_ctrl_vec, pos);
        break;
    }
    TObjEneMe1Gee__render_node_index += 1;
}

void TObjEneMe1Gee::render() {
    s32 detail;
    s32 draw_now;

    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (this->status_flags & 0x400000) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = this->classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        if (this->status_flags & 0x01000000) {
            this->draw_ground_shadow(0, 0);
        }
        this->update_secondary_light();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        this->apply_model_color();
        push_matrix();
        post_translate_matrix(&this->position.x);
        translate_matrix(0, 0.0f, this->hover_offset, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        draw_now = 1;
        if ((this->mode == 1) || (this->mode == 0xC)) {
            this->fade.set_flags_and_apply_damage_color();
            if (this->defer_render() != 0) {
                draw_now = 0;
            }
        }
        if (draw_now != 0) {
            if ((s16) this->mode != 0xB) {
                TObjEneMe1Gee__render_node_index = 0;
                gee_camera_ctrl_step_ptr = this->node_points;
                set_chunk_model_node_callback(TObjEneMe1Gee::advance_camera_ctrl_step);
                if (detail == 1) {
                    set_motion_packed_rotation();
                    this->draw();
                    clear_motion_packed_rotation();
                } else {
                    set_motion_packed_rotation();
                    this->draw_motion_model();
                    clear_motion_packed_rotation();
                }
                set_chunk_model_node_callback(NULL);
            } else {
                rotate_matrix_z(NULL, this->rotation_z);
                TObjEneMe1Gee__render_node_index = -1;
                gee_camera_ctrl_step_ptr = this->node_points;
                set_chunk_model_node_callback(TObjEneMe1Gee::advance_camera_ctrl_step);
                this->draw_with_alt_model(this->alt_model_color);
                set_chunk_model_node_callback(NULL);
            }
        }
        if ((this->mode == 1) || (this->mode == 0xC)) {
            this->fade.clear_flag_and_notify();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
        return;
    }
    VecCopy(&this->node_points[0], &this->body_center);
    VecCopy(&this->node_points[1], &this->body_center);
}

void TObjEneMe1Gee::run_demo_task() { if (this->get_target_info() != 0) { this->apply_parameters(); } }

#pragma push
// pool_data off: render_demo reaches each debug string with its own lis/addi.
#pragma pool_data off
void TObjEneMe1Gee::render_demo() {
    if (this->get_target_info() != 0) {
        if ((s32) this->kind == 0) {
            if (this->status_flags & 0x100) {
                queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:IN FIGHTER");
            } else if (this->status_flags & 0x200) {
                queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:OUT FIGHTER");
            } else {
                queue_debug_text((s32)(pack_debug_text_position(0, 2)), "TYPE:UNKOWN");
            }
            if (this->status_flags & 0x02000000) {
                queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:LOW APPEAR");
            } else if (this->status_flags & 0x04000000) {
                queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:HIGH APPEAR");
            } else {
                queue_debug_text((s32)(pack_debug_text_position(0, 3)), "TYPE:UNKOWN");
            }
        }
        queue_debug_text((s32)(pack_debug_text_position(0, 4)), "APPEAR SPEED(+1.f Min:0.01f)");
        queue_debug_text((s32)(pack_debug_text_position(0, 5)), "NEEDLE SPEED(+6.f Min:1.f)");
    }
    if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        this->draw_ground_shadow(0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
#pragma pop

TObjEneMe1GeeLeader::~TObjEneMe1GeeLeader() {}

void TObjEneMe1GeeLeader::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        this->update_fade_sequence();
        this->update_formation_state();
    }
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneMe1GeeLeader::select_model() {
    this->model = (void *)TObjEneMe1Gee__resource_bundle->models->model;
    this->texlist = TObjEneMe1Gee__resource_bundle->models->texlist;
}

void TObjEneMe1GeeLeader::select_next_attack_state() {
    switch (this->attack_pattern) {
    case 0:
    case 1:
        this->attack_pattern++;
        this->transition_enemy_state(7);
        break;
    case 2:
        this->attack_pattern = 0;
        this->transition_enemy_state(8);
        break;
    }
}

// dead-stripped: only its literals survive. 10.0f (.sdata2 0x805DA0B8) is pooled after spawn_members'
// 0.0f and before render_demo's 400.0f, ahead of its first live user state_melee_attack (deferred codegen
// runs this file bottom-up). Minimal body after state_melee_attack's frame-10 hit check; name inferred.
static s32 is_hit_frame(TObjEneMe1GeeLeader *gee) {
    return gee->is_passing_frame(10.0f);
}

void TObjEneMe1GeeLeader::spawn_members() {
    s32 n;
    s32 i;
    s32 j;
    u16 a;
    s32 b;
    s32 angle;
    Vec v;
    n = (s32)ceil_to_float((f32)this->member_total / (f32)this->kind_params->group_size);
    if (n < 1) {
        n = 1;
    }
    a = this->entity_id + 1;
    angle = this->rotation_y;
    b = this->set_index + 1;
    for (i = 0; i < n; i++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &this->position);
        angle += 0x10000 / this->member_total;
        this->members[i] = create(this, &v, a++, b++);
        this->members[i]->set_out_fighter();
        this->member_count++;
    }
    for (j = n; j < this->member_total; j++) {
        v.x = 40.0f * sin_table_lookup(angle);
        v.y = 0.0f;
        v.z = 40.0f * cos_table_lookup(angle);
        vec3_add_to(&v, &this->position);
        angle += 0x10000 / this->member_total;
        this->members[j] = create(this, &v, a++, b++);
        this->members[j]->set_in_fighter();
        this->member_count++;
    }
}

s32 TObjEneMe1GeeLeader::check_retreat_trigger() {
    s32 i;
    if (this->status_flags & 0x40) {
        this->status_flags &= ~0x40;
        this->transition_enemy_state(12);
        for (i = 0; i < this->member_count; i++) {
            this->members[i]->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TObjEneMe1GeeLeader::remove_member(TObjEneMe1Gee *member) {
    s32 i;
    TObjEneMe1Gee *tmp;

    for (i = 0; i < this->member_count; i++) {
        if (this->members[i] == member) {
            this->member_count--;
            tmp = this->members[this->member_count];
            this->members[this->member_count] = member;
            this->members[i] = tmp;
            break;
        }
    }
    if ((s32)this->formation_state == 3) {
        s32 lim = (s32)ceil_to_float((f32)this->member_total / (f32)this->kind_params->group_size);
        if (this->member_count <= this->member_total - lim) {
            this->leader = (TObjEneMe1Gee *)find_entity_by_id(this->leader_id);
            this->leader->set_flag3c8_bit8();
        }
    }
    if (!(this->status_flags & 0x100000) && this->member_count <= this->member_total / 2) {
        this->status_flags |= 0x10;
    }
    if (this->member_count <= 2) {
        this->status_flags |= 0x40;
    }
}

int TObjEneMe1GeeLeader::can_member_attack_target(TObjChara *) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < this->member_count; i++) {
        if (this->members[i]->get_attacking_target() == this->current_target) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneMe1GeeLeader::apply_model_color() {  }

int TObjEneMe1GeeLeader::has_no_members() {
    return (u8) (this->member_count <= 0);
}

void TObjEneMe1GeeLeader::update_formation_state() {
    s32 j;
    s32 i;

    if (this->status_flags & 0x10) {
        this->status_flags &= ~0x10;
        this->formation_state = 7;
    }
    switch (this->formation_state) {
    case 1:
        this->start_fade_sequence(0);
        this->formation_state = 2;
        break;
    case 2:
        if (this->fade_mode == 0) {
            this->formation_state = 3;
            this->status_flags &= ~8;
            copy_argb(&this->core_color, (NJS_ARGB *)&gee_formation_reset_vec4);
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
        break;
    case 5:
        if (this->fade_mode == 0) {
            copy_argb(&this->core_color, (NJS_ARGB *)&gee_formation_reset_vec4);
            this->formation_state = 6;
            for (i = 0; i < this->member_count; i++) {
                if (this->members[i]->has_status_flag(0x100) != 0) {
                    this->members[i]->order_attack();
                }
            }
        }
        break;
    case 7:
        this->start_fade_sequence(4);
        this->formation_state = 8;
        break;
    case 8:
        if (this->fade_mode == 0) {
            this->formation_state = 9;
            copy_argb(&this->core_color, (NJS_ARGB *)&gee_formation_reset_vec4);
            for (j = 0; j < this->member_count; j++) {
                this->members[j]->release_from_formation();
            }
            this->release_from_formation();
        }
        break;
    case 9:
        break;
    }
}

void TObjEneMe1GeeLeader::state_activate(s32 msg) {
    s32 k;
    s32 i;
    s32 j;
    s32 m;

    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        this->clear_intangible();
        this->core_color.r = gee_formation_reset_vec4.r;
        this->core_color.g = gee_formation_reset_vec4.g;
        this->core_color.b = gee_formation_reset_vec4.b;
        this->stage = 0;
        for (k = 2, i = 0; i < this->member_count; k += 2, i++) {
            this->members[i]->order_activation(this->current_target, k);
        }
        break;
    case 3:
        if (this->status_flags & 2) {
            this->status_flags &= ~2;
            this->formation_state = 1;
            this->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        switch (this->stage) {
        case 0:
            (this->attack_delay)--;
            if (this->attack_delay <= 0) {
                this->fade_mode = 2;
                this->stage = 1;
            }
            break;
        case 1:
            if (this->fade_mode == 0) {
                this->status_flags |= 0x8000;
                for (j = 0; j < this->member_count; j++) {
                    if (this->members[j]->is_activated() == 0) {
                        break;
                    }
                }
                if (j == this->member_count) {
                    this->start_formation();
                    for (m = 0; m < this->member_count; m++) {
                        this->members[m]->start_formation();
                    }
                }
            }
            this->update();
            break;
        }
        this->hover_toward(25.0f + this->position.y);
        this->check_collisions();
        break;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TObjEneMe1GeeLeader::state_rise(s32 msg) {
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(5);
        this->clear_intangible();
        break;
    case 3:
        if (this->status_flags & 4) {
            this->select_next_attack_state();
        }
        break;
    case 0:
        advance_animation();
        this->update_linked_position(200.0f);
        this->update();
        this->update_upper_hover_height();
        this->check_collisions();
        break;
    case 5:
        break;
    }
}

void TObjEneMe1GeeLeader::state_dead(s32 msg) {
    switch (msg) {
    case 4:
        TBoss3Volopt::create_breakup_mdl(gee_leader_breakup_model, NULL,
                           this->texlist, &this->body_center, this->rotation_y);
        this->status_flags |= 0x400000;
        refresh_lobby_state();
        return;
    case 0:
        if (this->has_no_members() != 0) {
            this->send_entity_set_flags();
            this->queue_destruction();
        }
    case 3:
    case 1:
        return;
    case 5:
        this->actorFlags &= 0xFFFFFDFF;
        break;
    }
}
}
