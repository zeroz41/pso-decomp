#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponFlowerBouquet.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponFlowerBouquet::emit_marker_effects() {
    s32 sp8[6];
    saddr weapon = (saddr)this;

    ((TItemWeapon *)weapon)->get_joint_position(1, sp8);
    spawn_particle_effect((const Vec *)sp8, 0xC1);
}

TItemWeaponFlowerBouquet::~TItemWeaponFlowerBouquet() {}

TItemWeaponFlowerBouquet::TItemWeaponFlowerBouquet(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}


TItem *TItemWeaponFlowerBouquet::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFlowerBouquet(tl_05, item);
    }
    return NULL;
}

