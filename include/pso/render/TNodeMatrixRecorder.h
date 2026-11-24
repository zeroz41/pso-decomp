#ifndef PSO_RENDER_TNODEMATRIXRECORDER_H
#define PSO_RENDER_TNODEMATRIXRECORDER_H
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

struct NJS_MOTION;

// Draws a model in a motion pose once, keeping the matrix of every node, and can draw the model again with
// those matrices.
class TNodeMatrixRecorder : public TObject {
public:
    TNodeMatrixRecorder(TObject *parent, NJS_OBJECT *model);
    void set_node_callback(ChunkModelNodeCallback callback);
    void draw_node_tree(NJS_OBJECT *node);
    void draw_recorded_pose();
    void record_pose(NJS_MOTION *motion, f32 frame);
    virtual ~TNodeMatrixRecorder();
    NJS_OBJECT *model;
    NJS_MOTION *motion;
    f32 frame;
    GC_Mtx *node_matrices; // One matrix per model node
    s32 node_count;      // count_tree_nodes() of the model
    s32 draw_node_index;
    ChunkModelNodeCallback draw_node_callback;
    ChunkModelNodeCallback node_callback;   // called for every node record_pose draws

};
LAYOUT_ASSERT(TNodeMatrixRecorder_size, sizeof(TNodeMatrixRecorder) == 0x3C);

#endif
