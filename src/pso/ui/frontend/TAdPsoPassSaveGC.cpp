#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

s32 TAdPsoPassSaveGC__data_805D6E80;
extern "C" {

void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);

void TAdPsoPassSaveGC::render() {
    vfunc_12();
}

void TAdPsoPassSaveGC::vfunc_10() {
    get_localized_text_entry(0x2A, 0);
}

extern s32 TAdPsoPassSaveGC__data_805D6E80;

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

const char *lbl_805D4310 = "TAdPsoPassSaveGC";

TAdPsoPassSaveGC::TAdPsoPassSaveGC(TObject *parent) : TAdYesNoBaseGC(parent) {
    void *o;
    m_name = lbl_805D4310;
    o = TObject::operator new(0x138);
    if (o != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(o, this, 18);
    }
}

}
