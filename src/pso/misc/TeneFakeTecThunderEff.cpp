#include "pso/system/ChunkMaterialState.h"
#include "pso/TEneEffHamon.h"
#include "pso/misc/TeneFakeTecThunderEff.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"


#include "types.h"
#include "pso/misc/TWindowDD.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_800A4204_lbl_80490A18 {
    s32 value;
    u8 remaining[0x14];
};

typedef struct Hamon_800A36A8 {
    u8 pad0[0x1C];
    u8 mtx1C[0x34 - 0x1C];
    f32 scale;
    u8 pad38[0x40 - 0x38];
    f32 f40;
    u8 pad44[0x4C - 0x44];
    s32 delay;
    u8 color50[0x10];
} Hamon_800A36A8;

struct Vec_800A4064 { f32 x, y, z; };

struct Inner_800A4064 { u8 pad0[0xC]; s32 *p; };

struct Entry_800A4064 { u8 pad0[8]; Inner_800A4064 *inner; };

struct Obj_800A4064 {
    u8 pad0[0x38];
    s32 count;
    Vec_800A4064 base[(0x108 - 0x3C) / 12];
    Vec_800A4064 out[(0x1D4 - 0x108) / 12];
    Vec_800A4064 dir[22];
    u8 pad2DC[8];
    f32 scale[(0x328 - 0x2E4) / 4];
    s32 timer;
    u8 pad32C[0x330 - 0x32C];
    s32 type;
    u8 pad334[0x340 - 0x334];
    s32 active;
};

typedef struct Cam_800A3D1C { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_800A3D1C;

struct Vec_800A3D1C { f32 x, y, z; };

struct Vtx_800A3D1C { f32 x, y, z, u, v; u32 color; };

struct Obj_800A3D1C {
    u8 pad0[0x38];
    s32 count;
    u8 pad3C[0x108 - 0x3C];
    Vec_800A3D1C pts[17];
    u8 pad1D4[0x32C - 0x1D4];
    u32 color;
    u8 pad330[0x10];
    s32 active;
};

extern "C" {
void build_beam_points__12TTecZondeEffFPv(struct Obj_800A39A8 *);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__21TeneFakeTecThunderEff[];
extern s32 lbl_805D29E0;
u8 *TObjPlayer__sub_800A4204(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
f32 sin_table_lookup(s32);
extern Entry_800A4064 *player_effect_task_list[];
extern s32 TObjPlayer__effect_count;
extern const f32 lbl_805D99F8;
extern const f32 lbl_805D9A04;
extern const f32 lbl_805D9A08;
f32 newton_sqrtf(f32);
s32 matrix_mult_vec(int, void *, void *);
extern Cam_800A3D1C lbl_8058D4F8;
extern const f32 lbl_805D99F0;
extern const f32 lbl_805D99FC;
extern const f32 lbl_805D9A00;

struct Vec_800A39A8 { f32 x, y, z; };
struct Obj_800A39A8 {
    u8 pad0[0x1C];
    Vec_800A39A8 a;
    Vec_800A39A8 d;
    f32 step;
    s32 count;
    Vec_800A39A8 pts[34];
    Vec_800A39A8 dirs[17];
    f32 t[17];
    f32 r[21];
    Vec_800A39A8 *from;
    Vec_800A39A8 *to;
    u8 pad340[4];
    s32 n;
};

f32 fabs_float(f32);
f32 rand_signed_unit();
s32 update_scale__15TObjBoss2TunnelFv(void *);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
extern const f32 lbl_805D99F4;
#pragma push
#pragma fp_contract on
void build_beam_points__12TTecZondeEffFPv(Obj_800A39A8 *o) {
    f32 len;
    f32 ax;
    f32 ay;
    f32 az;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 axis;
    f32 fx;
    f32 fy;
    f32 fz;
    Vec_800A39A8 *p;

    VecCopy((Vec *)&o->a, (const Vec *)o->from);
    VecCopy((Vec *)&o->d, (const Vec *)o->to);
    subtract_vector(&o->d, o->from);
    len = vector_length(&o->d);
    o->step = len / o->n;
    ax = o->a.x;
    ay = o->a.y;
    az = o->a.z;
    dx = o->d.x;
    dy = o->d.y;
    dz = o->d.z;
    o->count = 0;
    for (i = 0; i < o->n; i++) {
        f32 tt = (o->step * i) / (o->n - 1);
        o->t[i] = tt;
        o->pts[i].x = dx * tt + ax;
        o->pts[i].y = dy * tt + ay;
        o->pts[i].z = dz * tt + az;
    }
    o->count = o->n;
    fx = fabs_float(o->d.x);
    fy = fabs_float(o->d.y);
    fz = fabs_float(o->d.z);
    if (fx > fy) {
        if (fx > fz) {
            axis = 0;
        } else {
            axis = 2;
        }
    } else if (fy > fz) {
        axis = 1;
    } else {
        axis = 2;
    }
    p = o->dirs;
    switch (axis) {
    case 0: {
        f32 u;
        f32 k;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = lbl_805D99F0 / o->d.x;
        e1 = o->d.y;
        e2 = o->d.z;
        k = lbl_805D99F4;
        for (i = 0; i < o->count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->y = u;
            p->z = v;
            p->x = inv * (u * e1 + v * e2);
            update_scale__15TObjBoss2TunnelFv(p);
            p++;
        }
        break;
    }
    case 1: {
        f32 u;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = lbl_805D99F0 / o->d.y;
        e1 = o->d.z;
        e2 = o->d.x;
        f32 k;
        k = lbl_805D99F4;
        for (i = 0; i < o->count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->z = u;
            p->x = v;
            p->y = inv * (u * e1 + v * e2);
            update_scale__15TObjBoss2TunnelFv(p);
            p++;
        }
        break;
    }
    case 2: {
        f32 u;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = lbl_805D99F0 / o->d.z;
        e1 = o->d.x;
        e2 = o->d.y;
        f32 k;
        k = lbl_805D99F4;
        for (i = 0; i < o->count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->x = u;
            p->y = v;
            p->z = inv * (u * e1 + v * e2);
            update_scale__15TObjBoss2TunnelFv(p);
            p++;
        }
        break;
    }
    }
    for (i = 1; i < o->count - 1; i++) {
        o->r[i] = lbl_805D99F8 * rand_signed_unit();
    }
    o->r[0] = lbl_805D99FC;
    o->r[o->count - 1] = lbl_805D99FC;
#undef o
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TeneFakeTecThunderEff::render() {
    Obj_800A3D1C *o = (Obj_800A3D1C *)this;
    Vtx_800A3D1C verts[34];
    Vec_800A3D1C out[17];
    f32 sa[17];
    f32 sb[17];
    Vec_800A3D1C v;
    f32 sw;
    f32 sh;
    f32 cy;
    f32 cx;
    f32 one;
    f32 prevX;
    f32 prevY;
    f32 prevZ;
    f32 curX;
    f32 curY;
    f32 dx;
    f32 dy;
    f32 vv;
    f32 u0;
    f32 w;
    f32 a;
    f32 b;
    f32 inv;
    f32 nx;
    f32 ny;
    u32 color;
    Vec_800A3D1C *q;
    Vtx_800A3D1C *p;
    s32 i;
    s32 j;
    if (this->m_340 == 0) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    sw = lbl_8058D4F8.sw;
    cx = lbl_8058D4F8.cx;
    cy = lbl_8058D4F8.cy;
    sh = sw * (lbl_805D9A00 / (lbl_805D9A00 * lbl_8058D4F8.aspect));
    color = o->color | 0xFFFFFF;
    for (i = 0; i < this->m_38; i++) {
        matrix_mult_vec(0, &o->pts[i], &v);
        if (v.z >= lbl_805D99F0) {
            v.z = lbl_805D99F0;
        }
        w = lbl_805D99F0 / -v.z;
        v.y = -v.y;
        a = sh * w;
        b = sw * w;
        out[i].x = v.x * a + cx;
        sa[i] = a;
        out[i].y = v.y * b + cy;
        sb[i] = b;
        out[i].z = w;
    }
    vv = lbl_805D99FC;
    u0 = vv;
    p = verts;
    q = &out[1];
    prevX = out[0].x;
    prevY = out[0].y;
    prevZ = out[0].z;
    one = lbl_805D99F0;
    for (j = 0; j < this->m_38 - 1; j++) {
        curY = q->y;
        curX = q->x;
        dy = curY - prevY;
        dx = curX - prevX;
        inv = one / newton_sqrtf(dx * dx + dy * dy);
        dx *= inv;
        dy *= inv;
        nx = one * (dy * sa[j]);
        ny = one * (-dx * sb[j]);
        p[0].x = prevX + nx;
        p[0].y = prevY + ny;
        p[0].z = prevZ;
        p[0].u = u0;
        p[0].v = vv;
        p[0].color = color;
        p[1].x = prevX - nx;
        p[1].y = prevY - ny;
        p[1].z = prevZ;
        prevZ = q->z;
        q++;
        p[1].u = one;
        p[1].v = vv;
        vv += one;
        p[1].color = color;
        p += 2;
        prevX = curX;
        prevY = curY;
    }
    nx = lbl_805D99F0 * (dy * sa[this->m_38 - 1]);
    ny = lbl_805D99F0 * (-dx * sb[this->m_38 - 1]);
    p[0].x = prevX + nx;
    p[0].y = prevY + ny;
    p[0].z = prevZ;
    p[0].u = lbl_805D99FC;
    p[0].v = vv;
    p[0].color = color;
    p[1].x = prevX - nx;
    p[1].y = prevY - ny;
    p[1].z = prevZ;
    p[1].u = lbl_805D99F0;
    p[1].v = vv;
    p[1].color = color;
    set_additive_blend();
    ((TWindowDD *)verts)->draw_transformed_primitive((void*)(this->m_38 * 2), (void*)TObjPlayer__effect_count, (void*)1);
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TeneFakeTecThunderEff::run_task() {
    Obj_800A4064 *self = (Obj_800A4064 *)this;
    s32 i;
    if (this->m_340 != 0) {
        build_beam_points__12TTecZondeEffFPv((Obj_800A39A8 *)self);
        TObjPlayer__effect_count = *player_effect_task_list[0][this->m_330].inner->p;
        for (i = 0; i < this->m_38; i++) {
            self->scale[i] = lbl_805D99F8 * (lbl_805D9A08 * sin_table_lookup(this->m_328 * 0x1800) + lbl_805D9A04);
        }
        for (i = 0; i < this->m_38; i++) {
            f32 s = self->scale[i];
            self->out[i].x = self->dir[i].x * s + self->base[i].x;
            self->out[i].y = self->dir[i].y * s + self->base[i].y;
            self->out[i].z = self->dir[i].z * s + self->base[i].z;
        }
        this->m_328++;
    }
}
#pragma pop

}
TeneFakeTecThunderEff::~TeneFakeTecThunderEff() {

}

typedef char RecoveredGlobal_800A4204_lbl_80490A18_size[sizeof(RecoveredGlobal_800A4204_lbl_80490A18) == 0x18 ? 1 : -1];
u8 *TObjPlayer__sub_800A4204(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800A4204_lbl_80490A18 *)&__vt__21TeneFakeTecThunderEff).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D29E0;
    ((TeneFakeTecThunderEff *)arg0)->m_338 = arg2;
    *(s32 *)((s8 *)arg0 + 0x33C) = arg3;
    ((TeneFakeTecThunderEff *)arg0)->m_330 = 0;
    *(s32 *)((s8 *)arg0 + 0x334) = 0;
    *(s32 *)((s8 *)arg0 + 0x344) = arg4;
    build_beam_points__12TTecZondeEffFPv((Obj_800A39A8 *)arg0);
    ((TeneFakeTecThunderEff *)arg0)->m_328 = 0;
    *(s32 *)((s8 *)arg0 + 0x32C) = 0xFF000000;
    ((TeneFakeTecThunderEff *)arg0)->m_340 = 0;
    return arg0;
}

