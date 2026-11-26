#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdTitleGC.h"

#pragma readonly_strings on

s32 pso_pass_save_accepted;

void TAdPsoPassSaveGC::render() {
    render_dialog();
}

const char *TAdPsoPassSaveGC::get_message_text() {
    return get_localized_text_entry(0x2A, 0);
}


void TAdPsoPassSaveGC::on_cancel() {
    pso_pass_save_accepted = 0;
    request_main_phase(0xF);
}

void TAdPsoPassSaveGC::on_accept() {
    pso_pass_save_accepted = 1;
    request_main_phase(0xF);
}

void TAdPsoPassSaveGC::run_task() {
    run_dialog();
}


TAdPsoPassSaveGC::~TAdPsoPassSaveGC() {

}

const char *TAdPsoPassSaveGC::name = "TAdPsoPassSaveGC";

TAdPsoPassSaveGC::TAdPsoPassSaveGC(TObject *parent) : TAdYesNoBaseGC(parent) {
    m_name = TAdPsoPassSaveGC::name;
    new TAdTitleGC(this, 18);
}

