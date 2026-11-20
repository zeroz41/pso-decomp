#ifndef PSO_UI_FRONTEND_TADLICAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADLICAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

struct TAdLicAgreementGC : public TAdAgreementBaseGC {
    virtual ~TAdLicAgreementGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    uaddr m_38;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdLicAgreementGC_size, sizeof(TAdLicAgreementGC) == 0x3C);

extern "C" {
void *TAdLicAgreementGC__ct(void *arg0);
void *__dt__17TAdLicAgreementGCFv(void *arg0, s16 arg1);
}

// --- C functions defined in TAdLicAgreementGC.cpp ---
extern "C" {
void *TAdLicAgreementGC__ct(void *ad_lic_agreement_gc);
}
// --- end of C functions

#endif
