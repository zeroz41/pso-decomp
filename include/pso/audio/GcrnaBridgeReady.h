#ifndef PSO_AUDIO_GCRNABRIDGEREADY_H
#define PSO_AUDIO_GCRNABRIDGEREADY_H

#include "types.h"

struct GcrnaStream;

extern "C" {
s32 gcrna_bridge_stream_is_ready(GcrnaStream *stream);
}

#endif
