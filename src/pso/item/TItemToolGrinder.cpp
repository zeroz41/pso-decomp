#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemToolGrinder.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/weapon/TItemWeapon.h"

void TItemToolGrinder::apply_use_effect() {
    TItemWeapon *weapon;

    weapon = static_cast<TItemWeapon *>(TObjPlayer::get_equipped_weapon(this->owner));
    if (weapon != NULL) {
        add_weapon_grind(weapon, get_pmt_amount());
    }
}

TItemToolGrinder::~TItemToolGrinder() {}

TItemToolGrinder::TItemToolGrinder(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolGrinder::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolGrinder(tl_05, item);
    }
    return NULL;
}
