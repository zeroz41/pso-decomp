#ifndef PSO_AUDIO_GCRNA_BRIDGE_TEARDOWN_H
#define PSO_AUDIO_GCRNA_BRIDGE_TEARDOWN_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void unregister_si_polling(GcrnaStream *stream);
}

#endif
