#include "types.h"
#include "pso/weapon/TItemWeaponSaber.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSaber::update_weapon() {
    if (get_item_index() == 5) {
        refresh_owner_stats();
    }
}

TItemWeaponSaber::~TItemWeaponSaber() {}

TItemWeaponSaber::TItemWeaponSaber(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    if (item[2] >= 5U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponSaber::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSaber(tl_05, item);
    }
    return NULL;
}
