#include "types.h"
#include "pso/unk/text_803279CC.h"
#include "pso/system/NinjaTypes.h"

struct Rec_80327A38 { u8 type; u8 pad; u16 val; u8 pad2[0xC]; };

struct Src_80327A38 { Rec_80327A38 *recs; u8 pad[4]; void *t0; void *t1; };

extern "C" {
s32 has_texture_scroll_entry(void *, u16);
void fn_80327A38(Acc_80327A38 *acc, Src_80327A38 *src, s32 id);
void visit_model_tree_recursive(Acc_80327A38 *acc, NJS_OBJECT *node, s32 id) {
    do {
        if (node->model != NULL) {
            fn_80327A38(acc, (Src_80327A38 *)node->model, id);
        }
        if (node->child != NULL) {
            visit_model_tree_recursive(acc, node->child, id);
        }
        node = node->sibling;
    } while (node != NULL);
}
void fn_80327A38(Acc_80327A38 *acc, Src_80327A38 *src, s32 id) {
    s32 hit = 0;
    Rec_80327A38 *p;
    if (src->t0 != 0 && has_texture_scroll_entry(src->t0, id) == 1) {
        hit = 1;
    }
    if (src->t1 != 0 && has_texture_scroll_entry(src->t1, id) == 1) {
        hit = 1;
    }
    if (hit != 0) {
        for (p = src->recs; p != 0 && p->type != 0xFF; p++) {
            if (p->type == 5 || p->type == 6) {
                u16 v = p->val;
                acc->count++;
                acc->sum += v;
            }
        }
    }
}

}
