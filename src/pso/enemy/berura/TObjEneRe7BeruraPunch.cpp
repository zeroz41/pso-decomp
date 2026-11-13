#include "types.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"
#include "pso/enemy/dd/TObjEneDD_800BA138.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_80086B64.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/enemy/AttackTargetHistory.h"

#pragma readonly_strings on

extern "C" {

s32 is_player_entity_id();
s32 apply_hit_if_active__13TUnk_804928CCFPvPf();
f32 random_ratio__9TObjCharaFv();
u16 get_entity_id(void *);

int TObjEneRe7BeruraPunch::is_patrol_active() { return (*(u32 *)&this->owner_id >> 2) & 0x1; }

void TObjEneRe7BeruraPunch::apply_hit_if_active(void *target, f32 *) {
    s32 entity;

    apply_hit_if_active__13TUnk_804928CCFPvPf();
    if (TObjEneDD::check_v2_mode() != 0) {
        get_entity_id((void *)target);
        if (is_player_entity_id() != 0) {
            entity = (s32)find_entity_by_id(this->owner_id);
            if ((entity != 0) && (random_ratio__9TObjCharaFv() < 0.1f)) {
                TObjEneDD__sub_800BA438(entity, (u8 *)target);
            }
        }
    }
}

}

struct Pair_80096150 { s32 a; s32 b; };

extern "C" {

s32 TObjEneRe7Berura__sub_80094D98();

void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self);
s32 refresh_collision_body_centers__14TObjCollidableFv(void *, void *, f32, f32);
extern Pair_80096150 lbl_80439F28[];

s32 post_translate_matrix(void *);
s32 scale_matrix(s32, f32, f32, f32);
s32 push_matrix();
s32 defer_render__7TObjectFv(void *);

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TObjEneRe7BeruraPunch::render() {
    f32 temp_f1;

    if (this->m_b4 != 0) {
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        if (this->m_b4 == 2) {
            this->m_f8.set_flags_and_apply_damage_color();
            if (defer_render__7TObjectFv(this) != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        ((TObjEneDD *)&this->position)->draw_oriented_shadow((s32)&this->ground_normal, 0, (u32)0);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        post_translate_matrix(&this->position);
        translate_matrix(0, 0.0f, this->m_cc, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        temp_f1 = this->m_f4;
        scale_matrix(0, temp_f1, temp_f1, 1.0f);
        TObjEneRe7Berura::init_part(this->m_b8);
        pop_matrix();
        if (this->m_b4 == 2) {
            this->m_f8.clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
    }
}

extern const f32 TObjEneRe7BeruraPunch__data_805D97A0[1];

#pragma push
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_velocity_and_snap() {
    if (this->m_f8.decay_value_toward_floor() != 0) {
        this->m_b4 = 0;
    }
    this->m_dc.x = (0.2f * (TObjEneRe7BeruraPunch__data_805D97A0[0] * this->m_bc)) + this->m_dc.x;
    this->m_dc.z = (0.2f * (TObjEneRe7BeruraPunch__data_805D97A0[0] * this->m_c4)) + this->m_dc.z;
    this->snap_to_ground();
}
#pragma pop

__declspec(section ".sdata2") const f32 TObjEneRe7BeruraPunch__data_805D97A0[1] = {10.0f};

const char *TObjEneRe7BeruraPunch__name = "TObjEneRe7BeruraPunch";

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_flight() {
    Vec target;
    s32 blocked;
    CsnHit *hit;

    this->m_f4 += 0.15f;
    if (this->m_f4 > 2.0f) {
        this->m_f4 = 2.0f;
    }
    blocked = 0;
    this->m_114 += TObjEneRe7BeruraPunch__data_805D97A0[0];
    target.x = (TObjEneRe7BeruraPunch__data_805D97A0[0] * this->m_bc) + this->position.x;
    target.y = this->m_dc.y;
    target.z = (TObjEneRe7BeruraPunch__data_805D97A0[0] * this->m_c4) + this->position.z;
    hit = csnVector(&this->m_dc, &target, 0x88E0);
    if (hit != NULL) {
        blocked = 1;
        this->m_dc.x = hit->contact->point.x;
        this->m_dc.x = hit->contact->point.x;
    } else {
        this->m_dc.x = target.x;
        this->m_dc.z = target.z;
    }
    this->snap_to_ground();
    if ((blocked != 0) || (sub_80096150() != 0) || (this->m_114 > this->m_c8)) {
        this->m_b4 = 2;
        if (find_entity_by_id(this->owner_id) != NULL) {
            TObjEneRe7Berura__sub_80094D98();
        }
    }
}
#pragma pop

s32 TObjEneRe7BeruraPunch::sub_80096150() {
    TObjEneRe7Berura *owner;
    CollisionBody *bodies;

    owner = (TObjEneRe7Berura *)find_entity_by_id(this->owner_id);
    this->bodies[0].offset.y = this->m_cc;
    this->bodies[1].offset.y = this->m_cc;
    bodies = this->bodies;
    bodies[1].offset.z = 1.8f * (3.0f * this->m_f4);
    refresh_collision_body_centers__14TObjCollidableFv(this, bodies, 3.0f, 1.8f);
    this->update_enemy_collision_flags();
    bodies = this->bodies;
    if ((bodies[0].flags | bodies[1].flags) & 0x200000) {
        return 1;
    }
    if (owner != 0) {
        owner->reload_stats_from_tables();
    }
    Pair_80096150 p = lbl_80439F28[0];
    if (TObjEneDD::check_v2_mode() != 0) {
        p.b &= ~2;
    }
    this->call_vt16_with_default(&p, this->attack_history);
    if (owner != 0) {
        TObjEneRe7Berura__sub_80094C68(owner);
    }
    return 0;
}

void TObjEneRe7BeruraPunch::launch(s32 arg1, s32 arg2) {
    TObjCollidable *owner;

    this->m_b8 = arg1;
    VecCopy(&this->m_dc, (const Vec *)arg2);
    this->snap_to_ground();
    owner = find_entity_by_id(this->owner_id);
    if (owner != NULL) {
        this->rotation_y = owner->rotation_y;
    } else {
        this->rotation_y = 0;
    }
    this->m_bc = sin_table_lookup(this->rotation_y);
    this->m_c0 = 0.0f;
    this->m_c4 = cos_table_lookup(this->rotation_y);
    this->m_c8 = 300.0f;
    this->reset();
    this->m_b4 = 1;
}

}

extern "C" {

// The punch's two collision spheres (radius 3).
CollisionBody TObjEneRe7BeruraPunch__collision_body_templates[2] = {
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
};
extern const char *TObjEneRe7BeruraPunch__name;
void queue_destruction__7TObjectFv(void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void vec3_add_to(void *, void *);

void TObjEneRe7BeruraPunch__sub_800962F4(TObjEneRe7BeruraPunch *p);
s32 fill_value_array(void *);

void TObjEneRe7BeruraPunch__sub_800962F4(TObjEneRe7BeruraPunch *p) { p->m_b4 = 0; }

void TObjEneRe7BeruraPunch::snap_to_ground() {
    Vec origin;
    f32 y;
    CsnHit *hit;

    VecCopy(&origin, &this->m_dc);
    origin.y = 20.0f;
    hit = (CsnHit *)csnVecterUnder((s32)&origin, 0x16EF);
    if (hit != 0) {
        VecCopy(&this->position, &hit->contact->point);
        VecCopy(&this->ground_normal, &hit->contact->normal);
    } else {
        this->position.x = this->m_dc.x;
        this->position.z = this->m_dc.z;
    }
    y = ((f32 *)&this->m_dc)[1];
    this->m_cc = y - this->position.y;
    if (this->m_cc < TObjEneRe7BeruraPunch__data_805D97A0[0]) {
        ((f32 *)&this->m_dc)[1] = TObjEneRe7BeruraPunch__data_805D97A0[0] + this->position.y;
        this->m_cc = TObjEneRe7BeruraPunch__data_805D97A0[0];
    }
    if ((y && y) && y) {
    }
}

void TObjEneRe7BeruraPunch::reset() {
    fill_value_array(this->attack_history);
    this->m_f4 = 1.0f;
    this->m_f8.reset_color();
    this->m_118 = 0;
    this->m_114 = 0.0f;
}

void TObjEneRe7BeruraPunch::run_task() {
    ParticleAngles ang;
    Vec v;
    f32 s;
    f32 c;
    if (find_entity_by_id(this->owner_id) == NULL || all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    switch (this->m_b4) {
    case 0:
        break;
    case 1:
        this->update_flight();
        break;
    case 2:
        this->update_velocity_and_snap();
        break;
    }
    if (this->m_b4 == 1) {
        ang.x = 0;
        ang.y = this->rotation_y + 0x4000;
        ang.z = -0x4000;
        s = -sin_table_lookup(this->rotation_y);
        c = -cos_table_lookup(this->rotation_y);
        if (this->m_d0 == NULL) {
            this->m_d0 = create_particle_emitter(&this->position, 0xDD);
            if (this->m_d0 != NULL) {
                this->m_d0->set_flags(2);
                this->m_d0->enable();
            }
        } else {
            v.x = 40.0f * s;
            v.y = 3.0f;
            v.z = 40.0f * c;
            vec3_add_to(&v, &this->m_dc);
            this->m_d0->set_position(&v);
            this->m_d0->set_direction(&ang);
        }
        if (this->m_d4 == NULL) {
            this->m_d4 = create_particle_emitter(&this->position, 0x150);
            if (this->m_d4 != NULL) {
                this->m_d4->set_flags(2);
                this->m_d4->enable();
            }
        } else {
            v.x = -20.0f * s;
            v.y = 5.0f;
            v.z = -20.0f * c;
            vec3_add_to(&v, &this->m_dc);
            this->m_d4->set_position(&v);
            this->m_d4->set_direction(&ang);
        }
    } else {
        if (this->m_d0 != NULL) {
            this->m_d0->enable();
        }
        if (this->m_d4 != NULL) {
            this->m_d4->enable();
        }
    }
}

}
TObjEneRe7BeruraPunch::~TObjEneRe7BeruraPunch() {
    if (this->m_d0 != NULL) {
        queue_destruction__7TObjectFv(this->m_d0);
        this->m_d0 = 0;
    }
    if (this->m_d4 != NULL) {
        queue_destruction__7TObjectFv(this->m_d4);
        this->m_d4 = 0;
    }
    if (this->attack_history != NULL) {
        delete this->attack_history;
        this->attack_history = 0;
    }
}
extern "C" {

void TObjEneRe7BeruraPunch::init() {
    this->m_b4 = 0;
    this->m_b8 = 0;
    this->m_bc = 0.0f;
    this->m_c0 = 0.0f;
    this->m_c4 = 0.0f;
    this->m_c8 = 0.0f;
    this->m_cc = 0.0f;
    this->m_d0 = 0;
    this->m_d4 = 0;
    this->attack_history = new AreaAttackHistory(9);
    this->m_f8.set_rate_from_divisor(0);
    reset();
}
TObjEneRe7BeruraPunch::TObjEneRe7BeruraPunch(TObject *parent, TObjBase *owner)
    : TUnk_804928CC(parent, owner, TObjEneRe7BeruraPunch__collision_body_templates, 2) {
    m_name = TObjEneRe7BeruraPunch__name;
    owner_id = get_entity_id(owner);
    init();
}

}
