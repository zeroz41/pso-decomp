#include "types.h"
#include "pso/weapon/TItemWeaponFlameVisit.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponFlameVisit::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->particle = 0x1BB;
    desc->hit_effect = spawn_flame_effect;
    desc->hits = hits;
}

TItemWeaponFlameVisit::TItemWeaponFlameVisit(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
    shot_speed = 5.0f;
    if (get_item_index() == 1) {
        hits = 10;
    } else {
        hits = 1;
    }
}

TItem *TItemWeaponFlameVisit::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFlameVisit(tl_05, item);
    }
    return NULL;
}

TItemWeaponFlameVisit::~TItemWeaponFlameVisit() {}
