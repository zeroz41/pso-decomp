#ifndef PSO_UI_HUD_TLOC_LISTCLEAR_H
#define PSO_UI_HUD_TLOC_LISTCLEAR_H
#include "types.h"
#include "pso/ui/hud/LockOnTask.h"

// TLOC_ListClear's vtable sits in the TU's user data ahead of the jump
// tables, where no CW-emitted vtable goes: a real class here (key function in or out of the defer_codegen
// off stretch, class defined in the .cpp, inline virtuals) always gets its vtable written after the jump
// tables with the other vtables. So the original spelled the table out, and the ctor (init_lockon) and dtor
// that store it are plain functions which call the LockOnTask ctor and dtor directly. The
// dtor passes flag 0, which only an implicit base-dtor call in a real dtor passes (an explicit
// LockOnTask::~LockOnTask() call passes -1). Other compilers build the class with a real ctor and dtor.
class TLOC_ListClear : public LockOnTask {
public:
    virtual ~TLOC_ListClear();
#ifdef __MWERKS__
    // CodeWarrior: the constructor, which stores the hand-written table.
    void *init_lockon(TObject *parent, u16 id);
#else
    TLOC_ListClear(TObject *parent, u16 id);
#endif
    virtual void run_task();
};
LAYOUT_ASSERT(TLOC_ListClear_size, sizeof(TLOC_ListClear) == 0x24);

#ifdef __MWERKS__
extern "C" {
void *__ct__10LockOnTaskFP7TObjectUs(void *self, TObject *parent, u16 id);
void *__dt__10LockOnTaskFv(void *self, s16 flags);
TLOC_ListClear *__dt__14TLOC_ListClearFv(TLOC_ListClear *task, s16 flags);
}
#endif

#endif
