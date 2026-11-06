#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BB650_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_800BB650_H

#include "types.h"

extern "C" {
void TBoss8Dragon__sub_800BB650(void *p, void *q);
void TBoss8Dragon__sub_800BB7D4(void);
void TBoss8Dragon__sub_800BB7D8(void);
void TBoss8Dragon__sub_800BB7DC(void);
u16 enemy_find_nearest_player_in_range(u8 *self, f32 range);
}
u16 enemy_nearest_visible_player_sq(u8 *arg0, f32 farg0);

// --- C functions defined in TBoss8Dragon_800BB650.cpp ---
extern "C" {
void TBoss8Dragon__sub_800BB650(void *p, void *q);
void TBoss8Dragon__sub_800BB7D4(void);
void TBoss8Dragon__sub_800BB7D8(void);
void TBoss8Dragon__sub_800BB7DC(void);
u16 enemy_find_nearest_player_in_range(u8 *self, f32 range);
}
// --- end of C functions

#endif
