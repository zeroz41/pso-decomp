#ifndef PSO_TOBJBOSS2RAFTSPLASH_H
#define PSO_TOBJBOSS2RAFTSPLASH_H

#include "pso/TObject.h"
#include "types.h"

class TObjBoss2RaftSplash : public TObject {
public:
    virtual ~TObjBoss2RaftSplash();
    virtual void run_task();
public:
    static void spawn_splash(s32 arg0, s32 arg1, s32 arg2);
};

extern "C" {
u8 *TObjBoss2RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
}

#endif
