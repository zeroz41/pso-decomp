#ifndef PSO_UNK_TEXT_801036CC_H
#define PSO_UNK_TEXT_801036CC_H

#include "types.h"
#include "pso/item/TItemData.h"

// One item lying on a floor in the floor item tables (0x24 bytes).
struct FloorItemEntry {
    u8 unk_00[0xE];
    u16 floor;
    TItemData data;
};

extern "C" {
// Gives an object id back to the free list TLobby::pop_free_id takes from.
s32 TLobby__sub_80103B04(u16 id);
}

#endif
