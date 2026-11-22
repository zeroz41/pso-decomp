#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EMPTYWARP_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EMPTYWARP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss6EmptyWarp : public TObject {
    TBoss6EmptyWarp(TObject *parent);
    virtual ~TBoss6EmptyWarp();
    void render();
    void run_task();
    static void *create();
    static void init_warp();
    s32 warp_delay;  // run_task calls init_warp once it passes 3
};

LAYOUT_ASSERT(TBoss6EmptyWarp_size, sizeof(TBoss6EmptyWarp) == 0x20);
#endif
