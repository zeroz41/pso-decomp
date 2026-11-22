#ifndef PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H
#define PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdPsoPassSaveGC : public TAdYesNoBaseGC {
    TAdPsoPassSaveGC(TObject *parent);
    virtual ~TAdPsoPassSaveGC();
    virtual void render();
    virtual void run_task();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual saddr vfunc_10();
};

LAYOUT_ASSERT(TAdPsoPassSaveGC_size, sizeof(TAdPsoPassSaveGC) == 0x48);

extern s32 TAdPsoPassSaveGC__data_805D6E80;

#endif
