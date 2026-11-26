#ifndef PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H
#define PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

struct TAdTrialModemChkGC : public TAdWarningBaseGC {
    static const char *name;
    TAdTrialModemChkGC(TObject *parent);
    virtual ~TAdTrialModemChkGC();
    virtual saddr get_message_text();
    virtual void on_close();
    static void init_modem_check_phase();
    static void check_modem_result();
    static void exit_modem_check_phase();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdTrialModemChkGC_size, sizeof(TAdTrialModemChkGC) == 0x30);


#endif
