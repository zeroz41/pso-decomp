#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B9C0.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

void TWindowCtrl::update() { update_party_status_rows(); update_window_visibility(); update_com_card_window(); update_trade_request_window(); TWindowCtrl__sub_8024BB30(this); handle_controller(); update_trade_window(); TWindowCtrl__sub_8024B9C0(this); update_pulse_color(); }

}
