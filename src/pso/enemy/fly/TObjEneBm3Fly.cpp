#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/ambient/TObjFish.h"
#include <stddef.h>
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/object/base/TObjBase.h"

#pragma defer_codegen on

extern "C" {
player_stats *bm3_fly_boss_stat_handle;
AttackParams * TObjEneBm3Fly__attack_params;
ActorParamBlock *bm3_fly_resist_stats;
Bm3FlyParameters * bm3_fly_lobby_params;
BmlResource * bm3_fly_nest_resources;
TBreakUpMdlData * TObjEneBm3Fly__breakup_model;
extern const f32 lbl_805D9E80;
extern void *tl_04;

const BreakUpParamRow bm3_fly_breakup_params = { 0x14, 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f };
const char *TObjEneBm3Fly__name = "TObjEneBm3Fly";

Bm3FlyMovementParameters bm3_fly_decision_row = {
    225.0f, 0.92592591f, 0x600, { 0, 0, 0, 0 },
};

CollisionBody bm3_fly_collider_params[1] = {
    {{0.0f, 0.0f, 0.0f}, 7.0f, 0.0f, 0, 0x8003},
};

TObjMotionAction bm3_fly_action_table[5] = {
    { 1, 0, 0xA, 0.6f, 0x0 },
    { 1, 1, 0xC, 0.6f, 0x0 },
    { 3, 2, 0x0, 1.0f, 0x0 },
    { 3, 0, 0x1, 1.0f, 0x0 },
    { 3, 4, 0x3, 1.0f, 0x0 },
};

const NpcAnimationBinding bm3_fly_resource_binding_desc = { NULL, bm3_fly_action_table, 0, 1, 5 };

void TObjEneBm3Fly::load_resources() {
    TBreakUpMdlData *model;
    bm3_fly_nest_resources = TObjEneBm3FlyNest::get_bml_resource();
    model = new TBreakUpMdlData(bm3_fly_nest_resources->models[0].model);
    TObjEneBm3Fly__breakup_model = model;
    bm3_fly_boss_stat_handle = TLobby::register_boss(0);
    TObjEneBm3Fly__attack_params = (AttackParams *)TLobby::dispatch_shared_handler_b(0);
    bm3_fly_resist_stats = TLobby::register_object(0);
    bm3_fly_lobby_params = (Bm3FlyParameters *)TLobby::dispatch_shared_handler_a(0);
    {
        NpcAnimationBinding binding = bm3_fly_resource_binding_desc;
        binding.motions = bm3_fly_nest_resources->motions;
        TObjNpcEnemy::register_animated_chunk(7, bm3_fly_nest_resources->models[0].model, bm3_fly_nest_resources->models[0].texlist, &binding, bm3_fly_collider_params[0].radius, 15.0f);
    }
}

TObjEneBm3Fly *TObjEneBm3Fly::create(TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *velocity) {
    return new TObjEneBm3Fly((TObject *)tl_04, nest, entity_id, set_index, position, velocity);
}

void TObjEneBm3Fly::release_shared_data() {
    if (TObjEneBm3Fly__breakup_model != NULL) {
        delete TObjEneBm3Fly__breakup_model;
        TObjEneBm3Fly__breakup_model = NULL;
    }
}

TObjEneBm3Fly::TObjEneBm3Fly(TObject *parent, TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *velocity) : TObjEneDD_ST(parent) {
    m_name = TObjEneBm3Fly__name;
    owner_id = nest->get_entity_id();
    init_common_from(nest);
    this->entity_id = entity_id;
    this->set_index = set_index;
    VecCopy(&this->position, position);
    VecCopy(&nest_position, &nest->position);
    VecCopy(&launch_velocity, velocity);
    init_child_params();
    set_entry = NULL;
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::init_child_params() {
    init_position_vectors();
    this->model = (void *)bm3_fly_nest_resources->models[0].model;
    this->texlist = bm3_fly_nest_resources->models[0].texlist;
    this->init_model(bm3_fly_collider_params, 1);
    set_action_table(bm3_fly_action_table);
    set_motion_list(bm3_fly_nest_resources->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    this->reset_hp(bm3_fly_boss_stat_handle, TObjEneBm3Fly__attack_params, bm3_fly_resist_stats);
    set_state_flag_1();
    this->movementParameters = &bm3_fly_decision_row;
    this->initialize_enemy_state(3);
    this->wall_reach = (5.0f);
    enemy_init_acquire_period(0xA);
    enemy_init_validate_period(0xA);
    set_active();
    this->actorFlags |= 0x01000000;
    this->status_flags = BM3_FLY_SHADOW;
    this->flightY = this->position.y;
    this->moveDir.x = (0.0f);
    this->moveDir.y = (0.0f);
    this->moveDir.z = (0.0f);
    this->moveSpeed = (0.0f);
    this->strike_count = 0;
    this->hover_height = (0.0f);
    this->hover_angle = 0;
    this->chase_height = (2.0f) * calc_elapsed_scaled() + (45.0f);
    this->attack_height = (2.0f) * calc_elapsed_scaled() + (15.0f);
    this->attacking = 0;
    this->particle_effect = NULL;
    this->alternate_phase = 0;
    this->step = 0;
    this->counter = 0;
    this->pad_3c8 = 0;
    this->radius_wave = 0;
    this->radius_wave_speed = 0;
    this->orbit_angle = 0;
    this->orbit_speed = 0;
    this->pad_3dc = 0;
    this->waypoint_distance = (0.0f);
    this->slide_speed = (0.0f);
    this->waypoint.x = (0.0f);
    this->waypoint.y = (0.0f);
    this->waypoint.z = (0.0f);
    this->chase_position.x = (0.0f);
    this->chase_position.y = (0.0f);
    this->chase_position.z = (0.0f);
    this->weave_offset.x = (0.0f);
    this->weave_offset.y = (0.0f);
    this->weave_offset.z = (0.0f);
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
}
#pragma pop
TObjEneBm3Fly::~TObjEneBm3Fly() {
    if (particle_effect != NULL) {
        particle_effect->queue_destruction();
        particle_effect = NULL;
    }
    free_collision_body_parts(this);
}
}
void restore_alpha_ref(void);
void set_alpha_ref_override(u8 scene);
void TObjEneBm3Fly::run_task() {
    f32 dz;
    f32 dx;
    f32 side;
    TObject *nest;
    TParticleCtrl *effect;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    nest = (TObject *)find_entity_by_id(this->owner_id);
    if (nest == NULL || nest->all_parents_unqueued_for_destruction() == 0) {
        this->queue_destruction();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        effect = this->particle_effect;
        if (effect == NULL) {
            this->particle_effect = create_particle_emitter(&this->body_center, 0xC7);
            effect = this->particle_effect;
            if (effect != NULL) {
                effect->enable();
            }
        } else if (this->mode == 9 || this->mode == 8 || this->mode == 7) {
            effect->enable();
        } else {
            if (this->alternate_phase == 0) {
                side = 3.0f;
                this->alternate_phase = 1;
            } else {
                side = -3.0f;
                this->alternate_phase = 0;
            }
            if (TObjEneDD::check_v2_mode() != 0) {
                side *= 3.0f;
            }
            dx = side * cos_table_lookup(this->rotation_y);
            dz = side * -sin_table_lookup(this->rotation_y);
            this->particle_effect->position.x = (&this->body_center)->x + dx;
            this->particle_effect->position.y = -1.5f + (&this->body_center)->y;
            this->particle_effect->position.z = (&this->body_center)->z + dz;
        }
    } else {
        effect = this->particle_effect;
        if (effect != NULL) {
            effect->enable();
        }
    }
    this->store_position();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneBm3Fly::dispatch_action(u32 state, s32 msg) {
    switch (state) {
    case 0:
        update_launch_state(msg);
        return;
    case 1:
        update_orbit_state(msg);
        return;
    case 2:
        update_chase_state(msg);
        return;
    case 3:
        execute_action(msg);
        return;
    case 4:
        state_circle_target(msg);
        return;
    case 6:
        update_recoil_state(msg);
        return;
    case 8:
        state_death_fall(msg);
        return;
    case 5:
        update_return_state(msg);
        return;
    case 7:
        action(msg);
        return;
    case 9:
        handle_message(msg);
    default:
        return;
    }
}

void TObjEneBm3Fly::refresh_target() {  }

void TObjEneBm3Fly::run_death_reaction() {
    s16 state;
    state = this->mode;
    if ((state != 8) && (state != 9) && (state != 7)) {
        if (this->was_hit_by_ranged() != 0) {
            this->transition_enemy_state(7);
            return;
        }
        this->transition_enemy_state(8);
    }
}

void TObjEneBm3Fly::run_hit_reaction() { if (this->mode != 6) { this->transition_enemy_state(6); } }

void TObjEneBm3Fly::run_miss_reaction() {  }

void TObjEneBm3Fly::update() {
    this->enemy_copy_target_destination();
    this->destination.y = (f32) (this->position.y + this->chase_height);
}

void TObjEneBm3Fly::update_height_offset() {
    this->enemy_copy_target_destination();
    this->destination.y = (f32) (this->position.y + this->attack_height);
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::circle_destination(s32 angle) {
    this->enemy_copy_target_destination();
    this->destination.x = (f32) (((7e+01f) * sin_table_lookup(angle)) + this->destination.x);
    this->destination.y = (f32) ((this->position.y) + this->chase_height);
    this->destination.z = (f32) (((7e+01f) * cos_table_lookup(angle)) + this->destination.z);
}
#pragma pop
void TObjEneBm3Fly::update_collide_flag() {
    if (this->update_ground_contact() != 0U) {
        this->status_flags |= BM3_FLY_SHADOW;
        return;
    }
    this->status_flags &= ~BM3_FLY_SHADOW;
}

void TObjEneBm3Fly::update_dd_flag(f32 x, f32 z, f32 speed) {
    if (this->move_with_wall_slide_commit(x, z, speed) != 0U) {
        this->status_flags |= BM3_FLY_SHADOW;
        return;
    }
    this->status_flags &= ~BM3_FLY_SHADOW;
}

void TObjEneBm3Fly::update_state_flag() {

    if (TObjEneEpsilon__sub_800B92F8(this, ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_08, bm3_fly_lobby_params->distance) != 0) {
        this->status_flags |= BM3_FLY_SHADOW;
        return;
    }
    this->status_flags &= ~BM3_FLY_SHADOW;
}

void TObjEneBm3Fly::store_position() {
    this->body_center.x = (f32) this->position.x;
    this->body_center.z = (f32) this->position.z;
    VecCopy(&this->center, &this->body_center);
}
#pragma push
#pragma opt_common_subs off
void TObjEneBm3Fly::clamp_flight_height() {
    if ((this->flightY - this->position.y) < (1.2f)) {
        this->flightY = (1.2f) + this->position.y;
    }
    this->body_center.y = this->flightY;
}
#pragma pop
void TObjEneBm3Fly::check_collisions() { TObjEneDD::check_collisions(); this->clamp_flight_height(); }

void TObjEneBm3Fly::update_body_colliders() {
    f32 height;
    height = this->flightY - this->position.y;
    if (height >= (3e+01f)) {
        this->set_colliders_contact_high();
    } else {
        this->set_colliders_contact_low();
    }
    this->bodies->offset.y = height;
}

f32 TObjEneBm3Fly::approach_value(f32 current, f32 target) {
    f32 diff;
    f32 delta;

    diff = target - current;
    if (fabs_float(diff) < (0.2f)) {
        return target;
    }
    delta = (0.1f);
    delta = diff * delta;
    if (delta > (1.5f)) {
        delta = (1.5f);
    } else if (delta < (-1.5f)) {
        delta = (-1.5f);
    }
    return current + delta;
}

s32 TObjEneBm3Fly::can_attack_target() {
    f32 facing;
    if ((this->destination_distance < ((5.0f) + TObjEneBm3Fly__attack_params->get_attack_range())) && (fabs_float((f32) (this->flightY - this->destination.y)) < (1.0f))) {
        facing = vec3_dot(&this->moveDir, &this->destination_direction);
        if (facing >= cos_table_lookup(this->attack_params->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
}

void TObjEneBm3Fly::choose_attack() {
    TargetCandidate players[4];
    TObjEneBm3FlyNest *nest;
    s32 count;
    u16 id;
    s32 i;
    nest = (TObjEneBm3FlyNest *)find_entity_by_id(this->owner_id);
    if (nest == NULL) {
        this->transition_enemy_state(4);
        this->attacking = 0;
    }
    if (nest->has_free_attack_slot(this->target_id) != 0) {
        this->transition_enemy_state(3);
        return;
    }
    count = collect_enemy_target_candidates(this, players, (1e+04f));
    for (i = 0; i < count; i++) {
        id = players[i].id;
        if (id != this->target_id && nest->has_free_attack_slot(id) != 0) {
            enemy_set_target_id(this, id);
            this->transition_enemy_state(3);
            return;
        }
    }
    this->transition_enemy_state(4);
    this->attacking = 0;
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::pick_hover_point() {
    this->hover_height = (f32) (((2.0f) * calc_elapsed_scaled()) + ((45.0f) + this->nest_position.y));
    this->hover_angle = get_random_scaled();
}
#pragma pop
u16 TObjEneBm3Fly::get_active_id() {
    if (this->attacking != 0) {
        return this->target_id;
    }
    return 0xFFFFU;
}

void TObjEneBm3Fly::play_pitched_cue() {
    play_persistent_sound(this->remap_sound_for_area(0x40039E22), this, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

void TObjEneBm3Fly::play_orbit_flight_sound() {
    play_persistent_sound(this->remap_sound_for_area(0x4003AB23), this, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

s32 TObjEneBm3Fly::acquire_target(f32 range) {
    if (this->is_confused() != 0) {
        return this->select_and_apply_target(range);
    }
    return select_nearest_target(range);
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneBm3Fly::update_launch_state(s32 msg) {
    Vec *p = &this->waypoint;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags |= 0x01000000;
        this->pick_hover_point();
        this->step = 0;
        this->counter = 0;
        p->x = (3e+01f) * sin_table_lookup(this->hover_angle) + this->nest_position.x;
        p->y = this->hover_height;
        p->z = (3e+01f) * cos_table_lookup(this->hover_angle) + this->nest_position.z;
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->launch_velocity.x, this->launch_velocity.z));
        this->enemy_clear_target();
        break;
    case 3:
        if (this->counter == 2) {
            this->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->counter) {
        case 0:
            this->position.x += this->launch_velocity.x;
            this->flightY += this->launch_velocity.y;
            this->position.z += this->launch_velocity.z;
            this->launch_velocity.x *= (0.9f);
            this->launch_velocity.y += lbl_805D9E80;
            this->launch_velocity.z *= (0.9f);
            this->step++;
            if (this->step > 40) {
                this->counter = 1;
                this->step = 0;
                this->moveSpeed = (0.0f);
            }
            break;
        case 1:
            VecCopy(&this->moveDir, p);
            this->moveDir.x -= this->position.x;
            this->moveDir.y -= this->flightY;
            this->moveDir.z -= this->position.z;
            this->waypoint_distance = normalize_vector_safe(&this->moveDir);
            if (this->moveSpeed < (2.0f)) {
                this->moveSpeed += (0.1f);
            }
            if (this->waypoint_distance < (2.0f)) {
                VecCopy(&this->position, p);
                this->counter = 2;
            } else {
                this->position.x = this->moveDir.x * this->moveSpeed + this->position.x;
                this->flightY = this->moveDir.y * this->moveSpeed + this->flightY;
                this->position.z = this->moveDir.z * this->moveSpeed + this->position.z;
            }
            this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->moveDir.x, this->moveDir.z));
            break;
        }
        this->update_collide_flag();
        this->prev_position.x = this->body_center.x;
        this->prev_position.z = this->body_center.z;
        this->clamp_flight_height();
        this->update_body_colliders();
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::update_orbit_state(s32 msg) {
    Vec d;
    f32 radius;
    s32 a;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags |= 0x01000000;
        this->radius_wave = 0;
        this->radius_wave_speed = (s32)((512.0f) * calc_elapsed_scaled()) + 0x800;
        this->orbit_angle = this->hover_angle;
        this->orbit_speed = (s32)((512.0f) * calc_elapsed_scaled()) + 0xA00;
        d.x = this->position.x - this->nest_position.x;
        d.y = (0.0f);
        d.z = this->position.z - this->nest_position.z;
        if (is_vec_xz_cross_negative(&d, &this->moveDir) != 0) {
            this->orbit_speed *= -1;
        }
        this->enemy_clear_target();
        this->pad_3c8 = -1;
        break;
    case 3:
        if (this->update_linked_position(2e+02f) != 0) {
            this->transition_enemy_state(2);
        }
        break;
    case 0:
        this->advance_animation();
        this->counter++;
        if (this->counter > 300) {
            this->counter = 0;
            this->orbit_speed = (s32)((512.0f) * calc_elapsed_scaled()) + 0xA00;
        }
        this->radius_wave += this->radius_wave_speed;
        radius = (3e+01f) * cos_table_lookup(this->radius_wave / 2);
        this->orbit_angle += this->orbit_speed;
        a = this->orbit_angle;
        this->position.x = radius * sin_table_lookup(a) + this->nest_position.x;
        this->flightY = (1e+01f) * sin_table_lookup(this->orbit_angle) + this->hover_height;
        this->position.z = radius * cos_table_lookup(a) + this->nest_position.z;
        this->rotation_y = a - 0x4000;
        this->update_collide_flag();
        this->prev_position.x = this->body_center.x;
        this->prev_position.z = this->body_center.z;
        this->update_body_colliders();
        play_orbit_flight_sound();
        break;
    case 5:
        this->moveDir.x = this->position.x - this->prev_position.x;
        this->moveDir.y = (0.0f);
        this->moveDir.z = this->position.z - this->prev_position.z;
        this->moveSpeed = normalize_vector_safe(&this->moveDir);
        break;
    }
}
#pragma pop
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::update_chase_state(s32 msg) {
    Vec *pos;
    Vec *off;
    Vec *vel;
    Vec p;
    Vec d;
    f32 z;
    f32 x;
    f32 s;
    f32 len;

    vel = &this->chase_velocity;
    pos = &this->chase_position;
    off = &this->weave_offset;

    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags |= 0x01000000;
        vel->x = this->moveDir.x * this->moveSpeed;
        vel->y = (0.0f);
        vel->z = this->moveDir.z * this->moveSpeed;
        if (is_vec_xz_cross_negative(&this->moveDir, &this->destination_direction) != 0) {
            this->weave_angle = 0x8000;
        } else {
            this->weave_angle = 0;
        }
        this->counter = 0;
        off->x = (0.0f);
        off->y = (0.0f);
        off->z = (0.0f);
        pos->x = (0.0f);
        pos->y = this->flightY - this->position.y;
        pos->z = (0.0f);
        break;
    case 3:
        if (this->destination_distance > (4.5e+02f) || this->current_target == NULL) {
            this->transition_enemy_state(5);
        } else if (this->destination_distance < (1e+02f)) {
            this->choose_attack();
        }
        break;
    case 0:
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0 && this->acquire_target(2e+02f) == 0) {
            break;
        }
        this->update();
        this->update_velocity();
        VecCopy(pos, &this->body_center);
        subtract_vector(pos, off);
        if (this->counter == 0) {
            if ((0.0f) == this->moveDir.x && (0.0f) == this->moveDir.z) {
                this->moveDir.x = sin_table_lookup(this->rotation_y);
                this->moveDir.z = cos_table_lookup(this->rotation_y);
            }
            if (vec3_dot(&this->moveDir, &this->destination_direction) < (0.99f)) {
                if (is_vec_xz_cross_negative(&this->moveDir, &this->destination_direction) != 0) {
                    x = -this->moveDir.z;
                    z = this->moveDir.x;
                } else {
                    x = this->moveDir.z;
                    z = -this->moveDir.x;
                }
                vel->x = (0.18f) * x + vel->x;
                vel->y = (0.0f);
                vel->z = (0.18f) * z + vel->z;
                VecCopy(&this->moveDir, vel);
                normalize_vector_safe(&this->moveDir);
            } else {
                this->counter = 1;
                VecCopy(&this->moveDir, &this->destination_direction);
            }
        } else {
            VecCopy(&this->moveDir, &this->destination_direction);
            s = (5.0f) * sin_table_lookup(this->weave_angle);
            this->weave_angle += 0x600;
            off->x = this->destination_direction.z * s;
            off->y = (0.0f);
            off->z = -this->destination_direction.x * s;
        }
        if (this->moveSpeed > ((Bm3FlyMovementParameters *)this->movementParameters)->length) {
            this->moveSpeed *= (0.96f);
        } else {
            this->moveSpeed = ((Bm3FlyMovementParameters *)this->movementParameters)->length;
        }
        vel->x = this->moveDir.x * this->moveSpeed;
        vel->y = (0.0f);
        vel->z = this->moveDir.z * this->moveSpeed;
        pos->x += vel->x;
        pos->z += vel->z;
        VecCopy(&p, pos);
        vec3_add_to(&p, off);
        VecCopy(&d, &p);
        subtract_vector(&d, &this->position);
        d.y = (0.0f);
        len = normalize_vector_xz(&d);
        this->update_dd_flag(d.x, d.z, len);
        this->flightY = this->approach_value(pos->y, this->destination.y);
        pos->y = this->flightY;
        this->clamp_flight_height();
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->moveDir.x, this->moveDir.z));
        this->check_collisions();
        pos->x -= this->position.x;
        pos->y -= this->flightY;
        pos->z -= this->position.z;
        this->play_pitched_cue();
        break;
    case 5:
        this->moveSpeed = ((Bm3FlyMovementParameters *)this->movementParameters)->length;
        break;
    }
}
#pragma pop
void TObjEneBm3Fly::execute_action(s32 msg) {
    TObjChara *target;

    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags &= ~0x01000000;
        this->counter = 0;
        this->step = 0;
        this->attacking = 1;
        return;
    case 3:
        if (this->destination_distance > (4.5e+02f)) {
            this->transition_enemy_state(5);
            return;
        }
        switch (this->step) {
        case 0:
        case 1:
            if (this->current_target == NULL) {
                this->transition_enemy_state(5);
            }
        case 2:
            return;
        case 3:
            this->transition_enemy_state(4);
            return;
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            this->enemy_clear_target();
        }
        switch (this->step) {
        case 0:
            if (this->current_target != NULL) {
                update_height_offset();
            }
            this->update_velocity();
            this->moveDir.x = sin_table_lookup(this->rotation_y);
            this->moveDir.z = cos_table_lookup(this->rotation_y);
            update_state_flag();
            this->flightY = this->approach_value(this->flightY, this->destination.y);
            this->clamp_flight_height();
            if (can_attack_target() != 0) {
                this->requested_action = 0;
                this->step = 1;
            }
            break;
        case 1:
            this->counter++;
            if ((s32) this->counter >= bm3_fly_lobby_params->unknown_1C) {
                this->counter = 0;
                this->step = 2;
                this->requested_action = 2;
            }
            this->update_collide_flag();
            break;
        case 2:
            if (is_passing_frame(9.0f) != 0) {
                this->strike_count++;
                target = this->current_target;
                if ((target != NULL) && (target->select_melee_contact_body(this, (1.0f)) != 0)) {
                    this->current_target->receive_physical_attack(this, (1.0f));
                    this->current_target->apply_knockback_from_attacker((u8 *)this, (3.0f));
                    if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() < (0.05f))) {
                        TObjEneDD::inflict_poison(this, this->current_target);
                    }
                }
                play_sound_effect(this->remap_sound_for_area(0x4003A524), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x400);
            }
            if (this->get_flag_b4() != 0) {
                if (this->strike_count >= 4) {
                    this->strike_count = 0;
                    this->step = 3;
                } else {
                    this->requested_action = 1;
                    this->step = 0;
                }
            }
            this->update_collide_flag();
            break;
        }
        this->check_collisions();
        this->play_pitched_cue();
        return;
    case 5:
        this->attacking = 0;
        break;
    }
}

void TObjEneBm3Fly::state_circle_target(s32 msg) {
    f32 speed;
    f32 vertical;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags |= 0x01000000;
        if (this->mode == 4) {
            this->step = 2;
            this->swept_angle = 0;
        } else {
            this->step = 0;
            this->circle_angle = this->rotation_y + 0x8000;
            this->circle_speed = 0;
            this->swept_angle = 0;
            this->bob_angle = 0;
        }
        break;
    case 3:
        if (this->current_target == NULL) {
            this->transition_enemy_state(5);
        } else if (this->swept_angle > 0x8000 || this->swept_angle < -0x8000) {
            choose_attack();
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0 && this->acquire_target(2e+02f) == 0) {
            break;
        }
        switch (this->step) {
        case 0:
            circle_destination(this->circle_angle);
            this->update_velocity();
            vertical = (0.0f);
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->length;
            if (this->destination_distance < (14.0f)) {
                if (this->random_ratio() > (0.5f)) {
                    this->circle_speed = (s32)(((-65536.0f) * speed) / (439.82288f));
                } else {
                    this->circle_speed = (s32)(((65536.0f) * speed) / (439.82288f));
                }
                this->step = 1;
            }
            break;
        case 1:
            this->circle_angle += this->circle_speed / 2;
            this->swept_angle += this->circle_speed / 2;
            circle_destination(this->circle_angle);
            this->update_velocity();
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->length;
            vertical = (0.0f);
            if (this->destination_distance < speed) {
                this->step = 2;
            }
            break;
        case 2:
            this->circle_angle += this->circle_speed;
            this->swept_angle += this->circle_speed;
            circle_destination(this->circle_angle);
            this->update_velocity();
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->length;
            vertical = (1e+01f) * sin_table_lookup(this->bob_angle);
            this->bob_angle += 0x380;
            break;
        }
        VecCopy(&this->moveDir, &this->destination_direction);
        update_dd_flag(this->moveDir.x, this->moveDir.z, speed);
        this->flightY = this->approach_value(this->flightY, this->destination.y + vertical);
        this->clamp_flight_height();
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(
            this->current_target->position.x - this->position.x, this->current_target->position.z - this->position.z));
        this->check_collisions();
        this->play_pitched_cue();
        break;
    case 1:
        break;
    case 5:
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::update_return_state(s32 msg) {
    Bm3FlyMovementParameters *params;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->actorFlags |= 0x01000000;
        this->pick_hover_point();
        this->destination.x = (f32) (((3e+01f) * sin_table_lookup(this->hover_angle)) + this->nest_position.x);
        this->destination.y = (f32) this->hover_height;
        this->destination.z = (f32) (((3e+01f) * cos_table_lookup(this->hover_angle)) + this->nest_position.z);
        params = (Bm3FlyMovementParameters *)this->movementParameters;
        this->arrive_distance = 2.0f + TObjBoss2Tunnel::calc_scaled_value(params->unknown_08, params->length);
        this->update_velocity();
        break;
    case 3:
        if (this->update_linked_position(2e+02f) != 0) {
            this->transition_enemy_state(2);
        } else if (this->destination_distance < this->arrive_distance) {
            this->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        this->update_velocity();
        this->flightY = this->approach_value(this->flightY, this->destination.y);
        this->update_state_flag();
        this->update_body_colliders();
        this->clamp_flight_height();
        this->transform_part_positions();
        this->play_pitched_cue();
        break;
    }
}
#pragma pop
#pragma push
#pragma opt_common_subs off
void TObjEneBm3Fly::update_recoil_state(s32 msg) {
    s32 t;
    f32 v;
    switch (msg) {
    case 4:
        this->requested_action = 3;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->set_field_378(this->mode);
        ((TBoss8Dragon *)this)->noop();
        play_sound_effect(this->remap_sound_for_area(0x4003E425), &this->position, 0, 0);
        this->step = 0;
        break;
    case 3:
        if (this->motion_flags & 0x10) {
            if (this->is_confused() != 0) {
                this->acquire_target(2e+02f);
            }
            if (this->next_mode == 3) {
                choose_attack();
            } else {
                this->transition_enemy_state(this->next_mode);
            }
        }
        break;
    case 0:
        advance_animation();
        t = this->step;
        this->step = t + 1;
        this->moveDir.x = this->velocity.x;
        this->moveDir.z = this->velocity.z;
        v = normalize_vector_xz(&this->moveDir);
        update_dd_flag(this->moveDir.x, this->moveDir.z, v);
        this->clamp_flight_height();
        this->velocity.x *= (0.5f);
        this->velocity.z *= (0.5f);
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        break;
    }
}
#pragma pop
void TObjEneBm3Fly::action(s32 msg) {
    TObjEneBm3FlyNest *nest;

    switch (msg) {
    case 4:
        this->clear_intangible();
        this->status_flags |= BM3_FLY_HIDDEN;
        this->status_flags &= ~BM3_FLY_SHADOW;
        this->set_entry = NULL;
        this->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(this->owner_id);
        if (nest != NULL) {
            nest->remove_child(this);
        }
        TBoss8Dragon__sub_800BB7DC(this);
        TBoss8Dragon__sub_800BB7D8(this, 0xF1, 1.0f);
        play_sound_effect(this->remap_sound_for_area(0x4003E425), &this->position, 0, 0);
        TBoss3Volopt::create_breakup_mdl(TObjEneBm3Fly__breakup_model, &bm3_fly_breakup_params,
                           this->texlist, &this->body_center, this->rotation_y);
        this->step = 0;
        return;
    case 3:
        if (this->step >= 2) {
            this->transition_enemy_state(9);
        }
    case 5:
        return;
    case 0:
        this->step++;
        break;
    }
}

void TObjEneBm3Fly::state_death_fall(s32 msg) {
    TObjEneBm3FlyNest *nest;
    s32 sound;
    switch (msg) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        this->status_flags &= ~BM3_FLY_HIDDEN;
        this->status_flags |= BM3_FLY_SHADOW;
        this->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(this->owner_id);
        if (nest != NULL) {
            nest->remove_child(this);
        }
        TBoss8Dragon__sub_800BB7DC(this);
        this->step = 0;
        this->counter = 0;
        this->vertical_speed = 0.0f;
        this->moveDir.x = (f32) this->velocity.x;
        this->moveDir.z = (f32) this->velocity.z;
        this->slide_speed = normalize_vector_xz(&this->moveDir);
        sound = this->remap_sound_for_area(0x4003E425);
        play_sound_effect(sound, &this->position, 0, 0);
        return;
    case 3:
        if ((this->flightY - this->position.y) < (-2e+01f)) {
            this->transition_enemy_state(9);
        }
        break;
    case 0:
        advance_animation();
        switch (this->step) {
        case 0:
        case 1:
            update_dd_flag(this->moveDir.x, this->moveDir.z, this->slide_speed);
            this->vertical_speed = (f32) (this->vertical_speed - (0.1f));
            this->flightY = (f32) (this->flightY + this->vertical_speed);
            if (this->flightY < (1.2f) + this->position.y) {
                this->flightY = (1.2f) + this->position.y;
                if ((this->step == 0) && (this->get_flag_b4() == 0)) {
                    this->step = 1;
                    this->vertical_speed = 0.5f;
                    this->slide_speed *= (0.98f);
                } else {
                    this->step = 2;
                    this->slide_speed = 0.0f;
                    this->status_flags &= ~BM3_FLY_SHADOW;
                    spawn_landing_dead_spot(&position, 0xA);
                    spawn_effect_at_ground(&this->position, 0x1E);
                }
            }
            this->clamp_flight_height();
            break;
        case 2:
            this->counter++;
            this->flightY = (f32) (this->flightY - (0.1f));
            break;
        }
        this->slide_speed *= (0.98f);
        break;
    case 1:
    case 5:
        break;
    }
}

void TObjEneBm3Fly::handle_message(s32 msg) {
    switch (msg) {
    case 4:
        this->status_flags |= BM3_FLY_HIDDEN;
        this->status_flags &= ~BM3_FLY_SHADOW;
        return;
    case 3:
        this->queue_destruction();
    case 5:
    case 0:
        return;
    }
}

void TObjEneBm3Fly::run_demo_task() {  }

void TObjEneBm3Fly::render() {
    s32 kind;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (this->status_flags & BM3_FLY_HIDDEN) {
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        kind = this->classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, (15.0f));
    } else if (this->update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        kind = 1;
    } else {
        kind = 0;
    }
    if (kind != 0) {
        if (this->status_flags & BM3_FLY_SHADOW) {
            Vec v = {0.8f, 1.0f, 0.8f};
            this->draw_ground_shadow(&v, 0);
        }
        this->update_secondary_light();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        translate_matrix(0, this->position.x, this->flightY, this->position.z);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_alpha_ref_override(0x8F);
        if (kind == 1) {
            this->draw();
        } else {
            this->draw_motion_model();
        }
        restore_alpha_ref();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        this->update_primary_light();
    }
}

void TObjEneBm3Fly::render_demo() {
    if (update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjEneMoja::bindModel(int index) {
    model = moja_bml_resource->models[index].model;
    texlist = moja_bml_resource->models[index].texlist;
}

f32 AttackParams::get_damage_radius() { return damage_radius; }
