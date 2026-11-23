#ifndef PSO_PROTOCOL_ITEM_DROP_PACKET_H
#define PSO_PROTOCOL_ITEM_DROP_PACKET_H

#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>

// The packet is declared at its original initialization point, so its native
// constructor creates the header and FloorItem once without earlier side effects.
typedef char ItemDropPacketSize[sizeof(G_DropItem_PC_V3_BB_6x5F) == 0x2C ? 1 : -1];
typedef char ItemDropBaseSize[sizeof(G_DropItem_DC_6x5F) == 0x28 ? 1 : -1];
typedef char ItemDropFloorOffset[offsetof(G_DropItem_DC_6x5F, item) == 4 ? 1 : -1];
typedef char ItemDropPayloadOffset[offsetof(G_DropItem_DC_6x5F, item) + offsetof(FloorItem, item) == 0x14 ? 1 : -1];

typedef char ItemDropHeaderOffset[offsetof(G_DropItem_DC_6x5F, header) == 0 ? 1 : -1];
typedef char ItemDropRequestSize[sizeof(G_StandardDropItemRequest_DC_6x60) == 0x14 ? 1 : -1];
typedef char ItemDropRequestSlot[offsetof(G_StandardDropItemRequest_PC_V3_BB_6x60, effective_area) == 0x14 ? 1 : -1];
typedef char ItemDropBaseOffset[offsetof(G_DropItem_PC_V3_BB_6x5F, __base_G_DropItem_DC_6x5F) == 0 ? 1 : -1];

// Swap a complete aligned packet of at least 0x28 bytes. Its first subobject
// must be a live G_ClientIDHeader; its remaining record is encoded bytes.
extern "C" void bswap_item_packet__6TLobbyFv(void *packet);

// Byte-order conversion for an aligned 0x24-byte floor-item representation.
// Also used on sync-buffer records: this does not claim a FloorItem lifetime.
extern "C" void bswap_item__6TLobbyFv(void *record);

#endif
