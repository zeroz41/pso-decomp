#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInputState.h"

extern "C" {

s32 test_controller_flag_4c_color(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_4c & TRaderMapCore::pack_color_bits((s32)pad, mask)) != 0;
}

s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask) {
    return (*(s32 *)((s8 *)pad + 0x4C) & pack_flags__13TRaderMapCoreFii((s32)pad, mask)) != 0;
}

}
