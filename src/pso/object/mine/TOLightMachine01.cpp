#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/mine/TOLightMachine01.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *bm_o_light_machine01_motion_names[1] = {0};
const char *bm_o_light_machine01_model_names[3] = { "fs_obj_light.gj", "fs_obj_toudai.gj", NULL };
BmlResourceDescriptor light_machine01_resource_desc = { "bm_o_light_machine01.bml", bm_o_light_machine01_model_names, bm_o_light_machine01_motion_names, 2, 0 };

struct GinjaTextureList;

extern "C" {
BmlResource *TOLightMachine01__shared_bml_archive;
NJS_OBJECT *light_machine_ginja_model_handle;
GinjaTextureList *light_machine_ginja_param;
s32 __ct__8TObjBaseFP7TObject(void *, int);
extern s32 __vt__16TOLightMachine01[];
const char *TOLightMachine01__name = "TOLightMachine01";
extern s32 tl_05;
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TOLightMachine01::run_task() {
    this->m_a8 = (s32) (this->m_a8 + this->m_a4);
    this->m_9c = (f32) (bob_amplitude * sin_table_lookup((s32)m_a8));
    this->m_ac = (s32) (this->m_ac + this->set_params[2]);
}


void TOLightMachine01::render() {
    if (this->update_object_view_visibility(view_range, this->m_94) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_model((s32)((NJS_OBJECT *)model)->model);
        push_matrix();
        translate_matrix(0, 0.0f, this->m_9c, 0.0f);
        rotate_matrix_y(0, this->m_ac);
        draw_ginja_model((s32)((NJS_OBJECT *)model)->child->model);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param((s32)light_machine_ginja_param);
        draw_ginja_object(light_machine_ginja_model_handle);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void *TOLightMachine01::create(void *arg0) {
    void *o = TObject::operator new(0xB0);
    if (o != NULL) {
        o = TOLightMachine01__ct((TOLightMachine01 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

void TOLightMachine01::destroy_instance() {
    if (TOLightMachine01__shared_bml_archive != NULL) {
        free_bin_model_request(TOLightMachine01__shared_bml_archive, 1);
        TOLightMachine01__shared_bml_archive = NULL;
    }
}

void TOLightMachine01::load_assets() {
    BmlResource *archive = (BmlResource *)::operator new(0x440);
    if (archive != NULL) {
        archive = load_resource_from_descriptor(archive, 1, &light_machine01_resource_desc, 0, 0, 0);
    }
    TOLightMachine01__shared_bml_archive = archive;
    light_machine_ginja_model_handle = (NJS_OBJECT *)get_bml_model(archive, 0);
    light_machine_ginja_param = (GinjaTextureList *)get_bml_texlist(TOLightMachine01__shared_bml_archive, 0);
}

}
TOLightMachine01::~TOLightMachine01() {

}

#pragma push
#pragma fp_contract on
u8 *TOLightMachine01__ct(TOLightMachine01 *light_machine01, s32 arg1) {
    __ct__8TObjBaseFP7TObject(light_machine01, tl_05);
    *(s32 **)((s8 *)light_machine01 + 0x18) = __vt__16TOLightMachine01;
    ((TOLightMachine01 *)light_machine01)->m_name = TOLightMachine01__name;
    ((TOLightMachine01 *)(light_machine01))->apply_object_set_data((void *)arg1);
    light_machine01->model = (void *)get_bml_model(TOLightMachine01__shared_bml_archive, 1);
    light_machine01->texlist = (s32)get_bml_texlist(TOLightMachine01__shared_bml_archive, 1);
    light_machine01->view_range = 500.0f;
    light_machine01->m_94 = ((GinjaModelBounds *)((NJS_OBJECT *)light_machine01->model)->model)->radius;
    light_machine01->actorFlags = (s32) (light_machine01->actorFlags | 0x40000000);
    light_machine01->bob_speed = (f32) ((0.1f * (f32) light_machine01->set_params[0]) + 1.0f);
    light_machine01->m_a4 = (s32) (182.04445f * (360.0f / (30.0f / light_machine01->bob_speed)));
    light_machine01->m_a8 = (s32) (182.04445f * (360.0f * (3.0517578e-05f * (f32) rand())));
    light_machine01->bob_amplitude = (f32) ((0.1f * (f32) light_machine01->set_params[1]) + 0.5f);
    light_machine01->m_9c = (f32) (light_machine01->bob_amplitude * sin_table_lookup(light_machine01->m_a8));
    light_machine01->m_ac = 0;
    return (u8 *)light_machine01;
}
#pragma pop

