#include "types.h"
#include "pso/audio/AdxRnaInitBuffer.h"
#include "pso/audio/CriSvm.h"
#include "pso/audio/AdxUiBridge.h"
#include "pso/audio/GcrnaBridgeLoop.h"
#include "pso/network/TLobby.h"

void flush_input() {
    svm_exec_group4();
}

void wait_for_vi_retrace(void) {
    VIWaitForRetrace();
}

void TLobby__sub_803CBE20(void) {
    adx_rna_set_buffer_storage();
}

void adx_bridge_set_loop_flag(AdxUiBridgeTarget *bridge, s32 enabled) {
    gcrna_bridge_set_loop_flag(bridge->stream, enabled);
}

s32 TLobby__sub_803CBE64(AdxUiBridgeTarget *bridge, s32 channel) {
    return adx_bridge_get_stream_id(bridge->stream, channel);
}
