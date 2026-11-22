#include "pso/ui/window/WindowCtrlCallback.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024AEAC.h"

#include "pso/ui/window/TWindowCtrl.h"

extern PlayerWindowQuery lbl_804CE9D4;
extern PlayerWindowQuery window_ctrl_apply_default_vec_callback_entry;
extern PlayerWindowQuery TWindowCtrl__player_menu_query_cb;
extern PlayerWindowCommand TWindowCtrl__unsuppress_slot_cb;
extern PlayerWindowCommand TWindowCtrl__suppress_slot_cb;

void TWindowCtrl::suppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = TWindowCtrl__suppress_slot_cb;
    call_window_method__11TWindowCtrlFPvi(local_client_id, callback);
}

void TWindowCtrl::unsuppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = TWindowCtrl__unsuppress_slot_cb;
    call_window_method__11TWindowCtrlFPvi(local_client_id, callback);
}

void call_window_method__11TWindowCtrlFPvi(s32 client_id, PlayerWindowCommand pmf) {
    TWindowCtrl *w = (TWindowCtrl *)TWindowCtrl::get_window(client_id);
    if (w != NULL) {
        (w->*pmf)();
    }
}

s32 TWindowCtrl::has_player_active_menu(s32 local_client_id) {
    PlayerWindowQuery callback = TWindowCtrl__player_menu_query_cb;
    return TWindowCtrl__sub_8024B098(local_client_id, callback);
}

void TWindowCtrl::apply_default_vec(s32 arg0, saddr client_id) {
    PlayerWindowQuery callback = window_ctrl_apply_default_vec_callback_entry;
    TWindowCtrl__sub_8024B098(client_id, callback);
}

void TWindowCtrl__sub_8024B000(s32 arg0, saddr arg1) {
    PlayerWindowQuery callback = lbl_804CE9D4;
    TWindowCtrl__sub_8024B098(arg1, callback);
}
