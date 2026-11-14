#ifndef PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H
#define PSO_UI_FRONTEND_TADTRIALMODEMCHKGC_H

#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

struct TAdTrialModemChkGC : public TAdWarningBaseGC {
    virtual ~TAdTrialModemChkGC();
    virtual void vfunc_7();
    virtual int vfunc_6();
    static void check_modem_result();
    virtual void render();
    virtual void run_task();
    static s32 init_modem_check_params();
};

typedef char TAdTrialModemChkGC_size[sizeof(TAdTrialModemChkGC) == 0x30 ? 1 : -1];

extern "C" {
void *TAdTrialModemChkGC__ct(void *arg0);
void TAdTrialModemChkGC__sub_803354A4(void);
void TAdTrialModemChkGC__sub_803354E8(void);
void *__dt__18TAdTrialModemChkGCFv(void *arg0, s16 arg1);
}

// --- C functions defined in TAdTrialModemChkGC.cpp ---
extern "C" {
void *TAdTrialModemChkGC__ct(void *ad_trial_modem_chk_gc);
void TAdTrialModemChkGC__sub_803354A4(void);
void TAdTrialModemChkGC__sub_803354E8(void);
}
// --- end of C functions

#endif
