#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H

#include "types.h"

extern "C" {
void free_banner_buffers(void);
void TAdPlayerLoadGC__sub_801E14E4(void);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
int TAdPlayerLoadGC__sub_801E1510(void);
s32 TAdPlayerLoadGC__sub_801E1518(void *arg0, s32 arg1, u32 arg2);
}

// TAdPlayerLoadGC__banner_buffers: layout known from its uses only.
struct TAdPlayerLoadGCBannerBuffers { s32 value; u8 remaining[0x14]; };
extern TAdPlayerLoadGCBannerBuffers TAdPlayerLoadGC__banner_buffers;

#endif
