#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
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
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/unk/TLobby.h"

#pragma defer_codegen on

extern BmlResource *lbl_805D50D8;
extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 set_global_param__8TObjFishFl(s32);
extern Vec lbl_8043B10C;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void update_dd_flag__13TObjEneBm3FlyFPv(TObjEneBm3Fly *fly, f32 x, f32 z, f32 speed);
s32 TBoss8Dragon__sub_800BB7DC(void *);
}

void restore_alpha_ref(void);
void set_alpha_ref_override(u8 scene);
void spawn_landing_dead_spot(s32 point, s32 delay);
extern "C" {
void *find_entity_by_id(u16 id);
s32 TBoss8Dragon__sub_800BB7D8(void *, s32, f32);
s32 post_translate_matrix(void *);
extern s32 bm3_fly_breakup_params[];
extern TUnk_8048FA00 *TObjEneBm3Fly__breakup_model;
s32 vec3_add_to(void *, void *);
f32 vec3_dot(void *, void *);
s32 subtract_vector(void *, void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly);
f32 calc_scaled_value__15TObjBoss2TunnelFlf(int, int, f32, f32);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1);
void choose_attack__13TObjEneBm3FlyFPv(TObjEneBm3Fly *s);
s32 noop__12TBoss8DragonFv(void *);
f32 atan2_float(f32, f32);
f32 update_scale__15TObjBoss2TunnelFv(void *);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
extern const f64 TObjEneBm3Fly__data_8043B118[];
extern const f32 lbl_805D9E80;
void TObjEneBm3Fly__sub_800B1214(TObjEneBm3Fly *arg0, s32 arg1);
s32 is_vec_xz_cross_negative(void *, void *);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void TObjEneBm3Fly__sub_800B0F70(TObjEneBm3Fly *arg0, s32 arg1);
s32 select_nearest_target__12TObjEneDD_STFf(void *, f32);
extern Bm3FlyParameters *lbl_805D50EC;
f32 fabs_float(f32);
extern AttackParams *TObjEneBm3Fly__attack_params;
s32 get_random_scaled__9TObjEneDDFv(void *);
s32 enemy_set_target_id(void *, u16);
s32 collect_enemy_target_candidates(void *, EnemyTargetCandidate *, f32);
u16 get_entity_id(void *);
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *arg0, s32 arg1);
u32 TObjEneEpsilon__sub_800B92F8(void *, s32, f32);
u32 move_with_wall_slide_commit__9TObjEneDDFfff(TObjEneDD *, f32, f32, f32);
void free_collision_body_parts(void *);
extern const Bm3FlyAnimationBinding bm3_fly_resource_binding_desc;
extern const char *TObjEneBm3Fly__name;
extern u8 *bm3_fly_boss_stat_handle;
extern u8 *lbl_805D50E8;
extern BmlResource *bm3_fly_nest_resources;
extern void *tl_04;

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

void TObjEneBm3Fly::load_resources() {
    TUnk_8048FA00 *model;
    bm3_fly_nest_resources = TObjEneBm3FlyNest__sub_800B4158();
    model = (TUnk_8048FA00 *)::operator new(0x10);
    if (model != NULL) {
        model = (TUnk_8048FA00 *)((TBreakUpMdl *)model)->init_from_model(bm3_fly_nest_resources->models[0].model);
    }
    TObjEneBm3Fly__breakup_model = model;
    bm3_fly_boss_stat_handle = (u8 *)TLobby::register_boss(0);
    TObjEneBm3Fly__attack_params = (AttackParams *)TLobby::dispatch_shared_handler_b(0);
    lbl_805D50E8 = (u8 *)TLobby::register_object(0);
    lbl_805D50EC = (Bm3FlyParameters *)TLobby::dispatch_shared_handler_a(0);
    {
        Bm3FlyAnimationBinding binding = bm3_fly_resource_binding_desc;
        binding.motions = bm3_fly_nest_resources->motions;
        TLobby::spawn_npc_enemy(7, bm3_fly_nest_resources->models[0].model, (NJS_TEXLIST *)bm3_fly_nest_resources->models[0].m_c, &binding, bm3_fly_collider_params[0].radius, 15.0f);
    }
}

void *TObjEneBm3Fly::create(void *arg1, void *arg2, void *arg3, void *arg4) {
    return new TObjEneBm3Fly((TObject *)tl_04, (TObjEneBm3FlyNest *)this, (s32)arg1, (s32)arg2, (const Vec *)arg3, (const Vec *)arg4);
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
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly::init_child_params() {
    init_position_vectors();
    this->model = (void *)bm3_fly_nest_resources->models[0].model;
    this->texlist = bm3_fly_nest_resources->models[0].m_c;
    this->init_model(bm3_fly_collider_params, 1);
    set_field_d8((s32)bm3_fly_action_table);
    set_field_dc((s32)bm3_fly_nest_resources->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    this->reset_hp(bm3_fly_boss_stat_handle, (u8 *)TObjEneBm3Fly__attack_params, lbl_805D50E8);
    check_state_flag_1();
    this->movementParameters = &bm3_fly_decision_row;
    this->initialize_enemy_state(3);
    this->m_37c = (5.0f);
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
    this->m_44c = (2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this) + (45.0f);
    this->m_450 = (2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this) + (15.0f);
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
}

#pragma pop
extern "C" {
TObjEneBm3Fly::~TObjEneBm3Fly() {
    if (particle_effect != NULL) {
        particle_effect->queue_destruction();
        particle_effect = NULL;
    }
    free_collision_body_parts(this);
}
}

void TObjEneBm3Fly::run_task() {
    f32 dz;
    f32 dx;
    f32 side;
    TObject *nest;
    TParticleCtrl *effect;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_105();
        return;
    }
    nest = (TObject *)find_entity_by_id(this->owner_id);
    if (nest == NULL || nest->all_parents_unqueued_for_destruction() == 0) {
        this->queue_destruction();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
        effect = this->particle_effect;
        if (effect == NULL) {
            this->particle_effect = create_particle_emitter(&this->m_2fc, 0xC7);
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
            this->particle_effect->position.x = ((Vec *)&this->m_2fc)->x + dx;
            this->particle_effect->position.y = -1.5f + ((Vec *)&this->m_2fc)->y;
            this->particle_effect->position.z = ((Vec *)&this->m_2fc)->z + dz;
        }
    } else {
        effect = this->particle_effect;
        if (effect != NULL) {
            effect->enable();
        }
    }
    this->store_position();
    this->submit_default_cursor_candidate();
    this->vfunc_100();
}
extern "C" {
void TObjEneBm3Fly::dispatch_action(u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        TObjEneBm3Fly__sub_800B1214(this, msg);
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

void TObjEneBm3Fly::vfunc_28() {  }

void TObjEneBm3Fly::vfunc_63() {
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

void TObjEneBm3Fly::vfunc_62() { if (this->mode != 6) { this->transition_enemy_state(6); } }

void TObjEneBm3Fly::vfunc_61() {  }

void TObjEneBm3Fly::update() {
    this->enemy_copy_target_destination();
    this->m_394.y = (f32) (this->position.y + this->m_44c);
}

void TObjEneBm3Fly::update_height_offset() {
    this->enemy_copy_target_destination();
    this->m_394.y = (f32) (this->position.y + this->m_450);
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly::circle_destination(s32 arg1) {
    this->enemy_copy_target_destination();
    this->m_394.x = (f32) (((7e+01f) * sin_table_lookup(arg1)) + this->m_394.x);
    this->m_394.y = (f32) ((this->position.y) + this->m_44c);
    this->m_394.z = (f32) (((7e+01f) * cos_table_lookup(arg1)) + this->m_394.z);
}
}

#pragma pop
extern "C" {
void TObjEneBm3Fly::update_collide_flag() {
    if (this->vfunc_102() != 0U) {
        this->m_428 |= 2;
        return;
    }
    this->m_428 &= ~2;
}

void update_dd_flag__13TObjEneBm3FlyFPv(TObjEneBm3Fly *fly, f32 x, f32 z, f32 speed) {
    if (move_with_wall_slide_commit__9TObjEneDDFfff(fly, x, z, speed) != 0U) {
        fly->m_428 |= 2;
        return;
    }
    fly->m_428 &= ~2;
}

void TObjEneBm3Fly::update_state_flag() {

    if (TObjEneEpsilon__sub_800B92F8(this, ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_08, lbl_805D50EC->unknown_00) != 0U) {
        this->m_428 |= 2;
        return;
    }
    this->m_428 &= ~2;
}

void TObjEneBm3Fly::store_position() {
    this->m_2fc = (f32) this->position.x;
    this->m_304 = (f32) this->position.z;
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
}
}

#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjEneBm3Fly::clamp_flight_height() {
    if ((this->m_42c - this->position.y) < (1.2f)) {
        this->m_42c = (1.2f) + this->position.y;
    }
    this->m_300 = this->m_42c;
}
}

#pragma pop
extern "C" {
void TObjEneBm3Fly::vfunc_89() { TObjEneDD::vfunc_89(); this->clamp_flight_height(); }

void TObjEneBm3Fly::vfunc_88() {
    f32 temp_f31;
    temp_f31 = this->m_42c - this->position.y;
    if (temp_f31 >= (3e+01f)) {
        this->vfunc_97();
    } else {
        this->vfunc_98();
    }
    this->bodies->offset.y = temp_f31;
}

f32 TObjEneBm3Fly::approach_value(f32 farg0, f32 farg1) {
    f32 temp_f31;
    f32 var_f1;
    f32 cap;

    temp_f31 = farg1 - farg0;
    if (fabs_float(temp_f31) < (0.2f)) {
        return farg1;
    }
    var_f1 = (0.1f);
    var_f1 = temp_f31 * var_f1;
    if (var_f1 > (1.5f)) {
        var_f1 = (1.5f);
    } else if (var_f1 < (-1.5f)) {
        var_f1 = (-1.5f);
    }
    return farg0 + var_f1;
}

s32 TObjEneBm3Fly::can_attack_target() {
    f32 temp_f31;
    if ((this->m_3ac < ((5.0f) + TObjEneBm3Fly__attack_params->get_attack_range())) && (fabs_float((f32) (this->m_42c - this->m_394.y)) < (1.0f))) {
        temp_f31 = vec3_dot(&this->m_430, &this->m_3a0);
        if (temp_f31 >= cos_table_lookup(((AttackParams *)(this->m_318))->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
}

void choose_attack__13TObjEneBm3FlyFPv(TObjEneBm3Fly *s) {
    EnemyTargetCandidate players[4];
    TObjEneBm3FlyNest *nest;
    s32 count;
    u16 id;
    s32 i;
    nest = (TObjEneBm3FlyNest *)find_entity_by_id(s->owner_id);
    if (nest == NULL) {
        s->transition_enemy_state(4);
        s->m_454 = 0;
    }
    if (nest->has_free_attack_slot(s->m_38c) != 0) {
        s->transition_enemy_state(3);
        return;
    }
    count = collect_enemy_target_candidates(s, players, (1e+04f));
    for (i = 0; i < count; i++) {
        id = players[i].id;
        if (id != s->m_38c && nest->has_free_attack_slot(id) != 0) {
            enemy_set_target_id(s, id);
            s->transition_enemy_state(3);
            return;
        }
    }
    s->transition_enemy_state(4);
    s->m_454 = 0;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly::sub_800B1634() {
    this->m_444 = (f32) (((2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this)) + ((45.0f) + this->m_41c.y));
    this->m_448 = get_random_scaled__9TObjEneDDFv(this);
}
}

#pragma pop
extern "C" {
u16 TObjEneBm3Fly::get_active_id() {
    if (this->m_454 != 0) {
        return this->m_38c;
    }
    return 0xFFFFU;
}

void TObjEneBm3Fly::play_pitched_cue() {
    play_persistent_sound(this->remap_sound_for_area(0x40039E22), (s32)this, (u32)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly) {
    play_persistent_sound(fly->remap_sound_for_area(0x4003AB23), (s32)fly, (u32)&fly->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

s32 TObjEneBm3Fly::vfunc_104(f32 farg0) {
    if (this->vfunc_99() != 0) {
        this->select_and_apply_target(farg0);
        return;
    }
    select_nearest_target__12TObjEneDD_STFf(this, farg0);
}
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void TObjEneBm3Fly__sub_800B1214(TObjEneBm3Fly *arg0, s32 arg1) {
    Vec *p = &arg0->m_3e8;
    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        arg0->vfunc_95();
        arg0->m_428 &= ~1;
        arg0->m_428 |= 2;
        arg0->actorFlags |= 0x01000000;
        arg0->sub_800B1634();
        arg0->m_3c0 = 0;
        arg0->m_3c4 = 0;
        p->x = (3e+01f) * sin_table_lookup(arg0->m_448) + arg0->m_41c.x;
        p->y = arg0->m_444;
        p->z = (3e+01f) * cos_table_lookup(arg0->m_448) + arg0->m_41c.z;
        arg0->rotation_y = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(arg0->m_40c.x, arg0->m_40c.z));
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        break;
    case 3:
        if (arg0->m_3c4 == 2) {
            arg0->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        arg0->advance_animation();
        switch (arg0->m_3c4) {
        case 0:
            arg0->position.x += arg0->m_40c.x;
            arg0->m_42c += arg0->m_40c.y;
            arg0->position.z += arg0->m_40c.z;
            arg0->m_40c.x *= (0.9f);
            arg0->m_40c.y += lbl_805D9E80;
            arg0->m_40c.z *= (0.9f);
            arg0->m_3c0++;
            if (arg0->m_3c0 > 40) {
                arg0->m_3c4 = 1;
                arg0->m_3c0 = 0;
                arg0->m_43c = (0.0f);
            }
            break;
        case 1:
            VecCopy(&arg0->m_430, p);
            arg0->m_430.x -= arg0->position.x;
            arg0->m_430.y -= arg0->m_42c;
            arg0->m_430.z -= arg0->position.z;
            arg0->m_3e0 = update_scale__15TObjBoss2TunnelFv(&arg0->m_430);
            if (arg0->m_43c < (2.0f)) {
                arg0->m_43c += (0.1f);
            }
            if (arg0->m_3e0 < (2.0f)) {
                VecCopy(&arg0->position, p);
                arg0->m_3c4 = 2;
            } else {
                arg0->position.x = arg0->m_430.x * arg0->m_43c + arg0->position.x;
                arg0->m_42c = arg0->m_430.y * arg0->m_43c + arg0->m_42c;
                arg0->position.z = arg0->m_430.z * arg0->m_43c + arg0->position.z;
            }
            arg0->rotation_y = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(arg0->m_430.x, arg0->m_430.z));
            break;
        }
        arg0->update_collide_flag();
        arg0->prev_position.x = arg0->m_2fc;
        arg0->prev_position.z = arg0->m_304;
        arg0->clamp_flight_height();
        arg0->vfunc_88();
        break;
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly__sub_800B0F70(TObjEneBm3Fly *arg0, s32 arg1) {
    Vec d;
    f32 radius;
    s32 a;
    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        arg0->vfunc_95();
        arg0->m_428 &= ~1;
        arg0->m_428 |= 2;
        arg0->actorFlags |= 0x01000000;
        arg0->m_3cc = 0;
        arg0->m_3d0 = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0x800;
        arg0->m_3d4 = arg0->m_448;
        arg0->m_3d8 = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0xA00;
        d.x = arg0->position.x - arg0->m_41c.x;
        d.y = (0.0f);
        d.z = arg0->position.z - arg0->m_41c.z;
        if (is_vec_xz_cross_negative(&d, &arg0->m_430) != 0) {
            arg0->m_3d8 *= -1;
        }
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        arg0->m_3c8 = -1;
        break;
    case 3:
        if (arg0->update_linked_position(2e+02f) != 0) {
            arg0->transition_enemy_state(2);
        }
        break;
    case 0:
        arg0->advance_animation();
        arg0->m_3c4++;
        if (arg0->m_3c4 > 300) {
            arg0->m_3c4 = 0;
            arg0->m_3d8 = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0xA00;
        }
        arg0->m_3cc += arg0->m_3d0;
        radius = (3e+01f) * cos_table_lookup(arg0->m_3cc / 2);
        arg0->m_3d4 += arg0->m_3d8;
        a = arg0->m_3d4;
        arg0->position.x = radius * sin_table_lookup(a) + arg0->m_41c.x;
        arg0->m_42c = (1e+01f) * sin_table_lookup(arg0->m_3d4) + arg0->m_444;
        arg0->position.z = radius * cos_table_lookup(a) + arg0->m_41c.z;
        arg0->rotation_y = a - 0x4000;
        arg0->update_collide_flag();
        arg0->prev_position.x = arg0->m_2fc;
        arg0->prev_position.z = arg0->m_304;
        arg0->vfunc_88();
        TObjEneBm3Fly__play_orbit_flight_sound(arg0);
        break;
    case 5:
        arg0->m_430.x = arg0->position.x - arg0->prev_position.x;
        arg0->m_430.y = (0.0f);
        arg0->m_430.z = arg0->position.z - arg0->prev_position.z;
        arg0->m_43c = update_scale__15TObjBoss2TunnelFv(&arg0->m_430);
        break;
    }
}
}

#pragma pop
#pragma pop
#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *arg0, s32 arg1) {
    Vec *pos;
    Vec *off;
    Vec *vel;
    Vec p;
    Vec d;
    f32 z;
    f32 x;
    f32 s;
    f32 len;

    vel = &arg0->m_3e8;
    pos = &arg0->m_3f4;
    off = &arg0->m_400;

    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        arg0->vfunc_96();
        arg0->m_428 &= ~1;
        arg0->m_428 |= 2;
        arg0->actorFlags |= 0x01000000;
        vel->x = arg0->m_430.x * arg0->m_43c;
        vel->y = (0.0f);
        vel->z = arg0->m_430.z * arg0->m_43c;
        if (is_vec_xz_cross_negative(&arg0->m_430, &arg0->m_3a0) != 0) {
            arg0->m_3cc = 0x8000;
        } else {
            arg0->m_3cc = 0;
        }
        arg0->m_3c4 = 0;
        off->x = (0.0f);
        off->y = (0.0f);
        off->z = (0.0f);
        pos->x = (0.0f);
        pos->y = arg0->m_42c - arg0->position.y;
        pos->z = (0.0f);
        break;
    case 3:
        if (arg0->m_3ac > (4.5e+02f) || arg0->m_390 == NULL) {
            arg0->transition_enemy_state(5);
        } else if (arg0->m_3ac < (1e+02f)) {
            choose_attack__13TObjEneBm3FlyFPv(arg0);
        }
        break;
    case 0:
        arg0->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0 && arg0->vfunc_104(2e+02f) == 0) {
            break;
        }
        arg0->update();
        arg0->update_velocity();
        VecCopy(pos, (const Vec *)&arg0->m_2fc);
        subtract_vector(pos, off);
        if (arg0->m_3c4 == 0) {
            if ((0.0f) == arg0->m_430.x && (0.0f) == arg0->m_430.z) {
                arg0->m_430.x = sin_table_lookup(arg0->rotation_y);
                arg0->m_430.z = cos_table_lookup(arg0->rotation_y);
            }
            if (vec3_dot(&arg0->m_430, &arg0->m_3a0) < (0.99f)) {
                if (is_vec_xz_cross_negative(&arg0->m_430, &arg0->m_3a0) != 0) {
                    x = -arg0->m_430.z;
                    z = arg0->m_430.x;
                } else {
                    x = arg0->m_430.z;
                    z = -arg0->m_430.x;
                }
                vel->x = (0.18f) * x + vel->x;
                vel->y = (0.0f);
                vel->z = (0.18f) * z + vel->z;
                VecCopy(&arg0->m_430, vel);
                update_scale__15TObjBoss2TunnelFv(&arg0->m_430);
            } else {
                arg0->m_3c4 = 1;
                VecCopy(&arg0->m_430, &arg0->m_3a0);
            }
        } else {
            VecCopy(&arg0->m_430, &arg0->m_3a0);
            s = (5.0f) * sin_table_lookup(arg0->m_3cc);
            arg0->m_3cc += 0x600;
            off->x = arg0->m_3a0.z * s;
            off->y = (0.0f);
            off->z = -arg0->m_3a0.x * s;
        }
        if (arg0->m_43c > ((Bm3FlyMovementParameters *)arg0->movementParameters)->unknown_04) {
            arg0->m_43c *= (0.96f);
        } else {
            arg0->m_43c = ((Bm3FlyMovementParameters *)arg0->movementParameters)->unknown_04;
        }
        vel->x = arg0->m_430.x * arg0->m_43c;
        vel->y = (0.0f);
        vel->z = arg0->m_430.z * arg0->m_43c;
        pos->x += vel->x;
        pos->z += vel->z;
        VecCopy(&p, pos);
        vec3_add_to(&p, off);
        VecCopy(&d, &p);
        subtract_vector(&d, &arg0->position);
        d.y = (0.0f);
        len = normalize_vector_xz(&d);
        update_dd_flag__13TObjEneBm3FlyFPv(arg0, d.x, d.z, len);
        arg0->m_42c = arg0->approach_value(pos->y, arg0->m_394.y);
        pos->y = arg0->m_42c;
        arg0->clamp_flight_height();
        arg0->rotation_y = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(arg0->m_430.x, arg0->m_430.z));
        arg0->vfunc_89();
        pos->x -= arg0->position.x;
        pos->y -= arg0->m_42c;
        pos->z -= arg0->position.z;
        arg0->play_pitched_cue();
        break;
    case 5:
        arg0->m_43c = ((Bm3FlyMovementParameters *)arg0->movementParameters)->unknown_04;
        break;
    }
}
}

#pragma pop
extern "C" {
void TObjEneBm3Fly::execute_action(s32 arg1) {
    TObjChara *target;

    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->vfunc_96();
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->actorFlags &= ~0x01000000;
        this->m_3c4 = 0;
        this->m_3c0 = 0;
        this->m_454 = 1;
        return;
    case 3:
        if (this->m_3ac > (4.5e+02f)) {
            this->transition_enemy_state(5);
            return;
        }
        switch (this->m_3c0) {
        case 0:
        case 1:
            if (this->m_390 == NULL) {
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
            enemy_clear_target__12TObjEneDD_STFUs(this);
        }
        switch (this->m_3c0) {
        case 0:
            if (this->m_390 != NULL) {
                update_height_offset();
            }
            this->update_velocity();
            this->m_430.x = sin_table_lookup(this->rotation_y);
            this->m_430.z = cos_table_lookup(this->rotation_y);
            update_state_flag();
            this->m_42c = this->approach_value(this->m_42c, this->m_394.y);
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
                target = this->m_390;
                if ((target != NULL) && (target->select_melee_contact_body(this, (1.0f)) != 0)) {
                    this->m_390->receive_physical_attack(this, (1.0f));
                    this->m_390->apply_knockback_from_attacker((u8 *)this, (3.0f));
                    if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() < (0.05f))) {
                        TObjEneDD::inflict_poison((s32)this, (u8 *)this->m_390);
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
        this->vfunc_89();
        this->play_pitched_cue();
        return;
    case 5:
        this->m_454 = 0;
        break;
    }
}

void TObjEneBm3Fly::state_circle_target(s32 arg1) {
    f32 speed;
    f32 vertical;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->vfunc_96();
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
        if (this->m_390 == NULL) {
            this->transition_enemy_state(5);
        } else if (this->m_3cc > 0x8000 || this->m_3cc < -0x8000) {
            choose_attack__13TObjEneBm3FlyFPv(this);
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0 && this->vfunc_104(2e+02f) == 0) {
            break;
        }
        switch (this->m_3c0) {
        case 0:
            circle_destination(this->m_3d0);
            this->update_velocity();
            vertical = (0.0f);
            speed = ((Bm3FlyMovementParameters *)this->movementParameters)->unknown_04;
            if (this->m_3ac < (14.0f)) {
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
            if (this->m_3ac < speed) {
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
        VecCopy(&this->m_430, &this->m_3a0);
        update_dd_flag__13TObjEneBm3FlyFPv(this, this->m_430.x, this->m_430.z, speed);
        this->m_42c = this->approach_value(this->m_42c, this->m_394.y + vertical);
        this->clamp_flight_height();
        this->rotation_y = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(
            this->m_390->position.x - this->position.x, this->m_390->position.z - this->position.z));
        this->vfunc_89();
        this->play_pitched_cue();
        break;
    case 1:
        break;
    case 5:
        break;
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1) {
    Bm3FlyMovementParameters *params;
    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        arg0->vfunc_96();
        arg0->m_428 &= ~1;
        arg0->m_428 |= 2;
        arg0->actorFlags |= 0x01000000;
        arg0->sub_800B1634();
        arg0->m_394.x = (f32) (((3e+01f) * sin_table_lookup((int) (arg0->m_448))) + arg0->m_41c.x);
        arg0->m_394.y = (f32) arg0->m_444;
        arg0->m_394.z = (f32) (((3e+01f) * cos_table_lookup((int) (arg0->m_448))) + arg0->m_41c.z);
        params = (Bm3FlyMovementParameters *)arg0->movementParameters;
        arg0->m_3e0 = 2.0f + calc_scaled_value__15TObjBoss2TunnelFlf(params->unknown_08, (int)params, params->unknown_04, 3e+01f);
        arg0->update_velocity();
        break;
    case 3:
        if (arg0->update_linked_position(2e+02f) != 0) {
            arg0->transition_enemy_state(2);
        } else if (arg0->m_3ac < arg0->m_3e0) {
            arg0->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        arg0->advance_animation();
        arg0->update_velocity();
        arg0->m_42c = arg0->approach_value(arg0->m_42c, arg0->m_394.y);
        arg0->update_state_flag();
        arg0->vfunc_88();
        arg0->clamp_flight_height();
        arg0->transform_part_positions();
        arg0->play_pitched_cue();
        break;
    }
}
}

#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjEneBm3Fly::update_recoil_state(s32 arg1) {
    s32 t;
    f32 v;
    switch (arg1) {
    case 4:
        this->requested_action = 3;
        this->vfunc_96();
        this->m_428 &= ~1;
        this->m_428 |= 2;
        this->set_field_378(this->mode);
        noop__12TBoss8DragonFv(this);
        play_sound_effect(this->remap_sound_for_area((s32)(0x4003E425)), &this->position, 0, 0);
        this->m_3c0 = 0;
        break;
    case 3:
        if (this->motion_flags & 0x10) {
            if (this->vfunc_99() != 0) {
                this->vfunc_104(2e+02f);
            }
            if (this->m_378 == 3) {
                choose_attack__13TObjEneBm3FlyFPv(this);
            } else {
                this->transition_enemy_state(this->m_378);
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
        update_dd_flag__13TObjEneBm3FlyFPv(this, this->m_430.x, this->m_430.z, v);
        this->clamp_flight_height();
        this->x_speed *= (0.5f);
        this->m_310 *= (0.5f);
        this->vfunc_89();
        break;
    case 5:
        this->clear_attack_receipts();
        break;
    }
}
}

#pragma pop
extern "C" {
void action__13TObjEneBm3FlyFPvi(TObjEneBm3Fly *arg0, s32 arg1) {
    TObjEneBm3FlyNest *nest;

    switch (arg1) {
    case 4:
        arg0->vfunc_96();
        arg0->m_428 |= 1;
        arg0->m_428 &= ~2;
        arg0->set_entry = NULL;
        arg0->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(arg0->owner_id);
        if (nest != NULL) {
            nest->remove_child((u8 *)arg0);
        }
        TBoss8Dragon__sub_800BB7DC(arg0);
        TBoss8Dragon__sub_800BB7D8(arg0, 0xF1, (1.0f));
        play_sound_effect(arg0->remap_sound_for_area((s32)(0x4003E425)), &arg0->position, 0, 0);
        TBoss3Volopt::create_breakup_mdl((s32)TObjEneBm3Fly__breakup_model, (s32)bm3_fly_breakup_params, (s32)(arg0->texlist), (s32)&arg0->m_2fc, (s32)(arg0->rotation_y));
        arg0->m_3c0 = 0;
        return;
    case 3:
        if (arg0->m_3c0 >= 2) {
            arg0->transition_enemy_state(9);
        }
    case 5:
        return;
    case 0:
        arg0->m_3c0++;
        break;
    }
}

void TObjEneBm3Fly::state_death_fall(s32 arg1) {
    TObjEneBm3FlyNest *nest;
    s32 temp_copy;
    switch (arg1) {
    case 4:
        this->requested_action = 4;
        this->vfunc_96();
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
        temp_copy = this->remap_sound_for_area((s32)(0x4003E425));
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
            update_dd_flag__13TObjEneBm3FlyFPv(this, this->m_430.x, this->m_430.z, this->m_3e4);
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
                    spawn_landing_dead_spot((s32)&this->position, 0xA);
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

void TObjEneBm3Fly::vfunc_105() {  }

void TObjEneBm3Fly::render() {
    s32 kind;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_106();
        return;
    }
    if (this->m_428 & 1) {
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        kind = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, (15.0f));
    } else if (this->update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        kind = 1;
    } else {
        kind = 0;
    }
    if (kind != 0) {
        if (this->m_428 & 2) {
            Vec v = lbl_8043B10C;
            this->draw_ground_shadow(&v, 0);
        }
        this->update_secondary_light();
        set_global_param__8TObjFishFl(this->texlist);
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

void TObjEneBm3Fly::vfunc_106() {
    if (update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        draw_ground_shadow(0, 0);
        set_global_param__8TObjFishFl(texlist);
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
    texlist = lbl_805D50D8->models[index].m_c;
}

f32 AttackParams::get_damage_radius() { return damage_radius; }
}
