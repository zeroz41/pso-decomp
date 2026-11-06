#ifndef PSO_BOSS_DARKFALZ_TBOSS4URO_H
#define PSO_BOSS_DARKFALZ_TBOSS4URO_H

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Zako.h"

struct TBoss4Uro : public TBoss4Zako {
    virtual ~TBoss4Uro();
    void run_task();
    s32 get_phase();
    static int get_instance_count();
};

#endif
