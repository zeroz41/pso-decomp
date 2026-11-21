#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EFFHYOUI_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EFFHYOUI_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6EffHyoui : public TObject {
public:
 void* m_1c;
    u8 pad_20[0xC];
public:
    TBoss6EffHyoui(TObject *parent, void *arg2, void *arg3, void *arg4);
    virtual ~TBoss6EffHyoui();
    virtual void run_task();
public:
    void *create(void *arg1, void *arg2);
};

#endif
