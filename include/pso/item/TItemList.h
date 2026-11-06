#ifndef PSO_ITEM_TITEMLIST_H
#define PSO_ITEM_TITEMLIST_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemList : public TObject {
public:
    virtual ~TItemList();
public:
    static u8 is_item_valid(s32 arg0);
    void *dt(s16 arg1);
    void *init_items();
    void *init_array();
    static void *create_node(void *arg0, void *arg1, void *arg2, s8 arg3);
    void *destroy(s16 arg1);
    int copy_item_data();
    void lookup_entry_by_count(s32 arg1);
    u8 get_item_count();
    void run_item_count_update();
public:
    u8 *ct_init_placement_ring(u8 *arg1, s32 arg2, u8 *arg3, u8 *arg4, s8 arg5);
};

class TItemList;
extern "C" {
void TItemList__sub_801D59DC(void *p);
void TItemList__sub_801D5A0C(s32 *arg0);
void TItemList__sub_801D5A64(void *p);
void *TItemList__sub_801D5B10(void *arg0, s16 arg1);
u8 *TItemList__sub_801D5CF8(u8 *arg0);
void *__dt__9TItemListFPvs(void *arg0, s16 arg1);
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
void *reset_position__9TItemListFPv(void *a0);
}

// --- C functions defined in TItemList.cpp ---
extern "C" {
void *TItemList__sub_801D5B10(void *item_list, s16 arg1);
}
// --- end of C functions

#endif
