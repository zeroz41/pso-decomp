#ifndef PSO_PLAYER_TPLYITEM_H
#define PSO_PLAYER_TPLYITEM_H

#include "pso/item/TItemData.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>
#include "types.h"
struct TItem;

class TItemList;
struct TObjPlayer;
struct TItem;
class TPlyInventoryItem;
class TObjBase;

// A queue slot: 0 free, 1 reserved by a placement search, 2 placed, 3 no place found.
struct PlacementSlot {
    s32 state;
    PlacementSlot();
    PlacementSlot &operator=(const PlacementSlot &other);
    void reserve();
    s32 is_free();
    s32 is_placed();
    void set_placed();
    void set_failed();
    void clear();
};
struct PlacementPosition {
    PlacementSlot head;
    Vec pos;
    PlacementPosition();
    void set_position(const Vec *v);
};
// A pending drop: the inventory item ID it came from (-1 for meseta) and the item.
struct PendingItemDrop {
    PlacementSlot head;
    s32 source_id;
    TItemData item;
    PendingItemDrop();
    void set_source_id(s32 id);
    void copy_item_data(TItemData *source);
};
// Slots handed to placement searches (TPlacementSearch) and the number still searching.
class PlacementQueue {
public:
    s32 count;
    PlacementSlot slots[8];
    PlacementQueue();
    virtual ~PlacementQueue();
    void increment_count();
    void decrement_count();
    PlacementSlot *get_slot(s32 index);
    s32 is_first_slot_placed();
};
// The queue the telepipe uses: each slot gets the position its search found.
class PositionPlacementQueue : public PlacementQueue {
public:
    PlacementPosition positions[8];
    PositionPlacementQueue();
    virtual ~PositionPlacementQueue();
    PlacementPosition *get_position(s32 index);
};
// The queue a player's item drops wait in until a free spot on the ground is found.
class ItemDropQueue : public PositionPlacementQueue {
public:
    PendingItemDrop records[9];
    ItemDropQueue();
    virtual ~ItemDropQueue();
    PendingItemDrop *get_record(s32 index);
    void add_drop(Vec *position, TObjPlayer *owner, TItemData *item, s32 id);
    void add_drops(Vec *position, TObjPlayer *owner, PendingItemDrop *drops, s32 count);
};
class TPlyItem : public TObject {
public:
    s16 item_count;
    u16 pad_1E;
    ItemDropQueue list;
    TItemList *item_list;
    TObject *item_root;
    TPlyItem(TObject *parent);
    virtual ~TPlyItem();
    int run_and_get_result(s32 *out);
    int run_state_query(TPlyInventoryItem *out);
    s32 update_inventory_item(TObjPlayer *player, s32 item_id, f32 *position, s32 amount, s32 floor);
    void remove_equipped_item(TObjPlayer *player, TItemList *slot);
    void reduce_item_amount(TObjPlayer *player, TItemList *slot, s32 amount);
    s32 use_item(TObjPlayer *player, s32 item_id, s32 amount);
    void set_globals_and_update(TObjPlayer *player, int kind);
    int set_globals_and_notify(TObjPlayer *player, PendingItemDrop *out);
    int count_matching_items(TItem **out);
    int apply_shop_judgment(TItem **out);
    void set_flag_and_update(TObjPlayer *player);
    s32 count_items_by_id(TItemData *data);
    TItemList *find_first_inventory_entry(TItemData *data);
    TItemList *set_mode_and_refresh_object(void *data);
    void destroy_subobjects(TObjPlayer *player);
    TItemList *start_inventory_update(int key);
    // Reduces every item of the type and group (battle rules take the player's traps).
    void reduce_items_of_kind(TObjPlayer *player, int item_type, int item_group);
    s32 remove_items(TObjPlayer *player, s32 *item_ids, s32 count);
    s32 swap_items(s32 item_id, s32 other_id);
    // Reorders the item list by item type, group and index, unequipped items last.
    s32 sort_items();
    static const char *class_name;
};

LAYOUT_ASSERT(PlacementRecordSize, sizeof(PendingItemDrop) == 0x1C);
LAYOUT_ASSERT(PlacementItemOffset, offsetof(PendingItemDrop, item) == 8);
LAYOUT_ASSERT(PlacementSlotsOffset, offsetof(PlacementQueue, slots) == 4);
LAYOUT_ASSERT(PlacementPositionsOffset, offsetof(PositionPlacementQueue, positions) == 0x28);
LAYOUT_ASSERT(PlacementRecordsOffset, offsetof(ItemDropQueue, records) == 0xA8);
LAYOUT_ASSERT(PlayerInventoryListOffset, offsetof(TPlyItem, item_list) == 0x1C4);
LAYOUT_ASSERT(PlayerPlacementPoolOffset, offsetof(TPlyItem, list) == 0x20);

// Inventory helpers on the selected character's save data and item records.
s32 copy_equipped_weapon_and_mag(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *slots);
s32 check_player_action_allowed();
s32 selected_character_has_item(s32 item_id);
void remove_list_entry_by_id(s32 id);
saddr reset(void *p);
void start_placement_search(PositionPlacementQueue *queue, Vec *pos, TObjBase *source);

struct InventorySortEntry {
    u32 key;
    TItem *val;
    InventorySortEntry();
    void set_key(TItem *item);
    // Non-const source: the original reloads other.val after storing key.
    InventorySortEntry &operator=(InventorySortEntry &other);
};

// The 8-byte list TPlyItem::sort_items allocates with new and frees with
// delete (the destructor's s16 argument is MWCC's delete flag).
struct InventorySortBuffer {
    s32 count;
    InventorySortEntry *items;
    InventorySortBuffer(s32 n);
    ~InventorySortBuffer();
    // Bubble-sorts records by key.
    void sort_by_key();
};

#endif
