#ifndef PSO_ITEM_TITEMREVERSETECHBG_H
#define PSO_ITEM_TITEMREVERSETECHBG_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemReverseTechBG : public TObject {
public:
    virtual ~TItemReverseTechBG();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *__ct__18TItemReverseTechBGFv(void *arg0, void *arg1, void *arg3);
}

#endif
