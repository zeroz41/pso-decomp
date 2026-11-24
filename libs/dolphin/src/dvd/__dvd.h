#ifndef _DOLPHIN_DVD_INTERNAL_H_
#define _DOLPHIN_DVD_INTERNAL_H_

#include <dolphin/dvd.h>

void __DVDAudioBufferConfig(struct DVDCommandBlock * block, unsigned long enable, unsigned long size, void (* callback)(long, struct DVDCommandBlock *));
void __DVDPrepareResetAsync(DVDCBCallback callback);

void __DVDStoreErrorCode(u32 error);

extern struct OSThreadQueue __DVDThreadQueue;
extern unsigned long __DVDLongFileNameFlag;

void __DVDFSInit();

void __DVDInitWA(void);
void __DVDInterruptHandler(short interrupt, struct OSContext * context);
void __DVDLowSetWAType(u32 type, u32 location);

void __DVDClearWaitingQueue();
int __DVDPushWaitingQueue(long prio, struct DVDCommandBlock * block);
struct DVDCommandBlock * __DVDPopWaitingQueue();
int __DVDCheckWaitingQueue();
int __DVDDequeueWaitingQueue(struct DVDCommandBlock * block);
int __DVDIsBlockInWaitingQueue(struct DVDCommandBlock * block);

void __fstLoad();

int DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback);

#endif
