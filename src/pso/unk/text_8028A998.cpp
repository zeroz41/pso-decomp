#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
void clear_child_target_refs(NJS_OBJECT *root, NJS_OBJECT *target) {
    if (root == NULL) {
        return;
    }
    for (NJS_OBJECT *node = root->child; node != NULL; node = node->sibling) {
        if (node->child == target) {
            node->child = NULL;
        }
    }
}

void clear_chain_flags(NJS_OBJECT *root, NJS_OBJECT *target) {
    if (root == NULL) {
        return;
    }
    root->evalflags &= ~NJD_EVAL_BREAK;
    for (NJS_OBJECT *node = root->child; node != NULL; node = node->sibling) {
        node->evalflags &= ~NJD_EVAL_BREAK;
        if (node->child == NULL) {
            node->child = target;
        }
    }
}

}
