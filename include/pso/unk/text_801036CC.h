#ifndef PSO_UNK_TEXT_801036CC_H
#define PSO_UNK_TEXT_801036CC_H

#include "types.h"
#include "pso/item/TItemData.h"

// One item lying on a floor in the floor item tables (0x24 bytes).
struct FloorItemEntry {
    u8 unk_00[0xE];
    u16 floor;
    TItemData data;
};

// The stack of up to 32 free entity ids that transient objects take one from
// and give back; 0xFFFF when it is empty.
u16 pop_free_entity_id();
s32 push_free_entity_id(u16 id);

#endif
