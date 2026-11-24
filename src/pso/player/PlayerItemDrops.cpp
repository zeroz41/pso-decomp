#include "types.h"
#include "pso/item/TItemList.h"
#include "pso/player/TObjPlayer_801D3554.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"

#pragma dont_inline on

void TObjPlayer::insert_item_node(TUnk_804C445C *pool, Vec *position, TObjPlayer *owner, TItemData *item, s32 id) {
    Unk_801C2098 *slot = TItemList__sub_801D5868(pool, 0);
    PendingItemDrop *record = TItemList__sub_801D5854(pool, 0);
    if (TItemList__sub_801D5844(slot) != 0) {
        TItemList__sub_801D5838(slot);
        record->set_source_id(id);
        record->copy_item_data(item);
        TItemList::create_node(pool, owner, position, 0);
        TItemList__sub_801D5804(pool);
    }
}

extern "C" {
void create_drop_nodes__9TItemListFPvPvPvPvi(TUnk_804C445C *pool, Vec *position, TObjPlayer *owner,
                                             PendingItemDrop *records, s32 count) {
    s32 i;
    Unk_801C2098 *slot;
    PendingItemDrop *entry;

    slot = TItemList__sub_801D5868(pool, 0);
    entry = TItemList__sub_801D5854(pool, 0);
    for (i = 0; i < count; i++) {
        if (TItemList__sub_801D5844(slot) != 0) {
            TItemList__sub_801D5838(slot);
            *entry = *records;
            reinterpret_cast<void (*)(void *, void *, void *, s32)>(&TItemList::create_node)(pool, owner, position, i);
            TItemList__sub_801D5804(pool);
            ++slot;
            ++entry;
            ++records;
        }
    }
}
}

Unk_801C2098 &Unk_801C2098::operator=(const Unk_801C2098 &other) {
    state = other.state;
    return *this;
}

void start_placement_search(TUnk_804C4450 *pool, Vec *pos, TObjBase *source) {
    TItemList__sub_801D5838(TItemList__sub_801D5868(pool, 0));
    TItemList__sub_801D3B00(pool, source, pos, 0);
    TItemList__sub_801D5804(pool);
}
