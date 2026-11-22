#include "types.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/ui/window/WindowCtrlCallback.h"


extern PlayerWindowCommand window_ctrl_init_params;

void fn_8024AB54(saddr client_id) {
    call_window_method__11TWindowCtrlFPvi(client_id, window_ctrl_init_params);
}
