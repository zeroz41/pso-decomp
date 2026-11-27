#ifndef PSO_RENDER_SCROLLEDSTRIPCOUNT_H
#define PSO_RENDER_SCROLLEDSTRIPCOUNT_H

#include "types.h"

struct NJS_OBJECT;
struct ScrolledStripTotals {
    s32 sum;
    s32 count;
};

struct GinjaModel;

void visit_model_tree_recursive(ScrolledStripTotals *acc, NJS_OBJECT *node, s32 id);
void count_scrolled_texture_strips(ScrolledStripTotals *acc, GinjaModel *model, s32 id);

#endif
