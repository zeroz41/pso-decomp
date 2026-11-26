#ifndef PSO_ITEM_FLOORITEMSYNC_H
#define PSO_ITEM_FLOORITEMSYNC_H

#include "types.h"
#include "pso/item/TItemData.h"

// --- C functions defined in FloorItemSync.cpp ---
extern "C" {
void TLobby__sub_80104464(void);
}
// --- end of C functions

void handle_6x63_destroy_floor_item(void *command);

void reset_map(void);

struct TLobbyPlayer { u8 pad[0x10]; void *owner; };

struct ApplySyncItemStateEntry { u8 pad0[0xE]; u16 key; u8 padx[0xC]; s32 item_id; u8 pad2[4]; };

struct EvictLowestKeyFloorItemMsg { u32 hdr; s32 v; s32 who; };

struct ApplySyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    ApplySyncItemStateEntry items[1];
};

struct InsertItemConditionEntry { s8 n; u8 pad1[0xD]; u16 key; u8 padx[0xC]; s32 val; u8 pad2[4]; };

struct WriteSyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    ApplySyncItemStateEntry items[1];
};

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
