#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BC53C_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BC53C_H

#include "types.h"

extern "C" {
u8 *__ct__17AreaAttackHistoryFl(u8 *arg0, s32 arg1);
s32 attack_target_history_add(s32 object, s32 target);
}
int attack_target_history_contains(void *object, void *target);
extern "C" {
s32 __dt__17AreaAttackHistoryFv(s32 arg0, s16 arg1);
s32 fn_800BC758(u8 *arg0);
u32 *__dt__13PointerBufferFv(u32 *arg0, s16 arg1);
}
s32 push_attack_target_entry(u8 *arg0, s32 arg1);

#endif
