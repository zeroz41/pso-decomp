#ifndef PSO_UNK_TLOC_END_H
#define PSO_UNK_TLOC_END_H
#include "types.h"
#include "pso/unk/LockOnTask.h"

class TLOC_End : public LockOnTask {
public:
    TLOC_End(TObject *parent, u16 id);
    virtual ~TLOC_End();
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_End_size, sizeof(TLOC_End) == 0x24);

#endif
