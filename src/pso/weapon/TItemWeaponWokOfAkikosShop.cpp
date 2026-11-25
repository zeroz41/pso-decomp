#include "types.h"
#include "pso/weapon/TItemWeaponWokOfAkikosShop.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

void TItemWeaponWokOfAkikosShop::draw_held_model() {
    NJS_OBJECT *saved_model = item_model;
    draw_weapon_model();
    item_model = second_model;
    draw_weapon_at_joint((saddr)this, 0x23);
    item_model = saved_model;
}

TItemWeaponWokOfAkikosShop::~TItemWeaponWokOfAkikosShop() {}

TItemWeaponWokOfAkikosShop::TItemWeaponWokOfAkikosShop(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x800201);
}

TItem *TObjPlayer__sub_80123950(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponWokOfAkikosShop(tl_05, item);
    }
    return NULL;
}
