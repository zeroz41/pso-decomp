#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE1ACTIONS_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE1ACTIONS_H

#include "types.h"
#include <dolphin/mtx.h>

struct TBoss6Type1;
void send_flow_action_if_idle(TBoss6Type1 *boss, s32 action);

#endif
