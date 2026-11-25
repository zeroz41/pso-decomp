#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80067034_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;
class TObjBoss5PillarCtrl;

// Gal Gryphon attack hits on the arena: the grass and stone floors, and the pillars (boss5_ctrl_instance).
extern "C" {
void boss5_attack_floor_in_range(const Vec *pos, const DragonAttackParams *params);
void boss5_attack_pillars_in_range(const Vec *pos, const DragonAttackParams *params);
void trigger_pillars_in_range(TObjBoss5PillarCtrl *pillar_controller, const Vec *pos, const DragonAttackParams *params);
}

#endif
