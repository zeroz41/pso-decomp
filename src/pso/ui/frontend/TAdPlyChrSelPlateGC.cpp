#include "types.h"
#include <stddef.h>
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

struct O_802C4D5C { u8 pad[0x2a8]; f32 v[1]; };

typedef struct Q_802C4D88 { s8 b[4]; } Q_802C4D88;

typedef struct S_802C4D88 {
    u8 pad0[0x224];
    s32 f224;
    s32 a[32];
    f32 fl[32];
    Q_802C4D88 c[32];
    u8 pad3A8[4];
    s32 f3AC;
} S_802C4D88;

typedef struct V_802C4DD0 { s32 x, y; } V_802C4DD0;

typedef struct S_802C4DD0 {
    u8 pad0[0x1C];
    V_802C4DD0 v1C[32];
    V_802C4DD0 v11C[32];
    s32 pad21C[2];
    s32 f224;
} S_802C4DD0;

typedef struct V_802C4E38 { f32 x, y; } V_802C4E38;

typedef struct Q_802C4E38 { u8 b[4]; } Q_802C4E38;

typedef struct S_802C4E38 {
    u8 pad0[0x1C];
    V_802C4E38 v1C[32];
    V_802C4E38 v11C[32];
    s32 pad21C[2];
    s32 f224;
    s32 a[32];
    f32 fl[32];
    Q_802C4E38 c[32];
    u8 col[4];
    s32 f3AC;
} S_802C4E38;

const char *TAdPlyChrSelPlateGC__name = "TAdPlyChrSelPlateGC";

#pragma push
#pragma fp_contract on
void TAdEnterSerialAccessGC__sub_802C4B64(TAdPlyChrSelPlateGC *plate, NJS_POINT2 *pos, NJS_COLOR color, u32 depth) {
    NJS_POINT2COL fan;
    NJS_POINT2 *xyp;
    NJS_COLOR col[4];
    NJS_POINT2 xy[4];
    f32 y;
    f32 x;

    x = pos->x;
    y = pos->y;
    fan.col = col;
    xyp = xy;
    if ((!&color && !&color) && !&color) {
    }
    fan.p = xyp;
    fan.tex = NULL;
    fan.num = 4;
    fan.p[0].x = x;
    fan.p[0].y = y;
    ((TAdChrMoveEffectGC *)&fan.col[0])->copy4(&color);
    fan.p[1].x = fan.p[0].x;
    fan.p[1].y = fan.p[0].y + plate->plate_size.y;
    ((TAdChrMoveEffectGC *)&fan.col[1])->copy4(&color);
    fan.p[2].x = fan.p[0].x + plate->plate_size.x;
    fan.p[2].y = fan.p[0].y + plate->plate_size.y;
    ((TAdChrMoveEffectGC *)&fan.col[2])->copy4(&color);
    fan.p[3].x = fan.p[0].x + plate->plate_size.x;
    fan.p[3].y = fan.p[0].y;
    ((TAdChrMoveEffectGC *)&fan.col[3])->copy4(&color);
    ((TObjCMHairMenu *)&fan)->draw_tri_fan_2d(4, 7, 0.001f * (f32)depth + (-30.0f));
}
#pragma pop

void TAdPlyChrSelPlateGC::render() {
    u32 i;

    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 10);
        for (i = 0; i < plate_count; i++) {
            if (plate_shown[i] != 0) {
                u8 *pos = (u8 *)this;
                pos += i * sizeof(NJS_POINT2);
                pos += offsetof(TAdPlyChrSelPlateGC, plate_pos);
                TAdEnterSerialAccessGC__sub_802C4B64(this, (NJS_POINT2 *)pos, plate_color[i], i);
            }
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

extern "C" {
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *, void *);
bool TAdPlyChrSelPlateGC::is_slot_value_ready(s32 i) {
    O_802C4D5C *self = (O_802C4D5C *)this;
    return (self->v[i] >= 127.5f) ? true : false;
}
void TAdPlyChrSelPlateGC::reset_selection_slots() {
    S_802C4D88 *arg0 = (S_802C4D88 *)this;
    s32 i;
    arg0->f3AC = -1;
    arg0->f224 = 0;
    for (i = 0; i < 0x20; i++) {
        arg0->a[i] = 0;
        arg0->fl[i] = 0.0f;
        arg0->c[i].b[0] = 0;
        arg0->c[i].b[1] = 0;
        arg0->c[i].b[2] = 0;
        arg0->c[i].b[3] = 0;
    }
}
typedef void (*Fn1_802C4DD0)(void *);
void TAdPlyChrSelPlateGC::push_plate_position() {
    S_802C4DD0 *arg0 = (S_802C4DD0 *)this;
    if (arg0->f224 < 0x20) {
        ((Fn1_802C4DD0)copy_vec2__28TWindowSubSymbolChatPartsSetFPv)(&arg0->v11C[arg0->f224]);
        ((TWindowSubSymbolChatPartsSet *)(&arg0->v1C[arg0->f224]))->copy_vec2(&arg0->v11C[0]);
        arg0->f224 = arg0->f224 + 1;
    }
}
#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TAdPlyChrSelPlateGC::run_task() {
    S_802C4E38 *self = (S_802C4E38 *)this;
    s32 half;
    s32 m;
    u32 i;
    s32 j;
    if (self->f3AC < self->f224 * 2 + 1) {
        self->f3AC = self->f3AC + 1;
    }
    for (i = 0; i < 32; i++) {
        if (self->a[i] != 0) {
            if (self->a[i] == -1) {
                self->c[i].b[2] = 0xFF;
                self->c[i].b[1] = 0xFF;
                self->c[i].b[0] = 0xFF;
                self->c[i].b[3] = 0x22;
                self->a[i] = 1;
            } else {
                self->fl[i] += 255.0f;
                self->fl[i] = (self->fl[i] > 127.5f) ? 127.5f : self->fl[i];
                self->c[i].b[2] = self->col[2];
                self->c[i].b[1] = self->col[1];
                self->c[i].b[0] = self->col[0];
                self->c[i].b[3] = (s32)self->fl[i];
            }
            for (j = 0; j < 32; j++) {
                s32 k = 0;
                self->v1C[j].x = self->v11C[j].x;
                self->v1C[j].y += (self->v11C[j].y - self->v11C[0].y) / (5.0f * (f32)k + 30.0f);
                self->v1C[j].y = (self->v1C[j].y > self->v11C[j].y) ? self->v11C[j].y : self->v1C[j].y;
            }
        }
    }
    if (self->f3AC % 2 == 0) {
        half = self->f3AC / 2;
        m = half - 1;
        if (m < self->f224 && half - 1 >= 0 && m < 32) {
            self->a[half - 1] = 1;
        }
    }
}
#pragma pop

}

TAdPlyChrSelPlateGC::~TAdPlyChrSelPlateGC() {}

extern "C" {
struct Q_802C5040 { s8 b[4]; };
struct Arg_802C5040 { u8 pad0[0xC]; s32 f0C; };
struct S_802C5040 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[0x224 - 0x1C];
    s32 f224;
    s32 a[32];
    f32 fl[32];
    Q_802C5040 c[32];
    u8 pad3A8[4];
    s32 f3AC;
    s32 f3B0;
};
extern u8 __vt__19TAdPlyChrSelPlateGC[];
void __ct__7TObjectFP7TObject(void *);

S_802C5040 *__ct__19TAdPlyChrSelPlateGCFv(S_802C5040 *arg0, s32 arg1, Arg_802C5040 *arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = __vt__19TAdPlyChrSelPlateGC;
    arg0->name = TAdPlyChrSelPlateGC__name;
    arg0->f3B0 = arg2->f0C;
    arg0->f3AC = -1;
    arg0->f224 = 0;
    for (i = 0; i < 0x20; i++) {
        arg0->a[i] = 0;
        arg0->fl[i] = 0.0f;
        arg0->c[i].b[0] = 0;
        arg0->c[i].b[1] = 0;
        arg0->c[i].b[2] = 0;
        arg0->c[i].b[3] = 0;
    }
    ((TWindowSubSymbolChatPartsSet *)((u8 *)arg0 + 0x21C))->copy_vec2(arg2);
    ((TAdChrMoveEffectGC *)((u8 *)arg0 + 0x3A8))->copy4((u8 *)arg2 + 8);
    return arg0;
}
}
