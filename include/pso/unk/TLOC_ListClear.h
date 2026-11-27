#ifndef PSO_UNK_TLOC_LISTCLEAR_H
#define PSO_UNK_TLOC_LISTCLEAR_H
#include "types.h"
#include "pso/unk/TUnk_804A7260.h"

// The table in this class's data is TLOC_ListClear's vtable, but it sits in the TU's user data ahead of the jump
// tables, where no CW-emitted vtable goes: a real class here (key function in or out of the defer_codegen
// off stretch, class defined in the .cpp, inline virtuals) always gets its vtable written after the jump
// tables with the other vtables. So the original spelled the table out, and the ctor (init_lockon) and dtor
// that store it are plain functions which call the LockOnTask ctor and dtor directly. The
// dtor passes flag 0, which only an implicit base-dtor call in a real dtor passes (an explicit
// LockOnTask::~LockOnTask() call passes -1).
class TLOC_ListClear : public LockOnTask {
public:
    virtual ~TLOC_ListClear();
    void *init_lockon(TObject *parent, u16 id);
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_ListClear_size, sizeof(TLOC_ListClear) == 0x24);

extern "C" {
void *__ct__10LockOnTaskFP7TObjectUs(void *self, TObject *parent, u16 id);
void *__dt__10LockOnTaskFv(void *self, s16 flags);
TLOC_ListClear *__dt__14TLOC_ListClearFv(TLOC_ListClear *task, s16 flags);
}

#endif
