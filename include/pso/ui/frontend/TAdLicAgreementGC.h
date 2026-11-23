#ifndef PSO_UI_FRONTEND_TADLICAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADLICAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

class TAdScrollWinGC;

struct TAdLicAgreementGC : public TAdAgreementBaseGC {
    TAdLicAgreementGC(TObject *parent);
    virtual ~TAdLicAgreementGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    TAdScrollWinGC *scroll_window;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdLicAgreementGC_size, sizeof(TAdLicAgreementGC) == 0x3C);

extern "C" {
void *__dt__17TAdLicAgreementGCFv(void *arg0, s16 arg1);
}

// --- C functions defined in TAdLicAgreementGC.cpp ---
// --- end of C functions

#endif
