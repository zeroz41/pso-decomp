#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "types.h"
#include "pso/effect/TKomorebi.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/fence/TObjLazerFenceExtra.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/MatrixOps.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"

#include "pso/object/base/ObjectSetData.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"

#pragma readonly_strings on

__declspec(section ".data") const char *bm_fe_obj_komo_model_names[2] = { "fe_obj_komo.gj", NULL };
const char *bm_fe_obj_komo_motion_names[1] = { NULL };
BmlResourceDescriptor komorebi_resource_descriptor = { "bm_fe_obj_komo.bml", bm_fe_obj_komo_model_names, bm_fe_obj_komo_motion_names, 1, 0 };

const char *TKomorebi::class_name = "TKomorebi";
BmlResource *komorebi_bml_resource;
s32 komorebi_last_uv_update_frame;

void TKomorebi::render() {
    f32 horizontal_scale;

    if (update_object_view_visibility(400.0f, 20.0f) != 0 &&
        !(xz_distance_squared(&position, &camera_ctrl_instance->pos) < 1600.0f)) {
        TParticleCtrl::begin_effect_render();
        if (actor_frame_tick != komorebi_last_uv_update_frame) {
            scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(static_cast<NJS_OBJECT *>(model)->model), 0, (s32)scale.x, 0, 1);
            komorebi_last_uv_update_frame = actor_frame_tick;
        }
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        post_translate_matrix(&position.x);
        rotate_matrix_yxz(0, rotation_x, rotation_y, rotation_z);
        horizontal_scale = scale.z;
        scale_matrix(0, horizontal_scale, scale.y, horizontal_scale);
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TKomorebi::run_task() {}

TKomorebi::~TKomorebi() {}

TKomorebi::TKomorebi(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = class_name;
    VecCopy(&position, &set_data->position);
    copy_xyz(&rotation_x, set_data->rotation);
    VecCopy(&scale, &set_data->scale);
    model = get_bml_model(komorebi_bml_resource, 0);
    texlist = get_bml_texlist(komorebi_bml_resource, 0);
}

void *TKomorebi::create(void *set_data) {
    return new TKomorebi(tl_05, (ObjectSetData *)set_data);
}

void TKomorebi::free_static() {
    if (komorebi_bml_resource != NULL) {
        delete komorebi_bml_resource;
        komorebi_bml_resource = NULL;
    }
    komorebi_last_uv_update_frame = 0;
}

void TKomorebi::load_resources() {
    komorebi_bml_resource = new BmlResource(1, &komorebi_resource_descriptor, 0, 0, NULL);
    komorebi_last_uv_update_frame = 0;
}

void TObjLazerFenceExtra::init_models() {
    s32 count;
    NJS_OBJECT *node;
    s32 i;
    if (set_params[2] % 2 == 0) {
        base_model = get_bml_model(lazer_fence_norm_bml_resource, 1);
        beam_model = get_bml_model(lazer_fence_norm_bml_resource, 0);
        beam_motion = get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        base_model = get_bml_model(lazer_fence_norm_bml_resource, 3);
        beam_model = get_bml_model(lazer_fence_norm_bml_resource, 2);
        beam_motion = get_bml_motion(lazer_fence_norm_bml_resource, 1);
    }
    for (i = 0; i < 4; i++) {
        beam_part_models[i] = NULL;
    }
    count = 0;
    node = beam_model->child;
    if (node != NULL) {
        beam_part_models[count++] = node->model;
        node = node->sibling;
        while (node != NULL && count < 4) {
            beam_part_models[count++] = node->model;
            node = node->sibling;
        }
    }
}
