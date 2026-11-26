#ifndef PSO_UNK_TEXT_803279CC_H
#define PSO_UNK_TEXT_803279CC_H

#include "types.h"

struct NJS_OBJECT;
struct ScrolledStripTotals {
    s32 sum;
    s32 count;
};

void visit_model_tree_recursive(ScrolledStripTotals *acc, NJS_OBJECT *node, s32 id);

#endif
