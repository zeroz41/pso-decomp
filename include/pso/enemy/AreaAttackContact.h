#ifndef PSO_ENEMY_AREAATTACKCONTACT_H
#define PSO_ENEMY_AREAATTACKCONTACT_H

#include "types.h"
#include <stddef.h>

struct AreaAttackContact {
    f32 recoil;
    s32 contact_flags; // Bit 0 tests player bodies, bit 1 tests enemy bodies.
};

LAYOUT_ASSERT(AreaAttackContactSize, sizeof(AreaAttackContact) == 8);
LAYOUT_ASSERT(AreaAttackContactFlagsOffset, offsetof(AreaAttackContact, contact_flags) == 4);

#endif
