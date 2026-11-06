#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSnAkPassConfirmGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"


struct Obj_8032C004 { s32 f0; u8 pad[0x14]; void *vt; u8 pad2[0x48 - 0x1C]; s32 f48; };

extern "C" {
void *__nw__7TObjectFUl(u32);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void *TAdYesNoBaseGC__ct(TAdYesNoBaseGC *arg0);
extern u8 lbl_804772C0[];
extern u8 lbl_804772C8[];
extern u8 lbl_804772D0[];
extern s32 __vt__20TAdSnAkPassConfirmGC[];
extern s32 lbl_805D41F0;
Obj_8032C004 *TAdSnAkPassConfirmGC__ct(Obj_8032C004 *arg0);
void *__dt__14TAdYesNoBaseGCFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
int request_transition__21TAdMultiChgGameModeGCFv(void*);
int set_state_0x1a__21TAdMultiChgGameModeGCFv(void*);

s32 TAdSnAkPassConfirmGC::get_confirm_state() { return this->m_1c; }

void TAdSnAkPassConfirmGC::render() {
    vfunc_12();
}

void TAdSnAkPassConfirmGC::vfunc_10() { get_localized_text_entry((s32)((void*)39), (s32)((void*)0)); }
void TAdSnAkPassConfirmGC::vfunc_9() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::vfunc_8() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::vfunc_7() { request_transition__21TAdMultiChgGameModeGCFv(this); }
void TAdSnAkPassConfirmGC::vfunc_6() { set_state_0x1a__21TAdMultiChgGameModeGCFv(this); }

void TAdSnAkPassConfirmGC::run_task() {
    vfunc_11();
}

TAdSnAkPassConfirmGC::~TAdSnAkPassConfirmGC() {
    if (m_48 != 0) {
        ((TObject *)m_48)->queue_destruction();
        m_48 = 0;
    }
}

Obj_8032C004 *TAdSnAkPassConfirmGC__ct(Obj_8032C004 *parent) {
    void *p;
    TAdYesNoBaseGC__ct((TAdYesNoBaseGC *)parent);
    parent->vt = ((u8 *)&__vt__20TAdSnAkPassConfirmGC);
    parent->f0 = lbl_805D41F0;
    p = __nw__7TObjectFUl(0x138);
    if (p != 0) {
        __ct__10TAdTitleGCFP7TObjectl(p, parent, 0x11);
    }
    parent->f48 = ((TWindowOptionCtrl *)lbl_804772C0)->create_serial_info_window(0);
    ((TAdYesNoBaseGC *)parent)->init_parts(lbl_804772C8, lbl_804772D0);
    return parent;
}

void TAdYesNoBaseGC::vfunc_12() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

}
