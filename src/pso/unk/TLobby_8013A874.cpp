#include "types.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/unk/text_8013AAD4.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_10 { u8 bytes[0x10]; };

extern "C" {
s32 __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();

void TLobby::bswap_fields() { bswap_16((u16 *)((char*)this + 0x2)); bswap_32((u32 *)((char*)this + 0x4)); }

void TLobby::bswap_header_3words() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void bswap__15disp_data_part2Fv(s32 arg0) {
    s32 off;
    s32 i;

    bswap_32((u32 *)(arg0 + 0x18));
    bswap_32((u32 *)(arg0 + 0x2C));
    bswap_32((u32 *)(arg0 + 0x34));
    for (i = 0, off = 0; i < 8; i++, off += 2) {
        bswap_16((u16 *)((s32)((char *)arg0 + off + 0x38)));
    }
    bswap_32((u32 *)(arg0 + 0x48));
    bswap_32((u32 *)(arg0 + 0x4C));
}
}

void bswap_telepipe_record(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); bswap_32((u32 *)((char*)p + 0x10)); bswap_32((u32 *)((char*)p + 0x14)); bswap_32((u32 *)((char*)p + 0x18)); }

void TLobby__sub_8013A9C0(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); }

void bswap_object_source_record(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); }

void TLobby::bswap_6x6B() { bswap_32((u32 *)this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
u8 *TLobby__sub_8013AA64(u8 *arg0, u8 *arg1) {
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
    *(s32 *)((s8 *)arg0 + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(ByteBlock_10 *)((s32) arg0 + 0x10) = *(const ByteBlock_10 *)((s32) arg1 + 0x10);
    fn_8013AAD4((arg0 + 0x20), (arg1 + 0x20));
    return arg0;
}
