#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/object/TObjFish.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_aircon01_model_names[] = {"fs_obj_aircon01.gj", NULL};
const char *bm_fs_obj_aircon01_motion_names[] = {NULL};
BmlResourceDescriptor TOAirconCave01__shared_resource_desc = {
    "bm_fs_obj_aircon01.bml", bm_fs_obj_aircon01_model_names, bm_fs_obj_aircon01_motion_names, 1, 0,
};
const char *TOAirconCave01_class_name = "TOAirconCave01";
BmlResource *TOAirconCave01__model_archive;

void TOAirconCave01::render() {
    NJS_OBJECT *object = (NJS_OBJECT *)TOAirconCave01__model_archive->models[0].model;
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        rotation_x += 0x106;
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_model((s32)object->model);
        pop_matrix();
    }
}

void *TOAirconCave01::create(void *set_data) {
    return new TOAirconCave01(tl_05, set_data);
}

void TOAirconCave01::release_static_resource() {
    if (TOAirconCave01__model_archive != NULL) {
        TLobby__sub_8001FE7C(TOAirconCave01__model_archive, 1);
        TOAirconCave01__model_archive = NULL;
    }
}

void TOAirconCave01::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (resource != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &TOAirconCave01__shared_resource_desc, 0, 0, 0);
    }
    TOAirconCave01__model_archive = resource;
}

TOAirconCave01::~TOAirconCave01() {}

TOAirconCave01::TOAirconCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOAirconCave01_class_name;
    apply_object_set_data(set_data);
    model = (void *)TOAirconCave01__model_archive->models[0].model;
    texlist = TOAirconCave01__model_archive->models[0].m_c;
    m_c0 = 500.0f;
    model_radius = 40.0f;
}
