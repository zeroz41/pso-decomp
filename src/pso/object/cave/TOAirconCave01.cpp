#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/render/TextureState.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fs_obj_aircon01_model_names[] = {"fs_obj_aircon01.gj", NULL};
const char *bm_fs_obj_aircon01_motion_names[] = {NULL};
BmlResourceDescriptor aircon_cave01_shared_resource_desc = {
    "bm_fs_obj_aircon01.bml", bm_fs_obj_aircon01_model_names, bm_fs_obj_aircon01_motion_names, 1, 0,
};
const char *TOAirconCave01_class_name = "TOAirconCave01";
BmlResource *aircon_cave01_model_archive;

void TOAirconCave01::render() {
    NJS_OBJECT *object = (NJS_OBJECT *)aircon_cave01_model_archive->models[0].model;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        rotation.x += 0x106;
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation.y);
        set_texture_list(texlist);
        draw_ginja_model(object->model);
        pop_matrix();
    }
}

void *TOAirconCave01::create(void *set_data) {
    return new TOAirconCave01(tl_05, set_data);
}

void TOAirconCave01::release_static_resource() {
    if (aircon_cave01_model_archive != NULL) {
        delete aircon_cave01_model_archive;
        aircon_cave01_model_archive = NULL;
    }
}

void TOAirconCave01::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &aircon_cave01_shared_resource_desc, 0, 0, NULL);
    aircon_cave01_model_archive = resource;
}

TOAirconCave01::~TOAirconCave01() {}

TOAirconCave01::TOAirconCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOAirconCave01_class_name;
    apply_object_set_data(set_data);
    model = aircon_cave01_model_archive->models[0].model;
    texlist = aircon_cave01_model_archive->models[0].texlist;
    view_range = 500.0f;
    model_radius = 40.0f;
}
