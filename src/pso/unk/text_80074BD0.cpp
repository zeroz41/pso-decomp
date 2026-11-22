#include "types.h"
#include <string.h>
#include "pso/unk/text_80074BD0.h"
#include "pso/unk/text_80074C70.h"

struct RecoveredGlobal_80074BD0_lbl_8048D208 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
RecoveredGlobal_80074BD0_lbl_8048D208 lbl_8048D208 = { 0 };
LAYOUT_ASSERT(RecoveredGlobal_80074BD0_lbl_8048D208_size, sizeof(RecoveredGlobal_80074BD0_lbl_8048D208) == 0x18);
void fn_80074BD0(saddr src) {
    fn_80074C70();
    strncpy((char *)&lbl_8048D208.value, (const char *)src, 0x10);
    *(s8 *)((s8 *)&lbl_8048D208.value + 0x10) = 0;
}

}
