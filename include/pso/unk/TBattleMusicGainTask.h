#ifndef PSO_UNK_TBATTLEMUSICGAINTASK_H
#define PSO_UNK_TBATTLEMUSICGAINTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"

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

#endif
