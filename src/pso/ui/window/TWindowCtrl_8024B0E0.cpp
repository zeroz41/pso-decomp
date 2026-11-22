#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"

extern "C" {

saddr get_window_layout_position(s32);

saddr TWindowCtrl::get_message_by_type(s8 arg0, s32 client_id) {
    saddr window;
    s32 var_r3;

    window = TWindowCtrl::get_window(client_id);
    if (window == 0) {
        return 0;
    }
    if (((TWindowCtrlMain *)window)->get_main_menu_message() != 0) {
        var_r3 = 0x4D;
    } else if (((TWindowCtrl *)window)->get_active_menu() != 0) {
        var_r3 = 0x48;
    } else {
        var_r3 = 0x43;
    }
    return get_window_layout_position(var_r3 + arg0);
}


void TWindowCtrl::release_slot(s8 *arg0) {
    s8 temp_r4;

    if (instance != NULL) {
        temp_r4 = *arg0;
        if ((temp_r4 >= 0) && (temp_r4 < 4)) {
            instance->flags &= ~(0x40 << temp_r4);
            *arg0 = -1;
        }
    }
}

}
