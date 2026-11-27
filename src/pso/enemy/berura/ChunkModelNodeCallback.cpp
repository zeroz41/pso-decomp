#include "types.h"
#include "pso/enemy/berura/ChunkModelNodeCallback.h"

ChunkModelNodeCallback chunk_model_node_callback;

void set_chunk_model_node_callback(ChunkModelNodeCallback callback) {
    chunk_model_node_callback = callback;
}
