#ifndef PSO_RENDER_GINJATEXTUREMATRICES_H
#define PSO_RENDER_GINJATEXTUREMATRICES_H
#include "types.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/render/RenderSbssGlobals.h"
#include <dolphin/mtx.h>

typedef f32 GinjaMatrix[3][4];
struct GinjaModelQueue {
    void** models;
    u32 count;
    ModelDrawCallback draw;
};
extern u32 model_render_flags;
extern GinjaModelQueue model_draw_queue_state;
extern GinjaMatrix model_draw_queue_texture_matrices[10];
extern void* model_draw_queue_models[10];
void init_model_draw_queue(ModelDrawCallback draw);
extern "C" {
void queue_model_draw_matrix(void* model, GinjaMatrix matrix);
}
void flush_model_draw_queue();
void draw_queued_models(u32 count);
#endif
