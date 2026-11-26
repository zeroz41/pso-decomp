#ifndef PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

class TAdScrollWinGC;

struct TAdTrialAgreementGC : public TAdAgreementBaseGC {
    static const char *name;
    TAdTrialAgreementGC(TObject *parent);
    virtual ~TAdTrialAgreementGC();
    virtual void on_closing();
    virtual void on_agree();
    virtual void on_decline();
    TAdScrollWinGC *scroll_window;
    virtual void render();
    void wait_for_load();
    virtual void run_task();
    s32 check_card_file();
};

LAYOUT_ASSERT(TAdTrialAgreementGC_size, sizeof(TAdTrialAgreementGC) == 0x3C);
#endif
