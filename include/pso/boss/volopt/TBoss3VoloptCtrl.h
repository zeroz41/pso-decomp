#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTCTRL_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss3VoloptCtrl : public TObject {
public:
    TBoss3VoloptCtrl();
    virtual ~TBoss3VoloptCtrl();
    virtual void run_task();
    static void dispatch_state(s32 state);

    s32 countdown;
    s32 phase;
};

typedef char TBoss3VoloptCtrl_size[sizeof(TBoss3VoloptCtrl) == 0x24 ? 1 : -1];

#endif
