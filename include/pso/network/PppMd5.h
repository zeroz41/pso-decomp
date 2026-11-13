#ifndef PSO_NETWORK_PPPMD5_H
#define PSO_NETWORK_PPPMD5_H

#include "types.h"

/* RFC 1321's MD5 context, as CHAP hashes its responses with it. */
typedef struct MD5Context {
    u32 state[4];               /* A, B, C, D */
    u32 count[2];               /* 0x10: the number of bits hashed, low word first */
    u8 buffer[64];              /* 0x18: the input block being filled */
} MD5Context;

typedef char MD5Context_size_check[sizeof(MD5Context) == 0x58 ? 1 : -1];

#endif
