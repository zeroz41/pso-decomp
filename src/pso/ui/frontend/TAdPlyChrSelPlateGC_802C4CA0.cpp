#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
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

extern "C" {
extern const f32 lbl_805DE54C;
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *, void *);
extern const f32 lbl_805DE550;
extern const f32 lbl_805DE554;
extern const f32 lbl_805DE558;
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
        arg0->fl[i] = lbl_805DE54C;
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
                self->fl[i] += lbl_805DE550;
                self->fl[i] = (self->fl[i] > 127.5f) ? 127.5f : self->fl[i];
                self->c[i].b[2] = self->col[2];
                self->c[i].b[1] = self->col[1];
                self->c[i].b[0] = self->col[0];
                self->c[i].b[3] = (s32)self->fl[i];
            }
            for (j = 0; j < 32; j++) {
                s32 k = 0;
                self->v1C[j].x = self->v11C[j].x;
                self->v1C[j].y += (self->v11C[j].y - self->v11C[0].y) / (lbl_805DE558 * (f32)k + lbl_805DE554);
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
