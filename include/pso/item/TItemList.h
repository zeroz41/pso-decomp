#ifndef PSO_ITEM_TITEMLIST_H
#define PSO_ITEM_TITEMLIST_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

struct Vec;
struct TItem;
class TPlyItem;
struct TObjPlayer;
class TPlyInventoryItem;
struct PendingItemDrop;

class TItemList : public TObject {
public:
    TItemList(TObject *parent);
    virtual ~TItemList();
public:
    static s32 is_item_valid(TItemList *node);
    static const char *class_name;
    void set_owner(TItem *item);
    TItem *get_owner_if_alive();
    TItemList *find_item_by_id();
    TItemList *find_inventory_item_matching_data();
    void count_items_recursive();
    void unequip_invalid_items_recursive();
    void collect_alive_owners();
    void collect_item_owners_recursive();
    void collect_equipped_weapons();
    void count_owned_items();
    void collect_owner_fields_recursive();
    void destroy_subobjects_recursive();

    void reduce_child_item_amounts();
    void reduce_owner_matched_items();

    TItem *item_owner;
};

LAYOUT_ASSERT(InventorySlotOwnerOffset, offsetof(TItemList, item_owner) == 0x1C);
LAYOUT_ASSERT(InventorySlotSize, sizeof(TItemList) == 0x20);

// Inventory walks over the TItemList nodes below root.
TItemList *find_matching_inventory_item_node(TObject *root);

// State of the inventory walks below a TObjPlayer's item root: the entry points
// (the TPlyItem methods) set it, the recursive walks read and advance it.
extern s32 inventory_walk_visit_count;
extern s32 inventory_walk_progress_count;
extern TObjPlayer *item_reduce_target_player;
extern u8 item_reduce_type;
extern u8 item_reduce_group;
extern s32 *item_id_write_cursor;
extern TItem **player_owner_collect_cursor;
extern PendingItemDrop *player_item_collect_cursor;
extern TPlyInventoryItem *owned_item_export_cursor;
extern s32 inventory_search_item_id;
extern void *inventory_search_item_data;

#endif
