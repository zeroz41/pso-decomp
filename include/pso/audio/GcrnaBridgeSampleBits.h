#ifndef PSO_AUDIO_GCRNABRIDGESAMPLEBITS_H
#define PSO_AUDIO_GCRNABRIDGESAMPLEBITS_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void gcrna_bridge_set_sample_bits(GcrnaStream *stream, s32 sample_bits);
}

#endif
