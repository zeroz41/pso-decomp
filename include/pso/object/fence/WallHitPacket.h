#ifndef PSO_OBJECT_FENCE_WALLHITPACKET_H
#define PSO_OBJECT_FENCE_WALLHITPACKET_H

#include <stddef.h>
#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"

// The 6x86 wall hit subcommand: a 6x0B object-state message plus the hit
// reason and the wall's remaining hits (four 32-bit words).
struct WallHitPacket : G_UpdateObjectState_6x0B {
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
