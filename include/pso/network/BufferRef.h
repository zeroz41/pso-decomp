#ifndef PSO_NETWORK_BUFFERREF_H
#define PSO_NETWORK_BUFFERREF_H

#include "types.h"
#include <stddef.h>

typedef struct NetBufferRef {
    u32 value;
    u8 kind;
    u8 padding[3];
} NetBufferRef;

typedef char NetBufferRef_size_check[(sizeof(NetBufferRef) == 8) ? 1 : -1];
typedef char NetBufferRef_kind_check[(offsetof(NetBufferRef, kind) == 4) ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
/* Advances a buffer reference by n bytes (TLobby_804050DC.c). */
void TLobby__sub_80406EB8(NetBufferRef *ref, s32 n);
#ifdef __cplusplus
}
#endif

#endif
