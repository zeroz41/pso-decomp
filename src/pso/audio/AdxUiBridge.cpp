#include "types.h"
#include "pso/audio/AdxRnaInitBuffer.h"
#include "pso/audio/CriSvm.h"
#include "pso/audio/AdxUiBridge.h"
#include "pso/audio/GcrnaBridgeLoop.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

void TKeyBoardControl::flush_input() {
    svm_exec_group4();
}

void wait_for_vi_retrace(void) {
    VIWaitForRetrace();
}

void TLobby__sub_803CBE20(void) {
    adx_rna_set_buffer_storage();
}

void adx_bridge_set_loop_flag(AdxUiBridgeTarget *bridge, s32 enabled) {
    gcrna_bridge_set_loop_flag(bridge->target, enabled);
}

void TLobby__sub_803CBE64(AdxUiBridgeTarget *bridge) {
    adx_bridge_get_stream_id((int)bridge->target);
}
