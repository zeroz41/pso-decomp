#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/effect/enemy/TEneEffHamon.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ChunkMaterialColor.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"


#pragma readonly_strings on

const char *TEneEffHamon::class_name = "TEneEffHamon";
NJS_OBJECT *TEneEffHamon::fish_model;
NJS_TEXLIST *TEneEffHamon::fish_texlist;

void TEneEffHamon::render() {
    f32 s;
    if (delay > 0) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    copy_argb(&saved_model_draw_color, &model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x810;
    set_chunk_material_override_pair(0xFFFF00FF, 0x800);
    TObjFish::set_global_param(fish_texlist);
    set_constant_material(&color);
    push_matrix();
    post_translate_matrix(&position.x);
    s = size * scale;
    scale_matrix(0, s, s, s);
    draw_chunk_object(fish_model);
    pop_matrix();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb(&model_material_color, &saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void TEneEffHamon::run_task() {
    s32 frames;
    frames = delay;
    if (frames > 0) {
        delay = (frames - 1);
        return;
    }
    scale = (f32) (scale + scale_rate);
    color.a = (f32) (color.a + alpha_rate);
    if (color.a <= 0.0f) {
        queue_destruction();
    }
}

void TEneEffHamon::free_fish_effects() {  }

void TEneEffHamon::init_fish_effects() {
    fish_model = get_bml_model(TObjEneDarkGunner::bml_resource, 3);
    fish_texlist = get_bml_texlist(TObjEneDarkGunner::bml_resource, 3);
}

TEneEffHamon::~TEneEffHamon() {}

TEneEffHamon::TEneEffHamon(const Vec *position, s32 duration, s32 delay, f32 size) : TObject(tl_06) {
    m_name = class_name;
    rotation_x = rotation_y = rotation_z = 0;
    scale = 1.0f;
    VecCopy(&this->position, position);
    this->size = size;
    color.a = 0.9f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    this->delay = delay;
    if (duration <= 0) {
        duration = 1;
    }
    scale_rate = (f32) (1.0f / (f32) duration);
    alpha_rate = (f32) (-0.9f / (f32) duration);
}
