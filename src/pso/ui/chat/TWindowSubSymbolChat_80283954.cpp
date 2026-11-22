#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"

void TWindowSubSymbolChatHelp::set_flag60_bit1() {
    m_60 = (u8)(m_60 | 1);
}

void TWindowSubSymbolChatHelp::set_flag60_bit2() {
    m_60 = (u8)(m_60 | 2);
}

s32 TWindowSubSymbolChatParts::sub_80283974() {
    return this->m_70 & 1;
}

s32 TWindowSubSymbolChat__sub_80283980(void *parts) {
    return *(u8 *)((s8 *)parts + 0x70) & 2;
}

s32 TWindowSubSymbolChatFaceType::is_open() {
    return this->m_60 & 1;
}

s32 TWindowSubSymbolChat__sub_80283998(void *face_type_window) {
    return *(u8 *)((s8 *)face_type_window + 0x60) & 2;
}

s32 fn_802839A4(void *window_base) {
    return (s8) *(u8 *)((s8 *)window_base + 0x61) + ((s8) *(u8 *)((s8 *)window_base + 0x62) * 2);
}
