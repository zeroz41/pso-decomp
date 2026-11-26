#ifndef PSO_ITEM_TITEMDATATYPES_H
#define PSO_ITEM_TITEMDATATYPES_H

#include "types.h"

// get_item_icon_index copies the table whole.
struct ItemIconIndexTable { s32 w[19]; };

// A mag's item data as serialize_mag fills it (TItemData's layout).
struct MagItemData {
    u8 kind;
    u8 group;
    u8 level;
    u8 photon_blasts;
    s16 stat[4];
    u32 id;
    u8 synchro;
    u8 iq;
    u8 photon_blast_flags;
    u8 color;
};

#endif
