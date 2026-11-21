#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE2BATTLEACTION_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE2BATTLEACTION_H

#include <stddef.h>
#include "types.h"

struct TBoss6Type2;
typedef void (TBoss6Type2::*TBoss6Type2BattleHandler)();

struct TBoss6Type2BattleAction {
    const char *name;
    s32 motion;
    s32 flags;
    TBoss6Type2BattleHandler enter;
    TBoss6Type2BattleHandler idle;
    TBoss6Type2BattleHandler update;
};

LAYOUT_ASSERT(TBoss6Type2BattleActionSize, sizeof(TBoss6Type2BattleAction) == 0x30);
LAYOUT_ASSERT(TBoss6Type2BattleActionEnterOffset, offsetof(TBoss6Type2BattleAction, enter) == 0xC);
LAYOUT_ASSERT(TBoss6Type2BattleActionIdleOffset, offsetof(TBoss6Type2BattleAction, idle) == 0x18);
LAYOUT_ASSERT(TBoss6Type2BattleActionUpdateOffset, offsetof(TBoss6Type2BattleAction, update) == 0x24);

extern TBoss6Type2BattleAction boss6_type2_battle_actions[36];

#endif
