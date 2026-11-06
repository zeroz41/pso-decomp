#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowInputNumber.h"

void TWindowHelpItem::set_flag60_bit4() { this->m_60 |= 0x4; }

void TWindowHelpItem::sub_80255E24() {
    u8 temp_r4;
    temp_r4 = this->m_60;
    if (temp_r4 & 2) {
        this->m_60 = (u8) (temp_r4 & 0xFFFFFFFB);
    }
}
