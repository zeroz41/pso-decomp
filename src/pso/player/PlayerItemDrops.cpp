#include "types.h"
#include "pso/item/TItemList.h"
#include "pso/item/TPlacementSearch.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"

#pragma dont_inline on

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

PlacementSlot &PlacementSlot::operator=(const PlacementSlot &other) {
    state = other.state;
    return *this;
}

void start_placement_search(PositionPlacementQueue *queue, Vec *pos, TObjBase *source) {
    queue->get_slot(0)->reserve();
    TPositionSearch::create(queue, source, pos, 0);
    queue->increment_count();
}
