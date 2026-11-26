#ifndef PSO_ITEM_FLOORITEMSYNC_H
#define PSO_ITEM_FLOORITEMSYNC_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol_types.h"

void unload_select_confirm(void);

void handle_6x63_destroy_floor_item(void *command);

void reset_map(void);

struct TLobbyPlayer { u8 pad[0x10]; void *owner; };

struct EvictLowestKeyFloorItemMsg { u32 hdr; s32 v; s32 who; };

struct ApplySyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    FloorItem items[1];
};

struct WriteSyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    FloorItem items[1];
};

// The floor item records ("item conditions") of each floor, sorted by item id.
FloorItem *find_item_condition(s32 floor, s32 item_id);
s32 remove_item_condition(s32 floor, s32 item_id);
// Adds a record unless its item id is already on its floor; 1 when added.
s32 insert_item_condition(FloorItem *item);

// The stack of up to 32 free entity ids that transient objects take one from
// and give back; 0xFFFF when it is empty.
u16 pop_free_entity_id();
s32 push_free_entity_id(u16 id);

#endif
