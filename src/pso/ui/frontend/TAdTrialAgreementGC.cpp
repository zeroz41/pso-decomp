#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdTrialAgreementGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdScrollWinGC_80327504.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_8033573C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_80335958.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#pragma readonly_strings on

struct Base_80335648 { char pad[0x18]; };
struct VObj_80335648 : Base_80335648 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
};

extern "C" {

s32 poll_memcard_result(s32);
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);

void TAdTrialAgreementGC::render() {
    struct VObj_80335648 *o = (struct VObj_80335648 *)this;
    o->m10();
}

void TAdTrialAgreementGC::vfunc_8() { request_main_phase((saddr)((void*)0)); }
void TAdTrialAgreementGC::vfunc_7() { request_scene_change__21TAdMultiChgGameModeGCFv(this); }
void TAdTrialAgreementGC::vfunc_6() { if (this->m_38 != 0) { ((TAdScrollWinGC *)(this->m_38))->close_window(); this->m_38 = 0; } }
void TAdTrialAgreementGC::wait_for_load() {
loop_1:
    if ((TAdPlayerLoadGC::probe_card_slot(0) != 0) && (poll_memcard_result(0) != 0)) {
        render_tick();
        goto loop_1;
    }
}

}

struct Base_803357EC_8033573C { char pad[0x18]; };
struct VObj_803357EC_8033573C : Base_803357EC_8033573C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

extern "C" {

s32 __nw__7TObjectFUl(int);
s32 TAdAgreementBaseGC__ct(void *);
extern s32 __vt__19TAdTrialAgreementGC[];
const char *TAdTrialAgreementGC__name = "TAdTrialAgreementGC";
s32 wait_for_load__19TAdTrialAgreementGCFv(s32);

extern s32 pso_system_card_filename[];

s32 TAdTrialAgreementGC::check_card_file(s32 arg0) {
    s32 card_file;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        return 0;
    }
    wait_for_load__19TAdTrialAgreementGCFv(arg0);
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 0;
    }
    wait_for_load__19TAdTrialAgreementGCFv(arg0);
    card_file = TAdPlayerLoadGC::find_card_file(0, (const char *)pso_system_card_filename);
    if ((card_file == 0) || ((card_file + 0x10000) == 0xFF41U)) {
        return 1;
    }
    return 0;
}

void TAdTrialAgreementGC::run_task() {
    struct VObj_803357EC_8033573C *o = (struct VObj_803357EC_8033573C *)this;
    o->m9();
}

}
TAdTrialAgreementGC::~TAdTrialAgreementGC() {

}

u8 *TAdTrialAgreementGC__ct(u8 *ad_trial_agreement_gc) {
    s32 ad_scroll_win_gc;
    s32 var_r0;
    TAdAgreementBaseGC__ct(ad_trial_agreement_gc);
    *(s32 **)((s8 *)ad_trial_agreement_gc + 0x18) = __vt__19TAdTrialAgreementGC;
    *(const char **)((s8 *)ad_trial_agreement_gc + 0) = TAdTrialAgreementGC__name;
    ((TAdTrialAgreementGC *)ad_trial_agreement_gc)->m_38 = 0;
    if (TAdTrialAgreementGC::check_card_file((saddr)ad_trial_agreement_gc) != 0) {
        ((TAdTrialAgreementGC *)(ad_trial_agreement_gc))->vfunc_7();
        ((TObject *)ad_trial_agreement_gc)->queue_destruction();
        return ad_trial_agreement_gc;
    }
    ad_scroll_win_gc = __nw__7TObjectFUl(0x54);
    var_r0 = ad_scroll_win_gc;
    if (var_r0 != 0) {
        var_r0 = (saddr)TAdScrollWinGC__ct((TAdScrollWinGC *)((void *)ad_scroll_win_gc), (ad_trial_agreement_gc), 1, 0);
    }
    ((TAdTrialAgreementGC *)ad_trial_agreement_gc)->m_38 = var_r0;
    return ad_trial_agreement_gc;
}
