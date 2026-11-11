#include "pso/boss/olgaflow/TBoss6CrushRock.h"
#include "pso/boss/olgaflow/TBoss6CrushPtcl.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include <stdlib.h>

const char TBoss6CrushRock__class_name_string[] = "TBoss6CrushRock";
const char TBoss6CrushPtcl__class_name_string[] = "TBoss6CrushPtcl";
const char *TBoss6CrushRock__name = TBoss6CrushRock__class_name_string;
const char *TBoss6CrushPtcl__name = TBoss6CrushPtcl__class_name_string;
extern const f32 lbl_805E00B8;
extern const f32 lbl_805E00BC;
extern const f32 lbl_805E00C0;
extern const f32 lbl_805E00C4;

struct Vec_80359EF0 { s32 x, y, z; };

struct RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock {
    s32 value;
    u8 remaining[0x14];
};

struct Vec_8035A460 { f32 x, y, z; };

extern "C" {
void *__ct__7TObjectFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__15TBoss6CrushPtcl[];
u8 *TBoss6CrushPtcl__ct(u8 *arg0, void *arg1, Vec_80359EF0 *arg2);
extern RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock __vt__15TBoss6CrushRock;
extern s32 TBoss6PlotFalz__instance;
s32 get_bml_model(int, void *);
int TBoss6Rock__sub_80353A04(void);
int TBoss6Rock__sub_80353A0C(void);
f32 vec3_add_to(void *, void *);
f32 vector_length(void *);
int post_translate_matrix(void*);
int rotate_matrix_z(void*, void*);
int rotate_matrix_x(void*, void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void);
}

typedef char RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock_size[sizeof(RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock) == 0x18 ? 1 : -1];

s32 TBoss6PlotFalz::get_hp() {
    return TBoss6PlotFalz__instance;
}

void TBoss6Rock::spawn_crush_rocks(s32 kind) {
    f32 radius;
    s32 base;
    s32 n;
    s32 i;
    s32 j;

    if (TBoss6CrushRock::is_falz_alive() == 0) {
        return;
    }
    ((TBoss6CrushPtcl *)this)->create();
    radius = 7.5f;
    base = 5;
    n = 2;
    if ((u32)TBoss6PlotFalz::get_hp() == 0) {
        return;
    }
    switch (kind) {
    case 0:
        break;
    case 1:
        radius = 15.0f;
        base = 1;
        n = 3;
        break;
    }
    for (i = 0; i < 0x12 / n; i++) {
        for (j = 0; j < n; j++) {
            Vec_8035A460 p = *((Vec_8035A460 *)this);
            s32 angle = (s32)(65535.0f * (0.000030517578f * (f32)rand()));
            p.x += radius * sin_table_lookup(angle);
            p.y += 35.0f * (0.000030517578f * (f32)rand());
            p.z += radius * cos_table_lookup(angle);
            u8 *o = (u8 *)__nw__7TObjectFUl(0x54);
            if (o != NULL) {
                ((u8 *(*)(u8 *, s32, Vec_8035A460 *, s32))__ct__15TBoss6CrushRockFv)(o, (s32)tl_02, &p, base + j);
            }
        }
    }
}

extern "C" u8 *__ct__15TBoss6CrushRockFv(u8 *object, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__15TBoss6CrushRock.value;
    ((TObject *)object)->m_name = TBoss6CrushRock__name;
    *(s32 *)((s8 *)object + 0x1C) = get_bml_model((int) (TBoss6Rock__sub_80353A0C()), (void *)arg3);
    *(s32 *)((s8 *)object + 0x20) = TBoss6Rock__sub_80353A04();
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg2));
    *(f32 *)((s8 *)object + 0x30) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(f32 *)((s8 *)object + 0x34) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(f32 *)((s8 *)object + 0x38) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x3C) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x40) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x44) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x48) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x4C) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x50) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    return object;
}

TBoss6CrushRock::~TBoss6CrushRock() {}

#pragma push
#pragma opt_common_subs off
void TBoss6CrushRock::run_task() {
    u8 *arg0 = (u8 *)this;
    if (((s32)is_falz_alive()) == 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + *(s32 *)((s8 *)arg0 + 0x48));
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) (*(s32 *)((s8 *)arg0 + 0x40) + *(s32 *)((s8 *)arg0 + 0x4C));
    *(s32 *)((s8 *)arg0 + 0x44) = (s32) (*(s32 *)((s8 *)arg0 + 0x44) + *(s32 *)((s8 *)arg0 + 0x50));
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) + lbl_805E00B8);
    vec3_add_to(arg0 + 0x24, arg0 + 0x30);
    if (*(f32 *)((s8 *)arg0 + 0x28) < lbl_805E00BC) {
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) lbl_805E00BC;
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) * lbl_805E00C0);
        *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) * lbl_805E00B8);
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) (*(f32 *)((s8 *)arg0 + 0x38) * lbl_805E00C0);
        if (vector_length(arg0 + 0x30) < lbl_805E00C4) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
}
#pragma pop

void TBoss6CrushRock::render() { if (is_falz_alive() != 0) { push_matrix(); post_translate_matrix((char*)this + 0x24); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x40)); rotate_matrix_x((void*)0, *(void**)((char*)this + 0x3c)); rotate_matrix_z((void*)0, *(void**)((char*)this + 0x44)); TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x20))); draw_ginja_object(*(void**)((char*)this + 0x1c)); pop_matrix(); } }

s32 TBoss6CrushRock::is_falz_alive() {
    return TBoss6PlotFalz::get_hp() ? 1 : 0;
}

void *TBoss6CrushPtcl::create() {
    void *o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        o = TBoss6CrushPtcl__ct((u8 *)o, (void *)tl_02, (Vec_80359EF0 *)(this));
    }
    return o;
}

extern "C" u8 *TBoss6CrushPtcl__ct(u8 *boss6_crush_ptcl, void *arg1, Vec_80359EF0 *arg2) {
    __ct__7TObjectFP7TObject(boss6_crush_ptcl, arg1);
    *(s32 **)((s8 *)boss6_crush_ptcl + 0x18) = __vt__15TBoss6CrushPtcl;
    ((TObject *)boss6_crush_ptcl)->m_name = TBoss6CrushPtcl__name;
    Vec_80359EF0 v = *arg2;
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_20 = (s32)create_particle_emitter(&v, 0x203);
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_24 = (s32)create_particle_emitter(&v, 0x204);
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_1C = 0;
    return boss6_crush_ptcl;
}

TBoss6CrushPtcl::~TBoss6CrushPtcl() {}

void TBoss6CrushPtcl::run_task() {
    m_1C++;
    if (m_1C >= 6) {
        if (m_20 != 0) {
            TParticleCtrl::release((void *)m_20);
            m_20 = 0;
        }
        if (m_24 != 0) {
            TParticleCtrl::release((void *)m_24);
            m_24 = 0;
        }
        queue_destruction__7TObjectFv(this);
    }
}

// run_task's constants; defined after their use so the loads stay symbol loads (lead the .sdata2).
extern const f32 lbl_805E00B8 = -0.25f;
extern const f32 lbl_805E00BC = 0.0f;
extern const f32 lbl_805E00C0 = 0.25f;
extern const f32 lbl_805E00C4 = 0.1f;
