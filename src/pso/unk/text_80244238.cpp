#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowAddition.h"

struct Ctx_80244364 { u8 pad[0x10]; f32 x; f32 y; };

struct Obj_80244364 { u8 pad[0x60]; f32 a[2]; f32 x; f32 y; };

typedef struct Disp_80244238 {
    u8 pad0[0x30];
    f32 tx;
    f32 ty;
    f32 tz;
    f32 tw;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u32 n;
    u8 pad54[0x6C - 0x54];
    f32 f6C;
} Disp_80244238;

extern "C" {
s32 set_position_xy__15TWindowAdditionFff(f32, f32);
extern s32 lbl_805D3878;
extern const f32 lbl_805DCAAC;
extern const f32 lbl_805DCAB0;
Ctx_80244364 *setup_window_draw_context__11TWindowBaseFl(Obj_80244364 *self, f32 *p);
Ctx_80244364 *get_draw_context__11TWindowBaseFPv(Obj_80244364 *self);
extern const f32 lbl_805DCAA8;

#pragma push
#pragma fp_contract on
void TWindowAddition::step_window_tween() {
    Disp_80244238 *o = (Disp_80244238 *)this;
    f32 d;
    u32 n = o->n;
    if (n == 0) {
        d = o->tz - o->z;
        ((TWindowBase *)o)->save_position();
    } else {
        d = (o->tw - o->w) / n;
        o->x += (o->tx - o->x) / n;
        o->y += (o->ty - o->y) / o->n;
        o->z += (o->tz - o->z) / o->n;
        o->w += d;
        o->n--;
    }
    o->f6C -= lbl_805DCAA8 * d;
}
#pragma pop

Ctx_80244364 *get_draw_context__11TWindowBaseFPv(Obj_80244364 *self) {
    Ctx_80244364 *c = setup_window_draw_context__11TWindowBaseFl(self, self->a);
    c->x -= self->x;
    c->y -= self->y;
    return c;
}

void TWindowAddition::sub_802443B4() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)&this->m_name = (s32) lbl_805D3878;
    *(f32 *)((s8 *)arg0 + 0x68) = (f32) lbl_805DCAAC;
    *(f32 *)((s8 *)arg0 + 0x6C) = (f32) lbl_805DCAAC;
    set_position_xy__15TWindowAdditionFff(lbl_805DCAB0, lbl_805DCAB0);
}

}
