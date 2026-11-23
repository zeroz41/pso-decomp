#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_802838C4.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"



extern "C" {
void SymbolChatPreset::set_flag_bit2() {
    flags |= 2;
}

void SymbolChatPreset::clear_flag_bit2() {
    flags &= 0xFFFFFFFD;
}

s32 TWindowSubSymbolChatPartsSet::get_cursor_pos() {
    return cursor_y;
}

s32 TWindowSubSymbolChatPartsSet::get_cursor_x() {
    return cursor_x;
}

s32 TWindowSubSymbolChatPartsSet::is_active() {
    return this->m_68 & 1;
}

s32 TWindowSubSymbolChat__sub_80283900(void *parts_set) {
    return *(u8 *)((s8 *)parts_set + 0x68) & 2;
}

void TWindowSubSymbolChatHelp::clear_flag60_bit2() {
    m_60 = (u8)(m_60 & ~2);
}

void TWindowSubSymbolChatHelp::clear_flag60_bit4() {
    m_60 = (u8)(m_60 & ~4);
}

void TWindowSubSymbolChatHelp::set_pos_and_flag(s32 *first, s32 *second) {
    m_6c = first;
    m_70 = second;
    m_60 = (u8)(m_60 | 4);
}
void TWindowSubSymbolChat__sub_80283944(TWindowSubSymbolChatHelp *window) {
    window->m_60 &= ~1;
}

}
