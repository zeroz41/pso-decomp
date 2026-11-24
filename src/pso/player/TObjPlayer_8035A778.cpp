#include "pso/unk/TUnk_804F1C58.h"
#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby_801E2F94.h"


void TUnk_804F1C58::apply_with_callback(NJS_MOTION *new_motion, f32 new_frame) {
    motion = new_motion;
    frame = new_frame;
    player_node_matrix_cursor = 0;
    player_node_matrix_count = node_count;
    node_matrix_array_base = node_matrices;
    player_apply_callback_fn = node_callback;
    set_chunk_model_node_callback(process_node_callback);
    draw_motion(model, new_motion, new_frame);
    set_chunk_model_node_callback(NULL);
}
