#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include <stdlib.h>
#include "pso/unk/TLobby_803255F8.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/math/MatrixTransforms.h"


struct Vtx_80325070 { u8 pad[0xC]; f32 u; f32 v; u8 pad2[4]; };

struct Seg_80325070 { Vtx_80325070 a; Vtx_80325070 b; };

struct L2_80325070 { u8 pad[0xC]; s32 *p; };

struct L1_80325070 { u8 pad[8]; L2_80325070 *a; u8 pad2[8]; L2_80325070 *b; };

extern "C" {
const char *lbl_805D4188 = "TBoss5GryphonLightningEff";
L1_80325070 **inazuma_texture_list;
s32 project_lightning_points(void *, void *, void *, void *);

void TBoss5GryphonLightningEff::set_two_sided() { this->two_sided = 1; }

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

s32 TBoss5GryphonLightningEff::calc_segment_uvs(void *p_) {
    Seg_80325070 *p = (Seg_80325070 *)p_;
    s32 i;
    s16 flags;
    f32 base;
    f32 u;
    f32 step;
    f32 v0;
    f32 v1;
    flags = this->frame;
    u = 0.0f;
    step = this->length / (this->point_count - 1);
    base = 64.0f * (f32)(flags & 7);
    v0 = base / 512.0f;
    v1 = (64.0f + base) / 512.0f;
    for (i = 0; i < this->point_count; i++, p++) {
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
    ((TWindowDD *)sp10C)->draw_transformed_primitive(this->point_count * 2, calc_segment_uvs(sp10C), 1);
    if (this->two_sided == 1) {
        build_lightning_strip((void *)sp10C, (void *)pts_arg, (f32 *)sp8, (f32 *)sp3C);
        ((TWindowDD *)sp10C)->draw_transformed_primitive(this->point_count * 2, calc_segment_uvs(sp10C), 1);
    }
    set_default_alpha_blend();
    TParticleCtrl::end_effect_render();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    restore_saved_depth_alpha_state();
}
void TBoss5GryphonLightningEff::run_task() {
    TTecZondeEff::run_task();
    if ((3.0517578e-05f) * (f32)rand() > (0.95f)) {
        s32 i = (f32)this->point_count * ((3.0517578e-05f) * (f32)rand());
        spawn_particle_effect_with_flags(&this->points[i], 0x215, 0x40);
    }
    this->frame++;
}
TBoss5GryphonLightningEff::~TBoss5GryphonLightningEff() {}
}

extern const f32 gryphon_lightning_points_per_unit;

#pragma push
#pragma fp_contract on
TBoss5GryphonLightningEff::TBoss5GryphonLightningEff(TObject *parent, TBoss5GryphonLightningSegment *segments,
                                                     int segment_count, f32 from, f32 to, f32 scale)
    : TTecZondeEff(parent, 0x30000000, 4, scale) {
    Vec v;
    f32 denom;
    s32 i;
    m_name = lbl_805D4188;
    this->two_sided = 0;
    this->frame = 0;
    TBoss8Dragon::eval_bezier_curve(segments, segment_count, 0, &this->origin, from);
    TBoss8Dragon::eval_bezier_curve(segments, segment_count, 0, &this->direction, to);
    subtract_vector(&this->direction, &this->origin);
    this->length = normalize_vector_safe(&this->direction);
    this->point_count = this->length * gryphon_lightning_points_per_unit;
    this->point_count = this->point_count + 1;
    if (this->point_count < 2) {
        this->point_count = 2;
    }
    if (this->point_count > 13) {
        this->point_count = 13;
    }
    denom = (this->point_count - 1);
    to -= from;
    for (i = 0; i < this->point_count; i++) {
        TBoss8Dragon::eval_bezier_curve(segments, segment_count, 0, &this->base_points[i], from + to * ((f32)i / denom));
    }
    this->length = 0.0f;
    for (i = 0; (f32)i < denom; i++) {
        VecCopy(&v, &this->base_points[i]);
        subtract_vector(&v, &this->base_points[i + 1]);
        this->length += normalize_vector_safe(&v);
    }
    this->randomize_bolt_jitter();
    for (i = 0; i < this->point_count; i++) {
        VecCopy(&this->points[i], &this->base_points[i]);
    }
}
#pragma pop

__declspec(section ".sdata2") extern const f32 gryphon_lightning_points_per_unit = 0.0625f;  // one bolt point per 16 units of length

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
