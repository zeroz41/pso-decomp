#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TDeadSpot.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804949D8.h"
#include "pso/unk/TUnk_804949F4.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include <stddef.h>
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/unk/text_803D8DE0.h"

struct E_800D7FD4 { u8 pad[0x14]; u32 col; };

struct Obj_800D7FD4 { u8 pad0[0x1C]; E_800D7FD4 e[4]; u8 pad7c[0xC0 - 0x7C]; f32 c0; f32 c4; f32 c8; };

struct E_800D80E4 { Vec v; u8 pad[8]; u32 col; };

struct Obj_800D80E4 { u8 pad0[0x18]; void *vt; E_800D80E4 e[4]; Vec base; Vec dir[4]; u8 padb8[8]; f32 sc; u8 padc4[4]; f32 c8; };

struct E_800D8228 { Vec v; u8 pad[8]; u32 col; };

struct Obj_800D8228 { u8 pad0[0x18]; void *vt; E_800D8228 e[4]; Vec base; Vec dir[4]; u8 padb8[8]; f32 sc; f32 t; f32 c8; };

struct Vtx_800D8314 { Vec pos; f32 u; f32 v; s32 color; };

struct Mark_800D8314 {
    s32 name;
    u8 pad4[0x18 - 0x4];
    void *vtable;
    Vtx_800D8314 vtx[4];
    Vec center;
    Vec corners[4];
    void *texture;
    s32 selector;
    f32 maxScale;
    f32 scale;
};
extern "C" {
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805DA380;
u32 __cvt_fp2unsigned(f32);
void run_task__9TDeadSpotFv(Obj_800D8228 *arg0);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);

#pragma push
#pragma readonly_strings on
s32 TDeadSpot__class_name = (saddr)"TDeadSpot";
}
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2);
#pragma pop
extern saddr camera_ctrl_instance;

extern s32 saved_model_render_flags;

extern s32 model_render_flags;

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off

TDeadSpot::TDeadSpot(TObject *parent, Vec *point, void *texture, s32 selector, s32 delay, f32 maxScale) : TObject(parent) {
    Mark_800D8314 *self = (Mark_800D8314 *)this;
    Vec basis[2];
    Vec probe;
    Vec tmp;
    s32 yaw;
    s32 pitch;
    CsnHit *ground;
    f32 n1x, n1y, n1z;
    f32 scale;
    f32 first;
    f32 second;
    f32 b0x, b0y, b0z, b1x, b1y, b1z;
    s32 bad;
    s32 i;
    self->name = TDeadSpot__class_name;
    self->texture = texture;
    self->selector = selector;
    self->maxScale = maxScale;
    self->scale = -(0.2f * (f32)delay);
    self->vtx[0].u = 0.0f;
    self->vtx[0].v = 0.0f;
    self->vtx[0].color = -1;
    self->vtx[1].u = 0.0f;
    self->vtx[1].v = 1.0f;
    self->vtx[1].color = -1;
    self->vtx[2].u = 1.0f;
    self->vtx[2].v = 0.0f;
    self->vtx[2].color = -1;
    self->vtx[3].u = 1.0f;
    self->vtx[3].v = 1.0f;
    self->vtx[3].color = -1;
    VecCopy((Vec *)&probe, (const Vec *)point);
    probe.y += 5.0f;
    ground = csnVecterUnder(&probe, 0x16EF);
    if (ground == NULL) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    VecCopy((Vec *)&self->center, (const Vec *)&ground->contact->point);
    self->center.y += 0.5f * (3.0517578125e-05f * (f32)rand()) + 0.213456f;
    basis[0].x = 0.0f;
    basis[0].y = 0.0f;
    basis[0].z = 1.0f;
    basis[1].x = 0.0f;
    basis[1].y = 1.0f;
    basis[1].z = 0.0f;
    direction_to_rotation_yx((u8 *)&ground->contact->normal, &yaw, &pitch);
    if (pitch < 0x3000 || pitch > 0x5000) {
        ((TObject *)self)->queue_destruction();
        return;
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
    first = lerp__9TDeadSpotFff(0.35f, 1.55f);
    second = lerp__9TDeadSpotFff(0.35f, 1.55f);
    self->corners[0].x = b1x * second + b0x * first;
    self->corners[0].y = b1y * second + b0y * first;
    self->corners[0].z = b1z * second + b0z * first;
    first = lerp__9TDeadSpotFff(0.35f, 1.55f);
    second = lerp__9TDeadSpotFff(0.35f, 1.55f);
    self->corners[1].x = b1x * second - b0x * first;
    self->corners[1].y = b1y * second - b0y * first;
    self->corners[1].z = b1z * second - b0z * first;
    first = lerp__9TDeadSpotFff(0.35f, 1.55f);
    second = lerp__9TDeadSpotFff(0.35f, 1.55f);
    n1x = -b1x;
    n1y = -b1y;
    n1z = -b1z;
    self->corners[2].x = n1x * second + b0x * first;
    self->corners[2].y = n1y * second + b0y * first;
    self->corners[2].z = n1z * second + b0z * first;
    first = lerp__9TDeadSpotFff(0.35f, 1.55f);
    second = lerp__9TDeadSpotFff(0.35f, 1.55f);
    self->corners[3].x = n1x * second - b0x * first;
    self->corners[3].y = n1y * second - b0y * first;
    self->corners[3].z = n1z * second - b0z * first;
    scale = self->maxScale;
    if (scale > 5.0f) {
        for (i = 0; i < 4; i++) {
            VecCopy((Vec *)&tmp, (const Vec *)&self->center);
            Mark_800D8314 *c = (Mark_800D8314 *)((u8 *)self + i * 12);
            tmp.x += c->corners[0].x * scale;
            tmp.y += c->corners[0].y * scale;
            tmp.z += self->corners[i].z * scale;
            bad = 0;
            ground = csnVecterUnder(&tmp, 0x16EF);
            if (ground != NULL) {
                if (ground->contact->point.y - tmp.y < -3.0f) {
                    bad = 1;
                }
            } else {
                bad = 1;
            }
            if (bad != 0) {
                self->corners[i].x *= 0.2f;
                self->corners[i].y *= 0.2f;
                self->corners[i].z *= 0.2f;
            }
        }
    }
}

TDeadSpot::~TDeadSpot() {}
#pragma pop
#pragma push
#pragma fp_contract on
void run_task__9TDeadSpotFv(Obj_800D8228 *arg0) {
    E_800D8228 *p;
    s32 i;
    f32 bx, by, bz;
    if (arg0->t <= arg0->sc) {
        arg0->t += 0.2f;
        if (arg0->t <= 0.0f) {
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
#pragma pop
void render__9TDeadSpotFv(u8 *arg0) {
    if ((TMainTask::get_render_pass() != 1) && (*(f32 *)((s8 *)arg0 + 0xC4) > 0.0f) && (horizontal_distance_squared((const Vec *)(arg0 + 0x7C), (const Vec *)(camera_ctrl_instance + 0x178)) < 22500.0f)) {
        saved_model_render_flags = model_render_flags;
        set_default_alpha_blend();
        setup_alpha_test_render_state(0x8F);
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(*(s32 *)((s8 *)arg0 + 0xB8)));
        set_texture_num(*(s32 *)((s8 *)arg0 + 0xBC));
        draw_particle_strip(arg0 + 0x1C, (void *)(4), (void *)(1));
        restore_saved_depth_alpha_state();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma push
#pragma fp_contract on
TUnk_80494A10::TUnk_80494A10(TObject *parent, Vec *point, void *texture, s32 selector, s32 delay, f32 maxScale) : TDeadSpot(parent, point, texture, selector, delay, maxScale) {
    Obj_800D80E4 *arg0 = (Obj_800D80E4 *)this;
    E_800D80E4 *p;
    s32 i;
    f32 bx, by, bz, s;
    p = arg0->e;
    arg0->c8 = 0.0f;
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
}
#pragma pop
TUnk_80494A10::~TUnk_80494A10() {}

void TUnk_80494A10::run_task() {
    Obj_800D7FD4 *arg0 = (Obj_800D7FD4 *)this;
    E_800D7FD4 *p;
    s32 i;
    u32 c;
    if (arg0->c4 <= arg0->c0) {
        arg0->c4 += 0.2f;
        if (arg0->c4 <= 0.0f) {
            return;
        }
    }
    if (arg0->c8 < 1.0f) {
        arg0->c8 += 0.05f;
        if (arg0->c8 > 1.0f) {
            arg0->c8 = 1.0f;
        }
        p = arg0->e;
        c = __cvt_fp2unsigned(255.0f * arg0->c8) << 24 | 0xFF0000 | 0xFFFF;
        for (i = 0; i < 4; i++) {
            p->col = c;
            p++;
        }
    }
}
#pragma push
#pragma fp_contract on
TUnk_804949F4::TUnk_804949F4(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TObject(parent) {
    VecCopy(&this->position, position);
    this->radius = radius;
    timer = 0;
    interval = 2;
    this->emitter = emitter;
}
#pragma pop
TUnk_804949F4::~TUnk_804949F4() {}

void TUnk_804949F4::vfunc_6() {
  Vec stack;
  f32 temp_f1;
  s32 temp_r3;
  temp_r3 = TObjPlayer::calc_random_scaled();
  temp_f1 = radius * sin_table_lookup((int) (temp_r3 & 0xFFFFFFFFu));
  stack.y = lbl_805DA380;
  stack.x = temp_f1;
  stack.z = radius * cos_table_lookup((int) temp_r3);
  vec3_add_to(&stack.x, (u8 *)&position);
  emitter->set_position(&stack.x);
}

void TUnk_804949F4::run_task() {
    if (emitter == NULL || emitter->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    timer++;
    if (timer >= interval) {
        timer = 0;
        vfunc_6();
    }
}

TUnk_804949D8::TUnk_804949D8(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TUnk_804949F4(parent, position, emitter, radius) {
    interval = 8;
}

TUnk_804949D8::~TUnk_804949D8() {}
#pragma push
#pragma opt_common_subs off
void TUnk_804949D8::vfunc_6() {
    Vec stack;
    f32 temp_f1;
    s32 temp_r3;
    temp_r3 = TObjPlayer::calc_random_scaled();
    temp_f1 = radius * sin_table_lookup(temp_r3);
    stack.y = lbl_805DA380;
    stack.x = temp_f1;
    stack.z = radius * cos_table_lookup(temp_r3);
    vec3_add_to(&stack.x, (u8 *)&position);
    TObjBoss2Tunnel::adjust_to_ground(&stack, &stack);
    emitter->set_position(&stack.x);
}

#pragma pop
