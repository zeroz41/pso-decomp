#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdWarningBaseGC.h"
#include "pso/TMainTask.h"

struct B_8032D214 { u8 pad[0x18]; };

struct V_8032D214 : B_8032D214 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void *m5();
};

extern "C" {
void append_line__14TWindowMessageFii(s32, void *, int);
s32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
extern u8 lbl_80477334[];
extern u8 lbl_8047733C[];
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
void play_sound_effect(int, int, int, int);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
extern const f32 lbl_805DF7B0;
void *__ct__12TAdBackTxtGCFv(void *, void *);
void __ct__7TObjectFP7TObject(void *);
void *__ct__9TAdBackGCFv(void *, void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);

    extern int aram_request_busy_flag;
void clear_aram_request_busy(void) { aram_request_busy_flag = 0; }

extern s32 __vt__16TAdWarningBaseGC[];

void TAdWarningBaseGC::vfunc_9() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

s32 TAdWarningBaseGC::sub_8032D214() {
    V_8032D214 *arg0 = (V_8032D214 *)this;
    s32 r = update_window_mode_from_progress__6TLobbyFPv(lbl_80477334, lbl_8047733C);
    append_line__14TWindowMessageFii(r, arg0->m5(), 3);
    return r;
}

void TAdWarningBaseGC::vfunc_8() {
    u8 *arg0 = (u8 *)this;
    u8 *a;
    u8 *b;
    *(s32 *)&this->m_20 = *(s32 *)&this->m_1c;
    switch (*(s32 *)&this->m_1c) {
    case 0:
        *(s32 *)&this->m_2c = ((TAdWarningBaseGC *)arg0)->sub_8032D214();
        *(s32 *)&this->m_1c = 1;
        break;
    case 1:
        play_sound_effect(0x53F06, 0, 0, 0);
        *(s32 *)&this->m_1c = 2;
        break;
    case 2:
        if (TWindowShortListCtrl__check_controller_button(a = controller_physical_port_bank + 0x20, 4) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(b = controller_input_state + 0x160, 4) != 0 ||
            TWindowShortListCtrl__check_controller_button(a, 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(b, 2) != 0) {
            *(s32 *)&this->m_1c = 3;
            *(s32 *)&this->m_24 = 4;
        }
        break;
    case 3:
        if (*(void * *)&this->m_2c != NULL) {
            ((TWindowBase *)(*(void * *)&this->m_2c))->close();
            *(void * *)&this->m_2c = NULL;
        }
        if ((f32)++*(s32 *)&this->m_28 > lbl_805DF7B0) {
            *(s32 *)&this->m_1c = *(s32 *)&this->m_24;
        }
        break;
    case 4:
        this->vfunc_6();
        break;
    }
    if (*(s32 *)&this->m_20 != *(s32 *)&this->m_1c) {
        *(s32 *)&this->m_28 = 0;
    }
}

void *__dt__16TAdWarningBaseGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TAdWarningBaseGC;
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x2C)); ((TAdWarningBaseGC *)arg0)->m_2c = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D4208;

void *TAdWarningBaseGC__ct(TAdWarningBaseGC *ad_warning_base_gc) {
    void *o;
    void *o2;
    __ct__7TObjectFP7TObject(ad_warning_base_gc);
    *(s32 **)((s8 *)ad_warning_base_gc + 0x18) = __vt__16TAdWarningBaseGC;
    *(void * *)&ad_warning_base_gc->m_name = lbl_805D4208;
    ad_warning_base_gc->m_28 = 0;
    ad_warning_base_gc->m_1c = 0;
    ad_warning_base_gc->m_24 = 0;
    ad_warning_base_gc->m_2c = 0;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        __ct__9TAdBackGCFv(o, ad_warning_base_gc);
    }
    o2 = __nw__7TObjectFUl(0x28);
    if (o2 != NULL) {
        __ct__12TAdBackTxtGCFv(o2, ad_warning_base_gc);
    }
    return ad_warning_base_gc;
}

}
