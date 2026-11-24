#ifndef PSO_SDK_COMPACT_MATH
#define PSO_SDK_COMPACT_MATH 1
#endif
#include <dolphin/odemuexi/DebuggerDriver.h>
#include <dolphin/os.h>
#include <macros.h>

static __OSInterruptHandler MTRCallback;
static void (*DBGCallback)(u32, OSContext*);
static u32 SendMailData;
static s32 RecvDataLeng;
static u8* pEXIInputFlag;
static u8 EXIInputFlag;

static u8 SendCount = 0x80;

static void DBGHandler(__OSInterrupt interrupt, OSContext* context);
static void MWCallback(u32 interrupt, OSContext* context);
static void DBGEXIInit(void);
static BOOL DBGEXISelect(u32);
static BOOL DBGEXIDeselect(void);
static BOOL DBGReadStatus(void*);
static BOOL DBGWrite(u32, u32*, s32);
static BOOL DBGRead(u32, u32*, s32);
static BOOL DBGWriteMailbox(u32);
static BOOL DBGReadMailbox(void*);
static BOOL DBGEXIImm(void*, s32, u32);

static void DBGEXIInit(void)
{
	__OSMaskInterrupts(0x18000);
	__EXIRegs[10] = 0;
}

static BOOL DBGEXISelect(u32 v)
{
	u32 regs = __EXIRegs[10];
	regs &= 0x405;
	regs |= 0x80 | (v << 4);
	__EXIRegs[10] = regs;
	return TRUE;
}

static BOOL DBGEXIDeselect(void)
{
	__EXIRegs[10] &= 0x405;
	return TRUE;
}

static BOOL DBGEXISync(void)
{
	while (__EXIRegs[13] & 1)
		;
	return TRUE;
}

static BOOL DBGEXIImm(void* data, s32 byte_size, u32 write)
{
	u32 writeVal;
	u32 readVal;
	int i;

	if (write) {
		writeVal = 0;
		for (i = 0; i < byte_size; ++i) {
			u8* nextWordPtr = (u8*)data + i;
			writeVal |= *nextWordPtr << ((3 - i) << 3);
		}
		__EXIRegs[14] = writeVal;
	}

	__EXIRegs[13] = 1 | (write << 2) | ((byte_size - 1U) << 4);

	DBGEXISync();
	if (!write) {
		u8* dataPtr = (u8*)data;
		readVal     = __EXIRegs[14];
		for (i = 0; i < byte_size; ++i) {
			*dataPtr++ = readVal >> ((3 - i) << 3);
		}
	}

	return TRUE;
}

static BOOL DBGReadMailbox(void* mailbox)
{
	BOOL error = FALSE;
	u32 command;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	command = 0x60000000;
	error |= !DBGEXIImm((u8*)&command, 2, 1);
	error |= !DBGEXISync();
	error |= !DBGEXIImm(mailbox, sizeof(mailbox), 0);
	error |= !DBGEXISync();
	error |= !DBGEXIDeselect();

	return !error;
}

static BOOL DBGWriteMailbox(u32 mailbox)
{
	BOOL error = FALSE;
	u32 value;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	value = (mailbox & 0x1fffffff) | 0xc0000000;
	error |= !DBGEXIImm((u8*)&value, sizeof(value), 1);
	error |= !DBGEXISync();
	error |= !DBGEXIDeselect();

	return !error;
}

static BOOL DBGRead(u32 addr, u32* data, s32 byte_size)
{
	BOOL error   = FALSE;
	u32* dataPtr = data;
	u32 writeValue;
	u32 readValue;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	writeValue = (u32)(addr << 8) & 0x1fffc00 | 0x20000000;
	error |= !DBGEXIImm((u8*)&writeValue, sizeof(writeValue), 1);
	error |= !DBGEXISync();

	while (byte_size != 0) {
		error |= !DBGEXIImm((u8*)&readValue, sizeof(readValue), 0);
		error |= !DBGEXISync();

		*dataPtr++ = readValue;

		byte_size -= 4;
		if (byte_size < 0) {
			byte_size = 0;
		}
	}
	error |= !DBGEXIDeselect();

	return !error;
}

static BOOL DBGWrite(u32 addr, u32* data, s32 byte_size)
{
	BOOL error   = FALSE;
	u32* dataPtr = data;
	u32 value;
	u32 nextWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	value = (addr & 0x1fffc) << 8 | 0xa0000000;
	error = !DBGEXIImm((u8*)&value, sizeof(value), 1);
	error |= !DBGEXISync();

	while (byte_size != 0) {
		nextWord = *dataPtr++;

		error |= !DBGEXIImm((u8*)&nextWord, sizeof(nextWord), 1);
		error |= !DBGEXISync();

		byte_size -= 4;
		if (byte_size < 0)
			byte_size = 0;
	}

	error |= !DBGEXIDeselect();

	return !error;
}

static BOOL DBGReadStatus(void* status)
{
	BOOL error = FALSE;
	u32 value;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	value = 0x40000000;
	error |= !DBGEXIImm((u8*)&value, 2, 1);
	error |= !DBGEXISync();
	error |= !DBGEXIImm(status, sizeof(status), 0);
	error |= !DBGEXISync();
	error |= !DBGEXIDeselect();

	return !error;
}

static void MWCallback(u32 interrupt, OSContext* context)
{
	EXIInputFlag = 1;
	if (MTRCallback) {
		(*MTRCallback)(0, context);
	}
}

static void DBGHandler(__OSInterrupt interrupt, OSContext* context)
{
	__PIRegs[0] = 0x1000;
	if (DBGCallback) {
		(*DBGCallback)(interrupt, context);
	}
}

static void CheckMailBox(void)
{
	u32 status[2];

	DBGReadStatus(status);
	if (status[0] & 1) {
		DBGReadMailbox(status);
		status[0] &= ~0xE0000000;
		if ((status[0] & 0x1f000000) == 0x1f000000) {
			SendMailData = status[0];
			RecvDataLeng = status[0] & 0x7fff;
			EXIInputFlag = 1;
		}
	}
}

void DBInitComm(volatile u8** inputFlagPtr, __OSInterruptHandler monitorCallback)
{
	BOOL enabled;

	enabled       = OSDisableInterrupts();
	pEXIInputFlag = &EXIInputFlag;
	*inputFlagPtr      = pEXIInputFlag;
	MTRCallback   = monitorCallback;
	DBGEXIInit();
	OSRestoreInterrupts(enabled);
}

void DBInitInterrupts(void)
{
	__OSMaskInterrupts(0x18000);
	__OSMaskInterrupts(0x40);
	DBGCallback = MWCallback;
	__OSSetInterruptHandler(0x19, DBGHandler);
	__OSUnmaskInterrupts(0x40);
}

u32 DBQueryData(void)
{
	BOOL enable;

	EXIInputFlag = 0;
	if (RecvDataLeng == 0) {
		enable = OSDisableInterrupts();
		CheckMailBox();
		OSRestoreInterrupts(enable);
	}
	return RecvDataLeng;
}

int DBRead(void* data, u32 size)
{
	BOOL enabled;
	u32 offset;

	enabled = OSDisableInterrupts();
	if (SendMailData & 0x10000) {
		offset = 0x1000;
	} else {
		offset = 0;
	}
	DBGRead(offset + 0x1e000, data, size + 3U & 0xfffffffc);
	RecvDataLeng = 0;
	EXIInputFlag = 0;
	OSRestoreInterrupts(enabled);
	return 0;
}

int DBWrite(const void* data, u32 size)
{
	u32 value;
	u32 busyFlag;
	BOOL enabled;

	enabled = OSDisableInterrupts();
	do {
		DBGReadStatus(&busyFlag);
	} while (busyFlag & 2);

	++SendCount;

	value = ((SendCount & 1) ? 0x1000 : 0);
	while (!DBGWrite(value | 0x1c000, data, ALIGN_NEXT(size, 4)))
		;

	do {
		DBGReadStatus(&busyFlag);
	} while (busyFlag & 2);

	value = (SendCount << 0x10) | 0x1f000000 | size;
	while (!DBGWriteMailbox(value))
		;

	do {
		while (!DBGReadStatus(&busyFlag))
			;
	} while (busyFlag & 2);

	OSRestoreInterrupts(enabled);

	return 0;
}

void DBOpen(void) { }

void DBClose(void) { }
