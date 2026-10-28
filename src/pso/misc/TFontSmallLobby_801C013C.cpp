#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TFontSmallLobby_801C013C.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TUnk_804DDD28.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct O_801C0708 { u8 a; u8 b; u8 pad[2]; s32 c; u16 d; u16 e; };

struct O_801C0350 { u8 a; u8 b; u8 pad[2]; u16 c; u16 d; };

extern "C" {
int clear__8FlagWordFUl(void*, int);
extern s32 fn_80152EF8[];
void __construct_array(void *, void *, int, int, int);
int read_be16_field2__10TObjPlayerFv(void*);
void __copy(void *, void *, int);
int TFontSmallLobby__sub_801C013C(void* p) { return clear__8FlagWordFUl((void*)((char*)p + 0x10), 2); }

void *TFontSmallLobby__sub_801C0164(void *player) {
    __ct__8FlagWordFv(((char *)player + 16));
    __construct_array((void *)((char *)player + 32), fn_80152EF8, 0, 4, 10);
    ((TObjPlayer *)player)->reset_tech_state();
    return player;
}

int TFontSmallLobby__sub_801C01BC(void* p) { return read_be16_field2__10TObjPlayerFv(p); }

void *TFontSmallLobby__sub_801C01DC(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(u8 *)((s8 *)arg0 + 0x4) = *(u8 *)((s8 *)arg1 + 0x4);
    __copy((void *)((char *)arg0 + 5), (void *)((char *)arg1 + 5), 3);
    return arg0;
}

void* TFontSmallLobby__sub_801C0228(void* p, void* _w1) { TFontSmallLobby__sub_801C0258(p, _w1); return p; }

void TFontSmallLobby__sub_801C0258(void* p, void* q) { *(u8*)((char*)p + 0x0) = *(u8*)((char*)q + 0x0); *(u8*)((char*)p + 0x1) = *(u8*)((char*)q + 0x1); *(u16*)((char*)p + 0x2) = *(u16*)((char*)q + 0x2); }

void TFontSmallLobby::init_packet_6x9b_level_up() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 5) = 0;
    *(s8 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 7) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x9B;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TFontSmallLobby__sub_801C029C(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void TFontSmallLobby::bswap_battle_damage_packet() { read_be16_field2__10TObjPlayerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void* TFontSmallLobby__sub_801C030C(void* p, void* a1) { TFontSmallLobby__sub_801C0228(p, a1); *(short*)((char*)p + 0x4) = *(unsigned short*)((char*)a1 + 0x4); *(short*)((char*)p + 0x6) = *(short*)((char*)a1 + 0x6); return p; }

void TFontSmallLobby::init_packet_6x8f_battle_damage() {
    O_801C0350 *p = (O_801C0350 *)this;
    p->c = 0xFFFF;
    p->d = 0;
    p->a = 0x8f;
    p->b = 2;
}

void TFontSmallLobby__sub_801C0378(void* p) { ((TFontSmallLobby *)p)->bswap_battle_damage_packet(); ((TLobby *)p)->send_60_sized(); }

void TFontSmallLobby::bswap_6x90_set_player_battle_team() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); }

void *TFontSmallLobby__sub_801C03E0(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(void **)((s8 *)arg0 + 0x4) = *(void **)((s8 *)arg1 + 0x4);
    return arg0;
}

void TFontSmallLobby__sub_801C041C(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x90;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TFontSmallLobby__sub_801C0438(void* p) { *(u8*)((char*)p + 0x0) = 130; *(u8*)((char*)p + 0x1) = 1; }

void TFontSmallLobby__sub_801C044C(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void TFontSmallLobby__sub_801C0480(void* p) { *(u8*)((char*)p + 0x0) = 129; *(u8*)((char*)p + 0x1) = 1; }

void TFontSmallLobby::send_font_state_msg() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }

void TFontSmallLobby__sub_801C04C8(void* p) { *(u8*)((char*)p + 0x0) = 123; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C04DC(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void fn_801C0510(void* p) { *(u8*)((char*)p + 0x0) = 122; *(u8*)((char*)p + 0x1) = 1; }

void TLobby::cleanup_small_font() { TFontSmallLobby__sub_801C01BC(this); send_subcommand((u8 *)this); }

void fn_801C0558(void* p) { *(u8*)((char*)p + 0x0) = 28; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C056C(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void fn_801C05A0(void* p) { *(u8*)((char*)p + 0x0) = 27; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C05B4(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void fn_801C05E8(void* p) { *(u8*)((char*)p + 0x0) = 35; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C05FC(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void fn_801C0630(void* p) { *(u8*)((char*)p + 0x0) = 34; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C0644(void* p) { TFontSmallLobby__sub_801C01BC(p); send_subcommand((u8 *)p); }

void TObjPlayer::bswap_change_hp_packet() {
    read_be16_field2__10TObjPlayerFv(this);
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_16((u16 *)((void *)((char *)this + 8)));
    bswap_16((u16 *)((void *)((char *)this + 10)));
}

void *TObjPlayer__sub_801C06BC(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(void **)((s8 *)arg0 + 0x4) = *(void **)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x8) = *(s16 *)((s8 *)arg1 + 0x8);
    *(u16 *)((s8 *)arg0 + 0xA) = *(u16 *)((s8 *)arg1 + 0xA);
    return arg0;
}

void TObjPlayer::init_6x2F_packet_header() {
    O_801C0708 *p = (O_801C0708 *)this;
    p->c = 0;
    p->d = 0;
    p->e = 0xFFFF;
    p->a = 0x2f;
    p->b = 3;
}

void TObjPlayer__sub_801C0734(void* p) { ((TObjPlayer *)p)->bswap_change_hp_packet(); send_subcommand((u8 *)p); }

void TObjPlayer::byteswap_packet_body() {
    read_be16_field2__10TObjPlayerFv(this);
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_32((u32 *)((void *)((char *)this + 8)));
    bswap_32((u32 *)((void *)((char *)this + 12)));
    bswap_32((u32 *)((void *)((char *)this + 16)));
}
u8 *TObjPlayer__sub_801C07B4(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    return arg0;
}

}
