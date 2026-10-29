#ifndef PSO_TDEADSPOT_H
#define PSO_TDEADSPOT_H
#include "pso/TObject.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TDeadSpot.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/render/render_util.h"

#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804949D8.h"
#include "pso/misc/TUnk_804949F4.h"
#include "types.h"

class TDeadSpot : public TObject {
public:
    virtual ~TDeadSpot();
    virtual void run_task();
    virtual void render();
};
#endif

struct Stack_800D7E94
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct RecoveredGlobal_800D7F60_lbl_804949F4 {
    s32 value;
    u8 remaining[0x18];
};

#include <stddef.h>
#include "pso/TMainTask.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
struct Stack_800D7CF4 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct E_800D7FD4 { u8 pad[0x14]; u32 col; };

struct Obj_800D7FD4 { u8 pad0[0x1C]; E_800D7FD4 e[4]; u8 pad7c[0xC0 - 0x7C]; f32 c0; f32 c4; f32 c8; };

struct V3_800D80E4 { f32 x; f32 y; f32 z; };

struct E_800D80E4 { V3_800D80E4 v; u8 pad[8]; u32 col; };

struct Obj_800D80E4 { u8 pad0[0x18]; void *vt; E_800D80E4 e[4]; V3_800D80E4 base; V3_800D80E4 dir[4]; u8 padb8[8]; f32 sc; u8 padc4[4]; f32 c8; };

struct V3_800D8228 { f32 x; f32 y; f32 z; };

struct E_800D8228 { V3_800D8228 v; u8 pad[8]; u32 col; };

struct Obj_800D8228 { u8 pad0[0x18]; void *vt; E_800D8228 e[4]; V3_800D8228 base; V3_800D8228 dir[4]; u8 padb8[8]; f32 sc; f32 t; f32 c8; };

struct Vec_800D8314 { f32 x, y, z; };

struct Vtx_800D8314 { Vec_800D8314 pos; f32 u; f32 v; s32 color; };

struct Plane_800D8314 { Vec_800D8314 point; Vec_800D8314 normal; };

struct Ground_800D8314 { u32 unk; Plane_800D8314 *plane; };

struct Mark_800D8314 {
    s32 name;
    u8 pad4[0x18 - 0x4];
    void *vtable;
    Vtx_800D8314 vtx[4];
    Vec_800D8314 center;
    Vec_800D8314 corners[4];
    void *texture;
    s32 selector;
    f32 maxScale;
    f32 scale;
};

extern "C" {
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805DA380;
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_804949F4[];
u32 __cvt_fp2unsigned(f32);
extern const f32 TDeadSpot__data_805DA388;
extern const f32 TDeadSpot__data_805DA38C;
extern const f32 lbl_805DA390;
extern const f32 lbl_805DA394;
extern const f32 lbl_805DA398;
void update_fade_in_alpha__9TDeadSpotFPv(Obj_800D7FD4 *arg0);
extern s32 lbl_80494A10[];
Obj_800D80E4 *init_corner_vertices__9TDeadSpotFPv(Obj_800D80E4 *arg0, void * _w1, Vec_800D8314 * _w2, void * _w3, s32 _w4, s32 _w5, f32 _w6);
void run_task__9TDeadSpotFv(Obj_800D8228 *arg0);
Ground_800D8314 *csnVecterUnder(void *, s32);
}
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 rand();
s32 fn_803D8DE0(int, void *, void *, int);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
extern void *__vt__9TDeadSpot[];
extern s32 lbl_805D2A98;
extern const f32 lbl_805DA3A0;
extern const f32 lbl_805DA3A4;
extern const f32 lbl_805DA3A8;
extern const f32 lbl_805DA3AC;
extern const f32 lbl_805DA3B0;
extern const f32 lbl_805DA3B4;
extern const f32 lbl_805DA3B8;
Mark_800D8314 *__ct__9TDeadSpotFv(Mark_800D8314 *self, void *parent, Vec_800D8314 *point, void *texture, s32 selector, s32 delay, f32 maxScale);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void __dt__9TDeadSpotFv(void *, int);

extern s32 lbl_804949D8[];

#pragma push
#pragma opt_common_subs off
void TUnk_804949D8::vfunc_6() {
    typedef char sp8_offset[(offsetof(Stack_800D7CF4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800D7CF4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800D7CF4, sp10) == 0x8) ? 1 : -1];
    Stack_800D7CF4 stack;
    f32 temp_f1;
    s32 temp_r3;
    temp_r3 = TObjPlayer::calc_random_scaled();
    temp_f1 = this->m_28 * sin_table_lookup(temp_r3);
    stack.spC = lbl_805DA380;
    stack.sp8 = temp_f1;
    stack.sp10 = this->m_28 * cos_table_lookup(temp_r3);
    vec3_add_to(&stack.sp8, (u8 *)&this->unk_1C);
    TObjBoss2Tunnel::adjust_to_ground((s32)&stack.sp8, &stack.sp8);
    ((TParticleCtrl *)this->m_34)->set_position(&stack.sp8);
}
#pragma pop

void *__dt__13TUnk_804949D8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804949D8;
        __dt__13TUnk_804949F4Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *init__9TDeadSpotFPv(void *arg0, u8 * _w1, u8 * _w2, s32 _w3, f32 _w4) {
    construct_fire_base__9TDeadSpotFPvPvPvif((u8 *)arg0, (u8 *)_w1, (u8 *)_w2, (s32)_w3, _w4);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804949D8;
    ((TUnk_804949D8 *)arg0)->m_30 = 8;
    return arg0;
}

void update_lifetime__9TDeadSpotFPv(void *arg0) {
    u32 tmp34 = ((TUnk_804949F4 *)arg0)->m_34;
    if ((tmp34 == 0U) || (((TObject *)tmp34)->all_parents_unqueued_for_destruction() == 0)) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) (*(s32 *)((s8 *)arg0 + 0x2C) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x2C) >= (s32) ((TUnk_804949F4 *)arg0)->m_30) {
        *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        ((TUnk_804949F4 *)arg0)->vfunc_6();
    }
}

typedef struct Stack_800D7E94 Stack_800D7E94;
void TUnk_804949F4::vfunc_6() {
  Stack_800D7E94 stack;
  f32 temp_f1;
  s32 temp_r3;
  temp_r3 = TObjPlayer::calc_random_scaled();
  temp_f1 = (this->m_28) * sin_table_lookup((int) (temp_r3 & 0xFFFFFFFFu));
  stack.spC = lbl_805DA380;
  stack.sp8 = temp_f1;
  stack.sp10 = (this->m_28) * cos_table_lookup((int) temp_r3);
  vec3_add_to(&stack.sp8, (u8 *)&this->unk_1C);
  ((TParticleCtrl *)this->m_34)->set_position(&stack.sp8);
}

void *__dt__13TUnk_804949F4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804949F4;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_800D7F60_lbl_804949F4_size[sizeof(RecoveredGlobal_800D7F60_lbl_804949F4) == 0x1C ? 1 : -1];
u8 *construct_fire_base__9TDeadSpotFPvPvPvif(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 farg0) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800D7F60_lbl_804949F4 *)&lbl_804949F4).value;
    VecCopy((Vec *)(arg0 + 0x1C), (const Vec *)arg2);
    ((TUnk_804949F4 *)arg0)->m_28 = farg0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    ((TUnk_804949F4 *)arg0)->m_30 = 2;
    ((TUnk_804949F4 *)arg0)->m_34 = arg3;
    return arg0;
}
#pragma pop

void update_fade_in_alpha__9TDeadSpotFPv(Obj_800D7FD4 *arg0) {
    E_800D7FD4 *p;
    s32 i;
    u32 c;
    if (arg0->c4 <= arg0->c0) {
        arg0->c4 = arg0->c4 + TDeadSpot__data_805DA388;
        if (arg0->c4 <= TDeadSpot__data_805DA38C) {
            return;
        }
    }
    if (arg0->c8 < lbl_805DA390) {
        arg0->c8 = arg0->c8 + lbl_805DA394;
        if (arg0->c8 > lbl_805DA390) {
            arg0->c8 = lbl_805DA390;
        }
        p = arg0->e;
        c = __cvt_fp2unsigned(lbl_805DA398 * arg0->c8) << 24 | 0xFF0000 | 0xFFFF;
        for (i = 0; i < 4; i++) {
            p->col = c;
            p++;
        }
    }
}

void *__dt__13TUnk_80494A10Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_80494A10;
        __dt__9TDeadSpotFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DA39C;

#pragma push
#pragma fp_contract on
Obj_800D80E4 *init_corner_vertices__9TDeadSpotFPv(Obj_800D80E4 *arg0, void * parent, Vec_800D8314 * point, void * texture, s32 selector, s32 delay, f32 _w6) {
    E_800D80E4 *p;
    s32 i;
    f32 bx, by, bz, s;
    __ct__9TDeadSpotFv((Mark_800D8314 *)(arg0), parent, (Vec_800D8314 *)(point), texture, selector, delay, _w6);
    arg0->vt = ((u8 *)&lbl_80494A10);
    p = arg0->e;
    arg0->c8 = TDeadSpot__data_805DA38C;
    s = arg0->sc;
    bx = arg0->base.x;
    by = arg0->base.y;
    bz = arg0->base.z;
    for (i = 0; i < 4; i++) {
        p->v.x = arg0->dir[i].x * s + bx;
        p->v.y = arg0->dir[i].y * s + by;
        p->v.z = arg0->dir[i].z * s + bz;
        p->col = 0xFFFFFF;
        p++;
    }
    return arg0;
}
#pragma pop

void render__9TDeadSpotFv(u8 *arg0) {
    if ((TMainTask::get_render_pass() != 1) && (*(f32 *)((s8 *)arg0 + 0xC4) > TDeadSpot__data_805DA38C) && (horizontal_distance_squared((const Vec *)(arg0 + 0x7C), (const Vec *)(camera_ctrl_instance + 0x178)) < lbl_805DA39C)) {
        saved_model_render_flags = model_render_flags;
        set_default_alpha_blend();
        setup_alpha_test_render_state(0x8F);
        TObjFish::set_global_param(*(s32 *)((s8 *)arg0 + 0xB8));
        set_texture_num(*(s32 *)((s8 *)arg0 + 0xBC));
        draw_particle_strip(arg0 + 0x1C, (void *)(4), (void *)(1));
        restore_saved_depth_alpha_state();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma fp_contract on
void run_task__9TDeadSpotFv(Obj_800D8228 *arg0) {
    E_800D8228 *p;
    s32 i;
    f32 bx, by, bz;
    if (arg0->t <= arg0->sc) {
        arg0->t += TDeadSpot__data_805DA388;
        if (arg0->t <= TDeadSpot__data_805DA38C) {
            return;
        }
        p = arg0->e;
        bx = arg0->base.x;
        by = arg0->base.y;
        bz = arg0->base.z;
        for (i = 0; i < 4; i++) {
            p->v.x = arg0->dir[i].x * arg0->t + bx;
            p->v.y = arg0->dir[i].y * arg0->t + by;
            p->v.z = arg0->dir[i].z * arg0->t + bz;
            p++;
        }
    }
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
TDeadSpot::~TDeadSpot() {}
Mark_800D8314 *__ct__9TDeadSpotFv(Mark_800D8314 *self, void *parent, Vec_800D8314 *point, void *texture, s32 selector, s32 delay, f32 maxScale) {
    Vec_800D8314 basis[2];
    Vec_800D8314 probe;
    Vec_800D8314 tmp;
    s32 yaw;
    s32 pitch;
    Ground_800D8314 *ground;
    f32 n1x, n1y, n1z;
    f32 scale;
    f32 first;
    f32 second;
    f32 b0x, b0y, b0z, b1x, b1y, b1z;
    s32 bad;
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtable = __vt__9TDeadSpot;
    self->name = lbl_805D2A98;
    self->texture = texture;
    self->selector = selector;
    self->maxScale = maxScale;
    self->scale = -(TDeadSpot__data_805DA388 * (f32)delay);
    self->vtx[0].u = TDeadSpot__data_805DA38C;
    self->vtx[0].v = TDeadSpot__data_805DA38C;
    self->vtx[0].color = -1;
    self->vtx[1].u = TDeadSpot__data_805DA38C;
    self->vtx[1].v = lbl_805DA390;
    self->vtx[1].color = -1;
    self->vtx[2].u = lbl_805DA390;
    self->vtx[2].v = TDeadSpot__data_805DA38C;
    self->vtx[2].color = -1;
    self->vtx[3].u = lbl_805DA390;
    self->vtx[3].v = lbl_805DA390;
    self->vtx[3].color = -1;
    VecCopy((Vec *)&probe, (const Vec *)point);
    probe.y += lbl_805DA3A0;
    ground = csnVecterUnder(&probe, 0x16EF);
    if (ground == NULL) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    VecCopy((Vec *)&self->center, (const Vec *)&ground->plane->point);
    self->center.y += lbl_805DA3A8 * (lbl_805DA3AC * (f32)rand()) + lbl_805DA3A4;
    basis[0].x = TDeadSpot__data_805DA38C;
    basis[0].y = TDeadSpot__data_805DA38C;
    basis[0].z = lbl_805DA390;
    basis[1].x = TDeadSpot__data_805DA38C;
    basis[1].y = lbl_805DA390;
    basis[1].z = TDeadSpot__data_805DA38C;
    direction_to_rotation_yx((u8 *)&ground->plane->normal, &yaw, &pitch);
    if (pitch < 0x3000 || pitch > 0x5000) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, yaw);
    rotate_matrix_z(0, pitch);
    rotate_matrix_x(0, TObjPlayer::calc_random_scaled());
    fn_803D8DE0(0, basis, basis, 2);
    pop_matrix();
    b0x = basis[0].x;
    b0y = basis[0].y;
    b0z = basis[0].z;
    b1x = basis[1].x;
    b1y = basis[1].y;
    b1z = basis[1].z;
    first = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    second = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    self->corners[0].x = b1x * second + b0x * first;
    self->corners[0].y = b1y * second + b0y * first;
    self->corners[0].z = b1z * second + b0z * first;
    first = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    second = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    self->corners[1].x = b1x * second - b0x * first;
    self->corners[1].y = b1y * second - b0y * first;
    self->corners[1].z = b1z * second - b0z * first;
    first = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    second = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    n1x = -b1x;
    n1y = -b1y;
    n1z = -b1z;
    self->corners[2].x = n1x * second + b0x * first;
    self->corners[2].y = n1y * second + b0y * first;
    self->corners[2].z = n1z * second + b0z * first;
    first = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    second = lerp__9TDeadSpotFff(lbl_805DA3B0, lbl_805DA3B4);
    self->corners[3].x = n1x * second - b0x * first;
    self->corners[3].y = n1y * second - b0y * first;
    self->corners[3].z = n1z * second - b0z * first;
    scale = self->maxScale;
    if (scale > lbl_805DA3A0) {
        for (i = 0; i < 4; i++) {
            VecCopy((Vec *)&tmp, (const Vec *)&self->center);
            Mark_800D8314 *c = (Mark_800D8314 *)((u8 *)self + i * 12);
            tmp.x += c->corners[0].x * scale;
            tmp.y += c->corners[0].y * scale;
            tmp.z += self->corners[i].z * scale;
            bad = 0;
            ground = csnVecterUnder(&tmp, 0x16EF);
            if (ground != NULL) {
                if (ground->plane->point.y - tmp.y < lbl_805DA3B8) {
                    bad = 1;
                }
            } else {
                bad = 1;
            }
            if (bad != 0) {
                self->corners[i].x *= TDeadSpot__data_805DA388;
                self->corners[i].y *= TDeadSpot__data_805DA388;
                self->corners[i].z *= TDeadSpot__data_805DA388;
            }
        }
    }
    return self;
}
}
#pragma pop
