#ifndef _DOLPHIN_AR_H
#define _DOLPHIN_AR_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ARQRequest ARQRequest;

typedef void (*ARCallback)(void);

typedef void (*ARQCallback)(uaddr ptrToRequest);

struct ARQRequest {
	ARQRequest* next;
	uaddr owner;
	u32 type;
	u32 priority;
	uaddr source;
	uaddr dest;
	u32 length;
	ARQCallback callback;
};

void ARQInit();
void ARQPostRequest(ARQRequest* task, uaddr owner, u32 type, u32 priority, uaddr source, uaddr dest, u32 length, ARQCallback callback);
void ARQRemoveRequest(ARQRequest* task);

ARQCallback ARRegisterDMACallback(ARQCallback callback);
u32 ARGetDMAStatus();
void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
u32 ARAlloc(u32 length);
u32 ARInit(u32* stack_index_addr, u32 num_entries);
u32 ARGetBaseAddress();
u32 ARGetSize();

u32 ARFree(u32* length);
BOOL ARCheckInit();
void ARReset();
void ARSetSize();
u32 ARGetInternalSize();
void ARClear(u32 flag);

#define AR_STACK_INDEX_ENTRY_SIZE sizeof(u32)

#define ARAM_DIR_MRAM_TO_ARAM 0x00
#define ARAM_DIR_ARAM_TO_MRAM 0x01

#define AR_CLEAR_INTERNAL_ALL  0x00
#define AR_CLEAR_INTERNAL_USER 0x01
#define AR_CLEAR_EXPANSION     0x02

#define __AR_ARAM_OS_BASE_ADDR  0x0000
#define __AR_ARAM_USR_BASE_ADDR 0x4000

#define ARStartDMARead(mmem, aram, len)  ARStartDMA(ARAM_DIR_ARAM_TO_MRAM, mmem, aram, len)
#define ARStartDMAWrite(mmem, aram, len) ARStartDMA(ARAM_DIR_MRAM_TO_ARAM, mmem, aram, len)

#define ARQ_DMA_ALIGNMENT      32
#define ARQ_CHUNK_SIZE_DEFAULT 4096

#define ARQ_TYPE_MRAM_TO_ARAM ARAM_DIR_MRAM_TO_ARAM
#define ARQ_TYPE_ARAM_TO_MRAM ARAM_DIR_ARAM_TO_MRAM

#define ARQ_PRIORITY_LOW  0
#define ARQ_PRIORITY_HIGH 1

#ifdef __cplusplus
};
#endif

#endif
