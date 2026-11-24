#ifndef PSO_NETWORK_BUFFERREF_H
#define PSO_NETWORK_BUFFERREF_H

#include "types.h"
#include <stddef.h>

typedef struct NetBufferRef {
    union {
        uaddr value; /* kinds 2 and 3: a pool slot handle (entry << 24 | segment << 16) */
        void *data;  /* kinds 1 and 4: the bytes themselves */
    };
    u8 kind;
    u8 padding[3];
} NetBufferRef;

LAYOUT_ASSERT(NetBufferRef_size_check, sizeof(NetBufferRef) == 8);
LAYOUT_ASSERT(NetBufferRef_kind_check, offsetof(NetBufferRef, kind) == 4);
#ifdef __cplusplus
extern "C" {
#endif
void set_value_and_enable(NetBufferRef *ref, void *data);
void init_packet_header(NetBufferRef *ref, void *data);
void init_msg(NetBufferRef *ref, void *data);

/* Advances a buffer reference by n bytes (TLobby_804050DC.c). */
void netbuf_ref_advance(NetBufferRef *ref, s32 n);
/* Frees the block behind a buffer reference of kind 2 or 4 (TLobby_804050DC.c). */
s32 netbuf_release(NetBufferRef *ref);
#ifdef __cplusplus
}
#endif

#endif
