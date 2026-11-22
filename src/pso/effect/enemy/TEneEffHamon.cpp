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


#pragma readonly_strings on

typedef struct Cam_800A3D1C { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_800A3D1C;

extern "C" {
const char *TEneEffHamon__name = "TEneEffHamon";
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
saddr TEneEffHamon__fish_model;
saddr TEneEffHamon__fish_effect_param;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
}

void TEneEffHamon::render() {
    f32 s;
    if (delay > 0) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x810;
    set_chunk_material_override_pair(0xFFFF00FF, 0x800);
    TObjFish::set_global_param(TEneEffHamon__fish_effect_param);
    set_constant_material(&color);
    push_matrix();
    post_translate_matrix(&position);
    s = size * scale;
    scale_matrix(0, s, s, s);
    draw_chunk_object((void *)TEneEffHamon__fish_model);
    pop_matrix();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
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

void TEneEffHamon::sub_800A380C() {  }

extern BmlResource *TObjEneDarkGunner__bml_resource;
void TEneEffHamon::init_fish_effects() { TEneEffHamon__fish_model = (saddr)get_bml_model((BmlResource *)TObjEneDarkGunner__bml_resource, 3); TEneEffHamon__fish_effect_param = (saddr)get_bml_texlist((BmlResource *)TObjEneDarkGunner__bml_resource, 3); }

TEneEffHamon::~TEneEffHamon() {}

TEneEffHamon::TEneEffHamon(const Vec *position, s32 duration, s32 delay, f32 size) : TObject(tl_06) {
    m_name = TEneEffHamon__name;
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
