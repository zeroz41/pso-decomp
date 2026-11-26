#include "types.h"
#include "pso/audio/GcrnaBridgeReady.h"
#include "pso/audio/GcrnaStatusBridge.h"

s32 gcrna_bridge_stream_ready(GcrnaStream *stream) {
    return gcrna_bridge_is_ready();
}
