#ifndef _METROTRK_TRKTYPES_H
#define _METROTRK_TRKTYPES_H

#include "dolphin/os/OSInterrupt.h"
#include "PowerPC_EABI_Support/MetroTRK/trkenum.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*DBCommFunc)();
typedef void (*DBCommInitFunc)(volatile u8**, __OSInterruptHandler);
typedef int (*DBCommReadFunc)(void*, u32);
typedef int (*DBCommWriteFunc)(const void*, u32);

typedef int TRKBufferID;

typedef u32 NubEventID;

#define TRKMSGBUF_SIZE (0x800 + 0x80)

typedef struct TRKBuffer {
	u32 mutex;
	BOOL isInUse;
	u32 length;
	u32 position;
	u8 data[TRKMSGBUF_SIZE];
} TRKBuffer;

typedef struct DBCommTable {
	DBCommInitFunc initialize_func;
	DBCommFunc init_interrupts_func;
	DBCommFunc peek_func;
	DBCommReadFunc read_func;
	DBCommWriteFunc write_func;
	DBCommFunc open_func;
	DBCommFunc close_func;
} DBCommTable;

typedef struct DSVersions {
	u8 kernelMajor;
	u8 kernelMinor;
	u8 protocolMajor;
	u8 protocolMinor;
} DSVersions;

typedef struct TRKPacketSeq {
	u16 _00;
	u8 _02[6];
} TRKPacketSeq;

typedef struct TRKFramingState {
	TRKBufferID msgBufID;
	TRKBuffer* buffer;
	u8 receiveState;
	BOOL isEscape;
	u8 fcsType;
} TRKFramingState;

typedef struct CommandReply {
	u32 _00;
	union {
		u8 b;
		MessageCommandID m;
	} commandID;
	union {
		u8 b;
		DSReplyError r;
	} replyError;
	u32 _0C;
	u8 _10[0x30];
} CommandReply;

typedef struct TRKEvent {
	u8 eventType;
	NubEventID eventID;
	TRKBufferID msgBufID;
} TRKEvent;

typedef struct TRKEventQueue {
	u8 _00[4];
	int count;
	int next;
	TRKEvent events[2];
	NubEventID eventID;
} TRKEventQueue;

typedef struct TRKState {
	u32 gpr[32];
	u32 lr;
	u32 ctr;
	u32 xer;
	u32 msr;
	u32 dar;
	u32 dsisr;
	BOOL isStopped;
	BOOL inputActivated;
	void* inputPendingPtr;
} TRKState;

typedef struct TRKState_PPC {
	u32 GPR[32];
	u32 LR;
	u32 CTR;
	u32 XER;
	u32 MSR;
	u32 DAR;
	u32 DSISR;
	BOOL stopped;
	BOOL inputActivated;
	u8* inputPendingPtr;
} TRKState_PPC;

typedef struct ProcessorRestoreFlags_PPC {
	u8 TBR;
	u8 DEC;
	u8 linker_padding[0x9 - 0x2];
} ProcessorRestoreFlags_PPC;

#ifdef __cplusplus
};
#endif

#endif
