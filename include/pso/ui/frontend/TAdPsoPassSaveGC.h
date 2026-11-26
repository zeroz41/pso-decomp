#ifndef PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H
#define PSO_UI_FRONTEND_TADPSOPASSSAVEGC_H

#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdPsoPassSaveGC : public TAdYesNoBaseGC {
    static const char *name;
    TAdPsoPassSaveGC(TObject *parent);
    virtual ~TAdPsoPassSaveGC();
    virtual void render();
    virtual void run_task();
    virtual void on_accept();
    virtual void on_cancel();
    virtual saddr get_message_text();
};

LAYOUT_ASSERT(TAdPsoPassSaveGC_size, sizeof(TAdPsoPassSaveGC) == 0x48);

extern s32 pso_pass_save_accepted;

#endif
