#include "types.h"
#include "pso/unk/text_80074BD0.h"
#include "pso/unk/text_80074C70.h"

struct RecoveredGlobal_80074BD0_lbl_8048D208 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void strncpy(s32, s32, s32);
RecoveredGlobal_80074BD0_lbl_8048D208 lbl_8048D208 = { 0 };
typedef char RecoveredGlobal_80074BD0_lbl_8048D208_size[sizeof(RecoveredGlobal_80074BD0_lbl_8048D208) == 0x18 ? 1 : -1];
void fn_80074BD0(s32 arg0) {
    fn_80074C70();
    strncpy((s32) &lbl_8048D208.value, arg0, 0x10);
    *(s8 *)((s8 *)&lbl_8048D208.value + 0x10) = 0;
}

}
