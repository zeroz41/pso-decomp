#include "types.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/ui/window/TWindowChoiceSetting.h"

extern "C" {

s32 input_press_or_repeat(s32, s32, s32, s32);

s32 TWindowChoiceSetting::apply_choice(s32 input, s32 arg1, s32 delay, s32 period) {
    u32 t = pack_flags__13TRaderMapCoreFii(input, arg1);
    return input_press_or_repeat(input, t, delay, period);
}

}
