#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H

#include "types.h"

struct CardWriteDate;
struct CardSaveDescriptor;

extern "C" {
void free_banner_buffers(void);
s32 get_memcard_free_files(s32 chan);
s32 poll_memcard_result(saddr chan);
s32 start_memcard_write(s32 chan, const char *name, void *buffer, s32 blocks, CardWriteDate *date, u32 flags);
void TAdPlayerLoadGC__sub_801E14E4(CardSaveDescriptor *file);
void TAdPlayerLoadGC__sub_801E14E8(CardSaveDescriptor *file, s32 index);
int TAdPlayerLoadGC__sub_801E1510(void);
s32 TAdPlayerLoadGC__sub_801E1518(void *arg0, s32 arg1, u32 arg2);
}

extern void *banner_buffers[6];

#endif
