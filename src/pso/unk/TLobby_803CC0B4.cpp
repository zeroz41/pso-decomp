#include "types.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/unk/TLobby.h"


GcrnaStream *TLobby::run_step_5210(SjRingBuffer **inputs, s32 channels) {
    return GCRNA_Create(inputs, channels);
}

void TLobby::flush_update(GcrnaErrorCallback callback, void *context) {
    gcrna_set_error_callback(callback, context);
}

void TLobby::shutdown_cleanup() {
    gcrna_shutdown();
}

void TLobby__sub_803CC114(void) {
    gcrna_initialize();
}
