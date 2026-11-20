#include "types.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/jungle/TOGrassJungle_8029CD90.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/jungle/TOGrassJungle.h"
#include "pso/object/TMotorcycle.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
BmlResource *TOGrassJungle__bml_resource;
u32 TOGrassJungle__grass_gvm_texture;
const char *bm_o_grass_jungle_motion_names[1] = { NULL };
const char *bm_o_grass_jungle_model_names[3] = { "fe_obj_kusa_hinata.gj", "fe_obj_kusa_kage.gj", NULL };
BmlResourceDescriptor ograss_jungle_resource_descriptor = { "bm_o_grass_jungle.bml", bm_o_grass_jungle_model_names, bm_o_grass_jungle_motion_names, 2, 0 };
const char *grass_jungle_class_name = "TOGrassJungle";
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);

extern void *tl_05;

void *TOGrassJungle__create(void *arg0) {
    void *o = TObject::operator new(0x94);
    if (o != NULL) {
        o = TOGrassJungle__ct((TOGrassJungle *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOGrassJungle::release_static_instance() {
    if ((u32) TOGrassJungle__grass_gvm_texture != 0U) {
        release_texture_list((void*)TOGrassJungle__grass_gvm_texture);
        TAdSinglePlyChrSelectGC::safe_free(TOGrassJungle__grass_gvm_texture);
        TOGrassJungle__grass_gvm_texture = 0U;
    }
    if ((uaddr) TOGrassJungle__bml_resource != 0U) {
        free_bin_model_request((void*)TOGrassJungle__bml_resource, 1);
        TOGrassJungle__bml_resource = 0U;
    }
}
void TOGrassJungle::load_resources() {
    saddr temp_r3;
    saddr var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &ograss_jungle_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TOGrassJungle__bml_resource) = (unsigned char *) ((void *) var_r0);
    (*(u8 * *)&TOGrassJungle__grass_gvm_texture) = load_gvm_texture_file((s32)"o_grass_jungle.gvm");
    TMotorcycle::add_entry(0x3F, (int) (get_bml_model(TOGrassJungle__bml_resource, 0)), (int) ((*(u8 * *)&TOGrassJungle__grass_gvm_texture)), 12.0f, -10.0f);
}

s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__13TOGrassJungle[];
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TOGrassJungle::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) == 1) {
        TObjFish::set_global_param(TOGrassJungle__grass_gvm_texture);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_bml_model(TOGrassJungle__bml_resource, this->m_90);
        draw_ginja_object();
        pop_matrix();
    }
}

}
TOGrassJungle::~TOGrassJungle() {

}


u8 *TOGrassJungle__ct(TOGrassJungle *grass_jungle, saddr parent, saddr arg2) {
    __ct__8TObjBaseFP7TObject((void *)grass_jungle, (void *)parent);
    *(s32 **)((s8 *)grass_jungle + 0x18) = __vt__13TOGrassJungle;
    *(s32 *)((s8 *)grass_jungle + 0) = (s32) grass_jungle_class_name;
    ((TOGrassJungle *)(grass_jungle))->apply_object_set_data((void *)arg2);
    grass_jungle->m_90 = (s32) grass_jungle->set_params[0];
    if ((s32) grass_jungle->m_90 < 0) {
        grass_jungle->m_90 = 0;
    }
    if ((s32) grass_jungle->m_90 > 1) {
        grass_jungle->m_90 = 1;
    }
    return (u8 *)grass_jungle;
}

