#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdTitleGC.h"

#pragma readonly_strings on

s32 TAdPsoPassSaveGC__data_805D6E80;

void TAdPsoPassSaveGC::render() {
    render_dialog();
}

saddr TAdPsoPassSaveGC::get_message_text() {
    return get_localized_text_entry(0x2A, 0);
}


void TAdPsoPassSaveGC::on_cancel() {
    TAdPsoPassSaveGC__data_805D6E80 = 0;
    request_main_phase(0xF);
}

void TAdPsoPassSaveGC::on_accept() {
    TAdPsoPassSaveGC__data_805D6E80 = 1;
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

