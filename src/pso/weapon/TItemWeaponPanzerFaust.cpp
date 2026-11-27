#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItemAttackColBase.h"
#include "pso/weapon/TExplosionCollider.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TItem.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/weapon/TItemWeaponPanzerFaust.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Built with -inline off,deferred: functions are written last to first.

void spawn_faust_explosion(TItemWeapon *weapon, const Vec &pos);

TItem *create_panzer_faust(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPanzerFaust(tl_05, item);
    }
    return NULL;
}

TItemWeaponPanzerFaust::TItemWeaponPanzerFaust(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    pad_200 = 0.1f;
    pad_1fc = 0.1f;
    pad_1f8 = 0.1f;
    reload_timer = 0;
    shot_speed = 10.0f;
    set_weapon_flags(0x8000);
    if (get_item_index() == 1) {
        pad_238 = 10.0f;
        descriptor_flags = 0x80;
    } else {
        pad_238 = 2.5f;
        descriptor_flags = 0;
    }
}

TItemWeaponPanzerFaust::~TItemWeaponPanzerFaust() {}

void TItemWeaponPanzerFaust::on_equipped() { reload_timer = 0; }

void TItemWeaponPanzerFaust::update_weapon() {
    if (reload_timer > 0) {
        reload_timer--;
    }
}

void TItemWeaponPanzerFaust::emit_marker_effects() { reload_timer = 60; }

void TItemWeaponPanzerFaust::transform_model_node() {
    NJS_OBJECT *child;

    if (get_model_node_counter() == 1) {
        if (second_model != NULL && reload_timer == 0) {
            child = second_model->child;
            if (child != NULL) {
                child->scl[0] = 0.1f;
                child->scl[1] = 0.1f;
                child->scl[2] = 0.1f;
                child->evalflags &= ~4;
                draw_ginja_object(second_model);
                child->evalflags |= 4;
                child->scl[0] = 1.0f;
                child->scl[1] = 1.0f;
                child->scl[2] = 1.0f;
            }
        }
    }
}

void TItemWeaponPanzerFaust::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->hit_effect = spawn_faust_hit_explosion;
    desc->wall_effect = spawn_faust_wall_explosion;
    desc->spin[0] = -0x4000;
    desc->flags |= descriptor_flags;
    desc->particle = 0x1bb;
    desc->trail_particle = 0x1bc;
}

void spawn_faust_explosion(TItemWeapon *weapon, const Vec &pos) {
    if (weapon->get_item_index() == 1) {
        WeaponEffectDescriptor info;
        reset_weapon_effect_descriptor(&info);
        weapon->fill_status_info(&info);
        VecCopy(&info.position, &pos);
        info.hits = 10;
        new TExplosionCollider(tl_05, &info);
        create_timed_particle_emitter(&info.position, 0x17F, 0, 10);
    } else {
        Vec v = pos;
        create_timed_particle_emitter(&v, 0x17E, 0, 10);
    }
}

void spawn_faust_hit_explosion(s32 item_id, ActorBodyHit *hit, Vec *velocity) {
    TItem *item = find_item_by_id(item_id);
    if (item != NULL) {
        spawn_faust_explosion((TItemWeapon *)item, hit->target->bodies[hit->body].center);
    }
}

void spawn_faust_wall_explosion(s32 item_id, const Vec *pos, Vec *velocity) {
    TItem *item = find_item_by_id(item_id);
    if (item != NULL) {
        spawn_faust_explosion((TItemWeapon *)item, *pos);
    }
}

TExplosionCollider::TExplosionCollider(TObject *parent, AttackColParams *params) : TItemAttackColBase(parent, params) {
    max_radius = 50.0f;
}

TExplosionCollider::~TExplosionCollider() {}

void TExplosionCollider::run_task() {
    f32 radius;

    if (has_game_join_id() != 0) {
        radius = body.radius;
        if (radius < max_radius) {
            body.radius += 10.0f;
            radius = max_radius;
            if (radius < body.radius) {
                body.radius = radius;
            }
        } else {
            queue_destruction();
        }
        check_hits();
    }
}
