#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

void TKeyBoardControl::hide() {
    u16 flags;

    flags = m_1c;
    if (!(flags & 4)) {
        m_1c = flags | 4;
        if (m_hard != NULL) {
            m_hard->set_flag60_bit200();
        }
        if (m_soft != NULL) {
            m_soft->request_close();
        }
    }
}
void TKeyBoardControl::show() {
    u16 flags;

    flags = m_1c;
    if (flags & 4) {
        m_1c = flags & 0xFFFFFFFB;
        if (m_hard != NULL) {
            m_hard->clear_flag60_bit200();
        }
        if (!(m_1c & 1) && (m_soft != NULL)) {
            window_request_show(m_soft);
        }
    }
}
