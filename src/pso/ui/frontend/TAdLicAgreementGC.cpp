#include "types.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdScrollWinGC_80327504.h"

#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

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


void TAdLicAgreementGC::render() {
    struct VObj_80329BB8 *o = (struct VObj_80329BB8 *)this;
    o->m10();
}

void TAdLicAgreementGC::vfunc_9() { TAdMultiChgGameModeGC::set_game_mode(); }
void TAdLicAgreementGC::vfunc_8() { TAdMultiChgGameModeGC::request_scene_change(); }
void TAdLicAgreementGC::vfunc_7() { ((TAdMultiChgGameModeGC *)this)->set_mode_1c(); }
void TAdLicAgreementGC::vfunc_6() { if (this->m_38 != 0) { ((TAdScrollWinGC *)(this->m_38))->close_window(); this->m_38 = 0; } }

void TAdLicAgreementGC::run_task() {
    struct VObj_80329C84_80329BB8 *o = (struct VObj_80329C84_80329BB8 *)this;
    o->m9();
}


}
TAdLicAgreementGC::~TAdLicAgreementGC() {

}


const char *TAdLicAgreementGC__name = "TAdLicAgreementGC";

TAdLicAgreementGC::TAdLicAgreementGC(TObject *parent) : TAdAgreementBaseGC(parent) {
    void *o;
    m_name = TAdLicAgreementGC__name;
    m_34 = 0;
    m_38 = 0;
    o = TObject::operator new(0x54);
    if (o != NULL) {
        o = TAdScrollWinGC__ct((TAdScrollWinGC *)o, this, 0, 0);
    }
    *(void **)((s8 *)this + 0x38) = o;
}

