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

LAYOUT_ASSERT(WallHitPacketSize, sizeof(WallHitPacket) == 0x10);
LAYOUT_ASSERT(WallHitPacketReasonOffset, offsetof(WallHitPacket, update_reason) == 0xC);
LAYOUT_ASSERT(WallHitPacketHitsOffset, offsetof(WallHitPacket, remaining_hits) == 0xE);

struct game_command_header;
extern "C" void handle_6x86_hit_destructible_object(game_command_header *command);

#endif
