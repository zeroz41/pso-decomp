#include "types.h"
#include "pso/player/TPlyInventoryItem_800721D4.h"

extern "C" {
void init__9TItemDataFv(void *);
void init__17TPlyInventoryItemFv(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 0) = 0;
    *(s8 *)((s8 *)arg0 + 1) = -1;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 3) = 0;
    *(s8 *)((s8 *)arg0 + 2) = 0;
    init__9TItemDataFv(arg0 + 8);
}

}
