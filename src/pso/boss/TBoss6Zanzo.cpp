#include "types.h"
#include "pso/unk/text_80141A30.h"
#include "pso/system/memory.h"
#include "pso/boss/TBoss6Zanzo.h"
#include "pso/boss/TBoss6Type1.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdChrMoveEffectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct Src_80320534 { s32 a; u8 *p; };

struct Ent_803204B8 { u8 pad[4]; f32 v[3]; };

struct Blk_803204B8 { s32 flag; Ent_803204B8 *ents; };

struct Ef_803204B8 { u8 pad[0x20]; Blk_803204B8 *blk; s32 count; };

struct Src_80320950 { s32 a; u8 *p; };

struct Obj_80320950 { u8 pad[0x18]; void *vt; Src_80320950 *arr; Src_80320950 *last; u8 pad2[4]; s32 n; };

struct Obj_803208CC { u8 pad[0x1C]; Src_80320534 *arr; Src_80320534 *last; u8 pad2[4]; s32 n; };

struct Src_803209F0 { s32 a; u8 *p; };

struct Obj_803209F0 { s32 f0; u8 pad[0x14]; void *vt; Src_803209F0 *arr; Src_803209F0 *last; s32 n; s32 m; };

extern "C" {
void VecCopy__FP3VecPC3Vec(void *, void *);
void mem_free(void *);
void run_task__11TBoss6ZanzoFv(Obj_803208CC *arg0);
void *mem_alloc(u32 size);
extern s32 TBoss6Zanzo__name;
int TBoss6Zanzo__sub_803205C4(void*);
int set_depth_buffer_settings_1__Fv(void*);

s32 fn_803204B0(void* p) { return *(s32*)((char*)p + 0x4); }

void TBoss6Type1::set_effect_points(f32 *a, u32 *b) {
    Ef_803204B8 *o = (Ef_803204B8 *)this;
    Ent_803204B8 *p;
    Ent_803204B8 *end;
    f32 *a2 = a;
    u32 *b2 = b;
    o->blk->flag = 1;
    p = o->blk->ents;
    end = p + o->count;
    for (; p < end; p++, a2 += 3, b2++) {
        VecCopy__FP3VecPC3Vec(&p->v, a2);
        ((TAdChrMoveEffectGC *)p)->copy4(b2);
    }
}

void TBoss6Zanzo::copy_trail_buffer(void *arg1_arg, void *arg2_arg) {
    TBoss6Zanzo *arg0 = this;
    Src_80320534 *arg1 = (Src_80320534 *)arg1_arg;
    Src_80320534 *arg2 = (Src_80320534 *)arg2_arg;
    u8 *src;
    u8 *dst;
    u8 *end;
    arg1->a = arg2->a;
    if (arg1->a != 0) {
        dst = arg1->p;
        src = arg2->p;
        end = dst + (arg0->m_24 << 4);
        for (; dst < end; dst += 0x10, src += 0x10) {
            TBoss6Zanzo__sub_803205A0((s32 *)dst, (s32 *)src);
        }
    }
}

void TBoss6Zanzo__sub_803205A0(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
    *(ByteBlock_C *)((s32) arg0 + 4) = *(const ByteBlock_C *)((s32) arg1 + 4);
}

void TBoss6Zanzo::render() { set_depth_buffer_settings_1__Fv(this); TBoss6Zanzo__sub_803205C4(this); restore_saved_depth_alpha_state(); }

void run_task__11TBoss6ZanzoFv(Obj_803208CC *arg0) {
    Src_80320534 *base;
    Src_80320534 *p;
    if (TObjPlayer::check_demo_mode() == 0) {
        base = arg0->arr;
        for (p = base + arg0->n - 1; p > base; p--) {
            ((TBoss6Zanzo *)arg0)->copy_trail_buffer(p, p - 1);
        }
        ((TBoss6Zanzo *)arg0)->copy_trail_buffer(p, arg0->last);
        arg0->last->a = 0;
    }
}

}
TBoss6Zanzo::~TBoss6Zanzo() {
    Src_80320950 *p;
    Src_80320950 *end;
    mem_free(((Obj_80320950 *)this)->last->p);
    ::operator delete(((Obj_80320950 *)this)->last);
    for (p = ((Obj_80320950 *)this)->arr, end = p + ((Obj_80320950 *)this)->n; p < end; p++) {
        mem_free(p->p);
    }
    mem_free(((Obj_80320950 *)this)->arr);
}

TBoss6Zanzo::TBoss6Zanzo(TObject *object, s32 arg2, s32 arg3) : TObject(object) {
    Src_803209F0 *p;
    Src_803209F0 *end;
    ((Obj_803209F0 *)this)->f0 = TBoss6Zanzo__name;
    ((Obj_803209F0 *)this)->n = arg2;
    if (((Obj_803209F0 *)this)->n < 2) {
        ((Obj_803209F0 *)this)->n = 2;
    }
    ((Obj_803209F0 *)this)->m = arg3;
    if (((Obj_803209F0 *)this)->m < 2) {
        ((Obj_803209F0 *)this)->m = 2;
    }
    ((Obj_803209F0 *)this)->arr = (Src_803209F0 *)mem_alloc(((Obj_803209F0 *)this)->m * 8);
    for (p = ((Obj_803209F0 *)this)->arr, end = p + ((Obj_803209F0 *)this)->m; p < end; p++) {
        p->a = 0;
        p->p = (u8 *)mem_alloc(((Obj_803209F0 *)this)->n * 0x10);
    }
    ((Obj_803209F0 *)this)->last = (Src_803209F0 *)::operator new(8);
    ((Obj_803209F0 *)this)->last->a = 0;
    ((Obj_803209F0 *)this)->last->p = (u8 *)mem_alloc(((Obj_803209F0 *)this)->n * 0x10);
}
