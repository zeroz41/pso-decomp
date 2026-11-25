#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BC53C_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BC53C_H

#include "types.h"

class AreaAttackHistory;
class PointerBuffer;
class TObjChara;

s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target);
int attack_target_history_contains(void *object, void *target);
extern "C" {
u32 *__dt__13PointerBufferFv(u32 *arg0, s16 arg1);
}
s32 fn_800BC758(PointerBuffer *buffer);
s32 push_attack_target_entry(PointerBuffer *buffer, void *entry);

#endif
