#ifndef PSO_NETWORK_BUFFERREF_H
#define PSO_NETWORK_BUFFERREF_H

#include "types.h"
#include <stddef.h>

typedef struct NetBufferRef {
    uaddr value;
    u8 kind;
    u8 padding[3];
} NetBufferRef;

LAYOUT_ASSERT(NetBufferRef_size_check, sizeof(NetBufferRef) == 8);
LAYOUT_ASSERT(NetBufferRef_kind_check, offsetof(NetBufferRef, kind) == 4);
#ifdef __cplusplus
extern "C" {
#endif
void set_value_and_enable(NetBufferRef *ref, s32 value);
void init_packet_header(NetBufferRef *ref, s32 value);
void init_msg(NetBufferRef *ref, s32 value);

/* Advances a buffer reference by n bytes (TLobby_804050DC.c). */
void netbuf_ref_advance(NetBufferRef *ref, s32 n);
/* Frees the block behind a buffer reference of kind 2 or 4 (TLobby_804050DC.c). */
s32 TLobby__sub_80406B6C(NetBufferRef *ref);
#ifdef __cplusplus
}
#endif

#endif
