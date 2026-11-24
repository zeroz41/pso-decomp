#include "types.h"
#include "pso/audio/GcrnaBridgeReady.h"
#include "pso/audio/GcrnaStatusBridge.h"

s32 TLobby__sub_803CBF10(GcrnaStream *stream) {
    return gcrna_bridge_is_ready();
}
