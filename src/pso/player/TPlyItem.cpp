#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <string.h>
#include "pso/object/base/CollisionBodySet.h"
#include "pso/item/TItem.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_801D40D4.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/TItemList.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_801D4CB8.h"
#include "pso/player/TPlyItem.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"
#include "pso/item/TUnk_804C4498.h"
#include "pso/item/TUnk_804C4468.h"
#include "pso/item/TUnk_804C4480.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80011014.h"

#include "pso/player/TUnk_804B6C24.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

struct Actor_801D3E20 {
    u8 pad[0x30];
    u32 flags;
    u8 pad34[4];
    Vec pos;
    u8 pad44[0x1c];
    s32 facing;
    u8 pad64[0x40];
    CollisionBody *colliders;
    s32 count;
};
struct Req_801D3780 {
    u32 status;
    s32 source;
    u8 item[0xc];
    s32 id;
    s32 extra;
};
struct Ground_801D3C38 { u8 pad0[4]; Vec *pos; };
extern "C" {
s32 poll_memcard_result(saddr);
// The callers sign-extend the result (extsb), the header's member returns u8.
extern void *tl_07;
void *find_placement_obstruction(void *self, CollisionBodySet *s);
}
typedef struct Rec_801D40D4 {
    u8 pad0[4];
    s32 flags;
    u8 type;
    u8 pad9[0x1C - 9];
} Rec_801D40D4;
typedef struct Ent_801D41B4 {
    u8 pad0[8];
    u8 sub[0xC];
    s32 id;
    u8 pad18[4];
} Ent_801D41B4;
typedef struct Ent_801D4744 {
    u32 key;
    u32 val;
} Ent_801D4744;
typedef struct List_801D4744 {
    s32 count;
    Ent_801D4744 *items;
} List_801D4744;
struct Item_801D5004 {
    u8 pad0[0xC];
    Item_801D5004 *next;
    u8 pad10[0x4];
    Item_801D5004 *child;
};
struct Item_801D50E0 {
    u8 pad0[0xC];
    Item_801D50E0 *next;
    u8 pad10[0x4];
    Item_801D50E0 *child;
};
struct Item_801D51A0 {
    u8 pad0[0xC];
    Item_801D51A0 *next;
    u8 pad10[0x4];
    Item_801D51A0 *child;
};
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
void *__construct_new_array(void *block, void (*ctor)(void *), void (*dtor)(void *), u32 size, u32 n);
void fn_801C1BA8(void *, void *);
s32 fn_801D40D4(s32 arg0, Rec_801D40D4 *arg1, u8 *arg2);
int is_quest_active(void);
void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 export_inventory_entry__10TObjPlayerFiPv(saddr arg0, u8 *arg1);
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2);

const char *TItemList__name = "TItemList";
const char *TPlyItem_name_ref = "TPlyItem";

CollisionBody placement_search_collision_body = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
CollisionBodySet placement_search_collision_probe = {&placement_search_collision_body, 1, {0.0f, 0.0f, 0.0f}, 0};

saddr item_reduce_target_player;
u8 *player_item_collect_cursor;
s32 inventory_update_field_d8_key;
s32 *TObjPlayer__owner_field_write_cursor;
s32 inventory_walk_progress_count;
s32 inventory_walk_visit_count;
s32 *player_owner_collect_cursor;
saddr inventory_search_item_data;
saddr owned_item_export_cursor;
u8 item_reduce_owner_match_field_ec;
u8 reduce_owner_match_id;

// The original .text and vtable order (TPlyItem part last-to-first, then TItemList forward) is a deferred region.
#pragma push
#pragma defer_codegen on

// Deferred codegen emits these functions last to first: they are
// written here from the highest address (0x801D57A8) down to 0x801D3780.

void TItemList::set_field_1c(s32 v) { *(s32*)((char*)this + 0x1c) = v; }

saddr TItemList::get_owner_if_alive() {
    if (((TObject *)(*(saddr *)((s8 *)this + 0x1C)))->all_parents_unqueued_for_destruction() != 0) {
        return *(s32 *)((s8 *)this + 0x1C);
    }
    return 0;
}

void *TItemList::find_inventory_item_by_field_d8() {
    Node_801D56D0 *root = (Node_801D56D0 *)this;
    Node_801D56D0 *node;
    void *found;
    uaddr owner;
    for (node = root->child; node != NULL; node = node->next) {
        if (TItemList::is_item_valid((saddr)node) != 0) {
            owner = ((TItemList *)node)->get_owner_if_alive();
            if (owner != 0) {
                if (inventory_update_field_d8_key == ((TItem *)owner)->get_item_id()) {
                    return node;
                }
                inventory_walk_progress_count += 1;
            }
        }
        found = ((TItemList *)node)->find_inventory_item_by_field_d8();
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
    uaddr owner;
    for (node = root->m_down; node != NULL; node = node->m_next) {
        if (TItemList::is_item_valid((saddr)node) != 0) {
            owner = ((TItemList *)node)->get_owner_if_alive();
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

void *TItemList::find_inventory_item_matching_data() {
    Node_801D55A4 *root = (Node_801D55A4 *)this;
    s32 data[8];
    Node_801D55A4 *node;
    void *found;
    uaddr owner;
    for (node = root->child; node != NULL; node = node->next) {
        if (TItemList::is_item_valid((saddr)node) != 0) {
            owner = ((TItemList *)node)->get_owner_if_alive();
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)data);
                if (compare_item_data_masked((void *)data, (void *)inventory_search_item_data, 0) != 0) {
                    return node;
                }
            }
        }
        found = ((TItemList *)node)->find_inventory_item_matching_data();
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

void TItemList::count_items_recursive() {
    s32 sp8[7];
    void *down;

    uaddr temp;

    down = this->m_down;
    while (down != NULL) {
        if ((TItemList::is_item_valid((saddr)down) != 0) && ((temp = ((TItemList *)down)->get_owner_if_alive()) != 0U)) {
            ((TItem *)temp)->copy_to_item_data((TItemData *)&sp8[0]);
            if (item_identity_matches((u8 *)&sp8[0], (u8 *)inventory_search_item_data) != 0) {
                inventory_walk_visit_count += 1;
            }
        }
        ((TItemList *)down)->count_items_recursive();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TItemList::unequip_invalid_items_recursive() {
    Node_801D5468 *arg0 = (Node_801D5468 *)this;
    Node_801D5468 *n;
    TItem *o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (TItemList::is_item_valid((saddr)n) != 0) {
            o = (TItem *)((TItemList *)n)->get_owner_if_alive();
            if ((o != NULL) && (is_item_equipped(o) != 0) && (o->is_unit() == 0) &&
                (TObjPlayer::get_slot_value((s32 *)(item_reduce_target_player + 0xD04), o->get_attach_slot()) != 0U)) {
                unequip_item__10TObjPlayerFiPv(item_reduce_target_player, o);
            }
        }
        ((TItemList *)n)->unequip_invalid_items_recursive();
    }
}

void TItemList::collect_alive_owners() {
    u32 temp_r3;
    void *down;

    down = this->m_down;
    while (down != NULL) {
        if (TItemList::is_item_valid((saddr)(void *)((saddr)down)) != 0) {
            temp_r3 = ((TItemList *)down)->get_owner_if_alive();
            if (temp_r3 != 0U) {
                *player_owner_collect_cursor = temp_r3;
                player_owner_collect_cursor += 1;
                inventory_walk_visit_count += 1;
            }
        }
        ((TItemList *)down)->collect_alive_owners();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TItemList::collect_item_owners_recursive() {
    Node_801D535C *arg0 = (Node_801D535C *)this;
    Node_801D535C *n;
    saddr o;
    for (n = arg0->child; n != NULL; n = n->next) {
        if (TItemList::is_item_valid((saddr)n) != 0) {
            o = ((TItemList *)n)->get_owner_if_alive();
            if ((o != 0) && (((TItem *)o)->is_at_tekker() == 0)) {
                *player_owner_collect_cursor = o;
                player_owner_collect_cursor += 1;
                inventory_walk_visit_count += 1;
            }
        }
        ((TItemList *)n)->collect_item_owners_recursive();
    }
}

void TObjPlayer__sub_801D52A8(TObject *root) {
    TObject *n;
    saddr o;
    for (n = root->m_down; n != NULL; n = n->m_next) {
        if (TItemList::is_item_valid((saddr)n) != 0) {
            o = ((TItemList *)n)->get_owner_if_alive();
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

void TItemList::count_owned_items() {
    void *down;
    u32 temp;

    down = this->m_down;
    while (down != NULL) {
        if ((TItemList::is_item_valid((saddr)down) != 0) && ((temp = ((TItemList *)down)->get_owner_if_alive()) != 0U) && (export_inventory_entry__10TObjPlayerFiPv((s32)temp, (u8 *)owned_item_export_cursor) != 0)) {
            owned_item_export_cursor += 0x1C;
            inventory_walk_visit_count += 1;
        }
        ((TItemList *)down)->count_owned_items();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TItemList::collect_owner_fields_recursive() {
    Item_801D51A0 *self = (Item_801D51A0 *)this;
    Item_801D51A0 *it;
    TItem *owner;
    for (it = self->child; it != NULL; it = it->next) {
        if (TItemList::is_item_valid((saddr)it) != 0 && (owner = (TItem *)((TItemList *)it)->get_owner_if_alive()) != NULL) {
            *TObjPlayer__owner_field_write_cursor++ = owner->get_item_id();
            inventory_walk_visit_count++;
        }
        ((TItemList *)it)->collect_owner_fields_recursive();
    }
}

void TLobby::reduce_child_item_amounts() {
    Item_801D50E0 *self = (Item_801D50E0 *)this;
    TItem *owner;
    Item_801D50E0 *it;
    saddr lobby;
    for (it = self->child; it != NULL; it = it->next) {
        if (TItemList::is_item_valid((saddr)it) != 0) {
            owner = (TItem *)((TItemList *)it)->get_owner_if_alive();
            if (owner != NULL && item_reduce_owner_match_field_ec == owner->get_item_type()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    lobby = item_reduce_target_player;
                    ((TLobby *)(*(saddr *)(lobby + 0xD00)))->reduce_item_amount((s32)lobby, (saddr)it, owner->get_amount());
                } else {
                    ((TLobby *)(*(saddr *)(item_reduce_target_player + 0xD00)))->reduce_item_amount((s32)item_reduce_target_player, (saddr)it, 1);
                }
            }
        }
        ((TLobby *)it)->reduce_child_item_amounts();
    }
}

void TLobby::reduce_owner_matched_items() {
    Item_801D5004 *self = (Item_801D5004 *)this;
    TItem *owner;
    Item_801D5004 *it;
    saddr lobby;
    for (it = self->child; it != NULL; it = it->next) {
        if (TItemList::is_item_valid((saddr)it) != 0) {
            owner = (TItem *)((TItemList *)it)->get_owner_if_alive();
            if (owner != NULL && item_reduce_owner_match_field_ec == owner->get_item_type() &&
                reduce_owner_match_id == owner->get_item_group()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    lobby = item_reduce_target_player;
                    ((TLobby *)(*(saddr *)(lobby + 0xD00)))->reduce_item_amount((s32)lobby, (saddr)it, owner->get_amount());
                } else {
                    ((TLobby *)(*(saddr *)(item_reduce_target_player + 0xD00)))->reduce_item_amount((s32)item_reduce_target_player, (saddr)it, 1);
                }
            }
        }
        ((TLobby *)it)->reduce_child_item_amounts();
    }
}

TPlyItem::TPlyItem(TObject *parent) : TObject(parent) {
    m_name = TPlyItem_name_ref;
    pad_1C = 0;
    pad_1E = 0;
}

TPlyItem::~TPlyItem() {}

void *TPlyItem::start_inventory_update(int key) { inventory_update_field_d8_key = key; inventory_walk_progress_count = 0; return this->pad_1C4->find_inventory_item_by_field_d8(); }

void TItemList::destroy_subobjects_recursive() {
    u8 *p;
    TItem *o;
    p = *(u8 * *)&this->m_down;
    while (p != NULL) {
        if (TItemList::is_item_valid((saddr)p) != 0) {
            o = (TItem *)((TItemList *)p)->get_owner_if_alive();
            if (o != NULL && o->all_parents_unqueued_for_destruction() != 0) {
                o->destroy();
            }
        }
        ((TItemList *)p)->destroy_subobjects_recursive();
        p = *(u8 **)(p + 0xC);
    }
}

void TPlyItem::destroy_subobjects(int a1) { item_reduce_target_player = a1; inventory_walk_progress_count = 0; this->pad_1C4->destroy_subobjects_recursive(); this->pad_1C4->queue_destruction(); ((TObject *)(this->pad_1C8))->run_tasks(); ((TObject *)(this->pad_1C8))->run_tasks(); ((TObject *)(this->pad_1C8))->queue_destruction(); }

void *TPlyItem::set_mode_and_refresh_object(void *item_data) { inventory_search_item_data = (saddr)item_data; return find_matching_inventory_item_node(this->pad_1C4); }

void TPlyItem::find_first_inventory_entry(int a1) { inventory_search_item_data = a1; this->pad_1C4->find_inventory_item_matching_data(); }

s32 TPlyItem::count_items_by_id(saddr arg1) {
    void *node;
    TItem *item;

    if (TItemData::lookup_item_def((void *)arg1) != 0) {
        node = set_mode_and_refresh_object((void *)arg1);
        if (node != NULL) {
            item = (TItem *)((TItemList *)node)->get_owner_if_alive();
            if ((item != NULL) && (item->all_parents_unqueued_for_destruction() != 0)) {
                return item->get_amount();
            }
        }
        return 0;
    }
    inventory_search_item_data = arg1;
    inventory_walk_visit_count = 0;
    this->pad_1C4->count_items_recursive();
    return inventory_walk_visit_count;
}

void TPlyItem::set_flag_and_update(int a1) { item_reduce_target_player = a1; this->pad_1C4->unequip_invalid_items_recursive(); }

int TPlyItem::apply_shop_judgment(void *owners) { player_owner_collect_cursor = (s32 *)owners; inventory_walk_visit_count = 0; this->pad_1C4->collect_alive_owners(); return inventory_walk_visit_count; }

int TPlyItem::count_matching_items(void *owners) { player_owner_collect_cursor = (s32 *)owners; inventory_walk_visit_count = 0; this->pad_1C4->collect_item_owners_recursive(); return inventory_walk_visit_count; }

int TLobby::set_globals_and_notify(TObjPlayer *player, void *records) { player_item_collect_cursor = (u8 *)records; inventory_walk_visit_count = 0; TObjPlayer__sub_801D52A8((TObject *)(*(saddr *)((char*)this + 0x1c4))); return inventory_walk_visit_count; }

void TLobby::set_globals_and_update(int a1, int a2) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; ((TLobby *)(*(saddr *)((char*)this + 0x1c4)))->reduce_child_item_amounts(); }

void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; reduce_owner_match_id = a3; ((TLobby *)(*(saddr *)((char*)a0 + 0x1c4)))->reduce_owner_matched_items(); }

s32 TLobby::use_item(saddr player, s32 key, s32 amount) {
    void *node;

    if (key == -1) {
        try_spend_actor_meseta((u8 *)player, amount);
        return 1;
    }
    node = ((TPlyItem *)this)->start_inventory_update(key);
    if (node == NULL) {
        return 0;
    }
    reduce_item_amount(player, (saddr)node, amount);
    return 1;
}

void TLobby::reduce_item_amount(s32 player, saddr node, s32 arg3) {
    s16 count;
    TItem *item;

    item = (TItem *)((TItemList *)node)->get_owner_if_alive();
    if ((item != NULL) && (arg3 >= 0)) {
        if ((item->get_amount() - arg3) > 0) {
            item->remove_amount(arg3);
            return;
        }
        if (is_item_equipped(item) != 0) {
            unequip_item__10TObjPlayerFiPv(player, item);
        }
        count = *(s16 *)((s8 *)this + 0x1C);
        *(s16 *)((s8 *)this + 0x1C) = (count - 1);
        item->destroy();
        ((TObject *)node)->queue_destruction();
    }
}

void TPlyItem::remove_equipped_item(s32 player, void *node) {
    s16 count;
    TItem *item;

    item = (TItem *)((TItemList *)node)->get_owner_if_alive();
    if (item != NULL) {
        if (is_item_equipped(item) != 0) {
            unequip_item__10TObjPlayerFiPv(player, item);
        }
        count = *(s16 *)((s8 *)this + 0x1C);
        *(s16 *)((s8 *)this + 0x1C) = (count - 1);
        item->destroy();
        ((TObject *)node)->queue_destruction();
    }
}

s32 TObjPlayer__sub_801D49F4(void *inventory, s32 player, s32 *keys, s32 count) {
    s32 i;
    void *node;
    for (i = 0; i < count; keys++, i++) {
        node = ((TPlyItem *)inventory)->start_inventory_update(*keys);
        if (node == NULL) {
            return 0;
        }
        ((TPlyItem *)inventory)->remove_equipped_item(player, node);
    }
    return 1;
}

s32 TPlyItem::update_inventory_item(saddr player, s32 arg2, saddr pos, s32 arg4, s32 client) {
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
    item = (TItem *)((TItemList *)node)->get_owner_if_alive();
    if (item == NULL) {
        return 0;
    }
    if ((item->get_amount() - arg4) > 0) {
        item->remove_amount(arg4);
        return 1;
    }
    if (is_item_equipped(item) != 0) {
        unequip_item__10TObjPlayerFiPv(player, item);
    }
    *(s16 *)((s8 *)item + 0x28) = ((TObjBase *)player)->get_room();
    item->place_on_ground(client, (f32 *)pos, 0);
    count = *(s16 *)&this->pad_1C;
    *(s16 *)&this->pad_1C = (count - 1);
    ((TObject *)node)->queue_destruction();
    return 1;
}

int TPlyItem::run_state_query(int a1) { owned_item_export_cursor = a1; inventory_walk_visit_count = 0; this->pad_1C4->count_owned_items(); return inventory_walk_visit_count; }

int TPlyItem::run_and_get_result(saddr ids) { TObjPlayer__owner_field_write_cursor = (s32 *)ids; inventory_walk_visit_count = 0; this->pad_1C4->collect_owner_fields_recursive(); return inventory_walk_visit_count; }

s32 TObjPlayer__sub_801D47EC(saddr ply_item, s32 key, s32 arg2) {
    TItemList *node_a;
    TItemList *node_b;
    s32 item_a;
    s32 item_b;
    node_a = (TItemList *)((TPlyItem *)ply_item)->start_inventory_update(key);
    if (node_a == NULL) {
        return 0;
    }
    node_b = (TItemList *)((TPlyItem *)ply_item)->start_inventory_update(arg2);
    if (node_b == NULL) {
        return 0;
    }
    item_a = node_a->get_owner_if_alive();
    if (item_a == 0) {
        return 0;
    }
    item_b = node_b->get_owner_if_alive();
    if (item_b == 0) {
        return 0;
    }
    node_a->set_field_1c(item_b);
    node_b->set_field_1c(item_a);
    return 1;
}

void TObjPlayer__sub_801D47D8(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjPlayer::sort_by_key() {
    List_801D4744 *arg0 = (List_801D4744 *)this;
    Ent_801D4744 t;
    s32 n;
    s32 j;
    Ent_801D4744 *p;
    Ent_801D4744 *q;
    TObjPlayer__sub_801D4730(&t);
    n = arg0->count;
    while (--n > 0) {
        p = arg0->items;
        for (j = 0; j < n; p++, j++) {
            q = p + 1;
            if (p->key > q->key) {
                TObjPlayer__sub_801D47D8(&t, p);
                TObjPlayer__sub_801D47D8(p, q);
                TObjPlayer__sub_801D47D8(q, &t);
            }
        }
    }
}

void TObjPlayer__sub_801D4730(void* p) { *(s32*)((char*)p + 0x0) = -1; *(s32*)((char*)p + 0x4) = 0; }

u8 *TObjPlayer__sub_801D46D4(u8 *arg0, s32 arg1) {
    s32 n;
    *(s32 *)arg0 = arg1;
    n = *(s32 *)arg0;
    *(void **)(arg0 + 4) = __construct_new_array(mem_alloc((n * 8 + 0x10)), TObjPlayer__sub_801D4730, 0, 8, n);
    return arg0;
}

u8 *TObjPlayer__sub_801D4678(u8 *arg0, s16 arg1) {
    u8 *q;
    if (arg0 != NULL) {
        q = *(u8 **)(arg0 + 4);
        if (q != NULL) {
            if (q != NULL) {
                mem_free((q - 0x10));
            }
        }
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

void TObjPlayer__sub_801D45B0(s32 *rec, saddr item) {
    s32 temp_r4;
    *rec = 0;
    temp_r4 = ((TItem *)item)->get_item_type() << 0x19;
    *rec |= temp_r4;
    if (((TItem *)item)->get_item_type() == 1) {
        *rec |= (((TItem *)item)->get_item_group() << 0x11) & 0x01FE0000;
    } else {
        *rec |= (((TItem *)item)->get_item_group() << 8) & 0xFF00;
    }
    *rec |= ((TItem *)item)->get_item_index();
    if (is_item_equipped((TItem *)item) == 0) {
        *rec |= 0x10000;
    }
}

extern "C" s32 TObjPlayer__sub_801D4368(TObjPlayer *player) {
    u8 *obj;
    s32 cnt_2;
    u32 *rec;
    s32 cnt;
    void *down_4;
    s32 owner;
    u32 *rec_2;
    u32 *rec_3;
    void *down_3;
    void *down_2;
    void *down;
    s32 cnt_3;

    if (*(void **)((s8 *)player + 0x1c4) == NULL) {
        return 0;
    }
    if (TItemList::is_item_valid((saddr)*(void **)((s8 *)player + 0x1c4)) == 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)player + 0x1c) > 0x1e || *(s16 *)((s8 *)player + 0x1c) < 1) {
        return 0;
    }
    obj = (u8 *)::operator new(8);
    if (obj != NULL) {
        obj = TObjPlayer__sub_801D46D4(obj, *(s16 *)((s8 *)player + 0x1c));
    }
    if (obj == NULL) {
        return 0;
    }
    if (*(u32 *)(obj + 4) == 0) {
        TObjPlayer__sub_801D4678(obj, 1);
        return 0;
    }
    cnt = 0;
    down = *(void **)((s8 *)*(saddr *)((s8 *)player + 0x1c4) + 0x14);
    while (down != NULL) {
        if (TItemList::is_item_valid((saddr)down) != 0 && ((TItemList *)down)->get_owner_if_alive() != 0U) {
            cnt++;
        }
        down = *(void **)((s8 *)down + 0xC);
    }
    if (cnt != *(s16 *)((s8 *)player + 0x1c)) {
        TObjPlayer__sub_801D4678(obj, 1);
        return 0;
    }
    cnt_2 = 0;
    rec = (u32 *)*(saddr *)(obj + 4);
    down_2 = *(void **)((s8 *)*(saddr *)((s8 *)player + 0x1c4) + 0x14);
    while (down_2 != NULL) {
        if (TItemList::is_item_valid((saddr)down_2) != 0 && (owner = ((TItemList *)down_2)->get_owner_if_alive()) != 0U) {
            rec[1] = owner;
            TObjPlayer__sub_801D45B0((s32 *)rec, owner);
            rec = (u32 *)((s8 *)rec + 8);
            cnt_2++;
        }
        down_2 = *(void **)((s8 *)down_2 + 0xC);
    }
    ((TObjPlayer *)obj)->sort_by_key();
    cnt_3 = 0;
    down_3 = *(void **)((s8 *)*(saddr *)((s8 *)player + 0x1c4) + 0x14);
    rec_2 = (u32 *)*(saddr *)(obj + 4);
    while (down_3 != NULL) {
        if (TItemList::is_item_valid((saddr)down_3) != 0 && ((TItemList *)down_3)->get_owner_if_alive() != 0U && rec_2[1] != 0) {
            rec_2 = (u32 *)((s8 *)rec_2 + 8);
            cnt_3++;
        }
        down_3 = *(void **)((s8 *)down_3 + 0xC);
    }
    if (cnt_2 != cnt_3) {
        TObjPlayer__sub_801D4678(obj, 1);
        return 0;
    }
    rec_3 = (u32 *)*(saddr *)(obj + 4);
    down_4 = *(void **)((s8 *)*(saddr *)((s8 *)player + 0x1c4) + 0x14);
    while (down_4 != NULL) {
        if (TItemList::is_item_valid((saddr)down_4) != 0 && ((TItemList *)down_4)->get_owner_if_alive() != 0U) {
            if (rec_3[1] != 0) {
                ((TItemList *)down_4)->set_field_1c((s32)rec_3[1]);
                rec_3 = (u32 *)((s8 *)rec_3 + 8);
            }
        }
        down_4 = *(void **)((s8 *)down_4 + 0xC);
    }
    TObjPlayer__sub_801D4678(obj, 1);
    return 1;
}

s32 export_inventory_entry__10TObjPlayerFiPv(saddr item, u8 *arg1) {
    if (((TItem *)item)->copy_to_item_data((TItemData *)(arg1 + 8)) != 0) {
        *(s8 *)((s8 *)arg1 + 0) = ((TItem *)item)->get_mode();
        *(s32 *)((s8 *)arg1 + 4) = ((TItem *)item)->get_item_flags();
        return 1;
    }
    return 0;
}

saddr reset(void* p) { return (saddr)memset(p, 0, 28); }

s32 fn_801D4270(s32 id) {
    s32 i;
    u8 *p;
    void *list = (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
    if ((uaddr)list == 0) {
        return 0;
    }
    p = (u8 *)((TObjPlayer *)list)->get_ptr_4();
    for (i = 0; i < 30; i++, p += 0x1C) {
        if (*(s32 *)(p + 0x14) == id) {
            return 1;
        }
    }
    return 0;
}

void remove_list_entry_by_id(s32 arg0) {
    u8 *cnt;
    s32 i;
    s32 n;
    Ent_801D41B4 *p;
    s32 rem;
    cnt = ((u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    if (cnt != NULL) {
        p = ((Ent_801D41B4 *)((TObjPlayer *)cnt)->get_ptr_4());
        n = *cnt;
        for (i = 0; i < n; p++, i++) {
            if (p->id == arg0) {
                if (((TAdSinglePlyChrSelectGC *)p->sub)->is_both_confirmed() != 0) {
                    TAdSinglePlyChrSelectGC::remove_matching_entries((saddr)cnt);
                }
                rem = n - i;
                *cnt -= 1;
                if (rem <= 0) {
                    reset(p);
                    return;
                }
                memcpy(p, p + 1, rem * 0x1C);
                return;
            }
        }
    }
}

s32 check_player_action_allowed(void) {
    if ((get_main_phase() == 0xE) || (TTecCtrl::is_technique_ready() != 0) || ((is_quest_active() == 1) && (get_game_play_mode() == 1))) {
        return 0;
    }
    return TAdSinglePlyChrSelectGC::get_game_mode();
}

s32 fn_801D40D4(s32 arg0, Rec_801D40D4 *arg1, u8 *arg2) {
    s32 i;
    for (i = 0; i < arg0; i++) {
        if (arg1->flags & 8) {
            if (arg1->type == 0) {
                fn_801C1BA8(arg2, arg1);
            }
            if (arg1->type == 2) {
                fn_801C1BA8(arg2 + 0x1C, arg1);
            }
        }
        arg1++;
    }
    return 1;
}

TUnk_804C4498::TUnk_804C4498(TObject *parent, TObjBase *source, const Vec *pos, s8 arg) : TObject(parent) {
    if (source == NULL) {
        this->client_id = 0xFFFF;
        this->room = 0;
        this->heading = 0;
    } else {
        this->client_id = get_entity_id(source);
        this->room = source->get_room();
        this->heading = source->rotation_y;
    }
    VecCopy(&this->origin, pos);
    this->unk_1C = arg;
    this->candidate.z = 0.0f;
    this->candidate.y = 0.0f;
    this->candidate.x = 0.0f;
    this->online = 0;
}

TUnk_804C4498::~TUnk_804C4498() {
}

void TUnk_804C4498::reset_placement_search_ring() {
    this->sample = 0;
    if (this->ring == 0) {
        this->count = 1;
    } else {
        this->count = this->ring * 4;
    }
    this->step = 0x10000 / this->count;
    this->angle = this->heading;
    this->radius = 6.0f * this->ring;
}

void *find_placement_obstruction(void *self, CollisionBodySet *s) {
    s32 end = TLobby::get_lobby_flag();
    s32 i;
    for (i = TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i < end; i++) {
        Actor_801D3E20 *a = (Actor_801D3E20 *)TObjPlayer::get_player_data(i);
        if (a != 0 && a->colliders != 0 && !(a->flags & 0x800)) {
            if (10000.0f > horizontal_distance_squared(&s->position, &a->pos)) {
                CollisionBodySet b;
                void *r;
                b.colliders = a->colliders;
                b.count = a->count;
                VecCopy(&b.position, &a->pos);
                b.facing = a->facing;
                r = refresh_actor_body_spheres(*s, b);
                if (r != 0) {
                    return r;
                }
            }
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TUnk_804C4498::step_placement_search() {
    Ground_801D3C38 *g;
    if (check_player_action_allowed() != 0 && this->online != 0 &&
        TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 1) {
        TLobby::disconnect_protocol();
        queue_destruction();
        return 2;
    }
    if (this->ring > 5) {
        this->ring = 1;
        reset_placement_search_ring();
        return 2;
    }
    if (this->sample >= this->count) {
        this->ring++;
        reset_placement_search_ring();
    }
    this->candidate.x = this->radius * sin_table_lookup(this->angle) + this->origin.x;
    this->candidate.y = this->origin.y;
    this->candidate.z = this->radius * cos_table_lookup(this->angle) + this->origin.z;
    g = (Ground_801D3C38 *)csnVecterUnder(&this->candidate, 0x41);
    if (g == NULL) {
        this->angle += this->step;
        this->sample++;
        return 0;
    }
    this->candidate.y = 6.0f + g->pos->y;
    placement_search_collision_body.radius = 3.0f;
    placement_search_collision_body.shape = 0;
    placement_search_collision_body.flags = 0x31F03;
    VecCopy(&placement_search_collision_probe.position, &this->candidate);
    if (find_placement_obstruction(this, &placement_search_collision_probe) != NULL) {
        this->angle += this->step;
        this->sample++;
        return 0;
    }
    if (check_player_action_allowed() != 0 && this->online != 0 &&
        poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0) {
        return 0;
    }
    return 1;
}
#pragma pop

TUnk_804C4480::TUnk_804C4480(TObject *parent, s32 list, TObjBase *source, const Vec *pos, s8 arg)
    : TUnk_804C4498(parent, source, pos, arg) {
    this->unk_54 = list;
    sub_801D5884(0);
    reset_placement_search_ring();
}

TUnk_804C4480::~TUnk_804C4480() {
    clear_placement_search_slot((TItemList *)this, this->unk_54);
    decrement_placement_search_pending(this, (void *)this->unk_54);
}

void *TItemList__sub_801D3B00(void *list, void *source, void *pos, s8 arg3) {
    return new TUnk_804C4480((TObject *)tl_07, (saddr)list, (TObjBase *)source, (const Vec *)pos, arg3);
}

void TUnk_804C4480::run_task() {
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        TItemList__sub_801D59A0((TItemList *)this, this->unk_54);
        this->sub_801D5A70();
        break;
    case 2:
        ((TItemList *)this)->lookup_entry_by_count(this->unk_54);
        break;
    }
    queue_destruction();
}

TUnk_804C4468::TUnk_804C4468(TObject *parent, s32 list, TObjBase *source, const Vec *pos, s8 arg)
    : TUnk_804C4498(parent, source, pos, arg) {
    TItemList *entry;
    this->unk_54 = list;
    sub_801D5884(1);
    reset_placement_search_ring();
    if (check_player_action_allowed() != 0) {
        entry = (TItemList *)((TItemList *)this)->run_item_count_update();
        if (fn_801D4270(*(s32 *)((s8 *)entry + 4)) != 0) {
            remove_list_entry_by_id(*(s32 *)((s8 *)entry + 4));
            if (load_character_from_card__23TAdSinglePlyChrSelectGCFv() != 0) {
                queue_destruction();
                return;
            }
            this->online = 1;
        }
    }
}

TUnk_804C4468::~TUnk_804C4468() {
    clear_placement_search_slot((TItemList *)this, this->unk_54);
    decrement_placement_search_pending(this, (void *)this->unk_54);
}

void *TItemList::create_node(void *list, void *source, void *pos, s8 arg3) {
    return new TUnk_804C4468((TObject *)tl_07, (saddr)list, (TObjBase *)source, (const Vec *)pos, arg3);
}

void TUnk_804C4468::run_task() {
    Req_801D3780 *r;
    TObjPlayer *player;
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        TItemList__sub_801D59A0((TItemList *)this, this->unk_54);
        sub_801D591C();
        r = (Req_801D3780 *)((TItemList *)this)->run_item_count_update();
        player = get_player_by_client_id(get_client_id());
        if (player != NULL) {
            if (r->id == -1) {
                if (r->source == -1) {
                    drop_stacked_item((TItemData *)r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    TObjPlayer::send_6x29_delete_item(player, r->source, r->extra);
                    TObjPlayer::send_code_45_1((saddr)player);
                } else {
                    drop_stacked_item((TItemData *)r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    TObjPlayer::send_6x29_delete_item(player, r->source, ((TItemData *)r->item)->get_stack_count());
                    TObjPlayer::send_code_45_1((saddr)player);
                }
            } else {
                TObjPlayer::send_6x2A_drop_item(player, r->source, get_ptr_0x44__9TItemListFPv(this), ((TItemData *)r->item)->get_stack_count());
                TObjPlayer::send_code_45_1((saddr)player);
            }
        }
        break;
    case 2:
        ((TItemList *)this)->lookup_entry_by_count(this->unk_54);
        break;
    }
    queue_destruction();
}

#pragma pop

struct Arr_801D5868 { s32 n; s32 e[1]; };
struct Ent_801D598C { u8 d[0x10]; };
struct Obj_801D598C { u8 pad[0x28]; Ent_801D598C e[1]; };
struct Ent_801D5854 { u8 d[0x1C]; };
struct Obj_801D5854 { u8 pad[0xA8]; Ent_801D5854 arr[1]; };

extern "C" {
s32 *TItemList__sub_801D5868(Arr_801D5868 *, s32);
Ent_801D5854 *TItemList__sub_801D5854(Obj_801D5854 *p, s32 i);
void *TItemList__sub_801D598C(Obj_801D598C *arg0, s32 arg1);
int copy_from__9TItemDataFP9TItemData(void*);
}

TItemList::TItemList(TObject *parent) : TObject(parent) {
    m_name = TItemList__name;
    pad_1C = 0;
    disallow_rendering();
}


void TItemList__sub_801D5804(s32 *list) {
    *list += 1;
}

int TItemList::copy_item_data() { return copy_from__9TItemDataFP9TItemData((char*)this + 0x8); }
void TItemList__sub_801D5838(void* p) { *(s32*)((char*)p + 0x0) = 1; }
int TItemList__sub_801D5844(void* p) { return *(u32*)((char*)p + 0x0) == 0; }

Ent_801D5854 *TItemList__sub_801D5854(Obj_801D5854 *p, s32 i) {
    return &p->arr[i];
}

s32 *TItemList__sub_801D5868(Arr_801D5868 *list, s32 arg1) {
    return &list->e[arg1];
}

void* get_ptr_0x44__9TItemListFPv(void* p) { return (char*)p + 0x44; }
void TUnk_804C4498::sub_801D5884(u8 v) { this->ring = v; }

void TItemList::lookup_entry_by_count(saddr list) {
    TItemList__sub_801D58C8(TItemList__sub_801D5868((Arr_801D5868 *)list, (s8)get_item_count()));
}

void TItemList__sub_801D58C8(void* p) { *(s32*)((char*)p + 0x0) = 3; }
u8 TItemList::get_item_count() { return *(u8*)((char*)this + 0x1c); }
u16 TUnk_804C4468::get_client_id() { return this->client_id; }

void *TItemList::run_item_count_update() {
    return TItemList__sub_801D5854(*(Obj_801D5854 **)((s8 *)this + 0x54), (s8)get_item_count());
}

void TUnk_804C4468::sub_801D591C() {
    copy_position__9TItemListFPv(TItemList__sub_801D598C((Obj_801D598C *)this->unk_54, (s8)((TItemList *)this)->get_item_count()), (const Vec *)get_ptr_0x44__9TItemListFPv(this));
}

void copy_position__9TItemListFPv(void *p, const Vec *v) { VecCopy((Vec *)((char *)p + 0x4), v); }

void *TItemList__sub_801D598C(Obj_801D598C *arg0, s32 arg1) {
    return &arg0->e[arg1];
}
void TItemList__sub_801D59A0(TItemList *item_list, saddr list) {
    TItemList__sub_801D59DC(TItemList__sub_801D5868((Arr_801D5868 *)list, (s8)item_list->get_item_count()));
}

void TItemList__sub_801D59DC(void* p) { *(s32*)((char*)p + 0x0) = 2; }

void decrement_placement_search_pending(void* p, void* a1) { TItemList__sub_801D5A0C((s32 *)a1); }

void TItemList__sub_801D5A0C(s32 *arg0) {
    s32 temp_r0;
    temp_r0 = *arg0 - 1;
    *arg0 = temp_r0;
    if (temp_r0 < 0) {
        *arg0 = 0;
    }
}

void clear_placement_search_slot(TItemList *item_list, saddr list) {
    TItemList__sub_801D5A64(TItemList__sub_801D5868((Arr_801D5868 *)list, (s8)item_list->get_item_count()));
}

void TItemList__sub_801D5A64(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void TUnk_804C4480::sub_801D5A70() {
    copy_position__9TItemListFPv(TItemList__sub_801D598C((Obj_801D598C *)this->unk_54, (s8)((TItemList *)this)->get_item_count()), (const Vec *)get_ptr_0x44__9TItemListFPv(this));
}

s32 TItemList::is_item_valid(saddr arg0) {
    u8 valid;

    valid = 0;
    if ((((TUnk_804B6C24 *)arg0)->check_value_equals((saddr)TItemList__name) != 0) && (((TObject *)arg0)->all_parents_unqueued_for_destruction() != 0)) {
        valid = 1;
    }
    return valid;
}

TUnk_804C445C::~TUnk_804C445C() {}
TUnk_804C4450::~TUnk_804C4450() {}
TUnk_804C4444::~TUnk_804C4444() {}
TUnk_804C445C::TUnk_804C445C() {}
TUnk_804C4450::TUnk_804C4450() {}
Unk_801D5CB8::Unk_801D5CB8() { x = y = z = 0.0f; }
TUnk_804C4444::TUnk_804C4444() { count = 0; }

TItemList::~TItemList() {}
