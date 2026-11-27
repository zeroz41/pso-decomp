#ifndef PSO_PROTOCOL_ITEM_DROP_PACKET_H
#define PSO_PROTOCOL_ITEM_DROP_PACKET_H

#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>

// The packet is declared at its original initialization point, so its native
// constructor creates the header and FloorItem once without earlier side effects.
LAYOUT_ASSERT(ItemDropPacketSize, sizeof(G_DropItem_PC_V3_BB_6x5F) == 0x2C);
LAYOUT_ASSERT(ItemDropBaseSize, sizeof(G_DropItem_DC_6x5F) == 0x28);
LAYOUT_ASSERT(ItemDropFloorOffset, offsetof(G_DropItem_DC_6x5F, item) == 4);
LAYOUT_ASSERT(ItemDropPayloadOffset, offsetof(FloorItem, item) == 0x10);

LAYOUT_ASSERT(ItemDropHeaderOffset, offsetof(G_DropItem_DC_6x5F, header) == 0);
LAYOUT_ASSERT(ItemDropRequestSize, sizeof(G_StandardDropItemRequest_DC_6x60) == 0x14);
LAYOUT_ASSERT(ItemDropRequestSlot, offsetof(G_StandardDropItemRequest_PC_V3_BB_6x60, effective_area) == 0x14);
LAYOUT_ASSERT(ItemDropBaseOffset, offsetof(G_DropItem_PC_V3_BB_6x5F, __base_G_DropItem_DC_6x5F) == 0);

// Byte-swaps a 6x5F drop packet: its header and its floor item.
void bswap_item_packet(G_DropItem_DC_6x5F *packet);

// Byte-swaps a floor item record (a 6x5F drop's or a 6x6D sync record).
void bswap_item(FloorItem *item);

#endif
