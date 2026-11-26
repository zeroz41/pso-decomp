#ifndef PSO_AUDIO_GCRNACHANNELBRIDGE_H
#define PSO_AUDIO_GCRNACHANNELBRIDGE_H

#include "types.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {
void gcrna_set_stream_count(GcrnaStream *stream, s32 stream_count);
}

#endif
