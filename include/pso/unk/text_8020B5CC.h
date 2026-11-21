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

typedef char FloorSetFlagsPayloadSize[sizeof(FloorSetFlagsPayload) == 0x4000 ? 1 : -1];
typedef char FloorSetFlagsHeaderSize[sizeof(FloorSetFlagsHeader) == 0x10 ? 1 : -1];
typedef char FloorSetFlagsEnemyOffset[offsetof(FloorSetFlagsHeader, enemy_offset) == 8 ? 1 : -1];

extern "C" {
void swap_floor_set_flags_header(FloorSetFlagsHeader *header);
void TLobby__sub_8020B47C(FloorSetFlagsHeader *buffer);
void apply_floor_set_flags_packet(FloorSetFlagsHeader *buffer, u16 length);
int TLobby__sub_8020B5CC(FloorSetFlagsPayload *buffer);
void TLobby__sub_8020BB18(void);
}

#endif
