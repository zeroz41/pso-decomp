#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma defer_codegen on
#pragma fp_contract on
#pragma readonly_strings on
#include "pso/system/memory.h"
#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/TBGLightningCtrl.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTexture.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_803DA798.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"

const char *TBGLightning::class_name = "TBGLightning";
const char *TBGLightningCtrl::class_name = "TBGLightningCtrl";
const s32 TBGLightning::bolt_first_texture[3] = { 1, 5, 0 };
NJS_TEXLIST *bg_lightning_texture_handle;

TBGLightning::TBGLightning(TObject *parent, Vec *pos, f32 size) : TObject(parent) {
    m_name = class_name;
    bolt_set = (s8)(2.0f * (3.0517578e-05f * (f32)rand()));
    frame = 0;
    VecCopy(&position, pos);
    this->size = size;
}

TBGLightning::~TBGLightning() {}

TBGLightning *TBGLightning::create(TObject *parent, Vec *pos, f32 size) {
    return new TBGLightning(parent, pos, size);
}

void TBGLightning::run_task() {
    if (++frame >= 12) {
        queue_destruction();
    }
}

void TBGLightning::render() {
    Vec dir;
    s32 angle;
    if (TMainTask::get_render_pass() != 0) {
        angle = camera_ctrl_instance->yaw + 0x4000;
        dir.x = sin_table_lookup(angle);
        dir.y = -1.0f;
        dir.z = cos_table_lookup(angle);
        TParticleCtrl::begin_effect_render();
        set_additive_blend();
        draw_flash(&dir);
        draw_bolt(&dir);
        set_default_alpha_blend();
        TParticleCtrl::end_effect_render();
    }
}

void TBGLightning::draw_flash(Vec *dir) {
    Vec pos;
    Vec extent;
    f32 alpha;
    switch (frame) {
    case 0:
    case 2:
        alpha = 0.5f;
        break;
    case 1:
    case 3:
        alpha = 1.0f;
        break;
    default:
        alpha = 0.5f - 0.5f * (frame - 4) / 8.0f;
        break;
    }
    extent.x = dir->x * (64.0f * size);
    extent.y = dir->y * (64.0f * size);
    extent.z = dir->z * (64.0f * size);
    pos.x = position.x + dir->x * (-3.0f * size) - 0.5f * extent.x;
    pos.y = position.y + dir->y * (-24.0f * size) - extent.y;
    pos.z = position.z + dir->z * (-3.0f * size) - 0.5f * extent.z;
    bind_lightning_texture();
    set_texture_num(0);
    TParticleCtrl::setup_particle_draw(1);
    submit_particle_quad(this, &pos.x, &extent.x, (u32)(4278190080.0f * alpha) | 0xFFFFFF);
    TParticleCtrl::reset_particles();
}

void TBGLightning::draw_bolt(Vec *dir) {
    Vec pos;
    Vec extent;
    f32 alpha;
    s32 step;
    switch (frame) {
    case 0:
        alpha = 1.0f;
        step = 0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        alpha = 1.0f;
        step = frame - 1;
        break;
    default:
        step = 3;
        alpha = 0.5f - 0.5f * (frame - 5) / 7.0f;
        break;
    }
    extent.x = dir->x * (64.0f * size);
    extent.y = dir->y * (64.0f * size);
    extent.z = dir->z * (64.0f * size);
    pos.x = position.x - 0.5f * extent.x;
    pos.y = position.y - extent.y;
    pos.z = position.z - 0.5f * extent.z;
    bind_lightning_texture();
    set_texture_num(step + bolt_first_texture[bolt_set]);
    TParticleCtrl::setup_particle_draw(1);
    submit_particle_quad(this, &pos.x, &extent.x, (u32)(4278190080.0f * alpha) | 0xFFFFFF);
    TParticleCtrl::reset_particles();
}

void submit_particle_quad(void *owner, f32 *pos, f32 *extent, s32 color) {
    ParticleStripVertex quad[4];

    quad[0].x = pos[0];
    quad[0].y = pos[1];
    quad[0].z = pos[2];
    quad[0].u = 0.0f;
    quad[0].v = 0.0f;
    quad[0].color = color;
    quad[1].x = pos[0];
    quad[1].y = pos[1] + extent[1];
    quad[1].z = pos[2];
    quad[1].u = 0.0f;
    quad[1].v = 1.0f;
    quad[1].color = color;
    quad[2].x = pos[0] + extent[0];
    quad[2].y = pos[1];
    quad[2].z = pos[2] + extent[2];
    quad[2].u = 1.0f;
    quad[2].v = 0.0f;
    quad[2].color = color;
    quad[3].x = pos[0] + extent[0];
    quad[3].y = pos[1] + extent[1];
    quad[3].z = pos[2] + extent[2];
    quad[3].u = 1.0f;
    quad[3].v = 1.0f;
    quad[3].color = color;
    emit_particle_strip_vertices(quad, 4);
}

void load_bg_lightning(void) { bg_lightning_texture_handle = load_gvm_texture_file("bg_lightning.gvm"); }

void TBGLightningCtrl::destroy_instance() {
    if (bg_lightning_texture_handle != NULL) {
        release_texture_list(bg_lightning_texture_handle);
        safe_free(bg_lightning_texture_handle);
        bg_lightning_texture_handle = NULL;
    }
}

void *TBGLightningCtrl::create(void *set_data) {
    return new TBGLightningCtrl(tl_05, set_data);
}

TBGLightningCtrl::TBGLightningCtrl(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    strike_timer = 0;
}

TBGLightningCtrl::~TBGLightningCtrl() {}

void TBGLightningCtrl::run_task() {
    if (strike_timer-- <= 0) {
        spawn_lightning_at_angle((s32)(65536.0f * (3.0517578e-05f * (f32)rand())));
        strike_timer = (s32)((f32)set_params[1] * (3.0517578e-05f * (f32)rand()) + (f32)set_params[0]);
    }
}

void TBGLightningCtrl::render() {}

void TBGLightningCtrl::spawn_lightning_at_angle(s32 angle) {
    Vec pos;

    pos.x = scale.x * sin_table_lookup(angle);
    pos.y = scale.y;
    pos.z = scale.x * cos_table_lookup(angle);
    TBGLightning::create(this, &pos, scale.z * (0.3f * (3.0517578e-05f * (f32)rand()) + 1.0f));
}

void bind_lightning_texture(void) { TObjFish::set_global_param(bg_lightning_texture_handle); }
