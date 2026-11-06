#include "types.h"
#include "pso/ui/window/TWindowSubShortCut.h"

extern "C" {

s32 open_next_input_window__11TWindowChatFv(void *);
void TWindowChat__sub_80247D2C(void *p);
s32 close_all_children__11TWindowChatFv();

void TWindowSubShortCut::close_and_clear_flag() {
    close_all_children__11TWindowChatFv();
    this->m_1e = (u16) (this->m_1e & 0xFFFFFFFD);
    open_next_input_window__11TWindowChatFv(this);
}

void TWindowSubShortCut::free_icon() { void* m = *(void* *)&this->m_20; if (m) TWindowChat__sub_80247D2C(m); }

}
