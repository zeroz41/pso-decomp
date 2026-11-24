#ifndef PSO_SDK_COMPACT_MATH
#define PSO_SDK_COMPACT_MATH 1
#endif
#include <dolphin/os.h>
#include <dolphin/base/PPCArch.h>
#include <dolphin/db.h>
#include <dolphin/exi.h>
#include <dolphin/pad.h>
#include <string.h>
#include <macros.h>
#include "os/__os.h"
#include "dvd/__dvd.h"

#define OS_CURRENTCONTEXT_PADDR 0x00C0

#define OS_EXCEPTIONTABLE_ADDR 0x3000
#define OS_DBJUMPPOINT_ADDR    0x60
#define OS_BI2_DEBUG_ADDRESS    0x800000F4
#define OS_BI2_DEBUGFLAG_OFFSET 0xC
#define PAD3_BUTTON_ADDR        0x800030E4
#define OS_DVD_DEVICECODE       0x800030E6
#define DEBUGFLAG_ADDR          0x800030E8
#define OS_DEBUG_ADDRESS_2      0x800030E9
#define DB_EXCEPTIONRET_OFFSET  0xC
#define DB_EXCEPTIONDEST_OFFSET 0x8

static asm void __OSDBJump(void);

#define NOP 0x60000000

static OSBootInfo* BootInfo;
static volatile u32* BI2DebugFlag;
static u32* BI2DebugFlagHolder;
static BOOL __OSIsGcam;
static BOOL AreWeInitialized;

typedef void (*OSExceptionHandler)(u8, struct OSContext*);
static OSExceptionHandler* OSExceptionTable;

static void* __OSSavedRegionEnd;
static void* __OSSavedRegionStart;
static BOOL __OSInIPL;
OSTime __OSStartTime;

static DVDDriveInfo DriveInfo __attribute__((aligned(0x20)));
static DVDCommandBlock DriveBlock;

static asm void __OSInitFPRs(void);
static void OSExceptionInit(void);
static void OSDefaultExceptionHandler(u8 exception,
                                      OSContext* context);

#pragma peephole off

unsigned long OSGetConsoleType()
{
	if ((!BootInfo) || (BootInfo->consoleType == 0)) {
		return OS_CONSOLE_ARTHUR;
	}
	return BootInfo->consoleType;
}

volatile u16 __OSDeviceCode AT_ADDRESS(0x800030E6);

static void ClearArena()
{
	if (OSGetResetCode() != -0x80000000) {
		__OSSavedRegionStart = NULL;
		__OSSavedRegionEnd   = NULL;
		memset(OSGetArenaLo(), 0, (u8*)OSGetArenaHi() - (u8*)OSGetArenaLo());
		return;
	}

	__OSSavedRegionStart = BOOT_REGION_START;
	__OSSavedRegionEnd   = BOOT_REGION_END;

	if (BOOT_REGION_START == NULL) {
		memset(OSGetArenaLo(), 0, (u8*)OSGetArenaHi() - (u8*)OSGetArenaLo());
		return;
	}

	if ((u8*)OSGetArenaLo() < (u8*)__OSSavedRegionStart) {
		if ((u8*)OSGetArenaHi() <= (u8*)__OSSavedRegionStart) {
			memset(OSGetArenaLo(), 0,
			       (u8*)OSGetArenaHi() - (u8*)OSGetArenaLo());
			return;
		}

		memset(OSGetArenaLo(), 0,
		       (u8*)__OSSavedRegionStart - (u8*)OSGetArenaLo());

		if ((u8*)OSGetArenaHi() > (u8*)__OSSavedRegionEnd) {
			memset(__OSSavedRegionEnd, 0,
			       (u8*)OSGetArenaHi() - (u8*)__OSSavedRegionEnd);
		}
	}
}

static void InquiryCallback(s32 result, struct DVDCommandBlock* block)
{
	switch (block->state) {
	case 0:
		__OSDeviceCode = DriveInfo.deviceCode | 0x8000;
		break;
	default:
		__OSDeviceCode = 1;
		break;
	}
}

void OSInit()
{
	u32 consoleType;
	BI2Debug* bi2DebugInfo;

	if (AreWeInitialized != 0)
		return;

	AreWeInitialized = 1;
	__OSStartTime    = __OSGetSystemTime();
	OSDisableInterrupts();
	PPCDisableSpeculation();
	PPCSetFpNonIEEEMode();
	BootInfo              = (struct OSBootInfo_s*)OSPhysicalToCached(0);
	BI2DebugFlag          = NULL;
	__DVDLongFileNameFlag = 0;
	bi2DebugInfo          = (BI2Debug*)*(BI2Debug**)OS_BI2_DEBUG_ADDRESS;
	if (bi2DebugInfo != NULL) {
		BI2DebugFlag               = &bi2DebugInfo->debugFlag;
		__PADSpec                  = bi2DebugInfo->padSpec;
		*((u8*)DEBUGFLAG_ADDR)     = (u8)*BI2DebugFlag;
		*((u8*)OS_DEBUG_ADDRESS_2) = (u8)__PADSpec;
	} else if (BootInfo->arenaHi) {
		BI2DebugFlagHolder = (u32*)*((u8*)DEBUGFLAG_ADDR);
		BI2DebugFlag       = (u32*)&BI2DebugFlagHolder;
		__PADSpec          = (u32) * ((u8*)OS_DEBUG_ADDRESS_2);
	}

	__DVDLongFileNameFlag = 1;

	OSSetArenaLo((!BootInfo->arenaLo) ? &__ArenaLo : BootInfo->arenaLo);
	if ((!BootInfo->arenaLo) && (BI2DebugFlag) && (*BI2DebugFlag < 2)) {
		OSSetArenaLo((void*)OSRoundUp32B(&_stack_addr));
	}
	OSSetArenaHi((!BootInfo->arenaHi) ? &__ArenaHi : BootInfo->arenaHi);
	OSExceptionInit();
	__OSInitSystemCall();
	OSInitAlarm();
	__OSModuleInit();
	__OSInterruptInit();
	__OSSetInterruptHandler(0x16, &__OSResetSWInterruptHandler);
	__OSContextInit();
	__OSCacheInit();
	EXIInit();
	SIInit();
	__OSInitSram();
	__OSThreadInit();
	__OSInitAudioSystem();
	PPCMthid2(PPCMfhid2() & 0xbfffffff);
	if ((BootInfo->consoleType & OS_CONSOLE_DEVELOPMENT) != 0) {
		BootInfo->consoleType = OS_CONSOLE_DEVHW1;
	} else {
		BootInfo->consoleType = OS_CONSOLE_RETAIL1;
	}
	BootInfo->consoleType += (__PIRegs[11] & 0xF0000000) >> 28;
	if (__OSInIPL == 0) {
		__OSInitMemoryProtection();
	}

	OSReport("\nDolphin OS $Revision: 54 $.\n");
	OSReport("Kernel built : %s %s\n", "Jun  5 2002", "02:09:12");

	OSReport("Console Type : ");

	consoleType = OSGetConsoleType();
	if ((consoleType & 0x10000000) == OS_CONSOLE_RETAIL) {
		OSReport("Retail %d\n", consoleType);
	} else {
		switch (consoleType) {
		case OS_CONSOLE_EMULATOR:
			OSReport("Mac Emulator\n");
			break;
		case OS_CONSOLE_PC_EMULATOR:
			OSReport("PC Emulator\n");
			break;
		case OS_CONSOLE_ARTHUR:
			OSReport("EPPC Arthur\n");
			break;
		case OS_CONSOLE_MINNOW:
			OSReport("EPPC Minnow\n");
			break;
		default:
			OSReport("Development HW%d\n", (consoleType - 0x10000000) - 3);
			break;
		}
	}

	OSReport("Memory %d MB\n", (u32)BootInfo->memorySize >> 0x14U);
	OSReport("Arena : 0x%x - 0x%x\n", OSGetArenaLo(), OSGetArenaHi());

	if (BI2DebugFlag && ((*BI2DebugFlag) >= 2)) {
		EnableMetroTRKInterrupts();
	}
	ClearArena();
	OSEnableInterrupts();
	if (__OSInIPL == 0) {
		DVDInit();

		if (__OSIsGcam) {
			__OSDeviceCode = 0x9000;
			return;
		}

		DCInvalidateRange(&DriveInfo, 0x20);
		DVDInquiryAsync(&DriveBlock, &DriveInfo, InquiryCallback);
	}
}

static u32 __OSExceptionLocations[] = {
	0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500,
	0x00000600, 0x00000700, 0x00000800, 0x00000900, 0x00000C00,
	0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

static void OSExceptionInit(void)
{
	__OSException exception;
	void* destAddr;

	u32* opCodeAddr;
	u32 oldOpCode;

	u8* handlerStart;
	u32 handlerSize;

	opCodeAddr   = (u32*)__OSEVSetNumber;
	oldOpCode    = *opCodeAddr;
	handlerStart = (u8*)__OSEVStart;
	handlerSize  = (u32)((u8*)__OSEVEnd - (u8*)__OSEVStart);

	destAddr = (void*)OSPhysicalToCached(OS_DBJUMPPOINT_ADDR);
	if (*(u32*)destAddr == 0)
	{
		DBPrintf("Installing OSDBIntegrator\n");
		memcpy(destAddr, (void*)__OSDBINTSTART,
		       (u32)__OSDBJump - (u32)__OSDBINTSTART);
		DCFlushRangeNoSync(destAddr,
		                   (u32)__OSDBJump - (u32)__OSDBINTSTART);
		__sync();
		ICInvalidateRange(destAddr, (u32)__OSDBJump - (u32)__OSDBINTSTART);
	}

	for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
		if (BI2DebugFlag && (*BI2DebugFlag >= 2)
		    && __DBIsExceptionMarked(exception)) {
			DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n",
			         exception);
			continue;
		}

		*opCodeAddr = oldOpCode | exception;

		if (__DBIsExceptionMarked(exception)) {
			DBPrintf(">>> OSINIT: exception %d vectored to debugger\n",
			         exception);
			memcpy((void*)__DBVECTOR, (void*)__OSDBJump,
			       (u32)__OSDBJUMPEND - (u32)__OSDBJump);
		} else {
			u32* ops = (u32*)__DBVECTOR;
			int cb;

			for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBJump;
			     cb += sizeof(u32)) {
				*ops++ = NOP;
			}
		}

		destAddr
		    = (void*)OSPhysicalToCached(__OSExceptionLocations[(u32)exception]);
		memcpy(destAddr, handlerStart, handlerSize);
		DCFlushRangeNoSync(destAddr, handlerSize);
		__sync();
		ICInvalidateRange(destAddr, handlerSize);
	}
	OSExceptionTable = (void*)OSPhysicalToCached(OS_EXCEPTIONTABLE_ADDR);

	for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
		__OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
	}

	*opCodeAddr = oldOpCode;

	DBPrintf("Exceptions initialized...\n");
}

static asm void __OSDBIntegrator(void) {
#include "orig_asm/os/OS/__OSDBIntegrator.inc"
}

static asm void __OSDBJump(void) {
#include "orig_asm/os/OS/__OSDBJump.inc"
}

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception,
                                             __OSExceptionHandler handler)
{
	__OSExceptionHandler oldHandler;

	oldHandler                  = OSExceptionTable[exception];
	OSExceptionTable[exception] = handler;
	return oldHandler;
}

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception)
{
	return OSExceptionTable[exception];
}

static asm void OSExceptionVector(void) {
#include "orig_asm/os/OS/OSExceptionVector.inc"
}

asm void OSDefaultExceptionHandler(register __OSException exception,
                                   register OSContext* context) {
#include "orig_asm/os/OS/OSDefaultExceptionHandler.inc"
}

asm void __OSPSInit(void) {
#include "orig_asm/os/OS/__OSPSInit.inc"
}

#define DI_CONFIG_IDX         0x9
#define DI_CONFIG_CONFIG_MASK 0xFF

u32 __OSGetDIConfig(void)
{
	return (__DIRegs[DI_CONFIG_IDX] & DI_CONFIG_CONFIG_MASK);
}
