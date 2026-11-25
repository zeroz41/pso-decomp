#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeaponFrozenShooter.h"
#include "pso/item/TItemTimerEventFreezeCurse.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/HitEligibility.h"

#pragma push
#pragma fp_contract on
void frozen_shooter_freeze_hit(int, ActorBodyHit *hit) {
    TObjChara *target;
    if (hit != NULL && obj_is_hit_receivable(hit->target) != 0) {
        target = (TObjChara *)hit->target;
        target->apply_movement_ailment((saddr)&target->bodies[hit->body]);
        target->sync_enemy_state(0);
    }
}
#pragma pop

void TItemWeaponFrozenShooter::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    if (skip_freeze == 0) {
        desc->hit_effect = (void *)frozen_shooter_freeze_hit;
    }
    desc->hits = hits;
    desc->spin[0] = 0x4000;
    desc->scale = 2.0f;
    desc->particle = particle;
}

void TItemWeaponFrozenShooter::emit_marker_effects() {
    Vec point;
    u8 *p;
    get_gun_point(&point);
    skip_freeze = 0;
    p = reinterpret_cast<u8 *>(&point);
    if (is_mode_two_and_ready() != 0) {
        fire_shot_at_target(p, second_model, 0);
    } else if (get_item_index() == 1) {
        skip_freeze = 1;
        fire_shot_at_target(p, second_model, 0);
    } else {
        launch_shot(p, 0, 0, 1);
    }
}

// Starts the freeze curse timer on the equip effect objects.
void TItemWeaponFrozenShooter::on_equipped() {
    if (effect_objects != NULL) {
        new TItemTimerEventFreezeCurse(effect_objects, get_owner_client(), 0xE10, 0.25f);
    }
}

TItemWeaponFrozenShooter::~TItemWeaponFrozenShooter() {}


TItemWeaponFrozenShooter::TItemWeaponFrozenShooter(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x22);
    if (get_item_index() == 1) {
        hits = 10;
        particle = 0x1F5;
    } else {
        hits = 1;
        particle = 0x95;
    }
    skip_freeze = 0;
}

TItem *TItemWeaponFrozenShooter::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFrozenShooter(tl_05, item);
    }
    return NULL;
}

// This object's copy of the freeze curse timer's constructor (on_equipped
// calls it first).
TItemTimerEventFreezeCurse::TItemTimerEventFreezeCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    unk_2C = rate;
}
