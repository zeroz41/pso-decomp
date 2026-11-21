#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAWBUFFER_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAWBUFFER_H
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct Boss4ZakoDrawEntry {
    Vec position;
    s32 rotation_x;
    s32 rotation_y;
};

struct Boss4ZakoDrawBuffer {
    s32 count;
    Boss4ZakoDrawEntry entries[96];
};

LAYOUT_ASSERT(Boss4ZakoDrawEntrySize, sizeof(Boss4ZakoDrawEntry) == 0x14);
LAYOUT_ASSERT(Boss4ZakoDrawBufferSize, sizeof(Boss4ZakoDrawBuffer) == 0x784);
LAYOUT_ASSERT(Boss4ZakoDrawPositionOffset, offsetof(Boss4ZakoDrawEntry, position) == 0);
LAYOUT_ASSERT(Boss4ZakoDrawF0cOffset, offsetof(Boss4ZakoDrawEntry, rotation_x) == 0xC);
LAYOUT_ASSERT(Boss4ZakoDrawF10Offset, offsetof(Boss4ZakoDrawEntry, rotation_y) == 0x10);
LAYOUT_ASSERT(Boss4ZakoDrawEntriesOffset, offsetof(Boss4ZakoDrawBuffer, entries) == 4);
LAYOUT_ASSERT(Boss4ZakoDrawBuffersSize, sizeof(Boss4ZakoDrawBuffer[2]) == 0xF08);
extern "C" Boss4ZakoDrawBuffer boss4_zako_draw_buffers[2];
#endif
