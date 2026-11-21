#ifndef _DOLPHIN_GBA_H_
#define _DOLPHIN_GBA_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GBA_CHAN0 0
#define GBA_CHAN1 1
#define GBA_CHAN2 2
#define GBA_CHAN3 3
#define GBA_MAX_CHAN 4

#define GBA_JSTAT_MASK 0x3A
#define GBA_JSTAT_FLAGS_SHIFT 4
#define GBA_JSTAT_FLAGS_MASK 0x30
#define GBA_JSTAT_PSF1 0x20
#define GBA_JSTAT_PSF0 0x10
#define GBA_JSTAT_SEND 0x08
#define GBA_JSTAT_RECV 0x02

#define GBA_READY 0
#define GBA_NOT_READY 1
#define GBA_BUSY 2
#define GBA_JOYBOOT_UNKNOWN_STATE 3
#define GBA_JOYBOOT_ERR_INVALID 4

#define GBA_JOYBOOT_PROGRAM_SIZE_MAX 0x40000

typedef void (*GBACallback)(s32 chan, s32 ret);
typedef void (*GBATransferCallback)(s32 chan);

void GBAInit(void);
s32 GBAGetStatus(s32 chan, u8* status);
s32 GBAGetStatusAsync(s32 chan, u8* status, GBACallback callback);
s32 GBAReset(s32 chan, u8* status);
s32 GBAResetAsync(s32 chan, u8* status, GBACallback callback);
s32 GBAGetProcessStatus(s32 chan, u8* percentp);
s32 GBARead(s32 chan, u8* dst, u8* status);
s32 GBAReadAsync(s32 chan, u8* dst, u8* status, GBACallback callback);
s32 GBAWrite(s32 chan, u8* src, u8* status);
s32 GBAWriteAsync(s32 chan, u8* src, u8* status, GBACallback callback);
s32 GBAJoyBoot(s32 chan, s32 palette_color, s32 palette_speed, u8* programp, s32 length, u8* status);
s32 GBAJoyBootAsync(s32 chan, s32 palette_color, s32 palette_speed, u8* programp, s32 length, u8* status,
                    GBACallback callback);

#ifdef __cplusplus
}
#endif

#endif
