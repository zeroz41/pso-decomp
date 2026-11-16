#ifndef PSO_SYSTEM_MODELDRAWCALLBACK_H
#define PSO_SYSTEM_MODELDRAWCALLBACK_H

#include "types.h"

struct NJS_OBJECT;

typedef s32 (*ModelDrawCallback)(void *);
struct ModelDrawContext {
    u8 reserved[0xC];
    ModelDrawCallback draw;
};

extern ModelDrawContext *const model_draw_context;
s32 draw_ginja_model_lists(void *model);
void init_model_draw_queue(ModelDrawCallback draw);
extern "C" {
void draw_motion_node_tree_with_context(NJS_OBJECT *model);
}

#endif
