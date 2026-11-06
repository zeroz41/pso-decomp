#ifndef PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H
#define PSO_BOSS_OLGAFLOW_TBOSS6CRUSHROCK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6CrushRock : public TObject {
public:
    virtual ~TBoss6CrushRock();
    virtual void run_task();
    virtual void render();
public:
    static s32 is_falz_alive();
};

extern "C" {
u8 *__ct__15TBoss6CrushRockFv(u8 *object, s32 arg1, s32 arg2, s32 arg3);
}

#endif
