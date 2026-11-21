#include "types.h"
#include "pso/ui/hud/TLoadingCur_801A6DE0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInputState.h"

extern "C" {

s32 test_previous_buttons_color(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & TRaderMapCore::pack_color_bits((s32)pad, mask)) != 0;
}

}
