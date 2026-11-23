#ifndef PSO_OBJECT_TOBJMESBASE_H
#define PSO_OBJECT_TOBJMESBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TQuestThread;

struct TObjMesBase : public TObjCollidable {
    TObjMesBase(TObject *parent, ObjectSetData *placement);
    virtual ~TObjMesBase();
    virtual void vfunc_14();
    virtual void clear_ref_if_destroyed();
    virtual void debug_draw_label();
    virtual void interact(u16 client);
    virtual void run_task();
    TQuestThread *messageChild;
    s32 messagePhase;
    s32 messageLabel;
    s32 messageBank;
};
LAYOUT_ASSERT(TObjMesBaseSizeCheck, sizeof(TObjMesBase) == 0xBC);

#endif
