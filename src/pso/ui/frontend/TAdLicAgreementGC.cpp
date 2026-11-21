#include "types.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdScrollWinGC_80327504.h"

#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

#pragma readonly_strings on

extern "C" {


void TAdLicAgreementGC::render() {
    check_main_task_state();
}

void TAdLicAgreementGC::vfunc_9() { TAdMultiChgGameModeGC::set_game_mode(); }
void TAdLicAgreementGC::vfunc_8() { TAdMultiChgGameModeGC::request_scene_change(); }
void TAdLicAgreementGC::vfunc_7() { ((TAdMultiChgGameModeGC *)this)->set_mode_1c(); }
void TAdLicAgreementGC::vfunc_6() { if (this->m_38 != 0) { ((TAdScrollWinGC *)(this->m_38))->close_window(); this->m_38 = 0; } }

void TAdLicAgreementGC::run_task() {
    update_state();
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

