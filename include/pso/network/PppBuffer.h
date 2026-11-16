#ifndef PSO_NETWORK_PPPBUFFER_H
#define PSO_NETWORK_PPPBUFFER_H

#include "types.h"

/* PppBuffer.c (inferred module name): the PPP packet buffers and their readers. */
s16 ppp_buffer_read(void *self, void *dst, u16 n);

#endif
