#ifndef PSO_TITEMREVERSETECHCTRL_H
#define PSO_TITEMREVERSETECHCTRL_H
#include "pso/TObject.h"
#include "types.h"

class TItemReverseTechCtrl : public TObject {
public:
    TItemReverseTechCtrl(TObject *parent);
    virtual ~TItemReverseTechCtrl();
    virtual void run_task();
    s32 key_progress[3];

    static TItemReverseTechCtrl *create(TObject *parent);
};

typedef char TItemReverseTechCtrl_size[sizeof(TItemReverseTechCtrl) == 0x28 ? 1 : -1];

#endif
