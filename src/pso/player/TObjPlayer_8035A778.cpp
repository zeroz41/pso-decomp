#include "pso/unk/TUnk_804F1C58.h"
#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby_801E2F94.h"


extern s32 player_node_matrix_cursor;
extern s32 player_node_matrix_count;
extern saddr node_matrix_array_base;
extern ChunkModelNodeCallback player_apply_callback_fn;

void TUnk_804F1C58::apply_with_callback(NJS_MOTION *new_motion, f32 new_frame) {
    motion = new_motion;
    frame = new_frame;
    player_node_matrix_cursor = 0;
    player_node_matrix_count = node_count;
    node_matrix_array_base = reinterpret_cast<saddr>(node_matrices);
    player_apply_callback_fn = node_callback;
    set_chunk_model_node_callback(process_node_callback);
    draw_motion(static_cast<NJS_OBJECT *>(model), new_motion, new_frame);
    set_chunk_model_node_callback(NULL);
}
