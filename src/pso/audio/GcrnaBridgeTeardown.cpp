#include "types.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaBridgeTeardown.h"

void unregister_si_polling(GcrnaStream *stream) {
    GCRNA_SetPlaySw(stream, 0);
    GCRNA_SetTransSw(stream, 0);
    gcrna_destroy_stream(stream);
}
