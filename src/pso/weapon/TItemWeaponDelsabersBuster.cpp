#include "types.h"
#include "pso/weapon/TItemWeaponDelsabersBuster.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponDelsabersBuster::update_weapon() {
    NJS_OBJECT *model;

    refresh_owner_stats();
    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, 2, 0, 1);
    }
}

TItemWeaponDelsabersBuster::~TItemWeaponDelsabersBuster() {}
TItemWeaponDelsabersBuster::TItemWeaponDelsabersBuster(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponDelsabersBuster::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDelsabersBuster(tl_05, item);
    }
    return NULL;
}
