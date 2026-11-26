#include "types.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/unk/text_80327844.h"
#include "pso/system/NinjaTypes.h"

void visit_matching_models(saddr buffer, NJS_OBJECT *node, s32 texture_id) {
    u32 id;
    do {
        id = texture_id;
        if (node->model != NULL) {
            collect_scroll_uv_entries(buffer, static_cast<GinjaModel *>(node->model), id);
        }
        if (node->child != NULL) {
            visit_matching_models(buffer, node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
