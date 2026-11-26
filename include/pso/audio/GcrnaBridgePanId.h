#ifndef PSO_AUDIO_GCRNABRIDGEPANID_H
#define PSO_AUDIO_GCRNABRIDGEPANID_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void gcrna_bridge_set_pan_id(GcrnaStream *stream, s32 pan_id);
}

#endif
