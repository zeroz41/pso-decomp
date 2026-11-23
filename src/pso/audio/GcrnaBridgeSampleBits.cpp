#include "types.h"
#include "pso/audio/GcrnaBridgeSampleBits.h"
#include "pso/audio/GcrnaStatusBridge.h"

typedef void (*GcrnaSampleBitsTrampolineFn)(void);

void TLobby__sub_803CBF30(void) {
    ((GcrnaSampleBitsTrampolineFn)gcrna_set_sample_bits)();
}
