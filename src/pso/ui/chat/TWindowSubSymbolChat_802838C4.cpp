#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_802838C4.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"



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
    return this->result_flags & 1;
}

s32 TWindowSubSymbolChatPartsSet::is_cancelled() {
    return this->result_flags & 2;
}

void TWindowSubSymbolChatHelp::clear_flag60_bit2() {
    feature_flags = (u8)(feature_flags & ~2);
}

void TWindowSubSymbolChatHelp::clear_flag60_bit4() {
    feature_flags = (u8)(feature_flags & ~4);
}

void TWindowSubSymbolChatHelp::set_pos_and_flag(s32 *first, s32 *second) {
    flip_u = first;
    flip_v = second;
    feature_flags = (u8)(feature_flags | 4);
}
void TWindowSubSymbolChat__sub_80283944(TWindowSubSymbolChatHelp *window) {
    window->feature_flags &= ~1;
}

