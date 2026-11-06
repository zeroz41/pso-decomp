#ifndef PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H
#define PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

struct TAdExNetConfirmGC : public TAdWarningBaseGC {
    virtual ~TAdExNetConfirmGC();
    virtual void vfunc_7();
    virtual int vfunc_6();
    static s32 is_confirmed();
    virtual void render();
    virtual void run_task();
};

typedef char TAdExNetConfirmGC_size[sizeof(TAdExNetConfirmGC) == 0x30 ? 1 : -1];
#endif
