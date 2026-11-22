#ifndef PSO_BOSS_DARKFALZ_TBOSS4BISHI_H
#define PSO_BOSS_DARKFALZ_TBOSS4BISHI_H

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Zako.h"

// The minion TBoss4Type2::spawn_bishi_around_players spawns; it rises next to a
// player and charges in a straight line (TBoss4Zako.cpp).
struct TBoss4Bishi : public TBoss4Zako {
    TBoss4Bishi(TObject *parent, TBoss4ZakoSetData *set_data);
    virtual ~TBoss4Bishi();
    virtual void run_task();
    virtual void run_death_reaction();
    static TBoss4Bishi *create(TBoss4ZakoSetData *set_data);
    void enter_state_3();
    void update_rise_state();
    void vt1();
    void update_sink_state();
};
LAYOUT_ASSERT(TBoss4Bishi_size, sizeof(TBoss4Bishi) == 0x3C4);

#endif
