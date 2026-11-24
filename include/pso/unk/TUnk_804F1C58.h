#ifndef PSO_UNK_TUNK_804F1C58_H
#define PSO_UNK_TUNK_804F1C58_H
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

struct NJS_MOTION;

class TUnk_804F1C58 : public TObject {
public:
    TUnk_804F1C58(TObject *parent, NJS_OBJECT *model);
    void set_field_38(ChunkModelNodeCallback callback);
    void apply_with_callback(NJS_MOTION *motion, f32 frame);
    void draw_node_tree(NJS_OBJECT *node);
    void draw_node_tree_if_visible();
    virtual ~TUnk_804F1C58();
    NJS_OBJECT *model;
    NJS_MOTION *motion;
    f32 frame;
    GC_Mtx *node_matrices; // One matrix per model node
    s32 node_count;      // count_tree_nodes() of the model
    s32 draw_cursor;
    ChunkModelNodeCallback draw_callback;
    ChunkModelNodeCallback node_callback;   // Run while capturing node matrices

};
LAYOUT_ASSERT(TUnk_804F1C58_size, sizeof(TUnk_804F1C58) == 0x3C);

// Shared state for capturing the matrix during each chunk-model node callback.
extern s32 player_node_matrix_cursor;
extern s32 player_node_matrix_count;
extern GC_Mtx *node_matrix_array_base;
extern ChunkModelNodeCallback player_apply_callback_fn;

#endif
