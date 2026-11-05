#ifndef PSO_MISC_TPLAYERBATTLECTRL4P_8031012C_H
#define PSO_MISC_TPLAYERBATTLECTRL4P_8031012C_H

#include "types.h"

extern "C" {
s32 are_split_screen_battle_players_tied(void);
s32 calc_battle_score__19TPlayerBattleCtrl4PFPvPv(void *self, u8 *arg1);
s32 calculate_split_screen_battle_rankings(void *);
s32 *get_split_screen_battle_rankings(void);
}
s32 get_split_screen_battle_timer_limit(u8 *arg0);
extern "C" {
void record_split_screen_battle_results(void *);
}
void refresh_split_screen_battle_alive_flags(void *p);
void request_split_screen_battle_event(void *p);
extern "C" {
void send_code_45_to_window__19TPlayerBattleCtrl4PFPvii(void *arg0, s32 arg1, s32 arg2);
}

// --- C functions defined in TPlayerBattleCtrl4P_8031012C.cpp ---
extern "C" {
s32 are_split_screen_battle_players_tied(void);
s32 calc_battle_score__19TPlayerBattleCtrl4PFPvPv(void *self, u8 *arg1);
s32 calculate_split_screen_battle_rankings(void *);
s32 *get_split_screen_battle_rankings(void);
void record_split_screen_battle_results(void *);
}
// --- end of C functions

#endif
