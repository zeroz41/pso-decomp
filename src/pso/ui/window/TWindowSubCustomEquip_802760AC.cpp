#include "types.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"

s32 TWindowSubCustomEquip::is_type_valid() {

    switch ((s8) this->m_62) {
    case 0:
        return 0;
    default:
    case 1:
        return 1;
    }
}
s32 TWindowSubCustomEquip::get_saved_slot_for_index(s32 arg0, s8 arg1) {
    switch (arg1) {
    case 0:
        return 2;
    case 1:
        return 1;
    case 2: break;
    }
    return 3;
}
