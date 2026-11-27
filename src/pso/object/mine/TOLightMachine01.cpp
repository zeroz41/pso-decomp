#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"

#include "pso/system/BmlResourceLoader.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/mine/TOLightMachine01.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixReflect.h"

#pragma readonly_strings on

const char *bm_o_light_machine01_motion_names[1] = {0};
const char *bm_o_light_machine01_model_names[3] = { "fs_obj_light.gj", "fs_obj_toudai.gj", NULL };
BmlResourceDescriptor light_machine01_resource_desc = { "bm_o_light_machine01.bml", bm_o_light_machine01_model_names, bm_o_light_machine01_motion_names, 2, 0 };

struct NJS_TEXLIST;

extern "C" {
BmlResource *light_machine01_shared_bml_archive;
NJS_OBJECT *light_machine_ginja_model_handle;
NJS_TEXLIST *light_machine_ginja_param;
const char *light_machine01_name = "TOLightMachine01";

void TOLightMachine01::run_task() {
    this->bob_angle = (s32) (this->bob_angle + this->bob_angle_step);
    this->bob_offset = (f32) (bob_amplitude * sin_table_lookup((s32)bob_angle));
    this->spin_angle = (s32) (this->spin_angle + this->set_params[2]);
}


void TOLightMachine01::render() {
    if (this->update_object_view_visibility(view_range, this->model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        set_texture_list(this->texlist);
        draw_ginja_model(model->model);
        push_matrix();
        translate_matrix(0, 0.0f, this->bob_offset, 0.0f);
        rotate_matrix_y(0, this->spin_angle);
        draw_ginja_model(model->child->model);
        TParticleCtrl::begin_effect_render();
        set_texture_list(light_machine_ginja_param);
        draw_ginja_object(light_machine_ginja_model_handle);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void *TOLightMachine01::create(void *set_data) {
    return new TOLightMachine01(set_data);
}

void TOLightMachine01::destroy_instance() {
    if (light_machine01_shared_bml_archive != NULL) {
        delete (BmlResource *)light_machine01_shared_bml_archive;
        light_machine01_shared_bml_archive = NULL;
    }
}

void TOLightMachine01::load_assets() {
    BmlResource *archive = new BmlResource(1, &light_machine01_resource_desc, 0, 0, NULL);
    light_machine01_shared_bml_archive = archive;
    light_machine_ginja_model_handle = get_bml_model(archive, 0);
    light_machine_ginja_param = get_bml_texlist((BmlResource *)light_machine01_shared_bml_archive, 0);
}

}
TOLightMachine01::~TOLightMachine01() {

}

#pragma push
#pragma fp_contract on
#define light_machine01 this
TOLightMachine01::TOLightMachine01(void *set_data) : TObjBase(tl_05) {
    light_machine01->m_name = light_machine01_name;
    ((TOLightMachine01 *)(light_machine01))->apply_object_set_data(set_data);
    light_machine01->model = get_bml_model(light_machine01_shared_bml_archive, 1);
    light_machine01->texlist = get_bml_texlist(light_machine01_shared_bml_archive, 1);
    light_machine01->view_range = 500.0f;
    light_machine01->model_radius = ((GinjaModelBounds *)light_machine01->model->model)->radius;
    light_machine01->actorFlags = (s32) (light_machine01->actorFlags | 0x40000000);
    light_machine01->bob_speed = (f32) ((0.1f * (f32) light_machine01->set_params[0]) + 1.0f);
    light_machine01->bob_angle_step = (s32) (182.04445f * (360.0f / (30.0f / light_machine01->bob_speed)));
    light_machine01->bob_angle = (s32) (182.04445f * (360.0f * (3.0517578e-05f * (f32) rand())));
    light_machine01->bob_amplitude = (f32) ((0.1f * (f32) light_machine01->set_params[1]) + 0.5f);
    light_machine01->bob_offset = (f32) (light_machine01->bob_amplitude * sin_table_lookup(light_machine01->bob_angle));
    light_machine01->spin_angle = 0;
}
#undef light_machine01
#pragma pop

