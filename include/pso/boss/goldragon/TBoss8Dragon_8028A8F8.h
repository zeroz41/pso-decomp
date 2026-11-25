#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8028A8F8_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8028A8F8_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;
class TObject;

extern "C" {
void break_floor_grass_in_range(TObject *floor_grass, const Vec *pos, const DragonAttackParams *params);
}

#endif
