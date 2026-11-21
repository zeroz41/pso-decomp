#include "types.h"
#include "pso/unk/text_8006EF80.h"

struct RecoveredGlobal_8006EF80_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

extern RecoveredGlobal_8006EF80_lbl_8048C9D8 challenge_mode_state;
LAYOUT_ASSERT(RecoveredGlobal_8006EF80_lbl_8048C9D8_size, sizeof(RecoveredGlobal_8006EF80_lbl_8048C9D8) == 0x748);
s32 fn_8006EF80(void) {
    return *(s32 *)((s8 *)&challenge_mode_state.value + 0x48);
}
