#ifndef PSO_SDK_COMPACT_MATH
#define PSO_SDK_COMPACT_MATH 1
#endif
#include <dolphin/dolphin.h>
#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include "dvd/__dvd.h"
#include "os/__os.h"

static void* SaveStart = NULL;
static void* SaveEnd   = NULL;
static volatile BOOL Prepared;

int DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback);

extern u32 OS_RESET_CODE AT_ADDRESS(0x800030F0);
extern u8 OS_REBOOT_BOOL AT_ADDRESS(0x800030E2);
extern u32 UNK_817FFFF8 AT_ADDRESS(0x817FFFF8);
extern u32 UNK_817FFFFC AT_ADDRESS(0x817FFFFC);

#define OS_BOOTROM_ADDR ((void*)0x81300000)

typedef struct _ApploaderHeader {
 char date[16];
 u32 entry;
 u32 size;
 u32 rebootSize;
 u32 reserved2;
} ApploaderHeader;

static ApploaderHeader Header __attribute__((aligned(32)));

static asm void Run(register void (*addr)()) {
#include "orig_asm/os/OSReboot/Run.inc"
}

inline void ReadApploader(DVDCommandBlock* dvdCmd, void* addr, u32 offset,
                          u32 numBytes)
{
	while (Prepared == FALSE) { }
	DVDReadAbsAsyncForBS(dvdCmd, addr, numBytes, offset + 0x2440, NULL);

	while (TRUE) {
		switch (dvdCmd->state) {
		case 0:
			break;
		case 1:
		default:
			continue;
		case -1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			__OSDoHotReset(UNK_817FFFFC);
			continue;
		}
		break;
	}
}

static void Callback(s32 result, struct DVDCommandBlock* block)
{
	Prepared = TRUE;
}

void __OSReboot(u32 resetCode, u32 bootDol)
{
	OSContext exceptionContext;
	DVDCommandBlock dvdCmd;
	DVDCommandBlock dvdCmd2;
	u32 numBytes;
	u32 offset;

	OSDisableInterrupts();

	UNK_817FFFFC      = 0;
	UNK_817FFFF8      = 0;
	OS_REBOOT_BOOL    = TRUE;
	BOOT_REGION_START = SaveStart;
	BOOT_REGION_END   = SaveEnd;
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);
	DVDInit();
	DVDSetAutoInvalidation(TRUE);

	__DVDPrepareResetAsync(Callback);

	if (!DVDCheckDisk()) {
		__OSDoHotReset(UNK_817FFFFC);
	}

	__OSMaskInterrupts(0xffffffe0);
	__OSUnmaskInterrupts(0x400);

	OSEnableInterrupts();

	offset   = 0;
	numBytes = 32;
	ReadApploader(&dvdCmd, (void*)&Header, offset, numBytes);

	offset   = Header.size + 0x20;
	numBytes = OSRoundUp32B(Header.rebootSize);
	ReadApploader(&dvdCmd2, OS_BOOTROM_ADDR, offset, numBytes);

	ICInvalidateRange(OS_BOOTROM_ADDR, numBytes);
	Run(OS_BOOTROM_ADDR);
}

void OSGetSaveRegion(void** start, void** end)
{
	*start = SaveStart;
	*end   = SaveEnd;
}
