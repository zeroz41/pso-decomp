#ifndef PSO_UI_TADSNAKPASSCONFIRMGC_H
#define PSO_UI_TADSNAKPASSCONFIRMGC_H

#include "types.h"
#include "pso/ui/TAdYesNoBaseGC.h"

struct TAdSnAkPassConfirmGC : public TAdYesNoBaseGC {
    virtual ~TAdSnAkPassConfirmGC();
    virtual void vfunc_8();
    virtual void vfunc_9();
    u32 m_48;
    s32 get_confirm_state();
    virtual void render();
    virtual void run_task();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_10();
};

typedef char TAdSnAkPassConfirmGC_size[sizeof(TAdSnAkPassConfirmGC) == 0x4C ? 1 : -1];

extern "C" {
}

// --- C functions defined in TAdSnAkPassConfirmGC.cpp ---
extern "C" {
}
// --- end of C functions

#endif
