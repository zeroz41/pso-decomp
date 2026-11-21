#include "types.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct Base_802b1a70_802B1990 { char pad[0x18]; };
struct VObj_802b1a70_802B1990 : Base_802b1a70_802B1990 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

#pragma readonly_strings on
const char *TAdGuideTxtGC__class_name = "TAdGuideTxtGC";

extern "C" {

#pragma push
#pragma fp_contract on
void TAdGuideTxtGC::run_task() {
    u32 i;
    f32 t;
    for (i = 0; i < 2; i++) {
        alpha[i] += 25;
        if (alpha[i] > 255) {
            alpha[i] = 255;
        }
        t = 640.0f - (f32)calc_text_width(const_cast<char *>(text[i]));
        position[i].x = t / 2.0f;
        position[i].y = 20.0f * (f32)i + 370.0f;
    }
}
#pragma pop

}
TAdGuideTxtGC::~TAdGuideTxtGC() {

}

#pragma push
#pragma opt_common_subs off
TAdGuideTxtGC::TAdGuideTxtGC(TObject *parent) : TObject(parent) {
    u32 i;
    m_name = TAdGuideTxtGC__class_name;
    for (i = 0; i < 2; i++) {
        text[i] = "";
        previous_text[i] = "";
        alpha[i] = 0;
    }
    create_draw_line_ctrl(this, 9, 0.0f);
}
#pragma pop

void reset__15TLobby_802D2F7CFPv(u8 *arg0) {

    ((VObj_802b1a70_802B1990 *)((unsigned char *) (*(void **)((s8 *)arg0 + 0x28))))->m7();
    *(s8 *)((s8 *)arg0 + 0x1C) = 7;
}
