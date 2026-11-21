#include "pso/ui/window/WindowCtrlCallback.h"
#include "types.h"

#include "pso/ui/window/TWindowCtrl.h"

extern PlayerWindowQuery window_ctrl_is_visible_callback_entry;
s32 TWindowCtrl::is_slot_visible(s32 local_client_id) {
    PlayerWindowQuery callback = window_ctrl_is_visible_callback_entry;
    return TWindowCtrl__sub_8024B098(local_client_id, callback);
}

s32 TWindowCtrl__sub_8024B098(s32 client_id, PlayerWindowQuery pmf) {
    TWindowCtrl *w = (TWindowCtrl *)TWindowCtrl::get_window(client_id);
    if (w == NULL) {
        return 0;
    }
    return (w->*pmf)();
}
