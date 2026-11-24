#ifndef PSO_AUDIO_GCRNABUFFERQUERY_H
#define PSO_AUDIO_GCRNABUFFERQUERY_H

#include "types.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {
u32 get_packet_size(GcrnaStream *stream);
u32 get_available_size(GcrnaStream *stream);
}

#endif
