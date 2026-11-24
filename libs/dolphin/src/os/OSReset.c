#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>
#include <macros.h>
#include <string.h>

#include "os/__os.h"

#define ENQUEUE_INFO(info, queue)                                              \
	do {                                                                       \
		struct OSResetFunctionInfo* __prev = (queue)->tail;                    \
		if (__prev == 0) {                                                     \
			(queue)->head = (info);                                            \
		} else {                                                               \
			__prev->next = (info);                                             \
		}                                                                      \
		(info)->prev  = __prev;                                                \
		(info)->next  = 0;                                                     \
		(queue)->tail = (info);                                                \
	} while (0);

#define DEQUEUE_INFO(info, queue)                                              \
	do {                                                                       \
		struct OSResetFunctionInfo* __next = (info)->next;                     \
		struct OSResetFunctionInfo* __prev = (info)->prev;                     \
		if (__next == 0) {                                                     \
			(queue)->tail = __prev;                                            \
		} else {                                                               \
			__next->prev = __prev;                                             \
		}                                                                      \
		if (__prev == 0) {                                                     \
			(queue)->head = __next;                                            \
		} else {                                                               \
			__prev->next = __next;                                             \
		}                                                                      \
	} while (0);

#define ENQUEUE_INFO_PRIO(info, queue)                                         \
	do {                                                                       \
		struct OSResetFunctionInfo* __prev;                                    \
		struct OSResetFunctionInfo* __next;                                    \
		for (__next = (queue)->head;                                           \
		     __next && (__next->priority <= (info)->priority);                 \
		     __next = __next->next)                                            \
			;                                                                  \
                                                                               \
		if (__next == 0) {                                                     \
			ENQUEUE_INFO(info, queue);                                         \
		} else {                                                               \
			(info)->next = __next;                                             \
			__prev       = __next->prev;                                       \
			__next->prev = (info);                                             \
			(info)->prev = __prev;                                             \
			if (__prev == 0) {                                                 \
				(queue)->head = (info);                                        \
			} else {                                                           \
				__prev->next = (info);                                         \
			}                                                                  \
		}                                                                      \
	} while (0);

static struct OSResetFunctionQueue ResetFunctionQueue;

static int CallResetFunctions(int final);
static asm void Reset(unsigned long resetCode);

void OSRegisterResetFunction(struct OSResetFunctionInfo* info)
{
	ENQUEUE_INFO_PRIO(info, &ResetFunctionQueue);
}

void OSUnregisterResetFunction(struct OSResetFunctionInfo* info)
{
	DEQUEUE_INFO(info, &ResetFunctionQueue);
}

static int CallResetFunctions(int final)
{
	struct OSResetFunctionInfo* info;
	int err = 0;

	for (info = ResetFunctionQueue.head; info; info = info->next) {
		err |= !info->func(final);
	}
	err |= !__OSSyncSram();
	if (err) {
		return 0;
	}
	return 1;
}

static asm void Reset(unsigned long resetCode) {
#include "orig_asm/os/OSReset/Reset.inc"
}

void __OSDoHotReset(s32 resetCode)
{
	OSDisableInterrupts();
	__VIRegs[1] = 0;
	ICFlashInvalidate();
	Reset(resetCode * 8);
}

inline BOOL __OSCallResetFunctions(BOOL final)
{
	OSResetFunctionInfo* iter;
	s32 retCode = 0;
	s32 temp;

	for (iter = ResetFunctionQueue.head; iter != NULL;) {
		temp = !iter->func(final);
		iter = iter->next;
		retCode |= temp;
	}
	retCode |= !__OSSyncSram();
	if (retCode) {
		return 0;
	}
	return 1;
}

inline static void KillThreads(void)
{
	OSThread* thread;
	OSThread* next;

	for (thread = __OSActiveThreadQueue.head; thread; thread = next) {
		next = thread->linkActive.next;
		switch (thread->state) {
		case 1:
		case 4:
			OSCancelThread(thread);
			continue;
		default:
			continue;
		}
	}
}

extern u8 OS_REBOOT_BOOL AT_ADDRESS(0x800030E2);

void OSResetSystem(int reset, unsigned long resetCode, int forceMenu)
{
	char trash[0x10];
	s32 padThing;

	OSDisableScheduler();
	__OSStopAudioSystem();

	if (reset == OS_RESET_SHUTDOWN)
		padThing = __PADDisableRecalibration(1);

	do {
	} while (CallResetFunctions(0) == 0);

	if ((reset == OS_RESET_HOTRESET && (forceMenu != 0))) {
		__OSLockSram()->flags |= 0x40;
		__OSUnlockSram(1);
		do {
		} while (__OSSyncSram() == 0);
	}

	OSDisableInterrupts();
	__OSCallResetFunctions(TRUE);

	LCDisable();

	if (reset == OS_RESET_HOTRESET) {
		OSDisableInterrupts();
		__VIRegs[1] = 0;
		ICFlashInvalidate();
		Reset(resetCode * 8);
	} else if (reset == OS_RESET_RESTART) {
		KillThreads();
		OSEnableScheduler();
		__OSReboot(resetCode, forceMenu);
	}

	KillThreads();

	memset(OSPhysicalToCached(0x40), 0, 0xCC - 0x40);
	memset(OSPhysicalToCached(0xD4), 0, 0xE8 - 0xD4);
	memset(OSPhysicalToCached(0xF4), 0, 0xF8 - 0xF4);
	memset(OSPhysicalToCached(0x3000), 0, 0xC0);
	memset(OSPhysicalToCached(0x30C8), 0, 0xD4 - 0xC8);
	memset(&OS_REBOOT_BOOL, 0, 1);
	__PADDisableRecalibration(padThing);
}

u32 OSGetResetCode(void)
{
	if (OS_REBOOT_BOOL != 0)
		return 0x80000000;

	return ((__PIRegs[9] & ~7) >> 3);
}
