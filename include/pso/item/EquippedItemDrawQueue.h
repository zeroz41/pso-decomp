#ifndef PSO_ITEM_EQUIPPED_ITEM_DRAW_QUEUE_H
#define PSO_ITEM_EQUIPPED_ITEM_DRAW_QUEUE_H

#include "types.h"
#include <stddef.h>
#include "pso/system/NinjaTypes.h"

struct EquippedItemDrawQueue {
    u32 saved_model_render_flags;
    u32 saved_chunk_polygon_flags_and_mask;
    u32 saved_chunk_polygon_flags_or_mask;
    NJS_ARGB saved_model_material_color;
    NJS_ARGB saved_fade_color;
    f32 fade_alpha;
    u32 item_ids[32];
    s32 count;

    void reset();
};

LAYOUT_ASSERT(EquippedDrawIdsOffset, offsetof(EquippedItemDrawQueue, item_ids) == 0x30);
LAYOUT_ASSERT(EquippedDrawCountOffset, offsetof(EquippedItemDrawQueue, count) == 0xB0);
LAYOUT_ASSERT(EquippedDrawQueueSize, sizeof(EquippedItemDrawQueue) == 0xB4);

#endif
