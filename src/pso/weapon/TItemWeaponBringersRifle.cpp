#include "types.h"
#include "pso/weapon/TItemWeaponBringersRifle.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffBringer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponBringersRifle::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, uv_scroll, 0, 1);
    }
}

TItemWeaponBringersRifle::TItemWeaponBringersRifle(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    uv_scroll = 2;
    shot_callback = (WeaponShotCallback)TItemEffBringer::create;
}

TItem *TObjPlayer::create_bringer_effect(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponBringersRifle(tl_05, item);
    }
    return NULL;
}
