#include "pso/TTecZondeEff.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecZonde.h"

#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowDD.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8023D988___vt__12TTecZondeEff {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8023DADC___vt__12TTecZondeEff {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8023DA10___vt__12TTecZondeEff {
    s32 value;
    u8 remaining[0x14];
};

struct P_8023DBB4 { void *vt; s32 n; u8 pad[4]; };

struct Rec_8023D4A8 { f32 a, b, c; };

struct Obj_8023D4A8 {
    u8 pad0[0x38];
    s32 count;
    u8 pad3c[0x174 - 0x3C];
    Rec_8023D4A8 recs[1];
    u8 pad180[0x210 - 0x180];
    f32 w[1];
};

struct Rec_8023D568 { f32 x, y, z; };

struct Obj_8023D568 {
    u8 pad0[0x1C];
    Rec_8023D568 a;
    Rec_8023D568 d;
    f32 len;
    s32 count;
    Rec_8023D568 pts[1];
};

struct C_8023D7A0 { s32 v; };

struct B_8023D7A0 { u8 pad[0xc]; C_8023D7A0 *c; };

struct E_8023D7A0 { u8 pad[8]; B_8023D7A0 *b; };

struct V_8023D7A0 { f32 x, y, z; };

struct Zonde_8023D7A0 {
    u8 pad0[0x38];
    s32 count;
    V_8023D7A0 base[(0xD8 - 0x3C) / 12];
    V_8023D7A0 pos[(0x174 - 0xD8) / 12];
    V_8023D7A0 dir[(0x210 - 0x174) / 12];
    f32 w[(0x248 - 0x210) / 4];
    s32 timer;
    u32 power;
    s32 idx;
    u32 decay;
    s32 start;
    u8 pad25c[2];
    s16 active;
};

struct Zonde_8023D6B0 {
    u8 pad[0x38];
    s32 count;
    u8 pad3c[0x25e - 0x3c];
    s16 active;
};

struct Vec_8023D128
{
  f32 x;
  f32 y;
  f32 z;
};

struct Cam_8023D128
{
  u8 pad0[8];
  f32 cx;
  f32 cy;
  u8 pad10[8];
  f32 sx;
  f32 sy;
};

struct Obj_8023D128
{
  u8 pad0[0x38];
  s32 count;
  u8 pad3c[0xD8 - 0x3C];
  Vec_8023D128 pts[16];
  u8 pad198[0x244 - 0x198];
  f32 f244;
};

struct Vec_8023CED4
{
  f32 x;
  f32 y;
  f32 z;
};

struct Vtx_8023CED4
{
  f32 x;
  f32 y;
  f32 z;
  f32 u;
  f32 v;
  u32 color;
};

struct Obj_8023CED4
{
  u8 pad0[0x38];
  s32 count;
  u8 pad3C[0x24C - 0x3C];
  u32 color;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8023D988___vt__12TTecZondeEff __vt__12TTecZondeEff;
extern s32 TTecZondeEff_class_name;
u8 *__ct__12TTecZondeEffFv(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 farg0);
extern P_8023DBB4 tec_zonde_effect_task_list;
extern char lbl_804CC8C8[];
extern s32 TTecZondeEff__beam_vertex_data;
f32 rand_signed_unit();
void randomize_bolt_jitter__12TTecZondeEffFv(Obj_8023D4A8 *arg0);
s32 is_split_screen(void);
void spawn_particle_effect(Rec_8023D568 *, s32);
void queue_destruction__7TObjectFv(void *);
void restore_saved_depth_alpha_state();
extern f32 chunk_material_color_half_alpha_f32[];
extern u32 saved_model_render_flags;
extern u32 model_render_flags;
void matrix_mult_vec(s32, Vec_8023D128 *, Vec_8023D128 *);
extern Cam_8023D128 lbl_8058D4F8;
s32 project_lightning_points(Obj_8023D128 *self, Vec_8023D128 *out, f32 *a, f32 *b);
f32 newton_sqrtf(f32);
void clear_zonde_beam_vertex_pointer(void);
f32 fabs_float(f32);

struct Vec_8023D294 { f32 x, y, z; };
struct Obj_8023D294 { u8 pad[0x28]; Vec_8023D294 d; };

extern "C" {


#pragma push
#pragma fp_contract on
typedef struct Cam_8023D128 Cam_8023D128;
typedef struct Obj_8023D128 Obj_8023D128;
typedef struct Vec_8023D128 Vec_8023D128;

typedef struct Obj_8023CED4 Obj_8023CED4;
typedef struct Vec_8023CED4 Vec_8023CED4;
typedef struct Vtx_8023CED4 Vtx_8023CED4;
#pragma fp_contract on
s32 TTecZondeEff::build_lightning_strip(void *out_arg, void *pts_arg, f32 *widths, f32 *heights) {
    Vtx_8023CED4 *out = (Vtx_8023CED4 *)out_arg;
    Vec_8023CED4 *pts = (Vec_8023CED4 *)pts_arg;
  f32 px;
  f32 py;
  f32 pz;
  f32 nx;
  f32 ny;
  f32 dx;
  f32 dy;
  f32 v;
  f32 inv;
  f32 ox;
  f32 oy;
  f32 scale;
  u32 color;
  Vtx_8023CED4 *o;
  Vec_8023CED4 *p;
  s32 i;
  v = 0.0f;
  scale = 1.0f;
  px = pts->x;
  py = pts->y;
  pz = pts->z;
  color = 0xFFFFFF | ((Obj_8023CED4 *)this)->color;
  p = pts + 1;
  o = out;
  for (i = 0; i < (((Obj_8023CED4 *)this)->count - 1); i++)
  {
    ny = p->y;
    nx = p->x;
    dy = ny - py;
    dx = nx - px;
    if (((dx * dx) + (dy * dy)) == 0.0f)
    {
      return 0;
    }
    inv = 1.0f / newton_sqrtf((dx * dx) + (dy * dy));
    dx *= inv;
    p->z = p->z;
    dy *= inv;
    ox = scale * (dy * widths[i]);
    oy = scale * ((-dx) * heights[i]);
    o[0].x = px + ox;
    o[0].y = py + oy;
    o[0].z = pz;
    o[0].u = 0.0f;
    o[0].v = v;
    o[0].color = color;
    o[1].x = px - ox;
    o[1].y = py - oy;
    o[1].z = pz;
    o[1].u = 1.0f;
    o[1].v = v;
    v += 1.0f;
    o[1].color = color;
    o += 2;
    px = nx;
    py = ny;
    pz = p->z;
    p++;
  }
  ox = scale * (dy * widths[((Obj_8023CED4 *)this)->count - 1]);
  oy = scale * ((-dx) * heights[((Obj_8023CED4 *)this)->count - 1]);
  o[0].x = px + ox;
  o[0].y = py + oy;
  o[0].z = pz;
  o[0].u = 0.0f;
  o[0].v = v;
  o[0].color = color;
  o[1].x = px - ox;
  o[1].y = py - oy;
  o[1].z = pz;
  o[1].u = 1.0f;
  o[1].v = v;
  o[1].color = color;
  return 1;
}

s32 project_lightning_points(Obj_8023D128 *self, Vec_8023D128 *out, f32 *a, f32 *b) {
  f32 sy0;
  f32 sx0;
  f32 cx;
  f32 cy;
  s32 i;
  sy0 = lbl_8058D4F8.sx;
  sx0 = lbl_8058D4F8.sx * (480.0f / (480.0f * lbl_8058D4F8.sy));
  cx = lbl_8058D4F8.cx;
  cy = lbl_8058D4F8.cy;
  for (i = 0; i < self->count; i++)
  {
    Vec_8023D128 v;
    f32 w;
    f32 sx;
    f32 sy;
    matrix_mult_vec(0, &self->pts[i], &v);
    if (v.z >= 1.0f)
    {
      self->f244 = self->f244;
      v.z = 1.0f;
    }
    w = 1.0f / (-v.z);
    v.y = -v.y;
    sx = sx0 * w;
    sy = sy0 * w;
    out[i].x = (v.x * sx) + cx;
    out[i].y = (v.y * sy) + cy;
    out[i].z = w;
    a[i] = sx * self->f244;
    b[i] = 1.8f * sy;
  }
  return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TTecZondeEff::calc_lightning_scatter_direction(s32 axis, void *arg2) {
    void *arg0 = (void *)this;
    Obj_8023D294 *o = (Obj_8023D294 *)arg0;
    Vec_8023D294 *out = (Vec_8023D294 *)arg2;

    switch (axis) {
    case 0: {
        f32 a, inv, q, p, b;
        inv = 1.0f / o->d.x;
        p = o->d.y;
        q = o->d.z;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->y = a;
        out->z = b;
        out->x = inv * (a * p + b * q);
        ((TObjBoss2Tunnel *)out)->update_scale();
        break;
    }
    case 1: {
        f32 a, inv, q, p, b;
        inv = 1.0f / o->d.y;
        p = o->d.z;
        q = o->d.x;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->z = a;
        out->x = b;
        out->y = inv * (a * p + b * q);
        ((TObjBoss2Tunnel *)out)->update_scale();
        break;
    }
    case 2: {
        f32 a, inv, q, p, b;
        inv = 1.0f / o->d.z;
        p = o->d.x;
        q = o->d.y;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->x = a;
        out->y = b;
        out->z = inv * (a * p + b * q);
        ((TObjBoss2Tunnel *)out)->update_scale();
        break;
    }
    }
}
#pragma pop

}

s32 TTecZondeEff::calc_dominant_axis() {
    f32 temp_f1;
    f32 temp_f30;
    f32 temp_f31;

    temp_f30 = fabs_float(*(f32 *)((s8 *)this + 0x28));
    temp_f31 = fabs_float(*(f32 *)((s8 *)this + 0x2C));
    temp_f1 = fabs_float(*(f32 *)((s8 *)this + 0x30));
    if (temp_f30 > temp_f31) {
        if (temp_f30 > temp_f1) {
            return 0;
        }
        return 2;
    }
    if (temp_f31 > temp_f1) {
        return 1;
    }
    return 2;
}

typedef char RecoveredGlobal_8023D988___vt__12TTecZondeEff_size[sizeof(RecoveredGlobal_8023D988___vt__12TTecZondeEff) == 0x18 ? 1 : -1];

void TTecZondeEff::randomize_bolt_jitter() {
    Rec_8023D4A8 *p;
    s32 axis;
    s32 i;
    f32 k;
    Obj_8023D4A8 *arg0 = (Obj_8023D4A8 *)this;
    axis = ((TTecZondeEff *)arg0)->calc_dominant_axis();
    p = arg0->recs;
    for (i = 0; i < arg0->count; i++, p++) {
        ((TTecZondeEff *)arg0)->calc_lightning_scatter_direction(axis, p);
    }
    k = 8.0f;
    for (i = 1; i < arg0->count - 1; i++) {
        arg0->w[i] = k * rand_signed_unit();
    }
    arg0->w[0] = 0.0f;
    arg0->w[arg0->count - 1] = 0.0f;
}

#pragma push
#pragma fp_contract on
void TTecZondeEff::init_bolt_points() {
    Obj_8023D568 *o = (Obj_8023D568 *)this;
    f32 x0 = o->a.x;
    f32 y0 = o->a.y;
    f32 z0 = o->a.z;
    f32 dx = o->d.x;
    f32 dy = o->d.y;
    f32 dz = o->d.z;
    s32 i;
    for (i = 0; i < o->count; i++) {
        f32 t = (o->len * (f32)i) / (o->count - 1);
        o->pts[i].x = dx * t + x0;
        o->pts[i].y = dy * t + y0;
        o->pts[i].z = dz * t + z0;
        if (is_split_screen() == 0) {
            spawn_particle_effect(&o->pts[i], 0x1F0);
        }
    }
}
#pragma pop

void TTecZondeEff::render() {
    Zonde_8023D6B0 *self = (Zonde_8023D6B0 *)this;
    u32 verts[0x270 / 4];
    u32 m70[0x9c / 4];
    u32 m3c[0x34 / 4];
    u32 m8[0x34 / 4];
    u32 id;
    if (self->active == 0 || TOKeyMachine01::get_global_state() == 0 || TOKeyMachine01::get_global_state() == 0xF) {
        return;
    }
    if (((TObject *)self)->all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x10;
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    if (project_lightning_points((Obj_8023D128 *)(self), (Vec_8023D128 *)(m70), (f32 *)m3c, (f32 *)m8) != 0 && ((TTecZondeEff *)self)->build_lightning_strip((Vtx_8023CED4 *)(verts), (Vec_8023CED4 *)(m70), (f32 *)m3c, (f32 *)m8) != 0) {
        TObjPlayer::init_xyz_limits();
        ((TWindowDD *)verts)->draw_transformed_primitive((void*)(self->count * 2), (void*)TTecZondeEff__beam_vertex_data, (void*)1);
        TObjPlayer::reset_transform_state();
    }
    TParticleCtrl::end_effect_render();
    ((TUnk_80494AE0 *)chunk_material_color_half_alpha_f32)->set_chunk_material_color();
    model_render_flags = saved_model_render_flags;
    restore_saved_depth_alpha_state();
}

#pragma push
#pragma fp_contract on
void TTecZondeEff::run_task() {
    Zonde_8023D7A0 *arg0 = (Zonde_8023D7A0 *)this;
    s32 i;
    f32 s;
    E_8023D7A0 *e;
    e = (E_8023D7A0 *)tec_zonde_effect_task_list.vt;
    e += arg0->idx;
    TTecZondeEff__beam_vertex_data = e->b->c->v;
    if (arg0->timer > 0x78) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    for (i = 0; i < arg0->count; i++) {
        arg0->w[i] -= 0.05f;
        if (arg0->w[i] <= 1.0f) {
            arg0->w[i] = 1.0f;
        }
    }
    for (i = 0; i < arg0->count; i++) {
        s = arg0->w[i];
        arg0->pos[i].x = arg0->dir[i].x * s + arg0->base[i].x;
        arg0->pos[i].y = arg0->dir[i].y * s + arg0->base[i].y;
        arg0->pos[i].z = arg0->dir[i].z * s + arg0->base[i].z;
    }
    arg0->active = 1;
    if (arg0->timer > arg0->start) {
        if (arg0->power > arg0->decay) {
            arg0->power -= arg0->decay;
            if ((f32)arg0->power <= 0.0f) {
                arg0->power = 0;
            }
        } else {
            arg0->power = 0;
            arg0->timer = 0x79;
        }
    }
    arg0->timer++;
}
#pragma pop

TTecZondeEff::~TTecZondeEff() {}

u8 *__ct__12TTecZondeEffFv(u8 *object, u8 *arg1, s32 arg2, s32 arg3, f32 farg0) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__12TTecZondeEff.value;
    *(s32 *)((s8 *)object + 0) = (s32) TTecZondeEff_class_name;
    *(f32 *)((s8 *)object + 0x244) = farg0;
    *(s32 *)((s8 *)object + 0x254) = arg2;
    *(s32 *)((s8 *)object + 0x258) = arg3;
    *(s32 *)((s8 *)object + 0x250) = 0;
    *(s16 *)((s8 *)object + 0x25C) = 0;
    *(s32 *)((s8 *)object + 0x38) = 0xD;
    *(s32 *)((s8 *)object + 0x248) = 0;
    *(s32 *)((s8 *)object + 0x24C) = 0xFF000000;
    *(s16 *)((s8 *)object + 0x25E) = 0;
    return object;
}

typedef char RecoveredGlobal_8023DADC___vt__12TTecZondeEff_size[sizeof(RecoveredGlobal_8023DADC___vt__12TTecZondeEff) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8023DA10___vt__12TTecZondeEff_size[sizeof(RecoveredGlobal_8023DA10___vt__12TTecZondeEff) == 0x18 ? 1 : -1];
u8 *TTecZonde::construct_bolt_effect(u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1) {
    __ct__7TObjectFP7TObject(this, arg1);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8023DA10___vt__12TTecZondeEff *)&__vt__12TTecZondeEff).value;
    *(s32 *)&this->m_name = (s32) TTecZondeEff_class_name;
    *(f32 *)((s8 *)((u8 *)this) + 0x244) = farg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x254) = arg4;
    *(s32 *)((s8 *)((u8 *)this) + 0x258) = arg5;
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)arg3);
    *(f32 *)((s8 *)((u8 *)this) + 0x34) = farg0;
    *(s32 *)((s8 *)((u8 *)this) + 0x250) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x25C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x38) = 0xD;
    ((TTecZondeEff *)((u8 *)this))->init_bolt_points();
    randomize_bolt_jitter__12TTecZondeEffFv((Obj_8023D4A8 *)(this));
    *(s32 *)((s8 *)((u8 *)this) + 0x248) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x24C) = 0xFF000000;
    *(s16 *)((s8 *)((u8 *)this) + 0x25E) = 0;
    return ((u8 *)this);
}

u8 *TTecZondeEff::construct(u8 *arg1, u8 *arg2, u8 *arg3, f32 farg0) {
    __ct__7TObjectFP7TObject(this, arg1);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8023DADC___vt__12TTecZondeEff *)&__vt__12TTecZondeEff).value;
    *(s32 *)&this->m_name = (s32) TTecZondeEff_class_name;
    *(f32 *)((s8 *)((u8 *)this) + 0x244) = 1.0f;
    *(s32 *)((s8 *)((u8 *)this) + 0x254) = 0x08000000;
    *(s32 *)((s8 *)((u8 *)this) + 0x258) = 0x14;
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)arg3);
    *(f32 *)((s8 *)((u8 *)this) + 0x34) = farg0;
    *(s32 *)((s8 *)((u8 *)this) + 0x250) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x25C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x38) = 0xD;
    this->init_bolt_points();
    randomize_bolt_jitter__12TTecZondeEffFv((Obj_8023D4A8 *)(this));
    *(s32 *)((s8 *)((u8 *)this) + 0x248) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x24C) = 0xFF000000;
    *(s16 *)((s8 *)((u8 *)this) + 0x25E) = 0;
    return ((u8 *)this);
}

void clear_zonde_beam_vertex_pointer(void) {
    TTecZondeEff__beam_vertex_data = 0;
}
void TTecZondeEff::init_resources() {
    tec_zonde_effect_task_list.vt = lbl_804CC8C8;
    tec_zonde_effect_task_list.n = 0x10;
    TTecZondeEff__beam_vertex_data = shared_effect_texture_list.entries[16].texture->surface->id;
}

}
