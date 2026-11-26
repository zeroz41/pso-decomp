#ifndef PSO_WEAPON_TITEMWEAPONSORCERERSCANETYPES_H
#define PSO_WEAPON_TITEMWEAPONSORCERERSCANETYPES_H

#include "types.h"

// Eight x/y/z scales, indexed by scale_step.
struct CaneScaleTable {
    Vec value;
    Vec remaining[7];
};
LAYOUT_ASSERT(CaneScaleTable_size, sizeof(CaneScaleTable) == 0x60);

#endif
