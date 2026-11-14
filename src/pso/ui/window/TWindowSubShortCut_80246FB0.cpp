#include "types.h"
#include "pso/ui/window/TWindowSubShortCut.h"
#include "pso/ui/chat/TWindowChat.h"

extern "C" {

void TWindowChat__sub_80247D2C(void *p);
s32 close_all_children__11TWindowChatFv();

void TWindowSubShortCut::close_and_clear_flag() {
    close_all_children__11TWindowChatFv();
    this->m_1e = (u16) (this->m_1e & 0xFFFFFFFD);
    ((TWindowChat *)this)->open_next_input_window();
}

void TWindowSubShortCut::free_icon() { void* m = *(void* *)&this->m_20; if (m) TWindowChat__sub_80247D2C(m); }

}
