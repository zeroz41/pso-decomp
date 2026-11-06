#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8002CC48_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8002CC48_H

#include "types.h"

extern "C" {
s32 TBoss8Dragon__sub_8002DAEC(void *arg0);
s32 TBoss8Dragon__sub_8002DB04(void *arg0);
u8 *TObjBoss1MokoHill_SoloM__ct(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
void *TObjBoss1MokoHill_Solo__ct(void *arg0_, void *arg1, int arg2);
void *destroy__12TBoss8DragonFPvs(void *arg0, s16 arg1);
s32 get_state__12TBoss8DragonFv(void);
}
s32 is_dragon_trail_damaging(u8 *arg0);
extern "C" {
f32 lerp__9TDeadSpotFff(f32 farg0, f32 farg1);
f32 rand_signed_unit(void);
}

#endif
