#include "types.h"
#include "pso/item/TItemList.h"
#include "pso/player/TObjPlayer_801D3554.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

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
            copy_drop_node(reinterpret_cast<u8 *>(entry), reinterpret_cast<u8 *>(records));
            reinterpret_cast<void (*)(void *, void *, void *, s32)>(&TItemList::create_node)(pool, owner, position, i);
            TItemList__sub_801D5804(pool);
            ++slot;
            ++entry;
            ++records;
        }
    }
}
}

u8 *copy_drop_node(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;
    u8 *temp_r5;
    fn_801D371C(arg0, arg1);
    temp_r5 = (arg0 + 4);
    temp_r4 = (arg1 + 4);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_14 *)((saddr) temp_r5 + 4) = *(const ByteBlock_14 *)((saddr) temp_r4 + 4);
    return arg0;
}

void fn_801D371C(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }
void start_placement_search(TUnk_804C4450 *pool, Vec *pos, TObjBase *source) {
    TItemList__sub_801D5838(TItemList__sub_801D5868(pool, 0));
    TItemList__sub_801D3B00(pool, source, pos, 0);
    TItemList__sub_801D5804(pool);
}
