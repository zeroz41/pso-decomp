#include "types.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

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
void TAdLicAgreementGC::vfunc_6() { if (scroll_window != NULL) { scroll_window->close_window(); scroll_window = NULL; } }

void TAdLicAgreementGC::run_task() {
    update_state();
}


}
TAdLicAgreementGC::~TAdLicAgreementGC() {

}


const char *TAdLicAgreementGC__name = "TAdLicAgreementGC";

TAdLicAgreementGC::TAdLicAgreementGC(TObject *parent) : TAdAgreementBaseGC(parent) {
    m_name = TAdLicAgreementGC__name;
    m_34 = 0;
    scroll_window = NULL;
    scroll_window = new TAdScrollWinGC(this, 0, 0);
}

