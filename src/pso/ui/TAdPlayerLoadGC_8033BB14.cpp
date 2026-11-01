#include "types.h"
#include "pso/misc/TCheckMemoryCard.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 TAdSinglePlyChrSelectGC__sub_8033BA84(s32);
s32 fn_8033BAB4(void *);

s32 TCheckMemoryCard::sub_8033BB14() {
    s32 var_r31;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        *(s32 *)((s8 *)this + 0x2C) = 0;
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        *(s32 *)((s8 *)this + 0x2C) = 0;
        return 4;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        *(s32 *)&this->_pad24 = (s32) (*(s32 *)&this->_pad24 + 1);
        *(s32 *)((s8 *)this + 0x2C) = 0;
        return 2;
    }
    *(s32 *)&this->_pad24 = 0;
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        *(s32 *)((s8 *)this + 0x2C) = 0;
        return 8;
    }
    if ((s32) *(s32 *)((s8 *)this + 0x2C) != 0) {
        return this->m_28;
    }
    *(s32 *)((s8 *)this + 0x2C) = 1;
    var_r31 = fn_8033BAB4(this);
    if ((s32) this->m_1c != 0) {
        if (TAdSinglePlyChrSelectGC__sub_8033BA84(0) == 0) {
            var_r31 |= 0x10;
        }
    } else if (TAdSinglePlyChrSelectGC::has_no_save_files(0) == 0) {
        var_r31 |= 0x10;
    }
    return var_r31;
}

}
