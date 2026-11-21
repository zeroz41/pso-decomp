#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss7RaftSplash : public TObject {
public:
    TObjBoss7RaftSplash(TObject *parent, u8 *arg2, u8 *arg3, s32 arg4);
    virtual ~TObjBoss7RaftSplash();
    virtual void run_task();

    u8 pad_1C[0x40 - 0x1C];
};

#endif
