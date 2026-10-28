#ifndef PSO_OBJECT_TOBJMESBASE_H
#define PSO_OBJECT_TOBJMESBASE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjMesBase : public TObjCollidable {
    virtual ~TObjMesBase();
    virtual void vfunc_14();
    virtual void clear_ref_if_destroyed();
    virtual void debug_draw_label();
    virtual void interact(s32 client);
    virtual void run_task();
    void* messageChild;
    s32 messagePhase;
    s32 messageLabel;
    s32 messageBank;
};
typedef char TObjMesBaseSizeCheck[sizeof(TObjMesBase) == 0xBC ? 1 : -1];

#endif
