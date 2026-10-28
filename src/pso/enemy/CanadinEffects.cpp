#include "types.h"
#include "pso/enemy/TObjEneMe1Canadin_EffLight.h"
#include "pso/TObject.h"
#include "pso/unk/text_800A02AC.h"
#include "pso/enemy/CanadinEffects.h"
#include "pso/enemy/TObjEneMe1Canadin.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/enemy/TObjEneMe1Canadin_EffDischarge.h"

#include "pso/enemy/TObjEneMe1Canadin_EffLine.h"
#include "pso/TTecZondeEff.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"
extern "C" {
extern const char TObjEneMe1Canadin_EffLine__class_name[];
extern const char TObjEneMe1Canadin_EffDischarge__class_name[];
extern const char TObjEneMe1Canadin_EffLight__class_name[];
__declspec(section ".rodata") const char TObjEneMe1Canadin_EffLine__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffLine";
__declspec(section ".rodata") const char TObjEneMe1Canadin_EffDischarge__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffDischarge";
__declspec(section ".rodata") const char TObjEneMe1Canadin_EffLight__class_name[] ATTRIBUTE_ALIGN(4) = "TObjEneMe1Canadin_EffLight";
}

struct Vec_8009F7AC { f32 x, y, z; };

struct Pt_8009F7AC { f32 w; u32 color; Vec_8009F7AC pos; };

struct Vtx_8009F7AC { f32 x, y, z; u32 color; };

struct Quad_8009F7AC { Vtx_8009F7AC a; Vtx_8009F7AC b; };

struct Trail_8009F7AC {
    u8 pad0[0x1C];
    s32 cap;
    s32 count;
    s32 head;
    Quad_8009F7AC *verts;
    Pt_8009F7AC *pts;
};

extern "C" {
void VecCopy__FP3VecPC3Vec(void *, const void *);
extern Vec_8009F7AC camera_pitch_rotated_up_vector;
extern const f32 canadin_effect_negative_one;
void render__26TObjEneMe1Canadin_EffLightFv(Trail_8009F7AC *o);
#pragma push
#pragma fp_contract on
void render__26TObjEneMe1Canadin_EffLightFv(Trail_8009F7AC *o) {
    Vec_8009F7AC up;
    Quad_8009F7AC *v;
    s32 i;
    Pt_8009F7AC *p;
    f32 w;
    u32 c;
    s32 j;
    s32 k;
    s32 last;
    s32 n;
    last = o->count - 1;
    if (o->head == last) {
        return;
    }
    VecCopy__FP3VecPC3Vec(&up, &camera_pitch_rotated_up_vector);
    v = o->verts;
    if (o->head > last) {
        n = o->count + (o->cap - o->head);
        for (i = o->count - 1; i >= 0; i--) {
            p = &o->pts[i];
            w = p->w;
            c = p->color;
            v->a.x = up.x * w + p->pos.x;
            v->a.y = up.y * w + p->pos.y;
            v->a.z = up.z * w + p->pos.z;
            v->a.color = c;
            w *= canadin_effect_negative_one;
            v->b.x = up.x * w + p->pos.x;
            v->b.y = up.y * w + p->pos.y;
            v->b.z = up.z * w + p->pos.z;
            v->b.color = c;
            v++;
        }
        for (j = o->cap - 1; j >= o->head; j--) {
            p = &o->pts[j];
            w = p->w;
            c = p->color;
            v->a.x = up.x * w + p->pos.x;
            v->a.y = up.y * w + p->pos.y;
            v->a.z = up.z * w + p->pos.z;
            v->a.color = c;
            w *= canadin_effect_negative_one;
            v->b.x = up.x * w + p->pos.x;
            v->b.y = up.y * w + p->pos.y;
            v->b.z = up.z * w + p->pos.z;
            v->b.color = c;
            v++;
        }
    } else {
        n = o->count - o->head;
        for (k = o->count - 1; k >= o->head; k--) {
            p = &o->pts[k];
            w = p->w;
            c = p->color;
            v->a.x = up.x * w + p->pos.x;
            v->a.y = up.y * w + p->pos.y;
            v->a.z = up.z * w + p->pos.z;
            v->a.color = c;
            w *= canadin_effect_negative_one;
            v->b.x = up.x * w + p->pos.x;
            v->b.y = up.y * w + p->pos.y;
            v->b.z = up.z * w + p->pos.z;
            v->b.color = c;
            v++;
        }
    }
    set_additive_blend();
    ((TObjPlayer *)(o->verts))->draw_trail_strip((void *)(n * 2), 1);
}
#pragma pop

}

struct Vec_8009FADC { f32 x, y, z; };

struct Entry_8009FADC { f32 f; s32 val; Vec_8009FADC pos; };

struct Obj_8009FADC { u8 pad[0x1c]; s32 count; s32 idx; u8 pad2[8]; Entry_8009FADC *entries; };

struct Obj_8009FB54 { f32 alpha; u32 color; };

struct Rec_8009FC44 { f32 a; s32 b; f32 c; f32 d; f32 e; };

struct Obj_8009FC44 {
    s32 descriptor;
    u8 pad4[0x18 - 4];
    void *vtbl;
    s32 count;
    s32 field20;
    s32 field24;
    void *buf28;
    Rec_8009FC44 *recs;
    s32 field30;
    f32 field34;
};

struct Rec_8009FA24 { u8 pad[0x14]; };

struct Obj_8009FA24 { u8 pad0[0x1C]; s32 n1c; s32 n20; s32 sel; u8 pad28[4]; Rec_8009FA24 *recs; s32 a30; f32 f34; };

extern "C" {
void push_history_entry__17TObjEneMe1CanadinFPvfPvi(Obj_8009FADC *self, f32 f, const Vec_8009FADC *pos, s32 val);
extern const f32 canadin_effect_zero;
extern const f32 canadin_light_width_cutoff;
s32 fade_alpha_step__17TObjEneMe1CanadinFPvif(Obj_8009FB54 *self, s32 dec, f32 scale);
void *mem_alloc(u32 size);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__26TObjEneMe1Canadin_EffLight[];
extern s32 TObjEneMe1Canadin_EffLight__name;
extern const f32 canadin_light_width_decay;
void run_task__26TObjEneMe1Canadin_EffLightFv(Obj_8009FA24 *arg0);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void mem_free(void *);

struct Obj_8009FB54;
typedef s32 (*Fn_8009FA24)(Rec_8009FA24 *, f32, s32);
void run_task__26TObjEneMe1Canadin_EffLightFv(Obj_8009FA24 *arg0) {
    s32 i;
    arg0->sel = arg0->n20 - 1;
    for (i = arg0->n20 - 1; i >= 0; i--) {
        if (((Fn_8009FA24)fade_alpha_step__17TObjEneMe1CanadinFPvif)(&arg0->recs[i], arg0->f34, arg0->a30) == 0) {
            arg0->sel = i;
        }
    }
    for (i = arg0->n1c - 1; i >= arg0->n20; i--) {
        if (((Fn_8009FA24)fade_alpha_step__17TObjEneMe1CanadinFPvif)(&arg0->recs[i], arg0->f34, arg0->a30) == 0) {
            arg0->sel = i;
        }
    }
}

void push_history_entry__17TObjEneMe1CanadinFPvfPvi(Obj_8009FADC *self, f32 f, const Vec_8009FADC *pos, s32 val) {
    s32 i = self->idx;
    self->entries[i].f = f;
    self->entries[i].val = val;
    VecCopy__FP3VecPC3Vec(&self->entries[i].pos, pos);
    self->idx++;
    if (self->idx >= self->count) {
        self->idx = 0;
    }
}

s32 fade_alpha_step__17TObjEneMe1CanadinFPvif(Obj_8009FB54 *self, s32 dec, f32 scale) {
    s32 a;
    if (canadin_effect_zero == self->alpha) {
        return 1;
    }
    self->alpha = self->alpha * scale;
    if (self->alpha < canadin_light_width_cutoff) {
        self->alpha = canadin_effect_zero;
        return 1;
    }
    a = (self->color >> 24) - dec;
    self->color &= 0xFFFFFF;
    if (a <= 0) {
        return 1;
    }
    self->color |= a << 24;
    return 0;
}

void *__dt__26TObjEneMe1Canadin_EffLightFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TObjEneMe1Canadin_EffLight;
        mem_free(*(void **)((s8 *)arg0 + 0x2C));
        *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        mem_free(((TObjEneMe1Canadin_EffLight *)arg0)->m_28);
        *(s32 *)((s8 *)arg0 + 0x28) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}
TObjEneMe1Canadin_EffLight::TObjEneMe1Canadin_EffLight(TObject *parent, s32 count) : TObject(parent) {
    s32 i;
    ((Obj_8009FC44 *)this)->descriptor = TObjEneMe1Canadin_EffLight__name;
    ((Obj_8009FC44 *)this)->count = count;
    ((Obj_8009FC44 *)this)->field20 = 0;
    ((Obj_8009FC44 *)this)->field24 = 0;
    ((Obj_8009FC44 *)this)->buf28 = mem_alloc(((Obj_8009FC44 *)this)->count << 5);
    ((Obj_8009FC44 *)this)->recs = (Rec_8009FC44 *)mem_alloc(((Obj_8009FC44 *)this)->count * 0x14);
    for (i = 0; i < ((Obj_8009FC44 *)this)->count; i++) {
        ((Obj_8009FC44 *)this)->recs[i].a = canadin_effect_zero;
        ((Obj_8009FC44 *)this)->recs[i].b = 0;
        ((Obj_8009FC44 *)this)->recs[i].c = canadin_effect_zero;
        ((Obj_8009FC44 *)this)->recs[i].d = canadin_effect_zero;
        ((Obj_8009FC44 *)this)->recs[i].e = canadin_effect_zero;
    }
    ((Obj_8009FC44 *)this)->field30 = 0x30;
    ((Obj_8009FC44 *)this)->field34 = canadin_light_width_decay;
}
extern "C" {

void render__30TObjEneMe1Canadin_EffDischargeFv(void) {  }

#pragma fp_contract on
#define VC_B ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)
u32 __nw__7TObjectFUl(s32);
void subtract_vector(void *, void *);
extern s32 tl_05;
extern const f32 canadin_discharge_motion_scale;

void run_task__30TObjEneMe1Canadin_EffDischargeFv(u8 *ene_me1_canadin_eff_discharge) {
    s32 sp8;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f31;
    s32 var_r31;

    var_r31 = 0;
    ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_28 = (f32) (((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_28 + canadin_discharge_motion_scale);
    temp_f1 = ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_28;
    if (temp_f1 > *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x34)) {
        VC_B(ene_me1_canadin_eff_discharge + 0x50, ene_me1_canadin_eff_discharge + 0x44);
        var_r31 = 1;
    } else {
        temp_f0 = ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_30;
        if (temp_f1 < temp_f0) {
            *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x54) = (f32) *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x24);
        } else {
            temp_f2 = temp_f1 - temp_f0;
            *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x54) = (f32) (temp_f2 * (((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_20 * temp_f2) + *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x24));
        }
        ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_50 = (f32) (((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_50 + *(f32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x5C));
        ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_58 = (f32) (((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_58 + ((TObjEneMe1Canadin_EffDischarge *)ene_me1_canadin_eff_discharge)->m_64);
    }
    VC_B(&sp8, ene_me1_canadin_eff_discharge + 0x50);
    subtract_vector(&sp8, ene_me1_canadin_eff_discharge + 0x38);
    temp_f31 = ((TObjBoss2Tunnel *)(&sp8))->update_scale();
    s32 nw_ret = __nw__7TObjectFUl(0x260);
    if (nw_ret != 0U) {
        ((TTecZondeEff *)nw_ret)->construct((u8 *)tl_05, ene_me1_canadin_eff_discharge + 0x38, (u8 *)&sp8, (f32)temp_f31);
    }
    VC_B(ene_me1_canadin_eff_discharge + 0x38, ene_me1_canadin_eff_discharge + 0x50);
    if (var_r31 != 0) {
        fn_8009E1D4((u8 *)(*(s32 *)((s8 *)ene_me1_canadin_eff_discharge + 0x1C)), (s32)(ene_me1_canadin_eff_discharge + 0x44));
        queue_destruction__7TObjectFv(ene_me1_canadin_eff_discharge);
    }
}

}

struct Stack_8009FFD8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct Vec_8009FEB8 { f32 x, y, z; };

struct Obj_8009FEB8 {
    s32 descriptor;
    u8 pad4[0x18 - 4];
    void *vtbl;
    void *parent;
    f32 accel;
    f32 y0;
    f32 time;
    f32 duration;
    f32 remain;
    f32 dist;
    Vec_8009FEB8 start;
    Vec_8009FEB8 end;
    Vec_8009FEB8 pos;
    Vec_8009FEB8 dir;
};

extern "C" {
s32 draw_line_list(void *, int, int);
#define VC_C ((void (*)(void *, const void *))VecCopy__FP3VecPC3Vec)
extern s32 __vt__30TObjEneMe1Canadin_EffDischarge[];
extern s32 TObjEneMe1Canadin_EffDischarge__name;
Obj_8009FEB8 *TObjEneMe1Canadin_EffDischarge__ct(Obj_8009FEB8 *self, void *parent, Vec_8009FEB8 *from, Vec_8009FEB8 *to);

void *__dt__30TObjEneMe1Canadin_EffDischargeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__30TObjEneMe1Canadin_EffDischarge;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_8009FEB8 *TObjEneMe1Canadin_EffDischarge__ct(Obj_8009FEB8 *self, void *parent, Vec_8009FEB8 *from, Vec_8009FEB8 *to) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vtbl = ((s32 *)&__vt__30TObjEneMe1Canadin_EffDischarge);
    self->descriptor = TObjEneMe1Canadin_EffDischarge__name;
    self->parent = parent;
    VC_C(&self->start, from);
    VC_C(&self->end, to);
    VC_C(&self->dir, &self->end);
    subtract_vector(&self->dir, &self->start);
    self->dir.y = canadin_effect_zero;
    self->dist = ((TObjBoss2Tunnel *)(&self->dir))->clamp_velocity();
    if (self->dist > canadin_discharge_motion_scale) {
        self->duration = canadin_discharge_motion_scale;
        self->remain = self->dist - self->duration;
    } else {
        self->duration = self->dist;
        self->remain = canadin_effect_zero;
    }
    self->y0 = self->start.y;
    self->accel = (self->end.y - self->start.y) / (self->duration * self->duration);
    self->time = canadin_effect_zero;
    self->dir.x *= canadin_discharge_motion_scale;
    self->dir.z *= canadin_discharge_motion_scale;
    VC_C(&self->pos, &self->start);
    return self;
}

void render__25TObjEneMe1Canadin_EffLineFv(s32 arg0) {
    Stack_8009FFD8 stack;
    stack.sp8 = arg0 + 0x28;
    stack.spC = arg0 + 0x40;
    stack.sp10 = 0;
    stack.sp14 = 2;
    set_additive_blend();
    draw_line_list(&stack.sp8, 1, 5);
}

#define VC_D ((s32 (*)(void *, s32))VecCopy__FP3VecPC3Vec)

void run_task__25TObjEneMe1Canadin_EffLineFv(u8 *ene_me1_canadin_eff_line) {
    VC_D(ene_me1_canadin_eff_line + 0x28, ((TObjEneMe1Canadin_EffLine *)ene_me1_canadin_eff_line)->m_20);
    VC_D(ene_me1_canadin_eff_line + 0x34, *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x24));
    *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x1C) = (s32) (*(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x1C) + 1);
    if ((s32) *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x1C) > 5) {
        *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x1C) = 0;
        u32 newp = __nw__7TObjectFUl(0x3C);
        if (newp != 0U) {
            fn_800A02AC((u8 *)newp, (u8 *)(*(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x10)), ene_me1_canadin_eff_line + 0x28, ene_me1_canadin_eff_line + 0x34);
        }
    }
}

extern s32 __vt__25TObjEneMe1Canadin_EffLine[];

}
TObjEneMe1Canadin_EffLine::~TObjEneMe1Canadin_EffLine() {

}
extern "C" {

s32 rand(s32);

extern s32 TObjEneMe1Canadin_EffLine__name;
extern const f32 canadin_line_initial_phase_range;
struct CanadinRandomScale { f32 value; u32 padding; };
__declspec(section ".sdata2") extern const CanadinRandomScale canadin_random_scale;

#pragma opt_propagation off
u8 *TObjEneMe1Canadin_EffLine__ct(u8 *ene_me1_canadin_eff_line, s32 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(u8 *, s32))__ct__7TObjectFP7TObject)(ene_me1_canadin_eff_line, arg1);
    *(s32 **)((s8 *)ene_me1_canadin_eff_line + 0x18) = __vt__25TObjEneMe1Canadin_EffLine;
    *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0) = (s32) TObjEneMe1Canadin_EffLine__name;
    ((TObjEneMe1Canadin_EffLine *)ene_me1_canadin_eff_line)->m_20 = arg2;
    *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x24) = arg3;
    VC_D(ene_me1_canadin_eff_line + 0x28, ((TObjEneMe1Canadin_EffLine *)ene_me1_canadin_eff_line)->m_20);
    VC_D(ene_me1_canadin_eff_line + 0x34, *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x24));
    {
        s32 k = (s32) 0xFFFF0000;
        ((TObjEneMe1Canadin_EffLine *)ene_me1_canadin_eff_line)->m_40 = k + 0x33;
        *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x44) = k + 0x33;
        *(s32 *)((s8 *)ene_me1_canadin_eff_line + 0x1C) = (s32) (canadin_line_initial_phase_range * (canadin_random_scale.value * (f32) rand(k)));
    }
    return ene_me1_canadin_eff_line;
}

void render_shadows__7TObjectFv();
s32 __vt__26TObjEneMe1Canadin_EffLight[] = {
    0, 0, (s32)__dt__26TObjEneMe1Canadin_EffLightFv,
    (s32)run_task__26TObjEneMe1Canadin_EffLightFv,
    (s32)render__26TObjEneMe1Canadin_EffLightFv, (s32)render_shadows__7TObjectFv
};
s32 __vt__30TObjEneMe1Canadin_EffDischarge[] = {
    0, 0, (s32)__dt__30TObjEneMe1Canadin_EffDischargeFv,
    (s32)run_task__30TObjEneMe1Canadin_EffDischargeFv,
    (s32)render__30TObjEneMe1Canadin_EffDischargeFv, (s32)render_shadows__7TObjectFv
};
__declspec(section ".sdata2") const f32 canadin_effect_negative_one = -1.0f;
__declspec(section ".sdata2") const f32 canadin_effect_zero = 0.0f;
__declspec(section ".sdata2") const f32 canadin_light_width_cutoff = 0.01f;
__declspec(section ".sdata2") const f32 canadin_light_width_decay = 0.85f;
__declspec(section ".sdata2") const f32 canadin_discharge_motion_scale = 20.0f;
__declspec(section ".sdata2") const f32 canadin_line_initial_phase_range = 5.0f;
__declspec(section ".sdata2") const CanadinRandomScale canadin_random_scale = {0.000030517578125f, 0};
}
