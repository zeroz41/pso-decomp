#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;
class TObjBoss5PillarCtrl;

// Gal Gryphon attack hits on the arena: the grass and stone floors, and the pillars (boss5_ctrl_instance).
extern "C" {
void TBoss8Dragon__sub_80067074(const Vec *pos, const DragonAttackParams *params);
void TBoss8Dragon__sub_800670E0(const Vec *pos, const DragonAttackParams *params);
void TBoss8Dragon__sub_8028B0DC(TObjBoss5PillarCtrl *pillar_controller, const Vec *pos, const DragonAttackParams *params);
}

#endif
