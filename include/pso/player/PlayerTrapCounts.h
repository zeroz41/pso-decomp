#ifndef PSO_PLAYER_PLAYERTRAPCOUNTS_H
#define PSO_PLAYER_PLAYERTRAPCOUNTS_H

#include "types.h"

// A player's trap stock (s8 per trap kind, TObjPlayer::trap_counts) and the
// battle-rule counter after it (s32, 0..99).
extern "C" {
s32 decrement_clamped(s32 *value, s32 amount);
s32 fn_801C5404(s32 *value);
void fn_801C5420(s32 *value, s32 count);
bool fn_801C543C(s8 *counts, s32 kind);
void clear_trap_counts(s8 *counts);
s32 are_trap_counts_full(s8 *counts, s32 level, s8 char_class);
void TObjPlayer__sub_801C5780(s8 *counts, s8 count, s32 kind);
}

void refill_trap_counts(s8 *counts, s32 level, s32 char_class);
s8 calc_trap_capacity(s32 level, s8 char_class, s32 kind);

#endif
