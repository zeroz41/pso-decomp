#ifndef PSO_BOSS_TBOSS3VOLOPTMUSICTRIGGER_H
#define PSO_BOSS_TBOSS3VOLOPTMUSICTRIGGER_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss3VoloptMusicTrigger : public TObject {
public:
    TBoss3VoloptMusicTrigger();
    virtual ~TBoss3VoloptMusicTrigger();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss3VoloptMusicTrigger_size, sizeof(TBoss3VoloptMusicTrigger) == 0x1C);

#endif
