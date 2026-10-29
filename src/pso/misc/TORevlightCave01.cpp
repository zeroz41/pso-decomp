#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/misc/TORevlightCave01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_yukakaiten01_model_names[] = {"fs_obj_yukakaiten01.gj", NULL};
const char *bm_fs_obj_yukakaiten01_motion_names[] = {"fs_obj_yukakaiten01.njm", NULL};
BmlResourceDescriptor bm_fs_obj_yukakaiten01_resource_descriptor = {
    "bm_fs_obj_yukakaiten01.bml", bm_fs_obj_yukakaiten01_model_names, bm_fs_obj_yukakaiten01_motion_names, 1, 1,
};
const char *TORevlightCave01__class_name = "TORevlightCave01";
BmlResource *TORevlightCave01__bml_resource;

void TORevlightCave01::update_demo() {}

void TORevlightCave01::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
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
        TObjFish::set_global_param(texlist);
        draw_ginja_model((s32)((NJS_OBJECT *)model)->model);
        rotate_matrix_y(NULL, spin_angle);
        draw_ginja_model((s32)((NJS_OBJECT *)model)->child->model);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)((NJS_OBJECT *)model)->child->child->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TORevlightCave01::create(void *set_data) {
    return new TORevlightCave01(tl_05, set_data);
}

void TORevlightCave01::release_static_instance() {
    if (TORevlightCave01__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TORevlightCave01__bml_resource, 1);
        TORevlightCave01__bml_resource = NULL;
    }
}

void TORevlightCave01::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_yukakaiten01_resource_descriptor, 0, 0, 0);
    }
    TORevlightCave01__bml_resource = resource;
}

TORevlightCave01::~TORevlightCave01() {}

TORevlightCave01::TORevlightCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TORevlightCave01__class_name;
    apply_object_set_data(set_data);
    model = (void *)TORevlightCave01__bml_resource->models[0].model;
    texlist = TORevlightCave01__bml_resource->models[0].m_c;
    motion = TORevlightCave01__bml_resource->motions[0].motion;
    animation_step = 0.8f;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    view_range = 500.0f;
    model_radius = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->model)->r;
    spin_angle = 0;
    spin_speed = (s32)(182.04445f * scale.x);
}
