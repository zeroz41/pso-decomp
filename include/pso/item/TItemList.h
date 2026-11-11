#ifndef PSO_ITEM_TITEMLIST_H
#define PSO_ITEM_TITEMLIST_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct Vec;

class TItemList : public TObject {
public:
    TItemList(TObject *parent);
    virtual ~TItemList();
public:
    static s32 is_item_valid(s32 arg0);
    static void *create_node(void *arg0, void *arg1, void *arg2, s8 arg3);
    int copy_item_data();
    void lookup_entry_by_count(s32 arg1);
    u8 get_item_count();
    void *run_item_count_update();

    u32 pad_1C;
};

class TItemList;
extern "C" {
void TItemList__sub_801D59DC(void *p);
void TItemList__sub_801D5A0C(s32 *arg0);
void TItemList__sub_801D5A64(void *p);
void TItemList__sub_801D5804(s32 *arg0);
void TItemList__sub_801D5838(void *p);
int TItemList__sub_801D5844(void *p);
void TItemList__sub_801D58C8(void *p);
void TItemList__sub_801D59A0(TItemList *item_list, s32 arg1);
void copy_position__9TItemListFPv(void *p, const Vec *v);
void *get_ptr_0x44__9TItemListFPv(void *p);
}
void clear_placement_search_slot(TItemList *arg0, s32 arg1);
extern "C" {
// Inventory walks over the TItemList nodes below root (TObjPlayer_801D5220.cpp).
void *find_matching_inventory_item_node(TObject *root);
void TObjPlayer__sub_801D52A8(TObject *root);
// TObjPlayer_801D4890.cpp: r3 = the inventory (player + 0xD00, its s16 at 0x1C counts the
// items), r4 = the player that may have the item equipped, r5 = the inventory node.
void remove_equipped_item__10TObjPlayerFPvii(void *inventory, s32 player, void *node);
s32 TObjPlayer__sub_801D49F4(void *inventory, s32 player, s32 *keys, s32 count);
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
extern s32 item_reduce_target_player;
extern u8 item_reduce_owner_match_field_ec;
extern u8 reduce_owner_match_id;
extern s32 *TObjPlayer__owner_field_write_cursor;
extern s32 *player_owner_collect_cursor;
extern u8 *player_item_collect_cursor;
extern s32 owned_item_export_cursor;
extern s32 inventory_update_field_d8_key;
extern s32 inventory_search_item_data;

#endif
