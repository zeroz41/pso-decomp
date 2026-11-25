#include "types.h"
#include "pso/weapon/TItemWeaponNug2000Bazooka.h"
#include "pso/item/TItem.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TFireExplosion.h"
#include "pso/weapon/TExplosionCollider.h"

void spawn_nug2000_wall_explosion(s32 item_id, const Vec *pos) {
    TItemWeapon *weapon = static_cast<TItemWeapon *>(find_item_by_id(item_id));
    if (weapon != NULL) {
        spawn_fire_explosion_at(weapon, pos);
    }
}

void spawn_nug2000_hit_explosion(s32 item_id, ActorBodyHit *hit) {
    TItemWeapon *weapon = static_cast<TItemWeapon *>(find_item_by_id(item_id));
    if (weapon != NULL) {
        spawn_fire_explosion_at(weapon, &hit->target->bodies[hit->body].center);
    }
}

void spawn_fire_explosion_at(TItemWeapon *weapon, const Vec *pos) {
    WeaponEffectDescriptor info;
    reset_weapon_effect_descriptor(&info);
    weapon->fill_status_info(&info);
    VecCopy(&info.position, pos);
    info.hits = 10;
    new TExplosionCollider(tl_05, &info);
    new TFireExplosion(10.0f, &info.position, 0, tl_particle);
}

void TItemWeaponNug2000Bazooka::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->hit_effect = (void *)spawn_nug2000_hit_explosion;
    desc->wall_effect = (void *)spawn_nug2000_wall_explosion;
    desc->spin[0] = -0x4000;
    desc->particle = 0x1bb;
    desc->trail_particle = 0x1bc;
    desc->flags |= 0x80;
}

void TItemWeaponNug2000Bazooka::emit_marker_effects() {
    s32 origin;
    get_joint_position(1, &origin);
    fire_shot_at_target(&origin, second_model, 0);
}

TItemWeaponNug2000Bazooka::TItemWeaponNug2000Bazooka(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *create_nug2000_bazooka(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponNug2000Bazooka(tl_05, item);
    }
    return NULL;
}

TItemWeaponNug2000Bazooka::~TItemWeaponNug2000Bazooka() {}
