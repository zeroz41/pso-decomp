#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

void TWindowSubComCard::update_display_state() {
    s32 temp_r4;

    temp_r4 = this->m_28;
    if (!(temp_r4 & 2)) {
        if (temp_r4 & 1) {
            if ((u32) this->m_30 == 0U) {
                update_card_display((void*)0, (void*)(-1), (void*)(-1), (void*)(-1));
            }
        } else {
            if (temp_r4 & 4) {
                if ((s32) this->m_40 != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (temp_r4 & 8) {
                if ((s32) this->m_40 != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (temp_r4 & 0x10) {
                if ((s32) this->m_40 != 0) {
                    set_state(3);
                    return;
                }
                set_state(1);
                return;
            }
            if (temp_r4 == 0) {
                set_state(2);
            }
        }
    }
}

void TWindowSubComCard::close_and_update_display() {
    u8 *arg0 = (u8 *)this;
    ((TWindowSubComCard *)arg0)->close_windows();
    if (this->m_28 & 1) {
        ((TWindowSubComCard *)arg0)->update_card_display((void*)0, (void*)(-1), (void*)(-1), (void*)(-1));
    }
}
