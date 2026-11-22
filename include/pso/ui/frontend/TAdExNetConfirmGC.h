#ifndef PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H
#define PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

struct TAdExNetConfirmGC : public TAdWarningBaseGC {
    TAdExNetConfirmGC(TObject *parent);
    virtual ~TAdExNetConfirmGC();
    virtual saddr vfunc_7();
    virtual void vfunc_6();
    static s32 is_confirmed();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdExNetConfirmGC_size, sizeof(TAdExNetConfirmGC) == 0x30);
#endif
