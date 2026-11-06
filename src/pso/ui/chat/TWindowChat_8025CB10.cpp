#include "types.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

bool TWindowKeyBoardBase::sub_8025CB10() {
    if ((u32) this->m_7c != 0U) {
        return 1;
    }
    return this->m_94 != 0;
}

void TWindowChat::flush_if_flagged() { if (get_flag() != 0) { reset_input(); } }
