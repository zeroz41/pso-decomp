#include "types.h"
#include "pso/audio/AdxUiBridge.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

void TKeyBoardControl::flush_input() {
    TLobby::run_worker_callbacks_slot4();
}

void wait_for_vi_retrace(void) {
    VIWaitForRetrace();
}

void TLobby__sub_803CBE20(void) {
    TLobby::run_step_60c8();
}

void adx_bridge_apply_field(AdxUiBridgeTarget *bridge) {
    bridge->target->apply_field();
}

void TLobby__sub_803CBE64(AdxUiBridgeTarget *bridge) {
    adx_bridge_get_stream_id((int)bridge->target);
}
