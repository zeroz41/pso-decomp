#include "types.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern "C" {

s32 is_decided__19TWindowMenuIconLineFv();
s32 set_visible__19TWindowSubTradeMainFv();

void TWindowSubTradeMain::update_trade_state() {
    if ((u32) this->m_80 != 0U) {
        if (is_decided__19TWindowMenuIconLineFv() != 0) {
            ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(2);
        } else {
            ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(1);
        }
    }
    clear_flag70_bit80();
    clear_flag();
}

void TWindowSubTradeMain::close() {
    set_visible__19TWindowSubTradeMainFv();
    set_close_flag();
    if ((u32) this->m_80 != 0U) {
        ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(0);
    }
}

}
