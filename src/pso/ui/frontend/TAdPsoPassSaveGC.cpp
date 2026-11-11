#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"

extern "C" {

void *TAdYesNoBaseGC__ct(TAdYesNoBaseGC *arg0);
void *__dt__14TAdYesNoBaseGCFv(void *arg0, s16 arg1);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TAdPsoPassSaveGC::render() {
    vfunc_12();
}

void TAdPsoPassSaveGC::vfunc_10() {
    get_localized_text_entry(0x2A, 0);
}

extern s32 TAdPsoPassSaveGC__data_805D6E80;

void TAdPsoPassSaveGC::vfunc_7() {
    TAdPsoPassSaveGC__data_805D6E80 = 0;
    TKeyBoardControl__sub_8000F9CC(0xF);
}

void TAdPsoPassSaveGC::vfunc_6() {
    TAdPsoPassSaveGC__data_805D6E80 = 1;
    TKeyBoardControl__sub_8000F9CC(0xF);
}

void TAdPsoPassSaveGC::run_task() {
    vfunc_11();
}

extern s32 __vt__16TAdPsoPassSaveGC[];

TAdPsoPassSaveGC::~TAdPsoPassSaveGC() {

}

extern void *lbl_805D4310;

void *TAdPsoPassSaveGC__ct(void *parent) {
    void *o;
    TAdYesNoBaseGC__ct((TAdYesNoBaseGC *)parent);
    *(s32 **)((s8 *)parent + 0x18) = __vt__16TAdPsoPassSaveGC;
    *(void * *)&((TAdPsoPassSaveGC *)parent)->m_name = lbl_805D4310;
    o = __nw__7TObjectFUl(0x138);
    if (o != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(o, parent, 18);
    }
    return parent;
}

}
