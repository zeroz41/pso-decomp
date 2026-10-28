#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

s32 TItemWeapon::is_active_in_game() {
    u8 active = 0;
    if (owner != NULL && get_mode() == ITEM_MODE_EQUIPPED) {
        active = 1;
    }
    return active;
}
