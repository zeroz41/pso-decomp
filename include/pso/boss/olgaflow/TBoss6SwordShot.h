#ifndef PSO_BOSS_OLGAFLOW_TBOSS6SWORDSHOT_H
#define PSO_BOSS_OLGAFLOW_TBOSS6SWORDSHOT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6SwordShot : public TObject {
public:
    virtual ~TBoss6SwordShot();
    virtual void run_task();
};

#endif
