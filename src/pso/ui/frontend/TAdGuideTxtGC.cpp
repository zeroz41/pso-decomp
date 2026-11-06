#include "types.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject.h"

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

struct TAdGuideTxtGC_802B19E8 {
    s32 f0;
    u8 pad4[0x14];
    void *vt18;
    void *a[2];
    void *b[2];
    u8 pad2c[0x3C - 0x2C];
    s32 c[2];
};

typedef struct Pos_802B1878 { f32 x; f32 y; } Pos_802B1878;

typedef struct TAdGuideTxtGC_802B1878 {
    u8 pad0[0x1C];
    s32 txt[2];
    u8 pad24[0x2C - 0x24];
    Pos_802B1878 pos[2];
    u32 alpha[2];
} TAdGuideTxtGC_802B1878;

#pragma readonly_strings on
const char *TAdGuideTxtGC__class_name = "TAdGuideTxtGC";

extern "C" {
void __ct__7TObjectFP7TObject(void *);
extern void *__vt__13TAdGuideTxtGC[6];
TAdGuideTxtGC_802B19E8 *__ct__13TAdGuideTxtGCFv(TAdGuideTxtGC_802B19E8 *o);
void run_task__13TAdGuideTxtGCFv(TAdGuideTxtGC_802B1878 *o);

#pragma push
#pragma fp_contract on
void run_task__13TAdGuideTxtGCFv(TAdGuideTxtGC_802B1878 *o) {
    u32 i;
    f32 t;
    for (i = 0; i < 2; i++) {
        o->alpha[i] += 25;
        if (o->alpha[i] > 255) {
            o->alpha[i] = 255;
        }
        t = 640.0f - (f32)calc_text_width((char *)o->txt[i]);
        o->pos[i].x = t / 2.0f;
        o->pos[i].y = 20.0f * (f32)i + 370.0f;
    }
}
#pragma pop

}
TAdGuideTxtGC::~TAdGuideTxtGC() {

}

#pragma push
#pragma opt_common_subs off
TAdGuideTxtGC_802B19E8 *__ct__13TAdGuideTxtGCFv(TAdGuideTxtGC_802B19E8 *o) {
    u32 i;
    __ct__7TObjectFP7TObject(o);
    o->vt18 = __vt__13TAdGuideTxtGC;
    o->f0 = (s32)TAdGuideTxtGC__class_name;
    for (i = 0; i < 2; i++) {
        o->a[i] = (void *)"";
        o->b[i] = (void *)"";
        o->c[i] = 0;
    }
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)o, 9, 0.0f);
    return o;
}
#pragma pop

void reset__15TLobby_802D2F7CFPv(u8 *arg0) {

    ((VObj_802b1a70_802B1990 *)((unsigned char *) (*(void **)((s8 *)arg0 + 0x28))))->m7();
    *(s8 *)((s8 *)arg0 + 0x1C) = 7;
}

extern void *__vt__13TAdGuideTxtGC[];
