#ifndef PSO_OBJECT_TOBJTOMBSTONERECORD_H
#define PSO_OBJECT_TOBJTOMBSTONERECORD_H

#include "types.h"
#include <stddef.h>
#include <dolphin/mtx.h>

// What TObjTombstone::create_tombstone spawns a tombstone from (inferred layout:
// three bytes copied to the record, then its position).
struct TObjTombstoneSpot {
    s8 phase;
    s8 layout;
    s8 floor;
    u8 pad_3;
    Vec position;
    void bswap();
};

// What a tombstone is set up from (setup copies it whole; the copy is the
// compiler's assignment operator).
struct TObjTombstoneRecord {
    s8 phase;
    s8 layout;
    u8 floor;  // compared with get_current_floor
    u8 pad_3;
    s16 deaths;    // times the character died, capped at 9999 (inferred)
    s16 pad_6;
    u32 date;      // year-2000 << 28 | month << 24 | day << 16 | hour << 8 | minute
    s32 rt_index;  // passed to enemy_name_for_rt_index
    Vec position;
    char display_name[0x14];
    char unit_name[0x20];
    void bswap();
};

LAYOUT_ASSERT(TombstoneSpotSize, sizeof(TObjTombstoneSpot) == 0x10);
LAYOUT_ASSERT(TombstoneSpotPositionOffset, offsetof(TObjTombstoneSpot, position) == 4);
LAYOUT_ASSERT(TombstoneRecordSize, sizeof(TObjTombstoneRecord) == 0x50);
LAYOUT_ASSERT(TombstoneRecordPositionOffset, offsetof(TObjTombstoneRecord, position) == 0x10);

#endif
