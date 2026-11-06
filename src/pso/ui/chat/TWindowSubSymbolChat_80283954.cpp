#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"

void TWindowSubSymbolChat::set_flag60_bit1() {
    *(u8 *)((s8 *)this + 0x60) = (u8) (*(u8 *)((s8 *)this + 0x60) | 1);
}

void TWindowSubSymbolChat::set_flag60_bit2() {
    *(u8 *)((s8 *)this + 0x60) = (u8) (*(u8 *)((s8 *)this + 0x60) | 2);
}

s32 TWindowSubSymbolChatParts::sub_80283974() {
    return this->m_70 & 1;
}

s32 TWindowSubSymbolChat__sub_80283980(void *arg0) {
    return *(u8 *)((s8 *)arg0 + 0x70) & 2;
}

s32 TWindowSubSymbolChatFaceType::is_open() {
    return this->m_60 & 1;
}

s32 TWindowSubSymbolChat__sub_80283998(void *arg0) {
    return *(u8 *)((s8 *)arg0 + 0x60) & 2;
}

s32 fn_802839A4(void *arg0) {
    return (s8) *(u8 *)((s8 *)arg0 + 0x61) + ((s8) *(u8 *)((s8 *)arg0 + 0x62) * 2);
}
