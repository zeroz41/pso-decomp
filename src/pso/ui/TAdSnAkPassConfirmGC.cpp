#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSnAkPassConfirmGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/ui/TAdYesNoBaseGC.h"

struct Base_8032BE50_8032BE48 { char pad[0x18]; };
struct VObj_8032BE50_8032BE48 : Base_8032BE50_8032BE48 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
};
struct Base_8032BF64_8032BE48 { char pad[0x18]; };
struct VObj_8032BF64_8032BE48 : Base_8032BF64_8032BE48 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

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
    struct VObj_8032BE50_8032BE48 *o = (struct VObj_8032BE50_8032BE48 *)this;
    o->m10();
}

void TAdSnAkPassConfirmGC__vt8(void) { get_localized_text_entry((s32)((void*)39), (s32)((void*)0)); }
void TAdSnAkPassConfirmGC::vfunc_9() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::vfunc_8() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
int TAdSnAkPassConfirmGC__vt5(void* p) { return request_transition__21TAdMultiChgGameModeGCFv(p); }
int TAdSnAkPassConfirmGC__vt4(void* p) { return set_state_0x1a__21TAdMultiChgGameModeGCFv(p); }

void TAdSnAkPassConfirmGC::run_task() {
    struct VObj_8032BF64_8032BE48 *o = (struct VObj_8032BF64_8032BE48 *)this;
    o->m9();
}

void *__dt__20TAdSnAkPassConfirmGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TAdSnAkPassConfirmGC;
        if (*(void **)((s8 *)arg0 + 0x48) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x48)); ((TAdSnAkPassConfirmGC *)arg0)->m_48 = 0; }
        __dt__14TAdYesNoBaseGCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
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
