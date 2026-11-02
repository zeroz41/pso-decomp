#include "types.h"
#include "pso/unk/text_800FCC78.h"

struct RecoveredGlobal_800FCC78_lbl_8049CA54 {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
u8 * __ct__14TFontSmallHelpFUlUllUl(void *, s32, s32, s32, s32);
extern RecoveredGlobal_800FCC78_lbl_8049CA54 __vt__13TUnk_8049CA54;
typedef char RecoveredGlobal_800FCC78_lbl_8049CA54_size[sizeof(RecoveredGlobal_800FCC78_lbl_8049CA54) == 0x1C ? 1 : -1];
u8 *fn_800FCC78(u8 *arg0, s32 arg1) {
    __ct__14TFontSmallHelpFUlUllUl(arg0, arg1, -1, -1, 0);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_8049CA54.value;
    *(s32 *)((s8 *)arg0 + 0x60) = 5;
    return arg0;
}

}
