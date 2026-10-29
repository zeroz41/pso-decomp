#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOHangerMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_hanger_moto_model_names[] = {"fs_obj_hanger_moto.gj", NULL};
const char *bm_fs_obj_hanger_moto_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_hanger_moto_resource_descriptor = {
    "bm_fs_obj_hanger_moto.bml", bm_fs_obj_hanger_moto_model_names, bm_fs_obj_hanger_moto_motion_names, 1, 0,
};
CollisionBody hanger_machine01_collision_body_parts[] = {
    {{0.0f, 22.5f, 0.0f}, 25.0f, 25.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOHangerMachine01__class_name = "TOHangerMachine01";
BmlResource *TOHangerMachine01__bml_resource;

void TOHangerMachine01::run_task() {
    fan_angle += 0x888;
}

// The hangar body, its two optional arms (scale.y and scale.x switch them
// on) and the two fans spinning by fan_angle.
void TOHangerMachine01::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->child;
        if (0.0f < scale.y) {
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
        }
        node = node->sibling;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->sibling;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->child;
        push_matrix();
        post_translate_matrix(node->pos);
        rotate_matrix_z(NULL, node->ang[2]);
        rotate_matrix_x(NULL, node->ang[0]);
        rotate_matrix_y(NULL, node->ang[1] + fan_angle);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)node->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling->sibling->sibling;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->child;
        push_matrix();
        post_translate_matrix(node->pos);
        rotate_matrix_z(NULL, node->ang[2]);
        rotate_matrix_x(NULL, node->ang[0]);
        rotate_matrix_y(NULL, node->ang[1] + fan_angle);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)node->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling->sibling->sibling->sibling;
        if (0.0f < scale.x) {
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
        }
        pop_matrix();
    }
}

void *TOHangerMachine01::create(void *set_data) {
    return new TOHangerMachine01(set_data);
}

void TOHangerMachine01::free_static_model() {
    if (TOHangerMachine01__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOHangerMachine01__bml_resource, 1);
        TOHangerMachine01__bml_resource = NULL;
    }
}

void TOHangerMachine01::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_hanger_moto_resource_descriptor, 0, 0, 0);
    }
    TOHangerMachine01__bml_resource = resource;
}

TOHangerMachine01::~TOHangerMachine01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOHangerMachine01::TOHangerMachine01(void *set_data) : TObjMapObject(tl_05) {
    m_name = TOHangerMachine01__class_name;
    apply_object_set_data(set_data);
    model = (void *)TOHangerMachine01__bml_resource->models[0].model;
    texlist = TOHangerMachine01__bml_resource->models[0].m_c;
    view_range = 500.0f;
    model_radius = 50.0f;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, hanger_machine01_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    fan_angle = 0;
}
