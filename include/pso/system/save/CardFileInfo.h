#ifndef PSO_SYSTEM_SAVE_CARD_FILE_INFO_H
#define PSO_SYSTEM_SAVE_CARD_FILE_INFO_H

#include "pso/system/date.h"
#include "types.h"
#include <stddef.h>

struct CardFileInfo {
    u32 length;
    u16 blocks;
    // These consecutive bytes are cleared by the reader.
    u8 reserved_bytes[2];
    u16 reserved_word;
    CardWriteDate date;
};

LAYOUT_ASSERT(CardFileInfoBlocksOffset, offsetof(CardFileInfo, blocks) == 4);
LAYOUT_ASSERT(CardFileInfoDateOffset, offsetof(CardFileInfo, date) == 0xA);
LAYOUT_ASSERT(CardFileInfoSize, sizeof(CardFileInfo) == 0x14);

extern "C" {
s32 poll_memcard_result(s32 channel);
}

#endif
