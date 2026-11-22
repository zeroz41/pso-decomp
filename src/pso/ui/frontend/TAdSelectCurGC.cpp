#include "types.h"
#include "pso/ui/frontend/TAdSelectCurGC_801A6E20.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/system/ControllerInputState.h"

extern "C" {

s32 test_previous_buttons_remapped(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & TRaderMapCore__sub_801A6D00(pad, mask)) != 0;
}

s32 test_previous_buttons_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}
}
