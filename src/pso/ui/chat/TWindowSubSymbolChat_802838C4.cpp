#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_802838C4.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"

struct Obj_80283944 { u8 pad[0x60]; s8 f60; };

extern "C" {
void TWindowSubSymbolChat__sub_80283944(Obj_80283944 *o);
void TWindowSubSymbolChat::set_flag_bit2(s32 *arg0) {
    *arg0 |= 2;
}

void TWindowSubSymbolChat::clear_flag_bit2(s32 *arg0) {
    *arg0 &= 0xFFFFFFFD;
}

s16 TWindowSubSymbolChat::get_cursor_pos() {
    return *(s16 *)((s8 *)this + 0x6C);
}

s16 TWindowSubSymbolChat::get_cursor_x() {
    return *(s16 *)((s8 *)this + 0x6A);
}

s32 TWindowSubSymbolChatPartsSet::is_active() {
    return this->m_68 & 1;
}

s32 TWindowSubSymbolChat__sub_80283900(void *arg0) {
    return *(u8 *)((s8 *)arg0 + 0x68) & 2;
}

void TWindowSubSymbolChat::clear_flag60_bit2() {
    *(u8 *)((s8 *)this + 0x60) = (u8) (*(u8 *)((s8 *)this + 0x60) & 0xFFFFFFFD);
}

void TWindowSubSymbolChat::clear_flag60_bit4() {
    *(u8 *)((s8 *)this + 0x60) = (u8) (*(u8 *)((s8 *)this + 0x60) & 0xFFFFFFFB);
}

void TWindowSubSymbolChat::set_pos_and_flag(s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)this + 0x6C) = arg1;
    *(s32 *)((s8 *)this + 0x70) = arg2;
    *(u8 *)((s8 *)this + 0x60) = (u8) (*(u8 *)((s8 *)this + 0x60) | 4);
}
void TWindowSubSymbolChat__sub_80283944(Obj_80283944 *o) {
    o->f60 &= ~1;
}

}
