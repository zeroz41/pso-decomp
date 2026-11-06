#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {

s32 play_sound_effect(int, int, int, int);
s32 is_open__28TWindowSubSymbolChatFaceTypeFv();

void TWindowSubSymbolChatFaceType::close_when_chat_closed() {
    if (is_open__28TWindowSubSymbolChatFaceTypeFv() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubSymbolChatFaceType::confirm_selection() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
    ((TWindowSubStatusDisp *)(this->m_68))->set_entry_state(2);
}

}
