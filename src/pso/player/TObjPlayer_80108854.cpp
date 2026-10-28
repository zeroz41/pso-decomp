#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

u32 TItemWeapon::test_weapon_flags(u32 mask) { return weapon_flags & mask; }
