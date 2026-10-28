#include "pso/items/TItemWeapon.h"
#include "pso/item/WeaponSpecialSelection.h"
#include "pso/unk/TUnk_804A4948.h"
#include "pso/player/TObjPlayer.h"

s32 weapon_has_extra_attack(TItemWeapon* weapon) {
    if ((((TItemWeapon *)weapon)->test_weapon_flags(0x400020U) != 0U) ||
        (weapon->special_selector != 0)) {
        return 1;
    }
    return 0;
}

u8 TItemWeapon::get_special_selector() {
    return special_selector;
}

void TUnk_804A4948::set_special_selector(u8 value) {
    special_selector = value;
}
