#include "types.h"
#include "pso/audio/GcrnaBridgeSampleBits.h"
#include "pso/audio/GcrnaStatusBridge.h"

void TLobby__sub_803CBF30(GcrnaStream *stream, s32 sample_bits) {
    gcrna_set_sample_bits(stream, sample_bits);
}
