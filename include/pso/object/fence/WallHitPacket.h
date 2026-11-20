#ifndef PSO_OBJECT_FENCE_WALLHITPACKET_H
#define PSO_OBJECT_FENCE_WALLHITPACKET_H

#include <stddef.h>
#include "types.h"

// The 6x86 wall hit subcommand contains four 32-bit words.
struct WallHitPacket {
    u8 subcommand;
    u8 word_count;
    u16 entity_id;
    s32 state;
    s32 set_entry_index;
    u16 update_reason;
    u16 remaining_hits;
    WallHitPacket *init();
    void byteswap();
    void send();
};

typedef char WallHitPacketSize[sizeof(WallHitPacket) == 0x10 ? 1 : -1];
typedef char WallHitPacketReasonOffset[offsetof(WallHitPacket, update_reason) == 0xC ? 1 : -1];
typedef char WallHitPacketHitsOffset[offsetof(WallHitPacket, remaining_hits) == 0xE ? 1 : -1];

#endif
