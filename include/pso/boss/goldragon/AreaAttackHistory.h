#ifndef PSO_BOSS_GOLDRAGON_AREAATTACKHISTORY_H
#define PSO_BOSS_GOLDRAGON_AREAATTACKHISTORY_H

#include "types.h"

class AreaAttackHistory;
class PointerBuffer;
class TObjChara;

s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target);
int attack_target_history_contains(void *object, void *target);
extern "C" {
}
s32 fn_800BC758(PointerBuffer *buffer);
s32 push_attack_target_entry(PointerBuffer *buffer, void *entry);

#endif
