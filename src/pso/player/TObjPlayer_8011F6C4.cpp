#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s8 get_mode__5TItemFv();

u8 TItemWeapon::is_active_in_game() {
    int var_r31;

    var_r31 = 0;
    if (((u32) this->player != 0U) && (get_mode__5TItemFv() == 2)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
