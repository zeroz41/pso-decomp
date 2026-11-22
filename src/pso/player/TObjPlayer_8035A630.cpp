#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"

s32 player_node_matrix_cursor;
s32 player_node_matrix_count;
saddr node_matrix_array_base;
ChunkModelNodeCallback player_apply_callback_fn;


void process_node_callback(NJS_OBJECT *node) {
    if ((s32) player_node_matrix_cursor < (s32) player_node_matrix_count) {
        get_current_matrix((void *)(node_matrix_array_base + (player_node_matrix_cursor * 0x30)));
    }
    if (player_apply_callback_fn != NULL) {
        player_apply_callback_fn(node);
    }
    player_node_matrix_cursor += 1;
}

void TObjPlayer::draw_node_tree(void *arg1) {
    s32 (*temp_r12)(void *);
    s32 temp_r31;
    void *var_r30;

    var_r30 = arg1;
    do {
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        push_matrix();
        TObjPlayer::concat_matrix(0, node_matrix_array_base + (this->actorFlags * 0x30));
        this->actorFlags = (this->actorFlags + 1);
        temp_r12 = *(s32 (**)(void *))((s8 *)this + 0x34);
        if (temp_r12 != NULL) {
            temp_r12(var_r30);
        }
        if (!(temp_r31 & 8)) {
            draw_chunk_model((void *)(*(saddr *)((s8 *)var_r30 + 4)));
        }
        pop_matrix();
        if (!(temp_r31 & 0x10)) {
            draw_node_tree(*(void **)((s8 *)var_r30 + 0x2C));
        }
        var_r30 = *(void **)((s8 *)var_r30 + 0x30);
    } while (var_r30 != NULL);
}

