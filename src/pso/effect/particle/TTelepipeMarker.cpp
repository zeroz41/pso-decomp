#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleDefinition.h"
#include "types.h"
#include "pso/effect/particle/TTelepipeMarker.h"
#include "pso/effect/TEffIndirectSampler.h"

#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/render/CameraCapture.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/TextureState.h"

#include "pso/system/vector.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraCtrl.h"
#pragma defer_codegen on

TEffIndirectSampler::TEffIndirectSampler(s32 kind, s32 sampler, TObject *parent) : TObject(parent) {
    this->kind = kind;
    this->sampler = sampler;
    register_indirect_effect_ctrl(kind);
}

TEffIndirectSampler::~TEffIndirectSampler() {}

void TEffIndirectSampler::enable_indirect_tev(s32, s16 kind) {
    if (kind < 0) {
        kind = this->kind;
    }
    play_particle_at_active_slot((u8)kind, (u8)sampler, 0, 0, 0, 1);
}

void TEffIndirectSampler::disable_indirect_tev() {
    GXSetTevDirect(GX_TEVSTAGE1);
    GXSetNumIndStages(0);
    set_ginja_post_texgen_count(0);
}

void request_indirect_effect(s32 kind) { register_indirect_effect_ctrl(kind); }

void play_indirect_effect_recipe(u8 kind, u16 sampler, s32 second_stage) {
    play_particle_at_active_slot(kind, sampler, 0, 0, 0, second_stage);
}

void reset_indirect_tev(s32 second_stage) {
    if (second_stage != 0) {
        GXSetTevDirect(GX_TEVSTAGE1);
    } else {
        GXSetTevDirect(GX_TEVSTAGE0);
    }
    GXSetNumIndStages(0);
    set_ginja_post_texgen_count(0);
}

TTelepipeMarker::TTelepipeMarker(const Vec *position, s8 indirect_kind, s8 texture, TObject *parent, s32 depth_override,
                             s32 lifetime, f32 width, f32 height)
    : TObject(parent) {
    this->width = width;
    this->height = height;
    VecCopy(&this->position, position);
    this->indirect_kind = indirect_kind;
    this->texture = texture;
    this->depth_override = depth_override;
    indirect = new TEffIndirectSampler(0x1F, 0, tl_05);
    visible = 1;
    this->lifetime = lifetime;
}

TTelepipeMarker::~TTelepipeMarker() {
    if (indirect != NULL) {
        indirect->queue_destruction();
        indirect = NULL;
    }
    indirect = NULL;
}

void TTelepipeMarker::run_task() {
    if (indirect == NULL) {
        queue_destruction();
        return;
    }
    if (lifetime != 0) {
        if (--lifetime == 0) {
            queue_destruction();
        }
    }
}

void TTelepipeMarker::render() {
    ParticleStripVertex v[4];
    if (indirect != NULL && visible != 0) {
        v[0].x = 10.0f * width;
        v[0].y = 10.0f * height;
        v[0].z = 0.0f;
        v[0].u = 0.0f;
        v[0].v = 0.0f;
        v[0].color = 0xFFFF0000;
        v[1].x = 10.0f * width;
        v[1].y = -10.0f * height;
        v[1].z = 0.0f;
        v[1].u = 0.0f;
        v[1].v = 1.0f;
        v[1].color = 0xFFFF0000;
        v[2].x = -10.0f * width;
        v[2].y = 10.0f * height;
        v[2].z = 0.0f;
        v[2].u = 1.0f;
        v[2].v = 0.0f;
        v[2].color = 0xFFFF0000;
        v[3].x = -10.0f * width;
        v[3].y = -10.0f * height;
        v[3].z = 0.0f;
        v[3].u = 1.0f;
        v[3].v = 1.0f;
        v[3].color = 0xFFFF0000;
        begin_effect_render();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_matrix_x(0, camera_ctrl_instance->pitch);
        load_projected_texture_matrix(1.1333334f);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[9].texlist));
        set_texture_num(texture);
        setup_particle_draw(1);
        GXSetNumTevStages(2);
        GXSetNumTexGens(2);
        indirect->enable_indirect_tev(0, -1);
        setup_particle_tev(0);
        if (depth_override != 0) {
            set_depth_buffer_settings_2();
        }
        emit_particle_strip_vertices(v, 4);
        if (depth_override != 0) {
            restore_saved_depth_alpha_state();
        }
        end_particle_draw();
        reset_particle_tev();
        indirect->disable_indirect_tev();
        pop_matrix();
        end_effect_render();
    }
}
