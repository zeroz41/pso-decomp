#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/cave/TORevlightCave01.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fs_obj_yukakaiten01_model_names[] = {"fs_obj_yukakaiten01.gj", NULL};
const char *bm_fs_obj_yukakaiten01_motion_names[] = {"fs_obj_yukakaiten01.njm", NULL};
BmlResourceDescriptor bm_fs_obj_yukakaiten01_resource_descriptor = {
    "bm_fs_obj_yukakaiten01.bml", bm_fs_obj_yukakaiten01_model_names, bm_fs_obj_yukakaiten01_motion_names, 1, 1,
};
const char *revlight_cave01_class_name = "TORevlightCave01";
BmlResource *revlight_cave01_bml_resource;

void TORevlightCave01::update_demo() {}

void TORevlightCave01::run_task() {
    if (check_demo_mode() == 1) {
        update_demo();
    }
    spin_angle += spin_speed;
}

void TORevlightCave01::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_z(NULL, rotation_z);
        rotate_matrix_x(NULL, rotation_x);
        rotate_matrix_y(NULL, rotation_y);
        set_texture_list(texlist);
        draw_ginja_model(model->model);
        rotate_matrix_y(NULL, spin_angle);
        draw_ginja_model(model->child->model);
        begin_effect_render();
        draw_ginja_model(model->child->child->model);
        end_effect_render();
        pop_matrix();
    }
}

void *TORevlightCave01::create(void *set_data) {
    return new TORevlightCave01(tl_05, set_data);
}

void TORevlightCave01::release_static_instance() {
    if (revlight_cave01_bml_resource != NULL) {
        delete revlight_cave01_bml_resource;
        revlight_cave01_bml_resource = NULL;
    }
}

void TORevlightCave01::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_yukakaiten01_resource_descriptor, 0, 0, NULL);
    revlight_cave01_bml_resource = resource;
}

TORevlightCave01::~TORevlightCave01() {}

TORevlightCave01::TORevlightCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = revlight_cave01_class_name;
    apply_object_set_data(set_data);
    model = revlight_cave01_bml_resource->models[0].model;
    texlist = revlight_cave01_bml_resource->models[0].texlist;
    motion = revlight_cave01_bml_resource->motions[0].motion;
    animation_step = 0.8f;
    animation_end_frame = (f32)motion->nbFrame - 1.0f;
    view_range = 500.0f;
    model_radius = ((NJS_CNK_MODEL *)model->model)->r;
    spin_angle = 0;
    spin_speed = (s32)(182.04445f * scale.x);
}
