#include "pso/unk/TUnk_804F1C58.h"
#include "pso/system/NinjaTypes.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"

s32 player_node_matrix_cursor;
s32 player_node_matrix_count;
GC_Mtx *node_matrix_array_base;
ChunkModelNodeCallback player_apply_callback_fn;


void process_node_callback(NJS_OBJECT *node) {
    if (player_node_matrix_cursor < player_node_matrix_count) {
        get_current_matrix(&node_matrix_array_base[player_node_matrix_cursor]);
    }
    if (player_apply_callback_fn != NULL) {
        player_apply_callback_fn(node);
    }
    player_node_matrix_cursor += 1;
}

void TUnk_804F1C58::draw_node_tree(NJS_OBJECT *node) {
    do {
        u32 flags = node->evalflags;
        push_matrix();
        concat_matrix(NULL, node_matrix_array_base[draw_cursor]);
        draw_cursor++;
        ChunkModelNodeCallback callback = draw_callback;
        if (callback != NULL) {
            callback(node);
        }
        if (!(flags & NJD_EVAL_HIDE)) {
            draw_chunk_model(node->model);
        }
        pop_matrix();
        if (!(flags & NJD_EVAL_BREAK)) {
            draw_node_tree(node->child);
        }
        node = node->sibling;
    } while (node != NULL);
}
