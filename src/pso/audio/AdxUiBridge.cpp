#include "types.h"
#include "pso/audio/AdxRnaInitBuffer.h"
#include "pso/audio/CriSvm.h"
#include "pso/audio/AdxUiBridge.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/GcrnaBridgeLoop.h"
#include "pso/network/TLobby.h"

void flush_input() {
    svm_exec_group4();
}

void wait_for_vi_retrace(void) {
    VIWaitForRetrace();
}

void gcrna_bridge_init_buffers(void) {
    adx_rna_set_buffer_storage();
}

void adx_bridge_set_loop_flag(AdxtPlayer *player, s32 enabled) {
    gcrna_bridge_set_loop_flag(player->rna_handle, enabled);
}

s32 adx_ui_bridge_get_stream_id(AdxtPlayer *player, s32 channel) {
    return adx_bridge_get_stream_id(player->rna_handle, channel);
}
