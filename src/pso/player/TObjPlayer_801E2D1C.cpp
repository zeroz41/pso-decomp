#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801E2D1C.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/render/RenderSbssGlobals.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTransform.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/mtx.h>


void end_ginja_model_draw();
extern "C" {
extern s32 (*model_node_callback)(void *);
}
void compose_motion_node_matrix(void *arg0);
extern "C" {

void TObjPlayer::render_model_tree(void *model) {
    Mtx34 sp38;
    Mtx34 sp8;
    void *var_r31;

    var_r31 = model;
    do {
        push_matrix();
        ((TObjPlayer *)var_r31)->apply_motion_node_transform();
        if (((s32 (*)(void *)) model_node_callback) != NULL) {
            model_node_callback(var_r31);
        }
        if (((u32) *(u32 *)((s8 *)var_r31 + 4) != 0U) && !(*(s32 *)((s8 *)var_r31 + 0) & 8)) {
            GXLoadPosMtxImm(*current_matrix, 0);
            PSMTXInverse(*current_matrix, sp8);
            PSMTXTranspose(sp8, sp38);
            GXLoadNrmMtxImm(sp38, 0);
            model_draw_context->draw(*(void **)((s8 *)var_r31 + 4));
        }
        if ((u32) *(u32 *)((s8 *)var_r31 + 0x2C) != 0U) {
            TObjPlayer::render_model_tree((void *)(*(void **)((s8 *)var_r31 + 0x2C)));
        }
        pop_matrix();
        var_r31 = *(void **)((s8 *)var_r31 + 0x30);
    } while (var_r31 != NULL);
}

}

void draw_ginja_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    ModelDrawContext *g;
    bind_motion_context((NJS_MOTION *)motion, frame);
    g = model_draw_context;
    g->draw = draw_ginja_model_lists;
    prepare_ginja_model();
    TObjPlayer::render_matrix_chain(model);
    end_ginja_model_draw();
}

void TObjPlayer::render_matrix_chain(void *model) {
    Mtx34 sp38;
    Mtx34 sp8;
    void *var_r31;

    var_r31 = model;
    do {
        push_matrix();
        compose_motion_node_matrix(var_r31);
        if (((s32 (*)(void *)) model_node_callback) != NULL) {
            model_node_callback(var_r31);
        }
        if (((u32) *(u32 *)((s8 *)var_r31 + 4) != 0U) && !(*(s32 *)((s8 *)var_r31 + 0) & 8)) {
            GXLoadPosMtxImm(*current_matrix, 0);
            PSMTXInverse(*current_matrix, sp8);
            PSMTXTranspose(sp8, sp38);
            GXLoadNrmMtxImm(sp38, 0);
            model_draw_context->draw(*(void **)((s8 *)var_r31 + 4));
        }
        if ((u32) *(u32 *)((s8 *)var_r31 + 0x2C) != 0U) {
            TObjPlayer::render_matrix_chain((void *)(*(void **)((s8 *)var_r31 + 0x2C)));
        }
        pop_matrix();
        var_r31 = *(void **)((s8 *)var_r31 + 0x30);
    } while (var_r31 != NULL);
}
