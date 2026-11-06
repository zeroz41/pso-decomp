#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EMPTYWARP_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EMPTYWARP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss6EmptyWarp : public TObject {
    virtual ~TBoss6EmptyWarp();
    void render();
    void run_task();
    static void *create();
    void activate_warp();
    static void init_warp();
    u8 unk_1C[0x4];
};

typedef char TBoss6EmptyWarp_size[sizeof(TBoss6EmptyWarp) == 0x20 ? 1 : -1];
#endif
