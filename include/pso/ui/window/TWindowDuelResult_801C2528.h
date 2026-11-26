#ifndef PSO_UI_WINDOW_TWINDOWDUELRESULT_801C2528_H
#define PSO_UI_WINDOW_TWINDOWDUELRESULT_801C2528_H

#include "types.h"
#include "pso/player/BattleRanking.h"

// The rankings of the running battle: the split-screen table offline, the network duel table online.
BattleRanking *get_battle_rankings(void);

void show_duel_result_window(saddr gain, saddr duration);

class TBattleMusicGainTask;
// The battle music gain task show_duel_result_window runs; its dtor and clear_duel_result_window clear it.
extern TBattleMusicGainTask *duel_result_window;
void clear_duel_result_window();

#endif
