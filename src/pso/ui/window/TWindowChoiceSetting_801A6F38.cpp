#include "types.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/ui/window/TWindowChoiceSetting.h"

extern "C" {

s32 input_press_or_repeat(s32, s32, s32, s32);

s32 test_buttons_press_or_repeat(s32 input, s32 buttons, s32 delay, s32 period) {
    u32 t = pack_flags__13TRaderMapCoreFii(input, buttons);
    return input_press_or_repeat(input, t, delay, period);
}

}
