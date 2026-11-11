#ifndef PSO_UNK_MODELNODETABLES_H
#define PSO_UNK_MODELNODETABLES_H

#include "types.h"
#include <stddef.h>

// The scrolling strip buffers built on a model's nodes (init_model_node_tables
// fills it, scroll_strips scrolls it, fn_8004AA04 frees it).
// Embedded in TObjDFDemo0/1/4 and TBoss4Type1/2/3.
struct ModelNodeTables {
    void scroll_strips();

    s32 count;
    u8 pad_04[0x4];
    s32 scroll_u;
    s32 scroll_v;
    void **items;
};

typedef char ModelNodeTablesSize[(sizeof(ModelNodeTables) == 0x14) ? 1 : -1];
typedef char ModelNodeTablesItemsOffset[(offsetof(ModelNodeTables, items) == 0x10) ? 1 : -1];

#endif
