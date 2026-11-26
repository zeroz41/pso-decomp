#ifndef PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H
#define PSO_UI_FRONTEND_TADSNAKPASSCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowBase;

struct TAdSnAkPassConfirmGC : public TAdYesNoBaseGC {
    TAdSnAkPassConfirmGC(TObject *parent);
    virtual ~TAdSnAkPassConfirmGC();
    virtual void on_yes_chosen();
    virtual void on_no_chosen();
    // The serial number and access key window shown above the question.
    TWindowBase *info_window;
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
