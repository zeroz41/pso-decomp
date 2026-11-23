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
    static void *create_node(void *arg0, void *arg1, void *arg2, s8 arg3);
    void lookup_entry_by_count(saddr arg1);
    u8 get_item_count();
    PendingItemDrop *run_item_count_update();
    void set_field_1c(TItem *item);
    TItem *get_owner_if_alive();
    TItemList *find_inventory_item_by_field_d8();
    TItemList *find_inventory_item_matching_data();
    void count_items_recursive();
    void unequip_invalid_items_recursive();
    void collect_alive_owners();
    void collect_item_owners_recursive();
    void count_owned_items();
    void collect_owner_fields_recursive();
    void destroy_subobjects_recursive();

    void reduce_child_item_amounts();
    void reduce_owner_matched_items();

    TItem *item_owner;
};

LAYOUT_ASSERT(InventorySlotOwnerOffset, offsetof(TItemList, item_owner) == 0x1C);
LAYOUT_ASSERT(InventorySlotSize, sizeof(TItemList) == 0x20);

extern "C" {
void TItemList__sub_801D59DC(void *p);
void TItemList__sub_801D5A0C(s32 *arg0);
void TItemList__sub_801D5A64(void *p);
void TItemList__sub_801D5838(void *p);
int TItemList__sub_801D5844(void *p);
void TItemList__sub_801D58C8(void *p);
void TItemList__sub_801D59A0(TItemList *item_list, saddr arg1);
void copy_position__9TItemListFPv(void *p, const Vec *v);
void *get_ptr_0x44__9TItemListFPv(void *p);
}
void clear_placement_search_slot(TItemList *item_list, saddr arg1);
// Inventory walks over the TItemList nodes below root (TObjPlayer_801D5220.cpp).
TItemList *find_matching_inventory_item_node(TObject *root);
extern "C" {
void TObjPlayer__sub_801D52A8(TItemList *root);
s32 TObjPlayer__sub_801D49F4(TPlyItem *inventory, TObjPlayer *player, s32 *keys, s32 count);
}
void decrement_placement_search_pending(void *p, void *a1);

extern "C" {
// new TUnk_804C4480(tl_07, list, source, pos, 0) (TPlyItem.cpp)
void *TItemList__sub_801D3B00(void *list, void *source, void *pos, s8 arg);
}

// State of the inventory walks below a TObjPlayer's item root: the entry points
// (TObjPlayer_801D4890.cpp) set it, the recursive walks read and advance it.
extern s32 inventory_walk_visit_count;
extern s32 inventory_walk_progress_count;
extern TObjPlayer *item_reduce_target_player;
extern u8 item_reduce_owner_match_field_ec;
extern u8 reduce_owner_match_id;
extern s32 *TObjPlayer__owner_field_write_cursor;
extern TItem **player_owner_collect_cursor;
extern PendingItemDrop *player_item_collect_cursor;
extern TPlyInventoryItem *owned_item_export_cursor;
extern s32 inventory_update_field_d8_key;
extern void *inventory_search_item_data;

#endif
