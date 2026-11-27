#include "types.h"
#include "pso/weapon/TItemWeaponHandgun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponHandgun::update_weapon() {
    if (get_item_index() == 6) {
        refresh_owner_stats();
    }
}

TItemWeaponSuppressedGun::TItemWeaponSuppressedGun(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = spawn_weapon_impact_effect;
}

TItem *TItemWeaponSuppressedGun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSuppressedGun(tl_05, item);
    }
    return NULL;
}

TItemWeaponHandgun::TItemWeaponHandgun(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = spawn_weapon_impact_effect;
    if (item[2] >= 5U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponHandgun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHandgun(tl_05, item);
    }
    return NULL;
}

TItemWeaponHandgun::~TItemWeaponHandgun() {}
