#ifndef PSO_ITEM_EQUIPPED_ITEM_DRAW_QUEUE_H
#define PSO_ITEM_EQUIPPED_ITEM_DRAW_QUEUE_H
#include "types.h"
#include <stddef.h>

struct EquippedItemDrawQueue {
    u8 prefix[0x30];
    u32 item_ids[32];
    s32 count;
};
LAYOUT_ASSERT(EquippedDrawIdsOffset, offsetof(EquippedItemDrawQueue, item_ids) == 0x30);
LAYOUT_ASSERT(EquippedDrawCountOffset, offsetof(EquippedItemDrawQueue, count) == 0xB0);
LAYOUT_ASSERT(EquippedDrawQueueSize, sizeof(EquippedItemDrawQueue) == 0xB4);
#endif
