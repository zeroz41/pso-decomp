#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceLoad.h"
#include "types.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/jungle/TOGrassJungle.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"

extern "C" {
BmlResource *grass_jungle_bml_resource;
NJS_TEXLIST *grass_jungle_grass_gvm_texture;
const char *bm_o_grass_jungle_motion_names[1] = { NULL };
const char *bm_o_grass_jungle_model_names[3] = { "fe_obj_kusa_hinata.gj", "fe_obj_kusa_kage.gj", NULL };
BmlResourceDescriptor ograss_jungle_resource_descriptor = { "bm_o_grass_jungle.bml", bm_o_grass_jungle_model_names, bm_o_grass_jungle_motion_names, 2, 0 };
const char *grass_jungle_class_name = "TOGrassJungle";


void *TOGrassJungle::create(void *set_data) {
    return new TOGrassJungle(tl_05, set_data);
}

void TOGrassJungle::release_static_instance() {
    if (grass_jungle_grass_gvm_texture != NULL) {
        release_texture_list(grass_jungle_grass_gvm_texture);
        safe_free(grass_jungle_grass_gvm_texture);
        grass_jungle_grass_gvm_texture = NULL;
    }
    if (grass_jungle_bml_resource != NULL) {
        delete (BmlResource *)grass_jungle_bml_resource;
        grass_jungle_bml_resource = NULL;
    }
}
void TOGrassJungle::load_resources() {
    BmlResource *archive = new BmlResource(1, (BmlResourceDescriptor *)&ograss_jungle_resource_descriptor, 0, 0, NULL);
    grass_jungle_bml_resource = archive;
    grass_jungle_grass_gvm_texture = LoadPvmFileTls("o_grass_jungle.gvm");
    TObjNpcEnemy::register_ginja(0x3F, reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)grass_jungle_bml_resource, 0)),
                           grass_jungle_grass_gvm_texture, 12.0f, -10.0f);
}


void TOGrassJungle::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) == 1) {
        TObjFish::set_global_param(grass_jungle_grass_gvm_texture);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(NULL, this->rotation_y);
        draw_ginja_object(get_bml_model((BmlResource *)grass_jungle_bml_resource, this->model_index));
        pop_matrix();
    }
}

}
TOGrassJungle::~TOGrassJungle() {

}


TOGrassJungle::TOGrassJungle(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = grass_jungle_class_name;
    apply_object_set_data(set_data);
    model_index = (s32)set_params[0];
    if (model_index < 0) {
        model_index = 0;
    }
    if (model_index > 1) {
        model_index = 1;
    }
}
