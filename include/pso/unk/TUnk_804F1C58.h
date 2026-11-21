#ifndef PSO_UNK_TUNK_804F1C58_H
#define PSO_UNK_TUNK_804F1C58_H
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
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
    void *node_matrices; // node_count blocks of 0x30 bytes (one 3x4 matrix per node)
    s32 node_count;      // count_tree_nodes() of the model
    s32 pad_30;
    s32 pad_34;
    ChunkModelNodeCallback node_callback;   // TBoss7DeRolLeC installs its per-node draw hook here

};
LAYOUT_ASSERT(TUnk_804F1C58_size, sizeof(TUnk_804F1C58) == 0x3C);

#endif
