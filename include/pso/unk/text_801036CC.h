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

struct FloorItem;

// The floor item records ("item conditions") of each floor, sorted by item id.
FloorItemEntry *find_item_condition(s32 floor, s32 item_id);
s32 remove_item_condition(s32 floor, s32 item_id);
// Adds a record unless its item id is already on its floor; 1 when added.
s32 insert_item_condition(FloorItem *item);

// The stack of up to 32 free entity ids that transient objects take one from
// and give back; 0xFFFF when it is empty.
u16 pop_free_entity_id();
s32 push_free_entity_id(u16 id);

#endif
