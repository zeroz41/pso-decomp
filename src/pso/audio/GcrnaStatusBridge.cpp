#include "types.h"
#include "pso/audio/GcrnaStatusBridge.h"

s32 gcrna_bridge_is_ready(void) {
    return 0;
}

s32 gcrna_bridge_get_status(void) {
    return 0;
}

void gcrna_set_sample_bits(GcrnaStream *stream, s32 sample_bits) {
    if (stream != NULL) {
        stream->sample_bits = sample_bits;
    }
}
