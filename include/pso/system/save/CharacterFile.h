#ifndef PSO_SYSTEM_SAVE_CHARACTER_FILE_H
#define PSO_SYSTEM_SAVE_CHARACTER_FILE_H

#include "types.h"
#include <stddef.h>
#include "pso/player/TPlyCharData.h"
#include "pso/system/CharacterSaveRecordLookup.h"

// One slot of the character file: the character's data and its save record.
struct CharacterFileSlot {
    CharacterFileSlot();
    ~CharacterFileSlot();

    TPlyCharData chardata;
    CharacterSaveRecord record;
    u8 pad_278C[0x2798 - 0x278C];
};

// The PSO_CHARACTER memory card file: seven character slots.
struct CharacterFile {
    CharacterFile();
    ~CharacterFile();

    u32 pad_0;
    CharacterFileSlot slots[7];
    u8 pad_1152C[0x11564 - 0x1152C];
    u32 pad_11564;
    u32 pad_11568;
};

LAYOUT_ASSERT(CharacterSaveRecord_size, sizeof(CharacterSaveRecord) == 0x2370);
LAYOUT_ASSERT(CharacterFileSlot_record_offset, offsetof(CharacterFileSlot, record) == 0x41C);
LAYOUT_ASSERT(CharacterFileSlot_size, sizeof(CharacterFileSlot) == 0x2798);
LAYOUT_ASSERT(CharacterFile_size, sizeof(CharacterFile) == 0x1156C);

#endif
