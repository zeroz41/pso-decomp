#ifndef PSO_ITEM_WEAPONATTRIBUTE_H
#define PSO_ITEM_WEAPONATTRIBUTE_H

#include "types.h"

// One of a weapon's special attributes: area 1-4 is boosted against targets
// whose attribute mask has bit 1 << (area - 1), by percent.
struct WeaponAttribute {
    u8 area;
    s8 percent;

    void copy(WeaponAttribute *src);
};

#endif
