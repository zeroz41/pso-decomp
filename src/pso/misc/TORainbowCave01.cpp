#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TORainbowCave01.h"
#include "pso/network/client_id.h"
#include "pso/object/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"

const char *abeniji_fe_obj001_niji_model_names[] = {"abeniji_fe_obj001_niji.gj", NULL};
const char *abeniji_fe_obj001_niji_motion_names[] = {NULL};
BmlResourceDescriptor abeniji_fe_obj001_niji_resource_descriptor = {
    "abeniji_fe_obj001_niji.bml", abeniji_fe_obj001_niji_model_names, abeniji_fe_obj001_niji_motion_names, 1, 0,
};
const char *TORainbowCave01__class_name = "TORainbowCave01";
BmlResource *TORainbowCave01__bml_resource;

s32 TORainbowCave01::is_player_in_range(f32 range_sq) {
    TObjCollidable *player = find_entity_by_id((u16)local_client_id);
    if (player != NULL && horizontal_distance_squared(&position, &player->position) < range_sq) {
        return 1;
    }
    return 0;
}

void TORainbowCave01::init_light_params() {
    fade_step = 1.0f / (29.999998f + (f32)set_params[0] / 1024.0f);
    range_sq = 40000.0f + (f32)set_params[2];
    VecCopy(&model_scale, &scale);
}

void TORainbowCave01::render() {
    NJS_ARGB color;
    u32 flags;
    if (update_object_view_visibility(view_range, model_radius) != 0 && -1.0f < fade) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(texlist);
        flags = model_render_flags;
        saved_model_render_flags = flags;
        model_render_flags = flags | 0x20;
        color.b = color.g = color.r = 0.0f;
        if (TObjPlayer::check_demo_mode() == 1) {
            color.a = 0.0f;
        } else {
            color.a = fade;
        }
        set_constant_material(&color);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        scale_current_matrix(&model_scale.x);
        draw_ginja_object(model);
        pop_matrix();
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
    }
}

void TORainbowCave01::run_task() {
    s32 in_range = (is_player_in_range(range_sq) == 1) ? 1 : 0;
    switch (in_range + 1) {
    case 1:
        fade += fade_step;
        if (0.0f <= fade) {
            fade = 0.0f;
        }
        break;
    case 2:
        fade -= fade_step;
        if (fade <= -1.0f) {
            fade = -1.0f;
        }
        break;
    }
    TObjMapObject::run_task();
}

void *TORainbowCave01::create(void *set_data) {
    return new TORainbowCave01(tl_05, set_data);
}

void TORainbowCave01::free_static_data() {
    if (TORainbowCave01__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TORainbowCave01__bml_resource, 1);
        TORainbowCave01__bml_resource = NULL;
    }
}

void TORainbowCave01::load_resource_instance() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &abeniji_fe_obj001_niji_resource_descriptor, 0, 0, 0);
    }
    TORainbowCave01__bml_resource = resource;
}

TORainbowCave01::~TORainbowCave01() {}

TORainbowCave01::TORainbowCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TORainbowCave01__class_name;
    apply_object_set_data(set_data);
    model = (void *)TORainbowCave01__bml_resource->models[0].model;
    texlist = TORainbowCave01__bml_resource->models[0].m_c;
    view_range = 400.0f;
    model_radius = 40000.0f;
    fade = 0.0f;
    init_light_params();
}
