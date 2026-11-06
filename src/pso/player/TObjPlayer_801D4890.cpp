#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemList.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_801D4CB8.h"

extern "C" {

    extern s32 TObjPlayer__owner_field_write_cursor;
    extern s32 inventory_walk_visit_count;
int TObjPlayer::run_and_get_result(int a1) { TObjPlayer__owner_field_write_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)this->unk_1C4)->collect_owner_fields_recursive(); return inventory_walk_visit_count; }

    extern s32 owned_item_export_cursor;
int TObjPlayer::run_state_query(int a1) { owned_item_export_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)this->unk_1C4)->count_owned_items(); return inventory_walk_visit_count; }

s32 TObjPlayer::update_inventory_item(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 client) {
    s16 count;
    TItem *item;
    void *node;

    if (arg4 < 0) {
        return 0;
    }
    node = start_inventory_update(arg2);
    if (node == NULL) {
        return 0;
    }
    item = (TItem *)((TObjPlayer *)node)->get_owner_if_alive();
    if (item == NULL) {
        return 0;
    }
    if ((item->get_amount() - arg4) > 0) {
        item->remove_amount(arg4);
        return 1;
    }
    if (is_item_equipped(item) != 0) {
        unequip_item__10TObjPlayerFiPv(arg1, item);
    }
    *(s16 *)((s8 *)item + 0x28) = ((TObjBase *)arg1)->get_room();
    item->place_on_ground(client, (f32 *)arg3, 0);
    count = *(s16 *)&this->entity_id;
    *(s16 *)&this->entity_id = (count - 1);
    ((TObject *)node)->queue_destruction();
    return 1;
}
s32 TObjPlayer__sub_801D49F4(void *inventory, s32 player, s32 *arg2, s32 arg3) {
    s32 i;
    void *node;
    for (i = 0; i < arg3; arg2++, i++) {
        node = ((TObjPlayer *)inventory)->start_inventory_update(*arg2);
        if (node == NULL) {
            return 0;
        }
        remove_equipped_item__10TObjPlayerFPvii(inventory, player, node);
    }
    return 1;
}

}

void remove_equipped_item__10TObjPlayerFPvii(void *arg0, s32 arg1, void *arg2) {
    s16 count;
    TItem *item;

    item = (TItem *)((TObjPlayer *)arg2)->get_owner_if_alive();
    if (item != NULL) {
        if (is_item_equipped(item) != 0) {
            unequip_item__10TObjPlayerFiPv(arg1, item);
        }
        count = *(s16 *)((s8 *)arg0 + 0x1C);
        *(s16 *)((s8 *)arg0 + 0x1C) = (count - 1);
        item->destroy();
        ((TObject *)arg2)->queue_destruction();
    }
}


extern "C" {

void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);

void TLobby::reduce_item_amount(s32 arg1, s32 arg2, s32 arg3) {
    s16 count;
    TItem *item;

    item = (TItem *)((TObjPlayer *)arg2)->get_owner_if_alive();
    if ((item != NULL) && (arg3 >= 0)) {
        if ((item->get_amount() - arg3) > 0) {
            item->remove_amount(arg3);
            return;
        }
        if (is_item_equipped(item) != 0) {
            unequip_item__10TObjPlayerFiPv(arg1, item);
        }
        count = *(s16 *)((s8 *)this + 0x1C);
        *(s16 *)((s8 *)this + 0x1C) = (count - 1);
        item->destroy();
        ((TObject *)arg2)->queue_destruction();
    }
}

s32 TLobby::use_item(s32 arg1, s32 arg2, s32 arg3) {
    void *node;

    if (arg2 == -1) {
        try_spend_actor_meseta((u8 *)arg1, arg3);
        return 1;
    }
    node = ((TObjPlayer *)this)->start_inventory_update(arg2);
    if (node == NULL) {
        return 0;
    }
    reduce_item_amount(arg1, (s32)node, arg3);
    return 1;
}

    extern s32 item_reduce_target_player;
    extern u8 item_reduce_owner_match_field_ec;
    extern u8 reduce_owner_match_id;
void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; reduce_owner_match_id = a3; ((TLobby *)(*(int*)((char*)a0 + 0x1c4)))->reduce_owner_matched_items(); }

void TLobby::set_globals_and_update(int a1, int a2) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; ((TLobby *)(*(int*)((char*)this + 0x1c4)))->reduce_child_item_amounts(); }

    extern s32 player_item_collect_cursor;
    extern s32 inventory_walk_visit_count;
int TLobby::set_globals_and_notify(int a1, int a2) { player_item_collect_cursor = a2; inventory_walk_visit_count = 0; TObjPlayer__sub_801D52A8((TObject *)(*(int*)((char*)this + 0x1c4))); return inventory_walk_visit_count; }

}


    extern s32 inventory_walk_visit_count;
    extern s32 player_owner_collect_cursor;
int TObjPlayer::count_matching_items(int a1) { player_owner_collect_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)this->unk_1C4)->collect_item_owners_recursive(); return inventory_walk_visit_count; }

int TObjPlayer::apply_shop_judgment(int a1) { player_owner_collect_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)this->unk_1C4)->collect_alive_owners(); return inventory_walk_visit_count; }

    extern s32 item_reduce_target_player;
void TObjPlayer::set_flag_and_update(int a1) { item_reduce_target_player = a1; ((TObjPlayer *)this->unk_1C4)->unequip_invalid_items_recursive(); }

extern "C" {

s32 lookup_item_def__9TItemDataFPv(s32);

extern s32 inventory_search_item_data;

s32 TObjPlayer::count_items_by_id(s32 arg1) {
    void *node;
    TItem *item;

    if (lookup_item_def__9TItemDataFPv(arg1) != 0) {
        node = set_mode_and_refresh_object__10TObjPlayerFPvi(this, arg1);
        if (node != NULL) {
            item = (TItem *)((TObjPlayer *)node)->get_owner_if_alive();
            if ((item != NULL) && (item->all_parents_unqueued_for_destruction() != 0)) {
                return item->get_amount();
            }
        }
        return 0;
    }
    inventory_search_item_data = arg1;
    inventory_walk_visit_count = 0;
    ((TObjPlayer *)this->unk_1C4)->count_items_recursive();
    return inventory_walk_visit_count;
}

}

extern "C" {
s32 is_item_valid__9TItemListFl(void *);

void TObjPlayer::find_first_inventory_entry(int a1) { inventory_search_item_data = a1; ((TObjPlayer *)this->unk_1C4)->find_inventory_item_matching_data(); }

void *set_mode_and_refresh_object__10TObjPlayerFPvi(void *player, s32 item_data) { inventory_search_item_data = item_data; return find_matching_inventory_item_node(((TObjPlayer *)player)->unk_1C4); }

    extern s32 inventory_walk_progress_count;
void TObjPlayer::destroy_subobjects(int a1) { item_reduce_target_player = a1; inventory_walk_progress_count = 0; ((TObjPlayer *)this->unk_1C4)->destroy_subobjects_recursive(); this->unk_1C4->queue_destruction(); ((TObject *)(this->m_1c8))->run_tasks(); ((TObject *)(this->m_1c8))->run_tasks(); ((TObject *)(this->m_1c8))->queue_destruction(); }

    extern s32 inventory_update_field_d8_key;

void TObjPlayer::destroy_subobjects_recursive() {
    u8 *p;
    TItem *o;
    p = *(u8 * *)&this->m_down;
    while (p != NULL) {
        if (is_item_valid__9TItemListFl(p) != 0) {
            o = (TItem *)((TObjPlayer *)p)->get_owner_if_alive();
            if (o != NULL && o->all_parents_unqueued_for_destruction() != 0) {
                o->destroy();
            }
        }
        ((TObjPlayer *)p)->destroy_subobjects_recursive();
        p = *(u8 **)(p + 0xC);
    }
}

void *TObjPlayer::start_inventory_update(int key) { inventory_update_field_d8_key = key; inventory_walk_progress_count = 0; return ((TObjPlayer *)this->unk_1C4)->find_inventory_item_by_field_d8(); }

}
