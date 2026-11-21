#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject.h"

const char *lbl_805D4208 = "TAdWarningBaseGC";
static const f32 lbl_80477334[2] = {46.0f, 131.0f};
static const f32 lbl_8047733C[2] = {548.0f, 220.0f};

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
void play_sound_effect(int, int, int, int);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
void __ct__7TObjectFP7TObject(void *);

    extern int aram_request_busy_flag;
void clear_aram_request_busy(void) { aram_request_busy_flag = 0; }


void TAdWarningBaseGC::vfunc_9() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

s32 TAdWarningBaseGC::sub_8032D214() {
    V_8032D214 *arg0 = (V_8032D214 *)this;
    saddr r = (saddr)create_message_window_for_size((NJS_POINT2 *)lbl_80477334, (NJS_POINT2 *)lbl_8047733C);
    ((TWindowMessage *)r)->append_line((saddr)(arg0->m5()), (int)3);
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
            test_controller_flag_4c_color(b = controller_input_state + 0x160, 4) != 0 ||
            TWindowShortListCtrl__check_controller_button(a, 2) != 0 ||
            test_controller_flag_4c_color(b, 2) != 0) {
            *(s32 *)&this->m_1c = 3;
            *(s32 *)&this->m_24 = 4;
        }
        break;
    case 3:
        if (*(void * *)&this->m_2c != NULL) {
            ((TWindowBase *)(*(void * *)&this->m_2c))->close();
            *(void * *)&this->m_2c = NULL;
        }
        if ((f32)++*(s32 *)&this->m_28 > 4.5f) {
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

TAdWarningBaseGC::~TAdWarningBaseGC() {
    if (m_2c != 0) {
        ((TObject *)m_2c)->queue_destruction();
        m_2c = 0;
    }
}


TAdWarningBaseGC::TAdWarningBaseGC(TObject *parent) : TObject(parent) {
    void *o;
    void *o2;
    m_name = lbl_805D4208;
    m_28 = 0;
    m_1c = 0;
    m_24 = 0;
    m_2c = 0;
    o = new TAdBackGC(this);
    o2 = new TAdBackTxtGC(this);
}

}
