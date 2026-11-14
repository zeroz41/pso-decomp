#include "types.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdScrollWinGC_80327504.h"

#include "pso/ui/frontend/TAdScrollWinGC.h"

#pragma readonly_strings on

struct Base_80329BB8 { char pad[0x18]; };
struct VObj_80329BB8 : Base_80329BB8 {
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
struct Base_80329C84_80329BB8 { char pad[0x18]; };
struct VObj_80329C84_80329BB8 : Base_80329C84_80329BB8 {
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

void TAdAgreementBaseGC__ct(void *);
void *__nw__7TObjectFUl(int);
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);
int set_game_mode__21TAdMultiChgGameModeGCFv(void*);
int set_mode_1c__21TAdMultiChgGameModeGCFv(void*);

void TAdLicAgreementGC::render() {
    struct VObj_80329BB8 *o = (struct VObj_80329BB8 *)this;
    o->m10();
}

void TAdLicAgreementGC::vfunc_9() { set_game_mode__21TAdMultiChgGameModeGCFv(this); }
void TAdLicAgreementGC::vfunc_8() { request_scene_change__21TAdMultiChgGameModeGCFv(this); }
void TAdLicAgreementGC::vfunc_7() { set_mode_1c__21TAdMultiChgGameModeGCFv(this); }
void TAdLicAgreementGC::vfunc_6() { if (this->m_38 != 0) { ((TAdScrollWinGC *)(this->m_38))->close_window(); this->m_38 = 0; } }

void TAdLicAgreementGC::run_task() {
    struct VObj_80329C84_80329BB8 *o = (struct VObj_80329C84_80329BB8 *)this;
    o->m9();
}

extern s32 __vt__17TAdLicAgreementGC[];

}
TAdLicAgreementGC::~TAdLicAgreementGC() {

}


const char *lbl_805D41C0 = "TAdLicAgreementGC";

void *TAdLicAgreementGC__ct(void *ad_lic_agreement_gc) {
    void *o;
    TAdAgreementBaseGC__ct(ad_lic_agreement_gc);
    *(s32 **)((s8 *)ad_lic_agreement_gc + 0x18) = __vt__17TAdLicAgreementGC;
    ((TAdLicAgreementGC *)ad_lic_agreement_gc)->m_name = lbl_805D41C0;
    ((TAdLicAgreementGC *)ad_lic_agreement_gc)->m_34 = 0;
    ((TAdLicAgreementGC *)ad_lic_agreement_gc)->m_38 = 0;
    o = __nw__7TObjectFUl(0x54);
    if (o != NULL) {
        o = TAdScrollWinGC__ct((TAdScrollWinGC *)o, ad_lic_agreement_gc, 0, 0);
    }
    *(void **)((s8 *)ad_lic_agreement_gc + 0x38) = o;
    return ad_lic_agreement_gc;
}

