#ifndef PSO_SYSTEM_EVENT_SHUFFLE_TABLE_H
#define PSO_SYSTEM_EVENT_SHUFFLE_TABLE_H

#include "types.h"

struct EventShuffleTable {
    s32 rngState;
    s32* entries;
    s32 cursor;
    s32 count;
};

#include <stddef.h>
LAYOUT_ASSERT(EventShuffleTableSize, sizeof(EventShuffleTable) == 0x10);
LAYOUT_ASSERT(EventShuffleEntriesOffset, offsetof(EventShuffleTable, entries) == 4);
LAYOUT_ASSERT(EventShuffleCursorOffset, offsetof(EventShuffleTable, cursor) == 8);
LAYOUT_ASSERT(EventShuffleCountOffset, offsetof(EventShuffleTable, count) == 12);

#endif
