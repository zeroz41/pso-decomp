#ifndef PSO_TECHNIQUE_TSLICERHISTORY_H
#define PSO_TECHNIQUE_TSLICERHISTORY_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TSlicerHistory : public TObject {
public:
    virtual ~TSlicerHistory();
    virtual void run_task();
    virtual void render();
};

extern "C" {
u8 *__ct__14TSlicerHistoryFv(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, s32 arg4);
}

#endif
