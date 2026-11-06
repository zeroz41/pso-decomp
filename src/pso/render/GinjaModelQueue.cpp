#include "pso/system/ModelDrawCallback.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/render/GinjaModelQueue.h"
#include <stddef.h>
typedef char queue_models_offset[(offsetof(GinjaModelQueue, models) == 0) ? 1 : -1];
typedef char queue_count_offset[(offsetof(GinjaModelQueue, count) == 4) ? 1 : -1];
typedef char queue_draw_offset[(offsetof(GinjaModelQueue, draw) == 8) ? 1 : -1];
typedef char queue_known_size[(sizeof(GinjaModelQueue) == 12) ? 1 : -1];
extern void* model_draw_queue_models[10];

void init_model_draw_queue(ModelDrawCallback draw);
void queue_model_draw_matrix(void* model, const GinjaMatrix matrix);

s32 TObjPlayer__sub_803DB23C() { return 0; }
s32 TObjPlayer__sub_803DB244() { return 0; }

#pragma push
#pragma scheduling off
#pragma peephole off
void init_model_draw_queue(ModelDrawCallback draw) {
    model_draw_queue_state.models = model_draw_queue_models;
    model_draw_queue_state.count = 0;
    model_draw_queue_state.draw = draw;
}
#pragma pop

void queue_model_draw_matrix(void* model, const GinjaMatrix matrix) {
    GinjaMatrix inv;
    GinjaMatrix trans;
    GinjaMatrix scale;
    GXLoadPosMtxImm(matrix, model_draw_queue_state.count * 3);
    GXLoadNrmMtxImm(matrix, model_draw_queue_state.count * 3);
    if (model_render_flags & 0x100000) {
        PSMTXScale(scale, -0.5f, -0.5f, 0.0f);
        PSMTXTrans(trans, 0.5f, 0.5f, 1.0f);
        PSMTXInverse(*current_matrix, inv);
        PSMTXTranspose(inv, inv);
        PSMTXConcat(scale, inv, inv);
        PSMTXConcat(trans, inv, model_draw_queue_texture_matrices[model_draw_queue_state.count]);
    }
    model_draw_queue_state.models[model_draw_queue_state.count] = model;
    if (++model_draw_queue_state.count == 10) {
        draw_queued_models(10);
        model_draw_queue_state.count = 0;
    }
}

#pragma push
#pragma scheduling off
#pragma peephole off
void flush_model_draw_queue() {
    if (model_draw_queue_state.count) {
        draw_queued_models(model_draw_queue_state.count);
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
void draw_queued_models(u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        GXSetCurrentMtx(i * 3);
        if (model_render_flags & 0x100000) {
            GXLoadTexMtxImm(model_draw_queue_texture_matrices[i], 0x2A, 0);
        }
        model_draw_queue_state.draw(model_draw_queue_state.models[i]);
    }
    GXSetCurrentMtx(0);
}
#pragma pop

GinjaMatrix model_draw_queue_texture_matrices[10];
void* model_draw_queue_models[10];
