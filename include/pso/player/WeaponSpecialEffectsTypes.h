#ifndef PSO_PLAYER_WEAPONSPECIALEFFECTSTYPES_H
#define PSO_PLAYER_WEAPONSPECIALEFFECTSTYPES_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// One lightning strike of a weapon special: where it starts, its direction and length.
struct WeaponSpecialStrike {
    Vec pos;
    Vec dir;
    f32 len;
};


#endif
