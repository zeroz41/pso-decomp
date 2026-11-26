#include "types.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/unk/text_80327844.h"
#include "pso/system/NinjaTypes.h"

void visit_matching_models(s32 machine, u8 *root, s32 texture_id) {
    u32 id;
    NJS_OBJECT *node = (NJS_OBJECT *)root;
    do {
        id = texture_id;
        if (node->model != NULL) {
            collect_scroll_uv_entries__19TOComputerMachine01FiPvi(machine, static_cast<GinjaModel *>(node->model), id);
        }
        if (node->child != NULL) {
            visit_matching_models(machine, (u8 *)node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
