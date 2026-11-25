#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowInputNumber.h"

s16 TWindowSubStatusDisp::get_item_type() { return *(s16*)((char*)this + 0x2fa); }
s16 TWindowSubStatusDisp::get_field_2F8() { return *(s16*)((char*)this + 0x2f8); }
s16 TWindowSubStatusDisp::get_stat() { return *(s16*)((char*)this + 0x2f2); }

s16 TWindowSubStatusDisp::get_value() { return *(s16*)((char*)this + 0x2ce); }

void TWindowHelpItem::lock_page_flip() { this->help_flags |= 0x4; }

void TWindowHelpItem::unlock_page_flip() {
    u8 temp_r4;
    temp_r4 = this->help_flags;
    if (temp_r4 & 2) {
        this->help_flags = (u8) (temp_r4 & 0xFFFFFFFB);
    }
}
