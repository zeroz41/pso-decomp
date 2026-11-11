#ifndef PSO_UNK_TEXT_8004AA04_H
#define PSO_UNK_TEXT_8004AA04_H

#include "types.h"
#include "pso/unk/ModelNodeTables.h"

// One entry of a model node table: the model, the node inside it and the
// strip count passed to TLobby::alloc_tables.
struct ModelNodeSpec {
    s32 model;
    s32 node;
    s32 count;
};

extern "C" {
void fn_8004AA04(ModelNodeTables *tables);
void init_model_node_tables(ModelNodeTables *tables, const ModelNodeSpec *specs, s32 count);
}

#endif
