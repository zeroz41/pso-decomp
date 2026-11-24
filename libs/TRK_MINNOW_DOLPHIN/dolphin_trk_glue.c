#define PSO_SDK_COMPACT_MATH
#include "PowerPC_EABI_Support/MetroTRK/trk.h"
#include "OdemuExi2/odemuexi/DebuggerDriver.h"
#include "amcstubs/AmcExi2Stubs.h"

#define BUFF_LEN 4362

u8 gWriteBuf[BUFF_LEN];
u8 gReadBuf[BUFF_LEN];
s32 _MetroTRK_Has_Framing;
s32 gReadCount;
s32 gReadPos;
s32 gWritePos;

DBCommTable gDBCommTable = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

asm void TRKLoadContext(OSContext* ctx, u32 a) {
#include "orig_asm/TRK_MINNOW_DOLPHIN/dolphin_trk_glue/TRKLoadContext.inc"
}
void TRKEXICallBack(__OSInterrupt interrupt, OSContext* ctx)
{
	OSEnableScheduler();
	TRKLoadContext(ctx, 0x500);
}

int InitMetroTRKCommTable(int hwId)
{
	int result;

	if (hwId == HARDWARE_GDEV) {
        OSReport("MetroTRK : Set to GDEV hardware\n");
		result = Hu_IsStub();

		gDBCommTable.initialize_func      = (DBCommInitFunc)DBInitComm;
		gDBCommTable.init_interrupts_func = (DBCommFunc)DBInitInterrupts;
		gDBCommTable.peek_func            = (DBCommFunc)DBQueryData;
		gDBCommTable.read_func            = (DBCommReadFunc)DBRead;
		gDBCommTable.write_func           = (DBCommWriteFunc)DBWrite;
		gDBCommTable.open_func            = (DBCommFunc)DBOpen;
		gDBCommTable.close_func           = (DBCommFunc)DBClose;
	} else {
        OSReport("MetroTRK : Set to AMC DDH hardware\n");
		result = AMC_IsStub();

		gDBCommTable.initialize_func      = (DBCommInitFunc)EXI2_Init;
		gDBCommTable.init_interrupts_func = (DBCommFunc)EXI2_EnableInterrupts;
		gDBCommTable.peek_func            = (DBCommFunc)EXI2_Poll;
		gDBCommTable.read_func            = (DBCommReadFunc)EXI2_ReadN;
		gDBCommTable.write_func           = (DBCommWriteFunc)EXI2_WriteN;
		gDBCommTable.open_func            = (DBCommFunc)EXI2_Reserve;
		gDBCommTable.close_func           = (DBCommFunc)EXI2_Unreserve;
	}

	return result;
}

DSError TRKInitializeIntDrivenUART(u32 unused1, u32 unused2, u32 unused3, volatile u8** inputPendingPtrRef)
{
	gDBCommTable.initialize_func(inputPendingPtrRef, TRKEXICallBack);
	return DS_NoError;
}

void EnableEXI2Interrupts(void)
{
	gDBCommTable.init_interrupts_func();
}

int TRKPollUART(void)
{
	return gDBCommTable.peek_func();
}

UARTError TRKReadUARTN(void* bytes, u32 length)
{
	int readErr = gDBCommTable.read_func(bytes, length);
	return readErr == 0 ? 0 : -1;
}

UARTError TRKWriteUARTN(const void* bytes, u32 length)
{
	int writeErr = gDBCommTable.write_func(bytes, length);
	return writeErr == 0 ? 0 : -1;
}

UARTError WriteUARTFlush(void)
{
	UARTError readErr = 0;

	while (gWritePos < 0x800) {
		gWriteBuf[gWritePos] = 0;
		gWritePos++;
	}
	if (gWritePos != 0) {
		readErr   = TRKWriteUARTN(gWriteBuf, gWritePos);
		gWritePos = 0;
	}
	return readErr;
}
UARTError WriteUART1(s8 data)
{
	gWriteBuf[gWritePos++] = data;
	return 0;
}

UARTError TRKReadUARTPoll(u8* c)
{
	UARTError readErr = 4;
	s32 cnt;

	if (gReadPos >= gReadCount) {
		gReadPos = 0;
		cnt = gReadCount = TRKPollUART();
		if (cnt > 0) {
			if (cnt > BUFF_LEN) {
				gReadCount = BUFF_LEN;
			}
			readErr = TRKReadUARTN(gReadBuf, gReadCount);
			if (readErr != 0) {
				gReadCount = 0;
			}
		}
	}
	if (gReadPos < gReadCount) {
		*c   = gReadBuf[gReadPos++];
		readErr = 0;
	}
	return readErr;
}

void ReserveEXI2Port(void)
{
	gDBCommTable.open_func();
}

void UnreserveEXI2Port(void)
{
	gDBCommTable.close_func();
}

void TRK_board_display(char* str)
{
	OSReport(str);
}

void TRKUARTInterruptHandler(void)
{
}
