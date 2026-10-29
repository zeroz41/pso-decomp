#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/object/TObjFish.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fe_obj_aircon02_model_names[] = {"fe_obj_aircon02.gj", NULL};
const char *bm_fe_obj_aircon02_motion_names[] = {NULL};
BmlResourceDescriptor TOAirconCave02__shared_resource_desc = {
    "bm_fe_obj_aircon02.bml", bm_fe_obj_aircon02_model_names, bm_fe_obj_aircon02_motion_names, 1, 0,
};
const char *TOAirconCave02_class_name = "TOAirconCave02";
BmlResource *TOAirconCave02__bml_resource;

void TOAirconCave02::render() {
    void *object = (void *)TOAirconCave02__bml_resource->models[0].model;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(object);
        pop_matrix();
    }
}

void *TOAirconCave02::create(void *set_data) {
    return new TOAirconCave02(tl_05, set_data);
}

void TOAirconCave02::release_static_resource() {
    if (TOAirconCave02__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOAirconCave02__bml_resource, 1);
        TOAirconCave02__bml_resource = NULL;
    }
}

void TOAirconCave02::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (resource != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &TOAirconCave02__shared_resource_desc, 0, 0, 0);
    }
    TOAirconCave02__bml_resource = resource;
}

TOAirconCave02::~TOAirconCave02() {}

TOAirconCave02::TOAirconCave02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOAirconCave02_class_name;
    apply_object_set_data(set_data);
    model = (void *)TOAirconCave02__bml_resource->models[0].model;
    texlist = TOAirconCave02__bml_resource->models[0].m_c;
    view_range = 500.0f;
    model_radius = 40.0f;
}
