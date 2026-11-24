#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/save/CardFileInfo.h"
#include "pso/item/InventoryEntryCopy.h"
#include "types.h"
#include "pso/player/TPlyCharData.h"
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
#include "pso/player/TPlyDispData.h"

#include "pso/technique/TTecCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

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
struct Ground_801D3C38 { u8 pad0[4]; Vec *pos; };
extern "C" {
// The callers sign-extend the result (extsb), the header's member returns u8.
extern void *tl_07;
void *find_placement_obstruction(void *self, CollisionBodySet *s);
}
struct InventorySortEntry {
    u32 key;
    TItem *val;
    InventorySortEntry();
    // Non-const source: the original reloads other.val after storing key.
    InventorySortEntry &operator=(InventorySortEntry &other);
};

// The 8-byte list TObjPlayer__sub_801D4368 allocates with new and frees with
// delete (the destructor's s16 argument is MWCC's delete flag).
struct InventorySortBuffer {
    s32 count;
    InventorySortEntry *items;
    InventorySortBuffer(s32 n);
    ~InventorySortBuffer();
    // Bubble-sorts records by key.
    void sort_by_key();
};
extern "C" {
void *__construct_new_array(void *block, void (*ctor)(void *), void (*dtor)(void *), u32 size, u32 n);
s32 item_identity_matches(u8 *arg0, u8 *arg1);
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2);

const char *TItemList__name = "TItemList";
const char *TPlyItem_name_ref = "TPlyItem";

CollisionBody placement_search_collision_body = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
CollisionBodySet placement_search_collision_probe = {&placement_search_collision_body, 1, {0.0f, 0.0f, 0.0f}, 0};

TObjPlayer *item_reduce_target_player;
PendingItemDrop *player_item_collect_cursor;
s32 inventory_update_field_d8_key;
s32 *TObjPlayer__owner_field_write_cursor;
s32 inventory_walk_progress_count;
s32 inventory_walk_visit_count;
TItem **player_owner_collect_cursor;
void *inventory_search_item_data;
TPlyInventoryItem *owned_item_export_cursor;
u8 item_reduce_owner_match_field_ec;
u8 reduce_owner_match_id;

// The original .text and vtable order (TPlyItem part last-to-first, then TItemList forward) is a deferred region.
#pragma push
#pragma defer_codegen on

// Deferred codegen emits these functions last to first: they are
// written here from the highest address (0x801D57A8) down to 0x801D3780.

void TItemList::set_field_1c(TItem *item) { item_owner = item; }

TItem *TItemList::get_owner_if_alive() {
    if (item_owner->all_parents_unqueued_for_destruction() != 0) {
        return item_owner;
    }
    return NULL;
}

TItemList *TItemList::find_inventory_item_by_field_d8() {
    TItemList *node;
    TItemList *found;
    TItem *owner;
    for (node = (TItemList *)m_down; node != NULL; node = (TItemList *)node->m_next) {
        if (TItemList::is_item_valid(node) != 0) {
            owner = node->get_owner_if_alive();
            if (owner != NULL) {
                if (inventory_update_field_d8_key == owner->get_item_id()) {
                    return node;
                }
                inventory_walk_progress_count += 1;
            }
        }
        found = node->find_inventory_item_by_field_d8();
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

TItemList *find_matching_inventory_item_node(TObject *root) {
    s32 data[8];
    TItemList *node;
    TItemList *found;
    TItem *owner;
    for (node = (TItemList *)root->m_down; node != NULL; node = (TItemList *)node->m_next) {
        if (TItemList::is_item_valid(node) != 0) {
            owner = node->get_owner_if_alive();
            if (owner != NULL) {
                owner->copy_to_item_data((TItemData *)data);
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

TItemList *TItemList::find_inventory_item_matching_data() {
    s32 data[8];
    TItemList *node;
    TItemList *found;
    TItem *owner;
    for (node = (TItemList *)m_down; node != NULL; node = (TItemList *)node->m_next) {
        if (TItemList::is_item_valid(node) != 0) {
            owner = node->get_owner_if_alive();
            if (owner != NULL) {
                owner->copy_to_item_data((TItemData *)data);
                if (compare_item_data_masked((void *)data, (void *)inventory_search_item_data, 0) != 0) {
                    return node;
                }
            }
        }
        found = node->find_inventory_item_matching_data();
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

void TItemList::count_items_recursive() {
    s32 sp8[7];
    TItemList *down;

    TItem *temp;

    down = (TItemList *)m_down;
    while (down != NULL) {
        if ((TItemList::is_item_valid(down) != 0) && ((temp = down->get_owner_if_alive()) != NULL)) {
            temp->copy_to_item_data((TItemData *)&sp8[0]);
            if (item_identity_matches((u8 *)&sp8[0], (u8 *)inventory_search_item_data) != 0) {
                inventory_walk_visit_count += 1;
            }
        }
        down->count_items_recursive();
        down = (TItemList *)down->m_next;
    }
}

void TItemList::unequip_invalid_items_recursive() {
    TItemList *n;
    TItem *o;
    for (n = (TItemList *)m_down; n != NULL; n = (TItemList *)n->m_next) {
        if (TItemList::is_item_valid(n) != 0) {
            o = n->get_owner_if_alive();
            if ((o != NULL) && (is_item_equipped(o) != 0) && (o->is_unit() == 0) &&
                (TObjPlayer::get_slot_value(reinterpret_cast<s32 *>(item_reduce_target_player->equipped_items), o->get_attach_slot()) != 0U)) {
                item_reduce_target_player->unequip_item(o);
            }
        }
        n->unequip_invalid_items_recursive();
    }
}

void TItemList::collect_alive_owners() {
    TItem *owner_if_alive;
    TItemList *down;

    down = (TItemList *)m_down;
    while (down != NULL) {
        if (TItemList::is_item_valid(down) != 0) {
            owner_if_alive = down->get_owner_if_alive();
            if (owner_if_alive != NULL) {
                *player_owner_collect_cursor = owner_if_alive;
                player_owner_collect_cursor += 1;
                inventory_walk_visit_count += 1;
            }
        }
        down->collect_alive_owners();
        down = (TItemList *)down->m_next;
    }
}

void TItemList::collect_item_owners_recursive() {
    TItemList *n;
    TItem *o;
    for (n = (TItemList *)m_down; n != NULL; n = (TItemList *)n->m_next) {
        if (TItemList::is_item_valid(n) != 0) {
            o = n->get_owner_if_alive();
            if ((o != NULL) && (o->is_at_tekker() == 0)) {
                *player_owner_collect_cursor = o;
                player_owner_collect_cursor += 1;
                inventory_walk_visit_count += 1;
            }
        }
        n->collect_item_owners_recursive();
    }
}

void TObjPlayer__sub_801D52A8(TItemList *root) {
    TItemList *n;
    TItem *o;
    for (n = (TItemList *)root->m_down; n != NULL; n = (TItemList *)n->m_next) {
        if (TItemList::is_item_valid(n) != 0) {
            o = n->get_owner_if_alive();
            if ((o != NULL) && (is_item_equipped(o) != 0) && (o->get_item_type() == 0)) {
                o->copy_to_item_data(&player_item_collect_cursor->item);
                player_item_collect_cursor->source_id = o->get_item_id();
                ++player_item_collect_cursor;
                inventory_walk_visit_count += 1;
            }
        }
        TObjPlayer__sub_801D52A8(n);
    }
}

void TItemList::count_owned_items() {
    TItemList *down;
    TItem *temp;

    down = (TItemList *)m_down;
    while (down != NULL) {
        if ((TItemList::is_item_valid(down) != 0) && ((temp = down->get_owner_if_alive()) != NULL) && (temp->export_inventory_entry(owned_item_export_cursor) != 0)) {
            ++owned_item_export_cursor;
            inventory_walk_visit_count += 1;
        }
        down->count_owned_items();
        down = (TItemList *)down->m_next;
    }
}

void TItemList::collect_owner_fields_recursive() {
    TItemList *it;
    TItem *owner;
    for (it = (TItemList *)m_down; it != NULL; it = (TItemList *)it->m_next) {
        if (TItemList::is_item_valid(it) != 0 && (owner = it->get_owner_if_alive()) != NULL) {
            *TObjPlayer__owner_field_write_cursor++ = owner->get_item_id();
            inventory_walk_visit_count++;
        }
        it->collect_owner_fields_recursive();
    }
}

void TItemList::reduce_child_item_amounts() {
    TItem *owner;
    TItemList *it;
    TObjPlayer *player;
    for (it = (TItemList *)m_down; it != NULL; it = (TItemList *)it->m_next) {
        if (TItemList::is_item_valid(it) != 0) {
            owner = it->get_owner_if_alive();
            if (owner != NULL && item_reduce_owner_match_field_ec == owner->get_item_type()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    player = item_reduce_target_player;
                    player->inventory_objects->reduce_item_amount(player, it, owner->get_amount());
                } else {
                    item_reduce_target_player->inventory_objects->reduce_item_amount(item_reduce_target_player, it, 1);
                }
            }
        }
        it->reduce_child_item_amounts();
    }
}

void TItemList::reduce_owner_matched_items() {
    TItem *owner;
    TItemList *it;
    TObjPlayer *player;
    for (it = (TItemList *)m_down; it != NULL; it = (TItemList *)it->m_next) {
        if (TItemList::is_item_valid(it) != 0) {
            owner = it->get_owner_if_alive();
            if (owner != NULL && item_reduce_owner_match_field_ec == owner->get_item_type() &&
                reduce_owner_match_id == owner->get_item_group()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    player = item_reduce_target_player;
                    player->inventory_objects->reduce_item_amount(player, it, owner->get_amount());
                } else {
                    item_reduce_target_player->inventory_objects->reduce_item_amount(item_reduce_target_player, it, 1);
                }
            }
        }
        it->reduce_child_item_amounts();
    }
}

TPlyItem::TPlyItem(TObject *parent) : TObject(parent) {
    m_name = TPlyItem_name_ref;
    pad_1C = 0;
    pad_1E = 0;
}

TPlyItem::~TPlyItem() {}

TItemList *TPlyItem::start_inventory_update(int key) {
    inventory_update_field_d8_key = key;
    inventory_walk_progress_count = 0;
    return pad_1C4->find_inventory_item_by_field_d8();
}

void TItemList::destroy_subobjects_recursive() {
    TItemList *p;
    TItem *o;
    p = (TItemList *)m_down;
    while (p != NULL) {
        if (TItemList::is_item_valid(p) != 0) {
            o = p->get_owner_if_alive();
            if (o != NULL && o->all_parents_unqueued_for_destruction() != 0) {
                o->destroy();
            }
        }
        p->destroy_subobjects_recursive();
        p = (TItemList *)p->m_next;
    }
}

void TPlyItem::destroy_subobjects(TObjPlayer *player) {
    item_reduce_target_player = player;
    inventory_walk_progress_count = 0;
    pad_1C4->destroy_subobjects_recursive();
    pad_1C4->queue_destruction();
    pad_1C8->run_tasks();
    pad_1C8->run_tasks();
    pad_1C8->queue_destruction();
}

TItemList *TPlyItem::set_mode_and_refresh_object(void *data) {
    inventory_search_item_data = data;
    return find_matching_inventory_item_node(pad_1C4);
}

TItemList *TPlyItem::find_first_inventory_entry(TItemData *data) {
    inventory_search_item_data = data;
    return pad_1C4->find_inventory_item_matching_data();
}

s32 TPlyItem::count_items_by_id(TItemData *data) {
    TItemList *node;
    TItem *item;

    if (TItemData::lookup_item_def(data) != 0) {
        node = set_mode_and_refresh_object(data);
        if (node != NULL) {
            item = node->get_owner_if_alive();
            if ((item != NULL) && (item->all_parents_unqueued_for_destruction() != 0)) {
                return item->get_amount();
            }
        }
        return 0;
    }
    inventory_search_item_data = data;
    inventory_walk_visit_count = 0;
    pad_1C4->count_items_recursive();
    return inventory_walk_visit_count;
}

void TPlyItem::set_flag_and_update(TObjPlayer *player) {
    item_reduce_target_player = player;
    pad_1C4->unequip_invalid_items_recursive();
}

int TPlyItem::apply_shop_judgment(TItem **out) {
    player_owner_collect_cursor = out;
    inventory_walk_visit_count = 0;
    pad_1C4->collect_alive_owners();
    return inventory_walk_visit_count;
}

int TPlyItem::count_matching_items(TItem **out) {
    player_owner_collect_cursor = out;
    inventory_walk_visit_count = 0;
    pad_1C4->collect_item_owners_recursive();
    return inventory_walk_visit_count;
}

int TPlyItem::set_globals_and_notify(TObjPlayer *player, PendingItemDrop *out) {
    player_item_collect_cursor = out;
    inventory_walk_visit_count = 0;
    TObjPlayer__sub_801D52A8(pad_1C4);
    return inventory_walk_visit_count;
}

void TPlyItem::set_globals_and_update(TObjPlayer *player, int kind) {
    item_reduce_target_player = player;
    item_reduce_owner_match_field_ec = kind;
    pad_1C4->reduce_child_item_amounts();
}

void TLobby__sub_801D4C28(TPlyItem *inventory, TObjPlayer *player, int item_type, int item_group) {
    item_reduce_target_player = player;
    item_reduce_owner_match_field_ec = item_type;
    reduce_owner_match_id = item_group;
    inventory->pad_1C4->reduce_owner_matched_items();
}

s32 TPlyItem::use_item(TObjPlayer *player, s32 key, s32 arg3) {
    TItemList *node;

    if (key == -1) {
        try_spend_actor_meseta(player, arg3);
        return 1;
    }
    node = start_inventory_update(key);
    if (node == NULL) {
        return 0;
    }
    reduce_item_amount(player, node, arg3);
    return 1;
}

void TPlyItem::reduce_item_amount(TObjPlayer *player, TItemList *slot, s32 arg3) {
    s16 count;
    TItem *item;

    item = slot->get_owner_if_alive();
    if ((item != NULL) && (arg3 >= 0)) {
        if ((item->get_amount() - arg3) > 0) {
            item->remove_amount(arg3);
            return;
        }
        if (is_item_equipped(item) != 0) {
            player->unequip_item(item);
        }
        count = pad_1C;
        pad_1C = (count - 1);
        item->destroy();
        slot->queue_destruction();
    }
}

void TPlyItem::remove_equipped_item(TObjPlayer *player, TItemList *slot) {
    s16 count;
    TItem *item;

    item = slot->get_owner_if_alive();
    if (item != NULL) {
        if (is_item_equipped(item) != 0) {
            player->unequip_item(item);
        }
        count = pad_1C;
        pad_1C = (count - 1);
        item->destroy();
        slot->queue_destruction();
    }
}

s32 TObjPlayer__sub_801D49F4(TPlyItem *inventory, TObjPlayer *player, s32 *item_ids, s32 count) {
    s32 i;
    void *node;
    for (i = 0; i < count; item_ids++, i++) {
        node = inventory->start_inventory_update(*item_ids);
        if (node == NULL) {
            return 0;
        }
        inventory->remove_equipped_item(player, (TItemList *)node);
    }
    return 1;
}

s32 TPlyItem::update_inventory_item(TObjPlayer *player, s32 key, f32 *position, s32 arg4, s32 client) {
    s16 count;
    TItem *item;
    TItemList *node;

    if (arg4 < 0) {
        return 0;
    }
    node = start_inventory_update(key);
    if (node == NULL) {
        return 0;
    }
    item = node->get_owner_if_alive();
    if (item == NULL) {
        return 0;
    }
    if ((item->get_amount() - arg4) > 0) {
        item->remove_amount(arg4);
        return 1;
    }
    if (is_item_equipped(item) != 0) {
        player->unequip_item(item);
    }
    item->room = player->get_room();
    item->place_on_ground(client, position, 0);
    count = pad_1C;
    pad_1C = (count - 1);
    node->queue_destruction();
    return 1;
}

int TPlyItem::run_state_query(TPlyInventoryItem *out) {
    owned_item_export_cursor = out;
    inventory_walk_visit_count = 0;
    pad_1C4->count_owned_items();
    return inventory_walk_visit_count;
}

int TPlyItem::run_and_get_result(s32 *out) {
    TObjPlayer__owner_field_write_cursor = out;
    inventory_walk_visit_count = 0;
    pad_1C4->collect_owner_fields_recursive();
    return inventory_walk_visit_count;
}

s32 TObjPlayer__sub_801D47EC(TPlyItem *ply_item, s32 key, s32 arg2) {
    TItemList *node_a;
    TItemList *node_b;
    TItem *item_a;
    TItem *item_b;
    node_a = ply_item->start_inventory_update(key);
    if (node_a == NULL) {
        return 0;
    }
    node_b = ply_item->start_inventory_update(arg2);
    if (node_b == NULL) {
        return 0;
    }
    item_a = node_a->get_owner_if_alive();
    if (item_a == NULL) {
        return 0;
    }
    item_b = node_b->get_owner_if_alive();
    if (item_b == NULL) {
        return 0;
    }
    node_a->set_field_1c(item_b);
    node_b->set_field_1c(item_a);
    return 1;
}

InventorySortEntry &InventorySortEntry::operator=(InventorySortEntry &other) {
    key = other.key;
    val = other.val;
    return *this;
}

void InventorySortBuffer::sort_by_key() {
    InventorySortEntry t;
    s32 n;
    s32 j;
    InventorySortEntry *p;
    InventorySortEntry *q;
    n = count;
    while (--n > 0) {
        p = items;
        for (j = 0; j < n; p++, j++) {
            q = p + 1;
            if (p->key > q->key) {
                t = *p;
                *p = *q;
                *q = t;
            }
        }
    }
}

InventorySortEntry::InventorySortEntry() {
    key = -1;
    val = NULL;
}

extern "C" void __ct__18InventorySortEntryFv(void *entry);

InventorySortBuffer::InventorySortBuffer(s32 n) {
    count = n;
    // The runtime stores a 0x10-byte array cookie before the records.
    items = reinterpret_cast<InventorySortEntry *>(__construct_new_array(
        mem_alloc(count * sizeof(*items) + 0x10), __ct__18InventorySortEntryFv, 0, sizeof(*items), count));
}

InventorySortBuffer::~InventorySortBuffer() {
    InventorySortEntry *records = items;
    if (records != NULL) {
        if (records != NULL) {
            mem_free(reinterpret_cast<u8 *>(records) - 0x10);
        }
    }
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

extern "C" s32 TObjPlayer__sub_801D4368(TPlyItem *ply) {
    InventorySortBuffer *recs;
    s32 filled;
    InventorySortEntry *rec;
    s32 counted;
    TItemList *node_assigned;
    TItem *owner;
    InventorySortEntry *rec_checked;
    InventorySortEntry *rec_assigned;
    TItemList *node_checked;
    TItemList *node_filled;
    TItemList *node;
    s32 checked;

    if (ply->pad_1C4 == NULL) {
        return 0;
    }
    if (TItemList::is_item_valid(ply->pad_1C4) == 0) {
        return 0;
    }
    if (ply->pad_1C > 30 || ply->pad_1C < 1) {
        return 0;
    }
    recs = new InventorySortBuffer(ply->pad_1C);
    if (recs == NULL) {
        return 0;
    }
    if (recs->items == NULL) {
        delete recs;
        return 0;
    }
    counted = 0;
    node = (TItemList *)ply->pad_1C4->m_down;
    while (node != NULL) {
        if (TItemList::is_item_valid(node) != 0 && node->get_owner_if_alive() != NULL) {
            counted++;
        }
        node = (TItemList *)node->m_next;
    }
    if (counted != ply->pad_1C) {
        delete recs;
        return 0;
    }
    filled = 0;
    rec = recs->items;
    node_filled = (TItemList *)ply->pad_1C4->m_down;
    while (node_filled != NULL) {
        if (TItemList::is_item_valid(node_filled) != 0 && (owner = node_filled->get_owner_if_alive()) != NULL) {
            rec->val = owner;
            TObjPlayer__sub_801D45B0(reinterpret_cast<s32 *>(&rec->key), (saddr)owner);
            rec++;
            filled++;
        }
        node_filled = (TItemList *)node_filled->m_next;
    }
    recs->sort_by_key();
    checked = 0;
    rec_checked = recs->items;
    node_checked = (TItemList *)ply->pad_1C4->m_down;
    while (node_checked != NULL) {
        if (TItemList::is_item_valid(node_checked) != 0 && node_checked->get_owner_if_alive() != NULL && rec_checked->val != NULL) {
            rec_checked++;
            checked++;
        }
        node_checked = (TItemList *)node_checked->m_next;
    }
    if (filled != checked) {
        delete recs;
        return 0;
    }
    rec_assigned = recs->items;
    node_assigned = (TItemList *)ply->pad_1C4->m_down;
    while (node_assigned != NULL) {
        if (TItemList::is_item_valid(node_assigned) != 0 && node_assigned->get_owner_if_alive() != NULL) {
            if (rec_assigned->val != NULL) {
                node_assigned->set_field_1c(rec_assigned->val);
                rec_assigned++;
            }
        }
        node_assigned = (TItemList *)node_assigned->m_next;
    }
    delete recs;
    return 1;
}

s32 TItem::export_inventory_entry(TPlyInventoryItem *dest) {
    if (copy_to_item_data(&dest->m_data) != 0) {
        dest->m_present[0] = get_mode();
        dest->m_flags = get_item_flags();
        return 1;
    }
    return 0;
}

saddr reset(void* p) { return (saddr)memset(p, 0, 28); }

s32 fn_801D4270(s32 id) {
    s32 i;
    TPlyInventoryItem *p;
    TPlyInventory *list = reinterpret_cast<TPlyInventory *>(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    if (list == NULL) {
        return 0;
    }
    p = list->get_items();
    for (i = 0; i < 30; i++, ++p) {
        if (static_cast<s32>(p->m_data.id) == id) {
            return 1;
        }
    }
    return 0;
}

void remove_list_entry_by_id(s32 arg0) {
    TPlyInventory *selected;
    s32 i;
    s32 n;
    TPlyInventoryItem *p;
    s32 rem;
    selected = reinterpret_cast<TPlyInventory *>(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    if (selected != NULL) {
        p = selected->get_items();
        n = selected->m_num_items;
        for (i = 0; i < n; p++, i++) {
            if (static_cast<s32>(p->m_data.id) == arg0) {
                if ((reinterpret_cast<TAdSinglePlyChrSelectGC *>(&p->m_data))->is_both_confirmed() != 0) {
                    TAdSinglePlyChrSelectGC::remove_matching_entries(reinterpret_cast<saddr>(selected));
                }
                rem = n - i;
                selected->m_num_items -= 1;
                if (rem <= 0) {
                    reset(p);
                    return;
                }
                memcpy(p, p + 1, rem * sizeof(*p));
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

s32 fn_801D40D4(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *slots) {
    for (s32 i = 0; i < count; i++) {
        if (source->m_flags & 8) {
            if (source->m_data.data1.data_u8[0] == 0) {
                fn_801C1BA8(slots, source);
            }
            if (source->m_data.data1.data_u8[0] == 2) {
                fn_801C1BA8(slots + 1, source);
            }
        }
        source++;
    }
    return 1;
}

TUnk_804C4498::TUnk_804C4498(TObject *parent, TObjBase *source, const Vec *pos, s8 arg) : TObject(parent) {
    if (source == NULL) {
        this->client_id = 0xFFFF;
        this->room = 0;
        this->heading = 0;
    } else {
        this->client_id = source->get_entity_id();
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
    PendingItemDrop *entry;
    this->unk_54 = list;
    sub_801D5884(1);
    reset_placement_search_ring();
    if (check_player_action_allowed() != 0) {
        entry = ((TItemList *)this)->run_item_count_update();
        if (fn_801D4270(entry->source_id) != 0) {
            remove_list_entry_by_id(entry->source_id);
            if (TAdSinglePlyChrSelectGC::load_character_from_card() != 0) {
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
    PendingItemDrop *r;
    TObjPlayer *player;
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        TItemList__sub_801D59A0((TItemList *)this, this->unk_54);
        sub_801D591C();
        r = ((TItemList *)this)->run_item_count_update();
        player = get_player_by_client_id(get_client_id());
        if (player != NULL) {
            if (static_cast<s32>(r->item.id) == -1) {
                if (r->source_id == -1) {
                    drop_stacked_item(&r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    TObjPlayer::send_6x29_delete_item(player, r->source_id, r->item.data2.data_u32);
                    send_release_hold(player);
                } else {
                    drop_stacked_item(&r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    TObjPlayer::send_6x29_delete_item(player, r->source_id, r->item.get_stack_count());
                    send_release_hold(player);
                }
            } else {
                TObjPlayer::send_6x2A_drop_item(player, r->source_id, get_ptr_0x44__9TItemListFPv(this), r->item.get_stack_count());
                send_release_hold(player);
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

TItemList::TItemList(TObject *parent) : TObject(parent) {
    m_name = TItemList__name;
    item_owner = NULL;
    disallow_rendering();
}


void TItemList__sub_801D5804(TUnk_804C4444 *pool) {
    ++pool->count;
}

void PendingItemDrop::copy_item_data(TItemData *source) {
    item.copy_from(source);
}
void TItemList__sub_801D5838(void* p) { *(s32*)((char*)p + 0x0) = 1; }
int TItemList__sub_801D5844(void* p) { return *(u32*)((char*)p + 0x0) == 0; }

PendingItemDrop *TItemList__sub_801D5854(TUnk_804C445C *pool, s32 index) {
    return &pool->records[index];
}

Unk_801C2098 *TItemList__sub_801D5868(TUnk_804C4444 *pool, s32 index) {
    return &pool->entries[index];
}

void* get_ptr_0x44__9TItemListFPv(void* p) { return (char*)p + 0x44; }
void TUnk_804C4498::sub_801D5884(u8 v) { this->ring = v; }

void TItemList::lookup_entry_by_count(saddr list) {
    TItemList__sub_801D58C8((void*)(((u8 *)TItemList__sub_801D5868((TUnk_804C4444 *)(list), (s8)(get_item_count())))));
}

void TItemList__sub_801D58C8(void* p) { *(s32*)((char*)p + 0x0) = 3; }
u8 TItemList::get_item_count() { return *(u8*)((char*)this + 0x1c); }
u16 TUnk_804C4468::get_client_id() { return this->client_id; }

PendingItemDrop *TItemList::run_item_count_update() {
    return TItemList__sub_801D5854(*(TUnk_804C445C **)((s8 *)this + 0x54), (s8)get_item_count());
}

void TUnk_804C4468::sub_801D591C() {
    copy_position__9TItemListFPv((void *)TItemList__sub_801D598C((TUnk_804C4450 *)this->unk_54, (s8)((TItemList *)this)->get_item_count()), (const Vec *)get_ptr_0x44__9TItemListFPv(this));
}

void copy_position__9TItemListFPv(void *p, const Vec *v) { VecCopy((Vec *)((char *)p + 0x4), v); }

Unk_801D5CB8 *TItemList__sub_801D598C(TUnk_804C4450 *pool, s32 index) {
    return &pool->positions[index];
}
void TItemList__sub_801D59A0(TItemList *item_list, saddr list) {
    TItemList__sub_801D59DC((void*)(((u8 *)TItemList__sub_801D5868((TUnk_804C4444 *)list, (s8)item_list->get_item_count()))));
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
    TItemList__sub_801D5A64((void*)(TItemList__sub_801D5868((TUnk_804C4444 *)list, (s8)item_list->get_item_count())));
}

void TItemList__sub_801D5A64(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void TUnk_804C4480::sub_801D5A70() {
    copy_position__9TItemListFPv((void *)TItemList__sub_801D598C((TUnk_804C4450 *)this->unk_54, (s8)((TItemList *)this)->get_item_count()), (const Vec *)get_ptr_0x44__9TItemListFPv(this));
}

s32 TItemList::is_item_valid(TItemList *arg0) {
    u8 valid;

    valid = 0;
    if ((arg0->check_value_equals(TItemList__name) != 0) && (arg0->all_parents_unqueued_for_destruction() != 0)) {
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
