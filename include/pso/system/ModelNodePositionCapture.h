#ifndef PSO_SYSTEM_MODEL_NODE_POSITION_CAPTURE_H
#define PSO_SYSTEM_MODEL_NODE_POSITION_CAPTURE_H

#include "types.h"
#include "pso/system/vector.h"

struct NJS_OBJECT;

struct ModelNodePositionEntry {
    s32 node_index;
    Vec offset;
};

class ModelNodePositionCapture {
public:
    ModelNodePositionCapture(const ModelNodePositionEntry *entries, Vec *positions);
    ~ModelNodePositionCapture();
    void install();
    void clear();
    static void capture_node(NJS_OBJECT *node);
    static s32 is_valid(const ModelNodePositionEntry *entries);
    static ModelNodePositionCapture *create(const ModelNodePositionEntry *entries, Vec *positions);
    static void destroy(ModelNodePositionCapture *capture);

private:
    const ModelNodePositionEntry *entries;
    Vec *positions;
};

typedef char ModelNodePositionEntry_size[sizeof(ModelNodePositionEntry) == 16 ? 1 : -1];
typedef char ModelNodePositionCapture_size[sizeof(ModelNodePositionCapture) == 8 ? 1 : -1];

#endif
