#ifndef PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

class TAdScrollWinGC;

struct TAdTrialAgreementGC : public TAdAgreementBaseGC {
    TAdTrialAgreementGC(TObject *parent);
    virtual ~TAdTrialAgreementGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    TAdScrollWinGC *scroll_window;
    virtual void render();
    void wait_for_load();
    virtual void run_task();
    static s32 check_card_file(saddr arg0);
};

LAYOUT_ASSERT(TAdTrialAgreementGC_size, sizeof(TAdTrialAgreementGC) == 0x3C);
#endif
