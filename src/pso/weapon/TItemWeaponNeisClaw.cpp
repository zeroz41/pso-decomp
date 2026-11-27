#include "pso/math/ClampedStep.h"
#include "pso/technique/TFireExplosion.h"
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/object/base/TObjCollidable.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponGiGueBazooka.h"
#include "pso/weapon/TItemWeaponNeisClaw.h"
#include "pso/weapon/TItemWeaponRappysFan.h"
#include "pso/weapon/TItemWeaponRikasClaw.h"
#include "pso/weapon/TExplosionCollider.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemAttackColBase.h"
#include "pso/player/PlayerCommands.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"

// Gi Gue bazooka (TItemWeaponGiGueBazooka), TItemWeaponNeisClaw and the fire-explosion spawners: its own
// TU, since its 10.0f literal sits between two 4-byte pads.
// Built with -inline off,deferred like TItemEffPG.cpp: functions are written last to first.

TItem *TItemWeaponNeisClaw::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponNeisClaw(tl_05, item);
    }
    return NULL;
}

TItemWeaponNeisClaw::TItemWeaponNeisClaw(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    spin_angle = -30947;
    second_spin_angle = -7281;
}

TItemWeaponNeisClaw::~TItemWeaponNeisClaw() {}

void TItemWeaponNeisClaw::update_attack() { add_angle_clamped(&spin_angle, 16384, 0); add_angle_clamped(&second_spin_angle, 3640, 0); }

void TItemWeaponNeisClaw::update_idle() { add_angle_clamped(&spin_angle, -8192, -30947); add_angle_clamped(&second_spin_angle, -1820, -7281); }

void TItemWeaponNeisClaw::draw_held_model() { draw_weapon_at_joint(49); update_trail_slot(0); update_trail_slot(1); }

void TItemWeaponNeisClaw::transform_model_node() {
    s32 player_list;

    player_list = get_model_node_counter();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, this->spin_angle);
        return;
    case 8:
        rotate_matrix_z(0, this->second_spin_angle);
        return;
    }
}

TItem *TItemWeaponGiGueBazooka::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponGiGueBazooka(tl_05, item);
    }
    return NULL;
}

TItemWeaponGiGueBazooka::TItemWeaponGiGueBazooka(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
    spin_angle = -0x1C71;
    second_spin_angle = -0x1555;
    third_spin_angle = 0x238E;
}

TItemWeaponGiGueBazooka::~TItemWeaponGiGueBazooka() {}

void TItemWeaponGiGueBazooka::update_attack() { add_angle_clamped(&spin_angle, -3640, 0); add_angle_clamped(&second_spin_angle, 2730, 0); add_angle_clamped(&third_spin_angle, -1820, 0); }

void TItemWeaponGiGueBazooka::update_idle() { add_angle_clamped(&spin_angle, 1820, 7281); add_angle_clamped(&second_spin_angle, -1820, -5461); add_angle_clamped(&third_spin_angle, 1820, 9102); }

void TItemWeaponGiGueBazooka::transform_model_node() {
    s32 player_list;

    player_list = get_model_node_counter();
    switch (player_list) {
    case 2:
        rotate_matrix_x(0, this->spin_angle);
        return;
    case 3:
        rotate_matrix_x(0, this->second_spin_angle);
        return;
    case 5:
        rotate_matrix_z(0, this->third_spin_angle);
        return;
    case 4:
        rotate_matrix_z(0, -this->third_spin_angle);
        return;
    }
}

void TItemWeaponGiGueBazooka::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->hit_effect = TObjPlayer::spawn_fire_explosion_at_item;
    desc->wall_effect = spawn_fire_explosion_for_item;
    desc->flags |= 0x80;
}

void TObjPlayer::spawn_fire_explosion(TItemWeapon *weapon, const Vec *position) {
    WeaponEffectDescriptor info;
    reset_weapon_effect_descriptor(&info);
    weapon->fill_status_info(&info);
    VecCopy(&info.position, position);
    info.hits = 10;
    new TExplosionCollider(tl_05, &info);
    new TFireExplosion(10.0f, &info.position, 0, tl_particle);
}

void TObjPlayer::spawn_fire_explosion_at_item(s32 id, ActorBodyHit *hit, Vec *velocity) {
    TItemWeapon *weapon = (TItemWeapon *)find_item_by_id(id);
    if (weapon != NULL) {
        TObjPlayer::spawn_fire_explosion(weapon, &hit->target->bodies[hit->body].center);
    }
}

void spawn_fire_explosion_for_item(s32 id, const Vec *position, Vec *velocity) {
    TItemWeapon *weapon = (TItemWeapon *)find_item_by_id(id);
    if (weapon != NULL) {
        TObjPlayer::spawn_fire_explosion(weapon, position);
    }
}
