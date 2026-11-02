#include "types.h"

struct W_802D5B78 { s32 a; s32 b; s32 c; };

struct S_802D5B78 {
    u8 pad0[0xC];
    f32 scale;
    u8 pad10[0xC];
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad28[4];
};

extern "C" {

void normalize_vector(void *);

#pragma push
#pragma fp_contract on

void TObjPlayer__sub_802D5B78(void *arg0, void *arg1, void *arg2) {
    s32 *wsrc;
    s32 a;
    s32 b;
    s32 c;
    W_802D5B78 w;
    wsrc = (s32 *)arg2;
    c = wsrc[0];
    a = c;
    b = wsrc[1];
    c = wsrc[2];
    w.a = a;
    w.b = b;
    w.c = c;
    normalize_vector(&w);
    S_802D5B78 *tab = *(S_802D5B78 **)((s8 *)*(void **)arg0 + 0xA4);
    S_802D5B78 *e = (S_802D5B78 *)((s8 *)tab + *(s32 *)((s8 *)arg0 + 4) * 0x2C);
    f32 s = e->scale;
    f32 *out = (f32 *)arg1;
    out[0] = e->f1C - (*(f32 *)&w.a) * s;
    out[1] = e->f20 - (*(f32 *)&w.b) * s;
    out[2] = e->f24 - (*(f32 *)&w.c) * s;
}

#pragma pop

}
