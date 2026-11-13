#include "types.h"
#include "pso/unk/text_80327844.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
void collect_scroll_uv_entries__19TOComputerMachine01FiPvi(s32 arg0, void *model, s32 id);
}

void visit_matching_models(s32 arg0, u8 *arg1, s32 arg2) {
    u32 id;
    NJS_OBJECT *node = (NJS_OBJECT *)arg1;
    do {
        id = arg2;
        if (node->model != NULL) {
            collect_scroll_uv_entries__19TOComputerMachine01FiPvi(arg0, node->model, id);
        }
        if (node->child != NULL) {
            visit_matching_models(arg0, (u8 *)node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
