#ifndef PSO_UNK_TLOBBY_80103F5C_H
#define PSO_UNK_TLOBBY_80103F5C_H

#include "types.h"

// --- C functions defined in TLobby_80103F5C.cpp ---
extern "C" {
void select_confirm_exit_stub(void);
}
// --- end of C functions

void handle_6x63_destroy_floor_item(void *command);

void reset_map(void);

struct TLobbyPlayer { u8 pad[0x10]; void *owner; };

struct ApplySyncItemStateEntry { u8 pad0[0xE]; u16 key; u8 padx[0xC]; s32 item_id; u8 pad2[4]; };

struct EvictLowestKeyFloorItemMsg { u32 hdr; s32 v; s32 who; };

struct ApplySyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    ApplySyncItemStateEntry items[1];
};

struct InsertItemConditionEntry { s8 n; u8 pad1[0xD]; u16 key; u8 padx[0xC]; s32 val; u8 pad2[4]; };

struct WriteSyncItemStateSave {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    ApplySyncItemStateEntry items[1];
};

#endif
