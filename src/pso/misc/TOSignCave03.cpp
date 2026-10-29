#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TOSignCave03.h"
#include "pso/object/TObjFish.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_dokanban03_model_names[] = {"fs_obj_dokanban03.gj", NULL};
const char *bm_fs_obj_dokanban03_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_dokanban03_resource_descriptor = {
    "bm_fs_obj_dokanban03.bml", bm_fs_obj_dokanban03_model_names, bm_fs_obj_dokanban03_motion_names, 1, 0,
};
const char *TOSignCave03__class_name = "TOSignCave03";
BmlResource *TOSignCave03__bml_resource;

void TOSignCave03::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        node = (NJS_OBJECT *)model;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling->sibling->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void *TOSignCave03::create(void *set_data) {
    return new TOSignCave03(tl_05, set_data);
}

void TOSignCave03::release_static_resource() {
    if (TOSignCave03__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOSignCave03__bml_resource, 1);
        TOSignCave03__bml_resource = NULL;
    }
}

void TOSignCave03::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_dokanban03_resource_descriptor, 0, 0, 0);
    }
    TOSignCave03__bml_resource = resource;
}

TOSignCave03::~TOSignCave03() {}

TOSignCave03::TOSignCave03(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOSignCave03__class_name;
    apply_object_set_data(set_data);
    model = (void *)TOSignCave03__bml_resource->models[0].model;
    texlist = TOSignCave03__bml_resource->models[0].m_c;
    view_range = 500.0f;
    model_radius = 300.0f;
}
