#include "types.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/ui/window/WindowCtrlCallback.h"


extern PlayerWindowCommand window_ctrl_init_params;

void fn_8024AB54(saddr arg0) {
    call_window_method__11TWindowCtrlFPvi(arg0, window_ctrl_init_params);
}
