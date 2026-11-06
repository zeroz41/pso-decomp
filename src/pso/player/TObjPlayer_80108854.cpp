#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

u32 TItemWeapon::test_weapon_flags(u32 mask) { return weapon_flags & mask; }
