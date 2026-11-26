#ifndef PSO_UNK_TEXT_8020B5CC_H
#define PSO_UNK_TEXT_8020B5CC_H

#include "types.h"
#include <stddef.h>

// Followed by the object flag stream and then the enemy flag stream in game-state packet 6x6E.
struct FloorSetFlagsHeader {
    u32 object_offset;
    s32 object_count;
    u32 enemy_offset;
    s32 enemy_count;
};

// The decompressed sync scratch has 0x4000 payload bytes after its length words.
struct FloorSetFlagsPayload : FloorSetFlagsHeader {
    s16 flags[(0x4000 - sizeof(FloorSetFlagsHeader)) / sizeof(s16)];
};

LAYOUT_ASSERT(FloorSetFlagsPayloadSize, sizeof(FloorSetFlagsPayload) == 0x4000);
LAYOUT_ASSERT(FloorSetFlagsHeaderSize, sizeof(FloorSetFlagsHeader) == 0x10);
LAYOUT_ASSERT(FloorSetFlagsEnemyOffset, offsetof(FloorSetFlagsHeader, enemy_offset) == 8);

void swap_floor_set_flags_header(FloorSetFlagsHeader *header);
void unpack_floor_set_flags(FloorSetFlagsHeader *buffer);
void apply_floor_set_flags_packet(FloorSetFlagsHeader *buffer, u16 length);
int pack_floor_set_flags(FloorSetFlagsPayload *buffer);
void destroy_floor_decoration_objects(void);

#endif
