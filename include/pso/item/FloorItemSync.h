#ifndef PSO_ITEM_FLOORITEMSYNC_H
#define PSO_ITEM_FLOORITEMSYNC_H

#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol_types.h"

void select_confirm_exit_stub(void);
void respawn_missing_floor_items(s32 floor);

struct G_DestroyFloorItem_6x63;

void handle_6x63_destroy_floor_item(G_DestroyFloorItem_6x63 *destroy);
void build_6x63_packet(G_DestroyFloorItem_6x63 *destroy);

void reset_map(void);

struct TLobbyPlayer { u8 pad[0x10]; void *owner; };

// The floor item records ("item conditions") of each floor, sorted by item id.
FloorItem *find_item_condition(s32 floor, s32 item_id);
s32 remove_item_condition(s32 floor, s32 item_id);
// Adds a record unless its item id is already on its floor; 1 when added.
s32 insert_item_condition(FloorItem *item);
FloorItem *copy_floor_item_entry(FloorItem *dst, FloorItem *src);

// The stack of up to 32 free entity ids that transient objects take one from
// and give back; 0xFFFF when it is empty.
u16 pop_free_entity_id();
s32 push_free_entity_id(u16 id);
s32 is_stat_over_limit(s32 floor);
s32 is_entry_valid(s32 floor);
void free_boss_rocks();
void alloc_objects();
void reset_floor_items();

#endif
