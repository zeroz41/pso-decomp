#ifndef PSO_UNK_TUNK_804A7260_H
#define PSO_UNK_TUNK_804A7260_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerRef.h"

// Base of the lock-on cursor tasks TLOC_Start, TLOC_End and TLOC_ListClear. Its ctor
// takes the parent task and the lock-on target id, which goes into the target record.
class LockOnTask : public TObject {
public:
    LockOnTask(TObject *parent, u16 id);
    virtual ~LockOnTask();
    PlayerRef m_target;
};
LAYOUT_ASSERT(LockOnTask_size, sizeof(LockOnTask) == 0x24);

#endif
