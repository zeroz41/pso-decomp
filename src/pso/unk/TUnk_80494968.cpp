#include "types.h"
#include "pso/unk/TUnk_80494968.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/render/render_util.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_800D7950.h"
#include "pso/effect/TAttackTrace.h"

typedef struct Ent_800D76E8 {
    f32 ax, ay, az;
    s32 ta;
    f32 bx, by, bz;
    s32 tb;
} Ent_800D76E8;

typedef struct Trail_800D76E8 {
    u8 pad0[0x1C];
    s32 count;
    Ent_800D76E8 e[1];
} Trail_800D76E8;

extern "C" {

s32 defer_render__7TObjectFv();

void TUnk_80494968::render() {
    u8 *arg0 = (u8 *)this;
    if ((defer_render__7TObjectFv() == 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x1C) > 1)) {
        set_additive_blend();
        ((TObjPlayer *)(arg0 + 0x20))->draw_trail_strip((void *)(*(s32 *)((s8 *)arg0 + 0x1C) * 2), 1);
    }
}

void TUnk_80494968::run_task() {
    Trail_800D76E8 *arg0 = (Trail_800D76E8 *)this;
    s32 ta;
    s32 tb;
    s32 r;
    if (arg0->count <= 0) {
        return;
    }
    ta = arg0->e[0].ta;
    r = TObjBoss2Tunnel::decrement_packed_timer((u32 *)&ta, 0x20);
    tb = arg0->e[0].tb;
    if (r & TObjBoss2Tunnel::decrement_packed_timer((u32 *)&tb, 0x20)) {
        Ent_800D76E8 *dst = &arg0->e[0];
        Ent_800D76E8 *src = &arg0->e[1];
        s32 i;
        arg0->count--;
        for (i = 0; i < arg0->count; i++) {
            dst->ax = src->ax;
            dst->ay = src->ay;
            dst->az = src->az;
            dst->bx = src->bx;
            dst->by = src->by;
            dst->bz = src->bz;
            src++;
            dst++;
        }
        return;
    }
    if (arg0->count > 1) {
        Ent_800D76E8 *p = &arg0->e[arg0->count - 1];
        Ent_800D76E8 *q = p - 1;
        s32 j;
        for (j = 1; j < arg0->count; j++) {
            p->ta = q->ta;
            p[-1].tb = q[-1].tb;
            q--;
            p--;
        }
    }
    arg0->e[0].ta = ta;
    arg0->e[0].tb = tb;
}

void TUnk_80494968::sub_800D7818(s32 arg1, s32 arg2) {
    this->m_120 = arg1;
    *(s32 *)&this->unk_124 = arg2;
}

}

struct P_800D78CC { u8 b[0x10]; };

struct Obj_800D78CC { u8 pad0[0x1C]; s32 count; P_800D78CC a[2]; };

struct Vec_800D7824 { f32 x, y, z; };

struct P_800D7824 { Vec_800D7824 v; s32 w; };

struct B_800D7824 { u8 pad0[0x18]; };

struct Obj_800D7824 : B_800D7824 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void flush();
    s32 count;
    P_800D7824 a[16];
    s32 w120;
    s32 w124;
};

void TUnk_80494968::vfunc_6(void *p0_arg, void *p1_arg) {
    Obj_800D7824 *self = (Obj_800D7824 *)this;
    Vec_800D7824 *p0 = (Vec_800D7824 *)p0_arg;
    Vec_800D7824 *p1 = (Vec_800D7824 *)p1_arg;
    P_800D7824 *e;
    if (self->count >= 0x10) {
        self->flush();
    }
    e = &self->a[self->count * 2];
    e[0].v.x = p0->x;
    e[0].v.y = p0->y;
    e[0].v.z = p0->z;
    e[0].w = self->w120;
    e[1].v.x = p1->x;
    e[1].v.y = p1->y;
    e[1].v.z = p1->z;
    e[1].w = self->w124;
    self->count++;
}

void TUnk_80494968::shift_line_buffer_down() {
    Obj_800D78CC *arg0 = (Obj_800D78CC *)this;
    P_800D78CC *p;
    P_800D78CC *q;
    s32 lim;
    s32 i;
    s32 n = arg0->count;
    if (n <= 1) {
        arg0->count = 0;
        return;
    }
    p = arg0->a;
    q = arg0->a + 2;
    lim = (n - 1) * 2;
    for (i = 0; i < lim; i++) {
        TAdDrawLineTask__sub_80019A8C(p++, q++);
    }
    arg0->count = arg0->count - 1;
}

TUnk_80494968::~TUnk_80494968() {

}

struct Ent_800D79A8 { u8 pad[0xc]; s32 fc; u8 pad2[0xc]; s32 f1c; };

struct Obj_800D79A8 { u8 pad[0x18]; void *vt; u8 pad1c[4]; Ent_800D79A8 ents[8]; s32 f120; s32 f124; };

extern "C" {
extern u8 __vt__13TUnk_80494968[];
Obj_800D79A8 *fn_800D79A8(Obj_800D79A8 *self, s32 x, s32 a, s32 b);
Obj_800D79A8 *fn_800D79A8(Obj_800D79A8 *self, s32 x, s32 a, s32 b) {
    s32 i;
    Ent_800D79A8 *p;
    TAttackTrace__ct(self);
    self->vt = __vt__13TUnk_80494968;
    ((TUnk_80494968 *)self)->sub_800D7818(a, b);
    p = self->ents;
    for (i = 0; i < 8; i++) {
        p->fc = self->f120;
        p->f1c = self->f124;
        p++;
    }
    return self;
}

}
