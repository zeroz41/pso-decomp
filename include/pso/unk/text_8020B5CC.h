#ifndef PSO_UNK_TEXT_8020B5CC_H
#define PSO_UNK_TEXT_8020B5CC_H

#include "types.h"

// Set flags of every floor's object and enemy sets, packed for the network (serialize_area_set_flags).
// inferred: the buffer serialize_area_set_flags fills
struct SerializedAreaSetFlagsHeader {
    u32 header_size;
    s32 object_count;
    u32 enemy_offset;
    s32 enemy_count;
};

struct SerializedAreaSetFlags : SerializedAreaSetFlagsHeader {
    s16 flags[1];
};

extern "C" {
int TLobby__sub_8020B5CC(SerializedAreaSetFlags *buf);
void TLobby__sub_8020BB18(void);
}

#endif
