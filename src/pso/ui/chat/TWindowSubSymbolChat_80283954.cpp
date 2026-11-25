#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"

void TWindowSubSymbolChatHelp::set_flag60_bit1() {
    feature_flags = (u8)(feature_flags | 1);
}

void TWindowSubSymbolChatHelp::set_flag60_bit2() {
    feature_flags = (u8)(feature_flags | 2);
}

s32 TWindowSubSymbolChatParts::sub_80283974() {
    return this->result_flags & 1;
}

s32 TWindowSubSymbolChatParts::is_cancelled() {
    return this->result_flags & 2;
}

s32 TWindowSubSymbolChatFaceType::is_open() {
    return this->result_flags & 1;
}

s32 TWindowSubSymbolChatFaceType::is_cancelled() {
    return this->result_flags & 2;
}

s32 TWindowSubSymbolChatFaceType::get_face_index() {
    return (s8) this->cursor_col + ((s8) this->cursor_row * 2);
}
