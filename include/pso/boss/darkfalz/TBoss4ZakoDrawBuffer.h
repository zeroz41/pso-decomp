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

typedef char Boss4ZakoDrawEntrySize[sizeof(Boss4ZakoDrawEntry) == 0x14 ? 1 : -1];
typedef char Boss4ZakoDrawBufferSize[sizeof(Boss4ZakoDrawBuffer) == 0x784 ? 1 : -1];
typedef char Boss4ZakoDrawPositionOffset[offsetof(Boss4ZakoDrawEntry, position) == 0 ? 1 : -1];
typedef char Boss4ZakoDrawF0cOffset[offsetof(Boss4ZakoDrawEntry, rotation_x) == 0xC ? 1 : -1];
typedef char Boss4ZakoDrawF10Offset[offsetof(Boss4ZakoDrawEntry, rotation_y) == 0x10 ? 1 : -1];
typedef char Boss4ZakoDrawEntriesOffset[offsetof(Boss4ZakoDrawBuffer, entries) == 4 ? 1 : -1];
typedef char Boss4ZakoDrawBuffersSize[sizeof(Boss4ZakoDrawBuffer[2]) == 0xF08 ? 1 : -1];
extern "C" Boss4ZakoDrawBuffer boss4_zako_draw_buffers[2];
#endif
