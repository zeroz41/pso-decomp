#ifndef PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H
#define PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdPsoPassSaveGC : public TAdYesNoBaseGC {
    virtual ~TAdPsoPassSaveGC();
    virtual void render();
    virtual void run_task();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_10();
};

typedef char TAdPsoPassSaveGC_size[sizeof(TAdPsoPassSaveGC) == 0x48 ? 1 : -1];

extern "C" {
void *TAdPsoPassSaveGC__ct(void *parent);
}

// --- C functions defined in TAdPsoPassSaveGC.cpp ---
extern "C" {
void *TAdPsoPassSaveGC__ct(void *parent);
}
// --- end of C functions

#endif
