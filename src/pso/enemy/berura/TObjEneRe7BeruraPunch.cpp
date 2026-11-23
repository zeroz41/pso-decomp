#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"
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
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


int TObjMotion::is_motion_blending() { return (motion_flags >> 2) & 1; }

void TObjEneRe7BeruraPunch::apply_hit_if_active(void *target, f32 *hit) {
    TObjChara *entity;

    TUnk_804928CC::apply_hit_if_active(target, hit);
    if (TObjEneDD::check_v2_mode() != 0) {
        if (is_player_entity_id(((TObjBase *)(target))->get_entity_id()) != 0) {
            entity = (TObjChara *)find_entity_by_id(this->owner_id);
            if ((entity != NULL) && (entity->random_ratio() < 0.1f)) {
                TObjEneDD__sub_800BA438(entity, (TObjChara *)target);
            }
        }
    }
}

// the contact attack update_attack_collision hands call_vt16_with_default
// (layout as DelbiterContactAttack; name inferred)
struct BeruraPunchContactAttack { f32 power; s32 flags; };


void TObjEneRe7BeruraPunch::render() {

    if (this->state != 0) {
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        if (this->state == 2) {
            this->fade.set_flags_and_apply_damage_color();
            if (this->defer_render() != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        TObjEneDD::draw_oriented_shadow(&position, &ground_normal, 0, NULL);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        post_translate_matrix(&this->position.x);
        translate_matrix(0, 0.0f, this->height, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, this->scale, this->scale, 1.0f);
        TObjEneRe7Berura::draw_arm(this->arm);
        pop_matrix();
        if (this->state == 2) {
            this->fade.clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_velocity_and_snap() {
    if (this->fade.decay_value_toward_floor() != 0) {
        this->state = 0;
    }
    this->travel_position.x = (0.2f * (10.0f * this->direction.x)) + this->travel_position.x;
    this->travel_position.z = (0.2f * (10.0f * this->direction.z)) + this->travel_position.z;
    this->snap_to_ground();
}
#pragma pop

const char *TObjEneRe7BeruraPunch__name = "TObjEneRe7BeruraPunch";

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_flight() {
    Vec target;
    s32 blocked;
    CsnHit *hit;
    TObjEneRe7Berura *owner;

    this->scale += 0.15f;
    if (this->scale > 2.0f) {
        this->scale = 2.0f;
    }
    blocked = 0;
    this->distance += 10.0f;
    target.x = (10.0f * this->direction.x) + this->position.x;
    target.y = this->travel_position.y;
    target.z = (10.0f * this->direction.z) + this->position.z;
    hit = csnVector(&this->travel_position, &target, 0x88E0);
    if (hit != NULL) {
        blocked = 1;
        this->travel_position.x = hit->contact->point.x;
        this->travel_position.x = hit->contact->point.x;
    } else {
        this->travel_position.x = target.x;
        this->travel_position.z = target.z;
    }
    this->snap_to_ground();
    if ((blocked != 0) || (update_attack_collision() != 0) || (this->distance > this->range)) {
        this->state = 2;
        owner = (TObjEneRe7Berura *)find_entity_by_id(this->owner_id);
        if (owner != NULL) {
            owner->clear_arm_flying();
        }
    }
}
#pragma pop

s32 TObjEneRe7BeruraPunch::update_attack_collision() {
    TObjEneRe7Berura *owner;
    CollisionBody *bodies;

    owner = (TObjEneRe7Berura *)find_entity_by_id(this->owner_id);
    this->bodies[0].offset.y = this->height;
    this->bodies[1].offset.y = this->height;
    bodies = this->bodies;
    bodies[1].offset.z = 1.8f * (3.0f * this->scale);
    TObjCollidable::refresh_collision_body_centers();
    this->update_enemy_collision_flags();
    bodies = this->bodies;
    if ((bodies[0].flags | bodies[1].flags) & 0x200000) {
        return 1;
    }
    if (owner != 0) {
        owner->reload_stats_from_tables();
    }
    BeruraPunchContactAttack attack = { 3.0f, 3 };
    if (TObjEneDD::check_v2_mode() != 0) {
        attack.flags &= ~2;
    }
    this->call_vt16_with_default(&attack, this->attack_history);
    if (owner != 0) {
        owner->reload_base_stats();
    }
    return 0;
}

void TObjEneRe7BeruraPunch::launch(s32 arm, const Vec *position, const Vec *destination) {
    TObjCollidable *owner;

    this->arm = arm;
    VecCopy(&this->travel_position, position);
    this->snap_to_ground();
    owner = find_entity_by_id(this->owner_id);
    if (owner != NULL) {
        this->rotation_y = owner->rotation_y;
    } else {
        this->rotation_y = 0;
    }
    this->direction.x = sin_table_lookup(this->rotation_y);
    this->direction.y = 0.0f;
    this->direction.z = cos_table_lookup(this->rotation_y);
    this->range = 300.0f;
    this->reset();
    this->state = 1;
}

// The punch's two collision spheres (radius 3).
CollisionBody TObjEneRe7BeruraPunch__collision_body_templates[2] = {
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void TObjEneRe7BeruraPunch::deactivate() { this->state = 0; }

void TObjEneRe7BeruraPunch::snap_to_ground() {
    Vec origin;
    f32 y;
    CsnHit *hit;

    VecCopy(&origin, &this->travel_position);
    origin.y = 20.0f;
    hit = csnVecterUnder(&origin, 0x16EF);
    if (hit != 0) {
        VecCopy(&this->position, &hit->contact->point);
        VecCopy(&this->ground_normal, &hit->contact->normal);
    } else {
        this->position.x = this->travel_position.x;
        this->position.z = this->travel_position.z;
    }
    y = this->travel_position.y;
    this->height = y - this->position.y;
    if (this->height < 10.0f) {
        this->travel_position.y = 10.0f + this->position.y;
        this->height = 10.0f;
    }
}

void TObjEneRe7BeruraPunch::reset() {
    fill_value_array(this->attack_history);
    this->scale = 1.0f;
    this->fade.reset_color();
    this->pad_118 = 0;
    this->distance = 0.0f;
}

void TObjEneRe7BeruraPunch::run_task() {
    ParticleAngles ang;
    Vec v;
    f32 s;
    f32 c;
    TObject *e;
    if ((e = (TObject *)find_entity_by_id(this->owner_id)) == NULL || e->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    switch (this->state) {
    case 0:
        break;
    case 1:
        this->update_flight();
        break;
    case 2:
        this->update_velocity_and_snap();
        break;
    }
    if (this->state == 1) {
        ang.x = 0;
        ang.y = this->rotation_y + 0x4000;
        ang.z = -0x4000;
        s = -sin_table_lookup(this->rotation_y);
        c = -cos_table_lookup(this->rotation_y);
        if (this->trail_emitter == NULL) {
            this->trail_emitter = create_particle_emitter(&this->position, 0xDD);
            if (this->trail_emitter != NULL) {
                this->trail_emitter->set_flags(2);
                this->trail_emitter->enable();
            }
        } else {
            v.x = 40.0f * s;
            v.y = 3.0f;
            v.z = 40.0f * c;
            vec3_add_to(&v, &this->travel_position);
            this->trail_emitter->set_position(&v);
            this->trail_emitter->set_direction(&ang);
        }
        if (this->front_emitter == NULL) {
            this->front_emitter = create_particle_emitter(&this->position, 0x150);
            if (this->front_emitter != NULL) {
                this->front_emitter->set_flags(2);
                this->front_emitter->enable();
            }
        } else {
            v.x = -20.0f * s;
            v.y = 5.0f;
            v.z = -20.0f * c;
            vec3_add_to(&v, &this->travel_position);
            this->front_emitter->set_position(&v);
            this->front_emitter->set_direction(&ang);
        }
    } else {
        if (this->trail_emitter != NULL) {
            this->trail_emitter->enable();
        }
        if (this->front_emitter != NULL) {
            this->front_emitter->enable();
        }
    }
}

TObjEneRe7BeruraPunch::~TObjEneRe7BeruraPunch() {
    if (this->trail_emitter != NULL) {
        this->trail_emitter->queue_destruction();
        this->trail_emitter = 0;
    }
    if (this->front_emitter != NULL) {
        this->front_emitter->queue_destruction();
        this->front_emitter = 0;
    }
    if (this->attack_history != NULL) {
        delete this->attack_history;
        this->attack_history = 0;
    }
}


void TObjEneRe7BeruraPunch::init() {
    this->state = 0;
    this->arm = 0;
    this->direction.x = 0.0f;
    this->direction.y = 0.0f;
    this->direction.z = 0.0f;
    this->range = 0.0f;
    this->height = 0.0f;
    this->trail_emitter = 0;
    this->front_emitter = 0;
    this->attack_history = new AreaAttackHistory(9);
    this->fade.set_rate_from_divisor(0);
    reset();
}
TObjEneRe7BeruraPunch::TObjEneRe7BeruraPunch(TObject *parent, TObjBase *owner)
    : TUnk_804928CC(parent, owner, TObjEneRe7BeruraPunch__collision_body_templates, 2) {
    m_name = TObjEneRe7BeruraPunch__name;
    owner_id = owner->get_entity_id();
    init();
}

TObjEneRe7BeruraPunch *TObjEneRe7Berura::spawn_punch() {
    return new TObjEneRe7BeruraPunch(this, this);
}
