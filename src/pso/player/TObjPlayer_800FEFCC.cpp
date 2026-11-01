#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/TObjEZRopeBase.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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

struct Vec_800FF2D0 { f32 x, y, z; };

struct Rec_800FF2D0 { s8 n; u8 pad1[0x10 - 1]; void *f10; void *f14; };

struct Ang_800FF2D0 { s32 a; u8 pad4[0xC]; };

struct Blob_800FF2D0 { f32 scale; Vec_800FF2D0 pos; };

struct Obj_800FF2D0 {
    u8 pad0[0x1C];
    s32 f1C;
    Rec_800FF2D0 *recs;
    Ang_800FF2D0 *angs;
    Blob_800FF2D0 *blobs;
    Vec_800FF2D0 *pts;
};

extern "C" {
void TObjPlayer__sub_800FF220(s32 *arg0, s32 *arg1);
void TObjPlayer__sub_800FF1FC(f32 *arg0, f32 *arg1);
void TObjPlayer__sub_800FF244(u8 *arg0, u8 *arg1);
void *TObjEZRopeBase__ct(void *);
extern u8 ezrope_chunk_material_color_table[];
extern s32 TObjHMS_EZRope_Player__name;
void *TObjHMS_EZRope_Player__ct(void *arg0, void *arg1, void *arg2, void *arg3);
f32 fabs_float(f32);
f32 atan2_float(f32, f32);
f32 get_scale_factor__10TObjPlayerFv(f32);
s32 scale_matrix(int, f32, f32, f32);
f32 vector_length(void *);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 subtract_vector(void *, void *);
s32 rotate_matrix_x(int, int);
s32 normalize_vector(void *);
s32 push_matrix();
s32 pop_matrix();
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
void draw_chunk_object(void *child);
extern const f64 lbl_8043DF40;
extern u8 lbl_8048DEF4[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805DAA58;
extern const f32 lbl_805DAA5C;
extern const f32 lbl_805DAA60;
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
    Vec_800FF2D0 d;
    Rec_800FF2D0 *rec;
    Ang_800FF2D0 *ang;
    Vec_800FF2D0 *pt;
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
            VecCopy((Vec *)&d, (const Vec *)&pt[1]);
            subtract_vector(&d, pt);
            if (lbl_805DAA58 == vector_length(&d)) {
                d.x = lbl_805DAA58;
                d.y = lbl_805DAA5C;
                d.z = lbl_805DAA58;
            } else {
                normalize_vector(&d);
            }
            yaw = 0;
            if (lbl_805DAA58 != fabs_float(d.x) + fabs_float(d.z)) {
                yaw = (s32)(lbl_8043DF40 * atan2_float(-d.x, -d.z));
                rotate_matrix_y(0, yaw);
            }
            rotate_matrix_x(0, (s32)(lbl_8043DF40 * get_scale_factor__10TObjPlayerFv(-d.y)));
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
        for (b = arg0->blobs; b->scale >= lbl_805DAA58; b++) {
            f32 s;
            push_matrix();
            translate_matrix_vec3((u8 *)(0), (u8 *)&b->pos);
            s = lbl_805DAA60 * b->scale;
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
