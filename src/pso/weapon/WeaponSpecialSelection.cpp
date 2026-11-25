#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/weapon/TItemWeaponSRank.h"
#include "pso/player/TObjPlayer.h"

s32 weapon_has_extra_attack(TItemWeapon* weapon) {
    if ((weapon->test_weapon_flags(0x400020U) != 0U) ||
        (weapon->special_selector != 0)) {
        return 1;
    }
    return 0;
}

u8 TItemWeapon::get_special_selector() {
    return special_selector;
}

void TItemWeaponSRank::set_special_selector(u8 value) {
    special_selector = value;
}
