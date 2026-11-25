#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/render/GinjaMotionDraw.h"
#include "pso/render/GinjaView.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTransform.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/mtx.h>


void end_ginja_model_draw();

void render_model_tree(NJS_OBJECT *model) {
    Mtx34 normal_matrix;
    Mtx34 inverse;
    NJS_OBJECT *node;

    node = model;
    do {
        push_matrix();
        apply_motion_node_transform(node);
        if (model_node_callback != NULL) {
            model_node_callback(node);
        }
        if ((node->model != NULL) && !(node->evalflags & 8)) {
            GXLoadPosMtxImm(*current_matrix, 0);
            PSMTXInverse(*current_matrix, inverse);
            PSMTXTranspose(inverse, normal_matrix);
            GXLoadNrmMtxImm(normal_matrix, 0);
            model_draw_context->draw(node->model);
        }
        if (node->child != NULL) {
            render_model_tree(node->child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}
void compose_motion_node_matrix(void *node);
void draw_ginja_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    ModelDrawContext *g;
    bind_motion_context((NJS_MOTION *)motion, frame);
    g = model_draw_context;
    g->draw = draw_ginja_model_lists;
    prepare_ginja_model();
    render_matrix_chain(model);
    end_ginja_model_draw();
}

void render_matrix_chain(NJS_OBJECT *model) {
    Mtx34 normal_matrix;
    Mtx34 inverse;
    NJS_OBJECT *node;

    node = model;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (model_node_callback != NULL) {
            model_node_callback(node);
        }
        if ((node->model != NULL) && !(node->evalflags & 8)) {
            GXLoadPosMtxImm(*current_matrix, 0);
            PSMTXInverse(*current_matrix, inverse);
            PSMTXTranspose(inverse, normal_matrix);
            GXLoadNrmMtxImm(normal_matrix, 0);
            model_draw_context->draw(node->model);
        }
        if (node->child != NULL) {
            render_matrix_chain(node->child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}
