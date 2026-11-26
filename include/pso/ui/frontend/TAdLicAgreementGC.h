#ifndef PSO_UI_FRONTEND_TADLICAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADLICAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

class TAdScrollWinGC;

struct TAdLicAgreementGC : public TAdAgreementBaseGC {
    static const char *name;
    TAdLicAgreementGC(TObject *parent);
    virtual ~TAdLicAgreementGC();
    virtual void on_closing();
    virtual void on_agree();
    virtual void on_decline();
    virtual void on_cancel();
    TAdScrollWinGC *scroll_window;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdLicAgreementGC_size, sizeof(TAdLicAgreementGC) == 0x3C);



#endif
