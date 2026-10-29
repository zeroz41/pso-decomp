#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/item/TItem.h"
#include "pso/misc/TOSwitchItem.h"

typedef struct ItemNode_801D563C {
    u8 pad0[0xC];
    struct ItemNode_801D563C *next;
    u8 pad10[4];
    struct ItemNode_801D563C *child;
} ItemNode_801D563C;

typedef struct Node_801D535C {
    u8 pad0[0xC];
    struct Node_801D535C *next;
    u8 pad10[4];
    struct Node_801D535C *child;
} Node_801D535C;

typedef struct Node_801D52A8 {
    u8 pad0[0xC];
    struct Node_801D52A8 *next;
    u8 pad10[4];
    struct Node_801D52A8 *child;
} Node_801D52A8;

typedef struct Node_801D5468 {
    u8 pad0[0xC];
    struct Node_801D5468 *next;
    u8 pad10[4];
    struct Node_801D5468 *child;
} Node_801D5468;

class Obj_801D5468 {
public:
    u8 pad[0x18];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual s8 v31();
};

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
void *find_matching_inventory_item_node(ItemNode_801D563C *root);
s32 is_at_tekker__5TItemFv();
extern s32 inventory_walk_visit_count;
extern u32 *player_owner_collect_cursor;
s32 is_item_equipped();
extern u8 *player_item_collect_cursor;
void TObjPlayer__sub_801D52A8(Node_801D52A8 *arg0);
void unequip_item__10TObjPlayerFiPv(s32 arg0, void *arg1);
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

void TObjPlayer__sub_801D52A8(Node_801D52A8 *arg0) {
    Node_801D52A8 *n;
    s32 o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (is_item_valid__9TItemListFl(n) != 0) {
            o = ((TObjPlayer *)n)->get_owner_if_alive();
            if ((o != 0) && (is_item_equipped() != 0) && (((TItem *)o)->get_item_type() == 0)) {
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
    Obj_801D5468 *o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (is_item_valid__9TItemListFl(n) != 0) {
            o = (Obj_801D5468 *)((TObjPlayer *)n)->get_owner_if_alive();
            if ((o != NULL) && (is_item_equipped() != 0) && (((TItem *)o)->is_unit() == 0) &&
                (get_slot_value__10TObjPlayerFPvi((s32 *)(item_reduce_target_player + 0xD04), o->v31()) != 0U)) {
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

void *find_matching_inventory_item_node(ItemNode_801D563C *root) {
    s32 data[8];
    ItemNode_801D563C *node;
    void *found;
    u32 owner;
    for (node = root->child; node != NULL; node = node->next) {
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
