#include "types.h"
#include "pso/unk/text_801D6D8C.h"

void set_rule_slot_clamped(s8 *record, s8 value, s32 index) {
    s8 clamped;

    clamped = value;
    if ((clamped < 0) || (clamped > 0x14)) {
        clamped = 0x14;
    }
    (record + index)[0x20] = clamped;
}
