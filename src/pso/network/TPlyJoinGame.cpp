#include "types.h"
#include "pso/network/TPlyJoinGame.h"
#include "pso/unk/text_801E051C.h"
#include "pso/system/byteswap.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_80 { u8 bytes[0x80]; };

struct Row_801E03B8 { u32 a[2]; };

struct Join_801E03B8 {
    u32 hdr;
    Row_801E03B8 e[16];
    u8 mid[0x88];
    u32 tail;
};

extern "C" {
void bswap__13packet_headerFv();
void bswap__12TPlyJoinGameFv(Join_801E03B8 *self);

void bswap__12TPlyJoinGameFv(Join_801E03B8 *self) {
    int i;
    int j;
    bswap__13packet_headerFv();
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 2; j++) {
            bswap_32(&self->e[i].a[j]);
        }
    }
    bswap_32(&self->tail);
}

u8 *__ct__12TPlyJoinGameFRC12TPlyJoinGame(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(ByteBlock_80 *)((s32) arg0 + 4) = *(const ByteBlock_80 *)((s32) arg1 + 4);
    copy_player_lobby_data_entry(arg0 + 0x84, arg1 + 0x84);
    copy_player_lobby_data_entry(arg0 + 0xA4, arg1 + 0xA4);
    copy_player_lobby_data_entry(arg0 + 0xC4, arg1 + 0xC4);
    copy_player_lobby_data_entry(arg0 + 0xE4, arg1 + 0xE4);
    *(u8 *)((s8 *)arg0 + 0x104) = (u8) *(u8 *)((s8 *)arg1 + 0x104);
    *(u8 *)((s8 *)arg0 + 0x105) = (u8) *(u8 *)((s8 *)arg1 + 0x105);
    *(u8 *)((s8 *)arg0 + 0x106) = (u8) *(u8 *)((s8 *)arg1 + 0x106);
    *(u8 *)((s8 *)arg0 + 0x107) = (u8) *(u8 *)((s8 *)arg1 + 0x107);
    *(u8 *)((s8 *)arg0 + 0x108) = (u8) *(u8 *)((s8 *)arg1 + 0x108);
    *(u8 *)((s8 *)arg0 + 0x109) = (u8) *(u8 *)((s8 *)arg1 + 0x109);
    *(u8 *)((s8 *)arg0 + 0x10A) = (u8) *(u8 *)((s8 *)arg1 + 0x10A);
    *(u8 *)((s8 *)arg0 + 0x10B) = (u8) *(u8 *)((s8 *)arg1 + 0x10B);
    *(s32 *)((s8 *)arg0 + 0x10C) = (s32) *(s32 *)((s8 *)arg1 + 0x10C);
    *(u8 *)((s8 *)arg0 + 0x110) = (u8) *(u8 *)((s8 *)arg1 + 0x110);
    *(u8 *)((s8 *)arg0 + 0x111) = (u8) *(u8 *)((s8 *)arg1 + 0x111);
    *(u8 *)((s8 *)arg0 + 0x112) = (u8) *(u8 *)((s8 *)arg1 + 0x112);
    *(u8 *)((s8 *)arg0 + 0x113) = (u8) *(u8 *)((s8 *)arg1 + 0x113);
    return arg0;
}

}
