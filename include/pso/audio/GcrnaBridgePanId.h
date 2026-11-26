#ifndef PSO_AUDIO_GCRNABRIDGEPANID_H
#define PSO_AUDIO_GCRNABRIDGEPANID_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void gcrna_bridge_set_total_samples(GcrnaStream *stream, s32 total_samples);
}

#endif
