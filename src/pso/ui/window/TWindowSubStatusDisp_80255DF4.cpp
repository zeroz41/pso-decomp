#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowInputNumber.h"

s16 TWindowSubStatusDisp::get_item_type() { return *(s16*)((char*)this + 0x2fa); }
s16 TWindowSubStatusDisp::get_field_2F8() { return *(s16*)((char*)this + 0x2f8); }
s16 TWindowSubStatusDisp::get_stat() { return *(s16*)((char*)this + 0x2f2); }

s16 TWindowSubStatusDisp::get_value() { return *(s16*)((char*)this + 0x2ce); }

void TWindowHelpItem::set_flag60_bit4() { this->m_60 |= 0x4; }

void TWindowHelpItem::sub_80255E24() {
    u8 temp_r4;
    temp_r4 = this->m_60;
    if (temp_r4 & 2) {
        this->m_60 = (u8) (temp_r4 & 0xFFFFFFFB);
    }
}
