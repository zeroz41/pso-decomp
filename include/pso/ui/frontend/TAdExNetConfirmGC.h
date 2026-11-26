#ifndef PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H
#define PSO_UI_FRONTEND_TADEXNETCONFIRMGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

struct TAdExNetConfirmGC : public TAdWarningBaseGC {
    TAdExNetConfirmGC(TObject *parent);
    virtual ~TAdExNetConfirmGC();
    virtual saddr get_message_text();
    virtual void on_close();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdExNetConfirmGC_size, sizeof(TAdExNetConfirmGC) == 0x30);
#endif
