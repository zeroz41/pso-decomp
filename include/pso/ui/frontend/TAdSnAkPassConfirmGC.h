#ifndef PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H
#define PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/ui/window/TWindowBase.h"

struct TAdSnAkPassConfirmGC : public TAdYesNoBaseGC {
    TAdSnAkPassConfirmGC(TObject *parent);
    virtual ~TAdSnAkPassConfirmGC();
    virtual void on_yes_chosen();
    virtual void on_no_chosen();
    TWindowBase *info_window;  // the serial info window, closed when the choice is made
    virtual void render();
    virtual void run_task();
    virtual void on_accept();
    virtual void on_cancel();
    virtual saddr get_message_text();
};

LAYOUT_ASSERT(TAdSnAkPassConfirmGC_size, sizeof(TAdSnAkPassConfirmGC) == 0x4C);


// --- C functions defined in TAdSnAkPassConfirmGC.cpp ---
// --- end of C functions

#endif
