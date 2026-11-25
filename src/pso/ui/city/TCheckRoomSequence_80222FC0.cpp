#include "types.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/network/TLobby.h"
#include "pso/item/TItemData.h"

typedef struct ItemRecordView { u8 d[0x14]; } ItemRecordView;

extern "C" {
s32 TLobby__sub_8022318C(ItemRecordView *, ItemRecordView *);

s32 TCheckRoomSequence::get_item_def(uaddr item) {
    if (item != 0U) {
        return TItemData::lookup_item_def((void *)item);
    }
    return 0;
}
void sort_shop_items(ItemRecordView *items, s32 n, s32 mode) {
    s32 i;
    s32 j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            switch (mode) {
            case 0:
                if (TLobby__sub_8022318C(&items[i], &items[j]) != 0) {
                    ((TLobby *)(&items[i]))->swap_item_data((s32 *)&items[j]);
                }
                break;
            case 1:
                if (((TLobby *)(&items[i]))->compare_greater(&items[j]) != 0) {
                    ((TLobby *)(&items[i]))->swap_item_data((s32 *)&items[j]);
                }
                break;
            case 2:
                if (((TLobby *)(&items[i]))->compare_version(&items[j]) != 0) {
                    ((TLobby *)(&items[i]))->swap_item_data((s32 *)&items[j]);
                }
                break;
            }
        }
    }
}

}
