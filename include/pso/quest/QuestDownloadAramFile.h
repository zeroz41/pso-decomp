#ifndef PSO_QUEST_QUESTDOWNLOADARAMFILE_H
#define PSO_QUEST_QUESTDOWNLOADARAMFILE_H

#include "types.h"
#include <dolphin/ar.h>

s32 aram_close(s32 handle);
void aram_dma_setup(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms);
s32 start_askdic(void);

// The ARAM back end of the keyboard's ASKDIC dictionary ("ASKDIC:ARAM DMA Timeout!!"): TWindowKeyBoardBase sets the
// ARAM image up with aram_dma_setup, then start_askdic starts the dictionary.
struct QuestDownloadAramFile {
    s32 remain;
    s32 pos;
};

struct QuestDownloadAramDmaBuffer {
    u8 reserved[0x40];
    u8 bytes[0x2000];
    ARQRequest request;
};

#endif
