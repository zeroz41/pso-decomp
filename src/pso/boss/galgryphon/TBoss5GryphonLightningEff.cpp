#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include <stdlib.h>
#include "pso/unk/TLobby_803255F8.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/math/MatrixTransforms.h"


struct Ent_80325248 { u8 b[0xC]; };

struct Obj_80325248 { u8 pad[0x38]; s32 n; u8 pad2[0xD8 - 0x3C]; Ent_80325248 ents[1]; };

struct Self_8032537C {
    const char *f0;
    char pad4[0x14];
    void *vt;
    Vec v1c;
    Vec v28;
    f32 f34;
    s32 n;
    Vec pts[13];
    Vec pts2[13];
    char pad174[0x25C - 0x174];
    s16 f25c;
    char pad25e[2];
    u8 f260;
};

struct Vtx_80325070 { u8 pad[0xC]; f32 u; f32 v; u8 pad2[4]; };

struct Seg_80325070 { Vtx_80325070 a; Vtx_80325070 b; };

struct Obj_80325070 { u8 pad[0x34]; f32 len; s32 n; u8 pad2[0x25C - 0x3C]; s16 flags; };

struct L2_80325070 { u8 pad[0xC]; s32 *p; };

struct L1_80325070 { u8 pad[8]; L2_80325070 *a; u8 pad2[8]; L2_80325070 *b; };

extern "C" {
void eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, void *, s32, void *, f32);
extern s32 __vt__25TBoss5GryphonLightningEff[];
const char *lbl_805D4188 = "TBoss5GryphonLightningEff";
Self_8032537C *__ct__25TBoss5GryphonLightningEffFv(Self_8032537C *self, void *parent, void *a, void *b, f32 x0, f32 x1, f32 scale);
L1_80325070 **inazuma_texture_list;
s32 project_lightning_points(void *, void *, void *, void *);

void TBoss5GryphonLightningEff__sub_80325064(void* p) { *(u8*)((char*)p + 0x260) = 1; }

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

s32 TBoss5GryphonLightningEff::calc_segment_uvs(void *p_) {
#define self ((Obj_80325070 *)this)
    Seg_80325070 *p = (Seg_80325070 *)p_;
    s32 i;
    s16 flags;
    f32 base;
    f32 u;
    f32 step;
    f32 v0;
    f32 v1;
    flags = self->flags;
    u = 0.0f;
    step = self->len / (self->n - 1);
    base = 64.0f * (f32)(flags & 7);
    v0 = base / 512.0f;
    v1 = (64.0f + base) / 512.0f;
    for (i = 0; i < self->n; i++, p++) {
        p->a.u = u / 512.0f;
        p->a.v = v0;
        p->b.u = u / 512.0f;
        p->b.v = v1;
        u += step;
    }
    if (flags & 8) {
        return *(*inazuma_texture_list)->a->p;
    }
    return *(*inazuma_texture_list)->b->p;
}
#undef self

void TBoss5GryphonLightningEff::render() {
    char sp10C[0x270];
    char pts_arg[0x9C];
    char sp3C[0x34];
    char sp8[0x34];
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x10;
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    set_additive_blend();
    project_lightning_points(this, pts_arg, sp3C, sp8);
    build_lightning_strip((void *)sp10C, (void *)pts_arg, (f32 *)sp3C, (f32 *)sp8);
    ((TWindowDD *)sp10C)->draw_transformed_primitive(*(s32 *)((s8 *)this + 0x38) * 2, calc_segment_uvs(sp10C), 1);
    if ((u8) *(u8 *)((s8 *)this + 0x260) == 1) {
        build_lightning_strip((void *)sp10C, (void *)pts_arg, (f32 *)sp8, (f32 *)sp3C);
        ((TWindowDD *)sp10C)->draw_transformed_primitive(*(s32 *)((s8 *)this + 0x38) * 2, calc_segment_uvs(sp10C), 1);
    }
    set_default_alpha_blend();
    TParticleCtrl::end_effect_render();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    restore_saved_depth_alpha_state();
}
void TBoss5GryphonLightningEff::run_task() {
    Obj_80325248 *self = (Obj_80325248 *)this;
    ((TTecZondeEff *)self)->TTecZondeEff::run_task();
    if ((3.0517578e-05f) * (f32)rand() > (0.95f)) {
        s32 i = (f32)self->n * ((3.0517578e-05f) * (f32)rand());
        spawn_particle_effect_with_flags((const Vec *)&self->ents[i], 0x215, 0x40);
    }
    (*(s16 *)((u8 *)self + 0x25C))++;
}
TBoss5GryphonLightningEff::~TBoss5GryphonLightningEff() {}
extern const f32 lbl_805DF5FC = 0.0625f;
#pragma push
#pragma fp_contract on
Self_8032537C *__ct__25TBoss5GryphonLightningEffFv(Self_8032537C *self, void *parent, void *a, void *b, f32 x0, f32 x1, f32 scale) {
    Vec v;
    f32 denom;
    s32 i;
    __ct__12TTecZondeEffFP7TObjectllf((u8 *)self, (u8 *)parent, 0x30000000, 4, (f32)scale);
    self->vt = __vt__25TBoss5GryphonLightningEff;
    self->f0 = lbl_805D4188;
    self->f260 = 0;
    self->f25c = 0;
    eval_bezier_curve__12TBoss8DragonFPviiPvf(a, b, 0, &self->v1c, x0);
    eval_bezier_curve__12TBoss8DragonFPviiPvf(a, b, 0, &self->v28, x1);
    subtract_vector(&self->v28, &self->v1c);
    self->f34 = normalize_vector_safe(&self->v28);
    self->n = self->f34 * *(const volatile f32 *)&lbl_805DF5FC;
    self->n = self->n + 1;
    if (self->n < 2) {
        self->n = 2;
    }
    if (self->n > 13) {
        self->n = 13;
    }
    denom = (self->n - 1);
    x1 -= x0;
    for (i = 0; i < self->n; i++) {
        eval_bezier_curve__12TBoss8DragonFPviiPvf(a, b, 0, &self->pts[i], x0 + x1 * ((f32)i / denom));
    }
    self->f34 = (0.0f);
    for (i = 0; (f32)i < denom; i++) {
        VecCopy((Vec *)&v, (const Vec *)&self->pts[i]);
        subtract_vector(&v, &self->pts[i + 1]);
        self->f34 += normalize_vector_safe(&v);
    }
    ((TTecZondeEff *)self)->randomize_bolt_jitter();
    for (i = 0; i < self->n; i++) {
        VecCopy((Vec *)&self->pts2[i], (const Vec *)&self->pts[i]);
    }
    return self;
}
}
#pragma pop

#pragma readonly_strings on
    u8 *load_gvm_texture_file(s32 name);
extern "C" {
s32 release_texture_list(void*);
}

void TLobby::free_char_select_singleton() {
    if ((uaddr) inazuma_texture_list != 0U) {
        release_texture_list((void*)inazuma_texture_list);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)inazuma_texture_list);
        inazuma_texture_list = 0U;
    }
}
void load_f512_inazuma(void) { (*(int *)&inazuma_texture_list) = (saddr)load_gvm_texture_file((saddr)(unsigned char *)"f512_inazuma.gvm"); }
