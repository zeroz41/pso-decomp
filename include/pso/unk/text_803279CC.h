#ifndef PSO_UNK_TEXT_803279CC_H
#define PSO_UNK_TEXT_803279CC_H

#include "types.h"

struct NJS_OBJECT;
struct Acc_80327A38 {
    s32 sum;
    s32 count;
};

extern "C" {
void visit_model_tree_recursive(Acc_80327A38 *acc, NJS_OBJECT *node, s32 id);
}

#endif
