#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

void TAdMultiPlyChrSelectGC::set_entry_value(s32 arg1, u32 arg2) {
    s32 arg0 = (s32)this;
    u8 *temp_r3;

    temp_r3 = (unsigned char *) (arg0 + (arg1 * 4));
    if ((u32) *(u32 *)((s8 *)temp_r3 + 0x24) != arg2) {
        *(u32 *)((s8 *)temp_r3 + 0x1C) = arg2;
        *(s32 *)((s8 *)temp_r3 + 0x3C) = 0;
    }
    *(u32 *)((s8 *)temp_r3 + 0x24) = arg2;
}
