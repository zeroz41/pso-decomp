#include "types.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"
#include "pso/system/ControllerInputState.h"


s32 test_previous_buttons_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

