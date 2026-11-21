#include "types.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInputState.h"

s32 TRaderMapCore::pack_color_bits(s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = arg2 | ((arg2 << 0x10) & 0xF00000);
    return temp_r3 | ((temp_r3 << 0x16) & 0x3C000000);
}

s32 TRaderMapCore__sub_801A6D00(void *arg0, s32 arg1) {
    return (arg1 & 0xFFFFFF0F) | ((arg1 << 0x16) & 0x3C000000);
}

s32 pack_flags__13TRaderMapCoreFii(s32 arg1, s32 arg2) {
    return (arg2 & 0xFF0FFFFF) | ((arg2 << 0x16) & 0x3C000000);
}

s32 test_flags_04_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_04 & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}
