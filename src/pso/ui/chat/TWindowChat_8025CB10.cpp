#include "types.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

#pragma push
#pragma bool off
s32 TWindowKeyBoardBase::sub_8025CB10() {
    if ((u32) this->m_text.length != 0U) {
        return 1;
    }
    return this->m_text2.length != 0;
}
#pragma pop

void TWindowKeyBoardBase::flush_if_flagged() { if (get_flag() != 0) { reset_input(); } }
