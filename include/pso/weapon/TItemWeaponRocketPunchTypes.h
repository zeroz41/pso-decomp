#ifndef PSO_WEAPON_TITEMWEAPONROCKETPUNCHTYPES_H
#define PSO_WEAPON_TITEMWEAPONROCKETPUNCHTYPES_H

#include "types.h"

struct TargetEntityPosition {
    u8 pad[0x1c];
    u8 position[0x10];
};

struct TargetEntityManager {
    u8 pad[0xa4];
    TargetEntityPosition *ents;
    s32 count;
};

#endif
