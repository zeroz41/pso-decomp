#include "types.h"
#include "pso/unk/TLobby_8020A350.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

void TLobby::bswap_quad_word() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }

void TLobby__sub_8020A394(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); }

void TLobby__sub_8020A3D0(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}

void TLobby::bswap_vec3() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void TLobby::swap_header_endian() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_16((u16 *)((char*)this + 0x18)); bswap_16((u16 *)((char*)this + 0x1a)); }

void TLobby__sub_8020A48C(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); bswap_32((u32 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x14)); bswap_16((u16 *)((char*)p + 0x16)); bswap_16((u16 *)((char*)p + 0x18)); bswap_16((u16 *)((char*)p + 0x1a)); bswap_16((u16 *)((char*)p + 0x1c)); bswap_16((u16 *)((char*)p + 0x1e)); }
