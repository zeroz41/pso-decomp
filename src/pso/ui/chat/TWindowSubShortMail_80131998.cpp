#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/chat/TWindowSubShortMail_80131998.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

void TWindowSubShortMail__sub_80131998(void *arg0) {
    u16 temp_r3;

    temp_r3 = *(u16 *)((s8 *)arg0 + 0x1C);
    if (!(temp_r3 & 4)) {
        *(u16 *)((s8 *)arg0 + 0x1C) = (u16) (temp_r3 | 4);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) {
            ((TKeyBoardControl *)(*(void **)((s8 *)arg0 + 0x24)))->set_flag60_bit200();
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x28) != 0U) {
            ((TWindowLockOn *)(*(void **)((s8 *)arg0 + 0x28)))->request_close();
        }
    }
}
void TWindowSubShortMail::hide_window() {
    u16 temp_r3;

    temp_r3 = *(u16 *)((s8 *)this + 0x1C);
    if (temp_r3 & 4) {
        *(u16 *)((s8 *)this + 0x1C) = (u16) (temp_r3 & 0xFFFFFFFB);
        if ((u32) this->m_24 != 0U) {
            ((TKeyBoardControl *)(this->m_24))->clear_flag60_bit200();
        }
        if (!(*(u16 *)((s8 *)this + 0x1C) & 1) && ((u32) this->m_28 != 0U)) {
            window_request_show(*(void * *)&this->m_28);
        }
    }
}
