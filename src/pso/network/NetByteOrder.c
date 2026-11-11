/* Big-endian (network byte order) read and write helpers (a C library, built with GC/1.2.5n). NetByteOrder is
 * an inferred name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
/* This file's functions. */
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

u16 read_network_u16_be(u8 *p) {
    u16 v = *p++;
    v <<= 8;
    v |= *p;
    return v;
}

u32 TLobby__sub_80402AFC(u8 *p) {
    u32 v = *p++;
    v <<= 8;
    v |= *p++;
    v <<= 8;
    v |= *p++;
    v <<= 8;
    v |= *p;
    return v;
}

u8 *write_network_u16_be(u8 *p, u16 v) {
    *p++ = v >> 8;
    *p++ = v;
    return p;
}

u8 *write_network_u32_be(u8 *p, u32 v) {
    *p++ = v >> 24;
    *p++ = v >> 16;
    *p++ = v >> 8;
    *p++ = v;
    return p;
}
