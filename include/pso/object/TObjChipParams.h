#ifndef PSO_OBJECT_TOBJCHIPPARAMS_H
#define PSO_OBJECT_TOBJCHIPPARAMS_H

#include "types.h"

// What TObjChip::construct_debris copies into a new debris chip.
struct TObjChipParams {
    f32 pad_0[3];
    f32 pos[3];
    f32 pad_18[3];
    s32 pad_24[3];
    s32 pad_30[2];
    f32 pad_38[2];
    saddr model;
    s32 textures;
    s32 pad_48;
};

// TObjChipParams followed by the data spawn_chips reads (at +0x4C).
struct TObjChipSpawnParams {
    TObjChipParams chip;
    s32 pad_4C;
    s32 angle_y; // name inferred: TOTrapSeabed01 gives each fragment chip a y angle here
    s32 pad_54;
    u8 pad_58[0xC];
};

LAYOUT_ASSERT(TObjChipParams_size, sizeof(TObjChipParams) == 0x4C);
LAYOUT_ASSERT(TObjChipSpawnParams_size, sizeof(TObjChipSpawnParams) == 0x64);

#endif
