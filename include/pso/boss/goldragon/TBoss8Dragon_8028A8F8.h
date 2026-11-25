#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8028A8F8_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8028A8F8_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;
class TObject;

void break_floor_grass_in_range(TObject *floor_grass, const Vec *pos, const DragonAttackParams *params);

struct NJS_TEXLIST;

NJS_TEXLIST *get_green_door_textures(void);

#endif
