#ifndef PSO_OBJECT_BASE_OBJECTSETDATA_H
#define PSO_OBJECT_BASE_OBJECTSETDATA_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include <stddef.h>

// What apply_object_set_data reads: an object set entry from 4 bytes in, so
// entity_id, room, position, rotation and params 1-6 sit as in the .dat entry.
struct ObjectSetData {
    s16 object_type;
    s16 floor;
    u16 entity_id;
    s16 wave;
    s16 room;
    u8 pad_a[0x2];
    Vec position;
    s32 rotation[3];
    Vec scale;
    s32 set_params[3];
};

LAYOUT_ASSERT(ObjectSetDataSize, sizeof(ObjectSetData) == 0x3C);
LAYOUT_ASSERT(ObjectSetDataPositionOffset, offsetof(ObjectSetData, position) == 0xC);

extern "C" s32 TLobby__sub_80207F30(ObjectSetData *set);

#endif
