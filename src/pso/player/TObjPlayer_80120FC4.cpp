#include "types.h"
#include "pso/TMainTask.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_80120FC4.h"

// weapon_factory_table's entry for weapons without a class of their own.
TItemWeapon *create_common_weapon(u8 *item) {
    return new TItemWeapon(tl_05, item);
}
