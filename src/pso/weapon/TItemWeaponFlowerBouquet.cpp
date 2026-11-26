#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponFlowerBouquet.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponFlowerBouquet::emit_marker_effects() {
    s32 muzzle[6];
    saddr weapon = (saddr)this;

    ((TItemWeapon *)weapon)->get_joint_position(1, muzzle);
    spawn_particle_effect((const Vec *)muzzle, 0xC1);
}

TItemWeaponFlowerBouquet::~TItemWeaponFlowerBouquet() {}

TItemWeaponFlowerBouquet::TItemWeaponFlowerBouquet(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}


TItem *TItemWeaponFlowerBouquet::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFlowerBouquet(tl_05, item);
    }
    return NULL;
}

