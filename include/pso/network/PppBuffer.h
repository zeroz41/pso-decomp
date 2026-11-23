#ifndef PSO_NETWORK_PPPBUFFER_H
#define PSO_NETWORK_PPPBUFFER_H

#include "pso/network/NetworkRuntime.h"

/* PppBuffer.c (inferred module name): the PPP packet buffers and their readers. */
#ifdef __cplusplus
extern "C" {
#endif
PppFrame *alloc_from_buffer(PppFrame *frame, s16 length);
u32 get_field_4(PppFrame *frame);
s16 ppp_buffer_read(void *self, void *dst, u16 n);
u16 TLobby__sub_803FE934(u8 *object, PppFrame *frame, u16 count);
#ifdef __cplusplus
}
#endif

#endif
