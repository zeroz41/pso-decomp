#include "types.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/unk/text_8007FA24.h"
#include "pso/unk/text_80145A94.h"

#include "pso/unk/TLobby.h"

struct Base_80335508_803354A4 { char pad[0x18]; };
struct VObj_80335508_803354A4 : Base_80335508_803354A4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_80335580_803354A4 { char pad[0x18]; };
struct VObj_80335580_803354A4 : Base_80335580_803354A4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

extern "C" {

int TKeyBoardControl__sub_8000F9CC(void*);

void TAdTrialModemChkGC__sub_803354A4(void) {  }
void TAdTrialModemChkGC::check_modem_result() {
    if (TLobby__sub_80145A94() != 0) {
        TLobby::init_account_entries();
        TAdTrialModemChkGC__sub_8007FA24(0);
        return;
    }
    TAdTrialModemChkGC__sub_8007FA24(1);
}
void TAdTrialModemChkGC__sub_803354E8(void) { TLobby::stop_audio_streams(); }

void TAdTrialModemChkGC::render() {
    struct VObj_80335508_803354A4 *o = (struct VObj_80335508_803354A4 *)this;
    o->m7();
}

void TAdTrialModemChkGC::vfunc_7() { get_localized_text_entry((s32)((void*)35), (s32)((void*)0)); }
int TAdTrialModemChkGC::vfunc_6() { return TKeyBoardControl__sub_8000F9CC((void*)(0)); }

void TAdTrialModemChkGC::run_task() {
    struct VObj_80335580_803354A4 *o = (struct VObj_80335580_803354A4 *)this;
    o->m6();
}

extern s32 __vt__18TAdTrialModemChkGC[];

}
TAdTrialModemChkGC::~TAdTrialModemChkGC() {

}


extern void *TAdTrialModemChkGC__name;

void *TAdTrialModemChkGC__ct(void *ad_trial_modem_chk_gc) {
    TAdWarningBaseGC__ct((TAdWarningBaseGC *)ad_trial_modem_chk_gc);
    *(s32 **)((s8 *)ad_trial_modem_chk_gc + 0x18) = __vt__18TAdTrialModemChkGC;
    *(void * *)&((TAdTrialModemChkGC *)ad_trial_modem_chk_gc)->m_name = TAdTrialModemChkGC__name;
    return ad_trial_modem_chk_gc;
}

