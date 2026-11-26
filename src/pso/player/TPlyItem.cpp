#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/save/CardFileInfo.h"
#include "pso/item/item_create.h"
#include "pso/item/InventoryEntryCopy.h"
#include "types.h"
#include "pso/player/TPlyCharData.h"
#include <string.h>
#include "pso/object/base/CollisionBodySet.h"
#include "pso/item/TItem.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/system/GameModeQueries.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerCommands.h"
#include "pso/item/TItemList.h"
#include "pso/network/TLobby.h"
#include "pso/player/TPlyItem.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItemData.h"
#include "pso/item/TPlacementSearch.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/math/AngleLookup.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjCharaHelpers.h"
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
void *__construct_new_array(void *block, void (*ctor)(void *), void (*dtor)(void *), u32 size, u32 n);
}

const char *TItemList::class_name = "TItemList";
const char *TPlyItem::class_name = "TPlyItem";

CollisionBody placement_search_collision_body = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
CollisionBodySet placement_search_collision_probe = {&placement_search_collision_body, 1, {0.0f, 0.0f, 0.0f}, 0};

TObjPlayer *item_reduce_target_player;
PendingItemDrop *player_item_collect_cursor;
s32 inventory_search_item_id;
s32 *item_id_write_cursor;
s32 inventory_walk_progress_count;
s32 inventory_walk_visit_count;
TItem **player_owner_collect_cursor;
void *inventory_search_item_data;
TPlyInventoryItem *owned_item_export_cursor;
u8 item_reduce_type;
u8 item_reduce_group;

// The original .text and vtable order (TPlyItem part last-to-first, then TItemList forward) is a deferred region.
#pragma push
#pragma defer_codegen on

// Deferred codegen emits these functions last to first: they are
// written here from the highest address down.

void TItemList::set_owner(TItem *item) { item_owner = item; }

TItem *TItemList::get_owner_if_alive() {
    if (item_owner->all_parents_unqueued_for_destruction() != 0) {
        return item_owner;
    }
    return NULL;
}

TItemList *TItemList::find_item_by_id() {
    TItemList *node;
    TItemList *found;
    TItem *owner;
    for (node = (TItemList *)m_down; node != NULL; node = (TItemList *)node->m_next) {
        if (TItemList::is_item_valid(node) != 0) {
            owner = node->get_owner_if_alive();
            if (owner != NULL) {
                if (inventory_search_item_id == owner->get_item_id()) {
                    return node;
                }
                inventory_walk_progress_count += 1;
            }
        }
        found = node->find_item_by_id();
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
                if (item_identity_matches((u8 *)(data), (u8 *)inventory_search_item_data) != 0) {
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
                if (compare_item_data_masked(data, inventory_search_item_data, 0) != 0) {
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
    s32 item_data[7];
    TItemList *down;

    TItem *temp;

    down = (TItemList *)m_down;
    while (down != NULL) {
        if ((TItemList::is_item_valid(down) != 0) && ((temp = down->get_owner_if_alive()) != NULL)) {
            temp->copy_to_item_data((TItemData *)&item_data[0]);
            if (item_identity_matches((u8 *)&item_data[0], (u8 *)inventory_search_item_data) != 0) {
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
            if ((o != NULL) && (o->is_equipped() != 0) && (o->is_unit() == 0) &&
                (TObjPlayer::get_slot_value(reinterpret_cast<s32 *>(item_reduce_target_player->equipped_items.items), o->get_attach_slot()) != 0U)) {
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

void TItemList::collect_equipped_weapons() {
    TItemList *n;
    TItem *o;
    for (n = (TItemList *)m_down; n != NULL; n = (TItemList *)n->m_next) {
        if (TItemList::is_item_valid(n) != 0) {
            o = n->get_owner_if_alive();
            if ((o != NULL) && (o->is_equipped() != 0) && (o->get_item_type() == 0)) {
                o->copy_to_item_data(&player_item_collect_cursor->item);
                player_item_collect_cursor->source_id = o->get_item_id();
                ++player_item_collect_cursor;
                inventory_walk_visit_count += 1;
            }
        }
        n->collect_equipped_weapons();
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
            *item_id_write_cursor++ = owner->get_item_id();
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
            if (owner != NULL && item_reduce_type == owner->get_item_type()) {
                if (item_reduce_type == 3) {
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
            if (owner != NULL && item_reduce_type == owner->get_item_type() &&
                item_reduce_group == owner->get_item_group()) {
                if (item_reduce_type == 3) {
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
    m_name = class_name;
    item_count = 0;
    pad_1E = 0;
}

TPlyItem::~TPlyItem() {}

TItemList *TPlyItem::start_inventory_update(int key) {
    inventory_search_item_id = key;
    inventory_walk_progress_count = 0;
    return item_list->find_item_by_id();
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
    item_list->destroy_subobjects_recursive();
    item_list->queue_destruction();
    item_root->run_tasks();
    item_root->run_tasks();
    item_root->queue_destruction();
}

TItemList *TPlyItem::set_mode_and_refresh_object(void *data) {
    inventory_search_item_data = data;
    return find_matching_inventory_item_node(item_list);
}

TItemList *TPlyItem::find_first_inventory_entry(TItemData *data) {
    inventory_search_item_data = data;
    return item_list->find_inventory_item_matching_data();
}

s32 TPlyItem::count_items_by_id(TItemData *data) {
    TItemList *node;
    TItem *item;

    if (data->lookup_item_def() != 0) {
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
    item_list->count_items_recursive();
    return inventory_walk_visit_count;
}

void TPlyItem::set_flag_and_update(TObjPlayer *player) {
    item_reduce_target_player = player;
    item_list->unequip_invalid_items_recursive();
}

int TPlyItem::apply_shop_judgment(TItem **out) {
    player_owner_collect_cursor = out;
    inventory_walk_visit_count = 0;
    item_list->collect_alive_owners();
    return inventory_walk_visit_count;
}

int TPlyItem::count_matching_items(TItem **out) {
    player_owner_collect_cursor = out;
    inventory_walk_visit_count = 0;
    item_list->collect_item_owners_recursive();
    return inventory_walk_visit_count;
}

int TPlyItem::set_globals_and_notify(TObjPlayer *player, PendingItemDrop *out) {
    player_item_collect_cursor = out;
    inventory_walk_visit_count = 0;
    item_list->collect_equipped_weapons();
    return inventory_walk_visit_count;
}

void TPlyItem::set_globals_and_update(TObjPlayer *player, int kind) {
    item_reduce_target_player = player;
    item_reduce_type = kind;
    item_list->reduce_child_item_amounts();
}

void TPlyItem::reduce_items_of_kind(TObjPlayer *player, int item_type, int item_group) {
    item_reduce_target_player = player;
    item_reduce_type = item_type;
    item_reduce_group = item_group;
    item_list->reduce_owner_matched_items();
}

s32 TPlyItem::use_item(TObjPlayer *player, s32 key, s32 amount) {
    TItemList *node;

    if (key == -1) {
        player->try_spend_actor_meseta(amount);
        return 1;
    }
    node = start_inventory_update(key);
    if (node == NULL) {
        return 0;
    }
    reduce_item_amount(player, node, amount);
    return 1;
}

void TPlyItem::reduce_item_amount(TObjPlayer *player, TItemList *slot, s32 amount) {
    s16 count;
    TItem *item;

    item = slot->get_owner_if_alive();
    if ((item != NULL) && (amount >= 0)) {
        if ((item->get_amount() - amount) > 0) {
            item->remove_amount(amount);
            return;
        }
        if (item->is_equipped() != 0) {
            player->unequip_item(item);
        }
        count = item_count;
        item_count = (count - 1);
        item->destroy();
        slot->queue_destruction();
    }
}

void TPlyItem::remove_equipped_item(TObjPlayer *player, TItemList *slot) {
    s16 count;
    TItem *item;

    item = slot->get_owner_if_alive();
    if (item != NULL) {
        if (item->is_equipped() != 0) {
            player->unequip_item(item);
        }
        count = item_count;
        item_count = (count - 1);
        item->destroy();
        slot->queue_destruction();
    }
}

s32 TPlyItem::remove_items(TObjPlayer *player, s32 *item_ids, s32 count) {
    s32 i;
    TItemList *node;
    for (i = 0; i < count; item_ids++, i++) {
        node = start_inventory_update(*item_ids);
        if (node == NULL) {
            return 0;
        }
        remove_equipped_item(player, node);
    }
    return 1;
}

s32 TPlyItem::update_inventory_item(TObjPlayer *player, s32 key, f32 *position, s32 amount, s32 client) {
    s16 count;
    TItem *item;
    TItemList *node;

    if (amount < 0) {
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
    if ((item->get_amount() - amount) > 0) {
        item->remove_amount(amount);
        return 1;
    }
    if (item->is_equipped() != 0) {
        player->unequip_item(item);
    }
    item->room = player->get_room();
    item->place_on_ground(client, position, 0);
    count = item_count;
    item_count = (count - 1);
    node->queue_destruction();
    return 1;
}

int TPlyItem::run_state_query(TPlyInventoryItem *out) {
    owned_item_export_cursor = out;
    inventory_walk_visit_count = 0;
    item_list->count_owned_items();
    return inventory_walk_visit_count;
}

int TPlyItem::run_and_get_result(s32 *out) {
    item_id_write_cursor = out;
    inventory_walk_visit_count = 0;
    item_list->collect_owner_fields_recursive();
    return inventory_walk_visit_count;
}

s32 TPlyItem::swap_items(s32 item_id, s32 other_id) {
    TItemList *node_a;
    TItemList *node_b;
    TItem *item_a;
    TItem *item_b;
    node_a = start_inventory_update(item_id);
    if (node_a == NULL) {
        return 0;
    }
    node_b = start_inventory_update(other_id);
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
    node_a->set_owner(item_b);
    node_b->set_owner(item_a);
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

void InventorySortEntry::set_key(TItem *item) {
    s32 type_bits;
    key = 0;
    type_bits = item->get_item_type() << 0x19;
    key |= type_bits;
    if (item->get_item_type() == 1) {
        key |= (item->get_item_group() << 0x11) & 0x01FE0000;
    } else {
        key |= (item->get_item_group() << 8) & 0xFF00;
    }
    key |= item->get_item_index();
    if (item->is_equipped() == 0) {
        key |= 0x10000;
    }
}

s32 TPlyItem::sort_items() {
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

    if (item_list == NULL) {
        return 0;
    }
    if (TItemList::is_item_valid(item_list) == 0) {
        return 0;
    }
    if (item_count > 30 || item_count < 1) {
        return 0;
    }
    recs = new InventorySortBuffer(item_count);
    if (recs == NULL) {
        return 0;
    }
    if (recs->items == NULL) {
        delete recs;
        return 0;
    }
    counted = 0;
    node = (TItemList *)item_list->m_down;
    while (node != NULL) {
        if (TItemList::is_item_valid(node) != 0 && node->get_owner_if_alive() != NULL) {
            counted++;
        }
        node = (TItemList *)node->m_next;
    }
    if (counted != item_count) {
        delete recs;
        return 0;
    }
    filled = 0;
    rec = recs->items;
    node_filled = (TItemList *)item_list->m_down;
    while (node_filled != NULL) {
        if (TItemList::is_item_valid(node_filled) != 0 && (owner = node_filled->get_owner_if_alive()) != NULL) {
            rec->val = owner;
            rec->set_key(owner);
            rec++;
            filled++;
        }
        node_filled = (TItemList *)node_filled->m_next;
    }
    recs->sort_by_key();
    checked = 0;
    rec_checked = recs->items;
    node_checked = (TItemList *)item_list->m_down;
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
    node_assigned = (TItemList *)item_list->m_down;
    while (node_assigned != NULL) {
        if (TItemList::is_item_valid(node_assigned) != 0 && node_assigned->get_owner_if_alive() != NULL) {
            if (rec_assigned->val != NULL) {
                node_assigned->set_owner(rec_assigned->val);
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

s32 selected_character_has_item(s32 id) {
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

void remove_list_entry_by_id(s32 id) {
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
            if (static_cast<s32>(p->m_data.id) == id) {
                if (p->m_data.is_frame() != 0) {
                    selected->unequip_units();
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

s32 check_player_action_allowed() {
    if ((get_main_phase() == 0xE) || (TTecCtrl::is_technique_ready() != 0) || ((is_quest_active() == 1) && (get_game_play_mode() == 1))) {
        return 0;
    }
    return TAdSinglePlyChrSelectGC::get_game_mode();
}

s32 copy_equipped_weapon_and_mag(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *slots) {
    for (s32 i = 0; i < count; i++) {
        if (source->m_flags & 8) {
            if (source->m_data.data1.data_u8[0] == 0) {
                copy_inventory_item(slots, source);
            }
            if (source->m_data.data1.data_u8[0] == 2) {
                copy_inventory_item(slots + 1, source);
            }
        }
        source++;
    }
    return 1;
}

TPlacementSearch::TPlacementSearch(TObject *parent, TObjBase *source, const Vec *pos, s32 slot) : TObject(parent) {
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
    this->slot = slot;
    this->candidate.z = 0.0f;
    this->candidate.y = 0.0f;
    this->candidate.x = 0.0f;
    this->online = 0;
}

TPlacementSearch::~TPlacementSearch() {
}

void TPlacementSearch::reset_placement_search_ring() {
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

void *TPlacementSearch::find_obstruction(CollisionBodySet *probe) {
    s32 end = TLobby::get_lobby_flag();
    s32 i;
    for (i = TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i < end; i++) {
        Actor_801D3E20 *a = (Actor_801D3E20 *)TObjPlayer::get_player_data(i);
        if (a != 0 && a->colliders != 0 && !(a->flags & 0x800)) {
            if (10000.0f > horizontal_distance_squared(&probe->position, &a->pos)) {
                CollisionBodySet b;
                void *r;
                b.colliders = a->colliders;
                b.count = a->count;
                VecCopy(&b.position, &a->pos);
                b.facing = a->facing;
                r = refresh_actor_body_spheres(*probe, b);
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
s32 TPlacementSearch::step_placement_search() {
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
    if (find_obstruction(&placement_search_collision_probe) != NULL) {
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

TPositionSearch::TPositionSearch(TObject *parent, PositionPlacementQueue *queue, TObjBase *source, const Vec *pos,
                                 s32 slot)
    : TPlacementSearch(parent, source, pos, slot) {
    this->queue = queue;
    set_ring(0);
    reset_placement_search_ring();
}

TPositionSearch::~TPositionSearch() {
    clear_slot(queue);
    finish(queue);
}

TPositionSearch *TPositionSearch::create(PositionPlacementQueue *queue, TObjBase *source, const Vec *pos, s32 slot) {
    return new TPositionSearch(tl_07, queue, source, pos, slot);
}

void TPositionSearch::run_task() {
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        set_slot_placed(queue);
        store_position();
        break;
    case 2:
        set_slot_failed(queue);
        break;
    }
    queue_destruction();
}

TItemDropSearch::TItemDropSearch(TObject *parent, ItemDropQueue *queue, TObjBase *source, const Vec *pos, s32 slot)
    : TPlacementSearch(parent, source, pos, slot) {
    PendingItemDrop *entry;
    this->queue = queue;
    set_ring(1);
    reset_placement_search_ring();
    if (check_player_action_allowed() != 0) {
        entry = get_record();
        if (selected_character_has_item(entry->source_id) != 0) {
            remove_list_entry_by_id(entry->source_id);
            if (TAdSinglePlyChrSelectGC::load_character_from_card() != 0) {
                queue_destruction();
                return;
            }
            this->online = 1;
        }
    }
}

TItemDropSearch::~TItemDropSearch() {
    clear_slot(queue);
    finish(queue);
}

TItemDropSearch *TItemDropSearch::create(ItemDropQueue *queue, TObjBase *source, const Vec *pos, s32 slot) {
    return new TItemDropSearch(tl_07, queue, source, pos, slot);
}

void TItemDropSearch::run_task() {
    PendingItemDrop *r;
    TObjPlayer *player;
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        set_slot_placed(queue);
        store_position();
        r = get_record();
        player = get_player_by_client_id(get_client_id());
        if (player != NULL) {
            if (static_cast<s32>(r->item.id) == -1) {
                if (r->source_id == -1) {
                    drop_stacked_item(&r->item, get_client_id(), (f32 *)get_candidate());
                    TObjPlayer::send_6x29_delete_item(player, r->source_id, r->item.data2.data_u32);
                    send_release_hold(player);
                } else {
                    drop_stacked_item(&r->item, get_client_id(), (f32 *)get_candidate());
                    TObjPlayer::send_6x29_delete_item(player, r->source_id, r->item.get_stack_count());
                    send_release_hold(player);
                }
            } else {
                TObjPlayer::send_6x2A_drop_item(player, r->source_id, get_candidate(), r->item.get_stack_count());
                send_release_hold(player);
            }
        }
        break;
    case 2:
        set_slot_failed(queue);
        break;
    }
    queue_destruction();
}

void start_placement_search(PositionPlacementQueue *queue, Vec *pos, TObjBase *source) {
    queue->get_slot(0)->reserve();
    TPositionSearch::create(queue, source, pos, 0);
    queue->increment_count();
}

PlacementSlot &PlacementSlot::operator=(const PlacementSlot &other) {
    state = other.state;
    return *this;
}

void ItemDropQueue::add_drops(Vec *position, TObjPlayer *owner, PendingItemDrop *drops, s32 count) {
    s32 i;
    PlacementSlot *slot;
    PendingItemDrop *entry;

    slot = get_slot(0);
    entry = get_record(0);
    for (i = 0; i < count; i++) {
        if (slot->is_free() != 0) {
            slot->reserve();
            *entry = *drops;
            TItemDropSearch::create(this, owner, position, i);
            increment_count();
            ++slot;
            ++entry;
            ++drops;
        }
    }
}

void ItemDropQueue::add_drop(Vec *position, TObjPlayer *owner, TItemData *item, s32 id) {
    PlacementSlot *slot = get_slot(0);
    PendingItemDrop *record = get_record(0);
    if (slot->is_free() != 0) {
        slot->reserve();
        record->set_source_id(id);
        record->copy_item_data(item);
        TItemDropSearch::create(this, owner, position, 0);
        increment_count();
    }
}

#pragma pop

TItemList::TItemList(TObject *parent) : TObject(parent) {
    m_name = class_name;
    item_owner = NULL;
    disallow_rendering();
}


void PlacementQueue::increment_count() {
    ++count;
}

void PendingItemDrop::copy_item_data(TItemData *source) {
    item.copy_from(source);
}
void PlacementSlot::reserve() { state = 1; }
s32 PlacementSlot::is_free() { return state == 0; }

PendingItemDrop *ItemDropQueue::get_record(s32 index) {
    return &records[index];
}

PlacementSlot *PlacementQueue::get_slot(s32 index) {
    return &slots[index];
}

Vec *TPlacementSearch::get_candidate() { return &candidate; }
void TPlacementSearch::set_ring(u8 index) { ring = index; }

void TPlacementSearch::set_slot_failed(PlacementQueue *queue) {
    queue->get_slot((s8)get_slot())->set_failed();
}

void PlacementSlot::set_failed() { state = 3; }
u8 TPlacementSearch::get_slot() { return slot; }
u16 TItemDropSearch::get_client_id() { return this->client_id; }

PendingItemDrop *TItemDropSearch::get_record() {
    return queue->get_record((s8)get_slot());
}

void TItemDropSearch::store_position() {
    queue->get_position((s8)get_slot())->set_position(get_candidate());
}

void PlacementPosition::set_position(const Vec *v) { VecCopy(&pos, v); }

PlacementPosition *PositionPlacementQueue::get_position(s32 index) {
    return &positions[index];
}
void TPlacementSearch::set_slot_placed(PlacementQueue *queue) {
    queue->get_slot((s8)get_slot())->set_placed();
}

void PlacementSlot::set_placed() { state = 2; }

void TPlacementSearch::finish(PlacementQueue *queue) { queue->decrement_count(); }

void PlacementQueue::decrement_count() {
    s32 value;
    value = count - 1;
    count = value;
    if (value < 0) {
        count = 0;
    }
}

void TPlacementSearch::clear_slot(PlacementQueue *queue) {
    queue->get_slot((s8)get_slot())->clear();
}

void PlacementSlot::clear() { state = 0; }

void TPositionSearch::store_position() {
    queue->get_position((s8)get_slot())->set_position(get_candidate());
}

s32 TItemList::is_item_valid(TItemList *list) {
    u8 valid;

    valid = 0;
    if ((list->check_value_equals(class_name) != 0) && (list->all_parents_unqueued_for_destruction() != 0)) {
        valid = 1;
    }
    return valid;
}

ItemDropQueue::~ItemDropQueue() {}
PositionPlacementQueue::~PositionPlacementQueue() {}
PlacementQueue::~PlacementQueue() {}
ItemDropQueue::ItemDropQueue() {}
PositionPlacementQueue::PositionPlacementQueue() {}
PlacementPosition::PlacementPosition() { pos.x = pos.y = pos.z = 0.0f; }
PlacementQueue::PlacementQueue() { count = 0; }

TItemList::~TItemList() {}
