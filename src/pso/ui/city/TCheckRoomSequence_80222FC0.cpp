#include "types.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"

typedef struct Item_80222FF0 { u8 d[0x14]; } Item_80222FF0;

extern "C" {
s32 TLobby__sub_8022318C(Item_80222FF0 *, Item_80222FF0 *);
void sort_shop_items(Item_80222FF0 *items, s32 n, s32 mode);
s32 lookup_item_def__9TItemDataFPv();

s32 TCheckRoomSequence::get_item_def(u32 arg0) {
    if (arg0 != 0U) {
        return lookup_item_def__9TItemDataFPv();
    }
    return 0;
}
void sort_shop_items(Item_80222FF0 *items, s32 n, s32 mode) {
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
