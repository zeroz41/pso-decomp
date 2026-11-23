#ifndef PSO_PLAYER_TPLYITEM_H
#define PSO_PLAYER_TPLYITEM_H

#include "pso/item/TItemData.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "types.h"

class TItemList;
struct TObjPlayer;
struct TItem;
class TPlyInventoryItem;

// The item list a TPlyItem owns at +0x20. Placeholder names: TUnk_<vtable> for the three
// list levels; Unk_801C2098 (4 bytes, ctor 0x801C2098) and Unk_801D5CB8 (0x10 bytes, ctor 0x801D5CB8)
// for the smaller element types. PendingItemDrop holds the source ID and payload of a pending drop.
struct Unk_801C2098 {
    s32 state;
    Unk_801C2098();
};
struct Unk_801D5CB8 {
    Unk_801C2098 head;
    f32 x, y, z;
    Unk_801D5CB8();
};
struct PendingItemDrop {
    Unk_801C2098 head;
    s32 source_id;
    TItemData item;
    PendingItemDrop();
    void set_source_id(s32 id);
    void copy_item_data(TItemData *source);
};
class TUnk_804C4444 {
public:
    s32 count;
    Unk_801C2098 entries[8];
    TUnk_804C4444();
    virtual ~TUnk_804C4444();
};
class TUnk_804C4450 : public TUnk_804C4444 {
public:
    Unk_801D5CB8 positions[8];
    TUnk_804C4450();
    virtual ~TUnk_804C4450();
};
class TUnk_804C445C : public TUnk_804C4450 {
public:
    PendingItemDrop records[9];
    TUnk_804C445C();
    virtual ~TUnk_804C445C();
};
class TPlyItem : public TObject {
public:
    s16 pad_1C;
    u16 pad_1E;
    TUnk_804C445C list;
    TItemList *pad_1C4;
    TObject *pad_1C8;
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
};

LAYOUT_ASSERT(PlacementRecordSize, sizeof(PendingItemDrop) == 0x1C);
LAYOUT_ASSERT(PlacementItemOffset, offsetof(PendingItemDrop, item) == 8);
LAYOUT_ASSERT(PlacementSlotsOffset, offsetof(TUnk_804C4444, entries) == 4);
LAYOUT_ASSERT(PlacementPositionsOffset, offsetof(TUnk_804C4450, positions) == 0x28);
LAYOUT_ASSERT(PlacementRecordsOffset, offsetof(TUnk_804C445C, records) == 0xA8);
LAYOUT_ASSERT(PlayerInventoryListOffset, offsetof(TPlyItem, pad_1C4) == 0x1C4);
LAYOUT_ASSERT(PlayerPlacementPoolOffset, offsetof(TPlyItem, list) == 0x20);

extern "C" {
s32 query_state_if_present__10TObjPlayerFPv(TObjPlayer *player, TPlyInventoryItem *out);
void TLobby__sub_801D4C28(TPlyItem *inventory, TObjPlayer *player, int item_type, int item_group);
void TItemList__sub_801D5804(TUnk_804C4444 *pool);
PendingItemDrop *TItemList__sub_801D5854(TUnk_804C445C *pool, s32 index);
Unk_801C2098 *TItemList__sub_801D5868(TUnk_804C4444 *pool, s32 index);
Unk_801D5CB8 *TItemList__sub_801D598C(TUnk_804C4450 *pool, s32 index);
}

#endif
