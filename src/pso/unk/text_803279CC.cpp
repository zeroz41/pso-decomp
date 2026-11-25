#include "types.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/unk/text_803279CC.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
void count_scrolled_texture_strips(ScrolledStripTotals *acc, GinjaModel *model, s32 id);
void visit_model_tree_recursive(ScrolledStripTotals *acc, NJS_OBJECT *node, s32 id) {
    do {
        if (node->model != NULL) {
            count_scrolled_texture_strips(acc, static_cast<GinjaModel *>(node->model), id);
        }
        if (node->child != NULL) {
            visit_model_tree_recursive(acc, node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
void count_scrolled_texture_strips(ScrolledStripTotals *acc, GinjaModel *model, s32 id) {
    s32 hit = 0;
    GinjaVertexArray *p;
    if (model->primary != 0 && has_texture_scroll_entry(model->primary, id) == 1) {
        hit = 1;
    }
    if (model->secondary != 0 && has_texture_scroll_entry(model->secondary, id) == 1) {
        hit = 1;
    }
    if (hit != 0) {
        for (p = model->vertices; p != 0 && p->attribute != 0xFF; p++) {
            if (p->attribute == 5 || p->attribute == 6) {
                u16 v = p->count;
                acc->count++;
                acc->sum += v;
            }
        }
    }
}

}
