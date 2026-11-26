#include "types.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/network/NetworkConnect.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/SwitcherLaunch.h"
#include "pso/unk/text_80145A94.h"

#include "pso/network/TLobby.h"
#include "pso/ui/keyboard/SystemBootInit.h"

#pragma readonly_strings on


void TAdTrialModemChkGC::exit_modem_check_phase() {  }
void TAdTrialModemChkGC::check_modem_result() {
    if (load_network_info() != 0) {
        init_account_entries();
        TAdTrialModemChkGC__sub_8007FA24(0);
        return;
    }
    TAdTrialModemChkGC__sub_8007FA24(1);
}
void TAdTrialModemChkGC::init_modem_check_phase() { TLobby::stop_audio_streams(); }

void TAdTrialModemChkGC::render() {
    render_dialog();
}

const char *TAdTrialModemChkGC::get_message_text() { return get_localized_text_entry(35, 0); }
void TAdTrialModemChkGC::on_close() { request_main_phase(0); }

void TAdTrialModemChkGC::run_task() {
    update_state();
}


TAdTrialModemChkGC::~TAdTrialModemChkGC() {

}


const char *TAdTrialModemChkGC::name = "TAdTrialModemChkGC";

TAdTrialModemChkGC::TAdTrialModemChkGC(TObject *parent) : TAdWarningBaseGC(parent) {
    m_name = TAdTrialModemChkGC::name;
}

