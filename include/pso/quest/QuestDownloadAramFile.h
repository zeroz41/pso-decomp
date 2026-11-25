#ifndef PSO_QUEST_QUESTDOWNLOADARAMFILE_H
#define PSO_QUEST_QUESTDOWNLOADARAMFILE_H

#include "types.h"

s32 aram_close(s32 handle);
void aram_dma_setup(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms);
s32 start_askdic(void);

#endif
