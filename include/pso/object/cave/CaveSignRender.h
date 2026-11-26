#ifndef PSO_OBJECT_CAVE_CAVE_SIGN_RENDER_H
#define PSO_OBJECT_CAVE_CAVE_SIGN_RENDER_H
#include "pso/object/base/TObjMapObject.h"
#include "pso/render/TextureState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

// Both sign models use this branch order and the same nested effect passes.
inline void render_cave_sign(TObjMapObject *sign) {
    NJS_OBJECT *node;
    if (sign->update_object_view_visibility(sign->view_range, sign->model_radius) != 0) {
        set_texture_list(sign->texlist);
        push_matrix();
        post_translate_matrix(&sign->position.x);
        rotate_matrix_y(NULL, sign->rotation_y);
        node = sign->model;
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
        node = sign->model->child->sibling;
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
        node = sign->model->child->sibling->sibling;
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

#endif
