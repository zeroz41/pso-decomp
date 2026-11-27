#ifndef PSO_ENEMY_BERURA_CHUNKMODELNODECALLBACK_H
#define PSO_ENEMY_BERURA_CHUNKMODELNODECALLBACK_H

#include "types.h"

struct NJS_OBJECT;
typedef void (*ChunkModelNodeCallback)(NJS_OBJECT *);

// Called for every node the chunk model draw visits (0 = none).
void set_chunk_model_node_callback(ChunkModelNodeCallback callback);
extern ChunkModelNodeCallback chunk_model_node_callback;

#endif
