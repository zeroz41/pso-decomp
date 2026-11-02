#ifndef PSO_UNK_TEXT_8004AA04_H
#define PSO_UNK_TEXT_8004AA04_H

#include "types.h"

// One entry of a model node table: the model, the node inside it and the
// strip count passed to TLobby::alloc_tables.
struct ModelNodeSpec {
    s32 model;
    s32 node;
    s32 count;
};

// The scrolling strip buffers built on a model's nodes (init_model_node_tables
// fills it, TBoss4Type2::scroll_strips scrolls it, fn_8004AA04 frees it).
// Embedded in TObjDFDemo0/1/4 and TBoss4Type1/2/3.
struct ModelNodeTables {
    s32 count;
    u8 pad_04[0x4];
    s32 scroll_u;
    s32 scroll_v;
    void **items;
};

extern "C" {
void fn_8004AA04(ModelNodeTables *tables);
void init_model_node_tables(ModelNodeTables *tables, const ModelNodeSpec *specs, s32 count);
}

#endif
