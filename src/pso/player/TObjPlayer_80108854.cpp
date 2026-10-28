#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

u32 TItemWeapon::test_flags_1b8(u32 m) { return (*(u32 *)((u8 *)this + 0x1B8)) & m; }
