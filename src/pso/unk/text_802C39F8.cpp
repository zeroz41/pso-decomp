#include "pso/item/InventoryEntryCopy.h"
#include "pso/player/TPlyInventory.h"
#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby.h"
extern "C" {

void copy_entries(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *destination) {
    s32 i;
    for (i = 0; i < count; i++) {
        fn_801C1BA8(destination++, source++);
    }
}

// The template copy keeps the two reserved presence bytes already in the destination.
void copy_item_entry_array(s32 n, const TPlyInventoryItem *src, TPlyInventoryItem *dst) {
    s32 i;
    for (i = 0; i < n; i++) {
        // The retail copy stores the presence bytes before the flags word.
        *reinterpret_cast<volatile u8 *>(&dst->m_present[0]) = *reinterpret_cast<const u8 *>(&src->m_present[0]);
        *reinterpret_cast<volatile u8 *>(&dst->m_present[1]) = *reinterpret_cast<const volatile u8 *>(&src->m_present[1]);
        *static_cast<volatile u32 *>(&dst->m_flags) = *static_cast<const volatile u32 *>(&src->m_flags);
        dst->m_data.copy_from(const_cast<TItemData *>(&src->m_data));
        dst++;
        src++;
    }
}

}
