#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdTitleGC.h"

#pragma readonly_strings on

s32 TAdPsoPassSaveGC__data_805D6E80;
extern "C" {

void TAdPsoPassSaveGC::render() {
    vfunc_12();
}

saddr TAdPsoPassSaveGC::vfunc_10() {
    return get_localized_text_entry(0x2A, 0);
}


void TAdPsoPassSaveGC::vfunc_7() {
    TAdPsoPassSaveGC__data_805D6E80 = 0;
    request_main_phase(0xF);
}

void TAdPsoPassSaveGC::vfunc_6() {
    TAdPsoPassSaveGC__data_805D6E80 = 1;
    request_main_phase(0xF);
}

void TAdPsoPassSaveGC::run_task() {
    vfunc_11();
}


TAdPsoPassSaveGC::~TAdPsoPassSaveGC() {

}

const char *TAdPsoPassSaveGC__name = "TAdPsoPassSaveGC";

TAdPsoPassSaveGC::TAdPsoPassSaveGC(TObject *parent) : TAdYesNoBaseGC(parent) {
    m_name = TAdPsoPassSaveGC__name;
    new TAdTitleGC(this, 18);
}

}
