#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
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
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
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

#pragma defer_codegen on

extern BmlResource *lbl_805D50D8;
extern "C" {
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
s32 post_translate_matrix(void *);
u8 * bm3_fly_boss_stat_handle;
AttackParams * TObjEneBm3Fly__attack_params;
u8 * lbl_805D50E8;
Bm3FlyParameters * lbl_805D50EC;
BmlResource * bm3_fly_nest_resources;
TUnk_8048FA00 * TObjEneBm3Fly__breakup_model;
s32 vec3_add_to(void *, void *);
f32 vec3_dot(void *, void *);
s32 subtract_vector(void *, void *);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly);
f32 calc_scaled_value__15TObjBoss2TunnelFlf(int, int, f32, f32);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *ene_bm3_fly, s32 msg);
f32 atan2_float(f32, f32);
extern const f32 lbl_805D9E80;
s32 is_vec_xz_cross_negative(void *, void *);
void TObjEneBm3Fly__sub_800B0F70(TObjEneBm3Fly *self, s32 msg);
f32 fabs_float(f32);
u16 get_entity_id(void *);
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *ene_bm3_fly, s32 msg);
void free_collision_body_parts(void *);
extern void *tl_04;

const TBoss3VoloptBreakupParams bm3_fly_breakup_params = { 0x14, { 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f } };
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

const NpcAnimationBinding bm3_fly_resource_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(bm3_fly_action_table), 0, 1, 5 };

void TObjEneBm3Fly::load_resources() {
    TUnk_8048FA00 *model;
    bm3_fly_nest_resources = TObjEneBm3FlyNest::sub_800B4158();
    model = new TUnk_8048FA00((saddr)bm3_fly_nest_resources->models[0].model);
    TObjEneBm3Fly__breakup_model = model;
    bm3_fly_boss_stat_handle = (u8 *)TLobby::register_boss(0);
    TObjEneBm3Fly__attack_params = (AttackParams *)TLobby::dispatch_shared_handler_b(0);
    lbl_805D50E8 = (u8 *)TLobby::register_object(0);
    lbl_805D50EC = (Bm3FlyParameters *)TLobby::dispatch_shared_handler_a(0);
    {
        NpcAnimationBinding binding = bm3_fly_resource_binding_desc;
        binding.motions = reinterpret_cast<BmlMotionEntry *>(bm3_fly_nest_resources->motions);
        NpcModelRegistry::register_animated_chunk(7, reinterpret_cast<void *>(bm3_fly_nest_resources->models[0].model), reinterpret_cast<void *>(bm3_fly_nest_resources->models[0].m_c), &binding, bm3_fly_collider_params[0].radius, 15.0f);
    }
}

TObjEneBm3Fly *TObjEneBm3Fly::create(s32 entity_id, s32 set_index, const Vec *position, const Vec *velocity) {
    return new TObjEneBm3Fly((TObject *)tl_04, (TObjEneBm3FlyNest *)this, entity_id, set_index, position, velocity);
}

void TObjEneBm3Fly::release_shared_data() {
    if (TObjEneBm3Fly__breakup_model != NULL) {
        delete TObjEneBm3Fly__breakup_model;
        TObjEneBm3Fly__breakup_model = NULL;
    }
}

TObjEneBm3Fly::TObjEneBm3Fly(TObject *parent, TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *arg6) : TObjEneDD_ST(parent) {
    m_name = TObjEneBm3Fly__name;
    owner_id = get_entity_id(nest);
    init_common_from((u8 *)nest);
    this->entity_id = entity_id;
    this->set_index = set_index;
    VecCopy(&this->position, position);
    VecCopy(&m_41c, &nest->position);
    VecCopy(&m_40c, arg6);
    init_child_params();
    set_entry = NULL;
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::init_child_params() {
    init_position_vectors();
    this->model = (void *)bm3_fly_nest_resources->models[0].model;
    this->texlist = (saddr)bm3_fly_nest_resources->models[0].m_c;
    this->init_model(bm3_fly_collider_params, 1);
    set_field_d8((saddr)bm3_fly_action_table);
    set_field_dc((saddr)bm3_fly_nest_resources->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    this->reset_hp(bm3_fly_boss_stat_handle, (u8 *)TObjEneBm3Fly__attack_params, lbl_805D50E8);
    set_state_flag_1();
    this->movementParameters = &bm3_fly_decision_row;
    this->initialize_enemy_state(3);
    this->wall_reach = (5.0f);
    enemy_init_acquire_period(0xA);
    enemy_init_validate_period(0xA);
    set_active();
    this->actorFlags |= 0x01000000;
    this->m_428 = 2;
    this->m_42c = this->position.y;
    this->m_430.x = (0.0f);
    this->m_430.y = (0.0f);
    this->m_430.z = (0.0f);
    this->m_43c = (0.0f);
    this->m_440 = 0;
    this->m_444 = (0.0f);
    this->m_448 = 0;
    this->m_44c = (2.0f) * calc_elapsed_scaled() + (45.0f);
    this->m_450 = (2.0f) * calc_elapsed_scaled() + (15.0f);
    this->m_454 = 0;
    this->particle_effect = NULL;
    this->alternate_phase = 0;
    this->m_3c0 = 0;
    this->m_3c4 = 0;
    this->m_3c8 = 0;
    this->m_3cc = 0;
    this->m_3d0 = 0;
    this->m_3d4 = 0;
    this->m_3d8 = 0;
    this->m_3dc = 0;
    this->m_3e0 = (0.0f);
    this->m_3e4 = (0.0f);
    this->m_3e8.x = (0.0f);
    this->m_3e8.y = (0.0f);
    this->m_3e8.z = (0.0f);
    this->m_3f4.x = (0.0f);
    this->m_3f4.y = (0.0f);
    this->m_3f4.z = (0.0f);
    this->m_400.x = (0.0f);
    this->m_400.y = (0.0f);
    this->m_400.z = (0.0f);
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
void spawn_landing_dead_spot(s32 point, s32 delay);
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
        sub_800B1214(msg);
        return;
    case 1:
        TObjEneBm3Fly__sub_800B0F70(this, msg);
        return;
    case 2:
        TObjEneBm3Fly__sub_800B0B20(this, msg);
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
        TObjEneBm3Fly__sub_800B02C8(this, msg);
        return;
    case 7:
        action__13TObjEneBm3FlyFPvi(this, msg);
        return;
    case 9:
        handle_message(msg);
    default:
        return;
    }
}

void TObjEneBm3Fly::refresh_target() {  }

void TObjEneBm3Fly::run_death_reaction() {
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 8) && (temp_r0 != 9) && (temp_r0 != 7)) {
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
    this->destination.y = (f32) (this->position.y + this->m_44c);
}

void TObjEneBm3Fly::update_height_offset() {
    this->enemy_copy_target_destination();
    this->destination.y = (f32) (this->position.y + this->m_450);
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::circle_destination(s32 arg1) {
    this->enemy_copy_target_destination();
    this->destination.x = (f32) (((7e+01f) * sin_table_lookup(arg1)) + this->destination.x);
    this->destination.y = (f32) ((this->position.y) + this->m_44c);
    this->destination.z = (f32) (((7e+01f) * cos_table_lookup(arg1)) + this->destination.z);
}
#pragma pop
void TObjEneBm3Fly::update_collide_flag() {
    if (this->update_ground_contact() != 0U) {
        this->m_428 |= 2;
        return;
    }
    this->m_428 &= ~2;
}

void TObjEneBm3Fly::update_dd_flag(f32 x, f32 z, f32 speed) {
    if (this->move_with_wall_slide_commit(x, z, speed) != 0U) {
        this->m_428 |= 2;
        return;
    }
    this->m_428 &= ~2;
}

void TObjEneBm3Fly::update_state_flag() {

    if (TObjEneEpsilon__sub_800B92F8(this, ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_08, lbl_805D50EC->unknown_00) != 0) {
        this->m_428 |= 2;
        return;
    }
    this->m_428 &= ~2;
}

void TObjEneBm3Fly::store_position() {
    this->body_center.x = (f32) this->position.x;
    this->body_center.z = (f32) this->position.z;
    VecCopy(&this->center, &this->body_center);
}
#pragma push
#pragma opt_common_subs off
void TObjEneBm3Fly::clamp_flight_height() {
    if ((this->m_42c - this->position.y) < (1.2f)) {
        this->m_42c = (1.2f) + this->position.y;
    }
    this->body_center.y = this->m_42c;
}
#pragma pop
void TObjEneBm3Fly::check_collisions() { TObjEneDD::check_collisions(); this->clamp_flight_height(); }

void TObjEneBm3Fly::update_body_colliders() {
    f32 temp_f31;
    temp_f31 = this->m_42c - this->position.y;
    if (temp_f31 >= (3e+01f)) {
        this->set_colliders_contact_high();
    } else {
        this->set_colliders_contact_low();
    }
    this->bodies->offset.y = temp_f31;
}

f32 TObjEneBm3Fly::approach_value(f32 current, f32 target) {
    f32 temp_f31;
    f32 var_f1;
    f32 cap;

    temp_f31 = target - current;
    if (fabs_float(temp_f31) < (0.2f)) {
        return target;
    }
    var_f1 = (0.1f);
    var_f1 = temp_f31 * var_f1;
    if (var_f1 > (1.5f)) {
        var_f1 = (1.5f);
    } else if (var_f1 < (-1.5f)) {
        var_f1 = (-1.5f);
    }
    return current + var_f1;
}

s32 TObjEneBm3Fly::can_attack_target() {
    f32 temp_f31;
    if ((this->destination_distance < ((5.0f) + TObjEneBm3Fly__attack_params->get_attack_range())) && (fabs_float((f32) (this->m_42c - this->destination.y)) < (1.0f))) {
        temp_f31 = vec3_dot(&this->m_430, &this->destination_direction);
        if (temp_f31 >= cos_table_lookup(((AttackParams *)(this->m_318))->get_attack_angle())) {
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
        this->m_454 = 0;
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
    this->m_454 = 0;
}
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::sub_800B1634() {
    this->m_444 = (f32) (((2.0f) * calc_elapsed_scaled()) + ((45.0f) + this->m_41c.y));
    this->m_448 = get_random_scaled();
}
#pragma pop
u16 TObjEneBm3Fly::get_active_id() {
    if (this->m_454 != 0) {
        return this->target_id;
    }
    return 0xFFFFU;
}

void TObjEneBm3Fly::play_pitched_cue() {
    play_persistent_sound(this->remap_sound_for_area(0x40039E22), (saddr)this, (uaddr)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly) {
    play_persistent_sound(fly->remap_sound_for_area(0x4003AB23), (saddr)fly, (uaddr)&fly->position, 0, 0);
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
void TObjEneBm3Fly::sub_800B1214(s32 msg) {
    Vec *p = &this->m_3e8;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->actorFlags |= 0x01000000;
        this->sub_800B1634();
        this->m_3c0 = 0;
        this->m_3c4 = 0;
        p->x = (3e+01f) * sin_table_lookup(this->m_448) + this->m_41c.x;
        p->y = this->m_444;
        p->z = (3e+01f) * cos_table_lookup(this->m_448) + this->m_41c.z;
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->m_40c.x, this->m_40c.z));
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        break;
    case 3:
        if (this->m_3c4 == 2) {
            this->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->m_3c4) {
        case 0:
            this->position.x += this->m_40c.x;
            this->m_42c += this->m_40c.y;
            this->position.z += this->m_40c.z;
            this->m_40c.x *= (0.9f);
            this->m_40c.y += lbl_805D9E80;
            this->m_40c.z *= (0.9f);
            this->m_3c0++;
            if (this->m_3c0 > 40) {
                this->m_3c4 = 1;
                this->m_3c0 = 0;
                this->m_43c = (0.0f);
            }
            break;
        case 1:
            VecCopy(&this->m_430, p);
            this->m_430.x -= this->position.x;
            this->m_430.y -= this->m_42c;
            this->m_430.z -= this->position.z;
            this->m_3e0 = normalize_vector_safe(&this->m_430);
            if (this->m_43c < (2.0f)) {
                this->m_43c += (0.1f);
            }
            if (this->m_3e0 < (2.0f)) {
                VecCopy(&this->position, p);
                this->m_3c4 = 2;
            } else {
                this->position.x = this->m_430.x * this->m_43c + this->position.x;
                this->m_42c = this->m_430.y * this->m_43c + this->m_42c;
                this->position.z = this->m_430.z * this->m_43c + this->position.z;
            }
            this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->m_430.x, this->m_430.z));
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
void TObjEneBm3Fly__sub_800B0F70(TObjEneBm3Fly *self, s32 msg) {
    Vec d;
    f32 radius;
    s32 a;
    switch (msg) {
    case 4:
        self->requested_action = 1;
        self->set_intangible();
        self->m_428 &= ~1;
        self->m_428 |= 2;
        self->actorFlags |= 0x01000000;
        self->m_3cc = 0;
        self->m_3d0 = (s32)((512.0f) * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 0x800;
        self->m_3d4 = self->m_448;
        self->m_3d8 = (s32)((512.0f) * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 0xA00;
        d.x = self->position.x - self->m_41c.x;
        d.y = (0.0f);
        d.z = self->position.z - self->m_41c.z;
        if (is_vec_xz_cross_negative(&d, &self->m_430) != 0) {
            self->m_3d8 *= -1;
        }
        ((TObjEneDD_ST *)(self))->enemy_clear_target();
        self->m_3c8 = -1;
        break;
    case 3:
        if (self->update_linked_position(2e+02f) != 0) {
            self->transition_enemy_state(2);
        }
        break;
    case 0:
        self->advance_animation();
        self->m_3c4++;
        if (self->m_3c4 > 300) {
            self->m_3c4 = 0;
            self->m_3d8 = (s32)((512.0f) * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 0xA00;
        }
        self->m_3cc += self->m_3d0;
        radius = (3e+01f) * cos_table_lookup(self->m_3cc / 2);
        self->m_3d4 += self->m_3d8;
        a = self->m_3d4;
        self->position.x = radius * sin_table_lookup(a) + self->m_41c.x;
        self->m_42c = (1e+01f) * sin_table_lookup(self->m_3d4) + self->m_444;
        self->position.z = radius * cos_table_lookup(a) + self->m_41c.z;
        self->rotation_y = a - 0x4000;
        self->update_collide_flag();
        self->prev_position.x = self->body_center.x;
        self->prev_position.z = self->body_center.z;
        self->update_body_colliders();
        TObjEneBm3Fly__play_orbit_flight_sound(self);
        break;
    case 5:
        self->m_430.x = self->position.x - self->prev_position.x;
        self->m_430.y = (0.0f);
        self->m_430.z = self->position.z - self->prev_position.z;
        self->m_43c = normalize_vector_safe(&self->m_430);
        break;
    }
}
#pragma pop
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *ene_bm3_fly, s32 msg) {
    Vec *pos;
    Vec *off;
    Vec *vel;
    Vec p;
    Vec d;
    f32 z;
    f32 x;
    f32 s;
    f32 len;

    vel = &ene_bm3_fly->m_3e8;
    pos = &ene_bm3_fly->m_3f4;
    off = &ene_bm3_fly->m_400;

    switch (msg) {
    case 4:
        ene_bm3_fly->requested_action = 1;
        ene_bm3_fly->clear_intangible();
        ene_bm3_fly->m_428 &= ~1;
        ene_bm3_fly->m_428 |= 2;
        ene_bm3_fly->actorFlags |= 0x01000000;
        vel->x = ene_bm3_fly->m_430.x * ene_bm3_fly->m_43c;
        vel->y = (0.0f);
        vel->z = ene_bm3_fly->m_430.z * ene_bm3_fly->m_43c;
        if (is_vec_xz_cross_negative(&ene_bm3_fly->m_430, &ene_bm3_fly->destination_direction) != 0) {
            ene_bm3_fly->m_3cc = 0x8000;
        } else {
            ene_bm3_fly->m_3cc = 0;
        }
        ene_bm3_fly->m_3c4 = 0;
        off->x = (0.0f);
        off->y = (0.0f);
        off->z = (0.0f);
        pos->x = (0.0f);
        pos->y = ene_bm3_fly->m_42c - ene_bm3_fly->position.y;
        pos->z = (0.0f);
        break;
    case 3:
        if (ene_bm3_fly->destination_distance > (4.5e+02f) || ene_bm3_fly->current_target == NULL) {
            ene_bm3_fly->transition_enemy_state(5);
        } else if (ene_bm3_fly->destination_distance < (1e+02f)) {
            ((TObjEneBm3Fly *)ene_bm3_fly)->choose_attack();
        }
        break;
    case 0:
        ene_bm3_fly->advance_animation();
        if (((TObjEneEpsilon *)ene_bm3_fly)->update_death_check() == 0 && ene_bm3_fly->acquire_target(2e+02f) == 0) {
            break;
        }
        ene_bm3_fly->update();
        ene_bm3_fly->update_velocity();
        VecCopy(pos, &ene_bm3_fly->body_center);
        subtract_vector(pos, off);
        if (ene_bm3_fly->m_3c4 == 0) {
            if ((0.0f) == ene_bm3_fly->m_430.x && (0.0f) == ene_bm3_fly->m_430.z) {
                ene_bm3_fly->m_430.x = sin_table_lookup(ene_bm3_fly->rotation_y);
                ene_bm3_fly->m_430.z = cos_table_lookup(ene_bm3_fly->rotation_y);
            }
            if (vec3_dot(&ene_bm3_fly->m_430, &ene_bm3_fly->destination_direction) < (0.99f)) {
                if (is_vec_xz_cross_negative(&ene_bm3_fly->m_430, &ene_bm3_fly->destination_direction) != 0) {
                    x = -ene_bm3_fly->m_430.z;
                    z = ene_bm3_fly->m_430.x;
                } else {
                    x = ene_bm3_fly->m_430.z;
                    z = -ene_bm3_fly->m_430.x;
                }
                vel->x = (0.18f) * x + vel->x;
                vel->y = (0.0f);
                vel->z = (0.18f) * z + vel->z;
                VecCopy(&ene_bm3_fly->m_430, vel);
                normalize_vector_safe(&ene_bm3_fly->m_430);
            } else {
                ene_bm3_fly->m_3c4 = 1;
                VecCopy(&ene_bm3_fly->m_430, &ene_bm3_fly->destination_direction);
            }
        } else {
            VecCopy(&ene_bm3_fly->m_430, &ene_bm3_fly->destination_direction);
            s = (5.0f) * sin_table_lookup(ene_bm3_fly->m_3cc);
            ene_bm3_fly->m_3cc += 0x600;
            off->x = ene_bm3_fly->destination_direction.z * s;
            off->y = (0.0f);
            off->z = -ene_bm3_fly->destination_direction.x * s;
        }
        if (ene_bm3_fly->m_43c > ((Bm3FlyMovementParameters *)ene_bm3_fly->movementParameters)->unknown_04) {
            ene_bm3_fly->m_43c *= (0.96f);
        } else {
            ene_bm3_fly->m_43c = ((Bm3FlyMovementParameters *)ene_bm3_fly->movementParameters)->unknown_04;
        }
        vel->x = ene_bm3_fly->m_430.x * ene_bm3_fly->m_43c;
        vel->y = (0.0f);
        vel->z = ene_bm3_fly->m_430.z * ene_bm3_fly->m_43c;
        pos->x += vel->x;
        pos->z += vel->z;
        VecCopy(&p, pos);
        vec3_add_to(&p, off);
        VecCopy(&d, &p);
        subtract_vector(&d, &ene_bm3_fly->position);
        d.y = (0.0f);
        len = normalize_vector_xz(&d);
        ((TObjEneBm3Fly *)ene_bm3_fly)->update_dd_flag(d.x, d.z, len);
        ene_bm3_fly->m_42c = ene_bm3_fly->approach_value(pos->y, ene_bm3_fly->destination.y);
        pos->y = ene_bm3_fly->m_42c;
        ene_bm3_fly->clamp_flight_height();
        ene_bm3_fly->rotation_y = (s32)(10430.38043493439 * atan2_float(ene_bm3_fly->m_430.x, ene_bm3_fly->m_430.z));
        ene_bm3_fly->check_collisions();
        pos->x -= ene_bm3_fly->position.x;
        pos->y -= ene_bm3_fly->m_42c;
        pos->z -= ene_bm3_fly->position.z;
        ene_bm3_fly->play_pitched_cue();
        break;
    case 5:
        ene_bm3_fly->m_43c = ((Bm3FlyMovementParameters *)ene_bm3_fly->movementParameters)->unknown_04;
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
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->actorFlags &= ~0x01000000;
        this->m_3c4 = 0;
        this->m_3c0 = 0;
        this->m_454 = 1;
        return;
    case 3:
        if (this->destination_distance > (4.5e+02f)) {
            this->transition_enemy_state(5);
            return;
        }
        switch (this->m_3c0) {
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
            ((TObjEneDD_ST *)(this))->enemy_clear_target();
        }
        switch (this->m_3c0) {
        case 0:
            if (this->current_target != NULL) {
                update_height_offset();
            }
            this->update_velocity();
            this->m_430.x = sin_table_lookup(this->rotation_y);
            this->m_430.z = cos_table_lookup(this->rotation_y);
            update_state_flag();
            this->m_42c = this->approach_value(this->m_42c, this->destination.y);
            this->clamp_flight_height();
            if (can_attack_target() != 0) {
                this->requested_action = 0;
                this->m_3c0 = 1;
            }
            break;
        case 1:
            this->m_3c4++;
            if ((s32) this->m_3c4 >= lbl_805D50EC->unknown_1C) {
                this->m_3c4 = 0;
                this->m_3c0 = 2;
                this->requested_action = 2;
            }
            this->update_collide_flag();
            break;
        case 2:
            if (is_passing_frame(9.0f) != 0) {
                this->m_440++;
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
                if (this->m_440 >= 4) {
                    this->m_440 = 0;
                    this->m_3c0 = 3;
                } else {
                    this->requested_action = 1;
                    this->m_3c0 = 0;
                }
            }
            this->update_collide_flag();
            break;
        }
        this->check_collisions();
        this->play_pitched_cue();
        return;
    case 5:
        this->m_454 = 0;
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
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->actorFlags |= 0x01000000;
        if (this->mode == 4) {
            this->m_3c0 = 2;
            this->m_3cc = 0;
        } else {
            this->m_3c0 = 0;
            this->m_3d0 = this->rotation_y + 0x8000;
            this->m_3d4 = 0;
            this->m_3cc = 0;
            this->m_3d8 = 0;
        }
        break;
    case 3:
        if (this->current_target == NULL) {
            this->transition_enemy_state(5);
        } else if (this->m_3cc > 0x8000 || this->m_3cc < -0x8000) {
            choose_attack();
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0 && this->acquire_target(2e+02f) == 0) {
            break;
        }
        switch (this->m_3c0) {
        case 0:
            circle_destination(this->m_3d0);
            this->update_velocity();
            vertical = (0.0f);
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_04;
            if (this->destination_distance < (14.0f)) {
                if (this->random_ratio() > (0.5f)) {
                    this->m_3d4 = (s32)(((-65536.0f) * speed) / (439.82288f));
                } else {
                    this->m_3d4 = (s32)(((65536.0f) * speed) / (439.82288f));
                }
                this->m_3c0 = 1;
            }
            break;
        case 1:
            this->m_3d0 += this->m_3d4 / 2;
            this->m_3cc += this->m_3d4 / 2;
            circle_destination(this->m_3d0);
            this->update_velocity();
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_04;
            vertical = (0.0f);
            if (this->destination_distance < speed) {
                this->m_3c0 = 2;
            }
            break;
        case 2:
            this->m_3d0 += this->m_3d4;
            this->m_3cc += this->m_3d4;
            circle_destination(this->m_3d0);
            this->update_velocity();
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_04;
            vertical = (1e+01f) * sin_table_lookup(this->m_3d8);
            this->m_3d8 += 0x380;
            break;
        }
        VecCopy(&this->m_430, &this->destination_direction);
        update_dd_flag(this->m_430.x, this->m_430.z, speed);
        this->m_42c = this->approach_value(this->m_42c, this->destination.y + vertical);
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
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *ene_bm3_fly, s32 msg) {
    Bm3FlyMovementParameters *params;
    switch (msg) {
    case 4:
        ene_bm3_fly->requested_action = 1;
        ene_bm3_fly->clear_intangible();
        ene_bm3_fly->m_428 &= ~1;
        ene_bm3_fly->m_428 |= 2;
        ene_bm3_fly->actorFlags |= 0x01000000;
        ene_bm3_fly->sub_800B1634();
        ene_bm3_fly->destination.x = (f32) (((3e+01f) * sin_table_lookup(ene_bm3_fly->m_448)) + ene_bm3_fly->m_41c.x);
        ene_bm3_fly->destination.y = (f32) ene_bm3_fly->m_444;
        ene_bm3_fly->destination.z = (f32) (((3e+01f) * cos_table_lookup(ene_bm3_fly->m_448)) + ene_bm3_fly->m_41c.z);
        params = (Bm3FlyMovementParameters *)ene_bm3_fly->movementParameters;
        ene_bm3_fly->m_3e0 = 2.0f + calc_scaled_value__15TObjBoss2TunnelFlf(params->unknown_08, (saddr)params, params->unknown_04, 3e+01f);
        ene_bm3_fly->update_velocity();
        break;
    case 3:
        if (ene_bm3_fly->update_linked_position(2e+02f) != 0) {
            ene_bm3_fly->transition_enemy_state(2);
        } else if (ene_bm3_fly->destination_distance < ene_bm3_fly->m_3e0) {
            ene_bm3_fly->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        ene_bm3_fly->advance_animation();
        ene_bm3_fly->update_velocity();
        ene_bm3_fly->m_42c = ene_bm3_fly->approach_value(ene_bm3_fly->m_42c, ene_bm3_fly->destination.y);
        ene_bm3_fly->update_state_flag();
        ene_bm3_fly->update_body_colliders();
        ene_bm3_fly->clamp_flight_height();
        ene_bm3_fly->transform_part_positions();
        ene_bm3_fly->play_pitched_cue();
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
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->set_field_378(this->mode);
        ((TBoss8Dragon *)this)->noop();
        play_sound_effect(this->remap_sound_for_area(0x4003E425), &this->position, 0, 0);
        this->m_3c0 = 0;
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
        t = this->m_3c0;
        this->m_3c0 = t + 1;
        this->m_430.x = this->x_speed;
        this->m_430.z = this->m_310;
        v = normalize_vector_xz(&this->m_430);
        update_dd_flag(this->m_430.x, this->m_430.z, v);
        this->clamp_flight_height();
        this->x_speed *= (0.5f);
        this->m_310 *= (0.5f);
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        break;
    }
}
#pragma pop
void action__13TObjEneBm3FlyFPvi(TObjEneBm3Fly *child, s32 msg) {
    TObjEneBm3FlyNest *nest;

    switch (msg) {
    case 4:
        child->clear_intangible();
        child->m_428 |= 1;
        child->m_428 &= ~2;
        child->set_entry = NULL;
        child->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(child->owner_id);
        if (nest != NULL) {
            nest->remove_child((u8 *)child);
        }
        TBoss8Dragon__sub_800BB7DC(child);
        TBoss8Dragon__sub_800BB7D8(child, 0xF1, 1.0f);
        play_sound_effect(child->remap_sound_for_area(0x4003E425), &child->position, 0, 0);
        TBoss3Volopt::create_breakup_mdl((saddr)TObjEneBm3Fly__breakup_model, (saddr)&bm3_fly_breakup_params, child->texlist, (saddr)&child->body_center, child->rotation_y);
        child->m_3c0 = 0;
        return;
    case 3:
        if (child->m_3c0 >= 2) {
            child->transition_enemy_state(9);
        }
    case 5:
        return;
    case 0:
        child->m_3c0++;
        break;
    }
}

void TObjEneBm3Fly::state_death_fall(s32 msg) {
    TObjEneBm3FlyNest *nest;
    s32 temp_copy;
    switch (msg) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(this->owner_id);
        if (nest != NULL) {
            nest->remove_child((u8 *)this);
        }
        TBoss8Dragon__sub_800BB7DC(this);
        this->m_3c0 = 0;
        this->m_3c4 = 0;
        this->m_3e0 = 0.0f;
        this->m_430.x = (f32) this->x_speed;
        this->m_430.z = (f32) this->m_310;
        this->m_3e4 = normalize_vector_xz(&this->m_430);
        temp_copy = this->remap_sound_for_area(0x4003E425);
        play_sound_effect(temp_copy, &this->position, 0, 0);
        return;
    case 3:
        if ((this->m_42c - this->position.y) < (-2e+01f)) {
            this->transition_enemy_state(9);
        }
        break;
    case 0:
        advance_animation();
        switch (this->m_3c0) {
        case 0:
        case 1:
            update_dd_flag(this->m_430.x, this->m_430.z, this->m_3e4);
            this->m_3e0 = (f32) (this->m_3e0 - (0.1f));
            this->m_42c = (f32) (this->m_42c + this->m_3e0);
            if (this->m_42c < (1.2f) + this->position.y) {
                this->m_42c = (1.2f) + this->position.y;
                if ((this->m_3c0 == 0) && (this->get_flag_b4() == 0)) {
                    this->m_3c0 = 1;
                    this->m_3e0 = 0.5f;
                    this->m_3e4 *= (0.98f);
                } else {
                    this->m_3c0 = 2;
                    this->m_3e4 = 0.0f;
                    this->m_428 &= ~2;
                    spawn_landing_dead_spot((saddr)&this->position, 0xA);
                    ((TObjPlayer *)&this->position)->spawn_effect_at_ground(0x1E);
                }
            }
            this->clamp_flight_height();
            break;
        case 2:
            this->m_3c4++;
            this->m_42c = (f32) (this->m_42c - (0.1f));
            break;
        }
        this->m_3e4 *= (0.98f);
        break;
    case 1:
    case 5:
        break;
    }
}

void TObjEneBm3Fly::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        this->m_428 |= 1;
        this->m_428 &= ~2;
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
    if (this->m_428 & 1) {
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        kind = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, (15.0f));
    } else if (this->update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        kind = 1;
    } else {
        kind = 0;
    }
    if (kind != 0) {
        if (this->m_428 & 2) {
            Vec v = {0.8f, 1.0f, 0.8f};
            this->draw_ground_shadow(&v, 0);
        }
        this->update_secondary_light();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        translate_matrix(0, this->position.x, this->m_42c, this->position.z);
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
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjEneMoja::bindModel(int index) {
    model = (void *)lbl_805D50D8->models[index].model;
    texlist = (saddr)lbl_805D50D8->models[index].m_c;
}

f32 AttackParams::get_damage_radius() { return damage_radius; }
