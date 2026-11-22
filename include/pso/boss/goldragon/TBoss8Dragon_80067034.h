#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;

// Gal Gryphon attack hits on the arena: the grass and stone floors, and the pillars (boss5_ctrl_instance).
extern "C" {
void TBoss8Dragon__sub_80067074(Vec *pos, DragonAttackParams *params);
void TBoss8Dragon__sub_800670E0(Vec *pos, DragonAttackParams *params);
}

#endif
