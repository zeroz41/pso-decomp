#include "types.h"
#include "pso/audio/GcrnaBridgeLoop.h"
#include "pso/audio/GcrnaControlBridge.h"

void gcrna_bridge_set_loop_flag(GcrnaStream *stream, s32 enabled) {
    gcrna_set_loop_flag(stream, enabled);
}
