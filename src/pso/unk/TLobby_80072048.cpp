#include "types.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pair_8007206C { u8 bytes[8]; };

struct Npc_8007206C {
    Pair_8007206C x0;
    Pair_8007206C x8;
    Pair_8007206C x10;
    s32 x18;
    u8 x1C;
    char name[15];
    s32 x2C;
    u8 x30;
    u8 x31;
    u8 x32;
    u8 x33;
    s32 x34;
    Pair_8007206C x38;
    Pair_8007206C x40;
    Pair_8007206C x48;
};

extern "C" {
Npc_8007206C *copy_player_visual_record(Npc_8007206C *dst, Npc_8007206C *src);
void TLobby::copy_header_struct(void* q) { *(u8 *)&this->m_name = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); *(u16*)((char*)this + 0x2) = *(u16*)((char*)q + 0x2); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); }
Npc_8007206C *copy_player_visual_record(Npc_8007206C *dst, Npc_8007206C *src) {
    *dst = *src;
    return dst;
}

}
