#ifndef PSO_UNK_MODELNODETABLES_H
#define PSO_UNK_MODELNODETABLES_H

#include "types.h"
#include <stddef.h>

// One entry of a model node table: the model, the node inside it and the
// strip count passed to TLobby::alloc_tables.
struct ModelNodeSpec {
    s32 model;
    s32 node;
    s32 count;
};

// The scrolling strip buffers built on a model's nodes (init fills it,
// scroll_strips scrolls it, destroy frees it).
// Embedded in TObjDFDemo0/1/4 and TBoss4Type1/2/3.
struct ModelNodeTables {
    void scroll_strips();
    void destroy();
    void init(const ModelNodeSpec *specs, s32 spec_count);

    s32 count;
    u8 pad_04[0x4];
    s32 scroll_u;
    s32 scroll_v;
    void **items;
};

typedef char ModelNodeTablesSize[(sizeof(ModelNodeTables) == 0x14) ? 1 : -1];
typedef char ModelNodeTablesItemsOffset[(offsetof(ModelNodeTables, items) == 0x10) ? 1 : -1];

#endif
