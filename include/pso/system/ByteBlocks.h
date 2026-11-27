#ifndef PSO_SYSTEM_BYTEBLOCKS_H
#define PSO_SYSTEM_BYTEBLOCKS_H

#include "types.h"

// Fixed-size byte runs copied as one struct assignment.
struct ByteBlock_8 { u8 bytes[0x8]; };
struct ByteBlock_C { u8 bytes[0xC]; };
struct ByteBlock_14 { u8 bytes[0x14]; };
struct ByteBlock_10 { u8 bytes[0x10]; };
struct ByteBlock_20 { u8 bytes[0x20]; };
struct ByteBlock_24 { u8 bytes[0x24]; };
struct ByteBlock_50 { u8 bytes[0x50]; };
struct ByteBlock_348 { u8 bytes[0x348]; };

#endif
