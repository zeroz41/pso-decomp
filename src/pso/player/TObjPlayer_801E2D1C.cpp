#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801E2D1C.h"
#include "pso/misc/TCameraCtrl_803D6538.h"

struct G_801E2DE4 { u8 pad[0xC]; void (*draw)(); };

extern "C" {
void prepare_ginja_model(G_801E2DE4 *);
}
void end_ginja_model_draw();
extern "C" {
void draw_ginja_model_lists();
extern void *model_draw_context;
s32 GXLoadNrmMtxImm(s32 *, s32);
s32 GXLoadPosMtxImm(s32, s32);
extern s32 (*model_node_callback)(void *);
s32 PSMTXInverse(s32, s32 *);
s32 PSMTXTranspose(s32 *, s32 *);
void compose_motion_node_matrix(void *arg0);
s32 push_matrix();
s32 pop_matrix();

extern s32 current_matrix;

void TObjPlayer::render_model_tree(void *arg0) {
    s32 sp38[12];
    s32 sp8[12];
    void *var_r31;

    var_r31 = arg0;
    do {
        push_matrix();
        ((TObjPlayer *)var_r31)->apply_motion_node_transform();
        if (((s32 (*)(void *)) model_node_callback) != NULL) {
            model_node_callback(var_r31);
        }
        if (((u32) *(u32 *)((s8 *)var_r31 + 4) != 0U) && !(*(s32 *)((s8 *)var_r31 + 0) & 8)) {
            GXLoadPosMtxImm(current_matrix, 0);
            PSMTXInverse(current_matrix, sp8);
            PSMTXTranspose(sp8, sp38);
            GXLoadNrmMtxImm(sp38, 0);
            (*(s32 (**)(u32, void *))((s8 *)model_draw_context + 0xC))(*(u32 *)((s8 *)var_r31 + 4), model_draw_context);
        }
        if ((u32) *(u32 *)((s8 *)var_r31 + 0x2C) != 0U) {
            TObjPlayer::render_model_tree((void *)(*(void **)((s8 *)var_r31 + 0x2C)));
        }
        pop_matrix();
        var_r31 = *(void **)((s8 *)var_r31 + 0x30);
    } while (var_r31 != NULL);
}

void draw_ginja_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    G_801E2DE4 *g;
    bind_motion_context((s32)motion, frame);
    g = (G_801E2DE4 *)model_draw_context;
    g->draw = draw_ginja_model_lists;
    prepare_ginja_model(g);
    TObjPlayer::render_matrix_chain(model);
    end_ginja_model_draw();
}

void TObjPlayer::render_matrix_chain(void *arg0) {
    s32 sp38[12];
    s32 sp8[12];
    void *var_r31;

    var_r31 = arg0;
    do {
        push_matrix();
        compose_motion_node_matrix(var_r31);
        if (((s32 (*)(void *)) model_node_callback) != NULL) {
            model_node_callback(var_r31);
        }
        if (((u32) *(u32 *)((s8 *)var_r31 + 4) != 0U) && !(*(s32 *)((s8 *)var_r31 + 0) & 8)) {
            GXLoadPosMtxImm(current_matrix, 0);
            PSMTXInverse(current_matrix, sp8);
            PSMTXTranspose(sp8, sp38);
            GXLoadNrmMtxImm(sp38, 0);
            (*(s32 (**)(u32, void *))((s8 *)model_draw_context + 0xC))(*(u32 *)((s8 *)var_r31 + 4), model_draw_context);
        }
        if ((u32) *(u32 *)((s8 *)var_r31 + 0x2C) != 0U) {
            TObjPlayer::render_matrix_chain((void *)(*(void **)((s8 *)var_r31 + 0x2C)));
        }
        pop_matrix();
        var_r31 = *(void **)((s8 *)var_r31 + 0x30);
    } while (var_r31 != NULL);
}
}
