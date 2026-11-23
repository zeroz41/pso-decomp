#ifndef PSO_UNK_TUNK_804F1C58_H
#define PSO_UNK_TUNK_804F1C58_H
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

struct NJS_MOTION;

class TUnk_804F1C58 : public TObject {
public:
    TUnk_804F1C58(TObject *parent, void *model);
    void set_field_38(ChunkModelNodeCallback callback);
    void apply_with_callback(NJS_MOTION *motion, f32 frame);
    virtual ~TUnk_804F1C58();
    void *model;
    NJS_MOTION *motion;
    f32 frame;
    GC_Mtx *node_matrices; // One matrix per model node
    s32 node_count;      // count_tree_nodes() of the model
    s32 pad_30;
    s32 pad_34;
    ChunkModelNodeCallback node_callback;   // TBoss7DeRolLeC installs its per-node draw hook here

};
LAYOUT_ASSERT(TUnk_804F1C58_size, sizeof(TUnk_804F1C58) == 0x3C);

// Shared state for capturing the matrix during each chunk-model node callback.
extern s32 player_node_matrix_cursor;
extern s32 player_node_matrix_count;
extern GC_Mtx *node_matrix_array_base;
extern ChunkModelNodeCallback player_apply_callback_fn;

#endif
