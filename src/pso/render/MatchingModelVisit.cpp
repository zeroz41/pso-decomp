#include "types.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/MatchingModelVisit.h"
#include "pso/system/NinjaTypes.h"

void visit_matching_models(UvScrollBuffer *buffer, NJS_OBJECT *node, s32 texture_id) {
    u32 id;
    do {
        id = texture_id;
        if (node->model != NULL) {
            collect_scroll_uv_entries(buffer, node->ginja_model, id);
        }
        if (node->child != NULL) {
            visit_matching_models(buffer, node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
