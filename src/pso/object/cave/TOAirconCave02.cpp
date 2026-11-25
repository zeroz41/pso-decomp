#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/cave/TOAirconCave02.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fe_obj_aircon02_model_names[] = {"fe_obj_aircon02.gj", NULL};
const char *bm_fe_obj_aircon02_motion_names[] = {NULL};
BmlResourceDescriptor aircon_cave02_shared_resource_desc = {
    "bm_fe_obj_aircon02.bml", bm_fe_obj_aircon02_model_names, bm_fe_obj_aircon02_motion_names, 1, 0,
};
const char *TOAirconCave02_class_name = "TOAirconCave02";
BmlResource *aircon_cave02_bml_resource;

void TOAirconCave02::render() {
    void *object = (void *)aircon_cave02_bml_resource->models[0].model;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        draw_ginja_object(object);
        pop_matrix();
    }
}

void *TOAirconCave02::create(void *set_data) {
    return new TOAirconCave02(tl_05, set_data);
}

void TOAirconCave02::release_static_resource() {
    if (aircon_cave02_bml_resource != NULL) {
        delete aircon_cave02_bml_resource;
        aircon_cave02_bml_resource = NULL;
    }
}

void TOAirconCave02::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &aircon_cave02_shared_resource_desc, 0, 0, NULL);
    aircon_cave02_bml_resource = resource;
}

TOAirconCave02::~TOAirconCave02() {}

TOAirconCave02::TOAirconCave02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOAirconCave02_class_name;
    apply_object_set_data(set_data);
    model = (void *)aircon_cave02_bml_resource->models[0].model;
    texlist = aircon_cave02_bml_resource->models[0].texlist;
    view_range = 500.0f;
    model_radius = 40.0f;
}
