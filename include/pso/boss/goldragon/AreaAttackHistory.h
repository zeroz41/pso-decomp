#ifndef PSO_BOSS_GOLDRAGON_AREAATTACKHISTORY_H
#define PSO_BOSS_GOLDRAGON_AREAATTACKHISTORY_H

#include "types.h"

class AreaAttackHistory;
class PointerBuffer;
class TObjChara;

s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target);
int attack_target_history_contains(AreaAttackHistory *object, void *target);
s32 pointer_buffer_has_space(PointerBuffer *buffer);
s32 push_attack_target_entry(PointerBuffer *buffer, void *entry);

#endif
