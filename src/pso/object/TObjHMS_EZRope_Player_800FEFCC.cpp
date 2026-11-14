#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/object/TObjEZRopeBase.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct E1_800FF070 { s8 type; u8 pad1[0x13]; u8 *data; } E1_800FF070;

typedef struct E2_800FF070 { s8 type; u8 pad1[0x13]; } E2_800FF070;

typedef struct D1_800FF070 { s8 type; u8 pad1[0x17]; } D1_800FF070;

typedef struct D2_800FF070 { f32 v[4]; } D2_800FF070;

typedef struct Obj_800FF070 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[0x14];
    void *f30;
    E1_800FF070 *list;
    E2_800FF070 *list2;
    D1_800FF070 *a;
    D2_800FF070 *b;
    D2_800FF070 *c;
} Obj_800FF070;

struct Rec_800FF2D0 { s8 n; u8 pad1[0x10 - 1]; void *f10; void *f14; };

struct Ang_800FF2D0 { s32 a; u8 pad4[0xC]; };

struct Blob_800FF2D0 { f32 scale; Vec pos; };

struct Obj_800FF2D0 {
    u8 pad0[0x1C];
    s32 f1C;
    Rec_800FF2D0 *recs;
    Ang_800FF2D0 *angs;
    Blob_800FF2D0 *blobs;
    Vec *pts;
};

extern "C" {
void TObjPlayer__sub_800FF220(s32 *arg0, s32 *arg1);
void TObjPlayer__sub_800FF1FC(f32 *arg0, f32 *arg1);
void TObjPlayer__sub_800FF244(u8 *arg0, u8 *arg1);
void *TObjEZRopeBase__ct(void *);
extern u8 ezrope_chunk_material_color_table[];
extern s32 TObjHMS_EZRope_Player__name;
void *TObjHMS_EZRope_Player__ct(void *arg0, void *arg1, void *arg2, void *arg3);
f32 get_scale_factor__10TObjPlayerFv(f32);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void normalize_vector(Vec *v);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern u8 lbl_8048DEF4[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void *__dt__21TObjHMS_EZRope_PlayerFv(TObjHMS_EZRope_Player *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__14TObjEZRopeBaseFv(void *, int);
void *__nw__7TObjectFUl(int);

extern s32 __vt__21TObjHMS_EZRope_Player[];

void *__dt__21TObjHMS_EZRope_PlayerFv(TObjHMS_EZRope_Player *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjHMS_EZRope_Player;
        if (arg0->m_3c != NULL) { TAdSinglePlyChrSelectGC::safe_free((u32)arg0->m_3c); *(s32 *)((s8 *)arg0 + 0x3C) = 0; }
        if (*(void **)((s8 *)arg0 + 0x40) != NULL) { TAdSinglePlyChrSelectGC::safe_free((u32)(*(void **)((s8 *)arg0 + 0x40))); *(s32 *)((s8 *)arg0 + 0x40) = 0; }
        if (arg0->m_44 != NULL) { TAdSinglePlyChrSelectGC::safe_free((u32)arg0->m_44); *(s32 *)((s8 *)arg0 + 0x44) = 0; }
        __dt__14TObjEZRopeBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define SELF ((Obj_800FF070 *)arg0)
void *TObjHMS_EZRope_Player__ct(void *arg0, void *arg1, void *arg2, void *arg3) {
    s32 base = (s32)ezrope_chunk_material_color_table;
    s32 n1;
    s32 n2;
    E2_800FF070 *q;
    E1_800FF070 *p;
    D1_800FF070 *d;
    D2_800FF070 *e;
    TObjEZRopeBase__ct(arg0);
    n1 = 0;
    SELF->vt = (void *)(base + 0x3C);
    n2 = 0;
    SELF->f0 = TObjHMS_EZRope_Player__name;
    SELF->f30 = arg1;
    SELF->list = (E1_800FF070 *)arg2;
    SELF->list2 = (E2_800FF070 *)arg3;
    for (p = SELF->list; p->type >= 0; p++, n1++) {
    }
    if (SELF->list2 != NULL) {
        for (q = SELF->list2; q->type >= 0; q++, n2++) {
        }
    }
    SELF->a = (D1_800FF070 *)TQuestVmDownLoadServer::alloc((n1 + 1) * 0x18);
    SELF->b = (D2_800FF070 *)TQuestVmDownLoadServer::alloc(n1 * 0x10);
    if (n2 == 0) {
        SELF->c = NULL;
    } else {
        SELF->c = (D2_800FF070 *)TQuestVmDownLoadServer::alloc((n2 + 1) * 0x10);
    }
    {
        E1_800FF070 *p3;
        D1_800FF070 *d3;
        D2_800FF070 *e3;
        d3 = SELF->a;
        p3 = SELF->list;
        e3 = SELF->b;
        for (; p3->type >= 0; p3++, d3++, e3++) {
            TObjPlayer__sub_800FF244((u8 *)d3, p3->data);
            TObjPlayer__sub_800FF220((s32 *)e3, (s32 *)(base + 0x10));
        }
        d3->type = -1;
    }
    if (SELF->c != NULL) {
        E2_800FF070 *q4 = SELF->list2;
        D2_800FF070 *e4 = SELF->c;
        for (; q4->type >= 0; q4++, e4++) {
            TObjPlayer__sub_800FF1FC((f32 *)e4, (f32 *)(base + 0x20));
        }
        TObjPlayer__sub_800FF1FC((f32 *)e4, (f32 *)(base + 0x20));
    }
    ((TObjEZRopeBase *)arg0)->sub_800FF8CC((void *)SELF->a, (void *)SELF->b, (s32)SELF->c);
    return arg0;
}

void TObjPlayer__sub_800FF1FC(f32 *arg0, f32 *arg1) {
    *arg0 = *arg1;
    *(ByteBlock_C *)((s32) arg0 + 4) = *(const ByteBlock_C *)((s32) arg1 + 4);
}

void TObjPlayer__sub_800FF220(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
    *(ByteBlock_C *)((s32) arg0 + 4) = *(const ByteBlock_C *)((s32) arg1 + 4);
}

void TObjPlayer__sub_800FF244(u8 *arg0, u8 *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(ByteBlock_C *)((s32) arg0 + 4) = *(const ByteBlock_C *)((s32) arg1 + 4);
    *(s32 *)((s8 *)arg0 + 0x10) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
}

void *TObjPlayer::create_hairmove(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x48);
    if (o != NULL) {
        o = TObjHMS_EZRope_Player__ct(o, this, arg1, arg2);
    }
    return o;
}
void TObjHMS_EZRope_Player::sub_800FF2D0() {
    Obj_800FF2D0 *arg0 = (Obj_800FF2D0 *)this;
    Vec d;
    Rec_800FF2D0 *rec;
    Ang_800FF2D0 *ang;
    Vec *pt;
    s32 n;
    s32 yaw;
    Blob_800FF2D0 *b;
    if (arg0->f1C == 0 || arg0->recs == NULL || arg0->angs == NULL || arg0->pts == NULL) {
        return;
    }
    rec = arg0->recs;
    ang = arg0->angs;
    pt = arg0->pts;
    for (; rec->n >= 2; rec++, ang++) {
        for (n = rec->n - 1; n > 0; n--, pt++) {
            push_matrix();
            translate_matrix_vec3((u8 *)(0), (u8 *)pt);
            VecCopy(&d, &pt[1]);
            subtract_vector(&d, pt);
            if (0.0f == vector_length(&d)) {
                d.x = 0.0f;
                d.y = -1.0f;
                d.z = 0.0f;
            } else {
                normalize_vector(&d);
            }
            yaw = 0;
            if (0.0f != fabs_float(d.x) + fabs_float(d.z)) {
                yaw = (s32)(10430.38043493439 * atan2_float(-d.x, -d.z));
                rotate_matrix_y(0, yaw);
            }
            rotate_matrix_x(0, (s32)(10430.38043493439 * get_scale_factor__10TObjPlayerFv(-d.y)));
            rotate_matrix_y(0, ang->a - yaw);
            if (n == 1) {
                if (rec->f14 != NULL) {
                    draw_chunk_object(rec->f14);
                }
            } else if (rec->f10 != NULL) {
                draw_chunk_object(rec->f10);
            }
            pop_matrix();
        }
        pt++;
    }
    if (arg0->blobs != NULL) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x10;
        set_chunk_material_override_pair(0, 0x800);
        set_constant_material((const NJS_ARGB *)ezrope_chunk_material_color_table);
        for (b = arg0->blobs; b->scale >= 0.0f; b++) {
            f32 s;
            push_matrix();
            translate_matrix_vec3((u8 *)(0), (u8 *)&b->pos);
            s = 0.2f * b->scale;
            scale_matrix(0, s, s, s);
            draw_chunk_object(lbl_8048DEF4);
            pop_matrix();
        }
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
}

}

struct Src_800FF8CC {
    s8 count;
    u8 pad[3];
    Vec rot;
    u8 pad2[8];
};

struct Pos_800FF8CC {
    u32 f0;
    Vec v;
};

struct Self_800FF8CC {
    u8 pad[0x1C];
    s32 num;
    Src_800FF8CC *src;
    Pos_800FF8CC *pos;
    s32 arg;
    Vec *out;
};

struct Seg_800FF788 { s8 n; u8 pad1[3]; Vec dir; u8 pad10[8]; };

struct Src_800FF788 { s32 a; Vec v; };

struct Obj_800FF788 {
    u8 pad0[0x20];
    Seg_800FF788 *segs;
    Src_800FF788 *srcs;
    u32 flag;
    Vec *out;
};

extern "C" {
void fn_800FF580(Obj_800FF788 *self, Vec *p, f32 len);

// One of the rope's collision spheres; the list ends at a negative radius.
struct Collider_800FF580 {
    f32 radius;
    Vec center;
};

void fn_800FF580(Obj_800FF788 *self, Vec *p, f32 len) {
    Vec v = *p;
    Vec hit;
    s32 iter;
    Collider_800FF580 *c;
    f32 push;
    f32 d;
    f32 best;
    f32 reach;

    iter = 16;
    while (1) {
        best = 0.0f;
        for (c = (Collider_800FF580 *)self->flag; c->radius >= 0.0f; c++) {
            reach = 0.5f * len + c->radius;
            d = xyz_distance(&v, &c->center);
            if (d < reach && reach - d > best) {
                best = reach - d;
                push = reach;
                VecCopy(&hit, &c->center);
            }
        }
        if (iter <= 0 || 0.0f == best) {
            VecCopy(p, &v);
            return;
        }
        subtract_vector(&v, &hit);
        if (0.0f == vector_length(&v)) {
            v.x = 0.0f;
            v.y = -1.0f;
            v.z = 0.0f;
        } else {
            normalize_vector(&v);
        }
        v.x *= push;
        v.y *= push;
        v.z *= push;
        vec3_add_to(&v, &hit);
        subtract_vector(&v, p - 1);
        if (0.0f == vector_length(&v)) {
            v.x = 0.0f;
            v.y = -1.0f;
            v.z = 0.0f;
        } else {
            normalize_vector(&v);
        }
        v.x *= len;
        v.y *= len;
        v.z *= len;
        vec3_add_to(&v, p - 1);
        iter--;
    }
}

void TObjEZRopeBase::sub_800FF788(void *mtx) {
    Seg_800FF788 *seg;
    Src_800FF788 *src;
    Vec *p;
    s32 n;
    f32 zero;
    f32 len;
    zero = 0.0f;
    seg = ((Obj_800FF788 *)this)->segs;
    src = ((Obj_800FF788 *)this)->srcs;
    p = ((Obj_800FF788 *)this)->out;
    while (seg->n >= 2) {
        len = vector_length(&seg->dir);
        VecCopy(p, &src->v);
        p++;
        n = seg->n - 1;
        while (n > 0) {
            vec3_add_to(p, (Vec *)mtx);
            subtract_vector(p, p - 1);
            if (zero == vector_length(p)) {
                p->x = zero;
                p->y = -1.0f;
                p->z = zero;
            } else {
                normalize_vector(p);
            }
            p->x *= len;
            p->y *= len;
            p->z *= len;
            vec3_add_to(p, p - 1);
            if (((Obj_800FF788 *)this)->flag != 0) {
                fn_800FF580(((Obj_800FF788 *)this), p, len);
            }
            n--;
            p++;
        }
        seg++;
        src++;
    }
}

void TObjEZRopeBase::sub_800FF8CC(void *src_arg, void *pos_arg, s32 arg) {
    Src_800FF8CC *src = (Src_800FF8CC *)src_arg;
    Pos_800FF8CC *pos = (Pos_800FF8CC *)pos_arg;
    s32 total;
    Src_800FF8CC *s;
    Pos_800FF8CC *p;
    Vec *out;
    s32 n;
    total = 0;
    ((Self_800FF8CC *)this)->src = src;
    ((Self_800FF8CC *)this)->pos = pos;
    ((Self_800FF8CC *)this)->arg = arg;
    ((Self_800FF8CC *)this)->num = 0;
    for (s = src; s->count >= 2; s++) {
        total += s->count;
        ((Self_800FF8CC *)this)->num++;
    }
    ((Self_800FF8CC *)this)->out = (Vec *)TQuestVmDownLoadServer::alloc(total * 0xC);
    s = ((Self_800FF8CC *)this)->src;
    p = ((Self_800FF8CC *)this)->pos;
    out = ((Self_800FF8CC *)this)->out;
    for (; s->count >= 2; s++, p++) {
        Vec v = p->v;
        for (n = s->count; n > 0; n--, out++) {
            VecCopy(out, &v);
            vec3_add_to(&v, &s->rot);
        }
    }
}

}
