#include "types.h"
#include "pso/audio/GcrnaStatusBridge.h"
#include "pso/unk/TLobby.h"

s32 TLobby::run_step_4430() {
    gcrna_bridge_get_status();
    return 0;
}
