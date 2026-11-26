#include "types.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/cave/TOSignCave03.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_dokanban03_model_names[] = {"fs_obj_dokanban03.gj", NULL};
const char *bm_fs_obj_dokanban03_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_dokanban03_resource_descriptor = {
    "bm_fs_obj_dokanban03.bml", bm_fs_obj_dokanban03_model_names, bm_fs_obj_dokanban03_motion_names, 1, 0,
};
const char *sign_cave03_class_name = "TOSignCave03";
BmlResource *sign_cave03_bml_resource;

void TOSignCave03::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        node = model;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = (model)->child->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = (model)->child->sibling->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node = (model)->child->sibling->sibling->sibling;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
        push_matrix();
        node = node->child;
        translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
        draw_ginja_model(node->model);
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
    if (sign_cave03_bml_resource != NULL) {
        delete sign_cave03_bml_resource;
        sign_cave03_bml_resource = NULL;
    }
}

void TOSignCave03::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_dokanban03_resource_descriptor, 0, 0, NULL);
    sign_cave03_bml_resource = resource;
}

TOSignCave03::~TOSignCave03() {}

TOSignCave03::TOSignCave03(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = sign_cave03_class_name;
    apply_object_set_data(set_data);
    model = sign_cave03_bml_resource->models[0].model;
    texlist = sign_cave03_bml_resource->models[0].texlist;
    view_range = 500.0f;
    model_radius = 300.0f;
}
