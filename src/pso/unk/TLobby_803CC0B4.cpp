#include "types.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/unk/TLobby_803D60A8.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 GCRNA_Create();
s32 gcrna_shutdown();
s32 gcrna_initialize();

void TLobby::run_step_5210() {
    GCRNA_Create();
}

void TLobby::flush_update() {
    gcrna_set_error_callback();
}

void TLobby::shutdown_cleanup() {
    gcrna_shutdown();
}

void TLobby__sub_803CC114(void) {
    gcrna_initialize();
}

}
