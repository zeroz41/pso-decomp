#include "types.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInputState.h"

s32 TRaderMapCore::pack_color_bits(s32 input, s32 mask) {
    s32 temp_r3;

    temp_r3 = mask | ((mask << 0x10) & 0xF00000);
    return temp_r3 | ((temp_r3 << 0x16) & 0x3C000000);
}

s32 TRaderMapCore__sub_801A6D00(void *arg0, s32 mask) {
    return (mask & 0xFFFFFF0F) | ((mask << 0x16) & 0x3C000000);
}

s32 pack_flags__13TRaderMapCoreFii(s32 input, s32 mask) {
    return (mask & 0xFF0FFFFF) | ((mask << 0x16) & 0x3C000000);
}

s32 test_flags_04_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_04 & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}
