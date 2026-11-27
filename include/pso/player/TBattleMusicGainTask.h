#ifndef PSO_PLAYER_TBATTLEMUSICGAINTASK_H
#define PSO_PLAYER_TBATTLEMUSICGAINTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/player/BattleRanking.h"

class TBattleMusicGainTask : public TObject {
public:
    TBattleMusicGainTask(TObject *parent, s32 gain, s32 duration);
    virtual ~TBattleMusicGainTask();
    virtual void run_task();
    s32 countdown;
    s32 gain_offset;
};
LAYOUT_ASSERT(TBattleMusicGainTask_size, sizeof(TBattleMusicGainTask) == 0x24);

extern "C" TBattleMusicGainTask *battle_music_gain_task;

// The rankings of the running battle: the split-screen table offline, the network duel table online.
BattleRanking *get_battle_rankings(void);

void show_duel_result_window(saddr gain, saddr duration);

// The battle music gain task show_duel_result_window runs; its dtor and clear_duel_result_window clear it.
extern TBattleMusicGainTask *duel_result_window;
void clear_duel_result_window();

#endif
