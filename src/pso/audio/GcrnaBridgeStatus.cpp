#include "types.h"
#include "pso/audio/GcrnaStatusBridge.h"
#include "pso/audio/GcrnaBridgeStatus.h"

s32 run_step_4430(GcrnaStream *stream, u8 *header) {
    gcrna_bridge_get_status();
    return 0;
}
