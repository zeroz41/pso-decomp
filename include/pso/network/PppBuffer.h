#ifndef PSO_NETWORK_PPPBUFFER_H
#define PSO_NETWORK_PPPBUFFER_H

#include "pso/network/NetworkRuntime.h"

/* PppBuffer.c (inferred module name): the PPP packet buffers and their readers. */
struct IpPseudoHeader;

#ifdef __cplusplus
extern "C" {
#endif
PppFrame *alloc_from_buffer(PppFrame *frame, s16 length);
u32 ppp_frame_length(PppFrame *frame);
s16 ppp_buffer_read(PppFrame **cursor, void *dst, u16 n);
u16 ip_pseudo_header_checksum(struct IpPseudoHeader *pseudo, PppFrame *frame, u16 count);
#ifdef __cplusplus
}
#endif

#endif
