#ifndef PSO_PLAYER_TPLYCHARDATATYPES_H
#define PSO_PLAYER_TPLYCHARDATATYPES_H

#include "types.h"

// disp_data_part2 as the visual-record copy sees it: the name, the reserved
// words, the appearance and the proportions move as 8-byte blocks.
struct VisualRecordBlock { u8 bytes[8]; };

struct PlayerVisualRecord {
    VisualRecordBlock name[2];
    VisualRecordBlock reserved;
    s32 name_colour;
    u8 extra_model;
    char padding[15];
    s32 name_colour_checksum;
    u8 section_id;
    u8 char_class;
    u8 v2_flags;
    u8 version;
    s32 v1_flags;
    VisualRecordBlock appearance[2];
    VisualRecordBlock proportions;
};

#endif
