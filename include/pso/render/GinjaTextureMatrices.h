#ifndef PSO_RENDER_GINJATEXTUREMATRICES_H
#define PSO_RENDER_GINJATEXTUREMATRICES_H
#include "types.h"
#include "pso/system/ModelDrawCallback.h"

typedef f32 GinjaMatrix[3][4];
struct GinjaModelQueue {
    void** models;
    u32 count;
    ModelDrawCallback draw;
};
extern GinjaMatrix* current_matrix;
extern u32 model_render_flags;
extern GinjaModelQueue model_draw_queue_state;
extern GinjaMatrix model_draw_queue_texture_matrices[10];
extern void* model_draw_queue_models[10];
extern "C" {
void init_model_draw_queue(ModelDrawCallback draw);
void queue_model_draw_matrix(void* model, const GinjaMatrix matrix);
}
void flush_model_draw_queue();
void draw_queued_models(u32 count);
extern "C" {
void GXLoadPosMtxImm(const GinjaMatrix,u32);
void GXLoadNrmMtxImm(const GinjaMatrix,u32);
void GXLoadTexMtxImm(const GinjaMatrix,u32,u32);
void GXSetCurrentMtx(u32);
void PSMTXScale(GinjaMatrix,f32,f32,f32);
void PSMTXTrans(GinjaMatrix,f32,f32,f32);
u32 PSMTXInverse(const GinjaMatrix,GinjaMatrix);
void PSMTXTranspose(const GinjaMatrix,GinjaMatrix);
void PSMTXConcat(const GinjaMatrix,const GinjaMatrix,GinjaMatrix);
}
#endif
