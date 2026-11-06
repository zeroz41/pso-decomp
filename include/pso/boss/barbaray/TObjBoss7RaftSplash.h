#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss7RaftSplash : public TObject {
public:
    virtual ~TObjBoss7RaftSplash();
    virtual void run_task();
};

extern "C" {
u8 *TObjBoss7RaftSplash__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
}

#endif
