#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItem.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/item/TItemList.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"

typedef struct Node_801D535C {
    u8 pad0[0xC];
    struct Node_801D535C *next;
    u8 pad10[4];
    struct Node_801D535C *child;
} Node_801D535C;

typedef struct Node_801D5468 {
    u8 pad0[0xC];
    struct Node_801D5468 *next;
    u8 pad10[4];
    struct Node_801D5468 *child;
} Node_801D5468;

typedef struct Node_801D55A4 {
    u8 pad0[0xC];
    struct Node_801D55A4 *next;
    u8 pad10[4];
    struct Node_801D55A4 *child;
} Node_801D55A4;

typedef struct Node_801D56D0 {
    u8 pad0[0xC];
    struct Node_801D56D0 *next;
    u8 pad10[4];
    struct Node_801D56D0 *child;
} Node_801D56D0;

extern "C" {
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 is_item_valid__9TItemListFl(void *);
extern s32 inventory_search_item_data;
s32 is_at_tekker__5TItemFv();
extern s32 inventory_walk_visit_count;
extern u32 *player_owner_collect_cursor;
extern u8 *player_item_collect_cursor;
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);
}
extern s32 item_reduce_target_player;
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2);
extern s32 inventory_update_field_d8_key;
extern s32 inventory_walk_progress_count;
extern "C" {
s32 export_inventory_entry__10TObjPlayerFiPv(s32 arg0, u8 *arg1);

extern s32 owned_item_export_cursor;

void TObjPlayer::count_owned_items() {
    void *down;
    u32 temp;

    down = this->m_down;
    while (down != NULL) {
        if ((is_item_valid__9TItemListFl(down) != 0) && ((temp = ((TObjPlayer *)down)->get_owner_if_alive()) != 0U) && (export_inventory_entry__10TObjPlayerFiPv((s32)temp, (u8 *)owned_item_export_cursor) != 0)) {
            owned_item_export_cursor += 0x1C;
            inventory_walk_visit_count += 1;
        }
        ((TObjPlayer *)down)->count_owned_items();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TObjPlayer__sub_801D52A8(TObject *root) {
    TObject *n;
    s32 o;
    for (n = root->m_down; n != NULL; n = n->m_next) {
        if (is_item_valid__9TItemListFl(n) != 0) {
            o = ((TObjPlayer *)n)->get_owner_if_alive();
            if ((o != 0) && (is_item_equipped((TItem *)o) != 0) && (((TItem *)o)->get_item_type() == 0)) {
                ((TItem *)o)->copy_to_item_data((TItemData *)((s32 *)(player_item_collect_cursor + 8)));
                *(s32 *)(player_item_collect_cursor + 4) = ((TItem *)o)->get_item_id();
                player_item_collect_cursor += 0x1C;
                inventory_walk_visit_count += 1;
            }
        }
        TObjPlayer__sub_801D52A8(n);
    }
}

void TObjPlayer::collect_item_owners_recursive() {
    Node_801D535C *arg0 = (Node_801D535C *)this;
    Node_801D535C *n;
    s32 o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (is_item_valid__9TItemListFl(n) != 0) {
            o = ((TObjPlayer *)n)->get_owner_if_alive();
            if ((o != 0) && (is_at_tekker__5TItemFv() == 0)) {
                *(*(s32 * *)&player_owner_collect_cursor) = o;
                (*(s32 * *)&player_owner_collect_cursor) += 1;
                inventory_walk_visit_count += 1;
            }
        }
        ((TObjPlayer *)n)->collect_item_owners_recursive();
    }
}

void TObjPlayer::collect_alive_owners() {
    u32 temp_r3;
    void *down;

    down = this->m_down;
    while (down != NULL) {
        if (is_item_valid__9TItemListFl((void *)((s32)down)) != 0) {
            temp_r3 = ((TObjPlayer *)down)->get_owner_if_alive();
            if (temp_r3 != 0U) {
                *player_owner_collect_cursor = temp_r3;
                player_owner_collect_cursor += 1;
                inventory_walk_visit_count += 1;
            }
        }
        ((TObjPlayer *)down)->collect_alive_owners();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TObjPlayer::unequip_invalid_items_recursive() {
    Node_801D5468 *arg0 = (Node_801D5468 *)this;
    Node_801D5468 *n;
    TItem *o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (is_item_valid__9TItemListFl(n) != 0) {
            o = (TItem *)((TObjPlayer *)n)->get_owner_if_alive();
            if ((o != NULL) && (is_item_equipped(o) != 0) && (o->is_unit() == 0) &&
                (get_slot_value__10TObjPlayerFPvi((s32 *)(item_reduce_target_player + 0xD04), o->get_attach_slot()) != 0U)) {
                unequip_item__10TObjPlayerFiPv(item_reduce_target_player, o);
            }
        }
        ((TObjPlayer *)n)->unequip_invalid_items_recursive();
    }
}

void TObjPlayer::count_items_recursive() {
    s32 sp8[7];
    void *down;

    u32 temp;

    down = this->m_down;
    while (down != NULL) {
        if ((is_item_valid__9TItemListFl(down) != 0) && ((temp = ((TObjPlayer *)down)->get_owner_if_alive()) != 0U)) {
            ((TItem *)temp)->copy_to_item_data((TItemData *)&sp8[0]);
            if (item_identity_matches((u8 *)&sp8[0], (u8 *)inventory_search_item_data) != 0) {
                inventory_walk_visit_count += 1;
            }
        }
        ((TObjPlayer *)down)->count_items_recursive();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void *TObjPlayer::find_inventory_item_matching_data() {
    Node_801D55A4 *root = (Node_801D55A4 *)this;
    s32 data[8];
    Node_801D55A4 *node;
    void *found;
    u32 owner;
    for (node = root->child; node != NULL; node = node->next) {
        if (is_item_valid__9TItemListFl(node) != 0) {
            owner = ((TObjPlayer *)node)->get_owner_if_alive();
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)data);
                if (compare_item_data_masked((void *)data, (void *)inventory_search_item_data, 0) != 0) {
                    return node;
                }
            }
        }
        found = ((TObjPlayer *)node)->find_inventory_item_matching_data();
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

void *find_matching_inventory_item_node(TObject *root) {
    s32 data[8];
    TObject *node;
    void *found;
    u32 owner;
    for (node = root->m_down; node != NULL; node = node->m_next) {
        if (is_item_valid__9TItemListFl(node) != 0) {
            owner = ((TObjPlayer *)node)->get_owner_if_alive();
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)data);
                if (item_identity_matches((u8 *)((s32 *)data), (u8 *)inventory_search_item_data) != 0) {
                    return node;
                }
            }
        }
        found = find_matching_inventory_item_node(node);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

void *TObjPlayer::find_inventory_item_by_field_d8() {
    Node_801D56D0 *root = (Node_801D56D0 *)this;
    Node_801D56D0 *node;
    void *found;
    u32 owner;
    for (node = root->child; node != NULL; node = node->next) {
        if (is_item_valid__9TItemListFl(node) != 0) {
            owner = ((TObjPlayer *)node)->get_owner_if_alive();
            if (owner != 0) {
                if (inventory_update_field_d8_key == ((TItem *)owner)->get_item_id()) {
                    return node;
                }
                inventory_walk_progress_count += 1;
            }
        }
        found = ((TObjPlayer *)node)->find_inventory_item_by_field_d8();
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

s32 TObjPlayer::get_owner_if_alive() {
    if (((TObject *)(*(s32 *)((s8 *)this + 0x1C)))->all_parents_unqueued_for_destruction() != 0) {
        return *(s32 *)((s8 *)this + 0x1C);
    }
    return 0;
}
void TObjPlayer::set_field_1c(s32 v) { *(s32*)((char*)this + 0x1c) = v; }
}
