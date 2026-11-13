#ifndef PSO_OBJECT_FENCE_WALLHITPACKET_H
#define PSO_OBJECT_FENCE_WALLHITPACKET_H

#include "types.h"

// Subcommand 6x86 (hit destructible object), sent and received for TOVS2Wall01.
struct WallHitPacket {
    u16 m_0;
    u16 entity_id;
    s32 state;
    s32 m_8;
    u16 m_c;
    u16 m_e;
};

#endif
