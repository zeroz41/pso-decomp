#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/enemy/moja/TObjEneMoja.h"
struct MojaResourceEntry {u8 unknown[8];void* model;void* textures;};

struct MojaResources {u8 unknown[0x42C];MojaResourceEntry* models;};

extern MojaResources* lbl_805D50D8;
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
void TObjEneBm3Fly__vt103(void);
void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0);
s32 TBoss8Dragon__sub_800BB7D8(void *, s32, f32);
s32 post_translate_matrix(void *);
s32 queue_destruction__7TObjectFv();

f32 AttackParams::get_damage_radius() { return damage_radius; }

void TObjEneMoja::bindModel(int index) {
    model=lbl_805D50D8->models[index].model;
    (*(void * *)&this->texlist)=lbl_805D50D8->models[index].textures;
}

void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0) {
    if (arg0->update_object_view_visibility((4e+02f), (15.0f)) != 0) {
        ((TObjEneDD *)(arg0))->draw_ground_shadow(0, 0);
        set_global_param__8TObjFishFl(arg0->texlist);
        push_matrix();
        post_translate_matrix(&arg0->position);
        rotate_matrix_y(0, arg0->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(arg0->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

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
            ((TObjEneDD *)this)->draw_ground_shadow(&v, 0);
        }
        ((TObjEneDD *)this)->update_secondary_light();
        set_global_param__8TObjFishFl(this->texlist);
        push_matrix();
        translate_matrix(0, this->position.x, this->m_42c, this->position.z);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_alpha_ref_override(0x8F);
        if (kind == 1) {
            ((TObjMotion *)this)->draw();
        } else {
            ((TObjEnemy *)this)->draw_motion_model();
        }
        restore_alpha_ref();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        ((TObjEneDD *)this)->update_primary_light();
    }
}

void TObjEneBm3Fly__vt103(void) {  }
void TObjEneBm3Fly::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        this->m_428 = (s32) (this->m_428 | 1);
        this->m_428 = (s32) (this->m_428 & 0xFFFFFFFD);
        return;
    case 3:
        queue_destruction__7TObjectFv();
    case 5:
    case 0:
        return;
    }
}

extern s32 bm3_fly_breakup_params[];
extern TUnk_8048FA00 *TObjEneBm3Fly__breakup_model;

void TObjEneBm3Fly::state_death_fall(s32 arg1) {
    f32 temp_f0;
    s32 temp_r0;
    TObjEneBm3FlyNest *nest;
    s32 temp_copy;
    switch (arg1) {
    case 4:
        this->requested_action = 4;
        this->vfunc_96();
        this->m_428 = (s32) (this->m_428 & 0xFFFFFFFE);
        this->m_428 = (s32) (this->m_428 | 2);
        this->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(this->owner_id);
        if (nest != NULL) {
            nest->remove_child((u8 *)this);
        }
        TBoss8Dragon__sub_800BB7DC(this);
        this->m_3c0 = 0;
        this->m_3c4 = 0;
        this->m_3e0 = (f32) (0.0f);
        this->m_430.x = (f32) this->x_speed;
        this->m_430.z = (f32) this->m_310;
        this->m_3e4 = normalize_vector_xz(&this->m_430);
        temp_copy = ((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x4003E425));
        play_sound_effect(temp_copy, (u8 *)&this->position, 0, 0);
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
                if (((s32) this->m_3c0 == 0) && (((TObjEneDD *)this)->get_flag_b4() == 0)) {
                    this->m_3c0 = 1;
                    this->m_3e0 = (f32) (0.5f);
                    this->m_3e4 *= (0.98f);
                } else {
                    this->m_3c0 = 2;
                    this->m_3e4 = (f32) (0.0f);
                    this->m_428 = (s32) (this->m_428 & 0xFFFFFFFD);
                    spawn_landing_dead_spot((s32)&this->position, 0xA);
                    ((TObjPlayer *)&this->position)->spawn_effect_at_ground(0x1E);
                }
            }
            this->clamp_flight_height();
            break;
        case 2:
            this->m_3c4 = (s32) (this->m_3c4 + 1);
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

void action__13TObjEneBm3FlyFPvi(TObjEneBm3Fly *arg0, s32 arg1) {
    s32 temp_r4;
    TObjEneBm3FlyNest *nest;

    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->vfunc_96();
        arg0->m_428 = (s32) (arg0->m_428 | 1);
        temp_r4 = arg0->m_428 & 0xFFFFFFFD;
        arg0->m_428 = temp_r4;
        arg0->set_entry = 0;
        arg0->refresh_and_send_entity_flags();
        nest = (TObjEneBm3FlyNest *)find_entity_by_id(arg0->owner_id);
        if (nest != NULL) {
            nest->remove_child((u8 *)arg0);
        }
        TBoss8Dragon__sub_800BB7DC(arg0);
        TBoss8Dragon__sub_800BB7D8(arg0, 0xF1, (1.0f));
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003E425)), &arg0->position, 0, 0);
        TBoss3Volopt::create_breakup_mdl((s32)TObjEneBm3Fly__breakup_model, (s32)bm3_fly_breakup_params, (s32)(arg0->texlist), (s32)&arg0->m_2fc, (s32)(arg0->rotation_y));
        arg0->m_3c0 = 0;
        return;
    case 3:
        if ((s32) arg0->m_3c0 >= 2) {
            arg0->transition_enemy_state(9);
        }
    case 5:
        return;
    case 0:
        arg0->m_3c0 = (s32) (arg0->m_3c0 + 1);
        break;
    }
}
}

extern "C" {
s32 vec3_add_to(void *, void *);
f32 vec3_dot(void *, void *);
s32 subtract_vector(void *, void *);
}

extern "C" {
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

void vfunc_104__13TObjEneBm3FlyFf(void *arg0, f32 farg0);
s32 select_nearest_target__12TObjEneDD_STFf(void *, f32);

extern u8 *lbl_805D50EC;

#pragma push
#pragma opt_common_subs off
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
        play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x4003E425)), &this->position, 0, 0);
        this->m_3c0 = 0;
        break;
    case 3:
        if (this->motion_flags & 0x10) {
            if (this->vfunc_99() != 0) {
                this->vfunc_104((2e+02f));
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
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1) {
    u8 *temp_r4;
    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        arg0->vfunc_96();
        arg0->m_428 = (s32) (arg0->m_428 & 0xFFFFFFFE);
        arg0->m_428 = (s32) (arg0->m_428 | 2);
        arg0->actorFlags = (s32) (arg0->actorFlags | 0x01000000);
        arg0->sub_800B1634();
        arg0->m_394.x = (f32) (((3e+01f) * sin_table_lookup((int) (arg0->m_448))) + arg0->m_41c.x);
        arg0->m_394.y = (f32) arg0->m_444;
        arg0->m_394.z = (f32) (((3e+01f) * cos_table_lookup((int) (arg0->m_448))) + arg0->m_41c.z);
        temp_r4 = (u8 *)arg0->movementParameters;
        arg0->m_3e0 = (f32) ((2.0f) + calc_scaled_value__15TObjBoss2TunnelFlf((int) (*(s32 *)((s8 *)temp_r4 + 8)), (int)temp_r4, (f32) (*(f32 *)((s8 *)temp_r4 + 4)), (f32) ((3e+01f))));
        ((TObjEneDD *)arg0)->update_velocity();
        break;
    case 3:
        if (arg0->update_linked_position((f32) ((2e+02f))) != 0) {
            arg0->transition_enemy_state(2);
        } else if (arg0->m_3ac < arg0->m_3e0) {
            arg0->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        arg0->advance_animation();
        ((TObjEneDD *)arg0)->update_velocity();
        arg0->m_42c = arg0->approach_value((f32) (arg0->m_42c), arg0->m_394.y);
        arg0->update_state_flag();
        arg0->vfunc_88();
        arg0->clamp_flight_height();
        ((TObjEneDD *)arg0)->transform_part_positions();
        arg0->play_pitched_cue();
        break;
    }
}
#pragma pop

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
        if (((TObjEneEpsilon *)this)->update_death_check() == 0 && this->vfunc_104((2e+02f)) == 0) {
            break;
        }
        switch (this->m_3c0) {
        case 0:
            circle_destination(this->m_3d0);
            ((TObjEneDD *)this)->update_velocity();
            vertical = (0.0f);
            speed = *(f32 *)((s8 *)(this->movementParameters) + 4);
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
            ((TObjEneDD *)this)->update_velocity();
            speed = *(f32 *)((s8 *)(this->movementParameters) + 4);
            vertical = (0.0f);
            if (this->m_3ac < speed) {
                this->m_3c0 = 2;
            }
            break;
        case 2:
            this->m_3d0 += this->m_3d4;
            this->m_3cc += this->m_3d4;
            circle_destination(this->m_3d0);
            ((TObjEneDD *)this)->update_velocity();
            speed = *(f32 *)((s8 *)(this->movementParameters) + 4);
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

void TObjEneBm3Fly::execute_action(s32 arg1) {
    TObjChara *target;

    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->vfunc_96();
        this->m_428 = (s32) (this->m_428 & 0xFFFFFFFE);
        this->m_428 = (s32) (this->m_428 | 2);
        this->actorFlags = (s32) (this->actorFlags & 0xFEFFFFFF);
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
        if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(((u8 *)this));
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
            this->m_42c = this->approach_value((f32) (this->m_42c), this->m_394.y);
            this->clamp_flight_height();
            if (can_attack_target() != 0) {
                this->requested_action = 0;
                this->m_3c0 = 1;
            }
            break;
        case 1:
            this->m_3c4 = (s32) (this->m_3c4 + 1);
            if ((s32) this->m_3c4 >= (s32) *(s32 *)((s8 *)lbl_805D50EC + 0x1C)) {
                this->m_3c4 = 0;
                this->m_3c0 = 2;
                this->requested_action = 2;
            }
            this->update_collide_flag();
            break;
        case 2:
            if (is_passing_frame((f32) ((9.0f))) != 0) {
                this->m_440 = (s32) (this->m_440 + 1);
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
                if ((s32) this->m_440 >= 4) {
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

#pragma push
#pragma fp_contract on

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
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0 && arg0->vfunc_104((2e+02f)) == 0) {
            break;
        }
        arg0->update();
        ((TObjEneDD *)arg0)->update_velocity();
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
        if (arg0->m_43c > *(f32 *)((s8 *)(arg0->movementParameters) + 4)) {
            arg0->m_43c *= (0.96f);
        } else {
            arg0->m_43c = *(f32 *)((s8 *)(arg0->movementParameters) + 4);
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
        arg0->m_43c = *(f32 *)((s8 *)(arg0->movementParameters) + 4);
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off

#pragma push
#pragma fp_contract on
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
        if (arg0->update_linked_position((2e+02f)) != 0) {
            arg0->transition_enemy_state(2);
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
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
#pragma pop

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
        ((TObjMotion *)arg0)->advance_animation();
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
#pragma pop

s32 TObjEneBm3Fly::vfunc_104(f32 farg0) {
    if (this->vfunc_99() != 0) {
        ((TObjEneDD_ST *)this)->select_and_apply_target(farg0);
        return;
    }
    select_nearest_target__12TObjEneDD_STFf(this, farg0);
}
void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly) {
    play_persistent_sound(fly->remap_sound_for_area(0x4003AB23), (s32)fly, (u32)&fly->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}
void TObjEneBm3Fly::play_pitched_cue() {
    play_persistent_sound(this->remap_sound_for_area(0x40039E22), (s32)this, (u32)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

}

typedef struct Cand_800B1684 {
    u16 id;
    u16 pad;
    f32 dist;
} Cand_800B1684;

extern "C" {
void vfunc_88__13TObjEneBm3FlyFv(u8 *arg0);
f32 fabs_float(f32);
extern s32 TObjEneBm3Fly__attack_params;
s32 get_random_scaled__9TObjEneDDFv(void *);
s32 enemy_set_target_id(void *, u16);
s32 collect_enemy_target_candidates(void *, Cand_800B1684 *, f32);
void vfunc_89__13TObjEneBm3FlyFv(void* p);

u16 TObjEneBm3Fly::get_active_id() {
    if ((s32) this->m_454 != 0) {
        return this->m_38c;
    }
    return 0xFFFFU;
}

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::sub_800B1634() {
    this->m_444 = (f32) (((2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this)) + ((45.0f) + this->m_41c.y));
    this->m_448 = get_random_scaled__9TObjEneDDFv(this);
}
#pragma pop

void choose_attack__13TObjEneBm3FlyFPv(TObjEneBm3Fly *s) {
    Cand_800B1684 players[4];
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

s32 TObjEneBm3Fly::can_attack_target() {
    f32 temp_f31;
    if ((this->m_3ac < ((5.0f) + ((AttackParams *)TObjEneBm3Fly__attack_params)->get_attack_range())) && (fabs_float((f32) (this->m_42c - this->m_394.y)) < (1.0f))) {
        temp_f31 = vec3_dot(&this->m_430, &this->m_3a0);
        if (temp_f31 >= cos_table_lookup(((AttackParams *)(this->m_318))->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
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

void TObjEneBm3Fly::vfunc_89() { TObjEneDD::vfunc_89(); this->clamp_flight_height(); }

}

#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

struct Stack_800B22C8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_800B22C8_lbl_8043B0FC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_800B22C8_lbl_80491B4C {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly {
    s32 value;
    u8 remaining[0x1A8];
};

typedef char RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly_size[sizeof(RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly) == 0x1AC ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_8043B0FC_size[sizeof(RecoveredGlobal_800B22C8_lbl_8043B0FC) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_80491B4C_size[sizeof(RecoveredGlobal_800B22C8_lbl_80491B4C) == 0x2C ? 1 : -1];

u16 get_entity_id(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 init_from_model__11TBreakUpMdlFl(int, void *);
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *arg0, s32 arg1);
void vfunc_61__13TObjEneBm3FlyFv(void);
void vfunc_62__13TObjEneBm3FlyFv(void* p);
void vfunc_63__13TObjEneBm3FlyFv(u8 *arg0);
void vfunc_28__13TObjEneBm3FlyFv(void);
void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 arg2);
void * __dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1);
u8 * TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6);
int TObjEneBm3FlyNest__sub_800B4158(void);
u32 TObjEneEpsilon__sub_800B92F8(void *, void *, f32);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
u32 move_with_wall_slide_commit__9TObjEneDDFfff(TObjEneDD *, f32, f32, f32);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);

void vfunc_6__8TObjBaseFPsl();
void vfunc_103__9TObjEneDDFPUc();
void vfunc_79__9TObjEneDDFPl();
void vfunc_84__9TObjEneDDFv();
void vfunc_85__9TObjEneDDFv();
void vfunc_86__9TObjEneDDFv();
void vfunc_90__9TObjEneDDFv();
void vfunc_91__9TObjEneDDFv();
void vfunc_92__9TObjEneDDFv();
void vfunc_93__9TObjEneDDFv();
void vfunc_94__9TObjEneDDFv();
void vfunc_95__9TObjEneDDFv();
void vfunc_96__9TObjEneDDFv();
void vfunc_97__9TObjEneDDFv();
void vfunc_98__9TObjEneDDFv();
void vfunc_99__9TObjEneDDFv();
void vfunc_100__9TObjEneDDFv();
void vfunc_101__9TObjEneDDFPUc();
void vfunc_102__9TObjEneDDFv();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFf();
void vfunc_75__9TObjCharaFf();
void clear_lobby_object_state__9TObjEnemyFv();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
extern RecoveredGlobal_800B22C8_lbl_8043B0FC bm3_fly_resource_binding_desc;

extern s32 TObjEneBm3Fly__name;
extern s32 bm3_fly_boss_stat_handle;
extern s32 lbl_805D50E8;
extern u8 *bm3_fly_nest_resources;
extern void *tl_04;

extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void run_task__13TObjEneBm3FlyFv();
extern "C" void render__13TObjEneBm3FlyFv();
void *bm3_fly_decision_row[7] = {
    (void *)0x43610000, (void *)0x3f6d097b, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm3_fly_collider_params[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm3_fly_action_table[20] = {
    (void *)0x10000, (void *)0xa, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10001, (void *)0xc, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30002, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x30004, (void *)0x3, (void *)0x3f800000, (void *)0x0,
};
void *__vt__13TObjEneBm3Fly[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TObjEneBm3FlyFv, (void *)&run_task__13TObjEneBm3FlyFv,
    (void *)&render__13TObjEneBm3FlyFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__13TObjEneBm3FlyFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__13TObjEneBm3FlyFv, (void *)&vfunc_62__13TObjEneBm3FlyFv, (void *)&vfunc_63__13TObjEneBm3FlyFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneBm3Fly__vt85,
    (void *)&vfunc_88__13TObjEneBm3FlyFv, (void *)&vfunc_89__13TObjEneBm3FlyFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__13TObjEneBm3FlyFf, (void *)&TObjEneBm3Fly__vt103, (void *)&TObjEneBm3Fly__vt104,
};
#define bm3_fly_collider_params (*(RecoveredGlobal_800B22C8_lbl_80491B4C *)bm3_fly_collider_params)
#define __vt__13TObjEneBm3Fly ((s32 *)__vt__13TObjEneBm3Fly)

#pragma push
#pragma opt_common_subs off
void TObjEneBm3Fly::clamp_flight_height() {
    if ((this->m_42c - this->position.y) < (1.2f)) {
        this->m_42c = (1.2f) + this->position.y;
    }
#define queue_destruction__7TObjectFv (*(void (*)(void *))&queue_destruction__7TObjectFv)
#define update_scale__15TObjBoss2TunnelFv (*(s32 (*)(void *))&update_scale__15TObjBoss2TunnelFv)
#define set_global_param__8TObjFishFl (*(void (*)(s32))&set_global_param__8TObjFishFl)
#define render__13TObjEneBm3FlyFv (*(void (*)())&render__13TObjEneBm3FlyFv)
    this->m_300 = this->m_42c;
}
#pragma pop

void TObjEneBm3Fly::store_position() {
    this->m_2fc = (f32) this->position.x;
    this->m_304 = (f32) this->position.z;
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
}

void TObjEneBm3Fly::update_state_flag() {

    if (TObjEneEpsilon__sub_800B92F8(this, *(void **)((s8 *)this->movementParameters + 8), *(*(f32 **)&lbl_805D50EC)) != 0U) {
        this->m_428 = (s32) (this->m_428 | 2);
        return;
    }
    this->m_428 = (s32) (this->m_428 & 0xFFFFFFFD);
}

void update_dd_flag__13TObjEneBm3FlyFPv(TObjEneBm3Fly *fly, f32 x, f32 z, f32 speed) {
    if (move_with_wall_slide_commit__9TObjEneDDFfff(fly, x, z, speed) != 0U) {
        fly->m_428 = (s32) (fly->m_428 | 2);
        return;
    }
    fly->m_428 = (s32) (fly->m_428 & 0xFFFFFFFD);
}

void TObjEneBm3Fly::update_collide_flag() {
    if (this->vfunc_102() != 0U) {
        this->m_428 = (s32) (this->m_428 | 2);
        return;
    }
    this->m_428 = (s32) (this->m_428 & 0xFFFFFFFD);
}

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::circle_destination(s32 arg1) {
    this->enemy_copy_target_destination();
    this->m_394.x = (f32) (((7e+01f) * sin_table_lookup(arg1)) + this->m_394.x);
    this->m_394.y = (f32) ((this->position.y) + this->m_44c);
    this->m_394.z = (f32) (((7e+01f) * cos_table_lookup(arg1)) + this->m_394.z);
}
#pragma pop

void TObjEneBm3Fly::update_height_offset() {
    this->enemy_copy_target_destination();
    this->m_394.y = (f32) (this->position.y + this->m_450);
}

void TObjEneBm3Fly::update() {
    this->enemy_copy_target_destination();
    this->m_394.y = (f32) (this->position.y + this->m_44c);
}

void TObjEneBm3Fly::vfunc_61() {  }

void TObjEneBm3Fly::vfunc_62() { if (this->mode != 6) { this->transition_enemy_state(6); } }

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

void TObjEneBm3Fly::vfunc_28() {  }

void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        TObjEneBm3Fly__sub_800B1214((TObjEneBm3Fly *)arg0, (msg));
        return;
    case 1:
        TObjEneBm3Fly__sub_800B0F70((TObjEneBm3Fly *)arg0, (msg));
        return;
    case 2:
        TObjEneBm3Fly__sub_800B0B20((TObjEneBm3Fly *)arg0, (msg));
        return;
    case 3:
        ((TObjEneBm3Fly *)arg0)->execute_action((msg));
        return;
    case 4:
        ((TObjEneBm3Fly *)arg0)->state_circle_target((msg));
        return;
    case 6:
        ((TObjEneBm3Fly *)arg0)->update_recoil_state((msg));
        return;
    case 8:
        ((TObjEneBm3Fly *)arg0)->state_death_fall((msg));
        return;
    case 5:
        TObjEneBm3Fly__sub_800B02C8((TObjEneBm3Fly *)((u8 *)arg0), (msg));
        return;
    case 7:
        action__13TObjEneBm3FlyFPvi((TObjEneBm3Fly *)arg0, (msg));
        return;
    case 9:
        ((TObjEneBm3Fly *)arg0)->handle_message((msg));
    default:
        return;
    }
}

}
void TObjEneBm3Fly::run_task() {
  u8* arg0 = (u8*)this;
  f32 temp_f2;
  f32 temp_f31;
  f32 var_f30;
  s16 temp_r0;
  u32 entity;
  u8 *temp_r3_2;
  u8 *temp_r3_3;
  u8 *temp_r3_4;
  if (TObjPlayer::check_demo_mode() != 0)
  {
    this->vfunc_105();
    return;
  }
  entity = (u32)find_entity_by_id((owner_id));
  if ((entity == 0U) || (((TObject *)entity)->all_parents_unqueued_for_destruction() == 0))
  {
    queue_destruction__7TObjectFv((void *) arg0);
    return;
  }
  if ((this->vfunc_83()) != 4)
  {
    (this->vfunc_85());
    temp_r3_2 = particle_effect;
    if (temp_r3_2 == 0)
    {
      particle_effect = (u8 *)create_particle_emitter(&this->m_2fc, 0xC7);
      temp_r3_3 = particle_effect;
      if (temp_r3_3 != 0)
      {
        ((TParticleCtrl *)temp_r3_3)->enable();
      }
    }
    else
    {
      ;
      if ((((mode) == 9) || ((mode) == 8)) || ((mode) == 7))
      {
        ((TParticleCtrl *)temp_r3_2)->enable();
      }
      else
      {
        if ((alternate_phase) == 0)
        {
          var_f30 = (3.0f);
          alternate_phase = 1;
        }
        else
        {
          var_f30 = (-3.0f);
          alternate_phase = 0;
        }
        if (TObjEneDD::check_v2_mode() != 0)
        {
          var_f30 *= (3.0f);
        }
        temp_f31 = var_f30 * cos_table_lookup(rotation_y);
        temp_f2 = var_f30 * (-sin_table_lookup(rotation_y));
        *((f32 *) ((particle_effect) + 0x60)) = (f32) (((*(Vec *)&this->m_2fc).x) + temp_f31);
        *((f32 *) ((particle_effect) + 0x64)) = (f32) ((-1.5f) + ((*(Vec *)&this->m_2fc).y));
        *((f32 *) ((particle_effect) + 0x68)) = (f32) (((*(Vec *)&this->m_2fc).z) + temp_f2);
      }
    }
  }
  else
  {
    temp_r3_4 = particle_effect;
    if (temp_r3_4 != 0)
    {
      ((TParticleCtrl *)temp_r3_4)->enable();
    }
  }
  ((TObjEneBm3Fly *)arg0)->store_position();
  ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
  (this->vfunc_100());
}

extern "C" {
void *__dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjEneBm3Fly;
        if (((TObjEneBm3Fly *)arg0)->particle_effect != NULL) { queue_destruction__7TObjectFv(((TObjEneBm3Fly *)arg0)->particle_effect); *(s32 *)((s8 *)arg0 + 0x458) = 0; }
        free_collision_body_parts(arg0);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on

void reset_hp__9TObjEneDDFPUcPUcPUc(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFl(void *, s32);
void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, s32);

void TObjEneBm3Fly::init_child_params() {
    init_position_vectors();
    this->model = *(void **)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 8);
    this->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 0xC);
    init_model__9TObjEneDDFP13CollisionBodyl(this, &bm3_fly_collider_params, 1);
    set_field_d8((s32)bm3_fly_action_table);
    set_field_dc(*(s32 *)((s8 *)bm3_fly_nest_resources + 0x430));
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    reset_hp__9TObjEneDDFPUcPUcPUc(this, bm3_fly_boss_stat_handle, TObjEneBm3Fly__attack_params, lbl_805D50E8);
    check_state_flag_1();
    this->movementParameters = bm3_fly_decision_row;
    initialize_enemy_state__9TObjEneDDFl(this, 3);
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
    this->particle_effect = 0;
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

u8 *TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6) {
    __ct__12TObjEneDD_STFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly *)__vt__13TObjEneBm3Fly).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneBm3Fly__name;
    ((TObjEneBm3Fly *)arg0)->owner_id = get_entity_id(arg2);
    ((TObjEneDD *)arg0)->init_common_from((u8 *)arg2);
    ((TObjEneBm3Fly *)arg0)->entity_id = arg3;
    *(s16 *)((s8 *)arg0 + 0x2C) = arg4;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg5));
    VecCopy((Vec *)(arg0 + 0x41C), (const Vec *)(arg2 + 0x38));
    VecCopy((Vec *)(arg0 + 0x40C), (const Vec *)(arg6));
    ((TObjEneBm3Fly *)arg0)->init_child_params();
    *(s32 *)((s8 *)arg0 + 0x80) = 0;
    return arg0;
}

void TObjEneBm3Fly::release_shared_data() {
    if (TObjEneBm3Fly__breakup_model != NULL) {
        delete TObjEneBm3Fly__breakup_model;
        TObjEneBm3Fly__breakup_model = NULL;
    }
}

void *TObjEneBm3Fly::create(void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x4A8);
    if (o != NULL) {
        o = TObjEneBm3Fly__ct((u8 *)o, (s32)tl_04, (u8 *)this, (s32)arg1, (s32)arg2, (u8 *)arg3, (u8 *)arg4);
    }
    return o;
}

void TObjEneBm3Fly::load_resources() {
    typedef char sp8_offset[(offsetof(Stack_800B22C8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800B22C8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800B22C8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800B22C8, sp14) == 0xC) ? 1 : -1];
    Stack_800B22C8 stack;
    s32 temp_r3;
    s32 var_r0;
    u8 *temp_r5;
    bm3_fly_nest_resources = ((u8 * (*)(void))TObjEneBm3FlyNest__sub_800B4158)();
    temp_r3 = (int)::operator new(0x10);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = init_from_model__11TBreakUpMdlFl(temp_r3, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 8)));
    }
    TObjEneBm3Fly__breakup_model = (TUnk_8048FA00 *)var_r0;
    bm3_fly_boss_stat_handle = register_boss__6TLobbyFl(0);
    TObjEneBm3Fly__attack_params = dispatch_shared_handler_b__6TLobbyFl(0);
    lbl_805D50E8 = register_object__6TLobbyFl(0);
    (*(s32 *)&(*(f32 **)&lbl_805D50EC)) = dispatch_shared_handler_a__6TLobbyFl(0);
    stack.sp8 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 0);
    stack.spC = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)bm3_fly_nest_resources + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C));
    TLobby::spawn_npc_enemy((s16)(7), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 8))), (NJS_TEXLIST *)((int) (*(s32 *)((s8 *)temp_r5 + 0xC))), &stack.sp8, (f32)((f32) (*(f32 *)((s8 *)&bm3_fly_collider_params.value + 0xC))), (f32)((f32) ((15.0f))));
}

}

#undef queue_destruction__7TObjectFv
#undef update_scale__15TObjBoss2TunnelFv
#undef set_global_param__8TObjFishFl
#undef render__13TObjEneBm3FlyFv

#undef lbl_805D50EC
