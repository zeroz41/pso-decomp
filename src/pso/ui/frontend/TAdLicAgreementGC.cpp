#include "types.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

#pragma readonly_strings on


void TAdLicAgreementGC::render() {
    check_main_task_state();
}

void TAdLicAgreementGC::on_cancel() { TAdMultiChgGameModeGC::open_single_ply_chr_select_scene(); }
void TAdLicAgreementGC::on_decline() { TAdMultiChgGameModeGC::open_time_set_scene(); }
void TAdLicAgreementGC::on_agree() { TAdMultiChgGameModeGC::open_ep3_exist_scene(); }
void TAdLicAgreementGC::on_closing() { if (scroll_window != NULL) { scroll_window->close_window(); scroll_window = NULL; } }

void TAdLicAgreementGC::run_task() {
    update_state();
}


TAdLicAgreementGC::~TAdLicAgreementGC() {

}


const char *TAdLicAgreementGC::name = "TAdLicAgreementGC";

TAdLicAgreementGC::TAdLicAgreementGC(TObject *parent) : TAdAgreementBaseGC(parent) {
    m_name = TAdLicAgreementGC::name;
    m_34 = 0;
    scroll_window = NULL;
    scroll_window = new TAdScrollWinGC(this, 0, 0);
}

