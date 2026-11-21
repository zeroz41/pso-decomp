#ifndef PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H
#define PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdSnAkPassConfirmGC : public TAdYesNoBaseGC {
    TAdSnAkPassConfirmGC(TObject *parent);
    virtual ~TAdSnAkPassConfirmGC();
    virtual void vfunc_8();
    virtual void vfunc_9();
    uaddr m_48;
    virtual void render();
    virtual void run_task();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual saddr vfunc_10();
};

LAYOUT_ASSERT(TAdSnAkPassConfirmGC_size, sizeof(TAdSnAkPassConfirmGC) == 0x4C);

extern "C" {
}

// --- C functions defined in TAdSnAkPassConfirmGC.cpp ---
extern "C" {
}
// --- end of C functions

#endif
