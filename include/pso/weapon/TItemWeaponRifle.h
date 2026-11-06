#ifndef PSO_WEAPON_TITEMWEAPONRIFLE_H
#define PSO_WEAPON_TITEMWEAPONRIFLE_H
#include "types.h"
struct TItemWeaponRifle {
    TItemWeaponRifle* initialize(s32 parent,u8* item);
    u8 taskPrefix[0x18]; void* dispatch;
    u8 baseFields[0x1EC-0x1C]; void (*impactFactory)();
    u8 projectileFields[8]; f32 phase;
};
#endif
