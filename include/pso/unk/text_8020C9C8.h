#ifndef PSO_UNK_TEXT_8020C9C8_H
#define PSO_UNK_TEXT_8020C9C8_H

#include "types.h"

extern "C" {
s32 unhide_room_set_objects(s32 floor, s16 room, s16 group);
}

struct UnhideRoomSetObjectsSet {
    s16 f0;
    s16 flags;
    s16 f4;
    u8 pad6[4];
    s16 z;
    s16 x;
    u8 padE[0x32];
    void *obj;
};

struct ObjBase_8020C9C8 { u8 pad[0x18]; };

#endif
