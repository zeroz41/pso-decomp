#include "pso/system/memory.h"
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
#include "pso/render/GinjaTexture.h"
#include "pso/render/model_render_state.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/math/MatrixTransforms.h"

extern "C" {
const char *gryphon_lightning_eff_name = "TBoss5GryphonLightningEff";
NJS_TEXLIST *inazuma_texture_list;  // f512_inazuma.gvm: two bolt textures

void TBoss5GryphonLightningEff::set_two_sided() { this->two_sided = 1; }

s32 TBoss5GryphonLightningEff::calc_segment_uvs(void *vertices) {
    LightningStripSegment *p = (LightningStripSegment *)vertices;
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
        p->upper.u = u / 512.0f;
        p->upper.v = v0;
        p->lower.u = u / 512.0f;
        p->lower.v = v1;
        u += step;
    }
    if (flags & 8) {
        return inazuma_texture_list->textures[0].texture->surface->id;
    }
    return inazuma_texture_list->textures[1].texture->surface->id;
}

void TBoss5GryphonLightningEff::render() {
    ParticleStripVertex strip[26];
    Vec points[13];
    f32 widths[13];
    f32 heights[13];
    u32 flags;

    flags = model_render_flags;
    saved_model_render_flags = flags;
    model_render_flags = flags | 0x10;
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    set_additive_blend();
    project_lightning_points(points, widths, heights);
    build_lightning_strip(strip, points, widths, heights);
    ((TWindowDD *)strip)->draw_transformed_primitive(this->point_count * 2, calc_segment_uvs(strip), 1);
    if (this->two_sided == 1) {
        build_lightning_strip(strip, points, heights, widths);
        ((TWindowDD *)strip)->draw_transformed_primitive(this->point_count * 2, calc_segment_uvs(strip), 1);
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
TBoss5GryphonLightningEff::TBoss5GryphonLightningEff(TObject *parent, CurvePathPoint *segments,
                                                     int segment_count, f32 from, f32 to, f32 scale)
    : TTecZondeEff(parent, 0x30000000, 4, scale) {
    Vec v;
    f32 denom;
    s32 i;
    m_name = gryphon_lightning_eff_name;
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

void TBoss5GryphonLightningEff::release_texture() {
    if (inazuma_texture_list != NULL) {
        release_texture_list(inazuma_texture_list);
        safe_free(inazuma_texture_list);
        inazuma_texture_list = NULL;
    }
}
void TBoss5GryphonLightningEff::load_texture() {
    inazuma_texture_list = load_gvm_texture_file("f512_inazuma.gvm");
}
