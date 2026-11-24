#ifndef PSO_OBJECT_TOBJCHIPPARAMS_H
#define PSO_OBJECT_TOBJCHIPPARAMS_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include <stddef.h>

struct NJS_OBJECT;
struct NJS_TEXLIST;

// What TObjChip::construct_debris copies into a new debris chip.
struct TObjChipParams {
    f32 bounce;             // a piece hitting floor_y keeps -bounce of its fall speed
    f32 drag;               // share of x/z speed lost each frame
    f32 gravity;
    Vec pos;
    Vec velocity_range;  // a piece starts at up to this speed per axis
    s32 spin_range[3];      // and spins at up to this angle per frame
    s32 count;              // pieces, at most 8
    s32 life;               // frames a piece moves
    f32 floor_y;
    f32 scale;              // drawn scale of each piece
    NJS_OBJECT *model;
    NJS_TEXLIST *textures;
    s32 flags;              // 2: bounce on floor_y, 4: fade out after life; 8 and 0x10 pick the draw
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
LAYOUT_ASSERT(TObjChipParams_pos_offset, offsetof(TObjChipParams, pos) == 0x0C);
LAYOUT_ASSERT(TObjChipParams_velocity_range_offset, offsetof(TObjChipParams, velocity_range) == 0x18);
LAYOUT_ASSERT(TObjChipParams_model_offset, offsetof(TObjChipParams, model) == 0x40);
LAYOUT_ASSERT(TObjChipParams_textures_offset, offsetof(TObjChipParams, textures) == 0x44);
LAYOUT_ASSERT(TObjChipSpawnParams_size, sizeof(TObjChipSpawnParams) == 0x64);

#endif
