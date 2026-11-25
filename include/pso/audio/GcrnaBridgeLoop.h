#ifndef PSO_AUDIO_GCRNA_BRIDGE_LOOP_H
#define PSO_AUDIO_GCRNA_BRIDGE_LOOP_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void gcrna_bridge_set_loop_flag(GcrnaStream *stream, s32 enabled);
}

#endif
